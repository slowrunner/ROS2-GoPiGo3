# SETUP 1: Ubuntu 22.04 LTS Server and GoPiGo3 on Pi4 2GB+

11/12/2022 Added /swapfile creation
10/13/2022 Mod for slowrunner/ROS2-GoPiGo3  
10/12/2022 Initial  


This procedure is fully headless by configuring WiFi before the first boot,  
uses ssh access to complete everything, and also adds zswap and GoPiGo3 drivers/API.  

After setup:  
- load on my Pi4B 2GB processor is about 1-3% of the processor total (load .05/4 to .1/4)  
  Mostly seems to be the pigpiod daemon  
- Memory usage   login reports "10%" - "free -h" reports 1.5GB free of 1.8GB total memory  
- Disk usage 4GB  
- proc temp 51C in 25C room  

*** Flash SD card with Raspberry Pi Imager v1.73 or higher:  
  (See https://www.raspberrypi.com/software/ for latest Raspberry Pi Imager)  
  Select CHOOSE OS  
  - Other general-purpose OS->Ubuntu->Ubuntu Server 22.04.1 LTS (64-bit)  
    (2022-08-11 as of this writing)  

  Select CHOOSE STORAGE  
  - Select the __GB  (used 32GB) SD Card  
  
  Select Settings Gear lower right  
  - Set hostname:  used ROS2HH  
  - Enable SSH: Use password authentication  
  - Set username and password:  ubuntu:your_chosen_password  
  - Configure wireless LAN  
    - SSID:  __your_WiFi_SSID__  
    - Password:  __your_WiFi_password__  
    - Wireless LAN country:  US  
  - Set locale settings:  
    - Time zone:  America/New_York  
    - Keyboard layout: us  

  - SAVE  

=== Mount the card to allow headless configuration  
- Pull card out, reinsert for next step  


=== Verify WiFi Headless config  
- Browse system-boot partition  
- Show in enclosing folder   
- Open Terminal at folder  
- nano network-config  
```
wifis:  
  wlan0:  
    dhcp4: true  
    optional: true           <-- may want to set to false to make boot wait for complete network  
    access-points:  
      "your_SSID":  
        password: "your_netpswd"  (this will be a long encrypted thing)  
```
- exit ctrl-x y  

NOTE:  this info is "eaten" by cloud-init and put in /etc/netplan/50-cloud-init.yaml  


=== Disable ipv6  

nano cmdline.txt  
ctrl-e to end of line  
add at end of line with a space in front:  ipv6.disable=1  
ctrl-x y  

or  
```
sed '$ s/$/ ipv6.disable=1/' cmdline.txt >cmdline.txt.new && mv cmdline.txt.new cmdline.txt  
```

unmount microSD card

==== Ubuntu Server First Boot  
-insert micro SD card in GoPiGo3 robot  
-power on  
  (ignore flashing green LED for time being)  
- on mac:  arp -a to check IP  

=== First Login  (may take a few minutes before alive..)  
ssh ubuntu@x.x.x.x  
    username: ubuntu  
    password: __what_you_set_in_settings__  

    If see SSH HOST KEY verification failed  
     on mac:  ssh-keygen -R x.x.x.x   

  System information at login:  
```
  System load:            0.271484375
  Usage of /:             7.8% of 28.94GB  (2.3GB)
  Memory usage:           11%
  Swap usage:             0%
  Temperature:            43.3 C
  Processes:              157
  Users logged in:        0
 ```

=== CONFIGURE SUDO GROUP PASSWORD-LESS SUDO  

sudo nano /etc/sudoers  

make sudo group look like:  
```
# Allow members of group sudo to execute any command with no password  
%sudo	ALL=(ALL:ALL) NOPASSWD: ALL  
```
=== UPDATING  

- Check for unattended upgrade  
$ pgrep -a unattended  

809 /usr/bin/python3 /usr/share/unattended-upgrades/unattended-upgrade-shutdown --wait-for-signal  

ok to continue

==== DISABLE FUTURE UNATTENDED UPDATES (its a robot not a server) ===

$ sudo nano /etc/apt/apt.conf.d/20auto-upgrades  
Change the "1" to "0" in both lines:  
```
APT::Periodic::Update-Package-Lists "0";  
APT::Periodic::Unattended-Upgrade "0";  
```

$ sudo apt purge -y unattended-upgrades  
$ sudo reboot  

After reboot, probably some packages still to upgrade:  

$ sudo apt update  
$ sudo apt upgrade -y  
(Probably will pop a dialog with \<OK\> highlighted - press ENTER key)  
(May next display list of services to be restarted - press ESC key)  


==== Setup zswap (Speed improvement for compiles, and needed for Pi4 2GB to run a desktop GUI)  

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


sudo nano /boot/firmware/cmdline.txt  
  add to end of line:  
```
 zswap.enabled=1 zswap.compressor=lz4 zswap.zpool=z3fold  
```

$ sudo nano /etc/initramfs-tools/modules  
  add at bottom:  
```  
lz4  
z3fold  
```

Then:  
sudo update-initramfs -u  
(wait till completes)  
$ sudo reboot  


Verify:  
```
$ grep -R . /sys/module/zswap/parameters/
/sys/module/zswap/parameters/same_filled_pages_enabled:Y
/sys/module/zswap/parameters/enabled:Y
/sys/module/zswap/parameters/max_pool_percent:20
/sys/module/zswap/parameters/compressor:lz4
/sys/module/zswap/parameters/zpool:z3fold
/sys/module/zswap/parameters/accept_threshold_percent:90

$ sudo dmesg | grep "loaded using pool"

[    1.072982] zswap: loaded using pool lz4/z3fold

```

# ==== BEGIN GOPIGO3 SPECIFIC STEPS  

===== Create a Pi user with a /home/pi default directory, /bin/bash login shell ===  
```
mkdir utils  
cd utils  
wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/mk_pi_user.sh  
chmod +x mk_pi_user.sh  
./mk_pi_user.sh  
```

==== GOPIGO3 LIBRARIES   
```
$ su pi  
Password: robots1234  
```
(Note: Continuing in as user pi in /home/ubuntu/utils)

```  
$ wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/install_gopigo3_on_ubuntu.sh  
$ chmod +x install_gopigo3_on_ubuntu.sh  
$ ./install_gopigo3_on_ubuntu.sh  
```

When completes:  
1) change pi password from robots1234   
```
passwd
```
2) try the tests below  
3) exit (back to user ubuntu)  
4) try the tests below  
5) reboot and try the tests again  



=== Test GoPiGo Functions  
```
$ python3 /home/pi/Dexter/GoPiGo3/Software/Python/Examples/Read_Info.py
$ python3 /home/pi/Dexter/GoPiGo3/Software/Python/Examples/LED.py
$ python3 /home/pi/Dexter/GoPiGo3/Software/Python/Examples/easy_Distance_Sensor.py
$ python3 /home/pi/Dexter/DI_Sensors/Python/Examples/IMUSensor.py
$ python3 /home/pi/Dexter/GoPiGo3/Software/Python/Examples/Servo.py
$ python3 /home/pi/Dexter/GoPiGo3/Software/Python/Examples/Motor_Turn.py
```

==== FULL POWEROFF BEFORE CONTINUING TO SETUP_2 (Don't skip this!) 
$ sudo shutdown -h now  

# CONTINUE [at Step 2 of Directed Install](Directed_Install.md#step-2-run-setup_2_ros2_humblehawksbill_on_gopigo3sh)
