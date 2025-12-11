// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from prak_msgs:msg/JointStateStamped.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/msg/joint_state_stamped.h"


#ifndef PRAK_MSGS__MSG__DETAIL__JOINT_STATE_STAMPED__STRUCT_H_
#define PRAK_MSGS__MSG__DETAIL__JOINT_STATE_STAMPED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'joint_state'
#include "prak_msgs/msg/detail/joint_state__struct.h"

/// Struct defined in msg/JointStateStamped in the package prak_msgs.
typedef struct prak_msgs__msg__JointStateStamped
{
  builtin_interfaces__msg__Time stamp;
  prak_msgs__msg__JointState joint_state;
} prak_msgs__msg__JointStateStamped;

// Struct for a sequence of prak_msgs__msg__JointStateStamped.
typedef struct prak_msgs__msg__JointStateStamped__Sequence
{
  prak_msgs__msg__JointStateStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} prak_msgs__msg__JointStateStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRAK_MSGS__MSG__DETAIL__JOINT_STATE_STAMPED__STRUCT_H_
