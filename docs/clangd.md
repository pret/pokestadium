# Cross-file renaming with clangd

This repository uses the standard clangd language server, not a custom rename
extension. Its analysis database lists every existing game C translation unit
under `src/`, including nonignored new files. Shared headers are indexed through
those translation units. Tool sources and vendored library implementations have
different build contracts and are not part of this game-code database.

## First-time setup

1. Install Python 3, Git, clangd, and VS Code's recommended
   `llvm-vs-code-extensions.vscode-clangd` extension. In WSL, install/run these in
   the WSL environment and open the repository through VS Code's WSL connection.
   Use one C/C++ language service: disable the Microsoft C/C++ extension for this
   workspace if it is also supplying IntelliSense.
2. From the repository root, run:

   ```sh
   python3 tools/clangd_config.py
   ```

   Native Windows users can use `python` instead of `python3`.
3. Run **clangd: Restart language server** from the Command Palette. Let
   background indexing finish before using F2 on a shared declaration.
4. In a trusted VS Code workspace, allow the automatic task
   **clangd: keep compilation database current** when prompted. If necessary,
   use **Tasks: Manage Automatic Tasks in Folder** to allow it, then reopen the
   folder. It can also be started with **Tasks: Run Task**.

No ROM, extraction, virtual environment, IDO compiler, or MIPS binutils is needed
to generate the editor database. It reads the existing `compile_flags.txt` host
analysis flags and adds one selected version's definitions; it never invokes the
production build or changes its flags.

The analysis flags include `-m32`, matching the Makefile's host syntax-check
pointer width. Defining `_MIPS_SZPTR=32` alone does not change the host compiler's
pointer size; a 64-bit host view rejects some static display-list initializers.
The host-analysis warning policy also tolerates matching-source early returns
from non-void functions on clang 18, where the newer `-Wno-return-mismatch` flag
alone does not suppress that diagnostic. This does not change production checks.

The workspace settings enable background indexing and pass
`--rename-file-limit=0`. clangd otherwise limits a rename to 50 files, which is
too small for some shared-type migrations in this repository.

clangd documents that `compile_flags.txt` alone does not support background
indexing because it does not enumerate the source files. The explicit database
fixes that discovery problem; `Index.Background: Build` alone does not.
See [clangd setup](https://clangd.llvm.org/installation.html) and
[clangd's rename option](https://github.com/llvm/llvm-project/blob/main/clang-tools-extra/clangd/tool/ClangdMain.cpp).

## No per-symbol regeneration

**Renaming an identifier does not require regenerating JSON or restarting the
language server.** The database records source paths and flags, not symbol names.
clangd maintains its symbol index as files are edited.

The automatic task runs `python3 tools/clangd_config.py --watch`. It checks every
two seconds for source additions, deletions, moves, branch changes affecting the
source inventory, and `compile_flags.txt` changes. It atomically updates
`build/clangd/compile_commands.json` only when its contents differ. It does not
rewrite that file for normal identifier edits and does not compile anything.

If automatic tasks are not permitted, run the watcher in a terminal, or rerun the
one-shot command only after changing source paths or analysis flags. A freshness
check that does not write anything is available:

```sh
python3 tools/clangd_config.py --check
```

**After adding, moving or deleting source files, restart the clangd language
server once the database is current.** Database freshness and live-index
freshness are separate: an existing clangd process can retain old path entries
even after the JSON changes. The watcher removes the need to regenerate JSON by
hand, but is not a language-server restart mechanism. Ordinary identifier
renames do not change source paths and do not need this restart.

The command returns 1 for stale/missing output and 2 for an error. Generated
database paths, version selection and clangd caches stay ignored by Git, so they
do not create rename-history or merge-conflict churn.

## Regional analysis

The initial view is US 1.0. Select another view explicitly:

```sh
python3 tools/clangd_config.py --version us_rev2
```

The watcher preserves the selected version across refreshes and restarts.
Supported versions match the Makefile: `us`, `us_rev1`, `us_rev2`, `jp`, `eu`,
`eu_rev1`, `fr`, `de`, `es`, and `it`. The database uses the repository's
`NON_MATCHING`/`AVOID_UB` analysis view to expose C candidates.

A single selected view is not a union of all preprocessor branches. If a rename
can affect revision-specific declarations, inspect the other views and review
remaining occurrences. This editor setup is not a production ABI check, IDO
match oracle, or ROM-verification result.

## What F2 covers and what still requires review

Use **Rename Symbol** on the declaration or a correctly resolved reference.
Preview the edit before applying a shared rename. The goal is semantic C
references across indexed game sources, including files not open in the editor;
unrelated fields with the same spelling should remain unchanged.

F2 cannot promise to migrate every textual occurrence in the repository.
clangd documents limitations for macro bodies, comments and disabled preprocessor
sections. It also does not maintain this project's YAML extraction rules,
assembly/linker symbol metadata, filenames or generated linker inputs as part of
a C symbol rename. Review old-name hits and update authoritative non-C inputs
separately; regenerate extraction when its inputs change.
See [clangd rename limitations](https://clangd.llvm.org/features.html#rename).

After an important shared rename:

- Wait for indexing and review the complete proposed edit.
- Search remaining old-name occurrences and classify them rather than globally
  replacing every matching field spelling.
- Run the relevant source checks and normal target-specific ROM verifier.
- Coordinate any dependent PR branches before rewriting shared history.

## Troubleshooting and regression tests

If an unopened consumer is missing, run `--check`, confirm its `.c` file is in
`build/clangd/compile_commands.json`, inspect clangd's Output channel for parse
failures, and restart clangd after first-time setup or changing the selected
preprocessor view. Do not assume a completed index means every file parsed.

From the repository root:

```sh
python3 -m unittest discover -s tools -p 'test_clangd*.py' -v
```

The database tests need only Python and Git. The real language-server tests also
need `clangd` on PATH; they are explicitly skipped if it is unavailable. They use
temporary repositories, open only a header, and require a semantic field rename
to reach more than 50 unopened C files while preserving a different record's
same-spelled field. A second test confirms that clangd's default file limit
rejects that fixture rather than silently accepting partial coverage.
Another fixture moves a previously indexed file, regenerates its command, and
checks the new path after a server restart.

When `clang` is on PATH, a separate test syntax-checks every game translation
unit in the default US analysis view with the generated flags. It is explicitly
skipped without `clang`; listing a file in JSON is not a parse-success claim.
