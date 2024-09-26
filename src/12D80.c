#include "12D80.h"
#include "src/12D80.h"
#include "src/1CF30.h"
#include "src/1CF30.h"
#include "src/17300.h"
#include "src/18140.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/32D10.h"
#include "src/F420.h"
#include "src/memmap.h"
#include "src/util.h"

typedef void (*func_D_8006F0A4)(unk_D_86002F34_000* arg0);

typedef struct unk_D_800AA8C8 {
    /* 0x0000 */ MtxF unk_0000[64];
    /* 0x1000 */ MtxF* unk_1000[32];
    /* 0x1080 */ s8 unk_1080[32];
    /* 0x10A0 */ s32 unk_10A0;
} unk_D_800AA8C8; // size >= 0x10A4

s32 D_8006F080 = 0;
u16 D_8006F084 = 0;
unk_D_86002F34_00C* D_8006F088 = NULL;
unk_D_86002F34_alt1* D_8006F08C = NULL;
unk_D_86002F34_alt1* D_8006F090 = NULL;
unk_D_86002F34_00C* D_8006F094 = NULL;
unk_D_86002F34_alt1* D_8006F098 = NULL;
unk_D_86002F58_004_000* D_8006F09C = NULL;
unk_D_86002F34_alt11* D_8006F0A0 = NULL;
static func_D_8006F0A4 D_8006F0A4[] = {
    func_80013330, func_800133D8, func_80013464, func_80013764, func_8001378C, func_8001395C, func_800139E8,
    func_80013AF8, func_80013B8C, func_80013C14, func_80013C1C, func_80013D34, func_80013F7C, func_80013F84,
    func_80014124, func_80014D70, func_80014214, func_800142BC, func_80014334, func_80014384, func_800143C0,
    func_80014624, func_80014690, func_800148D8, func_80014980, func_80014A60, func_80014AEC, func_80014D24,
    func_80014D50, NULL,          NULL,
};

static s32 D_8006F120 = 0;

static u32 D_8006F124[4][9] = {
    {
        0x3024000,
        0x3024000,
        0x3024000,
        0x3024000,
        0x3027008,
        0x104240,
        0x104240,
        0x104240,
        0x104240,
    },
    {
        0x3124370,
        0x112230,
        0x112E10,
        0x112230,
        0x113238,
        0x104A50,
        0x104E50,
        0x104A50,
        0x104A70,
    },
    {
        0x3024000,
        0x112048,
        0x112048,
        0x112048,
        0x113048,
        0x1041C8,
        0x1041C8,
        0x1041C8,
        0x1041C8,
    },
    {
        0x3124370,
        0x112078,
        0x112D58,
        0x112478,
        0x113078,
        0x1049D8,
        0x104DD8,
        0x1045D8,
        0x1049F8,
    },
};

static u8 D_8006F1B4[15][16] = {
    { 0x1F, 0x1F, 0x1F, 3, 7, 7, 7, 3, 0, 0x1F, 4, 0x1F, 0, 7, 6, 7 },
    { 1, 0x1F, 3, 0x1F, 7, 7, 7, 1, 0, 0x1F, 4, 0x1F, 0, 7, 6, 7 },
    { 1, 3, 8, 3, 7, 7, 3, 7, 0, 0x1F, 4, 0x1F, 0, 7, 6, 7 },
    { 1, 0x1F, 3, 0x1F, 7, 7, 7, 3, 0, 0x1F, 4, 0x1F, 0, 7, 6, 7 },
    { 1, 0x1F, 3, 0x1F, 1, 7, 3, 7, 0, 0x1F, 4, 0x1F, 0, 7, 6, 7 },
    { 0x1F, 0x1F, 0x1F, 3, 7, 7, 7, 3, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 0x1F, 3, 0x1F, 7, 7, 7, 1, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 3, 8, 3, 7, 7, 3, 7, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 0x1F, 3, 0x1F, 7, 7, 7, 3, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 0x1F, 3, 0x1F, 1, 7, 3, 7, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 0x1F, 0x1F, 0x1F, 4, 7, 7, 7, 4, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 0x1F, 4, 0x1F, 7, 7, 7, 1, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 4, 8, 4, 7, 7, 3, 7, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 0x1F, 4, 0x1F, 7, 7, 7, 4, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
    { 1, 0x1F, 4, 0x1F, 1, 7, 4, 7, 0x1F, 0x1F, 0x1F, 0, 0, 7, 6, 7 },
};

static s16 D_8006F2A4[] = { 16, 8, 4, 2, 0, 0 };

static s32 D_800AA6C0;
static MtxF* D_800AA6C8[8];
static u8 pad_D_800AA6E8[0x1E0];
static unk_D_800AA8C8 D_800AA8C8;
static unk_D_800AB970 D_800AB970;
static s32 D_800ABB00;
static s32 D_800ABB04;
static s32 D_800ABB08;
static unk_D_800ABB10 D_800ABB10;
static unk_D_800ABB28 D_800ABB28[10];
static unk_D_800ABB28* D_800ABCB8;
static s32 D_800ABCBC;

void func_80012180(void) {
    D_800AA8C8.unk_10A0 = 0;
    D_800AA8C8.unk_1080[0] = 0;
    func_8000ED98(&D_800AA8C8.unk_0000[0]);
    D_800AA8C8.unk_1000[0] = func_80005F5C(sizeof(Mtx) * 1);
    func_80010090(D_800AA8C8.unk_1000[0], D_800AA8C8.unk_0000);
}

void func_800121C8(void) {
    D_800AA8C8.unk_1080[D_800AA8C8.unk_10A0] = 0;
    D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0] = func_80005F5C(sizeof(MtxF) * 1);
    func_80010090(D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0], &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
}

void func_80012230(MtxF* arg0) {
    func_8000ED4C(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0], arg0);
    D_800AA8C8.unk_1080[D_800AA8C8.unk_10A0] = 0;
    D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0] = func_80005F5C(sizeof(MtxF) * 1);
    func_80010090(D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0], &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
}

void func_800122B4(MtxF* arg0) {
    MtxF* temp_a0;

    D_800AA8C8.unk_10A0++;
    temp_a0 = &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0];

    func_8000FBB0(&temp_a0[0], arg0, &temp_a0[-1]);
    D_800AA8C8.unk_1080[D_800AA8C8.unk_10A0] = 0;
    D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0] = func_80005F5C(sizeof(MtxF) * 1);
    func_80010090(D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0], &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
}

void func_80012344(Vec3f* arg0) {
    MtxF* temp_a0;

    D_800AA8C8.unk_10A0++;
    temp_a0 = &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0];

    func_8000FDE4(&temp_a0[0], &temp_a0[-1], arg0);

    D_800AA8C8.unk_1080[D_800AA8C8.unk_10A0] = 0;
    D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0] = func_80005F5C(sizeof(MtxF) * 1);

    func_80010090(D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0], &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
}

MtxF* func_800123D4(s32 arg0) {
    MtxF* var_v1 = NULL;

    if (arg0 <= 0) {
        var_v1 = &(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0])[arg0];
    }

    return var_v1;
}

