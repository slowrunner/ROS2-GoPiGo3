#!/bin/bash

echo -e "\n*** Capturing one battery voltage topic"
echo "*** ros2 topic echo --once /battery_voltage"
ros2 topic echo --once /battery_voltage
