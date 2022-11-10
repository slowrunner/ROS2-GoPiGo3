#!/bin/bash 

echo -e "\nSwitching to ~/ros2ws"
cd ~/ros2ws

echo -e "\nSourcing install/setup.bash"
. ~/ros2ws//install/setup.bash

echo -e "\nStart GoPiGo3 IMU sensor node"
echo "ros2 run ros2_gopigo3_node imu_sensor &"
ros2 run ros2_gopigo3_node imu_sensor &



