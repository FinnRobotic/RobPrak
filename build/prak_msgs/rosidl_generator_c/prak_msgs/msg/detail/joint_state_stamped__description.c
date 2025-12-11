// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from prak_msgs:msg/JointStateStamped.idl
// generated code does not contain a copyright notice

#include "prak_msgs/msg/detail/joint_state_stamped__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_prak_msgs
const rosidl_type_hash_t *
prak_msgs__msg__JointStateStamped__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x80, 0xe2, 0x24, 0x4e, 0x28, 0x89, 0x05, 0xa5,
      0xcd, 0x8b, 0x9c, 0xae, 0x7c, 0x39, 0x86, 0x9a,
      0x1c, 0x24, 0xd4, 0x24, 0xea, 0xba, 0x7a, 0xa5,
      0x4d, 0x2f, 0x3e, 0xae, 0xed, 0x41, 0xa7, 0x47,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "prak_msgs/msg/detail/joint_state__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t prak_msgs__msg__JointState__EXPECTED_HASH = {1, {
    0xdd, 0xb3, 0xcb, 0x56, 0x8e, 0x09, 0x02, 0x84,
    0x4a, 0x2e, 0x96, 0x21, 0x91, 0x55, 0xec, 0xed,
    0x32, 0x95, 0x52, 0x9e, 0xe1, 0x21, 0x4d, 0x50,
    0xd9, 0xf5, 0x0f, 0x10, 0x61, 0xba, 0x68, 0x66,
  }};
#endif

static char prak_msgs__msg__JointStateStamped__TYPE_NAME[] = "prak_msgs/msg/JointStateStamped";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char prak_msgs__msg__JointState__TYPE_NAME[] = "prak_msgs/msg/JointState";

// Define type names, field names, and default values
static char prak_msgs__msg__JointStateStamped__FIELD_NAME__stamp[] = "stamp";
static char prak_msgs__msg__JointStateStamped__FIELD_NAME__joint_state[] = "joint_state";

static rosidl_runtime_c__type_description__Field prak_msgs__msg__JointStateStamped__FIELDS[] = {
  {
    {prak_msgs__msg__JointStateStamped__FIELD_NAME__stamp, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
  {
    {prak_msgs__msg__JointStateStamped__FIELD_NAME__joint_state, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {prak_msgs__msg__JointState__TYPE_NAME, 24, 24},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription prak_msgs__msg__JointStateStamped__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {prak_msgs__msg__JointState__TYPE_NAME, 24, 24},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
prak_msgs__msg__JointStateStamped__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {prak_msgs__msg__JointStateStamped__TYPE_NAME, 31, 31},
      {prak_msgs__msg__JointStateStamped__FIELDS, 2, 2},
    },
    {prak_msgs__msg__JointStateStamped__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&prak_msgs__msg__JointState__EXPECTED_HASH, prak_msgs__msg__JointState__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = prak_msgs__msg__JointState__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "  \n"
  "\n"
  "builtin_interfaces/Time stamp\n"
  "\n"
  "prak_msgs/JointState joint_state";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
prak_msgs__msg__JointStateStamped__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {prak_msgs__msg__JointStateStamped__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 67, 67},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
prak_msgs__msg__JointStateStamped__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *prak_msgs__msg__JointStateStamped__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *prak_msgs__msg__JointState__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
