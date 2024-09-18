#include "20470.h"
#include "src/1CF30.h"
#include "src/2E110.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/hal_libc.h"
#include "src/stage_loader.h"

extern u8 D_10025D0[];
extern u8 D_1002650[];
extern u8 D_10026D0[];
extern u8 D_1002750[];
extern u8 D_10027D0[];
extern u8 D_1002850[];
extern u8 D_10028D0[];
extern u8 D_1002950[];
extern u8 D_10029D0[];
extern u8 D_1002A50[];
extern u8 D_1002AD0[];
extern u8 D_1002B50[];
extern u8 D_1002BD0[];
extern u8 D_1002C50[];
extern u8 D_1002CD0[];
extern u8 D_1002D50[];
extern u8 D_1002DD0[];
extern u8 D_1002E50[];
extern u8 D_1002ED0[];
extern u8 D_1002F50[];
extern u8 D_1002FD0[];
extern u8 D_1003050[];
extern u8 D_10030D0[];
extern u8 D_1003150[];
extern u8 D_10031D0[];
extern u8 D_1003750[];
extern u8 D_1003890[];
extern u8 D_1003930[];
extern u8 D_10039F0[];
extern u8 D_1003AB0[];
extern u8 D_1003B70[];
extern u8 D_1003C30[];
extern u8 D_1003CF0[];
extern u8 D_1003DB0[];
extern u8 D_1003E50[];
extern u8 D_1003EA0[];
extern u8 D_1003EC8[];
extern u8 D_1003EF0[];
extern u8 D_2004000[];
extern u8 D_2004320[];

Gfx D_8006F470[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsSPEndDisplayList(),
};

Gfx D_8006F498[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsSPEndDisplayList(),
};

Gfx D_8006F4C0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsSPEndDisplayList(),
};

Gfx D_8006F4E0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_COPY),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPEndDisplayList(),
};

Gfx D_8006F518[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0,
                       ENVIRONMENT, 0),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsSPClearGeometryMode(G_ZBUFFER | G_LIGHTING),
    gsSPEndDisplayList(),
};

Gfx D_8006F558[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetCombineLERP(ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0, ENVIRONMENT, PRIMITIVE,
                       TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetPrimColor(0, 0, 0, 0, 0, 255),
    gsSPClearGeometryMode(G_ZBUFFER | G_LIGHTING),
    gsSPEndDisplayList(),
};

Gfx D_8006F5A0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL1, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsSPEndDisplayList(),
};

Gfx D_8006F5D8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
    gsDPSetCombineLERP(ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0, COMBINED, 0, TEXEL1, 0, 0,
                       0, 0, COMBINED),
    gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
    gsSPEndDisplayList(),
};

Gfx D_8006F608[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0,
                       ENVIRONMENT, 0),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPEndDisplayList(),
};

Gfx D_8006F630[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList(),
};

static u8 D_8006F650[] = {
    0x00, 0x34, 0x35, 0x0F, 0x00, 0x06, 0x0D, 0x37, 0x03, 0x04, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x10, 0x11,
    0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x3E, 0x42, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x1A, 0x1B, 0x1C,
    0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E,
    0x2F, 0x30, 0x31, 0x32, 0x33, 0x07, 0x00, 0x08, 0x00, 0x00, 0x00, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B,
    0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D,
    0x5E, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x8F, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x8D, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x8C, 0x00, 0x43, 0x44,
    0x41, 0x8E, 0x67, 0x66, 0x68, 0x00, 0x5F, 0x00, 0x00, 0x69, 0x6B, 0x6A, 0x6C, 0x6D, 0x7F, 0x7E, 0x80, 0x6F,
    0x00, 0x81, 0x83, 0x82, 0x6E, 0x00, 0x60, 0x36, 0x00, 0x70, 0x84, 0x71, 0x61, 0x00, 0x00, 0x65, 0x73, 0x72,
    0x74, 0x00, 0x62, 0x00, 0x00, 0x75, 0x77, 0x76, 0x78, 0x79, 0x86, 0x85, 0x87, 0x7B, 0x00, 0x88, 0x8A, 0x89,
    0x7A, 0x00, 0x63, 0x00, 0x00, 0x7C, 0x8B, 0x7D, 0x64, 0x00, 0x00, 0x00,
};

