// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_gopigo3_msg:msg/MotorStatusLR.idl
// generated code does not contain a copyright notice

#ifndef ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__STRUCT_H_
#define ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'left'
// Member 'right'
#include "ros2_gopigo3_msg/msg/detail/motor_status__struct.h"

/// Struct defined in msg/MotorStatusLR in the package ros2_gopigo3_msg.
typedef struct ros2_gopigo3_msg__msg__MotorStatusLR
{
  std_msgs__msg__Header header;
  ros2_gopigo3_msg__msg__MotorStatus left;
  ros2_gopigo3_msg__msg__MotorStatus right;
} ros2_gopigo3_msg__msg__MotorStatusLR;

// Struct for a sequence of ros2_gopigo3_msg__msg__MotorStatusLR.
typedef struct ros2_gopigo3_msg__msg__MotorStatusLR__Sequence
{
  ros2_gopigo3_msg__msg__MotorStatusLR * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_gopigo3_msg__msg__MotorStatusLR__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__STRUCT_H_
