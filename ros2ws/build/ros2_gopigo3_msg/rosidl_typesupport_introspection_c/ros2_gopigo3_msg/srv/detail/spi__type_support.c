// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ros2_gopigo3_msg:srv/SPI.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ros2_gopigo3_msg/srv/detail/spi__rosidl_typesupport_introspection_c.h"
#include "ros2_gopigo3_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ros2_gopigo3_msg/srv/detail/spi__functions.h"
#include "ros2_gopigo3_msg/srv/detail/spi__struct.h"


// Include directives for member types
// Member `data_out`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros2_gopigo3_msg__srv__SPI_Request__init(message_memory);
}

void ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_fini_function(void * message_memory)
{
  ros2_gopigo3_msg__srv__SPI_Request__fini(message_memory);
}

size_t ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__size_function__SPI_Request__data_out(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__get_const_function__SPI_Request__data_out(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__get_function__SPI_Request__data_out(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__fetch_function__SPI_Request__data_out(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__get_const_function__SPI_Request__data_out(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__assign_function__SPI_Request__data_out(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__get_function__SPI_Request__data_out(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__resize_function__SPI_Request__data_out(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_member_array[1] = {
  {
    "data_out",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_gopigo3_msg__srv__SPI_Request, data_out),  // bytes offset in struct
    NULL,  // default value
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__size_function__SPI_Request__data_out,  // size() function pointer
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__get_const_function__SPI_Request__data_out,  // get_const(index) function pointer
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__get_function__SPI_Request__data_out,  // get(index) function pointer
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__fetch_function__SPI_Request__data_out,  // fetch(index, &value) function pointer
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__assign_function__SPI_Request__data_out,  // assign(index, value) function pointer
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__resize_function__SPI_Request__data_out  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_members = {
  "ros2_gopigo3_msg__srv",  // message namespace
  "SPI_Request",  // message name
  1,  // number of fields
  sizeof(ros2_gopigo3_msg__srv__SPI_Request),
  ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_member_array,  // message members
  ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_type_support_handle = {
  0,
  &ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_gopigo3_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Request)() {
  if (!ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_type_support_handle.typesupport_identifier) {
    ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ros2_gopigo3_msg__srv__SPI_Request__rosidl_typesupport_introspection_c__SPI_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ros2_gopigo3_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__functions.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__struct.h"


// Include directives for member types
// Member `data_in`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros2_gopigo3_msg__srv__SPI_Response__init(message_memory);
}

void ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_fini_function(void * message_memory)
{
  ros2_gopigo3_msg__srv__SPI_Response__fini(message_memory);
}

size_t ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__size_function__SPI_Response__data_in(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__get_const_function__SPI_Response__data_in(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__get_function__SPI_Response__data_in(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__fetch_function__SPI_Response__data_in(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__get_const_function__SPI_Response__data_in(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__assign_function__SPI_Response__data_in(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__get_function__SPI_Response__data_in(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__resize_function__SPI_Response__data_in(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_member_array[1] = {
  {
    "data_in",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_gopigo3_msg__srv__SPI_Response, data_in),  // bytes offset in struct
    NULL,  // default value
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__size_function__SPI_Response__data_in,  // size() function pointer
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__get_const_function__SPI_Response__data_in,  // get_const(index) function pointer
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__get_function__SPI_Response__data_in,  // get(index) function pointer
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__fetch_function__SPI_Response__data_in,  // fetch(index, &value) function pointer
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__assign_function__SPI_Response__data_in,  // assign(index, value) function pointer
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__resize_function__SPI_Response__data_in  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_members = {
  "ros2_gopigo3_msg__srv",  // message namespace
  "SPI_Response",  // message name
  1,  // number of fields
  sizeof(ros2_gopigo3_msg__srv__SPI_Response),
  ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_member_array,  // message members
  ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_type_support_handle = {
  0,
  &ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_gopigo3_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Response)() {
  if (!ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_type_support_handle.typesupport_identifier) {
    ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ros2_gopigo3_msg__srv__SPI_Response__rosidl_typesupport_introspection_c__SPI_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ros2_gopigo3_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_service_members = {
  "ros2_gopigo3_msg__srv",  // service namespace
  "SPI",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_Request_message_type_support_handle,
  NULL  // response message
  // ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_Response_message_type_support_handle
};

static rosidl_service_type_support_t ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_service_type_support_handle = {
  0,
  &ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_gopigo3_msg
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI)() {
  if (!ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_service_type_support_handle.typesupport_identifier) {
    ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Response)()->data;
  }

  return &ros2_gopigo3_msg__srv__detail__spi__rosidl_typesupport_introspection_c__SPI_service_type_support_handle;
}
