#include "fragment33.h"
#include "src/12D80.h"
#include "src/19840.h"
#include "src/1AB70.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/20470.h"
#include "src/22630.h"
#include "src/26820.h"
#include "src/29BA0.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/4BDC0.h"
#include "src/6A40.h"
#include "src/F420.h"
#include "src/controller.h"
#include "src/geo_layout.h"
#include "src/math_util.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static u8* D_81303FA0;
static unk_D_81303FA8 D_81303FA8[4];
static s16 D_81304000;
static unk_D_81304008 D_81304008[4];
static GraphNode* D_81304648;
static GraphNode* D_8130464C;
static s16 D_81304650;
static s32 D_81304654;
static char** D_81304658;
static char D_81304660[0x400];
static s16 D_81304A60;
static s16 D_81304A62;
static s32 D_81304A64;

static u32 D_81303C20[] = {
    0xA4B3A4CE, 0xA5ABA1BC, 0xA5C8A5EA, 0x0AA5C3A5, 0xB8A4CFA1, 0xA2A4C4A4, 0xAB0AA4A8, 0xA4DEA4BB, 0xA4F3A1A3,
    0x00000000, 0xA5ECA5DD, 0xA1BCA5C8, 0xA4ACA1A2, 0x0AA4DFA4, 0xC4A4ABA4, 0xEAA4DEA4, 0xBB0AA4F3, 0xA1A30000,
    0xA5DDA5B1, 0xA5E2A5F3, 0xA5BBA5F3, 0x0AA5BFA1, 0xBCA4C7A1, 0xA2A5ECA5, 0xDD0AA1BC, 0xA5C8A4B5, 0xA4ECA4C6,
    0xA4A40AA4, 0xDEA4BBA4, 0xF3A1A300, 0xA4BAA4AB, 0xA4F3A4AC, 0xA1A20AA4, 0xA2A4EAA4, 0xDEA4BBA4, 0xF3A1A300,
};

static s16 D_81303CB0 = 0;

static u32 D_81303CB4[] = {
    0x0C000000,  0x05000000, 0x0B00002D, 0x00000000, 0x028001E0, 0x00000000, 0xFDBD0000, 0x00000243, 0x05000000,
    0x0D000000,  0x05000000, 0x14000000, 0x002D013B, 0xFFFFFF32, 0x16FFFFFF, 0x0F000002, 0x05000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000, 0x00000000,
};

static Vtx D_81303D18[] = {
    VTX(-32, 64, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 32, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 32, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 64, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 0, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 0, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, 32, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 39, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-16, 15, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, 15, 0, 1024, 768, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(16, 39, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

static Gfx D_81303DD8[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_81303D18, 12, 0),
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

static u32 D_81303EC0[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_81303D18, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, func_81300020, D_81303DD8, 0x06000000, 0x01000000,
};

static u32 D_81303EF4[] = {
    D_201D820, D_201DB20, D_201DE20, D_201E120, NULL,
};

static u32 D_81303F08[] = {
    0x1E1E1E00,
    0x00006400,
    0x0000FF00,
};

static Color_RGB8 D_81303F14 = { 0x64, 0x1E, 0x1E };
static s32 pad_D_81303F18 = 0;
static u8* D_81303F1C[] = { D_3000008, D_03000FD0, D_03001F98, D_03002F60, D_03003F28 };

s32 func_81300020(s32 arg0, GraphNode* arg1) {
    s32 idx;

    if (arg0 == 5) {
        idx = D_8006F09C->unk_000.unk_14;

        gDPPipeSync(gDisplayListHead++);

        if (gCurrentGameState == 0x25) {
            gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 639, 206);
        } else {
            gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 639, 202);
        }

        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, D_8006F09C->unk_01D);

        if (D_81304008[idx].unk_01C != NULL) {
            gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(D_81304008[idx].unk_01C));
            gSPSegment(gDisplayListHead++, 0x0E, Memmap_GetSegmentVaddr(D_81303EF4[D_81304008[idx].unk_002]));
            gSPDisplayList(gDisplayListHead++, arg1->unk_14);
        }
        func_80015684();
    }
    return 0;
}

s32 func_813001C0(void) {
    unk_func_8002A728 sp18;

    func_80028AFC(2);
    func_80027F24(&sp18);
    return sp18.unk_00;
}

