#!/usr/bin/env python3
"""Regenerate a fragment's relocation table from the linked ELF.

Fragment reloc tables are extracted retail bytes pinned in yamls/<VERSION>/rom.yaml, but the
loader patches the words they point at, so they are layout-dependent: grow the fragment
and every entry is wrong, the fragment corrupts itself and the game hangs. This rebuilds
the table for the current layout.

Format (from Memmap_RelocateFragment):

    struct RelocTable { u32 nRelocations; u32 relocations[]; }
    offset = reloc & 0xFFFFFF          position within the fragment's content
    type   = (reloc & 0x7F000000) >> 24
    only R_MIPS_32 (2), R_MIPS_26 (4), R_MIPS_HI16 (5), R_MIPS_LO16 (6) are handled

Only relocations whose symbol lives inside the fragment are kept: internal references
move with the fragment's runtime base and need fixing up, external ones point at fixed
addresses and are resolved by the linker. --whole-archive means the ELF carries relocs
for every object, so this filter is what takes 485 down to the ~234 retail has.
The battle engine's retail table is the exception: it also relocates every external
address, with bit 31 set (the loader masks it off). A table that has such entries gets
its external relocs regenerated the same way. Only targets in fragment space matter
(Memmap_GetFragmentVaddr leaves any other address alone), so equivalent() ignores the rest.

The real check is `--check` against the retail segment: on an unmodified build it must
reproduce the retail table entry for entry. `--selftest` covers the encoder and
positive/negative relocation-order comparisons, but not an emulator playthrough.

usage:
  gen_fragment_relocs.py <elf> <fragment-number> [--check <segment.bin>] [--write <file>]
  gen_fragment_relocs.py --all <elf>     (the Makefile's post-link step, run from the repo root)
      regenerates every REGEN_SAFE fragment's table in assets/ and deletes its stale object;
      exit 3 when anything changed (relink needed), 0 when all tables are current.
"""
from __future__ import annotations

import functools
import os
import struct
import sys
from typing import Any

Section = dict[str, Any]   # section header fields, plus "sname" (its name)
Symbol = dict[str, Any]    # "name", "value", "shndx"

VERSION = os.environ.get("VERSION", "us")
BUILD_DIR = os.environ.get("BUILD_DIR", "build" if VERSION == "us" else f"build/{VERSION}")

# Fragments whose retail table this tool reproduces from a matching build: entry for entry,
# or (22, 27, 34, 43, 55, 57, 61) the same entries in another order that the loader treats
# identically (see equivalent()). The others carry relocs the ELF cannot see (pointers inside
# data still kept as raw blobs), so they keep their retail table and must not change size
# (fix_fragment_headers enforces that). Re-derive after decomp progress with --audit on a
# matching build.
REGEN_SAFE = {5, 22, 25, 26, 27, 29, 30, 32, 33, 34, 35, 36, 37, 38, 40, 43, 48, 49, 51, 52, 53,
              54, 55, 56, 57, 58, 59, 60, 61, 65, 66, 68, 69, 70, 71, 72, 73, 74, 76, 77}

# Versions that build changed files from assembly, whose pointers splat may keep as plain
# numbers: keep every retail table there.
ASM_VERSIONS = ("eu", "eu_rev1", "fr", "de", "es", "it", "jp")
if VERSION in ASM_VERSIONS:
    REGEN_SAFE = set()
elif VERSION in ("us", "us_rev1", "us_rev2"):
    # Audited on the three US revisions. gb_tower_emulator's data tables are still raw blobs,
    # 41's table feeds one LUI from its LO16s in another order than the linker, and 67 has no
    # relocs at all.
    REGEN_SAFE = set(range(2, 78)) - {1, 41, 67}

EXTERNAL = 0x80000000
HEADER_SIZE = 0x20
FRAGMENT_SPACE = range(0x81000000, 0x90000000)

TYPE_NAMES = {2: "R_MIPS_32", 4: "R_MIPS_26", 5: "R_MIPS_HI16", 6: "R_MIPS_LO16"}