Gfx D_8006F710[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0,
                       ENVIRONMENT, 0),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsSPEndDisplayList(),
};

Gfx D_8006F750[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsSPEndDisplayList(),
};

Gfx D_8006F768[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_XLU_SURF2),
    gsDPSetCombineLERP(ENVIRONMENT, PRIMITIVE, TEXEL1, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, TEXEL1, 0, TEXEL1, 0,
                       ENVIRONMENT, 0),
    gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
    gsSPEndDisplayList(),
};

Gfx D_8006F798[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0,
                       ENVIRONMENT, 0),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsSPEndDisplayList(),
};

static s32 pad_D_8006F7C0[] = { 0, 0, 0, 0 };

void func_8001F870(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4) {
    s32 sp34 = (arg2 < 9) ? 0x400 : 0;
    s32 sp30 = (arg3 < 9) ? 0x400 : 0;

    gDPLoadTextureBlock(gDisplayListHead++, arg4, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, arg2, arg3, 0, 0, sp34, sp30, 0);
}

void func_8001F9D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_8001F870(arg0, arg1, 8, 8, D_10027D0);
    func_8001F870(arg0, (arg1 + arg3) - 8, 8, 8, D_1002850);
    func_8001F870((arg0 + arg2) - 8, (arg1 + arg3) - 8, 8, 8, D_10028D0);
    func_8001F870((arg0 + arg2) - 8, arg1, 8, 8, D_1002950);

    if (arg2 > 16) {
        func_8001F870(arg0 + 8, arg1, arg2 - 0x10, 8, D_10025D0);
        func_8001F870(arg0 + 8, (arg1 + arg3) - 8, arg2 - 0x10, 8, D_1002650);
    }

    if (arg3 > 16) {
        func_8001F870(arg0, arg1 + 8, 8, arg3 - 0x10, D_10026D0);
        func_8001F870((arg0 + arg2) - 8, arg1 + 8, 8, arg3 - 0x10, D_1002750);
    }
}

void func_8001FB40(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_8001F870(arg0, arg1, 8, 8, D_1002BD0);
    func_8001F870(arg0, (arg1 + arg3) - 8, 8, 8, D_1002C50);
    func_8001F870((arg0 + arg2) - 8, (arg1 + arg3) - 8, 8, 8, D_1002CD0);
    func_8001F870((arg0 + arg2) - 8, arg1, 8, 8, D_1002D50);

    if (arg2 > 16) {
        func_8001F870(arg0 + 8, arg1, arg2 - 0x10, 8, D_10029D0);
        func_8001F870(arg0 + 8, (arg1 + arg3) - 8, arg2 - 0x10, 8, D_1002A50);
    }

    if (arg3 > 16) {
        func_8001F870(arg0, arg1 + 8, 8, arg3 - 0x10, D_1002AD0);
        func_8001F870((arg0 + arg2) - 8, arg1 + 8, 8, arg3 - 0x10, D_1002B50);
    }
}

void func_8001FCAC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_8001F870(arg0, arg1, 8, 8, D_1002FD0);
    func_8001F870(arg0, (arg1 + arg3) - 8, 8, 8, D_1003050);
    func_8001F870((arg0 + arg2) - 8, (arg1 + arg3) - 8, 8, 8, D_10030D0);
    func_8001F870((arg0 + arg2) - 8, arg1, 8, 8, D_1003150);

    if (arg2 > 16) {
        func_8001F870(arg0 + 8, arg1, arg2 - 0x10, 8, D_1002DD0);
        func_8001F870(arg0 + 8, (arg1 + arg3) - 8, arg2 - 0x10, 8, D_1002E50);
    }

    if (arg3 > 16) {
        func_8001F870(arg0, arg1 + 8, 8, arg3 - 0x10, D_1002ED0);
        func_8001F870((arg0 + arg2) - 8, arg1 + 8, 8, arg3 - 0x10, D_1002F50);
    }
}

void func_8001FE18(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4) {
    gSPDisplayList(gDisplayListHead++, D_8006F4C0);
    gDPSetFillColor(gDisplayListHead++, (arg4 << 0x10) | arg4);

    if (func_80007A58() != 0) {
        gDPFillRectangle(gDisplayListHead++, arg0 + 7, arg1 + 7, (arg0 + arg2) - 8, (arg1 + arg3) - 8);
    } else {
        gDPFillRectangle(gDisplayListHead++, arg0 + 3, arg1 + 3, (arg0 + arg2) - 4, (arg1 + arg3) - 4);
    }
}

