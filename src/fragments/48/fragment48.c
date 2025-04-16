#include "fragment48.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/26820.h"
#include "src/3FB0.h"
#include "src/6A40.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_839006B0 {
    /* 0x00 */ unk_func_80026268_arg0 unk_00;
    /* 0x54 */ char unk54[0x38];
} unk_D_839006B0; // size = 0x8C

typedef struct unk_D_83902700 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk04[0x70];
} unk_D_83902700; // size >= 0x74

static unk_D_839006B0 D_839006B0[37];
static unk_D_839006B0 D_83901AF0[22];
static void* D_839026F8;
static s32 D_839026FC;
static unk_D_83902700 D_83902700;
static s32 D_83902774;

static Gfx D_83900630[] = {
    gsSPEndDisplayList(),
};

static Gfx D_83900638[] = {
    gsSPEndDisplayList(),
};

void func_83900020(void) {
}

void func_83900028(void) {
}

void func_83900030(void) {
}

void func_83900038(void) {
    s32 i;

    D_839026FC = 0;
    D_83902700.unk_00 = 0;
    func_80028AFC(2);

    for (i = 0; i < 36; i++) {
        func_8002797C(0x16, 0, i, &D_839006B0[i]);
    }

    for (i = 0; i < 21; i++) {
        func_8002797C(0x17, 0, i, &D_83901AF0[i]);
    }

    func_83900020();
}

void func_839000E4(void) {
    s32 i;

    for (i = 0; i < 36; i++) {
        func_80027C24(0x16, 0, i, &D_839006B0[i]);
    }

    for (i = 0; i < 21; i++) {
        func_80027C24(0x17, 0, i, &D_83901AF0[i]);
    }

    func_80026E4C(2);
    func_800284B4(2);
}

void func_83900180(void) {
    static char* D_83900640[] = { "Load Controller Pak", "Save Controller Pak", "Quit" };

    s32 i;
    s32 sp30;
    char* temp_s0 = "GALLERY DEBUGGER";

    func_8001F3F4();
    func_8001EBE0(8, 0);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    sp30 = (0x280 - func_8001F5B0(0, 0, temp_s0)) / 2;
    func_8001F1E8(sp30, 0x64, temp_s0);

    for (i = 0; i < 3; i++) {
        s32 tmp = i * 0x16;
        if (i != D_83902700.unk_00) {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            func_8001F324(0xFF, 0xFF, 0, 0xFF);
        }
        func_8001F1E8(0x78, 0x82 + tmp, D_83900640[i]);
    }

    func_8001F1E8(sp30, 0xC8, "PFS ERROR : %d", D_83902774);
    func_8001F444();
}

void func_839002B8(void) {
    func_800079C4();
    func_8001D924(D_839026F8);
    func_83900180();
    func_80007778();
}

s32 func_839002F4(void) {
    s32 var_a2 = 0;
    s32 temp_a1 = D_83902700.unk_00;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        D_83902700.unk_00--;
        if (D_83902700.unk_00 < 0) {
            D_83902700.unk_00 = 0;
        }
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        D_83902700.unk_00++;
        if (D_83902700.unk_00 >= 3) {
            D_83902700.unk_00 = 2;
        }
    }

    if (temp_a1 != D_83902700.unk_00) {
        D_83902774 = 0;
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        switch (D_83902700.unk_00) {
            case 0:
                func_83900030();
                var_a2 = 0;
                break;

            case 1:
                func_83900028();
                var_a2 = 0;
                break;

            case 2:
                var_a2 = 1;
                break;
        }
    }

    return var_a2;
}

s32 func_839003DC(void) {
    s32 sp1C = 1;

    switch (D_839026FC) {
        case 0:
            if (func_80007604() == 0) {
                D_839026FC = 1;
            }
            break;

        case 1:
            if (func_839002F4() != 0) {
                D_839026FC = 2;
                func_80006CB4(0xF);
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

void func_83900484(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_839004B4(void) {
    func_80006C6C(0xF);
    do {
        func_83900484();
        func_839002B8();
    } while (func_839003DC() != 0);
}

s32 func_839004F4(s32 arg0, s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('GLDB');

    func_80005E40(0x10000, 0);
    sp24 = func_80007444(1, 0, 2, 0, 2, 1);
    func_8001E94C(0x18, 0);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, gallery_ui, 0);
    D_839026F8 = func_8000484C(ASSET_LOAD2(backgrounds, 1, 1), 0x14);
    func_83900038();
    func_80007678(sp24);
    func_839004B4();
    func_839000E4();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('GLDB');

    return 0;
}
