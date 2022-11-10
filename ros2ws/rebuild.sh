#!/bin/bash

echo -e "\n*** REBUILDING ROS2 GOPIGO3"

echo "*** Executing rebuild.sh ***"

echo "*** cd ~/ros2ws"
cd ~/ros2ws

echo "*** rosdep install -i --from-path src"
rosdep install -i --from-path src


echo -e "\n *** colcon build --allow-overriding ros2_gopigo3_msg --symlink-install"
colcon build --allow-overriding ros2_gopigo3_msg --symlink-install


# echo "*** colcon build --packages-select ros2_gopigo3_msg --allow-overriding ros2_gopigo3_msg"
# colcon build --packages-select ros2_gopigo3_msg --allow-overriding ros2_gopigo3_msg

# echo "*** colcon build --packages-select ros2_gopigo3_node"
# colcon build --packages-select ros2_gopigo3_node

# echo "*** colcon build --packages-select teleop_gopigo3_keyboard"
# colcon build --packages-select teleop_gopigo3_keyboard

# echo "*** colcon build --packages-select ros2_libcamera_pub"
# colcon build --packages-select ros2_libcamera_pub

# echo "** colcon build --symlink-install --packages-select ydlidar_ros2_driver"
# colcon build --symlink-install --packages-select ydlidar_ros2_driver

# echo "** colcon build --symlink-install --packages-select scan_client"
# colcon build --symlink-install --packages-select scan_client

echo -e "\n*** . install/setup.bash"
. install/setup.bash

echo "*** REBUILD DONE"
