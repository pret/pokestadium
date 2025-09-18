#ifndef _E1C0_H_
#define _E1C0_H_

#include "global.h"

typedef struct unk_D_800AA664 {
  /* 0x0000 */ OSThread thread;
  /* 0x01B0 */ char unk01B0[0x2030];
} unk_D_800AA664; // size = 0x21E0

void func_8000D738(UnkInputStruct8000D738* arg0);
OSMesg* func_8000D8A8(void);
void func_8000D8DC(UnkInputStruct8000D738* arg0);

#endif // _E1C0_H_
