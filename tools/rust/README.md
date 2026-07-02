# Pokémon Stadium matching tools (Rust)

A cargo workspace with the tooling for the byte-for-byte matching effort. It has
no Python dependencies; MIPS disassembly uses the [`rabbitizer`] crate — the same
disassembler the Python scripts use — for output parity.

## Crates

| Crate          | Binary         | Replaces (eventually)     |
| -------------- | -------------- | ------------------------- |
| `ps-core`      | *(library)*    | shared parsers / models   |
| `ps-status`    | `ps-status`    | `progress.py`             |
| `ps-firstdiff` | `ps-firstdiff` | `tools/first_diff.py`     |
| `ps-fdiff`     | `ps-fdiff`     | `./diff.py -mwo <func>`   |

`ps-core` contains the reusable pieces:

* `globalasm` — scan `src/**/*.c` for `#pragma GLOBAL_ASM(...)` (build-free list
  of pending functions).
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

The Python scripts are **kept in place**. Only the parts validatable without a
ROM/toolchain have been checked so far:

* `ps-status` build-free — **validated**: total (190) and per-file counts match
  `grep -rho 'GLOBAL_ASM("[^"]*")' src/ | wc -l` and `grep -rln GLOBAL_ASM src/`.

The build-dependent tools (`ps-status --build-aware`, `ps-firstdiff`, `ps-fdiff`)
are covered by unit tests on synthetic fixtures but have **not** yet been
compared against the Python tools on real build output. Before removing
`progress.py`, `tools/first_diff.py` or `diff.py`, confirm parity in a full build
environment:

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
