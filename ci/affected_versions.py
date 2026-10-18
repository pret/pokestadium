#!/usr/bin/env python3
"""Print the ROM versions a set of changed files can affect.

usage: git diff --name-only BASE HEAD | ci/affected_versions.py [--repo-root DIR]

A version is buildable when yamls/<version>/rom.yaml exists. Output is one
version per line; nothing is printed when no build is affected (docs only).
  - files under yamls/, linker_scripts/, baseroms/, asm/, assets/ in a version
    directory affect only that version
  - src/<name>.c affects the versions whose rom.yaml builds <name> from C
  - documentation, COVERAGE.md and editor-only files (.vscode/, .clangd, its workflow,
    .gitignore, compile_flags.txt, the clangd helper and tool unit tests)
    affect nothing: neither the Makefile nor any build tool reads them
  - everything else (Makefile, tools, include, lib, ci, shared linker scripts)
    affects every buildable version
"""
import argparse
import json
import re
import sys
from pathlib import Path

VERSIONED = {"yamls", "linker_scripts", "baseroms", "asm", "assets"}
DOCS = re.compile(
    r"(^docs/|\.md$|^COVERAGE\.md$|^LICENSE"
    r"|^\.vscode/|^\.github/workflows/clangd\.yml$|^\.clangd$|^\.gitignore$|^compile_flags\.txt$"
    r"|^tools/clangd_config\.py$|^tools/test_[^/]*\.py$)"
)
CENTRY = re.compile(r"^\s*-\s*\[0x[0-9A-Fa-f]+,\s*c,\s*([^\],\s]+)", re.MULTILINE)


def buildable(root: Path):
    return sorted(p.parent.name for p in (root / "yamls").glob("*/rom.yaml"))


def known_regions(root: Path):
    path = root / "ci/regions.json"
    regions = json.loads(path.read_text(encoding="utf-8")) if path.exists() else {}
    return {k for k in regions if not k.startswith("_")} | set(buildable(root))


def affected(root: Path, files):
    built = buildable(root)
    known = known_regions(root)
    c_files = {v: set(CENTRY.findall((root / f"yamls/{v}/rom.yaml").read_text(encoding="utf-8"))) for v in built}
    out = set()
    for f in files:
        f = f.strip()
        if not f or DOCS.search(f):
            continue
        parts = f.split("/")
        if parts[0] in VERSIONED and len(parts) > 2 and parts[1] in known:
            if parts[1] in built:
                out.add(parts[1])
        elif parts[0] == "src" and f.endswith(".c"):
            name = re.sub(r"^src/|\.c$", "", f)
            out |= {v for v in built if name in c_files[v]} or ({"us"} & set(built))
        else:
            out |= set(built)
    return sorted(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--repo-root", type=Path, default=Path.cwd())
    args = ap.parse_args()
    for v in affected(args.repo_root.resolve(), sys.stdin.read().splitlines()):
        print(v)


if __name__ == "__main__":
    main()
