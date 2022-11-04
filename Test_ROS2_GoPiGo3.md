# Test_ROS2_GoPiGo3
Test and learn about the ROS2 GoPiGo3 

## ALL TESTS ASSUME REMOTE LOGIN:  
- ssh ubuntu@x.x.x.x  
  password: robots1234 (if not changed during installation steps)  

## AND EXECUTION FROM ~/ros2ws:
- cd ros2ws

## IF YOUR BOT STARTS RUNNING OFF - type ```stop```
(It sometimes happens mysteriously when shutting down the ROS2 robot nodes...)
  
  
# TEST 1: Talker - Listener Test
```
1) From "First Remote Shell":
   ./start_demo_talker.sh

2) From "Second Remote Shell":
   ./start_demo_listener.sh
   
3) Control-c in each shell to stop execution   
```


# TEST 2: ROS2 GoPiGo3 REMOTE CONTROL

1) From "First Remote Shell":  
   ./start_robot_gpgMin.sh  
   
2) From "Second Remote Shell":  
   ./run_teleop_gopigo3_keyboard.sh  
```
This node takes keypresses from the keyboard and publishes them  
as Twist messages. It works best with a US keyboard layout.  

Moving around:
   u    i    o
   j    k    l
   m    ,    .

anything else : stop

q/z : increase/decrease max speeds by 10%
w/x : increase/decrease only linear speed by 10%
e/c : increase/decrease only angular speed by 10%
```
- i : Moves forward  
- k : STOP MOTION    <---- Space Bar is also good for this  
- , : Moves backward  
- j : Spin Left  
- l : Spin Right  
- u : "Turns" Left (Forward + Rotation)  
- o : "Turns" Right (Forward + Rotation)  
- m : "Turns" Clockwise In Reverse  
- . : "Turns" Counter-Clockwise In Reverse  
 
CTRL-C to quit remote control - (does not kill ROS2 GoPiGo3 Nodes)  

3) From either shell (if do not see shell prompt, press CTRL-C in that shell):   
   ./stop_robot.sh  
   (Ignore any errors - Not a problem - investigating)  



# TEST 3:  GETTING TO KNOW THE ROS2 GoPiGo3 NODES
1) From "First Remote Shell":  
   ./start_robot_gpgMin.sh  
   
   (Finmark:  ./start_robot_finmark.sh)  
   (Dave:     ./start_robot_dave.sh)
   
2) From "Second Remote Shell":  
- List Running Nodes
```
   ./list_running_nodes.sh
List running ROS2 nodes
ros2 node list
/gopigo3_node
/joint_state_publisher
/robot_state_publisher
```

- List Active Topics
```
   ./list_active_topics.sh
   
List active ROS2 topics
ros2 topic list                   <--- NOTE: The ROS2 command line for this 
/battery_voltage
/cmd_vel
/joint_states
/led/blinker/left
/led/blinker/right
/led/eye/left
/led/eye/right
/led/wifi
/motor/dps/both
/motor/dps/left
/motor/dps/right
/motor/encoder/left
/motor/encoder/right
/motor/position/both
/motor/position/left
/motor/position/right
/motor/pwm/both
/motor/pwm/left
/motor/pwm/right
/motor/status
/odom
/parameter_events
/robot_description
/rosout
/servo/position/S1
/servo/position/S2
/servo/pulse_width/S1
/servo/pulse_width/S2
/tf
/tf_static
```

