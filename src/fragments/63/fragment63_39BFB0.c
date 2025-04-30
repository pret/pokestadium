#include "fragment63.h"
#include "src/12D80.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/20470.h"
#include "src/4CBC0.h"
#include "src/6BC0.h"
#include "src/F420.h"
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
    0x00000000, 0x08000000, func_84B07EB0, D_84B14CE0, 0x06000000, 0x01000000, 0x00000000,
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
    0x08000000, func_84B07F78, D_84B15200, 0x22050000, D_84B15618, 0x25000000, 0x06000000, 0x01000000,
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
    0x08000000, func_84B080F4, D_84B15848, 0x22050000, D_84B159B0, 0x25000000, 0x06000000, 0x01000000,
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
    0x00000000, 0x00180000, 0x05000000, 0x22050000, 0x00000000, 0x08000000, func_84B08230, D_84B15CA0,
    0x22050000, D_84B15EE0, 0x25000000, 0x06000000, 0x06000000, 0x01000000,
};
static u32 D_84B15FA8[] = {
    0x17000000, 0x00000000, 0x00000000, 0x00000000, D_84B15A60, 0x05000000, 0x1B000000,    0x00000000,
    0x00000000, 0xFFE80000, 0x05000000, 0x22050000, 0x00000000, 0x08000000, func_84B08230, D_84B15CA0,
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
    0x00000000, 0x00180000, 0x05000000, 0x22050000, 0x00000000, 0x08000000, func_84B083D8, D_84B16140,
    0x22050000, D_84B16268, 0x25000000, 0x06000000, 0x06000000, 0x01000000,
};
static u32 D_84B16330[] = {
    0x17000000, 0x00000000, 0x00000000, 0x00000000, D_84B16000, 0x05000000, 0x1B000000,    0x00000000,
    0x00000000, 0xFFE80000, 0x05000000, 0x22050000, 0x00000000, 0x08000000, func_84B083D8, D_84B16140,
    0x22050000, D_84B16268, 0x25000000, 0x06000000, 0x06000000, 0x01000000, 0x00000000,    0x00000000,
};

s32 func_84B07EB0(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25A58* temp_v1;
    u8* var_a3;

    if (arg0 == 5) {
        temp_v1 = (unk_D_84B25A58*)D_8006F09C->unk_000.unk_14;
        if (temp_v1->unk_04->unk_0A6 == D_8006F09C->unk_0A6) {
            var_a3 = temp_v1->unk_24->img_p;
        } else {
            var_a3 = temp_v1->unk_28->img_p;
        }

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)var_a3 & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }
    return 0;
}

s32 func_84B07F78(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25A58* temp_t1;
    s32 temp_t2;
    u8* var_a3;

    if (arg0 == 5) {
        temp_t1 = (unk_D_84B25A58*)D_8006F09C->unk_000.unk_14;
        temp_t2 = D_8006F09C->unk_0A6 - temp_t1->unk_04->unk_0A6;
        if (temp_t2 < 4) {
            var_a3 = D_3006000;
        } else {
            var_a3 = D_3009000;
        }

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)func_8001AFD8(temp_t1->unk_1C, temp_t2 - 1) & 0x1FFFFFFF);
        gSPSegment(gDisplayListHead++, 0x0E, (u32)Memmap_GetSegmentVaddr(var_a3) & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();

        if (temp_t1->unk_2C[temp_t2 - 1] != 0) {
            arg1->unk_00.unk_08->unk_01 |= 1;
        } else {
            arg1->unk_00.unk_08->unk_01 &= ~1;
        }
    }
    return 0;
}

s32 func_84B080F4(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25A58* temp_a3;
    s32 temp_t0;
    u8* var_a0;

    if (arg0 == 5) {
        temp_a3 = (unk_D_84B25A58*)D_8006F09C->unk_000.unk_14;
        temp_t0 = (D_8006F09C->unk_0A6 - temp_a3->unk_04->unk_0A6) % 8;
        if (temp_t0 < 4) {
            var_a0 = D_3006000;
        } else {
            var_a0 = D_3009000;
        }

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)temp_a3->unk_20[temp_t0 - 1] & 0x1FFFFFFF);
        gSPSegment(gDisplayListHead++, 0x0E, (u32)Memmap_GetSegmentVaddr(var_a0) & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }
    return 0;
}

