#!/usr/bin/env python3

# FILE: use500MB.py

# PURPOSE:  Allocate 500MB  memory to see OS memory allocation

import numpy as np
import time

print("use500MB.py: Sleeping 10s")
time.sleep(10)
print("use500MB.py: Starting 500MB memory allocation")
arr = np.ones((512,1024,1024, 1), dtype=np.uint8)
print("use500MB.py: Finished allocation")
time.sleep(10)
print("use500MB.py:  Exiting")
