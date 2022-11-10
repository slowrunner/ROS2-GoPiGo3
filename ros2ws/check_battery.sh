#!/bin/bash

echo -e "\n*** Checking Battery with GoPiGo3 API"
python3 /home/ubuntu/ros2ws/gopigo3_battery.py

echo -e "\n*** Checking Battery with ROS2"
echo "ros2 topic echo --once /battery_voltage"
ros2 topic echo --once /battery_voltage