s32 func_84B08230(s32 arg0, unk_func_80011B94* arg1) {
    u8* var_a3;
    unk_D_84B25A58* temp_t1;
    s32 temp_a1;

    if (arg0 == 5) {
        temp_t1 = (unk_D_84B25A58*)D_8006F09C->unk_000.unk_14;
        temp_a1 = D_8006F09C->unk_0A6 - temp_t1->unk_04->unk_0A6;

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
        gSPSegment(gDisplayListHead++, 0x0F, (u32)func_8001AFD8(temp_t1->unk_1C, temp_a1) & 0x1FFFFFFF);
        gSPSegment(gDisplayListHead++, 0x0E, (u32)Memmap_GetSegmentVaddr(var_a3) & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();

        if (temp_t1->unk_2C[temp_a1] != 0) {
            arg1->unk_00.unk_08->unk_01 |= 1;
        } else {
            arg1->unk_00.unk_08->unk_01 &= ~1;
        }
    }
    return 0;
}

s32 func_84B083D8(s32 arg0, unk_func_80011B94* arg1) {
    s32 temp_a3;
    unk_D_84B25A58* temp_t1;
    u8* var_a0;

    if (arg0 == 5) {
        temp_t1 = (unk_D_84B25A58*)D_8006F09C->unk_000.unk_14;
        temp_a3 = D_8006F09C->unk_0A6 - temp_t1->unk_04->unk_0A6;

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
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }
    return 0;
}

void func_84B0852C(unk_D_84B25A58* arg0, s32 arg1) {
    s32 i;
    s32 j;
    UNUSED s32 pad;
    unk_D_800AE540_0004* temp_s5;
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
            func_80006498(&gDisplayListHead, arg0->unk_1C->unk_08[i * 3 + j].unk_0C);
            func_80020B88(4, 0xB4, 0x78, var_s0, temp_s5->unk_01C[j].unk_26 * 0x64);
        }
    }
}

void func_84B08694(unk_D_84B25A58* arg0, s32 arg1) {
    s32 i;
    s32 j;
    s32 x;
    s32 temp_lo;
    s32 var_s0;
    unk_D_800AE540_0004* temp_s5;

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
                    func_80006498(&gDisplayListHead, arg0->unk_1C->unk_08[(i * 6) + (j * 3) + x].unk_0C);
                    func_80020B88(4, 0x54, 0x78, var_s0, temp_s5->unk_01C[x].unk_26 * 0x64);
                }
            }
        }
    }
}

void func_84B08858(unk_D_84B25A58* arg0, s32 arg1) {
    UNUSED s32 pad;
    unk_D_800AE540_0004* temp_s5;
    s32 temp_v0;
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        temp_s5 = D_800AE540.unk_1194[i].unk_08[0];

        for (j = 0; j < temp_s5->unk_002; j++) {
            if (arg1 == temp_s5->unk_01C[j].unk_25) {
                temp_v0 = (i * 3) + j;
                arg0->unk_2C[temp_v0] = 1;
                func_8004DF94(0x0110000B, temp_v0 + 1, 0);
            }
        }
    }
}

void func_84B08954(unk_D_84B25A58* arg0, s32 arg1) {
    s32 i;
    s32 j;
    s32 x;
    unk_D_800AE540_0004* temp_s5;
    s32 temp_v0;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            temp_s5 = D_800AE540.unk_1194[i].unk_08[j];

            if (temp_s5 != NULL) {
                for (x = 0; x < temp_s5->unk_002; x++) {
                    if (arg1 == temp_s5->unk_01C[x].unk_25) {
                        temp_v0 = (i * 6) + (j * 3) + x;
                        arg0->unk_2C[temp_v0] = 1;
                        func_8004DF94(0x0110000B, temp_v0 + 1, 1);
                    }
                }
            }
        }
    }
}

