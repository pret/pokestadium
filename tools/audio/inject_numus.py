#!/usr/bin/env python3
"""Replace Numus bank samples (the NADPCM voices/SFX of §2-§6) in the ROM.

Sample bytes live raw in each bank's wave-table region (`rom[wt + base : +len]`)
so injection is a straight in-place patch: no yay0 twin to recompress, no
pointer to move.  The replacement is encoded with the sample's *own* codebook
(numus_audio.encode_frames), which keeps the bank descriptors valid, and is
truncated or padded with silent frames to the original byte length, so nothing
downstream changes.

Input WAV is converted to mono 32000 Hz (SYNTH_RATE) by linear interpolation.

usage:  python3 tools/audio/inject_numus.py [-o OUT.z64] [-r BASEROM] [-a] SPEC...
  SPEC is BANK:N=FILE.wav, e.g. UNNAMED_16F2F68:8=kirby.wav.  Bank names are the
  ones extract_audio.py prints.  With no SPEC this is a byte-identical round trip.
"""

import argparse
import struct
import sys
import wave
from pathlib import Path

from extract_audio import RAW_BANKS, bank_name, find_twin
from inject_mort import PAK, PAK_SIZE
from numus_audio import (SYNTH_RATE, WT_MAGIC, decode_frames, encode_frames,
                         parse_expanded_bank)

SILENT_FRAME = b"\x00" * 9          # scale 0, predictor 0, all-zero nibbles


def read_wav(path, rate=SYNTH_RATE):
    """WAV -> mono s16 at `rate`, linearly resampled."""
    with wave.open(str(path)) as w:
        assert w.getsampwidth() == 2, "%s: only 16-bit WAV is supported" % path
        ch, src_rate, n = w.getnchannels(), w.getframerate(), w.getnframes()
        pcm = struct.unpack("<%dh" % (n * ch), w.readframes(n))
    if ch > 1:
        pcm = [sum(pcm[i:i + ch]) // ch for i in range(0, len(pcm), ch)]
    if src_rate == rate:
        return list(pcm)
    out = []
    for i in range(int(len(pcm) * rate / src_rate)):
        pos = i * src_rate / rate
        k = int(pos)
        a, b = pcm[k], pcm[min(k + 1, len(pcm) - 1)]
        out.append(int(a + (b - a) * (pos - k)))
    return out


def banks(rom):
    """{name: (wave-table offset, parsed bank)} for every bank in the ROM."""
    out = {}
    for raw in RAW_BANKS:
        wt = rom.find(WT_MAGIC, raw, raw + 0x40000)
        twin = find_twin(rom, raw)
        if wt < 0 or twin is None:
            continue
        bank = parse_expanded_bank(twin[1])
        out[bank_name(bank, raw)] = (wt, bank)
    return out


def encode_for(sample, pcm):
    """`pcm` as NADPCM of exactly sample.length bytes (padded with silence)."""
    frames = sample.length // 9
    data = encode_frames(sample.book, pcm[:frames * 16], sample.entries)
    return data[:sample.length].ljust(frames * 9, b"\0") if len(data) >= sample.length \
        else data + SILENT_FRAME * (frames - len(data) // 9)


def inject(rom, specs):
    """Apply [(bank, index, wav path), ...]; returns (new rom, [report, ...])."""
    out, table, report = bytearray(rom), banks(rom), []
    for name, index, path in specs:
        assert name in table, "unknown bank %s (have: %s)" % (name, ", ".join(table))
        wt, bank = table[name]
        assert 0 <= index < len(bank.samples), "%s: no sample %d" % (name, index)
        s = bank.samples[index]
        pcm = read_wav(path)
        data = encode_for(s, pcm)
        assert len(data) == s.length, (len(data), s.length)
        out[wt + s.base:wt + s.base + s.length] = data
        used = min(len(pcm), s.length // 9 * 16)
        report.append("%s s%03d @%#x: %d of %d bytes, %.2fs of %.2fs source"
                      % (name, index, wt + s.base, s.length, s.length,
                         used / SYNTH_RATE, len(pcm) / SYNTH_RATE))
    return bytes(out), report


def verify(rom, new_rom, specs):
    """Decode each patched sample back out of the new ROM through the same path
    the extractor uses, and require the rest of the ROM to be untouched."""
    table, touched = banks(new_rom), []
    for name, index, path in specs:
        wt, bank = table[name]
        s = bank.samples[index]
        data = new_rom[wt + s.base:wt + s.base + s.length]
        pcm = decode_frames(s.book, data, wrap_out=False)
        assert len(pcm) == s.length // 9 * 16, (len(pcm), s.length)
        want = read_wav(path)[:len(pcm)]
        err = sum((a - b) ** 2 for a, b in zip(pcm, want)) / max(len(want), 1)
        touched.append((wt + s.base, s.length, err ** 0.5))
    for off, length, rms in touched:
        assert new_rom[off:off + length] != rom[off:off + length] or not specs
    spans = sorted((o, o + n) for o, n, _ in touched)
    pos = 0
    for a, b in spans:
        assert new_rom[pos:a] == rom[pos:a], "ROM changed outside a sample"
        pos = b
    assert new_rom[pos:] == rom[pos:]
    return [rms for _, _, rms in touched]


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("specs", nargs="*", metavar="BANK:N=FILE.wav")
    ap.add_argument("-r", "--rom", default="baseroms/us/baserom.z64")
    ap.add_argument("-o", "--out", default="build/numus_injected.z64")
    ap.add_argument("-a", "--asset", action="store_true",
                    help="also write assets/us/15C0000.bin, so make builds it in")
    args = ap.parse_args()

    specs = []
    for spec in args.specs:
        where, _, path = spec.partition("=")
        name, _, index = where.partition(":")
        specs.append((name, int(index), path))

    rom = Path(args.rom).read_bytes()
    new_rom, report = inject(rom, specs)
    rms = verify(rom, new_rom, specs)
    for line, e in zip(report, rms):
        print("%s, rms error %.0f" % (line, e))
    if not specs:
        assert new_rom == rom, "round trip is not byte-identical"
        print("round trip: ROM byte-identical")

    Path(args.out).parent.mkdir(parents=True, exist_ok=True)
    Path(args.out).write_bytes(new_rom)
    print("wrote %s" % args.out)
    if args.asset:
        Path("assets/us/15C0000.bin").write_bytes(new_rom[PAK:PAK + PAK_SIZE])
        print("wrote assets/us/15C0000.bin")


if __name__ == "__main__":
    sys.exit(main())
