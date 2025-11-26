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

typedef struct unk_D_8122B1E8 {
  /* 0x00 */ OSMesg mesg[1];
  /* 0x04 */ OSMesgQueue queue;
  /* 0x1C */ char unk1C[0x4];
  /* 0x20 */ s32 unk_20;
  /* 0x24 */ s32 unk_24;
  /* 0x28 */ char unk28[0x40];
} unk_D_8122B1E8; // size = 0x68

typedef struct unk_func_812009D0 {
  /* 0x00 */ u8 unk00[0x34];
  /* 0x34 */ u8 data[0x10];  
  /* 0x44 */ u16 unk_44;
  /* 0x46 */ u8 unk_46;
  /* 0x47 */ u8 unk47;
  /* 0x48 */ u8 unk_48;
  /* 0x49 */ u8 unk_49;
  /* 0x4A */ u8 unk_4A;
} unk_func_812009D0; // size = 0x4B

typedef struct unk_D_8122C748 {
  /* 0x0000 */ u8 unk0000[0x9790];
  /* 0x9790 */ s32 unk_9790;
  /* 0x9794 */ u8 unk[0xFC];
  /* 0x9890 */ s32 unk_9890;
  /* 0x9894 */ u8 data[0xFC];
  /* 0x9990 */ s32 unk_9990;
} unk_D_8122C748; // size = 0x9994

extern unk_D_80068BB0* D_8122B1E0;
extern unk_D_80068BB0* D_8122B1E4;
extern u8 D_8120D820[200];
extern u8 D_8120DD70;
extern unk_D_8122B1E8 D_8122B1E8[2];
extern s32 D_8122B224[];
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
extern unk_D_8122C748* D_8122C748;
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

void func_812003EC(unk_D_8122B2C0* arg0, s32 arg1) {
  s32 i;

  switch (arg1) {
      case 3:
          for (i = 0; i < 8; i++) {
              arg0->unk_5D80[i] = 0;
          }
          break;
      case 2:
          for (i = 0; i < 8; i++) {
              arg0->unk_5D80[i] = -1;
          }
          break;
      case 1:
          osDpGetCounters(arg0->unk_5D80);
          arg0->unk_5D80[3] = osGetCount();
          osWritebackDCacheAll();
          osDpGetCounters(arg0->unk_5D90);
          arg0->unk_5D90[3] = osGetCount();
          break;
  }
}

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

s32 func_812006AC(unk_D_8122B2C0* arg0);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812006AC.s")

s32 func_812008C8(unk_D_8122B2C0* arg0, s32 arg1) {
  s32 temp_v0;
  s32 var_s0;
  s32 var_s1;
  u8* var_s3;
  s32 var_v0;
  s32 var_v1;
  u32 var_s2;

  var_v0 = func_812005D8(arg0);
  var_v1 = var_v0;
  var_s3 = arg0->transferBuffer;
  var_s2 = arg0->gbAddress;
  var_s1 = arg0->transferSize;
  while ((var_v0 == 0) && (var_s1 != 0)) {
      var_v0 = func_812002BC(arg0, var_s2 >> 0xD);
      var_v1 = var_v0;
      if (var_v0 == 0) {
          temp_v0 = var_s2 & 0x1FFF;
          if ((u32) (temp_v0 + var_s1) >= 0x2001U) {
              var_s0 = 0x2000 - temp_v0;
          } else {
              var_s0 = var_s1;
          }
          var_v0 = osGbpakReadWrite(&arg0->pfs, arg1, (temp_v0 | 0xA000) & 0xFFFF, var_s3, var_s0);
          var_v1 = var_v0;
          var_s3 += var_s0;
          var_s1 -= var_s0;
          var_s2 = (var_s2 + 0x2000) & ~0x1FFF;
      }
  }
  if (var_v0 == 0) {
      var_v1 = func_8120019C(arg0);
  }
  return var_v1;
}

