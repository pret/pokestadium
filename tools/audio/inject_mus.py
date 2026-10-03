#!/usr/bin/env python3
"""Put Numus sequences back into the ROM: songs and fx banks.

Like inject_mort.py the replacement is an expanded image (what extract_mus.py 
writes as `.bin`), re-packed with the codec at asm/us/517A0.s and written back
where the game expects it.

Songs (archive 1) share one region, 0x16ADA80..0x16F27E0 (0x44D60 bytes, packed
tight in the original).  The file table at 0x15C002C says where each one starts,
so songs may be *redistributed* inside that region; the total may not grow,
because archive 2 begins at its end and the pak's size is fixed by
yamls/us/rom.yaml.  The game expands a song into a 0x98D8 buffer (src/4BDC0.c),
which caps the image size.

Fx banks sit in slots bounded by the next file of their package, so each one is
rewritten in place and must fit its own slot; the leftover is zeroed.

usage:  python3 tools/audio/inject_mus.py [-o OUT.z64] [-r BASEROM] [-a] SPEC...
  SPEC is song:N=FILE.bin or fx:N=FILE.bin, N being the index extract_mus.py
  prints.  With no SPEC this is a round trip, which must reproduce the ROM byte
  for byte.
"""

import argparse
import struct
import sys
from pathlib import Path

from inject_mort import PAK, PAK_SIZE
from mus_seq import (ARCHIVE1, ARCHIVE2, SONG_BUF, archive_files, compress,
                     decompress, fx_blobs, parse_fx, parse_song, songs)

SONG_REGION = (ARCHIVE1, ARCHIVE2)      # the file table is relative to ARCHIVE1


def rebuild_songs(rom, repl):
    """Re-lay archive 1's songs with repl{index: expanded image} applied, then
    rewrite the file table.  Returns (new rom, bytes used, region size)."""
    table = songs(rom)
    start = table[0][0]
    size = ARCHIVE2 - start
    blobs = [compress(repl[i]) if i in repl else rom[o:o + n]
             for i, (o, n) in enumerate(table)]
    packed = b"".join(blobs)
    assert len(packed) <= size, \
        "songs need %#x bytes, the region holds %#x -- see the module docstring" \
        % (len(packed), size)

    out = bytearray(rom)
    out[start:start + size] = packed.ljust(size, b"\0")
    offset = start - ARCHIVE1
    for i, blob in enumerate(blobs):
        struct.pack_into(">I", out, ARCHIVE1 + 0xC + 4 * i, offset)
        offset += len(blob)
    return bytes(out), len(packed), size


def rebuild_fx(rom, repl):
    """Rewrite fx banks in place; each must fit the slot it already has."""
    out = bytearray(rom)
    used = []
    for i, img in repl.items():
        where = fx_blobs(rom)[i]
        off, slot = where["offset"], where["slot"]
        packed = compress(img)
        assert len(packed) <= slot, \
            "fx bank %d needs %#x bytes, its slot holds %#x" % (i, len(packed), slot)
        out[off:off + slot] = packed.ljust(slot, b"\0")
        used.append((i, off, len(packed), slot))
    return bytes(out), used


def verify(rom, new_rom, song_repl, fx_repl):
    """Re-read everything through the game's own path: the table, the codec,
    and the structures the player parses."""
    table = songs(new_rom)
    assert len(table) == 76, len(table)
    for i, (off, size) in enumerate(table):
        img = decompress(new_rom, off)
        assert len(img) <= SONG_BUF, (i, len(img))
        if i in song_repl:
            assert img == song_repl[i], "song %d does not expand back" % i
        parse_song(img)
    for i, blob in enumerate(fx_blobs(new_rom)):
        img = decompress(new_rom, blob["offset"])
        if i in fx_repl:
            assert img == fx_repl[i], "fx bank %d does not expand back" % i
        parse_fx(img)
    # nothing outside the song region and the patched fx slots may move
    start = table[0][0]
    assert new_rom[:start] == rom[:start] or fx_repl
    assert new_rom[ARCHIVE2:] == rom[ARCHIVE2:] or fx_repl


def load(spec):
    """'song:N=FILE' / 'fx:N=FILE' -> (kind, index, image)."""
    where, _, path = spec.partition("=")
    kind, _, index = where.partition(":")
    assert kind in ("song", "fx"), "%s: expected song:N=FILE or fx:N=FILE" % spec
    img = Path(path).read_bytes()
    assert len(img) >= 0x10, "%s: too small to be a sequence image" % path
    if kind == "song":
        assert len(img) <= SONG_BUF, \
            "%s: %#x bytes does not fit the game's %#x song buffer" % (path, len(img), SONG_BUF)
    return kind, int(index), img


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("specs", nargs="*", metavar="song:N=FILE.bin")
    ap.add_argument("-r", "--rom", default="baseroms/us/baserom.z64")
    ap.add_argument("-o", "--out", default="build/mus_injected.z64")
    ap.add_argument("-a", "--asset", action="store_true",
                    help="also write assets/us/15C0000.bin, so make builds it in")
    args = ap.parse_args()

    song_repl, fx_repl = {}, {}
    for spec in args.specs:
        kind, index, img = load(spec)
        (song_repl if kind == "song" else fx_repl)[index] = img

    rom = Path(args.rom).read_bytes()
    new_rom, used, region = rebuild_songs(rom, song_repl)
    new_rom, fx_used = rebuild_fx(new_rom, fx_repl)
    verify(rom, new_rom, song_repl, fx_repl)

    if not args.specs:
        assert new_rom == rom, "round trip is not byte-identical"
        print("round trip: ROM byte-identical")
    else:
        print("replaced %d song(s) and %d fx bank(s)" % (len(song_repl), len(fx_repl)))
    for i, off, n, slot in fx_used:
        print("fx %d @%#x: %#x of its %#x-byte slot" % (i, off, n, slot))
    print("songs use %#x of their %#x-byte region" % (used, region))

    Path(args.out).parent.mkdir(parents=True, exist_ok=True)
    Path(args.out).write_bytes(new_rom)
    print("wrote %s" % args.out)
    if args.asset:
        Path("assets/us/15C0000.bin").write_bytes(new_rom[PAK:PAK + PAK_SIZE])
        print("wrote assets/us/15C0000.bin")


if __name__ == "__main__":
    sys.exit(main())
