// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_gopigo3_msg:msg/MotorStatus.idl
// generated code does not contain a copyright notice

#ifndef ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__TRAITS_HPP_
#define ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_gopigo3_msg/msg/detail/motor_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_gopigo3_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: low_voltage
  {
    out << "low_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.low_voltage, out);
    out << ", ";
  }

  // member: overloaded
  {
    out << "overloaded: ";
    rosidl_generator_traits::value_to_yaml(msg.overloaded, out);
    out << ", ";
  }

  // member: power
  {
    out << "power: ";
    rosidl_generator_traits::value_to_yaml(msg.power, out);
    out << ", ";
  }

  // member: encoder
  {
    out << "encoder: ";
    rosidl_generator_traits::value_to_yaml(msg.encoder, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: low_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "low_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.low_voltage, out);
    out << "\n";
  }

  // member: overloaded
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "overloaded: ";
    rosidl_generator_traits::value_to_yaml(msg.overloaded, out);
    out << "\n";
  }

  // member: power
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "power: ";
    rosidl_generator_traits::value_to_yaml(msg.power, out);
    out << "\n";
  }

  // member: encoder
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "encoder: ";
    rosidl_generator_traits::value_to_yaml(msg.encoder, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorStatus & msg, bool use_flow_style = false)
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
  const ros2_gopigo3_msg::msg::MotorStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_gopigo3_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_gopigo3_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const ros2_gopigo3_msg::msg::MotorStatus & msg)
{
  return ros2_gopigo3_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_gopigo3_msg::msg::MotorStatus>()
{
  return "ros2_gopigo3_msg::msg::MotorStatus";
}

template<>
inline const char * name<ros2_gopigo3_msg::msg::MotorStatus>()
{
  return "ros2_gopigo3_msg/msg/MotorStatus";
}

template<>
struct has_fixed_size<ros2_gopigo3_msg::msg::MotorStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2_gopigo3_msg::msg::MotorStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2_gopigo3_msg::msg::MotorStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__TRAITS_HPP_
