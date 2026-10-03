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
  /* 0x28 */ char unk28[0x10];
  /* 0x38 */ s32 unk_38;
  /* 0x3C */ s32 unk_3C;
  /* 0x40 */ char unk40[0x1C];
  /* 0x5C */ u32 unk_5C;
  /* 0x60 */ char unk60[0x8];
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


typedef struct unk_D_8120D7F3 {
    u8 pad[0x116];
    u8 unk116;
} unk_D_8120D7F3; // size = 0x10A ??

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
extern u8 D_8120E480[0x100];
extern u8 D_8120E580[256];
extern u16 D_8120E680[4];

// .rodata
const u8 D_8122AD50[] = {
    0x74, 0x73, 0x72, 0xAA, 0xB0, 0xAA, 0xA4, 0xA0, 0xAD, 0x89, 0x73, 0x72, 0x71, 0xA9, 0xAF, 0xA9, 0xB5, 0x9F, 0x90, 0x00,
};

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
typedef struct {
    /* 0x0000 */ OSThread thread;
    /* 0x01B0 */ u8 stack[0x1000];
} unk_D_8122B300; // size = 0x11B0

extern unk_D_8122B300 D_8122B300;
extern OSMesg D_8122C4B0[4];
extern OSMesgQueue D_8122C4C0;
extern s16 D_8122C4F0;
extern u8 D_8122C4F7;
extern u8 D_8122C4F8;
extern s32 D_8122C774;
extern Controller* gPlayer1Controller;
extern u8 D_8122B2C4[];
extern u8 D_8122B2E4[];
extern u8 fragment2_ROM_START[];
extern u8 fragment1_misc_yay0_ROM_START[];
extern u8 D_102BA0_END[];
extern OSMesgQueue D_8122B1EC;
extern OSMesgQueue D_8122B254;
extern OSMesg D_8122B250;
extern OSMesgQueue* D_8122C4D8;
extern s32 D_8122C4DC;
extern volatile u8 D_8122C4E0;
extern u8 D_8122C540[];
extern u8 D_8122C640[];
extern u8 D_8122C4E2;
extern u8 D_8122C4E3;
extern u8 D_8122C4E4;
extern u8 D_8122C4E5;
extern u8 D_8122C4E7;
extern s32 D_8122B2E8;
extern u8 D_8122C4FB;
extern u8 D_8120E688[];
extern u8 D_8120E694[];
extern u8 D_8120E6A8[];
extern u8 D_8120E6B8[];
extern u8 D_8120E6D0[];
extern u8 D_8120E718[];
extern u8 D_8120E760[];
extern u8 D_8120E7A0[];
extern u8 D_8120E7CC[];
extern u8 D_8120E7D8[];
extern u8 D_8120E7DC[];
extern u8 D_8120E7E4[];
extern u8 D_8120E834[];
extern u8 D_8120E898[];
extern u8 D_8120E8A8[];
extern u8 D_8120E8C0[];
extern u8 D_8120E958[];
extern u8 D_8120E8D8[];
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
extern u8* D_8122C748;
extern s32 D_8122C74C;
extern s32 D_8122C750;
extern u8* D_8122C754;
extern u8 D_8120D8FD;
extern u8 D_8120D8FE;
extern u8 D_8120D906;
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
                ret = bcmp(&arg0->unk_5C5C, &arg0->gbpakId, sizeof(arg0->unk_5C5C));
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

void func_81200AA8(s32 arg0) {
    u16* entry;
    s32 retries;
    unk_D_8122B2C0* emu;
    u32 value;
    u16 sum;
    u8* ptr;
    s32 i;

    D_8122C4E0 = 1;

    for (;;) {
        osRecvMesg(&D_8122C4C0, (OSMesg*)&emu, OS_MESG_BLOCK);
        if (emu == NULL) {
            D_8122C4E0 = 0;
            osDestroyThread(NULL);
        }
        emu->unk_5DC8 = 1;
        if ((emu->unk_5DCA == 0) && (emu->unk_5DCC < 4)) {
            emu->unk_5DC7 = 0;
            emu->unk_5DC8 = 0;
            continue;
        }

        emu->unk_5DCD = 0x49;
    retry:
        emu->unk_5DCD--;
        if (emu->unk_5DCD <= 0) {
            goto disconnect;
        }
        switch (emu->unk_5DC9) {
            case 0:
                emu->unk_5DC9 = 1;
                bzero(&emu->unk_5C5C, sizeof(emu->unk_5C5C));
                /* fallthrough */
            case 1:
                emu->unk_5DCD -= 9;
                if (osGbpakInit(D_8122C4D8, (OSPfs*)&emu->pfs, emu->unk_5DCC) != 0) {
                    goto retry;
                }
                if (osGbpakReadId((OSPfs*)&emu->pfs, &emu->unk_5C5C, &emu->status) != 0) {
                    goto retry;
                }
                if (func_81200020(emu) != 0) {
                    goto retry;
                }
                if (func_812000DC(emu) != 0) {
                    goto retry;
                }
                emu->transferBuffer = emu->unk_5DA4;
                emu->gbAddress = 0x9C000;
                emu->transferSize = 0x20;
                if (func_812006AC(emu) != 0) {
                    goto retry;
                }
                if (!(emu->status & 1)) {
                    goto retry;
                }
                emu->unk_5DC5 = func_812009D0((unk_func_812009D0*)&emu->unk_5C5C);
                emu->unk_5DC9 = 2;
                /* fallthrough */
            case 2:
                switch (emu->unk_5DC7) {
                    case 1:
                        emu->unk_5DCD -= 0x17;
                        if (func_812006AC(emu) != 0) {
                            goto retry;
                        }
                        break;
                    case 2:
                        emu->unk_5DCD -= 0x17;
                        if (func_812008C8(emu, 0) != 0) {
                            goto retry;
                        }
                        break;
                    case 3:
                        emu->unk_5DCD -= 0x17;
                        if (func_812008C8(emu, 1) != 0) {
                            goto retry;
                        }
                        break;
                    case 5:
                        emu->transferBuffer = D_8122C540;
                        emu->transferSize = 0x100;
                        if ((func_812008C8(emu, 1) == 0) &&
                            (emu->transferBuffer = D_8122C640, func_812008C8(emu, 0) == 0) &&
                            (bcmp(D_8122C540, D_8122C640, 0x100) == 0)) {
                            if (emu->unk_5A2C[emu->gbAddress >> 8] != 0) {
                                emu->unk_5A2C[emu->gbAddress >> 8] = 2;
                            }
                            break;
                        }
                        emu->status &= ~1;
                        osGbpakPower((OSPfs*)&emu->pfs, 0);
                        retries = 0x3C;
                        emu->unk_5DC9 = 8;
                        goto retry;
                    case 6:
                        emu->unk_5DCD -= 2;
                        entry = (u16*)emu->unk_5D70[1];
                        do {
                            value = *entry;
                            if (*entry & 0x8000) {
                                if (emu->unk_559C[value & 0xF] == 0) {
                                    emu->gbAddress = (value & 0xF) << 13;
                                    emu->transferBuffer = (u8*)emu + emu->gbAddress + 0x12DF0;
                                    emu->transferSize = 0x2000;
                                    if (func_812008C8(emu, 0) != 0) {
                                        goto disconnect;
                                    }
                                    emu->unk_559C[entry[0] & 0xF] = 0xFF;
                                }
                                entry += 1;
                            } else {
                                if (emu->unk_549C[*entry] == 0) {
                                    emu->gbAddress = value << 14;
                                    emu->transferBuffer = (u8*)emu->unk_53BC + emu->gbAddress;
                                    emu->transferSize = 0x4000;
                                    if (func_812006AC(emu) != 0) {
                                        goto retry;
                                    }
                                    sum = 0;
                                    ptr = emu->transferBuffer;
                                    for (i = 0; i < 0x2000; i++) {
                                        sum += *ptr;
                                        ptr++;
                                    }
                                    if (sum != entry[1]) {
                                        goto retry;
                                    }
                                    sum = 0;
                                    for (i = 0; i != 0x2000U; i++) {
                                        sum += *ptr;
                                        ptr++;
                                    }
                                    if (sum != entry[2]) {
                                        goto retry;
                                    }
                                    emu->unk_549C[entry[0]] = 0xFF;
                                }
                                entry += 3;
                            }
                        } while (*entry);
                        break;
                    case 8:
                        emu->unk_5DC4 = 0;
                        if (func_812005D8(emu) != 0) {
                            goto retry;
                        }
                        if (func_812004B8(emu) != 0) {
                            goto retry;
                        }
                        break;
                    case 7:
                        if (func_8120019C(emu) != 0) {
                            goto retry;
                        }
                        break;
                    case 4:
                        emu->unk_5DCD -= 0x17;
                        emu->status &= ~1;
                        if (osGbpakPower((OSPfs*)&emu->pfs, 0) != 0) {
                            goto retry;
                        }
                        break;
                    case 0:
                    default:
                        break;
                }
                emu->unk_5DC7 = 0;
                break;
            case 8:
            case 11:
                if (emu->unk_5DC7 != 7) {
                    break;
                }
                if (func_8120019C(emu) != 0) {
                    if (--retries == 0) {
                        retries = 5;
                        emu->unk_5DC9 = 9;
                    }
                } else {
                    retries = 0x3C;
                }
                break;
            case 9:
                if (osGbpakInit(D_8122C4D8, (OSPfs*)&emu->pfs, emu->unk_5DCC) != 0) {
                    retries = 5;
                } else {
                    if (func_8120019C(emu) == 0) {
                        if (--retries == 0) {
                            i = func_812005D8(emu);
                            if (i != 0) {
                                goto power_off;
                            } else if (i == 0) {
                                emu->unk_5DC9 = 10;
                            }
                        }
                    } else {
                        retries = 5;
                    }
                }
                break;
            case 10:
                emu->transferBuffer = D_8122C540;
                if ((func_812008C8(emu, 1) == 0) &&
                    (emu->transferBuffer = D_8122C640, func_812008C8(emu, 0) == 0) &&
                    (bcmp(D_8122C540, D_8122C640, 0x100) == 0)) {
                    if (emu->unk_5A2C[emu->gbAddress >> 8] != 0) {
                        emu->unk_5A2C[emu->gbAddress >> 8] = 2;
                    }
                    emu->unk_5DC9 = 2;
                    emu->unk_5DC7 = 0;
                    break;
                }
            power_off:
                retries = 0x3C;
                emu->status &= ~1;
                osGbpakPower((OSPfs*)&emu->pfs, 0);
                emu->unk_5DC9 = 11;
                break;
            default:
            disconnect:
                emu->unk_5DCA = 0;
                break;
        }
        emu->unk_5DC8 = 0;
    }
}

