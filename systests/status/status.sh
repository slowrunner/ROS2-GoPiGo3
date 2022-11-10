#!/bin/bash


while true; do echo -n `date +"%A %D"`; echo ""; uptime; vcgencmd measure_temp && vcgencmd measure_clock arm && vcgencmd get_throttled; sleep 10; echo " "; done
