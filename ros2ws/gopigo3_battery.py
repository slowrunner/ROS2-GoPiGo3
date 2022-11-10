#!/usr/bin/env python3

# FILE:  gopigo3_battery.py
# PURPOSE:  Use GoPiGo3 API (not ROS 2) to print battery voltage

from easygopigo3 import EasyGoPiGo3
from time import sleep
from statistics import mean

DIODE_DROP = 0.7  # Voltage Drop from reverse polarity protection to make get_voltage() equal actual battery voltage

egpg = EasyGoPiGo3(use_mutex=True)
x = []

for i in [1,2,3]:
    sleep(.005)
    x += [egpg.volt()+DIODE_DROP]
out = mean(x)
print("GoPiGo3 Battery Voltage: {:.1f} volts".format(out))
