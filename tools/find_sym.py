#!/usr/bin/env python3

# This unused import makes the yaml library faster. don't remove
import pylibyaml  # pyright: ignore
import yaml
import sys

addr = sys.argv[1]
if "D_" in sys.argv[1]:
    addr = "0x" + sys.argv[1][2:]
addr = int(addr, 0)
is_vram = addr >= 0x10000000
if len(sys.argv) > 2 and sys.argv[2] == "v":
    is_vram = True
elif len(sys.argv) > 2 and sys.argv[2] == "p":
    is_vram = False

with open("yamls/us/rom.yaml", "r") as f:
    splat = yaml.load(f.read(), Loader=yaml.SafeLoader)

min_seg = None
min_subseg = 99999
min_diff = 0xFFFFFFFF

for segment in splat:
    if type(segment) == dict and "subsegments" in segment:
        for i,subseg in enumerate(segment["subsegments"]):
            if type(subseg) == list:
                if is_vram:
                    rom_to_vram = (subseg[0] - segment["start"]) + segment["vram"]
                    diff = addr - rom_to_vram
                else:
                    diff = addr - subseg[0]
            elif "bss" in subseg["type"]:
                if is_vram:
                    diff = addr - segment["vram"]
            else:
                #print(f"Unknown subsegment {subseg}")
                pass

            if diff >= 0 and diff < min_diff:
                min_seg = segment
                min_subseg = i
                min_diff = diff

if min_seg:
    seg_type = min_seg['subsegments'][min_subseg][1]

    if len(min_seg['subsegments'][min_subseg]) < 3:
        name = min_seg['subsegments'][min_subseg][1]
        has_rom = not ("bss" in seg_type)
    else:
        name = min_seg['subsegments'][min_subseg][2]
        has_rom = not ("reloc" in min_seg['subsegments'][min_subseg][2] or "bss" in seg_type)

    rom_str = "(No rom address)"
    if has_rom:
        rom_str = f"ROM: 0x{min_seg['subsegments'][min_subseg][0] + min_diff:X}"

    rom_diff = (min_seg['subsegments'][min_subseg][0] + min_diff) - min_seg['start']
    ram_str = f"RAM: 0x{min_seg['vram'] + rom_diff:X}"

    print(f"({rom_str} {ram_str}) is 0x{min_diff:X} bytes inside {name} ")
else:
    print(f"Could not find 0x{addr:08X}")
