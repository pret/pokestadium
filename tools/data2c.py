#!/usr/bin/env python3

import sys
from pathlib import Path
from struct import *

STRUCTS = {}
STRUCT_TYPEDEFS = {}
DEFINES = {}
BASE_TYPES = {
    "s8": 1,
    "u8": 1,
    "s16": 2,
    "u16": 2,
    "s32": 4,
    "u32": 4,

    "s64": 8,
    "u64": 8,

    "f32": 4,
    "f64": 8,

    "char": 1,
    "short": 2,
    "short int": 2,
    "int": 4,
    "long": 4,
    "long int": 8,
    "long long": 8,
    "long long int": 8,

    "float": 4,
    "double": 8,

    "ptr": 4,
    "size_t": 4,
    "uintptr_t": 4,
}

SIGNED = {
    "s8",
    "s16",
    "s32",
    "s64",

    "short",
    "int",
}

FLOAT = {
    "f32", "f64", "float", "double",
}

def calc_struct_sizes():
    def round_up(offset, rounding):
        return offset + (-offset % rounding)

    def calc_size(name, data):
        max_size = 0
        max_rounding = 0

        testMe = False
        #if name == "unk_D_86002F58_004_000_010_02C":
        #   testMe = True

        #print(data)

        i = 0
        offset = 0
        while i < len(data):
            member = data[i]
            if testMe:
                print(member)
            size = 0
            if member["type"] in STRUCTS:
                if "size" in STRUCTS[member["type"]]:
                    rounding = STRUCTS[member["type"]]["round"]
                    #size = round_up(size, rounding)
                    size += STRUCTS[member["type"]]["size"]
                else:
                    calc_size(member["type"], STRUCTS[member["type"]]["data"])
                    rounding = STRUCTS[member["type"]]["round"]
                    #size = round_up(size, rounding)
                    size += STRUCTS[member["type"]]["size"]
            elif "*" in member["type"]:
                rounding = 4
                #size = round_up(size, rounding)
                size += 4
            elif member["type"] in BASE_TYPES:
                rounding = BASE_TYPES[member["type"]]
                #size = round_up(size, rounding)
                size += BASE_TYPES[member["type"]]
            elif member["type"] in DEFINES:
                print(f"DEFINE!")
                print(member["type"])

                exit()
            else:
                print()
                print()
                print(f"What type? {member['type']}")
                exit()

            max_rounding = max(max_rounding, rounding)
            num_entries = 1
            for entry in member["counts"]:
                num_entries *= entry
            size *= num_entries

            offset = round_up(offset, rounding)

            if testMe:
                print(f"size 0x{size:X} rounding 0x{rounding:X} offset 0x{offset:X}")

            STRUCTS[name]["data"][i]["size"] = size
            STRUCTS[name]["data"][i]["round"] = rounding
            STRUCTS[name]["data"][i]["offset"] = offset

            offset += size

            if STRUCTS[name]["union"]:
                max_size = max(max_size, size)
            else:
                max_size = offset

            i += 1

        STRUCTS[name]["size"] = max_size
        STRUCTS[name]["round"] = max_rounding

    for struct_name, struct_data in STRUCTS.items():
        #print(f"--------------")
        #print(struct_name)
        #print(struct_data)
        #print()
        calc_size(struct_name, struct_data["data"])
        #print(f"####")
        #print(f"Type {struct_name} has size 0x{STRUCTS[struct_name]['size']:X} and rounding {STRUCTS[struct_name]['round']:X}")
        #print(STRUCTS[struct_name]["data"])

