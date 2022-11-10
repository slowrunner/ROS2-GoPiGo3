#!/usr/bin/env python3

#
# FILE: stop.py
#
# PURPOSE:  stop runaway bot

# import the GoPiGo3 drivers
import easygopigo3 as easy

# Create an instance of the GoPiGo3 class.
# GPG will be the GoPiGo3 object.
egpg = easy.EasyGoPiGo3()
egpg.stop()
print("stop.py: EasyGoPiGo3 commanded with stop()")
