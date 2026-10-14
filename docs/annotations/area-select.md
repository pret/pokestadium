# Area-select annotation evidence

This document records source and ROM evidence for the area-select annotations in [PR #259](https://github.com/michiiik/pokestadium/pull/259), stacked on [PR #258](https://github.com/michiiik/pokestadium/pull/258). The annotations preserve declaration order, types, array lengths, integer arithmetic, and branch structure. Semantic names describe observed uses; they are not recovered Nintendo identifiers. Historical build results below identify the revisions tested.

## Selection and animation

The exit-state table sends entry 0 to `STATE_STADIUM_MENU` and entry 8 to `STATE_MENU_SELECT`, and input refuses to navigate to entry 8. Entry 0 is therefore `AREA_STADIUM`; entry 8 is `AREA_NONE`, the blocked-neighbor, initial-position, and cancel-exit sentinel. Evidence: `sAreaSelectStateIds`, `AreaSelect_HandleInput`, `AreaSelect_Loop`, and `AreaSelect_Main` in [area_select.c at the artwork-review revision](https://github.com/michiiik/pokestadium/blob/93a61c5a99e732fee5e871c173e16ba67e998ed4/src/fragments/area_select/area_select.c).

`AreaSelect_DrawNameBannerCrossfade` takes a menu-loop state: `AreaSelect_Draw` passes its state argument directly, and `AREA_SELECT_MOVE` (2) invokes the six-frame cursor interpolation and label crossfade. Its function-static offset/direction independently make visible banners bob vertically. Evidence: `AreaSelect_Draw`, `AreaSelect_Loop`, and the banner function in [area_select.c](https://github.com/michiiik/pokestadium/blob/93a61c5a99e732fee5e871c173e16ba67e998ed4/src/fragments/area_select/area_select.c).

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
- **Magnemite trail**: `centerX`, `centerY`, `orbitRadius`, `scalePercent`, `orbitAngle`, and `spriteFrame` follow the trigonometric orbit, scale calculation, angle decrement, and texture-table index. The parent human annotation identifies the sprite as Magnemite; the follow-up ROM review below independently decodes its three unique frames.
- **Exit fade**: `AreaSelectExitFade` stores center, `halfExtent`, `blackBlendAlpha`, and color. The eight-vertex builder emits the inner quad and outer surround; the draw function interpolates the shade color toward black. It is separate from the circular Mewtwo glow.
- **Named operations**: `BuildExitFadeVertices`, `DrawExitFade`, `DrawAndAdvanceMagnemites`, `DrawMewtwoMarker`, `UpdateCursorMove`, `ShrinkMagnemites`, `UpdateExitFade`, `UpdateMewtwoExit`, `UpdateCancelFade`, and `RevealMewtwo` replace misleading or incomplete function names. Definitions, prototypes, callers, and all ten targets' function-symbol lists change together.

These are body-derived annotations of [the parent area-select structures and functions](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/area_select/area_select.c). They do not claim original identifier recovery.

## Direct ROM artwork review

The follow-up review decodes the supplied US 1.0 ROM with MD5 `ed1378bc12115f71209a77844965ba50`. The `PERS-SZP` assets at `0x4D1330..0x4EB0C0` (`area_select_ui`) and `0x4BE810..0x4D1330` (`common_menu2_ui`) are Yay0-decompressed and compared byte-for-byte with the repository's extracted assets; formats, dimensions, and offsets are taken from [the parent area-select texture loads](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/area_select/area_select.c).

- **Cursor identity**: the 36x36 RGBA16 frames at `0x03005000`, `0x03005A20`, and `0x03006440` visibly show Magnemite.
- **Round badge**: the 36x36 RGBA16 texture at `0x020144E0` explicitly reads `R-2`; its raw-byte SHA-256 is `f97fd43c8cec7b987d9ead5a1d488f17cd07cc485140bf5d47896defefffff5e`.
- **Area banners**: the ten 196x64 RGBA16 images read `STADIUM`, `FREE BATTLE`, `GYM LEADER CASTLE`, `VS MEWTWO`, `KIDS CLUB`, `VICTORY PALACE`, `POKEMON LAB`, `GB TOWER`, `DODUO GB TOWER`, and `DODRIO GB TOWER`. Entry 0 at `0x03006E60` therefore independently supports the Stadium name. Banner entries 8/9 are selected by adding Tower unlock tier to area index 7; they are not extra selectable areas, and banner entry 8 is not the meaning of `AREA_NONE`.
- **Mewtwo marker**: all twenty 48x40 I4 frames in `sAreaSelectMarkerTextures` show the animated long-tailed Mewtwo silhouette, supporting the source-derived location/unlock role.
- **Glow and exit fade**: `0x03044260` is a 64x64 I4 soft-edged filled circle. The first texture at segment `0x03000000` is a separate 64x32 I8 gradient mask, used with mirroring by the selected-area exit renderer; it is not another Magnemite sprite.
- **Panel corners**: the four 16x8 I4 images at `0x02028A60`, `0x02028AA0`, `0x020289E0`, and `0x02028A20` visibly match top-left, top-right, bottom-left, and bottom-right orientations.

These are direct decoder and visual-review observations, not runtime screenshots or an RDP compositing recreation. The exact extraction manifest, decoder, native images, and contact sheets are preserved in the Project's area-select handoff artifacts rather than added as new files to this PR.

## Number-formatting follow-up

The updated [CONTRIBUTING.md](https://github.com/michiiik/pokestadium/blob/master/CONTRIBUTING.md) additionally permits colors and one-off power-of-two-minus-one values in hex. The area-select follow-up restores RGBA constants, alpha-channel thresholds/steps, and `0xFF`/`0xFFFF` spellings while leaving ordinary dimensions, counts, indices, and nonqualifying values decimal. A token-normalization comparison verifies that the formatting edit changes no numeric value or nonnumeric code token.

At revision `93a61c5a99e732fee5e871c173e16ba67e998ed4`, all ten targets were rebuilt with the production toolchain and passed their checksum verifier and direct full-ROM retail comparison. Those results apply to that revision, not automatically to subsequent edits.

## Shared imports

- **ModeSettings**: `clearedModes` is a bitmask updated with `1 << gSessionContext.mode`. `castleClears`, `nintendoCupClears`, and `primeCupClears` store the highest completed location/division plus one; the writer caps castle updates below location 8 and division updates below division 4. `mewtwoUnlocked` is set to one when the cleared-mode mask reaches `0xF8`, and area select uses it to enable navigation to Mewtwo. Evidence: `BattlePrep_MarkCupCleared`, `BattlePrep_MarkNewRoundRecord`, and the area-select navigation guard in [battle prep](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/battle_prep/battle_prep_394120.c) and [area select](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/area_select/area_select.c).
- **GameOptions**: `gbTowerUnlockTier` is incremented on qualifying first cup clears and capped at two; area select consumes it to choose the normal/Doduo/Dodrio banner and background variants. The offset-4 word is carried into and out of GB Tower; its pointer role remains unknown. Evidence: `BattlePrep_MarkFirstClearBonus` in [battle prep](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/battle_prep/battle_prep_394120.c), `State_GbTower` in [game_state.c](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/game_state.c), and [save_data.h](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/save_data.h).
- **SessionContext**: the parent's `inRound2` name is retained. `SESSION_FLAG_REVEAL_MEWTWO = 0x04` names the bit set by cup completion, consumed by area-select reveal, and cleared when that reveal finishes. The original `0xFFFB` clear mask is preserved as the constant expression `0xFFFF ^ SESSION_FLAG_REVEAL_MEWTWO`, not replaced with a differently typed complement. Evidence: the producer in [battle prep](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/battle_prep/battle_prep_394120.c) and consumer in [area select](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/area_select/area_select.c).
- **StageContext**: fields describe render dimensions, clear bounds, render-target count/index, depth-buffer allocation, and fade duration/frame. Request bytes at `0x0D` and `0x10` remain unknown. `fadeMode` and `clearColor` describe the fade-state selector and RGBA5551 clear/fade color; the render-target evidence is detailed below.
- **UI display lists**: `gUiTranslucentFillDL` describes the AA translucent primitive-fill commands at `D_8006F498`; `gUiEnvTintTextureDL` describes the environment-tinted, nonperspective texture state at `D_8006F518`; `gUiRestoreTextureDL` describes the perspective/alpha-compare restoration at `D_8006F630`. The last list does not reset every graphics state. Its existing byte-addressed glyph lookup in `Font_MapGlyphCode` is also renamed, without moving its base or rewriting the lookup. Evidence: command arrays in [ui_graphics.c](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/ui_graphics.c).
- **Identity matrix**: `gIdentityMtx` names `D_8006F010`, whose fixed-point integer half encodes the diagonal ones and whose fractional half is zero. Evidence: the initializer in [matrix.c](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/matrix.c).
- **Menu textures**: the parent's R-2 badge import becomes `gRound2BadgeTexture`; the four panel corner symbols are named for their actual top/bottom and left/right drawing positions. The circular glow becomes `sAreaSelectGlowCircleTexture`. All declarations, use sites, explicit address lists, and regional `PROVIDE` bindings are synchronized. The reusable segment-base symbols `D_1000000`, `D_2000000`, and `D_3000000` retain their names because multiple different archives occupy those bases. Evidence: texture loads and geometry in [area_select.c](https://github.com/michiiik/pokestadium/blob/area_select_annotation/src/fragments/area_select/area_select.c).
- **Existing APIs**: already meaningful input/controller, graphics, matrix/color, font/text, archive, audio/cry, stage, memory-pool, and save function names are retained. Clear imported argument roles are added for viewport dimensions, display-list buffer allocation, save-option loading, round-progress loading, and stage allocation; unused shared fields are not guessed merely to eliminate every `unk_*` token.

### StageContext render targets

The field at `0x18` is `renderTargets[3]`, an array of pointers to `unk_D_80068BB0` descriptors. Each descriptor holds format, pixel size, dimensions, an `img_p` pixel-buffer pointer, and an optional `depth_p` descriptor. The array stores descriptors, not texture bytes or raw framebuffer addresses; see [gfx_rect.h](https://github.com/michiiik/pokestadium/blob/93a61c5a99e732fee5e871c173e16ba67e998ed4/src/gfx_rect.h).

- **Allocation**: `StageContext_Allocate` creates the requested number of 16-bit color-buffer descriptors and optionally attaches one shared depth-buffer descriptor. `GfxImage_Allocate` allocates descriptor plus pixel storage and aligns `img_p` to 64 bytes; see [stage_loader.c](https://github.com/michiiik/pokestadium/blob/93a61c5a99e732fee5e871c173e16ba67e998ed4/src/stage_loader.c) and [gfx_rect.c](https://github.com/michiiik/pokestadium/blob/93a61c5a99e732fee5e871c173e16ba67e998ed4/src/gfx_rect.c).
- **Rendering**: `StageLoader_SetupFrame` and `BgStage_DrawFrame` pass the indexed descriptor to `GfxImage_SetRenderTarget`. That function issues `gDPSetColorImage` with the descriptor's `img_p` as the RDP color destination, and `gDPSetDepthImage` when a depth buffer is attached. These commands establish the render-target role independently of the C function names; see [gfx_rect.c](https://github.com/michiiik/pokestadium/blob/93a61c5a99e732fee5e871c173e16ba67e998ed4/src/gfx_rect.c).
- **Cycling**: `StageLoader_BeginFrame` copies the selected descriptor into `D_800A7450.unk_0C`, then increments the index and wraps it at the count. These operations justify `renderTargetIndex` and `renderTargetCount`; see [stage_loader.c](https://github.com/michiiik/pokestadium/blob/93a61c5a99e732fee5e871c173e16ba67e998ed4/src/stage_loader.c).
- **Presentation**: the display worker copies the frame request into its queued buffer configuration and eventually passes the selected descriptor's `img_p` to `osViSwapBuffer`. Thus these descriptors also supply display buffers; see `DisplayWorker_SetBufferConfig` and `DisplayWorker_ProcessFrame` in [dp_intro.c](https://github.com/michiiik/pokestadium/blob/93a61c5a99e732fee5e871c173e16ba67e998ed4/src/dp_intro.c).

The pinned evidence revision spells these fields `images`, `imageIndex`, and `imageCount`. The corrected names express their roles without changing their offsets, types, or the three-slot array. The existing `StageContext_GetCurrentImage` API returns the selected descriptor; its symbol is retained because regional assembly callers use that name. These conclusions come from source data flow, not a runtime buffer trace or original-symbol recovery.

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

The clean parent at `7aebfee9c805b0dd4c85b35850b4ec20fb199dcb` passed a fresh Linux US 1.0 production build and direct retail comparison before annotation. Annotation revision `b1681b88918b5fd5e13a041e3ec51ed6fc89124e` and artwork/formatting revision `93a61c5a99e732fee5e871c173e16ba67e998ed4` passed all ten production builds, repository MD5 gates, and direct whole-ROM `cmp`. US 1.0 additionally passed a forced production rebuild. The following table records those historical results.

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

### Render-target field correction

The correction is based on `b48c24a93e4836bf194d3ab69a9351d0f2205a49`. That revision renamed the header members to `fadeMode` and `clearColor`, but `stage_loader.c` still referenced `fade_mode` and `clear_color`, causing the initial US build to fail with missing-member errors. Propagating those two case changes restored a byte-identical US production baseline before the render-target renames.

After the field correction, all ten targets in the table above passed normal Linux production builds, repository checksum gates, and direct whole-ROM `cmp` again. A normalized-token comparison checked that source edits consist only of identifier renames and comments. Seven 32-bit structure-size assertions and fifteen member-offset assertions passed again with the corrected field names. The changed paths remain within the existing PR diff. The `StageContext_GetCurrentImage` API symbol remains compatible with regional assembly callers, including Japan's `fragment64_3AFAB0`.

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

ROM identity establishes output preservation for these ten local Linux builds, not semantic correctness or recovered original names. No emulator, hardware, audio-playback, Windows/macOS, or Docker-overlay validation was performed. Existing compiler warnings remain; successful checks with the default `WERROR=0` do not mean warning-free code. The follow-up independently decodes the US 1.0 artwork described above; other-region artwork and live compositing remain unverified, while state/field/command roles were checked against source consumers and producers.
