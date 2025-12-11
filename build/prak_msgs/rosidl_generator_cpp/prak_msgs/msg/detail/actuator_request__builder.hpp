// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from prak_msgs:msg/ActuatorRequest.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/msg/actuator_request.hpp"


#ifndef PRAK_MSGS__MSG__DETAIL__ACTUATOR_REQUEST__BUILDER_HPP_
#define PRAK_MSGS__MSG__DETAIL__ACTUATOR_REQUEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "prak_msgs/msg/detail/actuator_request__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace prak_msgs
{

namespace msg
{

namespace builder
{

class Init_ActuatorRequest_pose
{
public:
  explicit Init_ActuatorRequest_pose(::prak_msgs::msg::ActuatorRequest & msg)
  : msg_(msg)
  {}
  ::prak_msgs::msg::ActuatorRequest pose(::prak_msgs::msg::ActuatorRequest::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::prak_msgs::msg::ActuatorRequest msg_;
};

class Init_ActuatorRequest_joint_state
{
public:
  explicit Init_ActuatorRequest_joint_state(::prak_msgs::msg::ActuatorRequest & msg)
  : msg_(msg)
  {}
  Init_ActuatorRequest_pose joint_state(::prak_msgs::msg::ActuatorRequest::_joint_state_type arg)
  {
    msg_.joint_state = std::move(arg);
    return Init_ActuatorRequest_pose(msg_);
  }

private:
  ::prak_msgs::msg::ActuatorRequest msg_;
};

class Init_ActuatorRequest_use_angles
{
public:
  explicit Init_ActuatorRequest_use_angles(::prak_msgs::msg::ActuatorRequest & msg)
  : msg_(msg)
  {}
  Init_ActuatorRequest_joint_state use_angles(::prak_msgs::msg::ActuatorRequest::_use_angles_type arg)
  {
    msg_.use_angles = std::move(arg);
    return Init_ActuatorRequest_joint_state(msg_);
  }

private:
  ::prak_msgs::msg::ActuatorRequest msg_;
};

class Init_ActuatorRequest_header
{
public:
  Init_ActuatorRequest_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActuatorRequest_use_angles header(::prak_msgs::msg::ActuatorRequest::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ActuatorRequest_use_angles(msg_);
  }

private:
  ::prak_msgs::msg::ActuatorRequest msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::prak_msgs::msg::ActuatorRequest>()
{
  return prak_msgs::msg::builder::Init_ActuatorRequest_header();
}

}  // namespace prak_msgs

#endif  // PRAK_MSGS__MSG__DETAIL__ACTUATOR_REQUEST__BUILDER_HPP_
