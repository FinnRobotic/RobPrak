// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from prak_msgs:msg/JointStateStamped.idl
// generated code does not contain a copyright notice
#include "prak_msgs/msg/detail/joint_state_stamped__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `joint_state`
#include "prak_msgs/msg/detail/joint_state__functions.h"

bool
prak_msgs__msg__JointStateStamped__init(prak_msgs__msg__JointStateStamped * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    prak_msgs__msg__JointStateStamped__fini(msg);
    return false;
  }
  // joint_state
  if (!prak_msgs__msg__JointState__init(&msg->joint_state)) {
    prak_msgs__msg__JointStateStamped__fini(msg);
    return false;
  }
  return true;
}

void
prak_msgs__msg__JointStateStamped__fini(prak_msgs__msg__JointStateStamped * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // joint_state
  prak_msgs__msg__JointState__fini(&msg->joint_state);
}

bool
prak_msgs__msg__JointStateStamped__are_equal(const prak_msgs__msg__JointStateStamped * lhs, const prak_msgs__msg__JointStateStamped * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  // joint_state
  if (!prak_msgs__msg__JointState__are_equal(
      &(lhs->joint_state), &(rhs->joint_state)))
  {
    return false;
  }
  return true;
}

bool
prak_msgs__msg__JointStateStamped__copy(
  const prak_msgs__msg__JointStateStamped * input,
  prak_msgs__msg__JointStateStamped * output)
{
  if (!input || !output) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  // joint_state
  if (!prak_msgs__msg__JointState__copy(
      &(input->joint_state), &(output->joint_state)))
  {
    return false;
  }
  return true;
}

prak_msgs__msg__JointStateStamped *
prak_msgs__msg__JointStateStamped__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__msg__JointStateStamped * msg = (prak_msgs__msg__JointStateStamped *)allocator.allocate(sizeof(prak_msgs__msg__JointStateStamped), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(prak_msgs__msg__JointStateStamped));
  bool success = prak_msgs__msg__JointStateStamped__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
prak_msgs__msg__JointStateStamped__destroy(prak_msgs__msg__JointStateStamped * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    prak_msgs__msg__JointStateStamped__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
prak_msgs__msg__JointStateStamped__Sequence__init(prak_msgs__msg__JointStateStamped__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__msg__JointStateStamped * data = NULL;

  if (size) {
    data = (prak_msgs__msg__JointStateStamped *)allocator.zero_allocate(size, sizeof(prak_msgs__msg__JointStateStamped), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = prak_msgs__msg__JointStateStamped__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        prak_msgs__msg__JointStateStamped__fini(&data[i - 1]);
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
prak_msgs__msg__JointStateStamped__Sequence__fini(prak_msgs__msg__JointStateStamped__Sequence * array)
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
      prak_msgs__msg__JointStateStamped__fini(&array->data[i]);
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

prak_msgs__msg__JointStateStamped__Sequence *
prak_msgs__msg__JointStateStamped__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__msg__JointStateStamped__Sequence * array = (prak_msgs__msg__JointStateStamped__Sequence *)allocator.allocate(sizeof(prak_msgs__msg__JointStateStamped__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = prak_msgs__msg__JointStateStamped__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
prak_msgs__msg__JointStateStamped__Sequence__destroy(prak_msgs__msg__JointStateStamped__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    prak_msgs__msg__JointStateStamped__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
prak_msgs__msg__JointStateStamped__Sequence__are_equal(const prak_msgs__msg__JointStateStamped__Sequence * lhs, const prak_msgs__msg__JointStateStamped__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!prak_msgs__msg__JointStateStamped__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
prak_msgs__msg__JointStateStamped__Sequence__copy(
  const prak_msgs__msg__JointStateStamped__Sequence * input,
  prak_msgs__msg__JointStateStamped__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(prak_msgs__msg__JointStateStamped);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    prak_msgs__msg__JointStateStamped * data =
      (prak_msgs__msg__JointStateStamped *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!prak_msgs__msg__JointStateStamped__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          prak_msgs__msg__JointStateStamped__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!prak_msgs__msg__JointStateStamped__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
