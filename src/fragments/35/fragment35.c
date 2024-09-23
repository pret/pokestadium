#include "fragment35.h"
#include "src/26820.h"
#include "src/22630.h"
#include "src/20470.h"
#include "src/2E110.h"
#include "src/3D140.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/4BA90.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/memory.h"
#include "src/stage_loader.h"

void func_82000020(void) {
    s32 var_t4;
    u8* var_t5;
    u32 tmp = 0xF;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_COPY);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
    gDPPipeSync(gDisplayListHead++);

    var_t5 = D_2000000;
    for (var_t4 = 0x40; var_t4 < 0xB0; var_t4 += 0x10, var_t5 += 0x1000) {
        gDPLoadTextureBlock(gDisplayListHead++, var_t5, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 7, 4, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, 0x0180, var_t4 << 2, 0x037C, (var_t4 + tmp) << 2, G_TX_RENDERTILE, 0, 0,
                            0x1000, 0x0400);
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureConvert(gDisplayListHead++, G_TC_FILT);
}

s32 func_820002B4(UNUSED u8 arg0) {
    func_800079C4();
    func_8000699C(&gDisplayListHead, 1);
    func_82000020();

    return 0;
}

void func_820002F0(u64 arg0) {
    u32 temp_ret = 0xF;

    while (temp_ret < 0xF4240) {
        temp_ret = __ull_div(__ll_mul(osGetTime() - arg0, 0x40), 0xBB8);
    }
}

void func_8200036C(void) {
    main_pool_push_state('GPAK');

    func_800240A0();

    main_pool_pop_state('GPAK');
}

s32 func_820003A4(UNUSED s32 arg0, UNUSED s32 arg1) {
    u64 sp30;
    unk_func_80007444* sp2C;
    u16 sp2A;

    main_pool_push_state('LOGO');

    func_80005E40(0x10000, 0);
    sp2C = func_80007444(0, 1, 2, 0, 2, 1);

    ASSET_LOAD(D_1000000, _4BD6B0, 0);
    ASSET_LOAD(D_2000000, n64_logo_texture, 0);

    func_80028AFC(2);
    func_80007678(sp2C);
    func_80006C04(1);
    func_80007820(3, func_820002B4);
    func_8002D510();
    func_80023068();
    func_80021920();
    func_80028070(&sp2A);

    if (sp2A & 1) {
        func_8004AF24(1);
    } else {
        func_8004AF24(0);
    }

    if (sp2A & 2) {
        func_8003D68C(0);
    } else {
        func_8003D68C(1);
    }

    func_80048B90(0xA);
    sp30 = osGetTime();
    func_8200036C();
    func_820002F0(sp30);
    func_80006C04(0x10);
    func_80007820(0x10, func_820002B4);
    func_800076C0();
    func_80005EAC();

    main_pool_pop_state('LOGO');
    return 2;
}
