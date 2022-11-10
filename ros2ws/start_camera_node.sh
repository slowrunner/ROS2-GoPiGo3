#!/bin/bash

# echo -e "\n*** THIS NODE DOES NOT FUNTION YET - USE start_image_pub.sh"
# exit

echo -e "\n*** Start Camera Node"
# echo "*** ros2 run v4l2_camera v4l2_camera_node"
# ros2 run v4l2_camera v4l2_camera_node
echo "*** ros2 run v4l2_camera v4l2_camera_node -ros-args --params-file /home/ubuntu/ros2ws/v4l2_camera_params.yaml"
ros2 run v4l2_camera v4l2_camera_node -ros-args --params-file /home/ubuntu/ros2ws/v4l2_camera_params.yaml
