#include "common.h"
#include "stage_loader.h"
#include "memory.h"
#include "string.h"
#include "dp_intro.h"
#include "6BC0.h"
#include "6A40.h"
#include "memmap.h"
#include "util.h"
#include "profiler.h"
#include "PR/xstdio.h"

typedef struct unk_D_80068CA0 {
    /* 0x00 */ struct unk_D_80068CA0* next;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s8 unk_08[4];
} unk_D_80068CA0; // size = 0xC

static s32 D_80068BC0_Pad[2] = { 0, 0 };

static Mtx D_80068BC8 = { {
    {
        0x00010000,
        0x00000000,
        0x00000001,
        0x00000000,
    },
    {
        0x00000000,
        0x00010000,
        0x00000000,
        0x00000001,
    },
    {
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
    },
    {
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
    },
} };

static Vp D_80068C08 = { {
    {
        0x0280,
        0x01E0,
        0x01FF,
        0x0000,
    },
    {
        0x0280,
        0x01E0,
        0x01FF,
        0x0000,
    },

} };

static Vp D_80068C18 = { {
    {
        0x0500,
        0x03C0,
        0x01FF,
        0x0000,
    },
    {
        0x0500,
        0x03C0,
        0x01FF,
        0x0000,
    },
} };

static Vtx D_80068C28[] = {
    VTX(0, 240, 0, 0, 0, 0x00, 0x00, 0x81, 0xFF),
    VTX(0, 0, 0, 0, 0, 0x00, 0x00, 0x81, 0xFF),
    VTX(320, 0, 0, 0, 0, 0x00, 0x00, 0x81, 0xFF),
    VTX(320, 240, 0, 0, 0, 0x00, 0x00, 0x81, 0xFF),
};

