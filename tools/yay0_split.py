#!/usr/bin/env python3

import sys
import os

# Yay0_split_script

# this was used to scan/generate splits for certain small portions of asset tables. Please do not use this.

bin_file = open("scan.bin", 'r+b')
size = os.path.getsize("scan.bin")
ba = bytearray(bin_file.read(size))

i = 0
for i in range(i, size, 4):
    if ba[i + 0] == 0x59 and ba[i + 1] == 0x61 and ba[i + 2] == 0x79 and ba[i + 3] == 0x30:
        print("Yay0 found at: -[", hex(0x7C0000 + (i)), "]")