MtxF* func_80012400(s32 arg0) {
    MtxF* var_v1 = NULL;

    if ((arg0 >= 0) && (arg0 < 0x20)) {
        var_v1 = &D_800AA8C8.unk_0000[arg0];
    }

    return var_v1;
}

void func_80012428(void) {
    D_800AB970.unk_180 = 0;
    D_800AB970.unk_000[0] = D_8006F064;
}

void func_80012458(Vec3f* arg0) {
    D_800AB970.unk_000[D_800AB970.unk_180 + 1].x = D_800AB970.unk_000[D_800AB970.unk_180].x * arg0->x;
    D_800AB970.unk_000[D_800AB970.unk_180 + 1].y = D_800AB970.unk_000[D_800AB970.unk_180].y * arg0->y;
    D_800AB970.unk_000[D_800AB970.unk_180 + 1].z = D_800AB970.unk_000[D_800AB970.unk_180].z * arg0->z;

    D_800AB970.unk_180++;
}

Vtx* func_800124D4(unk_D_86002F34_00C_0CC* arg0, unk_D_86002F34_00C_040* arg1) {
    u8 sp47;
    Vtx* temp_v0 = func_80005F5C(sizeof(Vtx) * 4);

    if (temp_v0 != NULL) {
        switch (arg0->unk_00) {
            case 1:
                sp47 = 0xFF;
                break;

            case 2:
                sp47 = 0xFF - ((arg0->unk_0A * 0xFF) / arg0->unk_08);
                break;

            case 3:
                sp47 = (arg0->unk_0A * 0xFF) / arg0->unk_08;
                break;
        }

        func_8001E680(&temp_v0[0], arg1->l, arg1->t, -1, 0, 0, arg0->color.r, arg0->color.g, arg0->color.b, sp47);
        func_8001E680(&temp_v0[1], arg1->l, arg1->b, -1, 0, 0, arg0->color.r, arg0->color.g, arg0->color.b, sp47);
        func_8001E680(&temp_v0[2], arg1->r, arg1->b, -1, 0, 0, arg0->color.r, arg0->color.g, arg0->color.b, sp47);
        func_8001E680(&temp_v0[3], arg1->r, arg1->t, -1, 0, 0, arg0->color.r, arg0->color.g, arg0->color.b, sp47);
    }

    return temp_v0;
}

void func_80012768(unk_D_86002F34_00C_0CC* arg0, unk_D_86002F34_00C_040* arg1) {
    Vtx* temp_v0 = func_800124D4(arg0, arg1);

    if (temp_v0 != NULL) {
        gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
        gDPSetRenderMode(gDisplayListHead++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

        gSPVertex(gDisplayListHead++, (u32)temp_v0 & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);
    }

    if (arg0->unk_00 != 1) {
        arg0->unk_0A++;
        if (arg0->unk_0A == arg0->unk_08) {
            if (arg0->unk_00 == 2) {
                arg0->unk_00 = 0;
            } else {
                arg0->unk_00 = 1;
            }
        }
    }
}

#ifdef NON_MATCHING
void func_80012870(Vtx* arg0, unk_D_86002F34_00C_0CC* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6,
                   s16 arg7) {
    f32 temp_fa0;
    f32 temp_fv1;
    u16 idx = arg1->unk_18;
    f32 a4;
    f32 a5;
    s16 tmp1;
    s16 tmp2;

    a4 = arg4;
    temp_fv1 = COSS(idx);
    temp_fa0 = SINS(idx);
    a5 = arg5;

    tmp1 = ((a4 * temp_fv1) - (temp_fa0 * a5));
    tmp2 = ((temp_fv1 * a5) + (a4 * temp_fa0));

    func_8001E680(arg0, tmp1 + arg2, tmp2 + arg3, -1, arg6 * 32, arg7 * 32, arg1->color.r, arg1->color.g, arg1->color.b,
                  0xFF);
}
#else
void func_80012870(Vtx* arg0, unk_D_86002F34_00C_0CC* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7);
#pragma GLOBAL_ASM("asm/us/nonmatchings/12D80/func_80012870.s")
#endif

Vtx* func_80012960(unk_D_86002F34_00C_0CC* arg0) {
    Vtx* temp_v0 = func_80005F5C(sizeof(Vtx) * 8);
    Vtx* temp_s0;
    s16 temp_s2;
    s16 temp_s4;
    s16 temp_s5;

    if (temp_v0 != NULL) {
        temp_s0 = temp_v0;

        temp_s4 = arg0->unk_10 + (((arg0->unk_14 - arg0->unk_10) * arg0->unk_0A) / arg0->unk_08);
        temp_s5 = arg0->unk_12 + (((arg0->unk_16 - arg0->unk_12) * arg0->unk_0A) / arg0->unk_08);
        temp_s2 = arg0->unk_0C + (((arg0->unk_0E - arg0->unk_0C) * arg0->unk_0A) / arg0->unk_08);

        if (arg0->unk_00 == 2) {
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, -temp_s2, -temp_s2, -0x1F, 0x3F);
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, temp_s2, -temp_s2, 0x1F, 0x3F);
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, temp_s2, temp_s2, 0x1F, 0);
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, -temp_s2, temp_s2, -0x1F, 0);
        } else {
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, -temp_s2, -temp_s2, 0, 0x3F);
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, temp_s2, -temp_s2, 0x3F, 0x3F);
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, temp_s2, temp_s2, 0x3F, 0);
            func_80012870(temp_s0++, arg0, temp_s4, temp_s5, -temp_s2, temp_s2, 0, 0);
        }

        func_80012870(temp_s0++, arg0, temp_s4, temp_s5, -0x7D0, -0x7D0, 0, 0);
        func_80012870(temp_s0++, arg0, temp_s4, temp_s5, 0x7D0, -0x7D0, 0, 0);
        func_80012870(temp_s0++, arg0, temp_s4, temp_s5, 0x7D0, 0x7D0, 0, 0);
        func_80012870(temp_s0++, arg0, temp_s4, temp_s5, -0x7D0, 0x7D0, 0, 0);
    }

    arg0->unk_18 += arg0->unk_1A;
    return temp_v0;
}