def parse_struct(filename, fd, i):
    testMe = False
    start_line = i

    indent = 0
    while fd[start_line][indent] == " ":
        indent += 1

    while len(fd[i]) <= indent or fd[i][indent] != "}":
        i += 1

    end_line = i
    if "sndp" in str(filename):
        testMe = True

    #if testMe:
    #    print(start_line, end_line, indent, fd[start_line:end_line])
    #    exit()

    pre_struct_name = fd[start_line]
    pre_struct_name = pre_struct_name.replace("struct","")
    pre_struct_name = pre_struct_name.replace("union","")
    pre_struct_name = pre_struct_name.replace("typedef","")
    pre_struct_name = pre_struct_name.replace("{","")
    pre_struct_name = pre_struct_name.strip()

    #print()
    #print()
    #print(start_line, end_line, indent)
    #print(fd[start_line:end_line])

    while "typedef" in fd[start_line] or fd[start_line][indent] == "{" or fd[start_line][indent:indent+6] == "struct" or fd[start_line][indent:indent+5] == "union":
        start_line += 1

    struct_name = fd[end_line].strip().rsplit(";",1)[0].split("}",1)[1].strip()

    #if "LEOCmd" in struct_name:
    #    testMe = True

    #if testMe:
    #    print()
    #    print(struct_name)
    #    print(start_line, end_line, indent)
    #    print(fd[start_line:end_line])
    #    #exit()

    if struct_name and struct_name in STRUCTS:
        return i, True, "", []

    if pre_struct_name and pre_struct_name != struct_name:
        STRUCT_TYPEDEFS[pre_struct_name] = struct_name

    #print(struct_name)
    #print(f"cccc")
    #print(fd[start_line:end_line])

    skipMe = False
    struct_data = []
    j = start_line
    startedComment = False
    while j < end_line:
        #print(f"xxxxx", j, end_line)
        data_member = fd[j]
        j += 1

        if not data_member.strip():
            continue

        #if testMe:
        #    print(f"bbbb {j}")
        #    print(data_member)

        if " : " in data_member:
            skipMe = True
            break;

        elif "#ifdef" in data_member or "#else" in data_member or "#endif" in data_member:
            continue

        elif (data_member.strip().startswith("union") or data_member.strip().startswith("struct")) and ";" not in data_member:
            is_union = "union" in data_member
            start = j

            while "{" not in data_member:
                data_member += fd[j]
                j += 1

            #while "{" not in fd[j]:
            #    j += 1

            #if testMe:
            #print(f"RECURSE {str(filename)} j {j} -- {fd[start-1]}")
            j, skipMe, name, data = parse_struct("", fd, start - 1)
            j += 1

            if skipMe:
                continue

            # invent a name for this anonymous struct
            if not name:
                name = f"{struct_name}_{j}"

            STRUCTS[name] = {}
            STRUCTS[name]["data"] = data
            STRUCTS[name]["union"] = is_union

            #if testMe:
            #print(f"DONE RECURSE {str(filename)} j {j}")
            #print(STRUCTS[name])
            #exit()
            struct_data.append({"name":name, "type":name, "counts":[], "size":0, "round":0, "offset":0})
            continue;

        elif ";" not in data_member and "/" in data_member:
            continue

        elif ";" not in data_member and startedComment:
            while ";" not in fd[j]:
                #print(f"yyyyy", j, end_line)
                j += 1
            startedComment = False
            continue

        if ";" in data_member and "/" in data_member:
            startedComment = True

        data_members = []
        if ";" not in data_member:
            data_members = [data_member]
            while ";" not in fd[j]:
                #print(f"zzzzzz", j, end_line)
                data_members.append(fd[j])
                j += 1
            data_members.append(fd[j])
            j += 1

            data_member = "".join(data_members)

        #if testMe:
        #    print()
        #    print()
        #    print(data_members)

        #print(data_members)
        data_member = data_member.rsplit(";",1)[0]

        #print(data_member)
        
        if "*/" in data_member:
            data_member = data_member.split("*/",1)[1]

        type, name = data_member.rsplit(" ",1)

        type = type.strip()
        if "," in type:
            names = type.split(" ",1)[1].split(",")
            type = type.split(" ",1)[0]

            x = 0
            while x < len(names):
                names[x] = names[x].strip()
                x += 1
        else:
            names = []
        names.append(name)

        for name in names:
            if not name:
                continue
            name = name.strip()

            if "*" in name:
                ptrs = name.count("*")
                name = name.rsplit("*",1)[1]
                type += "*" * ptrs

            if "struct " in type:
                type = type.rsplit(" ",1)[1]

            type = type.replace("unsigned", "")
            type = type.replace("signed", "")

            counts = []
            while "[" in name:
                count = name.split("[",1)[1].split("]",1)[0]
                name = name.split("[",1)[0] + name.split("]",1)[1]

                try:
                    count = int(count, 0)
                except Exception:
                    skipMe = True
                    break;

                counts.append(count)

            if skipMe:
                break;

            type = type.strip()
            name = name.strip()

            #print(f"name:\"{name}\", type:\"{type}\"")

            struct_data.append({"name":name, "type":type, "counts":counts, "size":0, "round":0, "offset":0})

    #if testMe:
    #    exit()

    return i, skipMe, struct_name, struct_data

