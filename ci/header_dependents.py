#!/usr/bin/env python3
"""Header-aware incremental rebuilds for the PR gate.

The baked US baseline is built on macOS without the host syntax check, so it
carries no .d dependency files and make cannot tell which objects a changed
header affects; the gate used to answer with `make -B` (a full rebuild of
every version). This scans #include lines instead:

  changes SRC_INCLUDE WORK_INCLUDE   print include/ files that differ
  touch   WORK_ROOT FILE...          touch every src/include file that
                                     transitively includes one of FILE...
  needs-full FILE...                 exit 0 if any FILE is not a plain .h
                                     (macro.inc, *.inc.c, ...), which this
                                     scan cannot follow

Includes are matched by basename, which over-approximates: an extra file is
rebuilt, a dependent is never missed.
"""

from __future__ import annotations

import filecmp
import os
import re
import sys
from pathlib import Path

INCLUDE_RE = re.compile(r'^\s*#\s*include\s*[<"]([^>"]+)[>"]', re.M)


def changes(src: Path, work: Path) -> list[str]:
    result = set()
    for root, _, files in os.walk(src):
        for name in files:
            rel = (Path(root) / name).relative_to(src)
            if not (work / rel).is_file() or not filecmp.cmp(src / rel, work / rel, shallow=False):
                result.add(rel.as_posix())
    for root, _, files in os.walk(work):
        for name in files:
            rel = (Path(root) / name).relative_to(work)
            if not (src / rel).is_file():
                result.add(rel.as_posix())
    return sorted(result)


def needs_full(files: list[str]) -> bool:
    return any(not f.endswith(".h") or f.endswith(".inc.h") for f in files)


def dependents(work_root: Path, changed: list[str]) -> list[Path]:
    """Return every .c/.h under src/ and include/ that transitively includes a changed file."""
    includes: dict[Path, set[str]] = {}
    for sub in ("src", "include"):
        for path in (work_root / sub).rglob("*"):
            if path.suffix in (".c", ".h") and path.is_file():
                text = path.read_text(encoding="utf-8", errors="replace")
                includes[path] = {Path(m).name for m in INCLUDE_RE.findall(text)}
    dirty = {Path(f).name for f in changed}
    hit: set[Path] = set()
    grew = True
    while grew:
        grew = False
        for path, names in includes.items():
            if path not in hit and names & dirty:
                hit.add(path)
                if path.suffix == ".h":
                    dirty.add(path.name)
                grew = True
    return sorted(hit)


def main(argv: list[str]) -> int:
    if len(argv) >= 4 and argv[1] == "changes":
        print("\n".join(changes(Path(argv[2]), Path(argv[3]))))
        return 0
    if len(argv) >= 2 and argv[1] == "needs-full":
        return 0 if needs_full(argv[2:]) else 1
    if len(argv) >= 4 and argv[1] == "touch":
        root = Path(argv[2])
        paths = [p for p in dependents(root, argv[3:]) if p.suffix == ".c"]
        for path in paths:
            os.utime(path, None)
        print(f"header_dependents: touched {len(paths)} source file(s)")
        return 0
    print(__doc__, file=sys.stderr)
    return 2


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
