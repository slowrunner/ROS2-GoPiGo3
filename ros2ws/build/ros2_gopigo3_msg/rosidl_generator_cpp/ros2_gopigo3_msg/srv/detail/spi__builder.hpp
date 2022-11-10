// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_gopigo3_msg:srv/SPI.idl
// generated code does not contain a copyright notice

#ifndef ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__BUILDER_HPP_
#define ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_gopigo3_msg/srv/detail/spi__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_gopigo3_msg
{

namespace srv
{

namespace builder
{

class Init_SPI_Request_data_out
{
public:
  Init_SPI_Request_data_out()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_gopigo3_msg::srv::SPI_Request data_out(::ros2_gopigo3_msg::srv::SPI_Request::_data_out_type arg)
  {
    msg_.data_out = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_gopigo3_msg::srv::SPI_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_gopigo3_msg::srv::SPI_Request>()
{
  return ros2_gopigo3_msg::srv::builder::Init_SPI_Request_data_out();
}

}  // namespace ros2_gopigo3_msg


namespace ros2_gopigo3_msg
{

namespace srv
{

namespace builder
{

class Init_SPI_Response_data_in
{
public:
  Init_SPI_Response_data_in()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_gopigo3_msg::srv::SPI_Response data_in(::ros2_gopigo3_msg::srv::SPI_Response::_data_in_type arg)
  {
    msg_.data_in = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_gopigo3_msg::srv::SPI_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_gopigo3_msg::srv::SPI_Response>()
{
  return ros2_gopigo3_msg::srv::builder::Init_SPI_Response_data_in();
}

}  // namespace ros2_gopigo3_msg

#endif  // ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__BUILDER_HPP_
