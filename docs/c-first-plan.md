# Plan: Get all game code written in C ("C-first")

## Context

Pokémon Stadium is **89.60% decompiled by bytes**. The remaining `.text` lives in
two forms:

- **190 `GLOBAL_ASM` functions** across 68 files. Of these, **129 already have a
  C body** behind `#ifdef NON_MATCHING` (logic understood, just non-matching), and
  **61 are "bare"** — no C at all, `GLOBAL_ASM` included unconditionally.
- **Whole-file assembly**: only two `asm`-typed code segments remain —
  `asm/us/boot.s` (~716 words) and `asm/us/exception_set.s` (~8 words). Everything
  else in asm is either `hasm` (hand-written, intentionally kept as asm) or data.

The goal is **C-first**: every function has a readable C implementation so that
`make NON_MATCHING=1` compiles the entire game from C with **zero `GLOBAL_ASM`
assembled**. Byte-matching is explicitly a *later* phase and must not be regressed
in the meantime.

**Definition of done:** `make NON_MATCHING=1` builds green, and every `GLOBAL_ASM`
in `src/` sits inside a `NON_MATCHING` guard (so none is reached in a NON_MATCHING
build). The plain `make` build still produces the byte-exact ROM
(`md5 ed1378bc12115f71209a77844965ba50`).

## Locked decisions

1. **`hasm` stays as hand-asm** — out of scope (bootloader/entry, Yay0 decoder,
   audio decoder 0x517A0, abs, 49190, libleo bootstrap). Scope = the 190
   `GLOBAL_ASM` functions + `boot` + `exception_set`.
2. **Preserve the byte-match** — every new C body is wrapped
   `#ifdef NON_MATCHING <C> #else GLOBAL_ASM(...) #endif`. Plain `make` stays
   md5-exact throughout. If a function happens to match, drop the wrapper entirely.
3. **Use m2c** (`mips_to_c`) to bootstrap first-draft C, with `tools/m2ctx.py` for
   context; hand-clean afterward.

## Rust toolkit — the backbone of this campaign

The existing Rust tools (`ps-status`, `ps-fdiff`, `ps-firstdiff`) drive the whole
effort: worklist, progress metric, opportunistic match detection, and regression
guard. **All measurement and verification go through the Rust toolkit, not the
Python scripts.** Three additions are made up-front in Phase 0:

1. **`ps-status --c-coverage`** (new mode) — the campaign's primary metric. Reuses
   `ps-core::globalasm` plus a new `ps-core` helper that detects whether each
   `GLOBAL_ASM` sits inside an `#ifdef NON_MATCHING` guard. Reports **guarded (has
   C) vs unguarded (bare)** counts, per-file and total. Campaign target:
   *unguarded → 0*. Supports `--list` (emit the exact bare functions + addresses,
   the worklist) and `--json` (drive scripting/CI).
2. **`ps-fdiff --file <src>`** (new batch mode) — run the per-function diff across
   every function in a file and print a one-line match/'`N` words differ' summary
   each, ranked closest-first. Used to (a) spot functions that *already match* so
   the wrapper can be dropped, and (b) later prioritize the matching phase.
3. **`ps-firstdiff`** (existing) — the fast regression guard after each change:
   exit 0 = still byte-exact, non-zero = first divergence located.

These three are the only tooling additions on the repo side; m2c is the sole
external/Python dependency.

## Work breakdown

### Phase 0 — Tooling + green baseline
- Build the Rust additions above (`cargo build --release --manifest-path tools/rust/Cargo.toml`),
  with unit tests for the `--c-coverage` guard detection on synthetic fixtures
  (mirroring the existing `ps-core` test style).
- Generate the worklist: `ps-status --c-coverage --list` → the 61 bare functions
  with addresses, grouped by file. This is the tracked backlog.
