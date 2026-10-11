#!/usr/bin/env python3
"""Regenerate a fragment's relocation table from the linked ELF.

Fragment reloc tables are extracted retail bytes pinned in yamls/us/rom.yaml, but the
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

The real check is `--check` against the retail segment: on an unmodified build it must
reproduce the retail table entry for entry. `--selftest` only covers the encoder.

usage:
  gen_fragment_relocs.py <elf> <fragment-number> [--check <segment.bin>] [--write <file>]
  gen_fragment_relocs.py --all <elf>     (the Makefile's post-link step, run from the repo root)
      regenerates every REGEN_SAFE fragment's table in assets/ and deletes its stale object;
      exit 3 when anything changed (relink needed), 0 when all tables are current.
"""

import os
import struct
import sys
from typing import Any

Section = dict[str, Any]   # section header fields, plus "sname" (its name)
Symbol = dict[str, Any]    # "name", "value", "shndx"

# Fragments whose retail table this tool reproduces from a matching build: entry for entry,
# or (22, 27, 34, 43, 55, 57, 61) the same entries in another order that the loader treats
# identically (see equivalent()). The others carry relocs the ELF cannot see (pointers inside
# data still kept as raw blobs), so they keep their retail table and must not change size
# (fix_fragment_headers enforces that). Re-derive after decomp progress with --audit on a
# matching build.
REGEN_SAFE = {5, 22, 25, 26, 27, 29, 30, 32, 33, 34, 35, 36, 37, 38, 40, 43, 48, 49, 51, 52, 53,
              54, 55, 56, 57, 58, 59, 60, 61, 65, 66, 68, 69, 70, 71, 72, 73, 74, 76, 77}

TYPE_NAMES = {2: "R_MIPS_32", 4: "R_MIPS_26", 5: "R_MIPS_HI16", 6: "R_MIPS_LO16"}


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


def build(elf_path: str, frag_no: int | str) -> tuple[list[int], int, int, int]:
    """-> (regenerated entries, external relocs dropped, reloc segment size, bss size)"""
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
        if not (base <= sym["value"] < ram_end):
            dropped += 1
            continue
        if r_type == 10:  # R_MIPS_PC16: branch within the fragment, position-independent
            continue
        if r_type not in TYPE_NAMES:
            raise AssertionError(f"unhandled reloc type {r_type} on {sym['name']}")
        assert base <= r_offset < base + content, f"reloc outside content at {hex(r_offset)}"
        entries.append((r_type << 24) | ((r_offset - base) & 0xFFFFFF))

    # Order matters: the retail table follows the linker's emission order, which is mostly
    # ascending by offset but not strictly so (local hi/lo rotations appear), so sorting
    # would break the match. Keep the ELF's order.
    # The table lives in the fragment's bss space (the loader clears sizeInRam - relocOffset
    # after applying it), so it may grow as long as it fits there. Growing the segment shifts
    # later segments, which is harmless: their reloc offsets are relative to their own start.
    return entries, dropped, seg["size"], (bss["size"] if bss else 0)


def encode(entries: list[int], limit: int) -> bytes:
    out = struct.pack(">I", len(entries)) + b"".join(struct.pack(">I", w) for w in entries)
    assert len(out) <= limit, f"table grew to 0x{len(out):X} > 0x{limit:X}"
    return out


def selftest() -> None:
    enc = encode([(5 << 24) | 0x10, (6 << 24) | 0x10], 12)
    assert len(enc) == 12, len(enc)
    assert struct.unpack_from(">I", enc, 0)[0] == 2          # count
    assert struct.unpack_from(">I", enc, 4)[0] == (5 << 24) | 0x10
    assert struct.unpack_from(">I", enc, 8)[0] == (6 << 24) | 0x10
    try:
        encode([0] * 5, 16)
        raise AssertionError("oversized table must be rejected")
    except AssertionError as e:
        assert "grew to" in str(e)
    hi, lo, w32 = (5 << 24) | 0x10, (6 << 24) | 0x14, (2 << 24) | 0x100
    assert equivalent([w32, hi, lo], [hi, lo, w32]), "32-bit words may move"
    assert not equivalent([hi, lo], [lo, hi]), "hi/lo order matters"
    print("selftest ok")