void func_80012D88(unk_D_86002F34_00C_0CC* arg0, UNUSED unk_D_86002F34_00C_040* arg1) {
    Vtx* temp_v0 = func_80012960(arg0);

    if (temp_v0 != 0) {
        gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
        gDPSetRenderMode(gDisplayListHead++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);

        gSPVertex(gDisplayListHead++, (u32)temp_v0 & 0x1FFFFFFF, 8, 0);
        gSP2Triangles(gDisplayListHead++, 0, 4, 1, 0, 1, 4, 5, 0);
        gSP2Triangles(gDisplayListHead++, 1, 5, 2, 0, 2, 5, 6, 0);
        gSP2Triangles(gDisplayListHead++, 2, 6, 7, 0, 2, 7, 3, 0);
        gSP2Triangles(gDisplayListHead++, 3, 4, 0, 0, 3, 7, 4, 0);

        gDPPipeSync(gDisplayListHead++);

        gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
        gDPSetRenderMode(gDisplayListHead++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);

        if (arg0->unk_02 == 0) {
            gDPLoadTextureBlock(gDisplayListHead++, arg0->texture, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD);
        } else {
            gDPLoadTextureBlock(gDisplayListHead++, arg0->texture, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 64, 0,
                                G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
        }

        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

        gSPVertex(gDisplayListHead++, (u32)temp_v0 & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);

        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
    }

    arg0->unk_0A++;
    if (arg0->unk_0A == arg0->unk_08) {
        if (arg0->unk_00 == 4) {
            arg0->unk_00 = 0;
        } else {
            arg0->unk_00 = 1;
        }
    }
}

void func_800131B4(unk_D_86002F34_00C_0CC* arg0, unk_D_86002F34_00C_040* arg1) {
    if (arg0->unk_00 != 0) {
        gDPPipeSync(gDisplayListHead++);

        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);
        gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
        gSPMatrix(gDisplayListHead++, (u32)arg1->mtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(gDisplayListHead++, (u32)&D_8006F010 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        if ((arg0->unk_00 == 1) || (arg0->unk_00 == 2) || (arg0->unk_00 == 3)) {
            func_80012768(arg0, arg1);
        } else {
            func_80012D88(arg0, arg1);
        }

        gDPPipeSync(gDisplayListHead++);
        gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
    }
}

void func_80013330(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_000* temp_s2 = arg0->unk_0C;
    unk_D_86002F34_000* var_s0 = temp_s2;

    if (temp_s2 != NULL) {
        do {
            if (var_s0->unk_01 & 1) {
                D_800AA6C0 = 0;
                if (var_s0->unk_10 != NULL) {
                    D_800AA6C0 = var_s0->unk_10(2, var_s0);
                }
                D_8006F0A4[var_s0->unk_00](var_s0);
            }
            var_s0 = var_s0->unk_08;
        } while (var_s0 != temp_s2);
    }
}

void func_800133D8(unk_D_86002F34_000* arg0) {
    UNUSED s32 pad;
    unk_D_86002F34_000* temp_a1 = ((unk_D_86002F34*)arg0)->unk_18;

    if ((temp_a1 != NULL) && (temp_a1->unk_01 & 1)) {
        D_800AA6C0 = 0;
        if (temp_a1->unk_10 != NULL) {
            D_800AA6C0 = temp_a1->unk_10(2, temp_a1);
        }
        D_8006F0A4[temp_a1->unk_00](temp_a1);
    }

    func_80013330(arg0);
}

void func_80013464(unk_D_86002F34_000* arg0) {
    UNUSED MtxF pad_mtx;
    unk_D_86002F34_00C* arg = (unk_D_86002F34_00C*)arg0;
    unk_D_86002F34_00C_040* temp_s2 = &arg->unk_40;
    unk_D_86002F34_00C_060* temp_s1 = &arg->unk_60;
    unk_D_86002F34_00C_024* sp48 = &arg->unk_24;
    unk_D_86002F34_00C_018* temp_s0 = &arg->unk_18;

    temp_s0->vp = func_80005F5C(sizeof(Vp) * 1);
    temp_s2->mtx = func_80005F5C(sizeof(Mtx) * 1);
    sp48->mtx = func_80005F5C(sizeof(MtxF) * 1);
    temp_s1->p_mtxf = func_80005F5C(sizeof(MtxF) * 1);
    temp_s1->lookat = func_80005F5C(sizeof(LookAt) * 1);

    temp_s0->vp->vp.vtrans[0] = (temp_s0->x * 4) + (temp_s0->width * 2);
    temp_s0->vp->vp.vtrans[1] = (temp_s0->y * 4) + (temp_s0->height * 2);
    temp_s0->vp->vp.vtrans[2] = 0x1FF;

    temp_s0->vp->vp.vscale[0] = temp_s0->width * 2;
    temp_s0->vp->vp.vscale[1] = temp_s0->height * 2;
    temp_s0->vp->vp.vscale[2] = 0x1FF;

    gSPViewport(gDisplayListHead++, (u32)temp_s0->vp & 0x1FFFFFFF);
    gDPSetScissorFrac(gDisplayListHead++, G_SC_NON_INTERLACE, temp_s0->x * 4.0f, temp_s0->y * 4.0f,
                      (temp_s0->x + temp_s0->width) * 4.0f, (temp_s0->y + temp_s0->height) * 4.0f);

    guOrtho(temp_s2->mtx, temp_s2->l, temp_s2->r, temp_s2->b, temp_s2->t, temp_s2->n, temp_s2->f, temp_s2->scale);
    guPerspective(sp48->mtx, &sp48->perspNorm, sp48->fovy, sp48->aspect, sp48->near, sp48->far, sp48->scale);
    guLookAtReflectF(&temp_s1->mtxf, temp_s1->lookat, temp_s1->eye.x, temp_s1->eye.y, temp_s1->eye.z, temp_s1->at.x,
                     temp_s1->at.y, temp_s1->at.z, temp_s1->up.x, temp_s1->up.y, temp_s1->up.z);
    func_80010090(temp_s1->p_mtxf, &temp_s1->mtxf);

    D_8006F088 = arg;
    if ((arg->unk_CC.unk_00 != 1) && (arg->unk_00.unk_0C != NULL)) {
        func_80013330(&arg->unk_00);
    }
    func_800131B4(&arg->unk_CC, temp_s2);
    func_80006200(&gDisplayListHead);
    D_8006F088 = NULL;
}

void func_80013764(unk_D_86002F34_000* arg0) {
    D_8006F08C = arg0;
    func_80013330(arg0);
    D_8006F08C = NULL;
}

void func_8001378C(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_alt1* arg = (unk_D_86002F34_alt1*)arg0;

    if (arg->unk_00.unk_0C != NULL) {
        arg->unk_1D = 0;
        arg->unk_20 = -1;
        arg->lights = func_80005F5C(sizeof(Lights7));
        arg->unk_1C = 0;
        arg->lights->a.l.col[0] = 0;
        arg->lights->a.l.col[1] = 0;
        arg->lights->a.l.col[2] = 0;

        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                                     G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
        gSPSetGeometryMode(gDisplayListHead++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
        gSPTexture(gDisplayListHead++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);

        func_80017080();
        func_800175D8();
        func_80012180();
        func_80012428();

        gSPMatrix(gDisplayListHead++, (u32)D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0] & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        D_8006F090 = arg;
        func_80013330(arg0);
        D_8006F090 = NULL;
    }

    arg->unk_1A = D_8006F084;
}

void func_800138F0(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_00C* arg = (unk_D_86002F34_00C*)arg0;

    if ((D_8006F094 == NULL) && (arg->unk_00.unk_0C != NULL)) {
        D_8006F094 = arg;
        func_8001638C(arg->unk_00.unk_02 & 3, D_8006F080);
        func_80013330(arg0);
        func_8001660C();
        D_8006F094 = NULL;
    }
}

void func_8001395C(unk_D_86002F34_000* arg0) {
    if ((D_8006F094 == NULL) && (arg0->unk_0C != NULL)) {
        gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
        gSPMatrix(gDisplayListHead++, (u32)D_8006F088->unk_40.mtx & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

        func_800138F0(arg0);
    }
}

void func_800139E8(unk_D_86002F34_000* arg0) {
    if ((D_8006F094 == NULL) && (arg0->unk_0C != NULL)) {
        gSPLookAt(gDisplayListHead++, (u32)&D_8006F088->unk_60.lookat->l & 0x1FFFFFFF);

        gSPPerspNormalize(gDisplayListHead++, D_8006F088->unk_24.perspNorm);

        gSPMatrix(gDisplayListHead++, (u32)D_8006F088->unk_24.mtx & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(gDisplayListHead++, (u32)D_8006F088->unk_60.p_mtxf & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

        func_800138F0(arg0);
    }
}

void func_80013AF8(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_alt2* arg = (unk_D_86002F34_alt2*)arg0;
    unk_D_86002F34_00C_018* ptr = &D_8006F088->unk_18;

    func_800065B4(&gDisplayListHead, ptr->x, ptr->y, ptr->width, ptr->height, arg->unk_18);

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
}

void func_80013B8C(UNUSED unk_D_86002F34_000* arg0) {
    unk_D_86002F34_00C_018* ptr = &D_8006F088->unk_18;

    func_800067E4(&gDisplayListHead, ptr->x, ptr->y, ptr->width, ptr->height);

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);
}

void func_80013C14(UNUSED unk_D_86002F34_000* arg0) {
}

void func_80013C1C(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_alt3* arg = (unk_D_86002F34_alt3*)arg0;

    D_8006F090->unk_1D = 1;
    D_8006F090->unk_20 = arg->unk_1C;

    gSPFogPosition(gDisplayListHead++, arg->unk_18, arg->unk_1A);
    gSPSetGeometryMode(gDisplayListHead++, G_FOG);
    gDPSetColor(gDisplayListHead++, G_SETFOGCOLOR, arg->unk_1C);
}

#ifdef NON_MATCHING
void func_80013D34(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_alt4* arg = (unk_D_86002F34_alt4*)arg0;
    Lights7* lights;
    unk_D_86002F34_alt1* new_var;
    Light* light;
    Ambient* temp_a4;

    if (D_8006F090->unk_1C >= 7) {
        // light = &lights->l[D_8006F090->unk_1C];
        return;
    }

    new_var = D_8006F090;
    lights = new_var->lights;
    temp_a4 = &lights->a;

    light = &lights->l[D_8006F090->unk_1C];

    *(u32*)light->l.col = arg->unk_18.rgba;
    *(u32*)light->l.colc = arg->unk_18.rgba;

    light->l.dir[0] = (120.0f * COSS(arg->unk_1C)) * SINS(arg->unk_1E);
    light->l.dir[1] = (120.0f) * SINS(arg->unk_1C);
    light->l.dir[2] = (120.0f * COSS(arg->unk_1C)) * COSS(arg->unk_1E);

    temp_a4->l.col[0] += ((arg->unk_18.r * arg->unk_18.a) / 100);
    if (temp_a4->l.col[0] > 0xFF) {
        temp_a4->l.col[0] = 0xFF;
    }

    temp_a4->l.col[1] += ((arg->unk_18.g * arg->unk_18.a) / 100);
    if (temp_a4->l.col[1] > 0xFF) {
        temp_a4->l.col[1] = 0xFF;
    }

    temp_a4->l.col[2] += ((arg->unk_18.b * arg->unk_18.a) / 100);
    if (temp_a4->l.col[2] > 0xFF) {
        temp_a4->l.col[2] = 0xFF;
    }

    D_8006F090->unk_1C++;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/12D80/func_80013D34.s")
#endif

void func_80013F7C(UNUSED unk_D_86002F34_000* arg0) {
}

void func_80013F84(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_alt4* arg = (unk_D_86002F34_alt4*)arg0;
    s32 i;
    Lights7* lights;

    lights = D_8006F090->lights;
    if ((arg->unk_18.r == 0xFF) && (arg->unk_18.g == 0xFF) && (arg->unk_18.b == 0xFF)) {
        lights->a.l.colc[0] = lights->a.l.col[0];
        lights->a.l.colc[1] = lights->a.l.col[1];
        lights->a.l.colc[2] = lights->a.l.col[2];
    } else {
        lights->a.l.colc[0] = lights->a.l.col[0] = arg->unk_18.r;
        lights->a.l.colc[1] = lights->a.l.col[1] = arg->unk_18.g;
        lights->a.l.colc[2] = lights->a.l.col[2] = arg->unk_18.b;
    }

    gSPSetGeometryMode(gDisplayListHead++, G_LIGHTING);
    gMoveWd(gDisplayListHead++, 2, 0, D_8006F090->unk_1C * 0x18);

    for (i = 0; i < D_8006F090->unk_1C; i++) {
        gSPLight(gDisplayListHead++, &D_8006F090->lights->l[i], i + 1);
    }

    gSPLight(gDisplayListHead++, D_8006F090->lights, i + 1);
}

void func_80014124(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_alt11* arg = (unk_D_86002F34_alt11*)arg0;
    MtxF* temp_v0 = &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0];
    Vec3f sp2C;
    Vec3s sp24;

    if (D_8006F09C->unk_000.unk_02 & 2) {
        func_8000E88C(&sp2C, temp_v0->xw, 0.0f, temp_v0->zw);
        func_8000EB70(&sp24, 0, D_8006F09C->unk_01E.y, 0);
        func_8000F2C4(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 + 1], &sp2C, &sp24);

        D_800AA8C8.unk_10A0++;

        func_800121C8();
        func_800160E0(0, D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0]);
        func_80016274(D_1002590, 1);

        D_800AA8C8.unk_10A0--;
    }

    D_8006F0A0 = arg;
    func_80013330(arg0);
    D_8006F0A0 = NULL;
}

void func_80014214(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_alt3* arg = (unk_D_86002F34_alt3*)arg0;
    MtxF* mtx2 = &D_8006F088->unk_60.mtxf;
    f32 a = D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0].mf[3][0];
    f32 b = D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0].mf[3][1];
    f32 c = D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0].mf[3][2];
    s16 temp_ft5 = ((a * mtx2->mf[0][2]) + (b * mtx2->mf[1][2]) + (c * mtx2->mf[2][2])) + mtx2->mf[3][2];

    if ((temp_ft5 >= arg->unk_18) && (temp_ft5 < arg->unk_1A)) {
        func_80013330(arg0);
    }
}

