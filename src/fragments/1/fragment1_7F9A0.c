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
extern s16 D_8122C4F0;
extern u8 D_8122C4F7;
extern u8 D_8122C4F8;
extern s32 D_8122C774;
extern Controller* gPlayer1Controller;
extern u8 D_8122B2C4[];
extern u8 D_8122B2E4[];
extern u8 fragment2_ROM_START[];
extern u8 fragment1_misc_yay0_ROM_START[];
extern OSMesgQueue D_8122B1EC;
extern OSMesgQueue D_8122B254;
extern OSMesg D_8122B250;
extern OSMesgQueue* D_8122C4D8;
extern s32 D_8122C4DC;
extern u8 D_8122C4E0;
extern u8 D_8122C540[];
extern u8 D_8122C640[];
extern u8 D_8122C4E2;
extern u8 D_8122C4E3;
extern u8 D_8122C4E4;
extern u8 D_8122C4E5;
extern s8 D_8122C4E7;
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
extern u8 D_8120E7DC;
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
extern unk_D_8122C748* D_8122C748;
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

void func_81200AA8(UNUSED void* arg0, UNUSED s32 arg1, UNUSED s32 arg2, UNUSED s32 arg3, s32 arg4) {
    unk_D_8122B2C0* pak;
    OSMesg msg;
    s32* fp;
    s32* s2;
    s32* s3;
    s32 s4;
    s32 s0;
    s32 s1;
    s32 s5;
    s32 s6;
    s32 s7;
    s32 v0;
    s32 v1;
    s32 i;
    s32 sum;

    D_8122C4E0 = 1;
    s2 = (s32*) &D_8122C540;
    s3 = (s32*) &D_8122C640;
    fp = (s32*) &D_8122C4D8;
    s4 = arg4;
    s1 = 0x2000;
    s5 = -2;
    s6 = 0xFF;
    s7 = 2;
    for (;;) {
        osRecvMesg(&D_8122C4C0, &msg, 1);
        pak = (unk_D_8122B2C0*) msg;
        if (msg == 0) {
            D_8122C4E0 = 0;
            osDestroyThread(0);
        }
        pak->unk_5DC8 = 1;
        if (pak->unk_5DCA != 0 || pak->unk_5DCC >= 4) {
            pak->unk05DCD[0] = 0x49;
        } else {
            pak->unk05DC6[1] = 0;
            pak->unk_5DC8 = 0;
            continue;
        }
    retry:
        if (pak->unk05DCD[0] <= 0) {
            pak->unk_5DCA = 0;
            pak->unk_5DC8 = 0;
            continue;
        }
        switch (pak->unk_5DC9) {
        case 0:
            pak->unk_5DC9 = 1;
            bzero((u8*) pak + 0x5C5C, 0x50);
        case 1:
            if (osGbpakInit((OSMesgQueue*) fp[0], &pak->pfs, pak->unk_5DCC) != 0) {
                goto retry;
            }
            if (osGbpakReadId(&pak->pfs, (OSGbpakId*) ((u8*) pak + 0x5C5C), &pak->status) != 0) {
                goto retry;
            }
            if (func_81200020(pak) != 0) {
                goto retry;
            }
            if (func_812000DC(pak) != 0) {
                goto retry;
            }
            pak->transferBuffer = (u8*) pak + 0x5DA4;
            pak->gbAddress = 0x9C000;
            pak->transferSize = 0x20;
            if (func_812006AC(pak) != 0) {
                goto retry;
            }
            if ((pak->status & 1) == 0) {
                goto retry;
            }
            pak->unk_5DC5 = func_812009D0((u8*) pak + 0x5C5C);
            pak->unk_5DC9 = 2;
        case 2:
            switch (pak->unk05DC6[1]) {
            case 0:
                pak->unk05DCD[0] -= 0x17;
                if (func_812006AC(pak) != 0) {
                    goto retry;
                }
                pak->unk05DC6[1] = 0;
                continue;
            case 1:
                pak->unk05DCD[0] -= 0x17;
                if (func_812008C8(pak, 0) != 0) {
                    goto retry;
                }
                pak->unk05DC6[1] = 0;
                continue;
            case 2:
                pak->unk05DCD[0] -= 0x17;
                if (func_812008C8(pak, 1) != 0) {
                    goto retry;
                }
                pak->unk05DC6[1] = 0;
                continue;
            case 3:
                pak->transferBuffer = (u8*) s2;
                pak->transferSize = 0x100;
                if (func_812008C8(pak, 1) != 0) {
                    goto poweroff;
                }
                pak->transferBuffer = (u8*) s3;
                if (func_812008C8(pak, 0) != 0) {
                    goto poweroff;
                }
                if (bcmp(s2, s3, 0x100) == 0) {
                    v0 = (s32) pak + (pak->gbAddress >> 8);
                    if (*(u8*) ((u8*) v0 + 0x5A2C) != 0) {
                        *(u8*) ((u8*) v0 + 0x5A2C) = 2;
                    }
                    pak->unk05DC6[1] = 0;
                    continue;
                }
                goto poweroff;
            case 4:
                pak->unk05DCD[0] -= 2;
                s0 = pak->unk_5D70[1];
                v0 = *(u16*) s0;
                s6 = v0 & 0x8000;
                do {
                    if (s6 != 0) {
                        v1 = v0;
                        v0 = v1 & 0xF;
                        if (pak->unk_559C[v0] == 0) {
                            pak->gbAddress = (v0 & 0xF) << 13;
                            pak->transferBuffer = (u8*) pak + pak->gbAddress + 0x12DF0;
                            pak->transferSize = 0x2000;
                            if (func_812008C8(pak, 0) != 0) {
                                pak->unk_5DCA = 0;
                                continue;
                            }
                            pak->unk_559C[v0] = 0xFF;
                        }
                        s0 += 2;
                    } else {
                        v1 = v1;
                        if (pak->unk_549C[v1 & 0xF] != 0) {
                            s0 += 6;
                        } else {
                            pak->gbAddress = v1 << 14;
                            pak->transferBuffer = (u8*) pak->unk_53BC + pak->gbAddress;
                            pak->transferSize = 0x4000;
                            if (func_812006AC(pak) != 0) {
                                goto retry;
                            }
                            sum = 0;
                            v0 = (s32) pak->transferBuffer;
                            for (i = 0; i < 0x2000; i++) {
                                sum = (sum + *(u8*) ((u8*) v0 + i)) & 0xFFFF;
                            }
                            if (sum != *(u16*) ((u8*) s0 + 2)) {
                                goto retry;
                            }
                            sum = 0;
                            for (i = 0; i < 0x2000; i += 4) {
                                sum = (sum + *(u8*) ((u8*) v0 + i) + *(u8*) ((u8*) v0 + i + 1) + *(u8*) ((u8*) v0 + i + 2) + *(u8*) ((u8*) v0 + i + 3)) & 0xFFFF;
                            }
                            if (sum != *(u16*) ((u8*) s0 + 4)) {
                                goto retry;
                            }
                            pak->unk_549C[v0 & 0xF] = 0xFF;
                            s0 += 6;
                        }
                    }
                    v0 = *(u16*) s0;
                    s6 = v0 & 0x8000;
                } while (v0 != 0);
                pak->unk05DC6[1] = 0;
                continue;
            case 5:
                pak->unk_5DC4 = 0;
                if (func_812005D8(pak) != 0) {
                    goto retry;
                }
                if (func_812004B8(pak) != 0) {
                    goto retry;
                }
                pak->unk05DC6[1] = 0;
                continue;
            case 6:
                if (func_8120019C(pak) != 0) {
                    goto retry;
                }
                pak->unk05DC6[1] = 0;
                continue;
            case 7:
                pak->unk05DCD[0] -= 0x17;
                pak->status &= 0xFE;
                if (osGbpakPower(&pak->pfs, 0) != 0) {
                    goto retry;
                }
                pak->unk05DC6[1] = 0;
                continue;
            case 8:
                if (pak->unk05DC6[1] != 7) {
                    pak->unk05DC6[1] = 0;
                    continue;
                }
                if (func_8120019C(pak) != 0) {
                    s4 -= 1;
                    if (s4 == 0) {
                        s4 = 5;
                        pak->unk_5DC9 = 9;
                    }
                } else {
                    s4 = 0x3C;
                }
                continue;
            case 9:
                if (osGbpakInit((OSMesgQueue*) fp[0], &pak->pfs, pak->unk_5DCC) != 0) {
                    s4 = 5;
                    continue;
                }
                s4 -= 1;
                if (func_8120019C(pak) != 0) {
                    s4 = 5;
                    continue;
                }
                if (s4 != 0) {
                    continue;
                }
                if (func_812005D8(pak) != 0) {
                    goto poweroff;
                }
                pak->unk_5DC9 = 10;
                continue;
            case 10:
                pak->transferBuffer = (u8*) s2;
                if (func_812008C8(pak, 1) != 0) {
                    goto poweroff;
                }
                pak->transferBuffer = (u8*) s3;
                if (func_812008C8(pak, 0) != 0) {
                    goto poweroff;
                }
                if (bcmp(s2, s3, 0x100) != 0) {
                    goto poweroff;
                }
                v0 = (s32) pak + (pak->gbAddress >> 8);
                if (*(u8*) ((u8*) v0 + 0x5A2C) != 0) {
                    *(u8*) ((u8*) v0 + 0x5A2C) = 2;
                }
                pak->unk_5DC9 = 2;
                pak->unk05DC6[1] = 0;
                continue;
            }
        }
        break;
poweroff:
        s4 = 0x3C;
        pak->status &= 0xFE;
        osGbpakPower(&pak->pfs, 0);
        s1 = 0xFF;
        s1 = pak->unk_5DC9 = 0xB;
        continue;
    }
}

