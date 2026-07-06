# Plan: rename every identifier in matching C code

## Why

The repo is at ~89.6% decomp-bytes, but the existing C still uses
address-based identifiers (`func_80029310`, `D_800AE540`, `unk_24`)
for nearly every symbol. Renaming them — **only in functions that
currently compile to byte-identical asm** — is the highest-leverage
way to finish "understanding, rewriting, and documenting" the existing
decompiled C (see `ABOUT_AI.md`). It also unlocks reading the codebase
without constantly bouncing into the map file.

This is a **Rust-toolkit-only** campaign: every measurement, worklist,
and verification step uses the `tools/rust/` workspace. The Python
matching tools (`progress.py`, `tools/first_diff.py`, `./diff.py`)
are **off-limits** — the Rust versions are validated to parity (see
`tools/rust/README.md`). The one remaining Python is `format.py`
(code-style formatter, not matching tooling).

## Goals (measurable)

- 0 `func_*` in `src/`, `include/` (kept only when purpose is genuinely unknown)
- 0 `D_*` globals in `src/`, `include/`
- 0 `unk_NN` struct-field names in headers (keep `/* 0xN */` offset comments)
- `make` still produces `md5 ed1378bc12115f71209a77844965ba50`
- `ps-status --rename-coverage` reports **100%**

## Hard precondition: md5 gate (non-negotiable)

**Every single commit MUST reproduce `md5 ed1378bc12115f71209a77844965ba50`.
No exceptions. No "I'll fix it in the next commit."**

Before **every** `git commit`:

1. Run `make`.
2. Read the md5 it prints.
3. **Only commit if the md5 is `ed1378bc12115f71209a77844965ba50`.**
4. If the md5 is anything else: **do not commit.** Run `ps-firstdiff`
   to locate the divergence, fix it, rebuild, recheck. Repeat until md5
   matches. Then commit.

This is enforced mechanically by the recommended verification flow:

```bash
# One-shot gate — exits 0 only if md5 matches AND rename is complete.
ps-rename-check <old> <new> && git commit
```

A commit that breaks md5 is a **revert, not a fix-forward**. The whole
point of the campaign is that *renames are semantics-preserving by
construction* — if md5 breaks, the rename was wrong (typo, missed
callsite, accidental semantic edit). Revert, then reattempt.

This rule applies equally to:

- Function renames
- Global var renames
- Struct field renames
- Enum / macro renames
- Phase 0 tooling commits — the tool itself must still build a
  matching ROM (renames don't change md5, but a sloppy tool change
  could)

A commit history where every commit is md5-clean is the entire
defense against silent regressions during a multi-month rename
campaign. **Do not relax this rule, ever.**

## Out of scope

- `lib/ultralib/`, `src/libultra/` — vendored
- `asm/us/*.s` — pure asm
- Anything behind `#ifdef NON_MATCHING` — not byte-matching yet
- `hasm` segments (boot, Yay0, 49190, 517A0, abs)
- `linker_scripts/us/symbol_addrs*.txt` — pins addresses; the name
  change is link-invisible, **do not edit them**
- Python matching tools (`progress.py`, `tools/first_diff.py`, `./diff.py`)
  — superseded by the Rust toolkit

---

## Rust toolkit extensions (Phase 0 — done first)

Add three modes to `ps-status` and one small new binary, all in
`tools/rust/crates/`. **Tooling lands in its own commits before any
rename** — no commit should mix "added tool" with "renamed something".

### `ps-status` additions

Edit `tools/rust/crates/ps-status/src/main.rs` and the helpers in
`ps-core/src/globalasm.rs` / `ps-core/src/symbols.rs` as needed:

```bash
# Campaign metric. 100% = every identifier has a meaningful name.
ps-status --rename-coverage
ps-status --rename-coverage --json
ps-status --rename-coverage --per-folder

# The worklist, sorted by call-graph depth (roots first).
ps-status --rename-list
ps-status --rename-list --funcs
ps-status --rename-list --globals
ps-status --rename-list --fields
ps-status --rename-list --enums
ps-status --rename-list --macros
ps-status --rename-list --file src/29BA0.c

# Graph queries — cheaper than re-running rg every commit.
ps-status --callees <symbol>
ps-status --callers  <symbol>
```

`--callees` / `--callers` resolve direct `jal` targets via the
build map. Indirect calls through function pointers get flagged with
`?` so the agent knows to grep separately for those.

### `ps-rename-check` (new binary)

New crate at `tools/rust/crates/ps-rename-check/`. ~80 lines. Reuses
`ps-core::globalasm` and `ps-core::mapfile` — does not reinvent them.

