#!/usr/bin/env python3
#

# import the time library for the sleep function
import time
# import the GoPiGo3 drivers
from easygopigo3 import EasyGoPiGo3

# Create an instance of the GoPiGo3 class.
# egpg will be the GoPiGo3 object.
egpg = EasyGoPiGo3()
egpg.set_speed(150)
print("About to drive 1 meter...")
time.sleep(5)

print("Driving 1 meter")
egpg.drive_cm(100, True)


# time.sleep(5)
# print("Stop!")
# gpg.stop()


print("Done!")
