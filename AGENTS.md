# AGENTS.md

Working in **reversed_stadium** — a work-in-progress *matching* decompilation of
Pokémon Stadium (US, N64). The end goal is C source whose compiled output is
**byte-identical** to the original ROM
(`pokestadium.z64`, `md5: ed1378bc12115f71209a77844965ba50`).

This file is an agent-focused checklist. For background, build commands, and
extended architecture notes see `README.md`, `CLAUDE.md`, and
`docs/c-first-plan.md` (the in-progress C-first campaign roadmap). Don't
duplicate what's already in those — link when possible.

---

## "Tests" don't exist here

There is no `make test` and no unit-test suite. The only correctness check is
that `make` produces a ROM whose md5 matches the baserom. Anything you change
in `src/`, headers, splat yaml, the Makefile, or generated assets can break
that match.

```bash
make                  # build + md5 verify against baseroms/us/baserom.z64
make diff-init        # snapshot current build/ into expected/ for diffing
make NON_MATCHING=1   # build without requiring a byte-match (sets NON_MATCHING, AVOID_UB)
```

Baseline guard after every change: `make` must still md5-match, then
`ps-firstdiff` (Rust) or `tools/first_diff.py` must exit 0. See `CLAUDE.md`
for the Python↔Rust tooling parity table.

## Build prerequisites (not optional)

- **MIPS binutils** on `PATH`: `mips-linux-gnu-{as,ld,objcopy,objdump,nm}`.
  Override prefix via `MIPS_BINUTILS_PREFIX=` if yours is named differently.
  The Makefile errors out hard if `mips-linux-gnu-ld` is missing — fix your
  env, don't paper over it.
- **IDO `cc`** vendored under `tools/ido/<os>/{5.3,7.1}/cc`. The build does
  **not** use GCC for actual compilation; GCC is only a syntax/warning check
  (`RUN_CC_CHECK`, see below). IDO codegen quirks are the source of truth —
  small "cleaner" rewrites often break the byte-match. Always verify with
  `./diff.py -mwo <func>` or `ps-fdiff <func>`.
- **Git submodule**: `tools/n64splat` (from `.gitmodules`). If you cloned
  without `--recurse-submodules`, `git submodule update --init` it before
  building — otherwise `make extract`/splat will silently misbehave.
- **Python venv** at `.venv`; populated by `make init` from `requirements.txt`.

### macOS — read before building

`make` on Darwin is GNU make, invoked as `gmake`. Two things *will* break
silently if missing:

- Install **GNU libiconv** (`brew install libiconv`). The system BSD `iconv`
  mis-encodes `\` (0x5C) inside Japanese strings as the fullwidth EUC-JP
  backslash (0xA1C0), corrupting `\n` escapes and diverging the ROM by ~293
  bytes at the end of `fragments/62`. The Makefile auto-detects Homebrew's
  libiconv and warns if it can't — that's your signal to install.
- Build with **`gmake RUN_CC_CHECK=0`**. The host-compiler `-m32` +
  `-Wint-conversion` combo errors out under Apple clang without affecting
  the ROM. Don't disable it on Linux.

## File layout & conventions agents get wrong

- **`src/*.c` are named by ROM offset**, not by feature (`11BA0.c`, `D470.c`,
  `33FE0.c`, `src/fragments/1/fragment1_7F9A0.c`, ...). This is on purpose —
  matching decomp preserves the ELF layout. **Don't rename files for clarity.**
- **Address-based identifiers** (`func_80010FA0`, `D_86002F34`,
  `unk_D_8690A610`) are the norm. Renaming them to meaningful names *as
  purpose becomes understood* is core documentation work; do it in commits
  separate from any behavior change.
- Sources are **EUC-JP encoded** (Japanese text strings). The build pipes
  through `iconv`; keep the encoding.
- Header structs carry explicit `/* 0x.. */` offset comments and trailing
  `// size = 0x..` markers — **preserve them**.
- `lib/ultralib/` is the vendored N64 SDK built separately with IDO 5.3 and
  archived into the ROM. Don't touch unless you know why.
- `lib/ultralib/src/os/...` is consulted via relative includes from a few
  `src/*.c` files (e.g. `src/libleo/leointerrupt.c`). Path is ugly on
  purpose to avoid touching the submodule tree.
- `asm/us/nonmatchings/<file>/<func>.s` is the reference asm for any function
  not yet decompiled. A function is "done" once that `.s` is gone
  (see `python3 progress.py` or `ps-status --build-aware`).