def parse_structs():
    file_list = []

    inc_path = Path(sys.argv[0]).absolute().parent / "../include/"
    src_path = Path(sys.argv[0]).absolute().parent / "../src/"
    lib_path = Path(sys.argv[0]).absolute().parent / "../lib/ultralib/include/"

    file_list += inc_path.glob("**/*.c")
    file_list += inc_path.glob("**/*.h")
    file_list += lib_path.glob("**/*.c")
    file_list += lib_path.glob("**/*.h")
    file_list += src_path.glob("**/*.c")
    file_list += src_path.glob("**/*.h")

    #print("\n".join(str(x) for x in file_list))

    for file_name in file_list:
        fd = file_name.read_text()

        fd = fd.replace("\t", " ")
        fd = fd.splitlines()

        i = 0
        while i < len(fd):
            if not fd[i].startswith("typedef") and not fd[i].startswith("#define"):
                i += 1
                continue

            if fd[i].startswith("#define"):
                if "\\" in fd[i]:
                    i += 1
                    continue

                line = fd[i].split()
                if len(line) >= 3:
                    try:
                        val = int(line[2], 0)
                    except Exception:
                        i += 1
                        continue

                    name = line[1]
                    DEFINES[name] = val

                i += 1

            elif fd[i].startswith("typedef struct") and ";" not in fd[i]:
                # struct
                i, skipMe, name, data = parse_struct(file_name, fd, i)

                if not skipMe:
                    STRUCTS[name] = {}
                    STRUCTS[name]["data"] = data
                    STRUCTS[name]["union"] = False

            elif fd[i].startswith("typedef union"):
                i, skipMe, name, data = parse_struct(file_name, fd, i)

                if not skipMe:
                    STRUCTS[name] = {}
                    STRUCTS[name]["data"] = data
                    STRUCTS[name]["union"] = True

            elif "(*" in fd[i]:
                # func ptr
                #print(fd[i])
                func_ptr = fd[i].split("typedef ",1)[1].rsplit(";",1)[0]
                func_ptr = func_ptr.split("(*",1)[1].split(")",1)[0]
                STRUCTS[func_ptr] = {}
                STRUCTS[func_ptr]["data"] = [{"name":func_ptr, "type":"ptr", "counts":[], "size":4, "round":4, "offset":0}]
                STRUCTS[func_ptr]["size"] = 4;
                STRUCTS[func_ptr]["round"] = 4;
                STRUCTS[func_ptr]["union"] = False
                i += 1

            elif "typedef" in fd[i] and ";" in fd[i]:
                if "va_list" in fd[i]:
                    i += 1
                    continue

                #print(fd[i])
                line = fd[i].replace("typedef ", "")
                line = line.replace("unsigned ", "")
                line = line.replace("signed ", "")
                line = line.replace("struct ", "")
                line = line.replace("union ", "")
                line = line.replace(";", "")

                #if "Bitmap" in line:
                #    print(line)
                #    exit()

                if len(line.split(" ",1)) == 1:
                    i += 1
                    continue

                type, name = line.split(" ",1)
                type = type.strip()
                name = name.strip()

                if "Bitmap" in name or "Sprite" in name:
                    STRUCT_TYPEDEFS[name] = type
                    i += 1
                    continue

                skipMe = False
                counts = []
                while "[" in name:
                    count = name.split("[",1)[1].split("]",1)[0]

                    if count in DEFINES:
                        count = DEFINES[count]
                    else:
                        try:
                            count = int(count, 0)
                        except Exception:
                            #print(f"Skipping {name}")
                            skipMe = True
                            break;
                    name = name.split("[",1)[0] + name.split("]",1)[1]
                    counts.append(count)

                if skipMe:
                    i += 1
                    continue

                if "*" in name:
                    ptr_count = name.count("*")
                    type += "*" * ptr_count
                    name = name.replace("*", "")

                name = name.strip()
                type = type.strip()

                #print(counts)
                #print(name, type)

                if type in BASE_TYPES and len(counts) == 0:
                    BASE_TYPES[name] = BASE_TYPES[type]
                    i += 1
                    continue

                if name not in STRUCTS:
                    STRUCTS[name] = {}
                    STRUCTS[name]["data"] = [{"name":name, "type":type, "counts":counts, "size":0, "round":0, "offset":0}]
                    STRUCTS[name]["union"] = False

                i += 1

            else:
                #print(fd[i])
                i += 1

        #exit()

    # For every struct, fix change pre-declared name to actual name:
    # e.g typedef struct mystruct_s {} mystruct_t;
    # mystruct_s -> mystruct_t
    for struct_name, struct_data in STRUCTS.items():
        #print(struct_name, struct_data["data"])
        for member in struct_data["data"]:
                ptr_count = 0
                #print(member)
                pointerless_type = member["type"]
                if "*" in pointerless_type:
                    ptr_count = pointerless_type.count("*")
                    pointerless_type = pointerless_type.split("*",1)[0]

                if pointerless_type in STRUCT_TYPEDEFS:
                    new_name = STRUCT_TYPEDEFS[pointerless_type] + ("*" * ptr_count)
                    member["type"] = new_name


