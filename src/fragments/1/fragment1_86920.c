#include "global.h"

typedef struct unk_func_81206FA0 {
  /* 0x00 */ s32 unk_00;
  /* 0x04 */ s32 unk_04;
  /* 0x08 */ s32 unk_08;
  /* 0x0C */ s32 unk_0C;
} unk_func_81206FA0; // size = 0x10

typedef struct unk_D_812346EC {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
} unk_D_812346EC;// size = 0x6

typedef struct unk_D_81231450 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} unk_D_81231450;// size = 0x8

typedef struct unk_D_81234650 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} unk_D_81234650;// size = 0x8

typedef struct unk_D_81234690 {
    /* 0x00 */ u8  pad0[2];
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ u8 pad0E[0x2A];
} unk_D_81234690; // size = 0x38

extern s32 D_812286EC;
extern s32 D_812286F0;
extern f32 D_8122AF70;
extern unk_D_81231450 D_81231450[0x640];
extern unk_D_81234650 D_81234650[0x6];
extern unk_func_81206FA0 D_81234680;
extern unk_D_81234690 D_81234690;
extern s32 D_812346C8;
extern s32 D_812346D4;
extern f32 D_812346D8;
extern s32 D_812346DC;
extern void* D_812346E0;
extern unk_D_812346EC D_812346EC;
extern s32 D_812346F2;
extern s32 D_81234700;
extern s32 D_812346FC;

u32 func_81206FA0(unk_func_81206FA0* arg0, s32 arg1) {
  s32 temp_v0;
  u32 temp_a2;
  u32 var_a1;
  temp_v0 = ALIGN16(arg1);
  temp_a2 = arg0->unk_04;
  if ((arg0->unk_00 + arg0->unk_08) >= (temp_a2 + temp_v0)) {
      arg0->unk_04 += temp_v0;
      var_a1 = temp_a2;
      while (var_a1 < arg0->unk_04) {
          *((u8*)var_a1++) = 0;
      }
  } else {
      return 0;
  }
  arg0->unk_0C++;
  return temp_a2;
}

s32 func_81207020(unk_func_81206FA0* arg0, s32 arg1) {
  s32 temp_a2;
  u32 temp_v0;

  temp_v0 = ALIGN16(arg1);
  temp_a2 = arg0->unk_04;
  if ((arg0->unk_00 + arg0->unk_08) >= (arg0->unk_04 + temp_v0)) {
      arg0->unk_04 = temp_v0 + temp_a2;
  } else {
      return 0;
  }
  arg0->unk_0C++;
  return temp_a2;
}


void func_81207078(unk_func_81206FA0* arg0, s32 arg1, s32 arg2) {
  arg0->unk_00 = ALIGN16(arg1);
  arg0->unk_04 = ALIGN16(arg1);
  arg0->unk_08 = (s32) (arg2 - (arg1 & 0xF));
  arg0->unk_0C = 0;
}

#ifdef NON_MATCHING
void func_812070A0(void) {
    unk_D_81231450* var_v0;
    unk_D_81234650* var_v0_2;
    unk_D_812346EC* var_v1_2;
    s32 temp_a0;
    s32 var_a0;
    u32 var_v1;
    unk_D_812346EC* temp_v0;
    unk_D_812346EC* var_v1_3;
    unk_D_812346EC** var_s1;

    D_812346FC = 0;
    temp_a0 = (s32) D_812286EC / 8;
    if (temp_a0 > 0) {
        var_v0 = &D_81231450[0];
        do {
            var_v0 += 8;
            var_v0->unk_04 = 0;
            var_v0->unk_00 = 0;
        } while ((u32) var_v0 < (u32)&D_81231450[temp_a0]);
    }
    var_v0_2 = &D_81234650[0];
    var_v1 = (u32) (&D_81234700 - (s32)&D_81234650) >> 3;
    if ((s32) var_v1 >= 0) {
        do {
            var_v1 -= 1;
            var_v0_2->unk_04 = 0;
            var_v0_2->unk_00 = 0;
            var_v0_2 += 8;
        } while ((s32) var_v1 >= 0);
    }
    D_812346D8 = D_8122AF70;
    D_812346DC = 0x3C;
    D_81234690.unk_02 = 0xBB80U;
    D_81234690.unk_04 = osAiSetFrequency(0xBB80 & 0xFFFF);
    D_81234690.unk_06 = (s16) ((((s32) D_81234690.unk_02 / (s32) D_812346DC) + 0xF) & ~0xF);
    var_v1_2 = &D_812346EC;
    D_81234690.unk_0A = (s16) (D_81234690.unk_06 - 0x10);
    D_81234690.unk_08 = (s16) (D_81234690.unk_06 + 0x10);
    do {
        var_v1_2 += 2;
        var_v1_2->unk_02 = 0xA0;
    } while ((u32) var_v1_2 < (u32) &D_812346F2);
    D_812346C8 = 0;
    D_812346D4 = 0;
    func_81207078(&D_81234680, (s32)&D_81231450, D_812286F0);
    var_s1 = D_812346E0;
    do {
        temp_v0 = func_81207020(&D_81234680, 0xFC0);
        *var_s1 = temp_v0;
        var_v1_3 = temp_v0;
        var_a0 = 0;
loop_9:
        var_a0 += 4;
        var_v1_3->unk_02 = 0;
        var_v1_3->unk_04 = 0;
        var_v1_3->unk_00 = 0;
        var_v1_3 += 8;
        var_v1_3->unk_00 = 0;
        if (var_a0 != 0x7E0) {
            goto loop_9;
        }
        var_s1 += 4;
    } while (*var_s1 != &D_812346EC);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_86920/func_812070A0.s")
#endif
