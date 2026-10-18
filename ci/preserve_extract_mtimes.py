#!/usr/bin/env python3
"""Make `make extract` incremental by keeping the mtimes of unchanged output.

`make extract` deletes asm/<v> and assets/<v> and regenerates them, so every
generated file gets a fresh mtime and make then recompiles every object that
depends on one, even when the PR only renamed a few symbols. The gate calls
this after a re-extraction: a regenerated file that is byte-identical to the
copy that was there before gets its old mtime back, so make rebuilds only the
objects whose input really changed.

    preserve_extract_mtimes.py --old OLD_ROOT --root ROOT --version V PATH...

PATH is relative to ROOT (a file or a directory). OLD_ROOT holds a
`cp -a` copy of the same PATHs taken before the extraction.

Two kinds of input change are invisible to make and are handled here:

* `#pragma GLOBAL_ASM("asm/us/...")` pulls a generated .s into a C object
  without an #include, so no .d file lists it. A C file whose referenced .s
  changed (or is new) is touched so it recompiles.
* Generated headers and .inc.c files under assets/<v> are included by C
  sources, but the baked US baseline carries no .d files (see the Makefile's
  RUN_CC_CHECK), so make cannot see the dependency. If any of those changed
  the script exits 3 and the caller falls back to a forced full rebuild.
"""
import argparse
import os
import re
import sys

GLOBAL_ASM_RE = re.compile(rb'GLOBAL_ASM\("(asm/[^"]+)"\)')
INCLUDABLE_SUFFIXES = (".h", ".inc", ".inc.c")


def iter_files(root, rel):
    base = os.path.join(root, rel)
    if os.path.isfile(base):
        yield rel
        return
    for dirpath, _dirs, names in os.walk(base):
        for name in names:
            yield os.path.relpath(os.path.join(dirpath, name), root)


def same_bytes(a, b):
    try:
        if os.path.getsize(a) != os.path.getsize(b):
            return False
        with open(a, "rb") as fa, open(b, "rb") as fb:
            return fa.read() == fb.read()
    except OSError:
        return False


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--old", required=True)
    ap.add_argument("--root", required=True)
    ap.add_argument("--version", required=True)
    ap.add_argument("paths", nargs="+")
    args = ap.parse_args()

    kept = 0
    changed = set()
    includable_changed = False
    for rel_path in args.paths:
        for rel in iter_files(args.root, rel_path):
            new = os.path.join(args.root, rel)
            old = os.path.join(args.old, rel)
            if os.path.isfile(old) and same_bytes(new, old):
                st = os.stat(old)
                os.utime(new, ns=(st.st_atime_ns, st.st_mtime_ns))
                kept += 1
            else:
                changed.add(rel)
                if rel.startswith("assets/") and rel.endswith(INCLUDABLE_SUFFIXES):
                    includable_changed = True

    # asm-processor reads asm/<version>/ whatever version the path names.
    touched = 0
    src_dir = os.path.join(args.root, "src")
    for dirpath, _dirs, names in os.walk(src_dir):
        for name in names:
            if not name.endswith(".c"):
                continue
            path = os.path.join(dirpath, name)
            with open(path, "rb") as f:
                data = f.read()
            for m in GLOBAL_ASM_RE.finditer(data):
                target = m.group(1).decode("utf-8", "replace")
                target = re.sub(r"^asm/[^/]+/", "asm/%s/" % args.version, target)
                if target in changed or not os.path.exists(os.path.join(args.root, target)):
                    os.utime(path, None)
                    touched += 1
                    break

    print(
        "preserve_extract_mtimes: %d unchanged file(s) kept, %d changed/new, "
        "%d C file(s) touched for changed GLOBAL_ASM" % (kept, len(changed), touched),
        file=sys.stderr,
    )
    if includable_changed:
        print("preserve_extract_mtimes: generated includable assets changed", file=sys.stderr)
        return 3
    return 0


if __name__ == "__main__":
    sys.exit(main())
