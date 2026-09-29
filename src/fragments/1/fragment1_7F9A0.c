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
  /* 0x9794 */ u8 unk9794[0xFC];
  /* 0x9890 */ s32 unk_9890;
  /* 0x9894 */ u8 unk9894[0xFC];
  /* 0x9990 */ s32 unk_9990;
  /* 0x9994 */ u8 unk9994[0xFC];
  /* 0x9A90 */ u16 unk_9A90[0x42];
  /* 0x9B14 */ u8 unk9B14[0x82];
  /* 0x9B96 */ u16 unk_9B96[0x42];
} unk_D_8122C748; // size = 0x9C1A

typedef struct unk_D_8120E480 {
  /* 0x00 */ s32 value;
  /* 0x04 */ u8 unk04[0x3F];
  /* 0x43 */ u8 unk_43;
} unk_D_8120E480; // size = 0x44

typedef struct unk_D_8120D7F3 {
    u8 pad[0x116];
    u8 unk116;
} unk_D_8120D7F3; // size = 0x10A ??

typedef struct unk_func_8120241C_80 {
    u8 pad[0x80];
    u8 unk80;
} unk_func_8120241C_80; // size = 0x81

// ??
extern unk_D_8120D7F3 D_8120D7F3;

// .data
extern s16 D_8120E300[];
extern s16 D_8120E320[];
extern s16 D_8120E340[];
extern s16 D_8120E360[];
extern s16 D_8120E380[];
extern s16 D_8120E3A0[];
extern s16 D_8120E3C0[];
extern s16 D_8120E3E0[];
extern s16 D_8120E400[];
extern s16 D_8120E420[];
extern s16 D_8120E440[];
extern s16 D_8120E460[];
extern unk_D_8120E480 D_8120E480[];
extern u8 D_8120E580[256];
extern u16 D_8120E680[4];

// .rodata
extern u8 D_8122AD50[];

// .bss
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
extern s32 D_8122B2E0;
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
extern s8 D_8122C4E7;
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
extern s32 D_8122C750;
extern u8* D_8122C754;
extern u8* D_8122C758[2];
extern u32 D_8122C760;
extern u32 D_8122C764;
extern u32 D_8122C768;
extern u32 D_8122C76C;
extern u8 D_8122C770;
extern u8 D_8122C771;

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

s32 func_812004B8(unk_D_8122B2C0* arg0) {
    s32 ret;
    s32 count;

    count = 3;
    do {
        func_812003EC(arg0, count);
        ret = func_812002BC(arg0, arg0->unk_5DA0 / 8192);
        if (ret == 0) {
            ret = osGbpakReadWrite(&arg0->pfs, 1, ((arg0->unk_5DA0 & 0x1FFF) | 0xA000), &arg0->unk_5D80, sizeof(D_8122C520));
            if (ret == 0) {
                ret = osGbpakReadWrite(&arg0->pfs, 0, ((arg0->unk_5DA0 & 0x1FFF) | 0xA000), D_8122C520, sizeof(D_8122C520));
                if (ret == 0) {
                    ret = bcmp(D_8122C520, &arg0->unk_5D80, sizeof(D_8122C520));
                    if (ret == 0) {
                        count -= 1;
                        if (count == 0) {
                            arg0->unk_5DC4 = 1;
                            break;
                        }
                    }
                }
            }
        }
    } while ((ret == 0));
    return ret;
}

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

s32 func_812006AC(unk_D_8122B2C0* arg0) {
    s32 var_s1 = 0;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s4;
    s32 var_v1;
    u32 var_s3;
    u8* var_s0;
    u32 offset;
    s32 i;
    u32 temp;
    var_v1 = func_812005D8(arg0);
    var_s0 = arg0->transferBuffer;
    var_s3 = arg0->gbAddress;
    var_s4 = arg0->transferSize;

    if (var_v1 == 0 && var_s3 < 0x4000U) {
        temp = var_s3;
        temp += var_s4;
        if (temp >= 0x4001U) {
            var_s2 = 0x4000 - var_s3;
        } else {
            var_s2 = var_s4;
        }

        var_v1 = osGbpakReadWrite(&arg0->pfs, 0, var_s3, var_s0, var_s2);

        if (var_v1 == 0) {
            var_v1 = var_s2;

            while (var_v1 != 0) {
                var_s1 += *var_s0;
                var_s0++;
                var_v1--;
            }
            var_s4 -= var_s2;
            var_s3 = 0x4000;
        }
    }

    while (var_v1 == 0 && var_s4 != 0) {
        var_v1 = func_812001E4(arg0, var_s3 >> 14);
        if (var_v1 == 0) {
            offset = var_s3 & 0x3FFF;
            temp = offset;
            temp += var_s4;
            if (temp >= 0x4001U) {
                var_s2_2 = 0x4000 - offset;
            } else {
                var_s2_2 = var_s4;
            }
    
            var_v1 = osGbpakReadWrite(&arg0->pfs, 0, (offset | 0x4000), var_s0, var_s2_2);
    
            if (var_v1 == 0) {
                var_v1 = var_s2_2;
    
                    while (var_v1 != 0) {
                        var_s1 += *var_s0;
                        var_s0++;
                        var_v1--;
                    }
    
                var_s4 -= var_s2_2;
                var_s3 = (var_s3 + 0x4000) & ~0x3FFF;
            }
        }
    }

    if (var_v1 == 0) {
        var_v1 = func_8120019C(arg0);
        if (var_v1 == 0) {
            arg0->unk_5D70[0] += var_s1;
        }
    }

    return var_v1;
}

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

