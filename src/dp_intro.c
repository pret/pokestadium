#include "global.h"
#include <PR/os_internal_reg.h>
#include "global.h"
#include "dp_intro.h"
#include "5580.h"
#include "6BC0.h"
#include "crash_screen.h"
#include "profiler.h"
#include "memory.h"

extern struct UnkStruct80083CA0_2 D_80083CA0;

extern UnkStruct80001380 D_800846C0;

extern struct UnkArray4 D_8008472C;
extern struct UnkArray4 D_8008473C;
extern struct UnkArray4 D_8008474C;

extern s32 D_80068B70;

extern u64 F3DEX2_data_bin[]; // F3DEX2_data.bin
extern u64 D_80084860[0x1];
extern u64 D_80085870[0x1];
extern u64 D_80084C68[0x1];

#define ALIGN16(val) (((val) + 0xF) & ~0xF)

extern s32 osTvType;
extern char D_80068B74[];
extern f32 D_8007AF10;

extern OSViMode D_800796E0[]; // osViModeTable

extern void func_8000183C(void*);

extern u32 D_80084680[];

extern OSMesgQueue D_8008468C;
extern OSMesgQueue D_800846A4;

extern OSMesg D_80084684;
extern OSMesg D_80084688;

extern s32 D_80084758;

// .bss?
extern u64 D_80084760[0x100 / sizeof(u64)];

// function prototypes
void func_80001AD4(u16 color);
void func_80001C1C(struct UnkArray4* arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, s32 arg5, s32 arg6, s32 arg7);

void func_80001380(UnkStruct80001380* arg0) {
    arg0->task.t.type = M_GFXTASK;
    arg0->task.t.flags = 0;
    arg0->task.t.ucode_boot = D_80084760;
    arg0->task.t.ucode_boot_size = 0x100;
    arg0->task.t.ucode = _binary_assets_us_F3DEX2_bin_start;
    arg0->task.t.ucode_data = F3DEX2_data_bin;
    arg0->task.t.ucode_size = 0x1000;
    arg0->task.t.ucode_data_size = 0x800;
    arg0->task.t.dram_stack = (void*)ALIGN16((uintptr_t)D_80084860);
    arg0->task.t.dram_stack_size = 0x400;
    arg0->task.t.yield_data_ptr = (void*)ALIGN16((uintptr_t)D_80084C68);
    arg0->task.t.yield_data_size = 0xC00;
    arg0->task.t.output_buff = (D_80085870);
    arg0->task.t.output_buff_size = (D_80085870 + (0x20000 / sizeof(u64)));
    osCreateMesgQueue(&arg0->queue, &arg0->mesg, 1);
}

void func_80001444(UnkStruct80001380* arg0, struct UnkArray4* arg1, s32 arg2) {
    arg0->task.t.data_ptr = (void*)(uintptr_t)arg1->unk_04;
    arg0->task.t.data_size = arg1->unk_08;
    func_800053B4(arg0, arg2);
}

void func_80001474(s8 arg0, s8 arg1) {
    s32 var_v0;

    if (osTvType == 2) {
        var_v0 = (arg0 * 2) + arg1 + 8;
    } else {
        var_v0 = (arg0 * 2) + arg1 + 4;
    }

    osViSetMode(&D_800796E0[(s32)D_80068B74[var_v0]]);
    osViSetSpecialFeatures(0x40U);
    osViSetSpecialFeatures(2U);
    osViSetSpecialFeatures(0x10U);
    if (osTvType == 0) {
        osViSetYScale(D_8007AF10);
    }
}

void func_8000152C(struct UnkArray4* arg0) {
    if (arg0 == NULL) {
        D_80083CA0.unk_A90 = 0;
        D_80083CA0.unk_A94 = 0;
        D_80083CA0.unk_A98 = 0;
        D_80083CA0.unk_A8D = D_80083CA0.unk_A9D;
        D_80083CA0.unk_A8E = D_80083CA0.unk_A9E;
        D_80083CA0.unk_A8C = D_80083CA0.unk_A9C;
    } else {
        D_80083CA0.unk_A8D = arg0->unk_01;
        D_80083CA0.unk_A8E = arg0->unk_02;
        D_80083CA0.unk_A8C = arg0->unk_00;
        D_80083CA0.unk_A90 = arg0->unk_04;
        D_80083CA0.unk_A94 = arg0->unk_08;
        D_80083CA0.unk_A98 = arg0->unk_0C;
        D_80083CA0.unk_A8F = arg0->unk_03;
    }
}

