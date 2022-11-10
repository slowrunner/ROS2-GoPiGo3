// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_gopigo3_msg:msg/MotorStatusLR.idl
// generated code does not contain a copyright notice

#ifndef ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__STRUCT_HPP_
#define ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'left'
// Member 'right'
#include "ros2_gopigo3_msg/msg/detail/motor_status__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ros2_gopigo3_msg__msg__MotorStatusLR __attribute__((deprecated))
#else
# define DEPRECATED__ros2_gopigo3_msg__msg__MotorStatusLR __declspec(deprecated)
#endif

namespace ros2_gopigo3_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorStatusLR_
{
  using Type = MotorStatusLR_<ContainerAllocator>;

  explicit MotorStatusLR_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    left(_init),
    right(_init)
  {
    (void)_init;
  }

  explicit MotorStatusLR_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    left(_alloc, _init),
    right(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _left_type =
    ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator>;
  _left_type left;
  using _right_type =
    ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator>;
  _right_type right;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__left(
    const ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator> & _arg)
  {
    this->left = _arg;
    return *this;
  }
  Type & set__right(
    const ros2_gopigo3_msg::msg::MotorStatus_<ContainerAllocator> & _arg)
  {
    this->right = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_gopigo3_msg::msg::MotorStatusLR_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_gopigo3_msg::msg::MotorStatusLR_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_gopigo3_msg::msg::MotorStatusLR_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_gopigo3_msg::msg::MotorStatusLR_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_gopigo3_msg::msg::MotorStatusLR_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_gopigo3_msg::msg::MotorStatusLR_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_gopigo3_msg::msg::MotorStatusLR_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_gopigo3_msg::msg::MotorStatusLR_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_gopigo3_msg::msg::MotorStatusLR_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_gopigo3_msg::msg::MotorStatusLR_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_gopigo3_msg__msg__MotorStatusLR
    std::shared_ptr<ros2_gopigo3_msg::msg::MotorStatusLR_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_gopigo3_msg__msg__MotorStatusLR
    std::shared_ptr<ros2_gopigo3_msg::msg::MotorStatusLR_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorStatusLR_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->left != other.left) {
      return false;
    }
    if (this->right != other.right) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorStatusLR_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorStatusLR_

// alias to use template instance with default allocator
using MotorStatusLR =
  ros2_gopigo3_msg::msg::MotorStatusLR_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros2_gopigo3_msg

#endif  // ROS2_GOPIGO3_MSG__MSG__DETAIL__MOTOR_STATUS_LR__STRUCT_HPP_
