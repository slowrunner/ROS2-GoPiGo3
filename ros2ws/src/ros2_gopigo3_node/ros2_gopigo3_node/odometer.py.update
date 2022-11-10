#!/usr/bin/env python

# FILE: odometer.py

"""
   Record distance traveled

   Subscribes: /odom

   Starts a recording a segment when motion detected
   Continues adding distance traveled until motion ends
   Logs datetime, new position/heading, and distance traveled

   nav_msgs.msg/Odometry message consists of:
      std_msgs/Header                    header
      string                             child_frame_id
      geometry_msgs/PoseWithCovariance   pose  (geometry_msgs/Point, geometry_msgs/Quaternion)
      geometry_msgs/TwistWithCovariance  twist
"""
import rclpy
import math
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
import sys
from nav_msgs.msg import Odometry    # (header, child_frame_id, pose, twist)
from geometry_msgs.msg import Point  # (position: float64 x,y,z)
import logging
import datetime as dt
from rclpy.time import Time

DEBUG = False

# Uncomment for debug prints to console
# DEBUG = True

ODOLOGFILE = 'odometer.log'
CLOSE_TOLERANCE = 0.001  # less than 1 millimeter in any direction for has not moved since last check
CLOSE_HEADING_TOLERANCE = 0.001745  # Heading varies from 0 to 2pi (6.28), 0.1deg is 0.001745 radians, (0.01745 is actually 1 deg from 6.28)
TWO_PI= math.pi * 2.0

def distance(p2,p1):   # (new,old)
  try:
    # Python3.8 hypot is n-dimensional
    dist=math.hypot(p2.x-p1.x, p2.y-p1.y, p2.z-p1.z)
  except:
    # older Python is 2D only
    dist=math.hypot(p2.x-p1.x, p2.y-p1.y)
  return dist



def euler_from_quaternion(q):
        """
        Convert a quaternion into euler angles (roll, pitch, yaw)
        roll is rotation around x in radians (counterclockwise)
        pitch is rotation around y in radians (counterclockwise)
        yaw is rotation around z in radians (counterclockwise)
        """
        x = q.x
        y = q.y
        z = q.z
        w = q.w
        t0 = +2.0 * (w * x + y * z)
        t1 = +1.0 - 2.0 * (x * x + y * y)
        roll_x = math.atan2(t0, t1)

        t2 = +2.0 * (w * y - z * x)
        t2 = +1.0 if t2 > +1.0 else t2
        t2 = -1.0 if t2 < -1.0 else t2
        pitch_y = math.asin(t2)

        t3 = +2.0 * (w * z + x * y)
        t4 = +1.0 - 2.0 * (y * y + z * z)
        yaw_z = math.atan2(t3, t4)

        return roll_x, pitch_y, yaw_z # in radians

