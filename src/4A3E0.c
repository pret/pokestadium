#include "4A3E0.h"
#include "src/4B940.h"
#include "src/373A0.h"

typedef struct unk_D_800FD008 {
    /* 0x00 */ u16 unk_00[20];
    /* 0x28 */ u8 unk_28;
    /* 0x29 */ u8 unk_29;
    /* 0x2A */ u8 unk_2A;
    /* 0x2B */ char unk2B[1];
    /* 0x2C */ u8 unk_2C;
} unk_D_800FD008; // size >= 0x2D

typedef struct unk_D_800FD068 {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x06 */ u16 unk_06;
} unk_D_800FD068; // size = 0x8

extern unk_D_800FD008 D_800FD008;
extern unk_D_800FD068 D_800FD068[199];
extern u32 D_800FD6A8;
extern u8 D_800FD6E0;
extern u8 D_800FD6E1;
extern f32 D_800FD6E4;
extern u32 D_800FD6F0;
extern u32 D_800FD6F4;
extern s16 D_800FD6F8[0x1140];
extern u8 D_800FD6A0[8];
extern u32 D_800FD6AC;
extern u32 D_800FF978;
extern u8 D_800FF97C;
extern s32 D_800FF980;
void func_80049A60(u32);

void func_800497E0(s16* arg0, s32 arg1, u32 arg2, f32 arg3) {
    func_80049A60(arg2);
}

void func_8004980C(u16 arg0, u8 arg1, u16 arg2) {
    D_800FD068[D_800FD6AC].unk_00 = (u8*)&D_800FD008.unk_00[(arg0 & 0xFF) - 0x10];
    D_800FD068[D_800FD6AC].unk_04 = arg1;
    D_800FD068[D_800FD6AC].unk_06 = arg2 + 1;
    D_800FD6A0[arg0 & 0xFF] = arg1;
    D_800FD6AC++;
    D_800FD6AC %= 200;
    D_800FD068[D_800FD6AC].unk_06 = 0;
}

u8 func_80049890(u16 arg0) {
    return D_800FD6A0[arg0 & 0xFF];
}

