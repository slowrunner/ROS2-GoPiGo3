#!/usr/bin/env python3

# FILE: use2GB.py

# PURPOSE:  Allocate 2 GB memory to see OS memory allocation

import numpy as np
import time

print("use2GB.py: Sleeping 10s")
time.sleep(10)
print("use2GB.py: Starting 2GB memory allocation")
arr = np.ones((1024,1024,1024, 2), dtype=np.uint8)
print("use2GB.py: Finished allocation")
time.sleep(10)
print("use2GB.py:  Exiting")
