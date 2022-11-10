#!/bin/bash

echo -e "\n*** Capturing one /map topic (flow-style) from slam-toolbox:"
echo "*** ros2 topic echo --once --flow-style /map"
ros2 topic echo --once --flow-style /map
ros2 topic hz /map


