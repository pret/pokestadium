#!/usr/bin/env python3

import sys
import re
from pathlib import Path

def get_include_syms(path):
    include_syms = {}
    for file in path.iterdir():
        if Path.is_dir(file):
            include_syms |= get_include_syms(file)
            continue

        if file.suffix != ".h":
            continue

        with open(file, "r") as f:
            fd = f.read()

        funcs = re.findall("(^(// )?[a-zA-Z0-9*_]+ .*\(.*\));$", fd, re.MULTILINE)

        for func in funcs:
            func = func[0]
            if "//" in func:
                func = func.split("// ",1)[1]
            if "typedef" in func:
                continue
            if func.startswith("extern"):
                func = func.split("extern ")[1]

            func = func.split("(", 1)[0].split(" ",1)[1]
            func = func.strip()

            if func.startswith("*"):
                func = func[1:]

            include_syms[func] = str(file)
    return include_syms

sym_addrs = {}
with open("linker_scripts/us/symbol_addrs_code.txt", "r") as f:
    fd = f.read().splitlines()
    for line in fd:
        if " = 0x" in line:
            name, addr = line.split(" = ",1)
            addr = addr.split(";",1)[0]
            sym_addrs[int(addr, 0)] = name

include_syms = get_include_syms(Path("include/"))
include_syms |= get_include_syms(Path("src/"))

file_list = []
path = Path(sys.argv[1])
if path.is_dir():
    for file in path.glob("*.s"):
        file_list.append(file)
else:
    file_list.append(sys.argv[1])

pattern = "jal +([^ ].*)$"
needed = set()
not_found = set()

for file in file_list:
    with open(file, "r") as f:
        fd = f.read()

    syms_used = re.findall(pattern, fd, re.MULTILINE)

    for sym in syms_used:
        if sym in include_syms:
            needed.add(f"#include \"{include_syms[sym]}\"")
        else:
            not_found.add(sym)


for need in sorted(list(needed)):
    print(need)

if len(not_found) > 0:
    print()
    print(f"Header not found, needs to be created for funcs:")
    for need in sorted(list(not_found)):
        print(f"\t{need}")
