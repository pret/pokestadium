#!/usr/bin/env python3

import sys
import re
import os

# asset validator v0.1
# not used for anything but manual validation checks. Please dont use this for anything.

# Defines
# ------------------------

asset_dir = '../assets/us'

# Functions
# ------------------------

# Return the number of times the string "Yay0" appears in a given file.
def get_yay0_count(file):
    count = file.read().count(b'\x59\x61\x79\x30') # check for yay0
    return count

# Main program
# ------------------------

print("Yay0 instances per asset bin: ")
print("----------------------------------")

for filename in os.listdir(asset_dir):
    if ".bin" in filename and "bootcode_font.bin" not in filename and "7C0000.bin" not in filename:
        filepath = asset_dir + '/' + filename
        file = open(filepath, 'rb')
        yay0_count = get_yay0_count(file)
        file.close()
        print(filename, ":", yay0_count)
