#!/bin/bash

echo -e "\n*** Capturing one motor status topic (flow-style):"
echo "*** ros2 topic echo --once --flow-style /motor/status"
ros2 topic echo --once --flow-style /motor/status

