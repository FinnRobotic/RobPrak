// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from prak_msgs:msg/JointStateStamped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/msg/joint_state_stamped.hpp"


#ifndef PRAK_MSGS__MSG__DETAIL__JOINT_STATE_STAMPED__STRUCT_HPP_
#define PRAK_MSGS__MSG__DETAIL__JOINT_STATE_STAMPED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"
// Member 'joint_state'
#include "prak_msgs/msg/detail/joint_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__prak_msgs__msg__JointStateStamped __attribute__((deprecated))
#else
# define DEPRECATED__prak_msgs__msg__JointStateStamped __declspec(deprecated)
#endif

namespace prak_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct JointStateStamped_
{
  using Type = JointStateStamped_<ContainerAllocator>;

  explicit JointStateStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init),
    joint_state(_init)
  {
    (void)_init;
  }

  explicit JointStateStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init),
    joint_state(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _joint_state_type =
    prak_msgs::msg::JointState_<ContainerAllocator>;
  _joint_state_type joint_state;

  // setters for named parameter idiom
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__joint_state(
    const prak_msgs::msg::JointState_<ContainerAllocator> & _arg)
  {
    this->joint_state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    prak_msgs::msg::JointStateStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const prak_msgs::msg::JointStateStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<prak_msgs::msg::JointStateStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<prak_msgs::msg::JointStateStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      prak_msgs::msg::JointStateStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<prak_msgs::msg::JointStateStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      prak_msgs::msg::JointStateStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<prak_msgs::msg::JointStateStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<prak_msgs::msg::JointStateStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<prak_msgs::msg::JointStateStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__prak_msgs__msg__JointStateStamped
    std::shared_ptr<prak_msgs::msg::JointStateStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__prak_msgs__msg__JointStateStamped
    std::shared_ptr<prak_msgs::msg::JointStateStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointStateStamped_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->joint_state != other.joint_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointStateStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointStateStamped_

// alias to use template instance with default allocator
using JointStateStamped =
  prak_msgs::msg::JointStateStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace prak_msgs

#endif  // PRAK_MSGS__MSG__DETAIL__JOINT_STATE_STAMPED__STRUCT_HPP_
