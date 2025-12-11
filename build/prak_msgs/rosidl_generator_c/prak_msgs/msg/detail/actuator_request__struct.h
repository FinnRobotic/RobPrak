// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from prak_msgs:msg/ActuatorRequest.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/msg/actuator_request.h"


#ifndef PRAK_MSGS__MSG__DETAIL__ACTUATOR_REQUEST__STRUCT_H_
#define PRAK_MSGS__MSG__DETAIL__ACTUATOR_REQUEST__STRUCT_H_

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
#include "prak_msgs/msg/detail/joint_state__struct.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/ActuatorRequest in the package prak_msgs.
typedef struct prak_msgs__msg__ActuatorRequest
{
  /// Timestamp of message and frame of message
  std_msgs__msg__Header header;
  bool use_angles;
  prak_msgs__msg__JointState joint_state;
  geometry_msgs__msg__Pose pose;
} prak_msgs__msg__ActuatorRequest;

// Struct for a sequence of prak_msgs__msg__ActuatorRequest.
typedef struct prak_msgs__msg__ActuatorRequest__Sequence
{
  prak_msgs__msg__ActuatorRequest * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} prak_msgs__msg__ActuatorRequest__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRAK_MSGS__MSG__DETAIL__ACTUATOR_REQUEST__STRUCT_H_
