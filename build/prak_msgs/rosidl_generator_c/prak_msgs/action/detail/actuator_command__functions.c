// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from prak_msgs:action/ActuatorCommand.idl
// generated code does not contain a copyright notice
#include "prak_msgs/action/detail/actuator_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `request`
#include "prak_msgs/msg/detail/actuator_request__functions.h"

bool
prak_msgs__action__ActuatorCommand_Goal__init(prak_msgs__action__ActuatorCommand_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // request
  if (!prak_msgs__msg__ActuatorRequest__init(&msg->request)) {
    prak_msgs__action__ActuatorCommand_Goal__fini(msg);
    return false;
  }
  return true;
}

void
prak_msgs__action__ActuatorCommand_Goal__fini(prak_msgs__action__ActuatorCommand_Goal * msg)
{
  if (!msg) {
    return;
  }
  // request
  prak_msgs__msg__ActuatorRequest__fini(&msg->request);
}

bool
prak_msgs__action__ActuatorCommand_Goal__are_equal(const prak_msgs__action__ActuatorCommand_Goal * lhs, const prak_msgs__action__ActuatorCommand_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // request
  if (!prak_msgs__msg__ActuatorRequest__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_Goal__copy(
  const prak_msgs__action__ActuatorCommand_Goal * input,
  prak_msgs__action__ActuatorCommand_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // request
  if (!prak_msgs__msg__ActuatorRequest__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  return true;
}

prak_msgs__action__ActuatorCommand_Goal *
prak_msgs__action__ActuatorCommand_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_Goal * msg = (prak_msgs__action__ActuatorCommand_Goal *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(prak_msgs__action__ActuatorCommand_Goal));
  bool success = prak_msgs__action__ActuatorCommand_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
prak_msgs__action__ActuatorCommand_Goal__destroy(prak_msgs__action__ActuatorCommand_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    prak_msgs__action__ActuatorCommand_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
prak_msgs__action__ActuatorCommand_Goal__Sequence__init(prak_msgs__action__ActuatorCommand_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_Goal * data = NULL;

  if (size) {
    data = (prak_msgs__action__ActuatorCommand_Goal *)allocator.zero_allocate(size, sizeof(prak_msgs__action__ActuatorCommand_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = prak_msgs__action__ActuatorCommand_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        prak_msgs__action__ActuatorCommand_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
prak_msgs__action__ActuatorCommand_Goal__Sequence__fini(prak_msgs__action__ActuatorCommand_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      prak_msgs__action__ActuatorCommand_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

prak_msgs__action__ActuatorCommand_Goal__Sequence *
prak_msgs__action__ActuatorCommand_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_Goal__Sequence * array = (prak_msgs__action__ActuatorCommand_Goal__Sequence *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = prak_msgs__action__ActuatorCommand_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
prak_msgs__action__ActuatorCommand_Goal__Sequence__destroy(prak_msgs__action__ActuatorCommand_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    prak_msgs__action__ActuatorCommand_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
prak_msgs__action__ActuatorCommand_Goal__Sequence__are_equal(const prak_msgs__action__ActuatorCommand_Goal__Sequence * lhs, const prak_msgs__action__ActuatorCommand_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_Goal__Sequence__copy(
  const prak_msgs__action__ActuatorCommand_Goal__Sequence * input,
  prak_msgs__action__ActuatorCommand_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(prak_msgs__action__ActuatorCommand_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    prak_msgs__action__ActuatorCommand_Goal * data =
      (prak_msgs__action__ActuatorCommand_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!prak_msgs__action__ActuatorCommand_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          prak_msgs__action__ActuatorCommand_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
prak_msgs__action__ActuatorCommand_Result__init(prak_msgs__action__ActuatorCommand_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    prak_msgs__action__ActuatorCommand_Result__fini(msg);
    return false;
  }
  return true;
}

void
prak_msgs__action__ActuatorCommand_Result__fini(prak_msgs__action__ActuatorCommand_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
prak_msgs__action__ActuatorCommand_Result__are_equal(const prak_msgs__action__ActuatorCommand_Result * lhs, const prak_msgs__action__ActuatorCommand_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_Result__copy(
  const prak_msgs__action__ActuatorCommand_Result * input,
  prak_msgs__action__ActuatorCommand_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

prak_msgs__action__ActuatorCommand_Result *
prak_msgs__action__ActuatorCommand_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_Result * msg = (prak_msgs__action__ActuatorCommand_Result *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(prak_msgs__action__ActuatorCommand_Result));
  bool success = prak_msgs__action__ActuatorCommand_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
prak_msgs__action__ActuatorCommand_Result__destroy(prak_msgs__action__ActuatorCommand_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    prak_msgs__action__ActuatorCommand_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
prak_msgs__action__ActuatorCommand_Result__Sequence__init(prak_msgs__action__ActuatorCommand_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_Result * data = NULL;

  if (size) {
    data = (prak_msgs__action__ActuatorCommand_Result *)allocator.zero_allocate(size, sizeof(prak_msgs__action__ActuatorCommand_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = prak_msgs__action__ActuatorCommand_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        prak_msgs__action__ActuatorCommand_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
prak_msgs__action__ActuatorCommand_Result__Sequence__fini(prak_msgs__action__ActuatorCommand_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      prak_msgs__action__ActuatorCommand_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

prak_msgs__action__ActuatorCommand_Result__Sequence *
prak_msgs__action__ActuatorCommand_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_Result__Sequence * array = (prak_msgs__action__ActuatorCommand_Result__Sequence *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = prak_msgs__action__ActuatorCommand_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
prak_msgs__action__ActuatorCommand_Result__Sequence__destroy(prak_msgs__action__ActuatorCommand_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    prak_msgs__action__ActuatorCommand_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
prak_msgs__action__ActuatorCommand_Result__Sequence__are_equal(const prak_msgs__action__ActuatorCommand_Result__Sequence * lhs, const prak_msgs__action__ActuatorCommand_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_Result__Sequence__copy(
  const prak_msgs__action__ActuatorCommand_Result__Sequence * input,
  prak_msgs__action__ActuatorCommand_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(prak_msgs__action__ActuatorCommand_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    prak_msgs__action__ActuatorCommand_Result * data =
      (prak_msgs__action__ActuatorCommand_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!prak_msgs__action__ActuatorCommand_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          prak_msgs__action__ActuatorCommand_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
prak_msgs__action__ActuatorCommand_Feedback__init(prak_msgs__action__ActuatorCommand_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // progress
  return true;
}

void
prak_msgs__action__ActuatorCommand_Feedback__fini(prak_msgs__action__ActuatorCommand_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // progress
}

bool
prak_msgs__action__ActuatorCommand_Feedback__are_equal(const prak_msgs__action__ActuatorCommand_Feedback * lhs, const prak_msgs__action__ActuatorCommand_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // progress
  if (lhs->progress != rhs->progress) {
    return false;
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_Feedback__copy(
  const prak_msgs__action__ActuatorCommand_Feedback * input,
  prak_msgs__action__ActuatorCommand_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // progress
  output->progress = input->progress;
  return true;
}

prak_msgs__action__ActuatorCommand_Feedback *
prak_msgs__action__ActuatorCommand_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_Feedback * msg = (prak_msgs__action__ActuatorCommand_Feedback *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(prak_msgs__action__ActuatorCommand_Feedback));
  bool success = prak_msgs__action__ActuatorCommand_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
prak_msgs__action__ActuatorCommand_Feedback__destroy(prak_msgs__action__ActuatorCommand_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    prak_msgs__action__ActuatorCommand_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
prak_msgs__action__ActuatorCommand_Feedback__Sequence__init(prak_msgs__action__ActuatorCommand_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_Feedback * data = NULL;

  if (size) {
    data = (prak_msgs__action__ActuatorCommand_Feedback *)allocator.zero_allocate(size, sizeof(prak_msgs__action__ActuatorCommand_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = prak_msgs__action__ActuatorCommand_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        prak_msgs__action__ActuatorCommand_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
prak_msgs__action__ActuatorCommand_Feedback__Sequence__fini(prak_msgs__action__ActuatorCommand_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      prak_msgs__action__ActuatorCommand_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

prak_msgs__action__ActuatorCommand_Feedback__Sequence *
prak_msgs__action__ActuatorCommand_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_Feedback__Sequence * array = (prak_msgs__action__ActuatorCommand_Feedback__Sequence *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = prak_msgs__action__ActuatorCommand_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
prak_msgs__action__ActuatorCommand_Feedback__Sequence__destroy(prak_msgs__action__ActuatorCommand_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    prak_msgs__action__ActuatorCommand_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
prak_msgs__action__ActuatorCommand_Feedback__Sequence__are_equal(const prak_msgs__action__ActuatorCommand_Feedback__Sequence * lhs, const prak_msgs__action__ActuatorCommand_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_Feedback__Sequence__copy(
  const prak_msgs__action__ActuatorCommand_Feedback__Sequence * input,
  prak_msgs__action__ActuatorCommand_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(prak_msgs__action__ActuatorCommand_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    prak_msgs__action__ActuatorCommand_Feedback * data =
      (prak_msgs__action__ActuatorCommand_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!prak_msgs__action__ActuatorCommand_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          prak_msgs__action__ActuatorCommand_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "prak_msgs/action/detail/actuator_command__functions.h"

bool
prak_msgs__action__ActuatorCommand_SendGoal_Request__init(prak_msgs__action__ActuatorCommand_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    prak_msgs__action__ActuatorCommand_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!prak_msgs__action__ActuatorCommand_Goal__init(&msg->goal)) {
    prak_msgs__action__ActuatorCommand_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
prak_msgs__action__ActuatorCommand_SendGoal_Request__fini(prak_msgs__action__ActuatorCommand_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  prak_msgs__action__ActuatorCommand_Goal__fini(&msg->goal);
}

bool
prak_msgs__action__ActuatorCommand_SendGoal_Request__are_equal(const prak_msgs__action__ActuatorCommand_SendGoal_Request * lhs, const prak_msgs__action__ActuatorCommand_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!prak_msgs__action__ActuatorCommand_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_SendGoal_Request__copy(
  const prak_msgs__action__ActuatorCommand_SendGoal_Request * input,
  prak_msgs__action__ActuatorCommand_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!prak_msgs__action__ActuatorCommand_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

prak_msgs__action__ActuatorCommand_SendGoal_Request *
prak_msgs__action__ActuatorCommand_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_SendGoal_Request * msg = (prak_msgs__action__ActuatorCommand_SendGoal_Request *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Request));
  bool success = prak_msgs__action__ActuatorCommand_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
prak_msgs__action__ActuatorCommand_SendGoal_Request__destroy(prak_msgs__action__ActuatorCommand_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    prak_msgs__action__ActuatorCommand_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence__init(prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_SendGoal_Request * data = NULL;

  if (size) {
    data = (prak_msgs__action__ActuatorCommand_SendGoal_Request *)allocator.zero_allocate(size, sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = prak_msgs__action__ActuatorCommand_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        prak_msgs__action__ActuatorCommand_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence__fini(prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      prak_msgs__action__ActuatorCommand_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence *
prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence * array = (prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence__destroy(prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence__are_equal(const prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence * lhs, const prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence__copy(
  const prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence * input,
  prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    prak_msgs__action__ActuatorCommand_SendGoal_Request * data =
      (prak_msgs__action__ActuatorCommand_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!prak_msgs__action__ActuatorCommand_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          prak_msgs__action__ActuatorCommand_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
prak_msgs__action__ActuatorCommand_SendGoal_Response__init(prak_msgs__action__ActuatorCommand_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    prak_msgs__action__ActuatorCommand_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
prak_msgs__action__ActuatorCommand_SendGoal_Response__fini(prak_msgs__action__ActuatorCommand_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
prak_msgs__action__ActuatorCommand_SendGoal_Response__are_equal(const prak_msgs__action__ActuatorCommand_SendGoal_Response * lhs, const prak_msgs__action__ActuatorCommand_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_SendGoal_Response__copy(
  const prak_msgs__action__ActuatorCommand_SendGoal_Response * input,
  prak_msgs__action__ActuatorCommand_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

prak_msgs__action__ActuatorCommand_SendGoal_Response *
prak_msgs__action__ActuatorCommand_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_SendGoal_Response * msg = (prak_msgs__action__ActuatorCommand_SendGoal_Response *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Response));
  bool success = prak_msgs__action__ActuatorCommand_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
prak_msgs__action__ActuatorCommand_SendGoal_Response__destroy(prak_msgs__action__ActuatorCommand_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    prak_msgs__action__ActuatorCommand_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence__init(prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_SendGoal_Response * data = NULL;

  if (size) {
    data = (prak_msgs__action__ActuatorCommand_SendGoal_Response *)allocator.zero_allocate(size, sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = prak_msgs__action__ActuatorCommand_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        prak_msgs__action__ActuatorCommand_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence__fini(prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      prak_msgs__action__ActuatorCommand_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence *
prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence * array = (prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence__destroy(prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence__are_equal(const prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence * lhs, const prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence__copy(
  const prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence * input,
  prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    prak_msgs__action__ActuatorCommand_SendGoal_Response * data =
      (prak_msgs__action__ActuatorCommand_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!prak_msgs__action__ActuatorCommand_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          prak_msgs__action__ActuatorCommand_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "prak_msgs/action/detail/actuator_command__functions.h"

bool
prak_msgs__action__ActuatorCommand_SendGoal_Event__init(prak_msgs__action__ActuatorCommand_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    prak_msgs__action__ActuatorCommand_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    prak_msgs__action__ActuatorCommand_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    prak_msgs__action__ActuatorCommand_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
prak_msgs__action__ActuatorCommand_SendGoal_Event__fini(prak_msgs__action__ActuatorCommand_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
prak_msgs__action__ActuatorCommand_SendGoal_Event__are_equal(const prak_msgs__action__ActuatorCommand_SendGoal_Event * lhs, const prak_msgs__action__ActuatorCommand_SendGoal_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_SendGoal_Event__copy(
  const prak_msgs__action__ActuatorCommand_SendGoal_Event * input,
  prak_msgs__action__ActuatorCommand_SendGoal_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!prak_msgs__action__ActuatorCommand_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!prak_msgs__action__ActuatorCommand_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

prak_msgs__action__ActuatorCommand_SendGoal_Event *
prak_msgs__action__ActuatorCommand_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_SendGoal_Event * msg = (prak_msgs__action__ActuatorCommand_SendGoal_Event *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Event));
  bool success = prak_msgs__action__ActuatorCommand_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
prak_msgs__action__ActuatorCommand_SendGoal_Event__destroy(prak_msgs__action__ActuatorCommand_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    prak_msgs__action__ActuatorCommand_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence__init(prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_SendGoal_Event * data = NULL;

  if (size) {
    data = (prak_msgs__action__ActuatorCommand_SendGoal_Event *)allocator.zero_allocate(size, sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = prak_msgs__action__ActuatorCommand_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        prak_msgs__action__ActuatorCommand_SendGoal_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence__fini(prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      prak_msgs__action__ActuatorCommand_SendGoal_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence *
prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence * array = (prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence__destroy(prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence__are_equal(const prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence * lhs, const prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence__copy(
  const prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence * input,
  prak_msgs__action__ActuatorCommand_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(prak_msgs__action__ActuatorCommand_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    prak_msgs__action__ActuatorCommand_SendGoal_Event * data =
      (prak_msgs__action__ActuatorCommand_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!prak_msgs__action__ActuatorCommand_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          prak_msgs__action__ActuatorCommand_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
prak_msgs__action__ActuatorCommand_GetResult_Request__init(prak_msgs__action__ActuatorCommand_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    prak_msgs__action__ActuatorCommand_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
prak_msgs__action__ActuatorCommand_GetResult_Request__fini(prak_msgs__action__ActuatorCommand_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
prak_msgs__action__ActuatorCommand_GetResult_Request__are_equal(const prak_msgs__action__ActuatorCommand_GetResult_Request * lhs, const prak_msgs__action__ActuatorCommand_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_GetResult_Request__copy(
  const prak_msgs__action__ActuatorCommand_GetResult_Request * input,
  prak_msgs__action__ActuatorCommand_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

prak_msgs__action__ActuatorCommand_GetResult_Request *
prak_msgs__action__ActuatorCommand_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_GetResult_Request * msg = (prak_msgs__action__ActuatorCommand_GetResult_Request *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(prak_msgs__action__ActuatorCommand_GetResult_Request));
  bool success = prak_msgs__action__ActuatorCommand_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
prak_msgs__action__ActuatorCommand_GetResult_Request__destroy(prak_msgs__action__ActuatorCommand_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    prak_msgs__action__ActuatorCommand_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence__init(prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_GetResult_Request * data = NULL;

  if (size) {
    data = (prak_msgs__action__ActuatorCommand_GetResult_Request *)allocator.zero_allocate(size, sizeof(prak_msgs__action__ActuatorCommand_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = prak_msgs__action__ActuatorCommand_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        prak_msgs__action__ActuatorCommand_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence__fini(prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      prak_msgs__action__ActuatorCommand_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence *
prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence * array = (prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence__destroy(prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence__are_equal(const prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence * lhs, const prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence__copy(
  const prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence * input,
  prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(prak_msgs__action__ActuatorCommand_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    prak_msgs__action__ActuatorCommand_GetResult_Request * data =
      (prak_msgs__action__ActuatorCommand_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!prak_msgs__action__ActuatorCommand_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          prak_msgs__action__ActuatorCommand_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "prak_msgs/action/detail/actuator_command__functions.h"

bool
prak_msgs__action__ActuatorCommand_GetResult_Response__init(prak_msgs__action__ActuatorCommand_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!prak_msgs__action__ActuatorCommand_Result__init(&msg->result)) {
    prak_msgs__action__ActuatorCommand_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
prak_msgs__action__ActuatorCommand_GetResult_Response__fini(prak_msgs__action__ActuatorCommand_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  prak_msgs__action__ActuatorCommand_Result__fini(&msg->result);
}

bool
prak_msgs__action__ActuatorCommand_GetResult_Response__are_equal(const prak_msgs__action__ActuatorCommand_GetResult_Response * lhs, const prak_msgs__action__ActuatorCommand_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!prak_msgs__action__ActuatorCommand_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_GetResult_Response__copy(
  const prak_msgs__action__ActuatorCommand_GetResult_Response * input,
  prak_msgs__action__ActuatorCommand_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!prak_msgs__action__ActuatorCommand_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

prak_msgs__action__ActuatorCommand_GetResult_Response *
prak_msgs__action__ActuatorCommand_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_GetResult_Response * msg = (prak_msgs__action__ActuatorCommand_GetResult_Response *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(prak_msgs__action__ActuatorCommand_GetResult_Response));
  bool success = prak_msgs__action__ActuatorCommand_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
prak_msgs__action__ActuatorCommand_GetResult_Response__destroy(prak_msgs__action__ActuatorCommand_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    prak_msgs__action__ActuatorCommand_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence__init(prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_GetResult_Response * data = NULL;

  if (size) {
    data = (prak_msgs__action__ActuatorCommand_GetResult_Response *)allocator.zero_allocate(size, sizeof(prak_msgs__action__ActuatorCommand_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = prak_msgs__action__ActuatorCommand_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        prak_msgs__action__ActuatorCommand_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence__fini(prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      prak_msgs__action__ActuatorCommand_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence *
prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence * array = (prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence__destroy(prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence__are_equal(const prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence * lhs, const prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence__copy(
  const prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence * input,
  prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(prak_msgs__action__ActuatorCommand_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    prak_msgs__action__ActuatorCommand_GetResult_Response * data =
      (prak_msgs__action__ActuatorCommand_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!prak_msgs__action__ActuatorCommand_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          prak_msgs__action__ActuatorCommand_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "prak_msgs/action/detail/actuator_command__functions.h"

bool
prak_msgs__action__ActuatorCommand_GetResult_Event__init(prak_msgs__action__ActuatorCommand_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    prak_msgs__action__ActuatorCommand_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence__init(&msg->request, 0)) {
    prak_msgs__action__ActuatorCommand_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence__init(&msg->response, 0)) {
    prak_msgs__action__ActuatorCommand_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
prak_msgs__action__ActuatorCommand_GetResult_Event__fini(prak_msgs__action__ActuatorCommand_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence__fini(&msg->request);
  // response
  prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence__fini(&msg->response);
}

bool
prak_msgs__action__ActuatorCommand_GetResult_Event__are_equal(const prak_msgs__action__ActuatorCommand_GetResult_Event * lhs, const prak_msgs__action__ActuatorCommand_GetResult_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_GetResult_Event__copy(
  const prak_msgs__action__ActuatorCommand_GetResult_Event * input,
  prak_msgs__action__ActuatorCommand_GetResult_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!prak_msgs__action__ActuatorCommand_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!prak_msgs__action__ActuatorCommand_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

prak_msgs__action__ActuatorCommand_GetResult_Event *
prak_msgs__action__ActuatorCommand_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_GetResult_Event * msg = (prak_msgs__action__ActuatorCommand_GetResult_Event *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(prak_msgs__action__ActuatorCommand_GetResult_Event));
  bool success = prak_msgs__action__ActuatorCommand_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
prak_msgs__action__ActuatorCommand_GetResult_Event__destroy(prak_msgs__action__ActuatorCommand_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    prak_msgs__action__ActuatorCommand_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence__init(prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_GetResult_Event * data = NULL;

  if (size) {
    data = (prak_msgs__action__ActuatorCommand_GetResult_Event *)allocator.zero_allocate(size, sizeof(prak_msgs__action__ActuatorCommand_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = prak_msgs__action__ActuatorCommand_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        prak_msgs__action__ActuatorCommand_GetResult_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence__fini(prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      prak_msgs__action__ActuatorCommand_GetResult_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence *
prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence * array = (prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence__destroy(prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence__are_equal(const prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence * lhs, const prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence__copy(
  const prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence * input,
  prak_msgs__action__ActuatorCommand_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(prak_msgs__action__ActuatorCommand_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    prak_msgs__action__ActuatorCommand_GetResult_Event * data =
      (prak_msgs__action__ActuatorCommand_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!prak_msgs__action__ActuatorCommand_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          prak_msgs__action__ActuatorCommand_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "prak_msgs/action/detail/actuator_command__functions.h"

bool
prak_msgs__action__ActuatorCommand_FeedbackMessage__init(prak_msgs__action__ActuatorCommand_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    prak_msgs__action__ActuatorCommand_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!prak_msgs__action__ActuatorCommand_Feedback__init(&msg->feedback)) {
    prak_msgs__action__ActuatorCommand_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
prak_msgs__action__ActuatorCommand_FeedbackMessage__fini(prak_msgs__action__ActuatorCommand_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  prak_msgs__action__ActuatorCommand_Feedback__fini(&msg->feedback);
}

bool
prak_msgs__action__ActuatorCommand_FeedbackMessage__are_equal(const prak_msgs__action__ActuatorCommand_FeedbackMessage * lhs, const prak_msgs__action__ActuatorCommand_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!prak_msgs__action__ActuatorCommand_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_FeedbackMessage__copy(
  const prak_msgs__action__ActuatorCommand_FeedbackMessage * input,
  prak_msgs__action__ActuatorCommand_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!prak_msgs__action__ActuatorCommand_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

prak_msgs__action__ActuatorCommand_FeedbackMessage *
prak_msgs__action__ActuatorCommand_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_FeedbackMessage * msg = (prak_msgs__action__ActuatorCommand_FeedbackMessage *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(prak_msgs__action__ActuatorCommand_FeedbackMessage));
  bool success = prak_msgs__action__ActuatorCommand_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
prak_msgs__action__ActuatorCommand_FeedbackMessage__destroy(prak_msgs__action__ActuatorCommand_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    prak_msgs__action__ActuatorCommand_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence__init(prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_FeedbackMessage * data = NULL;

  if (size) {
    data = (prak_msgs__action__ActuatorCommand_FeedbackMessage *)allocator.zero_allocate(size, sizeof(prak_msgs__action__ActuatorCommand_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = prak_msgs__action__ActuatorCommand_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        prak_msgs__action__ActuatorCommand_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence__fini(prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      prak_msgs__action__ActuatorCommand_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence *
prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence * array = (prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence *)allocator.allocate(sizeof(prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence__destroy(prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence__are_equal(const prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence * lhs, const prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence__copy(
  const prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence * input,
  prak_msgs__action__ActuatorCommand_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(prak_msgs__action__ActuatorCommand_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    prak_msgs__action__ActuatorCommand_FeedbackMessage * data =
      (prak_msgs__action__ActuatorCommand_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!prak_msgs__action__ActuatorCommand_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          prak_msgs__action__ActuatorCommand_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!prak_msgs__action__ActuatorCommand_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
