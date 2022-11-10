// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_gopigo3_msg:msg/MotorStatus.idl
// generated code does not contain a copyright notice

#ifndef ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__BUILDER_HPP_
#define ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_gopigo3_msg/msg/detail/motor_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_gopigo3_msg
{

namespace msg
{

namespace builder
{

class Init_MotorStatus_speed
{
public:
  explicit Init_MotorStatus_speed(::ros2_gopigo3_msg::msg::MotorStatus & msg)
  : msg_(msg)
  {}
  ::ros2_gopigo3_msg::msg::MotorStatus speed(::ros2_gopigo3_msg::msg::MotorStatus::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_gopigo3_msg::msg::MotorStatus msg_;
};

class Init_MotorStatus_encoder
{
public:
  explicit Init_MotorStatus_encoder(::ros2_gopigo3_msg::msg::MotorStatus & msg)
  : msg_(msg)
  {}
  Init_MotorStatus_speed encoder(::ros2_gopigo3_msg::msg::MotorStatus::_encoder_type arg)
  {
    msg_.encoder = std::move(arg);
    return Init_MotorStatus_speed(msg_);
  }

private:
  ::ros2_gopigo3_msg::msg::MotorStatus msg_;
};

class Init_MotorStatus_power
{
public:
  explicit Init_MotorStatus_power(::ros2_gopigo3_msg::msg::MotorStatus & msg)
  : msg_(msg)
  {}
  Init_MotorStatus_encoder power(::ros2_gopigo3_msg::msg::MotorStatus::_power_type arg)
  {
    msg_.power = std::move(arg);
    return Init_MotorStatus_encoder(msg_);
  }

private:
  ::ros2_gopigo3_msg::msg::MotorStatus msg_;
};

class Init_MotorStatus_overloaded
{
public:
  explicit Init_MotorStatus_overloaded(::ros2_gopigo3_msg::msg::MotorStatus & msg)
  : msg_(msg)
  {}
  Init_MotorStatus_power overloaded(::ros2_gopigo3_msg::msg::MotorStatus::_overloaded_type arg)
  {
    msg_.overloaded = std::move(arg);
    return Init_MotorStatus_power(msg_);
  }

private:
  ::ros2_gopigo3_msg::msg::MotorStatus msg_;
};

class Init_MotorStatus_low_voltage
{
public:
  Init_MotorStatus_low_voltage()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorStatus_overloaded low_voltage(::ros2_gopigo3_msg::msg::MotorStatus::_low_voltage_type arg)
  {
    msg_.low_voltage = std::move(arg);
    return Init_MotorStatus_overloaded(msg_);
  }

private:
  ::ros2_gopigo3_msg::msg::MotorStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_gopigo3_msg::msg::MotorStatus>()
{
  return ros2_gopigo3_msg::msg::builder::Init_MotorStatus_low_voltage();
}

}  // namespace ros2_gopigo3_msg

#endif  // ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__BUILDER_HPP_
