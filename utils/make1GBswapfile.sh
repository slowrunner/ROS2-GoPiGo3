#!/bin/bash

echo -e "\n*** Creating 1GB Swapfile"
sudo swapoff /swapfile
sudo fallocate -l 1G /swapfile
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
if ! grep -q '/swapfile' /etc/fstab; then
    sudo su -c "echo '/swapfile swap swap defaults 0 0' >> /etc/fstab"
fi
echo "*** 1GB swapfile created"
free -h
echo "Does it show Swap now?"
