#!/usr/bin/env python3

import sys
import re
import os
from pathlib import Path
import crunch64

# Asset unpacker v0.1 (WIP)

# Read a big endian 32-bit value from a bytearray file with a given offset.
def read_32_be_value(file_arr, i):
    return (file_arr[i + 0] << 24) + (file_arr[i + 1] << 16)  \
         + (file_arr[i + 2] << 8)  + (file_arr[i + 3])

# --------------------------
# Main program
# --------------------------

assets_path = "assets/us/"
    
extract_to = None
if len(sys.argv) == 3:
    extract_to = sys.argv[2]

filepath = Path(sys.argv[1])
filename = os.path.splitext(os.path.basename(filepath))[0]

file = open(filepath, 'rb')
file_header = bytearray(file.read(0x10))

#print("[DEBUG] File path:", filepath)
#print("[DEBUG] File name:", filename)

# Magic check for multi asset bin. If no match, treat as a single asset bin, and just copy it to the expected folder.
# For some reason, stadium_models.bin breaks this pattern and uses this for something. (HACK: Workaround by just not checking the 4th byte.)
# TODO: Properly handle this
if file_header[0] != 0x00 or file_header[1] != 0x00 or file_header[2] != 0x00 or file_header[4] != 0x00 or file_header[5] != 0x00 or file_header[6] != 0x00 or file_header[7] != 0x00:
    if extract_to == None:
        file_path_to_write = assets_path + filename + "/0/file.bin"
    else:
        file_path_to_write = extract_to
    os.makedirs(os.path.dirname(file_path_to_write), exist_ok=True)
    with open(file_path_to_write, 'wb') as f:
        fin = open(filepath, 'rb')
        f.write(fin.read())
    sys.exit(0)

# Otherwise, process as multi.
bin_size   = read_32_be_value(file_header, 8)
file_count = read_32_be_value(file_header, 12)

#print("[DEBUG] Size:", hex(bin_size))
#print("[DEBUG] File count:", file_count)

# Reallocate the file based on the bin size. First seek back to the start, then reallocate.
file.seek(0, os.SEEK_SET)
file_bytes = bytearray(file.read(bin_size))

file_num = 0
while file_num < file_count:
    #print("[DEBUG] Processing File #:", file_num)
    # Get bin offset and bin size for the # file being processed.
    bin_offset = read_32_be_value(file_bytes, 0x10 + (file_num * 0x10) + 0)
    bin_size   = read_32_be_value(file_bytes, 0x10 + (file_num * 0x10) + 4)
    #print("[DEBUG] File Offset:", hex(bin_offset))
    #print("[DEBUG] File Size:", hex(bin_size))
    # Seek to the file offset.
    file.seek(bin_offset, os.SEEK_SET)
    sub_file_bytes = bytearray(file.read(bin_size))
    file_path_to_write = assets_path + filename + "/" + str(file_num) + "/file.bin"
    #print("[DEBUG] Path to write:", file_path_to_write)
    os.makedirs(os.path.dirname(file_path_to_write), exist_ok=True)
    file_to_write = open(file_path_to_write, 'wb')
    file_to_write.write(sub_file_bytes)
    file_num = file_num + 1
