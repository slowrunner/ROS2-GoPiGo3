# ROS2 GoPiGo3 Reference


##  ros2ws Files and Folders:
```
- build/    ROS2 C++ executables and symlinks to python files
- install/  Setup scripts for built packages
- log/      Build logs
- roslogs/  ROS2 Execution logs
- src/      Source code for all nodes


- build_all.sh                : Runs COLCON build on all nodes

- call_odom_reset_srv.sh      : publishes to gopigo3 node to reset the pose values (x,y,z,heading to 0)

- check_battery.sh            : Uses Both GoPiGo3 API directly and ROS2 echo of /battery_voltage topic 

- echo_battery_voltage.sh     : Uses ROS2 to display one /battery_voltage topic
- echo_distance_topic.sh      : ROS2 echo of /distance_sensor/distance topic
- echo_encoder_topics.sh      : Performs one echo of /motor/encoder/left and /motor/encoder/right topic
- echo_imu_topics.sh          : Performs one echo of /imu_sensor/imu  /imu_sensor/magnetometer and /imu_sensor/temp
- echo_lidar_topic.sh         : Performs one echo of LIDAR /scan  (Displays first 128 data points of the 720 angles)
- echo_map_topic.sh           : Echo one /map topic
- echo_motor_status_topic.sh  : Performs one echo of /motor/status topic ( [low_voltage flag, overloaded flag, power, encoder value, speed] for left and right motor )
- echo_odom_topic.sh          : echo one /odom topic contains x,y,z position and heading with speed in x,y,z axes and angular velocities around the x,y,z axes
- echo_ultrasonic_topic.sh    : Echos one /ultrasonic_ranger/range topic (meters)

- export_jpg_map.sh           : Outputs jpeg file from pgm format saved map


- gopigo3_battery.py
- install_slam_toolbox.sh

- list_active_topics.sh
- list_running_nodes.sh
- list_services.sh
- list_topics_with_type.sh

- monitor.sh
- my_mapper_params_online_async.yaml
- odometer.log

- pub_center_servo.sh
- pub_servo_right_45.sh

- rebuild.sh

- run_teleop_gopigo3_keyboard.sh
- save_map.sh

- show_distance_sensor_node_info.sh
- show_gopigo3_node_info.sh
- show_imu_node_info.sh
- show_lidar_node_info.sh
- show_ultrasonic_ranger_node_info.sh

- start_camera_node.sh
- start_dave_robot_and_joint_state.sh
- start_demo_listener.sh
- start_demo_talker.sh
- start_distance_sensor_node.sh
- start_finmark_robot_and_joint_state.sh
- start_gpgMin_robot_and_joint_state.sh
- start_image_pub.sh
- start_imu_node.sh
- start_odomenter.sh
- start_robot_dave.sh
- start_robot_finmark.sh
- start_robot_gpgMin.sh
- start_slam_toolbox.sh
- start_ultrasonic_ranger_node.sh
- start_ydlidar_x4.sh

- stop.py
- stop_robot.sh
- stop_slam_toolbox.sh

- v4l2_camera_params.yaml

- versions.sh
```
