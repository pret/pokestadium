#include "global.h"

typedef struct unk_func_81208D7C {
  /* 0x00 */ u8 unk_00;
  /* 0x02 */ char unk02[0x02];
  /* 0x04 */ s32 unk_04;
  /* 0x08 */ union {
      u16 unk_00;
      s32 unk_02;
  } unk_08;
  /* 0x0C */ u32 unk_0C;
  /* 0x10 */ u16 unk_10;
  /* 0x12 */ u16 unk_12;
  /* 0x14 */ s32 unk_14;
  /* 0x18 */ s32 unk_18;
  /* 0x1C */ char unk1C[0x4];
  /* 0x20 */ u8 unk_20;
  /* 0x21 */ u8 unk_21;
  /* 0x22 */ char unk22[0x2];
  /* 0x24 */ u32 unk_24;
  /* 0x28 */ u32 unk_28;
  /* 0x2C */ char unk2C[0x1];
  /* 0x2D */ u8 unk_2D;
  /* 0x2E */ u8 unk_2E;
  /* 0x2F */ char unk2F[0xD];
  /* 0x3C */ u8 unk_3C;
  /* 0x3D */ char unk3D[0x3];
  /* 0x40 */ u32 unk_40;
  /* 0x44 */ u16 unk_44;
  /* 0x46 */ u16 unk46;
  /* 0x48 */ u32 unk_48;
  /* 0x4C */ u8 unk_4C;
  /* 0x4D */ char unk4D[0x3];
} unk_func_81208D7C; // size = 0x50

typedef struct unk_D_8122EEA8 {
  /* 0x00 */ u8 unk_00;
  /* 0x01 */ u8 unk_01;
  /* 0x02 */ u8 unk_02;
  /* 0x03 */ u8 unk_03;
} unk_D_8122EEA8; // size = 0x4

extern u8 D_811FEB60[];
extern u8 D_8120EB24[];
extern u8 D_8120EB28[];
extern u8 D_8120EB38[];
extern u16 D_8120EA86;
extern f32 D_8120EAC0;
extern s32 D_8120EAC8;
extern s32 D_8120EACC;
extern s32 D_8120EAC4;
extern s32 D_8120EA60;
extern u32 D_8120EA80;
extern s32 D_8120EB78;
extern s32 D_8120EB7C;
extern f32 D_8122B0A0;
extern f32 D_8122B0A4;
extern s32 D_8122C794;

extern unk_func_81208D7C D_8122C798;
extern unk_func_81208D7C D_8122C7E8;
extern unk_func_81208D7C D_8122C838;
extern unk_func_81208D7C D_8122C888;
extern unk_D_8122EEA8 D_8122EEA8;

extern OSMesgQueue D_8122EEB0;
extern OSMesg D_8122EEC8;

void func_81207330(void) {
}

void func_81207338(void) {
    D_8120EA60 = 1;
}

void func_81207348(void) {
    D_8120EA60 = 0;
}

void func_81207354(void) {
}

void func_8120735C(s32 arg0) {
    if (arg0 == 0) {
        D_8120EAC4 = 0x4578;
        D_8120EAC0 = D_8122B0A0;
        return;
    }
    D_8120EAC4 = 0x8AF0;
    D_8120EAC0 = D_8122B0A4;
}

void func_812073A4(s32 arg0, s32 arg1) {
    D_8120EAC8 = arg0;
    D_8120EACC = arg1;
}

u32 func_812073B8(u16 arg0) {
  u32 temp;
  if (arg0 == 0) {
      return 0;
  }
  temp = ((65536.0f / (0x800 - arg0)) / D_8120EAC0) * 65536;
  return temp;
}

