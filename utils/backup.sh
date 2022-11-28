#!/bin/bash

echo -e "Compressing ros2ws, utils to /home/ubuntu/ROS2HH_Backup.tgz"
cd ~/
rm -rf ~/ros2ws/log/*
rm -rf ~/ros3ws/roslogs/*
tar -cvzf ROS2HH_Backup.tgz ros2ws utils systests myYDLidar-SDK
