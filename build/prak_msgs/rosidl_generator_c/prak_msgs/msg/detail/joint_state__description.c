// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from prak_msgs:msg/JointState.idl
// generated code does not contain a copyright notice

#include "prak_msgs/msg/detail/joint_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_prak_msgs
const rosidl_type_hash_t *
prak_msgs__msg__JointState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xdd, 0xb3, 0xcb, 0x56, 0x8e, 0x09, 0x02, 0x84,
      0x4a, 0x2e, 0x96, 0x21, 0x91, 0x55, 0xec, 0xed,
      0x32, 0x95, 0x52, 0x9e, 0xe1, 0x21, 0x4d, 0x50,
      0xd9, 0xf5, 0x0f, 0x10, 0x61, 0xba, 0x68, 0x66,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char prak_msgs__msg__JointState__TYPE_NAME[] = "prak_msgs/msg/JointState";

// Define type names, field names, and default values
static char prak_msgs__msg__JointState__FIELD_NAME__shoulder_pan_joint[] = "shoulder_pan_joint";
static char prak_msgs__msg__JointState__FIELD_NAME__shoulder_lift_joint[] = "shoulder_lift_joint";
static char prak_msgs__msg__JointState__FIELD_NAME__elbow_joint[] = "elbow_joint";
static char prak_msgs__msg__JointState__FIELD_NAME__wrist_1_joint[] = "wrist_1_joint";
static char prak_msgs__msg__JointState__FIELD_NAME__wrist_2_joint[] = "wrist_2_joint";
static char prak_msgs__msg__JointState__FIELD_NAME__wrist_3_joint[] = "wrist_3_joint";

static rosidl_runtime_c__type_description__Field prak_msgs__msg__JointState__FIELDS[] = {
  {
    {prak_msgs__msg__JointState__FIELD_NAME__shoulder_pan_joint, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {prak_msgs__msg__JointState__FIELD_NAME__shoulder_lift_joint, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {prak_msgs__msg__JointState__FIELD_NAME__elbow_joint, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {prak_msgs__msg__JointState__FIELD_NAME__wrist_1_joint, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {prak_msgs__msg__JointState__FIELD_NAME__wrist_2_joint, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {prak_msgs__msg__JointState__FIELD_NAME__wrist_3_joint, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
prak_msgs__msg__JointState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {prak_msgs__msg__JointState__TYPE_NAME, 24, 24},
      {prak_msgs__msg__JointState__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "  \n"
  "float64 shoulder_pan_joint\n"
  "\n"
  "float64 shoulder_lift_joint\n"
  "\n"
  "float64 elbow_joint\n"
  "\n"
  "float64 wrist_1_joint\n"
  "\n"
  "float64 wrist_2_joint\n"
  "\n"
  "float64 wrist_3_joint";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
prak_msgs__msg__JointState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {prak_msgs__msg__JointState__TYPE_NAME, 24, 24},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 148, 148},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
prak_msgs__msg__JointState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *prak_msgs__msg__JointState__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