#ifdef NON_MATCHING
extern u16 D_8120EAD4[];
extern u32 D_8120EB48[];
extern s32 D_8122EE98;
extern f32 D_8122B0A8;
extern f32 D_8122B0AC;
// Map a (row, col, tile) triple to a GB tile-data byte offset (D_8122EE98) and a
// palette index (D_8120EAC8), returning the scaled screen coordinate for the tile.
u32 func_81207494(s32 arg0, s32 arg1, s32 arg2) {
    s32 col = arg0 & 0xFFFF;
    s32 row = arg1 & 0xFFFF;

    D_8122EE98 = ((row * 0x10) + col) << 0xE;
    D_8120EAC8 = D_8120EAD4[(col * 2) + row];
    return (u32) (((f32) (s32) (f32) D_8120EB48[arg2 & 0xFFFF] / D_8122B0A8) * D_8122B0AC);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_86CB0/func_81207494.s")
#endif

s32 func_812075C0(s32);
#ifdef NON_MATCHING
s32 func_812075C0(s32 arg0) {
    s32 temp;
    temp = ((131072.0f / (0x800 - (arg0 & 0xFFFF))) / D_8120EAC0) * 65536;
    return temp;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_86CB0/func_812075C0.s")
#endif

void func_81207690(void) {
}

s32 func_81207698(u32, u16);
#ifdef NON_MATCHING
extern u8 D_8122EE58[];
extern s32 D_8122EE98;
s32 func_81207698(u32 arg0, u16 arg1) {
    switch (arg0) {
    case 0:
        if ((arg1 >= 4) && (arg1 < 8)) {
            return 0x7F;
        }
        return 0;
    case 1:
        if (arg1 < 8) {
            return 0x7F;
        }
        return 0;
    case 2:
        if (arg1 < 0x10) {
            return 0x7F;
        }
        return 0;
    case 3:
        if (arg1 < 8) {
            return 0;
        }
        return 0x7F;
    case 6:
        return ((u8*) D_8122C794)[D_8122EE98 + arg1] & 0x7F;
    case 7:
        return (D_8122EE58[arg1] << 3) & 0xFF;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_86CB0/func_81207698.s")
#endif

#ifdef NON_MATCHING
extern u8 D_8120EB14[];
// Advance the GB square-wave channel (D_8122C798): run its length/envelope like
// the other channels, plus a frequency sweep that shifts unk_10 up or down and
// silences the channel when it under/overflows.
u16 func_81207774(void) {
    s32 sample;
    u16 out;
    u8 tmp;
    s32 doSweep;
    s32 runEnvelope;

    if (D_8122C798.unk_00 == 0) {
        if (D_8122C798.unk_3C == 0) {
            return 0;
        }
        D_8122C798.unk_3C--;
        D_8122C798.unk_20 = D_8122C798.unk_3C;
        D_8122C798.unk_0C = D_8122C798.unk_40;
    }

    if ((s32) D_8122C798.unk_10 <= 0) {
        D_8122C798.unk_4C = 1;
    } else if (((s32) D_8122C798.unk_10 >= 0x7FF) && ((u8) D_8122C798.unk2F[0xA] == 0)) {
        D_8122C798.unk_4C = 1;
    } else {
        D_8122C798.unk_4C = 0;
    }

    sample = func_81207698((u32) (u8) D_8122C798.unk2F[0xC], D_8122C798.unk_08.unk_00);
    D_8122C798.unk_08.unk_02 = (D_8122C798.unk_08.unk_02 + D_8122C798.unk_0C) & 0x1FFFFF;

    if (D_8122C798.unk_4C == 1) {
        u8 vol = D_8122C798.unk_3C;
        if (D_8122C798.unk_3C != 0) {
            D_8122C798.unk_3C--;
            vol = D_8122C798.unk_3C;
        }
        out = ((sample & 0xFFFF) * vol) & 0xFFFF;
    } else {
        D_8122C798.unk_40 = D_8122C798.unk_0C;
        D_8122C798.unk_3C = D_8122C798.unk_20;
        out = ((sample & 0xFFFF) * D_8122C798.unk_20) & 0xFFFF;
    }

    doSweep = 0;
    if ((u8) D_8122C798.unk2F[0xB] != 0) {
        u32 c = *(u32*) &D_8122C798.unk2F[1] + 1;
        *(u32*) &D_8122C798.unk2F[1] = c;
        if ((c % *(u32*) &D_8122C798.unk2F[5]) == 0) {
            doSweep = 1;
        }
    }

    runEnvelope = 1;
    if (doSweep) {
        u16 freq = D_8122C798.unk_10;
        s32 delta = ((s32) freq >> (u8) D_8122C798.unk2F[9]) & 0xFFFF;
        u8 mode = (u8) D_8122C798.unk2F[0xA];
        s32 nf;

        switch (mode) {
            case 0:
                nf = freq + delta;
                D_8122C798.unk_10 = nf;
                freq = nf;
                break;
            case 1:
                nf = (freq - delta) - 1;
                D_8122C798.unk_10 = nf;
                freq = nf;
                break;
        }

        if ((s32) freq <= 0) {
            D_8122C798.unk_00 = 0;
            runEnvelope = 0;
        } else {
            if (((s32) freq >= 0x800) && (mode == 0)) {
                D_8122C798.unk_10 = 0x7FF;
                D_8122C798.unk_00 = 0;
                freq = 0x7FF;
            }
            D_8122C798.unk_0C = func_812075C0(freq & 0xFFFF);
        }
    }

    if (runEnvelope) {
        if (D_8122C798.unk_28 != 0) {
            D_8122C798.unk_24++;
            if ((D_8122C798.unk_24 % D_8122C798.unk_28) == 0) {
                if (D_8122C798.unk_2E != 0) {
                    if (D_8122C798.unk_2E != 1) {
                        tmp = D_8122C798.unk_2D;
                    } else {
                        tmp = D_8122C798.unk_2D;
                        if ((s32) tmp < 0xF) {
                            D_8122C798.unk_2D = tmp + 1;
                            tmp = D_8122C798.unk_2D;
                        }
                    }
                } else {
                    tmp = D_8122C798.unk_2D;
                    if (tmp != 0) {
                        D_8122C798.unk_2D = tmp - 1;
                        tmp = D_8122C798.unk_2D;
                    }
                    if (tmp == 0) {
                        D_8122C798.unk_00 = 0;
                    }
                }
                D_8122C798.unk_20 = D_8120EB14[tmp];
            }
        } else {
            D_8122C798.unk_20 = D_8120EB14[D_8122C798.unk_2D];
        }
        if (D_8122C798.unk_18 == 1) {
            s32 len = D_8122C798.unk_14;
            if (len != 0) {
                D_8122C798.unk_14 = len - 1;
                len = D_8122C798.unk_14;
            }
            if (len == 0) {
                D_8122C798.unk_00 = 0;
            }
        }
    }
    return out;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_86CB0/func_81207774.s")
#endif

#ifdef NON_MATCHING
extern u8 D_8120EB14[];
// Advance one GB sound channel by a sample: run its length/envelope/sweep state
// and return the current amplitude.
s32 func_81207A60(void) {
    s32 sample;
    s32 vol;
    u8 tmp;

    if (D_8122C7E8.unk_00 == 0) {
        if (D_8122C7E8.unk_3C == 0) {
            return 0;
        }
        D_8122C7E8.unk_3C--;
        D_8122C7E8.unk_20 = D_8122C7E8.unk_3C;
        D_8122C7E8.unk_0C = D_8122C7E8.unk_40;
    }

    if ((s32) D_8122C7E8.unk_10 >= 0x7FF) {
        D_8122C7E8.unk_4C = 1;
    } else {
        D_8122C7E8.unk_4C = 0;
    }

    sample = func_81207698((u32) (u8) D_8122C7E8.unk2F[0xC], D_8122C7E8.unk_08.unk_00);
    D_8122C7E8.unk_08.unk_02 = (D_8122C7E8.unk_08.unk_02 + D_8122C7E8.unk_0C) & 0x1FFFFF;

    if (D_8122C7E8.unk_4C == 1) {
        vol = D_8122C7E8.unk_3C;
        if (D_8122C7E8.unk_3C != 0) {
            D_8122C7E8.unk_3C--;
            vol = D_8122C7E8.unk_3C;
        }
        sample = ((sample & 0xFFFF) * vol) & 0xFFFF;
    } else {
        if (D_8122C7E8.unk_3C != D_8122C7E8.unk_20) {
            D_8122C7E8.unk_3C = D_8122C7E8.unk_20;
        }
        D_8122C7E8.unk_40 = D_8122C7E8.unk_0C;
        sample = ((sample & 0xFFFF) * D_8122C7E8.unk_20) & 0xFFFF;
    }

    if (D_8122C7E8.unk_28 != 0) {
        D_8122C7E8.unk_24++;
        if ((D_8122C7E8.unk_24 % D_8122C7E8.unk_28) == 0) {
            if (D_8122C7E8.unk_2E != 0) {
                if (D_8122C7E8.unk_2E != 1) {
                    tmp = D_8122C7E8.unk_2D;
                } else {
                    tmp = D_8122C7E8.unk_2D;
                    if ((s32) tmp < 0xF) {
                        D_8122C7E8.unk_2D = tmp + 1;
                        tmp = D_8122C7E8.unk_2D;
                    }
                }
            } else {
                tmp = D_8122C7E8.unk_2D;
                if (tmp != 0) {
                    D_8122C7E8.unk_2D = tmp - 1;
                    tmp = D_8122C7E8.unk_2D;
                }
                if (tmp == 0) {
                    D_8122C7E8.unk_00 = 0;
                }
            }
            D_8122C7E8.unk_20 = D_8120EB14[tmp];
        }
    } else {
        D_8122C7E8.unk_20 = D_8120EB14[D_8122C7E8.unk_2D];
    }

    if (D_8122C7E8.unk_18 == 1) {
        s32 len = D_8122C7E8.unk_14;
        if (len != 0) {
            D_8122C7E8.unk_14 = len - 1;
            len = D_8122C7E8.unk_14;
        }
        if (len == 0) {
            D_8122C7E8.unk_00 = 0;
        }
    }
    return sample;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_86CB0/func_81207A60.s")
#endif

u16 func_81207C5C(void) {
    u16 temp_v0;
    u16 temp_a0;
    u16 temp_a1;
    u16 var_a0;

    if (D_8122C838.unk_00 == 0) {
        if (D_8122C838.unk_3C == 0) {
            return 0U;
        }
        D_8122C838.unk_3C--;
        D_8122C838.unk_20 = D_8122C838.unk_3C;
        D_8122C838.unk_0C = (s32) D_8122C838.unk_40;
    } else {    
        if (D_8122C838.unk_04 != 0) {
            D_8122C838.unk_04--;
            if (D_8122C838.unk_04 >= 0x21) {
                if (D_8122C838.unk_3C == 0) {
                    D_8122C838.unk_04 = 0x20;
                    D_8122C838.unk_08.unk_02 = 0;
                    D_8122C838.unk_0C = func_812073B8(D_8122C838.unk_10);
                    D_8122C838.unk_20 = D_8120EB24[D_8122C838.unk_21];
                } else {
                    if (!(D_8122C838.unk_04 & 7)) {
                        D_8122C838.unk_3C--;
                    }
                    D_8122C838.unk_20 = D_8122C838.unk_3C;
                    D_8122C838.unk_0C = (s32) D_8122C838.unk_40;
                }
            }
        }
    }
    temp_a0 = func_81207698(7, D_8122C838.unk_08.unk_00);
    D_8122C838.unk_08.unk_02 += D_8122C838.unk_0C;
    D_8122C838.unk_08.unk_02 &= 0x1FFFFF;
    if (D_8122C838.unk_4C - 1 == 0) {

        if (D_8122C838.unk_3C != 0) {
            D_8122C838.unk_3C--;
        }
        temp_a1 = D_8122C838.unk_3C;
    } else {
        D_8122C838.unk_3C = D_8122C838.unk_20;
        D_8122C838.unk_40 = D_8122C838.unk_0C;
        temp_a1 = D_8122C838.unk_20;
    }

    temp_a0 *= temp_a1;
    temp_a0 = (D_8122C838.unk_44 + temp_a0) >> 1;
    D_8122C838.unk_44 = temp_a0;
    if (D_8122C838.unk_18 == 1) {
        if (D_8122C838.unk_14 != 0) {
            D_8122C838.unk_14--;
        }
        if (D_8122C838.unk_14 == 0) {
            D_8122C838.unk_00 = 0U;
        }
    }
    return temp_a0;
}

u16 func_81207C5C_Empty(void) {
    
}

#ifdef NON_MATCHING
// Matching but won't generate correct checksum
u16 func_81207DF8(void) {
    static s32 D_8120EB6C;
    u16 temp_v0;
    u32 var_a2;

    if (D_8122C888.unk_0C < D_8122C888.unk_40) {
        D_8122C888.unk_40 -= D_8122C888.unk_48;
        var_a2 = D_8122C888.unk_40;
    } else if (D_8122C888.unk_40 < D_8122C888.unk_0C) {
        D_8122C888.unk_40 += D_8122C888.unk_48;
        var_a2 = D_8122C888.unk_40;
    } else {
        var_a2 = D_8122C888.unk_40;
    }

    if (D_8122C888.unk_00 == 0) {
        if (D_8122C888.unk_3C == 0) {
            return 0;
        }
        D_8122C888.unk_3C--;
        D_8122C888.unk_20 = D_8122C888.unk_3C;
        D_8122C888.unk_0C = D_8122C888.unk_40;
    }
    temp_v0 = func_81207698(6, D_8122C888.unk_08.unk_00);
    D_8122C888.unk_08.unk_02 += var_a2;
    if (D_8122C888.unk_08.unk_00  >= (u32)D_8120EACC) {
        D_8122C888.unk_08.unk_00  = D_8120EAC8;
    }
    temp_v0 *= D_8122C888.unk_3C;
    if ((D_8122C888.unk_3C != D_8122C888.unk_20) && ((D_8120EB6C % 95) == 0)) {
        if (D_8122C888.unk_3C > D_8122C888.unk_20) {
            D_8122C888.unk_3C--;
        } else {
            D_8122C888.unk_3C++;
        }
    }
    D_8120EB6C++;
    if (D_8122C888.unk_28 != 0) {
        D_8122C888.unk_24++;
        if ((D_8122C888.unk_24 % (u32) D_8122C888.unk_28) == 0) {
            switch (D_8122C888.unk_2E) {             /* irregular */
            case 0:
                if (D_8122C888.unk_2D) {
                    D_8122C888.unk_2D--;
                }
                if (D_8122C888.unk_2D == 0) {
                    D_8122C888.unk_00 = 0;
                }
                break;
            case 1:
                if (D_8122C888.unk_2D < 0xF) {
                    D_8122C888.unk_2D++;
                }
                break;
            }
            switch ((D_8120EA80 << 0x14) >> 0x1F) {                    /* switch 1; irregular */
            case 0:                                 /* switch 1 */
                D_8122C888.unk_20 = D_8120EB28[D_8122C888.unk_2D];
                break;
            case 1:                                 /* switch 1 */
                D_8122C888.unk_20 = D_8120EB38[D_8122C888.unk_2D];
                break;
            }
        }
    }
    if (D_8122C888.unk_18 == 1) {
        if (D_8122C888.unk_14 != 0) {
            D_8122C888.unk_14--;
        }
        if (D_8122C888.unk_14 == 0) {
            D_8122C888.unk_00 = 0U;
        }
    }
    
    return (temp_v0 << 1);
}
#else
u16 func_81207DF8(void);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_86CB0/func_81207DF8.s")
#endif

void func_8120806C(u16, u8);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_86CB0/func_8120806C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_86CB0/func_81208828.s")

#ifdef NON_MATCHING
extern s32 D_8120EAD0;
void func_81208C08(u16 arg0, u8 arg1, u16 arg2) {
    s32 code;

    code = arg0 + 0xFFFF0100;
    osSendMesg(&D_8122EEB0, (void*) ((code << 0x18) | (arg1 << 0x10) | arg2), 0);
    D_8120EAD0 = arg2;
    switch (code) {
    case 20:
        if (arg1 & 0x80) {
            D_8122EEA8.unk_00 = 2;
        }
        break;
    case 25:
        if (arg1 & 0x80) {
            D_8122EEA8.unk_01 = 2;
        }
        break;
    case 30:
        if (arg1 & 0x80) {
            D_8122EEA8.unk_02 = 2;
        }
        break;
    case 35:
        if (arg1 & 0x80) {
            D_8122EEA8.unk_03 = 2;
        }
        break;
    case 38:
        if (!(arg1 & 1)) {
            D_8122EEA8.unk_00 = 1;
        }
        if (!(arg1 & 2)) {
            D_8122EEA8.unk_01 = 1;
        }
        if (!(arg1 & 4)) {
            D_8122EEA8.unk_02 = 1;
        }
        if (!(arg1 & 8)) {
            D_8122EEA8.unk_03 = 1;
        }
        if (!(arg1 & 0x80)) {
            D_8122EEA8.unk_00 = 1;
            D_8122EEA8.unk_01 = 1;
            D_8122EEA8.unk_02 = 1;
            D_8122EEA8.unk_03 = 1;
        }
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_86CB0/func_81208C08.s")
#endif

void func_81208D7C(void) {
  s32 pad[6];
  s32 i;
  OSMesgQueue sp24;
  OSMesg sp20;

  osCreateMesgQueue(&sp24, &sp20, 1);
  osCreateMesgQueue(&D_8122EEB0, &D_8122EEC8, 0x960);
  for (i = 0x50; i > 0xF; i--) {
      func_8120806C(i, 0);
  }
  D_8122C798.unk_3C = 0;
  D_8122C7E8.unk_3C = 0;
  D_8122C838.unk_3C = 0;
  D_8122C888.unk_3C = 0;
  D_8122C798.unk_08.unk_02 = 0;
  D_8122C7E8.unk_08.unk_02 = 0;
  D_8122C838.unk_08.unk_02 = 0;
  D_8122C888.unk_08.unk_02 = 0;
}

void func_81208E28(s32 arg0) {
  D_8122C794 = arg0;
  func_81208D7C();
}

#ifdef NON_MATCHING
extern s16 D_8122C790;
extern s16 D_8122C792;
extern void* D_812346E0;
// Fill the GB line buffer (640 x/y s16 pairs) with a ramp from (D_8122C790,
// D_8122C792) down to the origin, then flush it and hand it to the GB DAC.
void func_81208E4C(void) {
    s16* buf = D_812346E0;
    f32 x = (f32) D_8122C790;
    f32 y = (f32) D_8122C792;
    f32 dx = x / 640.0f;
    f32 dy = y / 640.0f;
    s32 i;

    func_81208D7C();
    for (i = 0; i != 0x280; i += 4) {
        buf[0] = (s16) (s32) x;
        buf[1] = (s16) (s32) y;
        x -= dx;
        y -= dy;
        buf[2] = (s16) (s32) x;
        buf[3] = (s16) (s32) y;
        x -= dx;
        y -= dy;
        buf[4] = (s16) (s32) x;
        buf[5] = (s16) (s32) y;
        x -= dx;
        y -= dy;
        buf[6] = (s16) (s32) x;
        buf[7] = (s16) (s32) y;
        x -= dx;
        y -= dy;
        buf += 8;
    }
    while (osAiGetStatus() & 0x80000000) {}
    osWritebackDCache(D_812346E0, 0xA00);
    osGbSetNextBuffer(D_812346E0, 0xA00);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_86CB0/func_81208E4C.s")
#endif

void func_81208F94(void) {
}

u8 func_81208F9C(u16 arg0) {
  u8 var_a0;
  u8 var_a1;
  u8 var_a2;
  u8 var_v1;
  u8 temp;
  if ((arg0 & 0xFFFF) == 0xFF26) {
      if (D_8122EEA8.unk_00 != 0) {
          var_v1 = (D_8122EEA8.unk_00 - 1) & 0xFF;
      } else {
          var_v1 = D_8122C798.unk_00;
      }
      if (D_8122EEA8.unk_01 != 0) {
          var_a0 = (D_8122EEA8.unk_01 - 1) & 0xFF;
      } else {
          var_a0 = D_8122C7E8.unk_00;
      }
      if (D_8122EEA8.unk_02 != 0) {
          var_a1 = (D_8122EEA8.unk_02 - 1) & 0xFF;
      } else {
          var_a1 = D_8122C838.unk_00;
      }
      if (D_8122EEA8.unk_03 != 0) {
          var_a2 = (D_8122EEA8.unk_03 - 1) & 0xFF;
      } else {
          var_a2 = D_8122C888.unk_00;
      }
      temp = ((((u32)D_8120EA86 >> 0xF) << 7) | (var_a2 * 8) | (var_a1 * 4) | (var_a0 * 2) | var_v1);
      return temp;
  }
  return D_811FEB60[arg0 & 0xFFFF];
}

#ifdef NON_MATCHING
extern s16 D_812346EC[];
extern u8 D_81234690[];
extern s32 D_812346C8;
extern s32 D_812346D0;
extern s32 D_812346D4;
extern s32 D_812346F4;
extern u32 D_812346FC;
void func_81208828(s16, void*, s16, s16*);
void func_81209374(s16, void*, s16, s16*);
// Advance the GB audio triple buffer: hand the just-filled buffer to the DAC
// (after a warm-up delay), then size and (re)fill the next buffer.
s32 func_81209078(void) {
    void** bufs = (void**) &D_812346E0;
    s32 fill = (D_812346D4 + 1) % 3;
    s32 play = (fill + 2) % 3;
    s32 aiLen;
    void* buf;
    s16 len;

    D_812346C8++;
    D_812346D0 ^= 1;
    D_812346D4 = fill;

    aiLen = osAiGetLength() >> 2;

    if (D_812346FC < 0x10) {
        s16 playLen = D_812346EC[play];
        if (playLen != 0) {
            if (osGbSetNextBuffer(bufs[play], playLen * 4, playLen, &D_812346EC[play]) != -1) {
                s16* end = (s16*) ((u8*) bufs[play] + D_812346EC[play] * 4);
                D_8122C790 = end[-2];
                D_8122C792 = end[-1];
            }
        }
    }

    if (D_812346FC >= 0x11) {
        return 0;
    }
    if (D_812346FC != 0) {
        D_812346FC++;
    }

    buf = bufs[fill];
    D_812346EC[fill] = (((*(s16*) &D_81234690[6] - aiLen) + 0x80) & 0xFFF0) + 0x10;
    if (D_812346EC[fill] < *(s16*) &D_81234690[0xA]) {
        D_812346EC[fill] = *(s16*) &D_81234690[0xA];
    }
    if (*(s16*) &D_81234690[8] < D_812346EC[fill]) {
        D_812346EC[fill] = *(s16*) &D_81234690[8];
    }
    len = D_812346EC[fill];

    if (D_8120EB78 == 0) {
        func_81208828(len, buf, len, &D_812346EC[fill]);
    } else {
        func_81209374(len, buf, len, &D_812346EC[fill]);
    }
    osWritebackDCache(buf, len * 4);

    D_812346F4 = osGetCount() * (D_812346F4 + D_812346C8);
    D_812346F4 += ((s16*) buf)[D_812346C8 & 0xFF];
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_86CB0/func_81209078.s")
#endif

void func_8120935C(s32 arg0) {
  D_8120EB78 = arg0;
}

void func_81209368(s32 arg0) {
  D_8120EB7C = arg0;
}

#ifdef NON_MATCHING
extern s32 D_8120EB84;
extern s32 D_8120EB8C;
extern s32 D_8122869C;
extern s8* D_81228654[];
extern s32 D_81228678[];
typedef struct GbMixStream {
    /* 0x0 */ s32 index;
    /* 0x4 */ s32 cursor;
} GbMixStream;
// Mix the two active GB PCM streams into arg0 stereo s16 pairs (left = A+B,
// right = A-B). Stream B is scaled by the crossfade gain D_8122869C; a pending
// stream (D_8120EB7C) is swapped into slot A, pushing A down to B, on entry.
void func_81209374(s16 arg0, void* arg1, s16 arg2, s16* arg3) {
    GbMixStream* pend = (GbMixStream*) &D_8120EB7C;
    GbMixStream* chA = (GbMixStream*) &D_8120EB84;
    GbMixStream* chB = (GbMixStream*) &D_8120EB8C;
    s16* out = arg1;
    s8* baseA = NULL;
    s8* baseB = NULL;
    s32 lenA = 0;
    s32 lenB = 0;
    s32 gain;
    s32 i;

    if (pend->index != 0) {
        s32 pendIdx = pend->index;
        s32 oldIndex = chA->index;
        s32 oldCursor = chA->cursor;

        chA->cursor = 0;
        pend->index = 0;
        chB->index = oldIndex;
        chB->cursor = oldCursor;
        chA->index = pendIdx;
        D_8122869C = 0x400;
    }
    gain = D_8122869C;

    if (chA->index != 0) {
        baseA = D_81228654[chA->index];
        lenA = D_81228678[chA->index];
    }
    if (chB->index != 0) {
        baseB = D_81228654[chB->index];
        lenB = D_81228678[chB->index];
    }

    for (i = 0; i < arg0; i++) {
        s32 sampleA = 0;
        s32 sampleB = 0;

        if (baseA != NULL) {
            if (lenA == chA->cursor) {
                chA->index = 0;
                baseA = NULL;
            } else {
                sampleA = baseA[chA->cursor];
                chA->cursor++;
            }
        }
        if (baseB != NULL) {
            if (lenB == chB->cursor) {
                chB->index = 0;
                baseB = NULL;
            } else {
                sampleB = (baseB[chB->cursor] * gain) / 1024;
                chB->cursor++;
            }
        }

        out[0] = (sampleA + sampleB) << 6;
        out[1] = (sampleA - sampleB) << 6;
        out += 2;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_86CB0/func_81209374.s")
#endif

void func_81209688(UNUSED s32 arg0) {
}

// Decrypting this function causes issues
#ifdef NON_MATCHING
void func_81209690(s32 arg0) {
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_86CB0/func_81209690.s")
#endif
