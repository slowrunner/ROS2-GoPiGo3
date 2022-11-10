// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_gopigo3_msg:msg/MotorStatusLR.idl
// generated code does not contain a copyright notice

#ifndef ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__TRAITS_HPP_
#define ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_gopigo3_msg/msg/detail/motor_status_lr__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'left'
// Member 'right'
#include "ros2_gopigo3_msg/msg/detail/motor_status__traits.hpp"

namespace ros2_gopigo3_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorStatusLR & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: left
  {
    out << "left: ";
    to_flow_style_yaml(msg.left, out);
    out << ", ";
  }

  // member: right
  {
    out << "right: ";
    to_flow_style_yaml(msg.right, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorStatusLR & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left:\n";
    to_block_style_yaml(msg.left, out, indentation + 2);
  }

  // member: right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right:\n";
    to_block_style_yaml(msg.right, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorStatusLR & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ros2_gopigo3_msg

namespace rosidl_generator_traits
{

[[deprecated("use ros2_gopigo3_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_gopigo3_msg::msg::MotorStatusLR & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_gopigo3_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_gopigo3_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const ros2_gopigo3_msg::msg::MotorStatusLR & msg)
{
  return ros2_gopigo3_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_gopigo3_msg::msg::MotorStatusLR>()
{
  return "ros2_gopigo3_msg::msg::MotorStatusLR";
}

template<>
inline const char * name<ros2_gopigo3_msg::msg::MotorStatusLR>()
{
  return "ros2_gopigo3_msg/msg/MotorStatusLR";
}

template<>
struct has_fixed_size<ros2_gopigo3_msg::msg::MotorStatusLR>
  : std::integral_constant<bool, has_fixed_size<ros2_gopigo3_msg::msg::MotorStatus>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<ros2_gopigo3_msg::msg::MotorStatusLR>
  : std::integral_constant<bool, has_bounded_size<ros2_gopigo3_msg::msg::MotorStatus>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<ros2_gopigo3_msg::msg::MotorStatusLR>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__TRAITS_HPP_
