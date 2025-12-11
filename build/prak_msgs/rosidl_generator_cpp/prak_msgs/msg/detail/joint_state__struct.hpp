// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from prak_msgs:msg/JointState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/msg/joint_state.hpp"


#ifndef PRAK_MSGS__MSG__DETAIL__JOINT_STATE__STRUCT_HPP_
#define PRAK_MSGS__MSG__DETAIL__JOINT_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__prak_msgs__msg__JointState __attribute__((deprecated))
#else
# define DEPRECATED__prak_msgs__msg__JointState __declspec(deprecated)
#endif

namespace prak_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct JointState_
{
  using Type = JointState_<ContainerAllocator>;

  explicit JointState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shoulder_pan_joint = 0.0;
      this->shoulder_lift_joint = 0.0;
      this->elbow_joint = 0.0;
      this->wrist_1_joint = 0.0;
      this->wrist_2_joint = 0.0;
      this->wrist_3_joint = 0.0;
    }
  }

  explicit JointState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shoulder_pan_joint = 0.0;
      this->shoulder_lift_joint = 0.0;
      this->elbow_joint = 0.0;
      this->wrist_1_joint = 0.0;
      this->wrist_2_joint = 0.0;
      this->wrist_3_joint = 0.0;
    }
  }

  // field types and members
  using _shoulder_pan_joint_type =
    double;
  _shoulder_pan_joint_type shoulder_pan_joint;
  using _shoulder_lift_joint_type =
    double;
  _shoulder_lift_joint_type shoulder_lift_joint;
  using _elbow_joint_type =
    double;
  _elbow_joint_type elbow_joint;
  using _wrist_1_joint_type =
    double;
  _wrist_1_joint_type wrist_1_joint;
  using _wrist_2_joint_type =
    double;
  _wrist_2_joint_type wrist_2_joint;
  using _wrist_3_joint_type =
    double;
  _wrist_3_joint_type wrist_3_joint;

  // setters for named parameter idiom
  Type & set__shoulder_pan_joint(
    const double & _arg)
  {
    this->shoulder_pan_joint = _arg;
    return *this;
  }
  Type & set__shoulder_lift_joint(
    const double & _arg)
  {
    this->shoulder_lift_joint = _arg;
    return *this;
  }
  Type & set__elbow_joint(
    const double & _arg)
  {
    this->elbow_joint = _arg;
    return *this;
  }
  Type & set__wrist_1_joint(
    const double & _arg)
  {
    this->wrist_1_joint = _arg;
    return *this;
  }
  Type & set__wrist_2_joint(
    const double & _arg)
  {
    this->wrist_2_joint = _arg;
    return *this;
  }
  Type & set__wrist_3_joint(
    const double & _arg)
  {
    this->wrist_3_joint = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    prak_msgs::msg::JointState_<ContainerAllocator> *;
  using ConstRawPtr =
    const prak_msgs::msg::JointState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<prak_msgs::msg::JointState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<prak_msgs::msg::JointState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      prak_msgs::msg::JointState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<prak_msgs::msg::JointState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      prak_msgs::msg::JointState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<prak_msgs::msg::JointState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<prak_msgs::msg::JointState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<prak_msgs::msg::JointState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__prak_msgs__msg__JointState
    std::shared_ptr<prak_msgs::msg::JointState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__prak_msgs__msg__JointState
    std::shared_ptr<prak_msgs::msg::JointState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointState_ & other) const
  {
    if (this->shoulder_pan_joint != other.shoulder_pan_joint) {
      return false;
    }
    if (this->shoulder_lift_joint != other.shoulder_lift_joint) {
      return false;
    }
    if (this->elbow_joint != other.elbow_joint) {
      return false;
    }
    if (this->wrist_1_joint != other.wrist_1_joint) {
      return false;
    }
    if (this->wrist_2_joint != other.wrist_2_joint) {
      return false;
    }
    if (this->wrist_3_joint != other.wrist_3_joint) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointState_

// alias to use template instance with default allocator
using JointState =
  prak_msgs::msg::JointState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace prak_msgs

#endif  // PRAK_MSGS__MSG__DETAIL__JOINT_STATE__STRUCT_HPP_
