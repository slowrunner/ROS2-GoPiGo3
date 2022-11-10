#!/bin/bash

echo -e "\n*** STARTING ROS2 SLAM-TOOLBOX "
echo "*** Drive GoPiGo3 around room, generating /map topics"
echo "*** (Async: Best-effort processing, online - navigating on limited CPU)"
echo "*** ros2 launch slam_toolbox online_async_launch.py"
ros2 launch slam_toolbox online_async_launch.py 'slam_params_file:=./my_mapper_params_online_async.yaml'

