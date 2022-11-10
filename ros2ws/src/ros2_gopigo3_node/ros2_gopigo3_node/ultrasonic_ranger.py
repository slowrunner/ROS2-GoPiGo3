#!/usr/bin/env python3

# File: ultrasonic_ranger.py

# Basic ROS2 Node to publish Grove Ultrasonic Range sensor readings

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
import sys

# from angles import from_degrees
from sensor_msgs.msg import Range
import gopigo3
from gopigo3 import GoPiGo3
import math

PORT = GoPiGo3.GROVE_1
PORT = GoPiGo3.GROVE_2

class UltrasonicRangerNode(Node):

    def __init__(self):
        super().__init__('ultrasonic_ranger')
        self.gpg = GoPiGo3() 
        self.gpg.set_grove_type(PORT, self.gpg.GROVE_TYPE.US)
        self.msg_range = Range()
        # setting frame_id to urdf link element "distance_sensor"
        self.msg_range.header.frame_id = "ultrasonic_ranger"
        self.msg_range.radiation_type = Range.ULTRASOUND  
        self.msg_range.min_range = 0.0200   #         2 cm /   20 mm
        self.msg_range.max_range = 3.000    # 3 m / 300 cm / 3000 mm
        # self.msg_field_of_view = from_degrees(25.0)     # +/- 12.5 degree FOV (~60cm at max range)
        self.msg_range.field_of_view = math.radians(15.0)     # +/- 7.5 degree FOV 
        self.pub = self.create_publisher(Range, '~/range', qos_profile=10)
        timer_period = 0.06  # 0.06 second = ~16 Hz
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.get_logger().info('Created ultrasonic_ranger node at {:.0f} hz'.format(1.0/timer_period))

    def read_ultrasonic_range_in_mm(self,gpg):
        try:
            reading = gpg.get_grove_value(PORT)
        except gopigo3.SensorError:
            reading = 0
        except gopigo3.ValueError:
            reading = 5010
        return reading

    def timer_callback(self):
        try:
            self.reading_mm = self.read_ultrasonic_range_in_mm(self.gpg)
            # print("distance reading: {} mm".format(self.reading_mm))
            self.msg_range.range = self.reading_mm/1000.0
            self.msg_range.header.stamp = self.get_clock().now().to_msg()
            self.pub.publish(self.msg_range)
            # self.get_logger().info('Publishing: {}'.format(self.msg_range))
        except:
            pass

def main(args=None):
    rclpy.init(args=args)

    us_node = UltrasonicRangerNode()

    try:
        rclpy.spin(us_node)
    except KeyboardInterrupt:
        pass
    except ExternalShutdownException:
        sys.exit(0)
    finally:
        us_node.destroy_node()
        try:
            rclpy.try_shutdown()
        except:
            pass

if __name__ == '__main__':
    main()
