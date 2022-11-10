#!/bin/bash

echo -e "\n*** Switching to ~/ros2ws"
cd ~/ros2ws

echo -e "\n*** Sourcing install/setup.bash"
. ~/ros2ws/install/setup.bash

echo -e "\n*** Start SNES gamepad node"
echo '*** ros2 launch teleop_twist_joy teleop-launch.py joy_config:="snes_slow" '
ros2 launch teleop_twist_joy teleop-launch.py joy_config:="snes_slow" 