```bash
# Verifies a single rename is complete and the build is still matching.
# Exits 0 only if ALL hold:
#   (a) zero stragglers of <old> remain in src/ include/
#       other than the rename commit's definition;
#   (b) `make` produced md5 ed1378bc…;
#   (c) `ps-firstdiff` exits 0.
# Exits 1 if any check fails. Exits 2 on tool error.
ps-rename-check <old> <new>
```

### Validation requirements

Each new tool gets:

1. Unit tests under `crates/<tool>/tests/` mirroring the existing
   `ps-core` test style.
2. **Parity check** against a ground truth on a clean tree:
   - `--rename-coverage` totals must match
     `rg -c '\b(func_[0-9A-F]{8}|D_8[0-9A-F]{8})\b' src include`.
   - `--callees <f>` for a sample function must match the manual
     `rg '\bjal\b.*\b<f>\b' asm build` cross-reference.
3. `cargo test`, `cargo clippy --all-targets`,
   `cargo build --release --manifest-path tools/rust/Cargo.toml` —
   all green before any rename commit lands.

---

## Per-identifier workflow

The unit of work is **one identifier per commit**. Local variables
belong to their containing function — fix them when you fix the
function, in the same commit.

### Function (most common case)

```bash
1. Read src/<file>.c, understand what it does. Trace callees.
2. ps-status --callees <func>          # graph query
   ps-status --callers <func>
3. Pick a name matching the convention (below).
4. Update declaration:
     src/<file>.h                       # if file-scoped
     include/functions.h                # if cross-file
5. Update definition in src/<file>.c.
6. Update every callsite:
     rg -n '\b<old_name>\b' src include
   Must show 1 occurrence (the definition) or 0 (extern-only).
7. make                                 # md5 must match
8. ps-firstdiff                         # exits 0
9. ps-rename-check <old> <new>          # one-shot: 1+7+8
10. python3 format.py src/<file>.c      # formatter stays Python
11. Commit (template below).
```

### Global variable

Declaration in `include/variables.h` or `src/<file>.h`. Address is
pinned in `linker_scripts/us/symbol_addrs*.txt` — **leave those alone**,
the name change is link-invisible, md5 still matches. Workflow same
as function but step 6 must scan `include/` and `src/`.

### Struct field

Edit the `/* 0xN */` comment in the header to add the snake_case
field name; update every `.unk_NN` access across files.
**Preserve offset comments and trailing `// size = 0xN` markers —
non-negotiable.**

### Enum value / macro

Rename in the definition, then update every use. `switch` arms are
the most common call site.

### Local variable

In-source only, scoped to the function being renamed. Done in the
same commit as the function rename. Pattern: `s32 temp;` →
`s32 frameIndex;`.

---

## Strategy for unknowns

Never invent a name you can't justify. For functions whose purpose
you can't figure out, **leave the address-based name and document
it** in a per-file `KNOWN_UNKNOWNS` block at the top of
`src/<file>.h`:

```c
// === KNOWN_UNKNOWNS ============================================
// func_80029310: called from Game_Thread case STATE_N64_LOGO_INTRO.
//   Calls: func_80005A20, func_80029500.
//   Reads: gCurrentGameState. Writes: D_800AE540.
// func_800293CC: called from Game_Thread case STATE_TITLE_SCREEN.
//   ...
// ===============================================================
```

The block grows with each pass while the in-code `func_*` count
shrinks. The block *is* the next pass's worklist.
**`rg KNOWN_UNKNOWNS` is the cross-file query for unknowns.**

If a function is "almost obvious" but not 100% certain, prefer to
leave it address-named and add it to `KNOWN_UNKNOWNS` with a partial
description. A wrong name is worse than no name.

---

## Naming convention

Match the closest sibling. Existing precedent in `src/`:

| Kind            | Convention                   | Examples (current)                                                |
| --------------- | ---------------------------- | ----------------------------------------------------------------- |
| Module function | PascalCase, `Module_` prefix | `Game_Thread`, `Cont_SetupControllers`, `Yay0_Decompress`, `Game_DoCopyProtection` |
| Utility         | snake_case                   | `crash_screen_init`, `rsp_init`, `main_pool_push_state`           |
| Global var      | `g` + PascalCase             | `gCurrentGameState`, `gLastGameState`                             |
| Enum value      | `STATE_*` SCREAMING_SNAKE    | `STATE_N64_LOGO_INTRO`, `STATE_BATTLE_NOW_1P`                     |
| Macro           | SCREAMING_SNAKE_CASE         | (audit per file)                                                  |
| Struct field    | snake_case                   | replace `unk_NN`, keep offset comment                            |

For the `Game_Thread` state handlers, suggested pattern:
`Game_HandleN64LogoIntro`, `Game_HandleTitleScreen`, etc. —
short, verb-led, module-prefixed.

