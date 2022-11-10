#!/bin/bash


while true; do echo -e "\n********** ROS2 GoPiGo3 MONITOR ******************************"; echo -n `date +"%A %D"`; echo ""; uptime; vcgencmd measure_temp && vcgencmd measure_clock arm && vcgencmd get_throttled; free -h; python3 /home/ubuntu/ros2ws/gopigo3_battery.py; sleep 10; echo " "; done
