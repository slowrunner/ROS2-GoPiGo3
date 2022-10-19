# SETUP_3_TEST
Test and learn about the ROS2 GoPiGo3 

All tests assume remote login:  
- ssh ubuntu@x.x.x.x  
  password: robots1234  

and execution from ~/ros2ws:
- cd ros2ws
  
  
# TEST 1: Talker - Listener Test
```
1) From "First Remote Shell":
   ./start_demo_talker.sh

2) From "Second Remote Shell":
   ./start_demo_listener.sh
```


# TEST 2: ROS2 GoPiGo3 REMOTE CONTROL
```
1) From "First Remote Shell":
   ./start_gopigo3_nodes.sh
   
2) From "Second Remote Shell":
   ./run_teleop_gopigo3_keyboard.sh

Moving around:
   u    i    o
   j    k    l
   m    ,    .

anything else : stop

q/z : increase/decrease max speeds by 10%
w/x : increase/decrease only linear speed by 10%
e/c : increase/decrease only angular speed by 10%

CTRL-C to quit remote control - (does not kill ROS2 GoPiGo3 Nodes)

3) From either shell:
   ./stop_gopigo3_nodes.sh
   (Ignore all the errors - investigating 10/2022)
```


# TEST 3:  GETTING TO KNOW THE ROS2 GoPiGo3 NODES
1) From "First Remote Shell":  
   ./start_gopigo3_nodes.sh  
   
2) From "Second Remote Shell":  
- List Running Nodes
```
   ./list_running_nodes.sh
List running ROS2 nodes
ros2 node list
/distance_sensor
/gopigo3_node
/imu_sensor
/ultrasonic_ranger
```

- List Active Topics
```
   ./list_active_topics.sh
```

- List Active Topics (with Topic Type)
```
   ./list_active_topics_with_type.sh
```

- Show /gopigo3_node Info:
```
   ./show_gopigo3_node_info.sh
```

- Show /distance_sensor Node Info:
```
   ./show_distance_sensor_node_info.sh
```

- Show /ultrasonic_ranger Node Info:
```
   ./show_ultrasonic_ranger_node_info.sh
```

- Show some data topics
```
   ros2 topic echo --once /battery_voltage
   ros2 topic echo [--once] /odom
   ros2 topic echo --once /motor/encoder/left
   ros2 topic echo --once /motor/encoder/right
   ros2 topic echo --once /motor/status
   ros2 topic echo --once /distance_sensor/distance    (in meters)
   ros2 topic echo --once /ultrasonic_ranger/range     (in meters)
   ros2 node info /imu_sensor
   ros2 topic echo --once /imu_sensor/imu
   ros2 topic echo --once /imu_sensor/temp             (deg C)
```

# PUBLISHING COMMAND TOPICS TO THE ROS2 GOPIGO3

- Publish a data topic the GoPiGo3 node is subscribed to:
```
   Center Servo:
   ros2 topic pub --once /servo/position/S1 std_msgs/msg/Float64 '{data: 0.0}'
   
   Servo right 45 deg (-0.707 rads) Clockwise:
   ros2 topic pub --once /servo/position/S1 std_msgs/msg/Float64 '{data: -0.707}'
   
   Servo left 45 deg (0.707 rads) CounterClockwise:
   ros2 topic pub --once /servo/position/S1 std_msgs/msg/Float64 '{data: 0.707}'
```