// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from prak_msgs:msg/JointStateStamped.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "prak_msgs/msg/detail/joint_state_stamped__functions.h"
#include "prak_msgs/msg/detail/joint_state_stamped__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace prak_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void JointStateStamped_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) prak_msgs::msg::JointStateStamped(_init);
}

void JointStateStamped_fini_function(void * message_memory)
{
  auto typed_message = static_cast<prak_msgs::msg::JointStateStamped *>(message_memory);
  typed_message->~JointStateStamped();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember JointStateStamped_message_member_array[2] = {
  {
    "stamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(prak_msgs::msg::JointStateStamped, stamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "joint_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<prak_msgs::msg::JointState>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(prak_msgs::msg::JointStateStamped, joint_state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers JointStateStamped_message_members = {
  "prak_msgs::msg",  // message namespace
  "JointStateStamped",  // message name
  2,  // number of fields
  sizeof(prak_msgs::msg::JointStateStamped),
  false,  // has_any_key_member_
  JointStateStamped_message_member_array,  // message members
  JointStateStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  JointStateStamped_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t JointStateStamped_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &JointStateStamped_message_members,
  get_message_typesupport_handle_function,
  &prak_msgs__msg__JointStateStamped__get_type_hash,
  &prak_msgs__msg__JointStateStamped__get_type_description,
  &prak_msgs__msg__JointStateStamped__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace prak_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<prak_msgs::msg::JointStateStamped>()
{
  return &::prak_msgs::msg::rosidl_typesupport_introspection_cpp::JointStateStamped_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, prak_msgs, msg, JointStateStamped)() {
  return &::prak_msgs::msg::rosidl_typesupport_introspection_cpp::JointStateStamped_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
