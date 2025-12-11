// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from prak_msgs:msg/JointState.idl
// generated code does not contain a copyright notice
#include "prak_msgs/msg/detail/joint_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "prak_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "prak_msgs/msg/detail/joint_state__struct.h"
#include "prak_msgs/msg/detail/joint_state__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _JointState__ros_msg_type = prak_msgs__msg__JointState;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
bool cdr_serialize_prak_msgs__msg__JointState(
  const prak_msgs__msg__JointState * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: shoulder_pan_joint
  {
    cdr << ros_message->shoulder_pan_joint;
  }

  // Field name: shoulder_lift_joint
  {
    cdr << ros_message->shoulder_lift_joint;
  }

  // Field name: elbow_joint
  {
    cdr << ros_message->elbow_joint;
  }

  // Field name: wrist_1_joint
  {
    cdr << ros_message->wrist_1_joint;
  }

  // Field name: wrist_2_joint
  {
    cdr << ros_message->wrist_2_joint;
  }

  // Field name: wrist_3_joint
  {
    cdr << ros_message->wrist_3_joint;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
bool cdr_deserialize_prak_msgs__msg__JointState(
  eprosima::fastcdr::Cdr & cdr,
  prak_msgs__msg__JointState * ros_message)
{
  // Field name: shoulder_pan_joint
  {
    cdr >> ros_message->shoulder_pan_joint;
  }

  // Field name: shoulder_lift_joint
  {
    cdr >> ros_message->shoulder_lift_joint;
  }

  // Field name: elbow_joint
  {
    cdr >> ros_message->elbow_joint;
  }

  // Field name: wrist_1_joint
  {
    cdr >> ros_message->wrist_1_joint;
  }

  // Field name: wrist_2_joint
  {
    cdr >> ros_message->wrist_2_joint;
  }

  // Field name: wrist_3_joint
  {
    cdr >> ros_message->wrist_3_joint;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
size_t get_serialized_size_prak_msgs__msg__JointState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _JointState__ros_msg_type * ros_message = static_cast<const _JointState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: shoulder_pan_joint
  {
    size_t item_size = sizeof(ros_message->shoulder_pan_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: shoulder_lift_joint
  {
    size_t item_size = sizeof(ros_message->shoulder_lift_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: elbow_joint
  {
    size_t item_size = sizeof(ros_message->elbow_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: wrist_1_joint
  {
    size_t item_size = sizeof(ros_message->wrist_1_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: wrist_2_joint
  {
    size_t item_size = sizeof(ros_message->wrist_2_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: wrist_3_joint
  {
    size_t item_size = sizeof(ros_message->wrist_3_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
size_t max_serialized_size_prak_msgs__msg__JointState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: shoulder_pan_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: shoulder_lift_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: elbow_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: wrist_1_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: wrist_2_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: wrist_3_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = prak_msgs__msg__JointState;
    is_plain =
      (
      offsetof(DataType, wrist_3_joint) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
bool cdr_serialize_key_prak_msgs__msg__JointState(
  const prak_msgs__msg__JointState * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: shoulder_pan_joint
  {
    cdr << ros_message->shoulder_pan_joint;
  }

  // Field name: shoulder_lift_joint
  {
    cdr << ros_message->shoulder_lift_joint;
  }

  // Field name: elbow_joint
  {
    cdr << ros_message->elbow_joint;
  }

  // Field name: wrist_1_joint
  {
    cdr << ros_message->wrist_1_joint;
  }

  // Field name: wrist_2_joint
  {
    cdr << ros_message->wrist_2_joint;
  }

  // Field name: wrist_3_joint
  {
    cdr << ros_message->wrist_3_joint;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
size_t get_serialized_size_key_prak_msgs__msg__JointState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _JointState__ros_msg_type * ros_message = static_cast<const _JointState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: shoulder_pan_joint
  {
    size_t item_size = sizeof(ros_message->shoulder_pan_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: shoulder_lift_joint
  {
    size_t item_size = sizeof(ros_message->shoulder_lift_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: elbow_joint
  {
    size_t item_size = sizeof(ros_message->elbow_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: wrist_1_joint
  {
    size_t item_size = sizeof(ros_message->wrist_1_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: wrist_2_joint
  {
    size_t item_size = sizeof(ros_message->wrist_2_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: wrist_3_joint
  {
    size_t item_size = sizeof(ros_message->wrist_3_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_prak_msgs
size_t max_serialized_size_key_prak_msgs__msg__JointState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: shoulder_pan_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: shoulder_lift_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: elbow_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: wrist_1_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: wrist_2_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: wrist_3_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = prak_msgs__msg__JointState;
    is_plain =
      (
      offsetof(DataType, wrist_3_joint) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _JointState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const prak_msgs__msg__JointState * ros_message = static_cast<const prak_msgs__msg__JointState *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_prak_msgs__msg__JointState(ros_message, cdr);
}

static bool _JointState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  prak_msgs__msg__JointState * ros_message = static_cast<prak_msgs__msg__JointState *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_prak_msgs__msg__JointState(cdr, ros_message);
}

static uint32_t _JointState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_prak_msgs__msg__JointState(
      untyped_ros_message, 0));
}

static size_t _JointState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_prak_msgs__msg__JointState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_JointState = {
  "prak_msgs::msg",
  "JointState",
  _JointState__cdr_serialize,
  _JointState__cdr_deserialize,
  _JointState__get_serialized_size,
  _JointState__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _JointState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_JointState,
  get_message_typesupport_handle_function,
  &prak_msgs__msg__JointState__get_type_hash,
  &prak_msgs__msg__JointState__get_type_description,
  &prak_msgs__msg__JointState__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, prak_msgs, msg, JointState)() {
  return &_JointState__type_support;
}

#if defined(__cplusplus)
}
#endif
