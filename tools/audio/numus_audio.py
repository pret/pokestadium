#!/usr/bin/env python3

"""
Parses the banks, decodes their 9-byte ADPCM frames and writes the samples out
as N64 AIFC (VAPC/VADPCM). This module works on the EXPANDED bank image (what 
tools/decompress_yay0.py produces from the copies in the audio archives);
the raw compact ROM encoding is parsed in tools/audio/extract_audio.py.

usage (self-check):  python3 tools/audio/numus_audio.py [baserom]
"""

import math
import struct
import sys
from dataclasses import dataclass

BANK_MAGIC = b"N64 PtrTablesV2\x00"
WT_MAGIC = b"N64 WaveTables \x00"
SYNTH_RATE = 32000  # musConfig.syn_output_rate (src/373A0.c)
AUDIO_PAK = 0x15C0000
ARC1_FILE0 = (0x15C0160, 0x15C3EB0)  # yay0 copy of BGM.WBK


def u32(buf, off):
    return struct.unpack_from(">I", buf, off)[0]


def s16list(buf, off, count):
    return list(struct.unpack_from(">%dh" % count, buf, off))


def wrap16(x):
    """Truncate to C s16 (mod 2^16, sign)."""
    x &= 0xFFFF
    return x - 0x10000 if x >= 0x8000 else x


def pstr(s):
    """IFF pascal string."""
    return bytes([len(s)]) + s


@dataclass
class Sample:
    base: int          # byte offset inside the wave table region
    length: int        # ADPCM byte count
    book: list         # coefficients (s16)
    book_off: int
    loop_start: int    # sample units, -1 if no loop
    loop_end: int
    loop_count: int
    loop_state: list   # 16 s16 of filter state
    order: int = 2
    entries: int = 4


@dataclass
class Bank:
    offset: int
    name: str
    count: int
    samples: list


def parse_expanded_bank(img, offset=0):
    """Parse an expanded (RAM image) Numus bank. Returns Bank."""
    if img[offset:offset + 16] != BANK_MAGIC:
        raise ValueError("not a PtrTablesV2 bank at %#x" % offset)
    name = img[offset + 0x14:offset + 0x20].split(b"\x00")[0].decode("ascii", "replace")
    count = u32(img, offset + 0x20)
    wave_list = offset + u32(img, offset + 0x2C)
    samples = []
    for i in range(count):
        desc = offset + u32(img, wave_list + i * 4)
        base = u32(img, desc) & 0x00FFFFFF  # stored as 0xFF000000 | rel
        length = u32(img, desc + 4)
        loop_off = offset + u32(img, desc + 0x0C)
        book_off = offset + u32(img, desc + 0x10)
        if loop_off == offset and book_off == offset:
            continue  # null descriptor
        order, npred = struct.unpack_from(">ii", img, book_off)
        book = s16list(img, book_off + 8, min(order * npred * 16, 64))
        if loop_off == offset:
            loop_start = loop_end = loop_count = -1
            state = []
        else:
            loop_start, loop_end, loop_count = struct.unpack_from(">III", img, loop_off)
            state = s16list(img, loop_off + 0x0C, 16)
        samples.append(Sample(base, length, book, book_off, loop_start, loop_end,
                              loop_count, state, order, npred))
    return Bank(offset, name, count, samples)


