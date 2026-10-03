#!/usr/bin/env python3
"""HAL "Numus" sequences (Pokemon Stadium BGM + sound effects).

The player is src/libnumus/player.c: every channel is a byte stream, bytes
>= 0x80 are commands (`command_func_jumptable[b & 0x7F]`) and bytes < 0x80 are
notes. This module locates the streams, decodes the container they ship in,
and disassembles them.

Where they live:
  archive 1  0x15C0020  header {file0, wave_tables, num_files} + num_files u32
                        offsets (relative to the archive).  file0 is BGM.WBK;
                        the 76 numbered files are the songs, each a compressed
                        `song_t` image (player.h) that the game expands into a
                        0x98D8 buffer (src/4BDC0.c) and hands to MusLoadSong.
  archive 2  0x16F27E0  16 bank packages.  Each one's ptr_bank file expands to
                        an `fx_t` -- the sound effect sequences, played by
                        MusStartSoundEffect.  Two packages carry a further 166
                        and 151 small fx banks of their own (src/373A0.c reads
                        them as File2SubHeader2); 151 is one per Pokemon.
Both are compressed with the codec at asm/us/517A0.s (func_80050BA0): a
headerless MIO0; u32 pad, u32 size, u32 offset to the match stream, u32
offset to the literal stream, then the control bits.

Self-check:  python3 tools/audio/mus_seq.py [baserom]
"""

import struct
import sys

from mort_audio import parse_alseqfile

ARCHIVE1 = 0x15C0020
ARCHIVE2 = 0x16F27E0
SONG_BUF = 0x98D8               # the game's song scratch buffer (src/4BDC0.c)
WINDOW = 0x1000                 # match distance is 12 bits
MAX_MATCH = 0xFF + 0x12         # 4-bit length, or 0 plus an extra byte

# command_func_jumptable, src/libnumus/player.c.  Width is the operand byte
# count; None marks the ones that read a variable-length (high-bit) value.
COMMANDS = [
    ("stop", 0), ("wave", None), ("port", 1), ("portoff", 0), ("defa", 7),
    ("tempo", 1), ("cutoff", 2), ("endit", 1), ("vibup", 3), ("vibdown", 3),
    ("viboff", 0), ("length", None), ("ignore", 0), ("trans", 1),
    ("ignore_trans", 0), ("distort", 1), ("envelope", None), ("envoff", 0),
    ("envon", 0), ("troff", 0), ("tron", 0), ("for", 1), ("next", 0),
    ("wobble", 3), ("wobbleoff", 0), ("velon", 0), ("veloff", 0),
    ("velocity", 1), ("pan", 1), ("stereo", 2), ("drums", 1), ("drumsoff", 0),
    ("print", 1), ("goto", 6), ("reverb", 1), ("randnote", 2),
    ("randvolume", 2), ("randpan", 2), ("volume", 1), ("startfx", None),
    ("bendrange", 1), ("sweep", 1),
] + [(None, 0)] * 6 + [("startfx_ext", None)]
COMMANDS += [(None, 0)] * (0x80 - len(COMMANDS))


def decompress(buf, off=0):
    """func_80050BA0: headerless MIO0."""
    size, comp, raw = struct.unpack_from(">III", buf, off + 4)
    comp += off
    raw += off
    ctrl = off + 0x10
    out = bytearray()
    bits = nbits = 0
    while len(out) < size:
        if nbits == 0:
            bits = struct.unpack_from(">I", buf, ctrl)[0]
            ctrl += 4
            nbits = 32
        if bits & 0x80000000:
            out.append(buf[raw])
            raw += 1
        else:
            v = struct.unpack_from(">H", buf, comp)[0]
            comp += 2
            n, dist = v >> 12, v & 0xFFF
            if n == 0:
                n = buf[raw] + 0x12
                raw += 1
            else:
                n += 2
            src = len(out) - dist - 1
            for i in range(n):
                out.append(out[src + i])
        bits = (bits << 1) & 0xFFFFFFFF
        nbits -= 1
    return bytes(out)