---

## Phasing

The campaign is too big to do at once. Phases give natural commit
boundaries and let you ship in increments.

### Phase 0 — Rust tooling (this week)

- `ps-status --rename-coverage` (+ JSON, + per-folder)
- `ps-status --rename-list` (+ kind filters, + file filter)
- `ps-status --callees <f>` / `--callers <f>`
- New `ps-rename-check <old> <new>` binary
- All with unit tests + parity checks against `rg`
- `cargo test && cargo clippy --all-targets` green

**Done when:** `ps-status --rename-coverage` runs on a clean tree
and reports a baseline % (the starting line for the campaign).

### Phase 1 — Root 0 boot init (~5 functions)

`src/main.c` callers and the bare init helpers. Trivial wins;
tightens the per-commit loop on real data.

- `func_80001474` (init helper in `Idle_ThreadEntry`)
- `func_8000D564`
- `func_800052B4`
- `func_800019C8`
- `func_800196DC` (called from `Game_Thread`, likely controller init)

**Done when:** all renamed, `ps-status --rename-coverage` ticks,
`make` still md5-matches.

### Phase 2 — Game_Thread state handlers (23 functions)

The `switch` arms in `src/29BA0.c:796-870`. Highest-value first
batch — each handler maps 1:1 to a known game state.

| Address-named function | Game state (`gCurrentGameState`) | Suggested name                  |
| --- | --- | --- |
| `func_80029310` | `STATE_N64_LOGO_INTRO`         | `Game_HandleN64LogoIntro`       |
| `func_800293CC` | `STATE_TITLE_SCREEN`           | `Game_HandleTitleScreen`        |
| `func_800296AC` | `STATE_N64DD_BOOT_UNUSED`      | `Game_HandleN64DDBootUnused`    |
| `func_80029828` | `STATE_AREA_SELECT`            | `Game_HandleAreaSelect`         |
| `func_8002A698` | `STATE_GALLERY`                | `Game_HandleGallery`            |
| `func_80029884` | `STATE_EVENT_BATTLE`           | `Game_HandleEventBattle`        |
| `func_800298D4` | `STATE_OPTIONS`                | `Game_HandleOptions`            |
| `func_80029924` | `STATE_MENU_SELECT`            | `Game_HandleMenuSelect`         |
| `func_80029BC0` | `STATE_STADIUM_MENU`           | `Game_HandleStadiumMenu`        |
| `func_8002A06C` | `STATE_FREE_BATTLE`            | `Game_HandleFreeBattle`         |
| `func_8002A400` | `STATE_VS_MEWTWO`              | `Game_HandleVsMewtwo`           |
| `func_8002A670` | `STATE_KIDS_CLUB`              | `Game_HandleKidsClub`           |
| `func_8002A6C0` | `STATE_VICTORY_PALACE`         | `Game_HandleVictoryPalace`      |
| `func_8002EF44` | `STATE_POKEMON_LAB`            | `Game_HandlePokemonLab`         |
| `func_8002A728` | `STATE_GB_TOWER`               | `Game_HandleGBTower`            |
| `func_8002AAA8` | `STATE_GYM_LEADER_CASTLE`      | `Game_HandleGymLeaderCastle`    |
| `func_8002ADE8` | `STATE_BATTLE_NOW_1P/2P` (×2)  | `Game_StartBattleNow`           |
| `func_8002AF38` | `STATE_BATTLE_FROM_EVENT`      | `Game_HandleBattleFromEvent`    |
| `func_800296E0` | `STATE_STUBBED_DEBUG`          | `Game_HandleStubbedDebug`       |
| `func_8002B180` | `STATE_FAST_BATTLE`            | `Game_HandleFastBattle`         |
| `func_8002B24C` | `STATE_KIDS_CLUB_TITLE`        | `Game_HandleKidsClubTitle`      |
| `func_8002B07C` | `STATE_FAST_N64_LOGO`          | `Game_HandleFastN64Logo`        |
| `func_8002B310` | wrapper — calls `func_80000DF4` once | (audit first)             |

**Done when:** all 23 renamed; `KNOWN_UNKNOWNS` for `29BA0.c` reduced
to only the genuinely-unknown helpers.

### Phase 3 — Subsystems (multi-month)

Work downward through each state handler's callees. Order (by repo
footprint):

1. Controller (`Cont_*`, `src/controller.c`)
2. GB emulator (`src/gb_mbc.c`, `src/gb_tower.c`)
3. 64DD / `libleo/`
4. Audio (`src/libnaudio/`)
5. RSP / graphics (`src/rsp.c`, `src/geo_layout.c`, `src/stage_loader.c`)
6. `fragments/` overlays