void func_812011D0(u16* fb, u8* cmd) {
    u8* ptr;
    u8* map;
    u8* data;
    u8* src;
    u16* dst;
    u16* pal;
    u8 flags;
    u8 y;
    s32 tile;
    s32 width;
    s32 x;
    s32 dir;
    long trans;
    s32 tileSize;
    s32 count;
    s32 row;
    s32 col;

    flags = *cmd;
    ptr = cmd;
    while (((unsigned int) flags) != 0) {
        trans = flags;
        x = ptr[1] + ((flags & 1) << 8);
        y = ptr[2];
        if (flags & 0x40) {
            dir = -1;
        } else {
            dir = 0;
        }
        dst = fb + (y * 0x140 + x);
        trans &= 0x20;

        switch (ptr[3]) {
            default:
                map = D_8120E480;
                data = D_8122C740;
                tileSize = 0xA;
                break;
            case 0xC:
                tileSize = 0xC;
                map = D_8120E580;
                data = D_8122C744;
                break;
            case 0xA:
                map = D_8120E480, data = D_8122C740;
                tileSize = 0xA;
                break;
        }

        switch (ptr[4]) {
            case 1:
                pal = (u16*) &D_8120E320;
                break;
            case 2:
                pal = (u16*) &D_8120E340;
                break;
            case 3:
                pal = (u16*) &D_8120E360;
                break;
            case 4:
                pal = (u16*) &D_8120E380;
                break;
            case 5:
                pal = (u16*) &D_8120E3A0;
                break;
            case 6:
                pal = (u16*) &D_8120E3C0;
                break;
            case 7:
                pal = (u16*) &D_8120E3E0;
                break;
            case 8:
                pal = (u16*) &D_8120E400;
                break;
            case 9:
                pal = (u16*) &D_8120E420;
                break;
            case 10:
                pal = (u16*) &D_8120E440;
                break;
            case 11:
                pal = (u16*) &D_8120E460;
                break;
            case 0:
            default:
                pal = (u16*) &D_8120E300;
                break;
        }

        count = ptr[5];
        while (count != 0) {
            count--;
            tile = map[ptr[6] + 0x80];
            width = map[tile];
            src = data + tile * tileSize * 0x10;

            for (row = 0; row != tileSize; row++) {
                for (col = 0; col != width; col++) {
                    if (trans || (pal[*src & 0xF] != 0)) {
                        *dst = pal[*src & 0xF];
                    }
                    dst++;
                    src++;
                }
                dst = dst - width + 0x140;
                src = src - width + 0x10;
            }
            ptr++;
            dst -= tileSize * 0x140 - width - dir;
        }
        flags = ptr[6];
        ptr += 6;
    }
}

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

void func_812016DC(u16* dst) {
    s32 i;
    s32 y;

    for (i = 1; i < 5; i++) {
        func_812015EC(dst + i * 8, (u16*) (D_8122C748 + 0x1180), 0xFFFF, 8, 8);
        func_812015EC(dst + 38 * 320 + i * 8, (u16*) (D_8122C748 + 0x1400), 0xFFFF, 8, 8);
        func_812015EC(dst + i * 8 * 320, (u16*) (D_8122C748 + 0x1280), 0xFFFF, 8, 8);
        func_812015EC(dst + i * 8 * 320 + 38, (u16*) (D_8122C748 + 0x1300), 0xFFFF, 8, 8);
    }

    func_812015EC(dst, (u16*) (D_8122C748 + 0x1100), 0, 8, 8);
    func_812015EC(dst + 38, (u16*) (D_8122C748 + 0x1200), 0, 8, 8);
    func_812015EC(dst + 38 * 320, (u16*) (D_8122C748 + 0x1380), 0, 8, 8);
    func_812015EC(dst + 38 * 320 + 38, (u16*) (D_8122C748 + 0x1480), 0, 8, 8);

    for (y = 0; y < 30; y++) {
        for (i = 0; i < 30; i++) {
            dst[(y + 8) * 320 + (i + 8)] = 0xC14;
        }
    }
}

