#!/usr/bin/env python3

import mapfile_parser
from pathlib import Path

mapPath = Path("build") / f"pokestadium-us.map"
mapFile = mapfile_parser.MapFile()
mapFile.readMapFile(mapPath)

str_syms = []

for segment in mapFile:
	for file in segment:
		if file.sectionType != ".text":
			continue

		for symbol in file:
			str_syms.append(f"{symbol.name} = 0x{symbol.vram:X}; // type:func")

with open("tools/symbol_addrs_code.txt", "w") as f:
	f.write("\n".join(str_syms))
