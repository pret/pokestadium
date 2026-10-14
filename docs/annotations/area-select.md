# Area-select annotation handoff

This annotation continues the human-authored [PR #258](https://github.com/michiiik/pokestadium/pull/258), based on `c48029c017486f0845f14a28103ac698667eb368`. The clean build baseline was its earlier `7aebfee9c805b0dd4c85b35850b4ec20fb199dcb`; the parent advanced during verification with only `CONTRIBUTING.md` changes, which were incorporated before publication. It preserves the parent's matched C, declaration order, types, array lengths, integer arithmetic, and branch structure; recovered names are interpretations, not original Nintendo identifiers.

## Selection and animation

The parent's exit-state table sends entry 0 to `STATE_STADIUM_MENU` and entry 8 to `STATE_MENU_SELECT`, and input refuses to navigate to entry 8. Accordingly, entry 0 is `AREA_STADIUM`, while entry 8 is `AREA_NONE`, the blocked-neighbor, initial-position, and cancel-exit sentinel. The existing `AREA_STADIUM = 8` and “unused?” comment on entry 0 conflated these roles. Evidence: `sAreaSelectStateIds`, `AreaSelect_HandleInput`, `AreaSelect_Loop`, and `AreaSelect_Main` in [the parent area-select source](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/area_select/area_select.c).

`AreaSelect_DrawNameBannerCrossfade` takes a menu-loop state, not an area index: `AreaSelect_Draw` passes its state argument directly, and state 2 invokes the six-frame cursor interpolation. Thus the previous comment describing a Gym Leader Castle-specific faster crossfade was incorrect; the apparent castle value was the numerically identical menu state 2. Its function-static offset/direction independently make visible banners bob vertically. Evidence: the parent `AreaSelect_Draw`, `AreaSelect_Loop`, and banner function in [area_select.c](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/area_select/area_select.c).

| State | Named state | Observed operation |
|---|---|---|
| 0 | `AREA_SELECT_INTRO` | Intro fade rendering without banners/info text |
| 1 | `AREA_SELECT_INPUT` | Poll A/B/D-pad and display description |
| 2 | `AREA_SELECT_MOVE` | Interpolate cursor center/radius over six frames; crossfade labels |
| 3 | `AREA_SELECT_SHRINK` | Shrink the Magnemite scale, then select ordinary/Mewtwo exit |
| 4 | `AREA_SELECT_CANCEL` | Fade out to white and set cancel sentinel |
| 5 | `AREA_SELECT_EXIT_FADE` | Raise area-color alpha, blend toward black, check cartridge signature |
| 6 | `AREA_SELECT_MEWTWO_EXIT` | Expand the circular glow and fade out to white |
| 7 | `AREA_SELECT_DONE` | Terminate the menu loop |
| 8 | `AREA_SELECT_REVEAL_MEWTWO` | Crossfade the island background, then move from the sentinel to Stadium |

The table is a transcription of the parent switch and its transition returns, not emulator observations. See [the parent area-select loop and rendering path](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/area_select/area_select.c).

## Local structures and functions

- **Entry config**: `x`, `y`, `orbitRadius`, four directional neighbor indices, and `exitColor` follow directly from input dispatch, interpolation, and exit-fade initialization.
- **Magnemite point**: `diameter` replaces `offset`; the vertex builder divides it by two to position opposite corners.
- **Magnemite trail**: `centerX`, `centerY`, `orbitRadius`, `scalePercent`, `orbitAngle`, and `spriteFrame` follow the trigonometric orbit, scale calculation, angle decrement, and texture-table index. The parent human annotation already identifies the sprite as Magnemite; this PR retains that identity rather than independently decoding it again.
- **Exit fade**: `AreaSelectExitFade` stores center, `halfExtent`, `blackBlendAlpha`, and color. The eight-vertex builder emits the inner quad and outer surround; the draw function interpolates the shade color toward black. It is separate from the circular Mewtwo glow.
- **Named operations**: `BuildExitFadeVertices`, `DrawExitFade`, `DrawAndAdvanceMagnemites`, `DrawMewtwoMarker`, `UpdateCursorMove`, `ShrinkMagnemites`, `UpdateExitFade`, `UpdateMewtwoExit`, `UpdateCancelFade`, and `RevealMewtwo` replace misleading or incomplete function names. Definitions, prototypes, callers, and all ten targets' function-symbol lists change together.

These are body-derived annotations of [the parent area-select structures and functions](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/area_select/area_select.c). They do not claim original identifier recovery.

## Shared imports

- **ModeSettings**: `clearedModes` is a bitmask updated with `1 << gSessionContext.mode`. `castleClears`, `nintendoCupClears`, and `primeCupClears` store the highest completed location/division plus one; the writer caps castle updates below location 8 and division updates below division 4. `mewtwoUnlocked`, previously `fadeProgress`, is set to one when the cleared-mode mask reaches `0xF8`, and area select uses it to enable navigation to Mewtwo. Evidence: `BattlePrep_MarkCupCleared`, `BattlePrep_MarkNewRoundRecord`, and the area-select navigation guard in [battle prep](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/battle_prep/battle_prep_394120.c) and [area select](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/area_select/area_select.c).
- **GameOptions**: `gbTowerUnlockTier`, previously `gbTowerSpeed`, is incremented on qualifying first cup clears and capped at two; area select consumes it to choose the normal/Doduo/Dodrio banner and background variants. This is not a claim about the currently selected emulator speed. The inherited offset-4 pointer declaration is retained as an opaque Tower round-trip word; its stronger semantic identity is unresolved. Evidence: `BattlePrep_MarkFirstClearBonus` in [battle prep](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/battle_prep/battle_prep_394120.c), `State_GbTower` in [game_state.c](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/game_state.c), and [the inherited save declarations](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/save_data.h).
- **SessionContext**: the parent's `inRound2` name is retained. `SESSION_FLAG_REVEAL_MEWTWO = 0x04` names the bit set by cup completion, consumed by area-select reveal, and cleared when that reveal finishes. The original `0xFFFB` clear mask is preserved as the constant expression `0xFFFF ^ SESSION_FLAG_REVEAL_MEWTWO`, not replaced with a differently typed complement. Evidence: the producer in [battle prep](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/battle_prep/battle_prep_394120.c) and consumer in [area select](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/area_select/area_select.c).
- **StageContext**: the anonymous `unk_func_80007444` type becomes `StageContext`, consistently with its existing API. Confident fields name image dimensions, clear bounds, image count/index, depth-buffer request, fade duration/frame, and image pointers. Unknown request bytes at `0x0D` and `0x10` remain unknown; `zoom`, `fade_mode`, and `clear_color` retain their existing names with explanatory comments. Evidence: allocation, image attachment, render-target selection, and fade progression in [stage_loader.c](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/stage_loader.c).
- **UI display lists**: `gUiTranslucentFillDL` describes the AA translucent primitive-fill commands at `D_8006F498`; `gUiEnvTintTextureDL` describes the environment-tinted, nonperspective texture state at `D_8006F518`; `gUiRestoreTextureDL` describes the perspective/alpha-compare restoration at `D_8006F630`. The last list does not reset every graphics state. Its existing byte-addressed glyph lookup in `Font_MapGlyphCode` is also renamed, without moving its base or rewriting the lookup. Evidence: command arrays in [ui_graphics.c](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/ui_graphics.c).
- **Identity matrix**: `gIdentityMtx` names `D_8006F010`, whose fixed-point integer half encodes the diagonal ones and whose fractional half is zero. Evidence: the initializer in [matrix.c](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/matrix.c).
- **Menu textures**: the parent's R-2 badge import becomes `gRound2BadgeTexture`; the four panel corner symbols are named for their actual top/bottom and left/right drawing positions. The circular glow becomes `sAreaSelectGlowCircleTexture`. All declarations, use sites, explicit address lists, and regional `PROVIDE` bindings are synchronized. The reusable segment-base symbols `D_1000000`, `D_2000000`, and `D_3000000` retain their names because multiple different archives occupy those bases. Evidence: texture loads and geometry in [area_select.c](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/area_select/area_select.c).
- **Existing APIs**: already meaningful input/controller, graphics, matrix/color, font/text, archive, audio/cry, stage, memory-pool, and save function names are retained. Clear imported argument roles are added for viewport dimensions, display-list buffer allocation, save-option loading, round-progress loading, and stage allocation; unused shared fields are not guessed merely to eliminate every `unk_*` token.

### Regional symbol bindings

The target-specific existing bindings, rather than US offsets copied to every target, are authoritative. Japan's glow is `0x0303A260` and its panel corners are `0x020288C0`, `0x02028900`, `0x02028940`, and `0x02028980`; France, Germany, and Italy bind the R-2 badge to `0x02006C00`. This is a mechanical preservation of the parent's `linker_scripts/<version>/undefined_syms.ld`, independently checked by each target's successful full-ROM byte comparison.

## Preserved unknowns and declaration problems

- **Empty retail function**: `func_822014C0` has no body to support a purpose name. It retains its address-based name and an explicit unknown-purpose comment.
- **Trail overlap**: `AreaSelectMagnemiteTrail` has four declared afterimages and size `0x24`, but the shift and draw loops access indices through five. This PR labels the inherited declaration `// FAKE` and preserves its stride, overlapping accesses, and adjoining padding. It does not claim these C-level out-of-bounds accesses prove a bug in Nintendo's original source.
- **Saved round records**: the inherited `SaveOptionsRecord.unk_0C[1]` plus eight following bytes remains unchanged although the save getters index by round 0/1. No save-layout repair is bundled.
- **Cartridge guard**: the inherited `AreaSelect_CheckCartRemoved` name is retained, but its comment identifies the actual idle-PI/signature predicate rather than claiming a hardware-removal experiment. Its exceptional `-0x40` result remains unchanged.
- **Unknown data**: GameOptions offset 4, StageContext request bytes `0x0D`/`0x10`, padding, unused entry points, and untouched imported internals are not assigned guessed meanings.
- **Empty conditional**: the existing `if (1) {}` in the glow renderer is marked `// karodo`, as required by the repository guide, and not removed.

Evidence is the parent declarations in [save_data.h](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/save_data.h), [stage_loader.c](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/stage_loader.c), and [area_select.c](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/area_select/area_select.c).

## Verification

The clean parent at `7aebfee9c805b0dd4c85b35850b4ec20fb199dcb` passed a fresh Linux US 1.0 production build and direct retail comparison before edits. After annotation, all ten versions passed extraction, normal production compilation/linking, their repository MD5 gate, and direct whole-ROM `cmp`; US 1.0 additionally passed a forced production rebuild. The final source changes were rebuilt and compared across all ten versions again.

| Target | Full-ROM result | Output and retail MD5 |
|---|---|---|
| US 1.0 | Identical | `ed1378bc12115f71209a77844965ba50` |
| US Rev. 1 | Identical | `40e03eda831c01e0a12294287fd240e2` |
| US Rev. 2 | Identical | `6dc6820cef755fc1253d06df45c9bd2a` |
| Japan | Identical | `2449bb712a64e3363a6cbd56f5adeda5` |
| Europe | Identical | `2859090d78581e0925a3af8045e81e4b` |
| Europe Rev. 1 | Identical | `31ee2de8e65e30f5934c450dbaa924f0` |
| France | Identical | `0e85a098d0f0e8a7eb572a69612a6873` |
| Germany | Identical | `24be2ccb0dea0755908c02bf67e22fe5` |
| Spain | Identical | `d14a499bc4e324974eae3e42dec58625` |
| Italy | Identical | `a81321759af38beb30a40fdaca2ea22a` |

These are local build/comparison observations, not inherited CI reports. `make extract VERSION=<target>` used the existing checked-in target configuration; no `port_version.py` regeneration or new configuration was required for these byte-identical builds.

A separate GCC `-m32` syntax-check translation unit includes area select and asserts the sizes of all four local structures, `GameOptions`, `ModeSettings`, and `StageContext`, plus 15 relevant member offsets. All assertions passed using the repository's host-check defines. This is an additional 32-bit host-layout control, not a replacement for the production IDO full-ROM comparisons.

Game compiler: repository-provided Linux IDO 7.1, SHA-256 `3864adf8b9f66dc5691bef3ed9083c5210217dc003f7460df5bd9386f78b4a5c`. Library compiler: repository-provided Linux IDO 5.3, SHA-256 `43f58f6c073dcfe8bcfbfd84ee69d5b346a079847eab561a41e04f98a4031b54`. Default matching and comparison flags remain enabled; no output patch, compiler substitution, or comparison bypass was used.

Reproduction, in PowerShell command notation:

```powershell
make extract VERSION=us
make -j8 VERSION=us
make -B -j8 rom VERSION=us
cmp build/pokestadium-us.z64 baseroms/us/baserom.z64

$versions = "us_rev1", "us_rev2", "jp", "eu", "eu_rev1", "fr", "de", "es", "it"
foreach ($version in $versions) {
    make extract "VERSION=$version"
    if ($LASTEXITCODE -ne 0) { throw "Extraction failed: $version" }
    make -j6 "VERSION=$version"
    if ($LASTEXITCODE -ne 0) { throw "Build or checksum failed: $version" }
    cmp "build/$version/pokestadium-$version.z64" "baseroms/$version/baserom.z64"
    if ($LASTEXITCODE -ne 0) { throw "ROM differs: $version" }
}
git diff --check
```

The actual execution used the Linux sandbox. `cmp` is the GNU utility, not a claim that bare Windows has that command installed.

## Sanity check

ROM identity establishes output preservation for these ten local Linux builds, not semantic correctness or recovered original names. No emulator, hardware, audio-playback, Windows/macOS, or Docker-overlay validation was performed. Existing compiler warnings remain; successful checks with the default `WERROR=0` do not mean warning-free code. Names for decoded artwork inherit the parent's human annotation and prior project findings, while state/field/command roles above were checked against source consumers and producers.
