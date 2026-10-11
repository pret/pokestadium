#!/usr/bin/env python3
"""Recompute each fragment's in-ROM header from the linker symbols.

Why: the Fragment header (memmap.h) is a `textbin` subsegment, i.e. bytes copied out of the
retail ROM, and the loader trusts it - `Asset_LoadCompressed` copies `sizeInRom` bytes and
`Memmap_RelocateFragment` finds the relocation table at `relocOffset`. Retail values are only
correct while the fragment keeps its retail size, so any change to a fragment's code or data
silently makes the loader read the wrong bytes. Everything needed is already in the linker
script, so recompute it after linking instead of hardcoding it.

  relocOffset = fragment_relocs_ROM_START - fragment_ROM_START
  sizeInRom   = fragment_relocs_ROM_END   - fragment_ROM_START
  sizeInRam   = sizeInRom + fragment_BSS_SIZE - relocs_size

Verified against every retail fragment header: relocOffset 77/77, sizeInRom 77/77,
sizeInRam 75/77.

The header's first word is a hardcoded `j <entry>` (retail bytes too). If code before the
entry function grows, the stub jumps into the middle of whatever now sits at the retail
address. This is what broke the six-icon builds: StadiumSelect_Main moved +0x30..+0x7C, the
stub landed inside StadiumSelect_ConfirmSelection (bogus FREE BATTLE screen) or mid-function
(black-screen freeze). So the jump is retargeted too: the retail target is read from the
baserom, named via symbol_addrs*.txt, and pointed at that symbol's linked address.

usage: fix_fragment_headers.py <elf> <rom> (<fragment> ... | --all)
  (run from the repo root: reads baseroms/us/baserom.z64 and linker_scripts/us/symbol_addrs*.txt)

Size fields are only rewritten for a fragment whose layout moved (relocOffset or sizeInRom
differ): sizeInRam does not fit every retail header (fragment50 and fragment73 differ), so
untouched fragments keep their retail header. A moved fragment that is not in
gen_fragment_relocs.REGEN_SAFE is an error: its reloc table could not follow the move.
"""
import glob
import os
import re
import struct
import subprocess
import sys

HeaderValues = tuple[int, int, int]  # relocOffset, sizeInRom, sizeInRam

HEADER_OFF = {"headerSize": 0x10, "relocOffset": 0x14, "sizeInRom": 0x18, "sizeInRam": 0x1C}
MAGIC_OFF = 0x08


def symbols(elf: str, nm: str = os.environ.get("NM", "mips-linux-gnu-nm")) -> dict[str, int]:
    out = subprocess.run([nm, elf], capture_output=True, text=True, check=True).stdout
    syms = {}
    for line in out.splitlines():
        parts = line.split()
        if len(parts) == 3:
            syms[parts[2]] = int(parts[0], 16)
    return syms


def retail_funcs(paths: list[str] | None = None) -> dict[int, str]:
    """retail address -> function name, from splat's symbol_addrs files"""
    out = {}
    for path in paths or glob.glob("linker_scripts/us/symbol_addrs*.txt"):
        for m in re.finditer(r"^(\w+)\s*=\s*(0x[0-9A-Fa-f]+);.*type:func", open(path).read(), re.M):
            out[int(m.group(2), 16)] = m.group(1)
    return out


def retarget_entry(rom: bytearray, start: int, vram: int, retail_word: int,
                   syms: dict[str, int], funcs: dict[int, str]) -> str | None:
    """-> message, or None when nothing changed. Points the header's `j` at the entry
    function's linked address. retail_word is the stub as retail has it (from the baserom)."""
    if retail_word >> 26 != 2:
        return None
    target = (vram & 0xF0000000) | ((retail_word & 0x3FFFFFF) << 2)
    func = funcs.get(target)
    if func not in syms:
        return f"entry 0x{target:08X} has no linked symbol, jump left as is"
    word = (2 << 26) | ((syms[func] >> 2) & 0x3FFFFFF)
    if struct.unpack_from(">I", rom, start)[0] == word:
        return None
    struct.pack_into(">I", rom, start, word)
    return f"entry j {func} 0x{target:08X}->0x{syms[func]:08X}"


def fragment_names(syms: dict[str, int]) -> list[str]:
    return sorted({m.group(1) for k in syms if (m := re.fullmatch(r"(fragment\d+)_ROM_START", k))})


