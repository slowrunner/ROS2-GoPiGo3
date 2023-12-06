#!/usr/bin/env python3

# FILE: use4GB.py

# PURPOSE:  Allocate 4 GB memory to see OS memory allocation

import numpy as np
import time

print("use4GB.py: Sleeping 10s")
time.sleep(10)
print("use4GB.py: Starting 4GB memory allocation")
arr = np.ones((1024,1024,1024, 4), dtype=np.uint8)
print("use4GB.py: Finished allocation")
time.sleep(10)
print("use4GB.py:  Exiting")
