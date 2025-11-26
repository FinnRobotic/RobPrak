#include <memory>
#include <vector>
#include <cmath>
#include <chrono>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/pose.hpp>

#include <moveit/move_group_interface/move_group_interface.hpp>
#include <moveit_msgs/msg/robot_trajectory.hpp>

using namespace std::chrono_literals;

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>(
    "spiral_demo",
    rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));
  auto logger = node->get_logger();

  using moveit::planning_interface::MoveGroupInterface;
  MoveGroupInterface move_group(node, "ur_manipulator");

  // ---------- 1) Roboter in die Pose "home" fahren ----------
  RCLCPP_INFO(logger, "Moving to named target 'home'...");
  move_group.setNamedTarget("home");

  moveit::planning_interface::MoveGroupInterface::Plan plan_to_home;
  if (!static_cast<bool>(move_group.plan(plan_to_home)))
  {
    RCLCPP_ERROR(logger, "Planning to 'home' failed.");
    rclcpp::shutdown();
    return 1;
  }
  if (!static_cast<bool>(move_group.execute(plan_to_home)))
  {
    RCLCPP_ERROR(logger, "Execution to 'home' failed.");
    rclcpp::shutdown();
    return 1;
  }
  RCLCPP_INFO(logger, "Robot is at 'home'.");

  // ---------- 2) TCP-Pose von /tcp_pose_broadcaster/pose holen ----------
  geometry_msgs::msg::PoseStamped tcp_pose;
  bool got_pose = false;

  auto sub = node->create_subscription<geometry_msgs::msg::PoseStamped>(
    "/tcp_pose_broadcaster/pose", 10,
    [&](const geometry_msgs::msg::PoseStamped::SharedPtr msg)
    {
      tcp_pose = *msg;
      got_pose = true;
    });

  rclcpp::executors::SingleThreadedExecutor exec;
  exec.add_node(node);

  RCLCPP_INFO(logger, "Waiting for /tcp_pose_broadcaster/pose ...");
  auto start_time = node->get_clock()->now();
  while (rclcpp::ok() && !got_pose)
  {
    exec.spin_some();
    rclcpp::sleep_for(50ms);

    if ((node->get_clock()->now() - start_time).seconds() > 2.0)
    {
      RCLCPP_ERROR(logger, "Timeout: no /tcp_pose_broadcaster/pose received.");
      rclcpp::shutdown();
      return 1;
    }
  }

  geometry_msgs::msg::Pose home_pose = tcp_pose.pose;
  RCLCPP_INFO(logger,
              "TCP at home (from topic) = [%.3f, %.3f, %.3f]",
              home_pose.position.x,
              home_pose.position.y,
              home_pose.position.z);

  // ---------- 3) Ziel: 20 cm unterhalb von home in -Z (Basisframe) ----------
  geometry_msgs::msg::Pose center_pose = home_pose;
  center_pose.position.z -= 0.10;  // 20 cm nach unten

  RCLCPP_INFO(logger,
              "Target center pose (20cm below home) = [%.3f, %.3f, %.3f]",
              center_pose.position.x,
              center_pose.position.y,
              center_pose.position.z);

  move_group.setPoseTarget(center_pose);
  moveit::planning_interface::MoveGroupInterface::Plan plan_to_center;
  RCLCPP_INFO(logger, "Planning to center pose...");
  if (!static_cast<bool>(move_group.plan(plan_to_center)))
  {
    RCLCPP_ERROR(logger, "Planning to center pose failed.");
    rclcpp::shutdown();
    return 1;
  }
  if (!static_cast<bool>(move_group.execute(plan_to_center)))
  {
    RCLCPP_ERROR(logger, "Execution to center pose failed.");
    rclcpp::shutdown();
    return 1;
  }
  RCLCPP_INFO(logger, "Robot reached center pose (20cm below home).");

  // Spiralzentrum = diese Pose
  geometry_msgs::msg::Pose origin_pose = center_pose;
  RCLCPP_INFO(logger,
              "Spiral center = [%.3f, %.3f, %.3f]",
              origin_pose.position.x,
              origin_pose.position.y,
              origin_pose.position.z);

  // ---------- 4) Helix (konstanter Radius) um dieses Spiralzentrum ----------
  const int    num_points = 600;     // Anzahl Wegpunkte
  const double num_turns  = 3.0;     // Umdrehungen
  const double radius     = 0.10;    // 10 cm konstanter Radius
  const double dz_total   = 0.15;    // 15 cm nach oben (oder unten) insgesamt

  std::vector<geometry_msgs::msg::Pose> waypoints;
  waypoints.reserve(num_points);

  for (int i = 0; i < num_points; ++i)
  {
    double t = static_cast<double>(i) / (num_points - 1);   // [0..1]
    double angle = 2.0 * M_PI * num_turns * t;
    double dz    = -dz_total * t;   // nach unten spiralen (relativ zum center)

    geometry_msgs::msg::Pose p;
    p.position.x = origin_pose.position.x + radius * std::cos(angle);
    p.position.y = origin_pose.position.y + radius * std::sin(angle);
    p.position.z = origin_pose.position.z + dz;

    // Orientierung = Home-TCP-Orientierung (konstant)
    p.orientation = home_pose.orientation;

    waypoints.push_back(p);
  }

  // ---------- 5) Kartesische Trajektorie planen & ausführen ----------
  moveit_msgs::msg::RobotTrajectory traj;
  const double eef_step       = 0.01;   // 1 cm Auflösung
  const double jump_threshold = 0.0;

  double fraction = move_group.computeCartesianPath(
    waypoints, eef_step, jump_threshold, traj);

  RCLCPP_INFO(logger, "Spiral fraction: %.1f%%", fraction * 100.0);


  if (fraction < 0.9)
  {
    RCLCPP_ERROR(logger, "Cartesian path incomplete (<90%%).");
    rclcpp::shutdown();
    return 1;
  }


  if (!static_cast<bool>(move_group.execute(traj)))
  {
    RCLCPP_ERROR(logger, "Spiral execution failed.");
    rclcpp::shutdown();
    return 1;
  }

  RCLCPP_INFO(logger, "Spiral finished successfully.");
  rclcpp::shutdown();
  return 0;
}
