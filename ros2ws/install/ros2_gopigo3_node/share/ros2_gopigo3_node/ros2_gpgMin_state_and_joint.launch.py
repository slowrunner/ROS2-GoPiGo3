# FILE: ros2_gpgMin_state_and_joint.launch.py
# PURPOSE:  Launch robot and joint state publishers 

# USES:  urdf/gpgMin.urdf


import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, Shutdown
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():

    use_sim_time = LaunchConfiguration('use_sim_time', default='false')

    # URDF File to publish from
    urdf_file_name = 'gpgMin.urdf'


    urdf = os.path.join(
    #    get_package_share_directory('ros2_gopigo3_node'),'urdf',
        get_package_share_directory('ros2_gopigo3_node'),
        urdf_file_name)
    print("\n***** launch: urdf_file - {}".format(urdf))
    with open(urdf, 'r') as infp:
        robot_desc = infp.read()

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use sim (Gazebo) clock when True'),
        DeclareLaunchArgument(
            'model',
            default_value='gpgMin',
            description='Only visual and links for now'),
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{'use_sim_time': use_sim_time, 'robot_description': robot_desc}],
            arguments=[urdf]),
            # arguments=[urdf],
            # on_exit=Shutdown()),

        # Note in ROS2 passing use_gui to joint_state_publisher will attempt
        # to launcdh joint_state_publisher_gui (if installed)
        # (put joint_state_publisher_gui in an exec_depend in package.xml and 
        # run rosdep install -i --from-path src in the workspace root)
        Node(
            package='joint_state_publisher',
            executable='joint_state_publisher',
            name='joint_state_publisher',
            output='screen',
            parameters=[],
            arguments=[urdf]),
    ])
