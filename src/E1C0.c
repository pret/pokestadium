#include <ultra64.h>
#include <PR/os_internal_reg.h>
#include "dp_intro.h"
#include "fragments.h"
#include "intro_loader.h"
#include "dp_intro.h"

struct UnkInputStruct8000D738 {
    s32 unk0;
    s32 unk4;
};

struct UnkStruct800AA660 {
    /* 0x0000 */ OSThread thread;
    char padding1B0[0x2030];
    /* 0x21E0 */ OSMesg mesg;
    /* 0x21E4 */ OSMesgQueue queue;
    /* 0x21FC */ s32 unk21FC;
    /* 0x2200 */ s32 unk2200;
    /* 0x2204 */ struct UnkInputStruct8000D738 unk2204;
};

struct UnkStruct800AA664 {
    /* 0x0000 */ OSThread thread;
    char padding1B0[0x2030];
};

extern struct UnkStruct800AA660 *D_800AA660;
extern struct UnkStruct800AA664 *D_800AA664;
extern char D_800AA668;

extern u8 D_81200000[];

// ROM offsets
extern u8 D_3BA190[];
extern u8 D_3CB130[];

// from fragment 1
void func_81206D9C(void);
void func_81206E64(void);
void func_81206F38(void);

// from 3A80.c
extern uintptr_t func_80002E80(uintptr_t addr);

void func_80005370(struct UnkStruct800AA660 *);
void func_80004454(u32, void *, void *);
char func_8000B318(char);
s32 func_800044F4(void *, void *, s32, s32);
s32 func_8000484C(s32, s32);

void func_8000D5C0(void* unused) {
    void (*func)(void *) = func_80002E80(&func_81206F38);
    
    __osSetFpcCsr(0x01000C01);
    func_80004CC0(D_800AA664, 0, 1);
    func_80005328(D_800AA664);

    while(1) {
        func_80004CF4(D_800AA664);
        if (D_800A62E0.unkA38 >= 0x15) {
            continue;
        }
        func(D_800AA664);
    }
}

void func_8000D678(void *unused) {
    void (*func1)(void *func) = func_80002E80(&func_81206D9C);
    void (*func2)(void *func) = func_80002E80(&func_81206E64);

    __osSetFpcCsr(0x01000C01);
    func_80004CC0(D_800AA660, 0, 1);
    func_80005328(D_800AA660);
    func1(D_800AA660);
    osStartThread(D_800AA664);

    while(1) {
        func_80004CF4(D_800AA660);
        if (D_800A62E0.unkA38 >= 0x15) {
            continue;
        }
        func2(D_800AA660);
    }
}

void func_8000D738(struct UnkInputStruct8000D738* arg0) {
    s32 temp_v0;

    func_80002784(0x4742454D);
    D_800AA660 = (void*)func_800025C4(0x2210, 0);
    D_800AA664 = (void*)func_800025C4(0x21E0, 0);
    func_80004454(((u32) ((u32) &fragment1_TEXT_START & 0x0FF00000) >> 0x14) - 0x10, &fragment1_ROM_START, &fragment1_ROM_END);
    temp_v0 = func_800044F4(&D_3BA190, &D_3CB130, 1, 1);
    D_800AA660->unk21FC = func_8000484C(temp_v0, 0);
    D_800AA660->unk2200 = func_8000484C(temp_v0, 1);
    D_800AA660->unk2204 = *arg0;
    osCreateMesgQueue(&D_800AA660->queue, &D_800AA660->mesg, 1);
    osCreateThread(&D_800AA664->thread, 10,  func_8000D5C0, NULL, (u32)D_800AA664 + 0x21E0, 0x11);
    osCreateThread(&D_800AA660->thread, 8,   func_8000D678, NULL, (u32)D_800AA660 + 0x21E0, 0xF);
    D_800AA668 = func_8000B318(0);
    osStartThread(&D_800AA660->thread);
}

OSMesg* func_8000D8A8(void) {
    OSMesg mesg;

    osRecvMesg(&D_800AA660->queue, &mesg, OS_MESG_BLOCK);
    return mesg;
}

void func_8000D8DC(struct UnkInputStruct8000D738* arg0) {
    *arg0 = D_800AA660->unk2204;
    func_8000B318(D_800AA668);
    osViBlack(1U);
    func_80001C64();
    func_80005370(D_800AA660);
    func_80005370(D_800AA664);
    osDestroyThread(&D_800AA660->thread);
    osDestroyThread(&D_800AA664->thread);
    func_80002838(0x4742454D);
}
