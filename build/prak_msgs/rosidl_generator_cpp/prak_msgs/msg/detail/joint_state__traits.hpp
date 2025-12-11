// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from prak_msgs:msg/JointState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/msg/joint_state.hpp"


#ifndef PRAK_MSGS__MSG__DETAIL__JOINT_STATE__TRAITS_HPP_
#define PRAK_MSGS__MSG__DETAIL__JOINT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "prak_msgs/msg/detail/joint_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace prak_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const JointState & msg,
  std::ostream & out)
{
  out << "{";
  // member: shoulder_pan_joint
  {
    out << "shoulder_pan_joint: ";
    rosidl_generator_traits::value_to_yaml(msg.shoulder_pan_joint, out);
    out << ", ";
  }

  // member: shoulder_lift_joint
  {
    out << "shoulder_lift_joint: ";
    rosidl_generator_traits::value_to_yaml(msg.shoulder_lift_joint, out);
    out << ", ";
  }

  // member: elbow_joint
  {
    out << "elbow_joint: ";
    rosidl_generator_traits::value_to_yaml(msg.elbow_joint, out);
    out << ", ";
  }

  // member: wrist_1_joint
  {
    out << "wrist_1_joint: ";
    rosidl_generator_traits::value_to_yaml(msg.wrist_1_joint, out);
    out << ", ";
  }

  // member: wrist_2_joint
  {
    out << "wrist_2_joint: ";
    rosidl_generator_traits::value_to_yaml(msg.wrist_2_joint, out);
    out << ", ";
  }

  // member: wrist_3_joint
  {
    out << "wrist_3_joint: ";
    rosidl_generator_traits::value_to_yaml(msg.wrist_3_joint, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const JointState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: shoulder_pan_joint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shoulder_pan_joint: ";
    rosidl_generator_traits::value_to_yaml(msg.shoulder_pan_joint, out);
    out << "\n";
  }

  // member: shoulder_lift_joint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shoulder_lift_joint: ";
    rosidl_generator_traits::value_to_yaml(msg.shoulder_lift_joint, out);
    out << "\n";
  }

  // member: elbow_joint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "elbow_joint: ";
    rosidl_generator_traits::value_to_yaml(msg.elbow_joint, out);
    out << "\n";
  }

  // member: wrist_1_joint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wrist_1_joint: ";
    rosidl_generator_traits::value_to_yaml(msg.wrist_1_joint, out);
    out << "\n";
  }

  // member: wrist_2_joint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wrist_2_joint: ";
    rosidl_generator_traits::value_to_yaml(msg.wrist_2_joint, out);
    out << "\n";
  }

  // member: wrist_3_joint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wrist_3_joint: ";
    rosidl_generator_traits::value_to_yaml(msg.wrist_3_joint, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const JointState & msg, bool use_flow_style = false)
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
  const prak_msgs::msg::JointState & msg,
  std::ostream & out, size_t indentation = 0)
{
  prak_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use prak_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const prak_msgs::msg::JointState & msg)
{
  return prak_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<prak_msgs::msg::JointState>()
{
  return "prak_msgs::msg::JointState";
}

template<>
inline const char * name<prak_msgs::msg::JointState>()
{
  return "prak_msgs/msg/JointState";
}

template<>
struct has_fixed_size<prak_msgs::msg::JointState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<prak_msgs::msg::JointState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<prak_msgs::msg::JointState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PRAK_MSGS__MSG__DETAIL__JOINT_STATE__TRAITS_HPP_