void func_812018C0(u16* dst, u16* src, s32 color, s32 width, s32 height) {
    s32 x;
    s32 y;
    s32 intensity;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            intensity = (src[y * width + x] & 0x3E) >> 1;
            dst[y * 320 + x] = ((((color & 0xF800) * intensity) / 31) & 0xF800) |
                               ((((color & 0x7C0) * intensity) / 31) & 0x7C0) |
                               ((((color & 0x3E) * intensity) / 31) & 0x3E);
        }
    }
}

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
      func_812018C0(arg0 + i * 2, &((unk_D_8122C748*) D_8122C748)->unk_9890, arg1, 8, 0x10);
  }
  func_812018C0(arg0, &((unk_D_8122C748*) D_8122C748)->unk_9790, arg1, 8, 0x10);
  func_812018C0(arg0 + (arg2 - 8) * 2, &((unk_D_8122C748*) D_8122C748)->unk_9990, arg1, 8, 0x10);
}

void func_812020C0(u16* dst, s32 arg1, s32 arg2) {
  u16* src;
  s32 offset;
  s32 row;
  s32 col;
  u16 val;

  offset = arg2 * 132;
  if (arg1 != 0) {
      src = (u16*) (offset * 2 + D_8122C748 + 0x9A90);
      arg1 = 1;
  } else {
      src = (u16*) (offset * 2 + D_8122C748 + 0x9B96);
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

void func_81202210(s32 arg0, s32 arg1) {
    u8* fb;
    s32 x;
    s32 i;
    s32 count;
    s32 off;

    fb = (u8*) D_8122B2D8[arg0];
    bzero(D_8122B2D8[arg0], 0x2800);
    fb += 0xAA;

    i = D_8122B2C0->unk_5DC5;
    if (i != 0) {
        i--;
    }
    func_81201FBC((s32) fb, D_8120E680[i], 0x70);

    if (arg1 != 0) {
        count = 8;
        arg1 = 0xA;
    } else {
        count = 9;
    }
    x = 0;

    for (i = 0; i <= count; i++) {
        func_81201DDC((u16*) ((x * 2) + fb + 0x788),
                      &D_8122C740[D_8120E480[D_8122AD50[arg1 + count - i] - i + 0x43] * 0xA0], 0xFFFE, 0xC, 0xA,
                      0x10);
        x += D_8120E480[D_8120E480[D_8122AD50[arg1 + count - i] - i + 0x43]];
    }

    func_812015EC((u16*) (fb + 0x7FE), (u16*) (D_8122C748 + 0xAD18), 0, 0x10, 0xA);

    i = D_8122B2C0->unk_5DC5;
    if (i != 0) {
        i--;
    }
    off = i * 0x90;
    func_812015EC((u16*) (fb + 0x5C2), (u16*) ((off * 2) + D_8122C748 + 0xAE58), 0, 0xC, 0xC);

    func_812020C0((u16*) (fb - 0x10), arg1, 0);
    D_8122C4E7 = 0;
}

void func_8120241C(void) {
    u8* var_s2;
    s32 temp_s0;
    s32 var_s0;
    s32 var_s1;
    s32 var_s4;
    u16 temp_v1;

    temp_v1 = D_8122B2C0->unk_5DC5;
    temp_s0 = D_8122B2E0 - 0x14;
    temp_v1 = D_8120E680[(temp_v1 != 0) ? (temp_v1 - 1) : 0];
    switch (D_8122C4E2) {
        case 1:
            func_81201FBC(temp_s0 + 0xA4, temp_v1, 0x8C);
            func_812015EC((u16*) (temp_s0 + 0x5AA), (u16*) (D_8122C748 + 0xA778), 0, 0x18, 0xD);
            func_812015EC((u16*) (temp_s0 + 0x1762), (u16*) (D_8122C748 + 0xA6D8), 0, 0x10, 5);
            func_812015EC((u16*) (temp_s0 + 0x5DE), (u16*) (D_8122C748 + 0xAC58), 0, 8, 6);
            func_812015EC((u16*) (temp_s0 + 0x5EE), (u16*) (D_8122C748 + 0xACB8), 0, 8, 6);
            var_s4 = temp_s0 + 0x600;
            break;
        case 2:
            func_81201FBC(temp_s0 + 0x9C, temp_v1, 0x94);
            func_812015EC((u16*) (temp_s0 + 0x5A4), (u16*) (D_8122C748 + 0xA9E8), 0, 0x18, 0xD);
            func_812015EC((u16*) (temp_s0 + 0x175C), (u16*) (D_8122C748 + 0xA5E8), 0, 0x18, 5);
            func_812015EC((u16*) (temp_s0 + 0x5D8), (u16*) (D_8122C748 + 0xAC58), 0, 8, 6);
            func_812015EC((u16*) (temp_s0 + 0x5E8), (u16*) (D_8122C748 + 0xACB8), 0, 8, 6);
            func_812015EC((u16*) (temp_s0 + 0x5F8), (u16*) (D_8122C748 + 0xACB8), 0, 8, 6);
            var_s4 = temp_s0 + 0x608;
            break;
        default:
        case 0:
            func_81201FBC(temp_s0 + 0xCE, temp_v1, 0x60);
            var_s4 = temp_s0 + 0x5D6;
            break;
    }
    func_812015EC((u16*) var_s4, (u16*) (D_8122C748 + 0xC1D8), 0, 0xC, 0xC);

    var_s0 = 0;
    var_s4 -= 0x266;
    for (var_s2 = (u8*) &D_8120D7F3, var_s1 = 0x37; var_s1 < 0x42; var_s1++, var_s2--) {
        func_81201DDC((u16*) ((var_s0 * 2) + var_s4), (D_8120E580[var_s2[0x116] - var_s1 + 0x80] * 0xC0) + D_8122C744,
                      0xFFFE, 0xC, 0xC, 0x10);
        var_s0 += D_8120E580[D_8120E580[var_s2[0x116] - var_s1 + 0x80]];
        if (var_s1 == 0x3C) {
            var_s0 -= 1;
        }
        if (var_s1 == 0x3D) {
            var_s0 += 1;
        }
    }
}

void func_81202758(s32 arg0, s32 arg1) {
    s32 temp_s4;
    s32 temp_s6;
    s32 i;

    temp_s4 = (arg1 * 0x28) << 1;
    for (i = 0; i < 6; i++) {
        func_812015EC((u16*) (arg0), (u16*) (temp_s4 + D_8122C748 + 0x8910), 0, 8, 5);
        arg0 += 0x10;
    }
    temp_s6 = arg1 << 6;
    temp_s6 <<= 1;
    func_812015EC((u16*) (arg0), (u16*) (temp_s6 + D_8122C748 + 0x8F90), 0, 8, 8);
    arg0 += 0x1406;
    for (i = 0; i < 5; i++) {
        func_812015EC((u16*) (arg0), (u16*) (temp_s6 + D_8122C748 + 0x8090), 0, 8, 8);
        arg0 += 0x1400;
    }
    func_812015EC((u16*) (arg0), (u16*) (temp_s6 + D_8122C748 + 0x8510), 0, 8, 8);
    arg0 += 0x10;
    switch (D_8122C771) {
    case 1:
        i = 7;
        break;
    case 2:
        i = 0xA;
        break;
    case 3:
        i = 0xB;
        break;
    default:
        i = 6;
        break;
    }
    while (i > 0) {
        func_812015EC((u16*) (arg0 + 0x780), (u16*) (temp_s4 + D_8122C748 + 0x8910), 0, 8, 5);
        arg0 += 0x10;
        i--;
    }
    func_812015EC((u16*) (arg0), (u16*) (temp_s6 + D_8122C748 + 0x8B90), 0, 8, 8);
    arg0 -= 0x13FA;
    func_812015EC((u16*) (arg0), (u16*) (temp_s6 + D_8122C748 + 0x9390), 0, 8, 8);
    arg0 -= 0x1400;
    func_812015EC((u16*) (arg0), (u16*) (temp_s6 + D_8122C748 + 0x9390), 0, 8, 8);
    arg0 -= 0x1400;
    func_812015EC((u16*) (arg0), (u16*) (D_8122C748 + 0x8490), 0, 8, 8);
}
void func_812029B0(u16* dst, u16 (*arg1)[6][0x640], s32 arg2, s32 arg3) {
    s32 x;
    s32 y;
    s32 step;
    u16* row;
    s32 xpos;
    s32 i;
    s32 n;
    s32 j;

    step = 0x5000;
    for (y = 0; y < 0x14000; y += step) {
        row = dst + y;
        for (x = 0; x != 320u; x += 64) {
            func_812015EC(row, (u16*) ((u8*) D_8122C748 + 0x1500), 0xFFFF, 64, (y == 0xF000) ? 48 : 64);
            row += 64;
        }
    }

    if (D_8122C74C == 0) {
        xpos = 0;
        D_8122C74C = (s32) D_8122B2F4;
        D_8122B2F4 += 0x2580;
        j = 9;
        x = 8; // FAKE: x = 8 ... x++ ... if (x != 0) keeps the "li s0,9; beqz" loop guard
        _bcopy(dst + 0x10540, (void*) D_8122C74C, 0x2580);
        D_8122C750 = (s32) D_8122B2F4;
        D_8122B2F4 += 0x2580;
        bzero((void*) D_8122C750, 0x2580);
        x++;

        if (x != 0) {
            for (i = j; i != 0; i++) {
                func_81201DDC((u16*) ((xpos * 2) + D_8122C750 + 0x280),
                              (D_8120E580[D_8120D820[0xE7 - i] - i * 2 + 0x5B] * 0xC0) + D_8122C744, 0xFFFE, 0xC, 0xC,
                              0x10);
                xpos += D_8120E580[D_8120E580[D_8120D820[0xE7 - i] - i * 2 + 0x5B]];
                if (D_8120D820[0xE6 - i] < 0x40) {
                    break;
                }
            }
        }
    }

    for (x = 0; x < 6; x++) {
        func_812016DC(dst + 0xB916 + x * 46);
        if (arg1 != NULL) {
            osInvalDCache((*arg1) + (0, x), sizeof((*arg1)[x])); // FAKE: (0, x)
            func_812015EC(dst + 0xBCD9 + x * 46, (*arg1) + (0, x), 0, 40, 40);
        }
    }

    for (j = 0; j < 6; j++) {
        for (x = 0; x < 320; x++) {
            dst[(j + 27) * 320 + x] = 0x25A;
            dst[(j + 121) * 320 + x] = 0x25A;
        }
    }

    for (x = 0; x < 320; x += 8) {
        func_812015EC(dst + 33 * 320 + x, (u16*) ((u8*) D_8122C748 + 0x3500), 0xFFFF, 8, 8);
        func_812015EC(dst + 113 * 320 + x, (u16*) ((u8*) D_8122C748 + 0x3580), 0xFFFF, 8, 8);
    }

    for (j = 0; j < 72; j++) {
        for (x = 0; x < 320; x++) {
            dst[(j + 41) * 320 + x] = 0x2BA4;
        }
    }

    switch (arg2) {
        case 1:
            D_8122C754 = (u8*) dst + 2;
            break;
        case 2:
            D_8122C754 = (u8*) dst + 4;
            break;
        case 3:
            D_8122C754 = (u8*) dst + 6;
            break;
        default:
            D_8122C754 = (u8*) dst;
            break;
    }

    func_812015EC(dst + 0x4E38, (u16*) ((u8*) D_8122C748 + 0x3600), 0, 0x56, 0x21);
    func_812015EC((u16*) (D_8122C754 + 0x61E0), (u16*) ((u8*) D_8122C748 + 0x4CB0), 0, 0x3C, 0x4B);

    switch (arg3) {
        case 0:
            func_812015EC((u16*) (D_8122C754 + 0x6706), (u16*) ((u8*) D_8122C748 + 0x6FD8), 0, 0x17, 0x19);
            break;
        case 1:
            break;
        case 2:
            func_812015EC((u16*) (D_8122C754 + 0x6706), (u16*) ((u8*) D_8122C748 + 0x7730), 0, 0x17, 0x19);
            break;
        case 3:
            func_812015EC((u16*) (D_8122C754 + 0x6706), (u16*) ((u8*) D_8122C748 + 0x7BE0), 0, 0x17, 0x19);
            break;
    }

    D_8122C771 = arg2;
    func_81202758((s32) (D_8122C754 + 0x87BA), 0);
    D_8122C770 = 0;
    D_8122C768 = 0x800000;
    D_8122C764 = 0xA0;
}

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
void func_812070A0(void);
void func_8120735C(s32);
void func_81208C08(u16, u8, u16);
void func_81208D7C(void);
void func_81208E28(unk_D_8122B2F8*);
void func_81208F94(void);
void func_8120935C(s32);

void func_812033F4(s32 arg0, s32 arg1, OSId arg2, s32 arg3, OSMesgQueue* arg4, u16 (*arg5)[6][0x640]) {
    unk_D_8122B2C0* emu;
    s32 pad[2];
    s32 i;

    D_8122B1E0 = func_80006314(0, 2, 320, 288, 1);
    D_8122B1E4 = func_80006314(0, 2, 320, 288, 1);
    D_8122B2F8 = main_pool_alloc(0x1FEAE8, 0);
    if (D_8122B2F8 == NULL) {
        D_8122C4DC = 1;
        D_8122B2FC = 4;
        return;
    }
    D_8122B2F4 = (u8*)D_8122B2F8;

    osCreateMesgQueue(&D_8122B1E8[0].queue, D_8122B1E8[0].mesg, 1);
    osCreateMesgQueue(&D_8122B1E8[1].queue, D_8122B1E8[1].mesg, 1);
    D_8122B2F0 = 0;

    switch (osTvType) {
        case OS_TV_PAL:
            osViSetMode(&D_800795C0);
            break;
        case OS_TV_MPAL:
            osViSetMode(&osViModeMpalLpn1);
            break;
        case OS_TV_NTSC:
            osViSetMode(&osViModeNtscLpn1);
            break;
    }
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_OFF);
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_OFF);
    osViBlack(TRUE);

    D_8122C4E0 = 0;
    D_8122C4D8 = arg4;
    osCreateMesgQueue(&D_8122C4C0, D_8122C4B0, ARRAY_COUNT(D_8122C4B0));
    osCreateThread(&D_8122B300.thread, arg2, (void (*)(void*)) func_81200AA8, NULL, D_8122B300.stack + sizeof(D_8122B300.stack), arg3);
    osStartThread(&D_8122B300.thread);

    D_8122B2B8 = 0;
    D_8122B2EC = D_8122B2F4;
    D_8122B2F4 += 0xC410;

    for (i = 0; i < 1; i++) {
        emu = (unk_D_8122B2C0*)D_8122B2F4;
        (&D_8122B2C0)[i] = emu;
        bzero(emu, sizeof(unk_D_8122B2C0));
        D_8122B2F4 += sizeof(unk_D_8122B2C0);
        emu->unk_53B4 = D_8122B2F4;
        D_8122B2F4 += 0x6000;
        if (i == 0) {
            emu->unk_53A8 = D_8122B2F4;
            D_8122B2F4 += 0x4D40;
            emu->unk_53AC = D_8122B2F4;
            D_8122B2F4 += 0x4D40;
            emu->unk_53B0 = D_8122B2F4;
            D_8122B2F4 += 0x4D40;
            emu->unk_5388 = 0x400;
            if (i == 0) {
                emu->unk_53BC = D_8122B2F4;
                D_8122B2F4 += 0x100000;
            } else {
                emu->unk_53BC = D_8122B2C0->unk_53BC;
            }
            func_8120311C(emu);
            if ((i == 0) && (arg1 >= 0)) {
                if (arg1 < 4) {
                    emu->unk_5DCA = 1;
                }
                emu->unk_5DCC = arg1;
                osSendMesg(&D_8122C4C0, emu, OS_MESG_BLOCK);
            }
        }
    }

    func_80003B30((u32)(D_8122B2F4 + 0xC5C0), (u32)D_102BA0, ((u32)fragment2_ROM_START + 1) & ~1, 0);
    Yay0_Decompress((void*)((u32)D_8122B2F4 + 0xC5C0), D_8122B2F4);
    D_8122C748 = D_8122B2F4;
    D_8122B2F4 += 0xC5C0;
    D_8122B2C0->unk_5C58 = D_8122C748;
    D_8122C74C = 0;

    for (i = 0; i < 2; i++) {
        D_8122B1E8[i].unk_20 = 2;
        D_8122B1E8[i].unk_24 = 0;
        func_812029B0((u16*)(&D_8122B1E0)[i]->img_p, arg5, arg1, 0);
        D_8122C758[i] = D_8122C754;
    }

    func_812070A0();
    func_80003B30((u32)(D_8122B2F4 + 0x80000), (u32)fragment1_misc_yay0_ROM_START, ((u32)D_F4130 + 1) & ~1, 0);
    Yay0_Decompress((void*)((u32)D_8122B2F4 + 0x80000), D_8122B2F4);
    func_81208E28((unk_D_8122B2F8*)D_8122B2F4);
    func_8120935C(0);
    func_8120735C(0);
    func_81208D7C();
    func_81208C08(0xFF26, 0, 0);
    func_81208C08(0xFF26, 0x8F, 0x10);
    func_81208C08(0xFF24, 0x77, 0x20);
    func_81208C08(0xFF25, 0xFF, 0x30);
    func_81208F94();
    D_8122B2F4 += 0x80000;

    D_8122C4E4 = D_8122C4E2;
    D_8122C4E3 = 0;
    if (D_8122C4E2 == 2) {
        D_8122C4E5 = 2;
    } else {
        D_8122C4E5 = 1;
    }

    for (i = 0; i < 3; i++) {
        ((u8**)D_8122B2C8)[i] = D_8122B2F4;
        D_8122B2F4 += 0xE200;
        bzero(D_8122B2F4, 0x2800);
        ((u8**)D_8122B2D8)[i] = D_8122B2F4;
        D_8122B2F4 += 0x2800;
    }

    switch (D_8122C4E2) {
        case 2:
            func_80003B30((u32)D_8122B2C8[0], (u32)D_FDE40, ((u32)D_102BA0_END + 1) & ~1, 0);
            Yay0_Decompress(D_8122B2C8[0], D_8122B2C8[2]);
            /* fallthrough */
        case 1:
            func_80003B30((u32)D_8122B2C8[0], (u32)D_F5450, ((u32)D_FDE40 + 1) & ~1, 0);
            Yay0_Decompress(D_8122B2C8[0], D_8122B2C8[1]);
            break;
        case 0:
        default:
            func_80003B30((u32)D_8122B2C8[0], (u32)D_F4920, ((u32)D_F5450 + 1) & ~1, 0);
            Yay0_Decompress(D_8122B2C8[0], D_8122B2C8[1]);
            break;
    }

    while ((D_8122B2F4 - (u8*)D_8122B2F8) != 0x1FEAE8) {}

    osWritebackDCacheAll();

    emu = D_8122B2C0;
    if (emu->unk_5DCA != 0) {
        while (emu->unk_5DC8 != 0) {}
        for (i = ((emu->unk_5DC5 != 0) ? 0x500 : 0) / 256; i < 0x80; i++) {
            emu->unk_582C[i] = 0;
        }
        if (emu->unk_5DCA == 0) {
            D_8122C4DC = 1;
            D_8122B2FC = 1;
            func_81203304();
            return;
        }
        D_8122C4E8 = 0xFF;
        func_81202210(0, 1);
        func_81202210(1, 1);
        func_8120241C();
        if ((emu->unk_5DC5 == 0) || (emu->unk_5DC5 == 2)) {
            D_8122C4DC = 1;
            D_8122B2FC = 1;
            func_81203304();
            return;
        }
        D_8122C4DC = 5;
        func_812029B0((u16*)D_8122B1E0->img_p, arg5, arg1, (emu->unk_5DC5 != 0) ? emu->unk_5DC5 - 1 : 0);
        func_812029B0((u16*)D_8122B1E4->img_p, arg5, arg1, (emu->unk_5DC5 != 0) ? emu->unk_5DC5 - 1 : 0);
    }

    D_8122C760 = osGetCount();
    D_8122C76C = D_8122C760;
    osViSwapBuffer((&D_8122B1E0)[D_8122B2B8]->img_p);
    D_8122B2B8 ^= 1;
}
void func_81203C58(unk_D_8122B2C0* arg0) {
    u16* list;
    s32 i;
    s32 count;
    s32 bank;
    u32 rom;
    s32 j;
    u8* src;
    u8* dst;

    // FAKE
    if ((u16*) arg0->unk_5D70[2]) {}

    list = (u16*) arg0->unk_5D70[2];
    if (list != 0) {
        rom = arg0->unk_5D70[3] + 0x7C0000;
        do {
            bank = *list & 0xFF;
            count = *list / 256;
            func_80003B30((u32) arg0->unk_53BC + 0xEC000, rom, list[1] + rom, 0);
            rom += list[1];
            list += 2;
            Yay0_Decompress((void*) ((u32) arg0->unk_53BC + 0xEC000), (void*) ((u32) arg0->unk_53BC + (bank << 14)));
            for (i = 0; i < count; i++) {
                if (i + 1 >= arg0->unk_5DC6) {
                    func_80003B30((u32) arg0->unk_53BC + 0xF0000, rom, *list + rom, 0);
                    Yay0_Decompress((void*) ((u32) arg0->unk_53BC + 0xF0000), (void*) ((u32) arg0->unk_53BC + 0xEC000));
                    src = (u8*) ((u32) arg0->unk_53BC + 0xEC000);
                    dst = (u8*) ((u32) arg0->unk_53BC + (bank << 14));
                    for (j = 0; j < 0x1000; j++) {
                        dst[j] ^= src[j];
                    }
                }
                rom += *list++;
            }
            arg0->unk_549C[bank] = 0xFF;
        } while (*list);
    }
}