def compress(data):
    """The inverse: greedy longest match, emitted in the same three streams."""
    ctrl, matches, literals = bytearray(), bytearray(), bytearray()
    bits = nbits = 0
    index = {}
    pos = 0
    while pos < len(data):
        best_len, best_dist = 0, 0
        for cand in reversed(index.get(data[pos:pos + 3], ())):
            dist = pos - cand - 1
            if dist >= WINDOW:
                break
            n = 0
            while (n < MAX_MATCH and pos + n < len(data)
                   and data[cand + n] == data[pos + n]):
                n += 1
            if n > best_len:
                best_len, best_dist = n, dist
                if n == MAX_MATCH:
                    break
        if best_len >= 3:
            if best_len < 0x12:
                matches += struct.pack(">H", (best_len - 2) << 12 | best_dist)
            else:
                matches += struct.pack(">H", best_dist)
                literals.append(best_len - 0x12)
            n = best_len
        else:
            bits |= 0x80000000 >> nbits
            literals.append(data[pos])
            n = 1
        for i in range(pos, pos + n):
            index.setdefault(data[i:i + 3], []).append(i)
        pos += n
        nbits += 1
        if nbits == 32:
            ctrl += struct.pack(">I", bits)
            bits = nbits = 0
    if nbits:
        ctrl += struct.pack(">I", bits)
    head = struct.pack(">IIII", 0, len(data), 0x10 + len(ctrl),
                       0x10 + len(ctrl) + len(matches))
    return head + bytes(ctrl) + bytes(matches) + bytes(literals)


def archive_files(rom, base=ARCHIVE1):
    """Archive 1: (file0 offset, wave-table offset, [song offsets])."""
    file0, waves, count = struct.unpack_from(">III", rom, base)
    offs = struct.unpack_from(">%dI" % count, rom, base + 0xC)
    return base + file0, base + waves, [base + o for o in offs]


def songs(rom, base=ARCHIVE1, end=ARCHIVE2):
    """[(rom offset, packed length)] for every song, in play order. Each file
    runs to the next one; the last runs to the end of the archive."""
    offs = archive_files(rom, base)[2]
    return [(o, (offs[i + 1] if i + 1 < len(offs) else end) - o)
            for i, o in enumerate(offs)]


def packages(rom, base=ARCHIVE2):
    """Every bank package under archive 2, outermost first.

    Two header shapes (src/373A0.h): File2SubHeader1 {ptr_bank, sample_bank,
    wave_tables} and File2SubHeader2 {num_files, ptr_bank, wave_tables, files},
    whose files are small fx banks of their own. They are told apart by which
    reading lands on a valid compressed blob."""
    out = []
    for off, size in parse_alseqfile(rom, base)[1]:
        if rom[off:off + 2] == b"S1":
            out += packages(rom, off)
            continue
        w = struct.unpack_from(">III", rom, off)
        if packed_ok(rom, off + w[0]) and packed_ok(rom, off + w[1]):
            out.append({"offset": off, "end": off + size, "fx": off + w[0],
                        "bank": off + w[1], "waves": off + w[2], "files": []})
        else:
            # File2SubHeader2: offset1 is the sample bank, and the fx banks
            # are the files (src/373A0.c:587-600)
            files = struct.unpack_from(">%dI" % w[0], rom, off + 0xC)
            out.append({"offset": off, "end": off + size, "fx": None,
                        "bank": off + w[1], "waves": off + w[2],
                        "files": [off + f for f in files]})
    return out


def packed_ok(buf, off):
    """Does `off` look like a compressed blob header?"""
    if off + 0x10 > len(buf):
        return False
    size, comp, raw = struct.unpack_from(">III", buf, off + 4)
    return 0 < size <= SONG_BUF and 0x10 <= comp < raw


def fx_blobs(rom, base=ARCHIVE2):
    """Every fx bank in the ROM, in package order, as
    {offset, slot, bank, waves}.  `slot` is what an injected bank has to fit
    back into; `bank`/`waves` are the sample bank it plays through."""
    out = []
    for pkg in packages(rom, base):
        if pkg["fx"]:
            out.append({"offset": pkg["fx"], "slot": pkg["bank"] - pkg["fx"],
                        "bank": pkg["bank"], "waves": pkg["waves"],
                        "waves_end": pkg["end"]})
        files = pkg["files"]
        for i, off in enumerate(files):
            end = files[i + 1] if i + 1 < len(files) else pkg["end"]
            out.append({"offset": off, "slot": end - off,
                        "bank": pkg["bank"], "waves": pkg["waves"],
                        "waves_end": pkg["end"]})
    return out


def parse_fx(img):
    """fx_t (player.h) -> {count, metadata offsets, sequence offsets}."""
    count, _, meta, data = struct.unpack_from(">IIII", img, 0)
    return {"count": count, "meta": meta, "data": data,
            "sequences": list(struct.unpack_from(">%dI" % count, img, data))}


