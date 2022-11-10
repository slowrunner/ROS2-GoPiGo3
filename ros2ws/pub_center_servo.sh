#!/bin/bash

echo -e "\nPublishing servo one center position (0.0)"
ros2 topic pub --once /servo/position/S1 std_msgs/msg/Float64 '{data: 0.0}'