static Gfx D_80068C68[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2),
    gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT),
    gsSPVertex(D_80068C28, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

static s32 D_80068C98_Pad[2] = { 0, 0 };

static unk_D_80068CA0* D_80068CA0 = NULL;
static unk_D_80068CA0* D_80068CA4 = NULL;

static s32 D_80068CA8 = 0;

static s32 D_80068BAC_Pad[1] = { 0 };

static u32 D_80068CB0[] = {
    0x00000000, 0xF1000F1F, 0x10000000, 0x00F10000, 0x00000FF1, 0x0000F100, 0x000F100F, 0x10000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xF1000F1F, 0x100F1F10, 0x0FFFF1F1, 0x00F1F11F, 0x1000F100,
    0x00F11001, 0xF100F100, 0xF100F100, 0x00000000, 0x00000000, 0x000000F1, 0x00000000, 0xF1000111, 0x10FFFFF1,
    0xF1F11111, 0x0F11F1F1, 0x10001100, 0x0F110000, 0x1F101F1F, 0x1100F100, 0x00000000, 0x00000000, 0x00000F11,
    0x00000000, 0xF1000000, 0x001F1F11, 0x1FFF1000, 0xF1101F11, 0x00000000, 0x0F100000, 0x0F1001F1, 0x10FFFFF1,
    0x0000000F, 0xFF100000, 0x0000F110, 0x00000000, 0xF1000000, 0x00FFFFF1, 0x01F1F10F, 0x1100F1F1, 0xF1000000,
    0x0F100000, 0x0F100F1F, 0x1011F111, 0x00000001, 0x11100000, 0x000F1100, 0x00000000, 0x11000000, 0x001F1F11,
    0xFFFF11F1, 0x10F1F11F, 0x11000000, 0x01F10000, 0xF110F111, 0xF100F100, 0x00F10000, 0x00000000, 0x00F11000,
    0x00000000, 0xF1000000, 0x00011110, 0x11F11011, 0x00111FF1, 0xF1000000, 0x001F100F, 0x11001100, 0x11001100,
    0x0F110000, 0x000000F1, 0x00110000, 0x00000000, 0x11000000, 0x00000000, 0x00110000, 0x00000111, 0x11000000,
    0x00011001, 0x10000000, 0x00000000, 0x01100000, 0x00000011, 0x00000000, 0x0FFF1000, 0xF1000FFF, 0x100FFF10,
    0x00FF10FF, 0xFFF10FFF, 0x10FFFFF1, 0x0FFF100F, 0xFF100000, 0x00000000, 0x00000000, 0x00000000, 0x000FFF10,
    0xF111F10F, 0xF100F111, 0xF1F111F1, 0x0F1F10F1, 0x1111F111, 0xF1F111F1, 0xF111F1F1, 0x11F10000, 0x00000000,
    0x000F1000, 0x00000F10, 0x00F111F1, 0xF100F101, 0xF1001100, 0xF11100F1, 0xF11F10FF, 0xFF10F100, 0x111100F1,
    0xF100F1F1, 0x00F100F1, 0x0000F100, 0x00F1100F, 0xFF1001F1, 0x001100F1, 0xF100F100, 0xF10000FF, 0x110FFF11,
    0xF10F1011, 0x11F1FFFF, 0x10000F11, 0x1FFF111F, 0xFFF10011, 0x00001100, 0x0F110001, 0x1110001F, 0x10000F11,
    0xF100F100, 0xF1000F11, 0x100111F1, 0xFFFFF100, 0x00F1F111, 0xF100F110, 0xF111F101, 0x11F100F1, 0x0000F100,
    0x01F1000F, 0xFF1000F1, 0x1000F110, 0xF100F100, 0xF100F110, 0x00F100F1, 0x111F11F1, 0x00F1F100, 0xF100F100,
    0xF100F1F1, 0x00F10011, 0x000F1100, 0x001F1001, 0x11100F11, 0x00001100, 0x1FFF110F, 0xFF10FFFF, 0xF11FFF11,
    0x000F101F, 0xFF111FFF, 0x1100F100, 0x1FFF111F, 0xFF110000, 0x00011000, 0x00011000, 0x00000110, 0x0000F100,
    0x01111001, 0x11101111, 0x11011110, 0x00011001, 0x11100111, 0x10001100, 0x01111001, 0x11100000, 0x00000000,
    0x00000000, 0x00000000, 0x00001100, 0x0FFF1000, 0xF100FFFF, 0x100FFF10, 0xFFF100FF, 0xFFF1FFFF, 0xF10FFF10,
    0xF100F10F, 0xFF100000, 0xF1F100F1, 0xF10000F1, 0x00F1F100, 0xF10FFF10, 0xF111100F, 0x1F10F111, 0xF1F111F1,
    0xF11F10F1, 0x1111F111, 0x11F111F1, 0xF100F101, 0xF1100000, 0xF1F10F11, 0xF10000FF, 0x1FF1F100, 0xF1F111F1,
    0xF1FF10F1, 0x11F1F100, 0xF1F10011, 0xF101F1F1, 0x0000F100, 0x00F10011, 0xF100F100, 0xF1000000, 0xF1F1F110,
    0xF10000F1, 0xF1F1FF10, 0xF1F100F1, 0xF1F1F1F1, 0x00F1FFFF, 0x11F10000, 0xF100F1FF, 0xFF10FFFF, 0x10F1FFF1,
    0xFFFFF100, 0xF1000000, 0xF1FF1100, 0xF10000F1, 0xF1F1F1F1, 0xF1F100F1, 0xF1FFF1FF, 0xFFF1F111, 0xF1F10000,
    0xF100F1F1, 0x1110F111, 0x10F111F1, 0xF111F100, 0xF100F100, 0xF1F1F100, 0xF10000F1, 0x11F1F11F, 0xF1F100F1,
    0xF111F1F1, 0x11F1F100, 0xF1F100F1, 0xF10F11F1, 0x0000F100, 0x00F100F1, 0xF100F100, 0xF100F100, 0xF1F11F10,
    0xF10000F1, 0x00F1F101, 0xF1F100F1, 0x1FFF11F1, 0x00F1FFFF, 0x111FFF11, 0xFFF110FF, 0xFFF1F100, 0x001FFF11,
    0xF100F10F, 0xFF101FFF, 0x11F101F1, 0xFFFFF1F1, 0x00F1F100, 0xF11FFF11, 0x01111011, 0x00111111, 0x10011110,
    0x11110011, 0x11111100, 0x00011110, 0x11001101, 0x11100111, 0x10110011, 0x11111111, 0x00111100, 0x11011110,
    0xFFFF100F, 0xFF10FFFF, 0x100FFF10, 0xFFFFF1F1, 0x00F1F100, 0xF1F100F1, 0xF100F1F1, 0x00F1FFFF, 0xF100FF10,
    0x0000000F, 0xF10000F1, 0x00000000, 0xF111F1F1, 0x11F1F111, 0xF1F111F1, 0x11F111F1, 0x00F1F100, 0xF1F100F1,
    0xF100F1F1, 0x00F11111, 0xF100F110, 0xF1000001, 0xF1000F1F, 0x10000000, 0xF100F1F1, 0x00F1F100, 0xF1F10011,
    0x00F100F1, 0x00F1F100, 0xF1F100F1, 0x1F1F11F1, 0x00F1000F, 0x1100F100, 0x1F100000, 0xF100F111, 0xF1000000,
    0xF100F1F1, 0x00F1F100, 0xF11FFF10, 0x00F100F1, 0x00F1F100, 0xF1F1F1F1, 0x01F1101F, 0x1F1100F1, 0x1000F100,
    0x01F10000, 0xF1001100, 0x11000000, 0xFFFF11F1, 0xF1F1FFFF, 0x110111F1, 0x00F100F1, 0x00F11F1F, 0x11F1F1F1,
    0x0F1F1001, 0xF1100F11, 0x0000F100, 0x001F1000, 0xF1000000, 0x00000000, 0xF11110F1, 0x1F11F11F, 0x10F100F1,
    0x00F100F1, 0x00F10F1F, 0x10F1F1F1, 0xF111F100, 0xF100F110, 0x0000F100, 0x0001F100, 0xF1000000, 0x00000000,
    0xF100001F, 0xF1F1F101, 0xF11FFF11, 0x00F1001F, 0xFF1101F1, 0x101F1F11, 0xF100F100, 0xF100FFFF, 0xF100FF10,
    0x0000110F, 0xF1000000, 0x00FFFFF1, 0x11000001, 0x11111100, 0x11011110, 0x00110001, 0x11100011, 0x00011110,
    0x11001100, 0x11001111, 0x11001110, 0x00000001, 0x11000000, 0x00111111, 0x00000000, 0x0000F100, 0x00000000,
    0x000F1000, 0x000000FF, 0x10000000, 0xF1000000, 0x00000000, 0x00F10000, 0x0FF10000, 0x00000000, 0x00000000,
    0x00000000, 0x0000F100, 0x00000000, 0x000F1000, 0x00000F11, 0x100FF100, 0xF1000000, 0xF100000F, 0x10F10000,
    0x01F10000, 0x00000000, 0x00000000, 0x0000000F, 0xF100FFF1, 0x000FF100, 0x0FFF100F, 0xF1000F10, 0x00F11F10,
    0xFFF10000, 0x11000001, 0x10F10F10, 0x00F1000F, 0x1F10FFF1, 0x000FF100, 0x00000001, 0x1F10F11F, 0x10F11F10,
    0xF11F10F1, 0x1F10FFF1, 0x00F10F10, 0xF11F1000, 0xF100000F, 0x10F1F110, 0x00F100F1, 0xF1F1F11F, 0x10F11F10,
    0x0000000F, 0xFF10F10F, 0x10F10110, 0xF10F10FF, 0xFF101F11, 0x001FFF10, 0xF10F1000, 0xF100000F, 0x10FF1100,
    0x00F100F1, 0xF1F1F10F, 0x10F10F10, 0x000000F1, 0x1F10F10F, 0x10F10F10, 0xF10F10F1, 0x11100F10, 0x00011F10,
    0xF10F1000, 0xF100F10F, 0x10F1F100, 0x00F100F1, 0xF1F1F10F, 0x10F10F10, 0x0000001F, 0xF1F1FFF1, 0x101FF110,
    0x1FFF101F, 0xFF100F10, 0x000FF110, 0xF10F1000, 0xF1001FF1, 0x10F11F10, 0x0FFF10F1, 0xF1F1F10F, 0x101FF110,
    0x00000001, 0x11111111, 0x00011100, 0x01111001, 0x11100110, 0x00011100, 0x11011000, 0x11000111, 0x00110110,
    0x01111011, 0x11111101, 0x10011100, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000F10, 0x00F1000F, 0x1000FFFF, 0xF1000000, 0x00000000, 0x00000000, 0x00000000,
    0x00F10000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000F110, 0x00F10001, 0xF1001111, 0x11000000,
    0x0FF1000F, 0xF100F1FF, 0x100FFFF1, 0x00F100F1, 0x0F10F100, 0xF1F100F1, 0xF100F1F1, 0x0F10FFFF, 0x1000F100,
    0x00F10000, 0xF1000000, 0x00000000, 0xF11F10F1, 0x1F10FF11, 0x10F11111, 0x0FFF10F1, 0x0F10F100, 0xF1F1F1F1,
    0x1F1F11F1, 0x0F10111F, 0x100F1100, 0x00110000, 0x1F100000, 0x00000000, 0xF10F10F1, 0x0F10F110, 0x001FFF10,
    0x01F110F1, 0x0F10F100, 0xF1F1F1F1, 0x01F1101F, 0xFF100FF1, 0x1001F100, 0x00F10000, 0xF1100000, 0x00000000,
    0xFFF1101F, 0xFF10F100, 0x000111F1, 0x00F100F1, 0x0F101F1F, 0x11F1F1F1, 0x0F1F1001, 0x1F10F111, 0x0000F100,
    0x00F10000, 0xF1000000, 0x00000000, 0xF1110001, 0x1F10F100, 0x00FFFF11, 0x00FF101F, 0xF11001F1, 0x101F1F11,
    0xF111F10F, 0xF110FFFF, 0x10001F10, 0x00F1000F, 0x11000000, 0x00000000, 0x11000000, 0x01101100, 0x00111110,
    0x00111001, 0x11000011, 0x00011110, 0x11001101, 0x11001111, 0x10000110, 0x00110001, 0x10000000, 0x00000000,
};

s32 func_80007A58(void);
void func_80007FC4(Gfx**, s32);
void func_800080E0(void);

#ifdef NON_MATCHING
void func_800069F0(void) {
    u8 a;
    u8 b;
    u8 g;
    u8 r;

    if (D_800A7464->unk_11 == 0) {
        return;
    }

    r = RGBA16_GET_R(D_800A7464->unk_14);
    g = RGBA16_GET_G(D_800A7464->unk_14);
    b = RGBA16_GET_B(D_800A7464->unk_14);

    r = ((r << 3) | (r >> 2)) & 0xFF;
    g = ((g << 3) | (g >> 2)) & 0xFF;
    b = ((b << 3) | (b >> 2)) & 0xFF;

    switch (D_800A7464->unk_11) {
        default:
            a = a;
            break;

        case 1:
            a = 0xFF;
            break;

        case 2:
            a = (0xFF - ((D_800A7464->unk_13 * 0xFF) / D_800A7464->unk_12));
            break;

        case 3:
            a = ((D_800A7464->unk_13 * 0xFF) / D_800A7464->unk_12);
            break;
    }

    if (a != 0) {
        gDPSetEnvColor(gDisplayListHead++, r, g, b, a);
        gSPDisplayList(gDisplayListHead++, D_80068C68);
    }

    if (D_800A7464->unk_11 == 1) {
        return;
    }

    D_800A7464->unk_13++;
    if (D_800A7464->unk_13 == D_800A7464->unk_12) {
        if (D_800A7464->unk_11 == 2) {
            D_800A7464->unk_11 = 0;
        } else {
            D_800A7464->unk_11 = 1;
        }
    }
}
#else
void func_800069F0(void);
#pragma GLOBAL_ASM("asm/nonmatchings/stage_loader/func_800069F0.s")
#endif

s32 func_80006C04(s32 arg0) {
    s32 ret = 0;

    if ((D_800A7464 != NULL) && ((D_800A7464->unk_11 == 1) || (D_800A7464->unk_11 == 0))) {
        if (D_800A7464->unk_11 == 1) {
            D_800A7464->unk_11 = 2;
        } else {
            D_800A7464->unk_11 = 3;
        }

        ret = 1;
        D_800A7464->unk_13 = 0;
        D_800A7464->unk_12 = arg0;
    }

    return ret;
}

s32 func_80006C6C(s32 arg0) {
    s32 ret = 0;

    if ((D_800A7464 != NULL) && (D_800A7464->unk_11 == 1)) {
        ret = func_80006C04(arg0);
    }

    return ret;
}

s32 func_80006CB4(s32 arg0) {
    s32 ret = 0;

    if ((D_800A7464 != NULL) && (D_800A7464->unk_11 == 0)) {
        ret = func_80006C04(arg0);
    }

    return ret;
}

void func_80006CF8(s32 arg0) {
    if (D_800A7464 != NULL) {
        D_800A7464->unk_11 = arg0;
        D_800A7464->unk_13 = 0;
        D_800A7464->unk_12 = 0;
    }
}

void func_80006D28(u32 arg0, u32 arg1) {
    if (arg0 < 3) {
        gShowCPUProfiler = arg0;
    }

    if (arg1 < 2) {
        gShowMEMProfiler = arg1;
    }
}

void func_80006D50(void) {
    gDPPipeSync(gDisplayListHead++);
    gDPPipelineMode(gDisplayListHead++, G_PM_1PRIMITIVE);
    gDPSetTextureLOD(gDisplayListHead++, G_TL_TILE);
    gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
    gDPSetTextureDetail(gDisplayListHead++, G_TD_CLAMP);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gDPSetTextureConvert(gDisplayListHead++, G_TC_FILT);
    gDPSetCombineKey(gDisplayListHead++, G_CK_NONE);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);
    gDPSetColorDither(gDisplayListHead++, G_CD_MAGICSQ);
    gDPSetAlphaDither(gDisplayListHead++, G_AD_PATTERN);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPPipeSync(gDisplayListHead++);
}

