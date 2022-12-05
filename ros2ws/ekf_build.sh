#!/bin/bash

echo -e "\n*** REBUILDING ROBOT LOCALIZATION"

echo "*** Executing ekf_build.sh ***"

echo "*** cd ~/ros2ws"
cd ~/ros2ws

echo "*** rosdep install -i --from-path src"
rosdep install -i --from-path src


echo "*** colcon build --symlink-install --packages-select gopigo3_ekf"
colcon build --symlink-install --packages-select gopigo3_ekf

echo -e "\n*** . install/setup.bash"
. install/setup.bash

echo "*** REBUILD ROBOT LOCALIZATION DONE"
