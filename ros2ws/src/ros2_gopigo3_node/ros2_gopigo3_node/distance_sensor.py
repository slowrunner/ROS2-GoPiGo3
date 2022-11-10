#!/usr/bin/env python3

# File: distance_sensor.py

# Basic ROS2 Node to publish distance sensor readings

import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
import sys

# from angles import from_degrees
from sensor_msgs.msg import Range
from di_sensors.easy_distance_sensor import EasyDistanceSensor
import math


class DistanceSensorNode(Node):

    def __init__(self):
        super().__init__('distance_sensor')
        self.ds = EasyDistanceSensor(use_mutex=True)
        self.msg_range = Range()
        # setting frame_id to urdf link element "distance_sensor"
        self.msg_range.header.frame_id = "distance_sensor"
        self.msg_range.radiation_type = Range.INFRARED   # LASER is closer to INFRARED than ULTRASOUND
        self.msg_range.min_range = 0.0200   #         2 cm /   20 mm
        self.msg_range.max_range = 3.000    # 3 m / 300 cm / 3000 mm
        # self.msg_field_of_view = from_degrees(25.0)     # +/- 12.5 degree FOV (~60cm at max range)
        self.msg_range.field_of_view = math.radians(25.0)     # +/- 12.5 degree FOV (~60cm at max range)
        self.pub = self.create_publisher(Range, '~/distance', qos_profile=10)
        timer_period = 0.1  # 0.1 second = 10 Hz
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.get_logger().info('Created distance_sensor node at {:.0f} hz'.format(1.0/timer_period))

    def timer_callback(self):
        self.reading_mm = self.ds.read_mm()
        # USING reading_mm() uses 60% CPU
        # print("distance reading: {} mm".format(self.reading_mm))
        self.msg_range.range = self.reading_mm/1000.0

        # USING this still uses 50% CPU.  Lower but not good
        # self.msg_range.range = self.VL53L0X.read_range_single_millimeters()

        self.msg_range.header.stamp = self.get_clock().now().to_msg()
        try:
            self.pub.publish(self.msg_range)
        except Exception as e:
            pass

def main(args=None):
    rclpy.init(args=args)

    ds_node = DistanceSensorNode()

    try:
        rclpy.spin(ds_node)
    except KeyboardInterrupt:
        pass
    except ExternalShutdownException:
        sys.exit(1)
    finally:
      ds_node.destroy_node()
      try:
          rclpy.try_shutdown()
      except:
          pass

if __name__ == '__main__':
    main()
