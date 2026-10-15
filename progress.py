#!/usr/bin/env python3

# SPDX-FileCopyrightText: © 2023 ZeldaRET
# SPDX-License-Identifier: MIT

from __future__ import annotations

import argparse
import mapfile_parser
import yaml
from pathlib import Path


ASMPATH = Path("asm")
NONMATCHINGS = "nonmatchings"
YAMLPATH = Path("yamls")

SKIPPEDTYPES = ("hasm", "textbin")

def getSkippedPaths(yamlPath: Path) -> set[tuple[str, ...]]:
    skipped: set[tuple[str, ...]] = set()

    def walk(items) -> None:
        for segment in items:
            if isinstance(segment, dict):
                walk(segment.get("subsegments") or [])
                name = segment.get("name") if segment.get("type") in SKIPPEDTYPES else None
            elif isinstance(segment, list) and len(segment) >= 2 and segment[1] in SKIPPEDTYPES:
                # [start, type] with no name: splat names the file after the rom offset
                name = segment[2] if len(segment) >= 3 else f"{segment[0]:X}"
            else:
                continue

            if name is not None:
                parts = [part for part in Path(str(name)).parts if part != ".."]
                if parts and parts[0] in ("src", "asm"):
                    parts = parts[1:]
                skipped.add(tuple(parts))

    walk(yaml.safe_load(yamlPath.read_text(encoding="utf-8")) or [])
    return skipped


def isSkipped(filePath: Path, skipped: set[tuple[str, ...]]) -> bool:
    parts = filePath.parts
    return any(key and parts[-len(key):] == key for key in skipped)


def getProgressFromMapFile(mapFile: mapfile_parser.MapFile, asmPath: Path, nonmatchings: Path, aliases: dict[str, str]=dict(), pathIndex: int=2, skipped: set[tuple[str, ...]]=set()) -> tuple[mapfile_parser.ProgressStats, dict[str, mapfile_parser.ProgressStats]]:
    totalStats = mapfile_parser.ProgressStats()
    progressPerFolder: dict[str, mapfile_parser.ProgressStats] = dict()

    for segment in mapFile:
        for file in segment:
            if len(file) == 0:
                continue

            originalFilePath = Path(*file.filepath.parts[pathIndex:])

            extensionlessFilePath = originalFilePath
            while extensionlessFilePath.suffix:
                extensionlessFilePath = extensionlessFilePath.with_suffix("")

            if isSkipped(extensionlessFilePath, skipped):
                continue

            folder = file.filepath.parts[pathIndex]
            if folder == "fragments":
                folder = folder + "/" + file.filepath.parts[pathIndex + 1]

            if ".a" in folder:
                folder = folder.split('.a')[0]

            if folder in aliases:
                folder = aliases[folder]

            if folder not in progressPerFolder:
                progressPerFolder[folder] = mapfile_parser.ProgressStats()

            fullAsmFile = asmPath / extensionlessFilePath.with_suffix(".s")
            wholeFileIsUndecomped = fullAsmFile.exists()


            for func in file:
                funcAsmPath = nonmatchings / extensionlessFilePath / f"{func.name}.s"

                symSize = 0
                if func.size is not None:
                    symSize = func.size

                if wholeFileIsUndecomped:
                    totalStats.undecompedSize += symSize
                    progressPerFolder[folder].undecompedSize += symSize
                elif funcAsmPath.exists():
                    totalStats.undecompedSize += symSize
                    progressPerFolder[folder].undecompedSize += symSize
                else:
                    totalStats.decompedSize += symSize
                    progressPerFolder[folder].decompedSize += symSize

    return totalStats, progressPerFolder


def getProgress(mapPath: Path, version: str) -> tuple[mapfile_parser.ProgressStats, dict[str, mapfile_parser.ProgressStats]]:
    mapFile = mapfile_parser.MapFile()
    mapFile.readMapFile(mapPath)

    for segment in mapFile:
        for file in segment:
            if len(file) == 0:
                continue

            filepathParts = list(file.filepath.parts)
            if version in filepathParts:
                filepathParts.remove(version)
            file.filepath = Path(*filepathParts)

    nonMatchingsPath = ASMPATH / version / NONMATCHINGS
    skipped = getSkippedPaths(YAMLPATH / version / "rom.yaml")

    return getProgressFromMapFile(mapFile.filterBySectionType(".text"), ASMPATH / version, nonMatchingsPath, aliases={"ultralib": "libultra"}, skipped=skipped)

def progressMain():
    parser = argparse.ArgumentParser()
    parser.add_argument("-v", "--version", help="version to process", default="us")

    args = parser.parse_args()

    mapPath = Path("build") / f"pokestadium-{args.version}.map"

    totalStats, progressPerFolder = getProgress(mapPath, args.version)

    mapfile_parser.progress_stats.printStats(totalStats, progressPerFolder)

if __name__ == "__main__":
    progressMain()
