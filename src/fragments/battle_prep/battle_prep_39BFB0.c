#include "battle_prep.h"
#include "src/geo_render.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/ui_graphics.h"
#include "src/audio_commands_category2.h"
#include "src/gfx_rect.h"
#include "src/matrix.h"
#include "src/math_util.h"
#include "src/memmap.h"
#include "src/memory.h"

static s8 D_84B14C10[] = {
    0xFF, 0x00, 0x01, 0x02, 0x06, 0x07, 0x08, 0xFF, 0xFF, 0x03, 0x04, 0x05, 0x09, 0x0A, 0x0B, 0xFF,
};
static Vtx D_84B14C20[] = {
    VTX(-32, 48, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, 16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, 48, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, -48, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -48, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, -16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B14CE0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, SHADE, 0, 0, 0, COMBINED, COMBINED, 0, PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B14C20, 12, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F001000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureBlock(0x0F002000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B14DC8[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_84B14C20, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, BattlePrepTeamIcons_DrawActiveTeamBadge, D_84B14CE0, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84B14E00[] = {
    VTX(-32, 48, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, 16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, 48, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, -48, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -48, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, -16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B14EC0[] = {
    VTX(-30, 45, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-30, 30, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 30, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, 45, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 45, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(0, 30, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(30, 30, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(30, 45, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B14F40[] = {
    VTX(-30, 30, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-30, 15, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 15, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, 30, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 30, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(0, 15, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(30, 15, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(30, 30, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B14FC0[] = {
    VTX(-30, 15, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-30, 0, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 0, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, 15, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 15, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(0, 0, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(30, 0, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(30, 15, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B15040[] = {
    VTX(-30, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),        VTX(-30, -15, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -15, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, 0, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 0, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(0, -15, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(30, -15, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(30, 0, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B150C0[] = {
    VTX(-30, -15, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-30, -30, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -30, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, -15, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -15, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(0, -30, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(30, -30, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(30, -15, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B15140[] = {
    VTX(-30, -30, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-30, -45, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -45, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, -30, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -30, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(0, -45, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(30, -45, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(30, -30, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B151C0[] = {
    VTX(-30, 30, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-30, -30, 0, 0, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(30, -30, 0, 2048, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(30, 30, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B15200[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, COMBINED, COMBINED, 0, PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B14E00, 12, 0),
    gsDPLoadTextureBlock(0x0E000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0E001000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureBlock(0x0E002000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPVertex(D_84B14EC0, 8, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 64, 0, 127, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPVertex(D_84B14F40, 8, 0),
    gsDPLoadTextureTile(0x0F002000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F002000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 64, 0, 127, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPVertex(D_84B14FC0, 8, 0),
    gsDPLoadTextureTile(0x0F004000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F004000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 64, 0, 127, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPVertex(D_84B15040, 8, 0),
    gsDPLoadTextureTile(0x0F006000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F006000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 64, 0, 127, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPVertex(D_84B150C0, 8, 0),
    gsDPLoadTextureTile(0x0F008000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F008000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 64, 0, 127, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPVertex(D_84B15140, 8, 0),
    gsDPLoadTextureTile(0x0F00A000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F00A000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 64, 0, 127, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};
static Gfx D_84B15618[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, COMBINED, 0,
                       PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B151C0, 4, 0),
    gsDPSetEnvColor(255, 50, 20, 160),
    gsDPLoadTextureBlock_4b(D_3017F00, G_IM_FMT_I, 64, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B15688[] = {
    0x17000000, 0x00000000,    0x00000000, 0x00000000, D_84B14E00, 0x05000000, 0x22050000, 0x00000000,
    0x08000000, BattlePrepTeamIcons_DrawIconSingle, D_84B15200, 0x22050000, D_84B15618, 0x25000000, 0x06000000, 0x01000000,
};
static Vtx D_84B156C8[] = {
    VTX(-32, 48, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, 16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, 48, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, -48, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -48, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, -16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-20, 30, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-20, -10, 0, 0, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(20, -10, 0, 1280, 1280, 0xFF, 0xFF, 0xFF, 0xFF), VTX(20, 30, 0, 1280, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-24, -20, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-24, -44, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, -44, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(24, -20, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B15808[] = {
    VTX(-20, 30, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-20, -10, 0, 0, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(20, -10, 0, 2048, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(20, 30, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B15848[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, COMBINED, COMBINED, 0, PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B156C8, 20, 0),
    gsDPLoadTextureBlock(0x0E000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0E001000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureBlock(0x0E002000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 40, 40, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsDPLoadTextureBlock(D_3016F00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSPEndDisplayList(),
};
static Gfx D_84B159B0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, COMBINED, 0,
                       PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B15808, 4, 0),
    gsDPSetEnvColor(255, 50, 20, 160),
    gsDPLoadTextureBlock_4b(D_3017F00, G_IM_FMT_I, 64, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B15A20[] = {
    0x17000000, 0x00000000,    0x00000000, 0x00000000, D_84B156C8, 0x05000000, 0x22050000, 0x00000000,
    0x08000000, BattlePrepTeamIcons_DrawIconDouble, D_84B15848, 0x22050000, D_84B159B0, 0x25000000, 0x06000000, 0x01000000,
};
static Vtx D_84B15A60[] = {
    VTX(-32, 24, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 0, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 0, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(32, 24, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, -24, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -24, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 0, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B15AE0[] = {
    VTX(-30, 22, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-30, 7, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 7, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, 22, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 22, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(0, 7, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(30, 7, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(30, 22, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B15B60[] = {
    VTX(-30, 7, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-30, -7, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -7, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, 7, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 7, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(0, -7, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(30, -7, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(30, 7, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B15BE0[] = {
    VTX(-30, -7, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-30, -22, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -22, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, -7, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -7, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(0, -22, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(30, -22, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(30, -7, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B15C60[] = {
    VTX(-22, 22, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-22, -22, 0, 0, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(22, -22, 0, 2048, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(22, 22, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B15CA0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, COMBINED, COMBINED, 0, PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B15A60, 8, 0),
    gsDPLoadTextureBlock(0x0E000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0E000C00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPVertex(D_84B15AE0, 8, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 64, 0, 127, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPVertex(D_84B15B60, 8, 0),
    gsDPLoadTextureTile(0x0F002000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F002000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 64, 0, 127, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPVertex(D_84B15BE0, 8, 0),
    gsDPLoadTextureTile(0x0F004000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F004000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 64, 0, 127, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};
static Gfx D_84B15EE0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, COMBINED, 0,
                       PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B15C60, 4, 0),
    gsDPSetEnvColor(255, 50, 20, 160),
    gsDPLoadTextureBlock_4b(D_3017F00, G_IM_FMT_I, 64, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B15F50[] = {
    0x17000000, 0x00000000, 0x00000000, 0x00000000, D_84B15A60, 0x05000000, 0x1B000000,    0x00000000,
    0x00000000, 0x00180000, 0x05000000, 0x22050000, 0x00000000, 0x08000000, BattlePrepTeamIcons_DrawBadgeIconSingle, D_84B15CA0,
    0x22050000, D_84B15EE0, 0x25000000, 0x06000000, 0x06000000, 0x01000000,
};
static u32 D_84B15FA8[] = {
    0x17000000, 0x00000000, 0x00000000, 0x00000000, D_84B15A60, 0x05000000, 0x1B000000,    0x00000000,
    0x00000000, 0xFFE80000, 0x05000000, 0x22050000, 0x00000000, 0x08000000, BattlePrepTeamIcons_DrawBadgeIconSingle, D_84B15CA0,
    0x22050000, D_84B15EE0, 0x25000000, 0x06000000, 0x06000000, 0x01000000,
};
static Vtx D_84B16000[] = {
    VTX(-32, 24, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, 0, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 0, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(32, 24, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),        VTX(-32, -24, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -24, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, 0, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-14, 20, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-14, -8, 0, 0, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(14, -8, 0, 1280, 1280, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(14, 20, 0, 1280, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-12, -8, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-12, -20, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(12, -20, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(12, -8, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B16100[] = {
    VTX(-14, 20, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-14, -8, 0, 0, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(14, -8, 0, 2048, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(14, 20, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B16140[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, COMBINED, COMBINED, 0, PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B16000, 16, 0),
    gsDPLoadTextureBlock(0x0E000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0E000C00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 40, 40, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsDPLoadTextureBlock(D_3016F00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};
static Gfx D_84B16268[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, COMBINED, 0,
                       PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B16100, 4, 0),
    gsDPSetEnvColor(255, 50, 20, 160),
    gsDPLoadTextureBlock_4b(D_3017F00, G_IM_FMT_I, 64, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B162D8[] = {
    0x17000000, 0x00000000, 0x00000000, 0x00000000, D_84B16000, 0x05000000, 0x1B000000,    0x00000000,
    0x00000000, 0x00180000, 0x05000000, 0x22050000, 0x00000000, 0x08000000, BattlePrepTeamIcons_DrawBadgeIconDouble, D_84B16140,
    0x22050000, D_84B16268, 0x25000000, 0x06000000, 0x06000000, 0x01000000,
};
static u32 D_84B16330[] = {
    0x17000000, 0x00000000, 0x00000000, 0x00000000, D_84B16000, 0x05000000, 0x1B000000,    0x00000000,
    0x00000000, 0xFFE80000, 0x05000000, 0x22050000, 0x00000000, 0x08000000, BattlePrepTeamIcons_DrawBadgeIconDouble, D_84B16140,
    0x22050000, D_84B16268, 0x25000000, 0x06000000, 0x06000000, 0x01000000, 0x00000000,    0x00000000,
};

s32 BattlePrepTeamIcons_DrawActiveTeamBadge(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25A58* temp_v1;
    u8* var_a3;

    if (arg0 == 5) {
        temp_v1 = (unk_D_84B25A58*)D_8006F09C->node.callbackArg;
        if (temp_v1->unk_04->effectSlot == D_8006F09C->effectSlot) {
            var_a3 = temp_v1->unk_24->img_p;
        } else {
            var_a3 = temp_v1->unk_28->img_p;
        }

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)var_a3 & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->display_node_header.callbackArg);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

s32 BattlePrepTeamIcons_DrawIconSingle(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25A58* temp_t1;
    s32 temp_t2;
    u8* var_a3;

    if (arg0 == 5) {
        temp_t1 = (unk_D_84B25A58*)D_8006F09C->node.callbackArg;
        temp_t2 = D_8006F09C->effectSlot - temp_t1->unk_04->effectSlot;
        if (temp_t2 < 4) {
            var_a3 = D_3006000;
        } else {
            var_a3 = D_3009000;
        }

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)PokeIcon_GetImage(temp_t1->unk_1C, temp_t2 - 1) & 0x1FFFFFFF);
        gSPSegment(gDisplayListHead++, 0x0E, (u32)Memmap_GetSegmentVaddr(var_a3) & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->display_node_header.callbackArg);

        GeoRender_ApplyMaterialState();

        if (temp_t1->unk_2C[temp_t2 - 1] != 0) {
            arg1->display_node_header.nextSibling->flags |= 1;
        } else {
            arg1->display_node_header.nextSibling->flags &= ~1;
        }
    }
    return 0;
}

s32 BattlePrepTeamIcons_DrawIconDouble(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25A58* temp_a3;
    s32 temp_t0;
    u8* var_a0;

    if (arg0 == 5) {
        temp_a3 = (unk_D_84B25A58*)D_8006F09C->node.callbackArg;
        temp_t0 = (D_8006F09C->effectSlot - temp_a3->unk_04->effectSlot) % 8;
        if (temp_t0 < 4) {
            var_a0 = D_3006000;
        } else {
            var_a0 = D_3009000;
        }

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)temp_a3->unk_20[temp_t0 - 1] & 0x1FFFFFFF);
        gSPSegment(gDisplayListHead++, 0x0E, (u32)Memmap_GetSegmentVaddr(var_a0) & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->display_node_header.callbackArg);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

s32 BattlePrepTeamIcons_DrawBadgeIconSingle(s32 arg0, unk_func_80011B94* arg1) {
    u8* var_a3;
    unk_D_84B25A58* temp_t1;
    s32 temp_a1;

    if (arg0 == 5) {
        temp_t1 = (unk_D_84B25A58*)D_8006F09C->node.callbackArg;
        temp_a1 = D_8006F09C->effectSlot - temp_t1->unk_04->effectSlot;

        if (temp_a1 >= 0x10) {
            temp_a1 = (temp_a1 - 0x10) % 12;
        } else {
            temp_a1 = D_84B14C10[temp_a1];
        }

        if (temp_a1 < 6) {
            var_a3 = D_300C000;
        } else {
            var_a3 = D_300D800;
        }

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)PokeIcon_GetImage(temp_t1->unk_1C, temp_a1) & 0x1FFFFFFF);
        gSPSegment(gDisplayListHead++, 0x0E, (u32)Memmap_GetSegmentVaddr(var_a3) & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->display_node_header.callbackArg);

        GeoRender_ApplyMaterialState();

        if (temp_t1->unk_2C[temp_a1] != 0) {
            arg1->display_node_header.nextSibling->flags |= 1;
        } else {
            arg1->display_node_header.nextSibling->flags &= ~1;
        }
    }
    return 0;
}

s32 BattlePrepTeamIcons_DrawBadgeIconDouble(s32 arg0, unk_func_80011B94* arg1) {
    s32 temp_a3;
    unk_D_84B25A58* temp_t1;
    u8* var_a0;

    if (arg0 == 5) {
        temp_t1 = (unk_D_84B25A58*)D_8006F09C->node.callbackArg;
        temp_a3 = D_8006F09C->effectSlot - temp_t1->unk_04->effectSlot;

        if (temp_a3 >= 0x10) {
            temp_a3 = (temp_a3 - 0x10) % 12;
        } else {
            temp_a3 = D_84B14C10[temp_a3];
        }

        if (temp_a3 < 6) {
            var_a0 = D_300C000;
        } else {
            var_a0 = D_300D800;
        }

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)temp_t1->unk_20[temp_a3] & 0x1FFFFFFF);
        gSPSegment(gDisplayListHead++, 0x0E, (u32)Memmap_GetSegmentVaddr(var_a0) & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->display_node_header.callbackArg);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

void BattlePrepTeamIcons_DrawHpBarsSingle(unk_D_84B25A58* arg0, s32 arg1) {
    s32 i;
    s32 j;
    UNUSED s32 pad;
    TeamRoster* temp_s5;
    s32 temp_lo;
    s32 var_s0;

    for (i = 0; i < 2; i++) {
        temp_s5 = D_800AE540.unk_1194[i].unk_08[0];

        for (j = 0; j < temp_s5->unk_002; j++) {
            temp_lo = temp_s5->unk_01C[j].unk_26 * arg1;
            var_s0 = temp_s5->unk_01C[j].unk_02 * 0x64;
            if (var_s0 < temp_lo) {
                var_s0 = temp_lo;
            }
            GfxImage_SetRenderTarget(&gDisplayListHead, arg0->unk_1C->unk_08[i * 3 + j].unk_0C);
            BattleHud_DrawHpBarTexture(4, 0xB4, 0x78, var_s0, temp_s5->unk_01C[j].unk_26 * 0x64);
        }
    }
}

void BattlePrepTeamIcons_DrawHpBarsDouble(unk_D_84B25A58* arg0, s32 arg1) {
    s32 i;
    s32 j;
    s32 x;
    s32 temp_lo;
    s32 var_s0;
    TeamRoster* temp_s5;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            temp_s5 = D_800AE540.unk_1194[i].unk_08[j];

            if (temp_s5 != NULL) {
                for (x = 0; x < temp_s5->unk_002; x++) {
                    temp_lo = temp_s5->unk_01C[x].unk_26 * arg1;
                    var_s0 = temp_s5->unk_01C[x].unk_02 * 0x64;
                    if (var_s0 < temp_lo) {
                        var_s0 = temp_lo;
                    }
                    GfxImage_SetRenderTarget(&gDisplayListHead, arg0->unk_1C->unk_08[(i * 6) + (j * 3) + x].unk_0C);
                    BattleHud_DrawHpBarTexture(4, 0x54, 0x78, var_s0, temp_s5->unk_01C[x].unk_26 * 0x64);
                }
            }
        }
    }
}

void BattlePrepTeamIcons_MarkFaintedSingle(unk_D_84B25A58* arg0, s32 arg1) {
    UNUSED s32 pad;
    TeamRoster* temp_s5;
    s32 temp_v0;
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        temp_s5 = D_800AE540.unk_1194[i].unk_08[0];

        for (j = 0; j < temp_s5->unk_002; j++) {
            if (arg1 == temp_s5->unk_01C[j].unk_25) {
                temp_v0 = (i * 3) + j;
                arg0->unk_2C[temp_v0] = 1;
                Audio_PlayCategory11SoundCommand(0x0110000B, temp_v0 + 1, 0);
            }
        }
    }
}

void BattlePrepTeamIcons_MarkFaintedDouble(unk_D_84B25A58* arg0, s32 arg1) {
    s32 i;
    s32 j;
    s32 x;
    TeamRoster* temp_s5;
    s32 temp_v0;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            temp_s5 = D_800AE540.unk_1194[i].unk_08[j];

            if (temp_s5 != NULL) {
                for (x = 0; x < temp_s5->unk_002; x++) {
                    if (arg1 == temp_s5->unk_01C[x].unk_25) {
                        temp_v0 = (i * 6) + (j * 3) + x;
                        arg0->unk_2C[temp_v0] = 1;
                        Audio_PlayCategory11SoundCommand(0x0110000B, temp_v0 + 1, 1);
                    }
                }
            }
        }
    }
}

void BattlePrepTeamIcons_InitDisplayObjectsSingleVisible(unk_D_84B25A58* arg0) {
    s32 i;

    for (i = 1; i < 7; i++) {
        Model_InitDisplayObject(&arg0->unk_04[i], 0, 0, arg0->unk_08);
        arg0->unk_04[i].node.callbackArg = arg0;
    }

    for (i = 1; i < 4; i++) {
        arg0->unk_04[i].rotation.y = 0x5800;
        Vec3f_SetComponentsDuplicate(&arg0->unk_04[i].position, (i * 64.0f) - 96.0f, 48.0f, -289.0f);
    }

    for (i = 0; i < 3; i++) {
        arg0->unk_04[4 + i].rotation.y = -0x5800;
        Vec3f_SetComponentsDuplicate(&arg0->unk_04[4 + i].position, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
    }
}

void BattlePrepTeamIcons_InitDisplayObjectsSingleHidden(unk_D_84B25A58* arg0) {
    s32 i;

    for (i = 1; i < 7; i++) {
        Model_InitDisplayObject(&arg0->unk_04[8 + i], 0, 0, arg0->unk_10);
        arg0->unk_04[8 + i].node.callbackArg = arg0;
        arg0->unk_04[8 + i].rotation.y = -0x8000;
    }

    for (i = 1; i < 4; i++) {
        Vec3f_SetComponentsDuplicate(&arg0->unk_04[8 + i].position, (i * 64.0f) - 96.0f, 48.0f, -289.0f);
    }

    for (i = 0; i < 3; i++) {
        Vec3f_SetComponentsDuplicate(&arg0->unk_04[12 + i].position, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
    }
}

void BattlePrepTeamIcons_InitDisplayObjectsDoubleVisible(unk_D_84B25A58* arg0) {
    s32 i;

    for (i = 1; i < 4; i++) {
        Model_InitDisplayObject(&arg0->unk_04[15 + i], 0, 0, arg0->unk_08);
        Model_InitDisplayObject(&arg0->unk_04[18 + i], 0, 0, arg0->unk_0C);
        arg0->unk_04[15 + i].node.callbackArg = arg0;
        arg0->unk_04[18 + i].node.callbackArg = arg0;

        arg0->unk_04[15 + i].rotation.y = 0x5800;
        arg0->unk_04[18 + i].rotation.y = 0x5800;

        Vec3f_SetComponentsDuplicate(&arg0->unk_04[15 + i].position, (i * 64.0f) - 96.0f, 48.0f, -289.0f);
        Vec3f_SetComponentsDuplicate(&arg0->unk_04[18 + i].position, (i * 64.0f) - 96.0f, 48.0f, -289.0f);
    }

    for (i = 0; i < 3; i++) {
        Model_InitDisplayObject(&arg0->unk_04[22 + i], 0, 0, arg0->unk_08);
        Model_InitDisplayObject(&arg0->unk_04[25 + i], 0, 0, arg0->unk_0C);
        arg0->unk_04[22 + i].node.callbackArg = arg0;
        arg0->unk_04[25 + i].node.callbackArg = arg0;

        arg0->unk_04[22 + i].rotation.y = -0x5800;
        arg0->unk_04[25 + i].rotation.y = -0x5800;

        Vec3f_SetComponentsDuplicate(&arg0->unk_04[22 + i].position, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
        Vec3f_SetComponentsDuplicate(&arg0->unk_04[25 + i].position, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
    }
}

void BattlePrepTeamIcons_InitDisplayObjectsDoubleHidden(unk_D_84B25A58* arg0) {
    s32 i;

    for (i = 1; i < 4; i++) {
        Model_InitDisplayObject(&arg0->unk_04[27 + i], 0, 0, arg0->unk_10);
        Model_InitDisplayObject(&arg0->unk_04[30 + i], 0, 0, arg0->unk_14);

        arg0->unk_04[27 + i].node.callbackArg = arg0;
        arg0->unk_04[30 + i].node.callbackArg = arg0;

        arg0->unk_04[27 + i].rotation.y = -0x8000;
        arg0->unk_04[30 + i].rotation.y = -0x8000;

        Vec3f_SetComponentsDuplicate(&arg0->unk_04[27 + i].position, (i * 64.0f) - 96.0f, 48.0f, -289.0f);
        Vec3f_SetComponentsDuplicate(&arg0->unk_04[30 + i].position, (i * 64.0f) - 96.0f, 48.0f, -289.0f);
    }

    for (i = 0; i < 3; i++) {
        Model_InitDisplayObject(&arg0->unk_04[34 + i], 0, 0, arg0->unk_10);
        Model_InitDisplayObject(&arg0->unk_04[37 + i], 0, 0, arg0->unk_14);
        arg0->unk_04[34 + i].node.callbackArg = arg0;
        arg0->unk_04[37 + i].node.callbackArg = arg0;

        arg0->unk_04[34 + i].rotation.y = -0x8000;
        arg0->unk_04[37 + i].rotation.y = -0x8000;

        Vec3f_SetComponentsDuplicate(&arg0->unk_04[34 + i].position, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
        Vec3f_SetComponentsDuplicate(&arg0->unk_04[37 + i].position, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
    }
}

void BattlePrepTeamIcons_RevealStepSingle(unk_D_84B25A58* arg0, s16 arg1) {
    s16 i;

    if (arg1 == 0) {
        Audio_PlayCategory11SoundCommand(0x01100009, 0, 0);
    }

    if (arg1 < 0xB) {
        for (i = 0; i < 4; i++) {
            arg0->unk_04[i].rotation.y -= 0x800;
        }

        for (i = 4; i < 8; i++) {
            arg0->unk_04[i].rotation.y += 0x800;
        }

        BattlePrepTeamIcons_DrawHpBarsSingle(arg0, 0x64);
    }
}

void BattlePrepTeamIcons_RevealStepDouble(unk_D_84B25A58* arg0, s16 arg1) {
    s16 i;

    if (arg1 == 0) {
        Audio_PlayCategory11SoundCommand(0x01100009, 0, 0);
    }

    if (arg1 < 0xB) {
        arg0->unk_04[0].rotation.y -= 0x800;
        arg0->unk_04[7].rotation.y += 0x800;

        for (i = 16; i < 22; i++) {
            arg0->unk_04[i].rotation.y -= 0x800;
        }

        for (i = 22; i < 28; i++) {
            arg0->unk_04[i].rotation.y += 0x800;
        }

        BattlePrepTeamIcons_DrawHpBarsDouble(arg0, 0x64);
    }
}

void BattlePrepTeamIcons_HpDrainStepSingleNTSC(unk_D_84B25A58* arg0, s16 arg1) {
    if (arg1 == 0) {
        Audio_PlayCategory11SoundCommand(0x0110000A, 0, 0);
    }

    if (arg1 < 0x1A) {
        BattlePrepTeamIcons_DrawHpBarsSingle(arg0, 0x64 - (arg1 * 4));
    } else if (arg1 < 0x3E) {
        if (((arg1 - 0x1A) % 6) == 0) {
            BattlePrepTeamIcons_MarkFaintedSingle(arg0, ((arg1 - 0x1A) / 6) + 1);
        }
    }
}

void BattlePrepTeamIcons_HpDrainStepDoubleNTSC(unk_D_84B25A58* arg0, s16 arg1) {
    if (arg1 == 0) {
        Audio_PlayCategory11SoundCommand(0x0110000A, 0, 0);
    }

    if (arg1 < 0x1A) {
        BattlePrepTeamIcons_DrawHpBarsDouble(arg0, 0x64 - (arg1 * 4));
    } else if (arg1 < 0x3E) {
        if (((arg1 - 0x1A) % 3) == 0) {
            BattlePrepTeamIcons_MarkFaintedDouble(arg0, ((arg1 - 0x1A) / 3) + 1);
        }
    }
}

void BattlePrepTeamIcons_HpDrainStepSinglePAL(unk_D_84B25A58* arg0, s16 arg1) {
    if (arg1 == 0) {
        Audio_PlayCategory11SoundCommand(0x0110000A, 0, 0);
    }

    if (arg1 < 0x15) {
        BattlePrepTeamIcons_DrawHpBarsSingle(arg0, 0x64 - (arg1 * 5));
    } else if (arg1 < 0x33) {
        if (((arg1 - 0x15) % 5) == 0) {
            BattlePrepTeamIcons_MarkFaintedSingle(arg0, ((arg1 - 0x15) / 5) + 1);
        }
    }
}

void BattlePrepTeamIcons_HpDrainStepDoublePAL(unk_D_84B25A58* arg0, s16 arg1) {
    if (arg1 == 0) {
        Audio_PlayCategory11SoundCommand(0x0110000A, 0, 0);
    }

    if (arg1 < 0x15) {
        BattlePrepTeamIcons_DrawHpBarsDouble(arg0, 0x64 - (arg1 * 5));
    } else if (arg1 < 0x39) {
        if (((arg1 - 0x15) % 3) == 0) {
            BattlePrepTeamIcons_MarkFaintedDouble(arg0, ((arg1 - 0x15) / 3) + 1);
        }
    }
}

void BattlePrepTeamIcons_FinalRevealSingle(unk_D_84B25A58* arg0, s16 arg1) {
    s32 i;
    BattleMon* temp_s5 = D_800AE540.unk_1194[0].unk_08[0]->unk_01C;
    BattleMon* temp_s6 = D_800AE540.unk_1194[1].unk_08[0]->unk_01C;

    if (arg1 == 0) {
        BattlePrepTeamIcons_InitDisplayObjectsSingleHidden(arg0);
    }

    if (arg1 < 0x10) {
        for (i = 0; i < D_800AE540.unk_1194[0].unk_08[0]->unk_002; i++) {
            if (temp_s5[i].unk_25 != 0) {
                arg0->unk_04[1 + i].rotation.y += 0x800;
                arg0->unk_04[9 + i].rotation.y += 0x800;
            }
        }

        for (i = 0; i < D_800AE540.unk_1194[1].unk_08[0]->unk_002; i++) {
            if (temp_s6[i].unk_25 != 0) {
                arg0->unk_04[4 + i].rotation.y -= 0x800;
                arg0->unk_04[12 + i].rotation.y -= 0x800;
            }
        }
    }

    if (arg1 == 0x10) {
        for (i = 1; i < 7; i++) {
            ModelRenderer_ClearDisplayObject(&arg0->unk_04[i]);
            BattlePrep_ResetDisplayObject(&arg0->unk_04[8 + i]);
            arg0->unk_04[i].rotation.y = 0;
        }

        for (i = 0; i < 3; i++) {
            if ((i >= D_800AE540.unk_1194[0].unk_08[0]->unk_002) || (temp_s5[i].unk_25 == 0)) {
                Model_InitDisplayObject(&arg0->unk_04[1 + i], 0, 0, arg0->unk_08);
            } else {
                Model_InitDisplayObject(&arg0->unk_04[1 + i], 0, 0, arg0->unk_10);
            }
        }

        for (i = 0; i < 3; i++) {
            if ((i >= D_800AE540.unk_1194[1].unk_08[0]->unk_002) || (temp_s6[i].unk_25 == 0)) {
                Model_InitDisplayObject(&arg0->unk_04[4 + i], 0, 0, arg0->unk_08);
            } else {
                Model_InitDisplayObject(&arg0->unk_04[4 + i], 0, 0, arg0->unk_10);
            }
        }
    }
}

void BattlePrepTeamIcons_FinalRevealDouble(unk_D_84B25A58* arg0, s16 arg1) {
    s32 i;
    BattleMon* temp_s0 = &D_800AE540.unk_1194[0].unk_08[0]->unk_01C[0];
    BattleMon* var_a3 = NULL;
    BattleMon* temp_t1 = &D_800AE540.unk_1194[1].unk_08[0]->unk_01C[0];
    BattleMon* var_t0 = NULL;

    if (D_800AE540.unk_1194[0].unk_01 == 2) {
        var_a3 = &D_800AE540.unk_1194[0].unk_08[1]->unk_01C[0];
    }

    if (D_800AE540.unk_1194[1].unk_01 == 2) {
        var_t0 = &D_800AE540.unk_1194[1].unk_08[1]->unk_01C[0];
    }

    if (arg1 == 0) {
        BattlePrepTeamIcons_InitDisplayObjectsDoubleHidden(arg0);
    }

    if (arg1 < 0x10) {
        for (i = 0; i < D_800AE540.unk_1194[0].unk_08[0]->unk_002; i++) {
            if (temp_s0[i].unk_25 != 0) {
                arg0->unk_04[16 + i].rotation.y += 0x800;
                arg0->unk_04[28 + i].rotation.y += 0x800;
            }
        }

        for (i = 0; i < D_800AE540.unk_1194[1].unk_08[0]->unk_002; i++) {
            if (temp_t1[i].unk_25 != 0) {
                arg0->unk_04[22 + i].rotation.y -= 0x800;
                arg0->unk_04[34 + i].rotation.y -= 0x800;
            }
        }

        if (var_a3 != NULL) {
            for (i = 0; i < D_800AE540.unk_1194[0].unk_08[1]->unk_002; i++) {
                if (var_a3[i].unk_25 != 0) {
                    arg0->unk_04[19 + i].rotation.y += 0x800;
                    arg0->unk_04[31 + i].rotation.y += 0x800;
                }
            }
        }

        if (var_t0 != NULL) {
            for (i = 0; i < D_800AE540.unk_1194[1].unk_08[1]->unk_002; i++) {
                if (var_t0[i].unk_25 != 0) {
                    arg0->unk_04[25 + i].rotation.y -= 0x800;
                    arg0->unk_04[37 + i].rotation.y -= 0x800;
                }
            }
        }
    }

    if (arg1 == 0x10) {
        for (i = 0; i < 3; i++) {
            if (arg0->unk_04[16 + i].rotation.y == 0) {
                Model_InitDisplayObject(&arg0->unk_04[1 + i], 0, 0, arg0->unk_08);
            } else {
                Model_InitDisplayObject(&arg0->unk_04[1 + i], 0, 0, arg0->unk_10);
            }
            arg0->unk_04[1 + i].node.callbackArg = arg0;
            Vec3f_SetComponentsDuplicate(&arg0->unk_04[1 + i].position, (i * 64.0f) - 32.0f, 48.0f, -289.0f);
        }

        for (i = 0; i < 3; i++) {
            if (arg0->unk_04[19 + i].rotation.y == 0) {
                Model_InitDisplayObject(&arg0->unk_04[9 + i], 0, 0, arg0->unk_0C);
            } else {
                Model_InitDisplayObject(&arg0->unk_04[9 + i], 0, 0, arg0->unk_14);
            }
            arg0->unk_04[9 + i].node.callbackArg = arg0;
            Vec3f_SetComponentsDuplicate(&arg0->unk_04[9 + i].position, (i * 64.0f) - 32.0f, 48.0f, -289.0f);
        }

        for (i = 0; i < 3; i++) {
            if (arg0->unk_04[22 + i].rotation.y == 0) {
                Model_InitDisplayObject(&arg0->unk_04[4 + i], 0, 0, arg0->unk_08);
            } else {
                Model_InitDisplayObject(&arg0->unk_04[4 + i], 0, 0, arg0->unk_10);
            }
            arg0->unk_04[4 + i].node.callbackArg = arg0;
            Vec3f_SetComponentsDuplicate(&arg0->unk_04[4 + i].position, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
        }

        for (i = 0; i < 3; i++) {
            if (arg0->unk_04[25 + i].rotation.y == 0) {
                Model_InitDisplayObject(&arg0->unk_04[12 + i], 0, 0, arg0->unk_0C);
            } else {
                Model_InitDisplayObject(&arg0->unk_04[12 + i], 0, 0, arg0->unk_14);
            }
            arg0->unk_04[12 + i].node.callbackArg = arg0;
            Vec3f_SetComponentsDuplicate(&arg0->unk_04[12 + i].position, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
        }

        for (i = 16; i < 40; i++) {
            BattlePrep_ResetDisplayObject(&arg0->unk_04[i]);
        }
    }
}

void BattlePrepTeamIcons_UpdateStep(unk_D_84B25A58* arg0) {
    if (osTvType == OS_TV_PAL) {
        if (arg0->unk_02 == 1) {
            if (arg0->unk_01 >= 0) {
                BattlePrepTeamIcons_RevealStepDouble(arg0, arg0->unk_01);
            }

            if (arg0->unk_01 >= 0xC) {
                BattlePrepTeamIcons_HpDrainStepDoublePAL(arg0, arg0->unk_01 - 0xC);
            }

            if (arg0->unk_01 >= 0x3E) {
                BattlePrepTeamIcons_FinalRevealDouble(arg0, arg0->unk_01 - 0x3E);
            }
        } else {
            if (arg0->unk_01 >= 0) {
                BattlePrepTeamIcons_RevealStepSingle(arg0, arg0->unk_01);
            }

            if (arg0->unk_01 >= 0xC) {
                BattlePrepTeamIcons_HpDrainStepSinglePAL(arg0, arg0->unk_01 - 0xC);
            }

            if (arg0->unk_01 >= 0x3E) {
                BattlePrepTeamIcons_FinalRevealSingle(arg0, arg0->unk_01 - 0x3E);
            }
        }

        arg0->unk_01++;
        if (arg0->unk_01 == 0x50) {
            arg0->unk_00 = 0;
        }
    } else {
        if (arg0->unk_02 == 1) {
            if (arg0->unk_01 >= 0) {
                BattlePrepTeamIcons_RevealStepDouble(arg0, arg0->unk_01);
            }

            if (arg0->unk_01 >= 0xC) {
                BattlePrepTeamIcons_HpDrainStepDoubleNTSC(arg0, arg0->unk_01 - 0xC);
            }

            if (arg0->unk_01 >= 0x4A) {
                BattlePrepTeamIcons_FinalRevealDouble(arg0, arg0->unk_01 - 0x4A);
            }
        } else {
            if (arg0->unk_01 >= 0) {
                BattlePrepTeamIcons_RevealStepSingle(arg0, arg0->unk_01);
            }

            if (arg0->unk_01 >= 0xC) {
                BattlePrepTeamIcons_HpDrainStepSingleNTSC(arg0, arg0->unk_01 - 0xC);
            }

            if (arg0->unk_01 >= 0x4A) {
                BattlePrepTeamIcons_FinalRevealSingle(arg0, arg0->unk_01 - 0x4A);
            }
        }

        arg0->unk_01++;
        if (arg0->unk_01 == 0x60) {
            arg0->unk_00 = 0;
        }
    }
}

void BattlePrepTeamIcons_UpdateLoadingStep(unk_D_84B25A58* arg0) {
    PokeIcon_ProcessNextSlot(arg0->unk_1C, 0);

    arg0->unk_01++;
    if ((arg0->unk_01 >= 0x1E) && (PokeIcon_AreSlotsIdle(arg0->unk_1C) != 0)) {
        arg0->unk_01 = 0;
        arg0->unk_00 = 2;
    }
}

void BattlePrepTeamIcons_Update(unk_D_84B25A58* arg0) {
    switch (arg0->unk_00) {
        case 1:
            BattlePrepTeamIcons_UpdateLoadingStep(arg0);
            break;

        case 3:
            BattlePrepTeamIcons_UpdateStep(arg0);
            break;
    }
}

void BattlePrepTeamIcons_LoadDexIdsSingle(unk_D_84B25A58* arg0) {
    s32 i;
    s32 count;
    ModelLoadContext* temp_s0;

    temp_s0 = PokeIcon_AllocFramebuffers(5);
    PokeIcon_AttachDepthBuffer(arg0->unk_1C, temp_s0, GfxImage_Allocate(0, 2, 0x80, 0xC0, 1));

    for (count = 0, i = 0; i < D_800AE540.unk_1194[0].unk_08[0]->unk_002; count++, i++) {
        func_8001A324(arg0->unk_1C, count, D_800AE540.unk_1194[0].unk_08[0]->unk_01C[i].unk_00.unk_00, 0);
    }

    for (count = 3, i = 0; i < D_800AE540.unk_1194[1].unk_08[0]->unk_002; count++, i++) {
        func_8001A324(arg0->unk_1C, count, D_800AE540.unk_1194[1].unk_08[0]->unk_01C[i].unk_00.unk_00, 0);
    }
}

void BattlePrepTeamIcons_LoadDexIdsDouble(unk_D_84B25A58* arg0) {
    s32 i;
    s32 count;
    ModelLoadContext* temp_s0;

    temp_s0 = PokeIcon_AllocFramebuffers(5);
    PokeIcon_AttachDepthBuffer(arg0->unk_1C, temp_s0, GfxImage_Allocate(0, 2, 0x80, 0x60, 1));

    for (count = 0, i = 0; i < D_800AE540.unk_1194[0].unk_08[0]->unk_002; count++, i++) {
        func_8001A324(arg0->unk_1C, count, D_800AE540.unk_1194[0].unk_08[0]->unk_01C[i].unk_00.unk_00, 0);
    }

    for (count = 6, i = 0; i < D_800AE540.unk_1194[1].unk_08[0]->unk_002; count++, i++) {
        func_8001A324(arg0->unk_1C, count, D_800AE540.unk_1194[1].unk_08[0]->unk_01C[i].unk_00.unk_00, 0);
    }

    if (D_800AE540.unk_1194[0].unk_08[1] != NULL) {
        for (count = 3, i = 0; i < D_800AE540.unk_1194[0].unk_08[1]->unk_002; count++, i++) {
            func_8001A324(arg0->unk_1C, count, D_800AE540.unk_1194[0].unk_08[1]->unk_01C[i].unk_00.unk_00, 0);
        }
    }

    if (D_800AE540.unk_1194[1].unk_08[1] != NULL) {
        for (count = 9, i = 0; i < D_800AE540.unk_1194[1].unk_08[1]->unk_002; count++, i++) {
            func_8001A324(arg0->unk_1C, count, D_800AE540.unk_1194[1].unk_08[1]->unk_01C[i].unk_00.unk_00, 0);
        }
    }
}

void BattlePrepTeamIcons_Load(unk_D_84B25A58* arg0, BinArchive* arg1) {
    u8* sp24 = BinArchive_GetFile(arg1, D_800AE540.unk_1194[0].unk_08[0]->unk_214->unk_003);
    u8* sp20 = BinArchive_GetFile(arg1, D_800AE540.unk_1194[1].unk_08[0]->unk_214->unk_003);

    PokeIcon_OpenModelArchives();

    FRAGMENT_LOAD(fragment31);

    if (arg0->unk_02 == 1) {
        BattlePrepTeamIcons_LoadDexIdsDouble(arg0);
    } else {
        BattlePrepTeamIcons_LoadDexIdsSingle(arg0);
    }

    BattlePrep_DrawTrainerStatusIcon(arg0->unk_24, 0, sp24, D_3000000);
    BattlePrep_DrawTrainerStatusIcon(arg0->unk_28, 1, sp20, D_3003000);
    arg0->unk_00 = 1;
}

s32 BattlePrepTeamIcons_InitDisplayObjects(unk_D_84B25A58* arg0, DisplayObject* arg1) {
    if (arg0->unk_00 == 2) {
        arg0->unk_00 = 3;
        arg0->unk_04 = arg1;
        arg0->unk_01 = 0;
        arg1->node.callbackArg = arg0;

        arg0->unk_04[7].node.callbackArg = arg0;
        arg0->unk_04[0].rotation.y = 0x5800;
        arg0->unk_04[7].rotation.y = -0x5800;

        Vec3f_SetComponentsDuplicate(&arg0->unk_04[0].position, -96.0f, 48.0f, -289.0f);
        Vec3f_SetComponentsDuplicate(&arg0->unk_04[7].position, 96.0f, -48.0f, -289.0f);
        Model_InitDisplayObject(&arg0->unk_04[0], 0, 0, arg0->unk_18);
        Model_InitDisplayObject(&arg0->unk_04[7], 0, 0, arg0->unk_18);

        if (arg0->unk_02 == 1) {
            BattlePrepTeamIcons_InitDisplayObjectsDoubleVisible(arg0);
        } else {
            BattlePrepTeamIcons_InitDisplayObjectsSingleVisible(arg0);
        }
    }
    return arg0->unk_00 == 3;
}

void BattlePrepTeamIcons_LoadIconTexturesSingle(unk_D_84B25A58* arg0) {
    s32 i;
    s32 count;

    for (i = 0, count = 0; i < D_800AE540.unk_1194[0].unk_08[0]->unk_002; count++, i++) {
        PokeIcon_LoadModelTextureForMon(arg0->unk_20[count], D_800AE540.unk_1194[0].unk_08[0]->unk_01C[i].unk_00.unk_00, NULL);
    }

    for (i = 0, count = 3; i < D_800AE540.unk_1194[1].unk_08[0]->unk_002; count++, i++) {
        PokeIcon_LoadModelTextureForMon(arg0->unk_20[count], D_800AE540.unk_1194[1].unk_08[0]->unk_01C[i].unk_00.unk_00, NULL);
    }
}

void BattlePrepTeamIcons_LoadIconTexturesDouble(unk_D_84B25A58* arg0) {
    s32 i;
    s32 count;

    for (i = 0, count = 0; i < D_800AE540.unk_1194[0].unk_08[0]->unk_002; count++, i++) {
        PokeIcon_LoadModelTextureForMon(&arg0->unk_20[count], D_800AE540.unk_1194[0].unk_08[0]->unk_01C[i].unk_00.unk_00, NULL);
    }

    for (i = 0, count = 6; i < D_800AE540.unk_1194[1].unk_08[0]->unk_002; count++, i++) {
        PokeIcon_LoadModelTextureForMon(&arg0->unk_20[count], D_800AE540.unk_1194[1].unk_08[0]->unk_01C[i].unk_00.unk_00, NULL);
    }

    if (D_800AE540.unk_1194[0].unk_08[1] != NULL) {
        for (i = 0, count = 3; i < D_800AE540.unk_1194[0].unk_08[1]->unk_002; count++, i++) {
            PokeIcon_LoadModelTextureForMon(&arg0->unk_20[count], D_800AE540.unk_1194[0].unk_08[1]->unk_01C[i].unk_00.unk_00, NULL);
        }
    }

    if (D_800AE540.unk_1194[1].unk_08[1] != NULL) {
        for (i = 0, count = 9; i < D_800AE540.unk_1194[1].unk_08[1]->unk_002; count++, i++) {
            PokeIcon_LoadModelTextureForMon(&arg0->unk_20[count], D_800AE540.unk_1194[1].unk_08[1]->unk_01C[i].unk_00.unk_00, NULL);
        }
    }
}

void BattlePrepTeamIcons_Init(unk_D_84B25A58* arg0) {
    MemoryBlock* sp2C;
    s32 i;

    arg0->unk_00 = 0;
    arg0->unk_01 = 0;
    arg0->unk_02 = 0;
    arg0->unk_24 = GfxImage_Allocate(0, 2, 0x40, 0x60, 0);
    arg0->unk_28 = GfxImage_Allocate(0, 2, 0x40, 0x60, 0);

    if ((D_800AE540.unk_0001 == 8) && (D_800AE540.unk_1194[0].unk_08[0]->unk_002 >= 4)) {
        arg0->unk_02 = 1;
    }

    if (D_800AE540.unk_0001 == 0) {
        if ((D_800AE540.unk_1194[0].unk_01 == 2) || (D_800AE540.unk_1194[1].unk_01 == 2)) {
            arg0->unk_02 = 1;
        } else {
            if (D_800AE540.unk_1194[0].unk_08[0]->unk_002 >= 4) {
                arg0->unk_02 = 1;
            }

            if (D_800AE540.unk_1194[1].unk_08[0]->unk_002 >= 4) {
                arg0->unk_02 = 1;
            }
        }
    }

    for (i = 0; i < 12; i++) {
        arg0->unk_2C[i] = 0;
    }

    if (arg0->unk_02 == 1) {
        arg0->unk_1C = PokeIcon_CreateRenderList(NULL, 0xC, 0x80, 0x60);
        arg0->unk_20 = ALIGN64((u32)main_pool_alloc(0x9640, 0));
    } else {
        arg0->unk_1C = PokeIcon_CreateRenderList(NULL, 6, 0x80, 0xC0);
        arg0->unk_20 = ALIGN64((u32)main_pool_alloc(0x4B40, 0));
    }

    PokeIcon_SetNameTable(arg0->unk_1C, D_84B186C0);

    sp2C = MainPool_AllocState(main_pool_get_available(), 0);
    if (arg0->unk_02 == 1) {
        arg0->unk_08 = process_geo_layout(sp2C, D_84B15F50);
        arg0->unk_0C = process_geo_layout(sp2C, D_84B15FA8);
        arg0->unk_10 = process_geo_layout(sp2C, D_84B162D8);
        arg0->unk_14 = process_geo_layout(sp2C, D_84B16330);
    } else {
        arg0->unk_08 = process_geo_layout(sp2C, D_84B15688);
        arg0->unk_10 = process_geo_layout(sp2C, D_84B15A20);
    }

    arg0->unk_18 = process_geo_layout(sp2C, D_84B14DC8);
    MainPool_FinalizeAllocation(sp2C);

    if (arg0->unk_02 == 1) {
        BattlePrepTeamIcons_LoadIconTexturesDouble(arg0);
    } else {
        BattlePrepTeamIcons_LoadIconTexturesSingle(arg0);
    }
}
