#!/bin/bash

echo -e "\n*** Capturing one odometer topic (flow-style):"
echo "*** ros2 topic echo --once --flow-style /odom"
ros2 topic echo --once --flow-style /odom