void func_812011D0(s32 arg0, u8* arg1) {
    u8* s0;
    u8* s1;
    u8* s3;
    u16* a1;
    u16* v1;
    u8* v0;
    s32 s2;
    s32 t4;
    s32 t5;
    s32 t2;
    s32 t0;
    s32 t3;
    s32 a3;
    s32 t1;
    s32 tmp;
    s32 idx;

    if (arg1[0] == 0) {
        return;
    }
    s0 = arg1;
    do {
        v1 = (u16*) ((((s0[2] * 0x1040) + (s0[1] + ((s0[0] & 1) << 8))) << 1) + arg0);
        if ((s0[0] & 0x40) != 0) {
            s2 = -1;
        } else {
            s2 = 0;
        }
        if (s0[3] == 0xC) {
            s1 = D_8120E580;
            s3 = D_8122C744;
            t4 = 0xC;
        } else {
            s1 = (u8*) D_8120E480;
            s3 = D_8122C740;
            t4 = 0xA;
        }
        a1 = (u16*) D_8120E300;
        switch (s0[4]) {
            case 0: a1 = (u16*) D_8120E320; break;
            case 1: a1 = (u16*) D_8120E340; break;
            case 2: a1 = (u16*) D_8120E360; break;
            case 3: a1 = (u16*) D_8120E380; break;
            case 4: a1 = (u16*) D_8120E3A0; break;
            case 5: a1 = (u16*) D_8120E3C0; break;
            case 6: a1 = (u16*) D_8120E3E0; break;
            case 7: a1 = (u16*) D_8120E400; break;
            case 8: a1 = (u16*) D_8120E420; break;
            case 9: a1 = (u16*) D_8120E440; break;
            case 10: a1 = (u16*) D_8120E460; break;
        }
        t5 = s0[5];
        s2 = t4 * 0x140;
        a3 = s0[0] & 0x20;
        if (t5 != 0) {
            do {
                tmp = s0[6];
                t5 -= 1;
                t2 = 0;
                idx = *(u8*) (s1 + tmp + 0x80);
                s0 += 1;
                t0 = *(u8*) (s1 + idx);
                t3 = t0 << 1;
                v0 = s3 + ((idx * t4) << 4);
                if (t4 != 0) {
                    do {
                        if (t0 != 0) {
                            t1 = t0 & 3;
                            tmp = 0;
                            if (t1 != 0) {
                                do {
                                    if (a3 != 0) {
                                        *(u16*) v1 = a1[*v0 & 0xF];
                                        v1 = (u16*) ((u8*) v1 + 2);
                                    } else {
                                        if (a1[*v0 & 0xF] != 0) {
                                            *(u16*) v1 = a1[*v0 & 0xF];
                                        }
                                        v1 = (u16*) ((u8*) v1 + 2);
                                    }
                                    tmp += 1;
                                    v0 += 1;
                                } while (t1 != tmp);
                            }
                            if (tmp != t0) {
                                do {
                                    if (a3 != 0) {
                                        *(u16*) v1 = a1[v0[0] & 0xF];
                                        v1 = (u16*) ((u8*) v1 + 2);
                                        *(u16*) v1 = a1[v0[1] & 0xF];
                                        v1 = (u16*) ((u8*) v1 + 2);
                                        *(u16*) v1 = a1[v0[2] & 0xF];
                                        v1 = (u16*) ((u8*) v1 + 2);
                                        *(u16*) v1 = a1[v0[3] & 0xF];
                                        v1 = (u16*) ((u8*) v1 + 2);
                                    } else {
                                        if (a1[v0[0] & 0xF] != 0) {
                                            *(u16*) v1 = a1[v0[0] & 0xF];
                                        }
                                        v1 = (u16*) ((u8*) v1 + 2);
                                        if (a1[v0[1] & 0xF] != 0) {
                                            *(u16*) v1 = a1[v0[1] & 0xF];
                                        }
                                        v1 = (u16*) ((u8*) v1 + 2);
                                        if (a1[v0[2] & 0xF] != 0) {
                                            *(u16*) v1 = a1[v0[2] & 0xF];
                                        }
                                        v1 = (u16*) ((u8*) v1 + 2);
                                        if (a1[v0[3] & 0xF] != 0) {
                                            *(u16*) v1 = a1[v0[3] & 0xF];
                                        }
                                        v1 = (u16*) ((u8*) v1 + 2);
                                    }
                                    tmp += 4;
                                    v0 += 4;
                                } while (tmp != t0);
                            }
                        }
                        t2 += 1;
                        v1 = (u16*) ((u8*) v1 - t3 + 0x280);
                    } while (t2 != t4);
                }
                v1 = (u16*) ((u8*) v1 - (((t4 * 0x140) - t0 - s2) << 1));
                s2 = 0;
            } while (t5 != 0);
        }
        s2 = 0;
        tmp = s0[6];
        s0 += 6;
    } while (tmp != 0);
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

void func_812016DC(u8* arg0) {
    u8* spS1;
    u8* spS2;
    u8* spS3;
    u8* spS4;
    u8* spS5;
    u8* spS6;
    u8* spS7;
    u8* var_s0;
    s32 var_t0;
    u8* var_a2;
    u8* var_a3;
    s32 var_a1;
    u8* var_v0;
    s32 var_t1;

    var_s0 = (u8*) D_8122C748;
    spS1 = arg0 + 0x10;
    spS2 = arg0 + 0x1400;
    spS7 = arg0;
    spS5 = spS2 + 0x4C;
    spS3 = spS1 + 0x5F00;
    spS4 = (u8*) 0x1400;
    spS6 = (u8*) 0x6400;
    do {
        func_812015EC(spS1, var_s0 + 0x1180, 0xFFFF, 8, 8);
        func_812015EC(spS3, var_s0 + 0x1400, 0xFFFF, 8, 8);
        func_812015EC(spS2, var_s0 + 0x1280, 0xFFFF, 8, 8);
        func_812015EC(spS5, var_s0 + 0x1300, 0xFFFF, 8, 8);
        spS4 += 0x1400;
        spS1 += 0x10;
        spS3 += 0x10;
        spS2 += 0x1400;
        spS5 += 0x1400;
    } while (spS4 != spS6);
    func_812015EC(spS7, var_s0 + 0x1100, 0, 8, 8);
    func_812015EC(spS7 + 0x4C, var_s0 + 0x1200, 0, 8, 8);
    func_812015EC(spS7 + 0x5F00, var_s0 + 0x1380, 0, 8, 8);
    func_812015EC(spS7 + 0x5F4C, var_s0 + 0x1480, 0, 8, 8);
    var_t0 = 0;
    var_a3 = spS7;
    var_a2 = spS7;
    var_t1 = 0x2580;
    var_a1 = 0x1E;
    var_v0 = 0xC14;
    do {
        *(u16*) (var_a2 + 0x1410) = 0xC14;
        *(u16*) (var_a2 + 0x1412) = 0xC14;
        var_a1 = 2;
        var_v0 = var_a3 + 4;
        do {
            var_a1 += 4;
            *(u16*) (var_v0 + 0x1412) = 0xC14;
            *(u16*) (var_v0 + 0x1414) = 0xC14;
            *(u16*) (var_v0 + 0x1416) = 0xC14;
            var_v0 += 8;
            *(u16*) (var_v0 + 0x1408) = 0xC14;
        } while (var_a1 != 0x1E);
        var_t0 += 0x140;
        var_a3 += 0x280;
        var_a2 += 0x280;
    } while (var_t0 != var_t1);
}

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

void func_812029B0(void* arg0, void* arg1, s32 arg2, s32 arg3) {
    u8* s5;
    void* s7;
    void* fp;
    s32 s2;
    s32 s3;
    s32 s4;
    s32 s1;
    s32 s0;
    s32 s6;
    s32 t4;
    s32 t8;
    s32 i;
    s32 j;
    s32 k;
    s32 m;

    s5 = D_8122C748;
    s7 = arg0;
    fp = arg1;
    s2 = 0;
    s3 = 0xF000;
    s4 = 0x140;
    for (s2 = 0; s2 < 0x14000; s2 += 0x5000) {
        s1 = (s32) s7 + (s2 << 1);
        for (s0 = 0; s0 != 0x140; s0 += 0x40) {
            func_812015EC((u16*) s1, s5 + 0x1500, 0xFFFF, 0x40, (s2 == s3) ? 0x30 : 0x40);
            s1 += 0x80;
        }
    }
    if (D_8122C74C == 0) {
        t8 = (s32) D_8122B2F4;
        D_8122B2F4 = D_8122B2F4 + 0x2580;
        _bcopy((u8*) s7 + 0x20A80, (void*) t8, 0x2580);
        D_8122C750 = (s32) D_8122B2F4;
        D_8122B2F4 = D_8122B2F4 + 0x2580;
        bzero((void*) D_8122C750, 0x2580);
        s0 = 9;
        s1 = 0x12;
        if (s0 != 0) {
            s0 = (s32) &D_8120D8FE;
            s2 = (s32) &D_8120D8FD;
            s3 = (s32) D_8120E580;
            do {
                t4 = *(u8*) s0;
                t8 = *(u8*) (s3 + t4 - s1 + 0x5B);
                func_81201DDC((u16*) (D_8122C750 + (s4 << 1) + 0x280), (u8*) (D_8122C744 + ((t8 * 3) << 6)), 0xFFFE, 0xC, 0xC, 0x10);
                t4 = *(u8*) s0;
                t8 = *(u8*) s2;
                s6 = (u8*) (s3 + *(u8*) (s3 + t4 - s1 + 0x5B));
                s0 -= 1;
                s2 -= 1;
                s4 += *(u8*) s6;
                if (t8 < 0x40) {
                    break;
                }
                s1 += 2;
            } while (s2 != (s32) &D_8120D906);
        }
    }
    s3 = (s32) s7 + 0x1722C;
    s0 = 0;
    s2 = 0;
    s6 = 0xC80;
    do {
        func_812016DC((u8*) s3);
        if (fp != 0) {
            s4 = (s32) s7 + 0x179B2;
            s1 = (s32) fp + (s0 * s6);
            osInvalDCache((void*) s1, s6);
            func_812015EC((u16*) s4, s5 + 0x3600, 0, 0x28, 0x28);
        }
        s0 += 1;
        s2 += 0x5C;
        s3 += 0x5C;
    } while (s0 != 6);
    for (m = 0; m != 0x780; m += 0x140) {
        s4 = m;
        s2 = (s32) s7 + m;
        for (j = 0; j != 0x140; j++) {
            *(u16*) ((u8*) s7 + m + 0x4380 + (j << 1)) = 0x25A;
            *(u16*) ((u8*) s7 + m + 0x10002 + 0x2E7E + (j << 1)) = 0x25A;
        }
    }
    s3 = (s32) s7 + 0x11A80;
    s1 = 0;
    s2 = (s32) s7 + 0x5280;
    s0 = 0x280;
    for (s1 = 0; s1 < 0x280; s1 += 0x10) {
        func_812015EC((u16*) s2, s5 + 0x3500, 0xFFFF, 8, 8);
        func_812015EC((u16*) s3, s5 + 0x3580, 0xFFFF, 8, 8);
        s2 += 0x10;
        s3 += 0x10;
    }
    for (m = 0; m != 0x5A00; m += 0x140) {
        s5 = (u8*) s5;
        s2 = (s32) s7 + m;
        for (j = 0; j != 0x140; j += 4) {
            *(u16*) (s2 + 0x6678) = 0x2BA4;
            *(u16*) (s2 + 0x6682) = 0x2BA4;
            *(u16*) (s2 + 0x6684) = 0x2BA4;
            *(u16*) (s2 + 0x6686) = 0x2BA4;
            s2 += 8;
        }
    }
    s4 = arg2;
    if (s4 == 1) {
        D_8122C754 = (u8*) s7 + 2;
    } else if (s4 == 2) {
        D_8122C754 = (u8*) s7 + 4;
    } else if (s4 == 3) {
        D_8122C754 = (u8*) s7 + 6;
    } else {
        D_8122C754 = (u8*) s7;
    }
    func_812015EC((u16*) ((u8*) s7 + 0x9C70), s5 + 0x3600, 0, 0x21, 0x21);
    func_812015EC((u16*) (D_8122C754 + 0x61E0), s5 + 0x4CB0, 0, 0x3C, 0x4B);
    s4 = arg3;
    if (s4 == 0) {
        func_812015EC((u16*) (D_8122C754 + 0x6706), s5 + 0x6FD8, 0, 0x17, 0x19);
    } else if (s4 == 1) {
    } else if (s4 == 2) {
        func_812015EC((u16*) (D_8122C754 + 0x6706), s5 + 0x7730, 0, 0x17, 0x19);
    } else if (s4 == 3) {
        func_812015EC((u16*) (D_8122C754 + 0x6706), s5 + 0x7BE0, 0, 0x17, 0x19);
    }
    D_8122C771 = (u8) arg2;
    func_81202758(((s32) D_8122C754 + 0x87BA), 0);
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

void func_812033F4(UNUSED s32 arg0, s32 arg1, void* arg2, void* arg3, UNUSED s32 arg4, s32 arg5) {
    u8* s2;
    s32 s1;
    s32 s0;
    s32 s3;
    s32 t0;
    s32 v0;
    s32 v1;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;
    s32 tmp;
    s32 tmp2;
    u8* t3;
    unk_D_8122B2C0* pk;

    s1 = (s32) arg2;
    s3 = arg1;
    func_80006314(0, 2, 0x140, 0x120, 1);
    D_8122B1E0 = (unk_D_80068BB0*) v0;
    func_80006314(0, 2, 0x140, 0x120, 1);
    D_8122B1E4 = (unk_D_80068BB0*) v0;
    v0 = (s32) main_pool_alloc(0x1FEAE8, 0);
    D_8122B2F8 = (unk_D_8122B2F8*) v0;
    v1 = v0;
    if (v0 == 0) {
        D_8122C4DC = 1;
        D_8122B2FC = 4;
        return;
    }
    s2 = (u8*) &D_8122B2F4;
    osCreateMesgQueue(&D_8122B1EC, &D_8122B1E8, 1);
    osCreateMesgQueue(&D_8122B254, &D_8122B250, 1);
    D_8122B2F0 = 0;
    *(u32*) &D_8122B2F4 = (u32) v1;
    switch (osTvType) {
    case 0:
        osViSetMode(&D_800795C0);
        break;
    case 2:
        osViSetMode(&osViModeMpalLpn1);
        break;
    case 1:
        osViSetMode(&osViModeNtscLpn1);
        break;
    }
    osViSetSpecialFeatures(0x2A);
    osViSetSpecialFeatures(0x80);
    osViBlack(1);
    D_8122C4E0 = 0;
    D_8122C4D8 = (OSMesgQueue*) arg5;
    osCreateMesgQueue(&D_8122C4C0, &D_8122C4B0, 4);
    t3 = (u8*) &D_8122C4B0;
    osCreateThread(&D_8122B300, (void* (*)(void*)) func_81200AA8, arg2, 0, t3, (OSMesgQueue*) arg3);
    osStartThread(&D_8122B300);
    *(u32*) &D_8122B2B8 = 0;
    *(u32*) &D_8122B2EC = *(u32*) &D_8122B2F4;
    *(u8**) &D_8122B2F4 = (u8*) (*(u32*) &D_8122B2F4 + 0xC410);
    s1 = (s32) &D_8122B2C0;
    s0 = *(s32*) &D_8122B2F4;
    do {
        *(u32*) &D_8122B2F4 = (u32) (s0 + 0x1B058);
        *(s32*) ((u8*) s0 + 0x53B4) = (s32) ((u8*) s0 + 0x1B058);
        *(u32*) &D_8122B2F4 = (u32) ((u8*) s0 + 0x1B058 + 0x6000);
        *(s32*) ((u8*) s0 + 0x53A8) = (s32) ((u8*) s0 + 0x1B058 + 0x6000);
        *(u32*) &D_8122B2F4 = (u32) ((u8*) s0 + 0x1B058 + 0x6000 + 0x4D40);
        *(s32*) ((u8*) s0 + 0x53AC) = (s32) ((u8*) s0 + 0x1B058 + 0x6000 + 0x4D40);
        *(u32*) &D_8122B2F4 = (u32) ((u8*) s0 + 0x1B058 + 0x6000 + 0x4D40 + 0x4D40);
        *(s32*) ((u8*) s0 + 0x53B0) = (s32) ((u8*) s0 + 0x1B058 + 0x6000 + 0x4D40 + 0x4D40);
        *(s32*) ((u8*) s0 + 0x5388) = 0x400;
        if (((unk_D_8122B2C0*) s1) == (unk_D_8122B2C0*) &D_8122B2C0) {
            *(s32*) ((u8*) s0 + 0x53BC) = (s32) (s0 + 0x1B058 + 0x6000 + 0x4D40 + 0x4D40 + 0x4D40);
            *(u32*) &D_8122B2F4 = (u32) ((u8*) s0 + 0x1B058 + 0x6000 + 0x4D40 + 0x4D40 + 0x4D40 + 0x100000);
        } else {
            *(s32*) ((u8*) s0 + 0x53BC) = ((unk_D_8122B2C0*) &D_8122B2C0)->unk_53BC;
            *(u32*) &D_8122B2F4 = (u32) ((u8*) s0 + 0x1B058 + 0x6000 + 0x4D40 + 0x4D40);
        }
        *(s32*) &D_8122B2F4 = (u32) (s0 + 0x1B058);
        bzero((void*) s0, 0x1B058);
        func_8120311C((unk_D_8122B2C0*) s0);
        if (((unk_D_8122B2C0*) s1) == (unk_D_8122B2C0*) &D_8122B2C0) {
            if (s3 >= 0 && s3 < 4) {
                ((unk_D_8122B2C0*) s0)->unk_5DCA = 1;
                ((unk_D_8122B2C0*) s0)->unk_5DCC = s3;
                osSendMesg(&D_8122C4C0, (OSMesg) s0, 1);
            }
        }
    } while (s1 < (s32) &D_8122B2C4);
    a0 = (s32) ((u8*) (u32) *(u32*) &D_8122B2F4 + 0xC5C0);
    a2 = (s32) (fragment2_ROM_START + 1) & 0xFFFFFFFE;
    a1 = (s32) &D_102BA0;
    a3 = 0;
    func_80003B30(a0, a1, a2, a3);
    Yay0_Decompress((void*) ((u32) *(u32*) &D_8122B2F4 + 0xC5C0), (void*) *(u32*) &D_8122B2F4);
    a2 = (u32) *(u32*) &D_8122B2F4;
    a1 = (s32) &D_8122C748;
    *(u32*) &D_8122B2F4 = (u32) ((u8*) a2 + 0xC5C0);
    *(u32*) &D_8122C748 = a2;
    ((unk_D_8122B2C0*) &D_8122B2C0)->unk_5C58 = (void*) a2;
    D_8122C74C = 0;
    t0 = (s32) &D_8122B2D8;
    v1 = (s32) &D_8122C754;
    s1 = (s32) &D_8122C760;
    s3 = 0xE200;
    do {
        a2 = *(u32*) &D_8122B2F4;
        *(u32*) &D_8122B2F4 = (u32) ((u8*) a2 + s3);
        func_812029B0((void*) ((u32) ((unk_D_8122B2C0*) &D_8122B2C0)->unk_5C58 + s3), (void*) s3, s1, 0);
        *(u32*) ((u8*) v1 - 4) = (u32) a2;
        v1 += 4;
        t0 += 4;
        *(u32*) ((u8*) t0 - 4) = a2;
        *(u32*) ((u8*) t0 - 4) = a2;
    } while (v1 < (s32) &D_8122C760);
    func_812070A0();
    a0 = (s32) ((u8*) (u32) *(u32*) &D_8122B2F4 + 0x80000);
    a2 = (s32) (fragment1_misc_yay0_ROM_START + 1) & 0xFFFFFFFE;
    a1 = (s32) &D_F4130;
    a3 = 0;
    func_80003B30(a0, a1, a2, a3);
    Yay0_Decompress((void*) ((u32) *(u32*) &D_8122B2F4 + 0x80000), (void*) *(u32*) &D_8122B2F4);
    func_81208E28((void*) *(u32*) &D_8122B2F4);
    func_8120935C(0);
    func_8120735C(0);
    func_81208D7C();
    func_81208C08(0xFF26, 0, 0);
    func_81208C08(0xFF26, 0x8F, 0x10);
    func_81208C08(0xFF24, 0x77, 0x20);
    func_81208C08(0xFF25, 0xFF, 0x30);
    func_81208F94();
    *(u32*) &D_8122B2F4 = (u32) ((u8*) *(u32*) &D_8122B2F4 + 0x80000);
    v0 = *(u8*) &D_8122C4E2;
    D_8122C4E4 = v0;
    D_8122C4E3 = 0;
    if (v0 == 2) {
        D_8122C4E5 = 2;
    } else {
        D_8122C4E5 = 1;
    }
    tmp = (s32) &D_8122B2D8;
    tmp2 = (s32) &D_8122B2C8;
    s3 = 0xE200;
    do {
        a2 = *(u32*) &D_8122B2F4;
        *(u32*) &D_8122B2F4 = (u32) ((u8*) a2 + 0x2800);
        *(u32*) &D_8122B2F4 = (u32) ((u8*) a2 + 0x2800 + 0x2800);
        bzero((void*) ((u8*) a2 + 0xE200), 0x2800);
        *(u32*) tmp = a2;
        D_8122B2C8[0] = (unk_D_8122B2F8*) a2;
        tmp += 4;
        D_8122B2C8[1] = (unk_D_8122B2F8*) ((u8*) a2 + 0x2800);
        *(u32*) tmp2 = a2;
        D_8122B2C8[2] = (unk_D_8122B2F8*) ((u8*) a2 + 0x2800 + 0x2800);
        *(u32*) tmp2 = (u32) ((u8*) a2 + 0x2800);
        tmp2 += 4;
        *(u32*) tmp2 = (u32) ((u8*) a2 + 0x2800 + 0x2800);
        tmp2 += 4;
    } while (tmp < (s32) &D_8122B2E4);
    a3 = *(u8*) &D_8122C4E2;
    if (a3 != 0) {
        if (a3 == 1) {
            a2 = (s32) (D_FDE40 + 1) & 0xFFFFFFFE;
            a1 = (s32) &D_F5450;
            a0 = (s32) D_8122B2C8[0];
            func_80003B30(a0, a1, a2, 0);
            Yay0_Decompress((void*) D_8122B2C8[0], D_8122B2C8[2]);
        } else if (a3 == 2) {
            a2 = (s32) (D_FDE40 + 1) & 0xFFFFFFFE;
            a1 = (s32) &D_F5450;
            a0 = (s32) D_8122B2C8[0];
            func_80003B30(a0, a1, a2, 0);
            Yay0_Decompress((void*) D_8122B2C8[0], D_8122B2C8[1]);
        }
    } else {
        a2 = (s32) (D_F5450 + 1) & 0xFFFFFFFE;
        a1 = (s32) &D_F4920;
        a0 = (s32) D_8122B2C8[0];
        func_80003B30(a0, a1, a2, 0);
        Yay0_Decompress((void*) D_8122B2C8[0], D_8122B2C8[1]);
    }
    v0 = (s32) *(u32*) &D_8122B2F4 - (s32) D_8122B2F8;
    while (v0 != 0x1FEAE8 && (s32) *(u32*) &D_8122B2F4 - (s32) D_8122B2F8 == v0) {
        ;
    }
    osWritebackDCacheAll();
    pk = (unk_D_8122B2C0*) &D_8122B2C0;
    if (pk->unk_5DCA != 0) {
        if (pk->unk_5DC8 != 0) {
            while (pk->unk_5DC8 != 0) {
                ;
            }
        }
        tmp = (pk->unk_5DC5 != 0) ? 0x500 : 0;
        a3 = tmp;
        if (a3 < 0) {
            a3 = a3 + 0xFF;
        }
        a2 = a3 >> 8;
        if (a2 < 0x80) {
            a3 = (0x80 - a2) & 3;
            a0 = a2;
            v1 = a3 + a2;
            if (a3 != 0) {
                do {
                    a0 += 1;
                    pk->unk_582C[a0 - 1] = 0;
                } while (v1 != a0);
                if (a0 == 0x80) {
                    goto swapped;
                }
            }
            do {
                a0 += 4;
                pk->unk_582C[a0 - 4] = 0;
                pk->unk_582C[a0 - 3] = 0;
                pk->unk_582C[a0 - 2] = 0;
                pk->unk_582C[a0 - 1] = 0;
            } while (a0 != 0x80);
        }
    swapped:
        if (pk->unk_5DCA != 0) {
            func_81202210(1, 1);
            func_8120241C();
            tmp2 = pk->unk_5DC5;
            if (tmp2 == 2) {
                D_8122C4DC = 5;
                func_81203304();
                return;
            } else if (tmp2 == 0) {
                D_8122C4DC = 1;
                func_81203304();
                return;
            }
            a3 = (tmp2 != 0) ? (tmp2 - 1) : 0;
            D_8122C4E8 = 0xFF;
            func_812029B0((void*) ((u32*) D_8122B1E0)[2], (void*) arg5, s3, a3);
            a3 = (tmp2 != 0) ? (tmp2 - 1) : 0;
            func_812029B0((void*) ((u32*) D_8122B1E4)[2], (void*) arg5, s3, a3);
        } else {
            D_8122C4DC = 1;
            func_81203304();
            return;
        }
    }
    tmp = ((unk_D_8122B2C0*) &D_8122B2C0)->unk_5DCA;
    osGetCount();
    D_8122C760 = *(u32*) &v0;
    D_8122C76C = *(u32*) &v0;
    osViSwapBuffer((void*) ((u32*) ((unk_D_80068BB0**) &D_8122B1E0)[D_8122B2B8])[2]);
    D_8122B2B8 ^= 1;
}

void func_81203C58(unk_D_8122B2C0* arg0) {
    u16* s4;
    u8* s5;
    s32 s2;
    s32 s3;
    s32 s1;
    u32 s0;
    s32 i;
    s16 v0;
    s16 v1;
    u32 temp;

    v0 = arg0->unk_5D70[2];
    if (v0 != 0) {
        s4 = (u16*) v0;
        s5 = (u8*) (arg0->unk_5D70[3] + 0x7C0000);
        v1 = s4[0];
        v0 = v1;
        do {
            s1 = v0 >> 8;
            func_80003B30((u32) arg0->unk_53BC + 0xEC000, (u32) s5, s4[1] + (u32) s5, 0);
            temp = (v1 & 0xFF) << 14;
            Yay0_Decompress((u32) arg0->unk_53BC + 0xEC000, (u32) arg0->unk_53BC + temp);
            s5 += s4[1];
            s4 += 2;
            s2 = 0;
            if (s1 > 0) {
                do {
                    s3 = s2 + 1;
                    if (s3 >= arg0->unk05DC6[0]) {
                        func_80003B30((u32) arg0->unk_53BC + 0xF0000, (u32) s5, s4[0] + (u32) s5, 0);
                        s0 = (u32) arg0->unk_53BC;
                                        for (i = 0; i != 0x1000; i += 4) {
                            *(u8*) (s0 + 0xEC000 + i) ^= *(u8*) (s0 + 0xF0000 + i);
                        }
                        s5 += s4[0];
                    }
                    s2 = s3;
                    s4 += 1;
                } while (s3 != s1);
            }
            arg0->unk_549C[v1 & 0xFF] = 0xFF;
            v1 = s4[0];
            v0 = v1;
        } while (v1 != 0);
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

void func_81203F3C(unk_D_8122B2C0*);
void func_81203F3C(unk_D_8122B2C0* arg0) {
    s32 v1;
    s32 tmp;
    u16 v0;

    switch (arg0->unk_5DC9) {
    case 8:
        D_8122C4F7 = 0x12;
        break;
    case 9:
        D_8122C4F7 = 0x13;
        break;
    case 0xA:
        D_8122C4F7 = 0x14;
        break;
    case 0xB:
        D_8122C4F7 = 0x15;
        break;
    default:
        goto skip;
    }
    func_8120935C(1);
    func_81209368(1);
    switch (D_8122C4F2) {
    case 0x20:
        D_8122C4FA.unk_00 = 1;
        break;
    case 0x10:
        D_8122C4FA.unk_00 = 2;
        break;
    case 2:
        D_8122C4FA.unk_00 = 3;
        break;
    case 4:
        D_8122C4FA.unk_00 = 4;
        break;
    default:
        D_8122C4FA.unk_00 = 0;
    }
    switch (D_8122C4F2) {
    case 0x1000:
        D_8122C4FA.unk_01 = 0;
        break;
    case 0x10:
        D_8122C4FA.unk_01 = 2;
        break;
    case 2:
        D_8122C4FA.unk_01 = 3;
        break;
    case 4:
        D_8122C4FA.unk_01 = 4;
        break;
    default:
        D_8122C4FA.unk_01 = 1;
    }
    if (D_8122C4FA.unk_00 != D_8122C4FA.unk_01) {
        D_8122C4FA.unk_00 = 0;
        D_8122C4FA.unk_01 = 1;
    }
    return;
skip:
    v1 = D_8122C4F7;
    if (v1 == 0x12 || v1 == 0x13 || v1 == 0x14 || v1 == 0x15) {
        func_81209368(1);
        func_8120935C(0);
        D_8122C4F7 = 0;
        return;
    }
    if (v1 == 0) {
        if ((gPlayer1Controller->buttonPressed & 0x8) && arg0->unk_5DD0 == 0 && D_8122C4F0 == 0x40) {
            arg0->unk_53FD = 0x40;
            func_8120935C(1);
            func_81209368(1);
            D_8122C4F7 = 1;
            return;
        }
    }
    *(s32*) ((u8*) &D_8122B224[0] + (D_8122B2B8 * 104)) = 0;
    v1 -= 1;
    if (v1 >= 0x11) {
        return;
    }
    switch (v1) {
    case 0:
        arg0->unk_53FD -= 4;
        if (arg0->unk_53FD > 0) {
            arg0->unk_53FD = 0;
            return;
        }
        v0 = gPlayer1Controller->buttonPressed;
        if (v0 & 0xD000) {
            D_8122C4F7 = 0x11;
            return;
        }
        if (v0 & 0x800) {
            func_81209368(7);
            D_8122C4F7 = 3;
            return;
        }
        if (v0 & 0x400) {
            func_81209368(7);
            D_8122C4F7 = 2;
            return;
        }
        return;
    case 1:
        if (gPlayer1Controller->buttonDown != 0) {
            return;
        }
        func_81203E30();
        arg0->unk_53FD = 0x40;
        func_81209368(1);
        func_8120935C(0);
        D_8122C4F7 = 0;
        return;
    case 2:
        v0 = gPlayer1Controller->buttonPressed;
        if (v0 & 0x800) {
            func_81209368(7);
            D_8122C4F7 = 1;
            return;
        }
        if (v0 & 0x400) {
            func_81209368(7);
            D_8122C4F7 = 2;
            return;
        }
        if (v0 & 0x9000) {
            func_81209368(2);
            D_8122C4F7 = 4;
            return;
        }
        if (v0 & 0x4000) {
            D_8122C4F7 = 0x11;
            return;
        }
        return;
    case 3:
        v0 = gPlayer1Controller->buttonPressed;
        if (v0 & 0x800) {
            func_81209368(7);
            D_8122C4F7 = 2;
            return;
        }
        if (v0 & 0x400) {
            func_81209368(7);
            D_8122C4F7 = 3;
            return;
        }
        if (v0 & 0x9000) {
            func_81209368(6);
            D_8122C4F7 = 6;
            return;
        }
        if (v0 & 0x4000) {
            D_8122C4F7 = 0x11;
            return;
        }
        return;
    case 4:
        v0 = gPlayer1Controller->buttonPressed;
        if (v0 & 0x4000) {
            func_81209368(8);
            D_8122C4F7 = 2;
            return;
        }
        if (v0 & 0x300) {
            func_81209368(5);
            tmp = D_8122C4F7;
            D_8122C4F7 = (tmp == 4) ? 5 : 4;
            return;
        }
        if (v0 & 0x9000) {
            tmp = v1;
            if (tmp == 4) {
                D_8122C4F7 = 0xF;
                return;
            }
            D_8122C4F7 = 1;
            return;
        }
        return;
    case 5:
        v0 = gPlayer1Controller->buttonPressed;
        if (v0 >= 0x401) {
            if (v0 == 0x800) {
                func_81209368(7);
                D_8122C4F7 = 0xA;
                return;
            }
            if (v0 == 0x1000) {
                v0 = 0;
                goto d1;
            }
            if (v0 == 0x4000) {
                func_81209368(8);
                D_8122C4F7 = 3;
                return;
            }
            if (v0 == 0x8000) {
                func_81209368(6);
                D_8122C774 = D_8122C4FA.unk_00;
                D_8122C4F8 = 0;
                D_8122C4F7 = 7;
                return;
            }
            return;
        }
        if (v0 == 2) {
            v0 = 3;
            goto d1;
        }
        if (v0 == 4) {
            v0 = 4;
            goto d1;
        }
        if (v0 == 0x10) {
            v0 = 2;
            goto d1;
        }
        if (v0 == 0x20) {
            v0 = 1;
            goto d1;
        }
        if (v0 == 0x400) {
            func_81209368(7);
            D_8122C4F7 = 0xA;
            return;
        }
        return;
    d1:
        if (v0 != D_8122C4FA.unk_01) {
            func_81209368(6);
            D_8122C4FA.unk_01 = v0;
            if (D_8122C4F7 == 8) {
                D_8122C4F7 = 9;
            }
            return;
        }
        func_81209368(3);
        return;
    case 6:
        v0 = gPlayer1Controller->buttonPressed;
        if (v0 >= 0x401) {
            if (v0 == 0x800) {
                func_81209368(7);
                D_8122C4F7 = 6;
                return;
            }
            if (v0 == 0x1000) {
                v0 = 0;
                goto d2;
            }
            if (v0 == 0x4000) {
                func_81209368(8);
                D_8122C4F7 = 3;
                return;
            }
            if (v0 == 0x8000) {
                func_81209368(6);
                D_8122C774 = D_8122C4FA.unk_01;
                D_8122C4F8 = 0;
                D_8122C4F7 = 0xB;
                return;
            }
            return;
        }
        if (v0 == 2) {
            v0 = 3;
            goto d2;
        }
        if (v0 == 4) {
            v0 = 4;
            goto d2;
        }
        if (v0 == 0x10) {
            v0 = 2;
            goto d2;
        }
        if (v0 == 0x20) {
            v0 = 1;
            goto d2;
        }
        if (v0 == 0x400) {
            func_81209368(7);
            D_8122C4F7 = 6;
            return;
        }
        return;
    d2:
        if (v0 != D_8122C4FA.unk_00) {
            func_81209368(6);
            D_8122C4FA.unk_00 = v0;
            if (D_8122C4F7 == 0xC) {
                D_8122C4F7 = 0xD;
            }
            return;
        }
        func_81209368(3);
        return;
    case 7:
        v0 = D_8122C4F8;
        if (v0 < 0xA) {
            D_8122C4F8 = v0 + 1;
            return;
        }
        if (v1 == 7) {
            D_8122C4F7 = 8;
        } else {
            D_8122C4F7 = 0xC;
        }
        return;
    case 8:
        v0 = gPlayer1Controller->buttonPressed;
        if (v0 >= 0x101) {
            if (v0 == 0x200) {
                goto dec0;
            }
            if (v0 == 0x1000) {
                v0 = 0;
                goto d1;
            }
            if (v0 == 0x4000) {
                func_81209368(8);
                D_8122C4F7 = 9;
                D_8122C4FA.unk_00 = D_8122C774;
                return;
            }
            if (v0 == 0x8000) {
                if (D_8122C4FA.unk_01 != D_8122C4FA.unk_00) {
                    func_81209368(6);
                    D_8122C4F7 = 9;
                } else {
                    func_81209368(3);
                }
                return;
            }
            return;
        }
        if (v0 == 2) {
            v0 = 3;
            goto d1;
        }
        if (v0 == 4) {
            v0 = 4;
            goto d1;
        }
        if (v0 == 0x10) {
            v0 = 2;
            goto d1;
        }
        if (v0 == 0x20) {
            v0 = 1;
            goto d1;
        }
        if (v0 == 0x100) {
            goto inc0;
        }
        return;
    dec0:
        v0 = (D_8122C4FA.unk_00 - 1) & 0xFF;
        D_8122C4FA.unk_00 = v0;
        if (!(v0 < 5)) {
            D_8122C4FA.unk_00 = 0;
        }
        func_81209368(5);
        return;
    inc0:
        v0 = (D_8122C4FA.unk_00 + 1) & 0xFF;
        D_8122C4FA.unk_00 = v0;
        if (!(v0 < 5)) {
            D_8122C4FA.unk_00 = 4;
        }
        func_81209368(5);
        return;
    case 9:
        v0 = gPlayer1Controller->buttonPressed;
        if (v0 >= 0x101) {
            if (v0 == 0x200) {
                goto dec1;
            }
            if (v0 == 0x1000) {
                v0 = 0;
                goto d2;
            }
            if (v0 == 0x4000) {
                func_81209368(8);
                D_8122C4F7 = 0xD;
                D_8122C4FA.unk_01 = D_8122C774;
                return;
            }
            if (v0 == 0x8000) {
                if (D_8122C4FA.unk_01 != D_8122C4FA.unk_00) {
                    func_81209368(6);
                    D_8122C4F7 = 0xD;
                } else {
                    func_81209368(3);
                }
                return;
            }
            return;
        }
        if (v0 == 2) {
            v0 = 3;
            goto d2;
        }
        if (v0 == 4) {
            v0 = 4;
            goto d2;
        }
        if (v0 == 0x10) {
            v0 = 2;
            goto d2;
        }
        if (v0 == 0x20) {
            v0 = 1;
            goto d2;
        }
        if (v0 == 0x100) {
            goto inc1;
        }
        return;
    dec1:
        v0 = (D_8122C4FA.unk_01 - 1) & 0xFF;
        D_8122C4FA.unk_01 = v0;
        if (!(v0 < 5)) {
            D_8122C4FA.unk_01 = 0;
        }
        func_81209368(5);
        return;
    inc1:
        v0 = (D_8122C4FA.unk_01 + 1) & 0xFF;
        D_8122C4FA.unk_01 = v0;
        if (!(v0 < 5)) {
            D_8122C4FA.unk_01 = 4;
        }
        func_81209368(5);
        return;
    case 0xA:
        v0 = D_8122C4F8;
        if (v0 != 0) {
            D_8122C4F8 = v0 - 1;
            return;
        }
        if (v1 == 9) {
            D_8122C4F7 = 6;
        } else {
            D_8122C4F7 = 0xA;
        }
        return;
    case 0xB:
        if (gPlayer1Controller->buttonDown != 0) {
            return;
        }
        func_81203E30();
        D_8122C4F7 = 0xF;
        return;
    default:
        v0 = D_8122C4F0;
        v0 -= 4;
        D_8122C4F0 = v0;
        if (v0 > 0) {
            return;
        }
        D_8122C4F0 = 0;
        D_8122C4F7 = 0x10;
        func_81209368(1);
        func_8120935C(0);
        func_81208D7C();
        return;
    }
}

void func_81204A84(unk_D_8122B2C0* arg0) {
    s32 t0;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 v0;
    s32 v1;
    s32 tmp;
    s32 tmp2;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;
    u32* buf;

    v1 = D_8122C4F7;
    if (v1 == 0) {
        return;
    }
    if (v1 == 0x12 || v1 == 0x13) {
        func_812011D0((void*) ((u8*) arg0 - 0x1C), D_8120E8C0);
        a2 = D_8122C4E7;
    } else if (v1 == 0x14) {
        t3 = D_8122C4E7;
        D_8122B2E8 ^= 1;
        a2 = (t3 + 1) & 0xFF;
        D_8122C4E7 = t3 + 1;
        if (a2 >= 0xB) {
            D_8122C4E7 = 0;
            a2 = 0;
        }
    } else if (v1 == 0x15) {
        func_812011D0((void*) ((u8*) arg0 - 0x1C), D_8120E958);
        a2 = D_8122C4E7;
    } else {
        tmp = v1 - 1;
        if (tmp < 0x11) {
            switch (tmp) {
            case 4:
                func_812015EC((void*) ((u8*) arg0 + 0x1B890), D_8122C748 + 0xC2F8, 0, 0x10, 0xA);
                v1 = 0xB;
                v0 = 8;
                goto row2;
            case 5:
                v1 = 0xB;
                v0 = 8;
                goto row1;
            case 6:
                func_812015EC((void*) ((u8*) arg0 + 0x140A0 + 0x787C), D_8122C748 + 0xC2F8, 0, 0x10, 0xA);
                v1 = 8;
                v0 = 0xB;
                goto row2;
            case 7:
                func_812011D0((void*) ((u8*) arg0 + 0x787C), D_8120E6D0);
                goto jt3;
            case 8:
                func_812011D0((void*) ((u8*) arg0 + 0x787C), D_8120E718);
                goto jt3;
            case 9:
                func_812011D0((void*) ((u8*) arg0 + 0x787C), D_8120E760);
                goto jt3;
            case 0:
                func_812015EC((void*) ((u8*) arg0 + 0x787C + 0x3714), D_8122C748 + 0xC2F8, 0, 0x10, 0xA);
                v1 = 0xB;
                v0 = 8;
                goto row1;
            case 2:
                func_812015EC((void*) ((u8*) arg0 + 0x787C + 0x6914), D_8122C748 + 0xC2F8, 0, 0x10, 0xA);
                v1 = 8;
                v0 = 0xB;
                goto row1;
            case 3:
                func_812015EC((void*) ((u8*) arg0 + 0x787C + 0x9B14), D_8122C748 + 0xC2F8, 0, 0x10, 0xA);
                v1 = 8;
                v0 = 8;
                goto row1;
            default:
                goto jt3;
            }
        }
        goto jt3;
    }
    t3 = D_8122B2E8;
    buf = (u32*) ((u8*) &D_8122B1E8 + (D_8122B2B8 * 104));
    func_812020C0((u16*) (D_8122B2D8[t3] + 0x9C), 1, 0);
    buf[14] = 0;
    buf[15] = 0x1010;
    buf[23] = *(u32*) ((u8*) buf + 0x5C) & 0xFFFF;
    buf[14] = D_8122B2D8[D_8122B2E8];
    func_812011D0((void*) ((u8*) arg0 - 0x1C), D_8120E8D8);
    return;
row1:
    a2 = 8;
row2:
    func_812011D0((void*) ((u8*) arg0 + 0x787C), D_8120E688);
    D_8120E694[4] = v1;
    func_812011D0((void*) ((u8*) arg0 + 0x787C), D_8120E6A8);
    D_8120E6A8[4] = v0;
    func_812011D0((void*) ((u8*) arg0 + 0x787C), D_8120E6B8);
    D_8120E6B8[4] = a2;
    v0 = (s32) ((u8*) arg0 + 0x787C + 0x8010);
    t0 = 8;
    t2 = -1;
    do {
        t0 += 4;
        *(u16*) ((u8*) v0 + 0x4802) = t2;
        *(u16*) ((u8*) v0 + 0x4804) = t2;
        *(u16*) ((u8*) v0 + 0x4806) = t2;
        v0 += 8;
        *(u16*) ((u8*) v0 + 0x47F8) = t2;
    } while (t0 != 0x94);
jt3:
    v1 = D_8122C4F7;
    tmp = v1 - 6;
    if (tmp >= 8) {
        goto jt4;
    }
    switch (tmp) {
    case 0:
        t3 = gPlayer1Controller;
        v0 = D_8122C4E2;
        t3 = 0x4A;
        if (v0 != 1) {
            if (v0 == 2) {
                func_812015EC((void*) ((u8*) arg0 + 0x787C + 0xF08), D_8122C748 + 0xB758, 0, 0x10, 0xC);
                func_812011D0((void*) ((u8*) arg0 + 0x787C), D_8120E834);
            } else {
                t3 = 0x32;
            }
        } else {
            func_812015EC((void*) ((u8*) arg0 + 0x787C + 0xF08), D_8122C748 + 0xB758, 0, 0x10, 0xC);
            func_812011D0((void*) ((u8*) arg0 + 0x787C), D_8120E7E4);
        }
        v0 = (s32) arg0 + 0x787C + (t3 * 640);
        a0 = v0 + 0x280;
        v1 = v0 + 0x780;
        *(u16*) ((u8*) a0 + 0x282) = -1;
        *(u16*) ((u8*) a0 + 0x284) = -1;
        *(u16*) ((u8*) a0 + 0x3BA) = -1;
        *(u16*) ((u8*) a0 + 0x3BC) = -1;
        *(u16*) ((u8*) a0 + 0x2) = -1;
        *(u16*) ((u8*) a0 + 0x4) = -1;
        *(u16*) ((u8*) a0 + 0x13A) = -1;
        *(u16*) ((u8*) a0 + 0x13C) = -1;
        a0 = 0x3F;
        t1 = 3;
        do {
            t1 += 4;
            *(u16*) ((u8*) v1 + 0x3BC) = -1;
            *(u16*) ((u8*) v1 + 0x3BA) = -1;
            *(u16*) ((u8*) v1 + 0x284) = -1;
            *(u16*) ((u8*) v1 + 0x282) = -1;
            *(u16*) ((u8*) v1 + 0x63C) = -1;
            *(u16*) ((u8*) v1 + 0x63A) = -1;
            *(u16*) ((u8*) v1 + 0x504) = -1;
            *(u16*) ((u8*) v1 + 0x502) = -1;
            *(u16*) ((u8*) v1 + 0x8BC) = -1;
            *(u16*) ((u8*) v1 + 0x8BA) = -1;
            *(u16*) ((u8*) v1 + 0x784) = -1;
            *(u16*) ((u8*) v1 + 0x782) = -1;
            v1 += 0xA00;
            *(u16*) ((u8*) v1 - 0x8C4) = -1;
            *(u16*) ((u8*) v1 - 0x8C6) = -1;
            *(u16*) ((u8*) v1 - 0x9FC) = -1;
            *(u16*) ((u8*) v1 - 0x9FE) = -1;
        } while (t1 != a0);
        v0 = (s32) arg0 + 0x787C + (t3 * 640) + 4;
        v1 = v0 + 0x8000;
        t0 = 2;
        a0 = 0x9E;
        do {
            if (t0 < 0x10 || t0 >= 0x43) {
                *(u16*) ((u8*) v0 + 0x280) = -1;
                *(u16*) ((u8*) v0 + 0) = -1;
            }
            t0 += 1;
            v0 += 2;
            v1 += 2;
            *(u16*) ((u8*) v1 + 0x1D7E) = -1;
            *(u16*) ((u8*) v1 + 0x1AFE) = -1;
        } while (t0 != a0);
        D_8120E898[2] = t3 - 5;
        func_812011D0((void*) ((u8*) arg0 + 0x787C), D_8120E898);
        func_812015EC((void*) ((u8*) arg0 + 0x787C + (t3 * 640) + 0x7838), D_8122C748 + 0xB2D8, 0, 0x10, 0xC);
        D_8120E8A8[2] = t3 + 0x30;
        func_812011D0((void*) ((u8*) arg0 + 0x787C), D_8120E8A8);
        goto jt4;
    default:
        goto jt4;
    }
jt4:
    t2 = 0x28 - (D_8122C4F8 * 4);
    v1 = D_8122C4F7;
    tmp = v1 - 6;
    if (tmp < 8) {
        switch (tmp) {
        case 0:
            v1 = t3;
            t0 = 0;
            goto s310;
        case 1:
            v1 = t3;
            t0 = 0;
            goto s258;
        case 2:
            v1 = t3;
            t0 = 0;
            goto s208;
        case 3:
            v1 = t3;
            t0 = 0x14;
            goto s208;
        default:
            goto jt5;
        }
    }
    goto jt5;
s208:
    func_812015EC((void*) ((u8*) arg0 + 0x787C + ((t3 + t0) * 640) + 0x1E28), D_8122C748 + 0xC2F8, 0, 0x10, 0xA);
    v1 = t3 * 640;
    t2 = 0x28;
    t0 = 1;
s258:
    tmp2 = D_8122C4FA.unk_00;
    if (tmp2 < 5) {
        switch (tmp2) {
        case 0:
            t1 = 0xBBD8;
            break;
        case 1:
            t1 = 0xB8D8;
            break;
        case 2:
            t1 = 0xBA58;
            break;
        case 3:
            t1 = 0xB5D8;
            break;
        default:
            t1 = 0xB458;
            break;
        }
    }
    v0 = (t0 != 0) ? t2 : 0x28;
    func_812015EC((void*) ((u8*) arg0 + 0x787C + ((v0 + v1) << 1) + 0x1978), D_8122C748 + t1, 0, 0x10, 0xC);
    if (t0 != 0) {
        v1 = D_8122C4F7;
        goto jt5;
    }
s310:
    tmp2 = D_8122C4FB;
    if (tmp2 < 5) {
        switch (tmp2) {
        case 0:
            t1 = 0xBBD8;
            break;
        case 1:
            t1 = 0xB8D8;
            break;
        case 2:
            t1 = 0xBA58;
            break;
        case 3:
            t1 = 0xB5D8;
            break;
        default:
            t1 = 0xB458;
            break;
        }
    }
    v0 = (t0 != 0) ? t2 : 0x28;
    func_812015EC((void*) ((u8*) arg0 + 0x787C + ((v0 + v1) << 1) + 0x4B78), D_8122C748 + t1, 0, 0x10, 0xC);
jt5:
    v1 = D_8122C4F7;
    tmp = v1 - 6;
    if (tmp < 8) {
        switch (tmp) {
        case 0:
            v1 = t3;
            t0 = t2 + 8;
            t1 = 0x30;
            goto s41c;
        case 1:
            v1 = t3;
            t0 = 0x30;
            t1 = t2 + 8;
            goto s41c;
        default:
            goto endcheck;
        }
    }
    goto endcheck;
s41c:
    func_812015EC((void*) ((u8*) arg0 + 0x787C + ((v1 + t0) << 1) + 0x1900), D_8122C748 + 0xBF98, 0, 0x18, 0xC);
    func_812015EC((void*) ((u8*) arg0 + 0x787C + ((v1 + t0) << 1) + 0x1930), D_8122C748 + 0xC438, 0, 0x10, 0xC);
    func_812015EC((void*) ((u8*) arg0 + 0x787C + ((v1 + t1) << 1) + 0x4AFC), D_8122C748 + 0xBD58, 0, 0x18, 0xC);
    func_812015EC((void*) ((u8*) arg0 + 0x787C + ((v1 + t1) << 1) + 0x4B30), D_8122C748 + 0xC438, 0, 0x10, 0xC);
    v1 = D_8122C4F7;
endcheck:
    if (v1 == 8) {
        t0 = 0;
        t1 = D_8122C4FA.unk_00;
    } else if (v1 != 0xC) {
        return;
    } else {
        t0 = 0x14;
        t1 = D_8122C4FB;
    }
    v0 = t3 + t0;
    a0 = (s32) arg0 + 0x787C + (v0 * 640);
    func_812015EC((void*) ((u8*) a0 + 0x1974), D_8122C748 + 0xBBD8, 0, 0x10, 0xC);
    func_812015EC((void*) ((u8*) a0 + 0x1998), D_8122C748 + 0xB8D8, 0, 0x10, 0xC);
    func_812015EC((void*) ((u8*) a0 + 0x19BC), D_8122C748 + 0xBA58, 0, 0x10, 0xC);
    func_812015EC((void*) ((u8*) a0 + 0x19E0), D_8122C748 + 0xB5D8, 0, 0x10, 0xC);
    func_812015EC((void*) ((u8*) a0 + 0x1A04), D_8122C748 + 0xB458, 0, 0x10, 0xC);
    a3 = t3 + 7;
    t2 = t1 * 18 + 0x37;
    v1 = (s32) arg0 + 0x787C + (a3 * 0x280) + (t2 * 2) + 0x280;
    t1 = 1;
    do {
        t1 += 2;
        *(u16*) ((u8*) v1 + 0x2A2) = 0xE71C;
        *(u16*) ((u8*) v1 + 0x2A0) = 0xE71C;
        *(u16*) ((u8*) v1 + 0x282) = 0xE71C;
        *(u16*) ((u8*) v1 + 0x280) = 0xE71C;
        v1 += 0x500;
        *(u16*) ((u8*) v1 - 0x4DE) = 0xE71C;
        *(u16*) ((u8*) v1 - 0x4E0) = 0xE71C;
        *(u16*) ((u8*) v1 - 0x4FE) = 0xE71C;
        *(u16*) ((u8*) v1 - 0x500) = 0xE71C;
    } while (t1 != 0x11);
    a2 = (s32) arg0 + 0x787C + (a3 * 0x280) + (t2 * 2);
    a1 = a2 + 2;
    *(u16*) ((u8*) a1 + 0x2A80) = 0xE71C;
    *(u16*) ((u8*) a1 + 0x2800) = 0xE71C;
    *(u16*) ((u8*) a1 + 0x280) = 0xE71C;
    *(u16*) ((u8*) a1 + 0) = 0xE71C;
    v1 = a2 + 4;
    t0 = 2;
    do {
        t0 += 2;
        *(u16*) ((u8*) v1 + 0x2A82) = 0xE71C;
        *(u16*) ((u8*) v1 + 0x2802) = 0xE71C;
        *(u16*) ((u8*) v1 + 0x282) = 0xE71C;
        *(u16*) ((u8*) v1 + 0x2) = 0xE71C;
        v1 += 4;
        *(u16*) ((u8*) v1 + 0x2A7C) = 0xE71C;
        *(u16*) ((u8*) v1 + 0x27FC) = 0xE71C;
        *(u16*) ((u8*) v1 + 0x27C) = 0xE71C;
        *(u16*) ((u8*) v1 - 4) = 0xE71C;
    } while (t0 != 0x10);
    return;
}