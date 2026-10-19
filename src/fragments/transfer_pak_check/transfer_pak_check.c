#include "transfer_pak_check.h"
#include "src/geo_render.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/gb_data.h"
#include "src/pokemon_stats.h"
#include "src/game_state.h"
#include "src/session.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx.h"
#include "src/gfx_buffer.h"
#include "src/controller_ram.h"
#include "src/DDC0.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/geo_layout.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "PR/rcp.h"

#if defined(VERSION_JP)
extern u8 D_03004E20_jp[];
#endif

static GraphNode* D_82D09FF0;
static DisplayObject D_82D09FF8[8];
static Pak_PortStatus D_82D0AB38[4];
static ModeSettings D_82D0AB90;
static u16 D_82D0AB98;
#if defined(VERSION_JP)
// JP .bss order (ROM addresses 0x82D0A4AC-0x82D0A50C). D_82D0AB9C is unused in JP (no string
// table is loaded) but its slot remains; D_82D0ABA0-D_82D0ABA8 and D_82D0AC0C are absent.
static char** D_82D0AB9C;
static PakUi_StatusPopup D_82D0ABD0;
static DepthBuffer* D_82D0ABE0[8];
static GraphNode* D_82D0AC00;
static GraphNode* D_82D0AC04;
static GraphNode* D_82D0AC08;
static GraphNode* D_82D0ABAC;
static GraphNode* D_82D0ABB0;
static GraphNode* D_82D0ABB4;
static DepthBuffer* D_82D0ABB8[4];
static DepthBuffer* D_82D0ABC8;
static DepthBuffer* D_82D0ABCC;
#else
static char** D_82D0AB9C;
static s32 D_82D0ABA0;
static s32 D_82D0ABA4;
static s32 D_82D0ABA8;
static GraphNode* D_82D0ABAC;
static GraphNode* D_82D0ABB0;
static GraphNode* D_82D0ABB4;
static DepthBuffer* D_82D0ABB8[4];
static DepthBuffer* D_82D0ABC8;
static DepthBuffer* D_82D0ABCC;
static PakUi_StatusPopup D_82D0ABD0;
static DepthBuffer* D_82D0ABE0[8];
static GraphNode* D_82D0AC00;
static GraphNode* D_82D0AC04;
static GraphNode* D_82D0AC08;
static GraphNode* D_82D0AC0C;
#endif

// ModeSettings.clearedModes value that unlocks the Round 2 toggle (C-Right) and its header prompt.
#if defined(VERSION_JP)
#define PAKUI_ALL_MODES_CLEARED 0x1FE
#else
#define PAKUI_ALL_MODES_CLEARED 0x1F8
#endif

static s16 D_82D06FA0 = 7;
#if defined(VERSION_JP)
// JP text for message IDs 0-28 of string table 0xE (cup, ball, round and Gym names), which
// the other versions read with Text_GetString. PakUi_DrawDataSummaryPanel indexes it with
// the same IDs: unk_00 - 1, unk_01 + 7, unk_02 + 10 and unk_01 + 19.
static char* D_82D065D4_jp[] = {
    "ニンテンドウカップ‘９７",
    "ニンテンドウカップ‘９８",
    "ニンテンドウカップ‘９９",
    "ファンシーカップ",
    "イエローカップ",
    "ウルトラカップ",
    "ジムリーダーのしろ",
    "モンスターボール",
    "スーパーボール",
    "ハイパーボール",
    "マスターボール",
    "バトル１",
    "バトル２",
    "バトル３",
    "バトル４",
    "バトル５",
    "バトル６",
    "セミファイナル",
    "ファイナルバトル",
    "ニビジム",
    "ハナダジム",
    "クチバジム",
    "タマムシジム",
    "セキチクジム",
    "ヤマブキジム",
    "グレンジム",
    "トキワジム",
    "してんのう",
    "ライバル",
};
#endif
static u32 D_82D06FA4[] = {
    0x0C000000,  0x05000000, 0x0B00002D, 0x00000000, 0x028001E0, 0x00000000, 0xFDBD0000, 0x00000243, 0x05000000,
    0x0D000000,  0x05000000, 0x14000000, 0x00000000, 0xFFFFFF32, 0x16FFFFFF, 0x0F000002, 0x05000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};
