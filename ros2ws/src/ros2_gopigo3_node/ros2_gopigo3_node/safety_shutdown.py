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
import os
import logging
import datetime as dt
from rclpy.time import Time
import statistics
from std_msgs.msg import Float64
from rclpy.qos import qos_profile_sensor_data
import subprocess
from easygopigo3 import EasyGoPiGo3


SAFETY_SHUTDOWN_vBatt = 9.2   #  ~15m before battery cutoff
REV_PROTECT_DIODE = 0.7
WARNING_LOW_vBatt = 9.3       # Give ~10 minutes Advance Warning before safety shutdown
# WARNING_LOW_vBatt = 11.4       # testing

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

    self.safetyLog.info('ROS2_GoPiGo3 Safety Node Started')


    period_for_timer = 60.0  # Once every 60 seconds
    self.timer = self.create_timer( period_for_timer, self.main_cb)  # call the do nothing call back  when ROS timer triggers

    self.egpg = EasyGoPiGo3(use_mutex = True)
    printMsg = self.voltages_string()

    self.safetyLog.info(printMsg)
    dtstr = dt.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    print(dtstr, printMsg)
    self.ros_val = False
    self.first_warning = True

    if DEBUG:
        dtstr = dt.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        printMsg ='{}| safety_shutdown.py: created main_cb callback for once every {:.0f} seconds'.format(dtstr,period_for_timer)
        print(printMsg)
        # self.get_logger().info('*** safety_shutdown: created main_cp callback for once every {:.0f} seconds'.format(period_for_timer))

  def vBatt_vReading(self):
        vReading = self.egpg.volt()
        vBatt = vReading + REV_PROTECT_DIODE
        return vBatt,vReading


  def voltages_string(self):
        vBatt, vReading = self.vBatt_vReading()
        return "Current Battery {:.2f}v EasyGoPiGo3 Reading {:.2f}v".format(vBatt,vReading)



  def sub_callback(self,battery_voltage_msg):
      self.vBattList.append(battery_voltage_msg.data)
      if len(self.vBattList) > 10:
          self.vBattList = self.vBattList[-10:]
          # print(self.vBattList)
      self.vBatt = statistics.mean(self.vBattList)
      self.ros_val = True

  def main_cb(self):
      if self.ros_val != True:   # if /battery_voltage topic not recieved, set vBatt from gopigo3 API
          self.vBatt = self.egpg.volt() + REV_PROTECT_DIODE
          if DEBUG:
              printMsg = "/battery_voltage topic not recieved in last minute"
              dtstr = dt.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
              print(dtstr, printMsg)

      if self.vBatt < SAFETY_SHUTDOWN_vBatt:
          phrase = "Battery {:2.1f} volts - Safety Shutdown Initiated".format(self.vBatt)
          self.safetyLog.info(phrase)
          vol = 75
          # subprocess.check_output(['espeak-ng -s150 -ven-us+f5 -a'+str(vol)+' "%s"' % phrase], stderr=subprocess.STDOUT, shell=True)
          subprocess.Popen(['espeak-ng -s150 -ven-us -a'+str(vol)+' "%s"' % phrase], stderr=subprocess.STDOUT, shell=True)
          self.safetyLog.info(phrase)
          os.system("sudo shutdown -h +2")
          sys.exit(0)

      if self.vBatt < WARNING_LOW_vBatt:
          phrase = "Warning, Battery {:2.1f} volts".format(self.vBatt)
          vol = 30
          # subprocess.check_output(['espeak-ng -s150 -ven-us+f5 -a'+str(vol)+' "%s"' % phrase], stderr=subprocess.STDOUT, shell=True)
          subprocess.Popen(['espeak-ng -s150 -ven-us -a'+str(vol)+' "%s"' % phrase], stderr=subprocess.STDOUT, shell=True)
          if self.first_warning == True:
              self.safetyLog.info(phrase)
              self.first_warning = False
      self.ros_val = False   # if ROS /battery_voltage callback gets called this will be True next time

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