void func_800142BC(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_alt3* arg = (unk_D_86002F34_alt3*)arg0;
    s32 i;
    unk_D_86002F34_000* var_a1 = arg->unk_00.unk_0C;

    if (var_a1 != NULL) {
        for (i = 0; i < arg->unk_1A; i++) {
            var_a1 = var_a1->unk_08;
        }
    }

    if (var_a1->unk_01 & 1) {
        D_8006F0A4[var_a1->unk_00](var_a1);
    }
}

void func_80014334(unk_D_86002F34_000* arg0) {
    MtxF sp20;
    unk_D_86002F34_alt5* arg = (unk_D_86002F34_alt5*)arg0;

    func_8000F2C4(&sp20, &arg->unk_18, &arg->unk_24);
    func_800122B4(&sp20);
    func_80013330(arg0);

    D_800AA8C8.unk_10A0--;
}

void func_80014384(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_alt5* arg = (unk_D_86002F34_alt5*)arg0;

    func_80012344(&arg->unk_18);
    func_80013330(arg0);

    D_800AA8C8.unk_10A0--;
}

void func_800143C0(unk_D_86002F34_000* arg0) {
    Vec3s sp90;
    Vec3f sp84;
    Vec3f sp78;
    MtxF sp38;
    unk_D_86002F34_alt6* arg = (unk_D_86002F34_alt6*)arg0;
    s32 sp30;

    sp30 = 0;
    sp90 = arg->unk_1E;
    sp78 = arg->unk_24;

    func_8000E990(&sp84, &arg->unk_18);
    func_800171A8(&sp84, &sp90, &sp78, arg->unk_32 * 3);

    if (arg->unk_31 & 2) {
        func_80010228(&sp38, &sp84, &sp90, &sp78, &D_8006F088->unk_60.mtxf, &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
        D_800AA8C8.unk_10A0++;
        func_80012230(&sp38);
    } else if (arg->unk_31 & 1) {
        func_8000F5A8(&sp38, &sp84, &sp90, &sp78);
        func_800122B4(&sp38);
    } else {
        func_8000F730(&sp38, &sp84, &sp90, &D_800AB970.unk_000[D_800AB970.unk_180]);

        D_800AA8C8.unk_10A0++;

        func_80012458(&sp78);
        if (D_800AA8C8.unk_1080[D_800AA8C8.unk_10A0 - 1] == 1) {
            func_8000FBB0(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 + 32], &sp38,
                          &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 + 31]);
        } else {
            func_8000FBB0(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 + 32], &sp38,
                          &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 - 1]);
        }
        func_8000FDE4(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0], &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 + 32],
                      &D_800AB970.unk_000[D_800AB970.unk_180]);
        func_800121C8();
        D_800AA8C8.unk_1080[D_800AA8C8.unk_10A0] = 1;
        sp30 = 1;
    }

    D_800AA6C8[arg->unk_30] = D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0];
    func_80013330(arg0);
    D_800AA6C8[arg->unk_30] = NULL;
    D_800AA8C8.unk_10A0--;

    if (sp30 != 0) {
        D_800AB970.unk_180--;
    }
}

