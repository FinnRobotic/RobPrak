// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from prak_msgs:msg/JointStateStamped.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "prak_msgs/msg/detail/joint_state_stamped__rosidl_typesupport_introspection_c.h"
#include "prak_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "prak_msgs/msg/detail/joint_state_stamped__functions.h"
#include "prak_msgs/msg/detail/joint_state_stamped__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `joint_state`
#include "prak_msgs/msg/joint_state.h"
// Member `joint_state`
#include "prak_msgs/msg/detail/joint_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void prak_msgs__msg__JointStateStamped__rosidl_typesupport_introspection_c__JointStateStamped_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  prak_msgs__msg__JointStateStamped__init(message_memory);
}

void prak_msgs__msg__JointStateStamped__rosidl_typesupport_introspection_c__JointStateStamped_fini_function(void * message_memory)
{
  prak_msgs__msg__JointStateStamped__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember prak_msgs__msg__JointStateStamped__rosidl_typesupport_introspection_c__JointStateStamped_message_member_array[2] = {
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(prak_msgs__msg__JointStateStamped, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(prak_msgs__msg__JointStateStamped, joint_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers prak_msgs__msg__JointStateStamped__rosidl_typesupport_introspection_c__JointStateStamped_message_members = {
  "prak_msgs__msg",  // message namespace
  "JointStateStamped",  // message name
  2,  // number of fields
  sizeof(prak_msgs__msg__JointStateStamped),
  false,  // has_any_key_member_
  prak_msgs__msg__JointStateStamped__rosidl_typesupport_introspection_c__JointStateStamped_message_member_array,  // message members
  prak_msgs__msg__JointStateStamped__rosidl_typesupport_introspection_c__JointStateStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  prak_msgs__msg__JointStateStamped__rosidl_typesupport_introspection_c__JointStateStamped_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t prak_msgs__msg__JointStateStamped__rosidl_typesupport_introspection_c__JointStateStamped_message_type_support_handle = {
  0,
  &prak_msgs__msg__JointStateStamped__rosidl_typesupport_introspection_c__JointStateStamped_message_members,
  get_message_typesupport_handle_function,
  &prak_msgs__msg__JointStateStamped__get_type_hash,
  &prak_msgs__msg__JointStateStamped__get_type_description,
  &prak_msgs__msg__JointStateStamped__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_prak_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, prak_msgs, msg, JointStateStamped)() {
  prak_msgs__msg__JointStateStamped__rosidl_typesupport_introspection_c__JointStateStamped_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  prak_msgs__msg__JointStateStamped__rosidl_typesupport_introspection_c__JointStateStamped_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, prak_msgs, msg, JointState)();
  if (!prak_msgs__msg__JointStateStamped__rosidl_typesupport_introspection_c__JointStateStamped_message_type_support_handle.typesupport_identifier) {
    prak_msgs__msg__JointStateStamped__rosidl_typesupport_introspection_c__JointStateStamped_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &prak_msgs__msg__JointStateStamped__rosidl_typesupport_introspection_c__JointStateStamped_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
