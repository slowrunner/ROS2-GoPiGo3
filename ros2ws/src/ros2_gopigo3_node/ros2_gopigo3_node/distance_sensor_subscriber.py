#!/usr/bin/env python3

# FILE: distance_sensor_subscriber.py

# Pythonic Migration of Chapter6-ROS-Programming/distance-sensor_subscriber.py
"""
OUTPUT: 

[INFO] [1626215483.238406798] [distance_sensor_subscriber]: -----------------
[INFO] [1626215483.243113551] [distance_sensor_subscriber]: sensor_msgs.msg.Range(header=std_msgs.msg.Header(stamp=builtin_interfaces.msg.Time(sec=1626215483, nanosec=231828125), frame_id='distance'), radiation_type=1, field_of_view=0.4363323152065277, min_range=0.019999999552965164, max_range=3.0, range=0.04699999839067459)
[INFO] [1626215483.247360879] [distance_sensor_subscriber]: -----------------
[INFO] [1626215483.251502895] [distance_sensor_subscriber]: GoPiGo3 Distance: 47.0 mm

"""
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Range


class DistanceSensorSubscriberNode(Node):

    def __init__(self):
        super().__init__('distance_sensor_subscriber')
        self.subscription = self.create_subscription(
            Range,
            'distance_sensor/distance',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.get_logger().info('distance_sensor subscriber node created')

    def listener_callback(self, msg):
        self.get_logger().info('-----------------')
        self.get_logger().info('{}'.format(msg))
        self.get_logger().info('-----------------')
        self.get_logger().info('GoPiGo3 Distance: {:.1f} mm'.format(msg.range*1000))

def main(args=None):
    rclpy.init(args=args)

    distance_sub_node = DistanceSensorSubscriberNode()

    try:
      rclpy.spin(distance_sub_node)
    except KeyboardInterrupt:
      distance_sub_node.get_logger().info('control-c: shutting down')
    finally:
      # Destroy the node explicitly
      # (optional - otherwise it will be done automatically
      # when the garbage collector destroys the node object)
      distance_sub_node.destroy_node()
      rclpy.shutdown()


if __name__ == '__main__':
    main()