@functools.lru_cache(maxsize=1)
def read_elf(path: str) -> tuple[bytes, list[Section], list[Symbol]]:
    """Minimal ELF reader: section headers and .symtab of the decomp's linked ELF.

    The build only ever links 32-bit big-endian MIPS, so anything else is rejected rather than
    half-parsed.
    """
    data = open(path, "rb").read()
    if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 2 or struct.unpack_from(">H", data, 0x12)[0] != 8:
        sys.exit(f"{path}: not a 32-bit big-endian MIPS ELF")
    e_shoff, = struct.unpack_from(">I", data, 0x20)
    e_shentsize, e_shnum, e_shstrndx = struct.unpack_from(">HHH", data, 0x2E)

    sections = []
    for i in range(e_shnum):
        f = struct.unpack_from(">IIIIIIIIII", data, e_shoff + i * e_shentsize)
        sections.append({"name": f[0], "type": f[1], "addr": f[3], "off": f[4],
                         "size": f[5], "link": f[6], "info": f[7], "align": f[8],
                         "entsize": f[9]})

    shstr = sections[e_shstrndx]
    for sec in sections:
        start = shstr["off"] + sec["name"]
        sec["sname"] = data[start:data.index(b"\x00", start)].decode()

    symtab = next((sec for sec in sections if sec["type"] == 2), None)   # SHT_SYMTAB
    symbols = []
    if symtab:
        strtab = sections[symtab["link"]]
        ent = symtab["entsize"] or 16
        for i in range(symtab["size"] // ent):
            st_name, st_value, _, _, _, st_shndx = struct.unpack_from(">IIIBBH", data, symtab["off"] + i * ent)
            nm = data[strtab["off"] + st_name:strtab["off"] + st_name + 64]
            symbols.append({"name": nm.split(b"\x00")[0].decode("ascii", "replace"),
                            "value": st_value, "shndx": st_shndx})
    return data, sections, symbols


def build(elf_path: str, frag_no: int | str, external: bool = False) -> tuple[list[int], int, int, int]:
    """-> (regenerated entries, external relocs dropped, reloc segment size, bss size)
    external: keep external relocs too, flagged with EXTERNAL (see the module docstring)"""
    data, sections, symbols = read_elf(elf_path)
    frag = next(s for s in sections if s["sname"] == f".fragment{frag_no}")
    rel = next(s for s in sections if s["sname"] == f".rel.fragment{frag_no}")
    seg = next(s for s in sections if s["sname"] == f".fragment{frag_no}_relocs")
    bss = next((s for s in sections if s["sname"] == f".fragment{frag_no}_bss"), None)

    base, content = frag["addr"], frag["size"]
    ram_end = base + content + (bss["size"] if bss else 0)   # sizeInRam covers content + bss

    ent = rel["entsize"] or 8
    entries, dropped = [], 0
    for i in range(rel["size"] // ent):
        r_offset, r_info = struct.unpack_from(">II", data, rel["off"] + i * ent)
        sym_i, r_type = r_info >> 8, r_info & 0xFF
        sym = symbols[sym_i]
        # Only relocations whose symbol lives inside the fragment are regenerated: internal
        # references move with the fragment's runtime base, external ones point at fixed
        # addresses. The retail table's one non-internal entry is handled by merge().
        inside = base <= sym["value"] < ram_end
        if not inside and not external:
            dropped += 1
            continue
        if r_type == 10:  # R_MIPS_PC16: branch within the fragment, position-independent
            continue
        if r_type not in TYPE_NAMES:
            raise AssertionError(f"unhandled reloc type {r_type} on {sym['name']}")
        assert base <= r_offset < base + content, f"reloc outside content at {hex(r_offset)}"
        entries.append((0 if inside else EXTERNAL) | (r_type << 24) | ((r_offset - base) & 0xFFFFFF))

    # Order matters: the retail table follows the linker's emission order, which is mostly
    # ascending by offset but not strictly so (local hi/lo rotations appear), so sorting
    # would break the match. Keep the ELF's order.
    # The table may grow freely, even past the bss (retail fragment37's already is 0x3B8 bytes
    # against 0x100 of bss): Fragment_Register applies it while the block still holds the whole
    # ROM image, and only then shrinks the block to sizeInRam. Growing the segment shifts later
    # segments, which is harmless: their reloc offsets are relative to their own start.
    return entries, dropped, seg["size"], (bss["size"] if bss else 0)


def encode(entries: list[int]) -> bytes:
    return struct.pack(">I", len(entries)) + b"".join(struct.pack(">I", w) for w in entries)


def selftest() -> None:
    enc = encode([(5 << 24) | 0x10, (6 << 24) | 0x10])
    assert len(enc) == 12, len(enc)
    assert struct.unpack_from(">I", enc, 0)[0] == 2          # count
    assert struct.unpack_from(">I", enc, 4)[0] == (5 << 24) | 0x10
    assert struct.unpack_from(">I", enc, 8)[0] == (6 << 24) | 0x10
    hi, lo, w32 = (5 << 24) | 0x10, (6 << 24) | 0x14, (2 << 24) | 0x100
    assert equivalent([w32, hi, lo], [hi, lo, w32]), "32-bit words may move"
    assert not equivalent([hi, lo], [lo, hi]), "hi/lo order matters"
    content = struct.pack(">IIII", 0x3C088100, 0x25081000, 0x3C088101, 0x25088000)
    hi1, lo1, hi2, lo2 = 0x05000000, 0x06000004, 0x05000008, 0x0600000C
    first = [hi1, lo1, hi2, lo2]
    assert equivalent(first, [hi2, lo2, hi1, lo1], content), "independent pairs may move"
    assert not equivalent(first, [hi1, hi2, lo1, lo2], content), "changed pairings must fail"
    assert not equivalent(first, [lo1, hi1, hi2, lo2], content), "unpaired LO must fail"
    assert not equivalent(first, first[:-1], content), "different multisets must fail"
    outside = struct.pack(">II", 0x3C088100, 0x0303ED80)
    assert equivalent([0x02000000, 0x02000004], [0x02000000], outside), "targets outside fragment space change nothing"
    assert relocation_effects([hi1, lo1, hi1], content) is None, "duplicate offsets must fail"
    assert relocation_effects([0x05000010], content) is None, "out-of-range offsets must fail"
    assert relocation_effects([0x05000001], content) is None, "unaligned offsets must fail"
    assert relocation_effects([0x05000004], content) is None, "non-LUI HI must fail"
    # One LUI can feed multiple low words: the final high-word write must agree.
    shared = struct.pack(">III", 0x3C088100, 0x25081000, 0x25088000)
    assert not equivalent(
        [hi1, lo1, 0x06000008], [hi1, 0x06000008, lo1], shared
    ), "different final high-word targets must fail"
    assert equivalent([EXTERNAL | w32], [w32]), "the loader ignores bit 31"
    print("selftest ok")


def merge(entries: list[int], retail_path: str) -> tuple[list[int], list[int], list[int], int]:
    """Regenerated internal relocs plus any retail entry the linker does not emit.

    A retail entry inside the 0x20-byte header belongs to the decomp's hand-written entry
    stub: it jumps to a hardcoded address, so the linker emits no reloc for it, but the
    retail table has one (type 4, offset 0) and the loader applies it. Such entries are
    layout-independent.

    Every other retail entry is a stale offset from the previous layout and is superseded
    by the regenerated one, so it is dropped rather than carried. A grown fragment yields
    strictly more relocs than the retail table, so the regenerated set covers them.
    """
    retail = open(retail_path, "rb").read()
    n = struct.unpack_from(">I", retail, 0)[0]
    want = [struct.unpack_from(">I", retail, 4 + i * 4)[0] for i in range(n)]
    if not entries:
        return want, want, [], 0
    carried = sorted((w for w in want if w % 0x1000000 < HEADER_SIZE), key=lambda w: w % 0x1000000)
    stale = len(want) - len(carried)
    return carried + entries, want, carried, stale


def relocation_effects(entries: list[int], content: bytes) -> dict[int, tuple[int, ...]] | None:
    """Symbolic writes made by the loader, or None for an unsupported ordering.

    Model Memmap_RelocateFragment's saved LUI value/reference per register. Each
    symbolic target is the input to Memmap_GetFragmentVaddr, so equal targets
    yield equal patched immediates at any runtime base. Repeated offsets are
    rejected: they could read instructions already modified by another entry.
    Writes whose target lies outside fragment space change nothing and are left out.
    """
    offsets = [entry & 0xFFFFFF for entry in entries]
    if len(set(offsets)) != len(offsets):
        return None
    saved: dict[int, tuple[int, int]] = {}
    writes: dict[int, tuple[int, ...]] = {}
    for entry, offset in zip(entries, offsets):
        if offset % 4 or offset + 4 > len(content):
            return None
        kind = (entry >> 24) & 0x7F
        word, = struct.unpack_from(">I", content, offset)
        if kind in (2, 4):
            writes[offset] = (kind, ((word << 2) & 0x0FFFFFFC) | 0x80000000 if kind == 4 else word)
        elif kind == 5:
            if word >> 26 != 15:  # LUI
                return None
            saved[(word >> 16) & 31] = (offset, word)
        elif kind == 6:
            register = (word >> 21) & 31
            if register not in saved:
                return None
            high_offset, high_word = saved[register]
            low = word & 0xFFFF
            if low & 0x8000:
                low -= 0x10000
            target = ((high_word << 16) + low) & 0xFFFFFFFF
            writes[high_offset] = (5, target)
            writes[offset] = (6, high_offset, target)
        else:
            return None
    return {offset: w for offset, w in writes.items() if w[-1] in FRAGMENT_SPACE}


def equivalent(a: list[int], b: list[int], content: bytes | None = None) -> bool:
    """Conservative equivalence under Memmap_RelocateFragment.

    Without instruction bytes, preserve HI/LO relative order. With instruction
    bytes, also accept reordered pairs whose symbolic writes and pairings agree.
    The loader masks bit 31 off, so it is ignored.
    """
    a, b = [w & ~EXTERNAL for w in a], [w & ~EXTERNAL for w in b]
    def canon(t: list[int]) -> tuple[list[int], list[int]]:
        return (sorted(w for w in t if (w >> 24) & 0x7F not in (5, 6)),
                [w for w in t if (w >> 24) & 0x7F in (5, 6)])
    if canon(a) == canon(b):
        return True
    if content is None:
        return False
    # Assembly fallbacks can emit independent HI/LO pairs in another order, and a table may
    # carry entries that patch nothing. Keep the retail table when both write identically.
    effects = relocation_effects(a, content)
    return effects is not None and effects == relocation_effects(b, content)


def fragment_content(elf: str, number: int) -> bytes:
    data, sections, _ = read_elf(elf)
    section = next(s for s in sections if s["sname"] == f".fragment{number}")
    return data[section["off"]:section["off"] + section["size"]]


def has_external(path: str) -> bool:
    retail = open(path, "rb").read()
    n = struct.unpack_from(">I", retail, 0)[0]
    return any(struct.unpack_from(">I", retail, 4 + i * 4)[0] & EXTERNAL for i in range(n))


def table_path(n: int) -> str:
    return f"assets/{VERSION}/fragments/{n}/fragment{n}_reloc.rodatabin.bin"


def moved_unsafe(elf: str) -> list[int]:
    """Fragments outside REGEN_SAFE whose code moved. Their retail table also holds relocs the ELF
    cannot see, so it is kept, which is only right while every reloc the ELF *does* see is still
    at its retail offset. A size check alone misses code that moved inside an unchanged total
    size (padding absorbs it)."""
    moved = []
    for n in range(1, 100):
        if n in REGEN_SAFE or not os.path.exists(table_path(n)):
            continue
        try:
            entries = build(elf, n)[0]
        except StopIteration:  # no .rel section to compare
            continue
        _, current, _, _ = merge(entries, table_path(n))
        if not set(entries) <= set(current):
            moved.append(n)
    return moved


def pinned(elf: str, n: int) -> list[str]:
    """Referenced symbols that a linker script assigns inside fragment n. splat lists every
    symbol another segment references in undefined_syms_auto.ld, and that assignment overrides
    the C definition, so the symbol keeps its retail address when the fragment's layout moves.
    Mark them `defined:true` in symbol_addrs."""
    data, sections, symbols = read_elf(elf)
    frag = next(s for s in sections if s["sname"] == f".fragment{n}")
    bss = next((s for s in sections if s["sname"] == f".fragment{n}_bss"), None)
    end = frag["addr"] + frag["size"] + (bss["size"] if bss else 0)
    used = set()
    for sec in sections:
        if sec["type"] == 9:  # SHT_REL
            ent = sec["entsize"] or 8
            used |= {struct.unpack_from(">I", data, sec["off"] + i * ent + 4)[0] >> 8 for i in range(sec["size"] // ent)}
    return [symbols[i]["name"] for i in sorted(used)
            if symbols[i]["shndx"] == 0xFFF1 and frag["addr"] <= symbols[i]["value"] <= end]  # SHN_ABS


def update_all(elf: str) -> list[int]:
    """-> list of fragment numbers whose table was rewritten"""
    # Those versions take relocations from splat's assembly, which writes some fragment-internal
    # addresses as symbols the retail table never relocated; their md5 check covers layout.
    moved = [] if VERSION in ASM_VERSIONS else moved_unsafe(elf)
    if moved:
        sys.exit("code moved inside " + ", ".join(f"fragment{n}" for n in moved) + ", whose reloc table "
                 "cannot be regenerated (not in REGEN_SAFE): the ROM would crash. Keep the change "
                 "byte-neutral (same instructions at the same offsets).")
    changed = []
    for n in sorted(REGEN_SAFE):
        path = table_path(n)
        entries, _, _, _ = build(elf, n, has_external(path))
        merged, current, _, _ = merge(entries, path)
        # compare entries, not bytes (retail tables carry trailing padding), and keep the
        # current table when it is only ordered differently, so a matching build stays retail
        if equivalent(merged, current, fragment_content(elf, n)):
            continue
        pins = pinned(elf, n)
        if pins:
            sys.exit(f"fragment{n} moved, but these stay at their retail address (pinned by a linker "
                     "script): " + ", ".join(pins))
        data = encode(merged)
        open(path, "wb").write(data)
        # make does not track the .incbin, so age the object to force a reassemble. Deleting it
        # instead breaks the relink: GNU Make 3.81 (macOS) treats the nested make's missing
        # object as pruned and never rebuilds it, so ld fails with "cannot find ...o".
        obj = f"{BUILD_DIR}/asm/{VERSION}/data/fragments/{n}/fragment{n}_reloc.o"
        if os.path.exists(obj):
            os.utime(obj, (0, 0))
        changed.append(n)
    return changed


def audit(elf: str) -> list[int]:
    """fragments whose current table regenerates exactly; run on a matching build"""
    ok = []
    for n in range(1, 100):
        if not os.path.exists(table_path(n)):
            continue
        try:
            entries = build(elf, n, has_external(table_path(n)))[0]
        except StopIteration:  # no .rel section: nothing to regenerate from
            continue
        merged, want, _, _ = merge(entries, table_path(n))
        if equivalent(merged, want, fragment_content(elf, n)):
            ok.append(n)
    return ok


if __name__ == "__main__":
    if "--selftest" in sys.argv:
        selftest()
        sys.exit(0)
    if sys.argv[1] == "--audit":
        print(audit(sys.argv[2]))
        sys.exit(0)
    if sys.argv[1] == "--all":
        changed = update_all(sys.argv[2])
        if changed:
            print("regenerated reloc tables:", " ".join(f"fragment{n}" for n in changed))
        sys.exit(3 if changed else 0)
    elf, frag_no = sys.argv[1], sys.argv[2]
    retail_path = sys.argv[3]
    entries, dropped, seg_size, bss_size = build(elf, frag_no, has_external(retail_path))
    print(f".fragment{frag_no}: {len(entries)} relocations regenerated, {dropped} dropped "
          f"(external), segment 0x{seg_size:X}, bss 0x{bss_size:X}")

    merged, want, carried, stale = merge(entries, retail_path)
    for w in carried:
        print(f"  carried over retail-only entry: type={w // 0x1000000} off=0x{w % 0x1000000:X}")
    print(f"  dropped {stale} stale retail entries (superseded by regenerated offsets)")
    print(f"  retail has {len(want)} entries; final table has {len(merged)}; match: {merged == want}")
    if merged != want and stale == 0:
        for i, (a, b) in enumerate(zip(merged, want)):
            if a != b:
                print(f"  first difference at [{i}]: built 0x{a:08X} retail 0x{b:08X}")
                break
        print(f"  count difference: {len(merged) - len(want):+d}")

    if "--write" in sys.argv:
        path = sys.argv[sys.argv.index("--write") + 1]
        data = encode(merged)
        open(path, "wb").write(data)
        print(f"  wrote {path} ({len(data)} bytes, was {seg_size})")
