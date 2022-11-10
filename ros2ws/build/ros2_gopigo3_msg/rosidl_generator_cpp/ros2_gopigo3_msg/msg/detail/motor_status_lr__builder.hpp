// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_gopigo3_msg:msg/MotorStatusLR.idl
// generated code does not contain a copyright notice

#ifndef ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__BUILDER_HPP_
#define ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_gopigo3_msg/msg/detail/motor_status_lr__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_gopigo3_msg
{

namespace msg
{

namespace builder
{

class Init_MotorStatusLR_right
{
public:
  explicit Init_MotorStatusLR_right(::ros2_gopigo3_msg::msg::MotorStatusLR & msg)
  : msg_(msg)
  {}
  ::ros2_gopigo3_msg::msg::MotorStatusLR right(::ros2_gopigo3_msg::msg::MotorStatusLR::_right_type arg)
  {
    msg_.right = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_gopigo3_msg::msg::MotorStatusLR msg_;
};

class Init_MotorStatusLR_left
{
public:
  explicit Init_MotorStatusLR_left(::ros2_gopigo3_msg::msg::MotorStatusLR & msg)
  : msg_(msg)
  {}
  Init_MotorStatusLR_right left(::ros2_gopigo3_msg::msg::MotorStatusLR::_left_type arg)
  {
    msg_.left = std::move(arg);
    return Init_MotorStatusLR_right(msg_);
  }

private:
  ::ros2_gopigo3_msg::msg::MotorStatusLR msg_;
};

class Init_MotorStatusLR_header
{
public:
  Init_MotorStatusLR_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorStatusLR_left header(::ros2_gopigo3_msg::msg::MotorStatusLR::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotorStatusLR_left(msg_);
  }

private:
  ::ros2_gopigo3_msg::msg::MotorStatusLR msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_gopigo3_msg::msg::MotorStatusLR>()
{
  return ros2_gopigo3_msg::msg::builder::Init_MotorStatusLR_header();
}

}  // namespace ros2_gopigo3_msg

#endif  // ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__BUILDER_HPP_
