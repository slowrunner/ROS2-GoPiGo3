// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_gopigo3_msg:msg/MotorStatusLR.idl
// generated code does not contain a copyright notice
#include "ros2_gopigo3_msg/msg/detail/motor_status_lr__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `left`
// Member `right`
#include "ros2_gopigo3_msg/msg/detail/motor_status__functions.h"

bool
ros2_gopigo3_msg__msg__MotorStatusLR__init(ros2_gopigo3_msg__msg__MotorStatusLR * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    ros2_gopigo3_msg__msg__MotorStatusLR__fini(msg);
    return false;
  }
  // left
  if (!ros2_gopigo3_msg__msg__MotorStatus__init(&msg->left)) {
    ros2_gopigo3_msg__msg__MotorStatusLR__fini(msg);
    return false;
  }
  // right
  if (!ros2_gopigo3_msg__msg__MotorStatus__init(&msg->right)) {
    ros2_gopigo3_msg__msg__MotorStatusLR__fini(msg);
    return false;
  }
  return true;
}

void
ros2_gopigo3_msg__msg__MotorStatusLR__fini(ros2_gopigo3_msg__msg__MotorStatusLR * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // left
  ros2_gopigo3_msg__msg__MotorStatus__fini(&msg->left);
  // right
  ros2_gopigo3_msg__msg__MotorStatus__fini(&msg->right);
}

bool
ros2_gopigo3_msg__msg__MotorStatusLR__are_equal(const ros2_gopigo3_msg__msg__MotorStatusLR * lhs, const ros2_gopigo3_msg__msg__MotorStatusLR * rhs)
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
  // left
  if (!ros2_gopigo3_msg__msg__MotorStatus__are_equal(
      &(lhs->left), &(rhs->left)))
  {
    return false;
  }
  // right
  if (!ros2_gopigo3_msg__msg__MotorStatus__are_equal(
      &(lhs->right), &(rhs->right)))
  {
    return false;
  }
  return true;
}

bool
ros2_gopigo3_msg__msg__MotorStatusLR__copy(
  const ros2_gopigo3_msg__msg__MotorStatusLR * input,
  ros2_gopigo3_msg__msg__MotorStatusLR * output)
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
  // left
  if (!ros2_gopigo3_msg__msg__MotorStatus__copy(
      &(input->left), &(output->left)))
  {
    return false;
  }
  // right
  if (!ros2_gopigo3_msg__msg__MotorStatus__copy(
      &(input->right), &(output->right)))
  {
    return false;
  }
  return true;
}

ros2_gopigo3_msg__msg__MotorStatusLR *
ros2_gopigo3_msg__msg__MotorStatusLR__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_gopigo3_msg__msg__MotorStatusLR * msg = (ros2_gopigo3_msg__msg__MotorStatusLR *)allocator.allocate(sizeof(ros2_gopigo3_msg__msg__MotorStatusLR), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_gopigo3_msg__msg__MotorStatusLR));
  bool success = ros2_gopigo3_msg__msg__MotorStatusLR__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros2_gopigo3_msg__msg__MotorStatusLR__destroy(ros2_gopigo3_msg__msg__MotorStatusLR * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros2_gopigo3_msg__msg__MotorStatusLR__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros2_gopigo3_msg__msg__MotorStatusLR__Sequence__init(ros2_gopigo3_msg__msg__MotorStatusLR__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_gopigo3_msg__msg__MotorStatusLR * data = NULL;

  if (size) {
    data = (ros2_gopigo3_msg__msg__MotorStatusLR *)allocator.zero_allocate(size, sizeof(ros2_gopigo3_msg__msg__MotorStatusLR), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_gopigo3_msg__msg__MotorStatusLR__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_gopigo3_msg__msg__MotorStatusLR__fini(&data[i - 1]);
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
ros2_gopigo3_msg__msg__MotorStatusLR__Sequence__fini(ros2_gopigo3_msg__msg__MotorStatusLR__Sequence * array)
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
      ros2_gopigo3_msg__msg__MotorStatusLR__fini(&array->data[i]);
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

ros2_gopigo3_msg__msg__MotorStatusLR__Sequence *
ros2_gopigo3_msg__msg__MotorStatusLR__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_gopigo3_msg__msg__MotorStatusLR__Sequence * array = (ros2_gopigo3_msg__msg__MotorStatusLR__Sequence *)allocator.allocate(sizeof(ros2_gopigo3_msg__msg__MotorStatusLR__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros2_gopigo3_msg__msg__MotorStatusLR__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros2_gopigo3_msg__msg__MotorStatusLR__Sequence__destroy(ros2_gopigo3_msg__msg__MotorStatusLR__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros2_gopigo3_msg__msg__MotorStatusLR__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros2_gopigo3_msg__msg__MotorStatusLR__Sequence__are_equal(const ros2_gopigo3_msg__msg__MotorStatusLR__Sequence * lhs, const ros2_gopigo3_msg__msg__MotorStatusLR__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_gopigo3_msg__msg__MotorStatusLR__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_gopigo3_msg__msg__MotorStatusLR__Sequence__copy(
  const ros2_gopigo3_msg__msg__MotorStatusLR__Sequence * input,
  ros2_gopigo3_msg__msg__MotorStatusLR__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_gopigo3_msg__msg__MotorStatusLR);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros2_gopigo3_msg__msg__MotorStatusLR * data =
      (ros2_gopigo3_msg__msg__MotorStatusLR *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_gopigo3_msg__msg__MotorStatusLR__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros2_gopigo3_msg__msg__MotorStatusLR__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros2_gopigo3_msg__msg__MotorStatusLR__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
