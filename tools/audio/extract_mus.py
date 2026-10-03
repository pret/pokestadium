#!/usr/bin/env python3
"""Extract Pokemon Stadium's Numus sequences: the 76 songs and every fx bank.

Each one is written twice -- the expanded image (`.bin`, what inject_mus.py
takes back) and a disassembly of every channel (`.txt`, from the command table
in src/libnumus/player.c) -- plus sequences.json with the offsets and sizes.

usage:  python3 tools/audio/extract_mus.py [baserom]
"""

import json
import sys
from pathlib import Path

from mus_seq import (ARCHIVE1, decompress, disassemble, fx_blobs, parse_fx,
                     parse_song, songs, stream_bounds)

OUT = Path("build/assets/audio/SEQ")


def write_song(path, img):
    song = parse_song(img)
    bounds = stream_bounds(song, len(img))
    lines = ["song: %d channels, %d bytes" % (song["channels"], len(img))]
    for i, start in enumerate(song["data"]):
        if not start:
            continue
        lines.append("")
        lines.append("channel %d @%#x" % (i, start))
        end = min(b for b in bounds if b > start)
        lines += ["  %#06x  %s" % ev for ev in disassemble(img, start, end)]
    path.write_text("\n".join(lines) + "\n")
    return song


def write_fx(path, img):
    fx = parse_fx(img)
    order = sorted(set(fx["sequences"]) | {len(img)})
    lines = ["fx bank: %d sequences, %d bytes" % (fx["count"], len(img))]
    for i, start in enumerate(fx["sequences"]):
        lines.append("")
        lines.append("effect %d @%#x" % (i, start))
        end = min(b for b in order if b > start)
        lines += ["  %#06x  %s" % ev for ev in disassemble(img, start, end)]
    path.write_text("\n".join(lines) + "\n")
    return fx


def main(baserom="baseroms/us/baserom.z64"):
    rom = Path(baserom).read_bytes()
    song_dir, fx_dir = OUT / "songs", OUT / "fx"
    song_dir.mkdir(parents=True, exist_ok=True)
    fx_dir.mkdir(parents=True, exist_ok=True)

    manifest = {"archive1": ARCHIVE1, "songs": [], "fx_banks": []}
    for i, (off, size) in enumerate(songs(rom)):
        img = decompress(rom, off)
        name = "%02d_%08X" % (i, off)
        (song_dir / (name + ".bin")).write_bytes(img)
        song = write_song(song_dir / (name + ".txt"), img)
        manifest["songs"].append(
            {"index": i, "offset": off, "packed": size, "expanded": len(img),
             "channels": song["channels"], "file": name})
        print("[%2d/%d] song %s  %#x -> %#x bytes, %d channels"
              % (i + 1, 76, name, size, len(img), song["channels"]))

    for i, blob in enumerate(fx_blobs(rom)):
        off, slot = blob["offset"], blob["slot"]
        img = decompress(rom, off)
        name = "%03d_%08X" % (i, off)
        (fx_dir / (name + ".bin")).write_bytes(img)
        fx = write_fx(fx_dir / (name + ".txt"), img)
        manifest["fx_banks"].append(
            {"index": i, "offset": off, "slot": slot, "expanded": len(img),
             "sequences": fx["count"], "file": name})

    (OUT / "sequences.json").write_text(json.dumps(manifest, indent=1))
    print("done: %d songs, %d fx banks (%d effects) -> %s"
          % (len(manifest["songs"]), len(manifest["fx_banks"]),
             sum(b["sequences"] for b in manifest["fx_banks"]), OUT))


if __name__ == "__main__":
    main(*sys.argv[1:])
