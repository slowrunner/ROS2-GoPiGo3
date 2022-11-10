#!/bin/bash

echo -e "\n*** Before /odom/reset, Check current /odom"
echo -e "*** Capturing one odometer topic (flow-style):"
echo "*** ros2 topic echo --once --flow-style /odom"
ros2 topic echo --once --flow-style /odom


echo -e "\n*** Calling /odom/reset service"
echo "*** ros2 service call /odom/reset std_srvs/srv/Trigger"
echo "*** (note no data required for Trigger type)"
ros2 service call /odom/reset std_srvs/srv/Trigger


echo -e "\n*** Now check /odom topic to see reset effect"
echo -e "*** Capturing one odometer topic (flow-style):"
echo "*** ros2 topic echo --once --flow-style /odom"
ros2 topic echo --once --flow-style /odom

