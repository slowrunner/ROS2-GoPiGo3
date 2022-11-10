#!/usr/bin/env python3
#
# FILE: ros2_gopigo3_node/gopigo3_node.py
#
# DOC:
#    ROS2 Migration of a ROS1 gopigo3 node
#    See: https://github.com/ros-gopigo3/gopigo3-pi-code/blob/master/pkg_mygopigo/src/gopigo3_driver.py
# AUTHORS:
#    Alan McDonley: ROS2 Migration 2021
#    Christian Rauch: Original author of ROS1 gopigo3_node.py 2018
#    Quint van Djik and John Cole: edits
#    Bernardo R Japon: edits for "Hands On ROS for Robotics Programming", Packt Publishing
#
# VERSION HISTORY:
#
#    2021:  Migration to ROS2, and
#               moved custom msgs to ros2_gopigo3_msg,
#               gpg_config.json comapatibility (gopigo3.py v1.3),
#               servo parameters
#               correct battery voltage for reverse polarity protection diode drop
#               /motor/dps/both, pwm/both, position/both added to minimize heading change
#               additional initialization information output
#               1 hz DEBUG mode with additional detail to stdout
#               Turbo/HighSpeed Motor profile TURBO_BIAS added
#    2020:  Hands On ROS transform to match book's gopigo3.urdf
#    2018:  Initial gopigo3_node.py and renamed gopigo3_driver.py

import sys

try:
    import gopigo3
except IOError as e:
    print("cannot find SPI device")
    sys.exit()

import rclpy
from rclpy.executors import ExternalShutdownException
from std_msgs.msg import UInt8, Int8, Int16, Float64
from std_msgs.msg import ColorRGBA
from std_msgs.msg import Header
from std_srvs.srv import Trigger
from geometry_msgs.msg import Twist
from geometry_msgs.msg import PoseWithCovariance, TwistWithCovariance
from geometry_msgs.msg import TransformStamped
from nav_msgs.msg import Odometry
from sensor_msgs.msg import JointState
from ros2_gopigo3_msg.msg import MotorStatusLR, MotorStatus
from ros2_gopigo3_msg.srv import SPI
from rclpy.node import Node
from rclpy.exceptions import ParameterNotDeclaredException
from rcl_interfaces.msg import ParameterDescriptor, ParameterType
from math import pi as M_PI

# from tf.transformations import quaternion_about_axis
from tf_transformations import quaternion_about_axis
# from tf.broadcaster import TransformBroadcaster
from tf2_ros import TransformBroadcaster

import numpy as np
# import os
# import time

NODE_VERSION = '0.6'

DEBUG = False
# Uncomment next line for Debugging
# DEBUG = True

