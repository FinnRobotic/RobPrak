// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from prak_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice
#include "prak_msgs/msg/detail/robot_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `joint_state`
#include "prak_msgs/msg/detail/joint_state_stamped__functions.h"
// Member `tcp_pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
prak_msgs__msg__RobotState__init(prak_msgs__msg__RobotState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    prak_msgs__msg__RobotState__fini(msg);
    return false;
  }
  // joint_state
  if (!prak_msgs__msg__JointStateStamped__init(&msg->joint_state)) {
    prak_msgs__msg__RobotState__fini(msg);
    return false;
  }
  // tcp_pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->tcp_pose)) {
    prak_msgs__msg__RobotState__fini(msg);
    return false;
  }
  return true;
}

void
prak_msgs__msg__RobotState__fini(prak_msgs__msg__RobotState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // joint_state
  prak_msgs__msg__JointStateStamped__fini(&msg->joint_state);
  // tcp_pose
  geometry_msgs__msg__PoseStamped__fini(&msg->tcp_pose);
}

bool
prak_msgs__msg__RobotState__are_equal(const prak_msgs__msg__RobotState * lhs, const prak_msgs__msg__RobotState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // joint_state
  if (!prak_msgs__msg__JointStateStamped__are_equal(
      &(lhs->joint_state), &(rhs->joint_state)))
  {
    return false;
  }
  // tcp_pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->tcp_pose), &(rhs->tcp_pose)))
  {
    return false;
  }
  return true;
}

bool
prak_msgs__msg__RobotState__copy(
  const prak_msgs__msg__RobotState * input,
  prak_msgs__msg__RobotState * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // joint_state
  if (!prak_msgs__msg__JointStateStamped__copy(
      &(input->joint_state), &(output->joint_state)))
  {
    return false;
  }
  // tcp_pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->tcp_pose), &(output->tcp_pose)))
  {
    return false;
  }
  return true;
}

prak_msgs__msg__RobotState *
prak_msgs__msg__RobotState__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__msg__RobotState * msg = (prak_msgs__msg__RobotState *)allocator.allocate(sizeof(prak_msgs__msg__RobotState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(prak_msgs__msg__RobotState));
  bool success = prak_msgs__msg__RobotState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
prak_msgs__msg__RobotState__destroy(prak_msgs__msg__RobotState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    prak_msgs__msg__RobotState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
prak_msgs__msg__RobotState__Sequence__init(prak_msgs__msg__RobotState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__msg__RobotState * data = NULL;

  if (size) {
    data = (prak_msgs__msg__RobotState *)allocator.zero_allocate(size, sizeof(prak_msgs__msg__RobotState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = prak_msgs__msg__RobotState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        prak_msgs__msg__RobotState__fini(&data[i - 1]);
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
prak_msgs__msg__RobotState__Sequence__fini(prak_msgs__msg__RobotState__Sequence * array)
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
      prak_msgs__msg__RobotState__fini(&array->data[i]);
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

prak_msgs__msg__RobotState__Sequence *
prak_msgs__msg__RobotState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__msg__RobotState__Sequence * array = (prak_msgs__msg__RobotState__Sequence *)allocator.allocate(sizeof(prak_msgs__msg__RobotState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = prak_msgs__msg__RobotState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
prak_msgs__msg__RobotState__Sequence__destroy(prak_msgs__msg__RobotState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    prak_msgs__msg__RobotState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
prak_msgs__msg__RobotState__Sequence__are_equal(const prak_msgs__msg__RobotState__Sequence * lhs, const prak_msgs__msg__RobotState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!prak_msgs__msg__RobotState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
prak_msgs__msg__RobotState__Sequence__copy(
  const prak_msgs__msg__RobotState__Sequence * input,
  prak_msgs__msg__RobotState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(prak_msgs__msg__RobotState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    prak_msgs__msg__RobotState * data =
      (prak_msgs__msg__RobotState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!prak_msgs__msg__RobotState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          prak_msgs__msg__RobotState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!prak_msgs__msg__RobotState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