void func_813001EC(void) {
    if (D_81304000 >= 0) {
        D_81304008[D_81304000].unk_000 = 1;
        D_81304008[D_81304000].unk_020 = -D_81304008[D_81304000].unk_028.unk_024.x / 20.0f;
        D_81304008[D_81304000].unk_024 = 36.0f;
        D_81304650 = 0;
    }
}

s32 func_81300254(s32 arg0) {
    unk_D_81303FA8* ptr = &D_81303FA8[arg0];
    s32 var_v1;

    if (ptr->unk_01 != 0) {
        if (ptr->unk_00 == 0) {
            if (func_8002539C(arg0) == 0) {
                var_v1 = 0x16;
            } else if (ptr->unk_03 != 0) {
                var_v1 = 0;
            } else {
                var_v1 = 0x13;
            }
        } else {
            var_v1 = 0x14;
        }
    } else if (ptr->unk_00 == 2) {
        var_v1 = 0x15;
    } else if (ptr->unk_04 != 0) {
        var_v1 = 1;
    } else {
        var_v1 = 2;
    }
    return var_v1;
}

s32 func_81300314(s32 arg0) {
    UNUSED s32 pad;
    s32 sp18 = 0;
    s32 temp_v0 = func_81300254(arg0);

    if (gCurrentGameState == 0x25) {
        if (temp_v0 & 0x10) {
            switch (temp_v0) {
                case 20:
                    sp18 = 2;
                    break;

                case 19:
                    sp18 = 3;
                    break;

                case 21:
                    sp18 = 1;
                    break;

                case 22:
                    sp18 = 4;
                    break;
            }
        }
    } else if ((temp_v0 & 0x10) && (temp_v0 == 0x15)) {
        sp18 = 1;
    }
    return sp18;
}

void func_813003B4(s32 arg0, s32 arg1, s32 arg2) {
    s16 tmp2;
    s16 tmp1;

    if (D_81303FA8[arg0].unk_00 == 1) {
        tmp1 = 0x80;
    } else {
        tmp1 = 0xFF;
    }

    if (func_81300314(arg0) == 0) {
        func_81301668(arg1, arg2, 0x78, 0x38, 0x1E, 0x1E, 0x82, tmp1);
    } else {
        func_81301668(arg1, arg2, 0x78, 0x38, 0x64, 0x1E, 0x1E, tmp1);
    }

    if ((arg0 == D_81304000) && (D_81304650 == 1) && (func_81300314(arg0) > 0)) {
        func_8002053C(arg1 - 4, arg2 + 0x9C, 0x80, 0x74, &D_81303F14, &D_81303F14);
        tmp1 = arg1 + 0x28;
        tmp2 = (SINS(D_81303CB0 * 2) * 2) + (arg2 + 0x8C);
        func_81300870(D_3006060, tmp1, tmp2, 0x30, 0x10, 1.0f);
    }

    func_8001F3F4();
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001EBE0(8, 0);
    func_8001F3B4(0x18);

    if ((arg0 == D_81304000) && (D_81304650 == 1)) {
        switch (func_81300314(arg0)) {
            case 1:
                func_8001F1E8(arg1 + 5, arg2 + 0xAC, func_8002D7C0(NULL, 0, D_81304658, 0xE));
                break;

            case 2:
                func_8001F1E8(arg1 + 5, arg2 + 0xAC, func_8002D7C0(NULL, 0, D_81304658, 0xF));
                break;

            case 3:
                func_8001F1E8(arg1 + 5, arg2 + 0xAC, func_8002D7C0(NULL, 0, D_81304658, 0x10));
                break;

            case 4:
                func_8001F1E8(arg1 + 5, arg2 + 0xAC, func_8002D7C0(NULL, 0, D_81304658, 0x11));
                break;
        }
    }

    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);

    if (D_81303FA8[arg0].unk_00 == 0) {
        func_8001EBE0(8, 0);
        func_8001F1E8((arg1 - (func_8001F5B0(0, 0, D_81303FA8[arg0].unk_08) / 2)) + 0x3C, arg2 + 0xA,
                      D_81303FA8[arg0].unk_08);
        func_8001EBE0(4, 0);
        sprintf(D_81304660, "ID %05d", D_81303FA8[arg0].unk_06);
        func_8001F1E8((arg1 - (func_8001F5B0(0, 0, D_81304660) / 2)) + 0x3C, arg2 + 0x1E, D_81304660);
    } else if (D_81303FA8[arg0].unk_00 != 1) {
        func_8001EBE0(8, 0);
        func_8001F1E8((arg1 - (func_8001F5B0(0, 0, "?????") / 2)) + 0x3C, arg2 + 0xA, "?????");
        func_8001EBE0(4, 0);
        func_8001F1E8((arg1 - (func_8001F5B0(0, 0, "ID ?????") / 2)) + 0x3C, arg2 + 0x1E, "ID ?????");
    }

    func_8001F444();
}

