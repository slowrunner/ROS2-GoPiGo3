# ROS2 GoPiGo3 Statistics

## Configuration:
- ROS2 Humble Hawksbill
- Ubuntu 22.04 LTS Server (headless)
- Raspberry Pi 4B 2GB
- GoPiGo3
- "Stock GoPiGo3" Li-Ion 12v 27 Wh battery
   

## Idle ROS2 GoPiGo3 (Basic - no LiDAR, no Oak-D-Lite nodes, no speaker)
- Active:
  - GoPiGo3 Node
  - Distance Sensor Node
  - Ultrasonic Ranger Node
  - IMU Node
  - teleop_gopigo3_keyboard
  
- 28% CPU Load - 15 minute average load: 1.11 (out of 4.0 cores)
- 500MB memory used - free -h reports 1.3G available of 1.8G total
- 3.8W (0.35A at 10.8v)
- Expected Runtime: 6-7 hours

## Traveling ROS2 GoPiGo3 (Basic - no LiDAR, no Oak-D-Lite nodes, no speaker)
- Active:
  - GoPiGo3 Node
  - Distance Sensor Node
  - Ultrasonic Ranger Node
  - IMU Node
  - teleop_gopigo3_keyboard
  
- 28% CPU Load - 15 minute average load: 1.11 (out of 4.0 cores)
- 500MB memory used - free -h reports 1.3G available of 1.8G total
- 4.3W at .1 m/s (0.40A at 10.7v)
- 4.8W at .175 m/s (0.44A at 10.8v) 
- Expected Runtime: 5+ hours


## Speaker
- 0.4W (0.04A at 10.7v) idle
- 0.5W (0.05A at 10.7v) espeak-ng TTS

## ROS2 GoPiGo3 (w LiDAR, w Speaker, no Oak-D-Lite nodes)
- Active:
  - GoPiGo3 Node
  - Distance Sensor Node
  - Ultrasonic Ranger Node
  - IMU Node
  - teleop_gopigo3_keyboard
  - ydlidar_test.py  (still have to integrate ROS2 driver)
  
- 25-37% CPU Load - 1 minute average load: 1.49, 15 min ave load: 1.0 (out of 4.0 cores)
  - htop reports GoPiGo3 node: 22% CPU
  - IMU node: 16% CPU, 
  - US Ranger node: 3% CPU 
  - Distance Sensor: 1% CPU
  - ydlidar_test: 2% CPU
- 600MB memory used - free -h reports 1.2G available of 1.8G total
- 6.7W (0.67A at 9.9v)
- Expected Runtime: 3.7 hours (if ran LiDAR continuously - not planning to)
- Proc Temp: 60'C


