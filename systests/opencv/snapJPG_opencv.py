#!/usr/bin/env python3

import cv2 
from datetime import datetime

# open camera

cap = cv2.VideoCapture('/dev/video0', cv2.CAP_V4L)

# set dimensions
# 16:9 - 1296x730, 1920x1080
# 4:3 - 640x480, 1296x972, 2592x1944
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 2592)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 1944)

# filename format
fname = "capture_"+datetime.now().strftime("%Y%m%d-%H%M%S")+".jpg"

# capture a frame
ret, frame = cap.read()

print("ret:",ret)
if ret:
    print("h,w: ", frame.shape[:2])

    # wirte frame to file
    cv2.imwrite(fname, frame)
else:
    print("Frame not captured")

# release camera
cap.release()