void func_81300870(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, f32 arg5) {
    UNUSED s32 pad;
    Gfx* gfx;
    u16 a1;
    u16 a2;
    u16 tmp1;
    u16 tmp2;

    gfx = gDisplayListHead;

    if (arg5 == 0.0f) {
        return;
    }

    a1 = arg1 << 2;
    a2 = arg2 << 2;

    tmp1 = a1 + (4.0f * arg3 * arg5);
    tmp2 = a2 + (4.0f * arg4 * arg5);

    gDPPipeSync(gfx++);

    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTexturePersp(gfx++, G_TP_NONE);

    gDPPipeSync(gfx++);

    gDPLoadTextureBlock(gfx++, arg0, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg3, arg4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, a1, a2, tmp1, tmp2, G_TX_RENDERTILE, 0, 0, 1024.0f / arg5, 1024.0f / arg5);

    gDisplayListHead = gfx;
}

void func_81300DA4(void) {
    static s16 D_81303F30 = 0;
    static u16 D_81303F34[] = { 0, 0x6400, 0, 0xFF00 };

    s16 temp_v0 = (D_81303F30 + 0xA) & 0x1FF;

    D_81303F30 = 0x100;

    if (temp_v0 < D_81303F30) {
        D_81304A60 = temp_v0;
        D_81303F30 = temp_v0;
    } else {
        D_81304A60 = 0x1FF - temp_v0;
        D_81303F30 = temp_v0;
    }
}

void func_81300DF8(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, f32 arg5, s16 arg6) {
    Gfx* gfx = gDisplayListHead;
    u16 tmpa1;
    u16 tmpa2;
    u16 tmp1;
    u16 tmp2;
    u16 v;

    if (arg5 != 0.0f) {
        gDPPipeSync(gfx++);

        tmpa1 = arg1 << 2;
        tmpa2 = arg2 << 2;
        tmp1 = tmpa1 + ((4.0f * arg3) * arg5);
        tmp2 = tmpa2 + ((4.0f * arg4) * arg5);
        v = 1024.0f / arg5;

        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 230, D_81304A60 & 0xFF);
        gDPSetEnvColor(gfx++, 0, 50, 255, 0);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE,
                          ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0);
        gDPSetTextureLOD(gfx++, G_TL_TILE);
        gDPSetTextureFilter(gfx++, G_TF_BILERP);
        gDPSetTextureConvert(gfx++, G_TC_FILT);
        gDPSetTextureLUT(gfx++, G_TT_NONE);
        gDPSetTexturePersp(gfx++, G_TP_NONE);

        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, arg0, G_IM_FMT_I, G_IM_SIZ_8b, arg3, arg4, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        if (arg6 > 0) {
            gSPTextureRectangle(gfx++, tmpa1, tmpa2, tmp1, tmp2, G_TX_RENDERTILE, 0, 0, v, v);
        } else {
            gSPTextureRectangle(gfx++, tmpa1, tmpa2, tmp1, tmp2, G_TX_RENDERTILE, arg3 << 5, 0, -v, v);
        }

        gDisplayListHead = gfx;
    }
}

void func_81301668(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 temp_a2;
    s16 temp_s0_32;
    s16 var_s2;
    s16 var_s3;

    if ((arg2 < 0x20) && (arg2 & 1)) {
        arg2++;
    }

    if ((arg3 < 0x20) && (arg3 & 1)) {
        arg3++;
    }

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

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20288E0, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028960, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_20287E0, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3, 0x4000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_2028860, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x4000 / var_s3,
                  0x4000 / var_s2, 0);

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