[Active Nodes And Topics Graph (from desktop rqt)](https://github.com/slowrunner/ROS2-GoPiGo3/blob/e5daf0c3193ef3f6c3554db23988b0a7b03dceed/Nodes%20and%20Topics%20ROS2%20GoPiGo3%20(gpgMin).jpg)

&nbsp;

- List Active Topics (with Topic Type)
```
   ./list_topics_with_type.sh

List active ROS2 topics - With topic TYPE
ros2 topic list -t
/battery_voltage [std_msgs/msg/Float64]
/cmd_vel [geometry_msgs/msg/Twist]
/joint_states [sensor_msgs/msg/JointState]
/led/blinker/left [std_msgs/msg/UInt8]
/led/blinker/right [std_msgs/msg/UInt8]
/led/eye/left [std_msgs/msg/ColorRGBA]
/led/eye/right [std_msgs/msg/ColorRGBA]
/led/wifi [std_msgs/msg/ColorRGBA]
/motor/dps/both [std_msgs/msg/Int16]
/motor/dps/left [std_msgs/msg/Int16]
/motor/dps/right [std_msgs/msg/Int16]
/motor/encoder/left [std_msgs/msg/Float64]
/motor/encoder/right [std_msgs/msg/Float64]
/motor/position/both [std_msgs/msg/Int16]
/motor/position/left [std_msgs/msg/Int16]
/motor/position/right [std_msgs/msg/Int16]
/motor/pwm/both [std_msgs/msg/Int8]
/motor/pwm/left [std_msgs/msg/Int8]
/motor/pwm/right [std_msgs/msg/Int8]
/motor/status [ros2_gopigo3_msg/msg/MotorStatusLR]
/odom [nav_msgs/msg/Odometry]
/parameter_events [rcl_interfaces/msg/ParameterEvent]
/robot_description [std_msgs/msg/String]
/rosout [rcl_interfaces/msg/Log]
/servo/position/S1 [std_msgs/msg/Float64]
/servo/position/S2 [std_msgs/msg/Float64]
/servo/pulse_width/S1 [std_msgs/msg/Int16]
/servo/pulse_width/S2 [std_msgs/msg/Int16]
/tf [tf2_msgs/msg/TFMessage]
/tf_static [tf2_msgs/msg/TFMessage]

```

- Show /gopigo3_node Info:
```
   ./show_gopigo3_node_info.sh
   
GoPiGo3 Node Info
ros2 node info /gopigo3_node
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
  Service Clients:

  Action Servers:

  Action Clients:
   
```


- Show some data topics
```
   ./echo_battery_voltage.sh
   
*** Capturing one battery voltage topic
*** ros2 topic echo --once /battery_voltage
data: 10.08
---


./echo_odom_topic.sh 

*** Capturing one odometer topic (flow-style):
*** ros2 topic echo --once --flow-style /odom
header:
  stamp:
    sec: 1667491458
    nanosec: 341272571
  frame_id: odom
child_frame_id: base_link
pose:
  pose:
    position:
      x: 0.0
      y: 0.0
      z: 0.0
    orientation:
      x: 0.0
      y: 0.0
      z: 0.0
      w: 1.0
      ...
      
---

```
# TEST 3 - MONITOR MEMORY AND CPU 

- In a separate ssh shell: Type ```./monitor.sh```  
```
********** ROS2 GoPiGo3 MONITOR ******************************
Thursday 11/03/22
 17:59:20 up 6 min,  3 users,  load average: 0.49, 0.44, 0.22
temp=44.8'C
frequency(48)=1300324224
throttled=0x0
               total        used        free      shared  buff/cache   available
Mem:           1.8Gi       308Mi       1.2Gi        10Mi       300Mi       1.3Gi
Swap:             0B          0B          0B
GoPiGo3 Battery Voltage: 11.3 volts

```

# TEST 4 - (If your GoPiGo3 has a "Servo 1"): PUBLISHING COMMAND TOPICS TO THE ROS2 GOPIGO3  

- Publish a data topic the GoPiGo3 node is subscribed to:  
```
   Center Servo:  ./pub_center_servo.sh
   
   Servo right: ./pub_servo_right_45.sh
   
```

# INFO: LOG LOCATIONS  
- ROS2 Node Execution Logs:  ~/ros2ws/roslogs   
- COLCON Build Logs: ~/ros2ws/log  

# INFO: LIST OF ALL HELPER SCRIPTS IN ~/ros2ws/  

[See Reference](https://github.com/slowrunner/ROS2-GoPiGo3/blob/e5daf0c3193ef3f6c3554db23988b0a7b03dceed/Reference.md)

