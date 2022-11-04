#!/bin/bash

# (Headless) SETUP ROS2 GoPiGo3 (HUMBLE HAWKSBILL) ON Ubuntu 22.04 64-bit Server (Jammy Jellyfish)

# === Make sure system is up to date before continuing
sudo apt update
sudo apt upgrade -y

# === Setup GPG key to ROS2
sudo apt update && sudo apt install curl gnupg lsb-release
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg


# === Add ROS2 Repository to sources
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(source /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

# === Install ROS2 Humble Hawksbill basic packages
sudo apt install -y ros-humble-ros-base

# === Source setup script
source /opt/ros/humble/setup.bash

# === Install Demo Nodes (Demos and Tutorials not installed by the ROS-base package)
sudo apt install -y ros-humble-demo-nodes-py
sudo apt install -y ros-humble-demo-nodes-cpp

# === Setup colcon build tool
sudo apt install -y python3-colcon-common-extensions

# === Setup ROS2 in user's .bashrc file
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc

# === Tell ROS2 to inhabit "Domain 0" 
echo "export ROS_DOMAIN_ID=0" >> ~/.bashrc

# === Install build environment
sudo apt install -y build-essential
pip3 install setuptools==58.2.0

# (does transforms3d need sudo pip3 ?)
pip3 install transforms3d

# === Setup ROSDEP tool
sudo apt install -y python3-rosdep2
rosdep update

# === INSTALL SAFE IMU CLASS
sudo pip3 install imu4gopigo3ros2

# ==== Create a ROS2 Workspace with source folder

mkdir -p ~/ros2ws/src

=== Setup colcon_cd in .bashrc
echo "source /usr/share/colcon_cd/function/colcon_cd.sh" >> ~/.bashrc

# === Setup colcon to know where workspace is
echo "export _colcon_cd_root=~/ros2ws" >> ~/.bashrc

# setup to run GoPiGo3 ROS2 nodes when login 
echo "source ~/ros2ws/install/setup.bash" >> ~/.bashrc

# === Bring down ROS2 GoPiGo3 nodes and helper scripts
wget https://github.com/slowrunner/ROS2-GoPiGo3/raw/main/ROS2HH_Backup_2022-11-03.tgz
tar -xzvf ROS2HH_Backup_2022-11-03.tgz -C ~/ros2ws

# === SETUP ROSDEP
sudo apt install -y python3-rosdep2
rosdep update

# === INSTALL SAFE IMU CLASS 
sudo pip3 install imu4gopigo3ros2



# === Build everything
. ~/.bashrc
cd ~/ros2ws
./build_all.sh
. install/setup.bash

echo -e "\n********** ROS2 GOPIGO3 READY FOR TEST ***********\n"