void func_812016DC(void*);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812016DC.s")

#ifdef NON_MATCHING
void func_812018C0(u16* arg0, s32 arg1, u16* arg2, s32 arg3, s32 arg4) {
    s32 r = arg1 & 0xF800;
    s32 g = arg1 & 0x7C0;
    s32 b = arg1 & 0x3E;
    s32 x;
    s32 y;

    for (y = 0; y < arg4; y++) {
        u16* dst = &arg0[y * 160];
        u16* src = &arg2[y * arg3];
        for (x = 0; x < arg3; x++) {
            s32 intensity = (s32) (src[x] & 0x3E) >> 1;
            dst[x] = (((r * intensity) / 31) & 0xF800) | (((g * intensity) / 31) & 0x7C0) | (((b * intensity) / 31) & 0x3E);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812018C0.s")
#endif

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
            var_a0 = alpha_map[y * alpha_stride + x] & 0xF;

            var_t0 = (dst[y * 320 + x] & 0xF800) + ((((color & 0xF800) * (var_a0)) / 15) & 0xF800);
            if (var_t0 > 0xF800) var_t0 = 0xF800;

            var_t4 = var_t0;

            var_t0 = (dst[y * 320 + x] & 0x07C0) + ((((color & 0x07C0) * (var_a0)) / 15) & 0x07C0);
            if (var_t0 > 0x07C0) var_t0 = 0x07C0;
            
            var_t4 |= var_t0;

            var_t0 = (dst[y * 320 + x] & 0x003E) + ((((color & 0x003E) * (var_a0)) / 15) & 0x003E);
            if (var_t0 > 0x003E) var_t0 = 0x003E;

            dst[y * 320 + x] = (s16)(var_t4 | var_t0);
        }
    }
}

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

void func_812020C0(u16* dst, s32 arg1, s32 arg2) {
  u16* src;
  s32 offset;
  s32 row;
  s32 col;
  u16 val;

  offset = arg2 * 132;
  if (arg1 != 0) {
      src = (u16*) (offset * 2 + (u8*) D_8122C748 + 0x9A90);
      arg1 = 1;
  } else {
      src = (u16*) (offset * 2 + (u8*) D_8122C748 + 0x9B96);
      arg1 = -1;
  }

  for (row = 0; row < 11; row++) {
      for (col = 0; col < 12; col++) {
          val = *src;
          if (val & 1) {
              dst[row * 320 + col + 730] = val;
          }
          src += arg1;
      }
  }
}