void func_81203E30(void) {
  if ((D_8122C4FA.unk_01 == D_8122C4FA.unk_00) || (D_8122C4FA.unk_00 >= 5) || (D_8122C4FA.unk_01 >= 5)) {
      D_8122C4FA.unk_00 = 0;
      D_8122C4FA.unk_01 = 1;
  }

  D_8122C4F2 = (D_8122C4FA.unk_00 == 1) ?   0x20 : (D_8122C4FA.unk_00 == 2) ? 0x10 : (D_8122C4FA.unk_00 == 3) ? 2 : (D_8122C4FA.unk_00 == 4) ? 4 : 0x1000;
  D_8122C4F4 = (D_8122C4FA.unk_01 == 0) ? 0x1000 : (D_8122C4FA.unk_01 == 2) ? 0x10 : (D_8122C4FA.unk_01 == 3) ? 2 : (D_8122C4FA.unk_01 == 4) ? 4 : 0x20;
}

void func_81203F3C(unk_D_8122B2C0* arg0) {
    u8 var_v0;
    u8 var_v0_2;

    switch (arg0->unk_5DC9) {
        case 8:
            D_8122C4F7 = 0x12;
            goto block_9;
        case 9:
            D_8122C4F7 = 0x13;
            goto block_9;
        case 10:
            D_8122C4F7 = 0x14;
            goto block_9;
        case 11:
            D_8122C4F7 = 0x15;
        block_9:
            func_8120935C(1);
            func_81209368(1);

            D_8122C4FA.unk_00 = (D_8122C4F2 == 0x20)   ? 1
                                : (D_8122C4F2 == 0x10) ? 2
                                : (D_8122C4F2 == 2)    ? 3
                                : (D_8122C4F2 == 4)    ? 4
                                                       : 0;
            D_8122C4FA.unk_01 = (D_8122C4F2 == 0x1000) ? 0
                                : (D_8122C4F2 == 0x10) ? 2
                                : (D_8122C4F2 == 2)    ? 3
                                : (D_8122C4F2 == 4)    ? 4
                                                       : 1;

            if (D_8122C4FA.unk_01 == D_8122C4FA.unk_00) {
                D_8122C4FA.unk_00 = 0;
                D_8122C4FA.unk_01 = 1;
            }
            return;
        default:
            if ((D_8122C4F7 == 0x12) || (D_8122C4F7 == 0x13) || (D_8122C4F7 == 0x14) || (D_8122C4F7 == 0x15)) {
                func_81209368(1);
                func_8120935C(0);
                D_8122C4F7 = 0;
                return;
            }
            if (D_8122C4F7 == 0) {
                if ((gPlayer1Controller->buttonPressed & 8) && (arg0->unk_5DD0 == 0) && (D_8122C4F0 == 0x40)) {
                    arg0->unk_53FD = 0x40;
                    func_8120935C(1);
                    func_81209368(1);
                    D_8122C4F7 = 1;
                }
                return;
            }
            {
                ((unk_D_8122B1E8*) D_8122B224)[D_8122B2B8].mesg[0] = NULL;
                switch (D_8122C4F7) {
                    case 1:
                        arg0->unk_53FD -= 4;
                        if (arg0->unk_53FD <= 0) {
                            arg0->unk_53FD = 0;
                            if (gPlayer1Controller->buttonPressed & 0xD000) {
                            set_11:
                                D_8122C4F7 = 0x11;
                                return;
                            }
                            if (gPlayer1Controller->buttonPressed & 0x800) {
                            set_3:
                                func_81209368(7);
                                D_8122C4F7 = 3;
                                return;
                            }
                            if (gPlayer1Controller->buttonPressed & 0x400) {
                            set_2:
                                func_81209368(7);
                                D_8122C4F7 = 2;
                                return;
                            }
                        }
                        break;
                    case 17:
                        if (gPlayer1Controller->buttonDown == 0) {
                            func_81203E30();
                            arg0->unk_53FD = 0x40;
                            func_81209368(1);
                            func_8120935C(0);
                            D_8122C4F7 = 0;
                        }
                        break;
                    case 2:
                        if (gPlayer1Controller->buttonPressed & 0x800) {
                        set_1:
                            func_81209368(7);
                            D_8122C4F7 = 1;
                            return;
                        }
                        if (gPlayer1Controller->buttonPressed & 0x400) {
                            goto set_3;
                        }
                        if (gPlayer1Controller->buttonPressed & 0x9000) {
                            func_81209368(2);
                            D_8122C4F7 = 4;
                            return;
                        }
                        if (gPlayer1Controller->buttonPressed & 0x4000) {
                            goto set_11;
                        }
                        break;
                    case 3:
                        if (gPlayer1Controller->buttonPressed & 0x800) {
                            goto set_2;
                        }
                        if (gPlayer1Controller->buttonPressed & 0x400) {
                            goto set_1;
                        }
                        if (gPlayer1Controller->buttonPressed & 0x9000) {
                            func_81209368(6);
                            D_8122C4F7 = 6;
                            return;
                        }
                        if (gPlayer1Controller->buttonPressed & 0x4000) {
                            goto set_11;
                        }
                        break;
                    case 4:
                    case 5:
                        if (gPlayer1Controller->buttonPressed & 0x4000) {
                            func_81209368(8);
                            D_8122C4F7 = 2;
                            return;
                        }
                        if (gPlayer1Controller->buttonPressed & 0x300) {
                            func_81209368(5);
                            D_8122C4F7 = D_8122C4F7 == 4 ? 5 : 4;
                            return;
                        }
                        if (gPlayer1Controller->buttonPressed & 0x9000) {
                            if (D_8122C4F7 == 4) {
                                D_8122C4F7 = 0xF;
                                return;
                            }
                            D_8122C4F7 = 1;
                            return;
                        }
                        break;
                    case 6:
                        switch (gPlayer1Controller->buttonPressed) {
                            case 0x4000:
                            back_to_3:
                                func_81209368(8);
                                D_8122C4F7 = 3;
                                return;
                            case 0x8000:
                                func_81209368(6);
                                D_8122C774 = (s32) D_8122C4FA.unk_00;
                                D_8122C4F8 = 0;
                                D_8122C4F7 = 7;
                                return;
                            case 0x1000:
                                var_v0 = 0;
                                goto block_96;
                            case 0x20:
                                var_v0 = 1;
                                goto block_96;
                            case 0x10:
                                var_v0 = 2;
                                goto block_96;
                            case 0x2:
                                var_v0 = 3;
                                goto block_96;
                            case 0x4:
                                var_v0 = 4;
                            block_96:
                                if (D_8122C4FA.unk_01 == var_v0) {
                                    func_81209368(3);
                                    return;
                                }
                                D_8122C4FA.unk_00 = var_v0;
                                func_81209368(6);
                                if (D_8122C4F7 == 8) {
                                    D_8122C4F7 = 9;
                                    return;
                                }
                                break;
                            case 0x400:
                            case 0x800:
                                func_81209368(7);
                                D_8122C4F7 = 0xA;
                                return;
                        }
                        break;
                    case 10:
                        switch (gPlayer1Controller->buttonPressed) {
                            case 0x4000:
                                goto back_to_3;
                            case 0x8000:
                                func_81209368(6);
                                D_8122C4F8 = 0;
                                D_8122C774 = (s32) D_8122C4FA.unk_01;
                                D_8122C4F7 = 0xB;
                                return;
                            case 0x1000:
                                var_v0_2 = 0;
                                goto block_119;
                            case 0x20:
                                var_v0_2 = 1;
                                goto block_119;
                            case 0x10:
                                var_v0_2 = 2;
                                goto block_119;
                            case 0x2:
                                var_v0_2 = 3;
                                goto block_119;
                            case 0x4:
                                var_v0_2 = 4;
                            block_119:
                                if (D_8122C4FA.unk_00 == var_v0_2) {
                                    func_81209368(3);
                                    return;
                                }
                                D_8122C4FA.unk_01 = var_v0_2;
                                func_81209368(6);
                                if (D_8122C4F7 == 0xC) {
                                    D_8122C4F7 = 0xD;
                                    return;
                                }
                                break;
                            case 0x400:
                            case 0x800:
                                func_81209368(7);
                                D_8122C4F7 = 6;
                                return;
                        }
                        break;
                    case 7:
                    case 11:
                        if ((s32) D_8122C4F8 < 0xA) {
                            D_8122C4F8 += 1;
                            return;
                        }
                        if (D_8122C4F7 == 7) {
                            D_8122C4F7 = 8;
                            return;
                        }
                        D_8122C4F7 = 0xC;
                        return;
                    case 8:
                        switch (gPlayer1Controller->buttonPressed) {
                            case 0x4000:
                                func_81209368(8);
                                D_8122C4FA.unk_00 = D_8122C774;
                                D_8122C4F7 = 9;
                                return;
                            case 0x8000:
                                if (D_8122C4FA.unk_00 == D_8122C4FA.unk_01) {
                                    func_81209368(3);
                                } else {
                                    func_81209368(6);
                                    D_8122C4F7 = 9;
                                }
                                return;
                            case 0x200:
                                D_8122C4FA.unk_00--;
                                if ((D_8122C4FA.unk_00 < 0) || (D_8122C4FA.unk_00 >= 5)) {
                                    D_8122C4FA.unk_00 = 0U;
                                }
                                func_81209368(5);
                                return;
                            case 0x100:
                                D_8122C4FA.unk_00++;
                                if (D_8122C4FA.unk_00 >= 5) {
                                    D_8122C4FA.unk_00 = 4U;
                                }
                                func_81209368(5);
                                return;
                            case 0x1000:
                                var_v0 = 0;
                                goto block_96;
                            case 0x20:
                                var_v0 = 1;
                                goto block_96;
                            case 0x10:
                                var_v0 = 2;
                                goto block_96;
                            case 0x2:
                                var_v0 = 3;
                                goto block_96;
                            case 0x4:
                                var_v0 = 4;
                                goto block_96;
                        }
                        break;
                    case 12:
                        switch (gPlayer1Controller->buttonPressed) {
                            case 0x4000:
                                func_81209368(8);
                                D_8122C4FA.unk_01 = D_8122C774;
                                D_8122C4F7 = 0xD;
                                return;
                            case 0x8000:
                                if (D_8122C4FA.unk_00 == D_8122C4FA.unk_01) {
                                    func_81209368(3);
                                } else {
                                    func_81209368(6);
                                    D_8122C4F7 = 0xD;
                                }
                                return;
                            case 0x200:
                                D_8122C4FA.unk_01--;
                                if ((D_8122C4FA.unk_01 < 0) || (D_8122C4FA.unk_01 >= 5)) {
                                    D_8122C4FA.unk_01 = 0U;
                                }
                                func_81209368(5);
                                return;
                            case 0x100:
                                D_8122C4FA.unk_01++;
                                if (D_8122C4FA.unk_01 >= 5) {
                                    D_8122C4FA.unk_01 = 4U;
                                }
                                func_81209368(5);
                                return;
                            case 0x1000:
                                var_v0_2 = 0;
                                goto block_119;
                            case 0x20:
                                var_v0_2 = 1;
                                goto block_119;
                            case 0x10:
                                var_v0_2 = 2;
                                goto block_119;
                            case 0x2:
                                var_v0_2 = 3;
                                goto block_119;
                            case 0x4:
                                var_v0_2 = 4;
                                goto block_119;
                        }
                        break;
                    case 9:
                    case 13:
                        if (D_8122C4F8 != 0) {
                            D_8122C4F8 -= 1;
                            return;
                        }
                        if (D_8122C4F7 == 9) {
                            D_8122C4F7 = 6;
                            return;
                        }
                        D_8122C4F7 = 0xA;
                        return;
                    case 14:
                        if (gPlayer1Controller->buttonDown == 0) {
                            func_81203E30();
                            D_8122C4F7 = 0xF;
                        }
                        break;
                    case 15:
                        D_8122C4F0 -= 4;
                        if (D_8122C4F0 > 0) {
                            return;
                        }
                        D_8122C4F0 = 0;
                        D_8122C4F7 = 0x10;
                        /* fallthrough */
                    case 16:
                        func_81209368(1);
                        func_8120935C(0);
                        func_81208D7C();
                        break;
                }
            }
            break;
    }
}

