# ROS2 GoPiGo3 VISUALIZATION

# Using rqt

# Using rviz2

# Using rqt-image-view
1) Install: ```sudo apt ros-\<distro\>-rqt-image-view```  
   ```e.g. sudo apt install ros-humble-rqt-image-view```
2) create file start_image_view.sh  
```
#!/bin/bash

echo -e "\n*** Starting RQT Image View"
echo "*** ros2 run rqt_image_view rqt_image_view"
ros2 run rqt_image_view rqt_image_view &
```

3) ```chmod +x start_image_view.sh```  
4) Start image publisher ```./start_image_pub.sh``` on ROS2 GoPiGo3  
5) Start rqt-image-viewer ```./start_image_view.sh``` on desktop ROS2 environment.  
6) ROS2 GoPiGo3 publishes a new image from the Pi Camera about once every 10 seconds  
