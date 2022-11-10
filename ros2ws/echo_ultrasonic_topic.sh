#!/bin/bash

echo -e "\n*** Capturing one ultrasonic range sensor topic (flow-style):"
echo "*** ros2 topic echo --once --flow-style /ultrasonic_ranger/range"
ros2 topic echo --once --flow-style /ultrasonic_ranger/range

