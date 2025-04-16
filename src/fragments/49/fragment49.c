#include "fragment49.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static s32 D_83A00B70;
static BinArchive* D_83A00B74;
static u8* D_83A00B78;
static s32 D_83A00B7C;
static unk_D_80068BB0* D_83A00B80;

void func_83A00020(void) {
    D_83A00B70 = 0;
    D_83A00B80 = func_80006314(0, 2, 0x280, 0x1E0, 0);
    D_83A00B7C = -1;
}

void func_83A00068(s32 arg0, s32 arg1) {
    u8* img = D_83A00B80->img_p;
    s32 i;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 640, 480);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGB, G_CC_DECALRGB);

    gDPPipeSync(gDisplayListHead++);

    for (i = 0; i < 480; i++) {
        gDPLoadTextureBlock(gDisplayListHead++, img + i * 0x500, G_IM_FMT_RGBA, G_IM_SIZ_16b, 640, 1, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, arg0 << 2, (arg1 + i) << 2, (arg0 + 0x280) << 2, (arg1 + 1 + i) << 2,
                            G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
    }
}

void func_83A0031C(s32 arg0, u8* arg1) {
    static s32 D_83A00B50 = 4;
    static s32 D_83A00B54 = 6;

    UNUSED s32 pad[1];
    s32 j;
    s32 i;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    f32 divisor = 0.375f;
    s32 sp34;
    s16 temp_a0;
    s32 temp_ft0;
    s32 tmp1;
    s32 tmp2;

    sp48 = arg0 % 4;
    sp44 = arg0 / 4;

    sp40 = ROUND_MAX(320.0f * divisor);
    sp3C = ROUND_MAX(240.0f * divisor);
    temp_ft0 = ROUND_MAX(16.0f * divisor);
    sp34 = ROUND_MAX(16.0f * divisor);
    temp_a0 = ROUND_MAX(1024.0f / divisor);

    tmp2 = ((sp40 + D_83A00B50) * sp48) + ((-(sp40 * 4) - (D_83A00B50 * 3)) + 0x280) / 2;
    tmp1 = ((sp3C + D_83A00B54) * sp44) + ((-(sp3C * 4) - (D_83A00B54 * 3)) + 0x1E0) / 2;

    for (i = 0; i < sp3C; i += sp34) {
        for (j = 0; j < sp40; j += temp_ft0) {
            gDPLoadTextureBlock(gDisplayListHead++, arg1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, (tmp2 + j) << 2, (tmp1 + i) << 2, ((tmp2 + j) + temp_ft0) << 2,
                                ((tmp1 + i) + sp34) << 2, G_TX_RENDERTILE, 0, 0, temp_a0, temp_a0);

            arg1 += 0x200;
        }
    }
}

void func_83A00754(void) {
    static u8 D_83A00B58[] = {
        0x00, 0x11, 0x01, 0x02, 0x04, 0x06, 0x03, 0x0A, 0x0B, 0x07, 0x08, 0x09, 0x0C, 0x10, 0x0F, 0x14,
    };

    if (D_83A00B7C >= 0) {
        main_pool_push_state('mksl');

        D_83A00B78 = func_8000484C(D_83A00B74, D_83A00B58[D_83A00B7C]);
        func_80006498(&gDisplayListHead, D_83A00B80);

        gSPDisplayList(gDisplayListHead++, D_8006F518);
        gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

        func_83A0031C(D_83A00B7C, D_83A00B78);
    }

    func_800079C4();
    func_83A00068(0, 0);
    func_80007778();

    if (D_83A00B7C >= 0) {
        main_pool_pop_state('mksl');
    }
}

s32 func_83A00858(void) {
    s32 var_v1 = 0;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B)) {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_83A00880(void) {
    static s32 D_83A00B68 = 2;

    s32 sp1C = 1;

    switch (D_83A00B70) {
        case 0:
            if (func_80007604() == 0) {
                D_83A00B68--;
                if (D_83A00B68 <= 0) {
                    D_83A00B70 = 1;
                    D_83A00B7C = 0;
                }
            }
            break;

        case 1:
            if (D_83A00B7C >= 0) {
                D_83A00B7C++;
            }

            if (D_83A00B7C >= 0x10) {
                D_83A00B7C = -1;
            }

            if ((D_83A00B7C == -1) && (func_83A00858() != 0)) {
                D_83A00B70 = 2;
                func_80048B90(3);
                func_80006CB4(8);
            }
            break;

        case 2:
            if (func_80007604() == 1) {
                sp1C = 0;
            }
            break;
    }
    return sp1C;
}

void func_83A00990(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_83A009C0(void) {
}

void func_83A009C8(void) {
    func_80006498(&gDisplayListHead, D_83A00B80);
    func_800065B4(&gDisplayListHead, 0, 0, 0x280, 0x1E0, 0xFFFF);
    func_80007778();
    func_80006C6C(8);
    do {
        func_83A00990();
        func_83A00754();
    } while (func_83A00880() != 0);
}

s32 func_83A00A4C(s32 arg0, s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('BNVW');

    func_80005E40(0x10000, 0);
    sp24 = func_80007444(1, 0, 2, 0, 2, 1);
    func_8001E94C(8, 0);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    D_83A00B74 = ASSET_LOAD2(backgrounds, 1, 1);
    func_83A00020();
    func_80007678(sp24);
    func_83A009C8();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('BNVW');

    return 0;
}
