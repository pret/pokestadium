#!/usr/bin/env python3

import argparse
import json
import csv
import git
import os
import re

parser = argparse.ArgumentParser(description="Computes current progress throughout the whole project.")
parser.add_argument("format", nargs="?", default="text", choices=["text", "csv", "shield-json"])
parser.add_argument("-m", "--matching", dest='matching', action='store_true',
                    help="Output matching progress instead of decompilation progress")
args = parser.parse_args()

NON_MATCHING_PATTERN = r"#ifdef\s+NON_MATCHING.*?#pragma\s+GLOBAL_ASM\s*\(\s*\"(.*?)\"\s*\).*?#endif"

def GetNonMatchingFunctions(files):
    functions = []

    for file in files:
        with open(file) as f:
            functions += re.findall(NON_MATCHING_PATTERN, f.read(), re.DOTALL)

    return functions

def ReadAllLines(fileName):
    lineList = list()
    with open(fileName) as f:
        lineList = f.readlines()

    return lineList

def GetFiles(path, ext):
    files = []

    for r, d, f in os.walk(path):
        for file in f:
            if file.endswith(ext):
                files.append(os.path.join(r, file))

    return files

nonMatchingFunctions = GetNonMatchingFunctions(GetFiles("src", ".c")) if not args.matching else []

def GetNonMatchingSize(path):
    size = 0

    asmFiles = GetFiles(path, ".s")

    for asmFilePath in asmFiles:
        if asmFilePath not in nonMatchingFunctions:
            asmLines = ReadAllLines(asmFilePath)

            for asmLine in asmLines:
                if (asmLine.startswith("/*")):
                    size += 4

    return size

def IsCFile(objfile):
    srcfile = objfile.strip().replace("build/", "").replace(".c.o", ".c")
    return os.path.isfile(srcfile)

mapFile = ReadAllLines("build/pokestadium.map")
src = 0
asm = 0

for line in mapFile:
    lineSplit =  list(filter(None, line.split(" ")))

    if (len(lineSplit) == 4 and lineSplit[0].startswith(".")):
        section = lineSplit[0]
        size = int(lineSplit[2], 16)
        objFile = lineSplit[3]
        
        if (section == ".text"):
            if (IsCFile(objFile) and objFile.startswith("build/src")):
                src += size
            elif (objFile.startswith("build/asm")):
                asm += size

nonMatchingASM = GetNonMatchingSize("asm/non_matchings")

src -= nonMatchingASM

total = src + nonMatchingASM + asm
srcPct = 100 * src / total

bytesPerPokemon = total // 151

if args.format == 'csv':
    csv_version = 2
    git_object = git.Repo().head.object
    timestamp = str(git_object.committed_date)
    git_hash = git_object.hexsha
    csv_list = [str(csv_version), timestamp, git_hash, str(src), str(total), str(code), str(codeSize), str(boot), str(bootSize), str(ovl), str(ovlSize), str(nonMatchingASM), str(len(nonMatchingFunctions))]
    print(",".join(csv_list))
elif args.format == 'shield-json':
    # https://shields.io/endpoint
    print(json.dumps({
        "schemaVersion": 1,
        "label": "progress",
        "message": f"{srcPct:.3g}%",
        "color": 'yellow' if srcPct < 100 else 'brightgreen',
    }))
elif args.format == 'text':
    adjective = "decompiled" if not args.matching else "matched"

    print(str(total) + " total bytes of decompilable code")
    print(str(src) + " bytes " + adjective + " in src " + str(srcPct) + "%\n")
    print("------------------------------------\n")

    pokemonCount = int(src / bytesPerPokemon)

    print("You have " + str(pokemonCount) + "/151 Pokedex entries.\n")
else:
    print("Unknown format argument: " + args.format)