static Vtx D_82D07008[] = {
    VTX(-64, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -16, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -16, 0, 4096, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, 0, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07048[] = {
    VTX(-64, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -32, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -32, 0, 4096, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -16, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07088[] = {
    VTX(-64, -32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -48, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -48, 0, 4096, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -32, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D070C8[] = {
    VTX(-64, -48, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -64, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -64, 0, 4096, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -48, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07108[] = {
    VTX(-64, -64, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -80, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -80, 0, 4096, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -64, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07148[] = {
    VTX(-64, -80, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -96, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -96, 0, 4096, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -80, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07188[] = {
    VTX(-64, -96, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -112, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -112, 0, 4096, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -96, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D071C8[] = {
    VTX(-64, -112, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -128, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -128, 0, 4096, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -112, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07208[] = {
    VTX(-64, -128, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -144, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -144, 0, 4096, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -128, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07248[] = {
    VTX(-64, -144, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -160, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -160, 0, 4096, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -144, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07288[] = {
    VTX(-64, -160, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -176, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -176, 0, 4096, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -160, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D072C8[] = {
    VTX(-64, -176, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -192, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -192, 0, 4096, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -176, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07308[] = {
    VTX(-64, -192, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -204, 0, 0, 384, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -204, 0, 4096, 384, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -192, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_82D07348[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07008, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F001000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07048, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F002000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07088, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F003000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D070C8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F004000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07108, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F005000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07148, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F006000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07188, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F007000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D071C8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F008000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07208, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F009000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07248, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F00A000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07288, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F00B000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D072C8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F00C000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07308, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_82D07710[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82D07008, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, PakUi_RenderPartyCardTexture, 0x00000000, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_82D07748[] = {
    VTX(0, 50, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 0, 0, 0, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(40, 0, 0, 1280, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(40, 50, 0, 1280, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07788[] = {
    VTX(40, 50, 0, 1280, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(40, 0, 0, 1280, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(80, 0, 0, 2560, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(80, 50, 0, 2560, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D077C8[] = {
    VTX(80, 50, 0, 2560, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(80, 0, 0, 2560, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(120, 0, 0, 3840, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(120, 50, 0, 3840, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07808[] = {
    VTX(120, 50, 0, 3840, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(120, 0, 0, 3840, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(160, 0, 0, 5120, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(160, 50, 0, 5120, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07848[] = {
    VTX(160, 50, 0, 5120, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(160, 0, 0, 5120, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(200, 0, 0, 6400, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(200, 50, 0, 6400, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07888[] = {
    VTX(200, 50, 0, 6400, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(200, 0, 0, 6400, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(240, 0, 0, 7680, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(240, 50, 0, 7680, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D078C8[] = {
    VTX(240, 50, 0, 7680, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(240, 0, 0, 7680, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(280, 0, 0, 8960, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(280, 50, 0, 8960, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07908[] = {
    VTX(280, 50, 0, 8960, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(280, 0, 0, 8960, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(320, 0, 0, 10240, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(320, 50, 0, 10240, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07948[] = {
    VTX(320, 50, 0, 10240, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(320, 0, 0, 10240, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(360, 0, 0, 11520, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(360, 50, 0, 11520, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07988[] = {
    VTX(360, 50, 0, 11520, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(360, 0, 0, 11520, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(400, 0, 0, 12800, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(400, 50, 0, 12800, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D079C8[] = {
    VTX(400, 50, 0, 12800, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(400, 0, 0, 12800, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(440, 0, 0, 14080, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(440, 50, 0, 14080, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07A08[] = {
    VTX(440, 50, 0, 14080, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(440, 0, 0, 14080, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(480, 0, 0, 15360, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(480, 50, 0, 15360, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07A48[] = {
    VTX(480, 50, 0, 15360, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(480, 0, 0, 15360, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(520, 0, 0, 16640, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(520, 50, 0, 16640, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07A88[] = {
    VTX(520, 50, 0, 16640, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(520, 0, 0, 16640, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(538, 0, 0, 17216, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(538, 50, 0, 17216, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07AC8[] = {
    VTX(0, 0, 0, 0, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -50, 0, 0, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(40, -50, 0, 1280, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(40, 0, 0, 1280, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07B08[] = {
    VTX(40, 0, 0, 1280, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(40, -50, 0, 1280, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(80, -50, 0, 2560, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(80, 0, 0, 2560, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07B48[] = {
    VTX(80, 0, 0, 2560, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(80, -50, 0, 2560, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(120, -50, 0, 3840, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(120, 0, 0, 3840, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07B88[] = {
    VTX(120, 0, 0, 3840, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(120, -50, 0, 3840, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(160, -50, 0, 5120, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(160, 0, 0, 5120, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07BC8[] = {
    VTX(160, 0, 0, 5120, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(160, -50, 0, 5120, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(200, -50, 0, 6400, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(200, 0, 0, 6400, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07C08[] = {
    VTX(200, 0, 0, 6400, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(200, -50, 0, 6400, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(240, -50, 0, 7680, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(240, 0, 0, 7680, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07C48[] = {
    VTX(240, 0, 0, 7680, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(240, -50, 0, 7680, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(280, -50, 0, 8960, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(280, 0, 0, 8960, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07C88[] = {
    VTX(280, 0, 0, 8960, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(280, -50, 0, 8960, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(320, -50, 0, 10240, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(320, 0, 0, 10240, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07CC8[] = {
    VTX(320, 0, 0, 10240, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(320, -50, 0, 10240, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(360, -50, 0, 11520, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(360, 0, 0, 11520, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07D08[] = {
    VTX(360, 0, 0, 11520, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(360, -50, 0, 11520, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(400, -50, 0, 12800, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(400, 0, 0, 12800, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07D48[] = {
    VTX(400, 0, 0, 12800, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(400, -50, 0, 12800, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(440, -50, 0, 14080, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(440, 0, 0, 14080, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07D88[] = {
    VTX(440, 0, 0, 14080, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(440, -50, 0, 14080, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(480, -50, 0, 15360, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(480, 0, 0, 15360, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07DC8[] = {
    VTX(480, 0, 0, 15360, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(480, -50, 0, 15360, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(520, -50, 0, 16640, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(520, 0, 0, 16640, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D07E08[] = {
    VTX(520, 0, 0, 16640, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(520, -50, 0, 16640, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(538, -50, 0, 17216, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(538, 0, 0, 17216, 1600, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_82D07E48[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 0, 0, 39, 49, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07748, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 40, 0, 79, 49, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07788, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 80, 0, 119, 49, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D077C8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 120, 0, 159, 49, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07808, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 160, 0, 199, 49, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07848, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 200, 0, 239, 49, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07888, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 240, 0, 279, 49, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D078C8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 280, 0, 319, 49, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07908, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 320, 0, 359, 49, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07948, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 360, 0, 399, 49, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07988, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 400, 0, 439, 49, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D079C8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 440, 0, 479, 49, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07A08, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 480, 0, 519, 49, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07A48, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 520, 0, 559, 49, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07A88, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 0, 50, 39, 99, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07AC8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 40, 50, 79, 99, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07B08, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 80, 50, 119, 99, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D07B48, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 120, 50, 159, 99, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D07B88, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 160, 50, 199, 99, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D07BC8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 200, 50, 239, 99, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D07C08, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 240, 50, 279, 99, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D07C48, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 280, 50, 319, 99, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D07C88, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 320, 50, 359, 99, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D07CC8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 360, 50, 399, 99, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D07D08, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 400, 50, 439, 99, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D07D48, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 440, 50, 479, 99, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D07D88, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 480, 50, 519, 99, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D07DC8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 538, 0, 520, 50, 559, 99, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D07E08, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_82D08648[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82D07748, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, PakUi_RenderIconPanelTexture, 0x00000000, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_82D08680[] = {
    VTX(0, 22, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 6, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(124, 6, 0, 3968, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(124, 22, 0, 3968, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D086C0[] = {
    VTX(0, 6, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -10, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(124, -10, 0, 3968, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(124, 6, 0, 3968, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D08700[] = {
    VTX(0, -10, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -22, 0, 0, 384, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(124, -22, 0, 3968, 384, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(124, -10, 0, 3968, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_82D08740[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D08680, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F001000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D086C0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F002000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D08700, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_82D08838[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82D08680, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, PakUi_RenderBannerTexture, 0x00000000, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_82D08870[] = {
    VTX(0, 76, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 56, 0, 0, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 56, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 76, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D088B0[] = {
    VTX(0, 56, 0, 0, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 36, 0, 0, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 36, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 56, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D088F0[] = {
    VTX(0, 36, 0, 0, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 16, 0, 0, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 16, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 36, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D08930[] = {
    VTX(0, 16, 0, 0, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -4, 0, 0, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -4, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 16, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D08970[] = {
    VTX(0, -4, 0, 0, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -24, 0, 0, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -24, 0, 3200, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -4, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D089B0[] = {
    VTX(0, -24, 0, 0, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -44, 0, 0, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -44, 0, 3200, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -24, 0, 3200, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D089F0[] = {
    VTX(0, -44, 0, 0, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -64, 0, 0, 4480, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -64, 0, 3200, 4480, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -44, 0, 3200, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D08A30[] = {
    VTX(0, -64, 0, 0, 4480, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -76, 0, 0, 4864, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -76, 0, 3200, 4864, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -64, 0, 3200, 4480, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D08A70[] = {
    VTX(100, 76, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 56, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 56, 0, 5504, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 76, 0, 5504, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D08AB0[] = {
    VTX(100, 56, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 36, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 36, 0, 5504, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 56, 0, 5504, 640, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D08AF0[] = {
    VTX(100, 36, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 16, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 16, 0, 5504, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 36, 0, 5504, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D08B30[] = {
    VTX(100, 16, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -4, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -4, 0, 5504, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 16, 0, 5504, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D08B70[] = {
    VTX(100, -4, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -24, 0, 3200, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -24, 0, 5504, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -4, 0, 5504, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D08BB0[] = {
    VTX(100, -24, 0, 3200, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -44, 0, 3200, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -44, 0, 5504, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -24, 0, 5504, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D08BF0[] = {
    VTX(100, -44, 0, 3200, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -64, 0, 3200, 4480, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -64, 0, 5504, 4480, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -44, 0, 5504, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D08C30[] = {
    VTX(100, -64, 0, 3200, 4480, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -76, 0, 3200, 4864, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -76, 0, 5504, 4864, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -64, 0, 5504, 4480, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_82D08C70[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
#if defined(VERSION_JP)
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
#endif
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 0, 99, 19, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D08870, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 20, 99, 39, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D088B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 40, 99, 59, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D088F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 60, 99, 79, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D08930, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 80, 99, 99, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D08970, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 100, 99, 119, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D089B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 120, 99, 139, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D089F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 140, 99, 155, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D08A30, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 0, 171, 19, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D08A70, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 20, 171, 39, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D08AB0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 40, 171, 59, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D08AF0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 60, 171, 79, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D08B30, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 80, 171, 99, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D08B70, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 100, 171, 119, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D08BB0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 120, 171, 139, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D08BF0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 140, 171, 155, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D08C30, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_82D09108[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82D08870, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, PakUi_RenderMenuIconTexture, 0x00000000, 0x06000000, 0x01000000, 0x00000000,
};
#if !defined(VERSION_JP)
static Vtx D_82D09140[] = {
    VTX(0, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 16, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 16, 0, 3200, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 32, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09180[] = {
    VTX(0, 16, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 0, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 0, 0, 3200, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 16, 0, 3200, 512, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D091C0[] = {
    VTX(0, 0, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -16, 0, 0, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -16, 0, 3200, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 0, 0, 3200, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09200[] = {
    VTX(0, -16, 0, 0, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -32, 0, 0, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -32, 0, 3200, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -16, 0, 3200, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09240[] = {
    VTX(100, 32, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 16, 0, 3200, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 16, 0, 5504, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 32, 0, 5504, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09280[] = {
    VTX(100, 16, 0, 3200, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 0, 0, 3200, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 0, 0, 5504, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 16, 0, 5504, 512, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D092C0[] = {
    VTX(100, 0, 0, 3200, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -16, 0, 3200, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -16, 0, 5504, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 0, 0, 5504, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09300[] = {
    VTX(100, -16, 0, 3200, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -32, 0, 3200, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -32, 0, 5504, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -16, 0, 5504, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_82D09340[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 0, 99, 15, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D09140, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 16, 99, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D09180, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 32, 99, 47, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D091C0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 48, 99, 63, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D09200, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 0, 171, 15, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D09240, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 16, 171, 31, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D09280, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 32, 171, 47, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D092C0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 48, 171, 63, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D09300, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_82D09598[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82D09140, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, PakUi_RenderMenuIconTexture, 0x00000000, 0x06000000, 0x01000000, 0x00000000,
};
#endif
static Vtx D_82D095D0[] = {
    VTX(0, 46, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 26, 0, 0, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 26, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 46, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09610[] = {
    VTX(0, 26, 0, 0, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 6, 0, 0, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 6, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 26, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09650[] = {
    VTX(0, 6, 0, 0, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -14, 0, 0, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -14, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 6, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09690[] = {
    VTX(0, -14, 0, 0, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -34, 0, 0, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -34, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -14, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D096D0[] = {
    VTX(0, -34, 0, 0, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -46, 0, 0, 2944, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -46, 0, 3200, 2944, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -34, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09710[] = {
    VTX(100, 46, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 26, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 26, 0, 5504, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 46, 0, 5504, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09750[] = {
    VTX(100, 26, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 6, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 6, 0, 5504, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 26, 0, 5504, 640, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09790[] = {
    VTX(100, 6, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -14, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -14, 0, 5504, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 6, 0, 5504, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D097D0[] = {
    VTX(100, -14, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -34, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -34, 0, 5504, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -14, 0, 5504, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09810[] = {
    VTX(100, -34, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -46, 0, 3200, 2944, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -46, 0, 5504, 2944, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -34, 0, 5504, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_82D09850[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
#if defined(VERSION_JP)
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
#endif
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 0, 99, 19, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D095D0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 20, 99, 39, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D09610, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 40, 99, 59, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D09650, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 60, 99, 79, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D09690, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 80, 99, 91, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D096D0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 0, 171, 19, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D09710, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 20, 171, 39, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D09750, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 40, 171, 59, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D09790, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 60, 171, 79, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D097D0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 80, 171, 91, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D09810, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_82D09B38[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82D095D0, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, PakUi_RenderMenuIconTexture, 0x00000000, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_82D09B70[] = {
    VTX(0, 24, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 4, 0, 0, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 4, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 24, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09BB0[] = {
    VTX(0, 4, 0, 0, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -16, 0, 0, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -16, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 4, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09BF0[] = {
    VTX(0, -16, 0, 0, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -24, 0, 0, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -24, 0, 3200, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -16, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09C30[] = {
    VTX(100, 24, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 4, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 4, 0, 5504, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 24, 0, 5504, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09C70[] = {
    VTX(100, 4, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -16, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -16, 0, 5504, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, 4, 0, 5504, 640, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82D09CB0[] = {
    VTX(100, -16, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -24, 0, 3200, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -24, 0, 5504, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(172, -16, 0, 5504, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_82D09CF0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
#if defined(VERSION_JP)
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
#endif
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 0, 99, 19, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D09B70, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 20, 99, 39, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D09BB0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 0, 40, 99, 47, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D09BF0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 0, 171, 19, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82D09C30, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 20, 171, 39, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D09C70, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 172, 0, 100, 40, 171, 47, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82D09CB0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_82D09EB8[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82D09B70, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, PakUi_RenderMenuIconTexture, 0x00000000, 0x06000000, 0x01000000,
};

s32 Pak_CheckPiIntegrity(s32 arg0) {
    u32 temp_a0 = osSetIntMask(1);

    if (!(IO_READ(PI_STATUS_REG) & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) &&
        (((D_B0000504 & 0xFFFF) & 0xFFFF) != PHYS_TO_K1(PI_DRAM_ADDR_REG) >> 16)) {
        arg0 = -0x20;
    }
    osSetIntMask(temp_a0);
    return arg0;
}

void PakUi_DrawMenuBackdrop(void) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0,
                      ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetEnvColor(gDisplayListHead++, 180, 180, 100, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 120, 100, 40, 255);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_300F780, G_IM_FMT_I, 128, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 7, 6, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(0, 0, 0x280, 0x1E0, 0, 0, 0x400, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void PakUi_BuildFrameBuffer(DepthBuffer* arg0, s16 arg1, s16 arg2) {
    GfxImage_SetRenderTarget(&gDisplayListHead, arg0);
    GfxImage_FillCurrent(&gDisplayListHead, 0);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    gDPSetBlendColor(gDisplayListHead++, 255, 255, 255, 128);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);

    Gfx_DrawTextureIa8(-3, -3, 8, 8, D_2000340, 8, 0);
    Gfx_DrawTexturedRectClipped(4, -3, arg1 - 8, 8, 0xE0, 0, 0, 0x400, 0);
    Gfx_DrawTexturedRectClipped(-3, 4, 8, arg2 - 8, 0, 0xE0, 0x400, 0, 0);
    Gfx_DrawTextureIa8(arg1 - 5, -3, 8, 8, D_2000380, 8, 0);
    Gfx_DrawTexturedRectClipped(arg1 - 5, 4, 8, arg2 - 8, 0, 0xE0, 0x400, 0, 0);
    Gfx_DrawTextureIa8(-3, arg2 - 5, 8, 8, D_20002C0, 8, 0);
    Gfx_DrawTexturedRectClipped(4, arg2 - 5, arg1 - 8, 8, 0xE0, 0, 0, 0x400, 0);
    Gfx_DrawTextureIa8(arg1 - 5, arg2 - 5, 8, 8, D_2000300, 8, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void PakUi_DrawThickBoxBorder(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 temp_a2;
    s16 temp_s0_32;
    s16 var_s2;
    s16 var_s3;

    if (arg2 >= 0x20) {
        var_s3 = 0x10;
    } else {
        var_s3 = arg2 / 2;
    }
    if (arg3 >= 0x20) {
        var_s2 = 0x10;
    } else {
        var_s2 = arg3 / 2;
    }
    temp_a2 = arg2 - (var_s3 * 2);
    temp_s0_32 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_300F480, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_300F500, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_300F380, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_300F400, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3,
                  0x4000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, gUiTranslucentFillDL);

    if ((temp_a2 > 0) && (temp_s0_32 > 0)) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, temp_a2, var_s2, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0, arg1 + var_s3, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0 + var_s3, arg1 + var_s3 + temp_s0_32, temp_a2, var_s2, arg4, arg5, arg6, arg7);
    } else if (temp_a2 > 0) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, temp_a2, arg3, arg4, arg5, arg6, arg7);
    } else if (temp_s0_32 > 0) {
        Gfx_FillRectRgba(arg0, arg1 + var_s2, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void PakUi_DrawThinBoxBorder(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 temp_a2;
    s16 temp_s0_32;
    s16 var_s2;
    s16 var_s3;

    if (arg2 >= 0x10) {
        var_s3 = 8;
    } else {
        var_s3 = arg2 / 2;
    }
    if (arg3 >= 0x10) {
        var_s2 = 8;
    } else {
        var_s2 = arg3 / 2;
    }
    temp_a2 = arg2 - (var_s3 * 2);
    temp_s0_32 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3022A20, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3022A60, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30229A0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30229E0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3,
                  0x2000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, gUiTranslucentFillDL);

    if ((temp_a2 > 0) && (temp_s0_32 > 0)) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, temp_a2, var_s2, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0, arg1 + var_s3, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0 + var_s3, arg1 + var_s3 + temp_s0_32, temp_a2, var_s2, arg4, arg5, arg6, arg7);
    } else if (temp_a2 > 0) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, temp_a2, arg3, arg4, arg5, arg6, arg7);
    } else if (temp_s0_32 > 0) {
        Gfx_FillRectRgba(arg0, arg1 + var_s2, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void PakUi_DrawRotatingCorners(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    static s16 D_82D09EEC = 0;

    s16 sp56 = SINS(D_82D09EEC) * 2;
    UNUSED s32 pad[2];

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    Gfx_DrawTextureIa8((arg0 + sp56) - 8, (arg1 + sp56) - 8, 0x10, 0x10, D_2000C80, 0x10, 0);
    Gfx_DrawTextureIa8((arg0 + sp56) - 8, ((arg1 + arg3) - sp56) - 8, 0x10, 0x10, D_2000F80, 0x10, 0);
    Gfx_DrawTextureIa8(((arg0 + arg2) - sp56) - 8, (arg1 + sp56) - 8, 0x10, 0x10, D_2000D80, 0x10, 0);
    Gfx_DrawTextureIa8(((arg0 + arg2) - sp56) - 8, ((arg1 + arg3) - sp56) - 8, 0x10, 0x10, D_2000E80, 0x10, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    D_82D09EEC += 0x2000;
}

s32 PakUi_RenderPartyCardTexture(s32 arg0, unk_func_80011B94* arg1) {
    if (arg0 == 5) {
        s32 var_a3 = D_8006F09C->node.callbackArg;

        gDPPipeSync(gDisplayListHead++);

        gSPSegment(gDisplayListHead++, 0x0F, (u32)D_82D0ABB8[var_a3]->img_p & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, D_82D07348);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

s32 PakUi_RenderIconPanelTexture(s32 arg0, unk_func_80011B94* arg1) {
    if (arg0 == 5) {
        gDPPipeSync(gDisplayListHead++);

        gSPSegment(gDisplayListHead++, 0x0F, (u32)D_82D0ABC8[0].img_p & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, D_82D07E48);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

s32 PakUi_RenderBannerTexture(s32 arg0, unk_func_80011B94* arg1) {
    if (arg0 == 5) {
        gDPPipeSync(gDisplayListHead++);

        gSPSegment(gDisplayListHead++, 0x0F, (u32)D_82D0ABCC->img_p & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, D_82D08740);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

void PakUi_DrawPartyProgressBar(s32 arg0) {
    s16 temp_lo_2;
#if !defined(VERSION_JP)
    char* sp30;
#endif

    if (arg0 > 0) {
#if defined(VERSION_JP)
        temp_lo_2 = (arg0 * 0x3C) / 10;
        PakUi_DrawThickBoxBorder(0x34, (s16)((0x3C - temp_lo_2) / 2) + 0x28, 0xB0, temp_lo_2, 0x1E, 0x1E, 0x82, 0x96);
        if ((arg0 * 0x3C) == 600) {
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            Font_Printf(0x44, 0x2C, "カートリッジ");
            Font_Printf(0x44, 0x48, "チェック");
            Font_EndTexturedTextRendering();
        }
#else
        temp_lo_2 = (arg0 * 0x3C) / 10;
        PakUi_DrawThickBoxBorder(0x34, (s16)((0x3C - temp_lo_2) / 2) + 0x28, 0xB0, temp_lo_2, 0x1E, 0x1E, 0x82, 0x96);
        if (arg0 == 10) {
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            sp30 = Text_GetString(NULL, 0, D_82D0AB9C, 0x1D);
            Font_Printf(0x8C - (Font_MeasureTextExtent(0x10, 0, sp30) / 2), 0x2C, sp30);
            sp30 = Text_GetString(NULL, 0, D_82D0AB9C, 0x1E);
            Font_Printf(0x8C - (Font_MeasureTextExtent(0x10, 0, sp30) / 2), 0x48, sp30);
            Font_EndTexturedTextRendering();
        }
#endif
    }
}

void PakUi_DrawTitleHeader(s16 arg0) {
    static Color_RGB8 D_82D09EF0[] = { { 0x8C, 0x82, 0x50 }, { 0x32, 0x32, 0x32 } };

    Color_RGB8* ptr = &D_82D09EF0[0];

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, arg0);

    Gfx_DrawTextureRgba16(0x100, 0x20, 0x80, 0x10, D_300A820, 0x80, 0);
    Gfx_DrawTextureRgba16(0x100, 0x30, 0x80, 0x10, D_300B820, 0x80, 0);
    Gfx_DrawTextureRgba16(0x100, 0x40, 0x80, 0x10, D_300C820, 0x80, 0);
    Gfx_DrawTextureRgba16(0x100, 0x50, 0x80, 0x10, D_300D820, 0x80, 0);

    ptr = &D_82D09EF0[D_82D0AB38[0].unk_04];
    gDPSetEnvColor(gDisplayListHead++, ptr->r, ptr->g, ptr->b, arg0);

    Gfx_DrawTextureI4(0x120, 0x60, 8, 8, D_300F240, 0x10, 0);
    Gfx_DrawTextureI4(0x120, 0x6C, 8, 8, D_300F280, 0x10, 0);
    Gfx_DrawTextureI4(0x70, 0x6C, 8, 8, D_300F2C0, 0x10, 0);
    Gfx_DrawTexturedRectClipped(0x120, 0x68, 8, 4, 0, 0xE0, 0x400, 0, 0);
    Gfx_DrawTexturedRectClipped(0x70, 0x74, 8, 0x14, 0, 0xE0, 0x400, 0, 0);
    Gfx_DrawTexturedRectClipped(0x78, 0x6C, 0xA8, 8, 0xE0, 0, 0, 0x400, 0);

    ptr = &D_82D09EF0[D_82D0AB38[1].unk_04];
    gDPSetEnvColor(gDisplayListHead++, ptr->r, ptr->g, ptr->b, arg0);

    Gfx_DrawTextureI4(0x12C, 0x60, 8, 8, D_300F240, 0x10, 0);
    Gfx_DrawTextureI4(0x12C, 0x78, 8, 8, D_300F280, 0x10, 0);
    Gfx_DrawTextureI4(0xF8, 0x78, 8, 8, D_300F2C0, 0x10, 0);
    Gfx_DrawTexturedRectClipped(0x12C, 0x68, 8, 0x10, 0, 0xE0, 0x400, 0, 0);
    Gfx_DrawTexturedRectClipped(0xF8, 0x80, 8, 8, 0, 0xE0, 0x400, 0, 0);
    Gfx_DrawTexturedRectClipped(0x100, 0x78, 0x2C, 8, 0xE0, 0, 0, 0x400, 0);

    ptr = &D_82D09EF0[D_82D0AB38[2].unk_04];
    gDPSetEnvColor(gDisplayListHead++, ptr->r, ptr->g, ptr->b, arg0);

    Gfx_DrawTextureI4(0x14C, 0x60, 8, 8, D_300F240, 0x10, 0);
    Gfx_DrawTextureI4(0x14C, 0x78, 8, 8, D_300F300, 0x10, 0);
    Gfx_DrawTextureI4(0x180, 0x78, 8, 8, D_300F340, 0x10, 0);
    Gfx_DrawTexturedRectClipped(0x14C, 0x68, 8, 0x10, 0, 0xE0, 0x400, 0, 0);
    Gfx_DrawTexturedRectClipped(0x180, 0x80, 8, 8, 0, 0xE0, 0x400, 0, 0);
    Gfx_DrawTexturedRectClipped(0x154, 0x78, 0x2C, 8, 0, 0, 0, 0x400, 0);

    ptr = &D_82D09EF0[D_82D0AB38[3].unk_04];
    gDPSetEnvColor(gDisplayListHead++, ptr->r, ptr->g, ptr->b, arg0);

    Gfx_DrawTextureI4(0x158, 0x60, 8, 8, D_300F240, 0x10, 0);
    Gfx_DrawTextureI4(0x158, 0x6C, 8, 8, D_300F300, 0x10, 0);
    Gfx_DrawTextureI4(0x208, 0x6C, 8, 8, D_300F340, 0x10, 0);
    Gfx_DrawTexturedRectClipped(0x158, 0x68, 8, 4, 0, 0xE0, 0x400, 0, 0);
    Gfx_DrawTexturedRectClipped(0x208, 0x74, 8, 0x14, 0, 0xE0, 0x400, 0, 0);
    Gfx_DrawTexturedRectClipped(0x160, 0x6C, 0xA8, 8, 0, 0, 0, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void PakUi_DrawPartyCardBadge(s32 arg0) {
    u8* var_t0;

    switch (D_82D0AB38[arg0].unk_01) {
        default:
            var_t0 = D_3008420;
            break;

        case 1:
            var_t0 = D_3007220;
            break;

        case 2:
            var_t0 = D_3006020;
            break;

        case 3:
#if defined(VERSION_JP)
            // Segment 3 holds a different asset at 0x3004E20 than the one fragment17 names D_3004E20.
            var_t0 = D_03004E20_jp;
#else
            var_t0 = D_3004E20;
#endif
            break;

        case 7:
            var_t0 = D_3009620;
            break;
    }

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    Gfx_DrawTextureRgba16(0x26, 8, 0x30, 0x18, var_t0, 0x30, 0);
    Gfx_DrawTextureRgba16(0x26, 0x20, 0x30, 0x18, var_t0 + 0x900, 0x30, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void PakUi_DrawPartyCardList(u8 arg0) {
    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, arg0);

    Gfx_DrawTextureRgba16(0xC, 0x60, 0x64, 0x14, D_3000000, 0x64, 0);
    Gfx_DrawTextureRgba16(0xC, 0x74, 0x64, 0x14, D_3000FA0, 0x64, 0);
    Gfx_DrawTextureRgba16(0xC, 0x88, 0x64, 0x14, D_3001F40, 0x64, 0);
    Gfx_DrawTextureRgba16(0xC, 0x9C, 0x64, 0x14, D_3002EE0, 0x64, 0);
    Gfx_DrawTextureRgba16(0xC, 0xB0, 0x64, 0x14, D_3003E80, 0x64, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void PakUi_BuildPartyCard(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8* arg4) {
#if !defined(VERSION_JP)
    s32 sp2C;
    char* sp40;
#endif

    PakUi_BuildFrameBuffer(D_82D0ABB8[arg0], 0x7C, 0xC8);

    gSPDisplayList(gDisplayListHead++, D_8006F470);

#if defined(VERSION_JP)
#define sp2C (arg2 & 0x10)
#else
    sp2C = arg2 & 0x10;
#endif
    if (sp2C != 0) {
        Gfx_FillRectRgb(4, 4, 0x74, 0x64, 0x64, 0x1E, 0x1E);
        Gfx_FillRectRgb(4, 0x68, 0x74, 0x5C, 0, 0, 0);
    } else {
        Gfx_FillRectRgb(4, 4, 0x74, 0xC0, 0x32, 0x32, 0x78);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    if (arg1 != 0) {
        PakUi_DrawPartyCardBadge(arg0);
    }

    if (arg2 != 2) {
        if (sp2C != 0) {
            PakUi_DrawPartyCardList(0x64);
        } else {
            PakUi_DrawPartyCardList(0xFF);
        }
    }

    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    Font_DrawCharAt(8, 8, arg0 + 0x31);

#if defined(VERSION_JP)
    // JP prints fixed-position EUC-JP strings instead of centering string-table text.
    if (arg1 != 0) {
        if (arg4 != NULL) {
            Font_SetActive(4, 0);
            Font_Printf(0x16, 0x3C, arg4);
        }

        Font_SetActive(4, -6);
        Font_Printf(0x12, 0x50, "ID");
        Font_SetActive(4, -4);

        if (arg3 >= 0) {
            Font_Printf(0x32, 0x50, "%05d", arg3);
        } else {
            Font_Printf(0x32, 0x50, "＊＊＊＊＊");
        }
    } else {
        Font_SetActive(4, 0);
        Font_Printf(0xE, 0x24, "カートリッジ");
        Font_Printf(0x2E, 0x38, "なし");
    }

    if (sp2C != 0) {
        Font_SetActive(4, 0);
        Font_SetLineHeight(0x14);

        switch (arg2) {
            case 20:
                Font_Printf(0xE, 0x70, "レポートが、\nみつかりませ\nん。");
                break;

            case 19:
                Font_Printf(0xE, 0x70, "ポケモンセン\nターで、レポ\nートされてい\nません。");
                break;

            case 21:
                Font_Printf(0xE, 0x70, "このカートリ\nッジは、つか\nえません。");
                break;
        }
    }
#else
    if (arg1 != 0) {
        if (arg4 != NULL) {
            Font_SetActive(4, 0);
            Font_Printf(0x3E - (Font_MeasureTextExtent(4, 0, arg4) / 2), 0x3C, arg4);
        }

        Font_SetActive(4, 0);

        if (arg3 >= 0) {
            Font_Printf(0x3E - (Font_MeasureTextExtent(4, 0, "ID  00000") / 2), 0x50, "ID  %05d", arg3);
        } else {
            Font_Printf(0x3E - (Font_MeasureTextExtent(4, 0, "ID  *****") / 2), 0x50, "ID  *****");
        }
    } else {
        Font_SetActive(4, 0);
        sp40 = Text_GetString(NULL, 0, D_82D0AB9C, 0x1D);
        Font_Printf(0x40 - (Font_MeasureTextExtent(4, 0, sp40) / 2), 0x24, sp40);
        sp40 = Text_GetString(NULL, 0, D_82D0AB9C, 0x1F);
        Font_Printf(0x40 - (Font_MeasureTextExtent(4, 0, sp40) / 2), 0x38, sp40);
    }

    if (sp2C != 0) {
        Font_SetActive(4, 0);
        Font_SetLineHeight(0x14);

        switch (arg2) {
            case 20:
                Font_Printf(0xE, 0x70, Text_GetString(NULL, 0, D_82D0AB9C, 0x20));
                break;

            case 19:
                Font_Printf(0xE, 0x70, Text_GetString(NULL, 0, D_82D0AB9C, 0x21));
                break;

            case 21:
                Font_Printf(0xE, 0x70, Text_GetString(NULL, 0, D_82D0AB9C, 0x22));
                break;
        }
    }
#endif
    Font_EndTexturedTextRendering();
}

// Placeholder trainer name PakUi_InitPartyCard passes for card states 0x14 and 0x15.
#if defined(VERSION_JP)
#define PAKUI_UNKNOWN_NAME "？？？？？"
#else
#define PAKUI_UNKNOWN_NAME "?????"
#endif
#undef sp2C

void PakUi_InitPartyCard(s32 arg0) {
    Pak_PortStatus* temp_v1;

    D_82D0ABB8[arg0] = GfxImage_Allocate(0, 2, 0x80, 0xCC, 1);
    if (D_82D0AB38[arg0].unk_01 != 0) {
        if (D_82D0AB38[arg0].unk_00 == 0) {
            if (D_82D0AB38[arg0].unk_03 != 0) {
                PakUi_BuildPartyCard(arg0, 1, 0, (u16)D_82D0AB38[arg0].unk_06, D_82D0AB38[arg0].unk_08);
            } else {
                PakUi_BuildPartyCard(arg0, 1, 0x13, (u16)D_82D0AB38[arg0].unk_06, D_82D0AB38[arg0].unk_08);
            }
        } else {
            PakUi_BuildPartyCard(arg0, 1, 0x14, -1, PAKUI_UNKNOWN_NAME);
        }
    } else if (D_82D0AB38[arg0].unk_00 == 2) {
        PakUi_BuildPartyCard(arg0, 1, 0x15, -1, PAKUI_UNKNOWN_NAME);
    } else if (D_82D0AB38[arg0].unk_04 != 0) {
        PakUi_BuildPartyCard(arg0, 0, 1, -1, NULL);
    } else {
        PakUi_BuildPartyCard(arg0, 0, 2, -1, NULL);
    }
}

void PakUi_BuildIconPanel(void) {
    D_82D0ABC8 = GfxImage_Allocate(0, 2, 0x21A, 0x64, 1);
    PakUi_BuildFrameBuffer(D_82D0ABC8, 0x216, 0x60);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    gDPSetBlendColor(gDisplayListHead++, 255, 255, 255, 128);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);

    Gfx_DrawTextureIa8(0x5B, -3, 8, 8, D_2000240, 8, 0);
    Gfx_DrawTexturedRectClipped(0x5B, 4, 8, 0x58, 0, 0xE0, 0x400, 0, 0);
    Gfx_DrawTextureIa8(0x5B, 0x5B, 8, 8, D_2000040, 8, 0);

    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);
    gDPSetEnvColor(gDisplayListHead++, 160, 120, 30, 255);
    gDPLoadTextureBlock_4b(gDisplayListHead++, D_300F580, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(4, 4, 0x58, 0x58, 0, 0, 0x400, 0x400, 0);

    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    Gfx_DrawTextureIa8(0xC, 0x1E, 0x48, 0x12, D_300E820, 0x48, 0);
    Gfx_DrawTextureIa8(0xC, 0x30, 0x48, 0x12, D_300ED30, 0x48, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F470);

    Gfx_FillRectRgb(0x62, 4, 0x1B0, 0x58, 0x64, 0x1E, 0x1E);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
#if defined(VERSION_JP)
    Font_Printf(0x6E, 8, "GBカートリッジ、64GBパック、");
    Font_Printf(0x6E, 0x24, "コントローラのぬきさしは、でんげん");
    Font_Printf(0x6E, 0x40, "をきってからおこなってください。");
#else
    Font_SetLineHeight(0x1C);
    Font_Printf(0x6E, 8, Text_GetString(NULL, 0, D_82D0AB9C, 0x23));
#endif
    Font_EndTexturedTextRendering();
}

void PakUi_BuildBottomBanner(void) {
    s32 sp2C;
    char* sp28;

    D_82D0ABCC = GfxImage_Allocate(0, 2, 0x80, 0x2C, 1);
    PakUi_BuildFrameBuffer(D_82D0ABCC, 0x78, 0x28);

    gSPDisplayList(gDisplayListHead++, D_8006F470);

    Gfx_FillRectRgb(4, 4, 0x70, 0x20, 0x1E, 0x64, 0x1E);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

#if defined(VERSION_JP)
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Font_Printf(0x14, 7, "ＯＫ？");
#else
    sp28 = Text_GetString(NULL, 0, D_82D0AB9C, 0x24);
    sp2C = Font_MeasureTextExtent(0x10, 0, sp28);
    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Font_Printf(0x3C - (sp2C / 2), 7, sp28);
#endif
    Font_EndTexturedTextRendering();
}

void PakUi_UpdatePartyDisplayFrame(s32 arg0, s16 arg1) {
    s16 i;
    s16 sp1C;
    s16 temp_lo;

    if (arg0 < 0) {
        sp1C = arg0 + 0xA;
    } else {
        sp1C = 0xA - arg0;
    }

    temp_lo = (arg0 * 0x5000) / 10;
    for (i = 0; i < 4; i++) {
        D_82D09FF8[i].rotation.y = temp_lo;
    }

    for (i = 4; i < 6; i++) {
        D_82D09FF8[i].rotation.x = temp_lo;
    }

    BgStage_DrawFrame();
    PakUi_DrawMenuBackdrop();
    PakUi_DrawTitleHeader(arg1);
    Geo_RenderRootNode(D_82D09FF0);
    PakUi_DrawPartyProgressBar(sp1C);
    BgStage_AdvanceFrame();
}

void TransferPak_InitPartyDisplay(void) {
    s32 i;

    main_pool_push_state('chck');

    for (i = 0; i < 4; i++) {
        PakUi_InitPartyCard(i);
        Model_InitDisplayObject(&D_82D09FF8[i], 0, 0, D_82D0ABAC);
    }

    PakUi_BuildIconPanel();
    Model_InitDisplayObject(&D_82D09FF8[4], 0, 0, D_82D0ABB0);
    PakUi_BuildBottomBanner();
    Model_InitDisplayObject(&D_82D09FF8[5], 0, 0, D_82D0ABB4);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8->position, -204.0f, 104.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[1].position, -68.0f, 104.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[2].position, 68.0f, 104.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[3].position, 204.0f, 104.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[4].position, -268.0f, -158.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[5].position, 144.0f, 162.0f, -579.0f);
}

void PakUi_FreePartyDisplayModels(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        ModelRenderer_ClearDisplayObject(&D_82D09FF8[i]);
    }

    main_pool_pop_state('chck');
}

s32 TransferPak_ShowRulesPrompt(void) {
    s32 var_s2 = 0;
    s16 i;
    s16 j;

    TransferPak_InitPartyDisplay();
    StageFade_StartFromOpaque(8);

    for (j = 0; j < 7; j++) {
        Controller_PollInputs();
        PakUi_UpdatePartyDisplayFrame(-0xA, 0xFF);
    }

    for (i = -9; i < 0; i++) {
        Controller_PollInputs();
        PakUi_UpdatePartyDisplayFrame(i, 0xFF);
    }

    while (var_s2 == 0) {
        Controller_PollInputs();
        PakUi_UpdatePartyDisplayFrame(i, 0xFF);

        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
            var_s2 = BTN_A;
        } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
            var_s2 = BTN_B;
        }
    }

    if (var_s2 == BTN_A) {
        Audio_PlaySoundEffectById(0x17);

        for (i = 0; i < 10; i++) {
            Controller_PollInputs();
            PakUi_UpdatePartyDisplayFrame(i, 0xFF);
        }

        for (j = 0xE0; j >= 0x20; j -= 0x20) {
            Controller_PollInputs();
            PakUi_UpdatePartyDisplayFrame(i, j);
        }
    } else {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
        Audio_StopMusic(0x10);
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(8);
        while (StageContext_GetFadeMode() != 1) {
            Controller_PollInputs();
            PakUi_UpdatePartyDisplayFrame(i, 0xFF);
        }
    }
    PakUi_FreePartyDisplayModels();
    return var_s2 == BTN_A;
}

void PakUi_DrawDataPanelBorder(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 temp_a2;
    s16 temp_s0_32;
    s16 var_s2;
    s16 var_s3;

    if (arg2 >= 0x20) {
        var_s3 = 0x10;
    } else {
        var_s3 = arg2 / 2;
    }

    if (arg3 >= 0x20) {
        var_s2 = 0x10;
    } else {
        var_s2 = arg3 / 2;
    }
    temp_a2 = arg2 - (var_s3 * 2);
    temp_s0_32 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20288E0, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028960, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20287E0, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028860, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3,
                  0x4000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, gUiTranslucentFillDL);

    if ((temp_a2 > 0) && (temp_s0_32 > 0)) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, temp_a2, var_s2, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0, arg1 + var_s3, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
        Gfx_FillRectRgba(arg0 + var_s3, arg1 + var_s3 + temp_s0_32, temp_a2, var_s2, arg4, arg5, arg6, arg7);
    } else if (temp_a2 > 0) {
        Gfx_FillRectRgba(arg0 + var_s3, arg1, temp_a2, arg3, arg4, arg5, arg6, arg7);
    } else if (temp_s0_32 > 0) {
        Gfx_FillRectRgba(arg0, arg1 + var_s2, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

void PakUi_DrawMenuOptionText(s16 arg0, s16 arg1, s16 arg2, s16 arg3, char* arg4) {
    if (arg2 == arg3) {
        Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
    } else {
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    }
    Font_Printf(arg0, arg1 + (arg2 * 0x1C), arg4);
}

#if defined(VERSION_JP)
void PakUi_DrawRulesPanel(s16 arg0, s16 arg1) {
    s32 var_v0;
    s16 sp24;

    if (arg0 > 0) {
        var_v0 = (arg0 * 0x11) + 2;
        sp24 = ((0x8A - (s16)var_v0) / 2) + 0xFA;
        Ui_DrawBorderedPanel(0x87, sp24, 0x172, (s16)var_v0, 0x6109);
        if (var_v0 == 0x8A) {
            var_v0 = arg1 * 0x1C;
            Ui_DrawAnimatedTextureMarker(0xFF, sp24 + var_v0 + 0x48);
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, -2);
            Gfx_SetEnvColor(0xFF, 0xFF, 0x64, 0xFF);
            Font_Printf(0x9B, sp24 + 0xC, "ちゅうだんデータを　けします。");
            Font_Printf(0x9B, sp24 + 0x28, "いいですか？");
            Gfx_SetEnvColor(0xFF, 0xFF, (var_v0 == 0) ? 0 : 0xFF, 0xFF);
            Font_Printf(0x127, sp24 + 0x48, "はい");
            Gfx_SetEnvColor(0xFF, 0xFF, (var_v0 == 0x1C) ? 0 : 0xFF, 0xFF);
            Font_Printf(0x127, sp24 + 0x64, "いいえ");
            Font_EndTexturedTextRendering();
        }
    }
}
#else
void PakUi_DrawRulesPanel(s16 arg0, s16 arg1) {
    UNUSED s32 pad;
    s16 sp28;
    s16 sp24;

    if (1) {}

    if (arg0 > 0) {
        sp28 = (arg0 * 0x11) + 2;
        sp24 = ((0x8A - sp28) / 2) + 0xFA;
        Ui_DrawBorderedPanel(0x87, sp24, 0x172, sp28, 0x6109);
        if (arg0 == 8) {
            Ui_DrawAnimatedTextureMarker(0x13B, sp24 + (arg1 * 0x1C) + 0x48);
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            Gfx_SetEnvColor(0xFF, 0xFF, 0x64, 0xFF);
            Font_SetLineHeight(0x1A);
            Font_Printf(0x9B, sp24 + 0xC, Text_GetString(NULL, 0, D_82D0AB9C, 0x25));
            Font_Printf(0x9B, sp24 + 0x44, Text_GetString(NULL, 0, D_82D0AB9C, 0x26));
            Gfx_SetEnvColor(0xFF, 0xFF, ((arg1 * 0x1C) == 0) ? 0 : 0xFF, 0xFF);
            Font_Printf(0x163, sp24 + 0x48, Text_GetString(NULL, 0, D_82D0AB9C, 0x27));
            Gfx_SetEnvColor(0xFF, 0xFF, ((arg1 * 0x1C) == 0x1C) ? 0 : 0xFF, 0xFF);
            Font_Printf(0x163, sp24 + 0x64, Text_GetString(NULL, 0, D_82D0AB9C, 0x28));
            Font_EndTexturedTextRendering();
        }
    }
}
#endif

#if defined(VERSION_JP)
void PakUi_DrawDataSummaryPanel(s16 arg0, s16 arg1, SessionContinueData* arg2, s32 arg3) {
    UNUSED s32 pad;
    s16 temp_s0;

    if ((s16)((arg0 * 0x2C) + 2) >= 0x10) {
        temp_s0 = ((0x162 - (s16)((arg0 * 0x2C) + 2)) / 2) + 0x3C;
        Ui_DrawBorderedPanel(0x79, temp_s0, 0x18E, (s16)((arg0 * 0x2C) + 2), 0x2349);
        if ((s16)((arg0 * 0x2C) + 2) == 0x162) {
            PakUi_DrawDataPanelBorder(0x98, temp_s0 + 0x27, 0x150, 0x78, 0, 0, 0, 0xFF);
            PakUi_DrawDataPanelBorder(0x98, temp_s0 + 0xBF, 0x150, 0x60, 0, 0, 0, 0xFF);
            if (arg3 != 0) {
                Ui_DrawAnimatedTextureMarker(0x9D, temp_s0 + (arg1 * 0x1C) + 0xC7);
            }
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, -2);
            Font_Printf(0x99, temp_s0 + 0xD, "ちゅうだんデータがあります");
            Font_Printf(0x99, temp_s0 + 0xA5, "つづきをしますか？");
            PakUi_DrawMenuOptionText(0xC5, temp_s0 + 0xC7, 0, arg1, "つづきをする");
            PakUi_DrawMenuOptionText(0xC5, temp_s0 + 0xC7, 1, arg1, "つづきをしない");
            PakUi_DrawMenuOptionText(0xC5, temp_s0 + 0xC7, 2, arg1, "ちゅうだんデータをけす");
            Gfx_SetEnvColor(0xFF, 0x64, 0x64, 0xFF);

            if (arg2->unk_00 == 7) {
                Font_Printf(0xA9, temp_s0 + 0x2D, D_82D065D4_jp[arg2->unk_00 - 1]);
                Font_Printf(0xA9, temp_s0 + 0x4B, D_82D065D4_jp[arg2->unk_01 + 0x13]);

                if (arg2->unk_01 < 8) {
                    if (arg2->unk_02 < 4) {
                        Font_Printf(0xA9, temp_s0 + 0x69, "トレーナー%d", arg2->unk_02);
                    } else {
                        Font_Printf(0xA9, temp_s0 + 0x69, "ジムリーダー");
                    }
                } else {
                    Font_Printf(0xA9, temp_s0 + 0x69, "してんのう%d", arg2->unk_02);
                }
            } else if ((arg2->unk_00 == 3) || (arg2->unk_00 == 6)) {
                Font_Printf(0xA9, temp_s0 + 0x2D, D_82D065D4_jp[arg2->unk_00 - 1]);
                Font_Printf(0xA9, temp_s0 + 0x4B, D_82D065D4_jp[arg2->unk_01 + 7]);
                Font_Printf(0xA9, temp_s0 + 0x69, D_82D065D4_jp[arg2->unk_02 + 0xA]);
            } else {
                Font_Printf(0xA9, temp_s0 + 0x2D, D_82D065D4_jp[arg2->unk_00 - 1]);
                Font_Printf(0xA9, temp_s0 + 0x4B, D_82D065D4_jp[arg2->unk_02 + 0xA]);
            }

            if (arg2->unk_00 != 7) {
                Font_SetActive(8, -2);
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
                Font_Printf(0x12D, temp_s0 + 0x85, "コンティニュー＝%d", arg2->unk_04);
            }

            Font_SetActive(8, -3);
            Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
            Font_Printf(0xA1, temp_s0 + 0x124, "ちゅうだんデータは「つづきをする」を");
            Font_Printf(0xA1, temp_s0 + 0x13E, "えらぶと　なくなります。");
            Font_EndTexturedTextRendering();

            if (arg2->unk_03 == 1) {
                // Two bytes per EUC-JP glyph, 22 pixels per glyph.
                s32 temp_v0_3 = (strlen(D_82D065D4_jp[arg2->unk_00 - 1]) / 2) * 0x16;

                gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

                Gfx_DrawTextureRgba16(temp_v0_3 + 0xAB, temp_s0 + 0x2B, 0x1C, 0x1C, &D_3022AA0, 0x1C, 0);

                gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
            }
        }
    }
}
#else
void PakUi_DrawDataSummaryPanel(s16 arg0, s16 arg1, SessionContinueData* arg2, s32 arg3) {
    char sp50[0x100];
    UNUSED s32 pad;
    s16 sp34 = (arg0 * 0x2C) + 2;
    s16 temp_s0;

    if (sp34 >= 0x10) {
        temp_s0 = ((0x162 - sp34) / 2) + 0x3C;
        Ui_DrawBorderedPanel(0x79, temp_s0, 0x18E, sp34, 0x2349);
        if (sp34 == 0x162) {
            PakUi_DrawDataPanelBorder(0x98, temp_s0 + 0x27, 0x150, 0x78, 0, 0, 0, 0xFF);
            PakUi_DrawDataPanelBorder(0x98, temp_s0 + 0xBF, 0x150, 0x60, 0, 0, 0, 0xFF);
            if (arg3 != 0) {
                Ui_DrawAnimatedTextureMarker(0x9D, temp_s0 + (arg1 * 0x1C) + 0xC7);
            }
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            Font_Printf(0x99, temp_s0 + 0xD, Text_GetString(NULL, 0, D_82D0AB9C, 0x29));
            Font_Printf(0x99, temp_s0 + 0xA5, Text_GetString(NULL, 0, D_82D0AB9C, 0x2A));
            PakUi_DrawMenuOptionText(0xC5, temp_s0 + 0xC7, 0, arg1, Text_GetString(NULL, 0, D_82D0AB9C, 0x2B));
            PakUi_DrawMenuOptionText(0xC5, temp_s0 + 0xC7, 1, arg1, Text_GetString(NULL, 0, D_82D0AB9C, 0x2C));
            PakUi_DrawMenuOptionText(0xC5, temp_s0 + 0xC7, 2, arg1, Text_GetString(NULL, 0, D_82D0AB9C, 0x2D));
            Gfx_SetEnvColor(0xFF, 0x64, 0x64, 0xFF);

            if (arg2->unk_00 == 7) {
                Font_Printf(0xA9, temp_s0 + 0x2D, Text_GetString(NULL, 0, D_82D0AB9C, arg2->unk_00 - 1));
                Font_Printf(0xA9, temp_s0 + 0x4B, Text_GetString(NULL, 0, D_82D0AB9C, arg2->unk_01 + 0x13));

                if (arg2->unk_01 < 8) {
                    if (arg2->unk_02 < 4) {
                        Text_SetNumberToken(1, arg2->unk_02);
                        Font_Printf(0xA9, temp_s0 + 0x69, Text_GetString(sp50, sizeof(sp50), D_82D0AB9C, 0x2E));
                    } else {
                        Font_Printf(0xA9, temp_s0 + 0x69, Text_GetString(NULL, 0, D_82D0AB9C, 0x2F));
                    }
                } else {
                    Text_SetNumberToken(1, arg2->unk_02);
                    Font_Printf(0xA9, temp_s0 + 0x69, Text_GetString(sp50, sizeof(sp50), D_82D0AB9C, 0x30));
                }
            } else if ((arg2->unk_00 == 3) || (arg2->unk_00 == 6)) {
                Font_Printf(0xA9, temp_s0 + 0x2D, Text_GetString(NULL, 0, D_82D0AB9C, arg2->unk_00 - 1));
                Font_Printf(0xA9, temp_s0 + 0x4B, Text_GetString(NULL, 0, D_82D0AB9C, arg2->unk_01 + 7));
                Font_Printf(0xA9, temp_s0 + 0x69, Text_GetString(NULL, 0, D_82D0AB9C, arg2->unk_02 + 0xA));
            } else {
                Font_Printf(0xA9, temp_s0 + 0x2D, Text_GetString(NULL, 0, D_82D0AB9C, arg2->unk_00 - 1));
                Font_Printf(0xA9, temp_s0 + 0x4B, Text_GetString(NULL, 0, D_82D0AB9C, arg2->unk_02 + 0xA));
            }

            if (arg2->unk_00 != 7) {
                Font_SetActive(8, 0);
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
                Text_SetNumberToken(1, arg2->unk_04);
                Font_Printf(0x12D, temp_s0 + 0x85, Text_GetString(&sp50, 0x100, D_82D0AB9C, 0x31));
            }

            Font_SetActive(8, 0);
            Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
            Font_SetLineHeight(0x1A);
            Font_Printf(0xA1, temp_s0 + 0x124, Text_GetString(NULL, 0, D_82D0AB9C, 0x32));
            Font_EndTexturedTextRendering();

            if (arg2->unk_03 == 1) {
                s32 temp_v0_3 = Font_MeasureTextExtent(0x10, 0, Text_GetString(NULL, 0, D_82D0AB9C, arg2->unk_00 - 1));

                gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

                Gfx_DrawTextureRgba16(temp_v0_3 + 0xAB, temp_s0 + 0x2B, 0x1C, 0x1C, &D_3022AA0, 0x1C, 0);

                gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
            }
        }
    }
}
#endif

void PakUi_UpdateConfirmDisplayFrame(s16 arg0, s16 arg1, SessionContinueData* arg2, s16 arg3, s16 arg4) {
    BgStage_DrawFrame();
    PakUi_DrawMenuBackdrop();
    PakUi_DrawDataSummaryPanel(arg0, arg1, arg2, arg3 == 0);
    PakUi_DrawRulesPanel(arg3, arg4);
    BgStage_AdvanceFrame();
}

s32 TransferPak_ConfirmPrompt(SessionContinueData* arg0) {
    s16 i;
    s16 var_s2 = 1;
    s16 var_s1 = 1;

    for (i = 1; i < 8; i++) {
        Controller_PollInputs();
        PakUi_UpdateConfirmDisplayFrame(8, 2, arg0, i, 1);
    }

    while (var_s2 != 0) {
        Controller_PollInputs();
        if (gPlayer1Controller->buttonPressed & 0xC00) {
            Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
            var_s1 ^= 1;
        } else if (gPlayer1Controller->buttonPressed & 0x8000) {
            var_s2 = 0;
        } else if (gPlayer1Controller->buttonPressed & 0x4000) {
            var_s1 = 1;
            var_s2 = 0;
        }
        PakUi_UpdateConfirmDisplayFrame(8, 2, arg0, 8, var_s1);
    }

    if (var_s1 == 0) {
        Audio_PlaySoundEffectById(0x1F);
    } else {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    }

    for (i = 7; i > 0; i--) {
        Controller_PollInputs();
        PakUi_UpdateConfirmDisplayFrame(8, 2, arg0, i, var_s1);
    }

    return var_s1 == 0;
}

#if defined(VERSION_JP)
s16 TransferPak_MainMenu(void) {
    s16 i;
    SessionContinueData sp54;
    s16 var_s1;
    s32 var_s6;
    s16 var_s0;
    s16 sp44;

    var_s6 = 1;
    var_s0 = 0;
    sp44 = 4;

    // JP loads the suspended-session record here; TransferPak_CheckMain calls this menu
    // before TransferPak_MenuLoop instead of after it.
    if (Session_LoadContinueRecord(&sp54, NULL) == -1) {
        return 4;
    }

    Audio_PlaySoundEffectById(SFX_PANEL_OPEN);

    for (i = 1; i < 8; i++) {
        Controller_PollInputs();
        PakUi_UpdateConfirmDisplayFrame(i, 0, &sp54, 0, 0);
    }

    while (var_s6 != 0) {
        var_s1 = -1;
        while (var_s1 == -1) {
            Controller_PollInputs();

            if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
                var_s1 = var_s0;
            } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
                var_s1 = 3;
            } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
                Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
                var_s0 -= 1;
                if (var_s0 < 0) {
                    var_s0 = 2;
                }
            } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
                Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
                var_s0 += 1;
                if (var_s0 >= 3) {
                    var_s0 = 0;
                }
            }
            PakUi_UpdateConfirmDisplayFrame(i, var_s0, &sp54, 0, 0);
        }

        switch (var_s1) {
            case 0:
                var_s6 = 0;
                Audio_PlaySoundEffectById(0x20);
                break;

            case 1:
                var_s6 = 0;
                Audio_PlaySoundEffectById(SFX_MENU_BACK);
                break;

            case 2:
                Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                if (TransferPak_ConfirmPrompt(&sp54) != 0) {
                    var_s6 = 0;
                }
                break;

            case 3:
                var_s6 = 0;
                Audio_PlaySoundEffectById(SFX_MENU_BACK);
                break;
        }
    }

    for (i = 7; i >= 0; i--) {
        Controller_PollInputs();
        PakUi_UpdateConfirmDisplayFrame(i, var_s0, &sp54, 0, 0);
    }

    PakUi_UpdateConfirmDisplayFrame(0, var_s0, &sp54, 0, 0);

    if (var_s1 == 0) {
        Session_LoadContinueData();
        Audio_StopMusic(0x10);
        StageContext_SetClearColor(1);
        StageFade_StartFromTransparent(8);

        while (StageContext_GetFadeMode() != 1) {
            Controller_PollInputs();
            PakUi_UpdateConfirmDisplayFrame(0, 0, &sp54, 0, 0);
        }

        StageLoader_RunFrames(2);

        if (gSessionContext.mode == 7) {
            sp44 = 0x27;
        } else {
            sp44 = 0x20;
        }
    } else if (var_s1 == 2) {
        Save_ResetAndCommitTypedRecord(0x15, 0);
        Save_FlushBank(2);
    }

    return sp44;
}

#else
s16 TransferPak_MainMenu(SessionContinueData* arg0) {
    s16 i;
    s16 var_s1;
    UNUSED s32 pad;
    s16 var_s0;
    s16 sp44;
    s32 var_s6;

    var_s6 = 1;
    var_s0 = 0;
    sp44 = 4;
    Audio_PlaySoundEffectById(SFX_PANEL_OPEN);

    for (i = 1; i < 8; i++) {
        Controller_PollInputs();
        PakUi_UpdateConfirmDisplayFrame(i, 0, arg0, 0, 0);
    }

    while (var_s6 != 0) {
        var_s1 = -1;
        while (var_s1 == -1) {
            Controller_PollInputs();

            if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
                var_s1 = var_s0;
            } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
                var_s1 = 3;
            } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
                Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
                var_s0 -= 1;
                if (var_s0 < 0) {
                    var_s0 = 2;
                }
            } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
                Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
                var_s0 += 1;
                if (var_s0 >= 3) {
                    var_s0 = 0;
                }
            }
            PakUi_UpdateConfirmDisplayFrame(i, var_s0, arg0, 0, 0);
        }

        switch (var_s1) {
            case 0:
                var_s6 = 0;
                Audio_PlaySoundEffectById(0x20);
                break;

            case 1:
                var_s6 = 0;
                Audio_PlaySoundEffectById(SFX_MENU_BACK);
                break;

            case 2:
                Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
                if (TransferPak_ConfirmPrompt(arg0) != 0) {
                    var_s6 = 0;
                }
                break;

            case 3:
                var_s6 = 0;
                Audio_PlaySoundEffectById(SFX_MENU_BACK);
                break;
        }
    }

    for (i = 7; i >= 0; i--) {
        Controller_PollInputs();
        PakUi_UpdateConfirmDisplayFrame(i, var_s0, arg0, 0, 0);
    }

    PakUi_UpdateConfirmDisplayFrame(0, var_s0, arg0, 0, 0);

    if (var_s1 == 0) {
        Session_LoadContinueData();
        Audio_StopMusic(0x10);
        StageContext_SetClearColor(1);
        StageFade_StartFromTransparent(8);

        while (StageContext_GetFadeMode() != 1) {
            Controller_PollInputs();
            PakUi_UpdateConfirmDisplayFrame(0, 0, arg0, 0, 0);
        }

        StageLoader_RunFrames(2);

        if (gSessionContext.mode == 7) {
            sp44 = 0x27;
        } else {
            sp44 = 0x20;
        }
    } else if (var_s1 == 2) {
        Save_ResetAndCommitTypedRecord(0x15, 0);
        Save_FlushBank(2);
    }

    if (var_s1 != 0) {
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(8);
        while (StageContext_GetFadeMode() != 1) {
            Controller_PollInputs();
            PakUi_UpdateConfirmDisplayFrame(0, var_s0, arg0, 0, 0);
        }
    }
    return sp44;
}
#endif

void PakUi_DrawStatusPopup(PakUi_StatusPopup* arg0) {
#if defined(VERSION_JP)
    // Indexed by status code - 1; the other versions print message ID status code + 0x32.
    static char* D_82D09120_jp[] = {
        "カートリッジがセットされ\nていません。",
        "このカートリッジはつかえ\nません。",
        "てもちのポケモンが６ぴき\nそろっていません。",
        "コントローラがセットされ\nていません。",
    };
#endif
    s16 temp_s0;
    s16 sp48;
    s16 sp4A;

    if (arg0->unk_02 >= 0x10) {
        sp48 = arg0->unk_02;
        sp4A = arg0->unk_04;
        temp_s0 = arg0->unk_06 + ((0xA6 - sp48) / 2);
        Ui_DrawBorderedPanel(sp4A, temp_s0, 0x19E, sp48, 1);
        if (arg0->unk_02 == 0xA6) {
            gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

            Gfx_DrawTextureRgba16(sp4A + 0x1E, temp_s0 + 0x20, 0x48, 0x12, D_3024C80, 0x48, 0);
            Gfx_DrawTextureRgba16(sp4A + 0x1E, temp_s0 + 0x32, 0x48, 0x12, &D_30256A0, 0x48, 0);
            Gfx_DrawTextureRgba16(sp4A + 0x1E, temp_s0 + 0x62, 0x48, 0x12, D_30260C0, 0x48, 0);
            Gfx_DrawTextureRgba16(sp4A + 0x1E, temp_s0 + 0x74, 0x48, 0x12, &D_3026AE0, 0x48, 0);

            gDPSetEnvColor(gDisplayListHead++, 200, 30, 30, 150);

            if (arg0->unk_08 != 0) {
                Gfx_DrawTextureI4(sp4A + 0x22, temp_s0 + 0x12, 0x40, 0x40, &D_3024480, 0x40, 0);
            }

            if (arg0->unk_0A != 0) {
                Gfx_DrawTextureI4(sp4A + 0x22, temp_s0 + 0x54, 0x40, 0x40, &D_3024480, 0x40, 0);
            }

            gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

            Font_BeginTranslucentTextRendering();
#if defined(VERSION_JP)
            Font_SetActive(0x10, -2);
#else
            Font_SetActive(0x10, 0);
#endif
            Gfx_SetEnvColor(0xFF, 0x64, 0x32, 0xFF);
            Font_SetLineHeight(0x1C);

#if defined(VERSION_JP)
            if (arg0->unk_08 != 0) {
                Font_Printf(sp4A + 0x76, temp_s0 + 0x18, D_82D09120_jp[arg0->unk_08 - 1]);
            }

            if (arg0->unk_0A != 0) {
                Font_Printf(sp4A + 0x76, temp_s0 + 0x5A, D_82D09120_jp[arg0->unk_0A - 1]);
            }
#else
            if (arg0->unk_08 != 0) {
                Font_Printf(sp4A + 0x76, temp_s0 + 0x18, Text_GetString(NULL, 0, D_82D0AB9C, arg0->unk_08 + 0x32));
            }

            if (arg0->unk_0A != 0) {
                Font_Printf(sp4A + 0x76, temp_s0 + 0x5A, Text_GetString(NULL, 0, D_82D0AB9C, arg0->unk_0A + 0x32));
            }
#endif

            Font_EndTexturedTextRendering();
        }
    }
}

s32 PakUi_UpdateStatusPopup(PakUi_StatusPopup* arg0) {
    s16 sp1E = -2;

    switch (arg0->unk_00) {
        case 1:
            if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B)) {
                Audio_PlaySoundEffectById(SFX_MENU_BACK);
                arg0->unk_00 = 3;
            }
            break;

        case 2:
            arg0->unk_02 += 0x14;
            if (arg0->unk_02 == 0xA6) {
                arg0->unk_00 = 1;
            }
            break;

        case 3:
            arg0->unk_02 -= 0x14;
            if (arg0->unk_02 == 6) {
                arg0->unk_00 = 0;
                sp1E = -1;
            }
            break;
    }
    return sp1E;
}

void PakUi_InitStatusPopup(PakUi_StatusPopup* arg0, s16 arg1, s16 arg2) {
    arg0->unk_00 = 0;
    arg0->unk_02 = 6;
    arg0->unk_04 = arg1;
    arg0->unk_06 = arg2;
}

void PakUi_OpenStatusPopup(PakUi_StatusPopup* arg0, s16 arg1, s16 arg2) {
    arg0->unk_00 = 2;
    arg0->unk_08 = arg1;
    arg0->unk_0A = arg2;
}

s32 PakUi_RenderMenuIconTexture(s32 arg0, UNUSED unk_func_80011B94* arg1) {
    static Gfx* D_82D09EF8[] = {
#if defined(VERSION_JP)
        D_82D08C70, D_82D09850, D_82D09CF0, D_82D09CF0, D_82D09850, D_82D09CF0, D_82D09CF0,
#else
        D_82D08C70, D_82D09850, D_82D09CF0, D_82D09340, D_82D09850, D_82D09CF0, D_82D09CF0,
#endif
    };

    s32 var_a2;
    s32 var_a3;

    if (arg0 == 5) {
        var_a3 = D_8006F09C->node.callbackArg;
        var_a2 = var_a3;
        if ((var_a3 == 0) && (gSessionContext.inRound2 == 1)) {
            var_a2 = 7;
        }

        gDPPipeSync(gDisplayListHead++);

        gSPSegment(gDisplayListHead++, 0x0F, (u32)D_82D0ABE0[var_a2]->img_p & 0x1FFFFFFF);

#if !defined(VERSION_JP)
        // JP sets this combine mode in the icon display lists instead (D_82D08C70 and others).
        if (D_8006F09C->lodFraction < 0xFF) {
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, D_8006F09C->lodFraction);
            gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0,
                              0, COMBINED);
        } else {
            gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_PASS2);
        }
#endif

        gSPDisplayList(gDisplayListHead++, D_82D09EF8[var_a3]);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

#if !defined(VERSION_JP)
static u8 D_82D09F14[] = {
    0x37, 0x38, 0x39, 0x45, 0x3A, 0x3A, 0x3A,
};
#endif

#if defined(VERSION_JP)
// Entry 3 has no neighbours: JP has no menu icon in that slot.
static unk_D_82D09F1C D_82D09F1C[] = {
    { 240, 120, 160, 140, 0xFF, 0x02, 0x04, 0x01 },
    { 424, 180, 160, 80, 0xFF, 0xFF, 0x00, 0xFF },
    { 240, 284, 160, 36, 0x00, 0xFF, 0xFF, 0xFF },
    { 424, 284, 160, 36, 0xFF, 0xFF, 0xFF, 0xFF },
    { 56, 180, 160, 80, 0xFF, 0xFF, 0xFF, 0x00 },
    { 56, 224, 160, 36, 0xFF, 0x06, 0xFF, 0xFF },
    { 56, 276, 160, 36, 0x05, 0xFF, 0xFF, 0xFF },
};
#else
static unk_D_82D09F1C D_82D09F1C[] = {
    {
        240,
        120,
        160,
        140,
        0xFF,
        0x03,
        0x04,
        0x01,
    },
    {
        424,
        180,
        160,
        80,
        0xFF,
        0x02,
        0x00,
        0xFF,
    },
    {
        424,
        284,
        160,
        36,
        0x01,
        0xFF,
        0x03,
        0xFF,
    },
    {
        240,
        276,
        160,
        52,
        0x00,
        0xFF,
        0xFF,
        0x02,
    },
    {
        56,
        180,
        160,
        80,
        0xFF,
        0xFF,
        0xFF,
        0x00,
    },
    {
        56,
        224,
        160,
        36,
        0xFF,
        0x06,
        0xFF,
        0xFF,
    },
    {
        56,
        276,
        160,
        36,
        0x05,
        0xFF,
        0xFF,
        0xFF,
    },
};
#endif

#if defined(VERSION_JP)
// Description printed under the highlighted menu entry; PakUi_DrawBodyProgressBar maps
// cursor positions 4-6 to entry 4. The other versions print message IDs from D_82D09F14.
static char* D_82D091A0_jp[] = {
    "スタジアムは　ここにあります。\nバトルかいじょう、ポケモンけんきゅうじょ\nミニゲームなど　いろいろ　あります。",
    "コントローラ１と２に　セットされた\nカートリッジの　てもちのポケモンどうしの\nバトルです。",
    "サウンドのせってい、６４カセットのセーブ\nデータのクリア　などが　できます。",
    "ERROR",
    "とにかく１びょうでも　はやくバトルを\nやってみたい　というひとは　ここで\nあそんでみて　ください。",
};
#endif

s32 PakUi_ComputeBlinkAlpha(void) {
    static s16 D_82D09F70 = 0;

    s16 var_a0;

    // clang-format off
    if (D_82D09F70 >= 0) { var_a0 = SINS((s32)(SINS(D_82D09F70) * 0x4000)) * 127.0f; 
        var_a0 += 0x7F; 
    } else { 
        var_a0 = (SINS(D_82D09F70) * 127.0f);        
        var_a0 += 0x7F;    
    }
    // clang-format on
    D_82D09F70 += 0x400;
    return var_a0;
}

#if defined(VERSION_JP)
void PakUi_DrawHeaderProgressBar(s32 arg0) {
    s32 progress;
    s16 sp3A;
    s16 tmp;

    if (arg0 > 0) {
        if (arg0 >= 0xB) {
            arg0 = 0xA;
        }

        progress = arg0 * 0x3C;
        tmp = progress / 10;
        PakUi_DrawThickBoxBorder(0x38, (s16)((0x3C - tmp) / 2) + 0x24, 0x210, tmp, 0x1E, 0x1E, 0x82, 0x96);
        if (progress == 600) {
            sp3A = PakUi_ComputeBlinkAlpha();
            if (D_82D0AB90.clearedModes == PAKUI_ALL_MODES_CLEARED) {
                gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
                gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sp3A);

                Gfx_DrawTextureRgba16(0x1B8, 0x35, 0x1C, 0x1A, &D_2016010, 0x1C, 0);

                gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
            }

            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, -1);
            Font_Printf(0xE0, 0x36, "えらんでください");

            if (D_82D0AB90.clearedModes == PAKUI_ALL_MODES_CLEARED) {
                Font_SetActive(8, -2);
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, sp3A);
                Font_Printf(0x1D6, 0x2D, "スタジアム");
                Font_Printf(0x1D6, 0x43, "きりかえ");
            }

            Font_EndTexturedTextRendering();
        }
    }
}

void PakUi_DrawBodyProgressBar(s32 arg0) {
    s32 progress;
    s16 sp32;
    s16 temp_lo_2;

    if (arg0 > 0) {
        if (arg0 >= 0xB) {
            arg0 = 0xA;
        }

        progress = arg0 * 0x64;
        temp_lo_2 = progress / 10;
        PakUi_DrawThinBoxBorder(0x38, (s16)((0x64 - temp_lo_2) / 2) + 0x154, 0x210, temp_lo_2, 0x1E, 0x1E, 0x82,
                                0x96);
        if ((progress == 1000) && (D_82D06FA0 < 7)) {
            if (D_82D06FA0 < 5) {
                sp32 = D_82D06FA0;
            } else {
                sp32 = 4;
            }
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            Font_SetLineHeight(0x1C);
            Font_Printf(0x50, 0x15E, D_82D091A0_jp[sp32]);
            Font_EndTexturedTextRendering();
        }
    }
}
#else
void PakUi_DrawHeaderProgressBar(s32 arg0, s32 arg1) {
    UNUSED s32 pad;
    s16 tmp;
    s16 sp48;

    if (arg1 == 0) {
        if (arg0 >= 0xB) {
            arg0 = 0xA;
        }
    } else if (arg0 >= 0xB) {
        if (arg0 < 0x1B) {
            arg0 = 0xA;
        } else {
            arg0 = 0x24 - arg0;
            if (arg0 < 0) {
                arg0 = 0;
            }
        }
    }

    if (arg0 > 0) {
        tmp = (arg0 * 0x3C) / 10;
        PakUi_DrawThickBoxBorder(0x38, (s16)((0x3C - tmp) / 2) + 0x24, 0x210, tmp, 0x1E, 0x1E, 0x82, 0x96);
        if (arg0 == 10) {
            sp48 = PakUi_ComputeBlinkAlpha();
            if (D_82D0AB90.clearedModes == PAKUI_ALL_MODES_CLEARED) {
                gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);
                gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sp48);

                Gfx_DrawTextureRgba16(0x1B8, 0x35, 0x1C, 0x1A, &D_2016010, 0x1C, 0);

                gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
            }

            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            tmp = (Font_MeasureTextExtent(0x10, 0, Text_GetString(NULL, 0, D_82D0AB9C, 0x3B)));
            Font_Printf(0x140 - tmp / 2, 0x36, Text_GetString(NULL, 0, D_82D0AB9C, 0x3B));

            if (D_82D0AB90.clearedModes == PAKUI_ALL_MODES_CLEARED) {
                Font_SetActive(8, 0);
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, sp48);
                Font_Printf(0x1D6, 0x2D, Text_GetString(NULL, 0, D_82D0AB9C, 0x3C));
                Font_Printf(0x1D6, 0x43, Text_GetString(NULL, 0, D_82D0AB9C, 0x3D));
            }

            Font_EndTexturedTextRendering();
        }
    }
}

void PakUi_DrawBodyProgressBar(s32 arg0, s32 arg1) {
    s16 temp_lo_2;

    if (arg1 == 0) {
        if (arg0 >= 0xB) {
            arg0 = 0xA;
        }
    } else if (arg0 >= 0xB) {
        if (arg0 < 0x1B) {
            arg0 = 0xA;
        } else {
            arg0 = 0x24 - arg0;
            if (arg0 < 0) {
                arg0 = 0;
            }
        }
    }
    if (arg0 > 0) {
        temp_lo_2 = (arg0 * 0x64) / 10;
        PakUi_DrawThinBoxBorder(0x38, (s16)((0x64 - temp_lo_2) / 2) + 0x154, 0x210, temp_lo_2, 0x1E, 0x1E, 0x82, 0x96);
        if ((arg0 == 10) && (D_82D06FA0 < 7)) {
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            Font_SetLineHeight(0x1C);
            if (D_82D0ABA4 == 0) {
                Font_Printf(0x50, 0x15E, Text_GetString(NULL, 0, D_82D0AB9C, D_82D09F14[D_82D06FA0]));
            } else {
                Font_Printf(0x50, 0x15E, Text_GetString(NULL, 0, D_82D0AB9C, 0x46));
            }
            Font_EndTexturedTextRendering();
        }
    }
}
#endif

void PakUi_UpdateMenuDisplayFrame(s32 arg0, s32 arg1) {
    s16 i;
    s32 sp30;
    s16 var_a0;
    s32 temp_lo_4;

    if (arg0 < 0xB) {
        var_a0 = ((10 - arg0) * -0x5000) / 10;
        for (i = 0; i < 5; i++) {
            D_82D09FF8[i].rotation.x = var_a0;
        }
        D_82D09FF8[4].position.y = 18.0f;
    } else if (arg0 < 0x11) {
        D_82D09FF8[4].position.y = (((arg0 * 0x34) - 0x208) / 6) + 0x12;
        for (i = 0; i < 4; i++) {
            D_82D09FF8[i].rotation.x = 0;
        }

        for (i = 5; i < 7; i++) {
            D_82D09FF8[i].rotation.x = -0x5000;
        }
    } else if (arg0 < 0x1B) {
        temp_lo_4 = (arg0 * 0x5000) + 0xFFFB0000;
        var_a0 = temp_lo_4 / 10;
        D_82D09FF8[4].position.y = 70.0f;

        for (i = 0; i < 4; i++) {
            D_82D09FF8[i].rotation.x = var_a0;
        }

        for (i = 5; i < 7; i++) {
            D_82D09FF8[i].rotation.x = var_a0 - 0x5000;
        }
    } else {
        temp_lo_4 = (arg0 * 0x5000) + 0xFFF7E000;
        var_a0 = temp_lo_4 / 10;
        for (i = 0; i < 7; i++) {
#if defined(VERSION_JP)
            if ((i != D_82D06FA0) && (D_82D09FF8[i].rotation.x >= 0)) {
                if (D_82D09FF8[i].rotation.x < var_a0) {
                    D_82D09FF8[i].rotation.x = var_a0;
                }
            }
#else
            if ((D_82D0ABA8 == 0) || (D_82D06FA0 != 0)) {
                if ((i != D_82D06FA0) && (D_82D09FF8[i].rotation.x >= 0)) {
                    if (D_82D09FF8[i].rotation.x < var_a0) {
                        D_82D09FF8[i].rotation.x = var_a0;
                    }
                }
            } else if (D_82D09FF8[i].rotation.x >= 0) {
                if (D_82D09FF8[i].rotation.x < var_a0) {
                    D_82D09FF8[i].rotation.x = var_a0;
                }
            }
#endif
        }

        if (D_82D06FA0 >= 5) {
            D_82D09FF8[4].rotation.x = 0;
        }
    }

#if defined(VERSION_JP)
    BgStage_DrawFrame();
    PakUi_DrawMenuBackdrop();
    Geo_RenderRootNode(D_82D09FF0);
    PakUi_DrawHeaderProgressBar(arg0);
    PakUi_DrawBodyProgressBar(arg0);
#else
    if ((D_82D0ABA8 == 0) || (D_82D06FA0 != 0)) {
        sp30 = 0;
    } else {
        sp30 = 1;
    }

    BgStage_DrawFrame();
    PakUi_DrawMenuBackdrop();
    Geo_RenderRootNode(D_82D09FF0);
    PakUi_DrawHeaderProgressBar(arg0, sp30);
    PakUi_DrawBodyProgressBar(arg0, sp30);
#endif

    if (arg1 != 0) {
        unk_D_82D09F1C* ptr = &D_82D09F1C[D_82D06FA0];
        PakUi_DrawRotatingCorners(ptr->unk_00, ptr->unk_02, ptr->unk_04, ptr->unk_06, 0xFF, 0xF0, 0x64, 0xFF);
    }

    PakUi_DrawStatusPopup(&D_82D0ABD0);
    BgStage_AdvanceFrame();
}

DepthBuffer* PakUi_BuildGameIconBuffer(s32 arg0) {
    UNUSED s32 pad;
    s16 i;
    DepthBuffer* sp3C;
    u8* var_s3;
    s16 temp_s0;

    if (arg0 == 0) {
        var_s3 = D_30111A0;
    } else {
        var_s3 = D_3017DA0;
    }

    sp3C = GfxImage_Allocate(0, 2, 0xAC, 0x98, 1);
    PakUi_BuildFrameBuffer(sp3C, 0xA8, 0x94);

    gSPDisplayList(gDisplayListHead++, D_8006F470);

    if (arg0 == 0) {
        Gfx_FillRectRgb(4, 4, 0xA0, 0x8C, 0x1E, 0x1E, 0x82);
    } else {
        Gfx_FillRectRgb(4, 4, 0xA0, 0x8C, 0x64, 0x1E, 0x1E);
    }

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    for (i = 0; i < 8; i++) {
        Gfx_DrawTextureRgba16(0xC, (i * 0xC) + 0xC, 0x90, 0xC, (i * 0xD80) + var_s3, 0x90, 0);
    }

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    Font_BeginTranslucentTextRendering();
#if defined(VERSION_JP)
    Font_SetActive(8, -4);
    Font_Printf(0xA, 0x74, "ポケモンスタジアム");
    // EUC-JP code 0xA5B8, sign-extended as an s16.
    Font_DrawCharAt(0x6A, 0x74, (s16)0xA5B8);
#else
    temp_s0 = Font_MeasureTextExtent(8, 0, Text_GetString(NULL, 0, D_82D0AB9C, 0x3E));
    Font_SetActive(8, 0);
    Font_Printf(0x54 - (temp_s0 / 2), 0x74, Text_GetString(NULL, 0, D_82D0AB9C, 0x3E));
#endif
    Font_EndTexturedTextRendering();

    return sp3C;
}

DepthBuffer* PakUi_BuildControllerIconBuffer(void) {
    DepthBuffer* sp34;

    sp34 = GfxImage_Allocate(0, 2, 0xAC, 0x5C, 1);
    PakUi_BuildFrameBuffer(sp34, 0xA8, 0x58);

    gSPDisplayList(gDisplayListHead++, D_8006F470);

    Gfx_FillRectRgb(4, 4, 0xA0, 0x50, 0x1E, 0x1E, 0x82);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    Gfx_DrawTextureRgba16(0xC, 0xC, 0x40, 0x20, &D_301E9A0, 0x40, 0);
    Gfx_DrawTextureRgba16(0xC, 0x2C, 0x40, 0x20, &D_301F9A0, 0x40, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);
#if defined(VERSION_JP)
    Font_Printf(0x50, 0xA, "とにかく");
    Font_Printf(0x50, 0x22, "バトルが");
    Font_Printf(0x50, 0x3A, "したい！");
#else
    Font_SetLineHeight(0x16);
    Font_Printf(0x50, 0x17, Text_GetString(NULL, 0, D_82D0AB9C, 0x3F));
#endif
    Font_EndTexturedTextRendering();

    return sp34;
}

DepthBuffer* PakUi_BuildControllerIconBufferAlt(void) {
    DepthBuffer* sp34;

    sp34 = GfxImage_Allocate(0, 2, 0xAC, 0x5C, 1);
    PakUi_BuildFrameBuffer(sp34, 0xA8, 0x58);

    gSPDisplayList(gDisplayListHead++, D_8006F470);

    Gfx_FillRectRgb(4, 4, 0xA0, 0x50, 0x1E, 0x1E, 0x82);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    Gfx_DrawTextureRgba16(0xC, 0xC, 0x40, 0x20, &D_30209A0, 0x40, 0);
    Gfx_DrawTextureRgba16(0xC, 0x2C, 0x40, 0x20, &D_30219A0, 0x40, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);
#if defined(VERSION_JP)
    Font_Printf(0x50, 0x17, "イベント");
    Font_Printf(0x5A, 0x2D, "バトル");
#else
    Font_SetLineHeight(0x16);
    Font_Printf(0x50, 0x17, Text_GetString(NULL, 0, D_82D0AB9C, 0x40));
#endif
    Font_EndTexturedTextRendering();

    return sp34;
}

#if !defined(VERSION_JP)
DepthBuffer* PakUi_BuildMonIconBuffer(void) {
    DepthBuffer* sp34;

    sp34 = GfxImage_Allocate(0, 2, 0xAC, 0x40, 1);
    PakUi_BuildFrameBuffer(sp34, 0xA8, 0x3C);

    gSPDisplayList(gDisplayListHead++, D_8006F470);

    Gfx_FillRectRgb(4, 4, 0xA0, 0x34, 0x1E, 0x1E, 0x82);

    gSPDisplayList(gDisplayListHead++, gUiEnvTintTextureDL);

    Gfx_DrawTextureRgba16(6, 6, 0x30, 0x18, &D_30230C0, 0x30, 0);
    Gfx_DrawTextureRgba16(6, 0x1E, 0x30, 0x18, &D_30239C0, 0x30, 0);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);
    Font_SetLineHeight(0x16);
    Font_Printf(0x40, 0x14, Text_GetString(NULL, 0, D_82D0AB9C, 0x44));
    Font_EndTexturedTextRendering();

    return sp34;
}
#endif

DepthBuffer* PakUi_BuildTextLabelBuffer(s8* arg0, u8 arg1, u8 arg2, u8 arg3) {
#if !defined(VERSION_JP)
    s32 sp2C;
#endif
    DepthBuffer* sp28;

#if !defined(VERSION_JP)
    sp2C = Font_MeasureTextExtent(8, 0, arg0);
#endif
    sp28 = GfxImage_Allocate(0, 2, 0xAC, 0x30, 1);
    PakUi_BuildFrameBuffer(sp28, 0xA8, 0x2C);

    gSPDisplayList(gDisplayListHead++, D_8006F470);

    Gfx_FillRectRgb(4, 4, 0xA0, 0x24, arg1, arg2, arg3);

    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(8, 0);
#if defined(VERSION_JP)
    Font_Printf(0xE, 0xC, arg0);
#else
    Font_Printf(0x54 - (sp2C / 2), 0xC, arg0);
#endif
    Font_EndTexturedTextRendering();

    return sp28;
}

#if defined(VERSION_JP)
void TransferPak_MenuIconsInit(void) {
    s32 i;

    main_pool_push_state('msel');

    // JP has no icon for slot 3 and no D_82D0AC0C model; see D_82D09EF8.
    D_82D0ABE0[0] = PakUi_BuildGameIconBuffer(0);
    D_82D0ABE0[7] = PakUi_BuildGameIconBuffer(1);
    D_82D0ABE0[1] = PakUi_BuildControllerIconBufferAlt();
    D_82D0ABE0[2] = PakUi_BuildTextLabelBuffer("　オプション", 0x1E, 0x64, 0x1E);
    D_82D0ABE0[4] = PakUi_BuildControllerIconBuffer();
    D_82D0ABE0[5] = PakUi_BuildTextLabelBuffer("ひとりでバトル", 0x1E, 0x64, 0x1E);
    D_82D0ABE0[6] = PakUi_BuildTextLabelBuffer("ふたりでバトル", 0x1E, 0x64, 0x1E);

    Model_InitDisplayObject(&D_82D09FF8[0], 0, 0, D_82D0AC00);
    Model_InitDisplayObject(&D_82D09FF8[1], 0, 0, D_82D0AC04);
    Model_InitDisplayObject(&D_82D09FF8[2], 0, 0, D_82D0AC08);
    Model_InitDisplayObject(&D_82D09FF8[4], 0, 0, D_82D0AC04);
    Model_InitDisplayObject(&D_82D09FF8[5], 0, 0, D_82D0AC08);
    Model_InitDisplayObject(&D_82D09FF8[6], 0, 0, D_82D0AC08);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[0].position, -84.0f, 48.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[1].position, 100.0f, 18.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[2].position, -84.0f, -64.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[3].position, 100.0f, -64.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[4].position, -268.0f, 18.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[5].position, -268.0f, -4.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[6].position, -268.0f, -56.0f, -579.0f);

    for (i = 0; i < 6; i++) {
        D_82D09FF8[i].rotation.x = 0;
        D_82D09FF8[i].rotation.y = 0;
    }

    D_82D09FF8[5].rotation.x = -0x5000;
    D_82D09FF8[6].rotation.x = -0x5000;

    PakUi_InitStatusPopup(&D_82D0ABD0, 0x71, 0x84);
}
#else
void TransferPak_MenuIconsInit(void) {
    s32 i;
    u8 sp1B = Cont_GetControllerBits();

    main_pool_push_state('msel');

    D_82D0ABE0[0] = PakUi_BuildGameIconBuffer(0);
    D_82D0ABE0[7] = PakUi_BuildGameIconBuffer(1);
    D_82D0ABE0[1] = PakUi_BuildControllerIconBufferAlt();
    D_82D0ABE0[2] = PakUi_BuildTextLabelBuffer(Text_GetString(NULL, 0, D_82D0AB9C, 0x41), 0x1E, 0x64, 0x1E);
    D_82D0ABE0[3] = PakUi_BuildMonIconBuffer();
    D_82D0ABE0[4] = PakUi_BuildControllerIconBuffer();
    D_82D0ABE0[5] = PakUi_BuildTextLabelBuffer(Text_GetString(NULL, 0, D_82D0AB9C, 0x42), 0x1E, 0x64, 0x1E);
    D_82D0ABE0[6] = PakUi_BuildTextLabelBuffer(Text_GetString(NULL, 0, D_82D0AB9C, 0x43), 0x1E, 0x64, 0x1E);

    Model_InitDisplayObject(&D_82D09FF8[0], 0, 0, D_82D0AC00);
    Model_InitDisplayObject(&D_82D09FF8[1], 0, 0, D_82D0AC04);
    Model_InitDisplayObject(&D_82D09FF8[2], 0, 0, D_82D0AC08);
    Model_InitDisplayObject(&D_82D09FF8[3], 0, 0, D_82D0AC0C);
    Model_InitDisplayObject(&D_82D09FF8[4], 0, 0, D_82D0AC04);
    Model_InitDisplayObject(&D_82D09FF8[5], 0, 0, D_82D0AC08);
    Model_InitDisplayObject(&D_82D09FF8[6], 0, 0, D_82D0AC08);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[0].position, -84.0f, 48.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[1].position, 100.0f, 18.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[3].position, -84.0f, -64.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[2].position, 100.0f, -64.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[4].position, -268.0f, 18.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[5].position, -268.0f, -4.0f, -579.0f);
    Vec3f_SetComponentsDuplicate(&D_82D09FF8[6].position, -268.0f, -56.0f, -579.0f);

    for (i = 0; i < 6; i++) {
        D_82D09FF8[i].rotation.x = 0;
        D_82D09FF8[i].rotation.y = 0;
    }

    D_82D09FF8[5].rotation.x = -0x5000;
    D_82D09FF8[6].rotation.x = -0x5000;

    for (i = 0; i < 7; i++) {
        if (D_82D0ABA0 != 0) {
            switch (i) {
                case 0:
                case 1:
                case 2:
                    D_82D09FF8[i].lodFraction = 0x80;
                    break;

                case 6:
                    if (sp1B & 2) {
                        D_82D09FF8[i].lodFraction = 0xFF;
                    } else {
                        D_82D09FF8[i].lodFraction = 0x80;
                    }
                    break;
                default:
                    D_82D09FF8[i].lodFraction = 0xFF;
                    break;
            }
        } else {
            D_82D09FF8[i].lodFraction = 0xFF;
        }
    }

    PakUi_InitStatusPopup(&D_82D0ABD0, 0x71, 0x84);
}
#endif

void TransferPak_MenuIconsFree(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        ModelRenderer_ClearDisplayObject(D_82D09FF8);
    }

    main_pool_pop_state('msel');
}

s32 TransferPak_MenuHandleInput(void) {
    s16 var_a3;
    s16 sp24;
#if !defined(VERSION_JP)
    s16 sp22;
#endif
    s16 var_a1;
    s16 var_a2;

    sp24 = -1;
#if !defined(VERSION_JP)
    sp22 = D_82D06FA0;
#endif
    var_a3 = -1;
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
#if defined(VERSION_JP)
        var_a3 = D_82D06FA0;
#else
        if (D_82D09FF8[D_82D06FA0].lodFraction == 0xFF) {
            var_a3 = D_82D06FA0;
        } else {
            D_82D0ABA4 = 1;
            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
            var_a3 = -1;
        }
#endif
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        var_a3 = 7;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        sp24 = D_82D09F1C[D_82D06FA0].unk_08;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        sp24 = D_82D09F1C[D_82D06FA0].unk_09;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DLEFT)) {
        sp24 = D_82D09F1C[D_82D06FA0].unk_0A;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DRIGHT)) {
        sp24 = D_82D09F1C[D_82D06FA0].unk_0B;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_CRIGHT) &&
               (D_82D0AB90.clearedModes == PAKUI_ALL_MODES_CLEARED)) {
        Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
        var_a3 = -1;
        gSessionContext.inRound2 ^= 1;
    }

#if !defined(VERSION_JP)
    if ((sp24 != -1) && (sp22 != sp24)) {
        D_82D0ABA4 = 0;
    }
#endif

    if (var_a3 == 1) {
        var_a1 = 0;
        var_a2 = 0;
        if (D_82D0AB38->unk_01 == 0) {
            var_a1 = 1;
        } else if (D_82D0AB38->unk_00 != 0) {
            var_a1 = 2;
        } else if (D_82D0AB38->unk_02 != 6) {
            var_a1 = 3;
        }

        if (D_82D0AB38[1].unk_04 == 0) {
            var_a2 = 4;
        } else if (D_82D0AB38[1].unk_01 == 0) {
            var_a2 = 1;
        } else if (D_82D0AB38[1].unk_00 != 0) {
            var_a2 = 2;
        } else if (D_82D0AB38[1].unk_02 != 6) {
            var_a2 = 3;
        }

        if ((var_a1 != 0) || (var_a2 != 0)) {
            Audio_PlaySoundEffectById(SFX_MENU_ERROR);
            PakUi_OpenStatusPopup(&D_82D0ABD0, var_a1, var_a2);
            var_a3 = -2;
        }
    }

    if ((var_a3 == 6) && (D_82D0AB38[1].unk_04 == 0)) {
        Audio_PlaySoundEffectById(SFX_MENU_ERROR);
        PakUi_OpenStatusPopup(&D_82D0ABD0, 0, 4);
        var_a3 = -2;
    }

    if (var_a3 == 7) {
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    } else if (var_a3 >= 0) {
        Audio_PlaySoundEffectById(0x1C);
    }

    if (sp24 != -1) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
        D_82D06FA0 = sp24;
    }
    return var_a3;
}

s32 TransferPak_MenuCursorToCode(void) {
    s32 sp4;

    switch (D_82D06FA0) {
        case 0:
            sp4 = 0x10;
            break;

        case 1:
            sp4 = 0x12;
            break;

        case 2:
            sp4 = 0x13;
            break;

        case 3:
#if defined(VERSION_JP)
            sp4 = 2;
#else
            sp4 = 0x11;
#endif
            break;

        case 4:
            sp4 = 2;
            break;

        case 5:
            sp4 = 0x28;
            break;

        case 6:
            sp4 = 0x29;
            break;

        case 7:
            sp4 = 2;
            break;
    }
    return sp4;
}

s16 TransferPak_MenuLoop(void) {
    s16 i;
    s16 var_s1;
    s16 var_s0;

    var_s0 = -1;
#if !defined(VERSION_JP)
    D_82D0ABA4 = 0;
#endif
    TransferPak_MenuIconsInit();
    D_82D06FA0 = 0;
    if (StageContext_GetFadeMode() != 0) {
        StageFade_StartFromOpaque(8);
        while (StageContext_GetFadeMode() != 0) {
            Controller_PollInputs();
            PakUi_UpdateMenuDisplayFrame(0, 0);
        }
    }

    for (i = 0; i < 10; i++) {
        Controller_PollInputs();
        PakUi_UpdateMenuDisplayFrame(i, 0);
    }

    while (var_s0 == -1) {
        while (var_s0 < 0) {
            Controller_PollInputs();
            if (var_s0 == -1) {
                var_s0 = TransferPak_MenuHandleInput();
            } else {
                var_s0 = PakUi_UpdateStatusPopup(&D_82D0ABD0);
            }
            PakUi_UpdateMenuDisplayFrame(i, var_s0 == -1);
        }
        D_82D06FA0 = var_s0;

        if (D_82D06FA0 == 4) {
            for (i = 11; i < 26; i++) {
                Controller_PollInputs();
                PakUi_UpdateMenuDisplayFrame(i, 0);
            }

            D_82D06FA0 = 5;

            var_s0 = -1;
            while (var_s0 < 0) {
                Controller_PollInputs();
                if (var_s0 == -1) {
                    var_s0 = TransferPak_MenuHandleInput();
                } else {
                    var_s0 = PakUi_UpdateStatusPopup(&D_82D0ABD0);
                }
                PakUi_UpdateMenuDisplayFrame(i, var_s0 == -1);
            }
            D_82D06FA0 = var_s0;

            if (D_82D06FA0 == 7) {
                for (i = 25; i >= 11; i--) {
                    Controller_PollInputs();
                    PakUi_UpdateMenuDisplayFrame(i, 0);
                }
                D_82D06FA0 = 4;
                var_s0 = -1;
            }
        }
    }

    if (D_82D06FA0 < 7) {
        for (i = 27; i < 36; i++) {
            Controller_PollInputs();
            PakUi_UpdateMenuDisplayFrame(i, 0);
        }
    }

    if (D_82D06FA0 == 0) {
        Audio_PlayMusicIfChangedImmediate(0x50);
    } else if (D_82D06FA0 != 2) {
        Audio_StopMusic(0x10);
    }

    // JP has already shown the continue prompt (TransferPak_MainMenu) before this menu, so it
    // always fades out here.
#if !defined(VERSION_JP)
    if ((D_82D0ABA8 == 0) || (D_82D06FA0 != 0))
#endif
    {
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(8);
        while (StageContext_GetFadeMode() != 1) {
            Controller_PollInputs();
            PakUi_UpdateMenuDisplayFrame(i, 0);
        }
    }

    TransferPak_MenuIconsFree();
    return TransferPak_MenuCursorToCode();
}

void Pak_PollPortStatus(void) {
    s32 i;
    u8 temp_s3 = Cont_GetControllerBits();
    GbSavePlayerIdentity sp48;

    for (i = 0; i < 4; i++) {
        GbSave_CopyPlayerIdentity(i, &sp48);
        Text_UntranscodeName(&D_82D0AB38[i].unk_08, &sp48.unk_02);
        D_82D0AB38[i].unk_06 = sp48.unk_00;
        D_82D0AB38[i].unk_01 = GbSave_GetPortGame(i);
        D_82D0AB38[i].unk_00 = GbSave_GetSaveState(i);
        D_82D0AB38[i].unk_03 = GbSave_SavedAtPokemonCenter(i);
        D_82D0AB38[i].unk_04 = (temp_s3 & (1 << i)) != 0;
        D_82D0AB38[i].unk_02 = GbSave_GetPartyCount(i);
    }
}

void TransferPak_InitMenuGraphics(void) {
    s32 i;
    MemoryBlock* temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    DisplayObject* var_s1;

    D_82D09FF0 = process_geo_layout(temp_v0, &D_82D06FA4);
    D_82D0ABAC = process_geo_layout(temp_v0, &D_82D07710);
    D_82D0ABB0 = process_geo_layout(temp_v0, &D_82D08648);
    D_82D0ABB4 = process_geo_layout(temp_v0, &D_82D08838);
    D_82D0AC00 = process_geo_layout(temp_v0, &D_82D09108);
#if !defined(VERSION_JP)
    D_82D0AC0C = process_geo_layout(temp_v0, &D_82D09598);
#endif
    D_82D0AC04 = process_geo_layout(temp_v0, &D_82D09B38);
    D_82D0AC08 = process_geo_layout(temp_v0, &D_82D09EB8);

    MainPool_FinalizeAllocation(temp_v0);
    ModelRenderer_InitDisplayRoots();

    for (i = 0, var_s1 = &D_82D09FF8[0]; i < 8; var_s1++, i++) {
        ModelRenderer_AttachDisplayObject(var_s1);
        D_82D09FF8[i].node.callbackArg = i;
    }

    Pak_PollPortStatus();

#if !defined(VERSION_JP)
    if (Controller_CheckAccessoryEeprom() != 0) {
        D_82D0ABA0 = 1;
    } else {
        D_82D0ABA0 = 0;
    }
#endif
}

#if defined(VERSION_JP)
s32 TransferPak_CheckMain(s32 arg0, s32 arg1) {
    StageContext* sp54;
    u8 sp53;
    s16 sp50 = 2;
    s32 sp4C = 1;

    main_pool_push_state('GBCK');

    Save_EnsureBankLoaded(2);
    Save_GetModeSettings(&D_82D0AB90, 0);
    Save_GetOptionsField02(&D_82D0AB98);
    sp53 = (D_82D0AB98 & 4) != 0;
    gSessionContext.inRound2 = sp53;
    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp54 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    Font_Init(0x1C, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);
    ASSET_LOAD(D_3000000, menu_select_ui, 0);

    TransferPak_InitMenuGraphics();
    Audio_PlayMusicIfChanged(0x28);
    StageContext_Activate(sp54);

    if (arg1 != 0) {
        sp4C = TransferPak_ShowRulesPrompt();
        if (sp4C != 0) {
            sp50 = TransferPak_MainMenu();
            if (sp50 != 4) {
                sp4C = 0;
            }
        }
    }

    if (sp4C != 0) {
        sp50 = Pak_CheckPiIntegrity(TransferPak_MenuLoop());
    }

    StageContext_Deactivate();

    if (gSessionContext.inRound2 != sp53) {
        if (gSessionContext.inRound2 == 0) {
            D_82D0AB98 &= ~4;
        } else {
            D_82D0AB98 |= 4;
        }
        Save_SetOptionsField02(&D_82D0AB98);
        Save_CommitTypedRecord(0x14, 0);
    }

    Save_FlushBank(2);
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('GBCK');

    return sp50;
}
#else
s32 TransferPak_CheckMain(s32 arg0, s32 arg1) {
    StageContext* sp54;
    u8 sp53;
    s16 sp50 = 2;
    s32 sp4C = 1;
    s16 temp_v0_3;
    SessionContinueData sp28;

    main_pool_push_state('GBCK');

    Save_EnsureBankLoaded(2);
    Save_GetModeSettings(&D_82D0AB90, 0);
    Save_GetOptionsField02(&D_82D0AB98);
    sp53 = (D_82D0AB98 & 4) != 0;
    gSessionContext.inRound2 = sp53;
    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp54 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    Font_Init(0x1C, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);
    ASSET_LOAD(D_3000000, menu_select_ui, 0);

    TransferPak_InitMenuGraphics();
    Text_InitStringTables();
    D_82D0AB9C = Text_GetStringTable(0xE);
    Audio_PlayMusicIfChanged(0x28);
    StageContext_Activate(sp54);

    if (arg1 != 0) {
        sp4C = TransferPak_ShowRulesPrompt();
    }

    if (sp4C != 0) {
        if (Session_LoadContinueRecord(&sp28, NULL) == -1) {
            D_82D0ABA8 = 0;
        } else {
            D_82D0ABA8 = 1;
        }
        sp50 = Pak_CheckPiIntegrity(TransferPak_MenuLoop());
        if ((sp50 == 0x10) && (D_82D0ABA8 != 0)) {
            temp_v0_3 = TransferPak_MainMenu(&sp28);
            if (temp_v0_3 != 4) {
                sp50 = temp_v0_3;
            }
        }
    }

    StageContext_Deactivate();

    if (gSessionContext.inRound2 != sp53) {
        if (gSessionContext.inRound2 == 0) {
            D_82D0AB98 &= ~4;
        } else {
            D_82D0AB98 |= 4;
        }
        Save_SetOptionsField02(&D_82D0AB98);
        Save_CommitTypedRecord(0x14, 0);
    }

    Save_FlushBank(2);
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('GBCK');

    return sp50;
}
#endif