void func_800015A8(void) {
    s32 i;
    s32 sp20 = 0;

    if (D_80083CA0.unk_AA0 != 0) {
        func_800049AC(&D_800846C0);
    }

    if ((D_80083CA0.unk_A90 != 0) && (D_80083CA0.unk_AB8 != D_80083CA0.unk_A98) &&
        (D_80083CA0.unk_AAF != D_80083CA0.unk_A8F)) {
        func_80001444(&D_800846C0, &D_8008472C, 1);
        sp20 = 1;
    }

    for (i = 1; i < D_80083CA0.unk_AAC; i++) {
        func_80004CF4(&D_80083CA0);
    }

    while (D_80083CA0.unk_1C0.validCount > 0) {
        func_80004D20(&D_80083CA0);
    }

    if (D_80083CA0.unk_AA8 != NULL) {
        osViSwapBuffer((void*)(uintptr_t)D_80083CA0.unk_AA8->unk_08);
        osViRepeatLine(0);
        if ((D_80083CA0.unk_A9D != D_80083CA0.unk_AAD) || (D_80083CA0.unk_A9E != D_80083CA0.unk_AAE)) {
            func_80001474((s8)D_80083CA0.unk_A9D, (s8)D_80083CA0.unk_A9E);
        }
        if (D_80068B70 != 0) {
            osViBlack(1U);
        } else {
            osViBlack(0U);
        }
        crash_screen_set_draw_info((void*)(uintptr_t)D_80083CA0.unk_AA8->unk_08, *(u16*)&D_80083CA0.unk_AA8->unk_04,
                                   0x10);
    } else {
        osViRepeatLine(1);
        osViSwapBuffer((void*)(uintptr_t)D_80083CA0.unk_9E0->unk_08);
        if ((D_80083CA0.unk_A9D != D_80083CA0.unk_AAD) || (D_80083CA0.unk_A9E != D_80083CA0.unk_AAE)) {
            func_80001474((s8)D_80083CA0.unk_A9D, (s8)D_80083CA0.unk_A9E);
        }
    }

    if ((sp20 == 0) && (D_80083CA0.unk_A90 != 0)) {
        func_80001444(&D_800846C0, &D_8008472C, 0);
    }

    D_8008474C = D_8008473C;
    D_8008473C = D_8008472C;
    profiler_log_thread5_time(THREAD5_END);
    func_80004CF4(&D_80083CA0);
}

void func_800017E4(void) {
    func_80004CF4(&D_80083CA0);
    while (D_80083CA0.unk_1C0.validCount > 0) {
        func_80004D20(&D_80083CA0);
    }
    func_80004CF4(&D_80083CA0);
}

void func_8000183C(UNUSED void* arg) {
    __osSetFpcCsr(0x01000C01);
    func_80001C1C(&D_8008474C, 0, 1, 2, 0xFF, 0, 0, 0);
    func_80001C1C(&D_8008473C, 0, 1, 2, 0xFF, 0, 0, 0);
    func_80004CC0(&D_80083CA0.thread, 0, 4);
    func_80005328(&D_80083CA0);
    func_80001380(&D_800846C0);
    while (1) {
        void* sp4C;
        if (D_800A62E0.unk_A38 > 0) {
            func_800017E4();
            continue;
        }
        profiler_log_thread5_time(THREAD5_START);
        D_80083CA0.unk_A8A = 1;
        osRecvMesg(&D_8008468C, &sp4C, 1);
        D_80083CA0.unk_A8A = 0;
        profiler_log_thread5_time(UNK_EVENT_1);
        profiler_log_thread5_time(UNK_EVENT_2);
        func_8000152C(sp4C);
        func_800015A8();
        osSendMesg(&D_800846A4, (void*)'DONE', 0);
    }
}

void func_800019C8(void) {
    switch (osTvType) {
        case 1:
        case 2:
            break;

        default:
            osViBlack(1U);
            while (1) {
                ;
            }
            break;
    }

    osCreateThread(&D_80083CA0.thread, 5, func_8000183C, NULL, &D_80084680, 0x28);
    osStartThread(&D_80083CA0.thread);
    osCreateMesgQueue(&D_8008468C, &D_80084684, 1);
    osCreateMesgQueue(&D_800846A4, &D_80084688, 1);
    D_80083CA0.unk_A88 = 0;
    D_80083CA0.unk_A8A = 0;
    D_80084680[0] = func_80006314(0, IMAGE_SIZE_BITS_16b, 0x280, 1, MEMORY_POOL_RIGHT);
    func_80001AD4(1);
    func_80003B30(&D_80084760, 0xB0000B70, 0xB0000C70, 0);
}

/**
 * Write a specific color to a line on the framebuffer for a 640x480 resolution.
 */
void func_80001AD4(u16 color) {
    s32 width = 640;
    u16* buf = (void*)(uintptr_t)D_80083CA0.unk_9E0->unk_08;

    while (width-- > 0) {
        *(buf)++ = color;
    }

    osWritebackDCache((void*)(uintptr_t)D_80083CA0.unk_9E0->unk_08, 0x500);
}

u16 func_80001B2C(void) {
    // YIKES. What is this typing?!?
    u16* ptr = (u16*)(uintptr_t)((u32*)(uintptr_t)D_80084680[0])[2];
    return *ptr;
}

s32 func_80001B40(void) {
    s32 result = 0;

    if (osViGetCurrentFramebuffer() == ((void**)(uintptr_t)D_80084680[0])[2]) {
        result = 1;
    }

    return result;
}

void func_80001B7C(void) {
    osRecvMesg(&D_800846A4, NULL, 1);
}

void func_80001BA8(void* arg0) {
    osSendMesg(&D_8008468C, arg0, 0);
}

void func_80001BD4(s32 arg0) {
    while (arg0-- > 0) {
        func_80001BA8(0);
        func_80001B7C();
    }
}

void func_80001C1C(struct UnkArray4* arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, s32 arg5, s32 arg6, s32 arg7) {
    arg0->unk_01 = arg1;
    arg0->unk_02 = arg2;
    arg0->unk_00 = arg3;
    arg0->unk_03 = arg4;
    arg0->unk_04 = arg5;
    arg0->unk_08 = arg6;
    arg0->unk_0C = arg7;
}

s32 func_80001C58(void) {
    return D_80084758;
}

void func_80001C64(void) {
    func_80001474((s8)D_80083CA0.unk_AAD, (s8)D_80083CA0.unk_AAE);
}

s32 func_80001C90(void) {
    s32 result = 1;

    if (D_80083CA0.unk_AA0 != 0) {
        result = D_80083CA0.unk_A2C > 0;
    }
    return result;
}

void func_80001CB8(void) {
    D_80068B70 = 1;
}

void func_80001CC8(void) {
    D_80068B70 = 0;
}
