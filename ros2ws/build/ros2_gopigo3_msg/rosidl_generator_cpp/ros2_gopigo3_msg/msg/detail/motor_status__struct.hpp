// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_gopigo3_msg:msg/MotorStatus.idl
// generated code does not contain a copyright notice

#ifndef ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__STRUCT_HPP_
#define ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros2_gopigo3_msg__msg__MotorStatus __attribute__((deprecated))
#else
# define DEPRECATED__ros2_gopigo3_msg__msg__MotorStatus __declspec(deprecated)
#endif

namespace ros2_gopigo3_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorStatus_
{
  using Type = MotorStatus_<ContainerAllocator>;

  explicit MotorStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->low_voltage = false;
      this->overloaded = false;
      this->power = 0;
      this->encoder = 0.0f;
      this->speed = 0.0f;
    }
  }

  explicit MotorStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->low_voltage = false;
      this->overloaded = false;
      this->power = 0;
      this->encoder = 0.0f;
      this->speed = 0.0f;
    }
  }

  // field types and members
  using _low_voltage_type =
    bool;
  _low_voltage_type low_voltage;
  using _overloaded_type =
    bool;
  _overloaded_type overloaded;
  using _power_type =
    int8_t;
  _power_type power;
  using _encoder_type =
    float;
  _encoder_type encoder;
  using _speed_type =
    float;
  _speed_type speed;

  // setters for named parameter idiom
  Type & set__low_voltage(
    const bool & _arg)
  {
    this->low_voltage = _arg;
    return *this;
  }
  Type & set__overloaded(
    const bool & _arg)
  {
    this->overloaded = _arg;
    return *this;
  }
  Type & set__power(
    const int8_t & _arg)
  {
    this->power = _arg;
    return *this;
  }
  Type & set__encoder(
    const float & _arg)
  {
    this->encoder = _arg;
    return *this;
  }
  Type & set__speed(
    const float & _arg)
  {
    this->speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_gopigo3_msg__msg__MotorStatus
    std::shared_ptr<ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_gopigo3_msg__msg__MotorStatus
    std::shared_ptr<ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorStatus_ & other) const
  {
    if (this->low_voltage != other.low_voltage) {
      return false;
    }
    if (this->overloaded != other.overloaded) {
      return false;
    }
    if (this->power != other.power) {
      return false;
    }
    if (this->encoder != other.encoder) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorStatus_

// alias to use template instance with default allocator
using MotorStatus =
  ros2_gopigo3_msg::msg::MotorStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros2_gopigo3_msg

#endif  // ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS__STRUCT_HPP_
