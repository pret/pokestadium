#include "gb_tower_audio.h"
#include <PR/os_internal_reg.h>
#include "dp_intro.h"
#include "sections.h"
#include "memory.h"
#include "dp_intro.h"
#include "jpeg_stream.h"
#include "scheduler.h"
#include "util.h"
#include "src/fragments/gb_tower_emulator/gb_tower_emulator.h"

unk_D_800AA660* D_800AA660;
unk_D_800AA664* D_800AA664;
static char D_800AA668;

extern u8 D_81200000[];

void GbTower_AudioThread(UNUSED void* arg0) {
    void (*func)(void*) = Util_ConvertAddrToVirtAddr(&GbEmu_AudioVideoTick);

    __osSetFpcCsr(0x01000C01);
    Sched_InitClientQueue(D_800AA664, 0, 1);
    Sched_AddClient(D_800AA664);

    while (1) {
        Sched_WaitClientQueue(D_800AA664);
        if (D_800A62E0.unk_A38 >= 0x15) {
            continue;
        }
        func(D_800AA664);
    }
}

void GbTower_EmuThread(UNUSED void* arg0) {
    void (*func1)(void* func) = Util_ConvertAddrToVirtAddr(&GbEmu_Init);
    void (*func2)(void* func) = Util_ConvertAddrToVirtAddr(&GbEmu_RunFrame);

    __osSetFpcCsr(0x01000C01);
    Sched_InitClientQueue(D_800AA660, 0, 1);
    Sched_AddClient(D_800AA660);
    func1(D_800AA660);
    osStartThread(&D_800AA664->thread);

    while (1) {
        Sched_WaitClientQueue(D_800AA660);
        if (D_800A62E0.unk_A38 >= 0x15) {
            continue;
        }
        func2(D_800AA660);
    }
}

void GbTower_Start(UnkInputStruct8000D738* arg0) {
    s32 temp_v0;

    main_pool_push_state('GBEM');
    D_800AA660 = main_pool_alloc(0x2210, 0);
    D_800AA664 = main_pool_alloc(0x21E0, 0);

    FRAGMENT_LOAD(FRAGMENT_GB_TOWER_EMULATOR);
    temp_v0 = ASSET_LOAD2(fonts, 1, 1);

    D_800AA660->font1 = BinArchive_GetFile(temp_v0, 0);
    D_800AA660->font2 = BinArchive_GetFile(temp_v0, 1);
    D_800AA660->unk_2204 = *arg0;
    osCreateMesgQueue(&D_800AA660->queue2, &D_800AA660->mesg, 1);
    osCreateThread(&D_800AA664->thread, 10, GbTower_AudioThread, NULL, (u32)D_800AA664 + 0x21E0, 0x11);
    osCreateThread(&D_800AA660->thread, 8, GbTower_EmuThread, NULL, (u32)D_800AA660 + 0x21E0, 0xF);
    D_800AA668 = GbTower_SetPollMask(0);
    osStartThread(&D_800AA660->thread);
}

OSMesg* GbTower_RecvExitMesg(void) {
    OSMesg mesg;

    osRecvMesg(&D_800AA660->queue2, &mesg, OS_MESG_BLOCK);
    return mesg;
}

void GbTower_Stop(UnkInputStruct8000D738* arg0) {
    *arg0 = D_800AA660->unk_2204;
    GbTower_SetPollMask(D_800AA668);
    osViBlack(1U);
    Display_ApplyPendingVideoMode();
    Sched_RemoveClient(D_800AA660);
    Sched_RemoveClient(D_800AA664);
    osDestroyThread(&D_800AA660->thread);
    osDestroyThread(&D_800AA664->thread);
    main_pool_pop_state('GBEM');
}