- Install m2c into the venv: `pip install git+https://github.com/matt-kempster/mips_to_c`
  (confirm exact package/repo; expose as `m2c` / `python3 -m m2c`). Add it to
  `requirements.txt` (or a `requirements-dev.txt`) so it's reproducible.
- Establish that **`make NON_MATCHING=1` builds today**. The 129 existing
  `#ifdef NON_MATCHING` C bodies may include stale/incomplete attempts that don't
  compile under current headers. Fix any compile errors first — this is the
  baseline the whole effort builds on. (On macOS, build with
  `RUN_CC_CHECK=0` and GNU libiconv, per CLAUDE.md.)
- Confirm plain `make` still md5-matches, then `ps-firstdiff` exits 0 (baseline
  regression guard).

### Phase 1 — Wrap the 61 bare `GLOBAL_ASM` functions
The bare functions are concentrated in **11 files**:
```
fragments/1/fragment1_7F9A0.c   18    3D140.c                    6
fragments/1/fragment1_86CB0.c   12    4A3E0.c                    4
33FE0.c                         11    fragments/23/fragment23_1AE680.c  3
fragments/31/fragment31_2558B0.c 2    fragments/23/fragment23_1A9780.c  2
48C60.c / 485C0.c / 46680.c      1 each
```
Per-function loop (repeatable, see below). Suggested order: the 3 single-function
files first (quick wins to validate the loop), then `3D140.c`/`33FE0.c` (dense,
low-% files), then the two big `fragments/1` files.

### Phase 2 — Whole-file asm: `exception_set` then `boot`
- Change the segment type in `yamls/us/rom.yaml` from `asm` → `c`
  (`[0xC3D0, asm, exception_set]` → `c`, likewise `[0x0040, asm, boot]`).
- `make extract` regenerates `src/exception_set.c` / `src/boot.c` as `GLOBAL_ASM`
  stubs per function. Then apply the same per-function loop.
- Do `exception_set` (~8 words) first as a trivial proof, then `boot`.

### Per-function workflow (the core loop)
1. `python3 tools/m2ctx.py src/<file>.c` → generates `ctx.c` (types/externs).
2. `m2c --context ctx.c --target mips-ido-c asm/us/nonmatchings/<file>/<func>.s` →
   first-draft C. **If the function has a jump table** (`switch`), m2c fails with
   "corresponding jump table is not provided" — pass the rodata `.s` that defines
   the `jtbl_*` symbol as an extra argument, e.g.
   `m2c --context ctx.c … func.s asm/us/data/rom_rodata_7D8D0.rodata.s`.
   (14 of the remaining bare functions use jump tables.)
3. Hand-clean: fix types against `src/<file>.h` / `include/`, name obvious args,
   keep struct offset/size comments.
4. Wrap in the file:
   ```c
   #ifdef NON_MATCHING
   <cleaned C>
   #else
   #pragma GLOBAL_ASM("asm/us/nonmatchings/<file>/<func>.s")
   #endif
   ```
5. `make NON_MATCHING=1` must compile. Then `ps-fdiff <func>` (Rust) — if it
   already matches, delete the wrapper + `GLOBAL_ASM` outright (best outcome:
   advances both C-coverage *and* the match). Otherwise keep the wrapper.
6. `python3 format.py src/<file>.c`, then `ps-status --c-coverage` to confirm the
   unguarded count dropped, and `ps-firstdiff` to confirm the matching build is
   still byte-exact.

At file boundaries, `ps-fdiff --file src/<file>.c` gives a closeness ranking of
all its functions — a free head-start on the later matching phase.

### Workflow gotchas (discovered while validating the loop)
- **Never do a full `make NON_MATCHING=1` for verification** — it rebuilds every
  object as a NON_MATCHING variant, and switching back only rebuilds what changed,
  leaving a mixed build whose ROM md5 is wrong (seen: `964842af…`). The matching
  build is unaffected by guarded C anyway. To check that a wrapped file *compiles*
  under NON_MATCHING, build just its object:
  `gmake NON_MATCHING=1 RUN_CC_CHECK=0 build/src/<file>.o`. If you ever do run a
  full NON_MATCHING build, restore with `gmake clean && gmake` (then re-run
  `gmake diff-init` to reset `expected/`).
