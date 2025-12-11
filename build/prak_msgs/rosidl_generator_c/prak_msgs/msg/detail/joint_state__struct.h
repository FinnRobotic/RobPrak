// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from prak_msgs:msg/JointState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/msg/joint_state.h"


#ifndef PRAK_MSGS__MSG__DETAIL__JOINT_STATE__STRUCT_H_
#define PRAK_MSGS__MSG__DETAIL__JOINT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/JointState in the package prak_msgs.
typedef struct prak_msgs__msg__JointState
{
  double shoulder_pan_joint;
  double shoulder_lift_joint;
  double elbow_joint;
  double wrist_1_joint;
  double wrist_2_joint;
  double wrist_3_joint;
} prak_msgs__msg__JointState;

// Struct for a sequence of prak_msgs__msg__JointState.
typedef struct prak_msgs__msg__JointState__Sequence
{
  prak_msgs__msg__JointState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} prak_msgs__msg__JointState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRAK_MSGS__MSG__DETAIL__JOINT_STATE__STRUCT_H_
