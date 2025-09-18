#include "E1C0.h"
#include <PR/os_internal_reg.h>
#include "dp_intro.h"
#include "sections.h"
#include "memory.h"
#include "dp_intro.h"
#include "3FB0.h"
#include "5580.h"
#include "util.h"
#include "src/fragments/1/fragment1.h"

extern unk_D_800AA660* D_800AA660;
extern unk_D_800AA664* D_800AA664;
extern char D_800AA668;

extern u8 D_81200000[];

void func_8000D5C0(UNUSED void* arg0) {
    void (*func)(void*) = Util_ConvertAddrToVirtAddr(&func_81206F38);

    __osSetFpcCsr(0x01000C01);
    func_80004CC0(D_800AA664, 0, 1);
    func_80005328(D_800AA664);

    while (1) {
        func_80004CF4(D_800AA664);
        if (D_800A62E0.unk_A38 >= 0x15) {
            continue;
        }
        func(D_800AA664);
    }
}

void func_8000D678(UNUSED void* arg0) {
    void (*func1)(void* func) = Util_ConvertAddrToVirtAddr(&func_81206D9C);
    void (*func2)(void* func) = Util_ConvertAddrToVirtAddr(&func_81206E64);

    __osSetFpcCsr(0x01000C01);
    func_80004CC0(D_800AA660, 0, 1);
    func_80005328(D_800AA660);
    func1(D_800AA660);
    osStartThread(&D_800AA664->thread);

    while (1) {
        func_80004CF4(D_800AA660);
        if (D_800A62E0.unk_A38 >= 0x15) {
            continue;
        }
        func2(D_800AA660);
    }
}

void func_8000D738(UnkInputStruct8000D738* arg0) {
    s32 temp_v0;

    main_pool_push_state('GBEM');
    D_800AA660 = main_pool_alloc(0x2210, 0);
    D_800AA664 = main_pool_alloc(0x21E0, 0);

    FRAGMENT_LOAD(fragment1);
    temp_v0 = ASSET_LOAD2(fonts, 1, 1);

    D_800AA660->font1 = func_8000484C(temp_v0, 0);
    D_800AA660->font2 = func_8000484C(temp_v0, 1);
    D_800AA660->unk_2204 = *arg0;
    osCreateMesgQueue(&D_800AA660->queue2, &D_800AA660->mesg, 1);
    osCreateThread(&D_800AA664->thread, 10, func_8000D5C0, NULL, (u32)D_800AA664 + 0x21E0, 0x11);
    osCreateThread(&D_800AA660->thread, 8, func_8000D678, NULL, (u32)D_800AA660 + 0x21E0, 0xF);
    D_800AA668 = func_8000B318(0);
    osStartThread(&D_800AA660->thread);
}

OSMesg* func_8000D8A8(void) {
    OSMesg mesg;

    osRecvMesg(&D_800AA660->queue2, &mesg, OS_MESG_BLOCK);
    return mesg;
}

void func_8000D8DC(UnkInputStruct8000D738* arg0) {
    *arg0 = D_800AA660->unk_2204;
    func_8000B318(D_800AA668);
    osViBlack(1U);
    func_80001C64();
    func_80005370(D_800AA660);
    func_80005370(D_800AA664);
    osDestroyThread(&D_800AA660->thread);
    osDestroyThread(&D_800AA664->thread);
    main_pool_pop_state('GBEM');
}
