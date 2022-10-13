# Full headless setup for a ROS2 GoPiGo3 robot

Procedure creates:

ROS2 GoPiGo3 Robot nodes
- (ros2_gopigo3_msg)
- ros2_gopigo3_node
- ultrasonic_ranger node
- distance_sensor node
- imu_sensor node
- teleop_gopigo3_keyboard node

ROS2 workspace: ros2ws
- src 
- helper scripts
  - build_all.sh
  - list_active_topics.sh
  - list_active_topics_with_type.sh
  - list_running_nodes.sh
  - run_teleop_gopigo3_keyboard.sh
  - show_distance_sensor_node_info.sh
  - show_gopigo3_node_info.sh
  - show_ultrasonic_ranger_node_info.sh
  - start_demo_listener.sh
  - start_demo_talker.sh
  - start_gopigo3_nodes.sh
  - start_imu_node.sh
  - stop_gopigo3_nodes.sh

ROS2 Humble Hawksbill 

"Safe for MultiProcessing" BNO055 IMU drivers/utilities on GoPiGo3

GoPiGo3 Robot drivers/API

Ubuntu 22.04 LTS Server (64-bit) on Raspberry Pi 
(Suggest Pi4 2GB, Pi3B+ is minimum) 
- with zswap enabled 
- IPv6 disabled 

# INSTALLATION STEPS:  

Step 1: Follow steps in Setup_1_Ubuntu22.04_LTS_Server.txt

Step 2: Run Setup_2_ROS2_HumbleHawksbill_on_GoPiGo3.sh 

Step 3: Test all helper scripts and topics 

```
GoPiGo3 NODE INFO :
/gopigo3_node
  Subscribers:
    /cmd_vel: geometry_msgs/msg/Twist
    /led/blinker/left: std_msgs/msg/UInt8
    /led/blinker/right: std_msgs/msg/UInt8
    /led/eye/left: std_msgs/msg/ColorRGBA
    /led/eye/right: std_msgs/msg/ColorRGBA
    /led/wifi: std_msgs/msg/ColorRGBA
    /motor/dps/both: std_msgs/msg/Int16
    /motor/dps/left: std_msgs/msg/Int16
    /motor/dps/right: std_msgs/msg/Int16
    /motor/position/both: std_msgs/msg/Int16
    /motor/position/left: std_msgs/msg/Int16
    /motor/position/right: std_msgs/msg/Int16
    /motor/pwm/both: std_msgs/msg/Int8
    /motor/pwm/left: std_msgs/msg/Int8
    /motor/pwm/right: std_msgs/msg/Int8
    /servo/position/S1: std_msgs/msg/Float64
    /servo/position/S2: std_msgs/msg/Float64
    /servo/pulse_width/S1: std_msgs/msg/Int16
    /servo/pulse_width/S2: std_msgs/msg/Int16
  Publishers:
    /battery_voltage: std_msgs/msg/Float64
    /joint_states: sensor_msgs/msg/JointState
    /motor/encoder/left: std_msgs/msg/Float64
    /motor/encoder/right: std_msgs/msg/Float64
    /motor/status: ros2_gopigo3_msg/msg/MotorStatusLR
    /odom: nav_msgs/msg/Odometry
    /parameter_events: rcl_interfaces/msg/ParameterEvent
    /rosout: rcl_interfaces/msg/Log
    /tf: tf2_msgs/msg/TFMessage
  Service Servers:
    /gopigo3_node/describe_parameters: rcl_interfaces/srv/DescribeParameters
    /gopigo3_node/get_parameter_types: rcl_interfaces/srv/GetParameterTypes
    /gopigo3_node/get_parameters: rcl_interfaces/srv/GetParameters
    /gopigo3_node/list_parameters: rcl_interfaces/srv/ListParameters
    /gopigo3_node/set_parameters: rcl_interfaces/srv/SetParameters
    /gopigo3_node/set_parameters_atomically: rcl_interfaces/srv/SetParametersAtomically
    /odom/reset: std_srvs/srv/Trigger
    /power/off: std_srvs/srv/Trigger
    /power/on: std_srvs/srv/Trigger
    /reset: std_srvs/srv/Trigger
    /spi: ros2_gopigo3_msg/srv/SPI
    
    
  DISTANCE SENSOR NODE INFO:  
  /distance_sensor
  Subscribers:

  Publishers:
    /distance_sensor/distance: sensor_msgs/msg/Range
    /parameter_events: rcl_interfaces/msg/ParameterEvent
    /rosout: rcl_interfaces/msg/Log
  Service Servers:
    /distance_sensor/describe_parameters: rcl_interfaces/srv/DescribeParameters
    /distance_sensor/get_parameter_types: rcl_interfaces/srv/GetParameterTypes
    /distance_sensor/get_parameters: rcl_interfaces/srv/GetParameters
    /distance_sensor/list_parameters: rcl_interfaces/srv/ListParameters
    /distance_sensor/set_parameters: rcl_interfaces/srv/SetParameters
    /distance_sensor/set_parameters_atomically: rcl_interfaces/srv/SetParametersAtomically
  
ULTRASONIC RANGER NODE INFO:
  /ultrasonic_ranger
  Subscribers:

  Publishers:
    /parameter_events: rcl_interfaces/msg/ParameterEvent
    /rosout: rcl_interfaces/msg/Log
    /ultrasonic_ranger/range: sensor_msgs/msg/Range
  Service Servers:
    /ultrasonic_ranger/describe_parameters: rcl_interfaces/srv/DescribeParameters
    /ultrasonic_ranger/get_parameter_types: rcl_interfaces/srv/GetParameterTypes
    /ultrasonic_ranger/get_parameters: rcl_interfaces/srv/GetParameters
    /ultrasonic_ranger/list_parameters: rcl_interfaces/srv/ListParameters
    /ultrasonic_ranger/set_parameters: rcl_interfaces/srv/SetParameters
    /ultrasonic_ranger/set_parameters_atomically: rcl_interfaces/srv/SetParametersAtomically

IMU SENSOR NODE INFO:
/imu_sensor
  Subscribers:

  Publishers:
    /imu_sensor/imu: sensor_msgs/msg/Imu
    /imu_sensor/magnetometer: sensor_msgs/msg/MagneticField
    /imu_sensor/temp: sensor_msgs/msg/Temperature
    /parameter_events: rcl_interfaces/msg/ParameterEvent
    /rosout: rcl_interfaces/msg/Log
    /tf: tf2_msgs/msg/TFMessage
  Service Servers:
    /imu_sensor/describe_parameters: rcl_interfaces/srv/DescribeParameters
    /imu_sensor/get_parameter_types: rcl_interfaces/srv/GetParameterTypes
    /imu_sensor/get_parameters: rcl_interfaces/srv/GetParameters
    /imu_sensor/list_parameters: rcl_interfaces/srv/ListParameters
    /imu_sensor/set_parameters: rcl_interfaces/srv/SetParameters
    /imu_sensor/set_parameters_atomically: rcl_interfaces/srv/SetParametersAtomically

```
  
