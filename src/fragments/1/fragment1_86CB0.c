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
  /* 0x1C */ s32 unk_1C;
  /* 0x20 */ u8 unk_20;
  /* 0x21 */ u8 unk_21;
  /* 0x22 */ char unk22[0x2];
  /* 0x24 */ u32 unk_24;
  /* 0x28 */ u32 unk_28;
  /* 0x2C */ char unk2C[0x1];
  /* 0x2D */ u8 unk_2D;
  /* 0x2E */ u8 unk_2E;
  /* 0x2F */ char unk2F[0x1];
  /* 0x30 */ u32 unk_30;
  /* 0x34 */ u32 unk_34;
  /* 0x38 */ u8 unk_38;
  /* 0x39 */ u8 unk_39;
  /* 0x3A */ u8 unk_3A;
  /* 0x3B */ u8 unk_3B;
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
extern s32 D_8120EAD0;
extern u16 D_8120EAD4[32];
extern u8 D_8120EB14[];
extern u32 D_8120EB48[8];
extern s32 D_8120EB78;
typedef struct GbAudioStream {
    /* 0x0 */ s32 id;
    /* 0x4 */ s32 pos;
} GbAudioStream; // size = 0x8

extern GbAudioStream D_8120EB7C;
extern GbAudioStream D_8120EB84;
extern GbAudioStream D_8120EB8C;
extern s32 D_81228678[];
extern s8* D_81228654[];
extern u32 D_8122869C;

// .bss
extern s16 D_8122C790;
extern s16 D_8122C792;
extern u8* D_8122C794;
extern unk_func_81208D7C D_8122C798;
extern unk_func_81208D7C D_8122C7E8;
extern unk_func_81208D7C D_8122C838;
extern unk_func_81208D7C D_8122C888;
extern u8 D_8122EE58[40];
extern u8 D_8120EA70[];

// Game Boy sound registers NR10 (0xFF10) through NR52 (0xFF26), mirrored in
// D_8120EA70 (indexed by register address - 0xFF10).
typedef struct GbApuRegs {
    /* 0x00 NR10 */ u32 : 1;
                    u32 sweepTime : 3;
                    u32 sweepDir : 1;
                    u32 sweepShift : 3;
    /* 0x01 NR11 */ u32 duty1 : 2;
                    u32 length1 : 6;
    /* 0x02 NR12 */ u32 volume1 : 4;
                    u32 envDir1 : 1;
                    u32 envSweep1 : 3;
    /* 0x03 NR13 */ u32 freqLo1 : 8;
    /* 0x04 NR14 */ u32 trigger1 : 1;
                    u32 counter1 : 1;
                    u32 : 3;
                    u32 freqHi1 : 3;
    /* 0x05 */      u32 : 8;
    /* 0x06 NR21 */ u32 duty2 : 2;
                    u32 length2 : 6;
    /* 0x07 NR22 */ u32 volume2 : 4;
                    u32 envDir2 : 1;
                    u32 envSweep2 : 3;
    /* 0x08 NR23 */ u32 freqLo2 : 8;
    /* 0x09 NR24 */ u32 trigger2 : 1;
                    u32 counter2 : 1;
                    u32 : 3;
                    u32 freqHi2 : 3;
    /* 0x0A NR30 */ u32 waveOn : 1;
                    u32 : 7;
    /* 0x0B NR31 */ u32 length3 : 8;
    /* 0x0C NR32 */ u32 : 1;
                    u32 level3 : 2;
                    u32 : 5;
    /* 0x0D NR33 */ u32 freqLo3 : 8;
    /* 0x0E NR34 */ u32 trigger3 : 1;
                    u32 counter3 : 1;
                    u32 : 3;
                    u32 freqHi3 : 3;
    /* 0x0F */      u32 : 8;
    /* 0x10 NR41 */ u32 : 2;
                    u32 length4 : 6;
    /* 0x11 NR42 */ u32 volume4 : 4;
                    u32 envDir4 : 1;
                    u32 envSweep4 : 3;
    /* 0x12 NR43 */ u16 shift4 : 4;
                    u32 width4 : 1;
                    u32 ratio4 : 3;
    /* 0x13 NR44 */ u32 trigger4 : 1;
                    u32 counter4 : 1;
                    u32 : 6;
    /* 0x14 NR50 */ u32 vinLeft : 1;
                    u32 leftVolume : 3;
                    u32 vinRight : 1;
                    u32 rightVolume : 3;
    /* 0x15 NR51 */ u32 noiseLeft : 1;
                    u32 waveLeft : 1;
                    u32 sq2Left : 1;
                    u32 sq1Left : 1;
                    u32 noiseRight : 1;
                    u32 waveRight : 1;
                    u32 sq2Right : 1;
                    u32 sq1Right : 1;
    /* 0x16 NR52 */ u32 power : 1;
                    u32 : 7;
    /* 0x17 */      u32 : 8;
} GbApuRegs; // size = 0x18