void func_84B08A90(unk_D_84B25A58* arg0) {
    s32 i;

    for (i = 1; i < 7; i++) {
        func_8001BC34(&arg0->unk_04[i], 0, 0, arg0->unk_08);
        arg0->unk_04[i].unk_000.unk_14 = arg0;
    }

    for (i = 1; i < 4; i++) {
        arg0->unk_04[i].unk_01E.y = 0x5800;
        func_8000E88C(&arg0->unk_04[i].unk_024, (i * 64.0f) - 96.0f, 48.0f, -289.0f);
    }

    for (i = 0; i < 3; i++) {
        arg0->unk_04[4 + i].unk_01E.y = -0x5800;
        func_8000E88C(&arg0->unk_04[4 + i].unk_024, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
    }
}

void func_84B08BFC(unk_D_84B25A58* arg0) {
    s32 i;

    for (i = 1; i < 7; i++) {
        func_8001BC34(&arg0->unk_04[8 + i], 0, 0, arg0->unk_10);
        arg0->unk_04[8 + i].unk_000.unk_14 = arg0;
        arg0->unk_04[8 + i].unk_01E.y = -0x8000;
    }

    for (i = 1; i < 4; i++) {
        func_8000E88C(&arg0->unk_04[8 + i].unk_024, (i * 64.0f) - 96.0f, 48.0f, -289.0f);
    }

    for (i = 0; i < 3; i++) {
        func_8000E88C(&arg0->unk_04[12 + i].unk_024, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
    }
}

void func_84B08D54(unk_D_84B25A58* arg0) {
    s32 i;

    for (i = 1; i < 4; i++) {
        func_8001BC34(&arg0->unk_04[15 + i], 0, 0, arg0->unk_08);
        func_8001BC34(&arg0->unk_04[18 + i], 0, 0, arg0->unk_0C);
        arg0->unk_04[15 + i].unk_000.unk_14 = arg0;
        arg0->unk_04[18 + i].unk_000.unk_14 = arg0;

        arg0->unk_04[15 + i].unk_01E.y = 0x5800;
        arg0->unk_04[18 + i].unk_01E.y = 0x5800;

        func_8000E88C(&arg0->unk_04[15 + i].unk_024, (i * 64.0f) - 96.0f, 48.0f, -289.0f);
        func_8000E88C(&arg0->unk_04[18 + i].unk_024, (i * 64.0f) - 96.0f, 48.0f, -289.0f);
    }

    for (i = 0; i < 3; i++) {
        func_8001BC34(&arg0->unk_04[22 + i], 0, 0, arg0->unk_08);
        func_8001BC34(&arg0->unk_04[25 + i], 0, 0, arg0->unk_0C);
        arg0->unk_04[22 + i].unk_000.unk_14 = arg0;
        arg0->unk_04[25 + i].unk_000.unk_14 = arg0;

        arg0->unk_04[22 + i].unk_01E.y = -0x5800;
        arg0->unk_04[25 + i].unk_01E.y = -0x5800;

        func_8000E88C(&arg0->unk_04[22 + i].unk_024, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
        func_8000E88C(&arg0->unk_04[25 + i].unk_024, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
    }
}

void func_84B08F7C(unk_D_84B25A58* arg0) {
    s32 i;

    for (i = 1; i < 4; i++) {
        func_8001BC34(&arg0->unk_04[27 + i], 0, 0, arg0->unk_10);
        func_8001BC34(&arg0->unk_04[30 + i], 0, 0, arg0->unk_14);

        arg0->unk_04[27 + i].unk_000.unk_14 = arg0;
        arg0->unk_04[30 + i].unk_000.unk_14 = arg0;

        arg0->unk_04[27 + i].unk_01E.y = -0x8000;
        arg0->unk_04[30 + i].unk_01E.y = -0x8000;

        func_8000E88C(&arg0->unk_04[27 + i].unk_024, (i * 64.0f) - 96.0f, 48.0f, -289.0f);
        func_8000E88C(&arg0->unk_04[30 + i].unk_024, (i * 64.0f) - 96.0f, 48.0f, -289.0f);
    }

    for (i = 0; i < 3; i++) {
        func_8001BC34(&arg0->unk_04[34 + i], 0, 0, arg0->unk_10);
        func_8001BC34(&arg0->unk_04[37 + i], 0, 0, arg0->unk_14);
        arg0->unk_04[34 + i].unk_000.unk_14 = arg0;
        arg0->unk_04[37 + i].unk_000.unk_14 = arg0;

        arg0->unk_04[34 + i].unk_01E.y = -0x8000;
        arg0->unk_04[37 + i].unk_01E.y = -0x8000;

        func_8000E88C(&arg0->unk_04[34 + i].unk_024, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
        func_8000E88C(&arg0->unk_04[37 + i].unk_024, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
    }
}

void func_84B091A0(unk_D_84B25A58* arg0, s16 arg1) {
    s16 i;

    if (arg1 == 0) {
        func_8004DF94(0x01100009, 0, 0);
    }

    if (arg1 < 0xB) {
        for (i = 0; i < 4; i++) {
            arg0->unk_04[i].unk_01E.y -= 0x800;
        }

        for (i = 4; i < 8; i++) {
            arg0->unk_04[i].unk_01E.y += 0x800;
        }

        func_84B0852C(arg0, 0x64);
    }
}

void func_84B09268(unk_D_84B25A58* arg0, s16 arg1) {
    s16 i;

    if (arg1 == 0) {
        func_8004DF94(0x01100009, 0, 0);
    }

    if (arg1 < 0xB) {
        arg0->unk_04[0].unk_01E.y -= 0x800;
        arg0->unk_04[7].unk_01E.y += 0x800;

        for (i = 16; i < 22; i++) {
            arg0->unk_04[i].unk_01E.y -= 0x800;
        }

        for (i = 22; i < 28; i++) {
            arg0->unk_04[i].unk_01E.y += 0x800;
        }

        func_84B08694(arg0, 0x64);
    }
}

void func_84B09354(unk_D_84B25A58* arg0, s16 arg1) {
    if (arg1 == 0) {
        func_8004DF94(0x0110000A, 0, 0);
    }

    if (arg1 < 0x1A) {
        func_84B0852C(arg0, 0x64 - (arg1 * 4));
    } else if (arg1 < 0x3E) {
        if (((arg1 - 0x1A) % 6) == 0) {
            func_84B08858(arg0, ((arg1 - 0x1A) / 6) + 1);
        }
    }
}

void func_84B09444(unk_D_84B25A58* arg0, s16 arg1) {
    if (arg1 == 0) {
        func_8004DF94(0x0110000A, 0, 0);
    }

    if (arg1 < 0x1A) {
        func_84B08694(arg0, 0x64 - (arg1 * 4));
    } else if (arg1 < 0x3E) {
        if (((arg1 - 0x1A) % 3) == 0) {
            func_84B08954(arg0, ((arg1 - 0x1A) / 3) + 1);
        }
    }
}

void func_84B09534(unk_D_84B25A58* arg0, s16 arg1) {
    if (arg1 == 0) {
        func_8004DF94(0x0110000A, 0, 0);
    }

    if (arg1 < 0x15) {
        func_84B0852C(arg0, 0x64 - (arg1 * 5));
    } else if (arg1 < 0x33) {
        if (((arg1 - 0x15) % 5) == 0) {
            func_84B08858(arg0, ((arg1 - 0x15) / 5) + 1);
        }
    }
}

void func_84B0962C(unk_D_84B25A58* arg0, s16 arg1) {
    if (arg1 == 0) {
        func_8004DF94(0x0110000A, 0, 0);
    }

    if (arg1 < 0x15) {
        func_84B08694(arg0, 0x64 - (arg1 * 5));
    } else if (arg1 < 0x39) {
        if (((arg1 - 0x15) % 3) == 0) {
            func_84B08954(arg0, ((arg1 - 0x15) / 3) + 1);
        }
    }
}

void func_84B09720(unk_D_84B25A58* arg0, s16 arg1) {
    s32 i;
    unk_func_80026268_arg0* temp_s5 = D_800AE540.unk_1194[0].unk_08[0]->unk_01C;
    unk_func_80026268_arg0* temp_s6 = D_800AE540.unk_1194[1].unk_08[0]->unk_01C;

    if (arg1 == 0) {
        func_84B08BFC(arg0);
    }

    if (arg1 < 0x10) {
        for (i = 0; i < D_800AE540.unk_1194[0].unk_08[0]->unk_002; i++) {
            if (temp_s5[i].unk_25 != 0) {
                arg0->unk_04[1 + i].unk_01E.y += 0x800;
                arg0->unk_04[9 + i].unk_01E.y += 0x800;
            }
        }

        for (i = 0; i < D_800AE540.unk_1194[1].unk_08[0]->unk_002; i++) {
            if (temp_s6[i].unk_25 != 0) {
                arg0->unk_04[4 + i].unk_01E.y -= 0x800;
                arg0->unk_04[12 + i].unk_01E.y -= 0x800;
            }
        }
    }

    if (arg1 == 0x10) {
        for (i = 1; i < 7; i++) {
            func_8001BCF0(&arg0->unk_04[i]);
            func_84B00404(&arg0->unk_04[8 + i]);
            arg0->unk_04[i].unk_01E.y = 0;
        }

        for (i = 0; i < 3; i++) {
            if ((i >= D_800AE540.unk_1194[0].unk_08[0]->unk_002) || (temp_s5[i].unk_25 == 0)) {
                func_8001BC34(&arg0->unk_04[1 + i], 0, 0, arg0->unk_08);
            } else {
                func_8001BC34(&arg0->unk_04[1 + i], 0, 0, arg0->unk_10);
            }
        }

        for (i = 0; i < 3; i++) {
            if ((i >= D_800AE540.unk_1194[1].unk_08[0]->unk_002) || (temp_s6[i].unk_25 == 0)) {
                func_8001BC34(&arg0->unk_04[4 + i], 0, 0, arg0->unk_08);
            } else {
                func_8001BC34(&arg0->unk_04[4 + i], 0, 0, arg0->unk_10);
            }
        }
    }
}

void func_84B099D8(unk_D_84B25A58* arg0, s16 arg1) {
    s32 i;
    unk_func_80026268_arg0* temp_s0 = &D_800AE540.unk_1194[0].unk_08[0]->unk_01C[0];
    unk_func_80026268_arg0* var_a3 = NULL;
    unk_func_80026268_arg0* temp_t1 = &D_800AE540.unk_1194[1].unk_08[0]->unk_01C[0];
    unk_func_80026268_arg0* var_t0 = NULL;

    if (D_800AE540.unk_1194[0].unk_01 == 2) {
        var_a3 = &D_800AE540.unk_1194[0].unk_08[1]->unk_01C[0];
    }

    if (D_800AE540.unk_1194[1].unk_01 == 2) {
        var_t0 = &D_800AE540.unk_1194[1].unk_08[1]->unk_01C[0];
    }

    if (arg1 == 0) {
        func_84B08F7C(arg0);
    }

    if (arg1 < 0x10) {
        for (i = 0; i < D_800AE540.unk_1194[0].unk_08[0]->unk_002; i++) {
            if (temp_s0[i].unk_25 != 0) {
                arg0->unk_04[16 + i].unk_01E.y += 0x800;
                arg0->unk_04[28 + i].unk_01E.y += 0x800;
            }
        }

        for (i = 0; i < D_800AE540.unk_1194[1].unk_08[0]->unk_002; i++) {
            if (temp_t1[i].unk_25 != 0) {
                arg0->unk_04[22 + i].unk_01E.y -= 0x800;
                arg0->unk_04[34 + i].unk_01E.y -= 0x800;
            }
        }

        if (var_a3 != NULL) {
            for (i = 0; i < D_800AE540.unk_1194[0].unk_08[1]->unk_002; i++) {
                if (var_a3[i].unk_25 != 0) {
                    arg0->unk_04[19 + i].unk_01E.y += 0x800;
                    arg0->unk_04[31 + i].unk_01E.y += 0x800;
                }
            }
        }

        if (var_t0 != NULL) {
            for (i = 0; i < D_800AE540.unk_1194[1].unk_08[1]->unk_002; i++) {
                if (var_t0[i].unk_25 != 0) {
                    arg0->unk_04[25 + i].unk_01E.y -= 0x800;
                    arg0->unk_04[37 + i].unk_01E.y -= 0x800;
                }
            }
        }
    }

    if (arg1 == 0x10) {
        for (i = 0; i < 3; i++) {
            if (arg0->unk_04[16 + i].unk_01E.y == 0) {
                func_8001BC34(&arg0->unk_04[1 + i], 0, 0, arg0->unk_08);
            } else {
                func_8001BC34(&arg0->unk_04[1 + i], 0, 0, arg0->unk_10);
            }
            arg0->unk_04[1 + i].unk_000.unk_14 = arg0;
            func_8000E88C(&arg0->unk_04[1 + i].unk_024, (i * 64.0f) - 32.0f, 48.0f, -289.0f);
        }

        for (i = 0; i < 3; i++) {
            if (arg0->unk_04[19 + i].unk_01E.y == 0) {
                func_8001BC34(&arg0->unk_04[9 + i], 0, 0, arg0->unk_0C);
            } else {
                func_8001BC34(&arg0->unk_04[9 + i], 0, 0, arg0->unk_14);
            }
            arg0->unk_04[9 + i].unk_000.unk_14 = arg0;
            func_8000E88C(&arg0->unk_04[9 + i].unk_024, (i * 64.0f) - 32.0f, 48.0f, -289.0f);
        }

        for (i = 0; i < 3; i++) {
            if (arg0->unk_04[22 + i].unk_01E.y == 0) {
                func_8001BC34(&arg0->unk_04[4 + i], 0, 0, arg0->unk_08);
            } else {
                func_8001BC34(&arg0->unk_04[4 + i], 0, 0, arg0->unk_10);
            }
            arg0->unk_04[4 + i].unk_000.unk_14 = arg0;
            func_8000E88C(&arg0->unk_04[4 + i].unk_024, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
        }

        for (i = 0; i < 3; i++) {
            if (arg0->unk_04[25 + i].unk_01E.y == 0) {
                func_8001BC34(&arg0->unk_04[12 + i], 0, 0, arg0->unk_0C);
            } else {
                func_8001BC34(&arg0->unk_04[12 + i], 0, 0, arg0->unk_14);
            }
            arg0->unk_04[12 + i].unk_000.unk_14 = arg0;
            func_8000E88C(&arg0->unk_04[12 + i].unk_024, (i * 64.0f) - 96.0f, -48.0f, -289.0f);
        }

        for (i = 16; i < 40; i++) {
            func_84B00404(&arg0->unk_04[i]);
        }
    }
}

void func_84B09F60(unk_D_84B25A58* arg0) {
    if (osTvType == OS_TV_PAL) {
        if (arg0->unk_02 == 1) {
            if (arg0->unk_01 >= 0) {
                func_84B09268(arg0, arg0->unk_01);
            }

            if (arg0->unk_01 >= 0xC) {
                func_84B0962C(arg0, arg0->unk_01 - 0xC);
            }

            if (arg0->unk_01 >= 0x3E) {
                func_84B099D8(arg0, arg0->unk_01 - 0x3E);
            }
        } else {
            if (arg0->unk_01 >= 0) {
                func_84B091A0(arg0, arg0->unk_01);
            }

            if (arg0->unk_01 >= 0xC) {
                func_84B09534(arg0, arg0->unk_01 - 0xC);
            }

            if (arg0->unk_01 >= 0x3E) {
                func_84B09720(arg0, arg0->unk_01 - 0x3E);
            }
        }

        arg0->unk_01++;
        if (arg0->unk_01 == 0x50) {
            arg0->unk_00 = 0;
        }
    } else {
        if (arg0->unk_02 == 1) {
            if (arg0->unk_01 >= 0) {
                func_84B09268(arg0, arg0->unk_01);
            }

            if (arg0->unk_01 >= 0xC) {
                func_84B09444(arg0, arg0->unk_01 - 0xC);
            }

            if (arg0->unk_01 >= 0x4A) {
                func_84B099D8(arg0, arg0->unk_01 - 0x4A);
            }
        } else {
            if (arg0->unk_01 >= 0) {
                func_84B091A0(arg0, arg0->unk_01);
            }

            if (arg0->unk_01 >= 0xC) {
                func_84B09354(arg0, arg0->unk_01 - 0xC);
            }

            if (arg0->unk_01 >= 0x4A) {
                func_84B09720(arg0, arg0->unk_01 - 0x4A);
            }
        }

        arg0->unk_01++;
        if (arg0->unk_01 == 0x60) {
            arg0->unk_00 = 0;
        }
    }
}

void func_84B0A18C(unk_D_84B25A58* arg0) {
    func_8001AA18(arg0->unk_1C, 0, arg0);

    arg0->unk_01++;
    if ((arg0->unk_01 >= 0x1E) && (func_8001B010(arg0->unk_1C) != 0)) {
        arg0->unk_01 = 0;
        arg0->unk_00 = 2;
    }
}

void func_84B0A1F4(unk_D_84B25A58* arg0) {
    switch (arg0->unk_00) {
        case 1:
            func_84B0A18C(arg0);
            break;

        case 3:
            func_84B09F60(arg0);
            break;
    }
}

void func_84B0A244(unk_D_84B25A58* arg0) {
    s32 i;
    s32 count;
    unk_D_86002F58_004_000_010* temp_s0;

    temp_s0 = func_80019760(5);
    func_8001A1D0(arg0->unk_1C, temp_s0, func_80006314(0, 2, 0x80, 0xC0, 1));

    for (count = 0, i = 0; i < D_800AE540.unk_1194[0].unk_08[0]->unk_002; count++, i++) {
        func_8001A324(arg0->unk_1C, count, D_800AE540.unk_1194[0].unk_08[0]->unk_01C[i].unk_00.unk_00, 0);
    }

    for (count = 3, i = 0; i < D_800AE540.unk_1194[1].unk_08[0]->unk_002; count++, i++) {
        func_8001A324(arg0->unk_1C, count, D_800AE540.unk_1194[1].unk_08[0]->unk_01C[i].unk_00.unk_00, 0);
    }
}

void func_84B0A36C(unk_D_84B25A58* arg0) {
    s32 i;
    s32 count;
    unk_D_86002F58_004_000_010* temp_s0;

    temp_s0 = func_80019760(5);
    func_8001A1D0(arg0->unk_1C, temp_s0, func_80006314(0, 2, 0x80, 0x60, 1));

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

void func_84B0A544(unk_D_84B25A58* arg0, BinArchive* arg1) {
    u8* sp24 = func_8000484C(arg1, D_800AE540.unk_1194[0].unk_08[0]->unk_214->unk_003);
    u8* sp20 = func_8000484C(arg1, D_800AE540.unk_1194[1].unk_08[0]->unk_214->unk_003);

    func_8001987C();

    FRAGMENT_LOAD(fragment31);

    if (arg0->unk_02 == 1) {
        func_84B0A36C(arg0);
    } else {
        func_84B0A244(arg0);
    }

    func_84B00D3C(arg0->unk_24, 0, sp24, D_3000000);
    func_84B00D3C(arg0->unk_28, 1, sp20, D_3003000);
    arg0->unk_00 = 1;
}

s32 func_84B0A634(unk_D_84B25A58* arg0, unk_D_86002F58_004_000* arg1) {
    if (arg0->unk_00 == 2) {
        arg0->unk_00 = 3;
        arg0->unk_04 = arg1;
        arg0->unk_01 = 0;
        arg1->unk_000.unk_14 = arg0;

        arg0->unk_04[7].unk_000.unk_14 = arg0;
        arg0->unk_04[0].unk_01E.y = 0x5800;
        arg0->unk_04[7].unk_01E.y = -0x5800;

        func_8000E88C(&arg0->unk_04[0].unk_024, -96.0f, 48.0f, -289.0f);
        func_8000E88C(&arg0->unk_04[7].unk_024, 96.0f, -48.0f, -289.0f);
        func_8001BC34(&arg0->unk_04[0], 0, 0, arg0->unk_18);
        func_8001BC34(&arg0->unk_04[7], 0, 0, arg0->unk_18);

        if (arg0->unk_02 == 1) {
            func_84B08D54(arg0);
        } else {
            func_84B08A90(arg0);
        }
    }
    return arg0->unk_00 == 3;
}

void func_84B0A738(unk_D_84B25A58* arg0) {
    s32 i;
    s32 count;

    for (i = 0, count = 0; i < D_800AE540.unk_1194[0].unk_08[0]->unk_002; count++, i++) {
        func_8001B0DC(arg0->unk_20[count], D_800AE540.unk_1194[0].unk_08[0]->unk_01C[i].unk_00.unk_00, NULL);
    }

    for (i = 0, count = 3; i < D_800AE540.unk_1194[1].unk_08[0]->unk_002; count++, i++) {
        func_8001B0DC(arg0->unk_20[count], D_800AE540.unk_1194[1].unk_08[0]->unk_01C[i].unk_00.unk_00, NULL);
    }
}

void func_84B0A82C(unk_D_84B25A58* arg0) {
    s32 i;
    s32 count;

    for (i = 0, count = 0; i < D_800AE540.unk_1194[0].unk_08[0]->unk_002; count++, i++) {
        func_8001B0DC(&arg0->unk_20[count], D_800AE540.unk_1194[0].unk_08[0]->unk_01C[i].unk_00.unk_00, NULL);
    }

    for (i = 0, count = 6; i < D_800AE540.unk_1194[1].unk_08[0]->unk_002; count++, i++) {
        func_8001B0DC(&arg0->unk_20[count], D_800AE540.unk_1194[1].unk_08[0]->unk_01C[i].unk_00.unk_00, NULL);
    }

    if (D_800AE540.unk_1194[0].unk_08[1] != NULL) {
        for (i = 0, count = 3; i < D_800AE540.unk_1194[0].unk_08[1]->unk_002; count++, i++) {
            func_8001B0DC(&arg0->unk_20[count], D_800AE540.unk_1194[0].unk_08[1]->unk_01C[i].unk_00.unk_00, NULL);
        }
    }

    if (D_800AE540.unk_1194[1].unk_08[1] != NULL) {
        for (i = 0, count = 9; i < D_800AE540.unk_1194[1].unk_08[1]->unk_002; count++, i++) {
            func_8001B0DC(&arg0->unk_20[count], D_800AE540.unk_1194[1].unk_08[1]->unk_01C[i].unk_00.unk_00, NULL);
        }
    }
}

void func_84B0A9D0(unk_D_84B25A58* arg0) {
    MemoryBlock* sp2C;
    s32 i;

    arg0->unk_00 = 0;
    arg0->unk_01 = 0;
    arg0->unk_02 = 0;
    arg0->unk_24 = func_80006314(0, 2, 0x40, 0x60, 0);
    arg0->unk_28 = func_80006314(0, 2, 0x40, 0x60, 0);

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
        arg0->unk_1C = func_8001A024(NULL, 0xC, 0x80, 0x60);
        arg0->unk_20 = ALIGN64((u32)main_pool_alloc(0x9640, 0));
    } else {
        arg0->unk_1C = func_8001A024(NULL, 6, 0x80, 0xC0);
        arg0->unk_20 = ALIGN64((u32)main_pool_alloc(0x4B40, 0));
    }

    func_8001A250(arg0->unk_1C, D_84B186C0);

    sp2C = func_80002D10(main_pool_get_available(), 0);
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
    func_80002D60(sp2C);

    if (arg0->unk_02 == 1) {
        func_84B0A82C(arg0);
    } else {
        func_84B0A738(arg0);
    }
}
