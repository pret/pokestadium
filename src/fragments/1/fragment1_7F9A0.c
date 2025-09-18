#include "global.h"
#include "fragment1.h"
#include "src/29BA0.h"
#include "src/3FB0.h"
#include "src/5580.h"
#include "src/6BC0.h"
#include "src/controller.h"
#include "src/memory.h"
#include "include/variables.h"

typedef struct unk_D_8122C4FA {
  /* 0x00 */ u8 unk_00;
  /* 0x01 */ u8 unk_01;
} unk_D_8122C4FA; // size >= 0x2

typedef struct unk_D_8122B2F8 {
  /* 0x000000 */ char unk000000[0x1FEAE8];
} unk_D_8122B2F8; // size = 0x1FEAE8

// Gamepak State
typedef struct unk_D_8122B2C0 {
  /* 0x00000 */ char unk00000[0x5388];
  /* 0x05388 */ s32 unk_05388;
  /* 0x0538C */ char unk0538C[0x1C];
  /* 0x053A8 */ void* unk_053A8;
  /* 0x053AC */ void* unk_053AC;
  /* 0x053B0 */ void* unk_053B0;
  /* 0x053B4 */ void* unk_053B4;
  /* 0x053B8 */ char unk053B8[0x4];
  /* 0x053BC */ void* unk_053BC;
  /* 0x053C0 */ char unk053C0[0x46C];
  /* 0x0582C */ u8 unk_0582C[128];
  /* 0x058AC */ char unk058AC[0x3AC];
  /* 0x05C58 */ void* unk_05C58;
  /* 0x05C5C */ char unk_5C5C[0x50];
  /* 0x05CAC */ OSGbpakId gbpakId;
  /* 0x05CFC */ OSPfs* pfs;
  /* 0x05D00 */ char unk05D00[0x70];
  /* 0x05D70 */ s32 unk_5D70;
  /* 0x05D74 */ char unk05D74[0xC];
  /* 0x05D80 */ u32 unk_5D80;
  /* 0x05D84 */ s32 unk_5D84;
  /* 0x05D88 */ s32 unk_5D88;
  /* 0x05D8C */ s32 unk_5D8C;
  /* 0x05D90 */ u32 unk_5D90;
  /* 0x05D94 */ char unk05D94[0x8];
  /* 0x05D9C */ u32 unk_5D9C;
  /* 0x05DA0 */ u16 unk_5DA0;
  /* 0x05DA2 */ u16 unk_5DA2;
  /* 0x05DA4 */ char unk05DA3[0x20];
  /* 0x05DC4 */ u8 unk_5DC4;
  /* 0x05DC5 */ u8 unk_5DC5;
  /* 0x05DC6 */ char unk05DC6[0x2];
  /* 0x05DC8 */ volatile u8 unk_05DC8;
  /* 0x05DC9 */ char unk05DC9[0x1];
  /* 0x05DCA */ u8 unk_5DCA;
  /* 0x05DCB */ u8 status;
  /* 0x05DCC */ u8 unk_5DCC;
  /* 0x05DCD */ char unk05DCD[1];
  /* 0x05DCE */ u8 unk_5DCE;
  /* 0x05DCF */ u8 unk_5DCF;
  /* 0x05DD0 */ u8 unk05DD0[0x15288];
} unk_D_8122B2C0; // size = 0x1B058

typedef struct unk_D_8122B1E8 {
  /* 0x00 */ OSMesg mesg[1];
  /* 0x04 */ OSMesgQueue queue;
  /* 0x1C */ char unk1C[0x4];
  /* 0x20 */ s32 unk_20;
  /* 0x24 */ s32 unk_24;
  /* 0x28 */ char unk28[0x40];
} unk_D_8122B1E8; // size = 0x68

extern unk_D_80068BB0* D_8122B1E0[2];
extern unk_D_8122B1E8 D_8122B1E8[2];
extern s32 D_8122B2B8;
extern unk_D_8122B2C0* D_8122B2C0;
extern unk_D_8122B2F8* D_8122B2C8[3];
extern unk_D_80068BB0* D_8122B2D8[2];
extern void* D_8122B2EC;
extern s32 D_8122B2F0;
extern u8* D_8122B2F4;
extern unk_D_8122B2F8* D_8122B2F8;
extern s32 D_8122B2FC;
extern OSThread D_8122B300;
extern OSMesg D_8122C4B0[4];
extern OSMesgQueue D_8122C4C0;
extern OSMesgQueue* D_8122C4D8;
extern s32 D_8122C4DC;
extern u8 D_8122C4E0;
extern u8 D_8122C4E2;
extern u8 D_8122C4E3;
extern u8 D_8122C4E4;
extern u8 D_8122C4E5;
extern u8 D_8122C4E8;
extern u16 D_8122C4F2;
extern u16 D_8122C4F4;
extern unk_D_8122C4FA D_8122C4FA;
extern u8 D_8122C4FC;
extern u8 D_8122C500[0x1F];
// extern s8 D_8122C51F;
extern u8 D_8122C520[0x20];
extern u8* D_8122C740;
extern u8* D_8122C744;
extern void* D_8122C748;
extern s32 D_8122C74C;
extern u8* D_8122C754;
extern u8* D_8122C758[2];
extern u32 D_8122C760;
extern u32 D_8122C76C;

