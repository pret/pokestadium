#ifndef _22630_H_
#define _22630_H_

#include "global.h"

typedef struct unk_func_80026268_arg0 {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ char unk05[0x1F];
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ char unk26[0xA];
    /* 0x30 */ u8 unk_30[11];
    /* 0x3B */ u8 unk_3B[11];
    /* 0x46 */ u8 unk_46[11];
    /* 0x51 */ char unk51[0x1];
    /* 0x52 */ u8 unk_52;
    /* 0x52 */ u8 unk_53;
} unk_func_80026268_arg0; // size >= 0x54

typedef struct unk_D_800AE4E8_004_1_000_010 {
    /* 0x00 */ char unk00[0x21];
    /* 0x21 */ u8 unk_21[11];
    /* 0x2C */ u8 unk_2C[11];
} unk_D_800AE4E8_004_1_000_010; // size = 0x37

void func_80021B7C(u8*, u8*);
void func_80021C40(u8*, u8*);
void func_80021CA4(char*, u8);
void func_80021D9C(unk_func_80026268_arg0*, unk_D_800AE4E8_004_1_000_010*);
void func_80021F04(unk_func_80026268_arg0*, unk_D_800AE4E8_004_1_000_010*);
void func_80022338(unk_func_80026268_arg0*);
void func_80023068(void);
s32 func_8002311C(s32);
void func_80024040(s16);
void func_800240A0(void);


#endif // _6BC0_H_
