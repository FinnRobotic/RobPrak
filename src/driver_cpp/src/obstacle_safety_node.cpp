#include <memory>
#include <string>
#include <vector>
#include <optional>
#include <algorithm>

#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <geometry_msgs/msg/pose.hpp>

#include <moveit/move_group_interface/move_group_interface.hpp>
#include <moveit/planning_scene_interface/planning_scene_interface.hpp>
#include <moveit_msgs/msg/collision_object.hpp>
#include <shape_msgs/msg/solid_primitive.hpp>

class ObstaclePublisherNode : public rclcpp::Node
{
public:
  ObstaclePublisherNode()
  : Node("obstacle_publisher",
         rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true)),
    planning_group_("ur_manipulator")
  {
    logger_ = this->get_logger();

    // Parameters
    this->declare_parameter<std::string>("planning_group", planning_group_);
    this->declare_parameter<std::vector<std::string>>("obstacles", std::vector<std::string>{});
    this->declare_parameter<int>("startup_delay_ms", 800);
    this->declare_parameter<bool>("apply_on_start", true);
    this->declare_parameter<bool>("remove_all_on_start", false);
    this->declare_parameter<bool>("remove_only_configured_ids", true); // safer default

    planning_group_ = this->get_parameter("planning_group").as_string();
    obstacle_names_ = this->get_parameter("obstacles").as_string_array();
    startup_delay_ms_ = this->get_parameter("startup_delay_ms").as_int();
    apply_on_start_ = this->get_parameter("apply_on_start").as_bool();
    remove_all_on_start_ = this->get_parameter("remove_all_on_start").as_bool();
    remove_only_configured_ids_ = this->get_parameter("remove_only_configured_ids").as_bool();

    // Service: apply/reload obstacles
    apply_srv_ = this->create_service<std_srvs::srv::Trigger>(
      "~/apply",
      std::bind(&ObstaclePublisherNode::handleApply, this,
                std::placeholders::_1, std::placeholders::_2)
    );

    // Delay init to ensure ROS graph is up
    startup_timer_ = this->create_wall_timer(
      std::chrono::milliseconds(std::max(0, startup_delay_ms_)),
      std::bind(&ObstaclePublisherNode::startup, this)
    );

    RCLCPP_INFO(logger_, "ObstaclePublisherNode starting. planning_group='%s'", planning_group_.c_str());
  }

