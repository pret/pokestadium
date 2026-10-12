#!/usr/bin/env python3
"""Port the US 1.0 splat config and symbol files to another ROM version.

usage: port_version.py <version> [--asm-changed] [--report]
  (run from the repo root; reads baseroms/us/baserom.z64, baseroms/<version>/baserom.z64,
   yamls/us/*.yaml, linker_scripts/us/* and the US build ELF build/pokestadium-us.elf)

The US revisions have the same 78 code fragments in the same order, the same asset files
and the same main code segment, give or take a few changed functions; the other releases
change more (see --asm-changed below), and the Japanese one has no Gallery fragments.
Alignment is heuristic: generated configs need review and a target-specific full-ROM
identity check, and one version's verification does not cover another. This tool finds
where each piece of the US ROM landed in the other ROM and writes:

  yamls/<version>/header.yaml, yamls/<version>/rom.yaml   splat config, US offsets moved
  linker_scripts/<version>/symbol_addrs*.txt              US symbol names at their new addresses
  linker_scripts/<version>/symbol_addrs_version.txt       every named US ELF symbol, moved
  linker_scripts/<version>/{undefined_syms,hardware_regs,unused_syms}.ld

How offsets are found:
  * fragments by their FRAGMENT headers (fragment N is the Nth header in ROM order; when
    the counts differ, by the vram each header jumps to),
  * code and data inside the main segment and each fragment by aligning the two word
    streams, with relocated fields (jal targets, %hi/%lo immediates, pointers) masked,
  * everything else (misc blobs, assets) by searching for the US bytes around each
    boundary near where the previous boundary moved to.
.bss has no ROM bytes, so bss addresses come from the %hi/%lo pairs of aligned code
(a vote per reference), filled in between votes by keeping the nearest delta.

--asm-changed keeps the C only of files that are unchanged and builds everything else from
splat's assembly (for releases that change too much for C edits; see below). C files listed
in yamls/<version>/asm_files.txt are built from assembly regardless.
yamls/<version>/rom_overrides.txt replaces exact generated rom.yaml lines with reviewed
ones, for files built from version-specific C.
--report prints what moved and which functions differ (normalized), without writing files.
"""

from __future__ import annotations

import bisect
import collections
import os
import re
import struct
import subprocess
import sys

import yaml

US = "us"
VERSION_ONLY_MARK = "// ---- version-only symbols"

# ---------------------------------------------------------------------------------------
# word normalisation for alignment

MEM_OPS = {0x09, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x28, 0x29, 0x2A, 0x2B, 0x2E,
           0x31, 0x35, 0x39, 0x3D, 0x0D, 0x0C}  # addiu, loads, stores, lwc1/ldc1/swc1/sdc1, ori, andi
HI_LO_OPS = {0x09, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x28, 0x29, 0x2A, 0x2B, 0x2E,
             0x31, 0x35, 0x39, 0x3D}


def norm_code(w: int) -> int:
    op = w >> 26
    if op in (2, 3):            # j / jal: target relocated
        return op << 26
    if op == 0x0F:              # lui: immediate relocated, unless it can't be an address
        imm = w & 0xFFFF        # (float constants, PAL timing constants stay visible)
        return w & 0xFFFF0000 if 0x7F00 <= imm < 0x9300 or imm < 0x0400 else w
    if op == 0x09 and (w >> 21) & 31 == 0:
        return w                # addiu rt, $zero, constant: not a %lo
    if op in (0x0C, 0x0D, 0x0E):
        return w                # andi / ori / xori: constants in IDO code
    if op in MEM_OPS:           # %lo immediates relocated
        return w & 0xFFFF0000
    return w


def norm_any(w: int) -> int:
    op = w >> 26
    if op in (2, 3, 0x0F) or op in MEM_OPS:
        return norm_code(w)
    return norm_data(w)


def norm_data(w: int) -> int:
    if 0x80000000 <= w < 0x92000000:    # pointers into RAM
        return 0x80000000
    return w


