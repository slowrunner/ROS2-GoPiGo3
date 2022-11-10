#!/bin/bash
echo -e "\n*** Downloading ROS2 GoPiGo3 Desktop Visualization Files"
wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/ros2desk/dave.urdf
wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/ros2desk/finmark.urdf
wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/ros2desk/gpgMin.urdf
wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/ros2desk/show_rqt_graph.sh
wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/ros2desk/run_image_view.sh
wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/ros2desk/view_frames.sh
wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/ros2desk/check_all_urdfs.sh
chmod +x *.sh
