#!/usr/bin/env python3

# File: imu_sensor.py

# Basic ROS2 Node to publish imu sensor readings using Alan's SafeIMUSensor() class
"""
  Publishes:
     /imu/data
     /imu/mag   in units of full Tesla  1 microTesla = 0.000001 Tesla
     /imu/temp
  TODO:
     /imu/status
     /imu/raw
"""
import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
import sys
# from angles import from_degrees
from sensor_msgs.msg import Imu, Temperature, MagneticField
from std_msgs.msg import Header
# from diagnostic_msgs import DiagnosticStatus, DiagnosticArray, KeyValue
from ros_safe_inertial_measurement_unit import SafeIMUSensor
import math
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped
from datetime import datetime as dt

class IMUSensorNode(Node):

    def __init__(self):
        super().__init__('imu_sensor')
        self.imu = SafeIMUSensor(use_mutex=True)
        self.msg_imu = Imu()
        self.msg_temp = Temperature()
        self.msg_magn = MagneticField()
        # TODO: self.msg_diag = DiagnosticStatus()

        # setting frame_id to urdf link element "imu_link"
        self.hdr = Header(stamp=self.get_clock().now().to_msg(), frame_id="imu_link")  # use common time for all published topics

        self.imu_pub = self.create_publisher(Imu, '~/imu', qos_profile=10)
        self.temp_pub = self.create_publisher(Temperature, '~/temp', qos_profile=10)
        self.mag_pub = self.create_publisher(MagneticField, '~/magnetometer', qos_profile=10)
        # TODO: self.pub = self.create_publisher(DiagnosticStatus, '~/status', qos_profile=10)
        # Output Rate - Fusion in NDOF or IMUPLUS: 100Hz, Acc/Gyr: 100Hz,  Mags: 20Hz
        timer_period = 0.03333  #  second = 30 Hz
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.get_logger().info('Created imu_sensor node at {:.0f} hz'.format(1.0/timer_period))


        self.br = TransformBroadcaster(self)
        self.exCnt = 0

    def timer_callback(self):
        # Following Hands-On-ROS, performs multiple reads - perhaps should be reading all at once?

        self.q = self.imu.safe_read_quaternion()         # x,y,z,w
        self.mag = self.imu.safe_read_magnetometer()     # micro Tesla (µT)
        self.gyro = self.imu.safe_read_gyroscope()       # deg/second
        self.accel = self.imu.safe_read_accelerometer()  # m/s²
        self.temp = self.imu.safe_read_temperature()     # °C
        self.cal  = self.imu.safe_sgam_calibration_status() # sysCal, gyroCal, accCal, magCal none:0 - fully:3


        self.hdr.stamp = self.get_clock().now().to_msg()  # save common time stamp for all topics

        self.msg_temp.header=self.hdr
        self.msg_temp.temperature = float(self.temp)
        # self.get_logger().info('Publishing: {}'.format(self.msg_range))

        self.msg_imu.header = self.hdr
        self.msg_imu.linear_acceleration.x = float(self.accel[0])
        self.msg_imu.linear_acceleration.y = float(self.accel[1])
        self.msg_imu.linear_acceleration.z = float(self.accel[2])

        self.msg_imu.angular_velocity.x = math.radians(self.gyro[0])
        self.msg_imu.angular_velocity.y = math.radians(self.gyro[1])
        self.msg_imu.angular_velocity.z = math.radians(self.gyro[2])

        self.msg_imu.orientation.x = float(self.q[0])
        self.msg_imu.orientation.y = float(self.q[1])
        self.msg_imu.orientation.z = float(self.q[2])
        self.msg_imu.orientation.w = float(self.q[3])


        self.msg_magn.header = self.hdr
        self.msg_magn.magnetic_field.x = self.mag[0]*1e-6
        self.msg_magn.magnetic_field.y = self.mag[1]*1e-6
        self.msg_magn.magnetic_field.z = self.mag[2]*1e-6


        current_exCnt = self.imu.getExceptionCount()
        if (current_exCnt != self.exCnt):
            self.exCnt = current_exCnt
            print("\n{}: IMU Exception Count: {}".format(dt.now(),self.exCnt))
        else:
            try:
                # no exception so publish
                self.temp_pub.publish(self.msg_temp)
                self.imu_pub.publish(self.msg_imu)
                self.mag_pub.publish(self.msg_magn)
            except Exception:
                pass                # catch shutdown error

            # self.transform = TransformStamped(header=Header(stamp=self.hdr.stamp, frame_id="world"), child_frame_id=self.hdr.frame_id)
            # self.transform.transform.rotation = self.msg_imu.orientation
            # self.br.sendTransform(self.transform)



def main(args=None):
    rclpy.init(args=args)

    imu_node = IMUSensorNode()

    try:
        rclpy.spin(imu_node)
    except KeyboardInterrupt:
        pass
    except ExternalShutdownException:
        sys.exit(1)
    finally:
        imu_node.destroy_node()
        try:
            rclpy.try_shutdown()
        except:
            pass

if __name__ == '__main__':
    main()
