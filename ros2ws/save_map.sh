#!/bin/bash

echo -e "\n*** SAVING MAP TO xyzzy.map"
echo '*** ros2 run nav2_map_server map_saver_cli -f "xyzzy.map" '
ros2 run nav2_map_server map_saver_cli -f "xyzzy.map"
