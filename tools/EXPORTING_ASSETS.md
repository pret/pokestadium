
## Export assets to standard media after building

After `make init` and a successful US 1.0 ROM build, use Python 3.9+ and the
repository's Python environment:

```powershell
python -m pip install Pillow crunch64
python tools/unpack_all_assets.py --version us --media --fetch-model-tools
```

On Windows, substitute `.\.venv\Scripts\python.exe` if needed. For a WSL/Linux
build environment, invoke `.venv/bin/python` inside that environment.
The main script requires its companion `tools/export_asset_media.py`.

The script reads packed bins from `assets/us/` and exports to `assets/exported/us/`.
It preserves the decompressed binary tree and adds a `media/` tree containing:

- **PNG:** Decoded Pokémon-model textures, 40x40 Pokémon icons, font glyphs and
  atlases, JPEG backgrounds, and source-backed UI texture rectangles.
- **GLB:** All successfully decoded Pokémon-model archive entries, including
  textures, skeletons and skeletal animations. Model JSON sidecars preserve
  expression/material tracks, callbacks, warnings, and raw decoded metadata.
- **WAV:** Numus instrument/SFX samples and MORT announcer/voice clips, decoded
  using the existing `tools/audio` implementations.
- **UTF-8 TXT/JSON:** Indexed strings from every decoded `textdata` table.
  Original bytes, token placeholders and control codes are retained.

The first `--fetch-model-tools` run downloads two SHA-256-verified Python modules
from revision `33dea39d52a36641bca9499ad8ad59774ac183ae` of
[DramaticShapeVoxelMod-latest's model pipeline](https://github.com/scottcandy34/DramaticShapeVoxelMod-latest/tree/33dea39d52a36641bca9499ad8ad59774ac183ae/model_extract/pipeline)
into `build/asset-export-tools/`. Later runs use the verified cache offline.
Alternatively, `--model-tools <model_extract/pipeline-directory>` uses an existing
copy at that exact revision. External decoder source is not included in this repo.
No generated fire/gas stand-ins are exported.

Audio needs the full ROM, defaulting to `build/pokestadium-us.z64` and then
`baseroms/us/baserom.z64`. Use `--rom <path>` to override. Its MD5 must match retail
US 1.0 because the audio helpers use target-specific offsets. Other targets are
not supported by `--media`; container-only unpacking still accepts `--version`.
Use `--media-types textures,models,text` to omit audio, or another comma-separated
subset of `textures,models,audio,text`.

`media/coverage.json` records output counts, conversion failures, unresolved
source texture calls, and leaves without media exports. This is not universal
coverage: dynamic UI textures and non-Pokémon scene/model formats can remain raw.
Sequenced music is not rendered to WAV or exported to MIDI. GLB does not reproduce
runtime callback effects or material/expression animation switching. Sample WAVs
are 32000 Hz engine-rate previews; instrument pitch can change playback speed.
Texture rectangles come from a limited C-source recognizer and explicit recipes,
not a full preprocessor or runtime renderer.

To add a known linear texture, pass `--texture-manifest recipes.json` with an array
of records containing `asset`, integer `offset`, `width`, `height`, `format`, and
`evidence`. Supported formats are `rgba16`, `rgba32`, `ia4`, `ia8`, `ia16`, `i4`,
`i8`, `ci4`, and `ci8`; CI formats also require an RGBA16 `palette_offset`.

Without `--media`, the script only unpacks containers/compression into
`assets/unpacked/<version>/`. Both modes leave build inputs and ROM bytes unchanged.
`manifest.json` records source/output hashes and decoding steps. Identical reruns
are safe; changed existing outputs are refused, so use `--output <fresh-directory>`
after changing options, inputs, recipes, or exporter code.
`--assets <directory>` selects another top-level packed-bin directory, and
`--repo <path>` selects another checkout. Generated input subdirectories are ignored
to avoid processing old unpacked views twice. The tool does not run the destructive
`make extract` target. A successful export does not verify ROM byte identity.

Exit status is 0 for successful selected exporters, 1 for a fatal setup/input/output
error, or 2 for per-resource conversion failures recorded in the coverage report.
Known unsupported structures are inventory items, not proof of successful conversion.