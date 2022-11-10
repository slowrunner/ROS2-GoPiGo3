#!/bin/bash

echo -e "\nPublishing servo one right 45 degree position (-0.707 radians)"
ros2 topic pub --once /servo/position/S1 std_msgs/msg/Float64 '{data: -0.707}'
