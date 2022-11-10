#!/usr/bin/env python

# FILE: scan_client.py

"""
   Prints cardinal direction distances from LIDAR /scan topic
   Left (-0): XX.xxx   Forward (0): XX.xxx  Backward (180): XX.xxx  Right (-90): XX.xxx

   Subscribes: /scan


   sensor_msgs.msg/LaserScan message consists of:
      std_msgs/Header                    header
      string                             child_frame_id
"""
import rclpy
import math
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
import sys
from sensor_msgs.msg import LaserScan    # (header, child_frame_id, ...
import logging
import datetime as dt
from rclpy.time import Time

# pick one of the following qos profile methods - explicit or named profile
# from rclpy.qos import ReliabilityPolicy, QoSProfile
from rclpy.qos import qos_profile_sensor_data

from statistics import mean

DEBUG = False

# Uncomment for debug prints to console
DEBUG = True

NUM_READINGS = 14

class ScanClientNode(Node):


  def __init__(self):
    super().__init__('scan_client')

    self.sub = self.create_subscription(
      LaserScan,
      'scan',
      self.sub_callback,
      # pick one from following- explicit or named profile
      # QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT))
      qos_profile_sensor_data)  # best effort depth 10 sensor profile

    self.sub  # prevent unused var warning
    print('\n*** /scan topic subscriber created')
    self.left = []
    self.right = []
    self.front = []
    self.back = []
    self.debug_info_count = 0
    self.left_count = 0
    self.right_count = 0
    self.front_count = 0
    self.back_count = 0
    if DEBUG:
        self.lc2_always0 = "yes"
        self.lc1_always0 = "yes"
        self.c_always0 = "yes"
        self.rc1_always0 = "yes"
        self.rc2_always0 = "yes"

  def sub_callback(self,scan_msg):
    num_ranges = len(scan_msg.ranges)
    i_front_range = int(num_ranges/2)-1  # exact front ? 
    i_back_range = num_ranges - 1
    i_left_range = int(num_ranges * 0.75)
    i_right_range = int(num_ranges/4)

    # i_front_range = i_back_range

    if scan_msg.ranges[i_left_range] > 0:
        self.left += [scan_msg.ranges[i_left_range]]
        self.left_count += 1
    if len(self.left) > NUM_READINGS: self.left = self.left[-NUM_READINGS:]

    if scan_msg.ranges[i_right_range] > 0: 
        self.right += [scan_msg.ranges[i_right_range]]
        self.right_count += 1
    if len(self.right) > NUM_READINGS: self.right = self.right[-NUM_READINGS:]

    if scan_msg.ranges[i_front_range] > 0: 
        self.front += [scan_msg.ranges[i_front_range]]
        self.front_count += 1
    if len(self.front) > NUM_READINGS: self.front = self.front[-NUM_READINGS:]

    if scan_msg.ranges[i_back_range] > 0: 
        self.back += [scan_msg.ranges[i_back_range]]
        self.back_count += 1
    if len(self.back) > NUM_READINGS: self.back = self.back[-NUM_READINGS:]

    if len(self.left)>1: 
        dist_left_90 = format(mean(self.left), '.3f')
    else:
        dist_left_90 = "    "

    if len(self.right)>1: 
        dist_right_90 = format(mean(self.right), '.3f')
    else:
        dist_right_90 = "    "

    if len(self.front)>1: 
        dist_front_0 = format(mean(self.front), '.3f')
    else:
        dist_front_0 = "    "

    if len(self.back)>1: 
        dist_back_180 = format(mean(self.back), '.3f')
    else:
        dist_back_180 = "    "

    if DEBUG:
        self.debug_info_count += 1
        if self.debug_info_count % 9 == 1:
            
            print("\n\n************* DEBUG {} **********".format(int(self.debug_info_count/9)))
            print('*** Entering Scan Client Callback')
            print('*** angle_min: {:.0f} max: {:.0f} increment: {:.2f}'.format(
                math.degrees(scan_msg.angle_min),
                math.degrees(scan_msg.angle_max),
                math.degrees(scan_msg.angle_increment)))
            print('\n*** range[{}] index - left {} front {} back {} right {}'.format(
                num_ranges, i_left_range, i_front_range, i_back_range, i_right_range))

            print('\nleft: {:.3f} cnt: {}'.format(scan_msg.ranges[i_left_range], self.left_count))
            print('\nfront: {:.3f} cnt: {}'.format(scan_msg.ranges[i_front_range],self.front_count))
            print('\nback: {:.3f} cnt: {}'.format(scan_msg.ranges[i_back_range], self.back_count))
            print('\nright: {:.3f} cnt: {}'.format(scan_msg.ranges[i_right_range],self.right_count))

            lc2 = int(num_ranges/2)-3
            lc1 = lc2+1
            c  = lc2+2
            rc1 = lc2+3
            rc2 = lc2+4
            if scan_msg.ranges[lc2] > 0: self.lc2_always0 = "no"
            if scan_msg.ranges[lc1] > 0: self.lc1_always0 = "no"
            if scan_msg.ranges[c] > 0:  self.c_always0 = "no"
            if scan_msg.ranges[rc1] > 0: self.rc1_always0 = "no"
            if scan_msg.ranges[rc2] > 0: self.rc2_always0 = "no"
            print('\nscan_msg.ranges[{}]: {:.3f} always 0? {}'.format(lc2, scan_msg.ranges[lc2], self.lc2_always0))
            print('scan_msg.ranges[{}]: {:.3f} always 0? {}'.format(lc1, scan_msg.ranges[lc1],self.lc1_always0))
            print('scan_msg.ranges[{}]: {:.3f} always 0? {}'.format(c, scan_msg.ranges[c],self.c_always0))
            print('scan_msg.ranges[{}]: {:.3f} always 0? {}'.format(rc1, scan_msg.ranges[rc1],self.rc1_always0))
            print('scan_msg.ranges[{}]: {:.3f} always 0? {}'.format(rc2, scan_msg.ranges[rc2],self.rc2_always0))


            print("************* DEBUG **********\n")

    print(f'left: {dist_left_90} front: {dist_front_0} back: {dist_back_180} right: {dist_right_90}',end="\r")





def main(args=None):

  rclpy.init(args=args)
  scan_client_node = ScanClientNode()
  try:
    rclpy.spin(scan_client_node)
  except KeyboardInterrupt:
      pass
  except ExternalShutdownException:
      sys.exit(0)
  finally:
    scan_client_node.destroy_node()
    try:
        rclpy.try_shutdown()
    except:
        pass


if __name__ == '__main__':
  main()
