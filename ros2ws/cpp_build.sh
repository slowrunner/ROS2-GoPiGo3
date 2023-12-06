#!/bin/bash

# build for gopigo3_cpp package

echo "colcon build --packages-select gopigo3_cpp"
colcon build --packages-select gopigo3_cpp

echo "source ~/ros2ws/install/setup.bash"
source ~/ros2ws/install/setup.bash


