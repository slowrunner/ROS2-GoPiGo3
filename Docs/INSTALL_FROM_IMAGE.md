# INSTALL "ROS2 FOR GOPIGO3" FROM IMAGE

Updated: 12-06-2023 (ROS2HH version 5 release)

"ROS2 Humble Hawksbill on Ubuntu 22.04 LTS Server (64-bit) for GoPiGo3 Robots"  
is available as a 2.7GB image at:  

https://drive.google.com/file/d/1Nm8vYG05lMGZRwcfJGgwJH7uMcJtvrpQ/view?usp=drive_link  

# Install From Image
## 1) Download the custom image to your computer


## 2) Flash SD card with Raspberry Pi Imager v1.81 or higher:  
  (See https://www.raspberrypi.com/software/ for latest Raspberry Pi Imager)  

  Select CHOOSE DEVICE
  - Suggest Raspberry Pi 4 (but Pi 3B+ will get you started)
  
  Select CHOOSE OS  
  - (scroll to bottom) Use custom  
    - navigate to the saved location of the ```ROS2HHv5.img.gz``` image  
    - click Open  

  Select CHOOSE STORAGE (DANGER! - CHOOSE WISELY)  
  - Select your __GB SD Card (Minimum 16GB - image will expand to ~10GB)  
  
  Select SETTINGS Gear in lower right  
  - Set hostname:  ROS2HH  
  - Enable SSH:  
    - Use password authentication  
  - Set username and password:  
    - ubuntu  
    - robots1234   (use this for first boot)
  - Configure wireless LAN for your WiFi  
    - SSID:  "__Your_WiFi_SSID__"  
    - Password:  "__Your_WiFi_password__"   
    - Wireless LAN country:  US  
  - Set locale settings:  
    - Time zone:  America/New_York  
    - Keyboard layout: us  

  Click SAVE  
  Click WRITE  
    - PopUp:  Enter the user password of your laptop/desktop (you login as)  
  
  When complete and "safe to remove", pull the ROS2HH microSD card out  
  
=== Mount the card to allow headless configuration  
- Pull card out, reinsert for next step  
```
NOTE:  On some computers (e.g. Linux MATE on my 9 yr old laptop)  
       Imager may result in an error message:  
       "Could not mount FAT32 partition for writing"  

       If you see this, the network-config   
       was not rewritten, fix this in the next step.
       
```

=== Verify WiFi Headless config **and add ethernet**:  
!! MANDATORY STEP CUTS 2 MINUTES FROM BOOT UP TIME !!

Re-Insert the uSD card to your computer:
- On Mac:
  - Browse system-boot partition  
  - Show in enclosing folder   
  - Open Terminal at folder

- On Linux: 
  - In terminal: cd /media/\<user\>/system-boot


$ nano network-config  
```
version 2
ethernets:
   eth0:
     dhcp4: true
     dhcp6: false
     optional: true
wifis:  
  renderer: networkd
  wlan0:  
    dhcp4: true 
    dhcp6: false
    optional: true             
    access-points:  
      "your_SSID":  
        password: "your_netpswd"  (This may be a long encrypted thing if written correctly by Imager)  
```
- exit ctrl-x y  

NOTE:  this info will be read by cloud-init to generate /etc/netplan/50-cloud-init.yaml on the first boot

unmount microSD card  

## 3) First Boot  
  - **Connect powered speaker or headphones**  
  - Turn Battery Switch to On  
  - Press the GoPiGo3 power (on) button to start the first boot  
  - Wait till the GoPiGo3 Green LED stops flashing  
  - Listen for "WiFi IP x.x.x.x  ... Repeating, WiFi IP x.x.x.x"  
    (If after 5 minutes you do not hear the WiFi announcement,  
     press the GoPiGo3 power button to shutdown,  
     then press it again to power off,  
     then press it again to power on,  
     listen for WiFi IP ...)  
now ...  
  - Open a command shell on your desktop/laptop  
  - Remove any existing ssh key for your GoPiGo3's IP on your desktop/laptop  
    - ssh-keygen -R x.x.x.x  
  - SSH into your ROS2 GoPiGo3  
    - ssh ubuntu@x.x.x.x  
      - Answer yes to new ssh key question  
      - Enter robots1234 for the password
      
## 4)  === Change passwords   
  - $ su pi  
    Password: robots1234  
    passwd  
    Changing password for pi.  
    Current password: robots1234  
    New password: _______  
    Retype new password: _______
  - $ exit
  - $ whoami    
    ubuntu        <-- make sure it says ubuntu
  - $ passwd    
    Changing password for ubuntu.
    Current Passwd: robots1234  
    New password: __________  
    Retype new password: __________


## 5)  === TEST GoPiGo COMMUNICATION    
(Test Raspberry Pi communication with GoPiGo3 hardware control board)  
- Type ```./test_c``` and press Tab key,   
$ ./test_communication.sh     
```
*** ROS2 GOPIGO3 COMMUNICATION TEST - Read_info.py  
Manufacturer    :  Dexter Industries  
Board           :  GoPiGo3  
Serial Number   :  xxx  
Hardware version:  3.x.x  
Firmware version:  1.0.0  
Battery voltage :  10.065  
5v voltage      :  4.985  
```

## 6) === TEST GoPiGo3 MOTORS
- Type ```./test_m``` and press Tab key,
$ ./test_motors.sh
```
*** TEST GOPIGO3 MOTORS  
GOPIGO3 should:  
- Spin right about 90 degrees  
- Pause for a few seconds  
- Spin left about 180 degrees  
- Spin right, back approximately to starting heading  

*** NOT A PROBLEM IF DID NOT TURN TO EXACT 90 and -90 HEADINGS  
```

## 7) === Next: Test ROS2 GoPiGo3 (and Learn A Little About ROS2!)  
Follow steps in [Test_ROS2_GoPiGo3.md](https://github.com/slowrunner/ROS2-GoPiGo3/blob/main/Docs/Test_ROS2_GoPiGo3.md)  

 

