#!/bin/bash

echo "GoPiGo3 IMU Node Info"
set -v
ros2 node info /imu_sensor