void func_81301E8C(void) {
    static s32 D_81303F3C = 0;

    func_81300DA4();

    if (gCurrentGameState == 0x25) {
        func_81300870(D_81303F1C[D_81303F3C], 0x112, 0x11A, 0x30, 0x2A, 2.0f);
        D_81303F3C = (D_81303F3C + 1) % 5;
        func_81300DF8(D_30055B0, 0x98, 0xEE, 0x20, 0x23, 2.0f, 1);
        func_81300DF8(D_3004EF0, 0xC2, 0x100, 0x28, 0x2B, 2.0f, 1);
        func_81300DF8(D_30055B0, 0x1AA, 0xEE, 0x20, 0x23, 2.0f, -1);
        func_81300DF8(D_3004EF0, 0x172, 0xFC, 0x28, 0x2B, 2.0f, -1);
        func_81300DF8(D_3005A18, 0x102, 0xAC, 0x40, 0x19, 2.0f, 1);
    }

    if (D_81304000 >= 0) {
        func_81301668(0x38, 0x19A, 0x210, 0x28, 0x1E, 0x1E, 0x82, 0x80);
        func_8001F3F4();
        func_8001EBE0(0x10, 0);
        func_8001F1E8(0x132 - (func_8001F5B0(0, 0, func_8002D7C0(NULL, 0, D_81304658, 0x12)) / 2), 0x1A1,
                      func_8002D7C0(NULL, 0, D_81304658, 0x12));
        func_8001F444();
        func_813003B4(0, 0x38, 0x2E);
        func_813003B4(1, 0xBC, 0x2E);
        func_813003B4(2, 0x140, 0x2E);
        func_813003B4(3, 0x1C4, 0x2E);
        if (D_81304650 == 1) {
            func_800207FC((SINS(D_81303CB0) * 5.0f) + ((D_81304000 * 0x84) + 0x38), 0x7E);
        }
    } else {
        func_81301668(0x46, 0x146, 0x1F4, 0x78, 0x82, 0x1E, 0x1E, 0x80);
        func_8001F3F4();
        func_8001EBE0(0x10, 0);
        func_8001F3B4(0x1C);
        func_8001F1E8(0x5A, 0x15A, func_8002D7C0(NULL, 0, D_81304658, 0x13));
        func_8001F444();
    }
    D_81303CB0 += 0xB80;
}

void func_8130222C(void) {
    if (D_81304650 == 0) {
        return;
    }

    D_81304A62 = D_81304000;

    if (gPlayer1Controller->buttonPressed & 0x200) {
        while (true) {
            D_81304000 = (D_81304000 + 3) % 4;

            if (D_81303FA8[D_81304000].unk_01 != 0 || func_81300314(D_81304000) > 0) {
                break;
            }
        }
    } else if (gPlayer1Controller->buttonPressed & 0x100) {
        while (true) {
            D_81304000 = (D_81304000 + 1) % 4;

            if (D_81303FA8[D_81304000].unk_01 != 0 || func_81300314(D_81304000) > 0) {
                break;
            }
        }
    }

    if (D_81304000 != D_81304A62) {
        D_81303CB0 = 0;
        func_80048B90(0x25);
    }
}

void func_8130237C(void) {
    s32 var_v0;

    if (D_81304650 > 0) {
        if ((gPlayer1Controller->buttonPressed & 0x8000) && (D_81304A64 != 1)) {
            var_v0 = 0;
            if (D_81304000 < 0) {
                var_v0 = 1;
            }

            if ((var_v0 == 0) && (func_81300314(D_81304000) != 1)) {
                if (gCurrentGameState == 0x25) {
                    func_80048B90(0x2A);
                } else {
                    func_80048B90(0x2B);
                }
                D_81304A64 = 1;
                func_813001EC();
            } else {
                func_80048B90(8);
            }
        } else if ((gPlayer1Controller->buttonPressed & 0x4000) && (D_81304A64 != 2)) {
            func_80048B90(3);
            D_81304A64 = 2;
        } else if (D_81304000 >= 0) {
            func_8130222C();
        }
    }
}