## `GLOBAL_ASM` and the per-file compile loop

A `pragma GLOBAL_ASM("asm/us/nonmatchings/<file>/<func>.s")` in a `.c` file
pulls in a function's reference asm. Files containing `GLOBAL_ASM` are routed
through `tools/asm-processor`. To decompile a function:

1. Generate context: `python3 tools/m2ctx.py src/<file>.c` → `ctx.c`
   (types/externs/localities).
2. First-draft C: `m2c --context ctx.c --target mips-ido-c
   asm/us/nonmatchings/<file>/<func>.s`. Functions with **jump tables** need
   the defining `.rodata.s` passed as an extra arg or m2c returns "jump table
   not provided".
3. Hand-clean types against `src/<file>.h` and raw `.s`. m2c output has known
   artifacts: `M2C_ERROR(/* unset register */)`, `void*`/`?`, struct accesses
   at wrong offsets, leftover-`$f0` (callee declared `void` ending in
   `sqrtf(...)` whose caller uses `$f0` — fix by giving the callee a `f32`
   return).
4. Build (`make` or `make NON_MATCHING=1`) until the match is byte-exact or the
   guarded C compiles under `NON_MATCHING`.
5. `./diff.py -mwo <func>` / `ps-fdiff <func>` for per-function diff
   (non-interactive vs interactive TUI; both validated to parity).
6. Format with `python3 format.py -j src/<file>.c` (requires `clang-format`
   / `clang-tidy` / `clang-apply-replacements` v14). Re-check `progress.py`
   and confirm `make` still md5-matches.

For the broader C-first campaign plan (the 61 remaining bare `GLOBAL_ASM`
functions, tooling additions like `ps-status --c-coverage`,
`ps-fdiff --file <src>`) read **`docs/c-first-plan.md`** end-to-end before
starting a batch.

### `NON_MATCHING` gotcha

**Do not run a full `make NON_MATCHING=1` between iterations on the matching
build.** It rebuilds every object as the NON_MATCHING variant. Switching back
to plain `make` only rebuilds what's changed, leaving a mixed-object build
with a wrong md5 (e.g. observed `964842af…`). To verify a single file compiles
under NON_MATCHING, build **just its object**:

```bash
gmake NON_MATCHING=1 RUN_CC_CHECK=0 build/src/<file>.o
```

If you ever do run a full NON_MATCHING build, restore the matching build
with `gmake clean && gmake` and `gmake diff-init` to refresh `expected/`.

## Per-file Makefile overrides

Look at the bottom of the `Makefile` (search `build/src/...: %:` rules). Many
files force a specific compiler (`CC := $(CC_OLD)`), opt level (`OPTFLAGS :=
-O0`), ISA (`-mips1`), or pragma (`-Wo,-loopunroll,0`,
`-trapuv`, `-signed`). When a newly split file won't match and you can't see
why, check whether it needs an override and copy the pattern from a sibling.

## Splat / assets / linker

- Splat config lives in `yamls/us/{header,rom}.yaml`; concatenated to
  `pokestadium-us.yaml` at `make extract` time. Don't hand-edit the
  concatenated file — it's gitignored.
- New C from splat comes in as `GLOBAL_ASM` stubs per function.
- `linker_scripts/us/{hardware_regs,undefined_syms,unused_syms}.ld`,
  `linker_scripts/common_undef_syms.ld`, and the `auto/` directory drive the
  ELF layout — `auto/` is generated; don't hand-edit.
- `assets/us/*.bin` and `*.png` are extracted from the baserom at `make
  extract` time and re-incorporated as `.o` via the `$(BUILD_DIR)/%.o: %.bin`
  rule.

## What "done" looks like for a function

- `asm/us/nonmatchings/<file>/<func>.s` deleted (function moved out of asm).
- Function and its struct fields renamed in `src/<file>.h`, keeping offset
  and size comments.
- File formatted (`python3 format.py`) and `make` still md5-matches.
- `python3 progress.py` shows the byte count tick up (or stays flat if you
  only renamed), and `ps-status --c-coverage` (Rust) shows unguarded
  `GLOBAL_ASM` count dropping by one.

## Skills & OpenCode config

No `.opencode/` or `opencode.json` is checked in. The
`.claude/settings.local.json` is just an outputStyle override; nothing
agent-binding. If you add agent config, scope it tightly and don't fork C
tooling knobs (RUN_CC_CHECK, NON_MATCHING, MIPS_BINUTILS_PREFIX) into
persistent `.make_options` files casually — they're per-iteration.
