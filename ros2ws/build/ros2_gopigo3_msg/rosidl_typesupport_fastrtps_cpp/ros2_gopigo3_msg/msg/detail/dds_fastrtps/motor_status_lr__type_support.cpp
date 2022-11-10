// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ros2_gopigo3_msg:msg/MotorStatusLR.idl
// generated code does not contain a copyright notice
#include "ros2_gopigo3_msg/msg/detail/motor_status_lr__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ros2_gopigo3_msg/msg/detail/motor_status_lr__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace ros2_gopigo3_msg
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const ros2_gopigo3_msg::msg::MotorStatus &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  ros2_gopigo3_msg::msg::MotorStatus &);
size_t get_serialized_size(
  const ros2_gopigo3_msg::msg::MotorStatus &,
  size_t current_alignment);
size_t
max_serialized_size_MotorStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace ros2_gopigo3_msg

namespace ros2_gopigo3_msg
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const ros2_gopigo3_msg::msg::MotorStatus &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  ros2_gopigo3_msg::msg::MotorStatus &);
size_t get_serialized_size(
  const ros2_gopigo3_msg::msg::MotorStatus &,
  size_t current_alignment);
size_t
max_serialized_size_MotorStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace ros2_gopigo3_msg


namespace ros2_gopigo3_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_gopigo3_msg
cdr_serialize(
  const ros2_gopigo3_msg::msg::MotorStatusLR & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: left
  ros2_gopigo3_msg::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.left,
    cdr);
  // Member: right
  ros2_gopigo3_msg::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.right,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_gopigo3_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros2_gopigo3_msg::msg::MotorStatusLR & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: left
  ros2_gopigo3_msg::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.left);

  // Member: right
  ros2_gopigo3_msg::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.right);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_gopigo3_msg
get_serialized_size(
  const ros2_gopigo3_msg::msg::MotorStatusLR & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: left

  current_alignment +=
    ros2_gopigo3_msg::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.left, current_alignment);
  // Member: right

  current_alignment +=
    ros2_gopigo3_msg::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.right, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_gopigo3_msg
max_serialized_size_MotorStatusLR(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: left
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        ros2_gopigo3_msg::msg::typesupport_fastrtps_cpp::max_serialized_size_MotorStatus(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: right
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        ros2_gopigo3_msg::msg::typesupport_fastrtps_cpp::max_serialized_size_MotorStatus(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _MotorStatusLR__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ros2_gopigo3_msg::msg::MotorStatusLR *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MotorStatusLR__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ros2_gopigo3_msg::msg::MotorStatusLR *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MotorStatusLR__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ros2_gopigo3_msg::msg::MotorStatusLR *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MotorStatusLR__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MotorStatusLR(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MotorStatusLR__callbacks = {
  "ros2_gopigo3_msg::msg",
  "MotorStatusLR",
  _MotorStatusLR__cdr_serialize,
  _MotorStatusLR__cdr_deserialize,
  _MotorStatusLR__get_serialized_size,
  _MotorStatusLR__max_serialized_size
};

static rosidl_message_type_support_t _MotorStatusLR__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MotorStatusLR__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ros2_gopigo3_msg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ros2_gopigo3_msg
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_gopigo3_msg::msg::MotorStatusLR>()
{
  return &ros2_gopigo3_msg::msg::typesupport_fastrtps_cpp::_MotorStatusLR__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_gopigo3_msg, msg, MotorStatusLR)() {
  return &ros2_gopigo3_msg::msg::typesupport_fastrtps_cpp::_MotorStatusLR__handle;
}

#ifdef __cplusplus
}
#endif
