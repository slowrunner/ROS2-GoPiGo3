#!/bin/bash

echo -e "\n*** Capturing left encoder topic (flow-style):"
echo "*** ros2 topic echo --once --flow-style /motor/encoder/left"
ros2 topic echo --once --flow-style /motor/encoder/left

echo -e "\n*** Capturing right encoder topic (flow-style):"
echo "*** ros2 topic echo --once --flow-style /motor/encoder/right"
ros2 topic echo --once --flow-style /motor/encoder/right