void func_81302498(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_813024C8(s32 arg0) {
    func_800079C4();
    if (gCurrentGameState == 0x25) {
        func_8130306C(D_81303FA0);
    } else {
        func_8130337C();
    }

    if (arg0 != 0) {
        func_8130237C();
    }

    func_81301E8C();
    func_80015094(D_8130464C);
    func_80007778();
}

void func_81302548(void) {
    s32 i;
    u8 temp_s3;
    unk_D_800AC910_040 sp48;

    temp_s3 = Cont_GetControllerBits();

    for (i = 0; i < 4; i++) {
        func_80025040(i, &sp48);
        func_80021B5C(D_81303FA8[i].unk_08, sp48.unk_02);
        D_81303FA8[i].unk_06 = sp48.unk_00;
        D_81303FA8[i].unk_01 = func_80024F68(i);
        D_81303FA8[i].unk_00 = func_80024F00(i);
        D_81303FA8[i].unk_03 = func_80025370(i);
        D_81303FA8[i].unk_04 = (temp_s3 & (1 << i)) != 0;
        D_81303FA8[i].unk_02 = func_80024F8C(i);
    }
}

void func_81302630(void) {
    s32 i;
    s32 sp28 = func_80024EF4();
    s32 var_s1 = 0;

    if (sp28 == 0) {
        for (i = 0; i < 4; i++) {
            if (func_81300314(i) == 1) {
                var_s1++;
            }
        }
    }

    if ((sp28 == 0) && (var_s1 == 0)) {
        D_81304000 = -1;
        return;
    }

    D_81304000 = func_80029080();

    if (sp28 == 0) {
        D_81304000 = 0;
        while (func_81300314(D_81304000) != 1) {
            D_81304000++;
        }
    } else if ((D_81304000 == -1) || (D_81303FA8[D_81304000].unk_01 == 0)) {
        D_81304000 = 0;
        while (D_81303FA8[D_81304000].unk_01 == 0) {
            D_81304000++;
        }
    }
}

void func_81302798(void) {
    static s16 D_81303F40[] = { 0x5C0, 0x680, 0x580, 0 };

    f32 var_fv0;
    f32 var_fv1;
    s16 var_a1;
    s32 var_s1;
    unk_D_81304008* var_s0;
    unk_D_86002F58_004_000* var_v0;
    s32 i;

    for (i = 0, var_s0 = &D_81304008[0]; i < 4; i++, var_s0++) {
        switch (var_s0->unk_000) {
            case 0:
                if (i == D_81304000) {
                    var_fv0 = 1.5f;
                    var_s0->unk_00A = D_81303CB0 + 0x4000;
                    var_a1 = 0;
                    var_fv1 = 0.06f;
                    var_s1 = 0x3000;
                } else {
                    var_fv0 = 1.0f;
                    var_a1 = D_81303F40[0];
                    var_fv1 = 0.02f;
                    var_s1 = 0x2000;
                }

                var_s0->unk_004 = var_s0->unk_00E - (SINS(var_s0->unk_00A) * (6.0f * var_fv0));
                var_s0->unk_010 = SINS(var_s0->unk_00A) * (1536.0f * var_fv0);
                var_s0->unk_014 = (SINS(var_s0->unk_00C) * var_fv1) + 1.0f;
                var_s0->unk_018 = (COSS(var_s0->unk_00C) * var_fv1) + 1.0f;

                var_s0->unk_00A += var_a1;
                var_s0->unk_00C += var_s1 + ((MathUtil_Random16() & 0xF) * 0x10);

                var_s0->unk_028.unk_024.z = -579.0f;
                var_s0->unk_028.unk_01E.z = var_s0->unk_010;
                var_s0->unk_028.unk_030.x = var_s0->unk_014;
                var_s0->unk_028.unk_030.y = var_s0->unk_018;
                break;

            case 1:
                var_v0 = &var_s0->unk_028;

                var_v0->unk_024.x += var_s0->unk_020;
                if (var_s0->unk_020 < 0.0f) {
                    if (var_v0->unk_024.x < 0.0f) {
                        var_v0->unk_024.x = 0.0f;
                    }
                } else if ((var_s0->unk_020 > 0.0f) && (var_v0->unk_024.x > 0.0f)) {
                    var_v0->unk_024.x = 0.0f;
                }

                var_v0->unk_024.y += var_s0->unk_024 * 0.5f;
                var_v0->unk_024.z = -569.0f;
                var_s0->unk_024 -= 4.0f;

                var_v0->unk_01E.z = 0;
                var_v0->unk_030.x = 1.0f;
                var_v0->unk_030.y = 1.0f;
                break;
        }
    }
}

s32 func_81302A70(s32 arg0) {
    s32 var_s0 = 1;
    s32 var_s1 = 0;
    s32 i;

    func_80006C6C(8);

    while (func_80007604() != 0) {
        func_81302498();
        func_81302798();
        func_813024C8(0);
    }

    if (arg0 == 1) {
        func_8004B1CC(9);
    }

    while (var_s0 != 0) {
        func_81302498();
        func_81302798();
        func_813024C8(1);

        if (D_81304A64 > 0) {
            if (gPlayer1Controller->buttonPressed & 0x8000) {
                var_s0 = 0;
            } else if (gPlayer1Controller->buttonPressed & 0x4000) {
                var_s1 = -1;
                var_s0 = 0;
            }
        }
    }

    if (var_s1 != -1) {
        for (i = 0; i < 20; i++) {
            func_81302498();
            func_81302798();
            func_813024C8(1);
        }
    }

    if ((arg0 == 1) && (var_s1 == -1)) {
        func_8004B9C4(0x20);
    }

    func_80007990(1);
    func_80006CB4(8);

    while (func_80007604() != 1) {
        func_81302498();
        func_81302798();
        func_813024C8(0);
    }

    if ((var_s1 != -1) && (D_81304000 >= 0)) {
        func_8002908C(D_81304000);
    }

    return var_s1;
}

void func_81302C20(void) {
    static s16 D_81303F48[] = { 1, 2, 0, 3 };

    unk_D_86002F58_004_000* ptr;
    s32 temp_s1;
    s32 i;

    D_81304A64 = 0;

    for (i = 0; i < 4; i++) {
        temp_s1 = D_81303F48[i];
        ptr = &D_81304008[temp_s1].unk_028;

        func_8001BB58(ptr);
        func_8000E88C(&ptr->unk_024, ((temp_s1 * 0x84) + 0x7A) - 320.0f, 64.0f, -579.0f);
        D_81304008[temp_s1].unk_002 = temp_s1;
        D_81304008[temp_s1].unk_000 = 0;

        switch (func_80024F68(temp_s1)) {
            case 1:
                D_81304008[temp_s1].unk_01C = D_201E420;
                break;

            case 2:
                D_81304008[temp_s1].unk_01C = D_2020420;
                break;

            case 3:
                D_81304008[temp_s1].unk_01C = D_2022420;
                break;

            case 7:
                D_81304008[temp_s1].unk_01C = D_2024420;
                break;

            default:
                D_81304008[temp_s1].unk_01C = NULL;
                if (func_81300314(temp_s1) > 0) {
                    D_81304008[temp_s1].unk_01C = D_3006668;
                }
                break;
        }

        func_8001BC34(ptr, 0, 0, D_81304648);
        ptr->unk_000.unk_14 = temp_s1;
    }
}

void func_81302DD8(void) {
    MemoryBlock* sp1C = func_80002D10(main_pool_get_available(), 0);

    D_8130464C = process_geo_layout(sp1C, &D_81303CB4);
    D_81304648 = process_geo_layout(sp1C, &D_81303EC0);
    func_80002D60(sp1C);
    func_8001BB20();
    func_81302C20();
    D_81304650 = 1;
}

s32 func_81302E58(s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;
    s32 sp20;

    main_pool_push_state('GBSL');

    func_80005E40(0x10000, 0);
    sp24 = func_80007444(1, 0, 2, 0, 2, 1);
    func_8001E94C(0x1C, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_8000000, _6EC4D0, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);
    ASSET_LOAD(D_3000000, trade_select_ui, 0);
    ASSET_LOAD(D_3000000_2, gb_pak_select_ui, 0);

    FRAGMENT_LOAD(fragment31);

    func_8001987C();
    func_8001B058();
    func_81302548();
    func_81302630();
    func_8002D510();
    D_81304658 = func_8002D5AC(0x1F);
    func_81302DD8();
    D_81304654 = func_813001C0();

    D_81303FA0 = ASSET_LOAD(0, fragment33_misc, 0);

    func_80007678(sp24);
    sp20 = func_81302A70(arg0);
    func_800076C0();
    func_80005EAC();

    main_pool_pop_state('GBSL');

    return sp20;
}

#ifdef NON_MATCHING
void func_8130306C(u8* arg0) {
    Gfx* gfx = gDisplayListHead;
    u8* var_t0;
    s32 i;
    s32 j;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, G_ZBUFFER);
    gSPSetGeometryMode(gfx++, 0);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTexturePersp(gfx++, G_TP_NONE);

    for (i = 0; i < 15; i++) {
        var_t0 = ((i * 0x14) << 9) + arg0;
        for (j = 0; j < 20; j++, var_t0 += 0x200) {
            gDPPipeSync(gfx++);

            gDPLoadTextureBlock(gfx++, var_t0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gfx++, (j * 0x20) << 2, (i * 0x20) << 2, ((j + 1) * 0x20) << 2, ((i + 1) * 0x20) << 2,
                                G_TX_RENDERTILE, 0, 0, 0x0200, 0x0200);
        }
    }

    gDisplayListHead = gfx;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/33/fragment33/func_8130306C.s")
#endif

#ifdef NON_MATCHING
void func_8130337C(void) {
    Gfx* gfx = gDisplayListHead;
    u8* sp30;
    s32 i;

    gDPPipeSync(gfx++);

    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, G_ZBUFFER);
    gSPSetGeometryMode(gfx++, 0);
    gDPSetCombineMode(gfx++, G_CC_BLENDPEDECALA, G_CC_BLENDPEDECALA);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTexturePersp(gfx++, G_TP_NONE);

    gDPPipeSync(gfx++);

    gDPLoadTextureBlock_4b(gfx++, D_3008670, G_IM_FMT_IA, 128, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 7, 7, G_TX_NOLOD, G_TX_NOLOD);

    for (i = 0; i < 8; i++) {
        gDPPipeSync(gfx++);

        gDPSetPrimColor(gfx++, 0, 0, (0xBE0 - (i * 0xBE)) / 16, (0xDC0 - (i * 0xDC)) / 16, (0x7D0 - (i * 0x7D)) / 16,
                        255);
        gDPSetEnvColor(gfx++, (0x140 - (i * 0x14)) / 16, (0x5F0 - (i * 0x5F)) / 16, (0xA0 - (i * 10)) / 16, 255);
        gSPTextureRectangle(gfx++, 0, (i * 0x40) << 2, 0x0A00, ((i + 1) * 0x40) << 2, G_TX_RENDERTILE, 0, 0, 0x0400,
                            0x0400);
    }

    switch (D_81304654) {
        default:
            sp30 = D_3009678;
            break;

        case 0:
            sp30 = D_3009678;
            break;

        case 1:
            sp30 = D_3012D80;
            break;

        case 2:
            sp30 = D_301C488;
            break;
    }

    gDPSetRenderMode(gfx++, AA_EN | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | G_RM_PASS,
                     AA_EN | CVG_DST_CLAMP | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | G_RM_NOOP2);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPPipeSync(gfx++);

    gDPLoadTextureBlock(gfx++, &sp30[0], G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gfx++, 0x03E8, 0x0334, 0x05E8, 0x0374, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);

    for (i = 0; i < 4; i++) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, &sp30[0x1000 + (i * 0x2000)], G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gfx++, 0x03E8, (0xDD + (i * 0x20)) << 2, 0x05E8, (0xED + (i * 0x20)) << 2, G_TX_RENDERTILE,
                            0, 0, 0x0400, 0x0400);

        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, &sp30[0x2000 + (i * 0x2000)], G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gfx++, 0x03E8, (0xED + (i * 0x20)) << 2, 0x05E8, (0xFD + (i * 0x20)) << 2, G_TX_RENDERTILE,
                            0, 0, 0x0400, 0x0400);
    }

    gDPLoadTextureBlock(gfx++, &sp30[0x9000], G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 7, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gfx++, 0x03E8, 0x0574, 0x05E8, 0x0590, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);

    gDisplayListHead = gfx;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/33/fragment33/func_8130337C.s")
#endif
