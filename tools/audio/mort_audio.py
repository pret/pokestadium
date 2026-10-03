#!/usr/bin/env python3
"""
Pure-python port of SubDrag's CMORTDecoder (N64 Sound Tool, public domain
decode-only release), which is a register-level reconstruction of the MIPS
codec Pokemon Stadium uses for the announcer / voice clips.

The encode half (MortWriter) re-packs coded fields; it is not an encoder --
see tools/audio/inject_mort.py for what that is enough to do.

usage (self-check):  python3 tools/audio/mort_audio.py [baserom]
"""

import struct
import sys

MORT_MAGIC = b"MORT"
ARCHIVE4 = 0x197C1E0
ANN_END = 0x1FBA260
SAMPLES_PER_FRAME = 0xA0          # samples decoded per coded frame
RING = 0x1000                     # raw input ring buffer (bytes)


def u32(v):
    return v & 0xFFFFFFFF


def s32(v):
    v &= 0xFFFFFFFF
    return v - 0x100000000 if v & 0x80000000 else v


def s16(v):
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def be32(buf, off):
    return struct.unpack_from(">I", buf, off)[0]


def mul15(x, y):
    """Rounding Q15 multiply: (x*y + 0x4000) >> 15, as the codec does it."""
    return s32(u32(x * y + 0x4000)) >> 0xF


