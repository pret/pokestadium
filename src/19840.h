#ifndef _19840_H_
#define _19840_H_

#include "global.h"
#include "src/3FB0.h"
#include "src/F420.h"
#include "src/1C720.h"

typedef struct arg1_func_80019420 {
    /* 0x00 */ s8 unk_00;
    /* 0x04 */ void* unk_04;
} arg1_func_80019420; // size = 0x8

typedef struct unk_func_80019600 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ OSMesgQueue* queue;
    /* 0x08 */ void* unk_08;
    /* 0x0C */ void* unk_0C;
    /* 0x10 */ MainPoolState* pool;
    /* 0x14 */ s32 size;
    /* 0x18 */ arg1_func_80010CA8 unk_18;
} unk_func_80019600; // size >= 0x1C

typedef struct sp18_func_800198E4 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ unk_D_86002F58_004_000_010_02C unk_18;
} sp18_func_800198E4; // size = 0x1C

typedef struct unk_D_800ABE10_A04 {
    /* 0x00 */ BinArchive* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
} unk_D_800ABE10_A04; // size >= 0x14

typedef struct unk_D_800ABE10 {
    /* 0x000 */ OSThread unk_000;
    /* 0x1B0 */ char unk1B0[0x800];
    /* 0x9B0 */ OSMesg unk_9B0;
    /* 0x9B4 */ char unk9B4[0x1C];
    /* 0x9D0 */ OSMesgQueue unk_9D0;
    /* 0x9E8 */ OSMesg unk_9E8;
    /* 0x9EC */ OSMesgQueue unk_9EC;
    /* 0xA04 */ unk_D_800ABE10_A04 unk_A04;
} unk_D_800ABE10; // size >= 0xA18

extern unk_D_800ABE10 D_800ABE10;

void func_80018C40(unk_D_86002F34* arg0, arg1_func_80010CA8 arg1);
Fragment* func_80018DE8(MemoryBlock* arg0, PRESJPEG* arg1, PRESJPEG* arg2);
Fragment* func_80018E7C(MainPoolState* arg0, PERSSZP* arg1, PERSSZP* arg2);
Fragment* func_80018EC4(MainPoolState* arg0, PERSSZP* arg1, s32 arg2, u32 arg3);
Fragment* func_80018F20(MainPoolState* arg0, s32 start, s32 end, PERSSZP* arg3, s32 arg4);
Fragment* func_80018FF4(MainPoolState* arg0, unk_func_800041C0* arg1, PERSSZP* arg2, u32 arg3);
void func_80019128(MainPoolState* arg0, u32 arg1, Fragment* arg2);
Fragment* func_80019170(MainPoolState* arg0, BinArchive* arg1, BinArchiveFile* arg2, u32 arg3, s32 arg4);
Fragment* func_800191B0(MainPoolState* arg0, BinArchive* arg1, BinArchiveFile* arg2, u32 arg3, s32 arg4);
Fragment* func_80019204(MainPoolState* arg0, BinArchive* arg1, s32 arg2, u32 arg3, s32 arg4);
s32 func_80019328(MemoryBlock* arg0, Fragment* arg1, arg1_func_80010CA8 arg2);
void func_80019420(MemoryBlock* arg0, arg1_func_80019420* arg1);
void func_80019484(unk_func_80019600* arg0);
void func_80019514(unk_func_80019600* arg0);
void func_80019600(UNUSED void* arg0);
void func_800196DC(void);
unk_D_86002F58_004_000_010* func_80019760(u32 arg0);
void func_8001987C(void);
s32 func_800198E4(unk_D_86002F58_004_000_010* arg0, u16 arg1, unk_D_86002F58_004_000_010_02C arg2);
s32 func_80019A1C(unk_D_86002F58_004_000_010* arg0, u16 arg1, unk_D_86002F58_004_000_010_02C arg2, s16 arg3);
s32 func_80019A7C(unk_D_86002F58_004_000_010* arg0, s32 arg1, s32 arg2);
s32 func_80019B48(unk_D_86002F58_004_000_010* arg0, sp18_func_800198E4* arg1);
s32 func_80019C08(unk_D_86002F58_004_000_010* arg0);
s32 func_80019C58(unk_D_86002F58_004_000_010* arg0);
s32 func_80019CA8(unk_D_86002F58_004_000_010* arg0);
s32 func_80019CE0(unk_D_86002F58_004_000_010* arg0);
unk_D_86002F30* func_80019D18(s32 arg0);
unk_D_86002F30* func_80019D90(unk_func_80026268_arg0* arg0);
s32 func_80019E18(s32 arg0, s32 arg1);
arg1_func_80019420* func_80019EA0(s32 arg0);
Fragment* func_80019F0C(MainPoolState* arg0, u32 arg1, s32 arg2, s32 arg3, PERSSZP* arg4, s32 arg5);


#endif // _19840_H_
