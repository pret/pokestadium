#include "global.h"
#include "dp_intro.h"
#include "crash_screen.h"
#include "rsp.h"
#include "reset.h"

extern void func_8002B330(); // thread 6 function

// entry .bss
u8 D_8007ED80[0xF180 - 0xED80]; // unknown, start of .bss
OSThread gIdleThread;
u8 unk_8007F330[0x400];
OSThread pThreads;
u8 unk_8007F8E0[0x720];
u8 D_80080000[0x18E0];
u8 D_800818E0[0x18];
u8 D_800818F8[0x8];

/**
 * Initialize hardware, start main thread, then idle.
 */
void Idle_ThreadEntry(UNUSED void* unused) {
    osCreateViManager(OS_PRIORITY_VIMGR);
    func_80001474(0, 1);
    osViBlack(TRUE);
    crash_screen_init();
    rsp_init();
    func_800052B4();
    func_8000D564();
    func_800019C8();
    SoftReset_CreateThread();
    osCreateThread(&pThreads, 6, &func_8002B330, 0, &D_800818E0, 20);
    osStartThread(&pThreads);
    osSetThreadPri(NULL, 0);

    // Halt
    while (TRUE) {
        ;
    }
}

/**
 * C entrypoint from the boot/entry code. Starts the libultra OS library and
 * creates the idle thread which bootstraps the rest of the game.
 */
void Main(void) {
    osInitialize();
    osCartRomInit();
    set_watch_lohi(0);
    Util_InitMainPools();
    osCreateThread(&gIdleThread, THREAD_ID_IDLE, &Idle_ThreadEntry, NULL, &pThreads, THREAD_PRI_IDLE_INIT);
    osStartThread(&gIdleThread);
}
