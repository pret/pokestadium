#!/usr/bin/env python3
"""Port the US 1.0 splat config and symbol files to another ROM version.

usage: port_version.py <version> [--report]
  (run from the repo root; reads baseroms/us/baserom.z64, baseroms/<version>/baserom.z64,
   yamls/us/*.yaml, linker_scripts/us/* and the US build ELF build/pokestadium-us.elf)

This tool assumes the target has compatible fragment ordering, asset boundaries and
main-code structure. Its alignment is heuristic; generated configs require review
and a target-specific full-ROM identity check. US Rev. 2 has been verified, but that
does not establish support for PAL or Japanese releases. The tool writes:

  yamls/<version>/header.yaml, yamls/<version>/rom.yaml   splat config, US offsets moved
  linker_scripts/<version>/symbol_addrs*.txt              US symbol names at their new addresses
  linker_scripts/<version>/symbol_addrs_version.txt       every named US ELF symbol, moved
  linker_scripts/<version>/{undefined_syms,hardware_regs,unused_syms}.ld

How offsets are found:
  * fragments by their FRAGMENT headers (fragment N is the Nth header in ROM order),
  * code and data inside the main segment and each fragment by aligning the two word
    streams, with relocated fields (jal targets, %hi/%lo immediates, pointers) masked,
  * everything else (misc blobs, assets) by searching for the US bytes around each
    boundary near where the previous boundary moved to.
.bss has no ROM bytes, so bss addresses come from the %hi/%lo pairs of aligned code
(a vote per reference), filled in between votes by keeping the nearest delta.

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
    if op == 0x0F:              # lui: immediate relocated
        return w & 0xFFFF0000
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
        assert len(us_fr) == len(tg_fr), "fragment count differs"
        self.us_fr, self.tg_fr = us_fr, tg_fr
        # fixed: header, boot
        self.romap.add(0, 0, 0x1000)
        # main code
        self.align_region(0x1000, us_fr[0][0], 0x1000, tg_fr[0][0], "main")
        # fragments
        for k, (u, t) in enumerate(zip(us_fr, tg_fr)):
            self.align_region(u[0], u[0] + u[2], t[0], t[0] + t[2], f"fragment{k + 1}")
            self.romap.add(u[0] + u[1], t[0] + t[1], 0)    # reloc table start, from the header
        # gaps between fragments and everything after: search boundaries
        self.place_rest()
        self.romap.finish()
        self.prepare_vram()

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
        self.romap.finish()
        for off in self.all_boundaries():
            if off >= len(self.us):
                self.romap.add(off, len(self.tg), 0, True)
                continue
            if inside(off):
                r = self.romap.lookup(off)
                if r:
                    delta = r[0] - off
                continue
            # aligned (hard ROM address) segments keep their address when the bytes agree
            if self.tg[off:off + 64] == self.us[off:off + 64] and not self.us[off:off + 64].count(b"\xff") == 64 \
                    and not self.us[off:off + 64].count(b"\x00") == 64:
                self.romap.add(off, off, 0, True)
                delta = 0
                continue
            got = self.find_near(off, off + delta)
            if got is None:
                self.romap.add(off, off + delta, 0, False)
                self.notes.append(f"boundary {off:#x}: bytes not found, guessed {off + delta:#x}")
            else:
                self.romap.add(off, got, 0, True)
                delta = got - off
            self.romap.finish()

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
            if v <= A < v + max(u[3], u[2]):
                return k, u, t, v
        return None

    def vram(self, A: int, where: str, quiet: bool = False) -> int | None:
        """US vram (code, data or bss) -> target vram"""
        if A == 0:
            return 0
        f = self.frag_of_vram(A)
        if f:
            k, u, t, v = f
            if A - v < u[1]:      # ROM-backed part of the fragment
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

    def port_yaml(self) -> str:
        out = []
        cur = None          # current top-level segment dict
        seg_iter = iter(self.segs)
        top_start = {}
        for line in self.yaml_text.splitlines():
            m = re.match(r"^  - name:\s*(\S+)", line)
            if m:
                cur = next((s for s in self.segs if isinstance(s, dict) and s.get("name") == m.group(1)), None)
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
            m = re.match(r"^(\s*)(\w+)(\s*=\s*)(0x[0-9A-Fa-f]+)(;.*)$", line)
            if not m:
                out.append(line)
                continue
            A = int(m.group(4), 16)
            B = self.map_any(A, m.group(2))
            if B is None:
                B = A    # outside everything this tool maps (e.g. unused fragments): as in US
            rest = m.group(5)
            rest = re.sub(r"rom:0x([0-9A-Fa-f]+)",
                          lambda mm: f"rom:0x{self.rom(int(mm.group(1), 16), m.group(2)):X}", rest)
            out.append(f"{m.group(1)}{m.group(2)}{m.group(3)}0x{B:08X}{rest}")
        return "\n".join(out) + "\n"

    def map_any(self, A: int, where: str) -> int | None:
        if A >= 0x80000000:
            if 0xA0000000 <= A < 0xC0000000:
                return A          # KSEG1 (boot, hardware)
            return self.vram(A, where, quiet=True)
        # ROM offsets and segmented asset addresses: as the aligned code references them,
        # else ROM offsets through the ROM map (0x01xxxxxx is segment 1, not ROM)
        c = self.votes.get(A)
        if c:
            return c.most_common(1)[0][0]
        if A < 0x01000000:
            r = self.romap.lookup(A)
            return r[0] if r else None
        return A


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
        if name.startswith((".", "$")) or re.search(r"_(ROM|VRAM)_(START|END)$|_(TEXT|DATA|RODATA|BSS)_(START|END|SIZE)$", name):
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


def write(path: str, text: str):
    os.makedirs(os.path.dirname(path), exist_ok=True)
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
    p.run()
    rom_yaml = p.port_yaml()
    header = p.port_header()
    ls_us, ls = f"linker_scripts/{US}", f"linker_scripts/{ver}"
    files = {
        f"yamls/{ver}/header.yaml": header,
        f"yamls/{ver}/rom.yaml": rom_yaml,
    }
    for name in ("symbol_addrs.txt", "symbol_addrs_code.txt", "symbol_addrs_ultralib.txt",
                 "undefined_syms.ld"):
        files[f"{ls}/{name}"] = p.port_symbols(f"{ls_us}/{name}")
    # symbols splat defined automatically for US (ROM offsets, asset offsets, biased
    # bases) that C code names directly; here they would get version-suffixed names
    auto = [f"\n// US auto-defined symbols that sources reference by name ({ver} addresses)."]
    for m in re.finditer(r"^(\w+)\s*=\s*(0x[0-9A-Fa-f]+);", open(f"{ls_us}/auto/undefined_syms_auto.ld").read(), re.M):
        B = p.map_any(int(m.group(2), 16), m.group(1))
        auto.append(f"PROVIDE({m.group(1)} = 0x{(B if B is not None else int(m.group(2), 16)):X});")
    files[f"{ls}/undefined_syms.ld"] += "\n".join(auto) + "\n"
    for name in ("hardware_regs.ld", "unused_syms.ld"):
        files[f"{ls}/{name}"] = open(f"{ls_us}/{name}").read()
    # every named symbol of the US build, so asm in this version uses the names the C uses
    # names and addresses the ported symbol files already cover (splat rejects a second
    # name at the same address). Where a symbol file still has an old name for something
    # the sources have since renamed, the sources' name wins.
    elf = sorted(elf_symbols(os.environ.get("US_ELF", "build/pokestadium-us.elf")), key=lambda t: (t[1], t[0]))
    elf_names = {t[0] for t in elf}
    seen, taken = set(), {}
    for key, text in files.items():
        if key.endswith(".txt"):
            for m in re.finditer(r"^(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", text, re.M):
                seen.add(m.group(1))
                taken[int(m.group(2), 16)] = (key, m.group(1))
    lines = [f"// US 1.0 build symbols at their {ver} addresses (generated by tools/port_version.py)"]
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
            continue
        taken[B] = (None, name)
        typ = " // type:func" if kind in "Tt" else ""
        lines.append(f"{name} = 0x{B:08X};{typ}")
    files[f"{ls}/symbol_addrs_version.txt"] = "\n".join(lines) + "\n"
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