void func_8001FF68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4) {
    gSPDisplayList(gDisplayListHead++, D_8006F4C0);
    gDPSetFillColor(gDisplayListHead++, (arg4 << 0x10) | arg4);

    if (func_80007A58() != 0) {
        gDPFillRectangle(gDisplayListHead++, arg0 + 5, arg1 + 5, (arg0 + arg2) - 6, (arg1 + arg3) - 6);
    } else {
        gDPFillRectangle(gDisplayListHead++, arg0 + 3, arg1 + 3, (arg0 + arg2) - 4, (arg1 + arg3) - 4);
    }
}

void func_800200B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGB8* arg4, Color_RGB8* arg5) {
    Vtx* temp_s2;
    unk_D_80068BB0* temp_s1;
    Mtx* sp7C;
    Vp* sp78;

    temp_s1 = func_8000648C();
    temp_s2 = func_80005F5C(sizeof(Vtx) * 4);
    sp7C = func_80005F5C(sizeof(Mtx) * 1);
    sp78 = func_80005F5C(sizeof(Vp) * 1);

    func_8001E6E8(sp78, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)sp78 & 0x1FFFFFFF);

    guOrtho(sp7C, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);
    func_8001E680(&temp_s2[0], arg0, arg1, -1, 0, 0, arg4->r, arg4->g, arg4->b, 0xFF);
    func_8001E680(&temp_s2[1], arg0 + arg2, arg1, -1, 0, 0, arg4->r, arg4->g, arg4->b, 0xFF);
    func_8001E680(&temp_s2[2], arg0, arg1 + arg3, -1, 0, 0, arg5->r, arg5->g, arg5->b, 0xFF);
    func_8001E680(&temp_s2[3], arg0 + arg2, arg1 + arg3, -1, 0, 0, arg5->r, arg5->g, arg5->b, 0xFF);

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);

    gSPMatrix(gDisplayListHead++, (u32)sp7C & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
}

