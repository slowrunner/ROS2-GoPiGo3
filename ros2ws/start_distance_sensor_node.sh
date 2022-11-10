#!/bin/bash 

echo -e "\n*** Switching to ~/ros2ws"
cd ~/ros2ws

echo -e "\n*** Sourcing install/setup.bash"
. ~/ros2ws/install/setup.bash

echo -e "\n*** Start GoPiGo3 distance sensor node"
echo "*** ros2 run ros2_gopigo3_node distance_sensor &"
ros2 run ros2_gopigo3_node distance_sensor &

