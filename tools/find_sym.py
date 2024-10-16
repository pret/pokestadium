#!/usr/bin/env python3

# This unused import makes the yaml library faster. don't remove
import pylibyaml  # pyright: ignore
import yaml
import sys

def find(addr, opt=""):
    if type(addr) == str:
        if "D_" in addr:
            addr = "0x" + addr[2:]
        addr = int(addr, 0)

    is_vram = addr >= 0x10000000
    if opt == "v":
        is_vram = True
    elif opt == "p":
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
                        diff = addr - subseg["vram"]
                        #print(f"vram diff to {subseg['name']}  0x{diff}")
                else:
                    #print(f"Unknown subsegment {subseg}")
                    pass

                if diff >= 0 and diff < min_diff:
                    #print(f"Setting min seg to {segment['name']}")
                    min_seg = segment
                    min_subseg = i
                    min_diff = diff

    if min_seg:
        is_dict = type(min_seg['subsegments'][min_subseg]) == dict
        addr_idx = "vram" if is_dict else 0
        type_idx = "type" if is_dict else 1
        name_idx = "name" if is_dict else 2

        seg_type = min_seg['subsegments'][min_subseg][type_idx]

        if len(min_seg['subsegments'][min_subseg]) < 3:
            name = min_seg['subsegments'][min_subseg][type_idx]
            has_rom = not ("bss" in seg_type)
        else:
            name = min_seg['subsegments'][min_subseg][name_idx]
            has_rom = not ("reloc" in min_seg['subsegments'][min_subseg][name_idx] or "bss" in seg_type)

        rom = 0x0
        if has_rom:
            rom = min_seg['subsegments'][min_subseg][addr_idx] + min_diff

        rom_diff = (min_seg['subsegments'][min_subseg][addr_idx] + min_diff) - min_seg['start']
        ram = min_seg['vram'] + rom_diff

        return {"found":True, "rom":rom, "ram":ram, "min_diff":min_diff, "name": name}
    else:
        return {"found":False}

if __name__ == "__main__":
    opt = sys.argv[2] if len(sys.argv) > 2 else ""
    ret = find(sys.argv[1], opt)

    if ret["found"]:
        rom_str = "(No rom address)"
        if ret["rom"] != 0x0:
            rom_str = f"ROM: 0x{ret['rom']:X}"

        ram_str = f"RAM: 0x{ret['ram']:X}"

        print(f"({rom_str} {ram_str}) is 0x{ret['min_diff']:X} bytes inside {ret['name']} ")
    else:
        print(f"Could not find {sys.argv[1]}")
