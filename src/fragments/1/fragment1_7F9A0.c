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
#ifdef NON_MATCHING
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
                        }
                    }
                }
            }
        }
    } while ((ret == 0) && (count != 0));
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812004B8.s")
#endif

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
#ifdef NON_MATCHING
s32 func_812006AC(unk_D_8122B2C0* arg0) {
    s32 checksum;
    s32 ret;
    u8* buf;
    u32 addr;
    s32 remaining;
    s32 chunk;
    s32 off;
    s32 i;

    checksum = 0;
    ret = func_812005D8(arg0);
    buf = arg0->transferBuffer;
    addr = arg0->gbAddress;
    remaining = arg0->transferSize;

    if ((ret == 0) && (addr < 0x4000)) {
        if ((addr + remaining) >= 0x4001) {
            chunk = 0x4000 - addr;
        } else {
            chunk = remaining;
        }
        ret = osGbpakReadWrite(&arg0->pfs, 0, addr & 0xFFFF, buf, chunk);
        if (ret == 0) {
            for (i = 0; i < chunk; i++) {
                checksum += buf[i];
            }
            buf += chunk;
            remaining -= chunk;
            addr = 0x4000;
        }
    }

    while ((ret == 0) && (remaining != 0)) {
        ret = func_812001E4(arg0, addr >> 0xE);
        if (ret == 0) {
            off = addr & 0x3FFF;
            if ((off + remaining) >= 0x4001) {
                chunk = 0x4000 - off;
            } else {
                chunk = remaining;
            }
            ret = osGbpakReadWrite(&arg0->pfs, 0, (off | 0x4000) & 0xFFFF, buf, chunk);
            if (ret == 0) {
                for (i = 0; i < chunk; i++) {
                    checksum += buf[i];
                }
                buf += chunk;
                remaining -= chunk;
                addr = (addr + 0x4000) & ~0x3FFF;
            }
        }
    }

    if (ret == 0) {
        ret = func_8120019C(arg0);
        if (ret == 0) {
            arg0->unk_5D70[0] += checksum;
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812006AC.s")
#endif

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

#ifdef NON_MATCHING
// Draw the tile-grid border/frame into the render target: blit corner/edge
// glyphs from D_8122C748, then paint the 0xC14 grid lines. All pointer offsets
// are byte offsets into the u16 render target.
void func_812016DC(u16* arg0) {
    u8* s1;
    u8* s2;
    u8* s3;
    u8* s5;
    u8* a2;
    u8* a3;
    u8* v0;
    s32 s4;
    s32 t0;
    s32 a1;

    s1 = (u8*) arg0 + 0x10;
    s2 = (u8*) arg0 + 0x1400;
    s5 = s2 + 0x4C;
    s3 = s1 + 0x5F00;
    s4 = 0x1400;
    do {
        func_812015EC((u16*) s1, (u16*) &D_8122C748->unk0000[0x1180], 0xFFFF, 8, 8);
        func_812015EC((u16*) s3, (u16*) &D_8122C748->unk0000[0x1400], 0xFFFF, 8, 8);
        func_812015EC((u16*) s2, (u16*) &D_8122C748->unk0000[0x1280], 0xFFFF, 8, 8);
        func_812015EC((u16*) s5, (u16*) &D_8122C748->unk0000[0x1300], 0xFFFF, 8, 8);
        s4 += 0x1400;
        s1 += 0x10;
        s3 += 0x10;
        s2 += 0x1400;
        s5 += 0x1400;
    } while (s4 != 0x6400);
    func_812015EC(arg0, (u16*) &D_8122C748->unk0000[0x1100], 0, 8, 8);
    func_812015EC((u16*) ((u8*) arg0 + 0x4C), (u16*) &D_8122C748->unk0000[0x1200], 0, 8, 8);
    func_812015EC((u16*) ((u8*) arg0 + 0x5F00), (u16*) &D_8122C748->unk0000[0x1380], 0, 8, 8);
    func_812015EC((u16*) ((u8*) arg0 + 0x5F4C), (u16*) &D_8122C748->unk0000[0x1480], 0, 8, 8);
    t0 = 0;
    a3 = (u8*) arg0;
    a2 = (u8*) arg0;
    do {
        *(u16*) (a2 + 0x1410) = 0xC14;
        *(u16*) (a2 + 0x1412) = 0xC14;
        a1 = 2;
        v0 = a3 + 4;
        do {
            a1 += 4;
            *(u16*) (v0 + 0x1412) = 0xC14;
            *(u16*) (v0 + 0x1414) = 0xC14;
            *(u16*) (v0 + 0x1416) = 0xC14;
            v0 += 8;
            *(u16*) (v0 + 0x1408) = 0xC14;
        } while (a1 != 0x1E);
        t0 += 0x140;
        a3 += 0x280;
        a2 += 0x280;
    } while (t0 != 0x2580);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812016DC.s")
#endif

#ifdef NON_MATCHING
// Tint-modulated blit: scale each source pixel's luminance (blue channel) by the
// arg2 RGB565 tint and write it to the render target. arg0/arg1 are byte-offset
// pointers; the source row stride is arg3 pixels, the target's is 320.
void func_812018C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 x;
    s32 y;
    u16* dst;
    u16* src;
    s32 tintR;
    s32 tintG;
    s32 tintB;
    s32 intensity;

    tintR = arg2 & 0xF800;
    tintG = arg2 & 0x7C0;
    tintB = arg2 & 0x3E;
    y = 0;
    if (arg4 > 0) {
        do {
            dst = (u16*) ((u8*) arg0 + (y * 0x280));
            src = (u16*) ((u8*) arg1 + (y * arg3 * 2));
            x = 0;
            if (arg3 > 0) {
                do {
                    intensity = (s32) (src[x] & 0x3E) >> 1;
                    dst[x] = (((tintR * intensity) / 31) & 0xF800) | (((tintG * intensity) / 31) & 0x7C0) |
                             (((tintB * intensity) / 31) & 0x3E);
                    x++;
                } while (x != arg3);
            }
            y++;
        } while (y != arg4);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812018C0.s")
#endif

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

#ifdef NON_MATCHING
// Blit a tile's set (odd) pixels from D_8122C748's plane data into the render
// target at +0x5B4, 4 pixels per step across an 0xB x 0xC region. arg1 chooses
// the source plane and scan direction.
void func_812020C0(s32 arg0, s32 arg1, s32 arg2) {
    u16* src;
    u8* base;
    s32 step;
    s32 row;
    s32 col;
    u16 p;

    if (arg1 != 0) {
        src = (u16*) ((u8*) D_8122C748 + (arg2 * 0x108) + 0x9A90);
        step = 1;
    } else {
        src = (u16*) ((u8*) D_8122C748 + (arg2 * 0x108) + 0x9B96);
        step = -1;
    }
    base = (u8*) arg0;
    row = 0;
    do {
        col = 0;
        do {
            u16* dst = (u16*) (base + (row * 0x280) + (col * 2) + 0x5B4);
            p = *src;
            src += step;
            if (p & 1) {
                dst[0] = p;
            }
            p = *src;
            src += step;
            if (p & 1) {
                dst[1] = p;
            }
            p = *src;
            src += step;
            if (p & 1) {
                dst[2] = p;
            }
            p = *src;
            src += step;
            if (p & 1) {
                dst[3] = p;
            }
            col += 4;
        } while (col != 0xC);
        row += 1;
    } while (row != 0xB);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812020C0.s")
#endif

#ifdef NON_MATCHING
extern u8 D_8120E480[];
extern u16 D_8120E680[];
extern u8 D_8122AD50[];
extern s8 D_8122C4E7;
// Compose a Game Boy screen frame: clear the buffer, draw the border, then lay
// out the digit/glyph run for the current value using the D_8120E480 glyph-width
// table (two-level: width index at +0x43, then advance width).
void func_81202210(s32 arg0, s32 arg1) {
    unk_D_80068BB0* buf;
    u8* head;
    u8* ptr;
    s32 count;
    s32 acc;
    s32 i;
    s32 idx;
    u8 sel;

    buf = D_8122B2D8[arg0];
    bzero(buf, 0x2800);
    head = (u8*) buf + 0xAA;
    sel = D_8122B2C0->unk_5DC5;
    if (sel != 0) {
        sel -= 1;
    }
    func_81201FBC((s32) head, D_8120E680[sel], 0x70);
    count = 9;
    acc = 0;
    if (arg1 != 0) {
        count = 8;
        arg1 = 0xA;
    }
    i = 0;
    if (count >= 0) {
        ptr = &D_8122AD50[arg1 + count];
        do {
            idx = D_8120E480[(*ptr - i) + 0x43];
            func_81201DDC((u16*) (head + (acc * 2) + 0x788), D_8122C740 + (idx * 0xA0), 0xFFFE, 0xC, 0xA, 0x10);
            i += 1;
            acc += D_8120E480[idx];
            ptr -= 1;
        } while ((count + 1) != i);
    }
    func_812015EC((u16*) (head + 0x7FE), (u16*) ((u8*) D_8122C748 + 0xAD18), 0, 0x10, 0xA);
    sel = D_8122B2C0->unk_5DC5;
    if (sel != 0) {
        sel -= 1;
    }
    func_812015EC((u16*) (head + 0x5C2), (u16*) ((u8*) D_8122C748 + (sel * 0x120) + 0xAE58), 0, 0xC, 0xC);
    func_812020C0((s32) (head - 0x10), arg1, 0);
    D_8122C4E7 = 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81202210.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_8120241C.s")

#ifdef NON_MATCHING
extern u8 D_8122C771;
// Draws a bordered tile grid into dst from glyph data in D_8122C748->unk0000.
void func_81202758(u16* arg0, s32 arg1) {
    s32 srcA;
    s32 srcB;
    s32 i;
    s32 count;
    u16* dst;
    u16* dst2;
    u16* dst3;
    u16* p;
    u16* p2;

    dst = arg0;
    srcA = arg1 * 0x28 * 2;
    for (i = 0; i < 6; i++) {
        func_812015EC(dst, (u16*) &D_8122C748->unk0000[srcA + 0x8910], 0, 8, 5);
        dst += 0x10;
    }
    srcB = arg1 << 7;
    func_812015EC(dst, (u16*) &D_8122C748->unk0000[srcB + 0x8F90], 0, 8, 8);
    dst2 = dst + 0x1406;
    for (i = 0; i < 5; i++) {
        func_812015EC(dst2, (u16*) &D_8122C748->unk0000[srcB + 0x8090], 0, 8, 8);
        dst2 += 0x1400;
    }
    func_812015EC(dst2, (u16*) &D_8122C748->unk0000[srcB + 0x8510], 0, 8, 8);
    dst3 = dst2 + 0x10;
    if (D_8122C771 == 1) {
        count = 7;
    } else if (D_8122C771 == 2) {
        count = 0xA;
    } else if (D_8122C771 == 3) {
        count = 0xB;
    } else {
        count = 6;
    }
    while (count > 0) {
        func_812015EC(dst3 + 0x780, (u16*) &D_8122C748->unk0000[srcA + 0x8910], 0, 8, 5);
        count -= 1;
        dst3 += 0x10;
    }
    func_812015EC(dst3, (u16*) &D_8122C748->unk0000[srcB + 0x8B90], 0, 8, 8);
    p = dst3 - 0x13FA;
    func_812015EC(p, (u16*) &D_8122C748->unk0000[srcB + 0x9390], 0, 8, 8);
    p2 = p - 0x1400;
    func_812015EC(p2, (u16*) &D_8122C748->unk0000[srcB + 0x9390], 0, 8, 8);
    func_812015EC(p2 - 0x1400, (u16*) &D_8122C748->unk0000[0x8490], 0, 8, 8);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81202758.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_812029B0.s")

#ifdef NON_MATCHING
// Saturating additive RGB565 blend: out[y][x] = sat(srcB[y][x] + srcA[y][(arg4+x)%320])
void func_81202EA8(u16* arg0, u16* arg1, u16* arg2, s32 arg3, s32 arg4) {
    u16* aRow;
    u16* bRow;
    u16* outRow;
    u16* b;
    u16* out;
    s32 idx;
    s32 col;
    u16 pa;
    u16 pb;
    s32 r;
    s32 g;
    s32 blue;

    if (arg3 > 0) {
        bRow = arg1;
        aRow = arg0;
        outRow = arg2;
        do {
            col = 0;
            b = bRow;
            idx = arg4;
            out = outRow;
            do {
                pa = aRow[idx % 320];
                pb = *b;
                r = (pb & 0xF800) + (pa & 0xF800);
                if (r >= 0xF801) {
                    r = 0xF800;
                }
                g = (pb & 0x7C0) + (pa & 0x7C0);
                if (g >= 0x7C1) {
                    g = 0x7C0;
                }
                blue = (pb & 0x3E) + (pa & 0x3E);
                col += 1;
                if (blue >= 0x3F) {
                    blue = 0x3E;
                }
                b += 1;
                idx += 1;
                out += 1;
                out[-1] = (s16) (r | g | blue);
            } while (col != 0x140);
            outRow += 320;
            bRow += 320;
            aRow += 320;
        } while (outRow != arg2 + (arg3 * 320));
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81202EA8.s")
#endif

#ifdef NON_MATCHING
extern u16* D_8122C750;
extern u32 D_8122C764;
extern u32 D_8122C768;
extern u8 D_8122C770;
void func_81202758(u16*, s32);
s32 func_81202FCC(s32 arg0, s32 arg1) {
    s32 updated;

    updated = 0;
    if ((u32) D_8122C768 < (osGetCount() - D_8122C76C)) {
        updated = 1;
        D_8122C76C = osGetCount();
        D_8122C770 = (D_8122C770 + 1) & 7;
        if (D_8122C768 >= 0x80001) {
            D_8122C768 -= D_8122C768 >> 8;
        }
    }
    if ((osGetCount() - D_8122C760) >= 0x200001) {
        updated = 1;
        D_8122C760 = osGetCount();
        D_8122C764 += 1;
        if (D_8122C764 >= 0x140) {
            D_8122C764 = 0;
        }
    }
    if (updated != 0) {
        func_81202758((u16*) (arg0 + 0x87BA), D_8122C770);
        func_81202EA8((u16*) D_8122C750, (u16*) D_8122C74C, (u16*) (arg1 + 0x20A80), 0xF, D_8122C764);
    }
    return updated;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_7F9A0/func_81202FCC.s")
#endif

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