- **The matching build is the regression source of truth.** Because every new C is
  behind `#ifdef NON_MATCHING`, plain `gmake` must still produce
  `md5 ed1378bc…`; verify it and `ps-firstdiff` (exit 0) after a batch.
- **`format.py` needs clang-format-14**, which isn't installed here (`brew install
  llvm` / a clang-format-14). Until then, hand-format to `.clang-format` (4-space,
  pointer-left, attach-brace); the campaign C already follows it.
- **Pick smallest-first, but read the asm.** Function size varies wildly (0x10 …
  960 instructions). m2c drafts of non-trivial functions often carry artifacts
  that will not compile — `M2C_ERROR(/* unset register */)`, `void*`/`?` types,
  and struct accesses at offsets outside the inferred type (e.g. a `PosBlend`
  0x18 struct accessed at `+0x2C`, which really belongs to the enclosing
  `ModelVertex`). Treat m2c as a starting draft; resolve types/globals against
  `src/<file>.h` and the raw `.s`. Empty stubs (`func_81209690`) and functions
  that mirror an existing sibling (`func_812075C0` ↔ `func_812073B8`) are the
  cleanest wins.

Progress so far (7 done): `func_80033D1C`, `func_800414B8`, `func_8003F4C0`
(33FE0/3D140); `func_812075C0`, `func_81209690` (fragment1_86CB0);
`func_812004B8`, `func_81202EA8` (fragment1_7F9A0) → bare 61 → 54, C-first 71.6%.

## Critical files
- `tools/rust/crates/ps-status/` + `tools/rust/crates/ps-core/src/globalasm.rs` —
  new `--c-coverage` mode + guard detection.
- `tools/rust/crates/ps-fdiff/` — new `--file <src>` batch mode.
- `src/*.c` (11 bare-function files; representative: `src/48C60.c`, `src/33FE0.c`,
  `src/fragments/1/fragment1_7F9A0.c`) — add wrapped C bodies.
- `yamls/us/rom.yaml` — reseg `boot`, `exception_set` from `asm` → `c`.
- `requirements.txt` — add m2c.
- Reuse: `tools/m2ctx.py` (context), `format.py` (formatting), and the Rust tools
  `ps-status` / `ps-fdiff` / `ps-firstdiff` for all measurement and verification.

## Verification (all via the Rust toolkit)
- **Milestone check:** `make NON_MATCHING=1` builds green, and
  `ps-status --c-coverage` reports **0 unguarded** `GLOBAL_ASM`.
- **No-regression check (after every function):** plain `make` reproduces
  `md5 ed1378bc12115f71209a77844965ba50`, and `ps-firstdiff` exits 0 (new C is
  behind `#ifdef NON_MATCHING`, so the matching build is untouched).
- **Per-function compile check:** `make NON_MATCHING=1` after each wrap.
- **Opportunistic matches:** `ps-fdiff <func>` / `ps-fdiff --file <src>` — any
  function that already matches gets its wrapper dropped immediately.
- **Rust additions themselves:** `cargo test` + `cargo clippy` green, with parity
  of `--c-coverage` against a `grep`-based ground truth (as was done for the
  existing `ps-status` build-free metric).

## Out of scope / follow-up (later: the matching campaign)
Once every function is C, a separate matching campaign turns each
`#ifdef NON_MATCHING` body into a byte-match (delete the wrapper), tracked by the
existing `ps-status --build-aware` metric and prioritized by `ps-fdiff --file`
closeness rankings. Tooling to add then: the decomp **permuter**. `hasm` segments
and `asm/us/data/*` blobs remain as-is.
