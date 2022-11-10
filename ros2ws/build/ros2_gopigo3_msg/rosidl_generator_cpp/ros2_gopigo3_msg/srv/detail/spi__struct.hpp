// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_gopigo3_msg:srv/SPI.idl
// generated code does not contain a copyright notice

#ifndef ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__STRUCT_HPP_
#define ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros2_gopigo3_msg__srv__SPI_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros2_gopigo3_msg__srv__SPI_Request __declspec(deprecated)
#endif

namespace ros2_gopigo3_msg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SPI_Request_
{
  using Type = SPI_Request_<ContainerAllocator>;

  explicit SPI_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit SPI_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _data_out_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _data_out_type data_out;

  // setters for named parameter idiom
  Type & set__data_out(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->data_out = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_gopigo3_msg::srv::SPI_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_gopigo3_msg::srv::SPI_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_gopigo3_msg::srv::SPI_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_gopigo3_msg::srv::SPI_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_gopigo3_msg::srv::SPI_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_gopigo3_msg::srv::SPI_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_gopigo3_msg::srv::SPI_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_gopigo3_msg::srv::SPI_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_gopigo3_msg::srv::SPI_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_gopigo3_msg::srv::SPI_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_gopigo3_msg__srv__SPI_Request
    std::shared_ptr<ros2_gopigo3_msg::srv::SPI_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_gopigo3_msg__srv__SPI_Request
    std::shared_ptr<ros2_gopigo3_msg::srv::SPI_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SPI_Request_ & other) const
  {
    if (this->data_out != other.data_out) {
      return false;
    }
    return true;
  }
  bool operator!=(const SPI_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SPI_Request_

// alias to use template instance with default allocator
using SPI_Request =
  ros2_gopigo3_msg::srv::SPI_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_gopigo3_msg


#ifndef _WIN32
# define DEPRECATED__ros2_gopigo3_msg__srv__SPI_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros2_gopigo3_msg__srv__SPI_Response __declspec(deprecated)
#endif

namespace ros2_gopigo3_msg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SPI_Response_
{
  using Type = SPI_Response_<ContainerAllocator>;

  explicit SPI_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit SPI_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _data_in_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _data_in_type data_in;

  // setters for named parameter idiom
  Type & set__data_in(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->data_in = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_gopigo3_msg::srv::SPI_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_gopigo3_msg::srv::SPI_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_gopigo3_msg::srv::SPI_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_gopigo3_msg::srv::SPI_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_gopigo3_msg::srv::SPI_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_gopigo3_msg::srv::SPI_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_gopigo3_msg::srv::SPI_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_gopigo3_msg::srv::SPI_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_gopigo3_msg::srv::SPI_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_gopigo3_msg::srv::SPI_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_gopigo3_msg__srv__SPI_Response
    std::shared_ptr<ros2_gopigo3_msg::srv::SPI_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_gopigo3_msg__srv__SPI_Response
    std::shared_ptr<ros2_gopigo3_msg::srv::SPI_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SPI_Response_ & other) const
  {
    if (this->data_in != other.data_in) {
      return false;
    }
    return true;
  }
  bool operator!=(const SPI_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SPI_Response_

// alias to use template instance with default allocator
using SPI_Response =
  ros2_gopigo3_msg::srv::SPI_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_gopigo3_msg

namespace ros2_gopigo3_msg
{

namespace srv
{

struct SPI
{
  using Request = ros2_gopigo3_msg::srv::SPI_Request;
  using Response = ros2_gopigo3_msg::srv::SPI_Response;
};

}  // namespace srv

}  // namespace ros2_gopigo3_msg

#endif  // ROS2_GOPIGO3_MSG__SRV__DETAIL__SPI__STRUCT_HPP_
