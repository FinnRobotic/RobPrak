// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from prak_msgs:action/ActuatorCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "prak_msgs/action/actuator_command.h"


#ifndef PRAK_MSGS__ACTION__DETAIL__ACTUATOR_COMMAND__STRUCT_H_
#define PRAK_MSGS__ACTION__DETAIL__ACTUATOR_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'request'
#include "prak_msgs/msg/detail/actuator_request__struct.h"

/// Struct defined in action/ActuatorCommand in the package prak_msgs.
typedef struct prak_msgs__action__ActuatorCommand_Goal
{
  prak_msgs__msg__ActuatorRequest request;
} prak_msgs__action__ActuatorCommand_Goal;

// Struct for a sequence of prak_msgs__action__ActuatorCommand_Goal.
typedef struct prak_msgs__action__ActuatorCommand_Goal__Sequence
{
  prak_msgs__action__ActuatorCommand_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} prak_msgs__action__ActuatorCommand_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/ActuatorCommand in the package prak_msgs.
typedef struct prak_msgs__action__ActuatorCommand_Result
{
  bool success;
  rosidl_runtime_c__String message;
} prak_msgs__action__ActuatorCommand_Result;

// Struct for a sequence of prak_msgs__action__ActuatorCommand_Result.
typedef struct prak_msgs__action__ActuatorCommand_Result__Sequence
{
  prak_msgs__action__ActuatorCommand_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} prak_msgs__action__ActuatorCommand_Result__Sequence;

// Constants defined in the message

/// Struct defined in action/ActuatorCommand in the package prak_msgs.
typedef struct prak_msgs__action__ActuatorCommand_Feedback
{
  float progress;
} prak_msgs__action__ActuatorCommand_Feedback;

// Struct for a sequence of prak_msgs__action__ActuatorCommand_Feedback.
typedef struct prak_msgs__action__ActuatorCommand_Feedback__Sequence
{
  prak_msgs__action__ActuatorCommand_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} prak_msgs__action__ActuatorCommand_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "prak_msgs/action/detail/actuator_command__struct.h"

/// Struct defined in action/ActuatorCommand in the package prak_msgs.
typedef struct prak_msgs__action__ActuatorCommand_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  prak_msgs__action__ActuatorCommand_Goal goal;
} prak_msgs__action__ActuatorCommand_SendGoal_Request;

// Struct for a sequence of prak_msgs__action__ActuatorCommand_SendGoal_Request.
typedef struct prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence
{
  prak_msgs__action__ActuatorCommand_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ActuatorCommand in the package prak_msgs.
typedef struct prak_msgs__action__ActuatorCommand_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} prak_msgs__action__ActuatorCommand_SendGoal_Response;

// Struct for a sequence of prak_msgs__action__ActuatorCommand_SendGoal_Response.
typedef struct prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence
{
  prak_msgs__action__ActuatorCommand_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  prak_msgs__action__ActuatorCommand_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  prak_msgs__action__ActuatorCommand_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/ActuatorCommand in the package prak_msgs.
typedef struct prak_msgs__action__ActuatorCommand_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence request;
  prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence response;
} prak_msgs__action__ActuatorCommand_SendGoal_Event;

// Struct for a sequence of prak_msgs__action__ActuatorCommand_SendGoal_Event.
typedef struct prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence
{
  prak_msgs__action__ActuatorCommand_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ActuatorCommand in the package prak_msgs.
typedef struct prak_msgs__action__ActuatorCommand_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} prak_msgs__action__ActuatorCommand_GetResult_Request;

// Struct for a sequence of prak_msgs__action__ActuatorCommand_GetResult_Request.
typedef struct prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence
{
  prak_msgs__action__ActuatorCommand_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "prak_msgs/action/detail/actuator_command__struct.h"

/// Struct defined in action/ActuatorCommand in the package prak_msgs.
typedef struct prak_msgs__action__ActuatorCommand_GetResult_Response
{
  int8_t status;
  prak_msgs__action__ActuatorCommand_Result result;
} prak_msgs__action__ActuatorCommand_GetResult_Response;

// Struct for a sequence of prak_msgs__action__ActuatorCommand_GetResult_Response.
typedef struct prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence
{
  prak_msgs__action__ActuatorCommand_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  prak_msgs__action__ActuatorCommand_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  prak_msgs__action__ActuatorCommand_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/ActuatorCommand in the package prak_msgs.
typedef struct prak_msgs__action__ActuatorCommand_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence request;
  prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence response;
} prak_msgs__action__ActuatorCommand_GetResult_Event;

// Struct for a sequence of prak_msgs__action__ActuatorCommand_GetResult_Event.
typedef struct prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence
{
  prak_msgs__action__ActuatorCommand_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "prak_msgs/action/detail/actuator_command__struct.h"

/// Struct defined in action/ActuatorCommand in the package prak_msgs.
typedef struct prak_msgs__action__ActuatorCommand_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  prak_msgs__action__ActuatorCommand_Feedback feedback;
} prak_msgs__action__ActuatorCommand_FeedbackMessage;

// Struct for a sequence of prak_msgs__action__ActuatorCommand_FeedbackMessage.
typedef struct prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence
{
  prak_msgs__action__ActuatorCommand_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRAK_MSGS__ACTION__DETAIL__ACTUATOR_COMMAND__STRUCT_H_
