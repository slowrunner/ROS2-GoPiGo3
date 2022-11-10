#!/bin/bash


echo "List active ROS2 topics - With topic TYPE"
set -v
ros2 topic list -t
