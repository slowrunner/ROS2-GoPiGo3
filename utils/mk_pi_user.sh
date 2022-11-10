#!/bin/bash

sudo useradd -m pi
echo "pi:robots1234" | sudo chpasswd

sudo usermod -a -G ubuntu,adm,dialout,cdrom,sudo,audio,dip,video,plugdev,netdev,lxd pi
sudo usermod -a -G gpio,i2c,spi pi
sudo usermod -a -G gpio,i2c,spi ubuntu
sudo usermod -a -G pi ubuntu


echo "** pi groups: **"
groups pi

echo "** ubuntu groups: **"
groups ubuntu

# config pi default shell to bash
sudo chsh -s /bin/bash pi

# === ALLOW non-root SPI and GPIO  (Temporarily - will make permanent later)


sudo chgrp spi /dev/spidev0.0
sudo chgrp spi /dev/spidev0.1

sudo chmod 660 /dev/spidev0.0
sudo chmod 660 /dev/spidev0.1

sudo chgrp gpio /sys/class/gpio/export
sudo chgrp gpio /sys/class/gpio/unexport

sudo chmod 770 /sys/class/gpio/export
sudo chmod 770 /sys/class/gpio/unexport

echo "pi user configured"