#ifdef NON_MATCHING
void func_81202210(s32 arg0, s32 arg1) {
    s32 i;
    s32 var_s1;
    unk_D_80068BB0* temp_a0;
    s32 var_v0;
    u8 temp_t8;
    u8 var_s2;
    u8 var_s2_3;
    u8* var_s0;
    u8* temp_s7;

    temp_a0 = D_8122B2D8[arg0];
    bzero(temp_a0, 0x2800);
    temp_s7 = (u8*)temp_a0 + 0xAA;
    var_s2 = D_8122B2C0->unk_5DC5;
    if (var_s2 != 0) {
        var_s2 -= 1;
    }
    func_81201FBC(temp_s7, D_8120E680[var_s2], 0x70);
    var_v0 = 9;
    var_s1 = 0;
    if (arg1 != 0) {
        var_v0 = 8;
        arg1 = 0xA;
    }
    var_s0 = &D_8122AD50[arg1 + var_v0];
    for (i = 0; i <= var_v0; i++) {
        func_81201DDC((u16*)((var_s1 * 2) + temp_s7 + 0x788), &D_8122C740[(D_8120E480[*var_s0 - i].unk_43 * 0xA0)], 0xFFFE, 0xC, 0xA, 0x10);
        temp_t8 = D_8120E480[*var_s0 - i].unk_43;
        var_s0 -= 1;
        var_s1 += D_8120E480[temp_t8].value;
    }
    func_812015EC((u16*)(temp_s7 + 0x7FE), (u16*)(D_8122C748 + 0xAD18), 0, 0x10, 0xA);
    var_s2_3 = D_8122B2C0->unk_5DC5;
    if (var_s2_3 != 0) {
        var_s2_3 -= 1;
    }
    func_812015EC((u16*)(temp_s7 + 0x5C2), (u16*)((var_s2_3 * 0x90 * 2) + D_8122C748 + 0xAE58), 0, 0xC, 0xC);
    func_812020C0(temp_s7 - 0x10, arg1, 0);
    D_8122C4E7 = 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81202210.s")
#endif

#ifdef NON_MATCHING
void func_8120241C(void) {
    unk_D_8120D7F3* var_s2;
    s32 temp_s0;
    s32 var_s0;
    s32 var_s1;
    s32 var_s4;
    s32 var_v0;
    u16 temp_v1_2;
    u16 temp_v1;

    temp_v1 = D_8122B2C0->unk_5DC5;
    var_v0 = 0;
    temp_s0 = D_8122B2E0 - 0x14;
    if (temp_v1 != 0) {
        var_v0 = temp_v1 - 1;
    }
    temp_v1_2 = D_8120E680[var_v0];
    switch (D_8122C4E2) { 
    case 1:
        func_81201FBC(temp_s0 + 0xA4, temp_v1_2, 0x8C);
        func_812015EC(temp_s0 + 0x5AA, (u8*)D_8122C748 + 0xA778, 0, 0x18, 0xD);
        func_812015EC(temp_s0 + 0x1762, (u8*)D_8122C748 + 0xA6D8, 0, 0x10, 5);
        func_812015EC(temp_s0 + 0x5DE, (u8*)D_8122C748 + 0xAC58, 0, 8, 6);
        func_812015EC(temp_s0 + 0x5EE, (u8*)D_8122C748 + 0xACB8, 0, 8, 6);
        var_s4 = temp_s0 + 0x600;
        break;
    case 2:
        func_81201FBC(temp_s0 + 0x9C, temp_v1_2, 0x94);
        func_812015EC(temp_s0 + 0x5A4, (u8*)D_8122C748 + 0xA9E8, 0, 0x18, 0xD);
        func_812015EC(temp_s0 + 0x175C, (u8*)D_8122C748 + 0xA5E8, 0, 0x18, 5);
        func_812015EC(temp_s0 + 0x5D8,(u8*)D_8122C748 + 0xAC58, 0, 8, 6);
        func_812015EC(temp_s0 + 0x5E8, (u8*)D_8122C748 + 0xACB8, 0, 8, 6);
        func_812015EC(temp_s0 + 0x5F8,(u8*) D_8122C748 + 0xACB8, 0, 8, 6);
        var_s4 = temp_s0 + 0x608;
        break;
    default:
    case 0:
        func_81201FBC(temp_s0 + 0xCE, temp_v1_2, 0x60);
        var_s4 = temp_s0 + 0x5D6;
        break;
    }
    func_812015EC(var_s4, (u8*)D_8122C748 + 0xC1D8, 0, 0xC, 0xC);
    var_s0 = 0;
    var_s2 = &D_8120D7F3;
    var_s1 = 0x37;
    do {
        func_81201DDC((var_s0 * 2) + (var_s4 - 0x266), (((unk_func_8120241C_80*)((u8*)D_8120E580 + var_s2->unk116 + -var_s1))->unk80 * 0xC0) + D_8122C744, 0xFFFE, 0xC, 0xC, 0x10);
        var_s0 += D_8120E580[((unk_func_8120241C_80*)((u8*)D_8120E580 + var_s2->unk116 + -var_s1))->unk80];
        if (var_s1 == 0x3C) {
            var_s0 -= 1;
        }
        if (var_s1 == 0x3D) {
            var_s0 += 1;
        }
        var_s1 += 1;
        var_s2 -= 1;
    } while (var_s1 != 0x42);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_8120241C.s")
#endif

#ifdef NON_MATCHING
void func_81202758(s32 arg0, s32 arg1) {
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s4;
    s32 temp_s6;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;

    var_s1 = arg0;
    temp_s4 = arg1 * 0x28 * 2;
    var_s0 = 0;
    do {
        func_812015EC(var_s1, temp_s4 + (u8*)D_8122C748 + 0x8910, 0, 8, 5);
        var_s0 += 1;
        var_s1 += 0x10;
    } while (var_s0 < 6);
    temp_s6 = arg1 << 7;
    func_812015EC(var_s1, temp_s6 + (u8*)D_8122C748 + 0x8F90, 0, 8, 8);
    var_s1_2 = var_s1 + 0x1406;
    var_s0_2 = 0;
    do {
        func_812015EC(var_s1_2, temp_s6 + (u8*)D_8122C748 + 0x8090, 0, 8, 8);
        var_s0_2 += 1;
        var_s1_2 += 0x1400;
    } while (var_s0_2 < 5);
    func_812015EC(var_s1_2, temp_s6 + (u8*)D_8122C748 + 0x8510, 0, 8, 8);
    var_s1_3 = var_s1_2 + 0x10;
    switch(D_8122C771) {
        case 1:
            var_s0_3 = 7;
            break;
        case 2:
            var_s0_3 = 0xA;
            break;
        case 3:
            var_s0_3 = 0xB;
        break;
        default:
        var_s0_3 = 7;
        break;
    }
    while (var_s0_3 > 0) {
        func_812015EC(var_s1_3 + 0x780, temp_s4 + (u8*)D_8122C748 + 0x8910, 0, 8, 5);
        var_s0_3 -= 1;
        var_s1_3 += 0x10;
    }
    func_812015EC(var_s1_3, temp_s6 + (u8*)D_8122C748 + 0x8B90, 0, 8, 8);
    temp_s1 = var_s1_3 - 0x13FA;
    func_812015EC(temp_s1, temp_s6 + (u8*)D_8122C748 + 0x9390, 0, 8, 8);
    temp_s1_2 = temp_s1 - 0x1400;
    func_812015EC(temp_s1_2, temp_s6 + (u8*)D_8122C748 + 0x9390, 0, 8, 8);
    func_812015EC(temp_s1_2 - 0x1400, (u8*)D_8122C748 + 0x8490, 0, 8, 8);
}
#else
void func_81202758(s32, s32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81202758.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812029B0.s")

void func_81202EA8(u16* arg0, u16* arg1, s16* arg2, s32 arg3, s32 arg4) {
    s32 i;
    s32 j;
    s32 var_v1;
    s32 var_t4;

    for (j = 0; j < arg3; j++) {
        for (i = 0; i < 320; i++) {
            var_v1 = (arg0[(j * 320) + ((arg4 + i) % 320)] & 0xF800) + (arg1[(j * 320) + i] & 0xF800);
            if (var_v1 > 0xF800) {
                var_v1 = 0xF800;
            }
            var_t4 = var_v1;
            var_v1 = (arg0[(j * 320) + ((arg4 + i) % 320)] & 0x7C0) + (arg1[(j * 320) + i] & 0x7C0);
            if (var_v1 > 0x7C0) {
                var_v1 = 0x7C0;
            }
            var_t4 |= var_v1;
            var_v1 = (arg0[(j * 320) + ((arg4 + i) % 320)] & 0x3E) + (arg1[(j * 320) + i] & 0x3E);
            if (var_v1 > 0x3E) {
                var_v1 = 0x3E;
            }
            arg2[(j * 320) + i] = var_t4 | var_v1;
        }
    }
}

s32 func_81202FCC(s32 arg0, s32 arg1) {
    s32 var_s0;

    var_s0 = 0;
    if (D_8122C768 < (osGetCount() - D_8122C76C)) {
        var_s0 = 1;
        D_8122C76C = osGetCount();
        D_8122C770 = (D_8122C770 + 1) & 7;
        if (D_8122C768 >= 0x80001U) {
            D_8122C768 -= D_8122C768 >> 8;
        }
    }
    if ((osGetCount() - D_8122C760) >= 0x200001U) {
        var_s0 = 1;
        D_8122C760 = osGetCount();
        D_8122C764++;
        if (D_8122C764 >= 0x140U) {
            D_8122C764 = 0;
        }
    }
    if (var_s0 != 0) {
        func_81202758(arg0 + 0x87BA, D_8122C770);
        func_81202EA8(D_8122C750, D_8122C74C, arg1 + 0x20A80, 0xF, D_8122C764);
    }
    return var_s0;
}

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
void func_81208C08(u16, u8, u16);
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
