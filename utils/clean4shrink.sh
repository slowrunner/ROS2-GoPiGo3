#!/bin/bash

# FILE:  clean4shrink.sh

# PURPOSE:  Prepare ROS2 GoPiGo3 image for shrink and distribution

rm -rf ~/ros2ws/roslogs/*
rm -rf ~/.ros/log/*
rm -rf ~/ros2ws/log/*
rm -f ~/ipcount
rm -f ~/ip.number
rm -f ~/ros2ws/*.log
rm -f ~/ros2ws/nohup
sudo rm -rf ~/ROS2-GoPiGo3

sudo rm -f /home/pi/Dexter/gpg3_config.json
sudo rm -f /etc/netplan/50-cloud-init.yaml
sudo cp ~/utils/network-config /boot/firmware/network-config
sudo cloud-init clean --logs
sudo cloud-init clean
history -c
history -w

