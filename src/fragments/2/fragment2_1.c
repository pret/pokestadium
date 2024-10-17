#include "global.h"
#include "fragment2.h"
#include "src/6A40.h"
#include "src/11BA0.h"
#include "src/1C720.h"
#include "src/math_util.h"

static Gfx D_87806390[] = {
    gsSPEndDisplayList(),
};

u32 D_87806398[] = {
    0x0B00001E, 0x00000000, 0x014000F0, 0x00000000,  0x000016A8, 0x00000190, 0x05000000, 0x0D000000, 0x05000000,
    0x0F000002, 0x05000000, 0x0A000000, &D_800AC858, 0x06000000, 0x06000000, 0x06000000, 0x04000000, 0x00000000,
};

static Vtx D_878063E0[] = {
    VTX(-32, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 16, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 16, 0, 2048, 512, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, 32, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 0, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 0, 0, 2048, 512, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(32, 16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, -16, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -16, 0, 2048, 512, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 0, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-32, -32, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -32, 0, 2048, 512, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, -16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

static u32* D_878064E0[] = { &D_300C000, &D_3000000, 0x3004000, &D_3008000 };

static s16 D_8780FAC0;
static s16 D_8780FAC2;
static s16 D_8780FAC4;
static s16 D_8780FAC6;
static unk_D_86002F58_004_000 D_8780FAC8;
static unk_func_80011B94* D_8780FC30;

void func_87802360(s16 arg0, s16 arg1, f32* arg2, f32* arg3) {
    f32 var_fv0;
    s32 temp_ft1;
    s32 var_v0;

    if (arg1 >= 0x12) {
        var_v0 = 0;
    } else if (arg1 >= 8) {
        var_v0 = 1;
    } else if (arg1 > 0) {
        var_v0 = 2;
    } else {
        var_v0 = 3;
    }

    *arg3 = 0.0f;
    *arg2 = 0.0f;

    switch (var_v0) {
        case 0:
            var_fv0 = 0.5f;
            temp_ft1 = (1.0f - ((0x1B - arg1) / 10.0f)) * (0, 81920.0f);
            if (temp_ft1 <= 0x10000) {
                if (temp_ft1 > 0x10000) {
                    var_fv0 *= .5f;
                } else {
                    var_fv0 *= 0.25f;
                }
            }

            var_fv0 *= ABS(SINS((temp_ft1 & 0xFFFF)));

            *arg3 = 1.0f - var_fv0;
            *arg2 = 1.0f - var_fv0;
            break;

        case 1:
            *arg3 = 1.0f;
            *arg2 = 1.0f;
            break;

        case 2:
            if (arg0 == 0) {
                *arg2 = arg1 / 7.0f;
                if (0.001f < *arg2) {
                    *arg3 = 1.0f / *arg2;
                } else {
                    *arg2 = 0.0f;
                }
            }
            break;
    }
}

void func_87802528(void) {
    MainPoolState* sp1C;

    D_8780FAC4 = 0;
    D_8780FAC0 = 4;
    D_8780FAC2 = 0;
    D_8780FAC6 = 0;

    func_8001BBC8(&D_8780FAC8);
    sp1C = func_80002D10(main_pool_get_available(), 0);
    D_8780FC30 = func_80011B94(sp1C, NULL, 4, D_87806390);
    D_8780FAC8.unk_000.unk_02 |= 8;

    func_80012094(&D_8780FAC8.unk_000, &D_8780FC30->unk_00);
    func_80002D60(sp1C);
}

void func_878025D0(void) {
    s32 i;
    Gfx* temp_v0;
    s32 var_s2;
    u32* temp_s1;
    u32* img;

    var_s2 = 0;
    switch (D_8780FAC4) {
        case 0:
            if (D_8780FAC6 != 0) {
                D_8780FAC6 = 0;
                D_8780FAC4 = 1;
                var_s2 = 1;
                D_8780FAC8.unk_000.unk_01 |= 1;
                D_8780FAC8.unk_030.x = 0.5f;
                D_8780FAC8.unk_030.y = 0.5f;
            }
            break;

        case 1:
            D_8780FAC2 -= 1;
            if (D_8780FAC2 <= 0) {
                D_8780FAC2 = 0x1B;
                D_8780FAC0 -= 1;
            }

            if ((D_8780FAC0 >= 0) && (D_8780FAC0 < 4)) {
                var_s2 = 1;
                func_87802360(D_8780FAC0, D_8780FAC2, &D_8780FAC8.unk_030.x, &D_8780FAC8.unk_030.y);
            } else {
                D_8780FC30->unk_18 = D_87806390;
            }

            if (D_8780FAC0 < 0) {
                D_8780FAC4 = 2;
                D_8780FAC2 = 0x1B;
                D_8780FAC8.unk_000.unk_01 &= ~1;
            }
            break;

        case 2:
            if (D_8780FAC2 == 0x1B) {
                D_8780FAC2 = 0;
            }
            break;
    }

    if ((var_s2 != 0) && (D_8780FAC0 < 4)) {
        temp_s1 = D_878064E0[D_8780FAC0];
        temp_v0 = func_80005F5C(sizeof(Gfx) * 48);
        D_8780FC30->unk_18 = temp_v0;

        gSPSetGeometryMode(&temp_v0[0], G_CULL_BACK);
        gSPTexture(&temp_v0[1], 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gDPPipeSync(&temp_v0[2]);
        gDPSetCombineMode(&temp_v0[3], G_CC_DECALRGBA, G_CC_PASS2);
        gSPVertex(&temp_v0[4], D_878063E0, 16, 0);

        temp_v0 += 5;
        img = temp_s1;

        for (i = 0; i < 4; i++, img += 0x400) {
            gDPLoadTextureTile(temp_v0++, img, G_IM_FMT_RGBA, G_IM_SIZ_32b, 64, 0, 0, 0, 63, 15, 0,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);
            gSP2Triangles(temp_v0++, (i * 4) + 0, (i * 4) + 1, (i * 4) + 2, 0, (i * 4) + 0, (i * 4) + 2, (i * 4) + 3,
                          0);
        }

        gSPEndDisplayList(temp_v0++);
    }
}

void func_8780295C(s16 arg0) {
    D_8780FAC6 = arg0;
}

s32 func_87802974(void) {
    s16 var_v1 = -1;

    if (D_8780FAC4 == 2) {
        var_v1 = -2;
    } else if ((D_8780FAC2 == 0x1B) && (D_8780FAC4 == 1)) {
        var_v1 = D_8780FAC0;
    }

    return var_v1;
}
