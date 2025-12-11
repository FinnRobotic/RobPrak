// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from prak_msgs:msg/ActuatorRequest.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/msg/actuator_request.hpp"


#ifndef PRAK_MSGS__MSG__DETAIL__ACTUATOR_REQUEST__STRUCT_HPP_
#define PRAK_MSGS__MSG__DETAIL__ACTUATOR_REQUEST__STRUCT_HPP_

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
#include "prak_msgs/msg/detail/joint_state__struct.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__prak_msgs__msg__ActuatorRequest __attribute__((deprecated))
#else
# define DEPRECATED__prak_msgs__msg__ActuatorRequest __declspec(deprecated)
#endif

namespace prak_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ActuatorRequest_
{
  using Type = ActuatorRequest_<ContainerAllocator>;

  explicit ActuatorRequest_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    joint_state(_init),
    pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->use_angles = false;
    }
  }

  explicit ActuatorRequest_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    joint_state(_alloc, _init),
    pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->use_angles = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _use_angles_type =
    bool;
  _use_angles_type use_angles;
  using _joint_state_type =
    prak_msgs::msg::JointState_<ContainerAllocator>;
  _joint_state_type joint_state;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__use_angles(
    const bool & _arg)
  {
    this->use_angles = _arg;
    return *this;
  }
  Type & set__joint_state(
    const prak_msgs::msg::JointState_<ContainerAllocator> & _arg)
  {
    this->joint_state = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    prak_msgs::msg::ActuatorRequest_<ContainerAllocator> *;
  using ConstRawPtr =
    const prak_msgs::msg::ActuatorRequest_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<prak_msgs::msg::ActuatorRequest_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<prak_msgs::msg::ActuatorRequest_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      prak_msgs::msg::ActuatorRequest_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<prak_msgs::msg::ActuatorRequest_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      prak_msgs::msg::ActuatorRequest_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<prak_msgs::msg::ActuatorRequest_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<prak_msgs::msg::ActuatorRequest_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<prak_msgs::msg::ActuatorRequest_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__prak_msgs__msg__ActuatorRequest
    std::shared_ptr<prak_msgs::msg::ActuatorRequest_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__prak_msgs__msg__ActuatorRequest
    std::shared_ptr<prak_msgs::msg::ActuatorRequest_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ActuatorRequest_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->use_angles != other.use_angles) {
      return false;
    }
    if (this->joint_state != other.joint_state) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const ActuatorRequest_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ActuatorRequest_

// alias to use template instance with default allocator
using ActuatorRequest =
  prak_msgs::msg::ActuatorRequest_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace prak_msgs

#endif  // PRAK_MSGS__MSG__DETAIL__ACTUATOR_REQUEST__STRUCT_HPP_
