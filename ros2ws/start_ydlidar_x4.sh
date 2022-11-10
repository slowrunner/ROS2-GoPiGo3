#!/bin/bash 

echo -e "\n*** Switching to ~/ros2ws"
cd ~/ros2ws

echo -e "\n*** Sourcing install/setup.bash"
. ~/ros2ws/install/setup.bash

echo -e "\n*** Start YDLidar X4 node"
echo "*** ros2 launch ydlidar_ros2_driver ydlidar_launch.py"
ros2 launch ydlidar_ros2_driver ydlidar_launch.py
