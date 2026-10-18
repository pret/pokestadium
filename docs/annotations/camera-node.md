# Camera scene-graph node annotation

This annotation names `unk_D_86002F34_00C` as `CameraNode` and its five camera-owned sub-structs. Names are reconstructed from inspected producers and consumers, not recovered original identifiers or runtime observations.

## Naming boundary

A field receives a descriptive name only when it has at least five type-resolved written access sites in the source snapshot at `fa20a87f63665951ab3f414204681196ec17b739`. This applies to every field of the camera-owned sub-structs, including fields that previously had descriptive names. Below-threshold fields use `unk_<offset>`; the cutoff is an annotation policy, not a claim that their operations are unknowable.

The six records contain 47 fields: 24 meet the cutoff and 23 remain offset-named. The embedded `GraphNode` retains its existing nine annotations; all nine meet the same cutoff. Shared vector, matrix, color and libultra component types are unchanged.

Counts distinguish the declaring struct, ignore declarations/comments, and count each physical `.field` or `->field` token once. Repeated macro expansion, header inclusion and regional rescans do not multiply a written site. Counts are the union of the US, US Rev. 1, US Rev. 2, Japan and PAL source-branch scans, not execution frequencies.

## Source evidence

- **CameraNode:** `GeoNode_CreateCamera` initializes viewport, perspective, eye/target/up and overlay blocks before calling `GeoNode_Init(..., 2)`. `Geo_NodeCamera` allocates render data for those blocks, establishes the active camera, traverses children unless the overlay is solid, and then draws the overlay. The geo-layout camera command also fills its field of view and eye/target vectors. [Constructor](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_node.c#L59), [renderer](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_render.c#L412), [layout command](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_layout.c#L170).
- **CameraViewport:** `GeoCamera_SetViewport` supplies the pixel rectangle. `Geo_NodeCamera` converts its dimensions and origin into `Vp` translations/scales and an RDP scissor; background/depth clearing uses the same rectangle. [Setter](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_node.c#L474), [viewport conversion](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_render.c#L420).
- **CameraPerspective:** The setter supplies the field of view and near/far planes. The renderer passes these values directly to `guPerspective`, whose implementation converts the field of view from degrees to radians and computes its projection from those clipping planes. `Geo_NodePerspective` submits the resulting matrix. [Setter](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_node.c#L489), [consumer](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_render.c#L438), [libultra implementation](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/lib/ultralib/src/gu/perspective.c#L17).
- **CameraOrthographic:** The renderer consumes this block through `guOrtho`; orthographic graph nodes and the overlay reuse its matrix. The record's role is supported even though none of its individual fields reaches five written accesses. [Consumer](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_render.c#L437), [orthographic node](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_render.c#L506).
- **CameraView:** `GeoCamera_SetEyeAtUp` sets the three vectors. `Geo_NodeCamera` passes them to `guLookAtReflectF`, then converts the float matrix through `MtxF_ToFixed`; the perspective node submits that fixed-point result. `MtxF_ToFixed` explicitly writes the integer/fraction halves of packed 16.16 values. Its `MtxF*` output declaration is preserved without a type repair. [Vector setter](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_node.c#L497), [matrix construction](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_render.c#L439), [packed conversion](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/matrix.c#L593).
- **CameraOverlay:** `GeoCamera_SetBackground` selects its mode and initializes the step count/index and color for a transition. `GeoOverlay_Draw` dispatches solid/fade modes or textured geometry; the fade and rotating-quad consumers interpolate using step index divided by step count, increment after a draw, and select a terminal mode when the count is reached. Battle-camera code starts modes 4/5 and observes the step index. This supports draw-step names without assuming elapsed real time. [Producer](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_node.c#L511), [fade consumer](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_render.c#L202), [rotating-quad consumer](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_render.c#L276), [dispatch](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/geo_render.c#L358), [battle-camera callers](https://github.com/michiiik/pokestadium/blob/fa20a87f63665951ab3f414204681196ec17b739/src/fragments/battle_engine/battle_engine_313D60.c#L109).

## Field decisions

The following counts are frozen to the revision above. Offset-named fields deliberately receive no new semantic annotation, even when a direct library call supplies a plausible interpretation.

| Original record | Original field | Written mentions | Accepted field |
|---|---|---:|---|
| `unk_D_86002F34_00C` | `node` | 20 | `node` |
| | `unk_18` | 24 | `viewport` |
| | `unk_24` | 140 | `perspective` |
| | `unk_40` | 9 | `orthographic` |
| | `unk_60` | 492 | `view` |
| | `unk_CC` | 6 | `overlay` |
| | `unkEC` | 0 | `unk_EC` |
| `unk_D_86002F34_00C_018` | `vp` | 8 | `rspViewport` |
| | `x` | 9 | `x` |
| | `y` | 9 | `y` |
| | `width` | 10 | `width` |
| | `height` | 12 | `height` |
| `unk_D_86002F34_00C_024` | `mtx` | 5 | `projectionMatrix` |
| | `perspNorm` | 4 | `unk_04` |
| | `fovy` | 76 | `verticalFieldOfView` |
| | `aspect` | 3 | `unk_0C` |
| | `near` | 29 | `nearPlane` |
| | `far` | 28 | `farPlane` |
| | `scale` | 2 | `unk_18` |
| `unk_D_86002F34_00C_040` | `mtx` | 4 | `unk_00` |
| | `l` | 4 | `unk_04` |
| | `r` | 4 | `unk_08` |
| | `b` | 4 | `unk_0C` |
| | `t` | 4 | `unk_10` |
| | `n` | 2 | `unk_14` |
| | `f` | 2 | `unk_18` |
| | `scale` | 2 | `unk_1C` |
| `unk_D_86002F34_00C_060` | `p_mtxf` | 5 | `fixedMatrix` |
| | `mtxf` | 19 | `floatMatrix` |
| | `lookat` | 4 | `unk_44` |
| | `eye` | 207 | `eyePosition` |
| | `at` | 261 | `targetPosition` |
| | `up` | 14 | `upDirection` |
| `unk_D_86002F34_00C_0CC` | `unk_00` | 17 | `mode` |
| | `unk_02` | 2 | `unk_02` |
| | `color` | 18 | `color` |
| | `unk_08` | 8 | `stepCount` |
| | `unk_0A` | 12 | `stepIndex` |
| | `unk_0C` | 3 | `unk_0C` |
| | `unk_0E` | 2 | `unk_0E` |
| | `unk_10` | 3 | `unk_10` |
| | `unk_12` | 3 | `unk_12` |
| | `unk_14` | 2 | `unk_14` |
| | `unk_16` | 2 | `unk_16` |
| | `unk_18` | 3 | `unk_18` |
| | `unk_1A` | 2 | `unk_1A` |
| | `texture` | 3 | `unk_1C` |

## Scope and verification

Only camera type/member identifiers, the necessary usage-site updates, and annotation comments/documentation are in scope. Function/global/local variable renames, numeric cleanup, layout repairs and behavior changes are excluded.

Some legacy pointer views are broader than their declared payload. `GraphNode.children` still uses a camera pointer for a list that can contain other graph-node types, and `Geo_NodeModelPartRoot` accesses only the embedded graph header through its camera-shaped cast. The cast is marked `FAKE`; neither declaration is repaired or used as evidence that every pointed-to object is a camera.

Before integration, the untouched revision built US 1.0 with repository IDO tools using `make init VERSION=us RUN_CC_CHECK=0 N_THREADS=8 -j8`. The normal ROM gate reported MD5 `ed1378bc12115f71209a77844965ba50`; a direct comparison with the verified retail input also passed. This result does not verify the modified source.

The annotated source then passed a clean `make clean VERSION=us RUN_CC_CHECK=0` followed by `make VERSION=us RUN_CC_CHECK=0 N_THREADS=8 -j8`, with the same normal retail MD5 gate. Independent layout/declaration checks covered all 56 fields across the six camera records and `GraphNode`, including all 47 camera-field cutoff decisions. A fresh typed reference audit preserved every camera-field count and the repository-wide totals of 397 fields and 5,406 written references, with no parser errors or unresolved target matches.

Source names and comments are evidence-backed interpretations, not runtime verification or recovered original names. No emulator/hardware observation or other-region ROM build has been performed; the local host warning checker was disabled for both production-toolchain builds.
