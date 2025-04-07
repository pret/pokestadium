#include "fragment46.h"
#include "src/19840.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/30640.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/6A40.h"
#include "src/controller.h"
#include "src/fragments/43/fragment43.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static s32 D_837004C0;
static BinArchive* D_837004C4;
static unk_func_80007444* D_837004C8;

static unk_func_80031270* D_837004B0 = NULL;

void func_83700020(void) {
    UNUSED s32 pad;
    unk_D_86002F58_004_000_010* sp28;

    D_837004C0 = 0;
    sp28 = func_80019760(1);
    func_8002FF00();
    D_837004B0 = func_80031270(0x280, 0x1E0, NULL, D_837004C8->unk_18[0], sp28, D_837004C4, func_834006A0(1));
}

void func_83700090(void) {
}

void func_83700098(void) {
    static s16 D_837004B4 = 0;

    func_800079C4();
    if (D_837004B0->unk_00 == 2) {
        func_834018C0(D_837004B0->unk_08->img_p, 0, 0, D_837004B0->unk_04, D_837004B0->unk_06, 1, 0);
    }
    func_80007778();
    D_837004B4 += 0x1000;
}

s32 func_83700114(void) {
    s32 sp1C = 0;

    if (func_8003181C(&D_837004B0, 1) != -1) {
        return 0;
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B | BTN_CDOWN)) {
        sp1C = 1;
    }

    return sp1C;
}

s32 func_83700174(void) {
    static s32 D_837004B8 = 2;

    s32 sp1C = 1;

    switch (D_837004C0) {
        case 0:
            if (func_80007604() == 0) {
                D_837004B8--;
                if (D_837004B8 <= 0) {
                    D_837004C0 = 1;
                }
            }
            break;

        case 1:
            if (func_83700114() != 0) {
                D_837004C0 = 2;
                func_80048B90(0x1A);
                func_80006CB4(1);
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

void func_8370023C(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_8370026C(void) {
    do {
        func_80031660(D_837004B0);
    } while (D_837004B0->unk_00 != 2);

    func_80006C6C(1);

    do {
        func_8370023C();
        func_83700098();
    } while (func_83700174() != 0);
}

s32 func_837002EC(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('ELRG');

    func_80005E40(0x10000, 0);

    sp24 = func_80007444(1, 0, 1, 0, 2, 1);
    D_837004C8 = sp24;

    func_8001E94C(0x18, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_5000000, snap_mode_ui, 0);
    ASSET_LOAD(D_3000000, gallery_ui, 0);
    ASSET_LOAD(D_04000000, album_ui, 0);

    FRAGMENT_LOAD(fragment31);

    func_8001987C();

    D_837004C4 = ASSET_LOAD2(stadium_models, 1, 1);

    func_83700020();
    func_80007678(sp24);
    func_8370026C();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('ELRG');

    return 0;
}
