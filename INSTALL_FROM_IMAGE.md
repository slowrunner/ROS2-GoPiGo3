# INSTALL "ROS2 FOR GOPIGO3" FROM IMAGE

Updated: 10-27-2022 (Instructions and image link)

"ROS2 Humble Hawksbill on Ubuntu 22.04 LTS Server (64-bit) for GoPiGo3 Robots"  
is available as a 2GB image at:  

https://drive.google.com/file/d/1zz7hH7JhboGPJWlGVkS8RVd9aVddmPPc/view?usp=sharing

# Install From Image
## 1) Download the custom image to your computer



## 2) Flash SD card with Raspberry Pi Imager v1.73 or higher:  
  (See https://www.raspberrypi.com/software/ for latest Raspberry Pi Imager)  
  
  Select CHOOSE OS  
  - (scroll to bottom) Use custom
    - navigate to the ros2hhv3.img.gz image
    - click Open

  Select CHOOSE STORAGE (DANGER! - CHOOSE WISELY)
  - Select your __GB SD Card (Minimum 8GB)  
  
  Select SETTINGS Gear in lower right  
  - Set hostname:  used ROS2HH  
  - Enable SSH: 
    - Use password authentication  
  - Set username and password:  
    - ubuntu
    - robots1234  (cannot change it here!)  
  - Configure wireless LAN for your WiFi
    - SSID:  "__Your_WiFi_SSID__"  
    - Password:  "__Your_WiFi_password__"  
    - Wireless LAN country:  US  
  - Set locale settings:  
    - Time zone:  America/New_York  
    - Keyboard layout: us  

  Click SAVE  
  Click WRITE
    - Enter the user password on your laptop/desktop you logged as
  
  When complete and "safe to remove", pull the ROS2HH microSD card out
  
=== Mount the card to allow headless configuration  
- Pull card out, reinsert for next step  
```
NOTE:  On some computers (e.g. Linux MATE on my 9 yr old laptop) 
       Imager may result in an error message:
       "Could not mount FAT32 partition for writing"

       If you see this, the network-config and user-data settings 
       were not written, not a problem.
       
```

=== Verify WiFi Headless config **and add ethernet**:  
Re-Insert the uSD card to your computer:
- On Mac:
  - Browse system-boot partition  
  - Show in enclosing folder   
  - Open Terminal at folder

- On Linux: 
  - In terminal: cd /media/\<user\>/system-boot


$ nano network-config  
```
ethernets:
  eth0:
    dhcp4: true
    optional: true
wifis:  
  wlan0:  
    dhcp4: true  
    optional: true             
    access-points:  
      "your_SSID":  
        password: "your_netpswd"  (This may be a long encrypted thing if written correctly by Imager)  
```
- exit ctrl-x y  

NOTE:  this info is read by cloud-init to generate /etc/netplan/50-cloud-init.yaml  


unmount microSD card  




## 3) Insert ROS2HH microSD card in your GoPiGo3 - First Boot  
  - Power On  
  - Wait till GoPiGo3 Green LED stops flashing  
  - Press the GoPiGo3 power (off) button (next to the GoPiGo3 green LED)  
 
## 4) Second Boot  
  - Cycle Battery Switch to off, then back to On  
  - Press the GoPiGo3 power (on) button to start the second boot  
  - Wait till the GoPiGo3 Green LED stops flashing  
  - Press the GoPiGo3 power (off) button again to shutdown  
 
## 5) Third Boot  
  - Cycle Battery Switch to off, then back to On  
  - Press the GoPiGo3 power (on) button to start the third boot  
  - Wait till the GoPiGo3 Green LED stops flashing  
now ...  
  - Remove any existing ssh key for your GoPiGo3's IP  
    - ssh-keygen -R x.x.x.x  
  - SSH into your ROS2 GoPiGo3  
    - ssh ubuntu@x.x.x.x  
      - Answer yes to new ssh key question  
      - Enter robots1234  
      
## 4)  === Test GoPiGo Functions  
```
$ python3 /home/pi/Dexter/GoPiGo3/Software/Python/Examples/Read_Info.py  
$ python3 /home/pi/Dexter/GoPiGo3/Software/Python/Examples/Motor_Turn.py  
```


## 5) Test ROS2 GoPiGo3  
- Follow steps in [Setup_3_Test.md](Setup_3_Test.md)  