#define GB_APU_REGS (*(GbApuRegs*)D_8120EA70)

// A queued APU register write, packed into an OSMesg as (reg << 24) | (value << 16) | time.
typedef struct GbApuWrite {
    /* 0x0 */ u8 reg;
    /* 0x1 */ u8 value;
    /* 0x2 */ u16 time;
} GbApuWrite; // size = 0x4

extern GbApuWrite D_8122C8D8[];
void func_81209374(s32 arg0, s16* arg1);
extern s32 D_8122EE98;
extern unk_D_8122EEA8 D_8122EEA8;
extern OSMesgQueue D_8122EEB0;
extern OSMesg D_8122EEC8;
extern s16* D_812346E0[3];
extern volatile s32 D_812346C8;
extern s32 D_812346D0;
extern s32 D_812346D4;
extern u32 D_812346F4;
extern volatile u32 D_812346FC;
extern s16 D_81234690[];
extern s16 D_812346EC[];

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
        D_8120EAC0 = 1500.0f;
        return;
    }
    D_8120EAC4 = 0x8AF0;
    D_8120EAC0 = 1500.0f;
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

u32 func_81207494(u16 arg0, u16 arg1, u16 arg2) {
    u32 temp;
    s32 temp2;

    D_8122EE98 = (arg1 * 16 + arg0) << 14;
    temp = D_8120EB48[arg2];
    temp2 = (f32)temp;
    temp = (temp2 / 48000.0f) * 24000.0f;
    D_8120EAC8 = D_8120EAD4[arg0 * 2 + arg1];
    return temp;
}

u32 func_812075C0(u16 arg0) {
  u32 temp;
  temp = ((131072.0f / (0x800 - arg0)) / D_8120EAC0) * 65536;
  return temp;
}

void func_81207690(void) {
}

s32 func_81207698(u32 arg0, s32 arg1) {
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
    case 4:
    case 5:
    break;
    case 6:
        return (u8)(D_8122C794[arg1 + D_8122EE98] & 0x7F);
    case 7:
        return (u8)(D_8122EE58[arg1] << 3);
    }
}

u16 func_81207774(void) {
    u16 var_t0;

    if (D_8122C798.unk_00 == 0) {
        if (D_8122C798.unk_3C == 0) {
            return 0U;
        }
        D_8122C798.unk_3C--;
        D_8122C798.unk_20 = D_8122C798.unk_3C;
        D_8122C798.unk_0C = (s32) D_8122C798.unk_40;
    }
    if ((s32) D_8122C798.unk_10 <= 0) {
        D_8122C798.unk_4C = 1U;
    } else if (((s32) D_8122C798.unk_10 >= 0x7FF) && (D_8122C798.unk_39 == 0)) {
        D_8122C798.unk_4C = 1U;
    } else {
        D_8122C798.unk_4C = 0U;
    }
    {
        s32 temp_v0 = func_81207698(D_8122C798.unk_3B, D_8122C798.unk_08.unk_00);
        D_8122C798.unk_08.unk_02 += D_8122C798.unk_0C;
        D_8122C798.unk_08.unk_02 &= 0x1FFFFF;
        if (D_8122C798.unk_4C == 1) {
            if (D_8122C798.unk_3C != 0) {
                D_8122C798.unk_3C--;
            }
            var_t0 = ((temp_v0 & 0xFFFF) * D_8122C798.unk_3C);
        } else {
            D_8122C798.unk_40 = (s32) D_8122C798.unk_0C;
            D_8122C798.unk_3C = (u8) D_8122C798.unk_20;
            var_t0 = ((temp_v0 & 0xFFFF) * D_8122C798.unk_20);
        }
    }
    if ((D_8122C798.unk_3A != 0) && (((++D_8122C798.unk_30 % (u32) D_8122C798.unk_34) == 0))) {
        s32 temp_a2 = ((s32) D_8122C798.unk_10 >> D_8122C798.unk_38) & 0xFFFF;
        switch (D_8122C798.unk_39) {
        case 0:
            D_8122C798.unk_10 += temp_a2;
            break;
        case 1:
            D_8122C798.unk_10 = (D_8122C798.unk_10 - temp_a2) - 1;;
            break;
        }
        if (D_8122C798.unk_10 <= 0) {
            D_8122C798.unk_00 = 0U;
            return var_t0;
        } else {
            if ((D_8122C798.unk_10 >= 0x800) && (D_8122C798.unk_39 == 0)) {
                D_8122C798.unk_10 = 0x7FFU;
                D_8122C798.unk_00 = 0U;
            }
            D_8122C798.unk_0C = func_812075C0(D_8122C798.unk_10);
        }
    }
    if (D_8122C798.unk_28 != 0) {
        D_8122C798.unk_24++;
        if ((D_8122C798.unk_24 % (u32) D_8122C798.unk_28) == 0) {
            switch (D_8122C798.unk_2E) {
            case 0:
                if (D_8122C798.unk_2D != 0) {
                    D_8122C798.unk_2D--;
                }
                if (!D_8122C798.unk_2D) {
                    D_8122C798.unk_00 = 0;
                }
                break;
            
            case 1:
                if (D_8122C798.unk_2D < 0xF) {
                    D_8122C798.unk_2D++;
                }
                break;
            
            default:
                break;
            }
        D_8122C798.unk_20 = D_8120EB14[D_8122C798.unk_2D];
        }
    } else {
        D_8122C798.unk_20 = D_8120EB14[D_8122C798.unk_2D];
    }
    if (D_8122C798.unk_18 == 1U) {
        if (D_8122C798.unk_14 != 0) {
            D_8122C798.unk_14--;
        }
        if (D_8122C798.unk_14 == 0) {
            D_8122C798.unk_00 = 0U;
        }
    }
    return var_t0;
}

