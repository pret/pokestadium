#!/usr/bin/env python3
"""Apply text/textdata.json to the extracted retail textdata archive.

textdata.bin is a BinArchive: 16-byte header [0][0][total size][file count], then one 16-byte
entry (offset, size, 0, 0) per file, files 16-byte aligned and padded with 0xFF. Each file is
a string table: u32 count, count u32 offsets (relative to the file), NUL-terminated strings.
Text_GetString() resolves `table + offset` at runtime, so a table can be rebuilt freely.

The JSON maps a table number to {string index: text}. An index below the table's count
replaces that string; index == count appends one (indices must stay contiguous). Text is
encoded latin-1, which is how the game stores e.g. the e-acute in POKeMON.

Growing the archive shifts the segments after it (all referenced by symbol) into the 0xFF
padding before the 0x7C0000 pin, so it is safe up to ~145 KB.

usage: patch_textdata.py <textdata.bin> <textdata.json> <out.bin>
       patch_textdata.py --selftest <textdata.bin>
"""
import json
import struct
import sys


def split(blob: bytes) -> list[bytes]:
    n = struct.unpack_from(">I", blob, 12)[0]
    return [blob[o:o + s] for o, s in (struct.unpack_from(">II", blob, 16 + 16 * i) for i in range(n))]


def join(files: list[bytes]) -> bytes:
    head = 16 + 16 * len(files)
    entries, body, off = b"", b"", head
    for f in files:
        entries += struct.pack(">IIII", off, len(f), 0, 0)
        body += f
        off += len(f)
    return struct.pack(">IIII", 0, 0, off, len(files)) + entries + body


def read_table(f: bytes) -> list[bytes]:
    n = struct.unpack_from(">I", f, 0)[0]
    return [f[o:f.index(b"\0", o)] for o in struct.unpack_from(f">{n}I", f, 4)]


def write_table(strings: list[bytes]) -> bytes:
    out = struct.pack(">I", len(strings))
    pos = 4 + 4 * len(strings)
    for s in strings:
        out += struct.pack(">I", pos)
        pos += len(s) + 1
    out += b"".join(s + b"\0" for s in strings)
    return out + b"\xff" * (-len(out) % 16)


def patch(blob: bytes, edits: dict[str, dict[str, str]]) -> bytes:
    files = split(blob)
    for table, strings in edits.items():
        t = int(table, 0)
        table_strings = read_table(files[t])
        for key, text in sorted(strings.items(), key=lambda kv: int(kv[0])):
            idx = int(key)
            if idx > len(table_strings):
                sys.exit(f"table {table}: string {idx} would leave a gap (table has {len(table_strings)})")
            if idx == len(table_strings):
                table_strings.append(b"")
            table_strings[idx] = text.encode("latin-1")
        files[t] = write_table(table_strings)
    return join(files)


def selftest(path: str) -> None:
    blob = open(path, "rb").read()
    assert patch(blob, {}) == blob, "rebuild without edits must be byte-identical"
    files = split(blob)
    assert all(write_table(read_table(files[t])) == files[t] for t in (0x12, 0x13)), "table round trip"
    grown = patch(blob, {"0x13": {"7": "new text", "15": "appended"}})
    t = read_table(split(grown)[0x13])
    assert t[7] == b"new text" and t[15] == b"appended" and len(t) == 16
    assert split(grown)[0x14] == files[0x14], "later files move intact"
    print("selftest ok")


if __name__ == "__main__":
    if sys.argv[1] == "--selftest":
        selftest(sys.argv[2])
        sys.exit(0)
    blob = open(sys.argv[1], "rb").read()
    open(sys.argv[3], "wb").write(patch(blob, json.load(open(sys.argv[2], encoding="utf-8"))))
