#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);

  auto const node = std::make_shared<rclcpp::Node>(
    "hello_moveit",
    rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true)
  );


  auto const logger = rclcpp::get_logger("hello_moveit");

  using moveit::planning_interface::MoveGroupInterface;


  MoveGroupInterface move_group_interface(node, "ur_manipulator");

  auto const target_pose = [] {
    geometry_msgs::msg::Pose msg;
    msg.orientation.w = 1.0;  
    msg.position.x = 0.28;
    msg.position.y = -0.20;
    msg.position.z = 0.50;
    return msg;
  }();

  move_group_interface.setPoseTarget(target_pose);

  auto const [success, plan] = [&move_group_interface] {
    moveit::planning_interface::MoveGroupInterface::Plan plan_msg;
    auto const ok = static_cast<bool>(move_group_interface.plan(plan_msg));
    return std::make_pair(ok, plan_msg);
  }();

  
  if (success) {
    RCLCPP_INFO(logger, "Planning succeeded, executing trajectory...");
    auto const exec_ok = static_cast<bool>(move_group_interface.execute(plan));
    if (!exec_ok) {
      RCLCPP_ERROR(logger, "Execution failed!");
    }
  } else {
    RCLCPP_ERROR(logger, "Planning failed!");
  }

  rclcpp::shutdown();
  return 0;
}