s32 func_81207A60(void) {
    s32 temp_v0;
    s32 var_a3;
    u8 var_v0;

    if (D_8122C7E8.unk_00 == 0) {
        if (D_8122C7E8.unk_3C == 0) {
            return 0;
        }
        D_8122C7E8.unk_3C--;
        D_8122C7E8.unk_20 = D_8122C7E8.unk_3C;
        D_8122C7E8.unk_0C = (s32) D_8122C7E8.unk_40;
    }
    if ((s32) D_8122C7E8.unk_10 >= 0x7FF) {
        D_8122C7E8.unk_4C = 1U;
    } else {
        D_8122C7E8.unk_4C = 0U;
    }
    temp_v0 = func_81207698(D_8122C7E8.unk_3B, D_8122C7E8.unk_08.unk_00);
    D_8122C7E8.unk_08.unk_02 += D_8122C7E8.unk_0C;
    D_8122C7E8.unk_08.unk_02 &= 0x1FFFFF;
    if (D_8122C7E8.unk_4C == 1) {
        if (D_8122C7E8.unk_3C != 0) {
            D_8122C7E8.unk_3C--;
        }
        var_a3 = ((temp_v0 & 0xFFFF) * D_8122C7E8.unk_3C) & 0xFFFF;
    } else {
        if (D_8122C7E8.unk_20 != D_8122C7E8.unk_3C) {
            D_8122C7E8.unk_3C = (u8) D_8122C7E8.unk_20;
        }
        D_8122C7E8.unk_40 = (s32) D_8122C7E8.unk_0C;
        var_a3 = ((temp_v0 & 0xFFFF) * D_8122C7E8.unk_20) & 0xFFFF;
    }
    if (D_8122C7E8.unk_28 != 0) {
        D_8122C7E8.unk_24++;
        if ((D_8122C7E8.unk_24 % (u32) D_8122C7E8.unk_28) == 0) {
            switch (D_8122C7E8.unk_2E) {
                case 0:
                    if (D_8122C7E8.unk_2D != 0) {
                        D_8122C7E8.unk_2D--;
                    }
                    if (!D_8122C7E8.unk_2D) {
                        D_8122C7E8.unk_00 = 0;
                    }
                    break;
                
                case 1:
                    if (D_8122C7E8.unk_2D < 0xF) {
                        D_8122C7E8.unk_2D++;
                    }
                    break;
                
                default:
                    break;
                }
            D_8122C7E8.unk_20 = D_8120EB14[D_8122C7E8.unk_2D];
        }
    } else {
        D_8122C7E8.unk_20 = D_8120EB14[D_8122C7E8.unk_2D];
    }
    if (D_8122C7E8.unk_18 == 1U) {
        if (D_8122C7E8.unk_14 != 0) {
            D_8122C7E8.unk_14--;
        }
        if (D_8122C7E8.unk_14 == 0) {
            D_8122C7E8.unk_00 = 0U;
        }
    }
    return var_a3;
}

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
void func_8120806C(u16 reg, u8 value) {
    s32 pad;
    s32 i;
    s32 pad2;

    if ((reg == 0x26) && !(value & 0x80)) {
        for (i = 0x23; i != 0xF; i--) {
            func_8120806C(i, 0);
                }
            }

    if ((reg < 0x24) && !GB_APU_REGS.power) {
            return;
        }

    D_8120EA70[reg - 0x10] = value;

    switch (reg) {
        case 0x10:
            D_8122C798.unk_34 = GB_APU_REGS.sweepTime * 400;
            D_8122C798.unk_39 = GB_APU_REGS.sweepDir;
            D_8122C798.unk_38 = GB_APU_REGS.sweepShift;
        if (D_8122C798.unk_3A == 0) {
            D_8122C798.unk_30 = 0;
        }
            if (D_8122C798.unk_34 == 0) {
            D_8122C798.unk_3A = 0;
            } else {
                D_8122C798.unk_3A = 1;
        }
        break;
        case 0x11:
            D_8122C798.unk_3B = GB_APU_REGS.duty1;
            D_8122C798.unk_1C = 0x40 - GB_APU_REGS.length1;
        break;
        case 0x12:
            D_8122C798.unk_21 = GB_APU_REGS.volume1;
            if ((GB_APU_REGS.volume1 == 0) && (GB_APU_REGS.envDir1 == 0)) {
        D_8122C798.unk_00 = 0;
            }
        break;
        case 0x13:
            D_8122C798.unk_10 = GB_APU_REGS.freqLo1 | (GB_APU_REGS.freqHi1 << 8);
            D_8122C798.unk_0C = func_812075C0(D_8122C798.unk_10);
        break;
        case 0x14:
            D_8122C798.unk_18 = GB_APU_REGS.counter1;
            D_8122C798.unk_10 = GB_APU_REGS.freqLo1 | (GB_APU_REGS.freqHi1 << 8);
            D_8122C798.unk_0C = func_812075C0(D_8122C798.unk_10);
            if ((s32)GB_APU_REGS.trigger1 == 1) {
                D_8122C798.unk_14 = D_8122C798.unk_1C * 200;
                D_8122C798.unk_20 = D_8120EB14[D_8122C798.unk_21];
            D_8122C798.unk_24 = 0;
            D_8122C798.unk_30 = 0;
                D_8122C798.unk_2E = GB_APU_REGS.envDir1;
                D_8122C798.unk_28 = GB_APU_REGS.envSweep1 * 800;
                D_8122C798.unk_2D = D_8122C798.unk_21;
                if (GB_APU_REGS.power) {
                D_8122C798.unk_00 = 1;
            }
        }
            if (D_8122C798.unk_34 == 0) {
                D_8122C798.unk_3A = 0;
            } else {
                D_8122C798.unk_3A = 1;
            }
        break;
        case 0x16:
            D_8122C7E8.unk_3B = GB_APU_REGS.duty2;
            D_8122C7E8.unk_1C = 0x40 - GB_APU_REGS.length2;
        break;
        case 0x17:
            D_8122C7E8.unk_21 = GB_APU_REGS.volume2;
            if ((GB_APU_REGS.volume2 == 0) && (GB_APU_REGS.envDir2 == 0)) {
        D_8122C7E8.unk_00 = 0;
            }
        break;
        case 0x18:
            D_8122C7E8.unk_10 = GB_APU_REGS.freqLo2 | (GB_APU_REGS.freqHi2 << 8);
            D_8122C7E8.unk_0C = func_812075C0(D_8122C7E8.unk_10);
        break;
        case 0x19:
            D_8122C7E8.unk_18 = GB_APU_REGS.counter2;
            D_8122C7E8.unk_10 = GB_APU_REGS.freqLo2 | (GB_APU_REGS.freqHi2 << 8);
            D_8122C7E8.unk_0C = func_812075C0(D_8122C7E8.unk_10);
            if ((s32)GB_APU_REGS.trigger2 == 1) {
                D_8122C7E8.unk_14 = D_8122C7E8.unk_1C * 200;
                D_8122C7E8.unk_08.unk_02 = 0;
            D_8122C7E8.unk_20 = D_8120EB14[D_8122C7E8.unk_21];
            D_8122C7E8.unk_24 = 0;
                D_8122C7E8.unk_2E = GB_APU_REGS.envDir2;
                D_8122C7E8.unk_28 = GB_APU_REGS.envSweep2 * 800;
            D_8122C7E8.unk_2D = D_8122C7E8.unk_21;
                if (GB_APU_REGS.power) {
                D_8122C7E8.unk_00 = 1;
            }
        }
        break;
        case 0x1A:
            if (GB_APU_REGS.waveOn == 0) {
                D_8122C838.unk_00 = GB_APU_REGS.waveOn;
        }
        break;
        case 0x1B:
            D_8122C838.unk_1C = 0x100 - GB_APU_REGS.length3;
        break;
        case 0x1C:
            D_8122C838.unk_21 = GB_APU_REGS.level3;
            D_8122C838.unk_20 = D_8120EB24[D_8122C838.unk_21];
        break;
        case 0x1D:
            D_8122C838.unk_10 = GB_APU_REGS.freqLo3 | (GB_APU_REGS.freqHi3 << 8);
            D_8122C838.unk_0C = func_812073B8(D_8122C838.unk_10);
        break;
        case 0x1E:
            D_8122C838.unk_10 = GB_APU_REGS.freqLo3 | (GB_APU_REGS.freqHi3 << 8);
            D_8122C838.unk_0C = func_812073B8(D_8122C838.unk_10);
            D_8122C838.unk_18 = GB_APU_REGS.counter3;
            if ((s32)GB_APU_REGS.trigger3 == 1) {
                D_8122C838.unk_14 = D_8122C838.unk_1C * 200;
            D_8122C838.unk_04 = 0x140;
                if (GB_APU_REGS.power && ((s32)GB_APU_REGS.waveOn == 1)) {
                D_8122C838.unk_00 = 1;
            }
        }
        break;
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3A:
        case 0x3B:
        case 0x3C:
        case 0x3D:
        case 0x3E:
        case 0x3F:
            D_8122EE58[(reg - 0x30) * 2 + 0] = (D_8120EA70[reg - 0x10] >> 4) & 0xF;
            D_8122EE58[(reg - 0x30) * 2 + 1] = D_8120EA70[reg - 0x10] & 0xF;
        break;
        case 0x20:
            D_8122C888.unk_1C = 0x40 - GB_APU_REGS.length4;
        break;
        case 0x21:
            D_8122C888.unk_21 = GB_APU_REGS.volume4;
            if ((GB_APU_REGS.volume4 == 0) && (GB_APU_REGS.envDir4 == 0)) {
        D_8122C888.unk_00 = 0;
            }
        break;
        case 0x22:
            D_8122C888.unk_10 = GB_APU_REGS.shift4;
            D_8122C888.unk_0C = func_81207494(GB_APU_REGS.shift4, GB_APU_REGS.width4, GB_APU_REGS.ratio4);
            if (D_8122C888.unk_00 == 0) {
                D_8122C888.unk_40 = D_8122C888.unk_0C;
            }
            if (D_8122C888.unk_40 < D_8122C888.unk_0C) {
                D_8122C888.unk_48 = D_8122C888.unk_0C - D_8122C888.unk_40;
        } else {
                D_8122C888.unk_48 = D_8122C888.unk_40 - D_8122C888.unk_0C;
            }
            D_8122C888.unk_48 >>= 7;
            if (D_8122C888.unk_48 == 0) {
            D_8122C888.unk_48 = 1;
        }
        break;
        case 0x23:
            D_8122C888.unk_18 = GB_APU_REGS.counter4;
            if ((s32)GB_APU_REGS.trigger4 == 1) {
                D_8122C888.unk_14 = D_8122C888.unk_1C * 200;
                if (D_8122C888.unk_00 == 0) {
                D_8122C888.unk_08.unk_02 = 0;
            }
            D_8122C888.unk_2D = D_8122C888.unk_21;
                switch ((s32)GB_APU_REGS.width4) {
                    case 0:
                D_8122C888.unk_20 = D_8120EB28[D_8122C888.unk_2D];
                        break;
                    case 1:
                D_8122C888.unk_20 = D_8120EB38[D_8122C888.unk_2D];
                        break;
            }
                if ((D_8122C888.unk_00 == 0) || (D_8122C888.unk_3C < D_8122C888.unk_20)) {
                D_8122C888.unk_3C = D_8122C888.unk_20;
            }
            D_8122C888.unk_24 = 0;
                D_8122C888.unk_2E = GB_APU_REGS.envDir4;
                D_8122C888.unk_28 = GB_APU_REGS.envSweep4 * 800;
                if (GB_APU_REGS.power) {
                D_8122C888.unk_00 = 1;
            }
        }
        break;
        case 0x26:
            if (!(value & 0x80)) {
            D_8122C798.unk_00 = 0;
            D_8122C7E8.unk_00 = 0;
            D_8122C838.unk_00 = 0;
            D_8122C888.unk_00 = 0;
        }
        break;
    }
}

