#!/usr/bin/env python3

# FILE: wheelDiaDriveTest.py

'''
# Routine for testing EasyGoPiGo  drive_inches() method
# under changing conditions using WHEEL_DIAMETER values to improve accuracy and repeatability
# Test Variables:
#   distance to drive (21.0 inches)  - change with dNN.N command
#   drive_speed (120 DPS)            - change with sNNN command
#   wheel diameter (66.77 mm makes my bot very accurate, repeatably)  - change by entering NN.N at prompt
#   check_motor_status(False)  will change to non-blocking drive and check left and right motor status - "c"
#   ranging_active(False)  will perform read_inches() during each check motor status loop  - "r" 
#   num_tries (1)  -change with xN  x2 will drive forward then back to starting point
#
#  Operation:  Return executes once, ? gives help
#
#  Results:
#     "Uncalibrated": 0.4% error (+0.25 inch error)
#     "Calibration" via wheel diameter adjustment: 0.1% drive-to-drive accuracy  (1/16 inch error in 5 feet travel)
#                   and 0.?% session, and session-to-session accuracy (? inch error in 5 feet travel)
#
'''

from __future__ import print_function
from __future__ import division

import time
# import easygopigo3   # don't get from site-packages, don't know what version you will get
import sys
from math import pi
import sys

try:
    sys.path.append('/home/pi/rosbot-on-gopigo3/plib')
    import easygopigo3
    import status
    import battery
    import runLog
    import myconfig
    ROSbot = True
except:
    ROSbot = False
    import easygopigo3  # get it from site-packages 

egpg = easygopigo3.EasyGoPiGo3(use_mutex = True)
# ds   = egpg.init_distance_sensor()
ps   = egpg.init_servo()   # initialize "SERVO1"

if ROSbot:
    runLog.logger.info("wheelDiaDriveTest Started")
    myconfig.setParameters(egpg,verbose=True)   # configure custom wheel dia and base

ps.rotate_servo(90)
time.sleep(0.5)
egpg.set_servo(egpg.SERVO_1,0)   # turn servo off to conserve energy

python_version = sys.version_info[0]
print("Python Version:",python_version)

def enc_to_dist(enc):
	return egpg.WHEEL_DIAMETER * pi * enc / 360.0

def minus_if_odd(a):
    if a & 1:  rv = -1
    else: rv = 1
    return rv

default_dist = 100.0  # cm (1m)
num_tries = 1
dist = default_dist
wd = egpg.WHEEL_DIAMETER  #  default GoPiGo3 WHEEL_DIAMETER is 66.5 mm
wbw = egpg.WHEEL_BASE_WIDTH  # default GoPiGo3 WHEEL_BASE_WIDTH is 117.0 mm
check_motor_status = False
read_motor_status_delay = 0.010
drive_speed = 120
ranging_active = False
ds_reading = 0

