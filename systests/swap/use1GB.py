#!/usr/bin/env python3

# FILE: use1GB.py

# PURPOSE:  Allocate 1 GB memory to see OS memory allocation

import numpy as np
import time

print("use1GB.py: Sleeping 10s")
time.sleep(10)
print("use1GB.py: Starting 1GB memory allocation")
arr = np.ones((1024,1024,1024, 1), dtype=np.uint8)
print("use1GB.py: Finished allocation")
time.sleep(10)
print("use1GB.py:  Exiting")
