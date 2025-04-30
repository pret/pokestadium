#include "fragment63.h"
#include "src/12D80.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/4CBC0.h"
#include "src/6BC0.h"
#include "src/F420.h"
#include "src/memmap.h"
#include "src/memory.h"

static u32 D_84B11C20[] = {
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x39CF39CF, 0x39CF294B,
    0x18C70001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x10856B5B, 0xC631F7BD, 0xFFFFFFFF, 0xFFFFFFFF, 0xF7BDB5AD, 0x6319294B,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x1085A529, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFF7BD, 0xB5AD39CF, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x0001A527, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA5212949, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00012947, 0xDEE9FFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFBDEE7, 0x42090001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x1083DEDF, 0xFFF5FFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFD, 0xFFF5FFED, 0xDEDD2945, 0x00010001, 0x00010001, 0x00010001, 0x00011083, 0xDED5FFE1,
    0xFFEDFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFF3, 0xFFEFFFF3,
    0xFFF1FFE9, 0xFFDFDED7, 0x18C30001, 0x00010001, 0x00010001, 0x00016309, 0xFF95FFDB, 0xFFE5FFF9, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFF5FFEB, 0xFFE7FFE7, 0xFFEBFFE7, 0xFFDFFFDB,
    0xA50D0001, 0x00010001, 0x00010001, 0x1083F60F, 0xFED1FFDB, 0xFFE5FFEF, 0xFFF5FFF3, 0xFFF9FFFD, 0xFFF9FFFF,
    0xFFFFFFFF, 0xFFFFFFF9, 0xFFF7FFFB, 0xFFEFFFE7, 0xFFDFFFE1, 0xFFE5FFE1, 0xFFDFFFDB, 0xF79339C5, 0x00010001,
    0x00010001, 0xA389FD4D, 0xFE4FFFDB, 0xFFE1FFE5, 0xFFE9FFE9, 0xFFF1FFF3, 0xFFEDFFF9, 0xFFFFFFFF, 0xFFFFFFEF,
    0xFFEDFFEF, 0xFFE7FFE7, 0xFFDBFFDB, 0xFFDDFFDD, 0xFFDDFFD7, 0xFFD593C9, 0x00010001, 0x00011083, 0xFE0DFD4B,
    0xFF53FFDB, 0xFFDDFFDF, 0xFFE1FFE3, 0xFFE9FFE7, 0xFFE7FFF3, 0xFFFDFFF9, 0xFFFDFFE9, 0xFFE5FFE5, 0xFFE5FFE1,
    0xFFDFFFD5, 0xFFD9FFD9, 0xFFD9FFD7, 0xFFD1FD8D, 0x28830001, 0x00017B07, 0xFE0DFE4F, 0xFF93FFD7, 0xFFD7FFDB,
    0xFFDBFFE1, 0xFFDFFFDD, 0xFFDFFFEB, 0xFFEFFFEF, 0xFFEFFFE1, 0xFFDBFFDD, 0xFFDFFFD9, 0xFFDDFFD5, 0xFFD3FFD7,
    0xFFD7FFD3, 0xFFD1FCCB, 0x59430001, 0x0001B449, 0xFD4DFD8B, 0xFE91FF93, 0xFFD5FFD5, 0xFFD7FFD7, 0xFF95FFD5,
    0xFFD9FFE1, 0xFFE3FFE1, 0xFFE3FFDB, 0xFFD3FFD5, 0xFFD5FFD3, 0xFFD5FFD1, 0xFFD1FFD5, 0xFFD5FFD1, 0xFECFFD0B,
    0xAA450001, 0x0001DD0B, 0xFD0BFD0B, 0xFDCFFE0F, 0xFF91FE0F, 0xFF0FFD8D, 0xFE0DFF4F, 0xFF53FFD9, 0xFFD9FFD7,
    0xFFD9FFD7, 0xFE8FFECF, 0xFF0DFF0F, 0xFE0DFE8D, 0xFECFFE8F, 0xFF91FF91, 0xFDCDFD09, 0xF3090001, 0x0001FD4D,
    0xFC89FC49, 0xFD0DFCCB, 0xFD8DFD4B, 0xFD4BFC07, 0xFDCDFECF, 0xFE8FFFD3, 0xFECFFED1, 0xFFD3FF53, 0xFD4BFD49,
    0xFE0DFE8D, 0xFD8BFD0B, 0xFD49FD4B, 0xFECFFECF, 0xFD4BFCCB, 0xDAC70801, 0x1041FC8B, 0xFC49FC09, 0xFD4DFC0B,
    0xFBC9FCCB, 0xFD0BFB87, 0xFD4BFE4F, 0xFE0DFE0D, 0xFC4BFD8B, 0xFF91FE0D, 0xFC89FD4B, 0xFE8DFE0D, 0xFCC9FC4B,
    0xFC49FCC9, 0xFE8FFD4D, 0xFCC9FC89, 0xC2072081, 0x1841EB49, 0xFD0BFC09, 0xFCCDFC09, 0xFB49FBC9, 0xFC09F307,
    0xFBC9FD0B, 0xFC09FB89, 0xFB89FD4D, 0xFDCDFBC9, 0xFB89F389, 0xFD0DFCCB, 0xFB47FB4B, 0xFB89FC49, 0xFD8FFC8B,
    0xFC8BF347, 0xA1C51841, 0x0001CA87, 0xFC8BFB89, 0xFB89FB89, 0xEB09F347, 0xFBC9E2C9, 0xDAC7FB49, 0xAA05E2C7,
    0xD245EB8B, 0xEB89D247, 0xA1C7AA05, 0xFB8BFB89, 0xC247DA87, 0xF30BFC0B, 0xFBCBF349, 0xF349CA87, 0xA1C30001,
    0x000199C5, 0xEB09FB07, 0xDAC7F309, 0xDA87B207, 0x99C59185, 0x8145A1C5, 0x40839185, 0x9183D287, 0xCA479185,
    0x71059185, 0xA1C5C247, 0xA1C5A9C7, 0xDAC9F2C9, 0xB207AA07, 0xCA47A9C5, 0x91850001, 0x00016945, 0xCA47E2C7,
    0xC247D247, 0xB24768C3, 0x28412841, 0x508360C3, 0x58C37945, 0x8985A9C5, 0x71032841, 0x50C37905, 0x89837105,
    0x60C36903, 0xA9C799C7, 0x69038145, 0x91859185, 0x81830001, 0x00013083, 0x99C5DA89, 0xCA479985, 0xCA896903,
    0x28013843, 0x50C15083, 0x40836103, 0x68C36103, 0x50C32001, 0x404358C3, 0x58C34081, 0x488358C3, 0x79454041,
    0x488348C3, 0x5081A1C5, 0x48C30001, 0x00010801, 0x71458985, 0xC2078985, 0xA18791C5, 0x48832801, 0x38814883,
    0x30414043, 0x408150C3, 0x28012841, 0x20014083, 0x30413001, 0x40837943, 0x48833041, 0x60C33843, 0x7103C247,
    0x08010001, 0x00010001, 0x308358C3, 0x81458985, 0x60C37103, 0x59033001, 0x28413043, 0x20012001, 0x38413883,
    0x28413001, 0x18012841, 0x20012001, 0x58C358C3, 0x488358C3, 0x690360C3, 0x99C56905, 0x00010001, 0x00010001,
    0x100148C3, 0x58C36905, 0x48813043, 0x28412801, 0x28012041, 0x18011801, 0x30413043, 0x20012841, 0x20012001,
    0x18012841, 0x40433881, 0x384158C3, 0x50C34083, 0x48810801, 0x00010001, 0x00010001, 0x00012041, 0x48834083,
    0x40832801, 0x18012001, 0x18012001, 0x18011801, 0x20012041, 0x20011801, 0x18012001, 0x18012841, 0x38412001,
    0x20014083, 0x28012841, 0x18010001, 0x00010001, 0x00010001, 0x00010001, 0x20412001, 0x30433001, 0x18011801,
    0x18012001, 0x18011001, 0x18011801, 0x18011801, 0x18011801, 0x18012001, 0x28412001, 0x18013841, 0x20011801,
    0x08010001, 0x00010001, 0x00010001, 0x00010001, 0x00011801, 0x20012001, 0x18011801, 0x20011801, 0x18011801,
    0x10011801, 0x18011001, 0x18011801, 0x18011801, 0x18012801, 0x28412841, 0x18010801, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010801, 0x10012001, 0x18011801, 0x18011001, 0x18011801, 0x10011801, 0x18011801,
    0x10011801, 0x18011801, 0x18012001, 0x18011801, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00011001, 0x18011801, 0x18011001, 0x18011801, 0x10011001, 0x10011801, 0x10011801, 0x18011001,
    0x18011801, 0x08010801, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00011001, 0x10011801, 0x10011801, 0x10011001, 0x10011001, 0x10011801, 0x10011801, 0x10010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010801,
    0x08011001, 0x10011001, 0x10011001, 0x10010801, 0x08010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
};
static Gfx D_84B12420[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetCombineMode(G_CC_MODULATEI, G_CC_PASS2),
    gsSPSetGeometryMode(G_LIGHTING | G_TEXTURE_GEN),
    gsSPClearGeometryMode(G_TEXTURE_GEN_LINEAR),
    gsSPTexture(0x1194, 0x1194, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(D_84B11C20, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, 1, 1),
    gsSPEndDisplayList(),
};

s32 func_84B06B50(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25A28* temp_a3;
    u8* sp30;
    s32 temp_v1;
    s32 var_a1;

    if (arg0 == 5) {
        temp_a3 = (unk_D_84B25A28*)D_8006F09C->unk_000.unk_14;

        temp_v1 = D_8006F09C->unk_0A6 - temp_a3->unk_04->unk_0A6;
        if (temp_v1 < 5) {
            var_a1 = ((arg1->unk_00.unk_14 * 3) + temp_v1) - 2;
            sp30 = D_300C000;
        } else {
            var_a1 = (arg1->unk_00.unk_14 * 3) + temp_v1 + 1;
            sp30 = D_300D800;
        }

        gDPPipeSync(gDisplayListHead++);

        gSPSegment(gDisplayListHead++, 0x0F, (u32)func_8001AFD8(temp_a3->unk_20, var_a1) & 0x1FFFFFFF);
        gSPSegment(gDisplayListHead++, 0x0E, (u32)Memmap_GetSegmentVaddr(sp30) & 0x1FFFFFFF);
    }
    return 0;
}

s32 func_84B06C7C(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25A28* temp_a3;
    u8* sp30;
    s32 temp_v1;
    s32 var_a1;

    if (arg0 == 5) {
        temp_a3 = (unk_D_84B25A28*)D_8006F09C->unk_000.unk_14;

        temp_v1 = D_8006F09C->unk_0A6 - temp_a3->unk_04->unk_0A6;
        if (temp_v1 < 5) {
            var_a1 = (arg1->unk_00.unk_14 * 2) + (((temp_v1 - 1) / 2) * 6) + ((temp_v1 - 1) % 2);
            sp30 = D_300F000;
        } else {
            var_a1 = (arg1->unk_00.unk_14 * 2) + (((temp_v1 - 5) / 2) * 6) + ((temp_v1 - 5) % 2) + 0xC;
            sp30 = D_300FC00;
        }

        gDPPipeSync(gDisplayListHead++);

        gSPSegment(gDisplayListHead++, 0x0F, (u32)func_8001AFD8(temp_a3->unk_20, var_a1) & 0x1FFFFFFF);
        gSPSegment(gDisplayListHead++, 0x0E, (u32)Memmap_GetSegmentVaddr(sp30) & 0x1FFFFFFF);
    }
    return 0;
}

s32 func_84B06E08(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25A28* temp_v1;
    u8* var_a3;

    if (arg0 == 5) {
        temp_v1 = (unk_D_84B25A28*)D_8006F09C->unk_000.unk_14;
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

s32 func_84B06ED0(s32 arg0, unk_func_80011B94* arg1) {
    static s32 D_84B12490 = 0x80;

    s32 var_v0;

    if (arg0 == 5) {
        D_84B12490--;
        if (D_84B12490 < 0) {
            D_84B12490 = 0x80;
        }

        gSPDisplayList(gDisplayListHead++, D_84B12420);
        gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, D_84B12490, 0, (D_84B12490 + 0x1F) << 2, 0x007C);
    }
}

static Vtx D_84B12498[] = {
    VTX(-1, -38, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF), VTX(-31, 28, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(-21, 35, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF), VTX(0, -11, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(23, 36, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),  VTX(34, 31, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(0, -38, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),  VTX(-4, -43, -19, 0, 0, 0xF9, 0xAC, 0xAC, 0xFF),
    VTX(-1, -38, -25, 0, 0, 0xF9, 0xAC, 0xAC, 0xFF), VTX(0, -38, -25, 0, 0, 0xF9, 0xAC, 0xAC, 0xFF),
    VTX(3, -43, -19, 0, 0, 0xF9, 0xAC, 0xAC, 0xFF),  VTX(3, -43, -19, 0, 0, 0x4C, 0xDB, 0xAC, 0xFF),
    VTX(0, -38, -25, 0, 0, 0x4C, 0xDB, 0xAC, 0xFF),  VTX(34, 31, -25, 0, 0, 0x4C, 0xDB, 0xAC, 0xFF),
    VTX(41, 33, -19, 0, 0, 0x4C, 0xDB, 0xAC, 0xFF),  VTX(41, 33, -19, 0, 0, 0x24, 0x4C, 0xAC, 0xFF),
    VTX(34, 31, -25, 0, 0, 0x24, 0x4C, 0xAC, 0xFF),  VTX(23, 36, -25, 0, 0, 0x24, 0x4C, 0xAC, 0xFF),
    VTX(20, 43, -19, 0, 0, 0x24, 0x4C, 0xAC, 0xFF),  VTX(20, 43, -19, 0, 0, 0xB4, 0x25, 0xAC, 0xFF),
    VTX(23, 36, -25, 0, 0, 0xB4, 0x25, 0xAC, 0xFF),  VTX(0, -11, -25, 0, 0, 0xB4, 0x25, 0xAC, 0xFF),
    VTX(0, 0, -19, 0, 0, 0xB4, 0x25, 0xAC, 0xFF),    VTX(0, 0, -19, 0, 0, 0x4D, 0x22, 0xAC, 0xFF),
    VTX(0, -11, -25, 0, 0, 0x4D, 0x22, 0xAC, 0xFF),  VTX(-21, 35, -25, 0, 0, 0x4D, 0x22, 0xAC, 0xFF),
    VTX(-19, 42, -19, 0, 0, 0x4D, 0x22, 0xAC, 0xFF), VTX(-19, 42, -19, 0, 0, 0xD1, 0x46, 0xAC, 0xFF),
    VTX(-21, 35, -25, 0, 0, 0xD1, 0x46, 0xAC, 0xFF), VTX(-31, 28, -25, 0, 0, 0xD1, 0x46, 0xAC, 0xFF),
    VTX(-37, 29, -19, 0, 0, 0xD1, 0x46, 0xAC, 0xFF),
};
static Vtx D_84B12688[] = {
    VTX(-37, 29, -19, 0, 0, 0xB3, 0xDD, 0xAC, 0xFF), VTX(-31, 28, -25, 0, 0, 0xB3, 0xDD, 0xAC, 0xFF),
    VTX(-1, -38, -25, 0, 0, 0xB3, 0xDD, 0xAC, 0xFF), VTX(-4, -43, -19, 0, 0, 0xB3, 0xDD, 0xAC, 0xFF),
    VTX(-4, -43, 19, 0, 0, 0xF7, 0x89, 0x00, 0xFF),  VTX(-4, -43, -19, 0, 0, 0xF7, 0x89, 0x00, 0xFF),
    VTX(3, -43, -19, 0, 0, 0xF7, 0x89, 0x00, 0xFF),  VTX(3, -43, 19, 0, 0, 0xF7, 0x89, 0x00, 0xFF),
    VTX(3, -43, 19, 0, 0, 0x6B, 0xCC, 0x00, 0xFF),   VTX(3, -43, -19, 0, 0, 0x6B, 0xCC, 0x00, 0xFF),
    VTX(41, 33, -19, 0, 0, 0x6B, 0xCC, 0x00, 0xFF),  VTX(41, 33, 19, 0, 0, 0x6B, 0xCC, 0x00, 0xFF),
    VTX(41, 33, 19, 0, 0, 0x33, 0x6C, 0x00, 0xFF),   VTX(41, 33, -19, 0, 0, 0x33, 0x6C, 0x00, 0xFF),
    VTX(20, 43, -19, 0, 0, 0x33, 0x6C, 0x00, 0xFF),  VTX(20, 43, 19, 0, 0, 0x33, 0x6C, 0x00, 0xFF),
    VTX(20, 43, 19, 0, 0, 0x95, 0x34, 0x00, 0xFF),   VTX(20, 43, -19, 0, 0, 0x95, 0x34, 0x00, 0xFF),
    VTX(0, 0, -19, 0, 0, 0x95, 0x34, 0x00, 0xFF),    VTX(0, 0, 19, 0, 0, 0x95, 0x34, 0x00, 0xFF),
    VTX(0, 0, 19, 0, 0, 0x6D, 0x31, 0x00, 0xFF),     VTX(0, 0, -19, 0, 0, 0x6D, 0x31, 0x00, 0xFF),
    VTX(-19, 42, -19, 0, 0, 0x6D, 0x31, 0x00, 0xFF), VTX(-19, 42, 19, 0, 0, 0x6D, 0x31, 0x00, 0xFF),
    VTX(-19, 42, 19, 0, 0, 0xBD, 0x63, 0x00, 0xFF),  VTX(-19, 42, -19, 0, 0, 0xBD, 0x63, 0x00, 0xFF),
    VTX(-37, 29, -19, 0, 0, 0xBD, 0x63, 0x00, 0xFF), VTX(-37, 29, 19, 0, 0, 0xBD, 0x63, 0x00, 0xFF),
    VTX(-37, 29, 19, 0, 0, 0x93, 0xCF, 0x00, 0xFF),  VTX(-37, 29, -19, 0, 0, 0x93, 0xCF, 0x00, 0xFF),
    VTX(-4, -43, -19, 0, 0, 0x93, 0xCF, 0x00, 0xFF), VTX(-4, -43, 19, 0, 0, 0x93, 0xCF, 0x00, 0xFF),
};
static Vtx D_84B12888[] = {
    VTX(-1, -38, 25, 0, 0, 0xF9, 0xAC, 0x54, 0xFF), VTX(-4, -43, 19, 0, 0, 0xF9, 0xAC, 0x54, 0xFF),
    VTX(3, -43, 19, 0, 0, 0xF9, 0xAC, 0x54, 0xFF),  VTX(0, -38, 25, 0, 0, 0xF9, 0xAC, 0x54, 0xFF),
    VTX(0, -38, 25, 0, 0, 0x4C, 0xDB, 0x54, 0xFF),  VTX(3, -43, 19, 0, 0, 0x4C, 0xDB, 0x54, 0xFF),
    VTX(41, 33, 19, 0, 0, 0x4C, 0xDB, 0x54, 0xFF),  VTX(34, 31, 25, 0, 0, 0x4C, 0xDB, 0x54, 0xFF),
    VTX(34, 31, 25, 0, 0, 0x24, 0x4C, 0x54, 0xFF),  VTX(41, 33, 19, 0, 0, 0x24, 0x4C, 0x54, 0xFF),
    VTX(20, 43, 19, 0, 0, 0x24, 0x4C, 0x54, 0xFF),  VTX(23, 36, 25, 0, 0, 0x24, 0x4C, 0x54, 0xFF),
    VTX(23, 36, 25, 0, 0, 0xB4, 0x25, 0x54, 0xFF),  VTX(20, 43, 19, 0, 0, 0xB4, 0x25, 0x54, 0xFF),
    VTX(0, 0, 19, 0, 0, 0xB4, 0x25, 0x54, 0xFF),    VTX(0, -11, 25, 0, 0, 0xB4, 0x25, 0x54, 0xFF),
    VTX(0, -11, 25, 0, 0, 0x4D, 0x22, 0x54, 0xFF),  VTX(0, 0, 19, 0, 0, 0x4D, 0x22, 0x54, 0xFF),
    VTX(-19, 42, 19, 0, 0, 0x4D, 0x22, 0x54, 0xFF), VTX(-21, 35, 25, 0, 0, 0x4D, 0x22, 0x54, 0xFF),
    VTX(-21, 35, 25, 0, 0, 0xD1, 0x46, 0x54, 0xFF), VTX(-19, 42, 19, 0, 0, 0xD1, 0x46, 0x54, 0xFF),
    VTX(-37, 29, 19, 0, 0, 0xD1, 0x46, 0x54, 0xFF), VTX(-31, 28, 25, 0, 0, 0xD1, 0x46, 0x54, 0xFF),
    VTX(-31, 28, 25, 0, 0, 0xB3, 0xDD, 0x54, 0xFF), VTX(-37, 29, 19, 0, 0, 0xB3, 0xDD, 0x54, 0xFF),
    VTX(-4, -43, 19, 0, 0, 0xB3, 0xDD, 0x54, 0xFF), VTX(-1, -38, 25, 0, 0, 0xB3, 0xDD, 0x54, 0xFF),
    VTX(0, -38, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),  VTX(34, 31, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(23, 36, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),  VTX(0, -11, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
};
static Vtx D_84B12A88[] = {
    VTX(0, -38, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),  VTX(0, -11, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(-21, 35, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF), VTX(-31, 28, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(-1, -38, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
};
static Vtx D_84B12AD8[] = {
    VTX(0, 33, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),   VTX(8, 36, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(12, 30, -25, 0, 0, 0x0D, 0xD5, 0x92, 0xFF),  VTX(12, 30, -25, 0, 0, 0x13, 0xC7, 0x99, 0xFF),
    VTX(8, 28, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),   VTX(23, -12, -19, 0, 0, 0x51, 0x02, 0xA8, 0xFF),
    VTX(17, -12, -25, 0, 0, 0x51, 0x02, 0xA8, 0xFF), VTX(15, -6, -25, 0, 0, 0x45, 0x2F, 0xAB, 0xFF),
    VTX(19, -3, -19, 0, 0, 0x45, 0x2F, 0xAB, 0xFF),  VTX(7, 0, -25, 0, 0, 0x39, 0x3D, 0xAC, 0xFF),
    VTX(11, 4, -19, 0, 0, 0x39, 0x3D, 0xAC, 0xFF),   VTX(0, 8, -25, 0, 0, 0x3F, 0x37, 0xAB, 0xFF),
    VTX(2, 11, -19, 0, 0, 0x3F, 0x37, 0xAB, 0xFF),   VTX(-6, 17, -25, 0, 0, 0x49, 0xFA, 0xA2, 0xFF),
    VTX(0, 16, -19, 0, 0, 0x49, 0xFA, 0xA2, 0xFF),   VTX(0, 24, -25, 0, 0, 0x31, 0xBD, 0xAB, 0xFF),
    VTX(3, 20, -19, 0, 0, 0x31, 0xBD, 0xAB, 0xFF),   VTX(8, 28, -25, 0, 0, 0x20, 0xB3, 0xAB, 0xFF),
    VTX(10, 24, -19, 0, 0, 0x20, 0xB3, 0xAB, 0xFF),  VTX(17, 26, -19, 0, 0, 0x1A, 0xB0, 0xAB, 0xFF),
    VTX(20, 27, -19, 0, 0, 0x18, 0xB0, 0xAC, 0xFF),  VTX(20, 27, -19, 0, 0, 0x46, 0x2F, 0xAC, 0xFF),
    VTX(12, 30, -25, 0, 0, 0x46, 0x2F, 0xAC, 0xFF),  VTX(8, 36, -25, 0, 0, 0x15, 0x46, 0xA2, 0xFF),
    VTX(10, 42, -19, 0, 0, 0x15, 0x46, 0xA2, 0xFF),  VTX(0, 33, -25, 0, 0, 0xD9, 0x4A, 0xAB, 0xFF),
    VTX(-1, 37, -19, 0, 0, 0xD9, 0x4A, 0xAB, 0xFF),  VTX(-9, 26, -25, 0, 0, 0xCA, 0x40, 0xAB, 0xFF),
    VTX(-12, 30, -19, 0, 0, 0xCA, 0x40, 0xAB, 0xFF), VTX(-16, 19, -25, 0, 0, 0xBA, 0x2D, 0xAB, 0xFF),
    VTX(-20, 21, -19, 0, 0, 0xBA, 0x2D, 0xAB, 0xFF), VTX(-18, 14, -25, 0, 0, 0xB2, 0x1F, 0xAC, 0xFF),
};
static Vtx D_84B12CD8[] = {
    VTX(-20, 21, -19, 0, 0, 0xBA, 0x2D, 0xAB, 0xFF),  VTX(-18, 14, -25, 0, 0, 0xB2, 0x1F, 0xAC, 0xFF),
    VTX(-23, 14, -19, 0, 0, 0xB2, 0x1F, 0xAC, 0xFF),  VTX(-23, 14, -19, 0, 0, 0xB1, 0xE4, 0xAC, 0xFF),
    VTX(-18, 14, -25, 0, 0, 0xB1, 0xE4, 0xAC, 0xFF),  VTX(-16, 8, -25, 0, 0, 0xB8, 0xD6, 0xAB, 0xFF),
    VTX(-20, 5, -19, 0, 0, 0xB8, 0xD6, 0xAB, 0xFF),   VTX(-10, 1, -25, 0, 0, 0xC4, 0xC5, 0xAC, 0xFF),
    VTX(-13, -1, -19, 0, 0, 0xC4, 0xC5, 0xAC, 0xFF),  VTX(-2, -5, -25, 0, 0, 0xBF, 0xCB, 0xAB, 0xFF),
    VTX(-6, -8, -19, 0, 0, 0xBF, 0xCB, 0xAB, 0xFF),   VTX(1, -12, -25, 0, 0, 0xB2, 0xFE, 0xA6, 0xFF),
    VTX(-3, -13, -19, 0, 0, 0xB2, 0xFE, 0xA6, 0xFF),  VTX(-2, -21, -25, 0, 0, 0xBE, 0x33, 0xAB, 0xFF),
    VTX(-6, -18, -19, 0, 0, 0xBE, 0x33, 0xAB, 0xFF),  VTX(-8, -26, -25, 0, 0, 0xCD, 0x43, 0xAC, 0xFF),
    VTX(-11, -22, -19, 0, 0, 0xCD, 0x43, 0xAC, 0xFF), VTX(-14, -30, -25, 0, 0, 0xDF, 0x32, 0x99, 0xFF),
    VTX(-16, -26, -19, 0, 0, 0xD2, 0x46, 0xAB, 0xFF), VTX(-13, -30, -25, 0, 0, 0xE8, 0x25, 0x91, 0xFF),
    VTX(-19, -27, -19, 0, 0, 0xD3, 0x45, 0xAA, 0xFF), VTX(-19, -27, -19, 0, 0, 0xAE, 0xDE, 0xB1, 0xFF),
    VTX(-13, -30, -25, 0, 0, 0xAE, 0xDE, 0xB1, 0xFF), VTX(-9, -38, -25, 0, 0, 0xAE, 0xDE, 0xB1, 0xFF),
    VTX(-12, -45, -19, 0, 0, 0xAE, 0xDE, 0xB1, 0xFF), VTX(-12, -45, -19, 0, 0, 0x25, 0xB4, 0xAC, 0xFF),
    VTX(-9, -38, -25, 0, 0, 0x25, 0xB4, 0xAC, 0xFF),  VTX(-2, -34, -25, 0, 0, 0x2C, 0xB9, 0xAB, 0xFF),
    VTX(0, -38, -19, 0, 0, 0x2C, 0xB9, 0xAB, 0xFF),   VTX(7, -26, -25, 0, 0, 0x39, 0xC3, 0xAB, 0xFF),
    VTX(11, -30, -19, 0, 0, 0x39, 0xC3, 0xAB, 0xFF),  VTX(15, -17, -25, 0, 0, 0x47, 0xD5, 0xAB, 0xFF),
};
static Vtx D_84B12ED8[] = {
    VTX(11, -30, -19, 0, 0, 0x39, 0xC3, 0xAB, 0xFF), VTX(15, -17, -25, 0, 0, 0x47, 0xD5, 0xAB, 0xFF),
    VTX(19, -20, -19, 0, 0, 0x47, 0xD5, 0xAB, 0xFF), VTX(17, -12, -25, 0, 0, 0x51, 0x02, 0xA8, 0xFF),
    VTX(23, -12, -19, 0, 0, 0x51, 0x02, 0xA8, 0xFF), VTX(23, -12, 19, 0, 0, 0x77, 0x03, 0x00, 0xFF),
    VTX(23, -12, -19, 0, 0, 0x77, 0x03, 0x00, 0xFF), VTX(19, -3, -19, 0, 0, 0x62, 0x44, 0x00, 0xFF),
    VTX(19, -3, 19, 0, 0, 0x62, 0x44, 0x00, 0xFF),   VTX(11, 4, -19, 0, 0, 0x51, 0x57, 0x00, 0xFF),
    VTX(11, 4, 19, 0, 0, 0x51, 0x57, 0x00, 0xFF),    VTX(2, 11, -19, 0, 0, 0x5A, 0x4F, 0x00, 0xFF),
    VTX(2, 11, 19, 0, 0, 0x5A, 0x4F, 0x00, 0xFF),    VTX(0, 16, -19, 0, 0, 0x63, 0x42, 0x00, 0xFF),
    VTX(0, 16, 19, 0, 0, 0x63, 0x42, 0x00, 0xFF),    VTX(0, 16, 19, 0, 0, 0x57, 0xAE, 0x00, 0xFF),
    VTX(0, 16, -19, 0, 0, 0x57, 0xAE, 0x00, 0xFF),   VTX(3, 20, -19, 0, 0, 0x46, 0xA0, 0x00, 0xFF),
    VTX(3, 20, 19, 0, 0, 0x46, 0xA0, 0x00, 0xFF),    VTX(10, 24, -19, 0, 0, 0x2D, 0x92, 0x00, 0xFF),
    VTX(10, 24, 19, 0, 0, 0x2D, 0x92, 0x00, 0xFF),   VTX(17, 26, -19, 0, 0, 0x25, 0x8E, 0x00, 0xFF),
    VTX(17, 26, 19, 0, 0, 0x25, 0x8E, 0x00, 0xFF),   VTX(20, 27, -19, 0, 0, 0x22, 0x8E, 0x00, 0xFF),
    VTX(20, 27, 19, 0, 0, 0x22, 0x8E, 0x00, 0xFF),   VTX(20, 27, 19, 0, 0, 0x63, 0x42, 0x00, 0xFF),
    VTX(20, 27, -19, 0, 0, 0x63, 0x42, 0x00, 0xFF),  VTX(10, 42, -19, 0, 0, 0x63, 0x42, 0x00, 0xFF),
    VTX(10, 42, 19, 0, 0, 0x63, 0x42, 0x00, 0xFF),   VTX(10, 42, 19, 0, 0, 0xD4, 0x6F, 0x00, 0xFF),
    VTX(10, 42, -19, 0, 0, 0xD4, 0x6F, 0x00, 0xFF),  VTX(-1, 37, -19, 0, 0, 0xC8, 0x6A, 0x00, 0xFF),
};
static Vtx D_84B130D8[] = {
    VTX(10, 42, 19, 0, 0, 0xD4, 0x6F, 0x00, 0xFF),    VTX(-1, 37, -19, 0, 0, 0xC8, 0x6A, 0x00, 0xFF),
    VTX(-1, 37, 19, 0, 0, 0xC8, 0x6A, 0x00, 0xFF),    VTX(-12, 30, -19, 0, 0, 0xB3, 0x5B, 0x00, 0xFF),
    VTX(-12, 30, 19, 0, 0, 0xB3, 0x5B, 0x00, 0xFF),   VTX(-20, 21, -19, 0, 0, 0x9C, 0x40, 0x00, 0xFF),
    VTX(-20, 21, 19, 0, 0, 0x9C, 0x40, 0x00, 0xFF),   VTX(-23, 14, -19, 0, 0, 0x89, 0x02, 0x00, 0xFF),
    VTX(-23, 14, 19, 0, 0, 0x89, 0x02, 0x00, 0xFF),   VTX(-20, 5, -19, 0, 0, 0x99, 0xC3, 0x00, 0xFF),
    VTX(-20, 5, 19, 0, 0, 0x99, 0xC3, 0x00, 0xFF),    VTX(-13, -1, -19, 0, 0, 0xAB, 0xAD, 0x00, 0xFF),
    VTX(-13, -1, 19, 0, 0, 0xAB, 0xAD, 0x00, 0xFF),   VTX(-6, -8, -19, 0, 0, 0xA3, 0xB5, 0x00, 0xFF),
    VTX(-6, -8, 19, 0, 0, 0xA3, 0xB5, 0x00, 0xFF),    VTX(-3, -13, -19, 0, 0, 0x89, 0xFC, 0x00, 0xFF),
    VTX(-3, -13, 19, 0, 0, 0x89, 0xFC, 0x00, 0xFF),   VTX(-6, -18, -19, 0, 0, 0xA2, 0x49, 0x00, 0xFF),
    VTX(-6, -18, 19, 0, 0, 0xA2, 0x49, 0x00, 0xFF),   VTX(-11, -22, -19, 0, 0, 0xB8, 0x5F, 0x00, 0xFF),
    VTX(-11, -22, 19, 0, 0, 0xB8, 0x5F, 0x00, 0xFF),  VTX(-16, -26, -19, 0, 0, 0xC1, 0x66, 0x00, 0xFF),
    VTX(-16, -26, 19, 0, 0, 0xC1, 0x66, 0x00, 0xFF),  VTX(-19, -27, -19, 0, 0, 0xC5, 0x68, 0x00, 0xFF),
    VTX(-19, -27, 19, 0, 0, 0xC5, 0x68, 0x00, 0xFF),  VTX(-19, -27, 19, 0, 0, 0x90, 0xD6, 0x00, 0xFF),
    VTX(-19, -27, -19, 0, 0, 0x90, 0xD6, 0x00, 0xFF), VTX(-12, -45, -19, 0, 0, 0x90, 0xD6, 0x00, 0xFF),
    VTX(-12, -45, 19, 0, 0, 0x90, 0xD6, 0x00, 0xFF),  VTX(-12, -45, 19, 0, 0, 0x35, 0x95, 0x00, 0xFF),
    VTX(-12, -45, -19, 0, 0, 0x35, 0x95, 0x00, 0xFF), VTX(0, -38, -19, 0, 0, 0x3F, 0x9B, 0x00, 0xFF),
};
static Vtx D_84B132D8[] = {
    VTX(-12, -45, 19, 0, 0, 0x35, 0x95, 0x00, 0xFF), VTX(0, -38, -19, 0, 0, 0x3F, 0x9B, 0x00, 0xFF),
    VTX(0, -38, 19, 0, 0, 0x3F, 0x9B, 0x00, 0xFF),   VTX(11, -30, -19, 0, 0, 0x51, 0xA9, 0x00, 0xFF),
    VTX(11, -30, 19, 0, 0, 0x51, 0xA9, 0x00, 0xFF),  VTX(19, -20, -19, 0, 0, 0x66, 0xC2, 0x00, 0xFF),
    VTX(19, -20, 19, 0, 0, 0x66, 0xC2, 0x00, 0xFF),  VTX(23, -12, -19, 0, 0, 0x77, 0x03, 0x00, 0xFF),
    VTX(23, -12, 19, 0, 0, 0x77, 0x03, 0x00, 0xFF),  VTX(17, -12, 25, 0, 0, 0x51, 0x02, 0x58, 0xFF),
    VTX(23, -12, 19, 0, 0, 0x51, 0x02, 0x58, 0xFF),  VTX(19, -3, 19, 0, 0, 0x45, 0x2F, 0x55, 0xFF),
    VTX(15, -6, 25, 0, 0, 0x45, 0x2F, 0x55, 0xFF),   VTX(11, 4, 19, 0, 0, 0x39, 0x3D, 0x54, 0xFF),
    VTX(7, 0, 25, 0, 0, 0x39, 0x3D, 0x54, 0xFF),     VTX(2, 11, 19, 0, 0, 0x3F, 0x37, 0x55, 0xFF),
    VTX(0, 8, 25, 0, 0, 0x3F, 0x37, 0x55, 0xFF),     VTX(0, 16, 19, 0, 0, 0x49, 0xFA, 0x5E, 0xFF),
    VTX(-6, 17, 25, 0, 0, 0x49, 0xFA, 0x5E, 0xFF),   VTX(3, 20, 19, 0, 0, 0x31, 0xBD, 0x55, 0xFF),
    VTX(0, 24, 25, 0, 0, 0x31, 0xBD, 0x55, 0xFF),    VTX(10, 24, 19, 0, 0, 0x20, 0xB3, 0x55, 0xFF),
    VTX(8, 28, 25, 0, 0, 0x20, 0xB3, 0x55, 0xFF),    VTX(17, 26, 19, 0, 0, 0x1A, 0xB0, 0x55, 0xFF),
    VTX(12, 30, 25, 0, 0, 0x13, 0xC7, 0x67, 0xFF),   VTX(20, 27, 19, 0, 0, 0x18, 0xB0, 0x54, 0xFF),
    VTX(12, 30, 25, 0, 0, 0x0D, 0xD5, 0x6E, 0xFF),   VTX(12, 30, 25, 0, 0, 0x46, 0x2F, 0x54, 0xFF),
    VTX(20, 27, 19, 0, 0, 0x46, 0x2F, 0x54, 0xFF),   VTX(10, 42, 19, 0, 0, 0x15, 0x46, 0x5E, 0xFF),
    VTX(8, 36, 25, 0, 0, 0x15, 0x46, 0x5E, 0xFF),    VTX(-1, 37, 19, 0, 0, 0xD9, 0x4A, 0x55, 0xFF),
};
static Vtx D_84B134D8[] = {
    VTX(8, 36, 25, 0, 0, 0x15, 0x46, 0x5E, 0xFF),    VTX(-1, 37, 19, 0, 0, 0xD9, 0x4A, 0x55, 0xFF),
    VTX(0, 33, 25, 0, 0, 0xD9, 0x4A, 0x55, 0xFF),    VTX(-12, 30, 19, 0, 0, 0xCA, 0x40, 0x55, 0xFF),
    VTX(-9, 26, 25, 0, 0, 0xCA, 0x40, 0x55, 0xFF),   VTX(-20, 21, 19, 0, 0, 0xBA, 0x2D, 0x55, 0xFF),
    VTX(-16, 19, 25, 0, 0, 0xBA, 0x2D, 0x55, 0xFF),  VTX(-23, 14, 19, 0, 0, 0xAF, 0x01, 0x57, 0xFF),
    VTX(-18, 14, 25, 0, 0, 0xAF, 0x01, 0x57, 0xFF),  VTX(-20, 5, 19, 0, 0, 0xB8, 0xD6, 0x55, 0xFF),
    VTX(-16, 8, 25, 0, 0, 0xB8, 0xD6, 0x55, 0xFF),   VTX(-13, -1, 19, 0, 0, 0xC4, 0xC5, 0x54, 0xFF),
    VTX(-10, 1, 25, 0, 0, 0xC4, 0xC5, 0x54, 0xFF),   VTX(-6, -8, 19, 0, 0, 0xBF, 0xCB, 0x55, 0xFF),
    VTX(-2, -5, 25, 0, 0, 0xBF, 0xCB, 0x55, 0xFF),   VTX(-3, -13, 19, 0, 0, 0xB2, 0xFE, 0x5A, 0xFF),
    VTX(1, -12, 25, 0, 0, 0xB2, 0xFE, 0x5A, 0xFF),   VTX(-6, -18, 19, 0, 0, 0xBE, 0x33, 0x55, 0xFF),
    VTX(-2, -21, 25, 0, 0, 0xBE, 0x33, 0x55, 0xFF),  VTX(-11, -22, 19, 0, 0, 0xCD, 0x43, 0x54, 0xFF),
    VTX(-8, -26, 25, 0, 0, 0xCD, 0x43, 0x54, 0xFF),  VTX(-16, -26, 19, 0, 0, 0xD2, 0x46, 0x55, 0xFF),
    VTX(-14, -30, 25, 0, 0, 0xDF, 0x32, 0x67, 0xFF), VTX(-19, -27, 19, 0, 0, 0xB8, 0x13, 0x5D, 0xFF),
    VTX(-13, -30, 25, 0, 0, 0xD0, 0x0D, 0x6C, 0xFF), VTX(-12, -45, 19, 0, 0, 0xAE, 0xDE, 0x4F, 0xFF),
    VTX(-9, -38, 25, 0, 0, 0xAE, 0xDE, 0x4F, 0xFF),  VTX(-9, -38, 25, 0, 0, 0x25, 0xB4, 0x54, 0xFF),
    VTX(-12, -45, 19, 0, 0, 0x25, 0xB4, 0x54, 0xFF), VTX(0, -38, 19, 0, 0, 0x2C, 0xB9, 0x55, 0xFF),
    VTX(-2, -34, 25, 0, 0, 0x2C, 0xB9, 0x55, 0xFF),  VTX(11, -30, 19, 0, 0, 0x39, 0xC3, 0x55, 0xFF),
};
static Vtx D_84B136D8[] = {
    VTX(-2, -34, 25, 0, 0, 0x2C, 0xB9, 0x55, 0xFF),   VTX(11, -30, 19, 0, 0, 0x39, 0xC3, 0x55, 0xFF),
    VTX(7, -26, 25, 0, 0, 0x39, 0xC3, 0x55, 0xFF),    VTX(19, -20, 19, 0, 0, 0x47, 0xD5, 0x55, 0xFF),
    VTX(15, -17, 25, 0, 0, 0x47, 0xD5, 0x55, 0xFF),   VTX(23, -12, 19, 0, 0, 0x51, 0x02, 0x58, 0xFF),
    VTX(17, -12, 25, 0, 0, 0x51, 0x02, 0x58, 0xFF),   VTX(8, 28, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(12, 30, 25, 0, 0, 0x13, 0xC7, 0x67, 0xFF),    VTX(12, 30, 25, 0, 0, 0x0D, 0xD5, 0x6E, 0xFF),
    VTX(8, 36, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),     VTX(0, 33, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(-2, -34, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),  VTX(-9, -38, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(-13, -30, -25, 0, 0, 0xE8, 0x25, 0x91, 0xFF), VTX(-14, -30, -25, 0, 0, 0xDF, 0x32, 0x99, 0xFF),
    VTX(-8, -26, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),  VTX(-9, 26, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(0, 33, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),    VTX(8, 28, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(0, 24, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),    VTX(-16, 19, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(-6, 17, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),   VTX(-18, 14, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(-16, 8, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),   VTX(-10, 1, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(0, 8, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),     VTX(7, 0, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(1, -12, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),   VTX(15, -6, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(17, -12, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),  VTX(15, -17, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
};
static Vtx D_84B138D8[] = {
    VTX(-2, -21, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF), VTX(1, -12, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(15, -17, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF), VTX(7, -26, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(-8, -26, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF), VTX(-2, -34, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(-8, -26, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),  VTX(-14, -30, 25, 0, 0, 0xDF, 0x32, 0x67, 0xFF),
    VTX(-13, -30, 25, 0, 0, 0xD0, 0x0D, 0x6C, 0xFF), VTX(-9, -38, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(-2, -34, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),  VTX(0, 24, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(8, 28, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),    VTX(0, 33, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(-9, 26, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),   VTX(-6, 17, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(-16, 19, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),  VTX(-18, 14, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(-16, 8, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),   VTX(0, 8, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(7, 0, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),     VTX(-10, 1, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(7, 0, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),    VTX(15, -6, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(-2, -5, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),  VTX(15, -6, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(-2, -5, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),   VTX(1, -12, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(17, -12, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),  VTX(15, -17, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(7, -26, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),   VTX(-2, -21, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
};
static Vtx D_84B13AD8[] = {
    VTX(7, 0, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),   VTX(-2, -5, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF),
    VTX(-10, 1, -25, 0, 0, 0x00, 0x00, 0x88, 0xFF), VTX(-16, 8, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
    VTX(-10, 1, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),  VTX(0, 8, 25, 0, 0, 0x00, 0x00, 0x78, 0xFF),
};
static Gfx D_84B13B38[] = {
    gsSPVertex(D_84B12498, 32, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 0, 4, 5, 0),
    gsSP2Triangles(0, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(7, 9, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(11, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(15, 17, 18, 0, 19, 20, 21, 0),
    gsSP2Triangles(19, 21, 22, 0, 23, 24, 25, 0),
    gsSP2Triangles(23, 25, 26, 0, 27, 28, 29, 0),
    gsSP1Triangle(27, 29, 30, 0),
    gsSPVertex(D_84B12688, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
    gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
    gsSPVertex(D_84B12888, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
    gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
    gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
    gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
    gsSPVertex(D_84B12A88, 5, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP1Triangle(0, 3, 4, 0),
    gsSPEndDisplayList(),
};
static Gfx D_84B13C40[] = {
    gsSPVertex(D_84B12AD8, 32, 0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(0, 3, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(5, 7, 8, 0, 8, 7, 9, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 9, 11, 0),
    gsSP2Triangles(10, 11, 12, 0, 12, 11, 13, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 13, 15, 0),
    gsSP2Triangles(14, 15, 16, 0, 16, 15, 17, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 17, 3, 0),
    gsSP2Triangles(18, 3, 19, 0, 19, 3, 2, 0),
    gsSP2Triangles(19, 2, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(21, 23, 24, 0, 24, 23, 25, 0),
    gsSP2Triangles(24, 25, 26, 0, 26, 25, 27, 0),
    gsSP2Triangles(26, 27, 28, 0, 28, 27, 29, 0),
    gsSP2Triangles(28, 29, 30, 0, 30, 29, 31, 0),
    gsSPVertex(D_84B12CD8, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(3, 5, 6, 0, 6, 5, 7, 0),
    gsSP2Triangles(6, 7, 8, 0, 8, 7, 9, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 9, 11, 0),
    gsSP2Triangles(10, 11, 12, 0, 12, 11, 13, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 13, 15, 0),
    gsSP2Triangles(14, 15, 16, 0, 16, 15, 17, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 17, 19, 0),
    gsSP2Triangles(18, 19, 20, 0, 21, 22, 23, 0),
    gsSP2Triangles(21, 23, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(25, 27, 28, 0, 28, 27, 29, 0),
    gsSP2Triangles(28, 29, 30, 0, 30, 29, 31, 0),
    gsSPVertex(D_84B12ED8, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(2, 3, 4, 0, 5, 6, 7, 0),
    gsSP2Triangles(5, 7, 8, 0, 8, 7, 9, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 9, 11, 0),
    gsSP2Triangles(10, 11, 12, 0, 12, 11, 13, 0),
    gsSP2Triangles(12, 13, 14, 0, 15, 16, 17, 0),
    gsSP2Triangles(15, 17, 18, 0, 18, 17, 19, 0),
    gsSP2Triangles(18, 19, 20, 0, 20, 19, 21, 0),
    gsSP2Triangles(20, 21, 22, 0, 22, 21, 23, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(25, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_84B130D8, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(2, 3, 4, 0, 4, 3, 5, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 5, 7, 0),
    gsSP2Triangles(6, 7, 8, 0, 8, 7, 9, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 9, 11, 0),
    gsSP2Triangles(10, 11, 12, 0, 12, 11, 13, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 13, 15, 0),
    gsSP2Triangles(14, 15, 16, 0, 16, 15, 17, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 17, 19, 0),
    gsSP2Triangles(18, 19, 20, 0, 20, 19, 21, 0),
    gsSP2Triangles(20, 21, 22, 0, 22, 21, 23, 0),
    gsSP2Triangles(22, 23, 24, 0, 25, 26, 27, 0),
    gsSP2Triangles(25, 27, 28, 0, 29, 30, 31, 0),
    gsSPVertex(D_84B132D8, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(2, 3, 4, 0, 4, 3, 5, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 5, 7, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(9, 11, 12, 0, 12, 11, 13, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 13, 15, 0),
    gsSP2Triangles(14, 15, 16, 0, 16, 15, 17, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 17, 19, 0),
    gsSP2Triangles(18, 19, 20, 0, 20, 19, 21, 0),
    gsSP2Triangles(20, 21, 22, 0, 22, 21, 23, 0),
    gsSP2Triangles(22, 23, 24, 0, 24, 23, 25, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSP2Triangles(27, 29, 30, 0, 30, 29, 31, 0),
    gsSPVertex(D_84B134D8, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(2, 3, 4, 0, 4, 3, 5, 0),
    gsSP2Triangles(4, 5, 6, 0, 6, 5, 7, 0),
    gsSP2Triangles(6, 7, 8, 0, 8, 7, 9, 0),
    gsSP2Triangles(8, 9, 10, 0, 10, 9, 11, 0),
    gsSP2Triangles(10, 11, 12, 0, 12, 11, 13, 0),
    gsSP2Triangles(12, 13, 14, 0, 14, 13, 15, 0),
    gsSP2Triangles(14, 15, 16, 0, 16, 15, 17, 0),
    gsSP2Triangles(16, 17, 18, 0, 18, 17, 19, 0),
    gsSP2Triangles(18, 19, 20, 0, 20, 19, 21, 0),
    gsSP2Triangles(20, 21, 22, 0, 22, 21, 23, 0),
    gsSP2Triangles(22, 23, 24, 0, 24, 23, 25, 0),
    gsSP2Triangles(24, 25, 26, 0, 27, 28, 29, 0),
    gsSP2Triangles(27, 29, 30, 0, 30, 29, 31, 0),
    gsSPVertex(D_84B136D8, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
    gsSP2Triangles(2, 3, 4, 0, 4, 3, 5, 0),
    gsSP2Triangles(4, 5, 6, 0, 7, 8, 9, 0),
    gsSP2Triangles(7, 9, 10, 0, 7, 10, 11, 0),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSP2Triangles(12, 15, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(17, 19, 20, 0, 21, 17, 20, 0),
    gsSP2Triangles(21, 20, 22, 0, 23, 21, 22, 0),
    gsSP2Triangles(24, 23, 22, 0, 25, 24, 22, 0),
    gsSP2Triangles(25, 22, 26, 0, 25, 26, 27, 0),
    gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
    gsSPVertex(D_84B138D8, 32, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSP2Triangles(4, 0, 3, 0, 4, 3, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
    gsSP2Triangles(6, 9, 10, 0, 11, 12, 13, 0),
    gsSP2Triangles(11, 13, 14, 0, 15, 11, 14, 0),
    gsSP2Triangles(15, 14, 16, 0, 15, 16, 17, 0),
    gsSP2Triangles(15, 17, 18, 0, 19, 15, 18, 0),
    gsSP2Triangles(20, 19, 21, 0, 22, 23, 1, 0),
    gsSP2Triangles(22, 1, 24, 0, 25, 20, 26, 0),
    gsSP2Triangles(25, 26, 27, 0, 28, 25, 27, 0),
    gsSP2Triangles(29, 28, 27, 0, 30, 29, 27, 0),
    gsSP2Triangles(30, 27, 31, 0, 10, 30, 31, 0),
    gsSP2Triangles(10, 31, 6, 0, 21, 26, 20, 0),
    gsSPVertex(D_84B13AD8, 6, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B13FC8[] = {
    0x17000000, 0x0000016A,    0x00000000, 0x00000000, 0x84B12498, 0x05000000, 0x22010000, 0x00000000,
    0x08000000, func_84B06ED0, 0x00000000, 0x1B000000, 0x00000000, 0x0000001B, 0x00040000, 0x05000000,
    0x22010000, D_84B13C40,    0x06000000, 0x1B000000, 0x00000000, 0x0000FFD2, 0x00010000, 0x05000000,
    0x22010000, D_84B13B38,    0x06000000, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84B14040[] = {
    VTX(-32, 48, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, 16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, 48, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, -48, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -48, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, -16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B14100[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGB, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B14040, 12, 0),
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
static u32 D_84B141E8[] = {
    0x17000000,    0x00000000, 0x00000000, 0x00000000, D_84B14040, 0x05000000, 0x1B000000,
    0x00000000,    0x00000000, 0xFFD00000, 0x05000000, 0x22010000, 0x00000000, 0x08000000,
    func_84B06E08, D_84B14100, 0x06000000, 0x06000000, 0x01000000,
};
static u32 D_84B14234[] = {
    0x17000000,    0x00000000, 0x00000000, 0x00000000, D_84B14040, 0x05000000, 0x1B000000,
    0x00000000,    0x00000000, 0x00300000, 0x05000000, 0x22010000, 0x00000000, 0x08000000,
    func_84B06E08, D_84B14100, 0x06000000, 0x06000000, 0x01000000,
};
static Vtx D_84B14280[] = {
    VTX(-32, 24, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 0, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 0, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(32, 24, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, -24, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -24, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 0, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B14300[] = {
    VTX(-30, 22, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-30, 7, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 7, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, 22, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 22, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(0, 7, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(30, 7, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(30, 22, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B14380[] = {
    VTX(-30, 7, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-30, -7, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -7, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, 7, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 7, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(0, -7, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(30, -7, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(30, 7, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B14400[] = {
    VTX(-30, -7, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-30, -22, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -22, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, -7, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -7, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(0, -22, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(30, -22, 0, 4096, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(30, -7, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B14480[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B14280, 8, 0),
    gsDPLoadTextureBlock(0x0E000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0E000C00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPVertex(D_84B14300, 8, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 64, 0, 127, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPVertex(D_84B14380, 8, 0),
    gsDPLoadTextureTile(0x0F002000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F002000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 64, 0, 127, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPVertex(D_84B14400, 8, 0),
    gsDPLoadTextureTile(0x0F004000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 0, 0, 63, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F004000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 64, 0, 127, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B146C0[] = {
    0x17000000,    0x00000000, 0x00000000, 0x00000000, D_84B14280, 0x05000000,    0x1B000000, 0x00000000, 0x00000000,
    0xFFE80000,    0x05000000, 0x22050000, 0x00000000, 0x08000000, func_84B06B50, 0x00000000, 0x22050000, D_84B14480,
    0x06000000,    0x1B000000, 0x00000000, 0x00000000, 0xFFB80000, 0x05000000,    0x22050000, 0x00000000, 0x08000000,
    func_84B06B50, 0x00000001, 0x22050000, D_84B14480, 0x25000000, 0x06000000,    0x06000000, 0x01000000,
};
static u32 D_84B1474C[] = {
    0x17000000,    0x00000000, 0x00000000, 0x00000000, D_84B14280, 0x05000000,    0x1B000000, 0x00000000, 0x00000000,
    0x00480000,    0x05000000, 0x22050000, 0x00000000, 0x08000000, func_84B06B50, 0x00000000, 0x22050000, D_84B14480,
    0x06000000,    0x1B000000, 0x00000000, 0x00000000, 0x00180000, 0x05000000,    0x22050000, 0x00000000, 0x08000000,
    func_84B06B50, 0x00000001, 0x22050000, D_84B14480, 0x25000000, 0x06000000,    0x06000000, 0x01000000,
};
static Vtx D_84B147D8[] = {
    VTX(-24, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-24, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, -16, 0, 1536, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, 16, 0, 1536, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B14818[] = {
    VTX(-22, 14, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-22, 0, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 0, 0, 1536, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, 14, 0, 1536, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 14, 0, 1536, 0, 0xFF, 0xFF, 0xFF, 0xFF),    VTX(0, 0, 0, 1536, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(22, 0, 0, 3072, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(22, 14, 0, 3072, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_84B14898[] = {
    VTX(-22, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),        VTX(-22, -14, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -14, 0, 1536, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(0, 0, 0, 1536, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 0, 0, 1536, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(0, -14, 0, 1536, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(22, -14, 0, 3072, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(22, 0, 0, 3072, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B14918[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B147D8, 4, 0),
    gsDPLoadTextureBlock(0x0E000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPVertex(D_84B14818, 8, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 96, 0, 0, 0, 47, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 96, 0, 48, 0, 95, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPVertex(D_84B14898, 8, 0),
    gsDPLoadTextureTile(0x0F001800, G_IM_FMT_RGBA, G_IM_SIZ_16b, 96, 0, 0, 0, 47, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F001800, G_IM_FMT_RGBA, G_IM_SIZ_16b, 96, 0, 48, 0, 95, 31, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B14A90[] = {
    0x17000000,    0x00000000, 0x00000000, 0x00000000,    D_84B147D8, 0x05000000, 0x1B000000,    0x00000000,
    0x00000000,    0xFFF00000, 0x05000000, 0x22050000,    0x00000000, 0x08000000, func_84B06C7C, 0x00000000,
    0x22050000,    D_84B14918, 0x06000000, 0x1B000000,    0x00000000, 0x00000000, 0xFFD00000,    0x05000000,
    0x22050000,    0x00000000, 0x08000000, func_84B06C7C, 0x00000001, 0x22050000, D_84B14918,    0x06000000,
    0x1B000000,    0x00000000, 0x00000000, 0xFFB00000,    0x05000000, 0x22050000, 0x00000000,    0x08000000,
    func_84B06C7C, 0x00000002, 0x22050000, D_84B14918,    0x25000000, 0x06000000, 0x06000000,    0x01000000,
};
static u32 D_84B14B50[] = {
    0x17000000,    0x00000000, 0x00000000, 0x00000000,    D_84B147D8, 0x05000000, 0x1B000000,    0x00000000,
    0x00000000,    0x00500000, 0x05000000, 0x22050000,    0x00000000, 0x08000000, func_84B06C7C, 0x00000000,
    0x22050000,    D_84B14918, 0x06000000, 0x1B000000,    0x00000000, 0x00000000, 0x00300000,    0x05000000,
    0x22050000,    0x00000000, 0x08000000, func_84B06C7C, 0x00000001, 0x22050000, D_84B14918,    0x06000000,
    0x1B000000,    0x00000000, 0x00000000, 0x00100000,    0x05000000, 0x22050000, 0x00000000,    0x08000000,
    func_84B06C7C, 0x00000002, 0x22050000, D_84B14918,    0x25000000, 0x06000000, 0x06000000,    0x01000000,
};

s32 func_84B06F60(unk_D_84B25A28* arg0, s16 arg1) {
    s16 i;
    s16 sp24;
    s16 sp22;

    if (osTvType == OS_TV_PAL) {
        sp24 = 0x10;
        sp22 = 0x4F0;
    } else {
        sp24 = 0x14;
        sp22 = 0x400;
    }

    if (arg1 == 0) {
        func_8004DF94(0x01100006, 0, 0);
    }

    if (sp24 >= arg1) {
        for (i = 0; i < 5; i++) {
            arg0->unk_04[i].unk_01E.x -= sp22;
        }

        for (i = 5; i < 10; i++) {
            arg0->unk_04[i].unk_01E.x += sp22;
        }

        return 0;
    }

    return 1;
}

void func_84B07058(unk_D_84B25A28* arg0, s16 arg1) {
    arg0->unk_08->unk_60.at.y = SINS(arg1 << 0xE) * SQ((0x10 - arg1) / 12.0f);
    func_80010354(&arg0->unk_08->unk_60.at, &arg0->unk_08->unk_60.eye, 289.0f, 0, 0);
}

s32 func_84B070EC(unk_D_84B25A28* arg0, s16 arg1) {
    if (arg1 == 0) {
        func_8004DF94(0x01100007, 0, 0);
    }

    if (arg1 == 0x15) {
        func_8004DF94(0x01100008, 0, 0);
    }

    if (arg1 < 0x14) {
        arg0->unk_04[10].unk_024.z = -80.0f - (arg1 * 30.0f);
        return 0;
    }

    if (arg1 < 0x24) {
        func_84B07058(arg0, arg1 - 0x13);
        return 0;
    }
    return 1;
}

s32 func_84B071C0(unk_D_84B25A28* arg0, s16 arg1) {
    if (arg1 == 0) {
        func_8004DF94(0x01100007, 0, 0);
    }

    if (arg1 == 0x11) {
        func_8004DF94(0x01100008, 0, 0);
    }

    if (arg1 < 0x10) {
        arg0->unk_04[10].unk_024.z = -80.0f - (arg1 * 38.0f);
        return 0;
    }

    if (arg1 < 0x20) {
        func_84B07058(arg0, arg1 - 0xF);
        return 0;
    }

    return 1;
}

void func_84B07294(unk_D_84B25A28* arg0) {
    s32 sp24 = 1;

    if (osTvType == OS_TV_PAL) {
        if (arg0->unk_01 >= 0) {
            sp24 = func_84B06F60(arg0, arg0->unk_01) & 1;
        }

        if (arg0->unk_01 >= 0xD) {
            sp24 &= func_84B071C0(arg0, arg0->unk_01 - 0xD);
        }
    } else {
        if (arg0->unk_01 >= 0) {
            sp24 = func_84B06F60(arg0, arg0->unk_01) & 1;
        }

        if (arg0->unk_01 >= 0x10) {
            sp24 &= func_84B070EC(arg0, arg0->unk_01 - 0x10);
        }
    }

    if (sp24 != 0) {
        arg0->unk_00 = 0;
    }
    arg0->unk_01++;
}

void func_84B07370(unk_D_84B25A28* arg0) {
    func_8001AA18(arg0->unk_20, 0, arg0);

    arg0->unk_01++;
    if ((arg0->unk_01 >= 0x1E) && (func_8001B010(arg0->unk_20) != 0)) {
        arg0->unk_01 = 0;
        arg0->unk_00 = 2;
    }
}

void func_84B073D8(unk_D_84B25A28* arg0) {
    switch (arg0->unk_00) {
        case 1:
            func_84B07370(arg0);
            break;

        case 3:
            func_84B07294(arg0);
            break;
    }
}

void func_84B07428(unk_D_84B25A28* arg0) {
    s32 i;
    s32 count;
    unk_D_86002F58_004_000_010* temp_s0;

    temp_s0 = func_80019760(5);
    func_8001A1D0(arg0->unk_20, temp_s0, func_80006314(0, 2, 0x80, 0x60, 1));

    for (count = 0, i = 0; i < D_800AE540.unk_1194[0].unk_08[0]->unk_214->unk_002; count++, i++) {
        func_8001A324(arg0->unk_20, count, D_800AE540.unk_1194[0].unk_08[0]->unk_214->unk_028[i].unk_00.unk_00, 0);
    }

    for (count = 6, i = 0; i < D_800AE540.unk_1194[1].unk_08[0]->unk_214->unk_002; count++, i++) {
        func_8001A324(arg0->unk_20, count, D_800AE540.unk_1194[1].unk_08[0]->unk_214->unk_028[i].unk_00.unk_00, 0);
    }
}

void func_84B07560(unk_D_84B25A28* arg0) {
    s32 i;
    s32 count;
    unk_D_86002F58_004_000_010* tmp = func_80019760(5);

    func_8001A1D0(arg0->unk_20, tmp, func_80006314(0, 2, 0x60, 0x40, 1));

    for (count = 0, i = 0; i < D_800AE540.unk_1194[0].unk_08[0]->unk_214->unk_002; count++, i++) {
        func_8001A324(arg0->unk_20, count, D_800AE540.unk_1194[0].unk_08[0]->unk_214->unk_028[i].unk_00.unk_00, 0);
    }

    if (D_800AE540.unk_1194[0].unk_08[1] != NULL) {
        for (i = 0, count = 6; i < D_800AE540.unk_1194[0].unk_08[1]->unk_214->unk_002; count++, i++) {
            func_8001A324(arg0->unk_20, count, D_800AE540.unk_1194[0].unk_08[1]->unk_214->unk_028[i].unk_00.unk_00, 0);
        }
    }

    for (i = 0, count = 12; i < D_800AE540.unk_1194[1].unk_08[0]->unk_214->unk_002; count++, i++) {
        func_8001A324(arg0->unk_20, count, D_800AE540.unk_1194[1].unk_08[0]->unk_214->unk_028[i].unk_00.unk_00, 0);
    }

    if (D_800AE540.unk_1194[1].unk_08[1] != NULL) {
        for (count = 18, i = 0; i < D_800AE540.unk_1194[1].unk_08[1]->unk_214->unk_002; count++, i++) {
            func_8001A324(arg0->unk_20, count, D_800AE540.unk_1194[1].unk_08[1]->unk_214->unk_028[i].unk_00.unk_00, 0);
        }
    }
}

void func_84B07758(unk_D_84B25A28* arg0, BinArchive* arg1) {
    u8* sp24 = func_8000484C(arg1, D_800AE540.unk_1194[0].unk_08[0]->unk_214->unk_003);
    u8* sp20 = func_8000484C(arg1, D_800AE540.unk_1194[1].unk_08[0]->unk_214->unk_003);

    func_8001987C();
    FRAGMENT_LOAD(fragment31);

    if (arg0->unk_02 == 1) {
        func_84B07560(arg0);
    } else {
        func_84B07428(arg0);
    }

    func_84B00D3C(arg0->unk_24, 0, sp24, D_3000000);
    func_84B00D3C(arg0->unk_28, 1, sp20, D_3003000);
    arg0->unk_00 = 1;
}

void func_84B07848(unk_D_84B25A28* arg0) {
    func_8000E88C(&arg0->unk_04[0].unk_024, -96.0f, 96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[2].unk_024, -32.0f, 96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[3].unk_024, 32.0f, 96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[4].unk_024, 96.0f, 96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[5].unk_024, -96.0f, -96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[6].unk_024, -32.0f, -96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[7].unk_024, 32.0f, -96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[9].unk_024, 96.0f, -96.0f, -289.0f);

    arg0->unk_04[1].unk_000.unk_01 &= ~1;
    arg0->unk_04[8].unk_000.unk_01 &= ~1;
}

void func_84B07978(unk_D_84B25A28* arg0) {
    func_8000E88C(&arg0->unk_04[0].unk_024, -96.0f, 96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[1].unk_024, -40.0f, 96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[2].unk_024, 8.0f, 96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[3].unk_024, 56.0f, 96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[4].unk_024, 104.0f, 96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[5].unk_024, -104.0f, -96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[6].unk_024, -56.0f, -96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[7].unk_024, -8.0f, -96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[8].unk_024, 40.0f, -96.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[9].unk_024, 96.0f, -96.0f, -289.0f);
}

s32 func_84B07AB8(unk_D_84B25A28* arg0, unk_D_86002F58_004_000* arg1) {
    s32 i;
    s16 var_a1;

    if (arg0->unk_00 == 2) {
        arg0->unk_00 = 3;
        arg0->unk_04 = arg1;
        arg0->unk_01 = 0;
        if (osTvType == OS_TV_PAL) {
            var_a1 = 0x53F0;
        } else {
            var_a1 = 0x5400;
        }

        for (i = 0; i < 11; i++) {
            arg0->unk_04[i].unk_000.unk_14 = arg0;
        }

        for (i = 0; i < 5; i++) {
            arg0->unk_04[i].unk_01E.x = var_a1;
        }

        // clang-format off
        for (i = 5; i < 10; i++) { arg0->unk_04[i].unk_01E.x = -var_a1; }
        // clang-format on

        func_8001BC34(&arg0->unk_04[0], 1, 0, arg0->unk_14);
        func_8001BC34(&arg0->unk_04[1], 1, 0, arg0->unk_0C);
        func_8001BC34(&arg0->unk_04[2], 1, 0, arg0->unk_0C);
        func_8001BC34(&arg0->unk_04[3], 1, 0, arg0->unk_0C);
        func_8001BC34(&arg0->unk_04[4], 1, 0, arg0->unk_0C);
        func_8001BC34(&arg0->unk_04[5], 1, 0, arg0->unk_10);
        func_8001BC34(&arg0->unk_04[6], 1, 0, arg0->unk_10);
        func_8001BC34(&arg0->unk_04[7], 1, 0, arg0->unk_10);
        func_8001BC34(&arg0->unk_04[8], 1, 0, arg0->unk_10);
        func_8001BC34(&arg0->unk_04[9], 1, 0, arg0->unk_18);
        func_8001BC34(&arg0->unk_04[10], 3, 0, arg0->unk_1C);
        func_8000E88C(&arg0->unk_04[10].unk_024, 0.0f, 0.0f, 1000.0f);

        if (arg0->unk_02 == 1) {
            func_84B07978(arg0);
        } else {
            func_84B07848(arg0);
        }
    }

    return arg0->unk_00 == 3;
}

void func_84B07CF8(unk_D_84B25A28* arg0, unk_D_86002F34_00C* arg1) {
    MemoryBlock* temp_s1;

    arg0->unk_08 = arg1;
    arg0->unk_00 = 0;
    arg0->unk_01 = 0;
    arg0->unk_02 = 0;
    arg0->unk_24 = func_80006314(0, 2, 0x40, 0x60, 0);
    arg0->unk_28 = func_80006314(0, 2, 0x40, 0x60, 0);

    if ((D_800AE540.unk_0001 == 0) && ((D_800AE540.unk_1194[0].unk_01 == 2) || (D_800AE540.unk_1194[1].unk_01 == 2))) {
        arg0->unk_02 = 1;
    }
    if (arg0->unk_02 == 1) {
        arg0->unk_20 = func_8001A024(NULL, 0x18, 0x60, 0x40);
    } else {
        arg0->unk_20 = func_8001A024(NULL, 0xC, 0x80, 0x60);
    }
    func_8001A250(arg0->unk_20, D_84B17620);

    temp_s1 = func_80002D10(main_pool_get_available(), 0);
    if (arg0->unk_02 == 1) {
        arg0->unk_0C = process_geo_layout(temp_s1, D_84B14A90);
        arg0->unk_10 = process_geo_layout(temp_s1, D_84B14B50);
    } else {
        arg0->unk_0C = process_geo_layout(temp_s1, D_84B146C0);
        arg0->unk_10 = process_geo_layout(temp_s1, D_84B1474C);
    }

    arg0->unk_14 = process_geo_layout(temp_s1, D_84B141E8);
    arg0->unk_18 = process_geo_layout(temp_s1, D_84B14234);
    arg0->unk_1C = process_geo_layout(temp_s1, D_84B13FC8);

    func_80002D60(temp_s1);
}
