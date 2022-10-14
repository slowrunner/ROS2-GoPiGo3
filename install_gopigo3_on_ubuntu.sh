#!/bin/bash

# === install gcc and make
sudo apt install -y gcc
sudo apt install -y make
sudo apt install -y python3-dev

sudo chgrp spi /dev/spidev0.0
sudo chgrp spi /dev/spidev0.1

sudo chmod 660 /dev/spidev0.0
sudo chmod 660 /dev/spidev0.1

sudo chgrp gpio /sys/class/gpio/export
sudo chgrp gpio /sys/class/gpio/unexport

sudo chmod 770 /sys/class/gpio/export
sudo chmod 770 /sys/class/gpio/unexport

# Bring down the code
wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/pigpiod.service  
wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/99-com.rules

# Will need the following after this script finishes
wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/Setup_2_ROS2_HumbleHawksbill_on_GoPiGo3.sh
chmod 777 Setup_2_ROS2_HumbleHawksbill_on_GoPiGo3.sh

# sudo git clone -b install_on_ubuntu http://www.github.com/DexterInd/GoPiGo3.git /home/pi/Dexter/GoPiGo3
git clone http://www.github.com/DexterInd/GoPiGo3.git /home/pi/Dexter/GoPiGo3

sudo curl -kL dexterindustries.com/update_tools | bash -s -- --system-wide --use-python3-exe-too --install-deb-debs --install-python-package

sudo apt install -y --no-install-recommends python3-pip python3-numpy python3-curtsies

git clone https://github.com/DexterInd/DI_Sensors.git /home/pi/Dexter/DI_Sensors

sudo apt install -y python3-rpi.gpio

sudo apt install -y unzip

# === pigpiod

wget https://github.com/joan2937/pigpio/archive/master.zip
unzip master.zip
cd pigpio-master
make
sudo make install
cd ..
rm master.zip


sudo cp /home/ubuntu/utils/pigpiod.service /etc/systemd/system
sudo systemctl enable pigpiod.service
sudo systemctl start pigpiod.service
systemctl status pigpiod.service

# === setup RFR_Tools
sudo git clone https://github.com/DexterInd/RFR_Tools.git /home/pi/Dexter/lib/Dexter/RFR_Tools
sudo apt  install -y libffi-dev

cd /home/pi/Dexter/lib/Dexter//RFR_Tools/miscellaneous/
sudo python3 setup.py install

# ==== GPG3_POWER SERVICE ===
cd ~
sudo cp /home/pi/Dexter/GoPiGo3/Install/gpg3_power.service /etc/systemd/system
sudo chmod 644 /etc/systemd/system/gpg3_power.service
sudo systemctl daemon-reload
sudo systemctl enable gpg3_power.service
sudo systemctl start gpg3_power.service
systemctl status gpg3_power.service

# ==== SETUP GoPiGo3 and DI_Sensors Python3 eggs
cd /home/pi/Dexter/GoPiGo3/Software/Python
sudo python3 setup.py install
cd /home/pi/Dexter/DI_Sensors/Python
sudo python3 setup.py install

# ==== Setup non-root access rules ====

sudo cp /home/ubuntu/utils/99-com.rules /etc/udev/rules.d

cp /home/pi/Dexter/GoPiGo3/Install/list_of_serial_numbers.pkl /home/pi/Dexter/.list_of_serial_numbers.pkl

# === ESPEAK-NG
sudo apt install -y espeak-ng
pip3 install py-espeak-ng
espeak-ng "Am I alive? Can you hear me?"
# Install ffmpeg to allow ffplay to play tts from espeak-ng -w file 
sudo apt install -y ffmpeg

echo ""
echo "***************"
echo "Check that the mutex stuff will be available"
ls /usr/local/lib/python*/dist-packages/Dexter*
unzip -l /usr/local/lib/python3.10/dist-packages/Dexter_AutoDetection_and_I2C_Mutex-*-py3.10.egg

echo ""
echo "***************"
python3 /home/pi/Dexter/GoPiGo3/Software/Python/Examples/Read_Info.py

echo ""
echo "***************"
echo "/home/pi/Dexter/gpg3_config.json"
cat /home/pi/Dexter/gpg3_config.json
echo ""
echo "***************"
echo "You should change the pi password now with $ passwd"

echo ""
echo "****"
echo "Done gopigo3 setup - ready for reboot"
echo "After reboot run /home/ubuntu/utils/Setup_2_ROS2_HumbleHawksbill_on_GoPiGo3.sh"
echo "****"
