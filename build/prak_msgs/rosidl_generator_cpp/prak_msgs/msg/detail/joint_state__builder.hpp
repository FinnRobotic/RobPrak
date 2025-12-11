// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from prak_msgs:msg/JointState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/msg/joint_state.hpp"


#ifndef PRAK_MSGS__MSG__DETAIL__JOINT_STATE__BUILDER_HPP_
#define PRAK_MSGS__MSG__DETAIL__JOINT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "prak_msgs/msg/detail/joint_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace prak_msgs
{

namespace msg
{

namespace builder
{

class Init_JointState_wrist_3_joint
{
public:
  explicit Init_JointState_wrist_3_joint(::prak_msgs::msg::JointState & msg)
  : msg_(msg)
  {}
  ::prak_msgs::msg::JointState wrist_3_joint(::prak_msgs::msg::JointState::_wrist_3_joint_type arg)
  {
    msg_.wrist_3_joint = std::move(arg);
    return std::move(msg_);
  }

private:
  ::prak_msgs::msg::JointState msg_;
};

class Init_JointState_wrist_2_joint
{
public:
  explicit Init_JointState_wrist_2_joint(::prak_msgs::msg::JointState & msg)
  : msg_(msg)
  {}
  Init_JointState_wrist_3_joint wrist_2_joint(::prak_msgs::msg::JointState::_wrist_2_joint_type arg)
  {
    msg_.wrist_2_joint = std::move(arg);
    return Init_JointState_wrist_3_joint(msg_);
  }

private:
  ::prak_msgs::msg::JointState msg_;
};

class Init_JointState_wrist_1_joint
{
public:
  explicit Init_JointState_wrist_1_joint(::prak_msgs::msg::JointState & msg)
  : msg_(msg)
  {}
  Init_JointState_wrist_2_joint wrist_1_joint(::prak_msgs::msg::JointState::_wrist_1_joint_type arg)
  {
    msg_.wrist_1_joint = std::move(arg);
    return Init_JointState_wrist_2_joint(msg_);
  }

private:
  ::prak_msgs::msg::JointState msg_;
};

class Init_JointState_elbow_joint
{
public:
  explicit Init_JointState_elbow_joint(::prak_msgs::msg::JointState & msg)
  : msg_(msg)
  {}
  Init_JointState_wrist_1_joint elbow_joint(::prak_msgs::msg::JointState::_elbow_joint_type arg)
  {
    msg_.elbow_joint = std::move(arg);
    return Init_JointState_wrist_1_joint(msg_);
  }

private:
  ::prak_msgs::msg::JointState msg_;
};

class Init_JointState_shoulder_lift_joint
{
public:
  explicit Init_JointState_shoulder_lift_joint(::prak_msgs::msg::JointState & msg)
  : msg_(msg)
  {}
  Init_JointState_elbow_joint shoulder_lift_joint(::prak_msgs::msg::JointState::_shoulder_lift_joint_type arg)
  {
    msg_.shoulder_lift_joint = std::move(arg);
    return Init_JointState_elbow_joint(msg_);
  }

private:
  ::prak_msgs::msg::JointState msg_;
};

class Init_JointState_shoulder_pan_joint
{
public:
  Init_JointState_shoulder_pan_joint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointState_shoulder_lift_joint shoulder_pan_joint(::prak_msgs::msg::JointState::_shoulder_pan_joint_type arg)
  {
    msg_.shoulder_pan_joint = std::move(arg);
    return Init_JointState_shoulder_lift_joint(msg_);
  }

private:
  ::prak_msgs::msg::JointState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::prak_msgs::msg::JointState>()
{
  return prak_msgs::msg::builder::Init_JointState_shoulder_pan_joint();
}

}  // namespace prak_msgs

#endif  // PRAK_MSGS__MSG__DETAIL__JOINT_STATE__BUILDER_HPP_
