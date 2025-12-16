#include <rclcpp/rclcpp.hpp>

#include <geometry_msgs/msg/pose_stamped.hpp>
#include <prak_msgs/msg/actuator_request.hpp>
#include <prak_msgs/msg/joint_state.hpp>
#include <std_msgs/msg/bool.hpp>

#include <moveit/move_group_interface/move_group_interface.hpp>

#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

using prak_msgs::msg::ActuatorRequest;
using prak_msgs::msg::JointState;

class ActuatorDriverNode : public rclcpp::Node
{
public:
  ActuatorDriverNode()
  : Node("actuator_driver"),
    planning_group_("ur_manipulator")
  {
    // TF setup
    tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    // Subscription
    request_sub_ = this->create_subscription<ActuatorRequest>(
        "/driver/actuator_request", 10,
        std::bind(&ActuatorDriverNode::requestCallback, this, std::placeholders::_1));

    pose_reached_pub_ = this->create_publisher<std_msgs::msg::Bool>("/driver/pose_reached", 10);
        
  }



  void init_move_group()
  {
    auto node_shared = this->shared_from_this();

    move_group_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(
        node_shared, planning_group_);

    RCLCPP_INFO(this->get_logger(), "ActuatorDriverNode initialized.");
    RCLCPP_INFO(this->get_logger(), "Planning frame: %s",
                move_group_->getPlanningFrame().c_str());
    RCLCPP_INFO(this->get_logger(), "End-effector link: %s",
                move_group_->getEndEffectorLink().c_str());
  }

private:

  void publishPoseReached(bool reached)
  {
    std_msgs::msg::Bool msg;
    msg.data = reached;
    pose_reached_pub_->publish(msg);
  }

  void requestCallback(const ActuatorRequest::SharedPtr msg)
  {
    if (!move_group_)
    {
      RCLCPP_ERROR(this->get_logger(),
                   "MoveGroupInterface not initialized (did you call init_move_group()?).");
      return;
    }

    RCLCPP_INFO(this->get_logger(),
                "Received ActuatorRequest (use_angles=%s, frame_id='%s')",
                msg->use_angles ? "true" : "false",
                msg->header.frame_id.c_str());

    bool ok = false;

    if (msg->use_angles)
    {
      RCLCPP_INFO(this->get_logger(), "Executing joint goal.");
      ok = executeJointGoal(msg->joint_state);
    }
    else
    {
      RCLCPP_INFO(this->get_logger(), "Executing pose goal (frame_id='%s').",
                  msg->header.frame_id.c_str());
      ok = executePoseGoal(*msg);
    }

    if (!ok)
    {
      RCLCPP_ERROR(this->get_logger(), "Execution of ActuatorRequest failed.");
      publishPoseReached(false);
    }
    else
    {
      RCLCPP_INFO(this->get_logger(), "ActuatorRequest executed successfully.");
      publishPoseReached(true);
    }
  }

  bool executeJointGoal(const JointState &js)
  {
    std::map<std::string, double> target;

    target["shoulder_pan_joint"]   = js.shoulder_pan_joint;
    target["shoulder_lift_joint"]  = js.shoulder_lift_joint;
    target["elbow_joint"]          = js.elbow_joint;
    target["wrist_1_joint"]        = js.wrist_1_joint;
    target["wrist_2_joint"]        = js.wrist_2_joint;
    target["wrist_3_joint"]        = js.wrist_3_joint;

    move_group_->setJointValueTarget(target);

    moveit::planning_interface::MoveGroupInterface::Plan plan;
    bool success = static_cast<bool>(move_group_->plan(plan));

    if (!success)
    {
      RCLCPP_ERROR(this->get_logger(), "Planning joint goal failed.");
      return false;
    }

    auto exec_result = move_group_->execute(plan);
    if (exec_result != moveit::core::MoveItErrorCode::SUCCESS)
    {
      RCLCPP_ERROR(this->get_logger(), "Execution of joint goal failed.");
      return false;
    }

    return true;
  }

  bool executePoseGoal(const ActuatorRequest &req)
  {
    geometry_msgs::msg::PoseStamped pose_in;
    pose_in.header = req.header;
    pose_in.pose   = req.pose;  // pose is a top-level field in ActuatorRequest

    const std::string planning_frame = move_group_->getPlanningFrame();

    if (pose_in.header.frame_id.empty())
    {
      pose_in.header.frame_id = planning_frame;
    }

    geometry_msgs::msg::PoseStamped pose_target;

    try
    {
      pose_target = tf_buffer_->transform(
          pose_in,
          planning_frame,
          tf2::durationFromSec(0.1));
    }
    catch (const tf2::TransformException &ex)
    {
      RCLCPP_ERROR(this->get_logger(),
                   "Failed to transform pose from '%s' to '%s': %s",
                   pose_in.header.frame_id.c_str(),
                   planning_frame.c_str(),
                   ex.what());
      return false;
    }

    move_group_->setPoseReferenceFrame(planning_frame);

    const std::string eef_link = move_group_->getEndEffectorLink();
    move_group_->setPoseTarget(pose_target.pose, eef_link);

    moveit::planning_interface::MoveGroupInterface::Plan plan;
    bool success = static_cast<bool>(move_group_->plan(plan));

    if (!success)
    {
      RCLCPP_ERROR(this->get_logger(), "Planning pose goal failed.");
      return false;
    }

    auto exec_result = move_group_->execute(plan);
    if (exec_result != moveit::core::MoveItErrorCode::SUCCESS)
    {
      RCLCPP_ERROR(this->get_logger(), "Execution of pose goal failed.");
      return false;
    }

    return true;
  }

  // Members
  std::string planning_group_;

  std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_;
  std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
  std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

  rclcpp::Subscription<ActuatorRequest>::SharedPtr request_sub_;

  rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr pose_reached_pub_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<ActuatorDriverNode>();
  node->init_move_group();

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
