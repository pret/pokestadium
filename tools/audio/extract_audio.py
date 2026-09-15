#!/usr/bin/env python3

import json
import struct
import sys
import wave
from pathlib import Path

import crunch64

from numus_audio import (BANK_MAGIC, SYNTH_RATE, WT_MAGIC, decode_frames,
                         parse_expanded_bank, read_aifc, write_aifc)

# Raw (uncompressed) 'N64 PtrTablesV2' banks. The game loads the Yay0 twin
# of each one; the raw copy is only used to locate it.
RAW_BANKS = [
    0x15C0CFE, 0x16F2F68, 0x1723A4C, 0x17CA03C, 0x17DC988, 0x1850E50,
    0x18611B2, 0x186FB20, 0x187E1F4, 0x18A2740, 0x18BF876, 0x18CF0F4,
    0x18E6174, 0x1907F56, 0x1928992, 0x192D240, 0x1964C68,
]
YAY0_MAGIC = b"Yay0"
OUT_ROOT = Path("build/assets/audio")


def find_twin(rom, raw_off):
    """Last Yay0 blob before the raw bank that decompresses to a bank image."""
    best = None
    pos = max(0, raw_off - 0x20000)
    while True:
        p = rom.find(YAY0_MAGIC, pos, raw_off)
        if p < 0:
            return best
        pos = p + 4
        try:
            img = crunch64.yay0.decompress(rom[p:p + 0x40000])
        except Exception:
            continue
        if img[:16] == BANK_MAGIC:
            best = (p, img)


def bank_name(bank, raw_off):
    """Display name; the unnamed banks go by their raw offset."""
    return (bank.name or "UNNAMED_%X" % raw_off).replace(".WBK", "")


def write_wav(path, pcm, rate=SYNTH_RATE):
    pcm = [max(-32768, min(32767, x)) for x in pcm]
    with wave.open(str(path), "wb") as w:
        w.setnchannels(1)
        w.setsampwidth(2)
        w.setframerate(rate)
        w.writeframes(struct.pack("<%dh" % len(pcm), *pcm))


def check_aifc(path, sample, data, pcm):
    """Round-trip the AIFC we just wrote back through the decoder."""
    rt = read_aifc(path)
    assert rt["frames"] == data, path
    assert rt["book"][:len(sample.book)] == sample.book, path
    assert decode_frames(rt["book"], rt["frames"], wrap_out=False) == pcm, path
    assert (rt["loop"] is None) == (not sample.loop_state), path


def extract_bank(rom, raw_off):
    """Decode every sample of one bank to WAV + AIFC. Returns a manifest dict."""
    if rom[raw_off:raw_off + 16] != BANK_MAGIC:
        return print("!! bank %#x: bad magic" % raw_off)
    wt = rom.find(WT_MAGIC, raw_off, raw_off + 0x40000)
    if wt < 0:
        return print("!! bank %#x: no wave table region" % raw_off)
    twin = find_twin(rom, raw_off)
    if twin is None:
        return print("!! bank %#x: no Yay0 twin" % raw_off)
    twin_off, img = twin

    bank = parse_expanded_bank(img)
    name = bank_name(bank, raw_off)
    outdir = OUT_ROOT / name
    outdir.mkdir(parents=True, exist_ok=True)

    samples = []
    diffs = []
    for i, s in enumerate(bank.samples):
        data = rom[wt + s.base:wt + s.base + s.length]
        if len(data) < 9:
            continue
        pcm = decode_frames(s.book, data, wrap_out=False)
        entry = {"index": i, "base": s.base, "length": s.length,
                 "loop": bool(s.loop_state),
                 "loop_start": s.loop_start if s.loop_state else None,
                 "loop_end": s.loop_end if s.loop_state else None,
                 "wav": "s%03d.wav" % i, "aifc": "s%03d.aifc" % i,
                 "loop_state_diff": None}
        if s.loop_state:
            # The saved loop state is the 16-sample frame holding loop_start;
            # a non-zero diff is the encoder's pre-roll ringing (see numus_audio).
            f0 = (s.loop_start // 16) * 16
            entry["loop_state_diff"] = sum(
                abs(a - b) for a, b in zip(pcm[f0:f0 + 16], s.loop_state))
            diffs.append(entry["loop_state_diff"])
        write_wav(outdir / entry["wav"], pcm)
        write_aifc(str(outdir / entry["aifc"]), s, data)
        if not samples:  # one round-trip check per bank
            check_aifc(str(outdir / entry["aifc"]), s, data, pcm)
        samples.append(entry)

    loops = ("min=%d med=%d max=%d" % (min(diffs), sorted(diffs)[len(diffs) // 2],
                                       max(diffs)) if diffs else "n/a (no loops)")
    print("%-12s raw=%#x wt=%#x twin=%#x %3d samples | loop-state diff %s"
          % (name, raw_off, wt, twin_off, len(samples), loops))
    return {"bank": name, "raw_offset": raw_off, "wave_tables_offset": wt,
            "yay0_twin_offset": twin_off, "sample_count": len(samples),
            "samples": samples}


def main(baserom="baseroms/us/baserom.z64"):
    rom = Path(baserom).read_bytes()
    OUT_ROOT.mkdir(parents=True, exist_ok=True)
    banks = [b for b in (extract_bank(rom, off) for off in RAW_BANKS) if b]
    (OUT_ROOT / "banks.json").write_text(json.dumps({"banks": banks}, indent=1))
    print("done: %d banks, %d samples -> %s"
          % (len(banks), sum(b["sample_count"] for b in banks), OUT_ROOT))


if __name__ == "__main__":
    main(*sys.argv[1:])
