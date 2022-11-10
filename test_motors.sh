#!/bin/bash


echo -e "\n*** TEST GOPIGO3 MOTORS"
echo "GOPIGO3 should:"
echo "- Spin right about 90 degrees"
echo "- Pause for a few seconds"
echo "- Spin left about 180 degrees"
echo "- Spin right, back approximately to starting heading"
python3 /home/pi/Dexter/GoPiGo3/Software/Python/Examples/Motor_Turn.py
echo -e "\n*** NOT A PROBLEM IF DID NOT TURN TO EXACT 90 and -90 HEADINGS"