void func_80014624(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_alt7* arg = (unk_D_86002F34_alt7*)arg0;

    if (arg->unk_18 != NULL) {
        func_800160E0(arg->unk_00.unk_03, D_800AA6C8[arg->unk_1C]);
        func_80016274(arg->unk_18, (arg->unk_00.unk_02 & 4) != 0);
    }

    func_80013330(arg0);
}

void func_80014690(unk_D_86002F34_000* arg0) {
    MtxF sp38;
    Color_RGBA8_u32 sp34;
    unk_D_86002F58_004_000* arg = (unk_D_86002F58_004_000*)arg0;

    if (D_8006F090->unk_18 == arg->unk_018) {
        arg->unk_0A7 = 0;
        func_80017090(&arg->unk_040, D_8006F084, (arg->unk_000.unk_02 & 0x20) != 0);
        func_800175E8(&arg->unk_054, D_8006F084, (arg->unk_000.unk_02 & 0x20) != 0);

        if (arg->unk_000.unk_02 & 0x10) {
            func_8000FBB0(&sp38, &arg->unk_060, &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
        } else if (arg->unk_000.unk_02 & 8) {
            func_8000F88C(&sp38, &D_8006F088->unk_60.mtxf, &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0], &arg->unk_024,
                          1.0f);
        } else if (arg->unk_000.unk_02 & 0x80) {
            func_8000F3FC(&sp38, &arg->unk_024, &arg->unk_01E);
            func_8000FBB0(&sp38, &sp38, &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
        } else {
            func_8000F2C4(&sp38, &arg->unk_024, &arg->unk_01E);
            func_8000FBB0(&sp38, &sp38, &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0]);
        }

        func_8000FDE4(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 + 1], &sp38, &arg->unk_030);

        if (!(arg->unk_000.unk_02 & 4)) {
            D_800AA8C8.unk_10A0++;

            func_800121C8();
            D_8006F09C = arg0;

            func_80016344(arg->unk_0A0, arg->unk_01D, arg->unk_01C);

            if ((D_8006F08C->unk_18 < 0) && (arg->unk_01A > 0)) {
                func_80032670(arg->unk_0A6, arg->unk_01A);
                func_80013330(arg0);
                func_80032738(arg->unk_0A6, arg->unk_01A);
            } else {
                func_80013330(arg0);
            }

            sp34.rgba = 0xFFFFFF00;
            func_80016344(sp34, 0xFF, 0);
            D_8006F09C = NULL;
        }

        func_80017188();
        func_800176BC();
        D_800AA8C8.unk_10A0 -= 1;
    }
}

void func_800148D8(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_alt8* arg = (unk_D_86002F34_alt8*)arg0;

    func_800122B4(&arg->unk_1C);

    if ((arg->unk_18 != NULL) || (arg->unk_00.unk_10 != NULL)) {
        func_800160E0(arg->unk_00.unk_03, D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0]);
        if (arg->unk_00.unk_10 != NULL) {
            arg->unk_00.unk_10(5, arg0);
        }
        func_80016274(arg->unk_18, (arg->unk_00.unk_02 & 4) != 0);
    }
    func_80013330(arg0);
    D_800AA8C8.unk_10A0--;
}

void func_80014980(unk_D_86002F34_000* arg0) {
    MtxF sp30;
    unk_D_86002F34_alt9* arg = (unk_D_86002F34_alt9*)arg0;

    func_8000F88C(&sp30, &D_8006F088->unk_60.mtxf, &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0], &arg->unk_1C,
                  arg->unk_28);
    D_800AA8C8.unk_10A0++;
    func_80012230(&sp30);

    if ((arg->unk_18 != NULL) || (arg->unk_00.unk_10 != NULL)) {
        func_800160E0(arg->unk_00.unk_03, D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0]);
        if (arg->unk_00.unk_10 != NULL) {
            arg->unk_00.unk_10(5, arg0);
        }
        func_80016274(arg->unk_18, (arg->unk_00.unk_02 & 4) != 0);
    }

    func_80013330(arg0);
    D_800AA8C8.unk_10A0--;
}

void func_80014A60(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_alt9* arg = (unk_D_86002F34_alt9*)arg0;

    if ((arg->unk_18 != NULL) || (arg->unk_00.unk_10 != NULL)) {
        func_800160E0(arg->unk_00.unk_03, D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0]);
        if (arg->unk_00.unk_10 != NULL) {
            arg->unk_00.unk_10(5, arg0);
        }
        func_80016274(arg->unk_18, (arg->unk_00.unk_02 & 4) != 0);
    }
    func_80013330(arg0);
}