void func_80020460(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (func_80007A58() != 0) {
        func_8001F9D4(arg0, arg1, arg2, arg3);
    } else {
        func_8001FCAC(arg0, arg1, arg2, arg3);
    }

    if ((arg2 >= 0xF) && (arg3 >= 0xF)) {
        func_8001FE18(arg0, arg1, arg2, arg3, arg4);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_8002053C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGB8* arg4, Color_RGB8* arg5) {
    if ((arg2 >= 0xF) && (arg3 >= 0xF)) {
        if (func_80007A58() != 0) {
            func_800200B8(arg0 + 6, arg1 + 6, arg2 - 0xC, arg3 - 0xC, arg4, arg5);
        } else {
            func_800200B8(arg0 + 2, arg1 + 2, arg2 - 4, arg3 - 4, arg4, arg5);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (func_80007A58() != 0) {
        func_8001F9D4(arg0, arg1, arg2, arg3);
    } else {
        func_8001FCAC(arg0, arg1, arg2, arg3);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_80020678(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (func_80007A58() != 0) {
        func_8001FB40(arg0, arg1, arg2, arg3);
    } else {
        func_8001FCAC(arg0, arg1, arg2, arg3);
    }

    if ((arg2 >= 0xF) && (arg3 >= 0xF)) {
        func_8001FF68(arg0, arg1, arg2, arg3, arg4);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_80020754(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (func_80007A58() != 0) {
        func_8001F9D4(arg0, arg1, arg2, arg3);
    } else {
        func_8001FCAC(arg0, arg1, arg2, arg3);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_800207FC(s32 arg0, s32 arg1) {
    if (func_80007A58() != 0) {
        gSPDisplayList(gDisplayListHead++, D_8006F4E0);
        func_8001C6AC(arg0, arg1, 0x20, 0x16, D_10031D0, 0x20, 0x200000);
    } else {
        gSPDisplayList(gDisplayListHead++, D_8006F5A0);
        func_8001D560(arg0, arg1, 0xC, 0xA, D_1003750, D_1003890, 0x10, 0x100000);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_80020928(s16 arg0, s16 arg1) {
    static s16 D_8006F7D0 = 0;

    if (D_8006F7D0 < 6) {
        arg0 += D_8006F7D0;
    } else {
        arg0 = (arg0 - D_8006F7D0) + 0xC;
    }
    func_800207FC(arg0, arg1);
    D_8006F7D0 = (D_8006F7D0 + 1) % 12;
}

void func_800209B4(s32 arg0, s32 arg1, s32 arg2) {
    u8* var_t4;

    if (arg2 != 0) {
        var_t4 = D_2004320;
    } else {
        var_t4 = D_2004000;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F4E0);
    gDPLoadTextureBlock(gDisplayListHead++, var_t4, G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, arg0 << 2, arg1 << 2, (arg0 + 0x13) << 2, (arg1 + 0x13) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_80020B88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8* spDC;
    s32 spD8 = arg2 - 4;
    s32 temp_lo = ((arg4 - arg3) * (arg2 - 4)) / arg4;
    s32 sp1C = (arg2 - temp_lo) - 4;

    if ((arg3 * 0x30) < (arg4 * 0xA)) {
        spDC = D_1003CF0;
    } else if ((arg3 * 0x30) < (arg4 * 0x1B)) {
        spDC = D_1003C30;
    } else {
        spDC = D_1003B70;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F4E0);

    gDPLoadTextureBlock(gDisplayListHead++, D_1003930, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 12, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, arg0 << 2, arg1 << 2, (arg0 + 1) << 2, (arg1 + 0xB) << 2, G_TX_RENDERTILE,
                        0, 0, 0x1000, 0x0400);

    gDPLoadTextureBlock(gDisplayListHead++, D_10039F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 12, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, ((arg0 + spD8) + 2) << 2, arg1 << 2, ((arg0 + spD8) + 3) << 2,
                        (arg1 + 0xB) << 2, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);

    if (sp1C > 0) {
        gDPLoadTextureBlock(gDisplayListHead++, spDC, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (arg0 + 2) << 2, arg1 << 2, (arg0 + sp1C + 1) << 2, (arg1 + 0xB) << 2,
                            G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    if (temp_lo > 0) {
        gDPLoadTextureBlock(gDisplayListHead++, D_1003AB0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 12, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, ((arg0 + sp1C) + 2) << 2, arg1 << 2, ((arg0 + sp1C) + temp_lo + 1) << 2,
                            (arg1 + 0xB) << 2, G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_80021270(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8* spCC;
    s32 temp_lo = ((arg3 - arg2) * 0x30) / arg3;
    s32 sp14 = 0x30 - temp_lo;

    if ((arg2 * 0x30) < (arg3 * 0xA)) {
        spCC = D_1003EF0;
    } else if ((arg2 * 0x30) < (arg3 * 0x1B)) {
        spCC = D_1003EC8;
    } else {
        spCC = D_1003EA0;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    gDPLoadTextureBlock(gDisplayListHead++, D_1003DB0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 5, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, arg0 << 2, arg1 << 2, (arg0 + 0x10) << 2, (arg1 + 5) << 2, G_TX_RENDERTILE,
                        0, 0, 0x0400, 0x0400);
    gDPLoadTextureBlock(gDisplayListHead++, D_1003E50, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 5, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg0 + 0x40) << 2, arg1 << 2, (arg0 + 0x41) << 2, (arg1 + 5) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);

    if (sp14 > 0) {
        gDPLoadTextureBlock(gDisplayListHead++, spCC, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 5, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (arg0 + 0x10) << 2, arg1 << 2, (arg0 + sp14 + 0x10) << 2,
                            (arg1 + 5) << 2, G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    if (temp_lo > 0) {
        gDPLoadTextureBlock(gDisplayListHead++, D_1003E78, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 5, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, ((arg0 + sp14) + 0x10) << 2, arg1 << 2,
                            ((arg0 + sp14) + temp_lo + 0x10) << 2, (arg1 + 5) << 2, G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_80021920(void) {
    s32 temp_s2 = func_8002D5AC(0x24);
    s32 i;

    for (i = 0; i < 151; i++) {
        HAL_Strcpy(D_8006FF00[i].name, func_8002D7C0(NULL, 0, temp_s2, i));
    }
}
