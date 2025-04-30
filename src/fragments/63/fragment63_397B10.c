#include "fragment63.h"
#include "src/12D80.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/4CBC0.h"
#include "src/6BC0.h"
#include "src/F420.h"
#include "src/memory.h"
#include "src/util.h"

s32 func_84B03A10(s32, unk_func_80011B94*);
s32 func_84B03AB4(s32, unk_func_80011B94*);
s32 func_84B03C20(s32, unk_func_80011B94*);
s32 func_84B03CC4(s32, unk_D_86002F34_alt5*);
s32 func_84B03B58(s32, unk_func_80011B94*);

s32 func_84B05760(s32, unk_func_80011B94*);
s32 func_84B05844(s32, unk_func_80011B94*);
s32 func_84B05A2C(s32, unk_func_80011B94*);
s32 func_84B05B04(s32, unk_func_80011B94*);

static u8 D_84B0FC40[] = {
    0x00, 0x00, 0x00, 0x01, 0x02, 0x03,
};
static u8 D_84B0FC48[] = {
    0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0C,
};
static u8* D_84B0FC54[] = {
    D_30339F0, D_3034FD0, D_30365B0, D_3037B90, D_3039170, D_303A750,
};
static u8* D_84B0FC6C[] = {
    D_303BD30, D_303D310, D_303E8F0, D_303FED0, D_30414B0, D_3042A90, D_3044070, D_3045650, D_3046C30,
};
static u8* D_84B0FC90[] = {
    D_3048210, D_3029270, D_3029670, D_3029A70, D_3029E70, D_302A270, D_302A670,
};
static u8* D_84B0FCAC[] = {
    D_3030A70,
    D_3031650,
    D_3032230,
    D_3032E10,
};
static Color_RGBA8 D_84B0FCBC[] = {
    { 0x1E, 0x8C, 0x1E, 0xFF }, { 0x1E, 0x8C, 0x1E, 0xFF }, { 0x1E, 0x8C, 0x1E, 0xFF }, { 0x50, 0x50, 0xFF, 0xFF },
    { 0xB4, 0x8C, 0x1E, 0xFF }, { 0x96, 0x1E, 0x1E, 0xFF }, { 0x64, 0x64, 0x82, 0xFF }, { 0x50, 0x50, 0xFF, 0xFF },
    { 0xC8, 0x78, 0x1E, 0xFF }, { 0x82, 0x32, 0xC8, 0xFF }, { 0xB4, 0x3C, 0xB4, 0xFF }, { 0xB4, 0x8C, 0x1E, 0xFF },
    { 0x96, 0x1E, 0x1E, 0xFF }, { 0x1E, 0x8C, 0x1E, 0xFF }, { 0xB4, 0x50, 0x1E, 0xFF }, { 0x1E, 0x3C, 0xA0, 0xFF },
};
static Color_RGBA8 D_84B0FCFC[] = {
    { 0xC8, 0xC8, 0x1E, 0xFF }, { 0xC8, 0xC8, 0x1E, 0xFF }, { 0xC8, 0xC8, 0x1E, 0xFF }, { 0x64, 0xDC, 0xDC, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF }, { 0xC8, 0xC8, 0x1E, 0xFF }, { 0xFF, 0xFF, 0xFF, 0xFF }, { 0x64, 0xDC, 0xDC, 0xFF },
    { 0xDC, 0xDC, 0x1E, 0xFF }, { 0xDC, 0x64, 0xDC, 0xFF }, { 0xFF, 0xC8, 0xFF, 0xFF }, { 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xC8, 0x82, 0x82, 0xFF }, { 0xC8, 0xC8, 0x1E, 0xFF }, { 0xC8, 0xC8, 0x1E, 0xFF }, { 0x1E, 0xDC, 0x82, 0xFF },
};
static Vtx D_84B0FD40[] = {
    VTX(-128, 48, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-128, 16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, 16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(-64, 48, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, 48, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(-64, 16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 16, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(0, 48, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 48, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(0, 16, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, 16, 0, 6144, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(64, 48, 0, 6144, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, 48, 0, 6144, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(64, 16, 0, 6144, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, 16, 0, 8192, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(128, 48, 0, 8192, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B0FE40[] = {
    VTX(-128, 16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(-128, -16, 0, 0, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -16, 0, 2048, 2048, 0xFF, 0xFF, 0xFF, 0xFF), VTX(-64, 16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, 16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(-64, -16, 0, 2048, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -16, 0, 4096, 2048, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(0, 16, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 16, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(0, -16, 0, 4096, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -16, 0, 6144, 2048, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(64, 16, 0, 6144, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, 16, 0, 6144, 1024, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(64, -16, 0, 6144, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, -16, 0, 8192, 2048, 0xFF, 0xFF, 0xFF, 0xFF), VTX(128, 16, 0, 8192, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B0FF40[] = {
    VTX(-128, -16, 0, 0, 2048, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(-128, -48, 0, 0, 3072, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -48, 0, 2048, 3072, 0xFF, 0xFF, 0xFF, 0xFF), VTX(-64, -16, 0, 2048, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -16, 0, 2048, 2048, 0xFF, 0xFF, 0xFF, 0xFF), VTX(-64, -48, 0, 2048, 3072, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -48, 0, 4096, 3072, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(0, -16, 0, 4096, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -16, 0, 4096, 2048, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(0, -48, 0, 4096, 3072, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -48, 0, 6144, 3072, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(64, -16, 0, 6144, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -16, 0, 6144, 2048, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(64, -48, 0, 6144, 3072, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, -48, 0, 8192, 3072, 0xFF, 0xFF, 0xFF, 0xFF), VTX(128, -16, 0, 8192, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B10040[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B0FD40, 16, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 64, 0, 127, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 128, 0, 191, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 192, 0, 255, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPVertex(D_84B0FE40, 16, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 0, 32, 63, 63, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 64, 32, 127, 63, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 128, 32, 191, 63, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 192, 32, 255, 63, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPVertex(D_84B0FF40, 16, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 0, 64, 63, 95, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 64, 64, 127, 95, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 128, 64, 191, 95, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 192, 64, 255, 95, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B10378[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, 0x84B0FD40, 0x05000000, 0x22010000,
    0x00000000, 0x08000000, func_84B03A10, D_84B10040, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84B103B0[] = {
    VTX(-100, 14, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(-36, 14, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-36, 14, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF), VTX(36, 14, 0, 4352, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(36, 14, 0, 4352, 0, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(100, 14, 0, 6400, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B10410[] = {
    VTX(-100, -14, 0, 0, 896, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(-36, -14, 0, 2048, 896, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-36, -14, 0, 2048, 896, 0xFF, 0xFF, 0xFF, 0xFF), VTX(36, -14, 0, 4352, 896, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(36, -14, 0, 4352, 896, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(100, -14, 0, 6400, 896, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B10470[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIM_LOD_FRAC, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B103B0, 6, 0),
    gsSPEndDisplayList(),
};
static Gfx D_84B10498[] = {
    gsSPVertex(D_84B10410, 6, 6),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 200, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0, 0, 0x00FC, 0x006C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x00FC, 0x006C),
    gsSP2Triangles(0, 6, 7, 0, 0, 7, 1, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 200, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 9, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0x0100, 0, 0x021C, 0x006C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 9, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0x0100, 0, 0x021C, 0x006C),
    gsSP2Triangles(2, 8, 9, 0, 2, 9, 3, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 200, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0x0220, 0, 0x031C, 0x006C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0x0220, 0, 0x031C, 0x006C),
    gsSP2Triangles(4, 10, 11, 0, 4, 11, 5, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B10568[] = {
    0x17000000, 0x0000000C, 0x00000000, 0x00000000, D_84B103B0, 0x05000000, 0x1B000000, 0x00000000,
    0x00000000, 0x00120000, 0x05000000, 0x22050000, D_84B10470, 0x06000000, 0x06000000, 0x01000000,
};
static u32 D_84B105A8[] = {
    0x17000000,    0x0000000C, 0x00000000, 0x00000000, D_84B103B0, 0x05000000, 0x1B000000,
    0x00000000,    0x00000000, 0x00120000, 0x05000000, 0x22050000, 0x00000000, 0x08000000,
    func_84B03AB4, D_84B10498, 0x06000000, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84B105F8[] = {
    VTX(86, 14, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(114, 14, 0, 896, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-114, 14, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(-50, 14, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-50, 14, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF), VTX(22, 14, 0, 4352, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(22, 14, 0, 4352, 0, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(86, 14, 0, 6400, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B10678[] = {
    VTX(86, -14, 0, 0, 896, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(114, -14, 0, 896, 896, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-114, -14, 0, 0, 896, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(-50, -14, 0, 2048, 896, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-50, -14, 0, 2048, 896, 0xFF, 0xFF, 0xFF, 0xFF), VTX(22, -14, 0, 4352, 896, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(22, -14, 0, 4352, 896, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(86, -14, 0, 6400, 896, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B106F8[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B105F8, 8, 0),
    gsSPEndDisplayList(),
};
static Gfx D_84B10718[] = {
    gsSPVertex(D_84B10678, 8, 8),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, PRIM_LOD_FRAC, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsDPLoadTextureBlock(D_3027890, G_IM_FMT_RGBA, G_IM_SIZ_16b, 28, 28, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 8, 9, 0, 0, 9, 1, 0),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIM_LOD_FRAC, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 200, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0, 0, 0x00FC, 0x006C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x00FC, 0x006C),
    gsSP2Triangles(2, 10, 11, 0, 2, 11, 3, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 200, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 9, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0x0100, 0, 0x021C, 0x006C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 9, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0x0100, 0, 0x021C, 0x006C),
    gsSP2Triangles(4, 12, 13, 0, 4, 13, 5, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 200, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0x0220, 0, 0x031C, 0x006C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0x0220, 0, 0x031C, 0x006C),
    gsSP2Triangles(6, 14, 15, 0, 6, 15, 7, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B10838[] = {
    0x17000000, 0x00000010, 0x00000000, 0x00000000, D_84B105F8, 0x05000000, 0x1B000000, 0x00000000,
    0x00000000, 0x00120000, 0x05000000, 0x22050000, D_84B106F8, 0x06000000, 0x06000000, 0x01000000,
};
static u32 D_84B10878[] = {
    0x17000000,    0x00000010, 0x00000000, 0x00000000, D_84B105F8, 0x05000000, 0x1B000000,
    0x00000000,    0x00000000, 0x00120000, 0x05000000, 0x22050000, 0x00000000, 0x08000000,
    func_84B03AB4, D_84B10718, 0x06000000, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84B108C8[] = {
    VTX(-76, 10, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(0, 10, 0, 2432, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 10, 0, 2432, 0, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(76, 10, 0, 4864, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-76, -10, 0, 0, 640, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, -10, 0, 2432, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -10, 0, 2432, 640, 0xFF, 0xFF, 0xFF, 0xFF), VTX(76, -10, 0, 4864, 640, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B10948[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIM_LOD_FRAC, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B108C8, 8, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 152, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 10, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0, 0, 0x012C, 0x004C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 10, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x012C, 0x004C),
    gsSP2Triangles(0, 4, 5, 0, 0, 5, 1, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 152, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 10, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0x0130, 0, 0x025C, 0x004C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 10, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0x0130, 0, 0x025C, 0x004C),
    gsSP2Triangles(2, 6, 7, 0, 2, 7, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B109F0[] = {
    0x17000000,    0x00000008, 0x00000000, 0x00000000, D_84B108C8, 0x05000000, 0x1B000000,
    0x00000000,    0x00000000, 0x00020000, 0x05000000, 0x22050000, 0x00000000, 0x08000000,
    func_84B03C20, D_84B10948, 0x06000000, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84B10A40[] = {
    VTX(-100, 14, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-36, 14, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-36, 14, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(36, 14, 0, 4352, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(36, 14, 0, 4352, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(100, 14, 0, 6400, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-100, -14, 0, 0, 896, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(-36, -14, 0, 2048, 896, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-36, -14, 0, 2048, 896, 0xFF, 0xFF, 0xFF, 0xFF), VTX(36, -14, 0, 4352, 896, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(36, -14, 0, 4352, 896, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(100, -14, 0, 6400, 896, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B10B00[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIM_LOD_FRAC, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B10A40, 12, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 200, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0, 0, 0x00FC, 0x006C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x00FC, 0x006C),
    gsSP2Triangles(0, 6, 7, 0, 0, 7, 1, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 200, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 9, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0x0100, 0, 0x021C, 0x006C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 9, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0x0100, 0, 0x021C, 0x006C),
    gsSP2Triangles(2, 8, 9, 0, 2, 9, 3, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 200, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0x0220, 0, 0x031C, 0x006C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0x0220, 0, 0x031C, 0x006C),
    gsSP2Triangles(4, 10, 11, 0, 4, 11, 5, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B10BE8[] = {
    0x17000000, 0x0000000C,    0x00000000, 0x00000000,    D_84B10A40, 0x05000000, 0x1B000000, 0x00000000,
    0x00000000, 0xFFEE0000,    0x08000000, func_84B03CC4, 0x00000000, 0x05000000, 0x22050000, 0x00000000,
    0x08000000, func_84B03B58, D_84B10B00, 0x06000000,    0x06000000, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84B10C48[] = {
    VTX(-64, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(0, 16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(64, 16, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, -16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(64, -16, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B10CC8[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIM_LOD_FRAC, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B10C48, 8, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 128, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0, 0, 0x00FC, 0x007C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x00FC, 0x007C),
    gsSP2Triangles(0, 4, 5, 0, 0, 5, 1, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 128, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0x0100, 0, 0x01FC, 0x007C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0x0100, 0, 0x01FC, 0x007C),
    gsSP2Triangles(2, 6, 7, 0, 2, 7, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B10D70[] = {
    0x17000000, 0x00000008,    0x00000000, 0x00000000,    D_84B10C48, 0x05000000, 0x1B000000, 0x00000000,
    0x00000000, 0xFFEE0000,    0x08000000, func_84B03CC4, 0x00000000, 0x05000000, 0x22050000, 0x00000000,
    0x08000000, func_84B03B58, D_84B10CC8, 0x06000000,    0x06000000, 0x06000000, 0x01000000, 0x00000000,
};
static Gfx D_84B10DD0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIM_LOD_FRAC, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B10C48, 8, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 128, 0x0302FA70),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0, 0, 0x00FC, 0x007C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x00FC, 0x007C),
    gsSP2Triangles(0, 4, 5, 0, 0, 5, 1, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 128, 0x0302FA70),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0x0100, 0, 0x01FC, 0x007C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0x0100, 0, 0x01FC, 0x007C),
    gsSP2Triangles(2, 6, 7, 0, 2, 7, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B10E78[] = {
    0x17000000, 0x00000008, 0x00000000, 0x00000000, D_84B10C48, 0x05000000, 0x1B000000, 0x00000000,
    0x00000000, 0xFFEE0000, 0x05000000, 0x22050000, D_84B10DD0, 0x06000000, 0x06000000, 0x01000000,
};
static Vtx D_84B10EB8[] = {
    VTX(-80, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),        VTX(-16, 16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(48, 16, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(48, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),         VTX(80, 16, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-80, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(-16, -16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, -16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(48, -16, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(48, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(80, -16, 0, 1024, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B10F78[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIM_LOD_FRAC, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B10EB8, 12, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 128, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0, 0, 0x00FC, 0x007C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x00FC, 0x007C),
    gsSP2Triangles(0, 6, 7, 0, 0, 7, 1, 0),
    gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 128, 0x0F000000),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 0x0100, 0, 0x01FC, 0x007C),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0x0100, 0, 0x01FC, 0x007C),
    gsSP2Triangles(2, 8, 9, 0, 2, 9, 3, 0),
    gsDPLoadTextureBlock(0x0E000000, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 10, 11, 0, 4, 11, 5, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B11060[] = {
    0x17000000, 0x0000000C,    0x00000000, 0x00000000,    D_84B10EB8, 0x05000000, 0x1B000000, 0x00000000,
    0x00000000, 0xFFEE0000,    0x08000000, func_84B03CC4, 0x00000000, 0x05000000, 0x22050000, 0x00000000,
    0x08000000, func_84B03B58, D_84B10F78, 0x06000000,    0x06000000, 0x01000000, 0x00000000, 0x00000000,
};
static Vtx D_84B110C0[] = {
    VTX(-32, 24, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 0, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 0, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(32, 24, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, -24, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -24, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 0, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-22, 22, 0, 128, 128, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(-22, 0, 0, 128, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(22, 0, 0, 1920, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(22, 22, 0, 1920, 128, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-22, 0, 0, 128, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-22, -22, 0, 128, 896, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(22, -22, 0, 1920, 896, 0xFF, 0xFF, 0xFF, 0xFF), VTX(22, 0, 0, 1920, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B111C0[] = {
    VTX(-32, 24, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 16, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-24, 16, 0, 256, 256, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(-24, 24, 0, 256, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, 24, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(24, 16, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 16, 0, 256, 256, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(32, 24, 0, 256, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-24, 24, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-24, 16, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, 16, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(24, 24, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-32, -24, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-24, -24, 0, 256, 256, 0xFF, 0xFF, 0xFF, 0xFF), VTX(-24, -16, 0, 256, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-24, -16, 0, 256, 0, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(-24, 16, 0, 256, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(24, -24, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -24, 0, 256, 256, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, -16, 0, 256, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-24, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-24, -24, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, -24, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(24, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(24, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -16, 0, 256, 0, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(32, 16, 0, 256, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B113C0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B110C0, 16, 0),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, COMBINED, COMBINED, 0, PRIM_LOD_FRAC, 0),
    gsDPLoadTextureBlock(D_3010800, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(D_3011400, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, SHADE, 0, 0, 0, COMBINED, COMBINED, 0, PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsDPLoadTextureBlock(0x0F001000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};
static Gfx D_84B114F8[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED,
                       COMBINED, 0, PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B111C0, 32, 0),
    gsDPLoadTextureBlock(D_3018780, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 3, 3, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(D_30187C0, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 3, 3, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsDPLoadTextureBlock(D_3018700, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 3, 3, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsDPLoadTextureBlock(D_3018740, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 3, 3, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
    gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B11640[] = {
    0x17000000, 0x00000000, 0x00000000, 0x00000000,    D_84B110C0, 0x05000000, 0x1B000000,    0x00000000,
    0x00000000, 0x00180000, 0x05000000, 0x22050000,    0x00000000, 0x08000000, func_84B05760, 0x00000000,
    0x22050000, 0x00000000, 0x08000000, func_84B05844, 0x00000000, 0x06000000, 0x1B000000,    0x00000000,
    0x00000000, 0xFFE80000, 0x05000000, 0x22050000,    0x00000000, 0x08000000, func_84B05760, 0x00000001,
    0x22050000, 0x00000000, 0x08000000, func_84B05844, 0x00000001, 0x06000000, 0x06000000,    0x01000000,
};
static Vtx D_84B116E0[] = {
    VTX(-32, 48, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, 16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, 48, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, -48, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -48, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, -16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B117A0[] = {
    VTX(-32, 48, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 40, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-24, 40, 0, 256, 256, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(-24, 48, 0, 256, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, 48, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(24, 40, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 40, 0, 256, 256, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(32, 48, 0, 256, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-24, 48, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-24, 40, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, 40, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(24, 48, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, -40, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-32, -48, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-24, -48, 0, 256, 256, 0xFF, 0xFF, 0xFF, 0xFF), VTX(-24, -40, 0, 256, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 40, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, -40, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-27, -40, 0, 160, 0, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(-27, 40, 0, 160, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, -40, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(24, -48, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -48, 0, 256, 256, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, -40, 0, 256, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-24, -40, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-24, -48, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, -48, 0, 0, 256, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(24, -40, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(27, 40, 0, 96, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(27, -40, 0, 96, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -40, 0, 256, 0, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(32, 40, 0, 256, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B119A0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B116E0, 20, 0),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, COMBINED, COMBINED, 0, PRIM_LOD_FRAC, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F001000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureBlock(0x0F002000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};
static Gfx D_84B11A88[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED,
                       COMBINED, 0, PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B117A0, 32, 0),
    gsDPLoadTextureBlock(D_3018780, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 3, 3, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(D_30187C0, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 3, 3, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsDPLoadTextureBlock(D_3018700, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 3, 3, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsDPLoadTextureBlock(D_3018740, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 3, 3, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
    gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B11BD0[] = {
    0x17000000,    0x00000000, 0x00000000, 0x00000000, D_84B116E0, 0x05000000,    0x22050000, 0x00000000, 0x08000000,
    func_84B05A2C, D_84B119A0, 0x22050000, 0x00000000, 0x08000000, func_84B05B04, D_84B11A88, 0x06000000, 0x01000000,
};

s32 func_84B03A10(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B259E8* temp_a0;

    if (arg0 == 5) {
        temp_a0 = (unk_D_84B259E8*)D_8006F09C->unk_000.unk_14;

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)temp_a0->unk_0C & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }
    return 0;
}

s32 func_84B03AB4(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B259E8* temp_a0;

    if (arg0 == 5) {
        temp_a0 = (unk_D_84B259E8*)D_8006F09C->unk_000.unk_14;

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)temp_a0->unk_10[0] & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }
    return 0;
}

s32 func_84B03B58(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B259E8* temp_a0;

    if (arg0 == 5) {
        temp_a0 = (unk_D_84B259E8*)D_8006F09C->unk_000.unk_14;

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)temp_a0->unk_10[2] & 0x1FFFFFFF);
        gSPSegment(gDisplayListHead++, 0x0E, (u32)temp_a0->unk_10[3] & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }
    return 0;
}

s32 func_84B03C20(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B259E8* temp_a0;

    if (arg0 == 5) {
        temp_a0 = (unk_D_84B259E8*)D_8006F09C->unk_000.unk_14;

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)temp_a0->unk_10[1] & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }
    return 0;
}

s32 func_84B03CC4(s32 arg0, unk_D_86002F34_alt5* arg1) {
    unk_D_84B259A8* temp_a0;

    if (arg0 == 2) {
        temp_a0 = (unk_D_84B259A8*)D_8006F09C->unk_000.unk_14;

        arg1->unk_24.z = temp_a0->unk_02[(D_8006F09C->unk_0A6 - temp_a0->unk_20->unk_0A6) - 9];
    }
    return 0;
}

void func_84B03D08(unk_D_84B259A8* arg0, s16 arg1) {
    if (arg1 == 0) {
        func_8004DF94(0x01100001, 0, 0);
    }

    if (arg1 < 0xA) {
        arg0->unk_20->unk_024.x = (arg1 << 5) - 0x120;
    }
}

void func_84B03D74(unk_D_84B259A8* arg0, s16 arg1) {
    s32 i;

    if (arg1 == 2) {
        func_8004DF94(0x01100002, 0, 0);
    }

    for (i = 1; i < 7; i += 2) {
        arg0->unk_20[i].unk_024 = arg0->unk_20[2 + i].unk_024;
        arg0->unk_20[1 + i].unk_024 = arg0->unk_20[3 + i].unk_024;

        arg0->unk_20[i].unk_030 = arg0->unk_20[2 + i].unk_030;
        arg0->unk_20[1 + i].unk_030 = arg0->unk_20[3 + i].unk_030;
    }

    if (arg1 < 0x12) {
        arg0->unk_20[7].unk_024.x = (arg1 * 0x14) - 0x154;
    }

    if (arg1 < 0x10) {
        arg0->unk_20[8].unk_024.x = (arg1 * 0x14) - 0x12C;
    }

    if ((arg1 >= 0x12) && (arg1 < 0x2B)) {
        arg0->unk_20[7].unk_024.x = SINS((arg1 * 0x1555) + 0xFFFE955B) * (s16)(0x54 - (arg1 * 2));
    }
}

void func_84B03F10(unk_D_84B259A8* arg0, s16 arg1) {
    s32 i;

    if (arg1 == 2) {
        func_8004DF94(0x01100002, 0, 0);
    }

    for (i = 1; i < 7; i += 2) {
        arg0->unk_20[i].unk_024 = arg0->unk_20[2 + i].unk_024;
        arg0->unk_20[1 + i].unk_024 = arg0->unk_20[3 + i].unk_024;

        arg0->unk_20[i].unk_030 = arg0->unk_20[2 + i].unk_030;
        arg0->unk_20[1 + i].unk_030 = arg0->unk_20[3 + i].unk_030;
    }

    if (arg1 < 0xF) {
        arg0->unk_20[7].unk_024.x = (arg1 * 0x18) - 0x150;
    }

    if (arg1 < 0xD) {
        arg0->unk_20[8].unk_024.x = (arg1 * 0x18) - 0x120;
    }

    if ((arg1 >= 0xF) && (arg1 < 0x28)) {
        arg0->unk_20[7].unk_024.x = SINS((arg1 * 0x1555) + 0xFFFED55A) * (s16)(0x4E - (arg1 * 2));
    }
}

void func_84B040AC(unk_D_84B259A8* arg0, s16 arg1) {
    UNUSED s32 pad;
    s32 i;

    if (arg1 == 0) {
        func_8004DF94(0x01100003, 0, 0);
    }

    if (arg1 == 0x10) {
        func_8004DF94(0x01100004, 0, 0);
    }

    for (i = 0; i < 3; i++) {
        arg0->unk_20[9 + i].unk_024 = arg0->unk_20[10 + i].unk_024;
        arg0->unk_20[9 + i].unk_030 = arg0->unk_20[10 + i].unk_030;

        arg0->unk_02[i] = arg0->unk_02[i + 1];

        arg0->unk_20[13 + i].unk_024 = arg0->unk_20[14 + i].unk_024;
        arg0->unk_20[13 + i].unk_030 = arg0->unk_20[14 + i].unk_030;
    }

    if (arg1 < 0x12) {
        f32 sp28 = (arg1 + 1) * 0.0625f;
        s32 sp24 = (arg1 << 0xC) - 0x1000;

        arg0->unk_02[3] = sp24;
        arg0->unk_20[12].unk_024.x = 0.0f;
        arg0->unk_20[16].unk_024.x = 0.0f;

        func_8000E88C(&arg0->unk_20[12].unk_030, sp28, sp28, sp28);
        func_8000E88C(&arg0->unk_20[16].unk_030, sp28, sp28, sp28);
        if (sp24 >= 0xF000) {
            func_8000E88C(&arg0->unk_20[7].unk_030, sp28, sp28, sp28);
            func_8000E88C(&arg0->unk_20[8].unk_030, sp28, sp28, sp28);
        }
    } else if (arg1 < 0x1F) {
        f32 sp2C = (SINS((arg1 << 0xD) + 0xFFFE0000) * ((0x12C - (arg1 * 0xA)) / 1000.0f)) + 1.0f;

        func_8000E88C(&arg0->unk_20[7].unk_030, sp2C, sp2C, sp2C);
        func_8000E88C(&arg0->unk_20[8].unk_030, sp2C, sp2C, sp2C);
        func_8000E88C(&arg0->unk_20[12].unk_030, sp2C, sp2C, sp2C);
        func_8000E88C(&arg0->unk_20[16].unk_030, sp2C, sp2C, sp2C);
    }
}

void func_84B04364(unk_D_84B259A8* arg0, s16 arg1) {
    UNUSED s32 pad;
    s32 i;

    if (arg1 == 0) {
        func_8004DF94(0x01100003, 0, 0);
    }

    if (arg1 == 0xD) {
        func_8004DF94(0x01100004, 0, 0);
    }

    for (i = 0; i < 3; i++) {
        arg0->unk_20[9 + i].unk_024 = arg0->unk_20[10 + i].unk_024;
        arg0->unk_20[9 + i].unk_030 = arg0->unk_20[10 + i].unk_030;

        arg0->unk_02[i] = arg0->unk_02[i + 1];

        arg0->unk_20[13 + i].unk_024 = arg0->unk_20[14 + i].unk_024;
        arg0->unk_20[13 + i].unk_030 = arg0->unk_20[14 + i].unk_030;
    }

    if (arg1 < 0xF) {
        f32 sp28 = (arg1 + 1) / 13.0f;
        s32 sp24 = (arg1 * 0x1333) - 0xCCA;

        arg0->unk_02[3] = sp24;
        arg0->unk_20[12].unk_024.x = 0.0f;
        arg0->unk_20[16].unk_024.x = 0.0f;

        func_8000E88C(&arg0->unk_20[12].unk_030, sp28, sp28, sp28);
        func_8000E88C(&arg0->unk_20[16].unk_030, sp28, sp28, sp28);

        if (sp24 >= 0xECCD) {
            func_8000E88C(&arg0->unk_20[7].unk_030, sp28, sp28, sp28);
            func_8000E88C(&arg0->unk_20[8].unk_030, sp28, sp28, sp28);
        }
    } else if (arg1 < 0x1C) {
        f32 sp2C = (SINS((arg1 << 0xD) + 0xFFFE6000) * ((0x10E - (arg1 * 0xA)) / 1000.0f)) + 1.0f;

        func_8000E88C(&arg0->unk_20[7].unk_030, sp2C, sp2C, sp2C);
        func_8000E88C(&arg0->unk_20[8].unk_030, sp2C, sp2C, sp2C);
        func_8000E88C(&arg0->unk_20[12].unk_030, sp2C, sp2C, sp2C);
        func_8000E88C(&arg0->unk_20[16].unk_030, sp2C, sp2C, sp2C);
    }
}

void func_84B04628(unk_D_84B259A8* arg0) {
    s32 i;

    if (osTvType == OS_TV_PAL) {
        if (arg0->unk_01 >= 0) {
            func_84B03D08(arg0, arg0->unk_01);
        }

        if (arg0->unk_01 >= 2) {
            func_84B03F10(arg0, arg0->unk_01 - 2);
        }

        if (arg0->unk_01 >= 0x1B) {
            func_84B04364(arg0, arg0->unk_01 - 0x1B);
        }
    } else {
        if (arg0->unk_01 >= 0) {
            func_84B03D08(arg0, arg0->unk_01);
        }

        if (arg0->unk_01 >= 2) {
            func_84B03D74(arg0, arg0->unk_01 - 2);
        }

        if (arg0->unk_01 >= 0x1E) {
            func_84B040AC(arg0, arg0->unk_01 - 0x1E);
        }
    }

    if (arg0->unk_01 == 0xDC) {
        for (i = 0; i < 17; i++) {
            arg0->unk_20[i].unk_024.x = -320.0f;
        }
    }

    arg0->unk_01++;
}

void func_84B04798(unk_D_84B259A8* arg0) {
    s32 i;

    if (arg0->unk_01++ == 0) {
        func_8004DF94(0x01100005, 0, 0);
    }

    for (i = 0; i < 5; i += 2) {
        arg0->unk_20[1 + i].unk_024 = arg0->unk_20[3 + i].unk_024;
        arg0->unk_20[2 + i].unk_024 = arg0->unk_20[4 + i].unk_024;
    }

    for (i = 0; i < 3; i++) {
        arg0->unk_20[9 + i].unk_024 = arg0->unk_20[10 + i].unk_024;
        arg0->unk_20[13 + i].unk_024 = arg0->unk_20[14 + i].unk_024;
    }

    arg0->unk_20[0].unk_024.x += 32.0f;
    arg0->unk_20[7].unk_024.x += 32.0f;
    arg0->unk_20[8].unk_024.x += 32.0f;
    arg0->unk_20[12].unk_024.x += 32.0f;
    arg0->unk_20[16].unk_024.x += 32.0f;

    if (arg0->unk_20->unk_024.x >= 416.0f) {
        for (i = 0; i < 17; i++) {
            func_84B00404(&arg0->unk_20[i]);
        }
        arg0->unk_00 = 0;
    }
}

void func_84B0492C(unk_D_84B259A8* arg0) {
    s32 i;

    if (arg0->unk_01 == 0) {
        func_8004DF94(0x01100001, 0, 0);
        func_8004DF94(0x01100002, 0, 0);
    }

    for (i = 0; i < 5; i += 2) {
        arg0->unk_20[1 + i].unk_024 = arg0->unk_20[3 + i].unk_024;
        arg0->unk_20[2 + i].unk_024 = arg0->unk_20[4 + i].unk_024;
    }

    for (i = 0; i < 3; i++) {
        arg0->unk_20[9 + i].unk_024 = arg0->unk_20[10 + i].unk_024;
    }

    if (arg0->unk_01 < 0xA) {
        arg0->unk_20[0].unk_024.x += 32.0f;
        arg0->unk_20[7].unk_024.x -= 32.0f;
        arg0->unk_20[8].unk_024.x -= 32.0f;
        arg0->unk_20[12].unk_024.x -= 32.0f;
    }

    if (arg0->unk_01 == 0x20) {
        arg0->unk_00 = 0;
    }
    arg0->unk_01++;
}

void func_84B04A7C(unk_D_84B259A8* arg0) {
    switch (arg0->unk_00) {
        case 1:
            func_84B04628(arg0);
            break;

        case 3:
            func_84B04798(arg0);
            break;

        case 2:
            func_84B0492C(arg0);
            break;
    }
}

void func_84B04AE4(unk_D_84B259A8* arg0, s16 arg1, s16 arg2) {
    func_8001BC34(arg0->unk_20, 0, 0, arg0->unk_24);
    func_8000E88C(&arg0->unk_20->unk_024, arg1, arg2, -289.0f);
}

void func_84B04B5C(unk_D_84B259A8* arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 temp_s0;
    s16 sp2C;

    if (arg1 == 3) {
        sp2C = 1;
    } else {
        sp2C = 0;
    }
    temp_s0 = (arg1 * 2) + 1;
    if (sp2C) {}

    func_8001BC34(&arg0->unk_20[temp_s0], sp2C, 0, arg0->unk_28);
    func_8001BC34(&arg0->unk_20[temp_s0 + 1], sp2C, 0, arg0->unk_2C);
    func_8000E88C(&arg0->unk_20[temp_s0].unk_024, arg2, arg3, -289.0f);
    func_8000E88C(&arg0->unk_20[temp_s0 + 1].unk_024, arg2, arg3, -289.0f);

    if (arg1 == 3) {
        arg0->unk_20[temp_s0].unk_01D = 0xFF;
        arg0->unk_20[temp_s0 + 1].unk_01D = 0xFF;
    } else {
        arg0->unk_20[temp_s0].unk_01D = (arg1 * 0x28) + 0x50;
        arg0->unk_20[temp_s0 + 1].unk_01D = (arg1 * 0x28) + 0x50;
    }
}

void func_84B04CCC(unk_D_84B259A8* arg0, s16 arg1) {
    s16 temp_v1 = arg1 + 9;
    s16 var_a1;

    if (arg1 == 3) {
        var_a1 = 1;
    } else {
        var_a1 = 0;
    }

    func_8001BC34(&arg0->unk_20[temp_v1], var_a1, 0, arg0->unk_30);
    func_8000E88C(&arg0->unk_20[temp_v1].unk_024, -320.0f, 48.0f, -289.0f);

    if (arg1 == 3) {
        arg0->unk_20[temp_v1].unk_01D = 0xFF;
    } else {
        arg0->unk_20[temp_v1].unk_01D = (arg1 * 0x28) + 0x50;
    }
}

void func_84B04DB0(unk_D_84B259A8* arg0, s16 arg1) {
    s16 temp_v1 = arg1 + 9;
    s16 var_a1;

    if (arg1 == 3) {
        var_a1 = 1;
    } else {
        var_a1 = 0;
    }

    func_8001BC34(&arg0->unk_20[temp_v1], var_a1, 0, arg0->unk_38);
    func_8000E88C(&arg0->unk_20[temp_v1].unk_024, 320.0f, 0.0f, -289.0f);

    if (arg1 == 3) {
        arg0->unk_20[temp_v1].unk_01D = 0xFF;
    } else {
        arg0->unk_20[temp_v1].unk_01D = (arg1 * 0x28) + 0x50;
    }
}

void func_84B04E94(unk_D_84B259A8* arg0, s16 arg1) {
    s16 temp_v1 = arg1 + 0xD;
    s16 var_a1;

    if (arg1 == 3) {
        var_a1 = 1;
    } else {
        var_a1 = 0;
    }

    func_8001BC34(&arg0->unk_20[temp_v1], var_a1, 0, arg0->unk_34);
    func_8000E88C(&arg0->unk_20[temp_v1].unk_024, -320.0f, 48.0f, -289.0f);

    if (arg1 == 3) {
        arg0->unk_20[temp_v1].unk_01D = 0xFF;
    } else {
        arg0->unk_20[temp_v1].unk_01D = (arg1 * 0x28) + 0x50;
    }
}

void func_84B04F78(unk_D_84B259A8* arg0, unk_D_86002F58_004_000* arg1) {
    s32 i;

    arg0->unk_20 = arg1;
    arg0->unk_01 = 0;
    arg0->unk_00 = 1;
    func_84B04AE4(arg0, -0x140, 0x30);

    for (i = 0; i < 4; i++) {
        func_84B04B5C(arg0, i, -0x140, 0x30);
        func_84B04CCC(arg0, i);
        if ((D_800AE540.unk_0000 == 3) || (D_800AE540.unk_0000 == 6)) {
            func_84B04E94(arg0, i);
        }
    }

    for (i = 0; i < 17; i++) {
        arg0->unk_20[i].unk_000.unk_14 = arg0;
    }
}

void func_84B0509C(unk_D_84B259A8* arg0) {
    arg0->unk_01 = 0;
    arg0->unk_00 = 3;
}

void func_84B050AC(unk_D_84B259A8* arg0, unk_D_86002F58_004_000* arg1) {
    s32 i;

    arg0->unk_20 = arg1;
    arg0->unk_01 = 0;
    arg0->unk_00 = 2;
    func_84B04AE4(arg0, -0x140, 0);

    for (i = 0; i < 4; i++) {
        func_84B04B5C(arg0, i, 0x140, 0);
        func_84B04DB0(arg0, i);
    }

    for (i = 0; i < 13; i++) {
        arg0->unk_20[i].unk_000.unk_14 = arg0;
    }
}

void func_84B05184(unk_D_84B259A8* arg0) {
    BinArchive* temp_a0 = ASSET_LOAD2(battle_headers, 1, 1);

    if (D_800AE540.unk_0000 == 7) {
        arg0->unk_0C = func_8000484C(temp_a0, D_84B0FC48[D_800AE540.unk_0002]);
        arg0->unk_10 = Util_ConvertAddrToVirtAddr(D_84B0FC6C[D_800AE540.unk_0002]);

        switch (D_800AE540.unk_0002) {
            default:
                if (D_800AE540.unk_0003 == 4) {
                    arg0->unk_18 = Util_ConvertAddrToVirtAddr(D_302CA70);
                } else {
                    arg0->unk_18 = Util_ConvertAddrToVirtAddr(D_302BA70);
                }
                break;

            case 8:
                arg0->unk_18 = Util_ConvertAddrToVirtAddr(D_302DA70);
                break;

            case 9:
                arg0->unk_18 = Util_ConvertAddrToVirtAddr(D_302EA70);
                break;
        }
    } else {
        arg0->unk_0C = func_8000484C(temp_a0, D_84B0FC40[D_800AE540.unk_0000 - 1]);
        arg0->unk_10 = Util_ConvertAddrToVirtAddr(D_84B0FC54[D_800AE540.unk_0000 - 1]);
        arg0->unk_14 = Util_ConvertAddrToVirtAddr(D_84B0FCAC[D_800AE540.unk_0002]);

        switch (D_800AE540.unk_0003) {
            default:
                arg0->unk_18 = Util_ConvertAddrToVirtAddr(D_302AA70);
                break;

            case 7:
                arg0->unk_18 = Util_ConvertAddrToVirtAddr(D_30497F0);
                break;

            case 8:
                arg0->unk_18 = Util_ConvertAddrToVirtAddr(D_3048210);
                break;
        }
    }

    if (D_800AE540.unk_0003 < 7) {
        arg0->unk_1C = Util_ConvertAddrToVirtAddr(D_84B0FC90[D_800AE540.unk_0003]);
    }
}

void func_84B0535C(unk_D_84B259A8* arg0) {
    unk_D_86002F34* ptr;
    s32 var_v0;
    s32 var_v1;
    u8* var_a0;
    u8* var_a1;
    Vtx* temp_a3;
    s32 i;

    var_v0 = -1;
    var_v1 = 1;
    var_a1 = (u8*)arg0->unk_10 + 0xC7;
    ptr = arg0->unk_28;
    temp_a3 = ptr->unk_20;

    while (var_v1 != 0) {
        var_a0 = var_a1;
        for (i = 0; i < 28; i++) {
            if (*var_a0 & 0xF) {
                var_v1 = 0;
                break;
            }
            var_a0 += 0xC8;
        }
        var_v0++;
        var_a1--;
    }

    temp_a3[0].v.ob[0] = (temp_a3[0].v.ob[0] - var_v0) + 4;
    temp_a3[1].v.ob[0] = (temp_a3[1].v.ob[0] - var_v0) + 4;
    temp_a3[8].v.ob[0] = (temp_a3[8].v.ob[0] - var_v0) + 4;
    temp_a3[9].v.ob[0] = (temp_a3[9].v.ob[0] - var_v0) + 4;
}

void func_84B053F4(unk_D_84B259A8* arg0) {
    MemoryBlock* temp_v0;

    temp_v0 = func_80002D10(main_pool_get_available(), 0);
    arg0->unk_24 = process_geo_layout(temp_v0, D_84B10378);
    arg0->unk_38 = process_geo_layout(temp_v0, D_84B10E78);
    arg0->unk_34 = process_geo_layout(temp_v0, D_84B109F0);
    if (D_800AE540.unk_11F2 == 0) {
        arg0->unk_28 = process_geo_layout(temp_v0, D_84B10568);
        arg0->unk_2C = process_geo_layout(temp_v0, D_84B105A8);
    } else {
        arg0->unk_28 = process_geo_layout(temp_v0, D_84B10838);
        arg0->unk_2C = process_geo_layout(temp_v0, D_84B10878);
        func_84B0535C(arg0);
    }

    if (D_800AE540.unk_0000 == 7) {
        switch (D_800AE540.unk_0002) {
            default:
                if (D_800AE540.unk_0003 < 4) {
                    arg0->unk_30 = process_geo_layout(temp_v0, D_84B11060);
                } else {
                    arg0->unk_30 = process_geo_layout(temp_v0, D_84B10D70);
                }
                break;

            case 8:
                arg0->unk_30 = process_geo_layout(temp_v0, D_84B11060);
                break;

            case 9:
                arg0->unk_30 = process_geo_layout(temp_v0, D_84B10D70);
                break;
        }
    } else if (D_800AE540.unk_0003 < 7) {
        arg0->unk_30 = process_geo_layout(temp_v0, D_84B11060);
    } else {
        arg0->unk_30 = process_geo_layout(temp_v0, D_84B10BE8);
    }
    func_80002D60(temp_v0);
}

void func_84B055B8(unk_D_86002F34* arg0, Color_RGBA8* arg1, Color_RGBA8* arg2) {
    Vtx* var_v0 = arg0->unk_20;
    s16 temp_v1 = arg0->unk_26 / 2;
    s16 i;

    for (i = 0; i < temp_v1; i++, var_v0++) {
        var_v0->v.cn[0] = arg1->r;
        var_v0->v.cn[1] = arg1->g;
        var_v0->v.cn[2] = arg1->b;
        var_v0->v.cn[3] = arg1->a;
    }

    for (i = 0; i < temp_v1; i++, var_v0++) {
        var_v0->v.cn[0] = arg2->r;
        var_v0->v.cn[1] = arg2->g;
        var_v0->v.cn[2] = arg2->b;
        var_v0->v.cn[3] = arg2->a;
    }
}

void func_84B05668(unk_D_84B259A8* arg0) {
    UNUSED s32 pad[2];
    s16 var_v1;

    var_v1 = D_800AE540.unk_0000 - 1;
    if (D_800AE540.unk_0000 == 7) {
        var_v1 += D_800AE540.unk_0002;
    }

    func_84B055B8(arg0->unk_28, &D_84B0FCBC[var_v1], &D_84B0FCFC[var_v1]);
    func_84B055B8(arg0->unk_34, &D_84B0FCFC[var_v1], &D_84B0FCFC[var_v1]);
    func_84B055B8(arg0->unk_30, &D_84B0FCFC[var_v1], &D_84B0FCBC[var_v1]);
    func_84B055B8(arg0->unk_38, &D_84B0FCFC[var_v1], &D_84B0FCBC[var_v1]);
}

void func_84B05728(unk_D_84B259A8* arg0) {
    arg0->unk_00 = 0;
    arg0->unk_01 = 0;
    func_84B05184(arg0);
    func_84B053F4(arg0);
    func_84B05668(arg0);
}

s32 func_84B05760(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B259E8* temp_a0;
    s32 tmp;
    s32 tmp2;

    if (arg0 == 5) {
        temp_a0 = (unk_D_84B259E8*)D_8006F09C->unk_000.unk_14;
        tmp = ((D_8006F09C->unk_0A6 - temp_a0->unk_08->unk_0A6) % 8) - 4;
        tmp2 = (arg1->unk_00.unk_14 * 4) + tmp;

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)temp_a0->unk_10[tmp2] & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, D_84B113C0);

        func_80015684();
    }
    return 0;
}

s32 func_84B05844(s32 arg0, unk_func_80011B94* arg1) {
    static s16 D_84B11C18 = 0;

    unk_D_84B259E8* temp_v0;
    s32 var_t1;
    s32 tmp;
    s32 tmp2;

    if (arg0 == 5) {
        temp_v0 = (unk_D_84B259E8*)D_8006F09C->unk_000.unk_14;
        tmp = ((D_8006F09C->unk_0A6 - temp_v0->unk_08->unk_0A6) % 8) - 4;
        tmp2 = tmp + arg1->unk_00.unk_14 * 4;

        if ((temp_v0->unk_02 != 0) && ((tmp2 + 1) == D_800AE540.unk_0003)) {
            // clang-format off
            if (D_84B11C18 >= 0) { var_t1 = (s32)(SINS((s32)(SINS(D_84B11C18) * 16384.0f)) * 127.0f) + 0x7F;
            } else {
                var_t1 = (s32)(SINS(D_84B11C18) * 127.0f) + 0x7F;
            }
            // clang-format on

            gDPPipeSync(gDisplayListHead++);
            gDPSetPrimColor(gDisplayListHead++, 0, D_8006F09C->unk_01D, 200, 200, 30, var_t1);
            gDPSetEnvColor(gDisplayListHead++, 200, 30, 30, var_t1);
            gSPDisplayList(gDisplayListHead++, D_84B114F8);

            func_80015684();
            D_84B11C18 += 0x800;
        }
    }
    return 0;
}

s32 func_84B05A2C(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B259E8* temp_a0;
    s32 tmp;

    if (arg0 == 5) {
        temp_a0 = (unk_D_84B259E8*)D_8006F09C->unk_000.unk_14;
        tmp = ((D_8006F09C->unk_0A6 - temp_a0->unk_08->unk_0A6) % 8) - 4;

        gDPPipeSync(gDisplayListHead++);

        gSPSegment(gDisplayListHead++, 0x0F, (u32)temp_a0->unk_30[tmp]->img_p & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }
    return 0;
}

s32 func_84B05B04(s32 arg0, unk_func_80011B94* arg1) {
    static s16 D_84B11C1C = 0;

    unk_D_84B259E8* temp_v0;
    s32 var_t1;
    s32 tmp;

    if (arg0 == 5) {
        temp_v0 = (unk_D_84B259E8*)D_8006F09C->unk_000.unk_14;
        tmp = ((D_8006F09C->unk_0A6 - temp_v0->unk_08->unk_0A6) % 8);
        tmp -= 4;

        if ((temp_v0->unk_02 != 0) && ((tmp + 1) == D_800AE540.unk_0003)) {
            // clang-format off
            if (D_84B11C1C >= 0) {                var_t1 = (s32)(SINS((s32)(SINS(D_84B11C1C) * 16384.0f)) * 127.0f)+ 0x7F;
            } else {
                var_t1 = (s32)(SINS(D_84B11C1C) * 127.0f) + 0x7F;
            }
            // clang-format on
            gDPPipeSync(gDisplayListHead++);

            gDPSetPrimColor(gDisplayListHead++, 0, D_8006F09C->unk_01D, 200, 200, 30, var_t1);
            gDPSetEnvColor(gDisplayListHead++, 200, 30, 30, var_t1);
            gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

            func_80015684();
            D_84B11C1C += 0x800;
        }
    }
    return 0;
}

void func_84B05CE0(s32 arg0) {
    unk_D_80068BB0 sp40;
    u32 sp3C = Util_ConvertAddrToVirtAddr(&D_3017F00);

    func_800062E4(&sp40, 0, 2, 0x40, 0x40, arg0);
    func_80006498(&gDisplayListHead, &sp40);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, 255, 50, 20, 160);

    func_8001CF10(0, 0, 0x40, 0x40, sp3C, 0x40, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84B05DD0(unk_D_84B259E8* arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_8001BCF0(&arg0->unk_08[i + 4]);
        func_84B00404(&arg0->unk_08[i + 12]);
        func_8001BC34(&arg0->unk_08[i + 4], 1, 0, arg0->unk_0C);
        arg0->unk_08[i + 4].unk_01E.x = 0;
        arg0->unk_08[i + 4].unk_000.unk_14 = arg0;
    }
}

void func_84B05E64(unk_D_84B259E8* arg0) {
    s32 i;

    arg0->unk_01++;

    for (i = 0; i < 4; i++) {
        arg0->unk_08[4 + i].unk_024.x = (0xE0 + i * 0x40) - (arg0->unk_01 << 5);
    }

    if (arg0->unk_01 == 0xA) {
        arg0->unk_01 = 0;
        arg0->unk_00 = 0;
    }
}

void func_84B05F18(unk_D_84B259E8* arg0) {
    s32 i;
    s32 var_v0;

    arg0->unk_01++;

    for (i = 0, var_v0 = -0x60; i < 4; i++, var_v0 += 0x40) {
        arg0->unk_08[4 + i].unk_024.x = (s16)var_v0 - (arg0->unk_01 << 5);
    }

    if (arg0->unk_01 == 0xA) {
        for (i = 0; i < 4; i++) {
            func_84B00404(&arg0->unk_08[4 + i]);
        }
        arg0->unk_01 = 0;
        arg0->unk_00 = 0;
    }
}

void func_84B05FCC(unk_D_84B259E8* arg0) {
    s32 i;
    s32 var_a2;

    arg0->unk_01++;
    if (arg0->unk_01 < 0x10) {
        for (i = 0; i < 4; i++) {
            arg0->unk_08[4 + i].unk_01E.x += 0x800;
            arg0->unk_08[12 + i].unk_01E.x += 0x800;
        }
    } else if (arg0->unk_01 == 0x10) {
        func_8004DF94(0x0110000C, 0, 0);
        func_84B05DD0(arg0);
    } else if (arg0->unk_01 == 0x20) {
        if (D_800AE540.unk_0000 == 7) {
            var_a2 = 4;
        } else {
            var_a2 = 8;
        }

        func_8004DF94(0x01100014, D_800AE540.unk_0003, var_a2);
        func_84B05CE0(arg0->unk_10[D_800AE540.unk_0003 - 1]);

        if (D_800AE540.unk_0000 == 7) {
            func_80006498(&gDisplayListHead, arg0->unk_30[D_800AE540.unk_0003 - 1]);

            gSPDisplayList(gDisplayListHead++, D_8006F4E0);

            func_8001C6AC(4, 0x24, 0x38, 0x1C, &arg0->unk_10[D_800AE540.unk_0003 - 1][0x208], 0x40, 0x200000);
            func_8001C6AC(4, 0x40, 0x38, 0x1C, &arg0->unk_10[D_800AE540.unk_0003 - 1][0x1008], 0x40, 0x200000);

            gSPDisplayList(gDisplayListHead++, D_8006F630);
        }

        arg0->unk_01 = 0;
        arg0->unk_00 = 0;
    }
}

void func_84B06204(unk_D_84B259E8* arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        arg0->unk_08[4 + i].unk_01E.x -= 0x800;
        arg0->unk_08[12 + i].unk_01E.x -= 0x800;
    }

    arg0->unk_01++;
    if (arg0->unk_01 == 0x10) {
        func_8004DF94(0x0110000C, 0, 0);
        func_84B05DD0(arg0);
        arg0->unk_01 = 0;
        arg0->unk_00 = 0;
    }
}

void func_84B062E4(unk_D_84B259E8* arg0) {
    switch (arg0->unk_00) {
        case 1:
            func_84B05E64(arg0);
            break;

        case 2:
            func_84B05F18(arg0);
            break;

        case 3:
            func_84B05FCC(arg0);
            break;

        case 4:
            func_84B06204(arg0);
            break;
    }
}

void func_84B06364(unk_D_84B259E8* arg0, unk_D_86002F58_004_000* arg1, s16 arg2) {
    s32 i;
    s16 var_s2;

    arg0->unk_08 = arg1;
    arg0->unk_01 = 0;

    if (arg2 == 0) {
        for (i = 4; i < 8; i++) {
            func_8001BC34(&arg0->unk_08[i], 1, 0, arg0->unk_0C);
            func_8000E88C(&arg0->unk_08[i].unk_024, 320.0f, -48.0f, -289.0f);
            arg0->unk_08[i].unk_000.unk_14 = (s32)arg0;
        }
        arg0->unk_00 = 1;
    } else {
        for (i = 12, var_s2 = -0x60; i < 16; i++) {
            func_8001BC34(&arg0->unk_08[i], 1, 0, arg0->unk_0C);
            func_8000E88C(&arg0->unk_08[i].unk_024, var_s2, -48.0f, -289.0f);
            arg0->unk_08[i].unk_01E.x = -0x8000;
            var_s2 += 0x40;
            arg0->unk_08[i].unk_000.unk_14 = arg0;
        }

        if (arg2 == 1) {
            arg0->unk_02 = 0;
            arg0->unk_00 = 3;
        } else {
            arg0->unk_02 = 1;
            arg0->unk_00 = 4;
        }
    }
}

void func_84B064FC(unk_D_84B259E8* arg0, s16 arg1, char* arg2) {
    func_80006498(&gDisplayListHead, arg0->unk_30[arg1]);

    gSPDisplayList(gDisplayListHead++, D_8006F4E0);

    func_8001C6AC(0, 0, 0x40, 0x20, D_3012000, 0x40, 0x200000);
    func_8001C6AC(0, 0x20, 0x40, 0x20, D_3013000, 0x40, 0x200000);
    func_8001C6AC(0, 0x40, 0x40, 0x20, D_3014000, 0x40, 0x200000);

    if ((D_800AE540.unk_0002 < 9) || (arg1 == 0)) {
        func_8001C6AC(4, 0x24, 0x38, 0x1C, arg0->unk_10[arg1] + 0x208, 0x40, 0x200000);
        func_8001C6AC(4, 0x40, 0x38, 0x1C, arg0->unk_10[arg1] + 0x1008, 0x40, 0x200000);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    if ((D_800AE540.unk_0002 < 9) || (arg1 == 0)) {
        s32 sp34 = func_8001F5B0(2, 0, arg2);

        func_8001F3F4();
        func_8001F3B4(0xC);
        func_8001EBE0(2, 0);
        func_8001F1E8(0x20 - (sp34 / 2), 6, arg2);
        func_8001F444();
    }
}

s32 func_84B06720(s32* arg0) {
    u32 temp_v0;
    s32 var_v1;
    s32 i;
    u32 sp1C;

    var_v1 = (s32)arg0;
    sp1C = 0x40 - ((u32)arg0 & 0x3F);
    if (sp1C != 0x40) {
        s32* sp24;
        s32* sp20;

        temp_v0 = main_pool_get_block_dist(arg0);
        sp24 = (u32)arg0 + temp_v0;
        sp20 = (u32)arg0 + (temp_v0 + sp1C);
        main_pool_realloc(arg0, (temp_v0 + sp1C));
        for (; arg0 < sp24;) {
            *--sp20 = *--sp24;
        }
        var_v1 += sp1C;
    }
    return var_v1;
}

void func_84B067B4(unk_D_84B259E8* arg0, BinArchive* arg1, BinArchive* arg2) {
    s16 i;
    s16 sp44;
    unk_func_84B067B4* temp_s5;
    unk_func_84B067B4* ptr;
    s16 tmp;

    switch (D_800AE540.unk_0000) {
        case 1:
            sp44 = 6;
            break;

        case 2:
            sp44 = 7;
            break;

        case 3:
            sp44 = D_800AE540.unk_0002 + 8;
            break;

        case 4:
            sp44 = 0;
            break;

        case 5:
            sp44 = 1;
            break;

        case 6:
            sp44 = D_800AE540.unk_0002 + 2;
            break;

        case 7:
            sp44 = D_800AE540.unk_0002 + 0xC;
            break;

        case 8:
            sp44 = 0x16;
            break;
    }

    if (D_800AE540.unk_11F2 != 0) {
        sp44 += 0x1F;
    }

    temp_s5 = func_8000484C(arg1, sp44);
    if (D_800AE540.unk_0000 == 7) {
        for (i = 0; i < 4; i++) {
            ptr = i + ((void)0, temp_s5);

            tmp = (ptr->unk_038 >> 8) & 0xFF;
            arg0->unk_10[i] = func_84B06720(func_8000484C(arg2, tmp));
            if (i < (D_800AE540.unk_0003 - 1)) {
                func_84B05CE0(arg0->unk_10[i]);
            }
            arg0->unk_30[i] = func_80006314(0, 2, 0x40, 0x60, 0);
            func_84B064FC(arg0, i, ptr->unk_010);
        }
    } else {
        for (i = 0; i < 8; i++) {
            if (i < D_800AE540.unk_0003) {
                tmp = (temp_s5[D_800AE540.unk_11E4[0][i]].unk_038 >> 8) & 0xFF;

                arg0->unk_10[i] = func_84B06720(func_8000484C(arg2, tmp));
                if (i < (D_800AE540.unk_0003 - 1)) {
                    func_84B05CE0(arg0->unk_10[i]);
                }
            } else {
                arg0->unk_10[i] = func_8000484C(arg2, 0);
            }
        }
    }
}

void func_84B06A54(unk_D_84B259E8* arg0, BinArchive* arg1, BinArchive* arg2) {
    s32 i;
    MemoryBlock* temp_v0;

    arg0->unk_00 = 0;
    arg0->unk_01 = 0;
    arg0->unk_02 = 1;
    arg0->unk_04 = 0;

    for (i = 0; i < 4; i++) {
        arg0->unk_30[i] = func_80006314(0, 2, 0x40, 0x60, 0);
    }

    temp_v0 = func_80002D10(main_pool_get_available(), 0);
    if (D_800AE540.unk_0000 == 7) {
        arg0->unk_0C = process_geo_layout(temp_v0, D_84B11BD0);
    } else {
        arg0->unk_0C = process_geo_layout(temp_v0, D_84B11640);
    }

    func_80002D60(temp_v0);
    func_84B067B4(arg0, arg1, arg2);
}
