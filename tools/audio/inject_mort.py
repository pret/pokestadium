#!/usr/bin/env python3
"""
Rebuild archive 4 (the announcer's MORT clips) and patch it back into the
audio pak / ROM.

The game reaches a clip only through the two-level alSeqFile index, so 
injecting audio means rewriting that index plus the blobs. No encoder is 
involved, so supply MORT blobs dumped by `tools/audio/extract_mort.py --blobs`,
blobs from another region, or ones built with mort_audio.MortWriter.

Layout:
  pak        0x15C0000 +0xA2C050   == assets/us/15C0000.bin, mapped verbatim by
                                     yamls/us/rom.yaml, so its size is fixed
  archive 4  0x197C1E0 +0x63E080   originally tight
  archive 5  0x1FBA260 +0xFC0
  archive 6  0x1FBB220 +0x30E30
Archives 5/6 are reached through the master table (src/373A0.c), so archive 4
may be redistributed inside its slot but not grown; padding it back to 0x63E080
keeps the rest of the pak (and the master table) put.  The clip count must
stay 823: the game indexes the announcer clips by position.

usage:  python3 tools/audio/inject_mort.py [-o OUT.z64] [-r BASEROM] [-a] SPEC...
  SPEC is N=FILE (replace clip N with that MORT blob) or N=silence (replace it
  with an equally long silent clip).  With no SPEC this is a round trip, which
  must reproduce the ROM byte for byte.
"""

import argparse
import struct
import sys
from pathlib import Path

from mort_audio import (ARCHIVE4, MORT_MAGIC, MortDecoder, archive4_clips,
                        parse_alseqfile, silence)

PAK = 0x15C0000
PAK_SIZE = 0xA2C050
A4 = ARCHIVE4 - PAK              # archive 4, relative to the pak
A4_SIZE = 0x9FA260 - A4          # up to archive 5: 0x63E080
CLIP_COUNT = 823


def build_alseqfile(files):
    """'S1' + u16 count + count x {u32 offset, u32 len} + the files."""
    pos = 4 + 8 * len(files)
    index = bytearray()
    for f in files:
        index += struct.pack(">II", pos, len(f))
        pos += len(f)
    return b"S1" + struct.pack(">H", len(files)) + bytes(index) + b"".join(files)


def rebuild(pak, blobs):
    """Archive-4 image holding `blobs` (clip order), split over the original
    sub-files."""
    subs, out, i = [], [], 0
    for base, _ in parse_alseqfile(pak, A4)[1]:
        n = parse_alseqfile(pak, base)[0]
        subs.append(build_alseqfile(blobs[i:i + n]))
        i += n
    assert i == len(blobs), (i, len(blobs))
    return build_alseqfile(subs)


def inject(pak, repl):
    """Rebuild archive 4 with repl{clip index: blob} applied.  The archive keeps
    its exact slot -- the spare bytes are zeroed, as they are in the original --
    so nothing else moves and a no-op run ends up byte-identical."""
    clips = archive4_clips(pak, A4)
    assert len(clips) == CLIP_COUNT, len(clips)
    blobs = [repl.get(i, pak[off:off + wc * 4])
             for i, (off, fc, sr, wc) in enumerate(clips)]
    new = rebuild(pak, blobs)
    assert len(new) <= A4_SIZE, ("archive 4 grew to %#x > %#x -- see the module "
                                 "docstring" % (len(new), A4_SIZE))
    out = bytearray(pak)
    out[A4:A4 + A4_SIZE] = new.ljust(A4_SIZE, b"\0")
    return bytes(out), len(new)


def verify(pak, new_pak, repl):
    """Re-read the result through the path the game uses, and require everything
    outside archive 4 to be untouched."""
    assert new_pak[:A4] == pak[:A4]
    assert new_pak[A4 + A4_SIZE:] == pak[A4 + A4_SIZE:]
    clips = archive4_clips(new_pak, A4)
    assert len(clips) == CLIP_COUNT, len(clips)
    for i, blob in repl.items():
        off, fc, sr, wc = clips[i]
        pcm = MortDecoder(new_pak, off).decode()
        assert pcm == MortDecoder(blob, 0).decode(), "clip %d decodes wrong" % i
        assert len(pcm) == fc * 0xA0


def load(spec, clips):
    """'N=FILE' or 'N=silence' -> (clip index, blob)."""
    n, _, path = spec.partition("=")
    n = int(n)
    assert 0 <= n < len(clips), "clip index %d out of range" % n
    if path == "silence":
        return n, silence(clips[n][1], clips[n][2])
    blob = Path(path).read_bytes()
    assert blob[:4] == MORT_MAGIC, "%s: not a MORT blob" % path
    assert len(blob) == 4 * struct.unpack_from(">I", blob, 8)[0], \
        "%s: header word count does not match the file size" % path
    return n, blob


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("specs", nargs="*", metavar="N=FILE")
    ap.add_argument("-r", "--rom", default="baseroms/us/baserom.z64")
    ap.add_argument("-o", "--out", default="build/mort_injected.z64")
    ap.add_argument("-a", "--asset", action="store_true",
                    help="also write assets/us/15C0000.bin, so make builds it in")
    args = ap.parse_args()

    rom = Path(args.rom).read_bytes()
    pak = rom[PAK:PAK + PAK_SIZE]
    clips = archive4_clips(pak, A4)
    repl = dict(load(spec, clips) for spec in args.specs)

    new_pak, used = inject(pak, repl)
    verify(pak, new_pak, repl)
    if not repl:
        assert new_pak == pak, "round trip is not byte-identical"
    print("%s; archive 4 uses %#x of its %#x-byte slot"
          % ("round trip: pak byte-identical" if new_pak == pak else
             "replaced %d of %d clips" % (len(repl), len(clips)), used, A4_SIZE))

    out = bytearray(rom)
    out[PAK:PAK + PAK_SIZE] = new_pak
    Path(args.out).parent.mkdir(parents=True, exist_ok=True)
    Path(args.out).write_bytes(bytes(out))
    print("wrote %s" % args.out)
    if args.asset:
        Path("assets/us/15C0000.bin").write_bytes(new_pak)
        print("wrote assets/us/15C0000.bin")


if __name__ == "__main__":
    sys.exit(main())