Each subsystem = a self-contained Phase 3.x sub-phase with its own
`KNOWN_UNKNOWNS` tracking.

---

## Per-commit verification (Rust-only)

**The md5 gate is the only check that matters for commit eligibility.**
All other checks are quality bars, but a missing call-site or a typo
will *also* break md5 — so the md5 check catches everything that
could silently regress the build.

The required order, with the **commit gate** at the end:

```bash
# --- QUALITY CHECKS (do first, fix issues found) ---

# 1. Rename is complete (no stragglers of the old name)
rg -n '\b<old_name>\b' src include
#    Expect: 0 hits, OR 1 hit (this commit's definition only).

# 2. Formatted
python3 format.py src/<file>.c
#    Formatter stays Python — it's code-style, not matching tooling.

# --- BUILD + MD5 (the gate) ---

# 3. Build and read the md5
make
#    Expect: md5sum output ends with `ed1378bc12115f71209a77844965ba50`.

# 4. Regression check via the Rust tool
ps-firstdiff
#    Expect: exit 0.

# 5. One-shot all-in-one (preferred — combines 1, 3, 4)
ps-rename-check <old> <new>
#    Expect: exit 0.

# --- COMMIT GATE: only proceed if md5 is ed1378bc… ---

# 6. ONLY if step 3 (or 5) reported md5 ed1378bc…:
git add -p
git commit -m "rename: ..."
#    Else: STOP. Do not commit. Revert and fix.
```

**Stop-and-revert rule (repeated for emphasis):**

- If `make` prints any md5 other than `ed1378bc12115f71209a77844965ba50`,
  **do not commit.** Run `ps-firstdiff` to find the first divergence,
  undo the rename (`git restore --staged . && git checkout -- .` or
  manually revert the straggler), rebuild, recheck md5, then commit.
- A commit with a wrong md5 contaminates the entire history. The
  defense is one-line: **never commit without md5 `ed1378bc…` printed
  by `make` in the same shell session.**

`make diff-init` only needs re-running when `expected/` becomes
stale (after a deliberate build-artifact change, **never after a
rename**). Renames do **not** change `expected/`.

**Never run a full `make NON_MATCHING=1`** (per `AGENTS.md`). Renames
are in matching code; `NON_MATCHING` is irrelevant.

---

## Commit message template

```
rename: <func_80029310> → <Game_HandleN64LogoIntro>

<one-line description of what it does>

Callers: Game_Thread (src/29BA0.c:798)
Callees: func_80005A20, func_80029500, …
Still matching: md5 ed1378bc… (verified by `make`)
```

The `Still matching: md5 ed1378bc…` line is **not optional metadata —
it is the commit-gate receipt.** If you cannot truthfully write that
line, you are not ready to commit (see "Hard precondition: md5 gate"
above).

For global renames, drop the Callees line. For struct fields, drop
both. For tool commits (Phase 0), use `tools:` prefix and skip the
matching-metadata lines — but **still include the md5 line**: tooling
commits must also leave the ROM matching.

---

## Pacing

Long campaign — hundreds of functions, thousands of struct fields.
Realistic cadence:

- 5–10 functions/week for obvious state handlers (Phase 2)
- 1–3 functions/week for tricky ones (need call-graph archaeology)
- **Pause to extend Rust tooling when the same question keeps coming
  up** — e.g. if you find yourself grepping the map file 10× per
  session, add a `--xref <symbol>` mode to `ps-status`.

Don't try to do all renames in one PR. The one-identifier-per-commit
structure keeps `git blame` and `git bisect` useful for years. A
single ill-named symbol that breaks md5 should be revertable in one
command.

**Every commit in this campaign must satisfy the md5 gate (see
"Hard precondition" above).** That is the campaign's only invariant.
If you ever find yourself rationalizing "this commit can skip the
md5 check because…" — stop, that is exactly how regressions sneak
into multi-month rename campaigns.

---

## Concrete first batch

After Phase 0 lands:

1. The 23 `Game_Thread` state handlers in `src/29BA0.c:796-870`,
   starting at `func_80029310` (top of the `switch`) and walking
   down. One commit per handler, easy to review.
2. Their direct helpers (`func_80000DF4`, `func_8002B310`).
3. The four Root 0 init helpers in `src/main.c` and `func_800196DC`.

That's ~30 commits for the first month. After that, Phase 3 subsystem
sub-phases.

---

## Cross-references

- `AGENTS.md` — matching-build rules, `NON_MATCHING` gotcha, per-file
  Makefile overrides, `make` / `make diff-init` semantics
- `docs/c-first-plan.md` — the C-first campaign (write C for every
  function); this rename plan runs in parallel and only touches
  already-matching C
- `tools/rust/README.md` — Rust-toolkit parity status, build & test
  commands, validation methodology