s32 func_81200020(unk_D_8122B2C0* arg0) {
  s32 result;

  result = osGbpakCheckConnector(&arg0->pfs, &arg0->status);
  if ((result == 0) && ((arg0->status & 9) != 9)) {
      return 0x63;
  }
  return result;
}

s32 func_81200078(unk_D_8122B2C0* arg0, u16 arg1, s32 arg2) {
  s32 i;
  for (i = 0x1F; i >= 0; i--) {
      D_8122C500[i] = arg2;
  }
  return osGbpakReadWrite(&arg0->pfs, 1, arg1, &D_8122C500, 0x20);
}

s32 func_812000DC(unk_D_8122B2C0* arg0) {
  s32 ret;

  if (!(ret = func_81200078(arg0, 0, 0xA))    && !(ret = func_81200078(arg0, 0x6000, 1))
   && !(ret = func_81200078(arg0, 0x4000, 0)) && !(ret = func_81200078(arg0, 0x6000, 0))
   && !(ret = func_81200078(arg0, 0x4000, 0)) && !(ret = func_81200078(arg0, 0x2100, 1))) {
      arg0->unk_5DA2 = 1;
      arg0->unk_5DCE = 0;
      arg0->unk_5DCF = 0;
  }
  
  return ret;
}

s32 func_8120019C(unk_D_8122B2C0* arg0) {
  s32 ret;

  ret = osGbpakGetStatus(&arg0->pfs, &arg0->status);
  if (ret == 0) {
    ret = (arg0->status & 0xC0) ^ 0x80;
  }
  return ret;
}

s32 func_812001E4(unk_D_8122B2C0* arg0, s32 arg1) {
  s32 temp_a2;
  s32 var_v1;

  var_v1 = 0;
  arg0->unk_5DCE = 0xFF;
  if (arg0->unk_5DCF != 0) {
      arg0->unk_5DA2 = 0xFFFFU;
      var_v1 = func_81200078(arg0, 0x6000, 0);
      if (var_v1 == 0) {
          arg0->unk_5DCF = 0U;
      }
  }
  if (var_v1 == 0) {
      if (arg1 != arg0->unk_5DA2) {
          temp_a2 = arg1 / 32;
          if (temp_a2 != ((s32) arg0->unk_5DA2 / 32)) {
              arg0->unk_5DA2 = 0xFFFEU;
              var_v1 = func_81200078(arg0, 0x4000, temp_a2);
          }
          if (var_v1 == 0) {
              arg0->unk_5DA2 = 0xFFFDU;
              var_v1 = func_81200078(arg0, 0x2100, arg1);
              if (var_v1 == 0) {
                  arg0->unk_5DA2 = (u16) arg1;
              }
          }
      }
  }
  return var_v1;
}

s32 func_812002BC(unk_D_8122B2C0* arg0, s32 arg1) {
  s32 var_v1;

  var_v1 = 0;
  arg0->unk_5DA2 = 0xFFFF;
  if (arg0->unk_5DCF != 1) {
      arg0->unk_5DCE = 0xFFU;
      var_v1 = func_81200078(arg0, 0x6000, 1);
      if (var_v1 == 0) {
          arg0->unk_5DCF = 1U;
      }
  }
  if ((var_v1 == 0) && (arg1 != arg0->unk_5DCE)) {
      var_v1 = func_81200078(arg0, 0x4000, arg1);
      if (var_v1 == 0) {
          arg0->unk_5DCE = arg1;
      }
  }
  return var_v1;
}

s32 func_81200358(unk_D_8122B2C0* arg0) {
  s32 ret;

  ret = func_812002BC(arg0, arg0->unk_5DA0 / 8192);
  if (ret == 0) {
      ret = osGbpakReadWrite(&arg0->pfs, 0, ((arg0->unk_5DA0 & 0x1FFF) | 0xA000), D_8122C520, sizeof(D_8122C520));
      if (ret == 0) {
          ret = bcmp(D_8122C520, &arg0->unk_5D80, sizeof(D_8122C520));
      }
  }
  return ret;
}

