// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_gopigo3_msg:msg/MotorStatus.idl
// generated code does not contain a copyright notice

#ifndef ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__STRUCT_H_
#define ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MotorStatus in the package ros2_gopigo3_msg.
typedef struct ros2_gopigo3_msg__msg__MotorStatus
{
  bool low_voltage;
  bool overloaded;
  /// PWM duty cycle -100 ... 100
  int8_t power;
  /// degree
  float encoder;
  /// degree per second
  float speed;
} ros2_gopigo3_msg__msg__MotorStatus;

// Struct for a sequence of ros2_gopigo3_msg__msg__MotorStatus.
typedef struct ros2_gopigo3_msg__msg__MotorStatus__Sequence
{
  ros2_gopigo3_msg__msg__MotorStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_gopigo3_msg__msg__MotorStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__STRUCT_H_
