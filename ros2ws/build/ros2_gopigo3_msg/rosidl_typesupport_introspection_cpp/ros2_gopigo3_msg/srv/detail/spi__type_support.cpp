// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ros2_gopigo3_msg:srv/SPI.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ros2_gopigo3_msg/srv/detail/spi__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ros2_gopigo3_msg
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void SPI_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ros2_gopigo3_msg::srv::SPI_Request(_init);
}

void SPI_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ros2_gopigo3_msg::srv::SPI_Request *>(message_memory);
  typed_message->~SPI_Request();
}

size_t size_function__SPI_Request__data_out(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SPI_Request__data_out(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__SPI_Request__data_out(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__SPI_Request__data_out(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__SPI_Request__data_out(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__SPI_Request__data_out(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__SPI_Request__data_out(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__SPI_Request__data_out(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SPI_Request_message_member_array[1] = {
  {
    "data_out",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_gopigo3_msg::srv::SPI_Request, data_out),  // bytes offset in struct
    nullptr,  // default value
    size_function__SPI_Request__data_out,  // size() function pointer
    get_const_function__SPI_Request__data_out,  // get_const(index) function pointer
    get_function__SPI_Request__data_out,  // get(index) function pointer
    fetch_function__SPI_Request__data_out,  // fetch(index, &value) function pointer
    assign_function__SPI_Request__data_out,  // assign(index, value) function pointer
    resize_function__SPI_Request__data_out  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SPI_Request_message_members = {
  "ros2_gopigo3_msg::srv",  // message namespace
  "SPI_Request",  // message name
  1,  // number of fields
  sizeof(ros2_gopigo3_msg::srv::SPI_Request),
  SPI_Request_message_member_array,  // message members
  SPI_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  SPI_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SPI_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SPI_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace ros2_gopigo3_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_gopigo3_msg::srv::SPI_Request>()
{
  return &::ros2_gopigo3_msg::srv::rosidl_typesupport_introspection_cpp::SPI_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_gopigo3_msg, srv, SPI_Request)() {
  return &::ros2_gopigo3_msg::srv::rosidl_typesupport_introspection_cpp::SPI_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ros2_gopigo3_msg
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void SPI_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ros2_gopigo3_msg::srv::SPI_Response(_init);
}

void SPI_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ros2_gopigo3_msg::srv::SPI_Response *>(message_memory);
  typed_message->~SPI_Response();
}

size_t size_function__SPI_Response__data_in(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SPI_Response__data_in(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__SPI_Response__data_in(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__SPI_Response__data_in(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__SPI_Response__data_in(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__SPI_Response__data_in(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__SPI_Response__data_in(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__SPI_Response__data_in(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SPI_Response_message_member_array[1] = {
  {
    "data_in",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_gopigo3_msg::srv::SPI_Response, data_in),  // bytes offset in struct
    nullptr,  // default value
    size_function__SPI_Response__data_in,  // size() function pointer
    get_const_function__SPI_Response__data_in,  // get_const(index) function pointer
    get_function__SPI_Response__data_in,  // get(index) function pointer
    fetch_function__SPI_Response__data_in,  // fetch(index, &value) function pointer
    assign_function__SPI_Response__data_in,  // assign(index, value) function pointer
    resize_function__SPI_Response__data_in  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SPI_Response_message_members = {
  "ros2_gopigo3_msg::srv",  // message namespace
  "SPI_Response",  // message name
  1,  // number of fields
  sizeof(ros2_gopigo3_msg::srv::SPI_Response),
  SPI_Response_message_member_array,  // message members
  SPI_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  SPI_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SPI_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SPI_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace ros2_gopigo3_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_gopigo3_msg::srv::SPI_Response>()
{
  return &::ros2_gopigo3_msg::srv::rosidl_typesupport_introspection_cpp::SPI_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_gopigo3_msg, srv, SPI_Response)() {
  return &::ros2_gopigo3_msg::srv::rosidl_typesupport_introspection_cpp::SPI_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace ros2_gopigo3_msg
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers SPI_service_members = {
  "ros2_gopigo3_msg::srv",  // service namespace
  "SPI",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<ros2_gopigo3_msg::srv::SPI>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t SPI_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SPI_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace ros2_gopigo3_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<ros2_gopigo3_msg::srv::SPI>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::ros2_gopigo3_msg::srv::rosidl_typesupport_introspection_cpp::SPI_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::ros2_gopigo3_msg::srv::SPI_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::ros2_gopigo3_msg::srv::SPI_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ros2_gopigo3_msg, srv, SPI)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<ros2_gopigo3_msg::srv::SPI>();
}

#ifdef __cplusplus
}
#endif