void func_81208828(s32 arg0, s16* arg1, UNUSED s32 arg2, UNUSED s32 arg3, s32 arg4) {
    OSMesg msg;
    s32* s4;
    OSMesgQueue* s7;
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s5;
    s32 s6;
    s16* s3ptr;
    s16* last;
    s16* out;
    s32 v1;
    s32 t0;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 a0;
    s32 a2;
    s32 a3;
    s32 t5;
    s32 t6;
    s32 t7;
    s32 t8;
    s32 t9;
    s32 u0;
    s32 u1;
    s32 lim;
    f32 rate;
    f32 acc;
    s32 factor;

    s7 = &D_8122EEB0;
    s4 = (s32*) &D_8122C8D8[0];
    s3ptr = (s16*) &msg;
    s5 = arg4;
    acc = 0.0f;
    v1 = 1;
    s1 = 0;
    s2 = 0;
    s0 = 0;
    while (1) {
        v1 = v1;
        if (osRecvMesg(s7, &msg, 0) == -1) {
            break;
        }
        if (v1 == 0) {
            s5 = (u16) msg;
            v1 = 0;
        }
        if (((u16) msg & 0xFFFF) < (u32) s0) {
            if ((u32) s5 < (u32) D_8120EAD0) {
                osJamMesg(s7, msg, 0);
                break;
            }
            s4[s1] = msg;
            s1 += 1;
            s0 = (u16) msg;
        } else {
            s4[s1] = msg;
            s1 += 1;
            s0 = (u16) msg;
        }
    }
    rate = (f32) D_8120EAC4 / (f32) arg0;
    factor = (arg0 < s1) ? 1 : 0;
    out = arg1;
    if (arg0 > 0) {
        last = (s16*) ((u8*) arg1 + (arg0 << 2));
        factor = factor;
        do {
            acc += rate;
            if (factor != 0) {
                while (s1 != 0) {
                    t7 = (s32) acc;
                    t8 = t7 & 0xFFFF;
                    if (t8 < (u32) ((s32*) &s4[s2])[0]) {
                        break;
                    }
                    s0 = s4[s2];
                    func_8120806C((u16) s0, (u8) (s0 >> 8));
                    s1 -= 1;
                    s2 += 1;
                }
            } else {
                if (s1 != 0) {
                    t7 = (s32) acc;
                    t8 = t7 & 0xFFFF;
                    if (t8 < (u32) ((s32*) &s4[s2])[0]) {
                    } else {
                        s0 = s4[s2];
                        func_8120806C((u16) s0, (u8) (s0 >> 8));
                        s1 -= 1;
                        s2 += 1;
                    }
                }
            }
            s6 = func_81207774();
            s3ptr = (s16*) func_81207A60();
            s0 = func_81207C5C();
            s3ptr = (s16*) s0;
            t0 = func_81207DF8();
            t4 = 0;
            t2 = 0;
            t3 = 0;
            t1 = 0;
            t0 = 0;
            a2 = 0;
            a3 = 0;
            s3ptr = s3ptr;
            t9 = (s8) *(u8*) ((u8*) s7 + 0x15);
            if (t9 < 0) {
                t4 = t0;
            }
            t6 = *(u32*) ((u8*) s7 + 0x14);
            if ((s32) (t6 << 12) < 0) {
                t2 = t0;
            }
            t8 = t6 << 9;
            if ((s32) t8 < 0) {
                t3 = s0;
            }
            t5 = t6 << 13;
            if ((s32) t5 < 0) {
                t1 = s0;
            }
            t7 = t6 << 10;
            if ((s32) t7 < 0) {
                t0 = s3ptr;
            }
            t9 = t6 << 14;
            if ((s32) t9 < 0) {
                a2 = s3ptr;
            }
            t6 = t6 << 11;
            if ((s32) t6 < 0) {
                a3 = s6;
            }
            a0 = 0;
            t7 = *(u16*) ((u8*) s7 + 0x14);
            if ((t7 & 1) != 0) {
                a0 = s6;
            }
            t9 = a0 + a2 + t1 + t2;
            t8 = *(u8*) ((u8*) s7 + 0x14) & 7;
            t5 = a3 + t0 + t3;
            lim = 8 - t8;
            u0 = (u32) t9 / (u32) lim;
            u1 = (u32) (t5 + t4) / (u32) (8 - ((u32) (t6 << 1) >> 29));
            if (u0 >= 0x8000) {
                u0 = 0x7FFF;
            }
            if (u1 >= 0x8000) {
                u1 = 0x7FFF;
            }
            out[0] = u1;
            out[1] = u0;
            out += 2;
        } while (out != last);
    }
    if (s1 != 0) {
        t6 = s2 << 2;
        t9 = (s32*) &D_8122C8D8[0];
        s4 = (s32*) ((u8*) t9 + t6);
        do {
            s0 = s4[0];
            func_8120806C((u16) s0, (u8) (s0 >> 8));
            s1 -= 1;
            s4 += 1;
        } while (s1 != 0);
    }
    D_8122EEA8.unk_00 = 0;
    D_8122EEA8.unk_01 = 0;
    D_8122EEA8.unk_02 = 0;
    D_8122EEA8.unk_03 = 0;
}

