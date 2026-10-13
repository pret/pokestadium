#!/usr/bin/env python3
"""Refresh Stadium 1 coverage from tracked GLOBAL_ASM pragmas.

The total function count is the retail-map value recorded in COVERAGE.md; this
script never executes PR code or requires a ROM.
"""
import argparse
import json
import re
from pathlib import Path

PRAGMA = re.compile(r'#pragma GLOBAL_ASM\("asm/us/nonmatchings/[^" ]+/([A-Za-z_]\w*)\.s"\)')
TOTAL = re.compile(r'\*\*[0-9,]+ / ([0-9,]+) \(')
HASM = re.compile(r'^\s*-\s*\[(0x[0-9A-Fa-f]+),\s*hasm(?:,\s*([^\]]+?))?\]\s*(?:#\s*(.*))?$', re.MULTILINE)


def managed_assembly(root: Path):
    segments = []
    for path in sorted((root / "yamls" / "us").rglob("*.yaml")):
        for address, name, comment in HASM.findall(path.read_text(encoding="utf-8")):
            label = (name or comment or "managed assembly").strip()
            segments.append((path.relative_to(root).as_posix(), address, label))
    return segments

CENTRY = re.compile(r'^\s*-\s*\[0x[0-9A-Fa-f]+,\s*c,\s*([^\],\s]+)', re.MULTILINE)
FUNC = re.compile(r'^[A-Za-z_][\w \t\*]*?\b([A-Za-z_]\w*)\s*\([^;{}]*\)\s*\{', re.MULTILINE)
MAX_LISTED_FUNCTIONS = 300
KEYWORDS = {"if", "while", "for", "switch", "return", "sizeof"}


COND = re.compile(r"^\s*#\s*(ifdef|ifndef|if|elif|else|endif)\b(.*)$")
DEFINED = re.compile(r"defined\s*\(\s*(\w+)\s*\)|defined\s+(\w+)")


def _condition(kind: str, rest: str, defines):
    """Truth of one #if/#ifdef/#ifndef/#elif line; None when it cannot be decided."""
    rest = re.sub(r"/\*.*?\*/|//.*", "", rest).strip()
    if kind in ("ifdef", "ifndef"):
        name = rest.split()[0] if rest.split() else ""
        return (name in defines) == (kind == "ifdef")
    expr = DEFINED.sub(lambda m: str((m.group(1) or m.group(2)) in defines), rest)
    expr = re.sub(r"\bVERSION_\w+\b", lambda m: "1" if m.group(0) in defines else "0", expr)
    if re.fullmatch(r"[\s\d()!&|TrueFals]*", expr):
        try:
            return bool(eval(expr.replace("&&", " and ").replace("||", " or ").replace("!", " not "), {"__builtins__": {}}))
        except Exception:
            return None
    return None


def active_pragmas(text: str, defines=frozenset({"VERSION_US"})):
    """GLOBAL_ASM function names that the build for `defines` actually compiles.

    A pragma inside `#if defined(VERSION_US_REV2)` is assembly for Rev. 2 only; the US 1.0 build
    compiles the C in the #else branch, so it is not an open US function. Conditions that cannot
    be decided from the VERSION_* macros count as active.
    """
    names, stack = [], []  # stack of (this branch active, an earlier branch was taken, parent active)
    for line in text.splitlines():
        m = COND.match(line)
        if m:
            kind, rest = m.groups()
            parent = all(a for a, _, _ in stack)
            if kind in ("if", "ifdef", "ifndef"):
                cond = _condition(kind, rest, defines)
                taken = True if cond is None else cond
                stack.append((taken, taken and cond is not None, parent))
            elif kind == "elif" and stack:
                _, done, par = stack[-1]
                cond = _condition("if", rest, defines)
                taken = (not done) and (True if cond is None else cond)
                stack[-1] = (taken, done or (taken and cond is not None), par)
            elif kind == "else" and stack:
                _, done, par = stack[-1]
                stack[-1] = (not done, True, par)
            elif kind == "endif" and stack:
                stack.pop()
            continue
        if all(a for a, _, _ in stack):
            found = PRAGMA.findall(line)
            names.extend(found)
    return names


def c_files(yaml_path: Path):
    return set(CENTRY.findall(yaml_path.read_text(encoding="utf-8")))


