#include "fragment62.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/225A0.h"
#include "src/29BA0.h"
#include "src/2E110.h"
#include "src/3D140.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/F420.h"
#include "src/controller.h"
#include "src/memmap.h"
#include "src/memory.h"

Vec3f D_84390190;

static unk_D_84385790 D_84385790[] = {
    {
        0x00000000,
        {
            0xFF,
            0xFF,
            0xFF,
            0xFF,
        },
    },
    {
        0x00000001,
        {
            0x4D,
            0x4D,
            0x4D,
            0xFF,
        },
    },
    {
        0x00000002,
        {
            0x9F,
            0x91,
            0xE8,
            0xFF,
        },
    },
    {
        0x00000003,
        {
            0x96,
            0x50,
            0xFF,
            0xFF,
        },
    },
    {
        0x00000004,
        {
            0xF0,
            0x5A,
            0x46,
            0xFF,
        },
    },
    {
        0x00000005,
        {
            0x85,
            0xD5,
            0xF1,
            0xFF,
        },
    },
    {
        0x00000006,
        {
            0xFF,
            0xFF,
            0x00,
            0xFF,
        },
    },
};
static u8* D_843857C8[] = {
    D_30098F0, D_300B630, D_300A1F0, D_30096B0, D_300AAF0, D_300A8B0, D_30098F0, D_300B3F0, D_3009FB0, D_30098F0,
    D_30098F0, D_30098F0, D_30098F0, D_30098F0, D_30098F0, D_30098F0, D_30098F0, D_30098F0, D_30098F0, D_30098F0,
    D_300A430, D_300B1B0, D_300AF70, D_300A670, D_3009D70, D_300AD30, D_3009B30, NULL,
};
static u8* D_84385838[] = {
    D_3007A78, D_3007EB0, D_3007910, D_3008018, D_3007BE0, D_3007D48,
};
static u8* D_84385850[] = {
    D_3006D10,
    D_3007010,
    D_3007310,
    D_3007610,
};

static Color_RGB8 D_84385860[] = {
    { 0, 0, 0x8B }, { 0, 0x32, 0 }, { 0x1E, 0, 0 }, { 0x65, 0x49, 0x11 }, { 0, 0, 0 },
};
static Color_RGB8 D_84385870[] = {
    { 0x00, 0x00, 0xEE },
    { 0x00, 0x79, 0x00 },
    { 0x82, 0x00, 0x00 },
    { 0x97, 0x89, 0x13 },
};
static Color_RGB8 D_8438587C[] = {
    { 0x13, 0x45, 0xFF },
    { 0, 0x99, 0 },
    { 0xCC, 0x51, 0x28 },
    { 0xCC, 0x8F, 0 },
};
static Color_RGB8 D_84385888[] = {
    { 0x00, 0x00, 0x8B },
    { 0x00, 0x00, 0x8B },
    { 0x00, 0x00, 0x8B },
    { 0x00, 0x00, 0x8B },
};
static Color_RGB8 D_84385894[] = {
    { 0x00, 0x00, 0xEE },
    { 0x00, 0x00, 0xEE },
    { 0x00, 0x00, 0xEE },
    { 0x00, 0x00, 0xEE },
};
static Color_RGB8 D_843858A0[] = {
    { 0x00, 0x32, 0x00 },
    { 0x00, 0x32, 0x00 },
    { 0x00, 0x32, 0x00 },
    { 0x00, 0x32, 0x00 },
};
static Color_RGB8 D_843858AC[] = {
    { 0x00, 0x79, 0x00 },
    { 0x00, 0x79, 0x00 },
    { 0x00, 0x79, 0x00 },
    { 0x00, 0x79, 0x00 },
};
static Color_RGB8 D_843858B8[] = {
    { 0x1E, 0x00, 0x00 },
    { 0x1E, 0x00, 0x00 },
    { 0x1E, 0x00, 0x00 },
    { 0x1E, 0x00, 0x00 },
};
static Color_RGB8 D_843858C4[] = {
    { 0x82, 0x00, 0x00 },
    { 0x82, 0x00, 0x00 },
    { 0x82, 0x00, 0x00 },
    { 0x82, 0x00, 0x00 },
};
static Color_RGB8 D_843858D0[] = {
    { 0x65, 0x49, 0x11 },
    { 0x65, 0x49, 0x11 },
    { 0x65, 0x49, 0x11 },
    { 0x65, 0x49, 0x11 },
};
static Color_RGB8 D_843858DC[] = {
    { 0x97, 0x89, 0x13 },
    { 0x97, 0x89, 0x13 },
    { 0x97, 0x89, 0x13 },
    { 0x97, 0x89, 0x13 },
};
static Gfx D_843858E8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetRenderMode(G_RM_TEX_EDGE, G_RM_TEX_EDGE2),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPClearGeometryMode(G_ZBUFFER | G_LIGHTING),
    gsSPEndDisplayList(),
};

void func_8430FC10(void) {
}

void func_8430FC18(void) {
}

void func_8430FC20(void) {
}

void func_8430FC28(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    unk_D_80068BB0* temp_s1;
    Vtx* temp_s2;
    Mtx* sp84;
    Vp* sp80;

    temp_s1 = func_8000648C();
    temp_s2 = func_80005F5C(sizeof(Vtx) * 4);
    sp84 = func_80005F5C(sizeof(Mtx) * 1);
    sp80 = func_80005F5C(sizeof(Vp) * 1);
    func_8001E6E8(sp80, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)sp80 & 0x1FFFFFFF);

    guOrtho(sp84, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    func_8001E680(&temp_s2[0], arg0, arg1, -1, 0, 0, 0, 0, 0, arg4);
    func_8001E680(&temp_s2[1], arg0 + arg2, arg1, -1, 0, 0, 0, 0, 0, arg4);
    func_8001E680(&temp_s2[2], arg0, arg1 + arg3, -1, 0, 0, 0, 0, 0, arg4);
    func_8001E680(&temp_s2[3], arg0 + arg2, arg1 + arg3, -1, 0, 0, 0, 0, 0, arg4);

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)sp84 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
}