void func_812003EC(unk_D_8122B2C0*, s32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812003EC.s")

s32 func_812004B8(unk_D_8122B2C0*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812004B8.s")

s32 func_812005D8(unk_D_8122B2C0* arg0) {
  s32 ret;

  ret = 0;
  if (!(arg0->status & 1)) {
    ret = func_81200020(arg0);
      if (ret == 0) {
        ret = func_812000DC(arg0);
          if (ret == 0) {
            ret = osGbpakReadId(&arg0->pfs, &arg0->gbpakId, &arg0->status);
              if (ret == 0) {
                ret = bcmp(arg0->unk_5C5C, &arg0->gbpakId, sizeof(arg0->unk_5C5C));
                  if ((ret == 0) && (arg0->unk_5DC4 != 0)) {
                      arg0->unk_5DC4 = 0U;
                      ret = func_81200358(arg0);
                      if (ret == 0) {
                        ret = func_812004B8(arg0);
                      }
                      arg0->unk_5DC4 = 1U;
                  }
              }
          }
      }
  }
  if (ret != 0) {
      arg0->status = (u8) (arg0->status & 0xFFFE);
  }
  return ret;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812006AC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812008C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812009D0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81200AA8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812011D0.s")

s32 func_81201560(s32 arg0, s32 arg1) {
  return (arg1 & 1) ? arg1 : arg0;
}

s32 func_8120157C(s32 arg0, s32 arg1) {
  return (arg1 & 1) ? arg0 : arg1;
}

s32 func_81201598(s32 arg0, s32 arg1) {
  return (((s32) ((arg0 & 0xF800) + (arg1 & 0xF800)) >> 1) & 0xF800) | (((s32) ((arg0 & 0x7C0) + (arg1 & 0x7C0)) >> 1) & 0x7C0) | (((s32) ((arg0 & 0x3E) + (arg1 & 0x3E)) >> 1) & 0x3E);
}

s32 func_812015E0(UNUSED s32 arg0, s32 arg1) {
  return arg1;
}

void func_812015EC(u16*, u16*, s32, s32, s32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812015EC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812016DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812018C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81201DDC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81201FBC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812020C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81202210.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_8120241C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81202758.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812029B0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81202EA8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81202FCC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_8120311C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81203304.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_8120334C.s")

void func_81200AA8(void *);
void func_81202210(s32, s32);
void func_8120241C(void);
void func_812029B0(u8*, u16 (*)[6][0x640], s32, s32);
void func_8120311C(unk_D_8122B2C0*);
void func_81203304(void);
void func_812070A0(void);
void func_8120735C(s32);
void func_81208C08(s32, s32, s32);
void func_81208D7C(void);
void func_81208E28(unk_D_8122B2F8*);
void func_81208F94(void);
void func_8120935C(s32);

void func_812033F4(s32, s32, OSId, s32, OSMesgQueue*, u16 (*arg5)[6][0x640]);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812033F4.s")

void func_81203C58(unk_D_8122B2C0* arg0);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81203C58.s")

void func_81203E30(void) {
  if ((D_8122C4FA.unk_01 == D_8122C4FA.unk_00) || (D_8122C4FA.unk_00 >= 5) || (D_8122C4FA.unk_01 >= 5)) {
      D_8122C4FA.unk_00 = 0;
      D_8122C4FA.unk_01 = 1;
  }

  D_8122C4F2 = (D_8122C4FA.unk_00 == 1) ?   0x20 : (D_8122C4FA.unk_00 == 2) ? 0x10 : (D_8122C4FA.unk_00 == 3) ? 2 : (D_8122C4FA.unk_00 == 4) ? 4 : 0x1000;
  D_8122C4F4 = (D_8122C4FA.unk_01 == 0) ? 0x1000 : (D_8122C4FA.unk_01 == 2) ? 0x10 : (D_8122C4FA.unk_01 == 3) ? 2 : (D_8122C4FA.unk_01 == 4) ? 4 : 0x20;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81203F3C.s")

void func_81204A84(s32 arg0);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81204A84.s")

s32 func_8120572C(s32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_8120572C.s")

void func_81206D9C(unk_D_800AA660* arg0) {
  D_8122C4FC = 0;
  D_8122C4E2 = arg0->unk_2204.unk_02;
  if ((D_8122C4E2 < 0) || (D_8122C4E2 >= 3)) {
      D_8122C4E2 = 0;
  }
  D_8122C4FA.unk_00 = ((arg0->unk_2204.unk_00 & 0xFF00) >> 8);
  D_8122C4FA.unk_01 = (arg0->unk_2204.unk_00 + 1) & 0xFF;
  func_81203E30();
  D_8122C740 = arg0->font1 + 0x90;
  D_8122C744 = arg0->font2 + 0x90;
  func_812033F4(0, func_80029080(), 5, 0x50, &gSIEventMesgQueue, arg0->unk_2204.unk_04);
}

void func_81206E64(unk_D_800AA660* arg0) {
  if (func_8120572C(0) != 0) {
      arg0->unk_2204.unk_00 = ((D_8122C4FA.unk_01 - 1) & 0xFF) | (D_8122C4FA.unk_00 << 8);
      IO_WRITE(SP_STATUS_REG, 0x8000);
      osSendMesg(&arg0->queue2, D_8122B2FC, 0);
  }

  if (D_8122C4FC == 0) {
      if ((D_8122C4DC == 0) || (D_8122C4DC == 6)) {
          func_81209078();
      }
  } else if (D_8122C4FC == 1) {
      D_8122C4FC = 2;
  } else if (D_8122C4FC == 3) {
      D_8122C4FC = 0;
  }
}

void func_81206F38(UNUSED unk_D_800AA664* arg0) {
  if ((D_800A62E0.unk_A38 == 0) && (D_8122C4FC == 2) && ((D_8122C4DC == 0) || (D_8122C4DC == 6))) {
      func_81209078();
  }
}
