#!/usr/bin/env python3

import sys
import re
import os
from pathlib import Path
import crunch64

# PRESJPEG extractor
# Usage: decompress_presjpeg.py [path to PRESJPEG file]

# Read a big endian 32-bit value from a bytearray file with a given offset.
def read_32_be_value(file_arr, i):
    return (file_arr[i + 0] << 24) + (file_arr[i + 1] << 16)  \
         + (file_arr[i + 2] << 8)  + (file_arr[i + 3])

assets_path = "assets/us/"

filepath = Path(sys.argv[1])
filename = os.path.splitext(os.path.basename(filepath))[0]

file = open(filepath, 'rb')
file_header = bytearray(file.read(0xC)) # First, we need to fetch the header size. This is right after the magic part of the header.

# Check for 50 52 45 53 4A 50 45 47, which is "PRESJPEG"
if file_header[0] != 0x50 or file_header[1] != 0x52 or file_header[2] != 0x45 or file_header[3] != 0x53 or file_header[4] != 0x4A or file_header[5] != 0x50 or file_header[6] != 0x45 or file_header[7] != 0x47:
    print(filepath, "File magic is NOT 'PRESJPEG'. Please pass a valid file.")
    sys.exit(1)

header_size = read_32_be_value(file_header, 8)
file.seek(header_size, os.SEEK_SET)
jpeg_file = bytearray(file.read())
file.close()
file = open(filepath, 'wb')
file.write(jpeg_file)
filepath.rename(filepath.with_suffix('.jpeg'))
