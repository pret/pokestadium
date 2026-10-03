#include "global.h"

typedef struct unk_func_81206FA0 {
  /* 0x00 */ s32 unk_00;
  /* 0x04 */ s32 unk_04;
  /* 0x08 */ s32 unk_08;
  /* 0x0C */ s32 unk_0C;
} unk_func_81206FA0; // size = 0x10

typedef struct unk_D_81234690 {
    /* 0x00 */ u8  pad0[2];
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ u8 pad0E[0x2A];
} unk_D_81234690; // size = 0x38

// .data
extern s32 D_812286EC;
extern s32 D_812286F0;

// .rodata
extern f32 D_8122AF70;

// .bss
extern u64 D_81231450[0x640];
extern u64 D_81234650[0x6];
extern unk_func_81206FA0 D_81234680;
extern unk_D_81234690 D_81234690;
extern volatile s32 D_812346C8;
extern s32 D_812346D4;
extern f32 D_812346D8;
extern s32 D_812346DC;
extern s16* D_812346E0[3];
extern s16 D_812346EC[3];
extern s16 D_812346F2;
extern s32 D_81234700;
extern volatile u32 D_812346FC;

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

void func_812070A0(void) {
    u64* var_v0_2;
    s16* var_v1_2;
    s32 var_a0;
    u32 var_v1;
    s16* var_v1_3;
    s32 i;

    D_812346FC = 0;
    for (i = 0; i < D_812286EC / 8; i++) {
        D_81231450[i] = 0;
    }
    var_v0_2 = D_81234650;
    var_v1 = (u32) ((s32) &D_81234700 - (s32) D_81234650) >> 3;
    if ((s32) var_v1 >= 0) {
        do {
            var_v1--;
            *var_v0_2 = 0;
            ++var_v0_2;
        } while ((s32) var_v1 >= 0);
    }
    D_812346D8 = D_8122AF70;
    D_812346DC = 0x3C;
    do {} while (0);
    D_81234690.unk_02 = 0xBB80;
    D_81234690.unk_04 = osAiSetFrequency(D_81234690.unk_02);
    D_81234690.unk_06 = (s16) (((D_81234690.unk_02 / D_812346DC) + 0xF) & ~0xF);
    var_v1_2 = (s16*) &D_812346EC;
    D_81234690.unk_0A = (s16) (D_81234690.unk_06 - 0x10);
    D_81234690.unk_08 = (s16) (D_81234690.unk_06 + 0x10);
    do {
        *var_v1_2 = 0xA0;
        var_v1_2++;
    } while (var_v1_2 < (s16*) &D_812346F2);
    D_812346C8 = 0;
    D_812346D4 = 0;
    func_81207078(&D_81234680, (s32) D_81231450, D_812286F0);
    for (i = 0; i < 3; i++) {
        D_812346E0[i] = (s16*) func_81207020(&D_81234680, 0xFC0);
        var_v1_3 = D_812346E0[i];
        for (var_a0 = 0; var_a0 != 0xFC0 / 2; var_a0++) {
            *var_v1_3 = 0;
            var_v1_3++;
        }
    }
}