def merge(entries: list[int], retail_path: str) -> tuple[list[int], list[int], list[int], int]:
    """Regenerated internal relocs plus any retail entry the linker does not emit.

    A retail entry whose offset is below the first regenerated offset sits before the
    fragment's first function, where the decomp's hand-written entry stub lives: it jumps
    to a hardcoded address, so the linker emits no reloc for it, but the retail table has
    one (type 4, offset 0) and the loader applies it. Such entries are layout-independent.

    Every other retail entry is a stale offset from the previous layout and is superseded
    by the regenerated one, so it is dropped rather than carried. A grown fragment yields
    strictly more relocs than the retail table, so the regenerated set covers them.
    """
    retail = open(retail_path, "rb").read()
    n = struct.unpack_from(">I", retail, 0)[0]
    want = [struct.unpack_from(">I", retail, 4 + i * 4)[0] for i in range(n)]
    if not entries:
        return want, want, [], 0
    first = min(w % 0x1000000 for w in entries)
    carried = sorted((w for w in want if (w % 0x1000000) < first), key=lambda w: w % 0x1000000)
    stale = sum(1 for w in want if (w % 0x1000000) >= first)
    return carried + entries, want, carried, stale


def equivalent(a: list[int], b: list[int]) -> bool:
    """Same effect when Memmap_RelocateFragment applies them: R_MIPS_32/26 entries patch one
    word each, independently; HI16/LO16 entries pair through per-register state, so only
    their relative order matters."""
    def canon(t: list[int]) -> tuple[list[int], list[int]]:
        return (sorted(w for w in t if (w >> 24) & 0x7F not in (5, 6)),
                [w for w in t if (w >> 24) & 0x7F in (5, 6)])
    return canon(a) == canon(b)


def table_path(n: int) -> str:
    return f"assets/us/fragments/{n}/fragment{n}_reloc.rodatabin.bin"


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


def update_all(elf: str) -> list[int]:
    """-> list of fragment numbers whose table was rewritten"""
    moved = moved_unsafe(elf)
    if moved:
        sys.exit("code moved inside " + ", ".join(f"fragment{n}" for n in moved) + ", whose reloc table "
                 "cannot be regenerated (not in REGEN_SAFE): the ROM would crash. Keep the change "
                 "byte-neutral (same instructions at the same offsets).")
    changed = []
    for n in sorted(REGEN_SAFE):
        path = table_path(n)
        entries, _, _, bss_size = build(elf, n)
        merged, current, _, _ = merge(entries, path)
        # compare entries, not bytes (retail tables carry trailing padding), and keep the
        # current table when it is only ordered differently, so a matching build stays retail
        if equivalent(merged, current):
            continue
        data = encode(merged, bss_size)
        open(path, "wb").write(data)
        # make does not track the .incbin, so drop the object to force a reassemble
        obj = f"build/asm/us/data/fragments/{n}/fragment{n}_reloc.o"
        if os.path.exists(obj):
            os.remove(obj)
        changed.append(n)
    return changed


def audit(elf: str) -> list[int]:
    """fragments whose current table regenerates exactly; run on a matching build"""
    ok = []
    for n in range(1, 100):
        if not os.path.exists(table_path(n)):
            continue
        try:
            entries = build(elf, n)[0]
        except StopIteration:  # no .rel section: nothing to regenerate from
            continue
        merged, want, _, _ = merge(entries, table_path(n))
        if equivalent(merged, want):
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
    entries, dropped, seg_size, bss_size = build(elf, frag_no)
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
        data = encode(merged, bss_size)
        open(path, "wb").write(data)
        print(f"  wrote {path} ({len(data)} bytes, was {seg_size})")
