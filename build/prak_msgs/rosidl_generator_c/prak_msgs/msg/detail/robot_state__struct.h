// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from prak_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/msg/robot_state.h"


#ifndef PRAK_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
#define PRAK_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'joint_state'
#include "prak_msgs/msg/detail/joint_state_stamped__struct.h"
// Member 'tcp_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in msg/RobotState in the package prak_msgs.
typedef struct prak_msgs__msg__RobotState
{
  std_msgs__msg__Header header;
  prak_msgs__msg__JointStateStamped joint_state;
  geometry_msgs__msg__PoseStamped tcp_pose;
} prak_msgs__msg__RobotState;

// Struct for a sequence of prak_msgs__msg__RobotState.
typedef struct prak_msgs__msg__RobotState__Sequence
{
  prak_msgs__msg__RobotState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} prak_msgs__msg__RobotState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRAK_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
