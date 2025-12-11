// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from prak_msgs:msg/JointState.idl
// generated code does not contain a copyright notice
#include "prak_msgs/msg/detail/joint_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "prak_msgs/msg/detail/joint_state__functions.h"
#include "prak_msgs/msg/detail/joint_state__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace prak_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_prak_msgs
cdr_serialize(
  const prak_msgs::msg::JointState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: shoulder_pan_joint
  cdr << ros_message.shoulder_pan_joint;

  // Member: shoulder_lift_joint
  cdr << ros_message.shoulder_lift_joint;

  // Member: elbow_joint
  cdr << ros_message.elbow_joint;

  // Member: wrist_1_joint
  cdr << ros_message.wrist_1_joint;

  // Member: wrist_2_joint
  cdr << ros_message.wrist_2_joint;

  // Member: wrist_3_joint
  cdr << ros_message.wrist_3_joint;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_prak_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  prak_msgs::msg::JointState & ros_message)
{
  // Member: shoulder_pan_joint
  cdr >> ros_message.shoulder_pan_joint;

  // Member: shoulder_lift_joint
  cdr >> ros_message.shoulder_lift_joint;

  // Member: elbow_joint
  cdr >> ros_message.elbow_joint;

  // Member: wrist_1_joint
  cdr >> ros_message.wrist_1_joint;

  // Member: wrist_2_joint
  cdr >> ros_message.wrist_2_joint;

  // Member: wrist_3_joint
  cdr >> ros_message.wrist_3_joint;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_prak_msgs
get_serialized_size(
  const prak_msgs::msg::JointState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: shoulder_pan_joint
  {
    size_t item_size = sizeof(ros_message.shoulder_pan_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: shoulder_lift_joint
  {
    size_t item_size = sizeof(ros_message.shoulder_lift_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: elbow_joint
  {
    size_t item_size = sizeof(ros_message.elbow_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: wrist_1_joint
  {
    size_t item_size = sizeof(ros_message.wrist_1_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: wrist_2_joint
  {
    size_t item_size = sizeof(ros_message.wrist_2_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: wrist_3_joint
  {
    size_t item_size = sizeof(ros_message.wrist_3_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_prak_msgs
max_serialized_size_JointState(
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

  // Member: shoulder_pan_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: shoulder_lift_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: elbow_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: wrist_1_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: wrist_2_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: wrist_3_joint
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
    using DataType = prak_msgs::msg::JointState;
    is_plain =
      (
      offsetof(DataType, wrist_3_joint) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_prak_msgs
cdr_serialize_key(
  const prak_msgs::msg::JointState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: shoulder_pan_joint
  cdr << ros_message.shoulder_pan_joint;

  // Member: shoulder_lift_joint
  cdr << ros_message.shoulder_lift_joint;

  // Member: elbow_joint
  cdr << ros_message.elbow_joint;

  // Member: wrist_1_joint
  cdr << ros_message.wrist_1_joint;

  // Member: wrist_2_joint
  cdr << ros_message.wrist_2_joint;

  // Member: wrist_3_joint
  cdr << ros_message.wrist_3_joint;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_prak_msgs
get_serialized_size_key(
  const prak_msgs::msg::JointState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: shoulder_pan_joint
  {
    size_t item_size = sizeof(ros_message.shoulder_pan_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: shoulder_lift_joint
  {
    size_t item_size = sizeof(ros_message.shoulder_lift_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: elbow_joint
  {
    size_t item_size = sizeof(ros_message.elbow_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: wrist_1_joint
  {
    size_t item_size = sizeof(ros_message.wrist_1_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: wrist_2_joint
  {
    size_t item_size = sizeof(ros_message.wrist_2_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: wrist_3_joint
  {
    size_t item_size = sizeof(ros_message.wrist_3_joint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_prak_msgs
max_serialized_size_key_JointState(
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

  // Member: shoulder_pan_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: shoulder_lift_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: elbow_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: wrist_1_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: wrist_2_joint
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: wrist_3_joint
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
    using DataType = prak_msgs::msg::JointState;
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
  auto typed_message =
    static_cast<const prak_msgs::msg::JointState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _JointState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<prak_msgs::msg::JointState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _JointState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const prak_msgs::msg::JointState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _JointState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_JointState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _JointState__callbacks = {
  "prak_msgs::msg",
  "JointState",
  _JointState__cdr_serialize,
  _JointState__cdr_deserialize,
  _JointState__get_serialized_size,
  _JointState__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _JointState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_JointState__callbacks,
  get_message_typesupport_handle_function,
  &prak_msgs__msg__JointState__get_type_hash,
  &prak_msgs__msg__JointState__get_type_description,
  &prak_msgs__msg__JointState__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace prak_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_prak_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<prak_msgs::msg::JointState>()
{
  return &prak_msgs::msg::typesupport_fastrtps_cpp::_JointState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, prak_msgs, msg, JointState)() {
  return &prak_msgs::msg::typesupport_fastrtps_cpp::_JointState__handle;
}

#ifdef __cplusplus
}
#endif
