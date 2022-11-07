#/bin/bash

# installs and configures the ip_feedback service

chmod 777 ip_feedback.sh
chmod 777 setup_ip_feedback.sh

echo "copying ip_feedback.sh to /home/pi"
cp ip_feedback.sh /home/ubuntu/utils/

echo "copying ip_feedback.service to /etc/systemd/system"
sudo cp ./etc_systemd_system.ip_feedback.service /etc/systemd/system/ip_feedback.service
sudo systemctl daemon-reload
sudo systemctl enable ip_feedback
sudo service ip_feedback start