void func_80014AEC(unk_D_86002F34_000* arg0) {
    Color_RGBA8_u32 sp44;
    unk_D_86002F34_alt10* arg = (unk_D_86002F34_alt10*)arg0;
    unk_D_86002F34_alt11_018* sp3C;
    unk_D_86002F34_alt11_018* sp38;
    s32 sp34;

    sp3C = NULL;
    sp38 = NULL;
    sp34 = arg->unk_18;

    if (arg->unk_22 == 1) {
        sp44.rgba = 0xFFFFFFFF;
    } else {
        sp44.rgba = arg->unk_24.rgba;
    }

    if (arg->unk_1C >= 0) {
        sp3C = &D_8006F0A0->unk_18[arg->unk_1C];
    }

    if (arg->unk_1E >= 0) {
        sp38 = &D_8006F0A0->unk_1C[arg->unk_1E];
    }

    if (D_8006F09C != NULL) {
        sp44.r = (sp44.r * D_8006F09C->unk_03C.r) / 255;
        sp44.g = (sp44.g * D_8006F09C->unk_03C.g) / 255;
        sp44.b = (sp44.b * D_8006F09C->unk_03C.b) / 255;
    }

    func_800176DC(&sp3C, D_8006F0A0->unk_18, arg->unk_20);
    func_80016364(arg->unk_22, sp44, sp3C, sp38, sp34);
    func_80013330(arg0);
}

void func_80014CB8(s32 arg0) {
    MtxF* temp_a1;
    unk_D_86002F58_004_000_0A8* ptr;

    if (D_8006F09C != NULL) {
        if (D_8006F09C->unk_0A7 < 0xC) {
            ptr = &D_8006F09C->unk_0A8[D_8006F09C->unk_0A7++];
            temp_a1 = &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0];

            ptr->unk_00 = arg0;
            ptr->unk_04.x = temp_a1->mf[3][0];
            ptr->unk_04.y = temp_a1->mf[3][1];
            ptr->unk_04.z = temp_a1->mf[3][2];
        }
    }
}

void func_80014D24(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_alt3* arg = (unk_D_86002F34_alt3*)arg0;

    func_80014CB8(arg->unk_18);
    func_80013330(arg0);
}

void func_80014D50(unk_D_86002F34_000* arg0) {
    func_80013330(arg0);
}

void func_80014D70(unk_D_86002F34_000* arg0) {
    Vec3f sp9C;
    Vec3f sp90;
    Vec3f sp84;
    f32 sp80;
    MtxF sp40;
    MtxF* sp3C;
    unk_D_86002F34_alt12* arg = (unk_D_86002F34_alt12*)arg0;
    Gfx* temp_s1;

    sp3C = &D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0];
    temp_s1 = func_80005F5C(sizeof(Gfx) * 2);

    if (func_80015390(D_8006F09C, 0x64, NULL) == 0) {
        func_80014CB8(0x64);
    }

    func_8000E88C(&sp9C, sp3C->mf[3][0], sp3C->mf[3][1] + arg->unk_1E, sp3C->mf[3][2]);
    sp9C.y = 0.0f;

    if (D_8006F09C->unk_000.unk_02 & 0x40) {
        func_8000E88C(&sp90, 0.0f, 1.0f, 0.0f);
        func_8000FF04(sp3C, &sp84);

        sp80 = 1.0f - ((sp3C->mf[3][1] - sp9C.y) / 1000.0f);
        if (sp80 < 0.5f) {
            sp80 = 0.5f;
        }

        if (sp80 > 1.0f) {
            sp80 = 1.0f;
        }

        sp84.x *= (arg->unk_1A / 100.0f) * sp80;
        sp84.z *= (arg->unk_1C / 100.0f) * sp80;
        func_8000FA94(&sp40, &sp90, &sp9C, D_8006F09C->unk_01E.y);
        func_8000FDE4(&D_800AA8C8.unk_0000[D_800AA8C8.unk_10A0 + 1], &sp40, &sp84);

        D_800AA8C8.unk_10A0++;
        func_800121C8();

        if (arg->unk_18 == 0) {
            gSPBranchList(&temp_s1[1], Util_ConvertAddrToVirtAddr(D_1002480));
        } else {
            gSPBranchList(&temp_s1[1], Util_ConvertAddrToVirtAddr(D_1002508));
        }
        gDPSetEnvColor(&temp_s1[0], 0, 0, 0, (s32)(150.0f * sp80));

        if (D_8006F09C->unk_000.unk_02 & 2) {
            func_800160E0(6, D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0]);
        } else {
            func_800160E0(5, D_800AA8C8.unk_1000[D_800AA8C8.unk_10A0]);
        }

        gDPSetFogColor(gDisplayListHead++, 255, 255, 255, 0);
        gDPSetPrimColor(gDisplayListHead++, 0, D_8006F09C->unk_01D, 255, 255, 255, 255);

        func_80016274((u32)temp_s1 & 0x1FFFFFFF, 1);
        func_80013330(arg0);

        D_800AA8C8.unk_10A0--;
    }
}

void func_80015094(unk_D_86002F34_000* arg0) {
    unk_D_86002F34_alt1* arg = (unk_D_86002F34_alt1*)arg0;

    if (arg0->unk_01 & 1) {
        gDPPipeSync(gDisplayListHead++);

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

        D_8006F08C = arg;
        func_80013330(arg0);
        D_8006F08C = NULL;
    }

    D_8006F080 = 0;
}

void func_80015220(unk_D_86002F34_000* arg0, s32 arg1) {
    unk_D_86002F34_000* var_s1 = arg0;
    unk_D_86002F34_000** var_s0;

    do {
        if (var_s1->unk_10 != NULL) {
            var_s1->unk_10(arg1, var_s1);
        }

        if (var_s1->unk_0C != NULL) {
            switch (var_s1->unk_00) {
                default:
                    var_s0 = NULL;
                    break;

                case 2:
                    var_s0 = &D_8006F088;
                    break;

                case 4:
                    var_s0 = &D_8006F090;
                    break;

                case 6:
                    var_s0 = &D_8006F098;
                    break;

                case 0x16:
                    var_s0 = &D_8006F09C;
                    break;
            }

            if (var_s0 != NULL) {
                *var_s0 = var_s1;
            }

            func_80015220(var_s1->unk_0C, arg1);

            if (var_s0 != NULL) {
                *var_s0 = NULL;
            }
        }

        var_s1 = var_s1->unk_08;
    } while (var_s1 != arg0);
}

void func_8001533C(s32 arg0) {
    D_8006F080 = arg0;
}

void func_80015348(void) {
    D_8006F084++;
}

s32 func_80015360(void) {
    s32 var_v1 = 1;

    if (D_8006F090 != NULL) {
        var_v1 = D_8006F090->unk_1A == D_8006F084;
    }
    return var_v1;
}

