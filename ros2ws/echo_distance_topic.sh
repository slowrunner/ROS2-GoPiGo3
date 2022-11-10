#!/bin/bash

echo -e "\n*** Capturing one distance sensor topic (flow-style):"
echo "*** ros2 topic echo --once --flow-style /distance_sensor/distance"
ros2 topic echo --once --flow-style /distance_sensor/distance

