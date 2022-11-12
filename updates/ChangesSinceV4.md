# Changes since v4

## my_mapper_params_online_async.yaml: 0.01 is better value for resolution  
Fix: Edit ~/ros2ws/my_mapper_parames_online_async.yaml  
          change line:  
```          
                resolution: 0.05
          to:
                resolution: 0.01
```

## odometer.py only detects forward/backward motion, but not spins.  
Apply fix:  
```
    cd ~/ros2ws/src/ros2_gopigo3_node/ros2_gopigo3_node
    cp odometer.py odometer.py.v4
    wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/updates/odometer.py
```

## YDLidar X4 returning zero 25% of readings
Apply fix:
```
   cd ~/ros2ws/src/ydlidar_ros2_driver/params
   cp ydlidar.yaml ydlidar.yaml.v4
   wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/updates/ydlidar.yaml
```
## Image does not have swapfile setup
Apply fix:
```
cd ~/utils
wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/utils/make1GBswapfile.sh
chmod +x make1GBswapfile.sh
./make1GBswapfile.sh
```
