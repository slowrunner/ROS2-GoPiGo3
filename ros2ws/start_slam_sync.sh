#!/bin/bash

echo -e "\n*** STARTING ROS2 SLAM-TOOLBOX "
echo "*** Drive GoPiGo3 around room, generating /map topics"
echo "*** (Sync: Process every scan, online - may be slow with limited CPU)"
echo "*** ros2 launch slam_toolbox online_sync_launch.py 'slam_params_file:=./my_mapper_params_online_sync.yaml"
ros2 launch slam_toolbox online_sync_launch.py 'slam_params_file:=./my_mapper_params_online_sync.yaml'

