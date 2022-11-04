# Tuning the ROS2 GoPiGo3

The GoPiGo3 has a nominal WHEEL-DIAMETER of 66.5 mm and WHEEL-BASE-WIDTH of 117 mm
but...  
Due to reality the effective wheel diameter and wheel base will be different.  

To have the most accurate encoder odometry, the effective values need to be determined and  
put in the JSON parameter file:  ```/home/pi/Dexter/gpg3_config.json```  

The first time your robot instantiates a GoPiGo3 or EasyGoPiGo3 class,  
the default values will be writen to the file.  
To view the file conveniently:
```
python3 ~/systests/gpg_config/print_gpg3_config.py

or of course:

more ~/pi/Dexter/gpg3_config.json
```

# Finding effective WHEEL-DIAMETER

Use ```drive_1m.py``` and ```wheelBaseRotateTest.py``` to test and find the best WHEEL-DIAMETER value:
1) ```cd ~/systests/gpg_config```
2) Mark a starting location and 1 meter away
3) Assess the default value with ```./drive_1m.py```
4) Refine WHEEL-DIAMETER value with ```./wheelDiaDriveTest.py```
   Program begins 
