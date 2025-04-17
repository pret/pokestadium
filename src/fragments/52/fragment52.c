#include "fragment52.h"
#include "src/12D80.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/3FB0.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/controller.h"
#include "src/fragments/51/fragment51.h"
#include "src/geo_layout.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static unk_D_86002F30* D_82800530;
static GraphNode* D_82800534;
static unk_D_86002F58_004_000 D_82800538;
static BinArchive* D_828006A0;
static u8* D_828006A4;

static u32 D_828004D0[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E,  0x00000000, 0x014000F0, 0x00000032, 0x00000000, 0x00000118,
    0x05000000, 0x0D000000, 0x05000000,  0x14000000, 0x002B0012, 0xFFFFFF32, 0x16FFFFFF, 0x0F000003,
    0x05000000, 0x0A000000, &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};

void func_82900020(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_82800050(u8* arg0) {
    s32 i;
    s32 j;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGB, G_CC_DECALRGB);

    gDPPipeSync(gDisplayListHead++);

    if (1) {}

    for (i = 0; i < 15; i++) {
        for (j = 0; j < 20; j++, arg0 += 0x200) {
            func_8001C6AC(j * 0x10, i * 0x10, 0x10, 0x10, arg0, 0x10, 0);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_828001D0(void) {
    func_800079C4();
    func_82800050(D_828006A4);
    func_800067E4(&gDisplayListHead, 0, 0, 0x140, 0xF0);
    func_80015348();
    func_80015094(D_82800534);
    func_80007778();
}

void func_82800238(void) {
    s32 i;

    func_80006C6C(0x10);

    for (i = 0; i < 16; i++) {
        func_82900020();
        func_828001D0();
    }

    do {
        func_82900020();
        func_828001D0();
    } while (!(BTN_IS_PRESSED(gPlayer1Controller, BTN_A)));

    func_80006CB4(0x10);

    for (i = 0; i < 16; i++) {
        func_82900020();
        func_828001D0();
    }

    func_800077B4(2);
}

void func_828002E4(void) {
    MemoryBlock* sp1C = func_80002D10(main_pool_get_available(), 0);

    D_82800534 = process_geo_layout(sp1C, D_828004D0);
    func_80002D60(sp1C);
    func_8001BB20();
    func_8001BB58(&D_82800538);
    func_8001987C();
    D_82800530 = func_80019D18(0x96);
    func_8001BC34(&D_82800538, 0, 0x96, D_82800530->unk_08->unk_00[0]);
    func_8001BD04(&D_82800538, 0);
}

s32 func_82900390(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('MTWO');

    func_80005E40(0x10000, 0);
    sp24 = func_80007444(0, 1, 3, 1, 2, 1);
    func_8001E94C(6, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    FRAGMENT_LOAD(fragment31);

    D_828006A0 = ASSET_LOAD2(backgrounds, 1, 1);
    D_828006A4 = func_8000484C(D_828006A0, 2);

    func_828002E4();
    func_80007678(sp24);
    func_82800238();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('MTWO');

    return 0;
}
