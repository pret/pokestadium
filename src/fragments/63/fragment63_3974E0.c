#include "fragment63.h"
#include "src/1CF30.h"
#include "src/6A40.h"
#include "src/math_util.h"

s16 func_84B033E0(void) {
    f32 temp_fv0 = MathUtil_Random_ZeroOne();

    if (temp_fv0 >= 0.5f) {
        temp_fv0 = (temp_fv0 - 0.5f) * 4000.0f;
    } else {
        temp_fv0 = (temp_fv0 - 0.5f) * 4000.0f;
    }
    return temp_fv0;
}

void func_84B0345C(unk_D_84B19910* arg0) {
    Vtx* temp_v0_12;
    s32 i;
    unk_D_84B19910_002* ptr2;

    gDPPipeSync(gDisplayListHead++);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BACK);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_PASS2);
    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPLoadTextureBlock(gDisplayListHead++, D_3024A00, G_IM_FMT_IA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    for (i = 0; i < 400; i++) {
        temp_v0_12 = func_80005F5C(sizeof(Vtx) * 4);
        if (temp_v0_12 != NULL) {
            ptr2 = &(i + ((void)0, arg0))->unk_02;
            func_8001E680(&temp_v0_12[0], ptr2->unk_00 - 8, ptr2->unk_02 + 8, ptr2->unk_04, 0, 0, 0xFF, 0xFF, 0x96,
                          0xFF);
            func_8001E680(&temp_v0_12[1], ptr2->unk_00 - 8, ptr2->unk_02 - 8, ptr2->unk_04, 0, 0x400, 0xFF, 0xFF, 0x96,
                          0xFF);
            func_8001E680(&temp_v0_12[2], ptr2->unk_00 + 8, ptr2->unk_02 - 8, ptr2->unk_04, 0x400, 0x400, 0xFF, 0xFF,
                          0x96, 0xFF);
            func_8001E680(&temp_v0_12[3], ptr2->unk_00 + 8, ptr2->unk_02 + 8, ptr2->unk_04, 0x400, 0, 0xFF, 0xFF, 0x96,
                          0xFF);

            gSPVertex(gDisplayListHead++, temp_v0_12, 4, 0);
            gSP2Triangles(gDisplayListHead++, 0, 1, 2, 0, 0, 2, 3, 0);
        }
    }

    gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void func_84B03814(unk_D_84B19910* arg0) {
    s32 temp_s0;
    s32 temp_v0;
    s32 i;

    for (i = 0; i < 400; i++) {
        arg0[i].unk_02.unk_04 += 0x64;
        if (arg0[i].unk_02.unk_04 > 0) {
            do {
                temp_s0 = func_84B033E0();
                temp_v0 = func_84B033E0();
            } while ((SQ(temp_s0) + SQ(temp_v0)) < 0x6400);

            arg0[i].unk_02.unk_00 = temp_s0;
            arg0[i].unk_02.unk_02 = temp_v0;
            arg0[i].unk_02.unk_04 = (-MathUtil_Random_ZeroOne() * 500.0f) - 5000.0f;
        }
    }
}

void func_84B038F8(unk_D_84B19910* arg0) {
    s32 temp_s0;
    s32 temp_v0;
    s32 i;

    for (i = 0; i < 400; i++) {
        do {
            temp_s0 = func_84B033E0();
            temp_v0 = func_84B033E0();
        } while ((SQ(temp_s0) + SQ(temp_v0)) < 0x6400);

        arg0[i].unk_02.unk_00 = temp_s0;
        arg0[i].unk_02.unk_02 = temp_v0;
        arg0[i].unk_02.unk_04 = (-MathUtil_Random_ZeroOne() * 5000.0f) - 100.0f;
        arg0[i + 1].unk_00 = (MathUtil_Random_ZeroOne() * 10.0f) + 20.0f;
    }
    *(s8*)&arg0->unk_00 = 1;
}
