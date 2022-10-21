#include <ultra64.h>

extern void thread1_idle(); // thread 1 function
extern void func_8002B330(); // thread 6 function

// entry .bss
u8 D_8007ED80[0xF180-0xED80]; // unknown, start of .bss
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
void thread1_idle(void *arg0) {
    osCreateViManager(OS_PRIORITY_VIMGR);
    func_80001474(0, 1);
    osViBlack(TRUE);
    func_80008F7C();
    rsp_init();
    func_800052B4();
    func_8000D564();
    func_800019C8();
    func_800057C0();
    osCreateThread(&pThreads, 6, &func_8002B330, 0, &D_800818E0, 20);
    osStartThread(&pThreads);
    osSetThreadPri(NULL, 0);

    // Halt
    while(TRUE);
}

void main_func(void) {
    osInitialize();
    osCartRomInit();
    set_watch_lohi(0);
    func_80002F58();
    osCreateThread(&gIdleThread, 1, &thread1_idle, 0, &pThreads, 100);
    osStartThread(&gIdleThread);
}