s32 func_812009D0(unk_func_812009D0* arg0) {
  u8* var_s1;
  s32 i;

  var_s1 = &D_8120DD70;
  for (i = 4; i > 0; i--) {
      if (
          (bcmp(var_s1, arg0->data, 0x10) == 0) &&
          (arg0->unk_44 == 0x3031) &&
          (arg0->unk_46 == 3) &&
          (arg0->unk_48 == 5) &&
          (arg0->unk_49 == 3) &&
          (arg0->unk_4A != 0)
      ) {
         return i;
      }
      var_s1 -= 0x10;
  }
  return i;
}

void func_81200AA8(void *);
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

void func_812015EC(u16* dst, u16* src, s32 mode, s32 width, s32 height) {
  s32 (*operation)(s32, s32);
  s32 x;
  s32 y;
  width = ((width + 3) & 0xFFC);
  switch (mode) {
      case 0:  operation = func_81201560; break;
      case 1:  operation = func_8120157C; break;
      case 2:  operation = func_81201598; break;
      default: operation = func_812015E0; break;
  }

  for (x = 0; x != height; x++) {
      for (y = 0; y != width; y++) {
          *dst = operation(*dst, *src);
          dst++;
          src++;
      }
      dst = dst - width + 0x140;
  }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812016DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812018C0.s")

#ifdef NON_MATCHING
void func_81201DDC(u16* dst, u8* alpha_map, s32 color, s32 width, s32 height, u32 alpha_stride) {
  u16* dst_row;
  u8* alpha_row;
  s32 x;
  s32 y;
  s32 var_t0;
  s32 var_t4;
  s32 var_a0;

  for (y = 0; y < height; y++) {
      for (x = 0; x < width; x++) {
          var_a0 = alpha_map[y * alpha_stride + x];

          var_t0 = (dst[y * 320 + x] & 0xF800) + ((((color & 0xF800) * (var_a0 & 0xF)) / 15) & 0xF800);
          if (var_t0 > 0xF800) var_t0 = 0xF800;

          var_t4 = var_t0;

          var_t0 = (dst[y * 320 + x] & 0x07C0) + ((((color & 0x07C0) * (var_a0 & 0xF)) / 15) & 0x07C0);
          if (var_t0 > 0x07C0) var_t0 = 0x07C0;
          
          var_t4 |= var_t0;

          var_t0 = (dst[y * 320 + x] & 0x003E) + ((((color & 0x003E) * (var_a0 & 0xF)) / 15) & 0x003E);
          if (var_t0 > 0x003E) var_t0 = 0x003E;

          dst[y * 320 + x] = (s16)(var_t4 | var_t0);
      }
  }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81201DDC.s")
#endif

void func_81201FBC(s32 arg0, s32 arg1, s32 arg2) {
  s32 var_s0;
  s32 var_s1;
  s32 i;

  for (i = 8; i < arg2 - 8; i += 8) {
      func_812018C0(arg0 + i * 2, &D_8122C748->unk_9890, arg1, 8, 0x10);
  }
  func_812018C0(arg0, &D_8122C748->unk_9790, arg1, 8, 0x10);
  func_812018C0(arg0 + (arg2 - 8) * 2, &D_8122C748->unk_9990, arg1, 8, 0x10);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812020C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81202210.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_8120241C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81202758.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812029B0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81202EA8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81202FCC.s")

void func_8120311C(unk_D_8122B2C0* arg0) {
  s32 i;
  s32 var_a0;
  u8* var_a1;

  bzero(arg0->unk_00, 0x208);
  bzero(arg0->unk_208, 0x40);
  bzero(arg0->unk_248, 0x40);
  bzero(arg0->unk_388, 0x400);
  bzero(arg0->unk_788, 0x4000);
  bzero(arg0->unk_549C, 0x100);
  bzero(arg0->unk_559C, 0x10);
  bzero(arg0->unk_55AC, 0x40);
  bzero(arg0->unk_55EC, 0x40);
  bzero(arg0->unk_582C, 0x200);
  bzero(arg0->unk_5A2C, 0x200);
  bzero(arg0->unk_562C, 0x200);
  bzero(arg0->unk_53B4, 0x6000);

  for (i = 0; i < 0x80; i++) {
      arg0->unk_582C[i] = 0xFE;
      arg0->unk_5A2C[i] = 0xFF;
  }

  for (i = 0; i < 0x400; i++) {
      arg0->unk_388[i] = 0xFF;
  }

  var_a0 = 0;
  for (i = 0x10; i < 0x1A0; i += 2) {
      arg0->unk_788[i] = D_8120D820[var_a0];
      var_a0++;
  }

  var_a0 = 1;
  for (i = 0x1904; i < 0x1910; i++) {
      arg0->unk_788[i] = var_a0;
      arg0->unk_788[i + 32] = var_a0 + 0xC;
      var_a0 += 1;
  }
  arg0->unk_788[i] = 0x19;

  for (i = 1; i < 0x1A; i++) {
      arg0->unk_388[i] = 0;
  }

  for (i = 0x190; i < 0x193; i++) {
      arg0->unk_388[i] = 0;
  }

  arg0->unk_539C = 0x25800;
  arg0->unk_53FC = 0;
  arg0->unk_53FD = 0;
  arg0->unk_53EE = 0x140;
  arg0->unk_53FE = 0x30;
  arg0->unk_53F0 = 0x7C;
  arg0->unk_5485 = 1;
  arg0->unk_5390 = 0;
  arg0->unk_548E = 1;
  arg0->unk_5394 = 0x8000;
  arg0->unk_5398 = 0x8000;

  func_81209870(arg0);
}

void func_81203304(void) {
  bzero(D_8122B1E0->img_p, 0x2D000);
  bzero(D_8122B1E4->img_p, 0x2D000);
}

void func_8120334C(OSTime arg0) {
  OSMesgQueue sp68;
  void* sp64;
  OSTimer sp40;

  osCreateMesgQueue(&sp68, &sp64, 1);
  osSetTimer(&sp40, (1000 * arg0) * 64 / 3, 0, &sp68, NULL);
  osRecvMesg(&sp68, NULL, 1);
}

void func_81202210(s32, s32);
void func_8120241C(void);
void func_812029B0(u8*, u16 (*)[6][0x640], s32, s32);
void func_812070A0(void);
void func_8120735C(s32);
void func_81208C08(s32, s32, s32);
void func_81208D7C(void);
void func_81208E28(unk_D_8122B2F8*);
void func_81208F94(void);
void func_8120935C(s32);

void func_812033F4(s32, s32, OSId, s32, OSMesgQueue*, u16 (*arg5)[6][0x640]);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812033F4.s")

void func_81203C58(unk_D_8122B2C0*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81203C58.s")

void func_81203E30(void) {
  if ((D_8122C4FA.unk_01 == D_8122C4FA.unk_00) || (D_8122C4FA.unk_00 >= 5) || (D_8122C4FA.unk_01 >= 5)) {
      D_8122C4FA.unk_00 = 0;
      D_8122C4FA.unk_01 = 1;
  }

  D_8122C4F2 = (D_8122C4FA.unk_00 == 1) ?   0x20 : (D_8122C4FA.unk_00 == 2) ? 0x10 : (D_8122C4FA.unk_00 == 3) ? 2 : (D_8122C4FA.unk_00 == 4) ? 4 : 0x1000;
  D_8122C4F4 = (D_8122C4FA.unk_01 == 0) ? 0x1000 : (D_8122C4FA.unk_01 == 2) ? 0x10 : (D_8122C4FA.unk_01 == 3) ? 2 : (D_8122C4FA.unk_01 == 4) ? 4 : 0x20;
}

void func_81203F3C(unk_D_8122B2C0*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81203F3C.s")

void func_81204A84(s32);
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