#ifdef NON_MATCHING
extern u32 D_800FD004;
extern u8 D_800FD048[];
extern s16 D_800FD06E;
extern u8 D_800FCF60[];
extern u8 D_800FCF90[];
extern u8 D_800FCFB8[];
extern u8 D_800FCFD8[];
extern s32 D_800FD6E8;
void func_8004ACD0(void);
void func_8004AC9C(void);
// Reset the sound-mixer state: clear the voice/command tables, seed the first
// command entry, zero the four channel structs, and set the output sample rate.
void func_800498A8(s32 arg0, s32 arg1, s32 arg2) {
    s32 rate = (u32) arg0 >> 1;
    u8* p;
    s32 len;

    D_800FD004 = rate;
    D_800FD6E4 = 1048576.0f / (f32) rate;

    p = (u8*) &D_800FD008;
    do {
        p += 2;
        p[-1] = 1;
    } while ((u32) p < (u32) D_800FD068);

    p = (u8*) &D_800FD008;
    p[0x00] = 8;
    p[0x02] = 0;
    p[0x04] = 0;
    p[0x06] = 0;
    p[0x08] = 0x40;
    p[0x0C] = 0;
    p[0x0E] = 0;
    p[0x10] = 0;
    p[0x12] = 0x40;
    p[0x14] = 0;
    p[0x16] = 0;
    p[0x18] = 0;
    p[0x1A] = 0;
    p[0x1C] = 0x40;
    p[0x20] = 0;
    p[0x22] = 0;
    p[0x24] = 0;
    p[0x26] = 0x40;
    p[0x28] = 0;
    p[0x2A] = 0;
    p[0x2C] = 0;

    p = D_800FD048;
    do {
        p += 8;
        p[-6] = 0;
        p[-4] = 0;
        p[-2] = 0;
        p[-8] = 0;
    } while (p != (u8*) D_800FD068);

    D_800FD6AC = 0;
    D_800FD06E = 0;
    D_800FD6A8 = 0;

    *(u32*) &D_800FCF60[0] = 0;
    D_800FCF60[0x2C] = 0;
    *(u32*) &D_800FCF90[0] = 0;
    D_800FCF90[0x24] = 0;
    *(u32*) &D_800FCFB8[0] = 0;
    D_800FCFB8[0x1C] = 0;
    *(u32*) &D_800FCFD8[0] = 0;
    D_800FCFD8[0x28] = 0;
    D_800FCFD8[0x04] = 0xFF;

    func_8004ACD0();
    func_8004AC9C();

    D_800FF97C = (u8) arg1;
    len = arg2 * 2;
    D_800FF980 = arg2;
    D_800FF980 = len;
    if ((u32) len >= 0x1141) {
        D_800FF980 = 0x1140;
    }
    D_800FD6E8 = 2;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/4A3E0/func_800498A8.s")
#endif

void func_80049D5C(u16);
s16 func_80049DF0(void);
s16 func_8004A474(void);
s16 func_8004A89C(void);

#ifdef NON_MATCHING
void func_80049A60(u32 arg0) {
    s32 pad[3];
    s16 sp4C[4];
    u32 i;
    f32 var_fs0;
    s16 var_a0;
    u32 var_a2;
    u32 var_a3;
    u32 tmp2;
    s32 var_s4;
    u32 var_v1;
    s16 tmp;

    var_fs0 = 0.0f;
    var_s4 = 1;
    arg0 >>= 1;

    if (D_800FD6F4 < D_800FD6F0) {
        if ((0xB80 - (arg0 * 4)) < (D_800FD6F0 - D_800FD6F4)) {
            arg0++;
        }
    } else if ((D_800FD6F4 - D_800FD6F0) < (arg0 * 4)) {
        arg0++;
    }

    for (i = 0; i < arg0; i++) {
        if (var_fs0 <= i) {
            func_80049D5C(var_s4);
        }

        if (D_800FD008.unk_2C & 0x80) {
            if (D_800FD008.unk_29 != 0) {
                D_800FD6E0 = D_800FD008.unk_28 & 7;
                D_800FD6E1 = (D_800FD008.unk_28 & 0x70) >> 4;
                D_800FD008.unk_29 = 0;
            }

            sp4C[0] = func_80049DF0();
            sp4C[1] = func_8004A474();
            sp4C[3] = func_8004A89C();

            var_a0 =
                ((u32)((sp4C[0] & ((D_800FD008.unk_2A & 1) ? -1 : 0)) + (sp4C[1] & ((D_800FD008.unk_2A & 2) ? -1 : 0)) +
                       (sp4C[3] & ((D_800FD008.unk_2A & 8) ? -1 : 0))) >>
                 5) *
                (D_800FD6E0 + 1);
        } else {
            var_a0 = 0;
        }

        if (D_800FF97C != 0) {
            if (1) {}
            if (1) {}
            if (1) {}
            if (1) {}
            tmp = (f32)D_800FD6F8[((D_800FF978 - D_800FF980) + 0x1140) % 4416];

            var_a0 += (s16)(((tmp - var_a0) * D_800FF97C) >> 8);
            D_800FD6F8[D_800FF978++] = var_a0;
            if (D_800FF978 >= 0x1140) {
                D_800FF978 -= 0x1140;
            }
        }

        D_800FC6D8[D_800FD6F4 + 0] = var_a0;
        D_800FC6D8[D_800FD6F4 + 1] = var_a0;

        D_800FD6F4 += 2;
        if (D_800FD6F4 >= 0xB80) {
            D_800FD6F4 -= 0xB80;
        }

        var_s4++;
        var_fs0 += D_800FD6E4;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/4A3E0/func_80049A60.s")
#endif

void func_80049D5C(u16 arg0) {
    while (D_800FD068[D_800FD6A8].unk_06 >= arg0) {
        D_800FD068[D_800FD6A8].unk_00[0] = D_800FD068[D_800FD6A8].unk_04;
        D_800FD068[D_800FD6A8].unk_00[1] = 1;
        D_800FD6A8++;
        if (D_800FD6A8 >= 0xC8) {
            D_800FD6A8 -= 0xC8;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/4A3E0/func_80049DF0.s")

#ifdef NON_MATCHING
extern u8 D_800FD015;
extern u8 D_800FD016;
extern u8 D_800FD017;
extern u8 D_800FD019;
extern u8 D_800FD01B;
typedef struct GbPulse {
    /* 0x00 */ u32 unk_00; // phase position
    /* 0x04 */ s16 unk_04; // current amplitude
    /* 0x06 */ s16 unk_06; // envelope step
    /* 0x08 */ u32 unk_08; // envelope reload
    /* 0x0C */ u32 unk_0C; // envelope counter
    /* 0x10 */ s16 unk_10; // high half-period
    /* 0x12 */ s16 unk_12; // low half-period
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ u8 unk_16;  // duty phase (high/low)
    /* 0x17 */ u8 pad_17;
    /* 0x18 */ u32 unk_18; // next duty toggle position
    /* 0x1C */ u32 unk_1C; // full period
    /* 0x20 */ u32 unk_20; // length counter
    /* 0x24 */ u32 unk_24; // channel active
} GbPulse;
// Software-APU square (pulse) channel: on a register-change trigger, decode the
// GB pulse registers (D_800FD008) into period/duty/envelope/length, then each
// call advance the duty toggle and envelope and return the current amplitude.
s16 func_8004A474(void) {
    GbPulse* ch = (GbPulse*) D_800FCF90;
    u8* reg = (u8*) &D_800FD008;
    s32 triggered = 0;
    s16 out;

    if (D_800FD015 != 0) {
        triggered = 1;
        D_800FD015 = 0;
    }
    if (D_800FD017 != 0) {
        triggered = 1;
        D_800FD017 = 0;
    }
    if (D_800FD019 != 0) {
        triggered = 1;
        D_800FD019 = 0;
    }
    if (D_800FD01B != 0) {
        triggered = 1;
        D_800FD01B = 0;
    }

    if (triggered != 0) {
        s32 duty = (reg[0xC] & 0xC0) >> 6;
        s32 envDir;
        u8 startPhase = 1;
        s16 half;

        ch->unk_1C = ((0x800 - (reg[0x10] | ((reg[0x12] & 7) << 8))) * D_800FD004) >> 0xB;

        switch (duty) {
            case 0:
                half = ch->unk_1C >> 3;
                ch->unk_12 = half;
                if ((half & 0xFFFF) < 0x40) {
                    ch->unk_12 = 0x40;
                    half = 0x40;
                }
                startPhase = 1;
                ch->unk_10 = ch->unk_1C - (half & 0xFFFF);
                break;
            case 1:
                half = ch->unk_1C >> 2;
                ch->unk_12 = half;
                if ((half & 0xFFFF) < 0x40) {
                    ch->unk_12 = 0x40;
                    half = 0x40;
                }
                startPhase = 0;
                ch->unk_10 = ch->unk_1C - (half & 0xFFFF);
                break;
            case 2:
                half = ch->unk_1C >> 1;
                ch->unk_12 = half;
                if ((half & 0xFFFF) < 0x40) {
                    ch->unk_12 = 0x40;
                    half = 0x40;
                }
                startPhase = 0;
                ch->unk_10 = ch->unk_1C - (half & 0xFFFF);
                break;
            case 3:
                half = ch->unk_1C >> 2;
                ch->unk_10 = half;
                if ((half & 0xFFFF) < 0x40) {
                    ch->unk_10 = 0x40;
                    half = 0x40;
                }
                startPhase = 1;
                ch->unk_12 = ch->unk_1C - (half & 0xFFFF);
                break;
            default:
                ch->unk_10 = ch->unk_1C;
                ch->unk_12 = 0;
                startPhase = 1;
                break;
        }

        envDir = reg[0xE] & 8;
        if ((envDir == 0) && !(reg[0xE] & 0xF0)) {
            ch->unk_24 = 0;
            reg[0x2C] &= 0xFD;
            return 0;
        }
        if ((envDir != 0) && !(reg[0xE] & 0xF0) && !(reg[0xE] & 7)) {
            ch->unk_24 = 0;
            reg[0x2C] &= 0xFD;
            return 0;
        }
        if (reg[0x12] & 0x80) {
            s32 envPeriod = reg[0xE] & 7;

            ch->unk_00 = 0;
            ch->unk_24 = 1;
            ch->unk_16 = startPhase;
            ch->unk_14 = 0;
            ch->unk_18 = 0;
            ch->unk_04 = (reg[0xE] & 0xF0) << 7;
            if (envPeriod != 0) {
                if (envDir != 0) {
                    ch->unk_06 = 0x800;
                } else {
                    ch->unk_06 = -0x800;
                }
                ch->unk_08 = envPeriod * D_800FD004;
                ch->unk_0C = envPeriod * D_800FD004;
            } else {
                ch->unk_06 = 0;
                ch->unk_08 = -1;
                ch->unk_0C = -1;
            }
            if (reg[0x12] & 0x40) {
                ch->unk_20 = ((0x40 - (reg[0xC] & 0x3F)) * D_800FD004) >> 2;
            } else {
                ch->unk_20 = -1;
            }
            reg[0x12] &= 0x7F;
        }
    }

    if (ch->unk_24 == 0) {
        return 0;
    }

    if (ch->unk_20 < ch->unk_00) {
        ch->unk_24 = 0;
        reg[0x2C] &= 0xFD;
        return 0;
    }
    if (ch->unk_0C < ch->unk_00) {
        ch->unk_04 += ch->unk_06;
        ch->unk_0C += ch->unk_08;
    }

    if (ch->unk_00 >= ch->unk_18) {
        u8 phase = ch->unk_16;
        u32 next = ch->unk_18;

        do {
            phase ^= 1;
            ch->unk_16 = phase;
            next += (&ch->unk_10)[phase];
            ch->unk_18 = next;
        } while (ch->unk_00 >= next);
    }

    if (!(D_800FD016 & 8) && (ch->unk_04 < 0)) {
        ch->unk_24 = 0;
        return 0;
    }
    if ((ch->unk_04 & 0xFFFF) >= 0x7801) {
        ch->unk_04 = 0x7800;
        ch->unk_06 = 0;
        ch->unk_0C = -1;
    }

    out = ch->unk_04;
    if (ch->unk_16 == 0) {
        out = -out;
    }
    ch->unk_00 += 0x40;
    return out;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/4A3E0/func_8004A474.s")
#endif

#ifdef NON_MATCHING
extern u8 D_800FD028[];
extern u8 D_800FD030[];
extern u8 D_800FD02A;
extern u8 D_80078A60[];
extern f32 D_8007D4D0;
extern f32 D_8007D4D4;
typedef struct GbWave {
    /* 0x00 */ u32 unk_00; // phase position
    /* 0x04 */ u8 unk_04;  // current wave index
    /* 0x05 */ u8 pad_05[3];
    /* 0x08 */ u32 unk_08; // sample read position
    /* 0x0C */ f32 unk_0C; // samples per output
    /* 0x10 */ f32 unk_10; // sample accumulator
    /* 0x14 */ f32 unk_14; // volume
    /* 0x18 */ f32 unk_18; // envelope step
    /* 0x1C */ u32 unk_1C; // envelope reload
    /* 0x20 */ u32 unk_20; // envelope counter
    /* 0x24 */ u32 unk_24; // length counter
    /* 0x28 */ u32 unk_28; // channel active
} GbWave;
// Software-APU wave (PCM sample) channel: on a register trigger, decode the GB
// wave registers (D_800FD008), DMA in the selected waveform, set up envelope and
// length, then each call resample the waveform and return the scaled amplitude.
s16 func_8004A89C(void) {
    GbWave* ch = (GbWave*) D_800FCFD8;
    u8* reg = (u8*) &D_800FD008;
    u8* trig = (u8*) &D_800FD028;
    s32 triggered = 0;

    do {
        if (trig[1] != 0) {
            triggered = 1;
            trig[1] = 0;
        }
        trig += 2;
    } while (trig != (u8*) &D_800FD030);

    if (triggered != 0) {
        u8* entry = &D_80078A60[((reg[0x24] & 7) << 7) + (((reg[0x24] & 0xF0) >> 4) * 8)];
        u8 waveIdx = entry[0];
        s32 envDir;

        if (waveIdx == 0xFF) {
            ch->unk_28 = 0;
            return 0;
        }
        if (reg[0x24] & 8) {
            waveIdx = (waveIdx + 0x10) & 0xFF;
        }
        ch->unk_0C = (f32) *(s32*) &entry[4];
        if (ch->unk_04 != waveIdx) {
            ch->unk_04 = waveIdx;
            func_8004ADB0(D_800FC6CC[waveIdx].unk_00, (u32) D_800FC6D0, D_800FC6CC[waveIdx].unk_04);
        }
        ch->unk_08 = 0;
        envDir = reg[0x22] & 8;
        ch->unk_10 = 0.0f;
        if ((envDir == 0) && !(reg[0x22] & 0xF0)) {
            ch->unk_28 = 0;
            reg[0x2C] &= 0xF7;
            return 0;
        }
        if ((envDir != 0) && !(reg[0x22] & 0xF0) && !(reg[0x22] & 7)) {
            ch->unk_28 = 0;
            reg[0x2C] &= 0xF7;
            return 0;
        }
        if (reg[0x26] & 0x80) {
            s32 envPeriod = reg[0x22] & 7;

            ch->unk_00 = 0;
            ch->unk_28 = 1;
            ch->unk_14 = (f32) (reg[0x22] & 0xF0) * D_8007D4D0;
            if (envPeriod != 0) {
                if (envDir != 0) {
                    ch->unk_18 = D_8007D4D0;
                } else {
                    ch->unk_18 = D_8007D4D4;
                }
                ch->unk_1C = envPeriod * D_800FD004 * 4;
                ch->unk_20 = envPeriod * D_800FD004 * 4;
            } else {
                ch->unk_1C = -1;
                ch->unk_20 = -1;
                ch->unk_18 = 0.0f;
            }
            if (reg[0x26] & 0x40) {
                ch->unk_24 = (0x40 - (reg[0x20] & 0x3F)) * D_800FD004;
            } else {
                ch->unk_24 = -1;
            }
            reg[0x26] &= 0x7F;
        }
    }

    if (ch->unk_28 == 0) {
        return 0;
    }

    if (ch->unk_24 < ch->unk_00) {
        ch->unk_28 = 0;
        reg[0x2C] &= 0xF7;
        return 0;
    }
    if (ch->unk_20 < ch->unk_00) {
        ch->unk_20 += ch->unk_1C;
        ch->unk_14 += ch->unk_18;
    }
    ch->unk_10 += 1.0f;
    if (ch->unk_0C <= ch->unk_10) {
        ch->unk_08++;
        ch->unk_10 -= ch->unk_0C;
        if (ch->unk_08 >= (u32) (D_800FC6CC[ch->unk_04].unk_04 >> 1)) {
            ch->unk_08 = 0;
        }
    }
    if (!(D_800FD02A & 8) && (ch->unk_14 < 0.0f)) {
        ch->unk_28 = 0;
        return 0;
    }
    if (ch->unk_14 > 0.75f) {
        ch->unk_14 = 0.75f;
        ch->unk_20 = -1;
        ch->unk_18 = 0.0f;
    }
    ch->unk_00 += 0x100;
    return (s16) (s32) ((f32) ((s16*) D_800FC6D0)[ch->unk_08] * ch->unk_14);
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/4A3E0/func_8004A89C.s")
#endif

void func_8004AC9C(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800FD6F8); i++) {
        D_800FD6F8[i] = 0;
    }
    D_800FF978 = 0;
}

void func_8004ACD0(void) {
    s32 i;

    for (i = 0; i < 0xB80; i++) {
        D_800FC6D8[i] = 0;
    }
    D_800FD6F0 = 0;
    D_800FD6F4 = 0;
}

void func_8004AD2C(void) {

}
