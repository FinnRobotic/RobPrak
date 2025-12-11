// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from prak_msgs:msg/JointState.idl
// generated code does not contain a copyright notice
#include "prak_msgs/msg/detail/joint_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
prak_msgs__msg__JointState__init(prak_msgs__msg__JointState * msg)
{
  if (!msg) {
    return false;
  }
  // shoulder_pan_joint
  // shoulder_lift_joint
  // elbow_joint
  // wrist_1_joint
  // wrist_2_joint
  // wrist_3_joint
  return true;
}

void
prak_msgs__msg__JointState__fini(prak_msgs__msg__JointState * msg)
{
  if (!msg) {
    return;
  }
  // shoulder_pan_joint
  // shoulder_lift_joint
  // elbow_joint
  // wrist_1_joint
  // wrist_2_joint
  // wrist_3_joint
}

bool
prak_msgs__msg__JointState__are_equal(const prak_msgs__msg__JointState * lhs, const prak_msgs__msg__JointState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // shoulder_pan_joint
  if (lhs->shoulder_pan_joint != rhs->shoulder_pan_joint) {
    return false;
  }
  // shoulder_lift_joint
  if (lhs->shoulder_lift_joint != rhs->shoulder_lift_joint) {
    return false;
  }
  // elbow_joint
  if (lhs->elbow_joint != rhs->elbow_joint) {
    return false;
  }
  // wrist_1_joint
  if (lhs->wrist_1_joint != rhs->wrist_1_joint) {
    return false;
  }
  // wrist_2_joint
  if (lhs->wrist_2_joint != rhs->wrist_2_joint) {
    return false;
  }
  // wrist_3_joint
  if (lhs->wrist_3_joint != rhs->wrist_3_joint) {
    return false;
  }
  return true;
}

bool
prak_msgs__msg__JointState__copy(
  const prak_msgs__msg__JointState * input,
  prak_msgs__msg__JointState * output)
{
  if (!input || !output) {
    return false;
  }
  // shoulder_pan_joint
  output->shoulder_pan_joint = input->shoulder_pan_joint;
  // shoulder_lift_joint
  output->shoulder_lift_joint = input->shoulder_lift_joint;
  // elbow_joint
  output->elbow_joint = input->elbow_joint;
  // wrist_1_joint
  output->wrist_1_joint = input->wrist_1_joint;
  // wrist_2_joint
  output->wrist_2_joint = input->wrist_2_joint;
  // wrist_3_joint
  output->wrist_3_joint = input->wrist_3_joint;
  return true;
}

prak_msgs__msg__JointState *
prak_msgs__msg__JointState__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__msg__JointState * msg = (prak_msgs__msg__JointState *)allocator.allocate(sizeof(prak_msgs__msg__JointState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(prak_msgs__msg__JointState));
  bool success = prak_msgs__msg__JointState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
prak_msgs__msg__JointState__destroy(prak_msgs__msg__JointState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    prak_msgs__msg__JointState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
prak_msgs__msg__JointState__Sequence__init(prak_msgs__msg__JointState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__msg__JointState * data = NULL;

  if (size) {
    data = (prak_msgs__msg__JointState *)allocator.zero_allocate(size, sizeof(prak_msgs__msg__JointState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = prak_msgs__msg__JointState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        prak_msgs__msg__JointState__fini(&data[i - 1]);
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
prak_msgs__msg__JointState__Sequence__fini(prak_msgs__msg__JointState__Sequence * array)
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
      prak_msgs__msg__JointState__fini(&array->data[i]);
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

prak_msgs__msg__JointState__Sequence *
prak_msgs__msg__JointState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  prak_msgs__msg__JointState__Sequence * array = (prak_msgs__msg__JointState__Sequence *)allocator.allocate(sizeof(prak_msgs__msg__JointState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = prak_msgs__msg__JointState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
prak_msgs__msg__JointState__Sequence__destroy(prak_msgs__msg__JointState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    prak_msgs__msg__JointState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
prak_msgs__msg__JointState__Sequence__are_equal(const prak_msgs__msg__JointState__Sequence * lhs, const prak_msgs__msg__JointState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!prak_msgs__msg__JointState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
prak_msgs__msg__JointState__Sequence__copy(
  const prak_msgs__msg__JointState__Sequence * input,
  prak_msgs__msg__JointState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(prak_msgs__msg__JointState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    prak_msgs__msg__JointState * data =
      (prak_msgs__msg__JointState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!prak_msgs__msg__JointState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          prak_msgs__msg__JointState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!prak_msgs__msg__JointState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
