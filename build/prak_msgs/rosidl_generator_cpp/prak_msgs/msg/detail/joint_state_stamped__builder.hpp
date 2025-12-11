// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from prak_msgs:msg/JointStateStamped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/msg/joint_state_stamped.hpp"


#ifndef PRAK_MSGS__MSG__DETAIL__JOINT_STATE_STAMPED__BUILDER_HPP_
#define PRAK_MSGS__MSG__DETAIL__JOINT_STATE_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "prak_msgs/msg/detail/joint_state_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace prak_msgs
{

namespace msg
{

namespace builder
{

class Init_JointStateStamped_joint_state
{
public:
  explicit Init_JointStateStamped_joint_state(::prak_msgs::msg::JointStateStamped & msg)
  : msg_(msg)
  {}
  ::prak_msgs::msg::JointStateStamped joint_state(::prak_msgs::msg::JointStateStamped::_joint_state_type arg)
  {
    msg_.joint_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::prak_msgs::msg::JointStateStamped msg_;
};

class Init_JointStateStamped_stamp
{
public:
  Init_JointStateStamped_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointStateStamped_joint_state stamp(::prak_msgs::msg::JointStateStamped::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_JointStateStamped_joint_state(msg_);
  }

private:
  ::prak_msgs::msg::JointStateStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::prak_msgs::msg::JointStateStamped>()
{
  return prak_msgs::msg::builder::Init_JointStateStamped_stamp();
}

}  // namespace prak_msgs

#endif  // PRAK_MSGS__MSG__DETAIL__JOINT_STATE_STAMPED__BUILDER_HPP_