def other_versions(root: Path):
    """Shared C files not yet built for each non-US region/revision.

    A version's yaml lists the files it builds from C. Any file the US build
    compiles from C that another version still builds from its own
    disassembly is an open candidate for that version.
    """
    us = c_files(root / "yamls/us/rom.yaml")
    regions_path = root / "ci/regions.json"
    regions = json.loads(regions_path.read_text(encoding="utf-8")) if regions_path.exists() else {}
    versions = {k for k in regions if not k.startswith("_")} | {p.parent.name for p in (root / "yamls").glob("*/rom.yaml")}
    result = {}
    for version in sorted(versions - {"us"}):
        yaml_path = root / "yamls" / version / "rom.yaml"
        started = yaml_path.exists()
        built = c_files(yaml_path) if started else set()
        open_files = {}
        for name in sorted(us - built):
            src = root / "src" / f"{name}.c"
            if not src.exists():
                continue
            text = src.read_text(encoding="utf-8", errors="replace")
            names = PRAGMA.findall(text) or [f for f in FUNC.findall(text) if f not in KEYWORDS]
            open_files[f"src/{name}.c"] = names
        result[version] = (len(us & built), len(us), open_files, started)
    return result


def render(root: Path, baseline: Path) -> str:
    existing = baseline.read_text(encoding="utf-8")
    total_match = TOTAL.search(existing)
    if not total_match:
        raise SystemExit("coverage total missing from baseline")
    total = int(total_match.group(1).replace(",", ""))
    owners = {}
    for path in sorted((root / "src").rglob("*.c")):
        functions = active_pragmas(path.read_text(encoding="utf-8"))
        if functions:
            owners[path.relative_to(root).as_posix()] = functions
    remaining = sum(len(functions) for functions in owners.values()); covered = total - remaining
    managed = managed_assembly(root)
    others = other_versions(root)
    lines = [
        "<!-- Generated by ci/update_coverage.py. Do not edit by hand. -->", "",
        "# pokestadium decompilation coverage", "", "<!-- AUTO_COVERAGE:START -->",
        f"- Functions with C implementations: **{covered:,} / {total:,} ({covered / total * 100:.1f}%)**",
        f"- Remaining decompilable `GLOBAL_ASM` owners: **{remaining:,}** (across {len(owners):,} source files)",
        f"- Separately managed `hasm` assembly segments: **{len(managed):,}**",
    ] + [
        f"- `{v}`{'' if started else ' (not started)'}: **{built:,} / {shared:,}** shared C files built, **{sum(len(f) for f in files.values()):,}** functions open across {len(files):,} files"
        for v, (built, shared, files, started) in others.items()
    ] + [
        "<!-- AUTO_COVERAGE:END -->", "",
        "The function denominator covers C source owners and `GLOBAL_ASM` stubs. `hasm` entries are deliberately managed assembly segments, not unported C-function owners, so they are reported separately and excluded from the decompilation backlog. Total function count is derived from the retail linker map and retained from the trusted baseline. Regenerate with:",
        "`python3 ci/update_coverage.py`", "", "## Remaining owners by source file", "",
        "| File | Remaining owners | Functions |", "| --- | ---: | --- |",
    ]
    lines += [
        f"| `{path}` | {len(functions)} | {', '.join(f'`{name}`' for name in functions)} |"
        for path, functions in owners.items()
    ]
    for v, (built, shared, files, started) in others.items():
        if not started:
            continue
        total_open = sum(len(fn) for fn in files.values())
        names = total_open < MAX_LISTED_FUNCTIONS
        lines += ["", f"## Open candidates for `{v}`", "",
                  f"Shared C files the US build compiles that `{v}` still builds from its own disassembly. Function counts are read from the source and are approximate."
                  + ("" if names else f" Function names are listed once fewer than {MAX_LISTED_FUNCTIONS} remain open."), "",
                  "| File | Open functions |" + (" Functions |" if names else ""), "| --- | ---: |" + (" --- |" if names else "")]
        lines += [f"| `{p}` | {len(fn)} |" + (f" {', '.join(f'`{n}`' for n in fn)} |" if names else "") for p, fn in files.items()]
    lines += ["", "## Separately managed assembly segments", "", "These YAML `hasm` entries are kept as assembly by design and are not counted as `GLOBAL_ASM` decompilation candidates.", "", "| YAML | ROM offset | Segment |", "| --- | ---: | --- |"]
    lines += [f"| `{path}` | `{address}` | `{label}` |" for path, address, label in managed]
    return "\n".join(lines) + "\n"

def main():
    parser = argparse.ArgumentParser(); parser.add_argument("--repo-root", type=Path, default=Path.cwd()); parser.add_argument("--baseline", type=Path); parser.add_argument("--output", type=Path); parser.add_argument("--check", action="store_true")
    args = parser.parse_args(); root = args.repo_root.resolve(); output = args.output or root / "COVERAGE.md"; text = render(root, args.baseline or root / "COVERAGE.md")
    if args.check: return 0 if output.exists() and output.read_text(encoding="utf-8") == text else 1
    output.write_text(text, encoding="utf-8")
    return 0
if __name__ == "__main__": raise SystemExit(main())
