#include "fragment61.h"
#include "src/12D80.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/22630.h"
#include "src/232C0.h"
#include "src/26820.h"
#include "src/2E110.h"
#include "src/49790.h"
#include "src/F420.h"
#include "src/controller.h"
#include "src/geo_layout.h"
#include "src/math_util.h"
#include "src/memmap.h"
#include "src/fragments/47/fragment47.h"
#include "src/memory.h"

typedef struct unk_D_8423E518 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ char unk_06[1];
    /* 0x07 */ char unk_07[0xD];
} unk_D_8423E518; // size = 0x14

GraphNode* D_8423D400;
unk_D_86002F58_004_000 D_8423D408[2][6];
unk_D_86002F58_004_000_004* D_8423E4E8[6];
unk_D_86002F58_004_000_004* D_8423E500;
u8* D_8423E508[4];
unk_D_8423E518 D_8423E518[4];
s16 D_8423E568;
s16 D_8423E56A;
s16 D_8423E56C;
s16 D_8423E56E;
Controller* D_8423E570;
s16 D_8423E574;
s16 D_8423E576;
s16 D_8423E578;
s32 D_8423E57C;

unk_D_8380548C D_84210DA0[] = {
    {
        0x01,
        0x00,
        134,
        210,
        64,
        0,
        0,
        1472,
    },
    {
        0x01,
        0x00,
        258,
        210,
        64,
        -32768,
        -32768,
        1664,
    },
    {
        0x01,
        0x00,
        382,
        210,
        64,
        0,
        0,
        1408,
    },
    {
        0x01,
        0x00,
        506,
        210,
        64,
        -32768,
        -32768,
        1600,
    },
};
u8 D_84210DD8[] = {
    1, 0, 0, 0xBE, 1, 0x70, 0, 0x4C, 0, 0, 0, 0, 6, 0x20, 1, 0, 1, 0xC2, 1, 0x70, 0, 0x64, 0x80, 0, 0x80, 0, 5, 0xE0,
};
u32 D_84210DF4[] = {
    0x0C000000,  0x05000000, 0x0B00002D, 0x00000000, 0x028001E0, 0x00000000, 0xFDBD0000,
    0x00000243,  0x05000000, 0x0D000000, 0x05000000, 0x0F000002, 0x05000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000, 0x00000000,
};
Vtx D_84210E48[] = {
    VTX(-32, 64, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 32, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 32, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 64, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 0, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 0, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, 32, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 39, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-16, 15, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, 15, 0, 1024, 768, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(16, 39, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84210F08[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84210E48, 12, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F001000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureBlock(0x0E000000, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};
static u32 D_84210FF0[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_84210E48, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, func_84204070, D_84210F08, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84211028[] = {
    VTX(-38, 60, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-38, 40, 0, 0, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(38, 40, 0, 2432, 640, 0xFF, 0xFF, 0xFF, 0xFF), VTX(38, 60, 0, 2432, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-38, 40, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-38, 20, 0, 0, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(38, 20, 0, 2432, 640, 0xFF, 0xFF, 0xFF, 0xFF), VTX(38, 40, 0, 2432, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-38, 20, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-38, 0, 0, 0, 640, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(38, 0, 0, 2432, 640, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(38, 20, 0, 2432, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_842110E8[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84211028, 12, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 76, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F000BE0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 76, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureBlock(0x0F0017C0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 76, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};
static u32 D_842111D0[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_84211028, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, func_84204070, D_842110E8, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84211208[] = {
    VTX(-50, 64, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-50, 48, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(50, 48, 0, 3200, 512, 0xFF, 0xFF, 0xFF, 0xFF), VTX(50, 64, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-50, 48, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-50, 32, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(50, 32, 0, 3200, 512, 0xFF, 0xFF, 0xFF, 0xFF), VTX(50, 48, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-50, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-50, 16, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(50, 16, 0, 3200, 512, 0xFF, 0xFF, 0xFF, 0xFF), VTX(50, 32, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-50, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-50, 0, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(50, 0, 0, 3200, 512, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(50, 16, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84211308[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84211208, 16, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F000C80, G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureBlock(0x0F001900, G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsDPLoadTextureBlock(0x0F002580, G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};
static u32 D_84211430[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_84211208, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, func_84204070, D_84211308, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84211468[] = {
    VTX(-36, 12, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-36, -12, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(36, -12, 0, 2304, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(36, 12, 0, 2304, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_842114A8[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84211468, 4, 0),
    gsDPLoadTextureBlock_4b(0x0F000000, G_IM_FMT_I, 80, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_84211510[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_84211468, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, func_84204070, D_842114A8, 0x06000000, 0x01000000,
};

s16 D_84211544[] = { 0x46, 0x28, 0x1E, 0x1E, 0x1E, 0x1E, 0x28, 0x3C, 0x5A, 0x78, 0x6E, 0x64 };
s16 D_8421155C[] = { 0x14, 0x3C, 0x5F, 0x78, 0x82, 0x87, 0x82, 0x78, 0x6E, 0x69, 0x66, 0x64 };
s16 D_84211574[] = { 0x46, 0x32, 0x28, 0x1E, 0x19, 0x14, 0x14, 0x14, 0x19, 0x1E, 0x28, 0x32 };
s16 D_8421158C[] = {
    0x64, 0x6E, 0x82, 0x96, 0xA0, 0xA0, 0x78, 0x50, 0x32, 0x1E, 0xA, 5,
};

s32 func_84204070(s32 arg0, unk_func_80011B94* arg1) {
    u32 var_a0;
    u8* var_a3;

    if (arg0 == 5) {
        // clang-format off
        switch (D_8006F09C->unk_000.unk_14) {
            case 0:
                var_a0 = D_8423E508[0]; var_a3 = D_201D820;
                break;

            case 1:
                var_a0 = D_8423E508[1]; var_a3 = D_201DB20;
                break;

            case 2:
                var_a0 = D_8423E508[2]; var_a3 = D_201DE20;
                break;

            case 3:
                var_a0 = D_8423E508[3]; var_a3 = D_201E120;
                break;

            case 4:
                var_a0 = D_2029CE0;
                var_a3 = NULL;
                break;

            case 5:
                var_a0 = D_201A620;
                var_a3 = NULL;
                break;

            default:
                var_a0 = D_2028420;
                var_a3 = NULL;
                break;
        }
        // clang-format on

        gDPPipeSync(gDisplayListHead++);
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, D_8006F09C->unk_01D);
        gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(var_a0));
        gSPSegment(gDisplayListHead++, 0x0E, Memmap_GetSegmentVaddr(var_a3));
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }

    return 0;
}

void func_84204210(void) {
    if (D_8423E56C == 3) {
        s16 tmp = (D_84210DA0[D_8423E568].unk_02 - (D_84210DA0[D_8423E568].unk_06 / 2)) - 0x1E;

        func_80020928(tmp, D_84210DA0[D_8423E568].unk_04 - 0x20);
    }
}

void func_84204294(s32 arg0) {
    UNUSED s32 pad;

    if (D_84210DA0[arg0].unk_00 != 0) {
        if (D_84210DA0[arg0].unk_01 == 0) {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001EBE0(8, 0);
            func_8001F1E8(((arg0 * 128) - (func_8001F5B0(8, 0, D_8423E518[arg0].unk_06) / 2)) + 0x80, 0x5C,
                          D_8423E518[arg0].unk_06);
            func_8001F324(0xFF, 0xBE, 0xFF, 0xFF);
            func_8001EBE0(4, 0);
            func_8001F1E8(((arg0 * 128) - (func_8001F5B0(4, 0, "ID  00000") / 2)) + 0x80, 0x73, "ID  %05d",
                          D_8423E518[arg0].unk_04);
        } else {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001EBE0(8, 0);
            func_8001F1E8(((arg0 * 128) - (func_8001F5B0(8, 0, "???????") / 2)) + 0x80, 0x5C, "???????");
            func_8001F324(0xFF, 0xBE, 0xFF, 0xFF);
            func_8001EBE0(4, 0);
            func_8001F1E8(((arg0 * 128) - (func_8001F5B0(4, 0, "ID  *****") / 2)) + 0x80, 0x73, "ID  *****");
        }
    }
}

void func_8420448C(void) {
    s32 tmp;
    char* temp_v0;
    char sp20[0x100];

    func_8001F3F4();
    func_84204294(0);
    func_84204294(1);
    func_84204294(2);
    func_84204294(3);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001EBE0(0x10, 0);

    temp_v0 = func_84200130(0xB);
    tmp = func_8001F5B0(0x10, 0, temp_v0) / 2;
    func_8001F1E8(0x140 - tmp, 0x198, temp_v0);
    func_8001EBE0(8, 0);

    if (D_8423E56A == 0) {
        temp_v0 = func_84200130(0xC);
    } else {
        temp_v0 = func_84200130(0xD);
    }

    tmp = func_8001F5B0(8, 0, temp_v0) / 2;
    func_8001F1E8(0x1C0 - tmp, 0x102, temp_v0);

    if (D_8423E56A == 0) {
        temp_v0 = func_84200130(0xE);
        tmp = func_8001F5B0(8, 0, temp_v0) / 2;
        func_8001F1E8(0xC0 - tmp, 0xF6, temp_v0);
        func_8001F324(0xFF, 0xBA, 0xCC, 0xFF);
        func_8002D600(2, D_8423E578);
        temp_v0 = func_84200190(sp20, sizeof(sp20), 0xF);
        tmp = func_8001F5B0(8, 0, temp_v0) / 2;
        func_8001F1E8(0xC0 - tmp, 0x10E, temp_v0);
    }
    func_8001F444();
}

void func_84204660(s32 arg0, s16 arg1, s16 arg2) {
    Color_RGBA8 sp2C;

    if (D_84210DA0[arg0].unk_00 != 0) {
        if (D_84210DA0[arg0].unk_01 == 0) {
            func_8000E840(&sp2C, 0x1E, 0x1E, 0x82, 0xFF);
        } else {
            func_8000E840(&sp2C, 0x64, 0x1E, 0x1E, 0xFF);
        }
    } else {
        func_8000E840(&sp2C, 0x1E, 0x1E, 0x82, 0x80);
    }
    func_8420092C((arg0 * 128) + 0x44, arg1 + 0x54, 0x78, arg2, sp2C.r, sp2C.g, sp2C.b, sp2C.a);
}

void func_84204210(void);

void func_84204760(s32 arg0) {
    UNUSED s32 pad;
    s16 sp32;
    s16 temp_s0;

    if (D_8423E56C != 0) {
        temp_s0 = (0x38 - D_8423E574) / 2;
        sp32 = (0x28 - D_8423E576) / 2;
        func_80015094(D_8423D400);
        func_84204210();

        if (D_8423E574 > 0) {
            func_84204660(0, temp_s0, D_8423E574);
            func_84204660(1, temp_s0, D_8423E574);
            func_84204660(2, temp_s0, D_8423E574);
            func_84204660(3, temp_s0, D_8423E574);
            if (D_8423E56A == 0) {
                func_8420092C(0x44, temp_s0 + 0xF0, 0xF8, D_8423E574, 0x78, 0x1E, 0x64, 0xFF);
            }
            func_8420092C(0x144, temp_s0 + 0xF0, 0xF8, D_8423E574, 0x78, 0x1E, 0x64, 0xFF);
        }

        if (D_8423E576 > 0) {
            func_8420112C(0x38, sp32 + 0x190, 0x210, D_8423E576, 0x1E, 0x1E, 0x82, 0x96);
        }

        if (D_8423E574 == 0x38) {
            func_8420448C();
        }
    }
}

void func_84204934(s16 arg0, f32 arg1) {
    s16 var_a2;
    f32 var_fa0;

    if (arg0 == D_8423E568) {
        var_fa0 = 0.06f;
        var_a2 = 0x3000;
    } else {
        var_fa0 = 0.02f;
        var_a2 = 0x2000;
    }

    D_8423D408[0][arg0].unk_030.x = ((SINS(D_84210DA0[arg0].unk_0A) * var_fa0) + 1.0f) * arg1;
    D_8423D408[0][arg0].unk_030.y = ((COSS(D_84210DA0[arg0].unk_0A) * var_fa0) + 1.0f) * arg1;

    D_8423D408[1][arg0].unk_030.x = ((SINS(D_84210DA0[arg0].unk_0A) * var_fa0) + 1.0f) * arg1;
    D_8423D408[1][arg0].unk_030.y = ((COSS(D_84210DA0[arg0].unk_0A) * var_fa0) + 1.0f) * arg1;

    D_84210DA0[arg0].unk_0A += var_a2 + ((MathUtil_Random16() & 0xF) * 0x10);
}

void func_84204A3C(s16 arg0, f32 arg1) {
    f32 var_fv0;
    s16 var_v0;

    if (arg0 == D_8423E568) {
        var_v0 = D_84210DA0[arg0].unk_0C * 2;
        var_fv0 = 1.5f;
    } else {
        var_v0 = D_84210DA0[arg0].unk_0C;
        var_fv0 = 1.0f;
    }

    D_8423D408[0][arg0].unk_01E.z = SINS(D_84210DA0[arg0].unk_08) * (1536.0f * var_fv0);

    D_8423D408[0][arg0].unk_024.x =
        (D_84210DA0[arg0].unk_02 - 320.0f) - (SINS(D_84210DA0[arg0].unk_08) * (6.0f * var_fv0));
    D_8423D408[1][arg0].unk_024.x =
        (D_84210DA0[arg0].unk_02 - 320.0f) - (SINS(D_84210DA0[arg0].unk_08) * (6.0f * var_fv0));

    D_84210DA0[arg0].unk_08 += var_v0;
}

void func_84204B50(void) {
    s16 i;
    s16 var_v1;
    s32 var_a0;

    if (D_8423E568 >= 4) {
        if (D_8423E568 == 4) {
            var_v1 = 0;
            var_a0 = 1;
        } else {
            var_v1 = 3;
            var_a0 = -1;
        }

        for (i = 0; i < 4; i++) {
            if (D_84210DA0[var_v1].unk_00 != 0) {
                D_8423E568 = var_v1;
                func_80048B90(1);
                break;
            }
            var_v1 = (var_v1 + var_a0) & 3;
        }
    }
}

void func_84204BF8(void) {
    s16 var_v0;
    s16 i;

    if (D_8423E568 < 4) {
        var_v0 = D_8423E568 / 2 + 4;
        for (i = 0; i < 2; i++) {
            if (D_84210DA0[var_v0].unk_00 != 0) {
                D_8423E568 = var_v0;
                func_80048B90(1);
                break;
            }
            var_v0 ^= 1;
        }
    }
}

void func_84204C9C(void) {
    s16 i;

    if ((D_8423E568 > 0) && (D_8423E568 < 4)) {
        for (i = D_8423E568 - 1; i >= 0; i--) {
            if (D_84210DA0[i].unk_00 != 0) {
                D_8423E568 = i;
                func_80048B90(1);
                break;
            }
        }
    } else if ((D_8423E568 == 5) && (D_84210DA0[4].unk_00 != 0)) {
        D_8423E568 = 4;
        func_80048B90(1);
    }
}

void func_84204D5C(void) {
    s16 i;

    if (D_8423E568 < 3) {
        for (i = D_8423E568 + 1; i < 4; i++) {
            if (D_84210DA0[i].unk_00 != 0) {
                D_8423E568 = i;
                func_80048B90(1);
                break;
            }
        }
    } else if (D_8423E568 == 4) {
        D_8423E568 = 5;
        func_80048B90(1);
    }
}

void func_84204E0C(void) {
    s16 i;

    if (BTN_IS_PRESSED(D_8423E570, BTN_A)) {
        if (D_84210DA0[D_8423E568].unk_01 == 0) {
            func_80048B90(0x01100012);
            D_8423E56C = 4;
        } else {
            func_80048B90(8);
            D_8423E56C = 6;
        }
    } else if ((D_8423E57C != 0) && (BTN_IS_PRESSED(D_8423E570, BTN_B))) {
        D_8423E56C = 5;
        func_80048B90(3);
    } else if (BTN_IS_PRESSED(D_8423E570, BTN_DUP)) {
        func_84204B50();
    } else if (BTN_IS_PRESSED(D_8423E570, BTN_DDOWN)) {
        func_84204BF8();
    } else if (BTN_IS_PRESSED(D_8423E570, BTN_DLEFT)) {
        func_84204C9C();
    } else if (BTN_IS_PRESSED(D_8423E570, BTN_DRIGHT)) {
        func_84204D5C();
    }

    for (i = 0; i < 6; i++) {
        func_84204934(i, 1.0f);
        func_84204A3C(i, 1.0f);
    }
}

void func_84204F78(void) {
    s16 i;

    for (i = 0; i < 12; i++) {
        D_8423D408[0][i].unk_030.x = D_84211544[D_8423E56E] / 100.0f;
        D_8423D408[0][i].unk_030.y = D_8421155C[D_8423E56E] / 100.0f;
    }

    D_8423E574 = ((((D_8423E56E * 0x32) + 0x32) / 12) + 6) & (u16)~1;
    D_8423E576 = ((((D_8423E56E * 0x24) + 0x24) / 12) + 4) & (u16)~1;

    D_8423E56E++;
    if (D_8423E56E == 12) {
        D_8423E56C = 3;
    }
}

void func_842050CC(void) {
    if (D_8423E56E++ < 12) {
        D_8423D408[0][D_8423E568].unk_030.x = D_84211574[D_8423E56E] / 100.0f;
        D_8423D408[0][D_8423E568].unk_030.y = D_8421158C[D_8423E56E] / 100.0f;

        D_8423D408[1][D_8423E568].unk_030.x = D_84211574[D_8423E56E] / 100.0f;
        D_8423D408[1][D_8423E568].unk_030.y = D_8421158C[D_8423E56E] / 100.0f;

        D_8423D408[0][D_8423E568].unk_01E.z = 0;
    } else {
        func_8001BCF0(&D_8423D408[0][D_8423E568]);
        func_8001BCF0(&D_8423D408[1][D_8423E568]);
        D_8423E56C = 0;
    }
}

void func_84205200(void) {
    s16 i;

    D_8423E56E--;
    if (D_8423E56E == 0) {
        for (i = 0; i < 6; i++) {
            if (i != D_8423E568) {
                func_8001BCF0(&D_8423D408[0][i]);
                func_8001BCF0(&D_8423D408[1][i]);
            }
        }

        D_8423E574 = 0;
        D_8423E576 = 0;
        D_8423E56C = 2;
    } else {
        for (i = 0; i < 6; i++) {
            if (i == D_8423E568) {
                func_84204934(i, 1.0f);
                func_84204A3C(i, 1.0f);
            } else {
                func_84204934(i, D_8423E56E / 12.0f);
                func_84204A3C(i, D_8423E56E / 12.0f);
            }

            D_8423E574 = ((((D_8423E56E * 0x32) + 0x32) / 12) + 6) & (u16)~1;
            D_8423E576 = ((((D_8423E56E * 0x24) + 0x24) / 12) + 4) & (u16)~1;
        }
    }
}

void func_8420545C(void) {
    s16 i;

    D_8423E56E--;
    if (D_8423E56E == 0) {

        for (i = 0; i < 6; i++) {
            func_8001BCF0(&D_8423D408[0][i]);
            func_8001BCF0(&D_8423D408[1][i]);
        }

        D_8423E568 = -2;
        D_8423E574 = 0;
        D_8423E576 = 0;
        D_8423E56C = 0;
    } else {
        for (i = 0; i < 6; i++) {
            func_84204934(i, D_8423E56E / 12.0f);
            func_84204A3C(i, D_8423E56E / 12.0f);
        }

        D_8423E574 = ((((D_8423E56E * 0x32) + 0x32) / 12) + 6) & (u16)~1;
        D_8423E576 = ((((D_8423E56E * 0x24) + 0x24) / 12) + 4) & (u16)~1;
    }
}

void func_8420563C(void) {
    s16 var_s0;
    s16 i;

    if (D_84210DA0[D_8423E568].unk_01 == 0x15) {
        var_s0 = 0x11;
    } else {
        var_s0 = 0x12;
    }

    func_8420DA28(var_s0, D_8423E570);

    if (func_8420DB48(var_s0) != -1) {
        D_8423E56C = 3;
    }

    for (i = 0; i < 6; i++) {
        func_84204934(i, 1.0f);
        func_84204A3C(i, 1.0f);
    }
}

s32 func_8420570C(void) {
    switch (D_8423E56C) {
        case 1:
            func_84204F78();
            break;

        case 3:
            func_84204E0C();
            break;

        case 4:
            func_84205200();
            break;

        case 2:
            func_842050CC();
            break;

        case 5:
            func_8420545C();
            break;

        case 6:
            func_8420563C();
            break;
    }
    return 1;
}

void func_842057AC(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        if (D_8423E518[i].unk_01 != 0) {
            switch (D_8423E518[i].unk_01) {
                case 1:
                    D_8423E508[i] = D_201E420;
                    break;

                case 2:
                    D_8423E508[i] = D_2020420;
                    break;

                case 3:
                    D_8423E508[i] = D_2022420;
                    break;

                case 7:
                    D_8423E508[i] = D_2024420;
                    break;
            }

            if (D_8423E518[i].unk_00 != 0) {
                D_84210DA0[i].unk_01 = 0x14;
            }
        } else {
            D_8423E508[i] = D_2026420;
            if (D_8423E518[i].unk_00 == 2) {
                D_84210DA0[i].unk_01 = 0x15;
            } else {
                D_84210DA0[i].unk_00 = 0;
                D_84210DA0[i].unk_01 = 1;
            }
        }
    }
}

void func_8420594C(void) {
    s16 i;

    if (D_8423E56A != 0) {
        D_84210DD8[0] = 0;
    } else {
        D_84210DD8[0] = 1;
    }

    for (i = 0; i < 6; i++) {
        if (D_84210DA0[i].unk_00 != 0) {
            func_8001BC34(D_8423D408[0] + i, 0, 0, D_8423E4E8[i]);
            func_8001BC34(D_8423D408[1] + i, 0, 0, D_8423E500);
            func_8000E88C(&D_8423D408[0][i].unk_024, D_84210DA0[i].unk_02 - 0x140, 0xF0 - D_84210DA0[i].unk_04, -579.f);
            func_8000E88C(&D_8423D408[1][i].unk_024, D_84210DA0[i].unk_02 - 0x140, 0xE4 - D_84210DA0[i].unk_04,
                          -579.0f);
            D_8423D408[1][i].unk_01D = 0xB4;
        }
    }

    if (D_84210DD8[0] != 0) {
        D_8423E578 = func_80028E68();
        if (D_8423E578 == 0) {
            D_84210DD8[0] = 0;
            D_8423D408[0][4].unk_01D = 0xA0;
            D_8423D408[1][4].unk_01D = 0x64;
        }
    }

    if (!D_84210DA0) {}
}

void func_84205B3C(void) {
    s32 i;
    u8 temp_s3 = Cont_GetControllerBits();
    unk_D_800AC910_040 sp48;

    for (i = 0; i < 4; i++) {
        func_80025040(i, &sp48);
        func_80021A90(D_8423E518[i].unk_06, sp48.unk_02);
        D_8423E518[i].unk_04 = sp48.unk_00;
        D_8423E518[i].unk_01 = func_80024F68(i);
        D_8423E518[i].unk_00 = func_80024F00(i);
        D_8423E518[i].unk_02 = func_80025370(i);
        D_8423E518[i].unk_03 = (temp_s3 & (1 << i)) != 0;
    }
}

s32 func_84205C18(s16 arg0) {
    s32 i;
    MemoryBlock* temp_v0 = func_80002D10(main_pool_get_available(), 0);
    unk_D_86002F58_004_000* var_s2;

    D_8423D400 = process_geo_layout(temp_v0, D_84210DF4);
    D_8423E56A = arg0;
    D_8423E4E8[3] = D_8423E4E8[2] = D_8423E4E8[1] = D_8423E4E8[0] = process_geo_layout(temp_v0, D_84210FF0);
    D_8423E4E8[4] = process_geo_layout(temp_v0, D_842111D0);
    D_8423E4E8[5] = process_geo_layout(temp_v0, D_84211430);
    D_8423E500 = process_geo_layout(temp_v0, D_84211510);

    func_80002D60(temp_v0);
    func_8001BB20();

    var_s2 = &D_8423D408[0][0];
    for (i = 0; i < 12; var_s2++, i++) {
        func_8001BB58(var_s2);
        D_8423D408[0][i].unk_000.unk_14 = i;
    }

    func_84205B3C();
    func_842057AC();
    return 8;
}

s32 func_84205D48(s16 arg0, s32 arg1) {
    if (D_8423E56C == 0) {
        func_8420594C();
        if (D_84210DA0[arg0].unk_00 != 0) {
            D_8423E568 = arg0;
        } else {
            for (D_8423E568 = 0; D_8423E568 < 5; D_8423E568++) {
                if (D_84210DA0[D_8423E568].unk_00 != 0) {
                    break;
                }
            }
        }

        D_8423E570 = &gControllers[arg0];
        D_8423E57C = arg1;
        D_8423E56E = 0;
        D_8423E56C = 1;
        return 1;
    }

    return 0;
}

s16 func_84205E54(void) {
    if (D_8423E56C == 0) {
        return D_8423E568;
    }
    return -1;
}
