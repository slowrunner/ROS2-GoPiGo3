#!/bin/bash

# FILE:  start_gpgMin_robot_and_joint_state.sh

echo -e "\n*** Starting Robot_State and Joint_State Publishers"
echo "*** with URDF file: gpgMin.urdf"
ros2 launch ros2_gopigo3_node ros2_gpgMin_state_and_joint.launch.py &
