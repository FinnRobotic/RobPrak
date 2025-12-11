// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from prak_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/msg/robot_state.hpp"


#ifndef PRAK_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_
#define PRAK_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'joint_state'
#include "prak_msgs/msg/detail/joint_state_stamped__struct.hpp"
// Member 'tcp_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__prak_msgs__msg__RobotState __attribute__((deprecated))
#else
# define DEPRECATED__prak_msgs__msg__RobotState __declspec(deprecated)
#endif

namespace prak_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotState_
{
  using Type = RobotState_<ContainerAllocator>;

  explicit RobotState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    joint_state(_init),
    tcp_pose(_init)
  {
    (void)_init;
  }

  explicit RobotState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    joint_state(_alloc, _init),
    tcp_pose(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _joint_state_type =
    prak_msgs::msg::JointStateStamped_<ContainerAllocator>;
  _joint_state_type joint_state;
  using _tcp_pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _tcp_pose_type tcp_pose;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__joint_state(
    const prak_msgs::msg::JointStateStamped_<ContainerAllocator> & _arg)
  {
    this->joint_state = _arg;
    return *this;
  }
  Type & set__tcp_pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->tcp_pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    prak_msgs::msg::RobotState_<ContainerAllocator> *;
  using ConstRawPtr =
    const prak_msgs::msg::RobotState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<prak_msgs::msg::RobotState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<prak_msgs::msg::RobotState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      prak_msgs::msg::RobotState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<prak_msgs::msg::RobotState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      prak_msgs::msg::RobotState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<prak_msgs::msg::RobotState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<prak_msgs::msg::RobotState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<prak_msgs::msg::RobotState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__prak_msgs__msg__RobotState
    std::shared_ptr<prak_msgs::msg::RobotState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__prak_msgs__msg__RobotState
    std::shared_ptr<prak_msgs::msg::RobotState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->joint_state != other.joint_state) {
      return false;
    }
    if (this->tcp_pose != other.tcp_pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotState_

// alias to use template instance with default allocator
using RobotState =
  prak_msgs::msg::RobotState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace prak_msgs

#endif  // PRAK_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_