Vec3f* func_80015390(unk_D_86002F58_004_000* arg0, s16 arg1, Vec3f* arg2) {
    s32 i;
    s32 var_v0;
    u8 temp_v1;
    unk_D_86002F58_004_000* var_a2;

    for (i = 0; i < arg0->unk_0A7; i++) {
        if (arg1 == arg0->unk_0A8[i].unk_00) {
            if (arg2 != NULL) {
                *arg2 = arg0->unk_0A8[i].unk_04;
            }
            return &arg0->unk_0A8[i].unk_04;
        }
    }

    return NULL;
}

void func_80015400(Gfx* arg0, arg1_func_81407874_014_000_010* arg1) {
    gDPSetCombine(arg0++,
                  GCCc0w0(arg1->unk_00, arg1->unk_02, arg1->unk_04, arg1->unk_06) | GCCc1w0(arg1->unk_08, arg1->unk_0A),

                  GCCc0w1(arg1->unk_01, arg1->unk_03, arg1->unk_05, arg1->unk_07) |
                      GCCc1w1(arg1->unk_09, arg1->unk_0C, arg1->unk_0E, arg1->unk_0B, arg1->unk_0D, arg1->unk_0F));
}

void func_8001550C(void) {
    if (D_800ABB08 == 0) {
        D_800ABB08 = 1;

        gDPPipeSync(gDisplayListHead++);
    }
}

void func_8001554C(void) {
    s32 var_v0 = D_8006F124[D_800ABB00][D_800ABCB8->unk_24];

    D_800ABB08 = 1;

    gDPPipeSync(gDisplayListHead++);

    D_800ABCB8->unk_14.rgba = 0x00000000;

    gDPSetColor(gDisplayListHead++, G_SETFOGCOLOR, D_8006F090->unk_20);

    if ((D_800ABB04 & 1) && (D_800ABB00 == 1) && (D_800ABCB8->unk_24 == 5)) {
        var_v0 = 0x107A58;
    }

    if (D_8006F090->unk_1D != 0) {
        gDPSetRenderMode(gDisplayListHead++, var_v0, 0xC8000000);
    } else {
        gDPSetRenderMode(gDisplayListHead++, var_v0, 0x0C080000);
    }
}

void func_80015684(void) {
    Color_RGBA8_u32 sp1C;

    sp1C.rgba = D_800ABCB8->unk_10.rgba;

    D_800ABCB8->unk_18 = NULL;
    D_800ABCB8->unk_1C = NULL;
    D_800ABCB8->unk_0C = NULL;
    D_800ABCB8->unk_27 = 0;
    D_800ABB08 = 1;

    gDPPipeSync(gDisplayListHead++);
    gDPSetPrimColor(gDisplayListHead++, 0, D_800ABCB8->unk_26, sp1C.r, sp1C.g, sp1C.b, sp1C.a);
    gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);

    func_80015400(gDisplayListHead++, D_8006F1B4[D_800ABCB8->unk_25]);

    gSPSetGeometryMode(gDisplayListHead++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gSPClearGeometryMode(gDisplayListHead++, G_FOG | G_TEXTURE_GEN);

    gSPLookAt(gDisplayListHead++, (u32)&D_8006F088->unk_60.lookat->l & 0x1FFFFFFF);

    if (D_8006F090->unk_1D != 0) {
        gSPSetGeometryMode(gDisplayListHead++, G_FOG);
    }
}

void func_8001587C(unk_D_800ABB10* arg0) {
    if (arg0->unk_08.rgba != D_800ABCB8->unk_14.rgba) {
        func_8001550C();

        gDPSetColor(gDisplayListHead++, G_SETFOGCOLOR, arg0->unk_08.rgba);
        gDPSetRenderMode(gDisplayListHead++, D_8006F124[D_800ABB00][D_800ABCB8->unk_24], 0xC4000000);

        D_800ABCB8->unk_14.rgba = arg0->unk_08.rgba;
    }
}

void func_80015948(UNUSED unk_D_800ABB10* arg0) {
    if (D_800ABCB8->unk_14.rgba & 0xFF) {
        func_8001554C();
    }
}

void func_80015984(unk_D_800ABB10* arg0) {
    if ((arg0->unk_04.rgba != D_800ABCB8->unk_10.rgba) || (arg0->unk_01 != D_800ABCB8->unk_26)) {
        func_8001550C();

        gDPSetPrimColor(gDisplayListHead++, 0, arg0->unk_01, arg0->unk_04.r, arg0->unk_04.g, arg0->unk_04.b,
                        arg0->unk_04.a);

        D_800ABCB8->unk_10.rgba = arg0->unk_04.rgba;
        D_800ABCB8->unk_26 = arg0->unk_01;
    }
}

void func_80015A44(unk_D_800ABB10* arg0) {
    if (arg0->unk_00 != D_800ABCB8->unk_25) {
        func_8001550C();
        func_80015400(gDisplayListHead++, D_8006F1B4[arg0->unk_00]);
        D_800ABCB8->unk_25 = arg0->unk_00;
    }
}

void func_80015AC4(UNUSED unk_D_800ABB10* arg0) {
    if (D_800ABCB8->unk_18 != NULL) {
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    }

    D_800ABCB8->unk_18 = NULL;
    D_800ABCB8->unk_1C = NULL;
    D_800ABCB8->unk_20 = NULL;
}

void func_80015B20(unk_D_800ABB10* arg0) {
    unk_D_86002F34_alt11_018* temp_t0;
    s32 var_a3;

    if (D_800ABCB8->unk_18 == NULL) {
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    }

    if ((arg0->unk_0C != D_800ABCB8->unk_18) || (arg0->unk_14 != D_800ABCB8->unk_20)) {
        temp_t0 = arg0->unk_0C;

        if (arg0->unk_10 != NULL) {
            gSPDisplayList(gDisplayListHead++, arg0->unk_10->unk_08);
        } else {
            gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
        }

        if (temp_t0->unk_01 == 0) {
            if ((temp_t0->unk_02 % D_8006F2A4[0]) == 0) {
                gDPSetTextureImage(gDisplayListHead++, temp_t0->fmt, G_IM_SIZ_16b, 1, temp_t0->texture);
            } else {
                gDPSetTextureImage(gDisplayListHead++, temp_t0->fmt, G_IM_SIZ_8b, temp_t0->unk_02 >> 1,
                                   temp_t0->texture);
            }
        } else if ((temp_t0->unk_02 % D_8006F2A4[temp_t0->unk_01]) == 0) {
            if (temp_t0->unk_01 == 3) {
                var_a3 = 3;
            } else {
                var_a3 = 2;
            }

            gDPSetTextureImage(gDisplayListHead++, temp_t0->fmt, var_a3, 1, temp_t0->texture);
        } else {
            gDPSetTextureImage(gDisplayListHead++, temp_t0->fmt, temp_t0->unk_01, temp_t0->unk_02, temp_t0->texture);
        }

        gSPDisplayList(gDisplayListHead++, arg0->unk_14);
    }

    D_800ABCB8->unk_18 = arg0->unk_0C;
    D_800ABCB8->unk_1C = arg0->unk_10;
    D_800ABCB8->unk_20 = arg0->unk_14;
}

