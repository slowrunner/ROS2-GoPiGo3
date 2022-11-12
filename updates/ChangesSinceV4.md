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
cd ~/systests
mkdir swap
cd swap
wget https://raw.githubusercontent.com/slowrunner/ROS2-GoPiGo3/main/systests/swap/use1GB.py
chmod +x use1GB.py
```

# Test Swapfile
In another shell start monitoring memory use:  

```
cd ~/ros2ws
./monitor.sh
```

In the first shell:  

```
~/systests/swap/use1GB.py
```

and watch for Mem: line to show very little available, and then return to full memory available  

```
********** ROS2 GoPiGo3 MONITOR ******************************
Saturday 11/12/22
 09:23:02 up  1:01,  2 users,  load average: 0.15, 0.16, 0.10
temp=51.6'C
frequency(48)=1700419968
throttled=0x0
               total        used        free      shared  buff/cache   available
Mem:           1.8Gi       198Mi       1.4Gi       7.0Mi       228Mi       1.5Gi
Swap:          1.0Gi          0B       1.0Gi
GoPiGo3 Battery Voltage: 12.5 volts
 

********** ROS2 GoPiGo3 MONITOR ******************************
Saturday 11/12/22
 09:23:13 up  1:01,  2 users,  load average: 0.32, 0.20, 0.12
temp=52.5'C
frequency(48)=1200287104
throttled=0x0
               total        used        free      shared  buff/cache   available
Mem:           1.8Gi       1.6Gi        77Mi       7.0Mi       173Mi        91Mi
Swap:          1.0Gi       653Mi       370Mi
GoPiGo3 Battery Voltage: 12.6 volts


********** ROS2 GoPiGo3 MONITOR ******************************
Saturday 11/12/22
 09:23:24 up  1:01,  2 users,  load average: 0.35, 0.21, 0.12
temp=52.5'C
frequency(48)=1700419968
throttled=0x0
               total        used        free      shared  buff/cache   available
Mem:           1.8Gi       183Mi       1.5Gi       7.0Mi       172Mi       1.5Gi
Swap:          1.0Gi       3.0Mi       1.0Gi
GoPiGo3 Battery Voltage: 12.5 volts
``` 