while True:
    print ("\nDrive {} cm with Wheel Dia.({:.2f} mm) at {} dps?  (? for help)".format(dist,wd,drive_speed))
    try:
        if python_version < 3: i = raw_input()
        else: i = input()
    except KeyboardInterrupt:
        print("Exiting...")
        egpg.stop()
        exit(0)

    if len(i) == 0:
        num_tries=1    # and execute one time
    elif i[0] == "m":
        dist  = float(i[1:])
        print("New drive distance:{:.1f} centimeters".format(dist))
        continue
    elif i == "c":
        check_motor_status = not check_motor_status
        print("check_motor_status is now {}".format(check_motor_status))
        continue
    elif i[0] == "d":
        read_motor_status_delay = float(i[1:])
        print("read_motor_status_delay is now {:.3f} seconds".format(read_motor_status_delay))
        continue
    elif i == "r":
        ranging_active = not ranging_active
        print("ranging_active is now {}".format(ranging_active))
        if ranging_active: check_motor_status = True
        print("check_motor_status is now {}".format(check_motor_status))
        continue
    elif i[0] == "j":
        egpg.WHEEL_DIAMETER = wd
        egpg.WHEEL_CIRCUMFERENCE = wd * pi
        egpg.WHEEL_BASE_WIDTH = wbw
        egpg.WHEEL_BASE_CIRCUMFERENCE = wbw * pi
        egpg.save_robot_constants()
        print("Wrote new robot constants to /home/pi/Dexter/gpg3_config.json")
        continue
    elif i == "q":
        print("Exiting...")
        egpg.stop()
        exit(0)
    elif i == "?":
        print("return executes once with stated values")
        print("mNNN   change distance to NNN centimeters")
        print("c      toggle check_motor_status")
        print("d.NNN  change read_motor_status_delay to .NNN seconds")
        print("xN     repeat drive N times (fwd, bwd, fwd...)")
        print("sNNN   change motor dps to NNN")
        print("wNN.n  set WHEEL_DIAMETER to NN.n")
        print("r      toggle ranging_active")
        print("j      write current wBase and wDia to /home/pi/Dexter/gpg3_config.json")
        print("q      (or ctrl-c) Exit")
        print("?      print this help")
        print("\nCurrent WHEEL_DIAMETER:{:.2f}".format(wd))
        print("WHEEL_BASE_WIDTH:{:.1f}".format(wbw))
        print("Current Distance:{}".format(dist))
        print("Current Speed:{} dps".format(drive_speed))
        print("check_motor_status: {}".format(check_motor_status))
        print("read_motor_status_delay:{:.3f}".format(read_motor_status_delay))
        print("ranging_active: {}".format(ranging_active))
        continue
    elif i[0] == "x":
        num_tries = int(float(i[1:]))
    elif i[0] == "s":
        drive_speed = int(float(i[1:]))
        print("New drive_speed:{}".format(drive_speed))
        continue
    elif i[0] == "w":
        wd = float(i[1:])
        print("New WHEEL_DIAMETER:{:.3f}".format(wd))
        continue
    else:
        print("Type ? for help")
        continue


    egpg.WHEEL_DIAMETER = wd
    egpg.WHEEL_CIRCUMFERENCE = wd * pi

    print("\nResetting Encoders")
    egpg.reset_encoders()
    time.sleep(1)
    try:
      for i in range(num_tries):
        print ("\n===== Drive {:.1f} centimeters with WHEEL_DIA: {:.2f} mm at {} dps ========".format(dist,wd,drive_speed))
        encoderStartLeft, encoderStartRight = egpg.read_encoders()
        print ( "Encoder Values: " + str(encoderStartLeft) + ' ' + str(encoderStartRight))
        egpg.set_speed(drive_speed)  # DPS  (degrees per second rotation of wheels)
        startclock = time.perf_counter()
        starttime  = time.time()
        if check_motor_status:
            egpg.drive_cm(minus_if_odd(i)*dist,blocking=False)
            time.sleep(0.25)  # initial delay to let motion start
            motors_running = True
            motor_status_count = 0
            # if ranging_active: ds.start_continuous(read_motor_status_delay)
            while motors_running:
                time.sleep(read_motor_status_delay)
                if ranging_active: ds_reading = ds.read_inches()
                # if ranging_active: ds_reading = ds.read_range_continuous()/25.4
                motors_state_l = egpg.get_motor_status(egpg.MOTOR_LEFT)
                motors_state_r = egpg.get_motor_status(egpg.MOTOR_RIGHT)
                motors_running = motors_state_l[3] | motors_state_r[3]
                motor_status_count += 2
        else:
            egpg.drive_cm(minus_if_odd(i)*dist)
        drive_processor_time = time.perf_counter() - startclock
        drive_wall_time = time.time() - starttime

        print("Drive Time:{:.1f}ms Wall Time:{:.1f}s".format(drive_processor_time*1000,drive_wall_time))
        if check_motor_status: print("get_motor_status() called {} times".format(motor_status_count))
        if ranging_active: print("last distance sensor reading:{:.1f} inches".format(ds_reading))

        time.sleep(1)		# to be sure totally stopped
        encoderEndLeft, encoderEndRight = egpg.read_encoders()
        deltaLeft = abs(encoderEndLeft - encoderStartLeft)
        deltaRight = abs(encoderEndRight - encoderStartRight)
        deltaAve = (deltaLeft + deltaRight)/2.0
        deltaLeftdist = enc_to_dist(deltaLeft) / 25.4
        deltaRightdist = enc_to_dist(deltaRight) / 25.4
        deltaAvedist = enc_to_dist(deltaAve) / 25.4
        print ("Encoder Value: " + str(encoderEndLeft) + ' ' + str(encoderEndRight))	# print the encoder raw
        print ("Delta Value: %d %d" % (deltaLeft, deltaRight))
        print ("Distance: L {:.2f} R {:.2f} Ave {:.2f}".format(deltaLeftdist, deltaRightdist,deltaAvedist))
        print ("Accuracy: L {:.1f}% R {:.1f}% Ave {:.1f}%".format(
                                       deltaLeftdist * 100 / dist,
                                       deltaRightdist * 100 / dist,
                                       deltaAvedist * 100 / dist ))
        drive_rate = (dist/100.0)/drive_wall_time   # cm/100 = m / time = m/s
        wheelrate = deltaAve/drive_wall_time
        print ("Drive Rate:{:.3f} m/s Wheel Rate:{:.1f} dps (includes start/stop effect)".format(drive_rate, wheelrate))
        print ("=============")
        if num_tries > 1:
            print(" ^^^^ Drive {} ^^^^".format(i+1))
            time.sleep(2)
      num_tries = 1
    except KeyboardInterrupt:
        egpg.stop()
runLog.logger.info("Exit")
time.sleep(0.5)
