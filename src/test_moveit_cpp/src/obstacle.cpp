#include <memory>
#include <vector>
#include <chrono>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose.hpp>

#include <moveit/move_group_interface/move_group_interface.hpp>
#include <moveit/planning_scene_interface/planning_scene_interface.hpp>
#include <moveit_msgs/msg/collision_object.hpp>
#include <shape_msgs/msg/solid_primitive.hpp>

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>(
    "obstacle_demo",
    rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));
  auto logger = node->get_logger();

  using moveit::planning_interface::MoveGroupInterface;
  using moveit::planning_interface::PlanningSceneInterface;

  MoveGroupInterface move_group(node, "ur_manipulator");
  PlanningSceneInterface planning_scene;

  const std::string frame_id = move_group.getPlanningFrame();
  RCLCPP_INFO(logger, "Planning frame: %s", frame_id.c_str());

  // -------- Hindernisse definieren --------
  std::vector<moveit_msgs::msg::CollisionObject> objs;
  objs.resize(3);

  // Zentrales Hindernis
  {
    auto& obj = objs[0];
    obj.id = "central_obstacle";
    obj.header.frame_id = frame_id;

    shape_msgs::msg::SolidPrimitive prim;
    prim.type = prim.BOX;
    prim.dimensions = {0.2, 0.2, 0.4};

    geometry_msgs::msg::Pose pose;
    pose.position.x = 0.45;
    pose.position.y = 0.0;
    pose.position.z = 0.2;
    pose.orientation.w = 1.0;

    obj.primitives.push_back(prim);
    obj.primitive_poses.push_back(pose);
    obj.operation = obj.ADD;
  }

  // Tisch
  {
    auto& obj = objs[1];
    obj.id = "table";
    obj.header.frame_id = frame_id;

    shape_msgs::msg::SolidPrimitive prim;
    prim.type = prim.BOX;
    prim.dimensions = {1.2, 0.8, 0.05};

    geometry_msgs::msg::Pose pose;
    pose.position.x = 0.5;
    pose.position.y = 0.0;
    pose.position.z = -0.025;  // Tischplatte knapp unter Base
    pose.orientation.w = 1.0;

    obj.primitives.push_back(prim);
    obj.primitive_poses.push_back(pose);
    obj.operation = obj.ADD;
  }

  // Rückwand
  {
    auto& obj = objs[2];
    obj.id = "back_wall";
    obj.header.frame_id = frame_id;

    shape_msgs::msg::SolidPrimitive prim;
    prim.type = prim.BOX;
    prim.dimensions = {0.05, 2.0, 2.0};

    geometry_msgs::msg::Pose pose;
    pose.position.x = -0.2;
    pose.position.y = 0.0;
    pose.position.z = 1.0;
    pose.orientation.w = 1.0;

    obj.primitives.push_back(prim);
    obj.primitive_poses.push_back(pose);
    obj.operation = obj.ADD;
  }

  planning_scene.applyCollisionObjects(objs);
  RCLCPP_INFO(logger, "Collision objects added.");

  // kleine Pause, damit alles ankommt
  rclcpp::sleep_for(std::chrono::seconds(2));

  // -------- Startpose links vom Hindernis --------
  geometry_msgs::msg::Pose start_pose;
  start_pose.orientation.w = 1.0;
  start_pose.position.x = 0.35;
  start_pose.position.y = 0.30;
  start_pose.position.z = 0.40;

  move_group.setPoseTarget(start_pose);
  moveit::planning_interface::MoveGroupInterface::Plan plan;

  RCLCPP_INFO(logger, "Planning to start pose...");
  if (!static_cast<bool>(move_group.plan(plan)))
  {
    RCLCPP_ERROR(logger, "Planning to start pose failed.");
    rclcpp::shutdown();
    return 1;
  }
  move_group.execute(plan);

  // -------- Zielpose rechts vom Hindernis --------
  geometry_msgs::msg::Pose goal_pose = start_pose;
  goal_pose.position.y = -0.30;

  move_group.setPoseTarget(goal_pose);
  RCLCPP_INFO(logger, "Planning around obstacle to goal pose...");
  if (!static_cast<bool>(move_group.plan(plan)))
  {
    RCLCPP_ERROR(logger, "Planning around obstacle failed.");
    rclcpp::shutdown();
    return 1;
  }
  move_group.execute(plan);

  RCLCPP_INFO(logger, "Obstacle demo finished.");
  rclcpp::shutdown();
  return 0;
}