def decode_frames(book, data, wrap_out=True):
    """NADPCM decode, bit-exact rule (verified on BGM.WBK sample 0).

    A frame is [hdr][8 bytes]: hdr>>4 = scale, hdr&0xF = predictor, giving 16
    samples in interleaved nibble order (hi then lo), each a signed 4-bit value.
    Predictor p selects the 16 s16 coefficient block at p*16 (the classic N64
    "ADPCMFSIZE=16" layout), from which f1 = book[p*16 + 8], f2 = book[p*16].
    Per sample: out = ((f1*v1 + f2*v2) >> 11) + (nibble << scale), with v1/v2
    the two previous outputs, kept as s16 like the N64 player.
    """
    out = []
    v1 = v2 = 0
    for i in range(0, len(data) // 9 * 9, 9):
        scale, pred = data[i] >> 4, data[i] & 0xF
        b = pred * 16
        if b + 16 > len(book):
            b = 0  # keep bounded
        f1, f2 = book[b + 8], book[b]
        for byte in data[i + 1:i + 9]:
            for nib in (byte >> 4, byte & 0xF):
                cur = ((f1 * v1 + f2 * v2) >> 11) + (((nib ^ 8) - 8) << scale)
                if wrap_out:
                    cur = wrap16(cur)
                out.append(cur)
                v2, v1 = v1, cur
    return out


def encode_frames(book, pcm, npred=4):
    """NADPCM encode: the exact inverse search of decode_frames.

    For each 16-sample frame every (predictor, scale) pair is tried, the
    nibbles are the rounded quantised residuals, and the pair with the lowest
    squared error wins. Uses only codebook entries the sample already has, so
    the bank descriptors never change."""
    data = bytearray()
    v1 = v2 = 0
    for i in range(0, len(pcm) - len(pcm) % 16, 16):
        want = pcm[i:i + 16]
        best = None
        for pred in range(npred):
            f1, f2 = book[pred * 16 + 8], book[pred * 16]
            for scale in range(16):
                nibs, err, a1, a2 = [], 0, v1, v2
                for target in want:
                    base = (f1 * a1 + f2 * a2) >> 11
                    n = max(-8, min(7, (target - base + (1 << scale >> 1)) >> scale))
                    cur = wrap16(base + (n << scale))
                    err += (cur - target) ** 2
                    nibs.append(n & 0xF)
                    a2, a1 = a1, cur
                if best is None or err < best[0]:
                    best = (err, scale, pred, nibs, a1, a2)
        _, scale, pred, nibs, v1, v2 = best
        data.append(scale << 4 | pred)
        data += bytes(nibs[k] << 4 | nibs[k + 1] for k in range(0, 16, 2))
    return bytes(data)


def _extended(value):
    """80-bit IEEE extended (AIFF sample rate)."""
    if value == 0:
        return b"\x00" * 10
    exp = math.floor(math.log2(value))
    frac = value / (2.0 ** exp)          # 1.0 <= frac < 2.0
    return struct.pack(">HQ", 16383 + exp, int(frac * 2 ** 63))


def write_aifc(path, sample, data, rate=SYNTH_RATE):
    """Write one sample as an N64 AIFC (VAPC/VADPCM), layout copied from the
    official devkit files (ULTRA/USR/LIB/PR/SOUNDS/*.AIFC) and the N64 Pro-Man
    "ADPCM AIFC Format" spec: COMM + INST + APPL 'stoc' VADPCMCODES +
    optional APPL 'stoc' VADPCMLOOPS + SSND."""
    def chunk(tag, body):
        return tag + struct.pack(">i", len(body)) + body

    comm = (struct.pack(">HIH", 1, len(data) // 9 * 16, 16) + _extended(rate) +
            b"VAPC" + pstr(b"VADPCM ~4-1"))
    inst = struct.pack(">6Bh6H", 0x3C, 0, 0, 127, 1, 127, 0, 0, 0, 0, 0, 0, 0)
    nbook = sample.order * sample.entries * 16 // 2  # tableData, in s16
    book = list(sample.book)[:nbook] + [0] * max(0, nbook - len(sample.book))
    codes = (b"stoc" + pstr(b"VADPCMCODES") +
             struct.pack(">HhH", 1, sample.order, sample.entries) +
             struct.pack(">%dh" % nbook, *book))
    chunks = [chunk(b"COMM", comm), chunk(b"INST", inst), chunk(b"APPL", codes)]

    if sample.loop_state:
        sgn = lambda v: v - 0x100000000 if v >= 1 << 31 else v
        loops = (b"stoc" + pstr(b"VADPCMLOOPS") +
                 struct.pack(">Hhiii", 1, 1, sgn(sample.loop_start),
                             sgn(sample.loop_end), sgn(sample.loop_count)) +
                 struct.pack(">16H", *[x & 0xFFFF for x in sample.loop_state]))
        chunks.append(chunk(b"APPL", loops))
    chunks.append(chunk(b"SSND", b"\x00" * 8 + data))

    with open(path, "wb") as f:
        f.write(chunk(b"FORM", b"AIFC" + b"".join(chunks)))


def read_aifc(path):
    """Minimal reader for the files write_aifc produces (round-trip check)."""
    buf = open(path, "rb").read()
    assert buf[:4] == b"FORM" and buf[8:12] == b"AIFC", "not AIFC"
    out = {"frames": b"", "book": None, "order": None, "entries": None,
           "loop": None, "frames_count": None}
    pos = 12
    while pos + 8 <= len(buf):
        tag, size = buf[pos:pos + 4], struct.unpack_from(">i", buf, pos + 4)[0]
        body = buf[pos + 8:pos + 8 + size]
        appl = tag == b"APPL" and body[:4] == b"stoc"
        if tag == b"COMM":
            out["frames_count"] = u32(body, 2)
            assert body[18:22] == b"VAPC" and body[22] == 11, "bad COMM"
        elif appl and b"VADPCMCODES" in body[:20]:
            out["order"], out["entries"] = struct.unpack_from(">hH", body, 18)
            out["book"] = s16list(body, 22, out["order"] * out["entries"] * 8)
        elif appl and b"VADPCMLOOPS" in body[:20]:
            out["loop"] = struct.unpack_from(">iii", body, 20)
        elif tag == b"SSND":
            out["frames"] = body[8:]
        pos += 8 + size + (size & 1)
    return out


def _selfcheck(baserom="baseroms/us/baserom.z64"):
    import crunch64
    rom = open(baserom, "rb").read()
    img = crunch64.yay0.decompress(rom[ARC1_FILE0[0]:ARC1_FILE0[1]])
    bank = parse_expanded_bank(img)
    assert (bank.name, bank.count) == ("BGM.WBK", 83), (bank.name, bank.count)
    s = bank.samples[0]
    wt = AUDIO_PAK + 0x3EB0
    pcm = decode_frames(s.book, rom[wt + s.base:wt + s.base + s.length])
    # The loop state is the 16-sample frame containing loop_start
    # (loop_start=0x44DE=17630 -> samples [17616,17632)). It is not bit-exact:
    # the encoder saved a pre-roll whose ringing damps out to ~1..13 units.
    f0 = (s.loop_start // 16) * 16
    diff = sum(abs(a - b) for a, b in zip(pcm[f0:f0 + 16], s.loop_state))
    assert diff < 0x400, diff
    print("self-check ok: %s, %d samples, sample 0 = %d samples, max %d,"
          " loop-state diff %d" % (bank.name, bank.count, len(pcm),
                                   max(abs(x) for x in pcm), diff))


if __name__ == "__main__":
    _selfcheck(*sys.argv[1:])
