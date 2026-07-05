# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A work-in-progress **decompilation of Pokemon Stadium (US)** for the N64 — a fork of
[pret/pokestadium](https://github.com/pret/pokestadium). The goal is a *matching* decompilation:
C source that, when compiled with the original toolchain (IDO), produces a byte-identical ROM
(`pokestadium.z64`, `md5: ed1378bc12115f71209a77844965ba50`). Progress is measured by how much
of the ROM has been rewritten from assembly into C. See `ABOUT_AI.md` — this project is
explicitly AI-friendly and its purpose is to complete the understanding/rewriting/documentation
of the existing decompiled C.

A copy of the US 1.0 ROM must be placed at `baseroms/us/baserom.z64` before anything works
(not committed). `make` verifies the build against it via md5.

## Common commands

```bash
make init                 # first-time setup: venv, build tools, extract ROM, snapshot expected/
make                      # (== make rom) build + verify md5 against baserom
make -j$(nproc)           # parallel build
make NON_MATCHING=1       # build without requiring a byte-match (defines NON_MATCHING/AVOID_UB)
make clean                # remove build/ (keeps extracted asm/assets)
make distclean            # full reset (removes build/, asm/, assets/, tool builds)
make setup                # (re)build the C tools under tools/
make extract              # re-run splat + asset extraction

python3 format.py -j      # format all game C (clang-format 14 + clang-tidy); pass files to scope it
python3 progress.py       # print decomp progress (% of .text moved from asm to C)
./diff.py -mwo func_name  # diff a function's built asm vs baserom (asm-differ; needs `make` first)
```

There is also a Rust matching toolkit under `tools/rust/` (built by `make setup` when `cargo`
is present; binaries in `tools/rust/target/release/`). Each mirrors a Python script and is
validated to parity — use either:

```bash
ps-status                 # pending funcs (build-free); --build-aware mirrors progress.py
ps-firstdiff              # first build-vs-expected diff, like tools/first_diff.py
ps-fdiff func_name        # per-function built-vs-baserom asm diff, like ./diff.py -mwo
```

`make init` and `make` are wrappers driven by `make -C tools` and the Python venv (`.venv`).
Requires MIPS binutils on PATH (`mips-linux-gnu-*`) and the pip packages in `requirements.txt`.
On macOS use `gmake` (the Makefile detects this; `make` maps to `gmake`). **macOS build gotcha:**
the system (BSD) `iconv` mis-encodes an ASCII backslash as EUC-JP `0xA1C0` after a multibyte char,
silently corrupting `\n` escapes in Japanese strings and breaking the byte-match — install GNU
libiconv (`brew install libiconv`; the Makefile auto-detects it and warns otherwise). Also build
with `gmake RUN_CC_CHECK=0`: the host-compiler syntax check fails under Apple clang (`-m32` +
`-Wint-conversion` errors) but does not affect ROM output.

There is **no unit-test suite** — the "test" is that `make` reproduces the ROM byte-for-byte.
`diff-init` (part of `make init`) snapshots the current build into `expected/` so `first_diff.py`
and `diff.py` can compare against it.

## How the decomp is structured

- **`src/*.c` / `src/*.h`** — game code. Files are named by their **ROM offset** (e.g. `11BA0.c`,
  `D470.c`), not by feature. Functions and data still awaiting names use address-based identifiers
  (`func_80010FA0`, `D_86002F34`, `unk_D_8690A610`). Renaming these to meaningful names as their
  purpose is understood is the core documentation work.
- **`src/fragments/`, `src/libnaudio/`, `src/libleo/`** — subsystems (numbered overlay fragments,
  N64 audio library, 64DD Leo disk library).
- **`asm/us/`** — disassembly produced by splat. `asm/us/nonmatchings/<file>/<func>.s` holds the
  reference asm for functions not yet decompiled; a function is considered "done" once its
  `nonmatchings` .s no longer exists (see `progress.py`).
- **`GLOBAL_ASM("...")`** in a `.c` file pulls in a not-yet-decompiled function's assembly. The
  build routes only files containing `GLOBAL_ASM` through `tools/asm-processor`. To decompile,
  replace the `GLOBAL_ASM` include with equivalent C and iterate until `diff.py` shows a match.
- **`include/`** — shared headers: `global.h` (umbrella), `functions.h`, `variables.h`, `macros.h`,
  plus N64 SDK headers. Per-file `src/*.h` headers hold that file's structs (with explicit
  `/* offset */` field comments and `// size = 0x..` markers — preserve these).
- **`lib/ultralib`** (submodule-like) and **`lib/libultra`** — the N64 OS/SDK library, built
  separately with the older IDO 5.3 compiler and archived into the ROM.
- **`assets/us/`** — extracted graphics/data (PNGs, bins) turned into `.inc.c`/`.o` at build time.
- **`yamls/us/`** — splat configuration (`header.yaml` + `rom.yaml`) describing the ROM segmentation;
  concatenated into `pokestadium-us.yaml` during `make extract`.
- **`linker_scripts/`** — hand-written and auto-generated (`auto/`) linker scripts driving the ELF
  layout and symbol resolution.

## Build/toolchain specifics that matter when editing

- Compiled with **IDO `cc`** (`tools/ido/<os>/7.1/cc`; some files pinned to 5.3), not GCC. GCC is
  only used as a syntax/warning checker (`RUN_CC_CHECK`). Code must match IDO's codegen quirks, so
  "cleaner" C often breaks the match — verify with `diff.py`, not intuition.
- Per-file overrides live near the bottom of the `Makefile` (`build/src/<file>.o: ...`): specific
  files force `-O0`, `-mips1`, `CC_OLD`, `-trapuv`, disabled loop unrolling, etc. If a newly split
  file won't match, check whether it needs such an override.
- Sources are **EUC-JP** encoded (Japanese text); the build pipes through `iconv`. Keep the encoding.
- Style: 4-space indent, 120 col, attach braces, pointer-left (`Type* x`) — enforced by
  `.clang-format`. `format.py` skips `src/libultra/` (formatter churns it too much). Run it before
  committing C changes.

## Typical decompilation loop

1. Pick a `func_*` still backed by `GLOBAL_ASM` / a `nonmatchings/*.s` file.
2. Write C to replace it; build (`make`, or `make NON_MATCHING=1` while iterating).
3. `./diff.py -mwo <func>` to compare against the baserom; adjust C until it matches.
4. Name the function/args/struct fields, fill in `src/*.h` (keep offset/size comments), run
   `python3 format.py`, re-check `progress.py`.
