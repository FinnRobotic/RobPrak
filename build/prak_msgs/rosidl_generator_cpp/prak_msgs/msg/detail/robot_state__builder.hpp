// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from prak_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/msg/robot_state.hpp"


#ifndef PRAK_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
#define PRAK_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "prak_msgs/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace prak_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotState_tcp_pose
{
public:
  explicit Init_RobotState_tcp_pose(::prak_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  ::prak_msgs::msg::RobotState tcp_pose(::prak_msgs::msg::RobotState::_tcp_pose_type arg)
  {
    msg_.tcp_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::prak_msgs::msg::RobotState msg_;
};

class Init_RobotState_joint_state
{
public:
  explicit Init_RobotState_joint_state(::prak_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_tcp_pose joint_state(::prak_msgs::msg::RobotState::_joint_state_type arg)
  {
    msg_.joint_state = std::move(arg);
    return Init_RobotState_tcp_pose(msg_);
  }

private:
  ::prak_msgs::msg::RobotState msg_;
};

class Init_RobotState_header
{
public:
  Init_RobotState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotState_joint_state header(::prak_msgs::msg::RobotState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RobotState_joint_state(msg_);
  }

private:
  ::prak_msgs::msg::RobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::prak_msgs::msg::RobotState>()
{
  return prak_msgs::msg::builder::Init_RobotState_header();
}

}  // namespace prak_msgs

#endif  // PRAK_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
