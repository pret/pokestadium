# Pokemon Stadium (US)
A WIP decomp of Pokemon Stadium (US).

It builds the following ROMs:

* pokestadium.z64: `md5: ed1378bc12115f71209a77844965ba50`

Note: To use this repository, you must already have a rom for the game.

# Prerequisites

Under Debian / Ubuntu (which we recommend using), you can install them with the following commands:

```bash
sudo apt update
sudo apt install make git build-essential binutils-mips-linux-gnu python3 python3-pip python3-venv
```

**Please also ensure that the Python version installed is >3.7.**

The build process has a few python packages required that are located in `requirements.txt`.

To install them simply run in a terminal:

```bash
python3 -m pip install -r requirements.txt
```

## macOS

Use Homebrew: `brew install make mips-linux-gnu-binutils libiconv` (invoke the
build as `gmake`). **`libiconv` is required** — macOS's system (BSD) `iconv`
mis-encodes an ASCII backslash as the EUC-JP fullwidth backslash (0xA1C0) when it
follows a multibyte character, silently corrupting C escapes like `\n` inside
Japanese string literals and breaking the byte-match. The Makefile auto-detects
GNU libiconv from Homebrew (`/opt/homebrew` or `/usr/local`) and warns if only the
system `iconv` is found. The host-compiler syntax check also fails under Apple
clang (it can't do `-m32` and treats `-Wint-conversion` as an error), so build
with `gmake RUN_CC_CHECK=0`; this does not affect the ROM output.

# To use
1. Place the US Pokemon Stadium 1.0 rom into the repository's "/baseroms/us/" folder as "baserom.z64".
2. Set up tools and extract the rom: `make init`
3. Re-assemble the rom: `make`

# Matching tools (Rust)

A Rust workspace under [`tools/rust/`](tools/rust/) provides the tooling for the
byte-for-byte matching effort. It is built automatically by `make setup`
(`make -C tools`) when `cargo` is available; you can also build it directly:

```bash
cargo build --release --manifest-path tools/rust/Cargo.toml
```

The binaries land in `tools/rust/target/release/`:

* **`ps-status`** — status of functions still pending decompilation. Runs
  **build-free** (no ROM needed), scanning `#pragma GLOBAL_ASM` in `src/`:

  ```bash
  ./tools/rust/target/release/ps-status            # summary + per-file counts
  ./tools/rust/target/release/ps-status --list     # every function + address
  ./tools/rust/target/release/ps-status --json     # machine-readable
  ```

  After `make` it also runs **build-aware** (byte progress per folder, like
  `progress.py`) when `build/pokestadium-us.map` exists, or with `--build-aware`.

* **`ps-firstdiff`** — first difference(s) between the built and expected ROM
  (like `tools/first_diff.py`). Requires `make` + `make diff-init`:

  ```bash
  ./tools/rust/target/release/ps-firstdiff -c 5
  ```

* **`ps-fdiff`** — non-interactive per-function asm diff of the built ROM vs the
  baserom (like `./diff.py -mwo <func>`). Requires `make`:

  ```bash
  ./tools/rust/target/release/ps-fdiff func_80030010
  ```

Run any tool with `--help` for options.

## Rust ↔ Python equivalence

The Rust tools mirror the existing Python scripts, which are **maintained
alongside them** (not deprecated) — use whichever you prefer:

| Rust tool      | Python equivalent       | Parity                                   |
| -------------- | ----------------------- | ---------------------------------------- |
| `ps-status`    | `progress.py`           | byte-exact totals + per-folder counts    |
| `ps-firstdiff` | `tools/first_diff.py`   | same offset / function / decoded bytes   |
| `ps-fdiff`     | `./diff.py -mwo <func>` | same differing instruction located¹      |

¹ `ps-fdiff` additionally resolves `jal` targets to symbol names and is scoped to
the function; `diff.py` keeps its interactive TUI, scoring and wider window.

Parity was verified against a real matching build (`ps-status`) and an injected
one-instruction regression (`ps-firstdiff` / `ps-fdiff`). See
[`tools/rust/README.md`](tools/rust/README.md) for the full validation details.

For contacts and other pret projects, see [pret.github.io](https://pret.github.io/).
