#include <ultra64.h>
#include <PR/os_internal_reg.h>
#include "common.h"
#include "dp_intro.h"
#include "crash_screen.h"
#include "profiler.h"

// dp_intro.c

struct UnkStruct80001380 {
    OSMesg mesg;
    OSMesgQueue queue;
    OSTask task;
};

struct UnkArray4 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};

struct UnkStruct80083CA0_2 {
    // there's some wonkyness going on like the compiler trying to 8-align filler arrays? I dont understand.
    OSThread thread;
    char filler1B0[0x18];
    s32 unk1C8;
    u8 filler1CC[0x9E0 - 0x1CC];
    struct UnkArray4* unk9E0;
    char filler9E4[0xA2C - 0x9E4];
    s32 unkA2C;
    char fillerA30[0xA88 - 0xA30];
    u16 unkA88;
    u8 unkA8A;
    u8 unkA8B;
    u8 unkA8C;
    u8 unkA8D;
    u8 unkA8E;
    u8 unkA8F;
    s32 unkA90;
    s32 unkA94;
    s32 unkA98;
    u8 unkA9C;
    u8 unkA9D;
    u8 unkA9E;
    u8 unkA9F;
    s32 unkAA0;
    char fillerAA4[0x4];
    struct UnkArray4* unkAA8;
    u8 unkAAC;
    u8 unkAAD;
    u8 unkAAE;
    u8 unkAAF;
    char fillerAB0[0x8];
    s32 unkAB8;
};

extern struct UnkStruct80083CA0_2 D_80083CA0;

extern struct UnkStruct80001380 D_800846C0;

extern void func_800049AC();

extern struct UnkArray4 D_8008472C;
extern struct UnkArray4 D_8008473C;
extern struct UnkArray4 D_8008474C;

extern s32 D_80068B70;

extern u64 F3DEX2_bin[];
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

void func_80001380(struct UnkStruct80001380* arg0) {
    arg0->task.t.type = 1;
    arg0->task.t.flags = 0;
    arg0->task.t.ucode_boot = D_80084760;
    arg0->task.t.ucode_boot_size = 0x100;
    arg0->task.t.ucode = F3DEX2_bin;
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

void func_80001444(struct UnkStruct80001380* arg0, struct UnkArray4* arg1, s32 arg2) {
    arg0->task.t.data_ptr = (void*)(uintptr_t)arg1->unk4;
    arg0->task.t.data_size = arg1->unk8;
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
        D_80083CA0.unkA90 = 0;
        D_80083CA0.unkA94 = 0;
        D_80083CA0.unkA98 = 0;
        D_80083CA0.unkA8D = D_80083CA0.unkA9D;
        D_80083CA0.unkA8E = D_80083CA0.unkA9E;
        D_80083CA0.unkA8C = D_80083CA0.unkA9C;
    } else {
        D_80083CA0.unkA8D = arg0->unk1;
        D_80083CA0.unkA8E = arg0->unk2;
        D_80083CA0.unkA8C = arg0->unk0;
        D_80083CA0.unkA90 = arg0->unk4;
        D_80083CA0.unkA94 = arg0->unk8;
        D_80083CA0.unkA98 = arg0->unkC;
        D_80083CA0.unkA8F = arg0->unk3;
    }
}