class GoPiGo3Node(Node):
    # short constants
    ML = gopigo3.GoPiGo3.MOTOR_LEFT
    MR = gopigo3.GoPiGo3.MOTOR_RIGHT
    S1 = gopigo3.GoPiGo3.SERVO_1
    S2 = gopigo3.GoPiGo3.SERVO_2
    BL = gopigo3.GoPiGo3.LED_BLINKER_LEFT
    BR = gopigo3.GoPiGo3.LED_BLINKER_RIGHT
    EL = gopigo3.GoPiGo3.LED_EYE_LEFT
    ER = gopigo3.GoPiGo3.LED_EYE_RIGHT
    EW = gopigo3.GoPiGo3.LED_WIFI
    # Moved the following to __init__() to get from instance instead of class (gopigo3.py v1.3 compatibility)
    # WIDTH = gopigo3.GoPiGo3.WHEEL_BASE_WIDTH * 1e-3
    # CIRCUMFERENCE = gopigo3.GoPiGo3.WHEEL_CIRCUMFERENCE * 1e-3
    DIODE_DROP = 0.7  # Voltage Drop from reverse polarity protection to make get_voltage() equal actual battery voltage
    POWER_PIN = "23"
    # Move the following to __init__() and the node_cb() for parameterized servo limits
    # PULSE_RANGE = [575, 2425]

    # SERVO DEFAULTS can be reset by ros-arg parameters, parameter file, or parameter messages
    S1LPW = 2425         # defaults for ModRobotics Servo Kit
    S1RPW = 575
    S2LPW = 2425
    S2RPW = 575
    S1SECTOR = M_PI      # 180 degrees  (default is full travel)  10.278 usec/degree
    S2SECTOR = M_PI      # 180 degrees
    TURBO_BIAS = 0.01    # m/s add to twist.angular.z when twist.linear.x is greater than threshold
    BIAS_THRESH = 0.2    # m/s if cmd_vel:linear.x greater than threshold, apply turbo_bias

    def __init__(self):
        super().__init__('gopigo3_node')
        #### GoPiGo3 power management

        """
        # export pin
        if not os.path.isdir("/sys/class/gpio/gpio"+self.POWER_PIN):
            gpio_export = os.open("/sys/class/gpio/export", os.O_WRONLY)
            os.write(gpio_export, self.POWER_PIN.encode())
            os.close(gpio_export)
        time.sleep(0.1
        # set pin direction
        gpio_direction = os.open("/sys/class/gpio/gpio"+self.POWER_PIN+"/direction", os.O_WRONLY)
        os.write(gpio_direction, "out".encode())
        os.close(gpio_direction)

        # activate power management
        self.gpio_value = os.open("/sys/class/gpio/gpio"+self.POWER_PIN+"/value", os.O_WRONLY)
        os.write(self.gpio_value, "1".encode())
        """

        # GoPiGo3 and ROS setup
        self.g = gopigo3.GoPiGo3()

        # Short Constants in meters
        self.WIDTH = self.g.WHEEL_BASE_WIDTH * 1e-3
        self.CIRCUMFERENCE = self.g.WHEEL_CIRCUMFERENCE * 1e-3

        # Declare Parameters
        self.declare_parameter('S1LPW', self.S1LPW, ParameterDescriptor(description='Int16 Left Limit Pulse Width For Servo 1'))
        self.declare_parameter('S1RPW', self.S1RPW, ParameterDescriptor(description='Int16 Right Limit Pulse Width For Servo 1'))
        self.declare_parameter('S1SECTOR', self.S1SECTOR, ParameterDescriptor(description='Float Total Sector Angle in Rads for Servo 1'))

        self.declare_parameter('S2LPW', self.S2LPW, ParameterDescriptor(description='Int16 Left Limit Pulse Width For Servo 2'))
        self.declare_parameter('S2RPW', self.S2RPW, ParameterDescriptor(description='Int16 Right Limit Pulse Width For Servo 2'))
        self.declare_parameter('S2SECTOR', self.S2SECTOR, ParameterDescriptor(description='Float Total Sector Angle in Rads for Servo 2'))

        # Below the bias threshold, the GoPiGo3 will drive straight.  Bias must be added above the threshold to achieve straight travel.
        self.declare_parameter('TURBOBIAS', self.TURBO_BIAS, ParameterDescriptor(description='Float angular.z to add when linear.x cmd is over threshold'))
        self.declare_parameter('BIASTHRESH', self.BIAS_THRESH, ParameterDescriptor(description='Float linear.x cmd threshold for adding angular bias'))

        self.S1LPW  = self.get_parameter('S1LPW').get_parameter_value().integer_value
        self.S1RPW  = self.get_parameter('S1RPW').get_parameter_value().integer_value
        self.S1_PULSE_RANGE = [self.S1RPW, self.S1LPW]
        self.S1SECTOR  = self.get_parameter('S1SECTOR').get_parameter_value().double_value

        self.S2LPW  = self.get_parameter('S2LPW').get_parameter_value().integer_value
        self.S2RPW  = self.get_parameter('S2RPW').get_parameter_value().integer_value
        self.S2_PULSE_RANGE = [self.S2RPW, self.S2LPW]
        self.S2SECTOR  = self.get_parameter('S2SECTOR').get_parameter_value().double_value

        self.TURBO_BIAS  = self.get_parameter('TURBOBIAS').get_parameter_value().double_value
        self.BIAS_THRESH  = self.get_parameter('BIASTHRESH').get_parameter_value().double_value




        self.reset_odometry()

        # rclpy.init_node("gopigo3")

        self.br = TransformBroadcaster(self)

        # subscriber
        self.subscription = self.create_subscription(Int16,    "motor/dps/both",        lambda msg: self.g.set_motor_dps(self.ML+self.MR, msg.data),  10)  # ADDED: Alan
        self.subscription = self.create_subscription(Int16,    "motor/dps/left",        lambda msg: self.g.set_motor_dps(self.ML, msg.data),  10)
        self.subscription = self.create_subscription(Int16,    "motor/dps/right",       lambda msg: self.g.set_motor_dps(self.MR, msg.data),  10)
        self.subscription = self.create_subscription(Int8,     "motor/pwm/both",        lambda msg: self.g.set_motor_power(self.ML+self.MR, msg.data), 10) # ADDED: Alan
        self.subscription = self.create_subscription(Int8,     "motor/pwm/left",        lambda msg: self.g.set_motor_power(self.ML, msg.data), 10)
        self.subscription = self.create_subscription(Int8,     "motor/pwm/right",       lambda msg: self.g.set_motor_power(self.MR, msg.data), 10)
        # self.subscription = self.create_subscription(Int16,     "motor/limitdps",        lambda msg: self.g.set_motor_limits(self.ML+self.MR, dps=msg.data), 10)
        # self.subscription = self.create_subscription(Int16,     "motor/limitpwr",        lambda msg: self.g.set_motor_limits(self.ML+self.MR, power=msg.data), 10)
        self.subscription = self.create_subscription(Int16,    "motor/position/both",   lambda msg: self.g.set_motor_position(self.ML+self.MR, msg.data), 10) # ADDED: Alan
        self.subscription = self.create_subscription(Int16,    "motor/position/left",   lambda msg: self.g.set_motor_position(self.ML, msg.data), 10)
        self.subscription = self.create_subscription(Int16,    "motor/position/right",  lambda msg: self.g.set_motor_position(self.MR, msg.data), 10)
        self.subscription = self.create_subscription(Int16,    "servo/pulse_width/S1",   lambda msg: self.g.set_servo(self.S1, msg.data), 10)
        self.subscription = self.create_subscription(Int16,    "servo/pulse_width/S2",   lambda msg: self.g.set_servo(self.S2, msg.data), 10)
        self.subscription = self.create_subscription(Float64,  "servo/position/S1",      lambda msg: self.set_servo_angle(self.S1, msg.data), 10)
        self.subscription = self.create_subscription(Float64,  "servo/position/S2",      lambda msg: self.set_servo_angle(self.S2, msg.data), 10)
        self.subscription = self.create_subscription(Twist,    "cmd_vel",               self.on_twist, 10)

        self.subscription = self.create_subscription(UInt8,    "led/blinker/left",      lambda msg: self.g.set_led(self.BL, msg.data), 10)
        self.subscription = self.create_subscription(UInt8,    "led/blinker/right",     lambda msg: self.g.set_led(self.BR, msg.data), 10)
        self.subscription = self.create_subscription(ColorRGBA,"led/eye/left",          lambda c: self.g.set_led(self.EL, int(c.r*255), int(c.g*255), int(c.b*255)), 10)
        self.subscription = self.create_subscription(ColorRGBA,"led/eye/right",         lambda c: self.g.set_led(self.ER, int(c.r*255), int(c.g*255), int(c.b*255)), 10)
        self.subscription = self.create_subscription(ColorRGBA,"led/wifi",              lambda c: self.g.set_led(self.EW, int(c.r * 255), int(c.g * 255), int(c.b * 255)), 10)

        # publisher
        self.pub_enc_l = self.create_publisher(Float64,              'motor/encoder/left',  qos_profile=10)
        self.pub_enc_r = self.create_publisher(Float64,              'motor/encoder/right', qos_profile=10)
        self.pub_battery = self.create_publisher(Float64,            'battery_voltage',     qos_profile=10)
        self.pub_motor_status = self.create_publisher(MotorStatusLR, 'motor/status',        qos_profile=10)
        self.pub_odometry = self.create_publisher(Odometry,          "odom",                qos_profile=10)
        # note: joint_state in ros-gopigo3 and joint_states in Hands-On-ROS pkg_mygopigo
        self.pub_joints = self.create_publisher(JointState,          "joint_states",        qos_profile=10)

        # services
        self.srv_reset = self.create_service(Trigger,      'reset',       self.reset)
        self.srv_odom_reset = self.create_service(Trigger, 'odom/reset',  self.odom_reset)   # ADDED: Alan
        # self.srv_spi = self.create_service(SPI,         'spi',         lambda req: SPIResponse(data_in=self.g.spi_transfer_array(req.data_out)))
        self.srv_spi = self.create_service(SPI,            'spi',         self.spi)
        self.srv_pwr_on = self.create_service(Trigger,     'power/on',    self.power_on)
        self.srv_pwr_off = self.create_service(Trigger,    'power/off',   self.power_off)

        # rate = rclpy.Rate(rclpy.get_param('hz', 30))   # in Hz
        if DEBUG:
            self.hz = 1  # 1 for testing 
        else:
            self.hz = 30   # TODO: this needs to be a parameter
        period_for_timer = 1.0 / self.hz
        self.timer = self.create_timer( period_for_timer, self.gopigo3_main_cb)  # call the gopigo3_node's main loop when ROS timer triggers 
        self.get_logger().info('ros2_gopigo3_node: created main loop callback at {} Hz'.format(self.hz))


        print("==================================")
        print("GoPiGo3 info:")
        print("Manufacturer    : ", self.g.get_manufacturer())
        print("Board           : ", self.g.get_board())
        print("Serial Number   : ", self.g.get_id())
        print("Hardware version: ", self.g.get_version_hardware())
        print("Firmware version: ", self.g.get_version_firmware())

        print("\nGoPiGo3 Configuration:")
        print("(Using default values or ~/Dexter/gpg3_config.json if present)")
        print("WHEEL_DIAMETER: {:.3f} mm".format(self.g.WHEEL_DIAMETER))
        print("WHEEL_BASE_WIDTH: {:.3f} mm".format(self.g.WHEEL_BASE_WIDTH))
        print("ENCODER_TICKS_PER_ROTATION: {} (per one motor revolution)".format(self.g.ENCODER_TICKS_PER_ROTATION))
        print("MOTOR_GEAR_RATIO: {} (motor revolutions per wheel revolution)".format(self.g.MOTOR_GEAR_RATIO))
        print("MOTOR_TICKS_PER_DEGREE: {:.2f} (of wheel rotation)".format(self.g.MOTOR_TICKS_PER_DEGREE))
        print("\n")
        print("Node Version: {}".format(NODE_VERSION))
        if DEBUG:
            print("DEBUG MODE - Rate: {} hz".format(self.hz))
        else:
            print("Rate: {} hz".format(self.hz))
        print("Servo1 PulseWidths L: {} R: {} us".format(self.S1LPW, self.S1RPW))
        print("Servo1 Total Sector Width: {} radians".format(self.S1SECTOR))
        print("Servo2 PulseWidths L: {} R: {} us".format(self.S2LPW, self.S2RPW))
        print("Servo2 Total Sector Width: {:.2f} radians".format(self.S2SECTOR))
        print("\n")
        print("Turbo Bias Correction: {:.3f} m/s".format(self.TURBO_BIAS))
        print("Bias Threshold Speed: {:.3f} m/s".format(self.BIAS_THRESH))
        print("==================================")





    # GoPiGo3Node main loop callback
    def gopigo3_main_cb(self):
        try:
            self.pub_battery.publish(Float64(data=self.g.get_voltage_battery()+self.DIODE_DROP))

            # publish motor status, including encoder value
            (flags, power, encoder, speed) = self.g.get_motor_status(self.ML)
            if DEBUG: print("left  - flags:{} power:{} encoder:{} speed:{}".format(flags,power,encoder,speed))

            status_left = MotorStatus(low_voltage=bool(flags & (1<<0)), overloaded=bool(flags & (1<<1)),
                                      power=power, encoder=float(encoder), speed=float(speed))
            self.pub_enc_l.publish(Float64(data=float(encoder)))

            (flags, power, encoder, speed) = self.g.get_motor_status(self.MR)
            if DEBUG: print("right - flags:{} power:{} encoder:{} speed:{}".format(flags,power,encoder,speed))
            status_right = MotorStatus(low_voltage=bool(flags & (1<<0)), overloaded=bool(flags & (1<<1)),
                                      power=power, encoder=float(encoder), speed=float(speed))
            self.pub_enc_r.publish(Float64(data=float(encoder)))

            self.pub_motor_status.publish(MotorStatusLR(header=Header(stamp=self.get_clock().now().to_msg()), left=status_left, right=status_right))

            # publish current pose
            (odom, transform)= self.odometry(status_left, status_right)
            self.pub_odometry.publish(odom)
            self.br.sendTransform(transform)

            # Handle Parameters changing during execution
            self.S1LPW = self.get_parameter('S1LPW').get_parameter_value().integer_value
            self.S1RPW = self.get_parameter('S1RPW').get_parameter_value().integer_value
            self.S1_PULSE_RANGE = [self.S1RPW, self.S1LPW]
            self.S1SECTOR  = self.get_parameter('S1SECTOR').get_parameter_value().double_value

            self.S2LPW = self.get_parameter('S2LPW').get_parameter_value().integer_value
            self.S2RPW = self.get_parameter('S2RPW').get_parameter_value().integer_value
            self.S2_PULSE_RANGE = [self.S2RPW, self.S2LPW]
            self.S2SECTOR  = self.get_parameter('S2SECTOR').get_parameter_value().double_value

            self.TURBO_BIAS  = self.get_parameter('TURBOBIAS').get_parameter_value().double_value
            self.BIAS_THRESH  = self.get_parameter('BIASTHRESH').get_parameter_value().double_value



            if DEBUG:
                print('S1LPW: {} S1RPW: {}'.format(self.S1LPW, self.S1RPW))
                print('S1SECTOR: {:.2f} rads'.format(self.S1SECTOR))
                print('S2LPW: {} S2RPW: {}'.format(self.S2LPW, self.S2RPW))
                print('S2SECTOR: {:.2f} rads'.format(self.S2SECTOR))
                print('TURBOBIAS: {:.2f} m/s'.format(self.TURBO_BIAS))
                print('BIASTHRESH: {:.2f} m/s'.format(self.BIAS_THRESH))
        except:
            pass

    def destroy_node(self):
        if DEBUG:
            print('destroy_node(): encoders: ({},{})'.format(self.g.get_motor_encoder(self.ML),self.g.get_motor_encoder(self.MR)))
        self.g.reset_motor_encoder(self.ML+self.MR)
        if DEBUG:
            print('destroy_node(): encoders: ({},{})'.format(self.g.get_motor_encoder(self.ML),self.g.get_motor_encoder(self.MR)))
        self.g.reset_all()
        if DEBUG:
            print('destroy_node(): encoders: ({},{})'.format(self.g.get_motor_encoder(self.ML),self.g.get_motor_encoder(self.MR)))
        # self.g.offset_motor_encoder(self.ML, self.g.get_motor_encoder(self.ML))
        # self.g.offset_motor_encoder(self.MR, self.g.get_motor_encoder(self.MR))
        """
        # deactivate power management
        os.write(self.gpio_value, "0".encode())
        os.close(self.gpio_value)

        # unexport pin
        if os.path.isdir("/sys/class/gpio/gpio" + self.POWER_PIN):
            gpio_export = os.open("/sys/class/gpio/unexport", os.O_WRONLY)
            os.write(gpio_export, self.POWER_PIN.encode())
            os.close(gpio_export)
        """
        super().destroy_node()


    def set_servo_angle(self, servo, angle):
        # map angle from [-pi/2,+pi/2] to pulse width [pulse_min,pulse_max]
        # cangle = np.clip(angle, -np.pi/2, np.pi/2)

        # map angle from [-SnSECTOR/2, +SnSECTOR/2] to pulse width [SnRPW, SnLPW]
        if (servo == self.S1):
            cangle = np.clip(angle, -self.S1SECTOR/2, self.S1SECTOR/2)
            # normalise to range [0,1]
            #pos_norm = (1+cangle/(np.pi/2))/2.0
            pos_norm = (1+cangle/(self.S1SECTOR/2))/2.0
            #pulse = self.PULSE_RANGE[0] + pos_norm * (self.PULSE_RANGE[1]-self.PULSE_RANGE[0])
            # set servo position by pulse width
            pulse = self.S1_PULSE_RANGE[0] + pos_norm * (self.S1_PULSE_RANGE[1]-self.S1_PULSE_RANGE[0])
            pulse = np.clip(pulse, self.S1_PULSE_RANGE[0], self.S1_PULSE_RANGE[1])
        else:
            cangle = np.clip(angle, -self.S2SECTOR/2, self.S2SECTOR/2)
            # normalise to range [0,1]
            pos_norm = (1+cangle/(self.S2SECTOR/2))/2.0
            pulse = self.S2_PULSE_RANGE[0] + pos_norm * (self.S2_PULSE_RANGE[1]-self.S2_PULSE_RANGE[0])
            pulse = np.clip(pulse, self.S2_PULSE_RANGE[0], self.S2_PULSE_RANGE[1])

        pulse = np.rint(pulse).astype(np.int)
        self.g.set_servo(servo, int(pulse))
        # publish servo position as joint
        servo_names = {self.S1: "servo1", self.S2: "servo2"}
        self.pub_joints.publish(JointState(name=[servo_names[servo]], position=[cangle]))
        if DEBUG: print('set_servo_angle({}): angle: {:.3f} clipped angle: {:.3f}  pulse: {}'.format(servo_names[servo],angle, cangle, pulse))

    def reset_odometry(self):
        if DEBUG:
            print('reset_odometry(): encoders: ({},{})'.format(self.g.get_motor_encoder(self.ML),self.g.get_motor_encoder(self.MR)))
        self.g.offset_motor_encoder(self.ML, self.g.get_motor_encoder(self.ML))
        self.g.offset_motor_encoder(self.MR, self.g.get_motor_encoder(self.MR))
        # self.g.reset_motor_encoder(self.ML+self.MR)
        if DEBUG:
            print('reset_odometry(): encoders: ({},{})'.format(self.g.get_motor_encoder(self.ML),self.g.get_motor_encoder(self.MR)))
        self.last_encoders = {'l': 0, 'r': 0}
        self.pose = PoseWithCovariance()
        self.pose.pose.orientation.w = 1.0

    def odom_reset(self, req, response):
        """ Reset encoders, orientation, and position to 0 """
        if DEBUG:
            print('odom_reset({}, {}): triggered'.format(req,response))
            print('odom_reset: type(req): {}'.format(type(req)))
            print('odom_reset: type(response): {}'.format(type(response)))
        self.g.reset_motor_encoder(self.ML+self.MR)
        self.last_encoders = {'l': 0, 'r': 0}
        self.pose.pose.orientation.x = 0.0
        self.pose.pose.orientation.y = 0.0
        self.pose.pose.orientation.z = 0.0
        self.pose.pose.orientation.w = 1.0
        self.pose.pose.position.x = 0.0
        self.pose.pose.position.y = 0.0
        response.success = True
        response.message = ""
        return response

    def reset(self, req):
        self.g.reset_all()
        self.reset_odometry()
        return [True, ""]

    def spi(self, req, response):
        # self.srv_spi = self.create_service(SPI,         'spi',         lambda req: SPIResponse(data_in=self.g.spi_transfer_array(req.data_out)))
        response.data_in = self.g.spi_transfer_array(req.data_out)
        return response

    def power_on(self, req):
        # os.write(self.gpio_value, "1".encode())
        return [True, "Power ON"]

    def power_off(self, req):
        # os.write(self.gpio_value, "0".encode())
        return [True, "Power OFF"]

    def on_twist(self, twist):
        # Compute left and right wheel speed from a twist, which is the combination
        # of a linear speed (m/s) and an angular speed (rad/s).
        # In the coordinate frame of the GoPiGo3, the x-axis is pointing forward
        # and the z-axis is pointing upwards. Since the GoPiGo3 is only moving within
        # the x-y-plane, we are only using the linear velocity in x direction (forward)
        # and the angular velocity around the z-axis (yaw).
        # source:
        #   https://opencurriculum.org/5481/circular-motion-linear-and-angular-speed/
        #   http://www.euclideanspace.com/physics/kinematics/combinedVelocity/index.htm

        self.g.set_motor_limits(self.g.MOTOR_LEFT+self.g.MOTOR_RIGHT,0)  # allow for maximum speed possible

        # correct for L/R motor power-velocity profile difference
        if (twist.linear.x > self.BIAS_THRESH):  twist.angular.z += self.TURBO_BIAS

        right_speed = twist.linear.x + twist.angular.z * self.WIDTH / 2
        left_speed = twist.linear.x - twist.angular.z * self.WIDTH / 2

        self.g.set_motor_dps(self.ML, left_speed/self.CIRCUMFERENCE*360)
        self.g.set_motor_dps(self.MR, right_speed/self.CIRCUMFERENCE*360)

    def odometry(self, left, right):
        lspeed = left.speed / 360.0 * self.CIRCUMFERENCE
        rspeed = right.speed / 360.0 * self.CIRCUMFERENCE
        # Compute current linear and angular speed from wheel speed
        twist = TwistWithCovariance()
        twist.twist.linear.x = (rspeed + lspeed) / 2.0
        twist.twist.angular.z = (rspeed - lspeed) / self.WIDTH

        # Compute position and orientation from travelled distance per wheel
        # http://www8.cs.umu.se/kurser/5DV122/HT13/material/Hellstrom-ForwardKinematics.pdf
        # position change per wheel in meter
        dl = (left.encoder - self.last_encoders['l']) / 360.0 * self.CIRCUMFERENCE
        dr = (right.encoder - self.last_encoders['r']) / 360.0 * self.CIRCUMFERENCE

        # set previous encoder state
        self.last_encoders['l'] = left.encoder
        self.last_encoders['r'] = right.encoder

        angle = (dr-dl) / self.WIDTH
        linear = 0.5*(dl+dr)
        if dr!=dl:
            radius = self.WIDTH/2.0 * (dl+dr) / (dr-dl)
        else:
            radius = 0

        # old state
        old_angle = 2*np.arccos(self.pose.pose.orientation.w)
        old_pos = np.array([self.pose.pose.position.x, self.pose.pose.position.y])

        # update state
        new_angle = (old_angle+angle) % (2*np.pi)
        # new_q = transformations.quaternion_about_axis(new_angle, (0, 0, 1))
        new_q = quaternion_about_axis(new_angle, (0, 0, 1))
        new_angle2 = 2 * np.arccos(self.pose.pose.orientation.w)
        if DEBUG: print("new_angle2", new_angle2)
        new_pos = np.zeros((2,))

        if abs(angle) < 1e-6:
            direction = old_angle + angle * 0.5
            dx = linear * np.cos(direction)
            dy = linear * np.sin(direction)
        else:
            dx = + radius * (np.sin(new_angle) - np.sin(old_angle))
            dy = - radius * (np.cos(new_angle) - np.cos(old_angle))

        new_pos[0] = old_pos[0] + dx
        new_pos[1] = old_pos[1] + dy

        self.pose.pose.orientation.x = new_q[0]
        self.pose.pose.orientation.y = new_q[1]
        self.pose.pose.orientation.z = new_q[2]
        self.pose.pose.orientation.w = new_q[3]
        self.pose.pose.position.x = new_pos[0]
        self.pose.pose.position.y = new_pos[1]

        odom = Odometry(header=Header(stamp=self.get_clock().now().to_msg(), frame_id="odom"), child_frame_id="base_link",
                        pose=self.pose, twist=twist)

        # Note: in ros-gopigo3
        # transform = TransformStamped(header=Header(stamp=self.get_clock().now().to_msg(), frame_id="world"), child_frame_id="gopigo")
        # in pkg_mygopigo
        transform = TransformStamped(header=Header(stamp=self.get_clock().now().to_msg(), frame_id="odom"), child_frame_id="base_link")
        transform.transform.translation.x = self.pose.pose.position.x
        transform.transform.translation.y = self.pose.pose.position.y
        transform.transform.translation.z = self.pose.pose.position.z
        transform.transform.rotation = self.pose.pose.orientation

        return odom, transform


def main(args=None):
    rclpy.init(args=args)

    gopigo3_node = GoPiGo3Node()

    try:
        rclpy.spin(gopigo3_node)
    except KeyboardInterrupt:
        pass
    except ExternalShutdownException:
        sys.exit(0)
    finally:
        # Destroy the node explictly - don't depend on garbage collector
        gopigo3_node.destroy_node()
        try:
            rclpy.try_shutdown()
        except:
            pass

if __name__ == '__main__':
    main()
