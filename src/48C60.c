#include "48C60.h"
#include "38BB0.h"

extern s32 D_80078A18;
extern u8 D_80078A1C;

#pragma GLOBAL_ASM("asm/us/nonmatchings/48C60/func_80048060.s")

void func_80048464(void) {
  if (D_80078A1C != 0) {
      func_800392A8(D_80078A18, (s32)D_80078A1C);
  }
}
