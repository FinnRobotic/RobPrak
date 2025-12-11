// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from prak_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/msg/robot_state.hpp"


#ifndef PRAK_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
#define PRAK_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "prak_msgs/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'joint_state'
#include "prak_msgs/msg/detail/joint_state_stamped__traits.hpp"
// Member 'tcp_pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace prak_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: joint_state
  {
    out << "joint_state: ";
    to_flow_style_yaml(msg.joint_state, out);
    out << ", ";
  }

  // member: tcp_pose
  {
    out << "tcp_pose: ";
    to_flow_style_yaml(msg.tcp_pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: joint_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "joint_state:\n";
    to_block_style_yaml(msg.joint_state, out, indentation + 2);
  }

  // member: tcp_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tcp_pose:\n";
    to_block_style_yaml(msg.tcp_pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace prak_msgs

namespace rosidl_generator_traits
{

[[deprecated("use prak_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const prak_msgs::msg::RobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  prak_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use prak_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const prak_msgs::msg::RobotState & msg)
{
  return prak_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<prak_msgs::msg::RobotState>()
{
  return "prak_msgs::msg::RobotState";
}

template<>
inline const char * name<prak_msgs::msg::RobotState>()
{
  return "prak_msgs/msg/RobotState";
}

template<>
struct has_fixed_size<prak_msgs::msg::RobotState>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseStamped>::value && has_fixed_size<prak_msgs::msg::JointStateStamped>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<prak_msgs::msg::RobotState>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseStamped>::value && has_bounded_size<prak_msgs::msg::JointStateStamped>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<prak_msgs::msg::RobotState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PRAK_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
