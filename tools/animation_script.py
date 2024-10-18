#!/usr/bin/env python3

import sys
from pathlib import Path
from struct import *
import data2c
import find_sym
import subprocess

GFXDIS_CMD = "./tools/gfxdis.f3dex2 -x -dc -f baseroms/us/baserom.z64 "
VTXDIS_CMD = "./tools/vtxdis -f baseroms/us/baserom.z64 "

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
    REPLACE_OFFSETS = {}

    def get_type(f, offset, cmd, args, out):
        curr_args = []
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
                        v = unpack_from(">b" if is_signed else ">B", f.read(1))[0]
                        out += f"{v}, "

                    case 2:
                        v = unpack_from(">h" if is_signed else ">H", f.read(2))[0]
                        out += f"{v}, "

                    case 4:
                        v = unpack_from(">f" if is_float else ">i" if is_signed else ">I", f.read(4))[0]
                        
                        if (cmd == 0x00 or cmd == 0x03) and arg["name"] == "unk_04":
                            TO_DECOMP.append(find_sym.find(f"0x{v:X}", "v")["rom"])

                            REPLACE_OFFSETS[offset + arg["offset"]] = v

                            out += f"D_{v:08X}" + ", "

                        elif "*" in arg["type"]:
                            if v != 0:
                                t = arg["type"].replace("*","")

                                if t not in OUT_DATA:
                                    OUT_DATA[t] = []

                                match t:
                                    case "Gfx":
                                        OUT_DATA[t].append(v)

                                    case "Vtx":
                                        if cmd != 0x17:
                                            print(hex(v))
                                            print(curr_args)
                                            exit()
                                            OUT_DATA[t].append([curr_args[0], v])

                                    case "unk_D_86002F34_018":
                                        OUT_DATA[t].append([curr_args[0], v])

                                    case _:
                                        OUT_DATA[t].append(v)

                                out += f"D_{v:08X}" + ", "
                                REPLACE_OFFSETS[offset + arg["offset"]] = v
                            else:
                                out += f"NULL" + ", "
                                REPLACE_OFFSETS[offset + arg["offset"]] = 0

                        elif make_hex:
                            if v == 0:
                                out += f"NULL" + ", "
                                REPLACE_OFFSETS[offset + arg["offset"]] = 0
                            if v in FUNCS:
                                out += f"{FUNCS[v]}" + ", "
                                OUT_FUNCS[cmd].add(FUNCS[v])
                                REPLACE_OFFSETS[offset + arg["offset"]] = v
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

                curr_args.append(v)
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
            start = offset

            out = f""
            while True:
                cmd = unpack_from(">B", f.read(1), 0)[0]

                #out += f"    0x{word:08X},\n"
                #print(f"depth {DEPTH} offset 0x{offset:X} cmd 0x{cmd:02X} size 0x{COMMANDS[cmd]['size']:X}")
                #print(f"command 0x{cmd:X} --", COMMANDS[cmd])

                #out += f"    ANIMATION_SCRIPT_CMD_{cmd:02X}"
                #out += "("
                #print(hex(offset), hex(cmd))
                _ = get_type(f, offset, cmd, COMMANDS[cmd]["args"][1:], out)
                #if out[-2:] == ", ":
                #    out = out[:-2]
                #out += "),\n"

                if cmd == 0x01 or cmd == 0x04:
                    break;

                offset += COMMANDS[cmd]["size"]
                f.seek(offset, 0)

                end = offset

            #out = out[:-1]
            f.seek(start, 0)
            end += 4

            out = f""
            while start < end:
                word = unpack_from(">I", f.read(4), 0)[0]

                if start in REPLACE_OFFSETS:
                    v = REPLACE_OFFSETS[start]
                    if v == 0:
                        out += f"    NULL,\n"
                    elif v in FUNCS:
                        out += f"    {FUNCS[v]},\n"
                    else:
                        out += f"    D_{v:08X},\n"
                else:
                    out += f"    0x{word:08X},\n"

                start += 4

            #print()
            out_struct = f"static u32 D_{out_info['ram']:X}[] = " + "{\n"
            TO_OUTPUT.append([out_struct, out + "};\n"])

    for cmd in OUT_FUNCS:
        funcs = sorted(list(OUT_FUNCS[cmd]))
        for func in funcs:
            match cmd:
                case 0x08:
                    print(f"s32 {func}(s32, unk_D_86002F34_000*);")

                case _:
                    print(f"Unhandled output function type cmd {cmd}")
                    exit()

    FINAL_OUT_DATA = []

    OUT_DATA = list(OUT_DATA.items())

    while len(OUT_DATA) > 0:
        type, entries = OUT_DATA.pop()

        match type:
            case "Gfx":
                while len(entries) > 0:
                    v = entries.pop()
                    a = find_sym.find(f"0x{v:X}", "v")["rom"]
                    out = subprocess.getoutput(GFXDIS_CMD + f"-a 0x{a:X}")
                    
                    for line in out.splitlines():
                        if "SPVertex(" in line:
                            addr_str = line.split("(",1)[1].split(",")[0]
                            count_str = line.split("(",1)[1].split(",")[1]

                            addr = int(addr_str, 0)
                            count = int(count_str, 10)


                            OUT_DATA.append(("Vtx", [[count, addr]]))
                            out = out.replace(addr_str, f"D_{addr:X}")
                    FINAL_OUT_DATA.append([v, "Gfx", out])

            case "Vtx":
                while len(entries) > 0:
                    c, v = entries.pop()
                    addr = find_sym.find(f"0x{v:X}", "v")["rom"]
                    out = subprocess.getoutput(VTXDIS_CMD + f"-o 0x{addr:X} -c {c}")
                    FINAL_OUT_DATA.append([v, "Vtx", out])

            case "unk_D_86002F34_018":
                while len(entries) > 0:
                    c, v = entries.pop()

                    dump_type = f"unk_D_86002F34_018[{c}]" if c > 0 else f"unk_D_86002F34_018"
                    
                    out = data2c.dump(find_sym.find(f"0x{v:X}", "v")["rom"], dump_type)

                    split = out.split(",")
                    for i,arg in enumerate(split):
                        arg = arg.strip()
                        is_valid = False
                        try:
                            addr = int(arg, 16)
                            if addr >= 0x80000000:
                                is_valid = True
                        except Exception:
                            pass;

                        if is_valid:
                            tex_type_str = split[i-4].strip()
                            tex_type = int(tex_type_str, 16)

                            match tex_type:
                                case 2:
                                    new_tex_type = "unk_D_86002F34_018_GFX_TYPE_2"
                                    size = (int(split[i-1].strip(), 10) * 2) // 4
                                case 3:
                                    new_tex_type = "unk_D_86002F34_018_GFX_TYPE_3"
                                    size = (int(split[i-1].strip(), 10) * 4) // 4
                                case _:
                                    print(f"Inknown tex type {tex_type}")
                                    exit()

                            tex = data2c.dump(find_sym.find(f"0x{addr:X}", "v")["rom"], f"u32[{size}]")
                            FINAL_OUT_DATA.append([addr, f"u32[{size}]", tex])
                            
                            pos = out.rfind(tex_type_str, 0, out.find(arg))

                            out = out[:pos] + new_tex_type + out[pos+4:]
                            out = out.replace(arg, f"D_{addr:08X}")

                    FINAL_OUT_DATA.append([v, dump_type, out])

            case _:
                while len(entries) > 0:
                    v = entries.pop()
                    dump_type = f"{type}"
                    sym = find_sym.find(f"0x{v:X}", "v")
                    if sym["rom"] > 0:
                        out = data2c.dump(find_sym.find(f"0x{v:X}", "v")["rom"], dump_type)
                    else:
                        out = ""
                    FINAL_OUT_DATA.append([v, type, out])

    FINAL_OUT_DATA.sort(key=lambda x: x[0])
    FINAL_DONE = set()
    for v, type, out in FINAL_OUT_DATA:
        if v in FINAL_DONE:
            continue
        FINAL_DONE.add(v)
        is_array = "[" in type or type == "Gfx" or type == "Vtx"

        if "[" in type:
            count = int(type.split("[",1)[1].split("]",1)[0], 0)
        else:
            count = 0

        type = type.split("[",1)[0]

        o = f"static {type} D_{v:08X}"
        if len(out) > 0:
            if is_array:
                if count > 0:
                    o += f"[{count}]"
                else:
                    o += f"[]"

            o += " = " + out + (";" if out[-1] != ";" else "")

        else:
            o += ";"

        print(o)

    print()
    [print(x[0] + x[1]) for x in sorted(TO_OUTPUT, key=lambda x: x[0])]

if __name__ == "__main__":
    dump(sys.argv[1])

