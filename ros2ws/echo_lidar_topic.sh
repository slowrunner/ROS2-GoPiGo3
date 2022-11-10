#!/bin/bash

echo -e "\n*** Capturing one ydLidar topic (flow-style):"
echo "*** ros2 topic echo --once --flow-style /scan"
ros2 topic echo --once --flow-style /scan

