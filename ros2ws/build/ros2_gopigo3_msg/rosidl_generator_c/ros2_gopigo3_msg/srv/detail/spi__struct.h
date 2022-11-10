// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_gopigo3_msg:srv/SPI.idl
// generated code does not contain a copyright notice

#ifndef ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__STRUCT_H_
#define ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data_out'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/SPI in the package ros2_gopigo3_msg.
typedef struct ros2_gopigo3_msg__srv__SPI_Request
{
  /// sent byte array
  rosidl_runtime_c__uint8__Sequence data_out;
} ros2_gopigo3_msg__srv__SPI_Request;

// Struct for a sequence of ros2_gopigo3_msg__srv__SPI_Request.
typedef struct ros2_gopigo3_msg__srv__SPI_Request__Sequence
{
  ros2_gopigo3_msg__srv__SPI_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_gopigo3_msg__srv__SPI_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'data_in'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/SPI in the package ros2_gopigo3_msg.
typedef struct ros2_gopigo3_msg__srv__SPI_Response
{
  /// received byte array
  rosidl_runtime_c__uint8__Sequence data_in;
} ros2_gopigo3_msg__srv__SPI_Response;

// Struct for a sequence of ros2_gopigo3_msg__srv__SPI_Response.
typedef struct ros2_gopigo3_msg__srv__SPI_Response__Sequence
{
  ros2_gopigo3_msg__srv__SPI_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_gopigo3_msg__srv__SPI_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__STRUCT_H_