def fix(rom: bytearray, syms: dict[str, int], name: str
        ) -> tuple[HeaderValues | None, HeaderValues | None, str | None]:
    """-> (values now in the header, values before, message); (None, None, error) if not fixable"""
    try:
        start = syms[f"{name}_ROM_START"]
        relocs_start = syms[f"{name}_relocs_ROM_START"]
        relocs_end = syms[f"{name}_relocs_ROM_END"]
        bss = syms[f"{name}_BSS_SIZE"]
    except KeyError as e:
        return None, None, f"{name}: missing linker symbol {e}"
    reloc_offset = relocs_start - start
    size_in_rom = relocs_end - start
    size_in_ram = size_in_rom + bss - (relocs_end - relocs_start)
    if rom[start + MAGIC_OFF:start + MAGIC_OFF + 8] != b"FRAGMENT":
        return None, None, f"{name}: no FRAGMENT magic at 0x{start:X}, refusing to write"
    old = struct.unpack(">III", rom[start + 0x14:start + 0x20])
    if (reloc_offset, size_in_rom) == old[:2]:
        return old, old, None
    rom[start + 0x14:start + 0x18] = struct.pack(">I", reloc_offset)
    rom[start + 0x18:start + 0x1C] = struct.pack(">I", size_in_rom)
    rom[start + 0x1C:start + 0x20] = struct.pack(">I", size_in_ram)
    return (reloc_offset, size_in_rom, size_in_ram), old, (
        f"{name}: relocOffset 0x{old[0]:X}->0x{reloc_offset:X}  "
        f"sizeInRom 0x{old[1]:X}->0x{size_in_rom:X}  sizeInRam 0x{old[2]:X}->0x{size_in_ram:X}")


def selftest() -> None:
    rom = bytearray(0x100)
    rom[0x00:0x08] = struct.pack(">II", 0x08000020, 0)
    rom[MAGIC_OFF:MAGIC_OFF + 8] = b"FRAGMENT"
    struct.pack_into(">III", rom, 0x14, 0x3440, 0x37F0, 0x3D00)
    syms = {
        "fragment59_ROM_START": 0x00,
        "fragment59_relocs_ROM_START": 0x3440,
        "fragment59_relocs_ROM_END": 0x37F0,
        "fragment59_BSS_SIZE": 0x8C0,
    }
    vals, old, msg = fix(rom, syms, "fragment59")
    assert vals == (0x3440, 0x37F0, 0x3D00), vals
    # grew by 0x80: relocs move, bss stays
    syms["fragment59_relocs_ROM_START"] += 0x80
    syms["fragment59_relocs_ROM_END"] += 0x80
    vals, old, msg = fix(rom, syms, "fragment59")
    assert vals == (0x34C0, 0x3870, 0x3D80), vals
    assert struct.unpack(">III", rom[0x14:0x20]) == vals
    assert len(rom) == 0x100, "header fix must not resize the ROM"
    # a non-fragment region is refused
    bad = bytearray(0x100)
    assert fix(bad, syms, "fragment59")[0] is None
    # entry stub follows its function: retail j StadiumSelect_Main (0x841022C0), Main moved +0x7C
    syms = {"StadiumSelect_Main": 0x8410233C}
    funcs = {0x841022C0: "StadiumSelect_Main"}
    assert retarget_entry(rom, 0, 0x84100000, 0x090408B0, syms, funcs)
    assert struct.unpack_from(">I", rom, 0)[0] == 0x090408CF
    assert retarget_entry(rom, 0, 0x84100000, 0x090408B0, syms, funcs) is None  # idempotent
    print("selftest ok")


if __name__ == "__main__":
    if len(sys.argv) == 2 and sys.argv[1] == "--selftest":
        selftest()
        sys.exit(0)
    elf, rom_path = sys.argv[1], sys.argv[2]
    names = sys.argv[3:]
    if not names:
        sys.exit("give fragment names (e.g. fragment59) or --all - see the docstring")
    from gen_fragment_relocs import REGEN_SAFE
    rom = bytearray(open(rom_path, "rb").read())
    baserom = open("baseroms/us/baserom.z64", "rb").read()
    retail_rom = {m.group(1): int(m.group(2), 16) for m in re.finditer(
        r"^(fragment\d+)_ROM_START\s*=\s*(0x[0-9A-Fa-f]+);", open("linker_scripts/us/symbol_addrs.txt").read(), re.M)}
    syms = symbols(elf)
    funcs = retail_funcs()
    if names == ["--all"]:
        names = fragment_names(syms)
    changed = 0
    for name in names:
        vals, old, msg = fix(rom, syms, name)
        if vals is None:
            print(msg)
            continue
        if vals != old:
            if int(name[len("fragment"):]) not in REGEN_SAFE:
                sys.exit(f"{name} changed size but its reloc table cannot be regenerated "
                         "(not in gen_fragment_relocs.REGEN_SAFE); the ROM would crash on load")
            changed += 1
            print(msg)
        retail_word = struct.unpack_from(">I", baserom, retail_rom[name])[0]
        msg = retarget_entry(rom, syms[f"{name}_ROM_START"], syms[f"{name}_VRAM"], retail_word, syms, funcs)
        if msg and "no linked symbol" in msg and vals == old:
            continue  # fragment did not move, so neither did its entry
        if msg:
            changed += 1
            print(f"{name}: {msg}")
    if changed:
        open(rom_path, "wb").write(rom)
        print(f"patched {changed} fragment header(s) in {rom_path}")
