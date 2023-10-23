Testing SD Card Performance on the Command Line with Pi Agnostics

REF: https://www.henryleach.com/2022/12/testing-sd-card-performance-on-the-command-line-with-pi-agnostics/

=== original installation
1) sudo apt install fio
2) mkdir agnostics
3) git clone https://github.com/raspberrypi-ui/agnostics.git agnostics
4) cd agnostics/data
5) nano sdtest.sh
  change the line /usr/share/agnostics/sd_bench.fio to read just sd_bench.fio instead.
6) . sdtest.sh
7) cd ~/systests/sdcard 
8) create run_sdtest.sh
#!/bin/bash

pushd agnostics/data
. sdtest.sh
popd

9) ./run_sdtest.sh

NOTE:  Sequential write speed can vary by 7% from run to run,
       but Random r/w speeds will vary by less than 1%

RESULTS:

*** 32GB ROS2HH SD card (in micro SD extender)
Sequential write speed 21607 KB/sec (target 10000) - PASS
Random write speed 645 IOPS (target 500) - PASS
Random read speed 2497 IOPS (target 1500) - PASS


Not in micro SD extender:

Sequential write speed 21586 KB/sec (target 10000) - PASS
Random write speed 704 IOPS (target 500) - PASS
Random read speed 2494 IOPS (target 1500) - PASS

