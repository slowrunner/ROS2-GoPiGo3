#!/bin/bash

# FILE:  start_finmark_robot_and_joint_state.sh

echo -e "\n*** Starting Robot_State and Joint_State Publishers"
echo "*** with URDF file: finmark.urdf"
ros2 launch ros2_gopigo3_node ros2_finmark_state_and_joint.launch.py &
