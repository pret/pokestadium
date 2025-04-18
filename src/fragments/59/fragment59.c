#include "fragment59.h"
#include "src/12D80.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/232C0.h"
#include "src/26820.h"
#include "src/29BA0.h"
#include "src/2C1C0.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/DDC0.h"
#include "src/F420.h"
#include "src/geo_layout.h"
#include "src/math_util.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_84102450 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s8 unk_08;
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ s8 unk_0A;
    /* 0x0B */ s8 unk_0B;
} unk_D_84102450; // size = 0xC

typedef struct unk_D_84102498 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} unk_D_84102498; // size = 0xC

static char** D_84103440;
static BinArchive* D_84103444;
static void* D_84103448;
static void* D_8410344C;
static Vtx* D_84103450;
static GraphNode* D_84103454;
static unk_D_86002F58_004_000 D_84103458[6];
static s16 D_84103CC8;
static unk_D_80068BB0* D_84103CD0[6];
static GraphNode* D_84103CE8;
static GraphNode* D_84103CEC;
static unk_func_80027FA0 D_84103CF0;

static u8 D_84102430[] = {
    0x09, 0x07, 0x08, 0x0C, 0x0A, 0x0B,
};
static s16 D_84102438[] = { 3, 1, 2, 6, 4, 5 };
static s16 D_84102444[] = { 3, 1, 2, 6, 4, 5 };
static unk_D_84102450 D_84102450[] = {
    {
        244,
        70,
        152,
        114,
        -1,
        3,
        4,
        5,
    },
    {
        88,
        88,
        128,
        96,
        -1,
        -1,
        -1,
        -1,
    },
    {
        424,
        88,
        128,
        96,
        -1,
        -1,
        -1,
        -1,
    },
    {
        244,
        212,
        152,
        114,
        0,
        -1,
        4,
        5,
    },
    {
        88,
        150,
        128,
        96,
        0,
        3,
        -1,
        0,
    },
    {
        424,
        150,
        128,
        96,
        0,
        3,
        3,
        -1,
    },
};
static unk_D_84102498 D_84102498[] = {
    {
        0,
        260,
        140,
        32,
        -32768,
        0,
    },
    {
        0,
        298,
        140,
        32,
        16384,
        0,
    },
    {
        0,
        336,
        140,
        32,
        -16384,
        0,
    },
    {
        0,
        374,
        140,
        32,
        0,
        0,
    },
    {
        0,
        188,
        150,
        32,
        28672,
        0,
    },
    {
        0,
        524,
        150,
        32,
        12288,
        0,
    },
    {
        0,
        260,
        282,
        32,
        -24576,
        0,
    },
    {
        0,
        298,
        282,
        32,
        24576,
        0,
    },
    {
        0,
        336,
        282,
        32,
        -8192,
        0,
    },
    {
        0,
        374,
        282,
        32,
        8192,
        0,
    },
};
static s16 D_84102510[] = { 0, 0xBC, 0xD2, 0x20, 0x9000, 0 };
static s16 D_8410251C[] = { 0, 0x20C, 0xD2, 0x20, 0xD000, 0 };
static u8 D_84102528[][2] = {
    {
        0x32,
        0x37,
    },
    {
        0x32,
        0x37,
    },
    {
        0x1,
        0x1E,
    },
    {
        0x1,
        0x64,
    },
    {
        0x19,
        0x1E,
    },
    { 0xF, 0x14 },
};
static u8* D_84102534[] = { D_03028EC0, D_03029C40, D_0302A9C0, D_0302B740, D_0302C4C0, D_0302D480 };
static u32 D_8410254C[] = {
    0x0C000000,  0x05000000, 0x0B00002D, 0x00000000, 0x028001E0, 0x00000000, 0xFDBD0000, 0x00000243, 0x05000000,
    0x0D000000,  0x05000000, 0x14000000, 0x00000000, 0xFFFFFF32, 0x16FFFFFF, 0x0F000002, 0x05000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_841025B0[] = {
    VTX(0, 63, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 43, 0, 0, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 43, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 63, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_841025F0[] = {
    VTX(0, 43, 0, 0, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 23, 0, 0, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 23, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 43, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102630[] = {
    VTX(0, 23, 0, 0, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 3, 0, 0, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 3, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 22, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102670[] = {
    VTX(0, 3, 0, 0, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -17, 0, 0, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -17, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 3, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_841026B0[] = {
    VTX(0, -17, 0, 0, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -37, 0, 0, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -37, 0, 3200, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -17, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_841026F0[] = {
    VTX(0, -37, 0, 0, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -57, 0, 0, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -57, 0, 3200, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -37, 0, 3200, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102730[] = {
    VTX(0, -57, 0, 0, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -63, 0, 0, 4032, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -63, 0, 3200, 4032, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -57, 0, 3200, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102770[] = {
    VTX(100, 63, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 43, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(164, 43, 0, 5248, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(164, 63, 0, 5248, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_841027B0[] = {
    VTX(100, 43, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 23, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(164, 23, 0, 5248, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(164, 43, 0, 5248, 640, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_841027F0[] = {
    VTX(100, 23, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 3, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(164, 3, 0, 5248, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(164, 23, 0, 5248, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102830[] = {
    VTX(100, 3, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -17, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(164, -17, 0, 5248, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(164, 3, 0, 5248, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102870[] = {
    VTX(100, -17, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -37, 0, 3200, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(164, -37, 0, 5248, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(164, -17, 0, 5248, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_841028B0[] = {
    VTX(100, -37, 0, 3200, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -57, 0, 3200, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(164, -57, 0, 5248, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(164, -37, 0, 5248, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_841028F0[] = {
    VTX(100, -57, 0, 3200, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -63, 0, 3200, 4032, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(164, -63, 0, 5248, 4032, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(164, -57, 0, 5248, 3840, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84102930[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 164, 0, 0, 0, 99, 19, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_841025B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 164, 0, 0, 20, 99, 39, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_841025F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 164, 0, 0, 40, 99, 59, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_84102630, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 164, 0, 0, 60, 99, 79, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_84102670, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 164, 0, 0, 80, 99, 99, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_841026B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 164, 0, 0, 100, 99, 119, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_841026F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 164, 0, 0, 120, 99, 125, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_84102730, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 164, 0, 100, 0, 163, 19, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_84102770, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 164, 0, 100, 20, 163, 39, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_841027B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 164, 0, 100, 40, 163, 59, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_841027F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 164, 0, 100, 60, 163, 79, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_84102830, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 164, 0, 100, 80, 163, 99, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_84102870, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 164, 0, 100, 100, 163, 119, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_841028B0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 164, 0, 100, 120, 163, 125, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_841028F0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_84102D40[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_841025B0, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, func_84101120, 0x00000000, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84102D78[] = {
    VTX(0, 54, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 34, 0, 0, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 34, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 54, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102DB8[] = {
    VTX(0, 34, 0, 0, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 14, 0, 0, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 14, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 34, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102DF8[] = {
    VTX(0, 14, 0, 0, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -6, 0, 0, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -6, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 14, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102E38[] = {
    VTX(0, -6, 0, 0, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -26, 0, 0, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -26, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -6, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102E78[] = {
    VTX(0, -26, 0, 0, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -46, 0, 0, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -46, 0, 3200, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -26, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102EB8[] = {
    VTX(0, -46, 0, 0, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -54, 0, 0, 3456, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -54, 0, 3200, 3456, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -46, 0, 3200, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102EF8[] = {
    VTX(100, 54, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 34, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(140, 34, 0, 4480, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(140, 54, 0, 4480, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102F38[] = {
    VTX(100, 34, 0, 3200, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, 14, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(140, 14, 0, 4480, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(140, 34, 0, 4480, 640, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102F78[] = {
    VTX(100, 14, 0, 3200, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -6, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(140, -6, 0, 4480, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(140, 14, 0, 4480, 1280, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102FB8[] = {
    VTX(100, -6, 0, 3200, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -26, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(140, -26, 0, 4480, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(140, -6, 0, 4480, 1920, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84102FF8[] = {
    VTX(100, -26, 0, 3200, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -46, 0, 3200, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(140, -46, 0, 4480, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(140, -26, 0, 4480, 2560, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84103038[] = {
    VTX(100, -46, 0, 3200, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(100, -54, 0, 3200, 3456, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(140, -54, 0, 4480, 3456, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(140, -46, 0, 4480, 3200, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84103078[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 140, 0, 0, 0, 99, 19, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_84102D78, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 140, 0, 0, 20, 99, 39, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_84102DB8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 140, 0, 0, 40, 99, 59, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_84102DF8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 140, 0, 0, 60, 99, 79, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_84102E38, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 140, 0, 0, 80, 99, 99, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_84102E78, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 140, 0, 0, 100, 99, 107, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_84102EB8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 140, 0, 100, 0, 139, 19, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_84102EF8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 140, 0, 100, 20, 139, 39, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_84102F38, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 140, 0, 100, 40, 139, 59, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_84102F78, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 140, 0, 100, 60, 139, 79, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_84102FB8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 140, 0, 100, 80, 139, 99, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_84102FF8, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 140, 0, 100, 100, 139, 107, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_84103038, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_841033F8[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_84102D78, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, func_84101120, 0x00000000, 0x06000000, 0x01000000,
};

#ifdef NON_MATCHING
void func_84100020(s16 arg0, s16 arg1, s16 arg2) {
    s32 spC;
    s32 sp8;
    s32 sp4;

    if (arg2 < 2) {
        return;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 0, 255);
    gDPLoadTextureBlock(gDisplayListHead++, D_302E440, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, ((arg0 << 2) - (arg2 << 1)), ((arg1 << 2) - (arg2 << 1)),
                        (((arg0 << 2) - arg2 << 1)) << 2, (((arg1 << 2) - (arg2 << 1)) + (arg2 << 2)), G_TX_RENDERTILE,
                        0, 0, 0x8000 / arg2, 0x8000 / arg2);
    gSPDisplayList(gDisplayListHead++, D_8006F630);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59/func_84100020.s")
#endif

void func_84100288(s16 arg0) {
    s32 i;
    unk_D_84102498* var_s0 = &D_84102498[0];

    if (arg0 != 0xA) {
        return;
    }

    for (i = 0; i < 12; i++, var_s0++) {
        switch (i) {
            case 4:
            case 5:
                break;

            default:
                switch (var_s0->unk_00) {
                    case 1:
                        var_s0->unk_06 = (s32)(COSS(var_s0->unk_08) * 16.0f) + 0x10;
                        func_84100020(var_s0->unk_02, var_s0->unk_04, var_s0->unk_06);
                        var_s0->unk_08 += 0x1000;
                        if ((u16)var_s0->unk_08 == 0x8000) {
                            var_s0->unk_00 = 2;
                            var_s0->unk_0A = (MathUtil_Random16() & 7) + 0x14;
                        }
                        break;

                    case 2:
                        var_s0->unk_0A--;
                        if (var_s0->unk_0A == 0) {
                            var_s0->unk_00 = 1;
                        }
                        break;
                }
        }
    }
}

void func_841003F0(void) {
    s32 i;

    for (i = 0; i < D_84103CF0.unk_05; i++) {
        D_84102498[i].unk_00 = 1;
    }

    for (i = 0; i < D_84103CF0.unk_06; i++) {
        D_84102498[i + 6].unk_00 = 1;
    }

    if (D_84103CF0.unk_00 & 0x10) {
        D_84102510[0] = 1;
    }

    if (D_84103CF0.unk_00 & 0x20) {
        D_8410251C[0] = 1;
    }
}

void func_8410048C(unk_D_80068BB0* arg0, s16 arg1, s16 arg2) {
    func_80006498(&gDisplayListHead, arg0);
    func_8000699C(&gDisplayListHead, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetBlendColor(gDisplayListHead++, 255, 255, 255, 128);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);

    func_8001CADC(-3, -3, 8, 8, D_2000340, 8, 0);
    func_8001C330(4, -3, arg1 - 8, 8, 0xE0, 0, 0, 0x400, 0);
    func_8001C330(-3, 4, 8, arg2 - 8, 0, 0xE0, 0x400, 0, 0);
    func_8001CADC(arg1 - 5, -3, 8, 8, D_2000380, 8, 0);
    func_8001C330(arg1 - 5, 4, 8, arg2 - 8, 0, 0xE0, 0x400, 0, 0);
    func_8001CADC(-3, arg2 - 5, 8, 8, D_20002C0, 8, 0);
    func_8001C330(4, arg2 - 5, arg1 - 8, 8, 0xE0, 0, 0, 0x400, 0);
    func_8001CADC(arg1 - 5, arg2 - 5, 8, 8, D_2000300, 8, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84100704(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
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

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028A60, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028AA0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20289E0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028A20, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3,
                  0x2000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    if ((temp_a2 > 0) && (temp_s0_32 > 0)) {
        func_8001C604(arg0 + var_s3, arg1, temp_a2, var_s2, arg4, arg5, arg6, arg7);
        func_8001C604(arg0, arg1 + var_s3, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
        func_8001C604(arg0 + var_s3, arg1 + var_s3 + temp_s0_32, temp_a2, var_s2, arg4, arg5, arg6, arg7);
    } else if (temp_a2 > 0) {
        func_8001C604(arg0 + var_s3, arg1, temp_a2, arg3, arg4, arg5, arg6, arg7);
    } else if (temp_s0_32 > 0) {
        func_8001C604(arg0, arg1 + var_s2, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84100F04(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    static s16 D_8410342C = 0;

    s16 sp56 = SINS(D_8410342C) * 2;
    UNUSED s32 pad[2];

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    func_8001CADC((arg0 + sp56) - 8, (arg1 + sp56) - 8, 0x10, 0x10, D_2000C80, 0x10, 0);
    func_8001CADC((arg0 + sp56) - 8, ((arg1 + arg3) - sp56) - 8, 0x10, 0x10, D_2000F80, 0x10, 0);
    func_8001CADC(((arg0 + arg2) - sp56) - 8, (arg1 + sp56) - 8, 0x10, 0x10, D_2000D80, 0x10, 0);
    func_8001CADC(((arg0 + arg2) - sp56) - 8, ((arg1 + arg3) - sp56) - 8, 0x10, 0x10, D_2000E80, 0x10, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    D_8410342C += 0x2000;
}

s32 func_84101120(s32 arg0, unk_func_80011B94* arg1) {
    if (arg0 == 5) {
        s32 idx = D_8006F09C->unk_000.unk_14;

        gDPPipeSync(gDisplayListHead++);

        gSPSegment(gDisplayListHead++, 0x0F, (u32)D_84103CD0[idx]->img_p & 0x1FFFFFFF);

        if ((idx == 0) || (idx == 3)) {
            gSPDisplayList(gDisplayListHead++, D_84102930);
        } else {
            gSPDisplayList(gDisplayListHead++, D_84103078);
        }
        func_80015684();
    }
    return 0;
}

void func_84101210(s16 arg0) {
    s32 sp28;
    s16 temp_a3;
    s32 temp_v0;

    if (arg0 < 0xB) {
        sp28 = arg0 * 9;
        temp_a3 = (sp28 + 2);
    } else {
        sp28 = arg0 * 9;
        temp_a3 = (0xB6 - sp28);
    }

    if (temp_a3 >= 0xA) {
        func_84100704(0x38, ((0x5C - temp_a3) / 2) + 0x15C, 0x210, temp_a3, 0x1E, 0x1E, 0x82, 0x96);
    }

    if ((sp28 == 0x5A) && (D_84103CC8 < 6)) {
        func_8001F3F4();
        func_8001EBE0(0x10, 0);
        func_8001F324(0xFF, 0xFF, 0x64, 0xFF);
        func_8001F1E8(0x48, 0x160, func_8002D7C0(NULL, 0, D_84103440, D_84103CC8));
        func_8001F1E8(0x18C, 0x160, func_8002D7C0(NULL, 0, D_84103440, 0xC));
        func_8001F1E8(func_8001F5B0(0x10, 0, func_8002D7C0(NULL, 0, D_84103440, 0xC)) + 0x190, 0x160, "%d~%d",
                      D_84102528[D_84103CC8][0], D_84102528[D_84103CC8][1]);
        func_8001EBE0(8, 0);
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F3B4(0x18);
        func_8001F1E8(0x48, 0x182, func_8002D7C0(NULL, 0, D_84103440, D_84103CC8 + 6));
        func_8001F444();

        if (D_800AE540.unk_11F2 == 1) {
            temp_v0 = func_8001F5B0(0x10, 0, func_8002D7C0(NULL, 0, D_84103440, D_84103CC8));

            gSPDisplayList(gDisplayListHead++, D_8006F518);

            func_8001C6AC(temp_v0 + 0x4C, 0x160, 0x1C, 0x1C, &D_302E840, 0x1C, 0);

            gSPDisplayList(gDisplayListHead++, D_8006F630);
        }
    }
}

void func_841014E4(s32 arg0, s32 arg1, f32 arg2) {
    s16 i;
    f32 temp_fv0;
    s16 temp_t1;
    s16 temp_v1;
    s16 var_v0;

    if (arg0 < 0xB) {
        var_v0 = ((10 - arg0) * -0x5000) / 10;
        for (i = 0; i < 3; i++) {
            D_84103458[i].unk_01E.x = var_v0;
        }

        for (i = 3; i < 6; i++) {
            D_84103458[i].unk_01E.x = -var_v0;
        }
    } else {
        var_v0 = ((arg0 - 10) * -0x5000) / 10;
        for (i = 0; i < 3; i++) {
            if (i != D_84103CC8) {
                D_84103458[i].unk_01E.x = var_v0;
            }
        }

        for (i = 3; i < 6; i++) {
            if (i != D_84103CC8) {
                D_84103458[i].unk_01E.x = -var_v0;
            }
        }
    }

    func_800079C4();
    func_8001D924(D_84103448);
    func_80015094(D_84103454);

    if (arg2 != 0.0f) {
        unk_D_84102450* ptr = &D_84102450[D_84103CC8];

        temp_v1 = (ptr->unk_04 / 2) + ptr->unk_00;
        temp_t1 = (ptr->unk_06 / 2) + ptr->unk_02;
        temp_fv0 = ptr->unk_04 / 640.0f;
        func_8001E000(temp_v1 + ((0x140 - temp_v1) * arg2), temp_t1 + ((0xF0 - temp_t1) * arg2), 0,
                      ((1.0f - temp_fv0) * arg2) + temp_fv0, D_84103450, D_8410344C);
    }

    if (arg1 != 0) {
        unk_D_84102450* ptr = &D_84102450[D_84103CC8];

        func_84100F04(ptr->unk_00, ptr->unk_02, ptr->unk_04, ptr->unk_06, 0xFF, 0xF0, 0x64, 0xFF);
    }

    func_84100288(arg0);
    func_84101210(arg0);
    func_80007778();
}

unk_D_80068BB0* func_84101894(u8* arg0, s16 arg1) {
    s16 i;
    unk_D_80068BB0* sp40 = func_80006314(0, 2, 0xA4, 0x7E, 1);
    s32 var_s3;

    if (arg1 == 3) {
        var_s3 = D_84103CF0.unk_05;
    } else {
        var_s3 = D_84103CF0.unk_06;
    }
    func_8410048C(sp40, 0xA0, 0x7A);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 9; i++) {
        func_8001C6AC(4, (i * 0xC) + 4, 0x98, 0xC, (i * 0xE40) + arg0, 0x98, 0);
    }

    func_8001C6AC(4, (i * 0xC) + 4, 0x98, 6, (i * 0xE40) + arg0, 0x98, 0);

    for (i = 0; i < var_s3; i++) {
        func_8001C6AC((i * 0x26) + 5, 0x46, 0x24, 0x30, D_84102534[i], 0x24, 0);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    return sp40;
}

unk_D_80068BB0* func_84101A94(u8* arg0, s16 arg1) {
    s16 i;
    unk_D_80068BB0* sp30 = func_80006314(0, 2, 0x8C, 0x6C, 1);
    s32 var_v0;

    func_8410048C(sp30, 0x88, 0x68);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 6; i++) {
        func_8001C6AC(4, (i * 0x10) + 4, 0x80, 0x10, (i << 0xC) + arg0, 0x80, 0);
    }

    if (D_84103CF0.unk_00 & (1 << arg1)) {
        if (arg1 == 4) {
            var_v0 = 5;
        } else {
            var_v0 = 4;
        }
        func_8001C6AC(0x54, 0x3A, 0x30, 0x2A, D_84102534[var_v0], 0x30, 0);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    return sp30;
}

void func_84101BFC(void) {
    func_841003F0();
    D_84103CD0[0] = func_84101894(&D_300C000, 3);
    D_84103CD0[1] = func_84101A94(D_3000000, 1);
    D_84103CD0[2] = func_84101A94(D_3006000, 2);
    D_84103CD0[3] = func_84101894(&D_3020760, 6);
    D_84103CD0[4] = func_84101A94(&D_3014760, 4);
    D_84103CD0[5] = func_84101A94(&D_301A760, 5);
    func_8001BC34(D_84103458, 0, 0, D_84103CE8);
    func_8001BC34(&D_84103458[3], 0, 0, D_84103CE8);
    func_8001BC34(&D_84103458[4], 0, 0, D_84103CEC);
    func_8001BC34(&D_84103458[5], 0, 0, D_84103CEC);
    func_8000E88C(&D_84103458->unk_024, -80.0f, 113.0f, -579.0f);
    func_8000E88C(&D_84103458[3].unk_024, -80.0f, -29.0f, -579.0f);
    func_8000E88C(&D_84103458[4].unk_024, -236.0f, 42.0f, -579.0f);
    func_8000E88C(&D_84103458[5].unk_024, 100.0f, 42.0f, -579.0f);
}

s16 func_84101D80(void) {
    s16 var_a1 = -1;
    s16 var_v1 = -1;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        func_80048B90(0x26);
        var_v1 = -1;
        var_a1 = D_84103CC8;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        func_80048B90(3);
        var_v1 = -1;
        var_a1 = 6;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        var_v1 = D_84102450[D_84103CC8].unk_08;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        var_v1 = D_84102450[D_84103CC8].unk_09;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DLEFT)) {
        var_v1 = D_84102450[D_84103CC8].unk_0A;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DRIGHT)) {
        var_v1 = D_84102450[D_84103CC8].unk_0B;
    }

    if (var_v1 != -1) {
        func_80048B90(1);
        D_84103CC8 = var_v1;
    }
    return var_a1;
}

void func_84101EC8(void) {
    s16 i;
    s16 temp_v0;

    func_8000D1F0(0x15);
    func_84101BFC();
    D_84103CC8 = 0;
    func_80006C6C(0xA);
    while (func_80007604() != 0) {
        func_800290B4();
        func_841014E4(0, 0, 0.0f);
    }

    for (i = 0; i < 10; i++) {
        func_800290B4();
        func_841014E4(i, 0, 0.0f);
    }
    do {
        func_800290B4();
        func_841014E4(0xA, 1, 0.0f);
        temp_v0 = func_84101D80();
    } while (temp_v0 == -1);

    D_84103CC8 = temp_v0;

    if (D_84103CC8 < 6) {
        D_8410344C = func_8000484C(D_84103444, D_84102430[D_84103CC8]);

        for (i = 11; i < 21; i++) {
            func_800290B4();
            func_841014E4(i, 0, 0.0f);
        }

        for (i = 0; i < 6; i++) {
            func_8001BCF0(&D_84103458[i]);
        }

        for (i = 1; i < 10; i++) {
            func_800290B4();
            func_841014E4(0, 0, i / 10.0f);
        }

        func_841014E4(0, 0, 1.0f);
        func_841014E4(0, 0, 1.0f);
    } else {
        func_80007990(0xFFFF);
        func_8000D278(0x14);
        func_80006CB4(0xA);
        while (func_80007604() != 1) {
            func_800290B4();
            func_841014E4(0xA, 0, 0.0f);
        }
        func_800077B4(2);
    }
}

void func_84102140(void) {
    s32 i;
    unk_D_86002F58_004_000* ptr;
    unk_D_86002F58_004_000* ptr2;
    MemoryBlock* temp_v0 = func_80002D10(main_pool_get_available(), 0);

    D_84103454 = process_geo_layout(temp_v0, D_8410254C);
    D_84103CE8 = process_geo_layout(temp_v0, D_84102D40);
    D_84103CEC = process_geo_layout(temp_v0, D_841033F8);

    func_80002D60(temp_v0);
    func_8001BB20();

    ptr = &D_84103458[0];
    for (i = 0; i < 6; ptr++, i++) {
        func_8001BB58(ptr);
        D_84103458[i].unk_000.unk_14 = i;
    }
}

s32 func_84102210(void) {
    s32 var_v1 = 0;

    if (D_84103CC8 < 6) {
        s16 tmp = D_84102438[D_84103CC8];

        func_8002B5EC(tmp, D_84102444[D_84103CC8], 0);
        func_8002B840(0, func_8002B700(0, 0, "1P", func_8002311C(1)));
        func_8002B840(1, func_8002B700(-1, 0, "COM", func_8002311C(3)));
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_841022C0(s32 arg0, s32 arg1) {
    BinArchive* temp_v0;

    main_pool_push_state('PSSL');

    func_80028AFC(2);
    func_80027FA0(&D_84103CF0, D_800AE540.unk_11F2);
    func_8001E94C(0x18, 0);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);
    ASSET_LOAD(D_3000000, stadium_select_ui, 0);
    func_8002D510();
    D_84103440 = func_8002D5AC(0x13);
    D_84103450 = func_8001E490();

    D_84103444 = ASSET_LOAD2(backgrounds, 1, 1);

    D_84103448 = func_8000484C(D_84103444, 3);
    D_84103CC8 = 0;
    func_84102140();
    func_80007754();
    func_84101EC8();
    func_8000771C();

    main_pool_pop_state('PSSL');

    return func_84102210();
}
