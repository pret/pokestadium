#include "fragment75.h"
#include "src/19840.h"
#include "src/1CF30.h"
#include "src/30640.h"
#include "src/3FB0.h"
#include "src/6A40.h"
#include "src/C030.h"
#include "src/dp_intro.h"
#include "src/fragments/43/fragment43.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static BinArchive* D_8FA00A20;
static u8* D_8FA00A24;
static BinArchive* D_8FA00A28;
static unk_func_80007444* D_8FA00A2C;

static u8 D_8FA009F0[] = {
    0x00, 0x11, 0x01, 0x02, 0x04, 0x06, 0x03, 0x0A, 0x0B, 0x07, 0x08, 0x09, 0x0C, 0x10, 0x0F, 0x14,
};
static unk_func_80031270* D_8FA00A00 = NULL;

void func_8FA00020(s32 arg0) {
    func_800079C4();

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetFillColor(gDisplayListHead++, 0xFFFFFFFF);
    gDPFillRectangle(gDisplayListHead++, 0, 445, 639, 479);

    if (arg0 == 3) {
        gDPPipeSync(gDisplayListHead++);

        gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
        gDPSetTextureConvert(gDisplayListHead++, G_TC_FILT);
        gDPSetTextureLOD(gDisplayListHead++, G_TL_TILE);
        gDPSetTextureDetail(gDisplayListHead++, G_TD_CLAMP);
        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, 255);
        gDPSetRenderMode(gDisplayListHead++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
        gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);

        gDPLoadTextureTile_4b(gDisplayListHead++, D_6000000, G_IM_FMT_I, 560, 0, 0, 0, 559, 8, 0,
                              G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                              G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, 0x00A0, 0x06F4, 0x0960, 0x0718, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);

        gDPLoadTextureTile_4b(gDisplayListHead++, D_6000000, G_IM_FMT_I, 560, 0, 0, 9, 559, 17, 0,
                              G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                              G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, 0x00A0, 0x0718, 0x0960, 0x073C, G_TX_RENDERTILE, 0, 0x0120, 0x0400,
                            0x0400);
    }
}

void func_8FA0047C(s32 arg0) {
    u32 sp24 = osGetCount();
    u32 temp_s0 = __ull_div(__ll_mul(__ll_mul(arg0, 0x3E8), 0xBB8), 0x40) + sp24;

    while (osGetCount() < temp_s0) {}
}

s32 func_8FA00510(void) {
    return D_83407AE8;
}

s32 func_8FA0051C(s32 arg0, s32 arg1) {
    s32 i;
    unk_D_86002F58_004_000_010* temp_s0;
    unk_func_80007444* temp_v0;
    unk_D_83403C60* sp60 = (D_83407AE4 != 0) ? D_83407AC0 : D_83407ABC;
    u8 sp50[] = {
        0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x02, 0x02, 0x03, 0x03,
    };
    u8 var_v0;
    u8 sp4E;

    if (func_8FA00510() == 0) {
        if (func_83400704(sp60, (D_83407AE4 != 0) ? 16 : 4, 0) != 0) {
            func_8000B6FC(0x10);
            return 0;
        }
    }

    main_pool_push_state('SEAL');

    func_8001E94C(0x10, 0);
    func_80005E40(0x10000, 0);
    temp_v0 = func_80007444(1, 0, 1, 0, 2, 1);
    D_8FA00A2C = temp_v0;

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_6000000, copyright, 0);

    if (func_8FA00510() == 0) {
        ASSET_LOAD(D_5000000, snap_mode_ui, 0);
        FRAGMENT_LOAD(fragment31);

        func_8001987C();

        D_8FA00A28 = ASSET_LOAD2(stadium_models, 1, 1);
        temp_s0 = func_80019760(5);
        func_8002FF20();
        D_8FA00A00 = func_80031270(0x280, 0x1E0, D_8FA00A2C->unk_18[0], NULL, temp_s0, D_8FA00A28, sp60);
    }

    func_80007678(temp_v0);
    func_8000B6FC(1);
    func_8FA0047C(0xC8);
    func_80006C6C(1);

    while (func_80007604() != 0) {
        func_80007778();
    }

    osViBlack(1);
    func_80001CB8();

    sp4E = 0;
    for (i = 0; i < 16; i++) {
        if (func_8FA00510() == 0) {
            if (D_83407AE4 != 0) {
                var_v0 = i;
            } else {
                var_v0 = sp50[i];
            }

            if (sp4E != var_v0) {
                D_8FA00A00->unk_18 = &sp60[var_v0];
                D_8FA00A00->unk_00 = 0;
                sp4E = var_v0;
            }
            main_pool_push_state('DRAW');

            do {
                func_80031660(D_8FA00A00);
            } while (D_8FA00A00->unk_00 != 2);

            func_8FA00020(i);
            main_pool_pop_state('DRAW');
        } else {
            main_pool_push_state('DRAW');

            D_8FA00A20 = ASSET_LOAD2(backgrounds, 1, 1);
            D_8FA00A24 = func_8000484C(D_8FA00A20, D_8FA009F0[i]);
            func_8001D924(D_8FA00A24);
            func_8FA00020(i);

            main_pool_pop_state('DRAW');
        }

        func_80007778();

        while (func_80001C90() == 0) {}

        osViBlack(0);
        func_80001CC8();
        func_8FA0047C(0xC8);
        func_8000B6FC(2);

        while (func_8000B6B4() == 8) {
            func_8FA0047C(0xC8);
        }

        osViBlack(1);
        func_80001CB8();
    }

    func_8000B6FC(4);

    while (func_8000B6B4() == 8) {
        func_8FA0047C(0x14);
    }

    func_80001CC8();
    func_800076C0();

    main_pool_pop_state('SEAL');

    return 0;
}
