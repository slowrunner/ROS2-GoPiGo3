#!/bin/bash

echo "Starting ROS2 listener (no output if no talker)"
set -v
ros2 run demo_nodes_py listener

