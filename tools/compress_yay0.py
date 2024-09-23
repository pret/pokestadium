#!/usr/bin/env python3

import sys
import re
import os
from pathlib import Path
import crunch64

# This will only compress an asset that has a single Yay0!
# usage: compress_yay0.py [in file] [out file]

filepath = Path(sys.argv[1])
filebytes = filepath.read_bytes()

compressed = crunch64.yay0.compress(filebytes)

fileout = Path(sys.argv[2])
fileout.write_bytes(compressed)

print("Yay0 compressed")
