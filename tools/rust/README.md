# Pokémon Stadium matching tools (Rust)

A cargo workspace with the tooling for the byte-for-byte matching effort. It has
no Python dependencies; MIPS disassembly uses the [`rabbitizer`] crate — the same
disassembler the Python scripts use — for output parity.

## Crates

| Crate          | Binary         | Python equivalent (maintained) |
| -------------- | -------------- | ------------------------------ |
| `ps-core`      | *(library)*    | shared parsers / models        |
| `ps-status`    | `ps-status`    | `progress.py`                  |
| `ps-firstdiff` | `ps-firstdiff` | `tools/first_diff.py`          |
| `ps-fdiff`     | `ps-fdiff`     | `./diff.py -mwo <func>`        |

The Python scripts are **kept alongside** the Rust tools, not replaced — the two
are validated to parity (see below) so either can be used.

Two extra modes support the "C-first" campaign (writing C for every function
before matching; see `docs/c-first-plan.md`):

* `ps-status --c-coverage [--list] [--json]` — how many `GLOBAL_ASM` functions
  are **guarded** (have a `#ifdef NON_MATCHING` C body) vs **bare** (asm only).
  Campaign metric: *bare → 0*. `--list` prints the bare worklist with addresses.
* `ps-fdiff --file <src.c>` — summarize every function in a source file's object,
  ranked closest-first (fewest differing words), flagging any that already match.

`ps-core` contains the reusable pieces:

* `globalasm` — scan `src/**/*.c` for `#pragma GLOBAL_ASM(...)` (build-free list
  of pending functions), tracking whether each is behind a `NON_MATCHING` guard.
* `symbols` — parse `linker_scripts/<v>/symbol_addrs*.txt`.
* `mapfile` — minimal GNU `ld` `.map` parser: `.text` symbols with sizes, plus
  vram/vrom lookups (vrom derived from each section's `load address`).
* `rom` — big-endian `.z64` reader + md5 verification.
* `disasm` — `rabbitizer` wrapper; resolves `jal` targets to symbol names.

## Build & test

```bash
cargo build --release      # binaries in target/release/
cargo test                 # unit tests
cargo clippy --all-targets
```

## Modes that need build artifacts

`ps-status` (default), works with only the committed repo. Everything else needs
artifacts produced by `make`:

* `ps-status --build-aware` needs `build/pokestadium-<v>.map`.
* `ps-firstdiff` needs `build/…z64` + `.map` and `expected/build/…` (`make diff-init`).
* `ps-fdiff` needs `build/…z64` + `.map` and `baseroms/<v>/baserom.z64`.

## Parity-validation status

The Python scripts are **kept in place**. Validated so far:

* `ps-status` build-free — **validated**: total (190) and per-file counts match
  `grep -rho 'GLOBAL_ASM("[^"]*")' src/ | wc -l` and `grep -rln GLOBAL_ASM src/`.
* `ps-status --build-aware` vs `progress.py` — **validated to exact parity** on a
  real matching build: identical total (1975096 / 2204464 = 89.5953%) and every
  per-folder decomp/total byte count. The `.text` symbol table produced by
  `ps-core`'s map parser matches `mapfile_parser` symbol-for-symbol (8240 symbols,
  2204464 bytes). Reaching this required replicating two `mapfile_parser`
  behaviours: skipping `vram == 0` (unallocated archive members) and synthesizing
  a `$_static_symbol_...` for the leading gap before a contribution's first named
  symbol (static functions / symbol-less headers).

* `ps-firstdiff` vs `tools/first_diff.py` — **validated** with an injected
  regression (one instruction word patched in the built ROM). Both report the
  identical first difference: same ROM offset, containing function + inner
  offset, differing bytes, and decoded instructions — including resolving the
  patched `jal` target to its symbol via the map.
* `ps-fdiff` vs `./diff.py` — **validated** on the same regression: both flag the
  same differing instruction at the same offset (marked `|`). Presentation
  differs by design — `ps-fdiff` resolves `jal` targets to symbol names and stops
  at the function boundary, while asm-differ shows raw addresses over a wider
  window with its own scoring — but the located difference matches. Exit codes:
  `0` match, `1` differ, `2` error.

All three matching tools now have confirmed parity against their Python
counterparts. Reproduce the diff checks in a full build environment with:

```bash
# build-aware vs progress.py (compare bytes / percentages)
make && make diff-init
python3 progress.py
./tools/rust/target/release/ps-status --build-aware

# first-diff vs first_diff.py (introduce a deliberate regression first)
python3 tools/first_diff.py
./tools/rust/target/release/ps-firstdiff

# per-function diff vs diff.py
./diff.py -mwo <func>
./tools/rust/target/release/ps-fdiff <func>
```

Note: `ps-fdiff` v1 is non-interactive (word-by-word alignment); `diff.py`'s
interactive TUI, scoring and insert/delete alignment are not reimplemented.

[`rabbitizer`]: https://crates.io/crates/rabbitizer
