#!/usr/bin/env python3

import sys
import re
import os
from pathlib import Path
import crunch64

# PERS-SZP decompressor v0.1 (WIP)
# Usage: decompress_persszp.py [path to PERS-SZP file]

# Read a big endian 32-bit value from a bytearray file with a given offset.
def read_32_be_value(file_arr, i):
    return (file_arr[i + 0] << 24) + (file_arr[i + 1] << 16)  \
         + (file_arr[i + 2] << 8)  + (file_arr[i + 3])

assets_path = "assets/us/"

filepath = Path(sys.argv[1])
filename = os.path.splitext(os.path.basename(filepath))[0]

file = open(filepath, 'rb')
file_header = bytearray(file.read(0xC)) # First, we need to fetch the header size. This is right after the magic part of the header.

# Check for 50 45 52 53 2D 53 5A 50, which is "PERS-SZP"
if file_header[0] != 0x50 or file_header[1] != 0x45 or file_header[2] != 0x52 or file_header[3] != 0x53 or file_header[4] != 0x2D or file_header[5] != 0x53 or file_header[6] != 0x5A or file_header[7] != 0x50:
    print(filepath, "File magic is NOT 'PERS-SZP'. Please pass a valid file.")
    sys.exit(1)

header_size = read_32_be_value(file_header, 8)
# Now that we have the header size, seek past the header.
file.seek(header_size, os.SEEK_SET)
yay0_file = file.read()

decompressed = crunch64.yay0.decompress(yay0_file)
file.close()
file = open(filepath, 'wb')
file.write(decompressed)
