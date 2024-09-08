#ifndef _5580_H_
#define _5580_H_

#include "global.h"

typedef struct UnkStruct80001380 {
    /* 0x00 */ OSMesg mesg;
    /* 0x04 */ OSMesgQueue queue;
    /* 0x1C */ OSTask task;
} UnkStruct80001380; // size >= 0x7C

void func_800049AC(UnkStruct80001380*);
void func_80005370(struct UnkStruct800AA660*);
void func_800053B4(UnkStruct80001380*, s32);


#endif // _5580_H_
