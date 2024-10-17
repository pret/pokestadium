#!/usr/bin/env python3

import sys
from pathlib import Path
from struct import *
import data2c
import find_sym

COMMANDS = {}

NUM_COMMANDS = 38

for i in range(NUM_COMMANDS):
    struct_name = f"unk_D_800ABE00_cmd{i:X}"
    struct = data2c.STRUCTS[struct_name]

    COMMANDS[i] = {"name":struct_name, "size":struct["size"], "args":struct["data"]}

with open(Path(sys.argv[0]).absolute().parent / "../linker_scripts/us/symbol_addrs_code.txt", "r") as f:
    fd = f.read().splitlines()

FUNCS = {}
for line in fd:
    name, addr = line.split(";",1)[0].split(" = ")
    name = name.strip()
    addr = int(addr.strip(), 16)
    FUNCS[addr] = name

def dump(offset):
    OUT_FUNCS = {8:set()}
    OUT_DATA = {}
    DONE_DECOMP = set()
    TO_DECOMP = []

    def get_type(f, offset, cmd, args, out):
        for arg in args:
            if "pad" in arg["name"]:
                continue

            #print()
            #print(arg)
            f.seek(offset + arg["offset"], 0)

            if arg["type"] in data2c.STRUCTS:
                out = get_type(f, offset + arg["offset"], cmd, data2c.STRUCTS[arg["type"]]["data"], out)
            else:
                is_signed = arg["type"] in data2c.SIGNED
                is_float = arg["type"] in data2c.FLOAT
                make_hex = "*" in arg["type"] or arg["type"] == "ptr"

                type = "ptr" if "*" in arg["type"] else arg["type"]
                match data2c.BASE_TYPES[type]:
                    case 1:
                        v = unpack(">b" if is_signed else ">B", f.read(1))[0]
                        out += f"{v}, "

                    case 2:
                        v = unpack_from(">h" if is_signed else ">H", f.read(2))[0]
                        out += f"{v}, "

                    case 4:
                        v = unpack_from(">f" if is_float else ">i" if is_signed else ">I", f.read(4))[0]
                        
                        if (cmd == 0x00 or cmd == 0x03) and arg["name"] == "unk_04":
                            TO_DECOMP.append(find_sym.find(f"0x{v:X}", "v")["rom"])
                            out += f"D_{v:08X}" + ", "

                        elif "*" in arg["type"]:
                            if v != 0:
                                OUT_DATA[v] = arg["type"].replace("*","")
                                out += f"D_{v:08X}" + ", "
                            else:
                                out += f"NULL" + ", "

                        elif make_hex:
                            if v == 0:
                                out += f"NULL" + ", "
                            elif v in FUNCS:
                                out += f"{FUNCS[v]}" + ", "
                                OUT_FUNCS[cmd].add(FUNCS[v])
                            else:
                                out += f"0x{v:08X}" + ", "
                        else:
                            out += f"{v}" + ("f" if is_float else "") + ", "

                    case 8:
                        v = unpack_from(">d" if is_float else ">q" if is_signed else ">Q", f.read(8))[0]
                        out += f"{v}" + ", "

                    case _:
                        print(f"Unhandled size type for arg")
                        print(f"{arg}")
                        exit()
        return out

    offset = int(offset, 16)

    TO_DECOMP.append(offset)
    TO_OUTPUT = []

    with open(Path(sys.argv[0]).absolute().parent / "../baseroms/us/baserom.z64", "rb") as f:
        while len(TO_DECOMP) > 0:
            offset = TO_DECOMP.pop()
            if offset in DONE_DECOMP:
                continue
            DONE_DECOMP.add(offset)

            out_info = find_sym.find(offset)

            #print(f"Processing script at 0x{offset:X}")

            f.seek(offset, 0)

            out = f""
            while True:
                cmd = unpack_from(">B", f.read(1), 0)[0]
                #print(f"depth {DEPTH} offset 0x{offset:X} cmd 0x{cmd:02X} size 0x{COMMANDS[cmd]['size']:X}")
                #print(f"command 0x{cmd:X} --", COMMANDS[cmd])

                out += f"    ANIMATION_SCRIPT_CMD_{cmd:02X}"
                out += "("
                #print(hex(offset), hex(cmd))
                out = get_type(f, offset, cmd, COMMANDS[cmd]["args"][1:], out)
                if out[-2:] == ", ":
                    out = out[:-2]
                out += "),\n"

                if cmd == 0x01 or cmd == 0x04:
                    break;

                offset += COMMANDS[cmd]["size"]
                f.seek(offset, 0)

            out = out[:-1]

            #print()
            out_struct = f"static u32 D_{out_info['ram']:X}[] = " + "{\n"
            TO_OUTPUT.append([out_struct, out + "\n};\n"])

    for cmd in OUT_FUNCS:
        funcs = sorted(list(OUT_FUNCS[cmd]))
        for func in funcs:
            match cmd:
                case 0x08:
                    print(f"s32 {func}(s32, unk_D_86002F34_000*);")

                case _:
                    print(f"Unhandled output function type cmd {cmd}")
                    exit()

    if len(OUT_FUNCS) > 0:
        print()

    for v, type in sorted(list(OUT_DATA.items()), key=lambda x:x[0]):
        match type:
            case "Gfx":
                print(f"Gfx D_{v:08X}[];")

            case "Vtx":
                print(f"Vtx D_{v:08X}[];")

            case _:
                print(f"{type}* D_{v:08X};")

    print()
    [print(x[0] + x[1]) for x in sorted(TO_OUTPUT, key=lambda x: x[0])]

if __name__ == "__main__":
    dump(sys.argv[1])

