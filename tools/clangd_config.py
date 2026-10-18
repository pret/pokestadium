#!/usr/bin/env python3
"""Maintain an analysis-only clangd database without running the ROM build."""

import argparse
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import time


ROOT = Path(__file__).resolve().parents[1]
VERSION_FLAGS = {
    "us": ["-DVERSION_US=1"],
    "us_rev1": ["-DVERSION_US=1", "-DVERSION_US_REV1=1"],
    "us_rev2": ["-DVERSION_US=1", "-DVERSION_US_REV2=1"],
    "jp": ["-DVERSION_JP=1"],
    **{version: ["-DVERSION_PAL=1"]
       for version in ("eu", "eu_rev1", "fr", "de", "es", "it")},
}


def source_files(root):
    """Include existing tracked and nonignored new game C files, not tools/libs."""
    result = subprocess.run(
        ["git", "-C", str(root), "ls-files", "--cached", "--others",
         "--exclude-standard", "-z", "--", "src"],
        check=True, capture_output=True, encoding="utf-8",
    )
    sources = sorted({
        name for name in result.stdout.split("\0")
        if name.endswith(".c") and not name.endswith(".inc.c")
        and (root / name).is_file()
    })
    if not sources:
        raise ValueError("No game C translation units found under src/.")
    return sources


def selected_version(root, requested=None):
    """Keep the selected view across automatic watcher restarts."""
    version_file = root / "build/clangd/version.txt"
    if requested is not None:
        version = requested
    elif version_file.exists():
        version = version_file.read_text(encoding="utf-8").strip()
    else:
        version = "us"
    if version not in VERSION_FLAGS:
        raise ValueError(f"Unknown editor version: {version!r}")
    return version


def database_entries(root, version):
    """Use repository-root paths and existing host-analysis flags, not IDO flags."""
    root = root.resolve()
    flags = (root / "compile_flags.txt").read_text(encoding="utf-8").splitlines()
    flags = [flag.strip() for flag in flags if flag.strip()]
    # A single selected preprocessor view is deliberate; clangd does not merge
    # multiple variant commands into one rename analysis.
    arguments = ["clang", *flags, *VERSION_FLAGS[version], "-c"]
    return [
        {"directory": str(root), "file": str(root / source),
         "arguments": [*arguments, str(root / source)]}
        for source in source_files(root)
    ]


def write_if_changed(path, content):
    """Atomically replace changed output; preserve its mtime for symbol edits."""
    if path.exists() and path.read_text(encoding="utf-8") == content:
        return False
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = None
    try:
        with tempfile.NamedTemporaryFile(
                mode="w", encoding="utf-8", newline="\n",
                dir=path.parent, delete=False) as output:
            temporary = Path(output.name)
            output.write(content)
        os.replace(temporary, path)
    finally:
        if temporary is not None and temporary.exists():
            temporary.unlink()
    return True


def refresh_database(root, requested=None, check=False):
    """Return (changed, source count, version); --check never writes files."""
    version = selected_version(root, requested)
    entries = database_entries(root, version)
    content = json.dumps(entries, indent=2) + "\n"
    database = root / "build/clangd/compile_commands.json"
    if check:
        current = database.exists() and database.read_text(encoding="utf-8") == content
        return not current, len(entries), version
    changed = write_if_changed(database, content)
    write_if_changed(root / "build/clangd/version.txt", version + "\n")
    return changed, len(entries), version


def main(argv=None):
    """Generate once, verify freshness, or watch source inventory and flags."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--version", choices=sorted(VERSION_FLAGS))
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument("--check", action="store_true",
                      help="exit 1 if the editor database is missing or stale")
    mode.add_argument("--watch", action="store_true",
                      help="refresh source paths and flags automatically")
    parser.add_argument("--interval", type=float, default=2.0,
                        help="watch polling interval in seconds (default: 2)")
    args = parser.parse_args(argv)
    if not args.interval > 0:
        parser.error("--interval must be positive")
    try:
        changed, count, version = refresh_database(ROOT, args.version, args.check)
        state = "stale" if args.check and changed else "updated" if changed else "current"
        print(f"clangd database {state}: {count} translation units, view={version}",
              flush=True)
        if args.check:
            return int(changed)
        if args.watch:
            while True:
                time.sleep(args.interval)
                # A separate --version invocation can change the selection
                # without an already-running watcher changing it back.
                changed, count, version = refresh_database(ROOT)
                if changed:
                    print(f"clangd database updated: {count} translation units, "
                          f"view={version}", flush=True)
        return 0
    except KeyboardInterrupt:
        return 0
    except (OSError, ValueError, subprocess.SubprocessError) as error:
        print(f"clangd database: {error}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    sys.exit(main())
