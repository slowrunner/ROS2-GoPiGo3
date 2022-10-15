# INSTALL "ROS2 FOR GOPIGO3" FROM IMAGE

Success! 

"ROS2 Humble Hawksbill on Ubuntu 22.04 LTS Server (64-bit) for GoPiGo3 Robots"  
is available as a 2GB image at:  

https://drive.google.com/file/d/1JojrIoto7Cy3iwkMuSY2OfPKnEhRgnN3/view?usp=sharing

# Install From Image
## 1) Download the custom image to your computer



## 2) Flash SD card with Raspberry Pi Imager v1.73 or higher:  
  (See https://www.raspberrypi.com/software/ for latest Raspberry Pi Imager)  
  
  Select CHOOSE OS  
  - (scroll to bottom) Use custom
    - navigate to the ros2hh.img.gz image
    - click Open

  Select CHOOSE STORAGE (DANGER! - CHOOSE WISELY)
  - Select your __GB SD Card (Minimum 8GB)  
  
  Select SETTINGS Gear in lower right  
  - Set hostname:  used ROS2HH  
  - Enable SSH: 
    - Use password authentication  
  - Set username and password:  
    - ubuntu
    - robots1234 (or password you make up)  
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




## 3) Insert ROS2HH microSD card in your GoPiGo3
  - Power On
  - Wait till GoPiGo3 Green LED stops flashing
  - Remove any existing ssh key for your GoPiGo3's IP
    - ssh-keygen -R x.x.x.x
  - SSH into your ROS2 GoPiGo3
    - ssh ubuntu@x.x.x.x
      - Answer yes to new key question
      - Enter robots1234 (or password you made up)
      
## 4)  === Test GoPiGo Functions  
```
$ python3 /home/pi/Dexter/GoPiGo3/Software/Python/Examples/Read_Info.py
$ python3 /home/pi/Dexter/GoPiGo3/Software/Python/Examples/Motor_Turn.py
```


## 5) Test ROS2 GoPiGo3  
- Follow steps in [Setup_3_Test.md](Setup_3_Test.md)

