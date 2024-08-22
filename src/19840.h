#ifndef _19840_H_
#define _19840_H_

#include "global.h"
#include "src/memory.h"

// seems like unk_D_86002F58_004_000, but unk_20 and unk_24 need to be s32
typedef struct unk_func_8001C248 {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001;
    /* 0x002 */ u8 unk_002;
    /* 0x003 */ char pad3[9];
    /* 0x00C */ unk_D_86002F58_004_000_00C* unk_00C;
    /* 0x010 */ unk_D_86002F58_004_000_010* unk_010;
    /* 0x024 */ s32 unk_014;
    /* 0x018 */ s16 unk_018;
    /* 0x01A */ s16 unk_01A;
    /* 0x01C */ u8 unk_01C;
    /* 0x01D */ u8 unk_01D;
    /* 0x01E */ char unk01E[0x2];
    /* 0x020 */ s32 unk_020;
    /* 0x024 */ s32 unk_024;
} unk_func_8001C248;

void func_8001987C(void);
void func_80019A7C(unk_D_86002F58_004_000_010*, s32, s32, unk_func_8001C248*);
s32 func_80019C08(unk_D_86002F58_004_000_010*, unk_func_8001C248*);
s32 func_80019C58(unk_D_86002F58_004_000_010*, unk_func_8001C248*);
s32 func_80019CA8(unk_D_86002F58_004_000_010*);
void func_80019CE0(unk_D_86002F58_004_000_010*);
unk_D_86002F30* func_80019D18(s32);
void func_800198E4(unk_D_86002F58_004_000_010*, u16, s32);


#endif // _19840_H_
