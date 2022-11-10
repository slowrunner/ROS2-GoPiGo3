// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_gopigo3_msg:srv/SPI.idl
// generated code does not contain a copyright notice

#ifndef ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__TRAITS_HPP_
#define ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_gopigo3_msg/srv/detail/spi__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_gopigo3_msg
{

namespace srv
{

inline void to_flow_style_yaml(
  const SPI_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: data_out
  {
    if (msg.data_out.size() == 0) {
      out << "data_out: []";
    } else {
      out << "data_out: [";
      size_t pending_items = msg.data_out.size();
      for (auto item : msg.data_out) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SPI_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data_out
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data_out.size() == 0) {
      out << "data_out: []\n";
    } else {
      out << "data_out:\n";
      for (auto item : msg.data_out) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SPI_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros2_gopigo3_msg

namespace rosidl_generator_traits
{

[[deprecated("use ros2_gopigo3_msg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_gopigo3_msg::srv::SPI_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_gopigo3_msg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_gopigo3_msg::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_gopigo3_msg::srv::SPI_Request & msg)
{
  return ros2_gopigo3_msg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_gopigo3_msg::srv::SPI_Request>()
{
  return "ros2_gopigo3_msg::srv::SPI_Request";
}

template<>
inline const char * name<ros2_gopigo3_msg::srv::SPI_Request>()
{
  return "ros2_gopigo3_msg/srv/SPI_Request";
}

template<>
struct has_fixed_size<ros2_gopigo3_msg::srv::SPI_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_gopigo3_msg::srv::SPI_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_gopigo3_msg::srv::SPI_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ros2_gopigo3_msg
{

namespace srv
{

inline void to_flow_style_yaml(
  const SPI_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: data_in
  {
    if (msg.data_in.size() == 0) {
      out << "data_in: []";
    } else {
      out << "data_in: [";
      size_t pending_items = msg.data_in.size();
      for (auto item : msg.data_in) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SPI_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data_in
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data_in.size() == 0) {
      out << "data_in: []\n";
    } else {
      out << "data_in:\n";
      for (auto item : msg.data_in) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SPI_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros2_gopigo3_msg

namespace rosidl_generator_traits
{

[[deprecated("use ros2_gopigo3_msg::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_gopigo3_msg::srv::SPI_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_gopigo3_msg::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_gopigo3_msg::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_gopigo3_msg::srv::SPI_Response & msg)
{
  return ros2_gopigo3_msg::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_gopigo3_msg::srv::SPI_Response>()
{
  return "ros2_gopigo3_msg::srv::SPI_Response";
}

template<>
inline const char * name<ros2_gopigo3_msg::srv::SPI_Response>()
{
  return "ros2_gopigo3_msg/srv/SPI_Response";
}

template<>
struct has_fixed_size<ros2_gopigo3_msg::srv::SPI_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_gopigo3_msg::srv::SPI_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_gopigo3_msg::srv::SPI_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros2_gopigo3_msg::srv::SPI>()
{
  return "ros2_gopigo3_msg::srv::SPI";
}

template<>
inline const char * name<ros2_gopigo3_msg::srv::SPI>()
{
  return "ros2_gopigo3_msg/srv/SPI";
}

template<>
struct has_fixed_size<ros2_gopigo3_msg::srv::SPI>
  : std::integral_constant<
    bool,
    has_fixed_size<ros2_gopigo3_msg::srv::SPI_Request>::value &&
    has_fixed_size<ros2_gopigo3_msg::srv::SPI_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros2_gopigo3_msg::srv::SPI>
  : std::integral_constant<
    bool,
    has_bounded_size<ros2_gopigo3_msg::srv::SPI_Request>::value &&
    has_bounded_size<ros2_gopigo3_msg::srv::SPI_Response>::value
  >
{
};

template<>
struct is_service<ros2_gopigo3_msg::srv::SPI>
  : std::true_type
{
};

template<>
struct is_service_request<ros2_gopigo3_msg::srv::SPI_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros2_gopigo3_msg::srv::SPI_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__TRAITS_HPP_
