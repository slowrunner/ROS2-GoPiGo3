#!/bin/bash

echo -e "\n*** Capturing one IMU topic (flow-style):"
echo "*** ros2 topic echo --once --flow-style /imu_sensor/imu"
ros2 topic echo --once --flow-style /imu_sensor/imu

echo -e "\n*** Capturing one IMU Magnetometer topic:"
echo "*** ros2 topic echo --once --flow-style /imu_sensor/magnetometer"
ros2 topic echo --once --flow-style /imu_sensor/magnetometer


echo -e "\n*** Capturing one IMU Temperature (degC) topic:"
echo "*** ros2 topic echo --once --flow-style /imu_sensor/temp"
ros2 topic echo --once --flow-style /imu_sensor/temp