def parse_song(img):
    """song_t (player.h) -> {channels, per-channel stream offsets, tables}."""
    n, data, volume, pitchbend = struct.unpack_from(">IIII", img, 0)
    get = lambda off: list(struct.unpack_from(">%dI" % n, img, off)) if off else []
    return {"channels": n, "data": get(data), "volume": get(volume),
            "pitchbend": get(pitchbend),
            "env_table": struct.unpack_from(">I", img, 0x10)[0],
            "drum_table": struct.unpack_from(">I", img, 0x14)[0]}


def varint(img, pos):
    """The player's high-bit extension: 0..0x7F in one byte, else two."""
    v = img[pos]
    return (v, pos + 1) if v < 0x80 else (((v & 0x7F) << 8) | img[pos + 1], pos + 2)


def disassemble(img, start, end=None):
    """Walk one channel stream from `start`.  Returns [(offset, text)].

    Note length depends on player state (velon/veloff, length, ignore), so the
    walk tracks it exactly as __MusIntGetNewNote does."""
    out = []
    pos = start
    velocity_on = False
    fixed_length = 0
    ignore = False
    end = len(img) if end is None else end
    while pos < end:
        at = pos
        b = img[pos]
        if b >= 0x80:
            name, width = COMMANDS[b & 0x7F]
            pos += 1
            if name is None:
                out.append((at, "?%02X" % b))
                break
            if width is None:
                value, pos = varint(img, pos)
                args = [value]
            else:
                args = list(img[pos:pos + width])
                pos += width
            if name == "velon":
                velocity_on = True
            elif name in ("veloff", "velocity"):   # Fvelocity clears it too
                velocity_on = False
            elif name == "length":
                fixed_length = args[0]
            elif name == "ignore":
                ignore = True
            out.append((at, "%-12s %s" % (name, " ".join("%d" % a for a in args))))
            if name in ("stop", "goto"):
                break
            continue
        pos += 1
        velocity = None
        if velocity_on:
            velocity = img[pos]
            pos += 1
        if fixed_length and not ignore:
            duration = fixed_length
        else:
            ignore = False
            duration, pos = varint(img, pos)
        note = "rest" if b == 0x60 else "note %d" % b
        out.append((at, "%-12s dur %d%s"
                    % (note, duration,
                       "" if velocity is None else " vel %d" % velocity)))
    return out


def stream_bounds(song, size):
    """Every stream start in a song image, plus the end: a channel runs to the
    next one."""
    starts = song["data"] + song["volume"] + song["pitchbend"]
    return sorted(set([o for o in starts if o] + [size]))


def _selfcheck(baserom="baseroms/us/baserom.z64"):
    rom = open(baserom, "rb").read()
    file0, waves, offs = archive_files(rom)
    assert (file0, waves, len(offs)) == (0x15C0160, 0x15C3EB0, 76),         (hex(file0), hex(waves), len(offs))
    table = songs(rom)
    print("archive 1 @%#x: BGM bank @%#x, wave tables @%#x, %d songs"
          % (ARCHIVE1, file0, waves, len(table)))

    expanded = repacked = channels = 0
    for i, (off, size) in enumerate(table):
        img = decompress(rom, off)
        assert len(img) == struct.unpack_from(">I", rom, off + 4)[0]
        assert len(img) <= SONG_BUF, (i, len(img))
        packed = compress(img)
        assert decompress(packed) == img, i
        expanded += len(img)
        repacked += len(packed)

        song = parse_song(img)
        bounds = stream_bounds(song, len(img))
        for c, start in enumerate(song["data"]):
            if not start:
                continue
            channels += 1
            end = min(b for b in bounds if b > start)
            events = disassemble(img, start, end)
            # every byte must decode: the walk ends on `stop`/`goto`, or runs
            # exactly into the next stream (the channel loops via for/next)
            assert not any(t.startswith("?") for _, t in events), (i, c)
            last, pos = events[-1][1].split()[0], events[-1][0]
            assert last in ("stop", "goto") or pos == end - 1, (i, c, last)
        if i == 0:
            print("song 0: %d bytes, %d channels, channel 0 -> %d events"
                  % (len(img), song["channels"], len(events)))
            for at, text in disassemble(img, song["data"][0])[:8]:
                print("   %#06x  %s" % (at, text))

    packed_rom = sum(s for _, s in table)
    print("self-check ok: %d songs (%d channels, every byte decodes), %#x bytes "
          "in ROM -> %#x expanded; re-packed they need %#x (%+d)"
          % (len(table), channels, packed_rom, expanded, repacked,
             repacked - packed_rom))


if __name__ == "__main__":
    _selfcheck(*sys.argv[1:])