void func_80015DD8(UNUSED unk_D_800ABB10* arg0) {
    if (D_800ABCB8->unk_27 == 0) {
        gDPLoadTextureBlock(gDisplayListHead++, D_1001800, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 1, 1);
        gSPTexture(gDisplayListHead++, 0x1194, 0x1194, 0, G_TX_RENDERTILE, G_ON);

        gSPSetGeometryMode(gDisplayListHead++, G_TEXTURE_GEN);
        gSPClearGeometryMode(gDisplayListHead++, G_TEXTURE_GEN_LINEAR);
        gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIDECALA, G_CC_PASS2);

        D_800ABCB8->unk_27 = 1;
    }
}

void func_80015F64(s16 arg0) {
    if (arg0 == D_800ABCBC) {
        return;
    }

    D_800ABCB8->unk_08 = gDisplayListHead;

    gSPBranchList(gDisplayListHead++, NULL);

    D_800ABCBC = arg0;
    D_800ABCB8 = &D_800ABB28[D_800ABCBC];

    if (D_800ABCB8->unk_04 == NULL) {
        D_800ABCB8->unk_04 = gDisplayListHead;
    } else if (D_800ABCB8->unk_08 != NULL) {
        gSPBranchList(D_800ABCB8->unk_08, gDisplayListHead);
    }
}

void func_80016010(s16 arg0) {
    if (((arg0 > 0) && (arg0 < 4)) || (arg0 == 0x84) || (arg0 == 6)) {
        D_800ABB10.unk_03 = D_800ABB10.unk_02;
    } else {
        D_800ABB10.unk_03 = 0;
    }
}

s16 func_80016060(s16 arg0) {
    s16 var_v1 = arg0 & 0xF;

    if (D_800ABB10.unk_01 < 0xFF) {
        switch (var_v1) {
            case 1:
                var_v1 = 8;
                break;
            case 2:
                var_v1 = 6;
                break;
            case 3:
                var_v1 = 7;
                break;
            case 4:
                var_v1 = 5;
                break;
        }
    }

    return var_v1;
}

void func_800160E0(s16 arg0, MtxF* arg1) {
    if ((D_8006F120 != 0) && !(D_800ABB04 & 2) && (D_800ABB10.unk_01 > 0)) {
        func_80016010(arg0);
        func_80015F64(func_80016060(arg0));
        D_800ABB08 = 0;

        if (D_800ABCB8->unk_00 == 0) {
            func_8001554C();
            func_80015684();
            D_800ABCB8->unk_00 = 1;
        }

        if (D_800ABB10.unk_08.rgba & 0xFF) {
            func_8001587C(&D_800ABB10);
        } else {
            func_80015948(&D_800ABB10);
        }

        if (D_800ABB10.unk_03 != 0) {
            func_80015DD8(&D_800ABB10);
        } else {
            if (D_800ABCB8->unk_27 == 1) {
                func_80015684();
            }

            if (D_800ABB10.unk_0C != 0) {
                func_80015B20(&D_800ABB10);
            } else {
                func_80015AC4(&D_800ABB10);
            }

            func_80015984(&D_800ABB10);
            func_80015A44(&D_800ABB10);
        }

        if (arg1 != D_800ABCB8->unk_0C) {
            D_800ABCB8->unk_0C = arg1;
            gSPMatrix(gDisplayListHead++, (u32)arg1 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        }
    }
}

void func_80016274(Gfx* arg0, s32 arg1) {
    if ((D_8006F120 != 0) && !(D_800ABB04 & 2) && (D_800ABB10.unk_01 > 0)) {
        if (arg0 != NULL) {
            if (((u32)arg0 >= 0x81000000) && ((u32)arg0 < 0x90000000)) {
                gSPDisplayList(gDisplayListHead++, Memmap_GetFragmentVaddr((u32)arg0));
            } else {
                gSPDisplayList(gDisplayListHead++, arg0);
            }
        }

        if (arg1 != 0) {
            func_80015684();
        }
    }
}

void func_80016344(Color_RGBA8_u32 arg0, u8 arg1, u32 arg2) {
    D_800ABB10.unk_08.rgba = arg0.rgba;
    D_800ABB10.unk_01 = arg1;
    D_800ABB10.unk_02 = arg2;
}

void func_80016364(s32 arg0, Color_RGBA8_u32 arg1, unk_D_86002F34_alt11_018* arg2, unk_D_86002F34_alt11_018* arg3,
                   s32 arg4) {
    D_800ABB10.unk_00 = arg0;
    D_800ABB10.unk_04.rgba = arg1.rgba;
    D_800ABB10.unk_0C = arg2;
    D_800ABB10.unk_10 = arg3;
    D_800ABB10.unk_14 = arg4;
}

void func_8001638C(s32 arg0, s32 arg1) {
    s32 i;
    unk_D_800ABB28* ptr = D_800ABB28;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_2CYCLE);

    if (arg0 & 1) {
        gSPSetGeometryMode(gDisplayListHead++, G_ZBUFFER);
    } else {
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER);
    }

    for (i = 0; i < 10; i++, ptr++) {
        ptr->unk_04 = NULL;
        ptr->unk_08 = NULL;

        ptr->unk_00 = 0;
        ptr->unk_0C = 0;

        ptr->unk_10.rgba = 0xFFFFFFFF;
        ptr->unk_14.rgba = 0xFFFFFF00;

        ptr->unk_18 = NULL;
        ptr->unk_1C = NULL;
        ptr->unk_20 = NULL;

        ptr->unk_24 = i;
        ptr->unk_25 = 0;
        ptr->unk_27 = 0;
        ptr->unk_26 = 0xFF;
    }

    D_800ABB10.unk_00 = 0;
    D_800ABB10.unk_01 = 0xFF;
    D_800ABB10.unk_02 = 0;
    D_800ABB10.unk_03 = 0;
    D_800ABB10.unk_04.rgba = -1;
    D_800ABB10.unk_08.rgba = 0xFFFFFF00;
    D_800ABB10.unk_0C = 0;
    D_800ABB10.unk_10 = 0;
    D_800ABB10.unk_14 = 0;

    D_800ABB00 = arg0;
    D_800ABB04 = arg1;

    D_800ABB28[0].unk_04 = gDisplayListHead;

    D_800ABCBC = 0;
    D_800ABCB8 = D_800ABB28;

    D_8006F120 = 1;
}

void func_8001660C(void) {
    s32 sp1C = 0;
    Gfx* temp_t0;
    s32 temp_v0;

    func_80015F64(9);

    if (D_800ABB28[0].unk_08 != NULL) {
        while (sp1C < 9) {
            temp_v0 = sp1C + 1;
            temp_t0 = D_800ABB28[sp1C].unk_08;
            sp1C++;

            while (D_800ABB28[temp_v0].unk_04 == NULL) {
                temp_v0 = sp1C + 1;
                sp1C++;
            }

            gSPBranchList(temp_t0, D_800ABB28[sp1C].unk_04);
        }
    }

    func_80015684();

    if (D_800ABB00 & 1) {
        gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER);
    }

    D_8006F120 = 0;
}
