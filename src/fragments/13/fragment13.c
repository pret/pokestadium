#include "fragment13.h"
#include "src/12D80.h"
#include "src/17300.h"
#include "src/18140.h"
#include "src/geo_layout.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/20470.h"
#include "src/3FB0.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/F420.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static u32 D_86700840[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E, 0x00000000, 0x014000F0, 0x0000000F, 0x00000000, 0x00000000,
    0x05000000, 0x0D000000, 0x05000000, 0x0F000002, 0x05000000, 0x1F00FFFF, 0x00000000, 0x00000000,
    0x00000000, 0x00640064, 0x00640000, 0x05000000, 0x00000000, 0x8D000020, 0x06000000, 0x06000000,
    0x14000000, 0x002B0012, 0xFFFFFF32, 0x16FFFFFF, 0x0F000003, 0x05000000, 0x0A000000, 0x800AC840,
    0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};

static unk_D_86002F30* D_86700930;
static struct GraphNode* D_86700934;
static unk_D_86002F34_00C* D_86700938;
static unk_D_86002F58_004_000 D_86700940;

static s16 D_86700AA8;
static s16 D_86700AAA;
static s16 D_86700AAC;

void func_86700020(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_86700050(void) {
    D_86700938 = D_86700934->unk_0C;
    D_86700AA8 = 0x100;
    D_86700AAA = 0;
    D_86700AAC = 0x78;

    D_86700938->unk_24.near = 50.0f;
    D_86700938->unk_24.far = 6400.0f;
    func_80010354(&D_86700938->unk_60.at, &D_86700938->unk_60.eye, D_86700AAC, D_86700AA8, D_86700AAA);
}

void func_867000FC(void) {
    if (gPlayer1Controller->buttonDown & 0x800) {
        D_86700AA8 += 256;
    }

    if (gPlayer1Controller->buttonDown & 0x400) {
        D_86700AA8 -= 256;
    }

    if (gPlayer1Controller->buttonDown & 0x200) {
        D_86700AAA += 256;
    }

    if (gPlayer1Controller->buttonDown & 0x100) {
        D_86700AAA -= 256;
    }

    if (gPlayer1Controller->buttonDown & 8) {
        D_86700AAC -= 10;
    }

    if (gPlayer1Controller->buttonDown & 4) {
        D_86700AAC += 10;
    }

    if (D_86700AA8 > 16128) {
        D_86700AA8 = 16128;
    }

    if (D_86700AA8 < 0) {
        D_86700AA8 = 0;
    }

    if (D_86700AAC < 50) {
        D_86700AAC = 50;
    }

    func_80010354(&D_86700938->unk_60.at, &D_86700938->unk_60.eye, D_86700AAC, D_86700AA8, D_86700AAA);
}

void func_86700254(s32 arg0) {
    Color_RGB8 sp2C = { 0, 0, 30 };
    Color_RGB8 sp28 = { 0, 0, 250 };

    func_8002053C(0xC8, 0xBE, 0x5A, 0x20, &sp2C, &sp28);
    func_80020460(0x1E, 0xBE, 0xA0, 0x20, 0x141);
    func_8001F3F4();
    func_8001F470();
    func_8001EBE0(4, -2);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001F36C(0x50, 0x50, 0xFF, 0xFF);
    func_8001F1E8(0x30, 0x14, "MINIGAME8 SAMPLE");
    func_8001F4C4();
    func_8001EBE0(2, -2);
    func_8001F324(0xFF, 0xC8, 0x32, 0xFF);

    switch (arg0) {
        case 0:
            func_8001F1E8(0xCD, 0xC2, "OPENNING");
            break;

        case 1:
            func_8001F1E8(0xCD, 0xC2, "PLAYING");
            break;

        case 2:
            func_8001F1E8(0xCD, 0xC2, "ENDING");
            break;
    }

    if (arg0 == 1) {
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F1E8(0x23, 0xC2, "CAMERA D:%d", D_86700AAC);
        func_8001F1E8(0x23, 0xCE, "X:%04hX Y:%04hX", D_86700AA8, D_86700AAA);
    }

    func_8001F444();
}

void func_86700428(s32 arg0) {
    func_800079C4();
    func_8000699C(&gDisplayListHead, 0xA6BF);
    func_80015348();
    func_80015094(D_86700934);
    func_86700254(arg0);
    func_80007778();
}

void func_8670047C(void) {
    func_80006C6C(0x10);
    func_8001BD04(&D_86700940, 8);

    while (func_80017514(&D_86700940) == 0) {
        func_86700020();
        func_86700428(0);
    }
}

void func_867004E8(void) {
    s32 var_s1 = 1;
    s32 var_s0 = 0;

    func_8001BD04(&D_86700940, 0);

    while (var_s1 != 0) {
        func_86700020();
        func_867000FC();

        var_s0++;

        if (gPlayer1Controller->buttonPressed & 0x1000) {
            var_s1 = 0;
        }

        if (var_s0 == 0x3C) {
            var_s0 = 0;
            func_80017788(&D_86700940);
            func_8001BD9C(&D_86700940, 0xA);
        }

        func_86700428(1);
    }
}

void func_867005A8(void) {
    s32 i;

    func_8001BD04(&D_86700940, 0xB);
    func_8001BD9C(&D_86700940, 0xB);

    while (func_80017514(&D_86700940) == 0) {
        func_86700020();
        func_86700428(2);
    }

    func_80006CB4(0x1E);

    for (i = 0; i < 30; i++) {
        func_86700020();
        func_86700428(2);
    }
}

void func_86700648(void) {
    MemoryBlock* sp1C = func_80002D10(main_pool_get_available(), 0);

    D_86700934 = process_geo_layout(sp1C, &D_86700840);
    func_80002D60(sp1C);
    func_8001BB20();
    func_8001BB58(&D_86700940);
    func_8001987C();
    D_86700930 = func_80019D18(0x19);
    func_8001BC34(&D_86700940, 0, 0x19, D_86700930->unk_08->unk_00[0]);
    func_8001BD04(&D_86700940, 0);
    func_86700050();
}

s32 func_867006FC(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('MINI');

    func_80005E40(0x10000, 0);
    sp24 = func_80007444(0, 1, 3, 1, 2, 1);
    func_8001E94C(6, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);

    FRAGMENT_LOAD(fragment31);
    func_80004454((((u32)D_8D000000 & 0x0FF00000) >> 0x14) - 0x10, _5C7A70_ROM_START, pokedex_area_model_ROM_START);

    func_86700648();
    func_80007678(sp24);
    func_8670047C();
    func_867004E8();
    func_867005A8();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('MINI');

    return 0;
}
