# ROS2 GoPiGo3 VISUALIZATION

## Get ROS2 GoPiGo3 Desktop Visualization Files
```
wget 
chmod +x get_ros2_gopigo3_desktop_visualization_files.sh
./get_ros2_gopigo3_desktop_visualization_files.sh
chmod +x *.sh
```

# Using rqt_graph to view nodes and topics
1) Install: ```sudo apt install ros-\<distro\>-rqt-graph```
   ```e.g. sudo apt install ros-humble-rqt-graph```
2) Type ```rqt_graph``` or ```show_rqt_graph.sh```
3) Configure view and update
  - Uncheck Hide: items
    - Dead sinks
    - Leaf topics
    - tf
    - Unreachable
  - Click the "Refresh ROS Graph" button (upper left double circular arrows)
  
# Using rviz2

# Using rqt-image-view
1) Install: ```sudo apt install ros-\<distro\>-rqt-image-view```  
   ```e.g. sudo apt install ros-humble-rqt-image-view```
2) Start image publisher ```./start_image_pub.sh``` on [u]ROS2 GoPiGo3[/u]  
3) Start rqt-image-viewer ```./start_image_view.sh``` on [u]desktop ROS2 environment[/u] 
4) ROS2 GoPiGo3 publishes a new image from the Pi Camera about once every 10 seconds  
