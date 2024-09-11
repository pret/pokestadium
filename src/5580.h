#ifndef _5580_H_
#define _5580_H_

#include "global.h"

typedef struct UnkStruct80001380 {
    /* 0x00 */ OSMesg mesg;
    /* 0x04 */ OSMesgQueue queue;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x1C */ OSTask task;
    /* 0x60 */ char unk60[0x8];
} UnkStruct80001380; // size = 0x68

typedef struct UnkStruct800A62E0 {
    /* 0x000 */ char unk000[0x9F0];
    /* 0x9F0 */ OSMesgQueue queue;
    /* 0xA08 */ char unkA08[0x8];
    /* 0xA10 */ UnkStruct800AA660* unk_A10;
    /* 0xA14 */ char unkA14[0x8];
    /* 0xA1C */ UnkStruct80001380* unk_A1C;
    /* 0xA20 */ UnkStruct80001380* unk_A20;
    /* 0xA24 */ UnkStruct80001380* unk_A24;
    /* 0xA28 */ char unkA28[0x10];
    /* 0xA38 */ s16 unk_A38;
} UnkStruct800A62E0; // size >= 0xA3C

extern UnkStruct800A62E0 D_800A62E0;

void func_80004980(UnkStruct80001380* arg0);
void func_800049AC(UnkStruct80001380* arg0);
void func_80005370(UnkStruct800AA660* arg0);
void func_800053B4(UnkStruct80001380* arg0, s32 arg1);


#endif // _5580_H_