void func_81204A84(s32 arg0) {
    s32 pad;
    s32 j;
    s32 i;
    s32 c1;
    s32 c2 = 0;
    s32 c3;
    s32 y;
    s32 x;
    u16* volatile fb;
    u16* base;
    s32 row;
    u16* p;

    if (D_8122C4F7 == 0) {
        return;
    }

    fb = (u16*)arg0;
    base = (u16*)arg0 - 14;

    switch (D_8122C4F7) {
        case 0x12:
        case 0x13:
            func_812011D0(base, D_8120E8C0);
            goto transition;
        case 0x14:
            D_8122B2E8 ^= 1;
            D_8122C4E7++;
            if (D_8122C4E7 >= 11) {
                D_8122C4E7 = 0;
            }
            goto transition;
        case 0x15:
            func_812011D0(base, D_8120E958);
        transition:
            func_812020C0((u16*)((u8*)D_8122B2D8[D_8122B2E8] + 0x9C), 1, D_8122C4E7);
            D_8122B1E8[D_8122B2B8].unk_3C = 0x1010;
            D_8122B1E8[D_8122B2B8].unk_38 = (s32)D_8122B2D8[D_8122B2E8];
            D_8122B1E8[D_8122B2B8].unk_5C &= 0xFFFF;
            func_812011D0(base, D_8120E8D8);
            return;

        default:
            switch (D_8122C4F7) {
        case 1:
        case 17:
            base = fb + 0x3C3E;
            func_812015EC(base + 0x1B8A, (u16*)(D_8122C748 + 0xC2F8), 0, 16, 10);
            c1 = 0xB;
            c2 = 8;
            c3 = 8;
            goto draw_items;
        case 4:
        case 5:
            c1 = 8;
            c2 = 0xB;
            c3 = 8;
            base = fb + 0x3C3E;
            goto draw_items;
        case 2:
            base = fb + 0x3C3E;
            func_812015EC(base + 0x348A, (u16*)(D_8122C748 + 0xC2F8), 0, 16, 10);
            c1 = 8;
            c2 = 0xB;
            c3 = 8;
            goto draw_items;
        case 3:
            base = fb + 0x3C3E;
            func_812015EC(base + 0x4D8A, (u16*)(D_8122C748 + 0xC2F8), 0, 16, 10);
            c1 = 8;
            c2 = 8;
            c3 = 0xB;
        draw_items:
            func_812011D0(base, D_8120E688);
            D_8120E694[4] = c1;
            func_812011D0(base, D_8120E694);
            D_8120E6A8[4] = c2;
            func_812011D0(base, D_8120E6A8);
            D_8120E6B8[4] = c3;
            func_812011D0(base, D_8120E6B8);
            for (i = 8; i < 0x94; i++) {
                base[80 * 320 + i] = 0xFFFF;
            }
            break;
            }
            break;
    }

    switch (D_8122C4F7) {
        case 1:
        case 17:
            func_812011D0(fb + 0x3C3E, D_8120E6D0);
            break;
        case 2:
            func_812011D0(fb + 0x3C3E, D_8120E718);
            break;
        case 3:
            func_812011D0(fb + 0x3C3E, D_8120E760);
            break;
        case 4:
            func_812015EC(fb + 0xDC48, (u16*)(D_8122C748 + 0xC2F8), 0, 16, 10);
            /* fallthrough */
        case 14:
            c1 = 0xB;
            c2 = 8;
            base = fb + 0x3C3E;
            goto draw_submenu;
        case 5:
            base = fb + 0x3C3E;
            func_812015EC(base + 0xA050, (u16*)(D_8122C748 + 0xC2F8), 0, 16, 10);
            c1 = 8;
            c2 = 0xB;
        draw_submenu:
            func_812011D0(base, D_8120E7A0);
            D_8120E7CC[4] = c1;
            D_8120E7DC[0] = c2;
            func_812011D0(base, D_8120E7CC);
            func_812011D0(base, D_8120E7D8);
            break;
    }

    switch (D_8122C4F7) {
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            base = fb + 0x3C3E;
            y = 0x4A;
            if (D_8122C4E2 == 1) {
                func_812015EC(base + 0x784, (u16*)(D_8122C748 + 0xB758), 0, 16, 12);
                func_812011D0(base, D_8120E7E4);
            } else if (D_8122C4E2 == 2) {
                func_812015EC(base + 0x784, (u16*)(D_8122C748 + 0xB758), 0, 16, 12);
                func_812011D0(base, D_8120E834);
            } else {
                y = 0x32;
            }
            for (j = 1; j < 0x3F; j++) {
                base[(y + j) * 320 + 1] = base[(y + j) * 320 + 2] = base[(y + j) * 320 + 0x9D] =
                    base[(y + j) * 320 + 0x9E] = 0xFFFF;
            }
            for (i = 2; i < 0x9E; i++) {
                if ((i < 0x10) || (i >= 0x43)) {
                    base[y * 320 + i] = base[(y + 1) * 320 + i] = 0xFFFF;
                }
                base[(y + 62) * 320 + i] = base[(y + 63) * 320 + i] = 0xFFFF;
            }
            D_8120E898[2] = y - 5;
            func_812011D0(base, D_8120E898);
            func_812015EC(y * 320 + base + 0x3C1C, (u16*)(D_8122C748 + 0xB2D8), 0, 16, 12);
            D_8120E8A8[2] = y + 0x30;
            func_812011D0(base, D_8120E8A8);
            break;
    }

    x = 0x28 - D_8122C4F8 * 4;
    switch (D_8122C4F7) {
        case 7:
        case 8:
        case 9:
            i = 0;
            row = y * 320;
            base = fb + 0x3C3E;
            goto draw_second;
        case 11:
        case 12:
        case 13:
            i = 0;
            row = y * 320;
            base = fb + 0x3C3E;
            goto draw_first;
        case 6:
            i = 0;
            row = y * 320;
            base = fb + 0x3C3E;
            goto draw_cursor;
        case 10:
            i = 0x14;
            row = y * 320;
            base = fb + 0x3C3E;
        draw_cursor:
            func_812015EC((y + i) * 320 + base + 0xF14, (u16*)(D_8122C748 + 0xC2F8), 0, 16, 10);
            x = 0x28;
            i = 1;
        draw_first:
            switch (D_8122C4FA.unk_00) {
                case 0:
                default:
                    j = 0xBBD8;
                    break;
                case 1:
                    j = 0xB8D8;
                    break;
                case 2:
                    j = 0xBA58;
                    break;
                case 3:
                    j = 0xB5D8;
                    break;
                case 4:
                    j = 0xB458;
                    break;
            }
            func_812015EC((((i == 0) ? 0x28 : x) + row) + base + 0xCBC, (u16*)(D_8122C748 + j), 0, 16, 12);
            if (i == 0) {
                break;
            }
        draw_second:
            switch (D_8122C4FA.unk_01) {
                case 0:
                    j = 0xBBD8;
                    break;
                case 1:
                default:
                    j = 0xB8D8;
                    break;
                case 2:
                    j = 0xBA58;
                    break;
                case 3:
                    j = 0xB5D8;
                    break;
                case 4:
                    j = 0xB458;
                    break;
            }
            func_812015EC((((i == 0) ? 0x28 : x) + row) + base + 0x25BC, (u16*)(D_8122C748 + j), 0, 16, 12);
            break; } switch (D_8122C4F7) { case 6: case 7: case 8: case 9: i = x + 8; row = y * 320; j = 0x30; base = fb + 0x3C3E; goto draw_arrows; case 10: case 11: case 12: case 13: i = 0x30; row = y * 320; j = x + 8; base = fb + 0x3C3E; draw_arrows: p = (row + i) + base; // single line needed to match
            func_812015EC(p + 0xC80, (u16*)(D_8122C748 + 0xBF98), 0, 24, 12);
            func_812015EC(p + 0xC98, (u16*)(D_8122C748 + 0xC438), 0, 16, 12);
            p = (row + j) + base;
            func_812015EC(p + 0x257E, (u16*)(D_8122C748 + 0xBD58), 0, 24, 12);
            func_812015EC(p + 0x2598, (u16*)(D_8122C748 + 0xC438), 0, 16, 12);
            break;
    }

    switch (D_8122C4F7) {
        case 8:
            j = D_8122C4FA.unk_00;
            i = 0;
            base = fb + 0x3C3E;
            break;
        case 12:
            i = 0x14;
            j = D_8122C4FA.unk_01;
            base = fb + 0x3C3E;
            break;
        default:
            return;
    }
    row = y + i;
    p = row * 320 + base;
    func_812015EC(p + 0xCBA, (u16*)(D_8122C748 + 0xBBD8), 0, 16, 12);
    func_812015EC(p + 0xCCC, (u16*)(D_8122C748 + 0xB8D8), 0, 16, 12);
    func_812015EC(p + 0xCDE, (u16*)(D_8122C748 + 0xBA58), 0, 16, 12);
    func_812015EC(p + 0xCF0, (u16*)(D_8122C748 + 0xB5D8), 0, 16, 12);
    func_812015EC(p + 0xD02, (u16*)(D_8122C748 + 0xB458), 0, 16, 12);
    row += 7;
    x = j * 0x12 + 0x37;
    for (j = 1; j < 0x11; j++) {
        base[(row + j) * 320 + x] = base[(row + j) * 320 + x + 1] = base[(row + j) * 320 + x + 0x10] =
            base[(row + j) * 320 + x + 0x11] = 0xE71C;
    }
    for (i = 1; i < 0x10; i++) {
        base[row * 320 + x + i] = base[(row + 1) * 320 + x + i] = base[(row + 16) * 320 + x + i] =
            base[(row + 17) * 320 + x + i] = 0xE71C;
    }
}

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