class MortDecoder:
    """One MORT stream.  Call decode() after construction.

    With record=True every bit field read is appended to self.fields as
    (value, width) in read order, which is all MortWriter needs to re-pack
    the same stream."""

    def __init__(self, rom, address, record=False):
        self.rom = rom              # whole ROM (bytes)
        self.address = address      # MORT start; must be 0x1000-aligned
        self.pcm = []               # decoded samples as u16
        self.fields = [] if record else None
        self.frame_count = struct.unpack_from(">H", rom, address + 4)[0]
        self.sample_rate = struct.unpack_from(">H", rom, address + 6)[0]
        self.word_count = be32(rom, address + 8)
        self._reset_state()

    # ---- container ---------------------------------------------------
    def size(self):
        return self.word_count * 4

    def expected_samples(self):
        return self.frame_count * SAMPLES_PER_FRAME

    def _reset_state(self):
        self.pred = [0] * 0xA0          # adaptive predictor buffer
        self.pred_base = 0              # lastPredictorUpdateBase
        self.last_sample = 0
        self.sample_buf = [0] * 8       # s32 history
        self.smoother_cur = False
        self.smoother_a = [0] * 8
        self.smoother_b = [0] * 8
        self.n_skip = 0                 # periods to skip the reset check
        self.n_reset = 0                # frames of null/zero output left
        self.raw = bytearray(RING)      # compressed input ring
        self.bitpos = 0                 # read bit position in the stream
        self.amount_left = 0            # u16 sound-left counter
        self.words_left = 0             # compressed words left to stage
        self.chunk_amount_left = 0      # virtual write byte position
        self.chunk_used = 0             # virtual read byte position (aligned)
        self.var_F08 = 0                # samples handed to the mixer
        self.var_F0C = 0                # samples decoded so far
        self.status1 = 0
        self.status2 = 4
        self.status3 = 2
        self.mort_status2 = 0
        self.cf3c = 0x1F8               # output clock counter
        self.started = False

    # ---- bit reader --------------------------------------------------
    def _read_bits(self, n, cur, bitsleft):
        """Read n bits LSB-first out of the 32-bit input window `cur`."""
        if bitsleft >= n + 1:
            v = cur & ((1 << n) - 1)
            cur >>= n
            self._record(v, n)
            return v, cur, bitsleft - n
        t6 = 1 << bitsleft
        t9 = t6 - 1
        self.bitpos = u32(self.bitpos + 0x20)
        t8 = self.bitpos >> 5
        t6 = t8 & 0x3FF
        t7 = t9 & cur
        t8 = (t6 << 2) & 0xFFFFFFFF
        retval = t7 & 0xFFFF
        cur = be32(self.raw, t8)
        if bitsleft != n:
            t6 = n - bitsleft
            t9 = (1 << t6) - 1
            t8 = ((cur & t9) << bitsleft) & 0xFFFFFFFF
            retval = (retval | t8) & 0xFFFF
        cur = cur >> (n - bitsleft)
        self._record(retval, n)
        return retval, cur, bitsleft + (0x20 - n)

    def _record(self, value, width):
        if self.fields is not None:
            self.fields.append((value, width))

    # ---- helpers called from the frame decoder -----------------------
    def _f48590(self, spc8, off, stack2, sp60):
        """Scale the 13 coded shape taps by the 6-bit gain index."""
        tab1 = (-4, -3, -2, -2, -1, -1, -1, -1)
        tab2 = (7, 7, 3, 7, 1, 3, 5, 7)
        if spc8 < 8:
            t0 = tab1[spc8]
            t1 = tab2[spc8]
        else:
            t0 = (spc8 - 8) >> 3
            t1 = spc8 & 7
        t0 = 6 - t0
        t4 = t1 * 0x800 + 0x47FF
        for x in range(0x28):
            stack2[x] = 0                     # Function80048590 clears its buffer
        for x in range(0xD):
            t5 = mul15(s16(sp60[x]) * 0x2000 - 0x7000, t4)
            # t0-1 is -1 when t0 == 0 (gain index >= 56): MIPS sllv and 32-bit
            # host shifts both use the low 5 bits of the count, so mask it.
            t5 = s32(u32(t5 + (1 << ((t0 - 1) & 31)))) >> t0
            sp60[x] = t5 & 0xFFFF
            stack2[off + x * 3] = s16(sp60[x])

    def _f48684(self, spe0, spd0, stack2):
        """Snake the predictor history and add the new residual block."""
        tab = (0x0CCD, 0x2CCD, 0x5333, 0x7FFF, 0x852A, 0x0000)
        if 0x28 <= spe0 <= 0x78:
            self.pred_base = spe0
        pred = self.pred
        for x in range(0x78):
            pred[x] = pred[x + 0x28]
        gain = tab[spd0]
        base = 0x78 - self.pred_base
        for x in range(0x28):
            t1 = u32(s16(pred[base + x]))
            t1 = u32(t1 * gain + 0x4000) >> 0xF
            pred[0x78 + x] = (t1 + s16(stack2[x])) & 0xFFFF

    def _f48B3C(self, t2):
        """Companding curve applied to the interpolated smoother values."""
        neg = False
        t2 = u32(t2)
        if s32(t2) < 0:
            t2 = -s32(t2)
            neg = True
        if t2 < 0x2B33:
            t2 = t2 * 2
        elif t2 < 0x4E66:
            t2 = t2 + 0x2B33
        else:
            t2 = (s32(t2) >> 2) + 0x6600
        if t2 > 0x7FFF:
            t2 = 0x7FFF
        if neg:
            t2 = -t2
        return t2 & 0xFFFF

    def _f48A58(self, alg):
        """Interpolate the two smoother predictor sets into 8 adjusters."""
        if not self.smoother_cur:
            sp1, sp2 = self.smoother_a, self.smoother_b
        else:
            sp1, sp2 = self.smoother_b, self.smoother_a
        adj = [0] * 8
        for x in range(8):
            t2 = u32(s16(sp1[x]))
            t4 = u32(s16(sp2[x]))
            if alg == 0:
                t2 = u32((s32(t2) >> 2) + (s32(t4) >> 1) + (s32(t4) >> 2))
            elif alg == 1:
                t2 = u32((s32(t2) >> 1) + (s32(t4) >> 1))
            elif alg == 2:
                t2 = u32((s32(t2) >> 1) + (s32(t4) >> 2) + (s32(t2) >> 2))
            adj[x] = self._f48B3C(t2)
        return adj

    def _f48740(self, pbuf_off, count, adj, a3, s):
        """Lattice-style synthesis filter: emit `count` samples."""
        a3 = u32(a3)
        a = [s16(v) for v in adj]
        for x in range(count):
            t2 = u32(s16(self.pred[pbuf_off + x]) - mul15(s[7], a[7]))
            for k in range(6, -1, -1):
                t2 = u32(t2 - mul15(s[k], a[k]))
                s[k + 1] = u32(mul15(a[k], t2) + s[k])
            s[0] = t2
            t2 = a3 = u32(t2 + mul15(0x6E14, a3))
            t2 = u32(t2 << 1)
            at = s32(u32((s32(t2) >> 0xF) + 1)) >> 1
            if at != 0:
                t2 = 0xFFFF8000 if s32(at) < 0 else 0x7FFF
            self.pcm.append(t2 & 0xFFF8)
        return a3

    def _f48904(self):
        """Synthesis for one frame: 13+14+13+120 samples, 4 gain stages."""
        s = [u32(v) for v in self.sample_buf]
        a3 = u32(s16(self.last_sample))
        for alg, (pbuf_off, count) in enumerate(((0, 0xD), (0xD, 0xE),
                                                 (0x1B, 0xD), (0x28, 0x78))):
            a3 = self._f48740(pbuf_off, count, self._f48A58(alg), a3, s)
        self.sample_buf = [s32(v) for v in s]
        self.last_sample = s16(a3)

    # (bias, multiplier, addend) per coded gain
    SMOOTHER_TAPS = ((0x20, 0x3333, 0x4000), (0x20, 0x3333, 0x4000),
                     (0x10, 0x3333, -0x332F000), (0x10, 0x3333, 0x04003C00),
                     (0x8, 0x4B17, 0xFFC91B1C), (0x8, 0x4444, 0x03BBF800),
                     (0x4, 0x7ADE, 0x147936C), (0x4, 0x740C, 0x40D6B40))

    def _f45A80(self, spe8):
        """Build the smoother predictor set from the 8 coded gains."""
        sp = self.smoother_a if not self.smoother_cur else self.smoother_b
        for x, (bias, mul, add) in enumerate(self.SMOOTHER_TAPS):
            t = u32(s32(u32((s16(spe8[x]) - bias) * 0x400)) * u32(mul))
            sp[x] = u32((s32(u32(t + add)) >> 0xF) << 1) & 0xFFFF
        self._f48904()
        self.smoother_cur = not self.smoother_cur

    def _f45C78(self, sp60, spc8, spd0, offs, spe0, spe8):
        stack2 = [0] * 0x28
        for x in range(4):
            self._f48590(spc8[x] & 0xFF, offs[x] & 0xFF, stack2, sp60[x])
            self._f48684(spe0[x] & 0xFF, spd0[x] & 0xFF, stack2)
        self._f45A80(spe8)

    # ---- the coded frame --------------------------------------------
    def _decode_frame(self):
        sp60 = [[0] * 0xD for _ in range(4)]
        spc8 = [0] * 4
        spd0 = [0] * 4
        offs = [0] * 4
        spe0 = [0] * 4
        spe8 = [0] * 8

        cur = be32(self.raw, (u32(s32(self.bitpos) >> 5) & 0x3FF) << 2)
        bits_used = self.bitpos & 0x1F
        bitsleft = 0x20 - bits_used
        cur >>= bits_used

        if self.n_skip == 0 and self.n_reset == 0:
            t3, cur, bitsleft = self._read_bits(1, cur, bitsleft)
            if t3 != 0:
                self.n_reset, cur, bitsleft = self._read_bits(4, cur, bitsleft)
                self.n_reset += 1
            else:
                self.n_skip, cur, bitsleft = self._read_bits(7, cur, bitsleft)
                self.n_skip += 1

        if self.n_reset != 0:
            self.pcm.extend([0] * 0xA0)
            self.n_reset -= 1
        else:
            for i, n in enumerate((6, 6, 5, 5, 4, 4, 3, 3)):
                spe8[i], cur, bitsleft = self._read_bits(n, cur, bitsleft)
            for x in range(4):
                spe0[x], cur, bitsleft = self._read_bits(7, cur, bitsleft)
                spd0[x], cur, bitsleft = self._read_bits(2, cur, bitsleft)
                offs[x], cur, bitsleft = self._read_bits(2, cur, bitsleft)
                spc8[x], cur, bitsleft = self._read_bits(6, cur, bitsleft)
                for y in range(0xD):
                    sp60[x][y], cur, bitsleft = self._read_bits(3, cur, bitsleft)
            self.n_skip -= 1
            self._f45C78(sp60, spc8, spd0, offs, spe0, spe8)

        t9 = self.bitpos & u32(-0x20)
        self.bitpos = u32(t9 - bitsleft + 0x20)

    # ---- stream driver (Function80045780) ---------------------------
    def _f456D0(self):
        self.pred = [0] * 0xA0
        self.n_skip = 0
        self.n_reset = 0
        self.last_sample = 0
        self.sample_buf = [0] * 8
        self.smoother_cur = False
        self.smoother_a = [0] * 8
        self.smoother_b = [0] * 8
        self.pred_base = 0x28
        self.status2 = 1
        self.status1 = 0
        self.amount_left = 0
        self.words_left = 0
        self.bitpos = 0
        self.chunk_amount_left = 0
        self.chunk_used = 0
        self.var_F0C = 0
        self.var_F08 = 0
        self.status3 = 2

    def _stage(self, ring_off, rom_off, count):
        data = self.rom[rom_off:rom_off + count]
        self.raw[ring_off:ring_off + count] = data.ljust(count, b"\x00")

    def _step(self):
        budget = self.status3          # frames this call may decode
        pending = 0                    # samples decoded but not yet mixed
        if self.status1 != 0:
            # V0 always 0 (Function80056AD0); header parse then chunk accounting
            pos = self.chunk_amount_left
            if pos == 0:
                self.bitpos = 0x60
                self.amount_left = be32(self.raw, 4) >> 0x10
                self.words_left = be32(self.raw, 8) & 0x00FFFFFF
            self.chunk_amount_left = pos + 0x400
            self.words_left = max(0, self.words_left - 0x100)
            self.status1 = 0

        if self.status2 in (1, 2, 3):
            pos = self.chunk_amount_left
            if pos - self.chunk_used < 0xC01:
                if pos != 0:
                    count = (self.words_left << 2) if self.words_left < 0x101 else 0x400
                else:
                    count = 0x400
                if count > 0:
                    self.status1 = 1
                    self._stage(pos & 0xFF8, self.address + pos, count)

        pending = self.var_F0C - self.var_F08
        if pending < 0x960 and (self.status2 == 1 or self.amount_left > 0):
            while self.chunk_amount_left - self.chunk_used > 0 and budget > 0:
                self._decode_frame()
                self.chunk_used = (self.bitpos >> 3) & 0xFFFFFFFC
                self.var_F0C += 0xA0
                self.amount_left = max(0, self.amount_left - 1) & 0xFFFF
                pending = self.var_F0C - self.var_F08
                budget -= 1
                if pending >= 0x960:
                    break
                if self.status2 != 1 and self.amount_left <= 0:
                    break

        if self.status2 == 1 and pending >= 0x8C0:
            self.status2 = 2
            self.started = True

    def decode(self):
        """Decode the whole stream; returns the sample list (u16)."""
        expected = self.expected_samples()
        self._reset_state()
        clock = 0xFFFFFFFF          # audio DMA clock (cf30/cf34; always equal)
        loops = 0
        ended = -1
        while True:
            if clock == 0xFFFFFFFF:
                clock = 0xB8
            else:
                for _ in range(3):
                    clock = 0xB8 if clock >= 0x8A0 else clock + 0xB8
            # samples the mixer asks for this tick
            if clock < self.cf3c:
                want = 0x194 if self.cf3c - clock < 0x194 else 0xB8
            else:
                want = 0x194 if 0x8A0 - 0x194 < clock - self.cf3c else 0xB8

            if self.mort_status2 != 2:
                self._step()
                if len(self.pcm) >= expected:
                    del self.pcm[expected:]
                    break
                if self.status2 == 2:
                    self.status2 = 3        # Function80045A48: now "playing"
                elif self.status2 == 4 and self.mort_status2 not in (0, 3):
                    self.mort_status2 = 2

                # label80045084: Function800459E0 - hand samples to the mixer
                if self.status2 == 3:
                    ready = self.var_F0C - self.var_F08
                    if want < ready:
                        self.var_F08 += want
                    else:
                        self.var_F08 += ready
                        if self.amount_left <= 0:
                            self.status2 = 4

                if want != 0:
                    self.cf3c = (self.cf3c + (want << 1)) % 0x8A0
                    if self.mort_status2 == 0:
                        self._f456D0()
                        self.mort_status2 = 4
            loops += 1
            # the driver never signals "done"; stop once it has idled a while
            if self.started and (self.status2 == 4 or loops >= 2000):
                if ended == -1:
                    ended = loops + 1000
                elif loops > ended:
                    break
        return self.pcm


