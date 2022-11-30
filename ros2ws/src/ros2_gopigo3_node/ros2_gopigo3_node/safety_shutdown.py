#!/usr/bin/env python

# FILE: safety_shutdown.py

"""
   Monitor /battery_voltage, warn user at 10v, shutdown at 9.75v

   Subscribes: /battery_voltage

   battery_voltage msg is a Float64

"""
import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
import sys
import logging
import datetime as dt
from rclpy.time import Time
import statistics
from std_msgs.msg import Float64
from rclpy.qos import qos_profile_sensor_data
import subprocess

SAFETY_SHUTDOWN_vBatt = 9.75   # 9.75v leaves ~15m reserve
WARNING_LOW_vBatt = 10.0       # Give ~20 minutes Advance Warning before safety shutdown

DEBUG = False

# Uncomment for debug prints to console

DEBUG = True

LOGFILE = 'safety.log'

class SafetyNode(Node):

  current_timestamp = Time()    # header.stamp (int32 sec, uint32 nanosec)




  def __init__(self):
    super().__init__('safety_shutdown')

    self.vBattList = []
    self.vBatt  = 999

    self.sub = self.create_subscription(
      Float64,
      'battery_voltage',
      self.sub_callback,
      qos_profile_sensor_data)  # best effort depth 10 sensor profile

    self.sub  # prevent unused var warning

    if DEBUG:
        dtstr = dt.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        printMsg = '\n{}| safety_shutdown.py: *** /battery_voltage subscriber created'.format(dtstr)
        print(printMsg)
        # self.get_logger().info('*** /battery_voltage subscriber created')

    self.safetyLog = logging.getLogger('safetyLog')
    self.safetyLog.setLevel(logging.INFO)

    self.loghandler = logging.FileHandler(LOGFILE)
    self.logformatter = logging.Formatter('%(asctime)s|%(message)s',"%Y-%m-%d %H:%M:%S")
    self.loghandler.setFormatter(self.logformatter)
    self.safetyLog.addHandler(self.loghandler)


    period_for_timer = 60.0  # Once every 60 seconds
    self.timer = self.create_timer( period_for_timer, self.main_cb)  # call the do nothing call back  when ROS timer triggers
    if DEBUG:
        dtstr = dt.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        printMsg ='{}| safety_shutdown.py: created main_cb callback for once every {:.0f} seconds'.format(dtstr,period_for_timer)
        print(printMsg)
        # self.get_logger().info('*** safety_shutdown: created main_cp callback for once every {:.0f} seconds'.format(period_for_timer))

  def sub_callback(self,battery_voltage_msg):
      self.vBattList.append(battery_voltage_msg.data)
      if len(self.vBattList) > 10:
          self.vBattList = self.vBattList[-10:]
          # print(self.vBattList)
      self.vBatt = statistics.mean(self.vBattList)


  def main_cb(self):
      if self.vBatt < WARNING_LOW_vBatt:
          phrase = "Battery {:2.1f} volts".format(self.vBatt)
          vol = 30
          subprocess.check_output(['espeak-ng -s150 -ven-us+f5 -a'+str(vol)+' "%s"' % phrase], stderr=subprocess.STDOUT, shell=True)
      if DEBUG:
        dtstr = dt.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        printMsg = "{}| safety_shutdown.py: battery_voltage {:2.1f}v".format(dtstr, self.vBatt)
        print(printMsg)
        # self.get_logger().info('*** safety_shutdown: main_cb executing')
        # self.get_logger().info('*** battery_voltage: {:2.1f}v'.format(self.vBatt))
      else:
        pass

def main(args=None):

  rclpy.init(args=args)
  safety_node = SafetyNode()
  try:
    rclpy.spin(safety_node)
  except KeyboardInterrupt:
      pass
  except ExternalShutdownException:
      sys.exit(0)
  finally:
    safety_node.destroy_node()
    try:
        rclpy.try_shutdown()
    except:
        pass


if __name__ == '__main__':
  main()