void func_8430FF8C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGB8* arg4, Color_RGB8* arg5) {
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

void func_84310334(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Color_RGB8* arg4, Color_RGB8* arg5) {
    func_8430FF8C(arg0, arg1, arg2, arg3, arg4, arg5);
}

void func_84310360(void) {
}

void func_84310368(s32 arg0, s32 arg1, f32 arg2, s32 arg3) {
    u8* spCC;
    s32 temp_ft2 = ((arg3 - arg2) * 48.0f) / arg3;
    s32 sp14 = 0x30 - temp_ft2;

    if ((arg2 * 48.0f) < (arg3 * 0xA)) {
        spCC = D_1003EF0;
    } else if ((arg2 * 48.0f) < (arg3 * 0x1B)) {
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
        gSPTextureRectangle(gDisplayListHead++, (arg0 + 0x10) << 2, arg1 << 2, ((arg0 + sp14) + 0x10) << 2,
                            (arg1 + 5) << 2, G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    if (temp_ft2 > 0) {
        gDPLoadTextureBlock(gDisplayListHead++, D_1003E78, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 5, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, ((arg0 + sp14) + 0x10) << 2, arg1 << 2,
                            ((arg0 + sp14) + temp_ft2 + 0x10) << 2, (arg1 + 5) << 2, G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_843109EC(void) {
}

void func_843109F4(s32 arg0, s32 arg1, s32 arg2) {
    UNUSED s32 pad[2];
    s8* var_s2;
    s8 sp58[2];
    u8** temp_s4;

    var_s2 = &sp58;
    temp_s4 = Memmap_GetSegmentVaddr(D_300B870);
    sprintf(sp58, "%d", arg2);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (arg2 >= 0x64) {
        arg0 -= 2;
        func_8001C6AC(arg0, arg1, 8, 6, temp_s4[sp58[0] - '0'], 8, 0);
        arg0 += 8;
        var_s2 = &sp58[1];
    } else {
        func_8001C6AC(arg0, arg1, 4, 6, temp_s4[11], 4, 0);
        arg0 += 5;
    }

    while (*var_s2 != 0) {
        func_8001C6AC(arg0, arg1, 8, 6, temp_s4[*var_s2 - '0'], 8, 0);
        arg0 += 8;
        var_s2++;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84310B9C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad[2];
    s8 sp70[7];
    UNUSED s32 pad2;
    u8** temp_s2;
    u8* var_v0;
    s32 i;

    temp_s2 = Memmap_GetSegmentVaddr(D_300B870);
    sprintf(sp70, "%3d/%3d", arg2, arg3);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < sizeof(sp70); i++) {
        switch (sp70[i]) {
            case ' ':
                var_v0 = NULL;
                break;

            case '/':
                var_v0 = temp_s2[10];
                break;

            default:
                var_v0 = temp_s2[sp70[i] - '0'];
                break;
        }

        if (var_v0 != NULL) {
            func_8001C6AC(arg0, arg1, 8, 6, var_v0, 8, 0);
        }

        arg0 += 8;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84310CE4(s16 arg0, s16 arg1, s32 arg2, char* arg3, s32 arg4) {
    func_84310334(arg0, arg1, 0x46, 0x11, &D_84385860[arg2], &D_84385870[arg2]);
    func_8001F3F4();
    if (arg4 != 0) {
        func_8001F324(0xFF, 0x64, 0xFF, 0xFF);
    }
    func_8001EBE0(2, 0);
    func_8001F1E8((arg0 - (func_8001F5B0(2, 0, arg3) / 2)) + 0x23, arg1 + 2, arg3);
    func_8001F444();
}

void func_84310DC4(s16 arg0, s16 arg1, s32 arg2, u8* arg3, s32 arg4, s32 arg5) {
    s32 sp24;
    s16 sp22;
    s16 sp20;

    sp22 = COSS(arg4) * 255.0f;
    sp20 = sp22;
    if (sp22 < 0) {
        sp20 = sp22 * -1;
    }

    func_84310334(arg0, arg1, 0x46, 0x11, &D_84385860[arg2], &D_84385870[arg2]);
    func_8001F3F4();
    func_8001EBE0(2, 0);

    if (arg5 != 0) {
        func_8001F324(0xFF, 0x64, 0xFF, (s8)sp20);
    } else {
        func_8001F324(0xFF, 0xFF, 0xFF, (s8)sp20);
    }

    if (sp22 > 0) {
        sp24 = func_8001F5B0(2, 0, func_8002D7C0(NULL, 0, D_843900B0, 0xAA)) / 2;
        func_8001F1E8((arg0 - sp24) + 0x23, arg1 + 2, func_8002D7C0(NULL, 0, D_843900B0, 0xAA));
    } else {
        func_8001F1E8((arg0 - (func_8001F5B0(2, 0, arg3) / 2)) + 0x23, arg1 + 2, arg3);
    }

    func_8001F444();
}

void func_84310FA4(unk_D_84390010* arg0, unk_D_800AE540_0004* arg1, s16 arg2, s16 arg3, s32 arg4, u16 arg5, s32 arg6) {
    unk_D_84390010_654* ptr = &arg0->unk_654;
    s32 var_t0 = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (ptr->unk_C1[i] == 1) {
            var_t0 = 1;
        }
    }

    if (arg6 == 0) {
        func_84310CE4(arg2, arg3, arg4, &arg1->unk_008, var_t0);
    } else {
        func_84310DC4(arg2, arg3, arg4, &arg1->unk_008, arg5, var_t0);
    }
}

void func_84311048(unk_D_84390010* arg0, unk_func_80026268_arg0* arg1, unk_D_84385790* arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    s32 sp34;
    s32 temp_a2;

    if (arg3 < 0) {
        temp_a2 = arg5 + arg3;
        if (temp_a2 < 0) {
            func_8001F504(0, arg4, 0, arg6, arg7, arg8, arg9, argA);
        } else {
            func_8001F504(0, arg4, temp_a2, arg6, arg7, arg8, arg9, argA);
        }
    } else {
        func_8001F504(arg3, arg4, arg5, arg6, arg7, arg8, arg9, argA);
    }

    func_843109F4(arg3 + 3, arg4 + 0x10, arg1->unk_24);
    func_84310368(arg3 + 2, arg4 + 0x19, D_843900A8[func_84307F00(arg0)], arg1->unk_26);
    func_84310B9C(arg3 + 0xC, arg4 + 0x1F, arg1->unk_02, arg1->unk_26);
    func_8001F3F4();
    func_8001EBE0(2, 0);

    sp34 = func_8001F5B0(2, 0, func_8430862C(arg0)) / 2;
    func_8001F1E8((arg3 - sp34) + 0x23, arg4 + 2, func_8430862C(arg0));
    sp34 = func_8001F5B0(1, 0, func_8002D7C0(NULL, 0, D_843900BC, arg2->unk_00));

    if (sp34 >= 0x28) {
        func_8001EBE0(1, -1);
        sp34 = arg3 + 0x1A;
    } else {
        func_8001EBE0(1, 0);
        sp34 = (arg3 - (sp34 / 2)) + 0x2C;
    }

    func_8001F324(arg2->unk_04.r, arg2->unk_04.g, arg2->unk_04.b, 0xFF);
    func_8001F1E8(sp34, arg4 + 0xE, func_8002D7C0(NULL, 0, D_843900BC, arg2->unk_00));
    func_8001F444();
}

s32 func_843112C4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4) {
    UNUSED s32 pad[4];
    s32 sp2C;
    s32 sp28;

    if (arg2 < 9) {
        sp2C = 0x400;
    } else {
        sp2C = 0;
    }

    // clang-format off
    if (arg3 < 9) { sp28 = 0x400; } else { sp28 = 0; }
    // clang-format on

    gDPLoadTextureBlock(gDisplayListHead++, arg4, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C4E4(arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1, sp2C, sp28, 0);
}

void func_84311420(void) {
}

void func_84311428(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 i;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_843112C4(arg0, arg1 - 1, 8, 8, D_3008480);
    func_843112C4(arg0, (arg1 + arg3) - 6, 8, 8, D_3008400);
    func_843112C4((arg0 + arg2) - 6, arg1 - 1, 8, 8, D_3008600);
    func_843112C4((arg0 + arg2) - 6, (arg1 + arg3) - 6, 8, 8, D_3008580);

    for (i = 0; i < arg3 / 8; i++) {
        if ((arg3 - 4) >= (6 + i * 8)) {
            func_843112C4((arg0 + arg2) - 6, arg1 + (i * 8) + 4, 8, 8, D_3008500);
        }
    }

    for (i = 0; i < arg3 / 8; i++) {
        if ((arg3 - 4) >= (6 + i * 8)) {
            func_843112C4(arg0, arg1 + (i * 8) + 4, 8, 8, D_3008380);
        }
    }

    for (i = 0; i < arg2 / 8; i++) {
        if ((arg2 - 4) >= (6 + i * 8)) {
            func_843112C4(arg0 + (i * 8) + 3, arg1 - 1, 8, 8, D_3008700);
        }

        if ((arg2 - 4) >= (6 + i * 8)) {
            func_843112C4(arg0 + (i * 8) + 3, (arg1 + arg3) - 6, 8, 8, D_3008680);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_843116D8(s16 arg0, s16 arg1) {
    Color_RGB8 sp54[] = {
        { 0xB4, 0x00, 0x00 },
        { 0xCC, 0x8F, 0x00 },
        { 0x00, 0xB4, 0x00 },
        { 0x00, 0x00, 0x00 },
    };
    char sp44[16];
    UNUSED s32 pad[4];
    s32 var_v1;
    s32 temp_t0;

    temp_t0 = ((s32)((D_84390124 / 30.0f) / 60.0f) * 0x3C) + ((s32)(D_84390124 / 30.0f) % 60);
    if (temp_t0 >= 0xB) {
        var_v1 = 2;
    } else if (temp_t0 >= 4) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }

    func_8001F504(arg0 - 1, arg1, 0x14, 0xD, sp54[var_v1].r, sp54[var_v1].g, sp54[var_v1].b, 0xBE);
    func_84311428(arg0 - 2, arg1 - 1, 0x14, 0xC);

    sprintf(sp44, "%02d", temp_t0);

    func_8001F3F4();
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001EBE0(1, 0);
    func_8001F1E8(arg0 + 3, arg1, sp44);
    func_8001F444();
    func_8430FC28(arg0 - 3, arg1 - 3, 0x19, 0x12, 0);
}

void func_843118A8(s16 arg0, s16 arg1) {
    char sp40[16];
    f32 sp3C = D_84390128 / 30.0f;
    UNUSED s32 pad[2];

    func_8001F504(arg0, arg1, 0x27, 0xC, 0, 0, 0, 0x5A);
    func_84311428(arg0 - 2, arg1 - 1, 0x27, 0xC);
    func_8001F3F4();
    func_8001EBE0(2, 0);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    sprintf(sp40, "%02d", (s32)(sp3C / 60.0f));
    func_8001EBE0(1, 0);
    func_8001F1E8(arg0 + 3, arg1, sp40);
    func_8001F1E8(arg0 + 0x10, arg1, ":");
    sprintf(sp40, "%02d", (s32)sp3C % 60);
    func_8001EBE0(1, 0);
    func_8001F1E8(arg0 + 0x17, arg1, sp40);
    func_8001F444();
    func_8430FC28(arg0 - 3, arg1 - 3, 0x2C, 0x11, 0);
}

void func_84311A38(unk_D_84390010* arg0, s16 arg1, s16 arg2) {
    u8* sp74[] = { D_3006170, D_30061D0, D_3006230 };
    UNUSED s32 pad;
    s32 i;
    s32 j;
    s32 var_v0_2;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (arg0 == D_84390010[0]) {
        if (arg0->unk_720->unk_01 == 1) {
            for (i = 0; i < arg0->unk_720->unk_08[0]->unk_002; i++) {
                if (arg0->unk_720->unk_08[0]->unk_01C[i].unk_02 == 0) {
                    var_v0_2 = 2;
                } else if (arg0->unk_720->unk_08[0]->unk_01C[i].unk_05 != 0) {
                    var_v0_2 = 1;
                } else {
                    var_v0_2 = 0;
                }
                func_8001C6AC(arg1 + i * 7, arg2, 8, 6, sp74[var_v0_2], 8, 0);
            }
        } else {
            for (i = 0; i < arg0->unk_720->unk_08[0]->unk_002; i++) {
                if (arg0->unk_720->unk_08[0]->unk_01C[i].unk_02 == 0) {
                    var_v0_2 = 2;
                } else if (arg0->unk_720->unk_08[0]->unk_01C[i].unk_05 != 0) {
                    var_v0_2 = 1;
                } else {
                    var_v0_2 = 0;
                }
                func_8001C6AC(arg1 + i * 7, arg2, 8, 6, sp74[var_v0_2], 8, 0);
            }

            for (j = 0; j < arg0->unk_720->unk_08[1]->unk_002; j++) {
                if (arg0->unk_720->unk_08[1]->unk_01C[j].unk_02 == 0) {
                    var_v0_2 = 2;
                } else if (arg0->unk_720->unk_08[1]->unk_01C[j].unk_05 != 0) {
                    var_v0_2 = 1;
                } else {
                    var_v0_2 = 0;
                }
                func_8001C6AC(arg1 + i * 7 + j * 7, arg2, 8, 6, sp74[var_v0_2], 8, 0);
            }
        }
    }

    if (arg0 == D_84390010[1]) {
        if (arg0->unk_720->unk_01 == 1) {
            for (i = 0; i < arg0->unk_720->unk_08[0]->unk_002; i++) {
                if (arg0->unk_720->unk_08[0]->unk_01C[i].unk_02 == 0) {
                    var_v0_2 = 2;
                } else if (arg0->unk_720->unk_08[0]->unk_01C[i].unk_05 != 0) {
                    var_v0_2 = 1;
                } else {
                    var_v0_2 = 0;
                }
                func_8001C6AC(arg1 - i * 7, arg2, 8, 6, sp74[var_v0_2], 8, 0);
            }
        } else {
            for (i = 0; i < arg0->unk_720->unk_08[0]->unk_002; i++) {
                if (arg0->unk_720->unk_08[0]->unk_01C[i].unk_02 == 0) {
                    var_v0_2 = 2;
                } else if (arg0->unk_720->unk_08[0]->unk_01C[i].unk_05 != 0) {
                    var_v0_2 = 1;
                } else {
                    var_v0_2 = 0;
                }
                func_8001C6AC(arg1 - i * 7, arg2, 8, 6, sp74[var_v0_2], 8, 0);
            }

            for (j = 0; j < arg0->unk_720->unk_08[1]->unk_002; j++) {
                if (arg0->unk_720->unk_08[1]->unk_01C[j].unk_02 == 0) {
                    var_v0_2 = 2;
                } else if (arg0->unk_720->unk_08[1]->unk_01C[j].unk_05 != 0) {
                    var_v0_2 = 1;
                } else {
                    var_v0_2 = 0;
                }
                func_8001C6AC(arg1 - i * 7 - j * 7, arg2, 8, 6, sp74[var_v0_2], 8, 0);
            }
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84311F30(unk_D_84390010* arg0, s16 arg1, s16 arg2, u16 arg3, s32 arg4) {
    UNUSED s32 pad[3];
    unk_D_800AE540_0004* sp80;
    unk_func_80026268_arg0* sp7C;
    Color_RGB8* temp_v0_2;
    u32 var_v1;

    sp80 = arg0->unk_720->unk_08[arg0->unk_728.unk_16C];
    sp7C = &arg0->unk_720->unk_08[arg0->unk_728.unk_16C]->unk_01C[arg0->unk_654.unk_08];

    if (sp7C->unk_02 == 0) {
        var_v1 = 1;
    } else {
        var_v1 = func_800219A0(sp7C->unk_05);
    }

    temp_v0_2 = &D_84385860[sp80->unk_001];
    func_84311048(arg0, sp7C, &D_84385790[var_v1], arg1 + 1, arg2 + 0x12, 0x46, 0x28, temp_v0_2->r, temp_v0_2->g,
                  temp_v0_2->b, 0xB2);
    func_84310FA4(arg0, sp80, arg1 + 1, arg2 + 1, sp80->unk_001, arg3, arg4);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_843112C4(arg1, arg2, 8, 8, D_3008480);
    func_843112C4(arg1, arg2 + 0xF, 8, 8, D_3008200);
    func_843112C4(arg1, arg2 + 0x36, 8, 8, D_3008200);
    func_843112C4(arg1 + 0x41, arg2, 8, 8, D_3008600);
    func_843112C4(arg1 + 0x41, arg2 + 0xF, 8, 8, D_3008280);
    func_843112C4(arg1 + 0x41, arg2 + 0x33, 8, 8, D_3008580);
    func_843112C4(arg1 + 8, arg2, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x10, arg2, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x18, arg2, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x20, arg2, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x28, arg2, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x30, arg2, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x38, arg2, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x39, arg2, 8, 8, D_3008700);
    func_843112C4(arg1 + 8, arg2 + 0x12, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x10, arg2 + 0x12, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x18, arg2 + 0x12, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x20, arg2 + 0x12, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x28, arg2 + 0x12, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x30, arg2 + 0x12, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x38, arg2 + 0x12, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x39, arg2 + 0x12, 8, 8, D_3008700);
    func_843112C4(arg1 + 8, arg2 + 0x33, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x10, arg2 + 0x33, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x18, arg2 + 0x33, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x20, arg2 + 0x33, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x28, arg2 + 0x33, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x30, arg2 + 0x33, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x38, arg2 + 0x33, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x39, arg2 + 0x33, 8, 8, D_3008680);
    func_843112C4(arg1, arg2 + 8, 8, 8, D_3008380);
    func_843112C4(arg1, arg2 + 0x15, 8, 8, D_3008380);
    func_843112C4(arg1, arg2 + 0x1D, 8, 8, D_3008380);
    func_843112C4(arg1, arg2 + 0x25, 8, 8, D_3008380);
    func_843112C4(arg1, arg2 + 0x2D, 8, 8, D_3008380);
    func_843112C4(arg1, arg2 + 0x2E, 8, 8, D_3008380);
    func_843112C4(arg1 + 0x41, arg2 + 8, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x41, arg2 + 0x15, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x41, arg2 + 0x1D, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x41, arg2 + 0x25, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x41, arg2 + 0x2D, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x41, arg2 + 0x2F, 8, 8, D_3008500);
    func_843112C4(arg1, arg2 + 0x3D, 8, 8, D_3008380);
    func_843112C4(arg1, arg2 + 0x45, 8, 8, D_3008380);
    func_843112C4(arg1, arg2 + 0x4D, 8, 8, D_3008380);
    func_843112C4(arg1, arg2 + 0x55, 8, 8, D_3008380);
    func_843112C4(arg1 + 0x21, arg2 + 0x3A, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x21, arg2 + 0x3D, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x21, arg2 + 0x45, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x21, arg2 + 0x4D, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x21, arg2 + 0x55, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x21, arg2 + 0x59, 8, 8, D_3008580);
    func_843112C4(arg1, arg2 + 0x59, 8, 8, D_3008400);
    func_843112C4(arg1 + 4, arg2 + 0x59, 8, 8, D_3008680);
    func_843112C4(arg1 + 0xC, arg2 + 0x59, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x14, arg2 + 0x59, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x1C, arg2 + 0x59, 8, 8, D_3008680);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8430FC28(arg1 - 3, arg2 - 2, 0x4E, 0x3F, 0);
    func_8430FC28(arg1 - 3, arg2 + 0x3A, 0x2D, 0x29, 0);
    func_84311A38(arg0, arg1, arg2 + 0x62);
}

void func_843128A0(unk_D_84390010* arg0, s16 arg1, s16 arg2, u16 arg3, s32 arg4) {
    UNUSED s32 pad[3];
    unk_D_800AE540_0004* sp80;
    unk_func_80026268_arg0* sp7C;
    Color_RGB8* temp_v0;
    u32 var_v1;

    sp80 = arg0->unk_720->unk_08[arg0->unk_728.unk_16C];
    sp7C = &arg0->unk_720->unk_08[arg0->unk_728.unk_16C]->unk_01C[arg0->unk_654.unk_08];

    if (sp7C->unk_02 == 0) {
        var_v1 = 1;
    } else {
        var_v1 = func_800219A0(sp7C->unk_05);
    }

    temp_v0 = &D_84385860[sp80->unk_001];
    func_84311048(arg0, sp7C, &D_84385790[var_v1], arg1, arg2 + 0x28, 0x46, 0x28, temp_v0->r, temp_v0->g, temp_v0->b,
                  0xB2);
    func_84310FA4(arg0, sp80, arg1, arg2 + 0x50, sp80->unk_001, arg3, arg4);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_843112C4(arg1, arg2 + 0x4C, 8, 8, D_3008200);
    func_843112C4(arg1, arg2 + 0x5B, 8, 8, D_3008400);
    func_843112C4(arg1, arg2 + 0x27, 8, 8, D_3008480);
    func_843112C4(arg1 + 0x3F, arg2 + 0x24, 8, 8, D_3008280);
    func_843112C4(arg1 + 0x3F, arg2 + 0x4C, 8, 8, D_3008280);
    func_843112C4(arg1 + 0x3F, arg2 + 0x5B, 8, 8, D_3008580);
    func_843112C4(arg1 + 7, arg2 + 0x27, 8, 8, D_3008700);
    func_843112C4(arg1 + 8, arg2 + 0x27, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x10, arg2 + 0x27, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x18, arg2 + 0x27, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x20, arg2 + 0x27, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x28, arg2 + 0x27, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x30, arg2 + 0x27, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x38, arg2 + 0x27, 8, 8, D_3008700);
    func_843112C4(arg1 + 7, arg2 + 0x4F, 8, 8, D_3008700);
    func_843112C4(arg1 + 8, arg2 + 0x4F, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x10, arg2 + 0x4F, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x18, arg2 + 0x4F, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x20, arg2 + 0x4F, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x28, arg2 + 0x4F, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x30, arg2 + 0x4F, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x38, arg2 + 0x4F, 8, 8, D_3008700);
    func_843112C4(arg1 + 7, arg2 + 0x5B, 8, 8, D_3008680);
    func_843112C4(arg1 + 8, arg2 + 0x5B, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x10, arg2 + 0x5B, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x18, arg2 + 0x5B, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x20, arg2 + 0x5B, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x28, arg2 + 0x5B, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x30, arg2 + 0x5B, 8, 8, D_3008680);
    func_843112C4(arg1 + 0x38, arg2 + 0x5B, 8, 8, D_3008680);
    func_843112C4(arg1, arg2 + 0x2C, 8, 8, D_3008380);
    func_843112C4(arg1, arg2 + 0x34, 8, 8, D_3008380);
    func_843112C4(arg1, arg2 + 0x3C, 8, 8, D_3008380);
    func_843112C4(arg1, arg2 + 0x44, 8, 8, D_3008380);
    func_843112C4(arg1, arg2 + 0x52, 8, 8, D_3008380);
    func_843112C4(arg1, arg2 + 0x53, 8, 8, D_3008380);
    func_843112C4(arg1 + 0x3F, arg2 + 0x2C, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x3F, arg2 + 0x34, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x3F, arg2 + 0x3C, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x3F, arg2 + 0x44, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x3F, arg2 + 0x52, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x3F, arg2 + 0x53, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x3F, arg2, 8, 8, D_3008600);
    func_843112C4(arg1 + 0x1E, arg2, 8, 8, D_3008480);
    func_843112C4(arg1 + 0x3F, arg2 + 8, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x3F, arg2 + 0x10, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x3F, arg2 + 0x18, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x3F, arg2 + 0x20, 8, 8, D_3008500);
    func_843112C4(arg1 + 0x1E, arg2 + 8, 8, 8, D_3008380);
    func_843112C4(arg1 + 0x1E, arg2 + 0x10, 8, 8, D_3008380);
    func_843112C4(arg1 + 0x1E, arg2 + 0x18, 8, 8, D_3008380);
    func_843112C4(arg1 + 0x1E, arg2 + 0x1F, 8, 8, D_3008380);
    func_843112C4(arg1 + 0x20, arg2, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x28, arg2, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x30, arg2, 8, 8, D_3008700);
    func_843112C4(arg1 + 0x37, arg2, 8, 8, D_3008700);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8430FC28(arg1 + 0x1B, arg2 - 2, 0x2F, 0x2A, 0);
    func_8430FC28(arg1 - 4, arg2 + 0x26, 0x4D, 0x3D, 0);
    func_84311A38(arg0, arg1 + 0x41, arg2 - 7);
}

void func_84313148(unk_D_84390010* arg0, s16 arg1, s16 arg2, s32 arg3) {
    UNUSED s32 pad[2];

    func_84310334(arg1 + 1, arg2 + 1, 0xC6, 0x10, &D_84385860[arg3], &D_84385870[arg3]);
    func_84311428(arg1, arg2, 0xC6, 0x10);

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    func_8001D560(arg1 + 7, arg2 + 3, 0x10, 0xC, D_3008C00, D_3008D80, 0x10, 0x100000);
    func_8001D560(arg1 + 0x46, arg2 + 3, 0x10, 0xC, D_3008E40, D_3008FC0, 0x10, 0x100000);
    func_8001D560(arg1 + 0x86, arg2 + 3, 0x10, 0xC, D_3009080, D_3009200, 0x10, 0x100000);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(1, 0);
    func_8001F1E8(arg1 + 0x18, arg2 + 3, func_8002D7C0(NULL, 0, D_843900B0, 0x9E));
    func_8001F1E8(arg1 + 0x58, arg2 + 3, func_8002D7C0(NULL, 0, D_843900B0, 0x9F));
    func_8001F1E8(arg1 + 0x98, arg2 + 3, func_8002D7C0(NULL, 0, D_843900B0, 0xA0));
    func_8001F444();
    func_8430FC28(arg1 - 2, arg2 - 2, 0xCC, 0x16, 0);
}

void func_843133B4(unk_D_84390010* arg0, s16 arg1, s16 arg2, s32 arg3) {
    UNUSED s32 pad[2];

    func_84310334(arg1, arg2, 0x7D, 0x10, &D_84385860[arg3], &D_84385870[arg3]);
    func_84311428(arg1, arg2, 0x7D, 0x10);

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    func_8001D560(arg1 + 7, arg2 + 3, 0x10, 0xC, D_3008780, D_3008900, 0x10, 0x100000);
    func_8001D560(arg1 + 0x40, arg2 + 3, 0x10, 0xC, D_30089C0, D_3008B40, 0x10, 0x100000);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(1, 0);
    func_8001F1E8(arg1 + 0x18, arg2 + 3, func_8002D7C0(NULL, 0, D_843900B0, 0xA9));
    func_8001F1E8(arg1 + 0x51, arg2 + 3, func_8002D7C0(NULL, 0, D_843900B0, 0xA8));
    func_8001F444();
    func_8430FC28(arg1 - 2, arg2 - 2, 0x83, 0x16, 0);
}

void func_843135B8(unk_D_84390010* arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 pad[2];

    func_84310334(arg1 + 1, arg2 + 1, 0x47, 0x10, &D_84385860[arg3], &D_84385870[arg3]);
    func_84311428(arg1, arg2, 0x47, 0x10);

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    func_8001D560(arg1 + 7, arg2 + 3, 0x10, 0xC, D_30089C0, D_3008B40, 0x10, 0x100000);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(1, 0);
    func_8001F1E8(arg1 + 0x18, arg2 + 3, func_8002D7C0(NULL, 0, D_843900B0, 0xA8));
    func_8001F444();
    func_8430FC28(arg1 - 2, arg2 - 2, 0x4A, 0x16, 0);
}

void func_84313750(s32 arg0, s32 arg1, char* arg2) {
    func_8001F1E8(arg0 - (strlen(arg2) * 6), arg1, arg2);
}

s32 func_8431379C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad[2];
    s8 sp70[7];
    s32 i;
    u8** temp_s2;
    u8* var_v1;

    temp_s2 = Memmap_GetSegmentVaddr(D_300B870);
    sprintf(sp70, "%3d/%3d", arg2 & 0x3F, arg3);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 7; i++) {
        s32 c = sp70[i];

        switch (c) {
            case ' ':
                var_v1 = NULL;
                break;

            case '/':
                var_v1 = temp_s2[10];
                break;

            default:
                if ((c >= 0x30) && (c < 0x3A)) {
                    var_v1 = temp_s2[c - '0'];
                } else {
                    var_v1 = NULL;
                }
                break;
        }

        if (var_v1 != NULL) {
            func_8001C6AC(arg0, arg1, 8, 6, var_v1, 8, 0);
            arg0 += 8;
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    return arg0;
}

s32 func_84313908(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad[2];
    s8 sp70[7];
    s32 i;
    u8** temp_s2;
    u8* var_v1;

    temp_s2 = Memmap_GetSegmentVaddr(D_300B870);
    sprintf(sp70, "%3d/%3d", arg2 & 0x3F, arg3);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 7; i > 0; i--) {
        s32 c = sp70[i];

        switch (c) {
            case ' ':
                var_v1 = NULL;
                break;

            case '/':
                var_v1 = temp_s2[10];
                break;

            default:
                if ((c >= 0x30) && (c < 0x3A)) {
                    var_v1 = temp_s2[c - '0'];
                } else {
                    var_v1 = NULL;
                }
                break;
        }

        if (var_v1 != NULL) {
            func_8001C6AC(arg0, arg1, 8, 6, var_v1, 8, 0);
            arg0 -= 8;
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    return arg0;
}

void func_84313A74(unk_D_84390010* arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 i;
    s32 sp64[] = { 0, 0, 0, 0 };
    u8 sp60[4];
    unk_D_84390010_654_038* temp_s0;
    unk_func_80026268_arg0* sp58;
    UNUSED s32 pad;

    sp58 = &arg0->unk_720->unk_08[arg0->unk_728.unk_16C]->unk_01C[arg0->unk_654.unk_08];
    temp_s0 = &arg0->unk_654.unk_38;

    func_84310334(arg1 + 1, arg2 + 1, 0xC7, 0x38, &D_84385860[arg3], &D_84385870[arg3]);
    func_84311428(arg1, arg2, 0xC7, 0x38);

    for (i = 0; i < 4; i++) {
        if (temp_s0->unk_4E & 8) {
            sp60[i] = D_80072B00[temp_s0->unk_1F[i] - 1].unk_05 / 5;
            if (sp60[i] >= 8) {
                sp60[i] = 7;
            }
            sp60[i] = D_80072B00[temp_s0->unk_1F[i] - 1].unk_05 + (((temp_s0->unk_32[i] & 0xC0) >> 6) * sp60[i]);
        } else {
            sp60[i] = D_80072B00[sp58->unk_09[i] - 1].unk_05 / 5;
            if (sp60[i] >= 8) {
                sp60[i] = 7;
            }
            sp60[i] = D_80072B00[sp58->unk_09[i] - 1].unk_05 + (((sp58->unk_20[i] & 0xC0) >> 6) * sp60[i]);
        }
    }

    if (temp_s0->unk_4E & 8) {
        if ((temp_s0->unk_1F[0] != 0) && (temp_s0->unk_1F[0] < 0xA6)) {
            sp64[0] = func_84313908(arg1 + 0x52, arg2 + 0xF, temp_s0->unk_32[0], sp60[0]);
        }

        if ((temp_s0->unk_1F[1] != 0) && (temp_s0->unk_1F[1] < 0xA6)) {
            sp64[1] = func_8431379C(arg1 + 0x7C, arg2 + 0x1C, temp_s0->unk_32[1], sp60[1]);
        }

        if ((temp_s0->unk_1F[2] != 0) && (temp_s0->unk_1F[2] < 0xA6)) {
            sp64[2] = func_8431379C(arg1 + 0x70, arg2 + 0x30, temp_s0->unk_32[2], sp60[2]);
        }

        if ((temp_s0->unk_1F[3] != 0) && (temp_s0->unk_1F[3] < 0xA6)) {
            sp64[3] = func_84313908(arg1 + 0x44, arg2 + 0x23, temp_s0->unk_32[3], sp60[3]);
        }
    } else {
        if ((sp58->unk_09[0] != 0) && (sp58->unk_09[0] < 0xA6)) {
            sp64[0] = func_84313908(arg1 + 0x52, arg2 + 0xF, sp58->unk_20[0], sp60[0]);
        }

        if ((sp58->unk_09[1] != 0) && (sp58->unk_09[1] < 0xA6)) {
            sp64[1] = func_8431379C(arg1 + 0x7C, arg2 + 0x1C, sp58->unk_20[1], sp60[1]);
        }

        if ((sp58->unk_09[2] != 0) && (sp58->unk_09[2] < 0xA6)) {
            sp64[2] = func_8431379C(arg1 + 0x70, arg2 + 0x30, sp58->unk_20[2], sp60[2]);
        }

        if ((sp58->unk_09[3] != 0) && (sp58->unk_09[3] < 0xA6)) {
            sp64[3] = func_84313908(arg1 + 0x44, arg2 + 0x23, sp58->unk_20[3], sp60[3]);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    func_8001D560(arg1 + 0x5D, arg2 + 6, 0x10, 0xE, &D_3006A70, &D_3006C30, 0x10, 0x100000);
    func_8001D560(arg1 + 0x6C, arg2 + 0x16, 0x10, 0xE, &D_3006290, &D_3006450, 0x10, 0x100000);
    func_8001D560(arg1 + 0x5D, arg2 + 0x26, 0x10, 0xE, &D_3006530, &D_30066F0, 0x10, 0x100000);
    func_8001D560(arg1 + 0x4E, arg2 + 0x16, 0x10, 0xE, &D_30067D0, &D_3006990, 0x10, 0x100000);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (temp_s0->unk_4E & 8) {
        if ((temp_s0->unk_1F[0] != 0) && (temp_s0->unk_1F[0] < 0xA6)) {
            func_8001C6AC(sp64[0] - 0x19, arg2 + 0xE, 0x20, 9, D_843857C8[D_80072B00[temp_s0->unk_1F[0] - 1].unk_03],
                          0x20, 0);
        }

        if ((temp_s0->unk_1F[1] != 0) && (temp_s0->unk_1F[1] < 0xA6)) {
            func_8001C6AC(sp64[1], arg2 + 0x1B, 0x20, 9, D_843857C8[D_80072B00[temp_s0->unk_1F[1] - 1].unk_03], 0x20,
                          0);
        }

        if ((temp_s0->unk_1F[2] != 0) && (temp_s0->unk_1F[2] < 0xA6)) {
            func_8001C6AC(sp64[2], arg2 + 0x2F, 0x20, 9, D_843857C8[D_80072B00[temp_s0->unk_1F[2] - 1].unk_03], 0x20,
                          0);
        }

        if ((temp_s0->unk_1F[3] != 0) && (temp_s0->unk_1F[3] < 0xA6)) {
            func_8001C6AC(sp64[3] - 0x18, arg2 + 0x22, 0x20, 9, D_843857C8[D_80072B00[temp_s0->unk_1F[3] - 1].unk_03],
                          0x20, 0);
        }
    } else {
        if ((temp_s0->unk_1F[0] != 0) && (temp_s0->unk_1F[0] < 0xA6)) {
            func_8001C6AC(sp64[0] - 0x19, arg2 + 0xE, 0x20, 9, D_843857C8[D_80072B00[temp_s0->unk_1F[0] - 1].unk_03],
                          0x20, 0);
        }

        if ((temp_s0->unk_1F[1] != 0) && (temp_s0->unk_1F[1] < 0xA6)) {
            func_8001C6AC(sp64[1], arg2 + 0x1B, 0x20, 9, D_843857C8[D_80072B00[temp_s0->unk_1F[1] - 1].unk_03], 0x20,
                          0);
        }

        if ((temp_s0->unk_1F[2] != 0) && (temp_s0->unk_1F[2] < 0xA6)) {
            func_8001C6AC(sp64[2], arg2 + 0x2F, 0x20, 9, D_843857C8[D_80072B00[temp_s0->unk_1F[2] - 1].unk_03], 0x20,
                          0);
        }

        if ((temp_s0->unk_1F[3] != 0) && (temp_s0->unk_1F[3] < 0xA6)) {
            func_8001C6AC(sp64[3] - 0x18, arg2 + 0x22, 0x20, 9, D_843857C8[D_80072B00[temp_s0->unk_1F[3] - 1].unk_03],
                          0x20, 0);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(1, 0);

    if (temp_s0->unk_4E & 8) {
        if ((temp_s0->unk_1F[0] != 0) && (temp_s0->unk_1F[0] < 0xA6)) {
            if (arg0->unk_654.unk_C1[0] == 1) {
                func_8001F324(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            }
            func_84313750(arg1 + 0x5A, arg2 + 4, func_8002D7C0(NULL, 0, D_843900B8, temp_s0->unk_1F[0] - 1));
        }

        if ((temp_s0->unk_1F[1] != 0) && (temp_s0->unk_1F[1] < 0xA6)) {
            if (arg0->unk_654.unk_C1[1] == 1) {
                func_8001F324(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            }
            func_8001F1E8(arg1 + 0x7C, arg2 + 0x11, func_8002D7C0(NULL, 0, D_843900B8, temp_s0->unk_1F[1] - 1));
        }

        if ((temp_s0->unk_1F[2] != 0) && (temp_s0->unk_1F[2] < 0xA6)) {
            if (arg0->unk_654.unk_C1[2] == 1) {
                func_8001F324(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            }
            func_8001F1E8(arg1 + 0x6E, arg2 + 0x25, func_8002D7C0(NULL, 0, D_843900B8, temp_s0->unk_1F[2] - 1));
        }

        if ((temp_s0->unk_1F[3] != 0) && (temp_s0->unk_1F[3] < 0xA6)) {
            if (arg0->unk_654.unk_C1[3] == 1) {
                func_8001F324(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            }
            func_84313750(arg1 + 0x4C, arg2 + 0x18, func_8002D7C0(NULL, 0, D_843900B8, temp_s0->unk_1F[3] - 1));
        }
    } else {
        if ((temp_s0->unk_1F[0] != 0) && (temp_s0->unk_1F[0] < 0xA6)) {
            if (arg0->unk_654.unk_C1[0] == 1) {
                func_8001F324(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            }
            func_84313750(arg1 + 0x5A, arg2 + 4, func_8002D7C0(NULL, 0, D_843900B8, temp_s0->unk_1F[0] - 1));
        }

        if ((temp_s0->unk_1F[1] != 0) && (temp_s0->unk_1F[1] < 0xA6)) {
            if (arg0->unk_654.unk_C1[1] == 1) {
                func_8001F324(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            }
            func_8001F1E8(arg1 + 0x7C, arg2 + 0x11, func_8002D7C0(NULL, 0, D_843900B8, temp_s0->unk_1F[1] - 1));
        }

        if ((temp_s0->unk_1F[2] != 0) && (temp_s0->unk_1F[2] < 0xA6)) {
            if (arg0->unk_654.unk_C1[2] == 1) {
                func_8001F324(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            }
            func_8001F1E8(arg1 + 0x6E, arg2 + 0x25, func_8002D7C0(NULL, 0, D_843900B8, temp_s0->unk_1F[2] - 1));
        }

        if ((temp_s0->unk_1F[3] != 0) && (temp_s0->unk_1F[3] < 0xA6)) {
            if (arg0->unk_654.unk_C1[3] == 1) {
                func_8001F324(0xFF, 0x64, 0xFF, 0xFF);
            } else {
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            }
            func_84313750(arg1 + 0x4C, arg2 + 0x18, func_8002D7C0(NULL, 0, D_843900B8, temp_s0->unk_1F[3] - 1));
        }
    }

    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);

    if (temp_s0->unk_1F[0] >= 0xA6) {
        func_84313750(arg1 + 0x5A, arg2 + 4, "？？？？？");
    }

    if (temp_s0->unk_1F[1] >= 0xA6) {
        func_8001F1E8(arg1 + 0x7C, arg2 + 0x11, "？？？？？");
    }

    if (temp_s0->unk_1F[2] >= 0xA6) {
        func_8001F1E8(arg1 + 0x6E, arg2 + 0x25, "？？？？？");
    }

    if (temp_s0->unk_1F[3] >= 0xA6) {
        func_84313750(arg1 + 0x4C, arg2 + 0x18, "？？？？？");
    }

    func_8001F444();
    func_8430FC28(arg1 - 2, arg2 - 2, 0xCD, 0x3E, 0);
}

void func_8431493C(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    UNUSED s32 pad[2];
    s32 var_v1;

    if (func_80029074()[arg2].unk_000 & 2) {
        var_v1 = 4;
    } else {
        var_v1 = arg2;
    }

    func_84310334(arg0 + 1, arg1 + 1, 0xC6, 0x28, &D_84385860[var_v1], &D_84385870[var_v1]);
    func_8001F3F4();
    func_8001EBE0(2, 0);
    func_8001F1E8(arg0 + 0x2E, arg1 + 6, "こうさんしますか?");
    func_8001F1E8(arg0 + 0x38, arg1 + 0x18, "いいえ");
    func_8001F1E8(arg0 + 0x81, arg1 + 0x18, "はい");
    func_8001F444();

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    func_8001D560(arg0 + 0x21, arg1 + 0x17, 0x18, 0xE, D_30092C0, D_3009560, 0x18, 0x100000);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_84311428(arg0, arg1, 0xC6, 0x28);
    func_8430FC28(arg0 - 3, arg1 - 2, 0xCC, 0x2D, 0);
}

void func_84314B20(s16 arg0, s16 arg1, char* arg2) {
    func_8001F3F4();
    func_8001EBE0(1, 0);
    func_8001F1E8(arg0, arg1, arg2);
    func_8001F444();
}

void func_84314B6C(unk_D_84390010* arg0, unk_D_800AE540_0004* arg1, unk_func_80026268_arg0* arg2, s32 arg3, s32 arg4,
                   s32 arg5) {
    s32 var_t0;

    func_843109F4(arg3 + 3, arg4 + 4, arg2->unk_24);
    func_84310368(arg3 + 0x1E, arg4 + 0xE, arg2->unk_02, arg2->unk_26);
    func_84310B9C(arg3 + 0x26, arg4 + 0x14, arg2->unk_02, arg2->unk_26);

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    if (arg5 == 0) {
        func_8001D560(arg3 + 2, arg4 + 0xD, 0x10, 0xE, D_3006A70, D_3006C30, 0x10, 0x100000);
    }

    if (arg5 == 1) {
        func_8001D560(arg3 + 2, arg4 + 0xD, 0x10, 0xE, D_30067D0, D_3006990, 0x10, 0x100000);
    }

    if (arg5 == 2) {
        func_8001D560(arg3 + 2, arg4 + 0xD, 0x10, 0xC, D_3008E40, D_3008FC0, 0x10, 0x100000);
    }

    if (arg5 == 3) {
        func_8001D560(arg3 + 2, arg4 + 0xD, 0x10, 0xE, D_3006290, D_3006450, 0x10, 0x100000);
    }

    if (arg5 == 4) {
        func_8001D560(arg3 + 2, arg4 + 0xD, 0x10, 0xE, D_3006530, D_30066F0, 0x10, 0x100000);
    }

    if (arg5 == 5) {
        func_8001D560(arg3 + 2, arg4 + 0xD, 0x10, 0xC, D_3008C00, D_3008D80, 0x10, 0x100000);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(1, 0);
    func_8001F1E8(arg3 + 0x1D, arg4 + 2, arg2->unk_30);
    func_8001F444();

    if (arg1->unk_01C[arg5].unk_02 == 0) {
        var_t0 = 1;
    } else {
        var_t0 = func_800219A0(arg1->unk_01C[arg5].unk_05);
    }

    if (var_t0 != 0) {
        gSPDisplayList(gDisplayListHead++, D_8006F518);

        func_8001C6AC(arg3 + 0x11, arg4 + 0x14, 0x14, 9, D_84385838[var_t0 - 1], 0x14, 0);
        gSPDisplayList(gDisplayListHead++, D_8006F630);
    }
}

void func_84314F60(unk_D_84390010* arg0, unk_D_800AE540_0004* arg1, unk_func_80026268_arg0* arg2, s32 arg3, s32 arg4,
                   s32 arg5) {
    s32 var_t0;

    func_843109F4(arg3 + 3, arg4 + 4, arg2->unk_24);
    func_84310368(arg3 + 0x1E, arg4 + 0xE, arg2->unk_02, arg2->unk_26);
    func_84310B9C(arg3 + 0x26, arg4 + 0x14, arg2->unk_02, arg2->unk_26);

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    if (arg5 == 0) {
        func_8001D560(arg3 + 2, arg4 + 0xD, 0x10, 0xE, D_3006A70, D_3006C30, 0x10, 0x100000);
    }

    if (arg5 == 1) {
        func_8001D560(arg3 + 2, arg4 + 0xD, 0x10, 0xE, D_3006290, D_3006450, 0x10, 0x100000);
    }

    if (arg5 == 2) {
        func_8001D560(arg3 + 2, arg4 + 0xD, 0x10, 0xE, D_3006530, D_30066F0, 0x10, 0x100000);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8001F3F4();
    func_8001EBE0(1, 0);
    func_8001F1E8(arg3 + 0x1D, arg4 + 2, arg2->unk_30);
    func_8001F444();

    if (arg1->unk_01C[arg5].unk_02 == 0) {
        var_t0 = 1;
    } else {
        var_t0 = func_800219A0(arg1->unk_01C[arg5].unk_05);
    }

    if (var_t0 != 0) {
        gSPDisplayList(gDisplayListHead++, D_8006F518);

        func_8001C6AC(arg3 + 0x11, arg4 + 0x14, 0x14, 9, D_84385838[var_t0 - 1], 0x14, 0);

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    }
}

void func_8431524C(unk_D_84390010* arg0, unk_D_800AE540_0004* arg1, s16 arg2, s16 arg3, s32 arg4) {
    UNUSED s32 pad[2];
    Color_RGB8* sp88[] = {
        D_84385888,
        D_843858A0,
        D_843858B8,
        D_843858D0,
    };
    Color_RGB8* sp78[] = {
        D_84385894,
        D_843858AC,
        D_843858C4,
        D_843858DC,
    };
    UNUSED s32 pad2[4];

    func_84310334(arg2 + 1, arg3 + 1, 0x63, 0xF, &sp88[arg4][0], &sp78[arg4][0]);
    func_84310334(arg2 + 1, arg3 + 0x10, 0x63, 0x1D, &sp88[arg4][1], &sp78[arg4][1]);
    func_84310334(arg2 + 1, arg3 + 0x2D, 0x63, 0x1D, &sp88[arg4][2], &sp78[arg4][2]);
    func_84310334(arg2 + 1, arg3 + 0x4A, 0x63, 0x1D, &sp88[arg4][3], &sp78[arg4][3]);

    func_84314B20((arg2 - (func_8001F5B0(1, 0, arg1->unk_008) / 2)) + 0x32, arg3 + 3, arg1->unk_008);

    if (arg1->unk_002 > 0) {
        func_84314F60(arg0, arg1, &arg1->unk_01C[0], arg2 + 1, arg3 + 0x10, 0);
    }

    if (arg1->unk_002 >= 2) {
        func_84314F60(arg0, arg1, &arg1->unk_01C[1], arg2 + 1, arg3 + 0x2D, 1);
    }

    if (arg1->unk_002 >= 3) {
        func_84314F60(arg0, arg1, &arg1->unk_01C[2], arg2 + 1, arg3 + 0x4A, 2);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(arg2 + 1, arg3, 0x18, 0x10, D_84385850[arg4], 0x18, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_84311428(arg2, arg3, 0x63, 0x66);
    func_8430FC28(arg2 - 2, arg3 - 2, 0x69, 0x6A, 0);
}

void func_84315550(unk_D_84390010* arg0, s16 arg1, s16 arg2, s32 arg3) {
    unk_D_800AE540_0004* temp_s0;
    unk_D_800AE540_0004* temp_s1;
    unk_func_80026268_arg0* ptr = &arg0->unk_724->unk_01C[0];
    s32 i;
    Color_RGB8* sp88[] = {
        D_84385888,
        D_843858A0,
        D_843858B8,
        D_843858D0,
    };
    Color_RGB8* sp78[] = {
        D_84385894,
        D_843858AC,
        D_843858C4,
        D_843858DC,
    };
    s32 tmp;
    unk_func_80026268_arg0* sp5C[6];

    temp_s0 = arg0->unk_720->unk_08[arg0->unk_728.unk_16C];
    temp_s1 = arg0->unk_724;

    sp5C[5] = &temp_s1->unk_01C[0];
    sp5C[5] = &temp_s1->unk_01C[0];
    sp5C[4] = &temp_s1->unk_01C[1];
    sp5C[3] = &temp_s1->unk_01C[2];
    sp5C[2] = &temp_s1->unk_01C[3];
    sp5C[1] = &temp_s1->unk_01C[4];
    sp5C[0] = &temp_s1->unk_01C[5];

    func_84310334(arg1 + 1, arg2 + 1, 0xC8, 0xF, &sp88[arg3][0], &sp78[arg3][0]);
    func_84310334(arg1 + 1, arg2 + 0x10, 0xC8, 0x1D, &sp88[arg3][1], &sp78[arg3][1]);
    func_84310334(arg1 + 1, arg2 + 0x2D, 0xC8, 0x1D, &sp88[arg3][2], &sp78[arg3][2]);
    func_84310334(arg1 + 1, arg2 + 0x4A, 0xC8, 0x1D, &sp88[arg3][3], &sp78[arg3][3]);
    tmp = func_8001F5B0(1, 0, temp_s0->unk_008) / 2;
    func_84314B20((arg1 - tmp) + 0x32, arg2 + 3, temp_s0->unk_008);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC(arg1 + 1, arg2, 0x18, 0x10, *(D_84385850 + arg3), 0x18, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    if (temp_s0->unk_002 > 0) {
        func_84314B6C(arg0, temp_s0, sp5C[5], arg1 + 1, arg2 + 0x10, 0);
    }

    if (temp_s0->unk_002 >= 2) {
        func_84314B6C(arg0, temp_s0, sp5C[4], arg1 + 1, arg2 + 0x2D, 1);
    }

    if (temp_s0->unk_002 >= 3) {
        func_84314B6C(arg0, temp_s0, sp5C[3], arg1 + 1, arg2 + 0x4A, 2);
    }

    if (temp_s0->unk_002 >= 4) {
        func_84314B6C(arg0, temp_s0, sp5C[2], arg1 + 0x66, arg2 + 0x10, 3);
    }

    if (temp_s0->unk_002 >= 5) {
        func_84314B6C(arg0, temp_s0, sp5C[1], arg1 + 0x66, arg2 + 0x2D, 4);
    }

    if (temp_s0->unk_002 >= 6) {
        func_84314B6C(arg0, temp_s0, sp5C[0], arg1 + 0x66, arg2 + 0x4A, 5);
    }

    func_84311428(arg1, arg2, 0xC8, 0x66);
    func_8430FC28(arg1 - 2, arg2 - 2, 0xCE, 0x6A, 0);
}

void func_8431595C(unk_D_84390010* arg0, s16 arg1, s16 arg2, s32 arg3) {
    UNUSED s32 pad;
    Color_RGB8* var_v0;
    u32 var_t0;
    unk_D_84390010_654* temp_v0;
    u16 tmp;
    unk_func_80026268_arg0* sp40;

    sp40 = &arg0->unk_720->unk_08[arg0->unk_728.unk_16C]->unk_01C[arg0->unk_654.unk_08];
    temp_v0 = &arg0->unk_654;

    if (sp40->unk_02 == 0) {
        var_t0 = 1;
    } else {
        var_t0 = func_800219A0(sp40->unk_05);
    }

    if (temp_v0->unk_30 < 0xFF00) {
        temp_v0->unk_30 -= 0x30;
    }

    tmp = temp_v0->unk_30;
    if ((tmp >> 8) & 1) {
        var_v0 = &D_84385860[arg3];
    } else {
        var_v0 = &D_8438587C[arg3];
    }

    func_84311048(arg0, sp40, &D_84385790[var_t0], arg1 + 1, arg2 + 1, 0x46, 0x28, var_v0->r, var_v0->g, var_v0->b,
                  0xB2);
    func_84311428(arg1, arg2, 0x46, 0x28);
    func_8430FC28(arg1 - 2, arg2 - 2, 0x4C, 0x2D, 0);
}

void func_84315ADC(s32 arg0, s16 arg1, s16 arg2, char* arg3) {
    func_84310334(arg1 + 1, arg2 + 1, 0xEE, 0x24, &D_84385860[arg0], &D_84385870[arg0]);
    func_8001F3F4();
    func_8001EBE0(2, 0);
    func_8001F3B4(0x10);
    func_8001F1E8(arg1 + 0xA, arg2 + 5, arg3);
    func_8001F444();
    func_84311428(arg1, arg2, 0xEE, 0x24);
    func_8430FC28(arg1 - 2, arg2 - 1, 0xF4, 0x29, 0);
}

s32 func_84315BC0(char* arg0, s16 arg1, s16 arg2) {
    if (*(s8*)arg0 == 0) {
        return 0;
    }
    func_8001F3F4();
    func_8001EBE0(1, 0);
    func_8001F1E8(arg1, arg2, arg0);
    func_8001F444();
    return 1;
}

void func_84315C28(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2, Vec3f arg3) {
    s16 sp2C;
    s16 sp28;
    Color_RGB8* temp_v0;
    unk_D_84390010* temp_v1;
    unk_D_800AE540_0004* tmp;

    temp_v1 = D_84390010[arg0->unk_0C];
    tmp = temp_v1->unk_720->unk_08[temp_v1->unk_728.unk_16C];
    temp_v0 = &D_84385860[tmp->unk_001];

    sp2C = (arg1 - arg3.x) * 2;
    sp28 = (arg2 - arg3.y) * 2;

    func_8001F504(arg3.x, arg3.y, sp2C, sp28, temp_v0->r, temp_v0->g, temp_v0->b, 0x96);
    func_84311428(arg3.x, arg3.y, sp2C, sp28);
    func_8430FC28(arg0->unk_14.x - 2.0f, arg0->unk_14.y - 1.0f, 0xE0, 0x2B, 0);
}

void func_84315D88(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2) {
    Vec3f sp4C;
    Vec3f sp40;
    Vec3f sp34;
    UNUSED s32 pad;

    arg0->unk_08 = 0;
    arg0->unk_10 = 0;
    func_8000E88C(&sp40, arg1, arg2, 0.0f);
    func_8000E88C(&sp34, arg1 - 110.0f, arg2 - 19.0f, 0.0f);
    func_800102A4(&sp40, &sp34, &arg0->unk_20, &arg0->unk_28, &arg0->unk_2A);
    func_80010354(&sp40, &arg0->unk_14, arg0->unk_20, arg0->unk_28, arg0->unk_2A);
    arg0->unk_24 = arg0->unk_20 * 0.3f;
    func_80010354(&sp40, &sp4C, arg0->unk_24, arg0->unk_28, arg0->unk_2A);
    func_84315C28(arg0, arg1, arg2, sp4C);
}

s32 func_84315EC0(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2) {
    Vec3f sp34;
    Vec3f sp28;

    func_8000E88C(&sp28, arg1, arg2, 0.0f);
    arg0->unk_24 = func_800104AC(arg0->unk_24, arg0->unk_20, 15.0f, 15.0f);
    func_80010354(&sp28, &sp34, arg0->unk_24, arg0->unk_28, arg0->unk_2A);
    func_84315C28(arg0, arg1, arg2, sp34);

    if (arg0->unk_24 == arg0->unk_20) {
        return 1;
    }
    return 0;
}

void func_84315FAC(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2, Vec3f arg3) {
    func_8001F504(arg3.x, arg3.y, (s16)((arg1 - arg3.x) * 2), (s16)((arg2 - arg3.y) * 2), 0, 0, 0, 0x96);
    func_84311428(arg3.x, arg3.y, (s16)((arg1 - arg3.x) * 2), (s16)((arg2 - arg3.y) * 2));
    func_8430FC28(arg0->unk_14.x - 2.0f, arg0->unk_14.y - 1.0f, 0xE0, 0x2B, 0);
}

void func_843160C0(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2) {
    Vec3f sp4C;
    Vec3f sp40;
    Vec3f sp34;
    UNUSED s32 pad;

    arg0->unk_08 = 0;
    arg0->unk_10 = 0;
    func_8000E88C(&sp40, arg1, arg2, 0.0f);
    func_8000E88C(&sp34, arg1 - 50.0f, arg2 - 10.0f, 0.0f);
    func_800102A4(&sp40, &sp34, &arg0->unk_20, &arg0->unk_28, &arg0->unk_2A);
    func_80010354(&sp40, &arg0->unk_14, arg0->unk_20, arg0->unk_28, arg0->unk_2A);
    arg0->unk_24 = arg0->unk_20 * 0.3f;
    func_80010354(&sp40, &sp4C, arg0->unk_24, arg0->unk_28, arg0->unk_2A);
    func_84315FAC(arg0, arg1, arg2, sp4C);
}

s32 func_843161F8(unk_D_843901A0_4C8* arg0, s16 arg1, s16 arg2) {
    Vec3f sp34;
    Vec3f sp28;

    func_8000E88C(&sp28, arg1, arg2, 0.0f);
    arg0->unk_24 = func_800104AC(arg0->unk_24, arg0->unk_20, 15.0f, 15.0f);
    func_80010354(&sp28, &sp34, arg0->unk_24, arg0->unk_28, arg0->unk_2A);
    func_84315FAC(arg0, arg1, arg2, sp34);

    if (arg0->unk_24 == arg0->unk_20) {
        return 1;
    }
    return 0;
}

void func_843162E4(s32 arg0, s16 arg1, s16 arg2, char* arg3) {
    func_84310334(arg1 + 1, arg2 + 1, 0xC8, 0x24, &D_84385860[arg0], &D_84385870[arg0]);
    func_8001F3F4();
    func_8001EBE0(2, 0);
    func_8001F3B4(0x10);
    func_8001F1E8(arg1 + 0xA, arg2 + 5, arg3);
    func_8001F444();
    func_84311428(arg1, arg2, 0xC8, 0x25);
    func_8430FC28(arg1 - 2, arg2 - 1, 0xCD, 0x28, 0);
}

void func_843163C8(unk_D_84390010* arg0, s16 arg1, s16 arg2, s32 arg3) {
    UNUSED s32 pad;
    s32 sp48;
    UNUSED s32 pad2[2];

    func_84310334(arg1 + 1, arg2 + 1, 0xC8, 0x24, &D_84385860[arg3], &D_84385870[arg3]);
    func_8001F3F4();
    func_8001EBE0(2, 0);
    sp48 = func_8001F5B0(2, 0, func_8002D7C0(NULL, 0, D_843900B0, 0xA1)) / 2;
    func_8001F1E8((arg1 - sp48) + 0x61, arg2 + 5, func_8002D7C0(NULL, 0, D_843900B0, 0xA1));
    func_8001F1E8(arg1 + 0x32, arg2 + 0x14, func_8002D7C0(NULL, 0, D_843900B0, 0xA3));
    func_8001F1E8(arg1 + 0x7A, arg2 + 0x14, func_8002D7C0(NULL, 0, D_843900B0, 0xA2));
    func_8001F444();

    gSPDisplayList(gDisplayListHead++, D_8006F5A0);

    func_8001D560(arg1 + (arg0->unk_654.unk_2F * 0x49) + 0x1B, arg2 + 0x14, 0x18, 0xE, &D_30092C0, &D_3009560, 0x18,
                  0x100000);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_84311428(arg1, arg2, 0xC8, 0x25);
    func_8430FC28(arg1 - 2, arg2 - 1, 0xCD, 0x28, 0);
}

void func_84316610(void) {
    if (func_8436EF48() != 0) {
        func_8436F664();
    }
}

void func_84316640(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
    unk_D_800A7440 sp30;

    func_80005FC0(&sp30, arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1);

    if (func_80006030(&sp30) != 0) {
        if (arg6 != 0) {
            arg4 += ((sp30.x1 - arg0) * arg6) >> 5;
        }

        if (arg7 != 0) {
            arg5 += ((sp30.y2 - arg1) * arg7) >> 5;
        }

        sp30.y1 += 1;
        sp30.x2 += 1;

        gSPTextureRectangle(gDisplayListHead++, sp30.x1 << 2, sp30.y2 << 2, sp30.y1 << 2, sp30.x2 << 2, G_TX_RENDERTILE,
                            arg4, arg5, arg6, arg7);
    }
}

void func_843167D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4, s32 arg5) {
    gDPLoadTextureTile(gDisplayListHead++, arg4, G_IM_FMT_RGBA, G_IM_SIZ_32b, arg2, 0, 0, 0, arg2 - 1, arg3 - 1, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    func_84316640(arg0, arg1, arg2, arg3, 0, 0, 0x400, 0);
}

void func_8431694C(void) {
    s32 i;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 0x30; i++) {
        func_843167D4(0x1E, i + 0x17, 0x58, 1, &D_3001F70[i * 0x160], 0x58);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    func_8430FC28(0x1C, 0x16, 0x5E, 0x34, 0);
}

void func_84316A1C(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9,
                   u8 argA, u8 argB, u8 argC) {
    UNUSED s32 pad;
    unk_D_80068BB0* temp_s1 = func_8000648C();
    Vtx* temp_s2 = func_80005F5C(sizeof(Vtx) * 4);
    Mtx* spC0 = func_80005F5C(sizeof(Mtx) * 1);
    Vp* spBC = func_80005F5C(sizeof(Vp));

    func_8001E6E8(spBC, temp_s1->width, temp_s1->height);

    gSPViewport(gDisplayListHead++, (u32)spBC & 0x1FFFFFFF);

    guOrtho(spC0, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    func_8001E680(&temp_s2[0], arg1, arg2, -1, argC << 5, 0, 0xFF, 0xF0, 0, 0xFF);
    func_8001E680(&temp_s2[1], arg1 + arg3, arg2, -1, argB << 5, 0, 0xFF, 0xF0, 0, 0xFF);
    func_8001E680(&temp_s2[2], arg1, arg2 + arg4, -1, argC << 5, arg6 << 5, 0xFF, 0, 0x64, 0xFF);
    func_8001E680(&temp_s2[3], arg1 + arg3, arg2 + arg4, -1, argB << 5, arg6 << 5, 0xFF, 0, 0x64, 0xFF);

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL0, COMBINED, 0,
                      SHADE, 0, 0, 0, 0, COMBINED);
    gDPSetRenderMode(gDisplayListHead++, G_RM_PASS, G_RM_XLU_SURF2);
    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, 255);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureTile(gDisplayListHead++, arg0, G_IM_FMT_IA, G_IM_SIZ_8b, arg5, 0, arg7, arg8, arg9 - 1, argA - 1, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
    gSPMatrix(gDisplayListHead++, (u32)spC0 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gDisplayListHead++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(gDisplayListHead++, 0, 2, 3, 0, 0, 3, 1, 0);
    gSPDisplayList(gDisplayListHead++, D_8006F630);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
}

void func_84317004(void) {
    D_84390190.x = func_800104AC(D_84390190.x, 52.0f, 80.0f, 80.0f);
    func_84316A1C(D_3000470, D_84390190.x, D_84390190.y, 0x6C, 0x20, 0xD8, 0x20, 0, 0, 0x6C, 0x20, 0x6B, 0);
    func_84316A1C(D_3000470, (s32)D_84390190.x + 0x6C, D_84390190.y, 0x6C, 0x20, 0xD8, 0x20, 0x6C, 0, 0xD8, 0x20, 0xD7,
                  0x6C);
}

void func_8431712C(void) {
    static s32 D_84385988 = 0;

    s32 sp24;
    s16 temp_s0;

    if (!(Cont_GetControllerBits() & 1)) {
        sp24 = func_8001F5B0(4, 0, func_8002D7C0(NULL, 0, D_843900C0, 0));
        temp_s0 = 0x50 - D_84385988;

        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 16, 0, 304, 240);

        func_8001F3F4();
        func_8001EBE0(4, 0);
        func_8001F1E8(temp_s0, 0xB3, func_8002D7C0(NULL, 0, D_843900C0, 0));

        temp_s0 += sp24 + 0x1E;
        if (temp_s0 < 0x140) {
            func_8001F1E8(temp_s0, 0xB3, func_8002D7C0(NULL, 0, D_843900C0, 0));
        }
        func_8001F444();

        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 320, 240);

        D_84385988++;
        if (D_84385988 >= (sp24 + 0x50)) {
            D_84385988 = 0x32;
        }
    }
}

void func_843172A0(unk_D_84390010* arg0, unk_D_84390010_654* arg1) {
    unk_D_800AE540_0004* sp34 = arg0->unk_720->unk_08[arg0->unk_728.unk_16C];
    UNUSED s32 pad;
    s32 var_v1;

    if (D_800AE540.unk_0000 != 0x10) {
        if (arg1->unk_10 == 3) {
            func_84311F30(arg0, arg0->unk_728.unk_168->unk_1C - 2, arg0->unk_728.unk_168->unk_1E - 0x3A, arg1->unk_1E,
                          1);
        } else {
            func_84311F30(arg0, arg0->unk_728.unk_168->unk_1C - 2, arg0->unk_728.unk_168->unk_1E - 0x3A, arg1->unk_1E,
                          0);
        }

        if ((arg1->unk_10 != 3) && (arg0->unk_728.unk_168->unk_1C == 0x17)) {
            switch (arg1->unk_10) {
                case 2:
                    if (arg1->unk_1C == 1) {
                        if (arg0->unk_720->unk_01 == 2) {
                            if (arg0->unk_720->unk_08[1]->unk_001 < arg0->unk_720->unk_08[0]->unk_001) {
                                var_v1 = 0;
                            } else {
                                var_v1 = 1;
                            }
                            func_8431524C(arg0, arg0->unk_720->unk_08[var_v1], 0x60, 0xF,
                                          arg0->unk_720->unk_08[var_v1]->unk_001);
                            func_8431524C(arg0, arg0->unk_720->unk_08[var_v1 == 0], 0xC6, 0xF,
                                          arg0->unk_720->unk_08[var_v1 == 0]->unk_001);
                        } else if (arg0->unk_724->unk_002 < 4) {
                            func_8431524C(arg0, arg0->unk_720->unk_08[0], 0x60, 0xF, sp34->unk_001);
                        } else {
                            func_84315550(arg0, 0x60, 0xF, sp34->unk_001);
                        }
                    } else if (arg1->unk_2D == 0x10) {
                        func_843135B8(arg0, 0x60, 0xF, sp34->unk_001);
                    } else {
                        func_843133B4(arg0, 0x60, 0xF, sp34->unk_001);
                    }
                    break;

                case 1:
                    if (arg1->unk_1C == 1) {
                        func_84313A74(arg0, 0x60, 0xF, sp34->unk_001);
                    } else {
                        func_843133B4(arg0, 0x60, 0xF, sp34->unk_001);
                    }
                    break;

                case 4:
                    func_843163C8(arg0, 0x5F, 0xE, sp34->unk_001);
                    break;

                default:
                    func_84313148(arg0, 0x60, 0xF, sp34->unk_001);
                    break;
            }
        }
    }
}

void func_84317558(unk_D_84390010* arg0, unk_D_84390010_654* arg1) {
    unk_D_800AE540_0004* sp24 = arg0->unk_720->unk_08[arg0->unk_728.unk_16C];
    s32 sp20;

    if (D_800AE540.unk_0000 != 0x10) {
        if (arg1->unk_10 == 3) {
            func_843128A0(arg0, arg0->unk_728.unk_168->unk_1C - 0x20, arg0->unk_728.unk_168->unk_1E - 2, arg1->unk_1E,
                          1);
        } else {
            func_843128A0(arg0, arg0->unk_728.unk_168->unk_1C - 0x20, arg0->unk_728.unk_168->unk_1E - 2, arg1->unk_1E,
                          0);
        }

        if ((arg1->unk_10 != 3) && (arg0->unk_728.unk_168->unk_1C == 0x103)) {
            switch (arg1->unk_10) {
                case 2:
                    if (arg1->unk_1C == 1) {
                        if (arg0->unk_720->unk_01 == 2) {
                            if (arg0->unk_720->unk_08[1]->unk_001 < arg0->unk_720->unk_08[0]->unk_001) {
                                sp20 = 0;
                            } else {
                                sp20 = 1;
                            }
                            func_8431524C(arg0, arg0->unk_720->unk_08[sp20 == 0], 0x16, 0x79,
                                          arg0->unk_720->unk_08[sp20 == 0]->unk_001);
                            func_8431524C(arg0, arg0->unk_720->unk_08[sp20], 0x7C, 0x79,
                                          arg0->unk_720->unk_08[sp20]->unk_001);
                        } else if (arg0->unk_724->unk_002 < 4) {
                            func_8431524C(arg0, arg0->unk_720->unk_08[0], 0x7C, 0x79, sp24->unk_001);
                        } else {
                            func_84315550(arg0, 0x18, 0x79, sp24->unk_001);
                        }
                    } else if (arg1->unk_2D == 0x10) {
                        func_843135B8(arg0, 0x98, 0xCE, sp24->unk_001);
                    } else {
                        func_843133B4(arg0, 0x62, 0xCE, sp24->unk_001);
                    }
                    break;

                case 1:
                    if (arg1->unk_1C == 1) {
                        func_84313A74(arg0, 0x19, 0xA6, sp24->unk_001);
                    } else {
                        func_843133B4(arg0, 0x62, 0xCE, sp24->unk_001);
                    }
                    break;

                case 4:
                    func_843163C8(arg0, 0x17, 0xBB, sp24->unk_001);
                    break;

                default:
                    func_84313148(arg0, 0x18, 0xCE, sp24->unk_001);
                    break;
            }
        }
    }
}
