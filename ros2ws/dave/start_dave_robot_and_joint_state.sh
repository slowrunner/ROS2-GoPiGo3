#!/bin/bash

# FILE:  start_dave_robot_and_joint_state.sh

echo -e "\n*** Starting Robot_State and Joint_State Publishers"
echo "*** with URDF file: dave.urdf"
ros2 launch ros2_gopigo3_node ros2_dave_state_and_joint.launch.py &
