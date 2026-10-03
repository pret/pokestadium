#!/usr/bin/env python3
"""Extract Pokemon Stadium (US) announcer / voice clips (MORT) to WAV.

Walks archive 4's alSeqFile index (0x197C1E0..0x1FBA260), decodes each
self-describing clip with the ported MORT codec (tools/audio/mort_audio.py, a
register-level port of SubDrag's public-domain CMORTDecoder) and writes
build/assets/audio/ANNOUNCER/<NNNN>_<offset>.wav (16-bit mono, header rate)
plus announcer.json with per-clip stats.

With --blobs it instead dumps the raw MORT blobs next to the WAVs; those feed
straight back into tools/audio/inject_mort.py for a byte-identical round trip.

usage:  python3 tools/audio/extract_mort.py [baserom] [--blobs]
"""

import json
import struct
import sys
import time
import wave
from pathlib import Path

from mort_audio import (ANN_END, ARCHIVE4, SAMPLES_PER_FRAME, MortDecoder,
                        archive4_clips, find_mort_chains, parse_alseqfile)

OUT = Path("build/assets/audio/ANNOUNCER")


def s16(pcm):
    """The decoder yields u16; reinterpret as signed."""
    return [x - 0x10000 if x & 0x8000 else x for x in pcm]


def write_wav(path, pcm, rate):
    with wave.open(str(path), "wb") as w:
        w.setnchannels(1)
        w.setsampwidth(2)
        w.setframerate(rate)
        w.writeframes(struct.pack("<%dh" % len(pcm), *s16(pcm)))


def read_wav(path, expected, rate):
    """Reload a clip written by an earlier run, or None if it doesn't match."""
    with wave.open(str(path)) as w:
        if w.getnframes() != expected or w.getframerate() != rate:
            return None
        return list(struct.unpack("<%dh" % expected, w.readframes(expected)))


def dump_blobs(rom, clips, out):
    """The clips as they sit in the ROM, one file each."""
    out.mkdir(parents=True, exist_ok=True)
    for i, (off, fc, sr, wc) in enumerate(clips):
        (out / ("%04d_%08X.mort" % (i, off))).write_bytes(rom[off:off + wc * 4])
    print("wrote %d MORT blobs -> %s" % (len(clips), out))


def main(baserom="baseroms/us/baserom.z64", blobs=False):
    rom = Path(baserom).read_bytes()
    clips = archive4_clips(rom)
    chains = find_mort_chains(rom)
    # cross-check: an independent walk of the contiguous MORT magics must
    # enumerate exactly the same clips
    assert sorted(clips) == sorted(c for ch in chains for c in ch), len(clips)
    print("archive 4 %#x..%#x: %d alSeqFile sub-files, %d clips "
          "(index == magic chain-walk)"
          % (ARCHIVE4, ANN_END, len(parse_alseqfile(rom, ARCHIVE4)[1]), len(clips)))

    if blobs:
        return dump_blobs(rom, clips, OUT / "blobs")

    OUT.mkdir(parents=True, exist_ok=True)
    entries = []
    total = 0
    t0 = time.time()
    for i, (off, fc, sr, wc) in enumerate(clips):
        expected = fc * SAMPLES_PER_FRAME
        path = OUT / ("%04d_%08X.wav" % (i, off))
        pcm = read_wav(path, expected, sr) if path.exists() else None
        if pcm is None:
            dec = MortDecoder(rom, off)
            raw = dec.decode()
            assert len(raw) == expected, (off, len(raw), expected)
            assert dec.size() == wc * 4, off
            tmp = path.with_suffix(".tmp")       # write atomically, so an
            write_wav(tmp, raw, sr)              # interrupted run can resume
            tmp.replace(path)
            pcm = s16(raw)

        peak = max(abs(x) for x in pcm)
        rms = (sum(x * x for x in pcm) / len(pcm)) ** 0.5
        entries.append({
            "index": i, "offset": off, "frames": fc, "sample_rate": sr,
            "words": wc, "bytes": wc * 4, "samples": len(pcm),
            "seconds": round(len(pcm) / sr, 3), "wav": path.name,
            "peak": peak, "rms": round(rms, 1),
            "nonzero_frac": round(sum(1 for x in pcm if x) / len(pcm), 3),
        })
        total += len(pcm)
        print("[%3d/%d] %s @%#x %4d frames %5.2fs peak=%5d rms=%6.1f"
              % (i + 1, len(clips), path.name, off, fc, len(pcm) / sr, peak, rms))

    manifest = {"archive4_offset": ARCHIVE4, "clip_count": len(clips),
                "chains": [[c[0] for c in ch] for ch in chains],
                "clips": entries}
    (OUT.parent / "announcer.json").write_text(json.dumps(manifest, indent=1))
    silent = sum(1 for c in entries if c["peak"] < 64)
    print("done: %d clips, %d samples, %.1fs audio -> %s (%.1fs)"
          % (len(clips), total, total / 16000.0, OUT, time.time() - t0))
    print("near-silent clips (<64 peak): %d" % silent)


if __name__ == "__main__":
    args = [a for a in sys.argv[1:] if a != "--blobs"]
    main(*args, blobs="--blobs" in sys.argv)
