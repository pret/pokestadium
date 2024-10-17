#include "fragment19.h"
#include "src/12D80.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/3FB0.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/fragments/3/fragment3.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/geo_layout.h"

static u32 D_86D00530[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E,  0x00000000, 0x014000F0, 0x0000000F, 0x00000000, 0x00000000, 0x05000000,
    0x0D000000, 0x05000000, 0x0F000002,  0x05000000, 0x1F00FFFF, 0x00000000, 0x00000000, 0x00000000, 0x00640064,
    0x00640000, 0x05000000, 0x06000000,  0x06000000, 0x14000000, 0x002B0012, 0xFFFFFF32, 0x16FFFFFF, 0x0F000003,
    0x05000000, 0x0A000000, &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000, 0x00000000,
};

void func_86D00020(void) {
    D_87906054 = D_87906050->unk_00.unk_0C;

    D_87906060 = 0xA00;
    D_87906062 = 0;
    D_87906064 = 0x17C;
    D_87906066 = 0x1E;
    D_87906068 = 0x32;
    D_8790606A = 0x1900;

    D_8790606C.x = 0;
    D_8790606C.y = 0x1E;
    D_8790606C.z = 0;

    func_87900B64();
}

void func_86D000A8(void) {
    func_87900C5C();
    func_87900B64();
}

void func_86D000D0(UNUSED s32 arg0) {
    func_800079C4();
    func_8000699C(&gDisplayListHead, 1);
    func_80015348();
    func_80015094(&D_87906050->unk_00);

    if (D_87903DB0 != 0) {
        func_87900F44();
    }

    func_80007778();
}

void func_86D00134(void) {
    func_80006C6C(0x10);
    D_87903DC4 = 3;
}

void func_86D0015C(void) {
    s32 var_s1 = 1;

    while (var_s1 != 0) {
        func_87900528();

        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
            func_879037D0(0.2f, 0.0f, 50.0f, 50.0f, 0x2000, 0, 0x1000);
        }

        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
            func_87903838(0.2f, 50.0f, 50.0f, 50.0f, 0, 0, 0);
        }

        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_CLEFT)) {
            func_879038AC(0.2f, -50.0f, 50.0f, 50.0f, -0x6000, 0, 0x2000);
        }

        if (BTN_IS_PRESSED(gPlayer1Controller, BTN_Z)) {
            D_87903DB0 = (D_87903DB0 + 1) & 1;
        }

        if ((D_87903DB0 == 0) && BTN_IS_PRESSED(gPlayer1Controller, BTN_START)) {
            D_87903DA0 = 1;
        }

        func_8790370C();
        func_86D000A8();

        if ((D_87903DB0 == 0) && BTN_IS_PRESSED(gPlayer1Controller, BTN_CDOWN)) {
            var_s1 = 0;
        }

        func_86D000D0(1);
    }
}

void func_86D0032C(void) {
    s32 i;

    func_80006CB4(0x1E);

    for (i = 0; i < 30; i++) {
        func_87900528();
        func_86D000D0(2);
    }
}

void func_86D0037C(void) {
    UNUSED s32 pad[2];
    MemoryBlock* sp1C = func_80002D10(main_pool_get_available(), 0);

    D_87906050 = process_geo_layout(sp1C, &D_86D00530);
    func_80002D60(sp1C);
    func_8001BB20();
    func_8001987C();
    func_87903600();
    func_86D00020();
}

s32 func_86D003EC(s32 arg0, s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('MINI');

    func_80005E40(0x20000, 0);
    sp24 = func_80007444(0, 1, 3, 1, 2, 1);
    func_8001E94C(6, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    FRAGMENT_LOAD(fragment31);
    func_80004454((((u32)D_8D000000 & 0x0FF00000) >> 0x14) - 0x10, _5C7A70_ROM_START, pokedex_area_model_ROM_START);

    func_86D0037C();
    func_80007678(sp24);
    func_86D00134();
    func_86D0015C();
    func_86D0032C();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('MINI');

    return 0;
}