def dump_data(offset, struct, counts):

    def output_struct(data, name, out, offset, indent):
        def round_up(offset, rounding):
            return offset + (-offset % rounding)

        out += indent + "{ "

        for member in STRUCTS[name]["data"]:
            if member["type"] in STRUCTS:
                out = output_struct(data, member["type"], out, offset + member["offset"], indent)
            else:
                #print(member)

                is_signed = member["type"] in SIGNED
                is_float = member["type"] in FLOAT
                read_offset = offset + member["offset"]
                make_hex = "*" in member["type"]

                match member["size"]:
                    case 1:
                        v = unpack_from(">b" if is_signed else ">B", data, read_offset)[0]
                        out += f"{v}, "

                    case 2:
                        v = unpack_from(">h" if is_signed else ">H", data, read_offset)[0]
                        out += f"{v}, "

                    case 4:
                        v = unpack_from(">f" if is_float else ">i" if is_signed else ">I", data, read_offset)[0]
                        if make_hex:
                            if v == 0:
                                out += f"NULL" + ", "
                            else:
                                out += f"0x{v:08X}" + ", "
                        else:
                            out += f"{v}" + ("f" if is_float else "") + ", "

                    case 8:
                        v = unpack_from(">d" if is_float else ">q" if is_signed else ">Q", data, read_offset)[0]
                        out += f"{v}" + ", "

        if len(STRUCTS[name]["data"]) <= 4:
            out = out[:-2]
        out += indent + "}, "
        return out

    def output_array(data, name, counts, depth, out, offset):
        indent = (depth + 1) * "    "
        if depth < len(counts):
            for i in range(counts[depth]):
                #print(f"depth {depth} number {i} offset 0x{offset:X}")

                if len(counts) > depth + 1:
                    out += indent + "\n{"

                    #print(f"recurse start depth {depth+1} offset 0x{offset:X}")
                    out, offset = output_array(data, name, counts, depth+1, out, offset)
                    #print(f"recurse end   depth {depth} offset 0x{offset:X}")

                    out += indent + "\n},"
                else:
                    out = output_struct(data, name, out, offset, (depth + 1) * "    ")
                    offset += STRUCTS[name]["size"]

        else:
            out = output_struct(data, name, out, offset, "")

        return out, offset

    total_size = STRUCTS[struct]["size"]
    total_count = 1
    for count in counts:
        total_count *= count
    total_size = STRUCTS[struct]["size"] * total_count

    #print(f"size 0x{STRUCTS[struct]['size']:X} x {total_count} = 0x{total_size:X}")

    with open(Path(sys.argv[0]).absolute().parent / "../baseroms/us/baserom.z64", "rb") as f:
        f.seek(offset, 0)

        data = f.read(total_size)

    out = "{" if len(counts) > 0 else ""
    out, _ = output_array(data, struct, counts, 0, out, 0)
    out =  out + "};" if len(counts) > 0 else (out[:-2] + ";")

    print(out)



#######################################################################

parse_structs()
calc_struct_sizes()

#print(f"{len(STRUCTS)} structs parsed in")

offset = int(sys.argv[1], 16)
struct = sys.argv[2]

counts = []
while "[" in struct:
    count = struct.split("[",1)[1].split("]",1)[0]
    struct = struct.split("[",1)[0] + struct.split("]",1)[1]
    count = int(count, 0)
    counts.append(count)

if struct not in STRUCTS:
    print(f"Could not find struct definition \"{struct}\", maybe it failed to parse...")
    exit()

dump_data(offset, struct, counts)
