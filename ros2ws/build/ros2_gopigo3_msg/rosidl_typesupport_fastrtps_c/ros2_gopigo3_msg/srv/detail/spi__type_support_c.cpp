// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ros2_gopigo3_msg:srv/SPI.idl
// generated code does not contain a copyright notice
#include "ros2_gopigo3_msg/srv/detail/spi__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ros2_gopigo3_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros2_gopigo3_msg/srv/detail/spi__struct.h"
#include "ros2_gopigo3_msg/srv/detail/spi__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // data_out
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // data_out

// forward declare type support functions


using _SPI_Request__ros_msg_type = ros2_gopigo3_msg__srv__SPI_Request;

static bool _SPI_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SPI_Request__ros_msg_type * ros_message = static_cast<const _SPI_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: data_out
  {
    size_t size = ros_message->data_out.size;
    auto array_ptr = ros_message->data_out.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _SPI_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SPI_Request__ros_msg_type * ros_message = static_cast<_SPI_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: data_out
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->data_out.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->data_out);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->data_out, size)) {
      fprintf(stderr, "failed to create array for field 'data_out'");
      return false;
    }
    auto array_ptr = ros_message->data_out.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_gopigo3_msg
size_t get_serialized_size_ros2_gopigo3_msg__srv__SPI_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SPI_Request__ros_msg_type * ros_message = static_cast<const _SPI_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name data_out
  {
    size_t array_size = ros_message->data_out.size;
    auto array_ptr = ros_message->data_out.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SPI_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros2_gopigo3_msg__srv__SPI_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_gopigo3_msg
size_t max_serialized_size_ros2_gopigo3_msg__srv__SPI_Request(
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

  // member: data_out
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _SPI_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ros2_gopigo3_msg__srv__SPI_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SPI_Request = {
  "ros2_gopigo3_msg::srv",
  "SPI_Request",
  _SPI_Request__cdr_serialize,
  _SPI_Request__cdr_deserialize,
  _SPI_Request__get_serialized_size,
  _SPI_Request__max_serialized_size
};

static rosidl_message_type_support_t _SPI_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SPI_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_gopigo3_msg, srv, SPI_Request)() {
  return &_SPI_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "ros2_gopigo3_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__struct.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"  // data_in
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"  // data_in

// forward declare type support functions


using _SPI_Response__ros_msg_type = ros2_gopigo3_msg__srv__SPI_Response;

static bool _SPI_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SPI_Response__ros_msg_type * ros_message = static_cast<const _SPI_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: data_in
  {
    size_t size = ros_message->data_in.size;
    auto array_ptr = ros_message->data_in.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _SPI_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SPI_Response__ros_msg_type * ros_message = static_cast<_SPI_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: data_in
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->data_in.data) {
      rosidl_runtime_c__uint8__Sequence__fini(&ros_message->data_in);
    }
    if (!rosidl_runtime_c__uint8__Sequence__init(&ros_message->data_in, size)) {
      fprintf(stderr, "failed to create array for field 'data_in'");
      return false;
    }
    auto array_ptr = ros_message->data_in.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_gopigo3_msg
size_t get_serialized_size_ros2_gopigo3_msg__srv__SPI_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SPI_Response__ros_msg_type * ros_message = static_cast<const _SPI_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name data_in
  {
    size_t array_size = ros_message->data_in.size;
    auto array_ptr = ros_message->data_in.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SPI_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros2_gopigo3_msg__srv__SPI_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_gopigo3_msg
size_t max_serialized_size_ros2_gopigo3_msg__srv__SPI_Response(
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

  // member: data_in
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _SPI_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ros2_gopigo3_msg__srv__SPI_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SPI_Response = {
  "ros2_gopigo3_msg::srv",
  "SPI_Response",
  _SPI_Response__cdr_serialize,
  _SPI_Response__cdr_deserialize,
  _SPI_Response__get_serialized_size,
  _SPI_Response__max_serialized_size
};

static rosidl_message_type_support_t _SPI_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SPI_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_gopigo3_msg, srv, SPI_Response)() {
  return &_SPI_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "ros2_gopigo3_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros2_gopigo3_msg/srv/spi.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t SPI__callbacks = {
  "ros2_gopigo3_msg::srv",
  "SPI",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_gopigo3_msg, srv, SPI_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_gopigo3_msg, srv, SPI_Response)(),
};

static rosidl_service_type_support_t SPI__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &SPI__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_gopigo3_msg, srv, SPI)() {
  return &SPI__handle;
}

#if defined(__cplusplus)
}
#endif