void func_80006F34(void) {
    gSPClearGeometryMode(gDisplayListHead++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                                 G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gDisplayListHead++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gSPTexture(gDisplayListHead++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
}

void func_80006F98(void) {
    func_80006450();
    Memmap_SetSegmentMap(0, 0x80000000, osMemSize);
    Memmap_SetSegments(&gDisplayListHead);
    func_80006D50();
    func_80006F34();
}

void func_80006FE8(void) {
    func_80006498(&gDisplayListHead, D_800A7464->unk_18[D_800A7464->unk_16]);
    guOrtho(&D_800A7468, 0.0f, 320.0f, 0.0f, 240.0f, -2.0f, 2.0f, 1.0f);
    func_80006D50();
    func_80006F34();

    gSPMatrix(gDisplayListHead++, (u32)&D_80068BC8 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gDisplayListHead++, (u32)&D_800A7468 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

    if (D_800A7464->unk_0C == 1) {
        gSPViewport(gDisplayListHead++, (u32)&D_80068C18 & 0x1FFFFFFF);
    } else {
        gSPViewport(gDisplayListHead++, (u32)&D_80068C08 & 0x1FFFFFFF);
    }

    func_800060E0(&gDisplayListHead, 0, 0, D_800A7464->unk_00, D_800A7464->unk_02);
    func_800069F0();

    if (gShowCPUProfiler != 0) {
        print_profiler_metrics();
    }

    func_80007FC4(&gDisplayListHead, func_80007A58());

    if (gShowCPUProfiler != 0) {
        draw_profiler(gShowCPUProfiler - 1);
    }

    if ((gShowCPUProfiler != 0) && (gShowMEMProfiler != 0)) {
        Util_DrawMemProfiler(&gDisplayListHead);
    }

    gDPFullSync(gDisplayListHead++);
    gSPEndDisplayList(gDisplayListHead++);

    func_80005F5C(0);
}

void func_80007234(void) {
    func_80005EDC();
    func_80006F98();
}

void func_8000725C(void) {
    func_80006FE8();
    D_800A7450.unk_00 = D_800A7464->unk_10;
    D_800A7450.unk_01 = D_800A7464->unk_0C;
    D_800A7450.unk_02 = D_800A7464->unk_0D;
    D_800A7450.unk_03 = D_800A7464->unk_16;
    D_800A7450.unk_0C = D_800A7464->unk_18[D_800A7464->unk_16];
    func_80005F1C(&D_800A7450.unk_04, &D_800A7450.unk_08);
    D_800A7464->unk_16++;
    if (D_800A7464->unk_16 == D_800A7464->unk_0E) {
        D_800A7464->unk_16 = 0;
    }
}

void func_80007304(void) {
    func_800079C4();

    gDPPipeSync(gDisplayListHead++);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetFillColor(gDisplayListHead++, (D_800A7464->unk_14 << 0x10) | D_800A7464->unk_14);
    gDPFillRectangle(gDisplayListHead++, D_800A7464->unk_04, D_800A7464->unk_08, D_800A7464->unk_06,
                     D_800A7464->unk_0A);
    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
}

unk_func_80007444* func_80007444(s8 arg0, s8 arg1, s8 arg2, s8 arg3, s8 arg4, s32 arg5) {
    unk_func_80007444* temp_v0 = main_pool_alloc(0x24, 0);

    if (temp_v0 != NULL) {
        if (arg0 == 1) {
            temp_v0->unk_00 = 0x280, temp_v0->unk_02 = 0x1E0;
        } else {
            temp_v0->unk_00 = 0x140, temp_v0->unk_02 = 0xF0;
        }

        temp_v0->unk_11 = 1;
        temp_v0->unk_0C = arg0;
        temp_v0->unk_0D = arg1;
        temp_v0->unk_0E = arg2;
        temp_v0->unk_0F = arg3;
        temp_v0->unk_10 = arg4;
        temp_v0->unk_14 = func_80001B2C();
        temp_v0->unk_16 = 0;
        temp_v0->unk_04 = 0;
        temp_v0->unk_06 = temp_v0->unk_00 - 1;
        temp_v0->unk_08 = 0;
        temp_v0->unk_0A = temp_v0->unk_02 - 1;

        temp_v0->unk_18[0] = 0;
        temp_v0->unk_18[1] = 0;
        temp_v0->unk_18[2] = 0;

        if (arg5 != 0) {
            s32 i;

            for (i = 0; i < temp_v0->unk_0E; i++) {
                temp_v0->unk_18[i] = func_80006314(0, 2, temp_v0->unk_00, temp_v0->unk_02, 1);
            }

            if (temp_v0->unk_0F == 1) {
                void* temp_s3 = func_80006314(0, 2, temp_v0->unk_00, temp_v0->unk_02, 0);

                for (i = 0; i < temp_v0->unk_0E; i++) {
                    func_80006414(temp_v0->unk_18[i], temp_s3);
                }
            }
        }
    }

    return temp_v0;
}

unk_func_80007444* func_800075F8(void) {
    return D_800A7464;
}

s32 func_80007604(void) {
    return D_800A7464->unk_11;
}

void func_80007614(unk_func_80007444* arg0) {
    arg0->unk_11 = D_800A7464->unk_11;
    arg0->unk_12 = D_800A7464->unk_12;
    arg0->unk_13 = D_800A7464->unk_13;
    arg0->unk_14 = D_800A7464->unk_14;

    if (D_800A7464->unk_16 < arg0->unk_0E) {
        arg0->unk_16 = D_800A7464->unk_16;
    } else {
        arg0->unk_16 = 0;
    }

    D_800A7464 = arg0;
}

void func_80007678(unk_func_80007444* arg0) {
    D_800A7464 = arg0;
    func_80001BA8(NULL);
    func_80001B7C();
    func_80001AD4(arg0->unk_14);
    func_80007234();
}

void func_800076C0(void) {
    if (D_800A7464 != NULL) {
        func_80007304();
        func_8000725C();
        func_80001BA8(&D_800A7450);
        func_80001B7C();
        func_80001BD4(2);
        D_800A7464 = NULL;
    }
}

void func_8000771C(void) {
    while (func_80001C90() == 0) {}
}

void func_80007754(void) {
    Memmap_SetSegments(&gDisplayListHead);
}

s32 func_80007778(void) {
    func_8000725C();
    func_80001BA8(&D_800A7450);
    func_80001B7C();
    func_80007234();
}

void func_800077B4(s32 arg0) {
    while (arg0-- > 0) {
        func_80007304();
        func_8000725C();
        func_80001BA8(&D_800A7450);
        func_80001B7C();
        func_80007234();
    }
}

s32 func_80007820(u32 arg0, s32 (*arg1)(u8)) {
    s32 var_s1 = 0;

    if (arg0 == 0) {
        while (var_s1 == 0) {
            var_s1 = arg1(D_800A7464->unk_11);
            func_80007778();
        }
    } else {
        while (arg0-- > 0) {
            var_s1 = arg1(D_800A7464->unk_11);
            func_80007778();
            if (var_s1 != 0) {
                break;
            }
        }
    }
    return var_s1;
}

s32 func_800078D4(s32 (*arg0)(u8), s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_s2;

    var_s2 = 0;
    var_s0 = 1;
    func_80006C6C(arg1);

    while (var_s0 != 0) {
        temp_v0 = arg0(D_800A7464->unk_11);
        if (var_s2 == 0) {
            if (temp_v0 != 0) {
                var_s2 = temp_v0;
                func_80006CB4(arg2);
            }
        } else if (D_800A7464->unk_11 == 1) {
            var_s0 = 0;
        }
        func_80007778();
    }

    return var_s2;
}

void func_80007990(u16 arg0) {
    if (D_800A7464 != NULL) {
        D_800A7464->unk_14 = arg0;
        func_80001AD4(arg0);
    }
}

void func_800079C4(void) {
    if (D_800A7464 != NULL) {
        func_80006498(&gDisplayListHead, D_800A7464->unk_18[D_800A7464->unk_16]);

        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    }
}

void* func_80007A2C(void) {
    void* ret = NULL;

    if (D_800A7464 != NULL) {
        ret = D_800A7464->unk_18[D_800A7464->unk_16];
    }

    return ret;
}

s32 func_80007A58(void) {
    s32 ret = 0;

    if (D_800A7464 != NULL) {
        ret = D_800A7464->unk_0C == 1;
    }

    return ret;
}

void func_80007A80(void) {
    gDPPipeSync(D_800A74B0++);
    gDPSetCycleType(D_800A74B0++, G_CYC_1CYCLE);
    gDPSetTexturePersp(D_800A74B0++, G_TP_NONE);
    gDPSetTextureFilter(D_800A74B0++, G_TF_POINT);
    gDPSetPrimColor(D_800A74B0++, 0, 0, 255, 255, 255, 255);
    gDPSetRenderMode(D_800A74B0++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetCombineMode(D_800A74B0++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPLoadTextureBlock_4b(D_800A74B0++, (u32)D_80068CB0 & 0x1FFFFFFF, G_IM_FMT_IA, 96, 48, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 7, 6, G_TX_NOLOD, G_TX_NOLOD);
}

void func_80007C3C(void) {
    gDPPipeSync(D_800A74B0++);
    gDPSetTexturePersp(D_800A74B0++, G_TP_PERSP);
    gDPSetTextureFilter(D_800A74B0++, G_TF_BILERP);
    gDPSetAlphaCompare(D_800A74B0++, G_AC_NONE);
    gSPTexture(D_800A74B0++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

void func_80007CD8(s16 arg0, s16 arg1, s16 arg2) {
    gSPTextureRectangle(D_800A74B0++, arg0 * 4, arg1 * 4, (arg0 + 6) << 2, (arg1 + 8) << 2, G_TX_RENDERTILE,
                        ((arg2 % 16) * 6) << 5, (u16)(arg2 / 16) << 8, 0x0400, 0x0400);
}

void func_80007DE4(s16 arg0, s16 arg1, s16 arg2) {
    gSPTextureRectangle(D_800A74B0++, arg0 * 8, arg1 * 8, (arg0 + 6) << 3, (arg1 + 8) << 3, G_TX_RENDERTILE,
                        ((arg2 % 16) * 6) << 5, (u16)(arg2 / 16) << 8, 0x0200, 0x0200);
}

void func_80007EF0(s16 arg0, s16 arg1, s8* arg2, s32 arg3) {
    s32 temp_s0;

    while (*arg2 != 0) {
        temp_s0 = (*arg2++ & 0x7F) - 0x20;
        if (temp_s0 != 0) {
            if (arg3 == 0) {
                func_80007CD8(arg0, arg1, temp_s0);
            }

            if (arg3 == 1) {
                func_80007DE4(arg0, arg1, temp_s0);
            }
        }
        arg0 += 6;
    }
}

void func_80007FC4(Gfx** arg0, s32 arg1) {
    unk_D_80068CA0* var_s0 = D_80068CA0;
    unk_D_80068CA0* var_s2 = D_80068CA4;

    D_800A74B0 = *arg0;

    if ((var_s0 != NULL) || (var_s2 != NULL)) {
        func_80007A80();

        while (var_s0 != NULL) {
            unk_D_80068CA0* next = var_s0->next;

            func_80007EF0(var_s0->unk_04, var_s0->unk_06, var_s0->unk_08, arg1);
            Util_Free(var_s0);
            var_s0 = next;
        }

        while (var_s2 != NULL) {
            func_80007EF0(var_s2->unk_04, var_s2->unk_06, var_s2->unk_08, arg1);
            var_s2 = var_s2->next;
        }

        func_80007C3C();
        D_80068CA0 = NULL;
    }

    *arg0 = D_800A74B0;

    D_80068CA8++;
    if (D_80068CA8 >= 0x384) {
        D_80068CA8 = 0;
        if (D_80068CA4 != NULL) {
            func_800080E0();
        }
    }
}

void func_800080E0(void) {
    unk_D_80068CA0* var_s0 = D_80068CA4;

    while (var_s0 != NULL) {
        unk_D_80068CA0* next = var_s0->next;

        Util_Free(var_s0);
        var_s0 = next;
    }

    D_80068CA4 = NULL;
}

char* func_80008130(char* buffer, const char* data, size_t size) {
    return (char*)memcpy(buffer, data, size) + size;
}

s32 HAL_Printf(s16 x, s16 y, const char* fmt, ...) {
    s32 sp124;
    char sp20[0x104];
    unk_D_80068CA0* sp1C;
    va_list args;

    va_start(args, fmt);

    sp124 = _Printf(func_80008130, sp20, fmt, args);

    if (sp124 > 0) {
        sp1C = Util_Malloc(sp124 + sizeof(unk_D_80068CA0));
        if (sp1C != NULL) {
            sp1C->unk_04 = x;
            sp1C->unk_06 = y;
            memcpy(sp1C->unk_08, &sp20, sp124);
            sp1C->unk_08[sp124] = 0;
            sp1C->next = D_80068CA0;
            D_80068CA0 = sp1C;
        }
    }

    va_end(args);

    return sp124;
}

s32 func_800081F8(s16 x, s16 y, const char* fmt, ...) {
    s32 sp124;
    char sp20[0x104];
    unk_D_80068CA0* sp1C;
    va_list args;

    va_start(args, fmt);

    D_80068CA8 = 0;
    sp124 = _Printf(func_80008130, sp20, fmt, args);
    if (sp124 > 0) {
        sp1C = Util_Malloc(sp124 + sizeof(unk_D_80068CA0));
        if (sp1C != NULL) {
            sp1C->unk_04 = x;
            sp1C->unk_06 = y;
            memcpy(sp1C->unk_08, &sp20, sp124);
            sp1C->unk_08[sp124] = 0;
            sp1C->next = D_80068CA4;
            D_80068CA4 = sp1C;
        }
    }

    va_end(args);

    return sp124;
}
