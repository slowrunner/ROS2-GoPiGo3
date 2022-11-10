#!/bin/bash 

echo -e "\n*** Switching to ~/ros2ws"
cd ~/ros2ws

echo -e "\n*** Sourcing install/setup.bash"
. ~/ros2ws/install/setup.bash

echo -e "\n*** Start Scan Client node"
echo "*** ros2 run scan_client scan_client"
ros2 run scan_client scan_client