void func_800015A8(void) {
    s32 i; // i
    s32 sp20;

    sp20 = 0;
    if (D_80083CA0.unkAA0 != 0) {
        func_800049AC(&D_800846C0);
    }
    if ((D_80083CA0.unkA90 != 0) && (D_80083CA0.unkAB8 != D_80083CA0.unkA98) &&
        (D_80083CA0.unkAAF != D_80083CA0.unkA8F)) {
        func_80001444(&D_800846C0, &D_8008472C, 1);
        sp20 = 1;
    }
    i = 1;
    if (D_80083CA0.unkAAC >= 2) {
        do {
            func_80004CF4(&D_80083CA0);
        } while (++i < D_80083CA0.unkAAC);
    }
    if (D_80083CA0.unk1C8 > 0) {
        do {
            func_80004D20(&D_80083CA0);
        } while (D_80083CA0.unk1C8 > 0);
    }
    if (D_80083CA0.unkAA8 != NULL) {
        osViSwapBuffer((void*)(uintptr_t)D_80083CA0.unkAA8->unk8);
        osViRepeatLine(0);
        if ((D_80083CA0.unkA9D != D_80083CA0.unkAAD) || (D_80083CA0.unkA9E != D_80083CA0.unkAAE)) {
            func_80001474((s8)D_80083CA0.unkA9D, (s8)D_80083CA0.unkA9E);
        }
        if (D_80068B70 != 0) {
            osViBlack(1U);
        } else {
            osViBlack(0U);
        }
        crash_screen_set_draw_info((void*)(uintptr_t)D_80083CA0.unkAA8->unk8, *(u16*)&D_80083CA0.unkAA8->unk4, 0x10);
    } else {
        osViRepeatLine(1);
        osViSwapBuffer((void*)(uintptr_t)D_80083CA0.unk9E0->unk8);
        if ((D_80083CA0.unkA9D != D_80083CA0.unkAAD) || (D_80083CA0.unkA9E != D_80083CA0.unkAAE)) {
            func_80001474((s8)D_80083CA0.unkA9D, (s8)D_80083CA0.unkA9E);
        }
    }
    if ((sp20 == 0) && (D_80083CA0.unkA90 != 0)) {
        func_80001444(&D_800846C0, &D_8008472C, 0);
    }
    D_8008474C = D_8008473C;
    D_8008473C = D_8008472C;
    profiler_log_thread5_time(THREAD5_END);
    func_80004CF4(&D_80083CA0);
}

void func_800017E4(void) {
    func_80004CF4(&D_80083CA0);
    if (D_80083CA0.unk1C8 > 0) {
        do {
            func_80004D20(&D_80083CA0);
        } while (D_80083CA0.unk1C8 > 0);
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
        if (D_800A62E0.unkA38 > 0) {
            func_800017E4();
            continue;
        }
        profiler_log_thread5_time(THREAD5_START);
        D_80083CA0.unkA8A = 1;
        osRecvMesg(&D_8008468C, &sp4C, 1);
        D_80083CA0.unkA8A = 0;
        profiler_log_thread5_time(UNK_EVENT_1);
        profiler_log_thread5_time(UNK_EVENT_2);
        func_8000152C(sp4C);
        func_800015A8();
        osSendMesg(&D_800846A4, (void*)'DONE', 0);
    }
}

void func_800019C8(void) {
    s32 temp_v0 = osTvType;

    if ((temp_v0 != 1) && (temp_v0 != 2)) {
        osViBlack(1U);
        while (1) {
            ;
        }
    }
    osCreateThread(&D_80083CA0.thread, 5, func_8000183C, NULL, &D_80084680, 0x28);
    osStartThread(&D_80083CA0.thread);
    osCreateMesgQueue(&D_8008468C, &D_80084684, 1);
    osCreateMesgQueue(&D_800846A4, &D_80084688, 1);
    D_80083CA0.unkA88 = 0;
    D_80083CA0.unkA8A = 0;
    D_80084680[0] = func_80006314(0, 2, 0x280, 1, 1);
    func_80001AD4(1);
    func_80003B30(&D_80084760, 0xB0000B70, 0xB0000C70, 0);
}

/**
 * Write a specific color to a line on the framebuffer for a 640x480 resolution.
 */
void func_80001AD4(u16 color) {
    s32 width = 640;
    u16* buf = (void*)(uintptr_t)D_80083CA0.unk9E0->unk8;

    while (width-- > 0) {
        *(buf)++ = color;
    }

    osWritebackDCache((void*)(uintptr_t)D_80083CA0.unk9E0->unk8, 0x500);
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
    arg0->unk1 = arg1;
    arg0->unk2 = arg2;
    arg0->unk0 = arg3;
    arg0->unk3 = arg4;
    arg0->unk4 = arg5;
    arg0->unk8 = arg6;
    arg0->unkC = arg7;
}

s32 func_80001C58(void) {
    return D_80084758;
}

void func_80001C64(void) {
    func_80001474((s8)D_80083CA0.unkAAD, (s8)D_80083CA0.unkAAE);
}

s32 func_80001C90(void) {
    s32 result = 1;

    if (D_80083CA0.unkAA0 != 0) {
        result = D_80083CA0.unkA2C > 0;
    }
    return result;
}

void func_80001CB8(void) {
    D_80068B70 = 1;
}

void func_80001CC8(void) {
    D_80068B70 = 0;
}
