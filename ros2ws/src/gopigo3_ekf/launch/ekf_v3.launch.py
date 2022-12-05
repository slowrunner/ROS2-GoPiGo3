# Adapted from basic_mobile_bot_v3.launch.py
#     Author: Addison Sears-Collins
#     https://automaticaddison.com/sensor-fusion-using-the-robot-localization-package-ros-2/

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition, UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, LaunchConfiguration, PythonExpression
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():

  # Set the path to different files and folders.
  pkg_share = FindPackageShare(package='gopigo3_ekf').find('gopigo3_ekf')
  default_launch_dir = os.path.join(pkg_share, 'launch')
  # default_model_path = os.path.join(pkg_share, 'models/basic_mobile_bot_v1.urdf')
  robot_localization_file_path = os.path.join(pkg_share, 'config/ekf.yaml') 
  # robot_name_in_urdf = 'basic_mobile_bot'
  # default_rviz_config_path = os.path.join(pkg_share, 'rviz/urdf_config.rviz')
  # world_file_name = 'basic_mobile_bot_world/smalltown.world'
  # world_path = os.path.join(pkg_share, 'worlds', world_file_name)


  # Declare the launch arguments
  # Specify the actions

  # Start robot localization using an Extended Kalman filter
  start_robot_localization_cmd = Node(
    package='robot_localization',
    executable='ekf_node',
    name='ekf_filter_node',
    output='screen',
    parameters=[robot_localization_file_path, 
    {}])



  # Create the launch description and populate
  ld = LaunchDescription()

  # Declare the launch options

  # Add any actions
  ld.add_action(start_robot_localization_cmd)

  return ld
