#!/usr/bin/env python3
"""Stage retail dumps for the multi-version ROM gate.

usage: ci/stage_baseroms.py SOURCE_DIR DEST_DIR

Finds every ROM in SOURCE_DIR whose md5 is listed in ci/regions.json and copies
it to DEST_DIR/<version>/baserom.z64, the layout POKESTADIUM_BASEROM_DIR expects
on the runner. Files are matched by content, never by name. Prints which
versions were staged and which are still missing. Nothing is committed anywhere.
"""
import hashlib
import json
import shutil
import sys
from pathlib import Path


def md5(path: Path) -> str:
    h = hashlib.md5()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def main() -> int:
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    src, dest = Path(sys.argv[1]), Path(sys.argv[2])
    regions = json.loads((Path(__file__).parent / "regions.json").read_text())
    wanted = {v["md5"]: k for k, v in regions.items() if not k.startswith("_")}
    staged = set()
    for f in sorted(src.iterdir()):
        if not f.is_file() or f.stat().st_size < 1 << 20:
            continue
        version = wanted.get(md5(f))
        if version and version not in staged:
            out = dest / version / "baserom.z64"
            out.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(f, out)
            staged.add(version)
            print(f"{version}: {f.name}")
    missing = sorted(set(wanted.values()) - staged)
    print("missing:", ", ".join(missing) or "none")
    return 1 if missing else 0


if __name__ == "__main__":
    sys.exit(main())