def words(b: bytes) -> list[int]:
    return list(struct.unpack(f">{len(b) // 4}I", b[: len(b) // 4 * 4]))


# ---------------------------------------------------------------------------------------
# alignment of two word streams: greedy, resynchronising on K-grams


def align(a: list[int], b: list[int], K: int = 8, W: int = 4096) -> list[tuple[int, int, int]]:
    """-> equal runs (i, j, n): a[i:i+n] == b[j:j+n], increasing in i and j"""
    runs = []
    i = j = 0
    n, m = len(a), len(b)
    far = None
    K2 = 2 * K
    while i < n and j < m:
        if a[i] == b[j]:
            s_i, s_j = i, j
            while i < n and j < m and a[i] == b[j]:
                i += 1
                j += 1
            runs.append((s_i, s_j, i - s_i))
            continue
        # resync: smallest di + dj with a K-gram match
        wb = min(m, j + W)
        index: dict[tuple, int] = {}
        for q in range(j, max(j, wb - K + 1)):
            index.setdefault(tuple(b[q:q + K]), q)
        best = None
        for di in range(0, min(W, n - i - K + 1)):
            if best is not None and di >= best[0] + best[1]:
                break
            q = index.get(tuple(a[i + di:i + di + K]))
            if q is not None:
                dj = q - j
                if best is None or di + dj < best[0] + best[1]:
                    best = (di, dj)
        if best is None:
            # nothing within the window (a large insertion or rewrite): jump to the next
            # K2-gram of a that occurs exactly once in the rest of b
            if far is None:
                far = collections.defaultdict(list)
                for q in range(0, m - K2 + 1):
                    far[tuple(b[q:q + K2])].append(q)
            for di in range(0, n - i - K2 + 1):
                qs = [q for q in far.get(tuple(a[i + di:i + di + K2]), ()) if q >= j]
                if len(qs) == 1:
                    best = (di, qs[0] - j)
                    break
            if best is None:
                break
        i += best[0]
        j += best[1]
    return runs


class OffsetMap:
    """piecewise map from US offsets to target offsets"""

    def __init__(self):
        self.pts: list[tuple[int, int, int, bool]] = []   # (us, tg, len, exact)

    def add(self, us: int, tg: int, n: int, exact: bool = True):
        self.pts.append((us, tg, n, exact))

    def finish(self):
        self.pts.sort()
        self.keys = [p[0] for p in self.pts]

    def lookup(self, x: int) -> tuple[int, bool] | None:
        k = bisect.bisect_right(self.keys, x) - 1
        if k < 0:
            return None
        us, tg, n, exact = self.pts[k]
        if x == us:
            return tg, exact
        if x < us + n:
            return tg + (x - us), exact
        # in a gap after this run: exact only at the start of the next run
        nxt = self.pts[k + 1] if k + 1 < len(self.pts) else None
        if nxt is not None and nxt[0] == x:
            return nxt[1], nxt[3]
        if nxt is not None:
            gap_us = nxt[0] - (us + n)
            gap_tg = nxt[1] - (tg + n)
            if gap_us == gap_tg:   # same-size replacement: words line up
                return tg + (x - us), True
        return tg + n + (x - us - n), False


# ---------------------------------------------------------------------------------------
# ROM structure


def fragment_headers(rom: bytes) -> list[tuple[int, int, int, int]]:
    """-> [(rom start, relocOffset, sizeInRom, sizeInRam)] in ROM order"""
    out = []
    i = 0
    while True:
        i = rom.find(b"FRAGMENT", i)
        if i < 0:
            break
        st = i - 8
        if st % 16 == 0:
            _, ro, sr, sm = struct.unpack_from(">4I", rom, st + 0x10)
            out.append((st, ro, sr, sm))
        i += 1
    return out


def fragment_vram(rom: bytes, st: int) -> int:
    """the vram a fragment loads at: its header starts with a jump into it"""
    w = struct.unpack_from(">I", rom, st)[0]
    return (0x80000000 | (w & 0x3FFFFFF) << 2) & 0xFFF00000


def load_us_yaml():
    text = open(f"yamls/{US}/rom.yaml").read()
    return text, yaml.safe_load(text)


def seg_list(doc) -> list:
    return doc["segments"] if isinstance(doc, dict) else doc


def sub_entries(seg) -> list[tuple[int, str]]:
    """-> [(rom offset, type)] of a code segment's ROM-backed subsegments"""
    out = []
    for s in seg.get("subsegments", []):
        if isinstance(s, list) and s:
            out.append((s[0], s[1] if len(s) > 1 else "end"))
        elif isinstance(s, dict) and "start" in s:
            out.append((s["start"], s.get("type", "?")))
    return out


TEXT_TYPES = {"c", "asm", "hasm", "textbin", "lib"}


class Porter:
    def __init__(self, version: str):
        self.version = version
        self.us = open(f"baseroms/{US}/baserom.z64", "rb").read()
        self.tg = open(f"baseroms/{version}/baserom.z64", "rb").read()
        self.yaml_text, doc = load_us_yaml()
        self.segs = seg_list(doc)
        self.romap = OffsetMap()
        self.text_ranges: list[tuple[int, int]] = []   # US ROM ranges holding code
        self.code_segs: list[dict] = []    # US code segments with vram
        self.votes: dict[int, collections.Counter] = collections.defaultdict(collections.Counter)
        self.notes: list[str] = []
        self.asm_changed = False
        self.placer: Placer | None = None
        # C files whose code matches US but whose built bytes do not (constants the
        # placement cannot tell apart from addresses): built from assembly here too
        path = f"yamls/{version}/asm_files.txt"
        self.forced_asm = {l.split("#")[0].strip() for l in open(path)} - {""} if os.path.exists(path) else set()
        # libleo's boot code is encrypted in the ROM, and this mode does not encrypt
        self.forced_asm |= {"libleo/bootdisk", "../../src/libleo/bootstrap"}

    # -- segment table -------------------------------------------------------------------

    def classify(self):
        """US ROM ranges that hold text (for normalisation and %hi/%lo voting)"""
        rows = []
        for seg in self.segs:
            if isinstance(seg, dict) and seg.get("type") == "code":
                rows += sub_entries(seg)
        rows.sort()
        for (off, typ), nxt in zip(rows, rows[1:] + [(None, None)]):
            end = nxt[0] if nxt[0] is not None else off
            if typ in TEXT_TYPES and end > off:
                self.text_ranges.append((off, end))
        self.text_starts = [r[0] for r in self.text_ranges]

    def is_text(self, off: int) -> bool:
        k = bisect.bisect_right(self.text_starts, off) - 1
        return k >= 0 and off < self.text_ranges[k][1]

    # -- alignment -------------------------------------------------------------------

    def align_region(self, us0: int, us1: int, tg0: int, tg1: int, label: str):
        a_raw = words(self.us[us0:us1])
        b_raw = words(self.tg[tg0:tg1])
        # Both sides get the same normaliser (the target's code/data split is not known
        # yet): words that decode as relocated code lose their fields, pointers lose theirs.
        b = [norm_any(w) for w in b_raw]
        a2 = [norm_any(w) for w in a_raw]
        runs = align(a2, b)
        same = sum(r[2] for r in runs)
        for i, j, n in runs:
            self.romap.add(us0 + 4 * i, tg0 + 4 * j, 4 * n)
        self.romap.add(us1, tg1, 0)
        if same != len(a2) or len(a2) != len(b):
            self.notes.append(f"{label}: {len(a2) * 4:#x} -> {len(b) * 4:#x} bytes, "
                              f"{(len(a2) - same) * 4:#x} US bytes unaligned")
        self.vote_region(us0, tg0, runs, a_raw, b_raw)
        return runs

    def vote_region(self, us0, tg0, runs, a_raw, b_raw):
        """%hi/%lo pairs and data pointers in aligned words -> address votes"""
        # pair up aligned positions, also same-size gaps between runs
        pairs = []
        prev = None
        for i, j, n in runs:
            if prev is not None:
                pi, pj = prev
                if i - pi == j - pj and 0 < i - pi < 64:
                    pairs += [(pi + t, pj + t) for t in range(i - pi)]
            pairs += [(i + t, j + t) for t in range(n)]
            prev = (i + n, j + n)
        pos_b = dict(pairs)
        for i, j in pairs:
            wa, wb = a_raw[i], b_raw[j]
            if self.is_text(us0 + 4 * i):
                if wa >> 26 == 0x0F and wb >> 26 == 0x0F and (wa >> 16) & 31 == (wb >> 16) & 31:
                    rt = (wa >> 16) & 31
                    regs = {rt}     # registers holding %hi (followed through addu)
                    for t in range(1, 24):
                        ia, jb = i + t, pos_b.get(i + t)
                        if ia >= len(a_raw) or jb is None or jb >= len(b_raw):
                            break
                        xa, xb = a_raw[ia], b_raw[jb]
                        opa = xa >> 26
                        if opa in HI_LO_OPS and (xa >> 21) & 31 in regs:
                            if xb >> 26 != opa or (xb >> 21) & 31 != (xa >> 21) & 31:
                                break
                            A = ((wa & 0xFFFF) << 16) + sx(xa & 0xFFFF)
                            B = ((wb & 0xFFFF) << 16) + sx(xb & 0xFFFF)
                            self.votes[A & 0xFFFFFFFF][B & 0xFFFFFFFF] += 1
                            break
                        if opa == 0 and xa & 0x3F == 0x21 and ((xa >> 21) & 31 in regs or (xa >> 16) & 31 in regs):
                            regs.add((xa >> 11) & 31)     # addu rd, hi, index
                            continue
                        # %hi register redefined?
                        if writes_reg(xa) in regs:
                            regs.discard(writes_reg(xa))
                            if not regs:
                                break
                elif wa >> 26 == 3 and wb >> 26 == 3:
                    A = ((us0 + 4 * i) & 0) | 0x80000000 | ((wa & 0x3FFFFFF) << 2)
                    B = 0x80000000 | ((wb & 0x3FFFFFF) << 2)
                    self.votes[A][B] += 1
            else:
                if 0x80000000 <= wa < 0x92000000 and 0x80000000 <= wb < 0x92000000:
                    self.votes[wa][wb] += 1

    # -- top level ----------------------------------------------------------------------

    def find_near(self, us_off: int, expect: int, span: int = 0x400000, n: int = 64) -> int | None:
        """target offset of the US bytes at us_off, searching around expect"""
        for probe, back in ((self.us[us_off:us_off + n], 0), (self.us[us_off - n:us_off], n),
                            (self.us[us_off:us_off + 16], 0), (self.us[us_off - 16:us_off], 16)):
            if len(probe) < 16 or probe.count(probe[:4]) * 4 == len(probe):
                continue   # padding-like probes match anywhere
            lo = max(0, expect - span)
            hi = min(len(self.tg), expect + span)
            best = None
            k = self.tg.find(probe, lo, hi)
            while k >= 0:
                cand = k + back
                if best is None or abs(cand - expect) < abs(best - expect):
                    best = cand
                k = self.tg.find(probe, k + 1, hi)
            if best is not None:
                return best
        return None

    def run(self):
        self.classify()
        us_fr = fragment_headers(self.us)
        tg_fr = fragment_headers(self.tg)
        if len(us_fr) != len(tg_fr):
            # the Japanese release has no Gallery: pair fragments by the vram their header
            # jumps to, a fragment the target lacks pairs with None
            by_vram = {fragment_vram(self.tg, t[0]): t for t in tg_fr}
            tg_fr = [by_vram.pop(fragment_vram(self.us, u[0]), None) for u in us_fr]
            assert not by_vram, "fragments only in the target"
        self.us_fr, self.tg_fr = us_fr, tg_fr
        self.missing = {k + 1 for k, t in enumerate(tg_fr) if t is None}
        self.missing_ranges = [(u[0], u[0] + u[2]) for u, t in zip(us_fr, tg_fr) if t is None]
        # fixed: header, boot
        self.romap.add(0, 0, 0x1000)
        # main code
        self.align_region(0x1000, us_fr[0][0], 0x1000, tg_fr[0][0], "main")
        # fragments
        for k, (u, t) in enumerate(zip(us_fr, tg_fr)):
            if t is None:
                nxt = next((t2 for t2 in tg_fr[k + 1:] if t2), None)
                self.romap.add(u[0], nxt[0] if nxt else len(self.tg), 0)
                self.notes.append(f"fragment{k + 1} ({fragment_vram(self.us, u[0]):#x}) is not in {self.version}")
                continue
            self.align_region(u[0], u[0] + u[2], t[0], t[0] + t[2], f"fragment{k + 1}")
            self.romap.add(u[0] + u[1], t[0] + t[1], 0)    # reloc table start, from the header
        # gaps between fragments and everything after: search boundaries
        self.place_rest()
        self.romap.finish()
        self.place_yay0_runs()
        self.prepare_vram()
        if self.asm_changed:
            self.place_files()
            self.prepare_vram()    # again, with the votes of the placed files

    def code_blocks(self):
        """-> [(segment, us_start, us_end, tg_start, tg_end)] for main and every fragment"""
        out = []
        for seg in self.segs:
            if not isinstance(seg, dict):
                continue
            if seg.get("name") == "text":
                out.append((seg, 0x1000, self.us_fr[0][0], 0x1000, self.tg_fr[0][0]))
            m = re.fullmatch(r"fragment(\d+)", seg.get("name", ""))
            if m:
                k = int(m.group(1)) - 1
                u, t = self.us_fr[k], self.tg_fr[k]
                if t is None:
                    continue
                out.append((seg, u[0], u[0] + u[1], t[0], t[0] + t[1]))
        return out

    def place_files(self):
        """--asm-changed: place each file by itself (see Placer); its clean pieces vote"""
        self.placer = Placer(self)
        self.new_subs = {}
        lines = self.yaml_text.splitlines()
        blocks = {}
        cur = None
        for i, line in enumerate(lines):
            m = re.match(r"^  - name:\s*(\S+)", line)
            if m:
                cur = m.group(1)
                continue
            if re.match(r"^  \S", line):
                cur = None
            if cur is not None and re.match(r"^\s{4,}- ", line):
                blocks.setdefault(cur, []).append(line)
        for seg, us0, us1, t0, t1 in self.code_blocks():
            self.new_subs[seg["name"]] = self.placer.segment(seg, blocks.get(seg["name"], []), t0, t1, us1)
        self.placer.finish()
        for x in self.placer.pieces:
            if x["clean"]:
                n = (x["end"] - x["us"]) // 4
                self.vote_region(x["us"], x["t"], [(0, 0, n)], words(self.us[x["us"]:x["end"]]),
                                 words(self.tg[x["t"]:x["t"] + 4 * n]))

    def all_boundaries(self) -> list[int]:
        out = set()
        for seg in self.segs:
            if isinstance(seg, list):
                out.add(seg[0])
            elif isinstance(seg, dict):
                if "start" in seg:
                    out.add(seg["start"])
                for off, _ in sub_entries(seg):
                    out.add(off)
        return sorted(out)

    def place_rest(self):
        covered = [(0, 0x1000), (0x1000, self.us_fr[0][0])]
        covered += [(u[0], u[0] + u[2]) for u in self.us_fr]
        self.covered = covered

        def inside(x):
            return any(a <= x < b for a, b in covered)

        delta = 0
        last = 0
        aligned = {s["ld_align_segment_start"] for s in self.segs
                   if isinstance(s, dict) and "ld_align_segment_start" in s}
        self.romap.finish()
        # pass 1: a candidate for every boundary; (us, target or None, weight)
        cands = []
        for off in self.all_boundaries():
            if off >= len(self.us):
                self.romap.add(off, len(self.tg), 0, True)
                continue
            if inside(off):
                r = self.romap.lookup(off)
                if r:
                    delta = r[0] - off
                    last = max(last, r[0])
                    cands.append((off, r[0], 1000, False))
                continue
            # aligned (hard ROM address) segments keep their address when the bytes agree
            if self.tg[off:off + 64] == self.us[off:off + 64] and not self.us[off:off + 64].count(b"\xff") == 64 \
                    and not self.us[off:off + 64].count(b"\x00") == 64:
                cands.append((off, off, 10, True))
                delta = 0
                last = off
                continue
            # code that loads the boundary (a ROM offset in a %hi/%lo pair) says where it is
            c = self.votes.get(off)
            got = c.most_common(1)[0][0] if c else None
            if got is None:
                got = self.find_near(off, off + delta)
            if got is None:
                # the head differs (a count or size field): look a little further in
                for k in (0x100, 0x200, 0x400):
                    g = self.find_near(off + k, off + delta + k)
                    if g is not None and g - k > last and not (off in aligned and (g - k) % 0x1000):
                        got = g - k
                        break
            if got is None and off in aligned:
                got = self.find_aligned(off, off + delta, last)
            if got is not None and (got - off) % 4:
                got = None      # files start word aligned in every release
            cands.append((off, got, 1, True))
            if got is not None:
                delta = got - off
                last = got
        # pass 2: keep the heaviest increasing chain of found targets (a probe that matched
        # far away, or two boundaries on one place, drop out of it)
        found = [i for i, c in enumerate(cands) if c[1] is not None]
        best, prev = {}, {}
        for n, i in enumerate(found):
            best[i], prev[i] = cands[i][2], None
            for j in found[:n]:
                if cands[j][1] <= cands[i][1] and best[j] + cands[i][2] > best[i]:
                    best[i], prev[i] = best[j] + cands[i][2], j
        chain = set()
        i = max(found, key=lambda i: best[i]) if found else None
        while i is not None:
            chain.add(i)
            i = prev[i]
        # two boundaries on one place: the first one is a file the target does not have
        order = sorted(chain)
        for a, b in zip(order, order[1:]):
            if cands[a][1] == cands[b][1] and cands[a][3]:
                chain.discard(a)
        delta = 0
        for i, (off, got, w, new) in enumerate(cands):
            ok = got is not None and i in chain
            if not new:
                if ok:
                    delta = got - off
                continue
            if ok:
                self.romap.add(off, got, 0, True)
                delta = got - off
            else:
                self.romap.add(off, off + delta, 0, False)
                why = "bytes not found" if got is None else f"found at {got:#x}, out of order"
                self.notes.append(f"boundary {off:#x}: {why}, guessed {off + delta:#x}")
        self.romap.finish()

    def place_yay0_runs(self):
        """segments made only of Yay0 bins (gb_tower_roms) hold language-specific files in
        other releases, with another count and other sizes: when their boundaries do not all
        map, take the files the target has, in order, named rom_part_N as in US"""
        self.yay0_subs = {}
        for seg in self.segs:
            if not isinstance(seg, dict):
                continue
            subs = sub_entries(seg)
            bins = [o for o, t in subs if t == "bin"]
            term = len(bins) == len(subs) - 1
            if len(bins) < 2 or len(bins) < len(subs) - 1 \
                    or any(self.us[o:o + 4] != b"Yay0" for o in bins):
                continue
            if all((self.romap.lookup(o) or (0, False))[1] for o, _ in subs):
                continue
            t0 = self.rom(bins[0], seg.get("name"))
            nxt = min((b for b in self.all_boundaries() if b > subs[-1][0] and not self.in_missing(b)), default=None)
            t1 = self.rom(nxt, "next segment") if nxt is not None else len(self.tg)
            starts, p = [], t0
            while 0 <= p < t1 and self.tg[p:p + 4] == b"Yay0":
                starts.append(p)
                p = self.tg.find(b"Yay0", p + 4, t1)
            if not starts:
                self.notes.append(f"{seg['name']}: no Yay0 file at {t0:#x}")
                continue
            end = t1
            while end > starts[-1] and self.tg[end - 1] == 0xFF:
                end -= 1
            end = (end + 3) & ~3
            self.yay0_subs[seg["name"]] = (starts + [end], term)
            self.notes.append(f"{seg['name']}: {t0:#x}-{end:#x}, {len(starts)} Yay0 files here, {len(bins)} in US")

    def find_aligned(self, off: int, expect: int, last: int, align: int = 0x4000) -> int | None:
        """a segment the linker aligns (ld_align_segment_start): the aligned offset nearest
        to expect, after the last placed boundary, that starts with the same 8 bytes, else
        the first one after last where padding ends"""
        head = self.us[off:off + 8]
        lo = max(last + 1, expect - 0x400000)
        for a in (align, 0x1000):   # PAL releases align some of them to 0x1000 only
            cands = [p for p in range((lo + a - 1) // a * a, min(len(self.tg), expect + 0x400000), a)
                     if self.tg[p:p + 8] == head]
            if cands:
                return min(cands, key=lambda p: abs(p - expect))
        for p in range((last + align) // align * align, min(len(self.tg), expect + 0x400000), align):
            before = self.tg[p - 16:p]
            if before.count(before[:1]) == 16 and before[:1] in (b"\x00", b"\xff") and self.tg[p:p + 4] != before[:4]:
                return p
        return None

    # -- vram ---------------------------------------------------------------------------

    def build_vram_map(self):
        """vram windows: [(us_vram_start, us_vram_end, us_rom_start, tg_rom_start-ish)]"""
        self.vwin = []   # (vram0, vram1, rom0, segname)
        for seg in self.segs:
            if not (isinstance(seg, dict) and seg.get("type") == "code" and "vram" in seg):
                continue
            v = seg["vram"]
            if not v:
                continue
            subs = sub_entries(seg)
            if not subs:
                continue
            end = max(o for o, _ in subs)
            self.vwin.append((v, v + (end - seg["start"]), seg["start"], seg))
        self.vwin.sort(key=lambda w: w[0])

    def map_vram(self, A: int) -> tuple[int, str] | None:
        """US vram -> (target vram, how)"""
        for v0, v1, r0, seg in self.vwin:
            if v0 <= A < v1:
                r = self.romap.lookup(r0 + (A - v0))
                tg_start = self.romap.lookup(r0)
                if r and tg_start:
                    return seg["vram"] + (r[0] - tg_start[0]), "rom" if r[1] else "rom~"
        c = self.votes.get(A)
        if c:
            B, n = c.most_common(1)[0]
            return B, "vote"
        return None

    def bss_map(self, A: int, lo: int, hi: int) -> tuple[int, str] | None:
        """US bss address in [lo, hi) -> target, from the nearest vote at or below"""
        c = self.votes.get(A)
        if c:
            return c.most_common(1)[0][0], "vote"
        keys = self.vote_keys
        k = bisect.bisect_right(keys, A) - 1
        while k >= 0 and keys[k] >= lo:
            B = self.votes[keys[k]].most_common(1)[0][0]
            return B + (A - keys[k]), "near"
        return None

    # -- writers ------------------------------------------------------------------------

    def rom(self, off: int, where: str) -> int:
        r = self.romap.lookup(off)
        if r is None:
            raise SystemExit(f"{where}: no mapping for {off:#x}")
        if not r[1]:
            self.notes.append(f"{where}: {off:#x} -> {r[0]:#x} is a guess")
        return r[0]

    def frag_of_vram(self, A: int):
        """-> (k, us header, tg header, vram base) for a fragment containing A (incl. bss)"""
        for k, seg in self.frag_segs.items():
            v = seg["vram"]
            u, t = self.us_fr[k - 1], self.tg_fr[k - 1]
            if t is not None and v <= A < v + max(u[3], u[2]):
                return k, u, t, v
        return None

    def vram(self, A: int, where: str, quiet: bool = False) -> int | None:
        """US vram (code, data or bss) -> target vram"""
        if A == 0:
            return 0
        if self.placer:
            # .bss of a kept file: where the layout put it (the C defines what is inside)
            for u0, u1, v in self.placer.kept_bss:
                if u0 <= A < u1:
                    return v + (A - u0)
        f = self.frag_of_vram(A)
        if f:
            k, u, t, v = f
            if A - v < u[1]:      # ROM-backed part of the fragment
                if self.placer:
                    got = self.placed_vram(A, u[0] + (A - v), v, t[0], quiet)
                    return got if got is not None else self.vote_between(A)
                r = self.romap.lookup(u[0] + (A - v))
                if r is not None and (r[1] or quiet):
                    return v + (r[0] - t[0])
            else:                 # bss: votes, else keep the distance to the bss start/end
                got = self.bss_map(A, v + u[1], v + u[3])
                if got is not None and (got[1] == "vote" or A - v - u[1] > 0):
                    if got[1] == "vote":
                        return got[0]
                    near = got[0]
                    # bss start itself is known exactly
                    return near
                return v + t[1] + (A - v - u[1])
        if 0x80000400 <= A < self.main_bss_end:
            if A < self.main_bss_start:
                if self.placer:
                    return self.placed_vram(A, 0x1000 + (A - 0x80000400), 0x80000400, 0x1000, quiet)
                r = self.romap.lookup(0x1000 + (A - 0x80000400))
                if r is not None and (r[1] or quiet):
                    return 0x80000400 + (r[0] - 0x1000)
            else:
                got = self.bss_map(A, self.main_bss_start, self.main_bss_end)
                if got is not None:
                    return got[0]
                return A + (self.tg_main_bss_start - self.main_bss_start)
        if self.main_bss_end <= A < 0x80400000:     # heap: moves with the end of .bss
            return A + (self.tg_main_bss_end - self.main_bss_end)
        c = self.votes.get(A)
        if c:
            return c.most_common(1)[0][0]
        # biased bases (gGbMemoryMap = a fragment table minus its first index): nearest vote
        k = bisect.bisect_right(self.vote_keys, A)
        for kk in (k, k - 1):
            if 0 <= kk < len(self.vote_keys) and abs(self.vote_keys[kk] - A) < 0x2000:
                key = self.vote_keys[kk]
                return self.votes[key].most_common(1)[0][0] + (A - key)
        if not quiet:
            self.notes.append(f"{where}: no mapping for vram {A:#x}")
        return None

    def vote_between(self, A: int, span: int = 0x100) -> int | None:
        """data the code of this version does not load by itself: the votes just before and
        after it, when they agree on how far it moved"""
        k = bisect.bisect_left(self.vote_keys, A)
        lo = self.vote_keys[k - 1] if k > 0 else None
        hi = self.vote_keys[k] if k < len(self.vote_keys) else None
        if lo is None or hi is None or A - lo > span or hi - A > span:
            return None
        d_lo = self.votes[lo].most_common(1)[0][0] - lo
        d_hi = self.votes[hi].most_common(1)[0][0] - hi
        return A + d_lo if d_lo == d_hi else None

    def us_sections(self) -> list[tuple[int, int, str]]:
        """[(US ROM start, end, C file)] of every ROM-backed section the US link placed, from
        its map: the yaml lists only some of them (a C file's .rodata can sit unlisted
        inside the previous file's piece)"""
        if not hasattr(self, "_us_secs"):
            self._us_secs = []
            path = os.environ.get("US_MAP", "build/pokestadium-us.map")
            for m in re.finditer(r"^ \.(?:text|data|rodata)\s+0x([0-9a-f]+)\s+0x([0-9a-f]+) build/src/(\S+)\.o$",
                                 open(path).read(), re.M):
                v, n = int(m.group(1), 16), int(m.group(2), 16)
                if not n:
                    continue
                r = self.us_vram_to_rom(v)
                if r is not None:
                    self._us_secs.append((r, r + n, m.group(3)))
            self._us_secs.sort()
        return self._us_secs

    def us_section_starts(self) -> dict[tuple[str, str], int]:
        """{(C file, text|data|rodata): US ROM start}, from the US map"""
        if not hasattr(self, "_us_starts"):
            self._us_starts = {}
            path = os.environ.get("US_MAP", "build/pokestadium-us.map")
            for m in re.finditer(r"^ \.(text|data|rodata)\s+0x([0-9a-f]+)\s+0x([0-9a-f]+) build/src/(\S+)\.o$",
                                 open(path).read(), re.M):
                if int(m.group(3), 16):
                    r = self.us_vram_to_rom(int(m.group(2), 16))
                    if r is not None:
                        self._us_starts.setdefault((m.group(4), m.group(1)), r)
        return self._us_starts

    def us_vram_to_rom(self, v: int) -> int | None:
        if 0x80000400 <= v < self.main_bss_start:
            return 0x1000 + (v - 0x80000400)
        f = self.frag_of_vram(v)
        if f and v - f[3] < f[1][1]:
            return f[1][0] + (v - f[3])
        return None

    def us_bss(self) -> dict[str, tuple[int, int]]:
        """C file -> (.bss start, size) in the US build, from its map"""
        if not hasattr(self, "_us_bss"):
            self._us_bss = {}
            path = os.environ.get("US_MAP", "build/pokestadium-us.map")
            for m in re.finditer(r"^ \.bss\s+0x([0-9a-f]+)\s+0x([0-9a-f]+) build/src/(\S+)\.o$",
                                 open(path).read(), re.M):
                if int(m.group(2), 16):
                    self._us_bss[m.group(3)] = (int(m.group(1), 16), int(m.group(2), 16))
        return self._us_bss

    def placed_vram(self, A: int, us_off: int, vbase: int, tg_base: int, quiet: bool) -> int | None:
        """US code/data address -> target, --asm-changed: where its file was placed when the
        file is unchanged, else a vote from aligned code, else a search for its own bytes"""
        r = self.placer.lookup(us_off)
        if r is not None and r[1]:
            return vbase + (r[0] - tg_base)
        c = self.votes.get(A)
        if c:
            return c.most_common(1)[0][0]
        t = self.find_own_bytes(us_off)
        if t is not None:
            return vbase + (t - tg_base)
        return None

    def find_own_bytes(self, us_off: int, n: int = 16) -> int | None:
        """target offset of the normalised words at us_off, when they occur exactly once in
        the target ROM's code (main or the same fragment)"""
        for seg, us0, us1, t0, t1 in self.code_blocks():
            if us0 <= us_off < us1:
                b, idx = self.placer.target_index(t0, t1)
                a = [norm_any(w) for w in words(self.us[us_off:min(us1, us_off + 4 * n)])]
                if len(a) < 4 or all(w == 0 for w in a):
                    return None
                if len(a) < PK:
                    return None
                hits = [q for q in idx.get(tuple(a[:PK]), ()) if b[q:q + len(a)] == a]
                if len(hits) == 1:
                    return t0 + 4 * hits[0]
                return None
        return None

    def prepare_vram(self):
        self.frag_segs = {}
        for seg in self.segs:
            if isinstance(seg, dict):
                m = re.fullmatch(r"fragment(\d+)", seg.get("name", ""))
                if m:
                    self.frag_segs[int(m.group(1))] = seg
        text = next(s for s in self.segs if isinstance(s, dict) and s.get("name") == "text")
        self.main_bss_start = 0x80000400 + (self.us_fr[0][0] - 0x1000)
        self.main_bss_end = self.main_bss_start + text["bss_size"]
        self.tg_main_bss_start = 0x80000400 + (self.tg_fr[0][0] - 0x1000)
        c = self.votes.get(self.main_bss_end)
        self.tg_main_bss_end = c.most_common(1)[0][0] if c else self.tg_main_bss_start + text["bss_size"]
        self.vote_keys = sorted(self.votes)

    def placed_yaml_text(self) -> str:
        """US yaml text with each placed segment's subsegment lines replaced (marked \\x00 so
        port_yaml passes them through)"""
        out = []
        cur = None
        skipping = False
        frag_bss = {}
        for seg, us0, us1, t0, t1 in self.code_blocks():
            m = re.fullmatch(r"fragment(\d+)", seg["name"])
            if m:
                k = int(m.group(1)) - 1
                v = seg["vram"]
                frag_bss[seg["name"]] = (v + self.tg_fr[k][1], v + self.tg_fr[k][3],
                                         v + self.us_fr[k][1], v + self.us_fr[k][3])
            else:
                frag_bss[seg["name"]] = (self.tg_main_bss_start, self.tg_main_bss_end,
                                         self.main_bss_start, self.main_bss_end)
        for line in self.yaml_text.splitlines():
            m = re.match(r"^  - name:\s*(\S+)", line)
            if m:
                cur = m.group(1)
                skipping = False
            elif re.match(r"^  \S", line):
                cur = None
                skipping = False
            if cur in self.new_subs and re.match(r"^\s+subsegments:", line):
                out.append(line)
                for l in self.new_subs[cur]:
                    out.append("\x00" + l)
                lo, hi, us_lo, us_hi = frag_bss[cur]
                for l in self.placer.bss(cur, lo, hi, us_lo, us_hi):
                    out.append("\x00" + l)
                skipping = True
                continue
            if skipping and (re.match(r"^\s{4,}", line) or not line.strip()):
                continue
            out.append(line)
        return "\n".join(out) + "\n"

    def port_yaml(self) -> str:
        out = []
        cur = None          # current top-level segment dict
        seg_iter = iter(self.segs)
        top_start = {}
        skip_subs = None
        text = self.placed_yaml_text() if self.placer else self.yaml_text
        missing = False
        for line in text.splitlines():
            m = re.match(r"^  - name:\s*(\S+)", line)
            if m:
                cur = next((s for s in self.segs if isinstance(s, dict) and s.get("name") == m.group(1)), None)
                missing = cur is not None and "start" in cur and self.in_missing(cur["start"])
            elif re.match(r"^  - ", line):
                mm = re.match(r"^  - \[\s*(0x[0-9A-Fa-f]+)", line)
                missing = bool(mm) and self.in_missing(int(mm.group(1), 16))
            if missing:
                continue
            if line.startswith("\x00"):
                out.append(line[1:])
                continue
            def hx(x):
                return f"0x{x:X}"
            m = re.match(r"^(\s*start:\s*)(0x[0-9A-Fa-f]+|\d+)(.*)$", line)
            if m:
                v = int(m.group(2), 0)
                line = m.group(1) + hx(self.rom(v, f"{cur and cur.get('name')} start")) + m.group(3)
                out.append(line)
                continue
            m = re.match(r"^(\s*ld_align_segment_start:\s*)(0x[0-9A-Fa-f]+)(.*)$", line)
            if m:
                v = int(m.group(2), 0)
                out.append(m.group(1) + hx(self.rom(v, "ld_align")) + m.group(3))
                continue
            m = re.match(r"^(\s*-\s*\[\s*)(0x[0-9A-Fa-f]+|\d+)(.*)$", line)
            if m and cur is not None and cur.get("name") in self.yay0_subs:
                offs, term = self.yay0_subs.pop(cur["name"])
                names = [re.match(r"^,\s*bin,\s*(\S+?)\s*\]", r.group(3)) for r in
                         (re.match(r"^(\s*-\s*\[\s*)(0x[0-9A-Fa-f]+|\d+)(.*)$", ln) for ln in [line])]
                base = re.sub(r"_\d+$", "", names[0].group(1)) if names[0] else "rom_part"
                for i, o in enumerate(offs[:-1]):
                    out.append(f"{m.group(1)}{hx(o)}, bin, {base}_{i}]")
                if term:
                    out.append(f"{m.group(1)}{hx(offs[-1])}]")
                skip_subs = cur["name"]
                continue
            if m and cur is not None and cur.get("name") == skip_subs:
                continue
            if m and self.asm_changed and cur is not None and int(m.group(2), 0) != cur.get("start"):
                v = int(m.group(2), 0)
                r = self.romap.lookup(v)
                if r and not r[1] and re.match(r"^,\s*bin\b", m.group(3)):
                    # a bin the target does not have, or has with other contents and size:
                    # it stays part of the bin before it
                    self.notes.append(f"{line.strip()}: not found, merged into the previous bin")
                    continue
                if r and not r[1] and re.match(r"^\s*\]", m.group(3)):
                    out.append(m.group(1) + hx(self.data_end(v)) + m.group(3))
                    continue
            if m:
                v = int(m.group(2), 0)
                rest = m.group(3)
                # unnamed subsegments are named after their offset, which sources and C code use
                # (src/DDE0.c, _52F6D0_ROM_START); keep the US name
                mm = re.match(r"^,\s*(bin|c|hasm|asm|rodata|data)\s*\]", rest)
                if mm and v < 0x1000000:
                    rest = f", {mm.group(1)}, {v:X}]" + rest[mm.end():]
                out.append(m.group(1) + hx(self.rom(v, line.strip())) + rest)
                continue
            m = re.match(r"^(\s*-\s*\{\s*start:\s*)(0x[0-9A-Fa-f]+)(.*)$", line)
            if m:
                v = int(m.group(2), 0)
                out.append(m.group(1) + hx(self.rom(v, line.strip())) + m.group(3))
                continue
            m = re.match(r"^(\s*-\s*\{.*?vram:\s*)(0x[0-9A-Fa-f]+)(.*)$", line)
            if m:
                v = int(m.group(2), 0)
                nv = self.vram(v, line.strip())
                out.append(m.group(1) + hx(nv if nv is not None else v) + m.group(3))
                continue
            m = re.match(r"^(\s*bss_size:\s*)(0x[0-9A-Fa-f]+)(.*)$", line)
            if m and cur is not None:
                v = int(m.group(2), 0)
                name = cur.get("name", "")
                fm = re.fullmatch(r"fragment(\d+)", name)
                if fm:
                    t = self.tg_fr[int(fm.group(1)) - 1]
                    v = t[3] - t[1]
                elif name == "text":
                    v = self.tg_main_bss_end - self.tg_main_bss_start
                out.append(m.group(1) + hx(v) + m.group(3))
                continue
            m = re.match(r"^(    vram:\s*)(0x[0-9A-Fa-f]+)(.*)$", line)
            if m and cur is not None and int(m.group(2), 0):
                v = int(m.group(2), 0)
                name = cur.get("name", "")
                if name == "heap":
                    v = self.tg_main_bss_end
                elif not re.fullmatch(r"fragment\d+", name) and name != "text":
                    # segments that sit right after a fragment in both ROM and RAM
                    nv = self.follow_vram(cur)
                    if nv is not None:
                        v = nv
                out.append(m.group(1) + hx(v) + m.group(3))
                continue
            out.append(line)
        return "\n".join(out) + "\n"

    def data_end(self, off: int) -> int:
        """the end of the data before the next exactly placed boundary after US off: where the
        0xFF padding before it starts"""
        nxt = min(b for b in self.all_boundaries() if b > off and (self.romap.lookup(b) or (0, False))[1])
        end = self.rom(nxt, "data end")
        while self.tg[end - 1] == 0xFF:
            end -= 1
        return (end + 3) & ~3

    def shared_vram_segment(self, name: str, A: int) -> str | None:
        """the segment of a US symbol whose vram two code segments share"""
        if not hasattr(self, "_shared"):
            bases = collections.Counter(s["vram"] for s in self.segs
                                        if isinstance(s, dict) and s.get("type") == "code" and s.get("vram"))
            self._shared = {v for v, n in bases.items() if n > 1}
            # object -> segment, from the yaml; symbol -> object, from the US map
            self._obj_seg, cur = {}, None
            for line in self.yaml_text.splitlines():
                mm = re.match(r"^  - name:\s*(\S+)", line)
                if mm:
                    cur = mm.group(1)
                mm = re.match(r"^\s+- \[\s*0x[0-9A-Fa-f]+,\s*(?:c|asm|\.data|\.rodata|data|rodata),\s*([\w/]+)", line)
                if mm and cur:
                    self._obj_seg[mm.group(1)] = cur
            self._sym_obj, obj = {}, None
            for line in open(os.environ.get("US_MAP", "build/pokestadium-us.map")).read().splitlines():
                mm = re.match(r"^ \.\w+\s+0x[0-9a-f]+\s+0x[0-9a-f]+ build/src/(\S+)\.o$", line)
                if mm:
                    obj = mm.group(1)
                    continue
                mm = re.match(r"^\s+0x([0-9a-f]+)\s+(\w+)$", line)
                if mm and obj:
                    self._sym_obj.setdefault(mm.group(2), obj)
        if not any(v <= A < v + 0x100000 for v in self._shared):
            return None
        return self._obj_seg.get(self._sym_obj.get(name))

    def in_missing(self, off: int) -> bool:
        """inside a fragment the target does not have"""
        return any(a <= off < b for a, b in self.missing_ranges)

    def follow_vram(self, seg) -> int | None:
        for k, fs in self.frag_segs.items():
            dv = seg["vram"] - fs["vram"]
            if 0 <= dv < 0x1000000 and dv == seg["start"] - fs["start"]:
                return fs["vram"] + (self.rom(seg["start"], "follow") - self.tg_fr[k - 1][0])
        return None

    def port_header(self) -> str:
        text = open(f"yamls/{US}/header.yaml").read()
        sha1 = __import__("hashlib").sha1(self.tg).hexdigest()
        text = re.sub(r"^sha1: .*$", f"sha1: {sha1}", text, flags=re.M)
        text = text.replace("linker_scripts/us/", f"linker_scripts/{self.version}/")
        text = text.replace("baseroms/us/", f"baseroms/{self.version}/")
        text = text.replace("asm_path: asm/us", f"asm_path: asm/{self.version}")
        text = text.replace("asset_path: assets/us", f"asset_path: assets/{self.version}")
        text = text.replace("build_path: build\n", f"build_path: build/{self.version}\n")
        text = text.replace("lib_path: build/lib", f"lib_path: build/{self.version}/lib")
        text = text.replace(f"  symbol_addrs_path:\n",
                            f"  symbol_addrs_path:\n    - linker_scripts/{self.version}/symbol_addrs_version.txt\n", 1)
        # auto-named symbols get a suffix, so they can never alias a US name that moved
        text = text.replace("  platform: n64\n",
                            f"  platform: n64\n  symbol_name_format: $VRAM_{self.version}\n"
                            f"  symbol_name_format_no_rom: $VRAM_{self.version}\n", 1)
        return text

    def port_symbols(self, path: str) -> str:
        out = []
        for line in open(path).read().splitlines():
            m = re.match(r"^(\s*)(\w+(?:\+(?:0x[0-9A-Fa-f]+|\d+))?)(\s*=\s*)(0[xX][0-9A-Fa-f]+)(;.*)$", line)
            if not m:
                out.append(line)
                continue
            A = int(m.group(4), 16)
            if "+" in m.group(2) and self.asm_changed:
                # splat would write it as a label in the assembly this mode generates
                out.append(f"// {line} // name+offset, not a label in {self.version}")
                continue
            if "+" in m.group(2):     # name+offset: moves with the base symbol
                off = int(m.group(2).split("+")[1], 0)
                B = self.map_any(A - off, m.group(2))
                B = None if B is None else B + off
            else:
                B = self.map_any(A, m.group(2))
            if B is None and self.asm_changed:
                out.append(f"// {line} // not found in {self.version}")
                continue
            if B is None:
                B = A    # outside everything this tool maps (e.g. unused fragments): as in US
            rest = m.group(5)
            rest = re.sub(r"rom:0x([0-9A-Fa-f]+)",
                          lambda mm: f"rom:0x{self.rom(int(mm.group(1), 16), m.group(2)):X}", rest)
            if self.asm_changed:
                # sizes would make splat check them against file boundaries that are only
                # approximate in .bss here
                rest = re.sub(r"\s*size:0x[0-9A-Fa-f]+", "", rest)
                # two segments at one vram (unused fragments): name the one the symbol is in,
                # else splat labels the same address in the other one too
                seg = self.shared_vram_segment(m.group(2), A)
                if seg and "segment:" not in rest:
                    rest += f" // segment:{seg}" if "//" not in rest else f" segment:{seg}"
            out.append(f"{m.group(1)}{m.group(2)}{m.group(3)}0x{B:08X}{rest}")
        return "\n".join(out) + "\n"

    def map_any(self, A: int, where: str) -> int | None:
        if A >= 0x80000000:
            if 0xA0000000 <= A < 0xC0000000:
                return A          # KSEG1 (boot, hardware)
            return self.vram(A, where, quiet=True)
        # fragments are paired by their headers (a version can lack some)
        for u, t in zip(self.us_fr, self.tg_fr):
            if A == u[0]:
                return None if t is None else t[0]
        if A < 0x01000000 and self.in_missing(A):
            return None
        # ROM offsets and segmented asset addresses: as the aligned code references them,
        # else ROM offsets through the ROM map (0x01xxxxxx is segment 1, not ROM)
        c = self.votes.get(A)
        if c:
            return c.most_common(1)[0][0]
        if A < 0x01000000:
            r = self.romap.lookup(A)
            return r[0] if r else None
        return A


# ---------------------------------------------------------------------------------------
# --asm-changed: place every US file on its own, build the files that differ from assembly
#
# The PAL and Japanese releases relink the audio library and libultra in another order and
# change many files, so one monotone alignment of a whole segment breaks down there. In this mode each
# subsegment of a code segment is found by itself (K-gram votes on its normalised words);
# a C file (or libultra object) that appears unchanged, every section of it, keeps its C,
# and everything else in the segment becomes assembly or data that splat disassembles, cut
# only where a cut is safe (a known file start that follows a function end).

SECTION_OF = {"c": "text", "asm": "text", "hasm": "text", "textbin": "text", "lib": "text",
              ".data": "data", "data": "data", "databin": "data",
              ".rodata": "rodata", "rodata": "rodata", "rodatabin": "rodata",
              "bin": "bin", "pad": "pad"}
SECTION_ORDER = {"text": 0, "data": 1, "rodata": 2}
PK = 6     # K-gram length (words) for file placement


def parse_sub(line: str) -> dict | None:
    s = line.strip()
    if s.startswith("- ["):
        inner, after = s[3:].split("]", 1)
        toks = [t.strip() for t in inner.split(",")]
        d = {"line": line, "off": int(toks[0], 0) if toks[0] else None, "comment": after.strip()}
        typ = toks[1] if len(toks) > 1 else None
        d["typ"] = typ
        if typ == "lib":
            d["key"] = ("lib", toks[3])
            d["sect"] = SECTION_OF.get(toks[4], "text") if len(toks) > 4 else "text"
        else:
            d["key"] = toks[2] if len(toks) > 2 else None
            d["sect"] = SECTION_OF.get(typ, "end") if typ else "end"
            if d["key"] is None and typ in ("c", "asm", "hasm", "bin", "data", "rodata"):
                d["key"] = f"{d['off']:X}"     # unnamed: named after its US offset
        return d
    if s.startswith("- {"):
        kv = dict(re.findall(r"(\w+):\s*([^,}]+?)\s*(?=,|})", s))
        d = {"line": line, "comment": ""}
        if "start" in kv:
            d["off"] = int(kv["start"], 0)
            d["typ"] = kv.get("type")
            d["key"] = kv.get("name")
            d["sect"] = SECTION_OF.get(kv.get("linker_section_order", kv.get("type")), "data")
            return d
        if "vram" in kv:
            d["off"] = None
            d["vram"] = int(kv["vram"], 0)
            d["typ"] = kv.get("type")
            d["key"] = ("lib", kv["object"]) if kv.get("type") == "lib" else kv.get("name")
            d["sect"] = "bss"
            return d
    return None


def fn_end_before(rom: bytes, t: int) -> bool:
    """a function ends right before t: jr $ra within the last few words, nothing but its
    delay slot and zero padding after it"""
    for k in range(1, 7):
        p = t - 4 * k
        if p < 0:
            return False
        w = struct.unpack_from(">I", rom, p)[0]
        if w == 0x03E00008:
            return k >= 2
        if k >= 2 and w != 0:
            return False
    return False


class Placer:
    def __init__(self, porter: "Porter"):
        self.p = porter
        self.us, self.tg = porter.us, porter.tg
        self.pieces: list[dict] = []   # every placed piece: us, end, t, clean
        self.keys: list[int] = []
        self.idx_cache: dict = {}
        self.pending_bss: dict = {}
        self.kept_bss: list[tuple[int, int, int]] = []   # (US start, US end, target start)

    def target_index(self, t0: int, t1: int):
        key = (t0, t1)
        if key not in self.idx_cache:
            b = [norm_any(w) for w in words(self.tg[t0:t1])]
            idx = collections.defaultdict(list)
            for q in range(len(b) - PK + 1):
                idx[tuple(b[q:q + PK])].append(q)
            self.idx_cache[key] = (b, idx)
        return self.idx_cache[key]

    def place(self, s: int, e: int, t0: int, t1: int, expect: int | None) -> tuple[int | None, bool]:
        """-> (target offset, clean) of US bytes [s, e) inside target [t0, t1)"""
        b, idx = self.target_index(t0, t1)
        a = [norm_any(w) for w in words(self.us[s:e])]
        n = len(a)

        def matches(t):
            q = (t - t0) // 4
            return 0 <= q and q + n <= len(b) and b[q:q + n] == a

        if expect is not None and t0 <= expect and matches(expect):
            return expect, True
        votes = collections.Counter()
        for i in range(0, n - PK + 1):
            qs = idx.get(tuple(a[i:i + PK]))
            if qs and len(qs) == 1:
                votes[qs[0] - i] += 1
        if not votes:
            return None, False
        d, c = votes.most_common(1)[0]
        t = t0 + 4 * d
        if matches(t):
            return t, True
        if c >= 2:
            return t, False
        return None, False

    def segment(self, seg: dict, lines: list[str], t0: int, t1: int, us_end: int) -> list[str]:
        """new subsegment lines for one code segment"""
        subs = [d for d in (parse_sub(l) for l in lines) if d is not None]
        rom_subs = [d for d in subs if d.get("off") is not None]
        bss_subs = [d for d in subs if d["sect"] == "bss"]
        end_marker = any(d["sect"] == "end" for d in rom_subs)
        rom_subs = [d for d in rom_subs if d["sect"] != "end"]
        # a C file's section starts where the US link put it, which the yaml offset (a name)
        # does not always say: a file can have grown since its offset was written
        starts = self.p.us_section_starts()
        for d in rom_subs:
            st = starts.get((d["key"], {"c": "text", ".data": "data", ".rodata": "rodata"}.get(d["typ"])))
            if st is not None and st != d["off"] and abs(st - d["off"]) < 0x1000:
                d["off"] = st
        rom_subs.sort(key=lambda d: d["off"])
        name = seg["name"]
        # place every piece
        prev = None
        for k, d in enumerate(rom_subs):
            s = d["off"]
            e = rom_subs[k + 1]["off"] if k + 1 < len(rom_subs) else us_end
            d["end"] = e
            if e <= s:
                d["t"], d["clean"] = None, False
                continue
            expect = None
            if prev is not None and prev.get("clean") and prev["end"] == s:
                expect = prev["t"] + (prev["end"] - prev["off"])
            if k == 0:
                expect = t0
            d["t"], d["clean"] = self.place(s, e, t0, t1, expect)
            if k == 0 and d["typ"] == "textbin":     # fragment header: always there
                d["t"], d["clean"] = t0, True
            if d["typ"] in ("c", ".data", ".rodata") and d["t"] is not None and (d["t"] - t0) % 16:
                d["clean"] = False      # IDO starts every section of a C file 16-aligned
            prev = d
            if d["t"] is not None:
                self.pieces.append({"us": s, "end": e, "t": d["t"], "clean": d["clean"]})
        # which files keep their source: every ROM piece clean (pads don't count)
        files = collections.defaultdict(list)
        for d in rom_subs:
            if d["typ"] in ("c", "lib", ".data", ".rodata") or d["typ"] == "lib":
                files[d["key"]].append(d)
        # libultra objects always become assembly: the link takes the whole archive, so an
        # object kept from it next to changed ones would define their symbols twice
        keep = {key for key, ds in files.items()
                if not isinstance(key, tuple) and all(x["clean"] or x["end"] <= x["off"] for x in ds)
                and key not in self.p.forced_asm}
        # fixed intervals
        us_secs = [x for x in self.p.us_sections() if x[1] > rom_subs[0]["off"] and x[0] < us_end] if rom_subs else []
        while True:
            fixed = []
            for d in rom_subs:
                if d["sect"] == "pad" or d["end"] <= d["off"] or not d["clean"] or d["key"] in self.p.forced_asm:
                    continue
                if d["typ"] in ("c", ".data", ".rodata", "lib") and d["key"] not in keep:
                    continue
                fixed.append((d["t"], d["t"] + d["end"] - d["off"], d))
            fixed.sort(key=lambda x: x[0])
            ok, last, dropped = [], t0, set()
            for iv in fixed:
                if iv[0] >= last:
                    ok.append(iv)
                    last = iv[1]
                elif iv[2]["key"] in keep:
                    dropped.add(iv[2]["key"])
            # a C file whose sections (US map) lie in a piece that becomes assembly can't be
            # kept either: the piece already holds its bytes
            fixed_ids = {id(x[2]) for x in ok}
            for d in rom_subs:
                if id(d) in fixed_ids or d["end"] <= d["off"]:
                    continue
                for s0, s1, key in us_secs:
                    if s0 < d["end"] and d["off"] < s1 and key in keep:
                        dropped.add(key)
            # a kept file is all or nothing: its object brings every section along
            if not dropped:
                break
            keep -= dropped
        fixed = ok
        # section split points in the target, from the fixed pieces
        def bound(sect_lo, sect_hi):
            ends = [b for a, b, d in fixed if SECTION_ORDER.get(d["sect"], -1) <= SECTION_ORDER[sect_lo]
                    and d["sect"] in SECTION_ORDER]
            starts = [a for a, b, d in fixed if SECTION_ORDER.get(d["sect"], 9) >= SECTION_ORDER[sect_hi]
                      and d["sect"] in SECTION_ORDER]
            lo = max(ends, default=t0)
            hi = min(starts, default=t1)
            cands = sorted(d["t"] for d in rom_subs if d.get("t") is not None and d["sect"] == sect_hi
                           and lo <= d["t"] <= hi and d["t"] % 16 == 0)
            return cands[0] if cands else hi
        text_end = bound("text", "data")
        data_end = max(text_end, bound("data", "rodata"))

        def sect_at(t):
            return "text" if t < text_end else "data" if t < data_end else "rodata"

        # candidates for cuts inside the gaps: pieces not fixed, at their (approximate) start
        fixed_ids = {id(d) for _, _, d in fixed}
        cands = {}
        for d in rom_subs:
            if id(d) in fixed_ids or d.get("t") is None or d["sect"] == "pad":
                continue
            cands.setdefault(d["t"], d)
        out_rom = []    # (t, line)
        used_names = collections.Counter()

        def emit_gap(g0, g1):
            # IDO starts every file's sections on 16 bytes: other cuts are bad guesses
            cuts = sorted({g0, g1, *(t for t in cands if g0 < t < g1 and t % 16 == 0),
                           *(x for x in (text_end, data_end) if g0 < x < g1)})
            pieces = []
            for a, b in zip(cuts, cuts[1:]):
                sect = sect_at(a)
                d = cands.get(a)
                # a cut inside text must follow a function end, else the cut is dropped
                if pieces and sect == "text" and pieces[-1][2] == "text" and not fn_end_before(self.tg, a):
                    pieces[-1][1] = b
                    continue
                if pieces and d is None and pieces[-1][2] == sect:
                    pieces[-1][1] = b
                    continue
                pieces.append([a, b, sect, d])
            for a, b, sect, d in pieces:
                if b - a <= 0x10 and not any(self.tg[a:b]) and d is None:
                    out_rom.append((a, f"    - [0x{a:X}, pad]"))
                    continue
                if d is not None and d["sect"] == sect:
                    base = d["key"]
                    base = f"lib/{base[1]}" if isinstance(base, tuple) else (base or f"{d['off']:X}")
                    if base.startswith(".."):
                        base = f"{name}_{a:X}"
                else:
                    base = f"{name}_{a:X}"
                typ = {"text": "asm", "data": "data", "rodata": "rodata"}[sect]
                used_names[(base, typ)] += 1
                if used_names[(base, typ)] > 1:
                    base = f"{base}_{a:X}"
                out_rom.append((a, f"    - [0x{a:X}, {typ}, {base}]"))

        cur = t0
        for a, b, d in fixed:
            if a > cur:
                emit_gap(cur, a)
            line = d["line"]
            line = re.sub(r"(- \[\s*)0x[0-9A-Fa-f]+", lambda m: f"{m.group(1)}0x{a:X}", line, count=1)
            line = re.sub(r"(start:\s*)0x[0-9A-Fa-f]+", lambda m: f"{m.group(1)}0x{a:X}", line, count=1)
            if re.match(r"^\s*- \[[^,\]]+,\s*(bin|c|hasm|asm|rodata|data)\s*\]", line):
                line = line.replace(f"{d['typ']}]", f"{d['typ']}, {d['off']:X}]", 1)
            out_rom.append((a, line))
            cur = b
        if cur < t1:
            emit_gap(cur, t1)
        out_rom.sort(key=lambda x: x[0])
        out = [l for _, l in out_rom]
        if end_marker:
            out.append(f"    - [0x{t1:X}]")
        self.kept = getattr(self, "kept", set()) | {k for k in keep}
        self.pending_bss[name] = (bss_subs, keep)
        return out

    def bss(self, name: str, lo: int, hi: int, us_lo: int, us_hi: int) -> list[str]:
        """.bss lines of a placed segment (after the votes are in), inside the target's
        [lo, hi). Kept files keep their .bss, at their US size (the C decides it); the
        others become bss pieces that start where the previous piece ends, so the linker's
        layout and splat's agree, and run up to the next file."""
        bss_subs, keep = self.pending_bss.get(name, ([], set()))
        vk = self.p.vote_keys
        ents = []
        us_bss = self.p.us_bss()
        # C files whose .bss the yaml doesn't list (splat links it implicitly): listed here,
        # so the layout below accounts for them
        have = {d["key"] for d in bss_subs}
        extra = [{"key": k, "vram": v, "typ": ".bss", "sect": "bss",
                  "line": f"    - {{vram: 0x{v:08X}, type: .bss, name: {k}}}"}
                 for k, (v, n) in us_bss.items() if us_lo <= v < us_hi and k not in have]
        bss_subs = sorted(bss_subs + extra, key=lambda d: us_bss.get(d["key"], (d["vram"], 0))[0]
                          if isinstance(d["key"], str) else d["vram"])
        for k, d in enumerate(bss_subs):
            # the file's start, from the first voted address inside its US range (where the
            # US link put it: the yaml's .bss vrams only order the files)
            v0 = d["vram"]
            v1 = bss_subs[k + 1]["vram"] if k + 1 < len(bss_subs) else us_hi
            if isinstance(d["key"], str) and d["key"] in us_bss:
                v0, size = us_bss[d["key"]]
                v1 = v0 + size
            elif isinstance(d["key"], str) and d["typ"] == ".bss":
                v1 = v0         # the US link gave this C file no .bss at all
            i = bisect.bisect_left(vk, v0)
            v = None
            if i < len(vk) and vk[i] < v1:
                v = self.p.votes[vk[i]].most_common(1)[0][0] - (vk[i] - v0)
            if v is None:
                v = self.p.vram(d["vram"], d["line"].strip(), quiet=True)
            if v is None or not lo <= v < hi:
                continue
            ents.append([v, d, d["key"] in keep, v1 - v0, v0])
        ents.sort(key=lambda x: x[0])
        # a changed file's .bss that ends up where a kept file's starts is empty here
        ents = [e for k, e in enumerate(ents)
                if e[2] or k + 1 == len(ents) or not (ents[k + 1][2] and ents[k + 1][0] == e[0])]
        out = []
        cursor, prev_kept = lo, True

        def line_for(d, v, kept):
            if d["typ"] == "lib":
                if kept:
                    return re.sub(r"vram:\s*0x[0-9A-Fa-f]+", f"vram: 0x{v:08X}", d["line"])
                return f"    - {{vram: 0x{v:08X}, type: bss, name: lib/{d['key'][1]}}}"
            line = re.sub(r"vram:\s*0x[0-9A-Fa-f]+", f"vram: 0x{v:08X}", d["line"])
            return line if kept else line.replace(".bss", "bss")

        for v, d, kept, size, us_v in ents:
            if kept:
                if v > cursor and prev_kept:
                    out.append(f"    - {{vram: 0x{cursor:08X}, type: bss, name: {name}_bss_{cursor:X}}}")
                elif v < cursor:
                    self.p.notes.append(f"{name}: .bss of {d['key']} expected at {v:#x}, follows at {cursor:#x}")
                    v = cursor
                self.kept_bss.append((us_v, us_v + size, v))
                out.append(line_for(d, v, True))
                cursor, prev_kept = v + size, True
            else:
                v &= ~0xF             # an assembled .bss is 16-aligned, like a C one
                if v <= cursor and not prev_kept and out:
                    continue          # inside the previous piece: merged into it
                v = cursor if prev_kept else v
                out.append(line_for(d, v, False))
                cursor, prev_kept = v, False
        if out and not out[0].count(f"0x{lo:08X}"):
            out.insert(0, f"    - {{vram: 0x{lo:08X}, type: bss, name: {name}_bss_{lo:X}}}")
        return out

    def finish(self):
        self.pieces.sort(key=lambda x: x["us"])
        self.keys = [x["us"] for x in self.pieces]

    def lookup(self, off: int) -> tuple[int, bool] | None:
        k = bisect.bisect_right(self.keys, off) - 1
        if k < 0:
            return None
        x = self.pieces[k]
        if off < x["end"]:
            return x["t"] + (off - x["us"]), x["clean"]
        return None


def sx(v: int) -> int:
    return v - 0x10000 if v & 0x8000 else v


def writes_reg(w: int) -> int | None:
    op = w >> 26
    if op == 0:
        return (w >> 11) & 31
    if op in (0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26):
        return (w >> 16) & 31
    return None


def elf_symbols(elf: str) -> list[tuple[str, int, str]]:
    nm = os.environ.get("NM", "mips-linux-gnu-nm")
    out = subprocess.run([nm, elf], capture_output=True, text=True, check=True).stdout
    syms = []
    for line in out.splitlines():
        parts = line.split()
        if len(parts) != 3 or parts[1] not in "TtDdBbRrWw":
            continue
        val, kind, name = int(parts[0], 16), parts[1], parts[2]
        if name.startswith((".", "$")) or ":" in name or "/" in name or re.search(r"_(ROM|VRAM)_(START|END)$|_(TEXT|DATA|RODATA|BSS)_(START|END|SIZE)$", name):
            continue
        if val < 0x80000000:
            continue
        syms.append((name, val, kind))
    return syms


def changed_functions(p: "Porter", elf: str) -> list[tuple[str, int, int, int | None]]:
    """US functions whose code differs in this version (beyond relocations):
    -> [(name, us vram, us size, target size or None)]"""
    nm = os.environ.get("NM", "mips-linux-gnu-nm")
    out = subprocess.run([nm, "-S", "-n", elf], capture_output=True, text=True, check=True).stdout
    res = []
    for line in out.splitlines():
        parts = line.split()
        if len(parts) != 4 or parts[2] not in "Tt":
            continue
        A, size, name = int(parts[0], 16), int(parts[1], 16), parts[3]
        if size == 0:
            continue
        if 0x80000400 <= A < p.main_bss_start:
            r0 = 0x1000 + (A - 0x80000400)
        else:
            f = p.frag_of_vram(A)
            if not f:
                continue
            r0 = f[1][0] + (A - f[3])
        # covered by one equal run?
        k = bisect.bisect_right(p.romap.keys, r0) - 1
        ok = False
        if k >= 0:
            us, tg, n, exact = p.romap.pts[k]
            ok = us <= r0 and r0 + size <= us + n
        if not ok:
            a = p.romap.lookup(r0)
            b = p.romap.lookup(r0 + size)
            res.append((name, A, size, (b[0] - a[0]) if a and b else None))
    return res


def apply_rom_overrides(version: str, rom_yaml: str) -> str:
    """Apply yamls/<version>/rom_overrides.txt to the generated rom.yaml.

    Some files need version-specific C (an #ifdef VERSION_<X> body) that the
    unchanged-bytes check cannot accept. Each override names one generated line
    exactly and the lines that replace it (each written after "->"). A missing or
    repeated line stops the run, so a regeneration cannot drop reviewed C silently.
    """
    path = f"yamls/{version}/rom_overrides.txt"
    if not os.path.exists(path):
        return rom_yaml
    overrides: list[tuple[str, list[str]]] = []
    for raw in open(path):
        line = raw.split("#")[0].strip()
        if not line:
            continue
        if line.startswith("->"):
            if not overrides:
                sys.exit(f"{path}: replacement line before any generated line")
            overrides[-1][1].append(line[2:].strip())
        else:
            overrides.append((line, []))
    lines = rom_yaml.split("\n")
    for wanted, replacement in overrides:
        hits = [i for i, l in enumerate(lines) if l.strip() == wanted]
        if len(hits) != 1:
            sys.exit(f"{path}: expected one generated line {wanted!r}, found {len(hits)}; "
                     "review the override against the new rom.yaml")
        i = hits[0]
        indent = lines[i][:len(lines[i]) - len(lines[i].lstrip())]
        lines[i:i + 1] = [indent + r for r in replacement]
    return "\n".join(lines)


def write(path: str, text: str):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    # the US files carry stray trailing spaces; generated configs do not need them
    text = "\n".join(line.rstrip() for line in text.split("\n"))
    with open(path, "w") as f:
        f.write(text)


def main():
    ver = sys.argv[1]
    report = "--report" in sys.argv
    if "--changed" in sys.argv:
        p = Porter(ver)
        p.run()
        for name, A, size, tsize in changed_functions(p, os.environ.get("US_ELF", "build/pokestadium-us.elf")):
            print(f"{name} {A:08X} {size:#x} {tsize:#x}" if tsize is not None else f"{name} {A:08X} {size:#x} ?")
        return
    p = Porter(ver)
    p.asm_changed = "--asm-changed" in sys.argv
    p.run()
    rom_yaml = apply_rom_overrides(ver, p.port_yaml())
    header = p.port_header()
    ls_us, ls = f"linker_scripts/{US}", f"linker_scripts/{ver}"
    files = {
        f"yamls/{ver}/header.yaml": header,
        f"yamls/{ver}/rom.yaml": rom_yaml,
    }
    for name in ("symbol_addrs.txt", "symbol_addrs_code.txt", "symbol_addrs_ultralib.txt",
                 "undefined_syms.ld"):
        files[f"{ls}/{name}"] = p.port_symbols(f"{ls_us}/{name}")
    # two US symbols mapped onto one address (bss guesses, merged files): splat rejects the
    # second, so it is dropped (commented out) here
    if p.asm_changed:
        at = {}
        names = {}
        for key in [k for k in files if k.endswith(".txt")]:
            out = []
            for line in files[key].splitlines():
                m = re.match(r"^(\w+)\s*=\s*(0x[0-9A-Fa-f]+);", line)
                if m and "segment:" not in line:
                    B = int(m.group(2), 16)
                    if B in at and at[B] != m.group(1):
                        out.append(f"// {line} // same address as {at[B]} in {ver}")
                        continue
                    if m.group(1) in names and names[m.group(1)] != B:
                        # static functions of the same name in two US objects: as assembly
                        # here they would both be global labels
                        out.append(f"// {line} // second symbol of this name")
                        continue
                    at[B] = m.group(1)
                    names[m.group(1)] = B
                out.append(line)
            files[key] = "\n".join(out) + "\n"
    # symbols splat defined automatically for US (ROM offsets, asset offsets, biased
    # bases) that C code names directly; here they would get version-suffixed names
    auto = [f"\n// US auto-defined symbols that sources reference by name ({ver} addresses)."]
    for m in re.finditer(r"^(\w+)\s*=\s*(0x[0-9A-Fa-f]+);", open(f"{ls_us}/auto/undefined_syms_auto.ld").read(), re.M):
        B = p.map_any(int(m.group(2), 16), m.group(1))
        auto.append(f"PROVIDE({m.group(1)} = 0x{(B if B is not None else int(m.group(2), 16)):X});")
    files[f"{ls}/undefined_syms.ld"] += "\n".join(auto) + "\n"
    for name in ("hardware_regs.ld", "unused_syms.ld"):
        files[f"{ls}/{name}"] = open(f"{ls_us}/{name}").read()
    if p.asm_changed:
        # no libultra archive in the link (its objects are assembly here): nothing to force
        # in, and the absolute boot parameters it defines come from here
        files[f"{ls}/unused_syms.ld"] = "// libultra is built from assembly in this version; no archive members to force in\n"
        files[f"{ls}/undefined_syms.ld"] += (
            "\n// libultra boot parameters (lib/ultralib/src/os/parameters.s), not linked from the archive here\n"
            + "".join(f"{n} = 0x{a:08X};\n" for n, a in (
                ("leoBootID", 0x800001A0), ("osTvType", 0x80000300), ("osRomType", 0x80000304),
                ("osRomBase", 0x80000308), ("osResetType", 0x8000030C), ("osCicId", 0x80000310),
                ("osVersion", 0x80000314), ("osMemSize", 0x80000318), ("osAppNMIBuffer", 0x8000031C))))
    # every named symbol of the US build, so asm in this version uses the names the C uses
    # names and addresses the ported symbol files already cover (splat rejects a second
    # name at the same address). Where a symbol file still has an old name for something
    # the sources have since renamed, the sources' name wins.
    # (not the symbols the linker script defines for each piece: those are layout markers)
    ld_syms = set(re.findall(r"^\s*(\w+) = \.;", open(f"{ls_us}/pokestadium.ld").read(), re.M)) \
        if os.path.exists(f"{ls_us}/pokestadium.ld") else set()
    elf = sorted((s for s in elf_symbols(os.environ.get("US_ELF", "build/pokestadium-us.elf"))
                  if s[0] not in ld_syms), key=lambda t: (t[1], t[0]))
    elf_names = {t[0] for t in elf}
    # file-local symbols the ELF lists as "<object>:<name>" still count as names in use
    nm = os.environ.get("NM", "mips-linux-gnu-nm")
    elf_names |= {l.split()[-1].split(":")[-1] for l in subprocess.run(
        [nm, os.environ.get("US_ELF", "build/pokestadium-us.elf")], capture_output=True, text=True).stdout.splitlines()
        if ":" in l}
    seen, taken = set(), {}
    for key, text in files.items():
        if key.endswith(".txt"):
            for m in re.finditer(r"^(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", text, re.M):
                seen.add(m.group(1))
                taken[int(m.group(2), 16)] = (key, m.group(1))
    lines = [f"// US 1.0 build symbols at their {ver} addresses (generated by tools/port_version.py)"]
    aliases = [f"\n// US names at an address another name has in {ver}"]
    for name, val, kind in elf:
        if name in seen or re.search(r"_VRAM$|_END$|_START$", name):
            continue
        seen.add(name)
        B = p.vram(val, name, quiet=True)
        if B is None:
            continue
        if B in taken:
            key, old = taken[B]
            if key and old not in elf_names:
                files[key] = re.sub(rf"^{old}(\s*=)", rf"{name}\1", files[key], flags=re.M)
                taken[B] = (key, name)
            else:
                # splat takes one name per address; C that uses this one gets it from the link
                aliases.append(f"PROVIDE({name} = 0x{B:08X});")
            continue
        taken[B] = (None, name)
        typ = " // type:func" if kind in "Tt" else ""
        lines.append(f"{name} = 0x{B:08X};{typ}")
    files[f"{ls}/symbol_addrs_version.txt"] = "\n".join(lines) + "\n"
    if p.asm_changed:
        files[f"{ls}/undefined_syms.ld"] += "\n".join(aliases) + "\n"
    for n in p.notes:
        print(n)
    # keep the hand-maintained tail of undefined_syms.ld (symbols only this version has)
    und = f"{ls}/undefined_syms.ld"
    if os.path.exists(und) and VERSION_ONLY_MARK in open(und).read():
        old = open(und).read()
        files[und] += old[old.index(VERSION_ONLY_MARK) - 1:]
    if not report:
        for path, text in files.items():
            write(path, text)
        print(f"wrote {len(files)} files for {ver}")


if __name__ == "__main__":
    main()