private:
  void startup()
  {
    if (startup_timer_)
    {
      startup_timer_->cancel();
      startup_timer_.reset();
    }

    init_move_group();

    if (remove_all_on_start_)
    {
      removeConfiguredObjects();
    }

    if (apply_on_start_)
    {
      applyConfiguredObjects();
    }

    RCLCPP_INFO(logger_, "ObstaclePublisherNode ready. Call service '%s/apply' to reload obstacles.",
                this->get_name());
  }

  void init_move_group()
  {
    auto node_shared = this->shared_from_this();

    move_group_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(
      node_shared, planning_group_);

    planning_frame_ = move_group_->getPlanningFrame();

    RCLCPP_INFO(logger_, "MoveGroup initialized.");
    RCLCPP_INFO(logger_, "Planning frame: %s", planning_frame_.c_str());
    RCLCPP_INFO(logger_, "End-effector link: %s", move_group_->getEndEffectorLink().c_str());
  }

  void handleApply(const std::shared_ptr<std_srvs::srv::Trigger::Request> /*req*/,
                   std::shared_ptr<std_srvs::srv::Trigger::Response> res)
  {
    if (!move_group_)
    {
      res->success = false;
      res->message = "MoveGroup not initialized yet.";
      return;
    }

    // Optionally remove first, then re-apply
    if (remove_all_on_start_)
    {
      removeConfiguredObjects();
    }

    const size_t applied = applyConfiguredObjects();
    res->success = (applied > 0);
    res->message = "Applied " + std::to_string(applied) + " obstacle(s).";
  }

  void removeConfiguredObjects()
  {
    if (obstacle_names_.empty())
    {
      RCLCPP_WARN(logger_, "remove_all_on_start=true but 'obstacles' list is empty. Nothing to remove.");
      return;
    }

    // PlanningSceneInterface supports removing by ID list.
    // Safer default: remove only the IDs that are configured in YAML.
    if (remove_only_configured_ids_)
    {
      planning_scene_.removeCollisionObjects(obstacle_names_);
      RCLCPP_INFO(logger_, "Removed %zu configured collision object(s).", obstacle_names_.size());
      return;
    }

    // If you ever want a true "wipe all known IDs", you’d need to track IDs yourself
    // or query the planning scene (not exposed nicely via PlanningSceneInterface).
    planning_scene_.removeCollisionObjects(obstacle_names_);
    RCLCPP_INFO(logger_, "Removed %zu collision object(s) (configured IDs).", obstacle_names_.size());
  }

  size_t applyConfiguredObjects()
  {
    if (obstacle_names_.empty())
    {
      RCLCPP_WARN(logger_, "No obstacles configured (param 'obstacles' is empty).");
      return 0;
    }

    std::vector<moveit_msgs::msg::CollisionObject> objs;
    objs.reserve(obstacle_names_.size());

    for (const auto& name : obstacle_names_)
    {
      auto obj_opt = buildCollisionObject(name);
      if (obj_opt.has_value())
        objs.push_back(std::move(obj_opt.value()));
    }

    if (objs.empty())
    {
      RCLCPP_WARN(logger_, "No valid collision objects built. Nothing to apply.");
      return 0;
    }

    planning_scene_.applyCollisionObjects(objs);
    RCLCPP_INFO(logger_, "Applied %zu collision object(s).", objs.size());
    return objs.size();
  }

  std::optional<moveit_msgs::msg::CollisionObject> buildCollisionObject(const std::string& name)
  {
    const std::string base = "obstacle." + name + ".";

    // Declare expected per-obstacle params
    this->declare_parameter<std::string>(base + "type", "box");
    this->declare_parameter<std::vector<double>>(base + "size", std::vector<double>{});
    this->declare_parameter<std::vector<double>>(base + "pose.position", std::vector<double>{0.0, 0.0, 0.0});
    this->declare_parameter<std::vector<double>>(base + "pose.orientation", std::vector<double>{0.0, 0.0, 0.0, 1.0});
    this->declare_parameter<std::string>(base + "operation", "add"); // add/remove
    this->declare_parameter<std::string>(base + "frame_id", "");     // optional override

    const auto type = this->get_parameter(base + "type").as_string();
    const auto size = this->get_parameter(base + "size").as_double_array();
    const auto pos  = this->get_parameter(base + "pose.position").as_double_array();
    const auto quat = this->get_parameter(base + "pose.orientation").as_double_array();
    const auto op   = this->get_parameter(base + "operation").as_string();
    auto frame_id   = this->get_parameter(base + "frame_id").as_string();

    if (pos.size() != 3 || quat.size() != 4)
    {
      RCLCPP_ERROR(logger_, "Obstacle '%s': pose.position must have 3 and pose.orientation 4 values.", name.c_str());
      return std::nullopt;
    }

    moveit_msgs::msg::CollisionObject obj;
    obj.id = name;

    // Default to MoveGroup planning frame unless overridden per obstacle
    if (frame_id.empty())
      frame_id = planning_frame_;
    obj.header.frame_id = frame_id;

    geometry_msgs::msg::Pose pose;
    pose.position.x = pos[0];
    pose.position.y = pos[1];
    pose.position.z = pos[2];
    pose.orientation.x = quat[0];
    pose.orientation.y = quat[1];
    pose.orientation.z = quat[2];
    pose.orientation.w = quat[3];

    shape_msgs::msg::SolidPrimitive prim;

    if (type == "box")
    {
      if (size.size() != 3)
      {
        RCLCPP_ERROR(logger_, "Obstacle '%s': box size must be [x,y,z].", name.c_str());
        return std::nullopt;
      }
      prim.type = prim.BOX;
      prim.dimensions = {size[0], size[1], size[2]};
    }
    else if (type == "cylinder")
    {
      // MoveIt: dimensions = [height, radius]
      if (size.size() != 2)
      {
        RCLCPP_ERROR(logger_, "Obstacle '%s': cylinder size must be [height, radius].", name.c_str());
        return std::nullopt;
      }
      prim.type = prim.CYLINDER;
      prim.dimensions = {size[0], size[1]};
    }
    else if (type == "sphere")
    {
      // MoveIt: dimensions = [radius]
      if (size.size() != 1)
      {
        RCLCPP_ERROR(logger_, "Obstacle '%s': sphere size must be [radius].", name.c_str());
        return std::nullopt;
      }
      prim.type = prim.SPHERE;
      prim.dimensions = {size[0]};
    }
    else
    {
      RCLCPP_ERROR(logger_, "Obstacle '%s': unsupported type '%s' (use box/cylinder/sphere).",
                   name.c_str(), type.c_str());
      return std::nullopt;
    }

    obj.primitives.push_back(prim);
    obj.primitive_poses.push_back(pose);

    obj.operation = (op == "remove") ? obj.REMOVE : obj.ADD;

    RCLCPP_INFO(logger_, "Built obstacle '%s' type=%s frame=%s op=%s",
                name.c_str(), type.c_str(), obj.header.frame_id.c_str(), op.c_str());
    return obj;
  }

private:
  rclcpp::Logger logger_;

  // MoveIt
  std::string planning_group_;
  std::string planning_frame_;
  std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_;
  moveit::planning_interface::PlanningSceneInterface planning_scene_;

  // Params
  std::vector<std::string> obstacle_names_;
  int startup_delay_ms_{800};
  bool apply_on_start_{true};
  bool remove_all_on_start_{false};
  bool remove_only_configured_ids_{true};

  // ROS
  rclcpp::TimerBase::SharedPtr startup_timer_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr apply_srv_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ObstaclePublisherNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