class MortWriter:
    """Packs coded fields back into a MORT blob.

    This is the wire format only: the caller supplies the coded fields
    (value, width) in the order the decoder reads them, e.g. from
    MortDecoder(record=True).  Picking fields that make the result sound like
    some target PCM is the analysis half, so... not implemented."""

    HEADER_BITS = 96        # the 12-byte container header, skipped by the reader

    def __init__(self):
        self.bits = 0
        self.nbits = self.HEADER_BITS

    def write(self, value, width):
        self.bits |= (value & ((1 << width) - 1)) << self.nbits
        self.nbits += width

    def write_silence(self, frames):
        """Code `frames` null frames -- mode bit 1 plus a 4-bit run length of
        1..16, repeated.  The one frame class that is trivially invertible."""
        while frames > 0:
            n = min(frames, 16)
            self.write(1, 1)
            self.write(n - 1, 4)
            frames -= n

    def blob(self, frame_count, sample_rate):
        nwords = (self.nbits + 31) // 32
        body = b"".join(struct.pack(">I", (self.bits >> (32 * k)) & 0xFFFFFFFF)
                        for k in range(self.HEADER_BITS // 32, nwords))
        return (MORT_MAGIC + struct.pack(">HHI", frame_count, sample_rate, nwords)
                + body)


def repack(rom, address):
    """Decode one clip while recording its fields, then write those fields back
    out.  Returns (pcm, blob); the blob's coded bits equal the original's."""
    dec = MortDecoder(rom, address, record=True)
    pcm = dec.decode()
    w = MortWriter()
    for value, width in dec.fields:
        w.write(value, width)
    return pcm, w.blob(dec.frame_count, dec.sample_rate)


def silence(frame_count, sample_rate=16000):
    """A blob built from scratch that decodes to frame_count * 160 zeros."""
    w = MortWriter()
    w.write_silence(frame_count)
    return w.blob(frame_count, sample_rate)


def parse_alseqfile(rom, base):
    """'S1' + u16 BE count + count x ALSeqData{u32 offset; u32 len}, offsets
    relative to `base`.  Returns (count, [(abs_offset, len), ...])."""
    assert rom[base:base + 2] == b"S1", hex(base)
    n = struct.unpack_from(">H", rom, base + 2)[0]
    ents = [(base + be32(rom, base + 4 + 8 * i), be32(rom, base + 8 + 8 * i))
            for i in range(n)]
    return n, ents


def archive4_clips(rom, archive4=ARCHIVE4):
    """Every announcer clip of archive 4 in game (sub-file) order:
    (offset, frame_count, sample_rate, word_count).

    Archive 4 is an alSeqFile of 3 sub-files; each sub-file is itself an
    alSeqFile whose entries point straight at a raw (uncompressed container)
    MORT blob, one clip each."""
    _, subs = parse_alseqfile(rom, archive4)
    out = []
    for base, _ in subs:
        _, ents = parse_alseqfile(rom, base)
        for off, size in ents:
            assert rom[off:off + 4] == MORT_MAGIC, hex(off)
            fc, sr, wc = struct.unpack_from(">HHI", rom, off + 4)
            assert wc * 4 == size, (hex(off), wc * 4, size)
            out.append((off, fc, sr, wc))
    return out


def find_mort_chains(rom, start=ARCHIVE4, end=ANN_END):
    """Walk every maximal MORT chain in [start, end), longest first; each is a
    list of (offset, frame_count, sample_rate, word_count) tuples."""
    hits = []
    p = rom.find(MORT_MAGIC, start, end)
    while p >= 0:
        hits.append(p)
        p = rom.find(MORT_MAGIC, p + 4, end)
    hitset = set(hits)
    chains = []
    seen = set()
    for base in hits:
        if base in seen:
            continue
        run = []
        p = base
        while p in hitset:
            fc, sr, wc = struct.unpack_from(">HHI", rom, p + 4)
            nxt = p + wc * 4
            if nxt <= p or nxt > end:
                break
            run.append((p, fc, sr, wc))
            seen.add(p)
            p = nxt
        if run:
            chains.append(run)
    chains.sort(key=lambda r: -len(r))
    return chains


def _selfcheck(baserom="baseroms/us/baserom.z64"):
    rom = open(baserom, "rb").read()
    clips = archive4_clips(rom)
    chains = find_mort_chains(rom)
    # the alSeqFile index and an independent magic chain-walk must agree
    assert sorted(clips) == sorted(c for ch in chains for c in ch), len(clips)
    assert len(clips) == 823, len(clips)
    assert [len(c) for c in chains] == [657, 165, 1], [len(c) for c in chains]
    print("archive 4: %d sub-files, %d clips (index == magic chain-walk)"
          % (len(parse_alseqfile(rom, ARCHIVE4)[1]), len(clips)))

    off, fc, sr, wc = clips[0]
    dec = MortDecoder(rom, off)
    assert (fc, sr, wc) == (157, 16000, 1199), (fc, sr, wc)
    assert dec.size() == wc * 4
    pcm = dec.decode()
    assert len(pcm) == fc * SAMPLES_PER_FRAME, len(pcm)
    assert pcm[:2] == [0, 336], pcm[:2]
    print("first clip @%#x: %d frames, %d Hz, %d words -> %d samples, %.2fs"
          % (off, fc, sr, wc, len(pcm), len(pcm) / sr))

    # encode half: the re-packed fields must decode back to the same samples,
    # and a blob built from scratch must decode to silence
    pcm2, blob = repack(rom, off)
    assert pcm2 == pcm
    assert blob == rom[off:off + wc * 4], "re-packed clip is not byte-identical"
    assert MortDecoder(blob, 0).decode() == pcm
    assert MortDecoder(silence(37), 0).decode() == [0] * (37 * SAMPLES_PER_FRAME)
    print("self-check ok: re-packed clip is %d of %d bytes and decodes back"
          % (len(blob), wc * 4))


if __name__ == "__main__":
    _selfcheck(*sys.argv[1:])