class OdometerNode(Node):

  last_point = Point()
  current_point = Point()
  start_point = Point()

  last_heading = 0.0
  current_heading = 0.0
  start_heading = 0.0

  current_timestamp = Time()    # header.stamp (int32 sec, uint32 nanosec)
  last_timestamp = Time()
  start_timestamp = Time()    # (int32 sec, uint32 nanosec)

  moving = False
  moved_dist = 0.0
  total_dist = 0.0
  startup = True



  def __init__(self):
    super().__init__('odometer')

    self.sub = self.create_subscription(
      Odometry,
      'odom',
      self.sub_callback,
      10)
    self.sub  # prevent unused var warning
    self.get_logger().info('odometry topic subscriber created')

    self.odoLog = logging.getLogger('odoLog')
    self.odoLog.setLevel(logging.INFO)

    self.loghandler = logging.FileHandler(ODOLOGFILE)
    self.logformatter = logging.Formatter('%(asctime)s|%(message)s',"%Y-%m-%d %H:%M:%S")
    self.loghandler.setFormatter(self.logformatter)
    self.odoLog.addHandler(self.loghandler)


  def sub_callback(self,odometry_msg):
    # segment_msg = ()
    self.current_point = odometry_msg.pose.pose.position
    self.current_heading = euler_from_quaternion(odometry_msg.pose.pose.orientation)[2]
    self.current_timestamp = odometry_msg.header.stamp
    # self.get_loger().info(odom_msg.pose.pose)

    if self.startup:
        self.last_point = self.current_point
        self.last_heading = self.current_heading
        self.last_timestamp = self.current_timestamp
        self.start_point = self.current_point
        self.start_heading = self.current_heading

        self.startup = False
        pass


    # CHECK FOR NOT MOVING
    # Three isclose cases for checking heading:
    # 1) both values are in same quadrant
    # 2) current in quad 3 (+90 to +180), last in quad 2 (-90 to -179)
    # 3) current in quad 2 (-90 to -179), last in quad 3 (+90 to +180)
    if math.isclose(self.current_point.x, self.last_point.x, abs_tol=CLOSE_TOLERANCE) and \
       math.isclose(self.current_point.y, self.last_point.y, abs_tol=CLOSE_TOLERANCE) and \
       math.isclose(self.current_point.z, self.last_point.z, abs_tol=CLOSE_TOLERANCE) and \
       ( math.isclose(self.current_heading, self.last_heading, abs_tol=CLOSE_HEADING_TOLERANCE) or \
         math.isclose(self.current_heading, self.last_heading + TWO_PI, abs_tol=CLOSE_HEADING_TOLERANCE) or \
         math.isclose(self.current_heading + TWO_PI, self.last_heading, abs_tol=CLOSE_HEADING_TOLERANCE) ):
        if (self.moving == True):   # end of motion
            self.total_dist += abs(self.moved_dist)
            moving_seconds = self.current_timestamp.sec + (self.current_timestamp.nanosec/1000000000.0) - self.start_timestamp.sec - (self.start_timestamp.nanosec/1000000000.0)

            print("\n*** stopped moving")

            if DEBUG:
                print("start heading {:.4f} rads".format(self.start_heading))
                print("last heading {:.4f} rads".format(self.last_heading))
                print("current heading {:.4f} rads".format(self.current_heading))

                heading_deg = math.degrees(self.last_heading)
                printMsg = "last_point - x: {:.4f} y: {:.4f} z: {:.4f} heading: {:>4.1f}".format(self.last_point.x, self.last_point.y, self.last_point.z, heading_deg)
                heading_deg = math.degrees(self.start_heading)
                printMsg = "start_point - x: {:.4f} y: {:.4f} z: {:.4f} heading: {:>4.1f}".format(self.start_point.x, self.start_point.y, self.start_point.z, heading_deg)
                print(printMsg)

            heading_deg = math.degrees(self.current_heading)
            printMsg = "stop_point -  x: {:>6.3f} y: {:>6.3f} z: {:>6.3f} heading: {:>4.0f} - moved: {:>6.3f} meters in {:.1f}s".format(
                       self.current_point.x, self.current_point.y, self.current_point.z, heading_deg, self.moved_dist, moving_seconds)
            print(printMsg)
            # Log this travel segment to odom.log
            self.odoLog.info(printMsg)
            self.moving = False

        else:   # was not moving and still not moved
            pass

    else:  # moving
        if (self.moving == False):  # start of motion
            print("\n*** started moving")
            self.moving = True
            self.moved_dist = distance(self.current_point, self.last_point)
            if DEBUG:
                print("start heading {:.4f} rads".format(self.start_heading))
                print("last heading {:.4f} rads".format(self.last_heading))
                print("current heading {:.4f} rads".format(self.current_heading))
                heading_deg = math.degrees(self.last_heading)
                printMsg = "last_point - x: {:.4f} y: {:.4f} z: {:.4f} heading: {:>4.1f}".format(self.last_point.x, self.last_point.y, self.last_point.z, heading_deg)
                heading_deg = math.degrees(self.current_heading)
                printMsg = "current_point - x: {:.4f} y: {:.4f} z: {:.4f} heading: {:>4.1f}".format(self.current_point.x, self.current_point.y, self.current_point.z, heading_deg)


            heading_deg = math.degrees(self.start_heading)
            printMsg = "start_point - x: {:>6.3f} y: {:>6.3f} z: {:>6.3f} heading: {:>4.0f}".format(self.start_point.x, self.start_point.y, self.start_point.z, heading_deg)
            print(printMsg)
            self.odoLog.info(printMsg)
            self.start_timestamp = self.last_timestamp



        else:     # still moving
            self.moved_dist += distance(self.current_point, self.last_point)
            # heading_deg = math.degrees(self.current_heading)
            # print("current heading {:.3f} rads".format(self.current_heading))
            # print("current_point - x: {:.3f} y: {:.3f} z: {:.3f} heading: {:.0f} - moved: {:.3f}".format(self.current_point.x, self.current_point.y, self.current_point.z, heading_deg, self.moved_dist))

    self.last_point = self.current_point
    self.last_heading = self.current_heading
    self.last_timestamp = self.current_timestamp
    if self.moving == False:
        self.moved_dist = 0.0
        self.start_point = self.current_point
        self.start_heading = self.current_heading
        # self.start_timestamp = self.current_timestamp


def main(args=None):

  rclpy.init(args=args)
  odometer_node = OdometerNode()
  try:
    rclpy.spin(odometer_node)
  except KeyboardInterrupt:
      pass
  except ExternalShutdownException:
      sys.exit(0)
  finally:
    odometer_node.destroy_node()
    try:
        rclpy.try_shutdown()
    except:
        pass


if __name__ == '__main__':
  main()
