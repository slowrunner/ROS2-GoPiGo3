// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from ros2_gopigo3_msg:srv/SPI.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "ros2_gopigo3_msg/srv/detail/spi__struct.h"
#include "ros2_gopigo3_msg/srv/detail/spi__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace ros2_gopigo3_msg
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SPI_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SPI_Request_type_support_ids_t;

static const _SPI_Request_type_support_ids_t _SPI_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SPI_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SPI_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SPI_Request_type_support_symbol_names_t _SPI_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_gopigo3_msg, srv, SPI_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Request)),
  }
};

typedef struct _SPI_Request_type_support_data_t
{
  void * data[2];
} _SPI_Request_type_support_data_t;

static _SPI_Request_type_support_data_t _SPI_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SPI_Request_message_typesupport_map = {
  2,
  "ros2_gopigo3_msg",
  &_SPI_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SPI_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SPI_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SPI_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SPI_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace ros2_gopigo3_msg

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ros2_gopigo3_msg, srv, SPI_Request)() {
  return &::ros2_gopigo3_msg::srv::rosidl_typesupport_c::SPI_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__struct.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ros2_gopigo3_msg
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SPI_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SPI_Response_type_support_ids_t;

static const _SPI_Response_type_support_ids_t _SPI_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SPI_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SPI_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SPI_Response_type_support_symbol_names_t _SPI_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_gopigo3_msg, srv, SPI_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI_Response)),
  }
};

typedef struct _SPI_Response_type_support_data_t
{
  void * data[2];
} _SPI_Response_type_support_data_t;

static _SPI_Response_type_support_data_t _SPI_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SPI_Response_message_typesupport_map = {
  2,
  "ros2_gopigo3_msg",
  &_SPI_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SPI_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SPI_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SPI_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SPI_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace ros2_gopigo3_msg

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ros2_gopigo3_msg, srv, SPI_Response)() {
  return &::ros2_gopigo3_msg::srv::rosidl_typesupport_c::SPI_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ros2_gopigo3_msg/srv/detail/spi__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ros2_gopigo3_msg
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SPI_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SPI_type_support_ids_t;

static const _SPI_type_support_ids_t _SPI_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SPI_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SPI_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SPI_type_support_symbol_names_t _SPI_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_gopigo3_msg, srv, SPI)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_gopigo3_msg, srv, SPI)),
  }
};

typedef struct _SPI_type_support_data_t
{
  void * data[2];
} _SPI_type_support_data_t;

static _SPI_type_support_data_t _SPI_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SPI_service_typesupport_map = {
  2,
  "ros2_gopigo3_msg",
  &_SPI_service_typesupport_ids.typesupport_identifier[0],
  &_SPI_service_typesupport_symbol_names.symbol_name[0],
  &_SPI_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SPI_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SPI_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace ros2_gopigo3_msg

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, ros2_gopigo3_msg, srv, SPI)() {
  return &::ros2_gopigo3_msg::srv::rosidl_typesupport_c::SPI_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
