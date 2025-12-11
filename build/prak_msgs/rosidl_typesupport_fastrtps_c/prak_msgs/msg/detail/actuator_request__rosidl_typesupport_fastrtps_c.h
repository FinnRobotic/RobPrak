// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from prak_msgs:msg/ActuatorRequest.idl
// generated code does not contain a copyright notice
#ifndef PRAK_MSGS__MSG__DETAIL__ACTUATOR_REQUEST__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define PRAK_MSGS__MSG__DETAIL__ACTUATOR_REQUEST__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "prak_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "prak_msgs/msg/detail/actuator_request__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
bool cdr_serialize_prak_msgs__msg__ActuatorRequest(
  const prak_msgs__msg__ActuatorRequest * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
bool cdr_deserialize_prak_msgs__msg__ActuatorRequest(
  eprosima::fastcdr::Cdr &,
  prak_msgs__msg__ActuatorRequest * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
size_t get_serialized_size_prak_msgs__msg__ActuatorRequest(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
size_t max_serialized_size_prak_msgs__msg__ActuatorRequest(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
bool cdr_serialize_key_prak_msgs__msg__ActuatorRequest(
  const prak_msgs__msg__ActuatorRequest * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
size_t get_serialized_size_key_prak_msgs__msg__ActuatorRequest(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
size_t max_serialized_size_key_prak_msgs__msg__ActuatorRequest(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, prak_msgs, msg, ActuatorRequest)();

#ifdef __cplusplus
}
#endif

#endif  // PRAK_MSGS__MSG__DETAIL__ACTUATOR_REQUEST__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