void func_81208C08(u16 arg0, u8 arg1, u16 arg2) {
    s32 temp_v1;

    temp_v1 = arg0 + 0xFFFF0100;
    osSendMesg(&D_8122EEB0, (temp_v1 << 0x18) | (arg1 << 0x10) | arg2, 0);
    D_8120EAD0 = (s32) arg2;
    switch (temp_v1) {
    case 20:
        if (arg1 & 0x80) {
            D_8122EEA8.unk_00 = 2;
            return;
        }
    default:
        return;
    case 25:
        if (arg1 & 0x80) {
            D_8122EEA8.unk_01 = 2;
            return;
        }
        break;
    case 30:
        if (arg1 & 0x80) {
            D_8122EEA8.unk_02 = 2;
            return;
        }
        break;
    case 35:
        if (arg1 & 0x80) {
            D_8122EEA8.unk_03 = 2;
            return;
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

void func_81208E4C(void) {
    void* sp34 = D_812346E0[0];
    f32 x = (f32) D_8122C790;
    f32 y = (f32) D_8122C792;
    f32 dx = x / 640.0f;
    f32 dy = y / 640.0f;
    s32 i;
    s32 idx;

    func_81208D7C();
    for (i = 0, idx = 0; i != 0x280; i++) {
        ((s16*)sp34)[idx + 0] = x;
        ((s16*)sp34)[idx + 1] = y;
        x -= dx;
        y -= dy;
        idx += 2;
    }
     do {
     } while (osAiGetStatus() & 0x80000000);
    osWritebackDCache(sp34, 0xA00);
    osGbSetNextBuffer(sp34, 0xA00);
}

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

s32 func_81209078(void) {
    s32 v0;
    s32 v1;
    s32 t0;
    s32 t2;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;

    D_812346D4 += 1;
    D_812346C8 += 1;
    D_812346D0 ^= 1;
    D_812346D4 %= 3;
    v1 = (D_812346D4 + 2) % 3;
    v0 = osAiGetLength();
    if (D_812346FC < 0x10) {
        a2 = D_812346EC[v1];
        if (a2 != 0) {
            a0 = (s32) ((u32*) &D_812346E0)[v1];
            if (osGbSetNextBuffer((void*) a0, a2 * 4) != -1) {
                D_8122C790 = *(s16*) ((u8*) a0 + (a2 * 4) - 4);
                D_8122C792 = *(s16*) ((u8*) a0 + (a2 * 4) - 2);
            }
        }
    }
    if (D_812346FC >= 0x11) {
        return 0;
    }
    if (D_812346FC != 0) {
        D_812346FC += 1;
    }
    v1 = D_812346D4;
    t2 = *(s16*) &D_81234690[3] - (v0 >> 2);
    a0 = *(s16*) &D_81234690[5];
    t2 = ((t2 + 0x80) & 0xFFF0) + 0x10;
    a3 = t2;
    if (a3 < a0) {
        a3 = a0;
    }
    a0 = *(s16*) &D_81234690[4];
    if (a0 < a3) {
        a3 = a0;
    }
    a1 = (s32) ((u32*) &D_812346E0)[v1];
    if (D_8120EB78 == 0) {
        func_81208828(a3, (void*) a1, 0, 0, 0);
    } else {
        func_81209374(a3, (void*) a1);
    }
    osWritebackDCache((void*) a1, a3 * 4);
    v0 = osGetCount();
    D_812346F4 = v0 * (D_812346F4 + D_812346C8);
    t0 = (s32) ((u32*) &D_812346E0)[v1];
    D_812346F4 += *(s16*) ((u8*) t0 + ((D_812346C8 & 0xFF) << 1));
    return 0;
}

void func_8120935C(s32 arg0) {
  D_8120EB78 = arg0;
}

void func_81209368(s32 arg0) {
  D_8120EB7C.id = arg0;
}

void func_81209374(s32 arg0, s16* arg1) {
    s32* p;
    s32 scale;
    s32 cursor1;
    s32 cursor2;
    s32 val1;
    s32 val2;
    s32 q1;
    s32 q2;
    s32 byte1;
    s32 byte2;
    s32 temp;
    s16* out;
    s16* end;
    s32 done;

    q1 = 0;
    q2 = 0;
    if (D_8120EB7C != 0) {
        p = (s32*) &D_8120EB7C;
        D_8120EB84[1] = p[1];
        D_8120EB84[1] = 0;
        p[0] = 0;
        D_8120EB8C[0] = D_8120EB84[0];
        D_8120EB8C[1] = D_8120EB84[1];
        D_8120EB84[0] = p[0];
        D_8122869C = 0x400;
    }
    scale = D_8122869C;
    cursor1 = D_8120EB84[0];
    cursor2 = D_8120EB8C[0];
    if (cursor1 != 0) {
        val1 = D_81228678[cursor1];
        q1 = D_81228654[cursor1];
    }
    if (cursor2 != 0) {
        val2 = D_81228678[cursor2];
        q2 = D_81228654[cursor2];
    }
    D_8122869C = scale;
    if (arg0 <= 0) {
        return;
    }
    done = 0;
    if (arg0 & 1) {
        byte1 = 0;
        if (q1 != 0) {
            temp = D_8120EB84[1];
            if (val1 == temp) {
                D_8120EB84[0] = 0;
                q1 = 0;
            } else {
                byte1 = *(s8*) (temp + q1);
                D_8120EB84[1] = temp + 1;
            }
        }
        byte2 = 0;
        if (q2 != 0) {
            temp = D_8120EB8C[1];
            if (val2 == temp) {
                D_8120EB8C[0] = 0;
                q2 = 0;
            } else {
                byte2 = *(s8*) (temp + q2);
                D_8120EB8C[1] = temp + 1;
                byte2 = byte2 * scale;
                if (byte2 < 0) {
                    byte2 += 0x3FF;
                }
                byte2 >>= 10;
            }
        }
        arg1[0] = (byte1 + byte2) << 6;
        arg1[2] = (byte1 - byte2) << 6;
        D_8122869C = scale;
        done = 1;
        if (done == arg0) {
            return;
        }
    }
    out = &arg1[done * 2];
    end = &arg1[arg0 * 2];
    do {
        byte1 = 0;
        if (q1 != 0) {
            temp = D_8120EB84[1];
            if (val1 == temp) {
                D_8120EB84[0] = 0;
                q1 = 0;
            } else {
                byte1 = *(s8*) (temp + q1);
                D_8120EB84[1] = temp + 1;
            }
        }
        byte2 = 0;
        if (q2 != 0) {
            temp = D_8120EB8C[1];
            if (val2 == temp) {
                D_8120EB8C[0] = 0;
                q2 = 0;
            } else {
                byte2 = *(s8*) (temp + q2);
                D_8120EB8C[1] = temp + 1;
                byte2 = byte2 * scale;
                if (byte2 < 0) {
                    byte2 += 0x3FF;
                }
                byte2 >>= 10;
            }
        }
        out[0] = (byte1 + byte2) << 6;
        out[2] = (byte1 - byte2) << 6;
        byte1 = 0;
        if (q1 != 0) {
            temp = D_8120EB84[1];
            if (val1 == temp) {
                D_8120EB84[0] = 0;
                q1 = 0;
            } else {
                byte1 = *(s8*) (temp + q1);
                D_8120EB84[1] = temp + 1;
            }
        }
        byte2 = 0;
        if (q2 != 0) {
            temp = D_8120EB8C[1];
            if (val2 == temp) {
                D_8120EB8C[0] = 0;
                q2 = 0;
            } else {
                byte2 = *(s8*) (temp + q2);
                D_8120EB8C[1] = temp + 1;
                byte2 = byte2 * scale;
                if (byte2 < 0) {
                    byte2 += 0x3FF;
                }
                byte2 >>= 10;
            }
        }
        out[4] = (byte1 + byte2) << 6;
        out[6] = (byte1 - byte2) << 6;
        out += 4;
    } while (out != end);
    D_8122869C = scale;
}
void func_81209688(UNUSED s32 arg0) {
}
