#include "gb_audio_render.h"
#include "src/rom_device.h"
#include "src/audio_commands.h"

typedef struct unk_D_800FD008 {
    /* 0x00 */ u16 unk_00[20];
    /* 0x28 */ u8 unk_28;
    /* 0x29 */ u8 unk_29;
    /* 0x2A */ u8 unk_2A;
    /* 0x2B */ char unk2B[1];
    /* 0x2C */ u8 unk_2C;
    /* 0x2D */ char unk2D[0x13];
} unk_D_800FD008; // size = 0x40

// Each GB sound register is mirrored as a {value, dirty} byte pair.
#define GB_REG(n) (((u8*)&D_800FD008.unk_00[n])[0])
#define GB_REG_DIRTY(n) (((u8*)&D_800FD008.unk_00[n])[1])

typedef struct unk_D_800FD068 {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x06 */ u16 unk_06;
} unk_D_800FD068; // size = 0x8

typedef struct unk_D_800FCFD8 {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 pad05[0x3];
    /* 0x04 */ u32 unk_08;
    /* 0x04 */ f32 unk_0C;
    /* 0x04 */ f32 unk_10;
    /* 0x04 */ f32 unk_14;
    /* 0x04 */ f32 unk_18;
    /* 0x04 */ u32 unk_1C;
    /* 0x04 */ u32 unk_20;
    /* 0x04 */ u32 unk_24;
    /* 0x04 */ u8 unk_28;
} unk_D_800FCFD8; // size = 0x2C

typedef struct unk_D_800FCF90 {
    /* 0x00 */ u32 unk_00;
    /* 0x00 */ s16 unk_04;
    /* 0x00 */ s16 unk_06;
    /* 0x00 */ u32 unk_08;
    /* 0x00 */ u32 unk_0C;
    /* 0x10 */ u16 unk_10[2];
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ u8 unk_16;
    /* 0x00 */ u32 unk_18;
    /* 0x00 */ u32 unk_1C;
    /* 0x00 */ u32 unk_20;
    /* 0x24 */ u8 unk_24;
} unk_D_800FCF90; // size = 0x28

typedef struct unk_D_800FCFB8 {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u8 unk04[0x18];
    /* 0x1C */ u8 unk_1C;
} unk_D_800FCFB8; // size = 0x20

typedef struct unk_D_800FCF60 {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ char pad06[0x2];
    /* 0x08 */ u32 unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u32 unk_14;
    /* 0x18 */ u16 unk_18[2];
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ u8 unk_1E;
    /* 0x1F */ char pad1F[0x1];
    /* 0x20 */ u32 unk_20;
    /* 0x24 */ u32 unk_24;
    /* 0x28 */ u32 unk_28;
    /* 0x2C */ u8 unk_2C;
} unk_D_800FCF60; // size = 0x30

// .bss
unk_D_800FCF60 D_800FCF60;
unk_D_800FCF90 D_800FCF90;
unk_D_800FCFB8 D_800FCFB8;
unk_D_800FCFD8 D_800FCFD8;
u32 D_800FD004;
unk_D_800FD008 D_800FD008;
u8 D_800FD048[32];
unk_D_800FD068 D_800FD068[199];
u8 D_800FD6A0[8];
u32 D_800FD6A8;
u32 D_800FD6AC;
static u8 D_800FD6B0[0x30]; // pad
u8 D_800FD6E0;
u8 D_800FD6E1;
f32 D_800FD6E4;
s32 D_800FD6E8;
static u8 D_800FD6EC[0x4]; // pad
u32 D_800FD6F0;
u32 D_800FD6F4;
s16 D_800FD6F8[0x1140];
u32 D_800FF978;
u8 D_800FF97C;
s32 D_800FF980;

// Noise channel sample table: 8 rows (NR43 ratio) x 16 columns (NR43 shift clock).
typedef struct GbNoiseEntry {
    /* 0x0 */ u8 sampleId;
    /* 0x4 */ f32 pitchStep;
} GbNoiseEntry; // size = 0x8

#define GB_NOISE_TABLE ((GbNoiseEntry(*)[16])D_80078A60)

extern f32 D_8007D4D0;
extern f32 D_8007D4D4;

void func_80049A60(u32);
void GbAudio_ClearInterpolationHistory();
void GbAudio_ClearOutputBuffer();

// Looks like {u32 index, f32} pairs; only func_8004A89C references it, so the
// element type is unconfirmed. Kept as raw words to stay byte-exact.
u32 D_80078A60[0x100] = {
    0x00000000, 0x3F800000, 0x01000000, 0x3F800000,
    0x02000000, 0x3F800000, 0x03000000, 0x3F800000,
    0x04000000, 0x3F800000, 0x05000000, 0x3F800000,
    0x06000000, 0x3F800000, 0x07000000, 0x3F800000,
    0x08000000, 0x3F800000, 0x09000000, 0x3F800000,
    0x0A000000, 0x3F800000, 0x0B000000, 0x3F800000,
    0x0C000000, 0x3F800000, 0x0D000000, 0x3F800000,
    0xFF000000, 0x3F800000, 0xFF000000, 0x3F800000,
    0x01000000, 0x3F800000, 0x02000000, 0x3F800000,
    0x03000000, 0x3F800000, 0x04000000, 0x3F800000,
    0x05000000, 0x3F800000, 0x06000000, 0x3F800000,
    0x07000000, 0x3F800000, 0x08000000, 0x3F800000,
    0x09000000, 0x3F800000, 0x0A000000, 0x3F800000,
    0x0B000000, 0x3F800000, 0x0C000000, 0x3F800000,
    0x0D000000, 0x3F800000, 0x0D000000, 0x40000000,
    0xFF000000, 0x3F800000, 0xFF000000, 0x3F800000,
    0x02000000, 0x3F800000, 0x03000000, 0x3F800000,
    0x04000000, 0x3F800000, 0x05000000, 0x3F800000,
    0x06000000, 0x3F800000, 0x07000000, 0x3F800000,
    0x08000000, 0x3F800000, 0x09000000, 0x3F800000,
    0x0A000000, 0x3F800000, 0x0B000000, 0x3F800000,
    0x0C000000, 0x3F800000, 0x0D000000, 0x3F800000,
    0x0D000000, 0x40000000, 0x0D000000, 0x40800000,
    0xFF000000, 0x3F800000, 0xFF000000, 0x3F800000,
    0x02000000, 0x3FC00000, 0x03000000, 0x3FC00000,
    0x04000000, 0x3FC00000, 0x05000000, 0x3FC00000,
    0x06000000, 0x3FC00000, 0x07000000, 0x3FC00000,
    0x08000000, 0x3FC00000, 0x09000000, 0x3FC00000,
    0x0A000000, 0x3FC00000, 0x0B000000, 0x3FC00000,
    0x0C000000, 0x3FC00000, 0x0D000000, 0x3FC00000,
    0x0D000000, 0x40400000, 0x0D000000, 0x40C00000,
    0xFF000000, 0x3F800000, 0xFF000000, 0x3F800000,
    0x03000000, 0x3F800000, 0x04000000, 0x3F800000,
    0x05000000, 0x3F800000, 0x06000000, 0x3F800000,
    0x07000000, 0x3F800000, 0x08000000, 0x3F800000,
    0x09000000, 0x3F800000, 0x0A000000, 0x3F800000,
    0x0B000000, 0x3F800000, 0x0C000000, 0x3F800000,
    0x0D000000, 0x3F800000, 0x0D000000, 0x40000000,
    0x0D000000, 0x40800000, 0x0D000000, 0x41000000,
    0xFF000000, 0x3F800000, 0xFF000000, 0x3F800000,
    0x03000000, 0x3FA00000, 0x04000000, 0x3FA00000,
    0x05000000, 0x3FA00000, 0x06000000, 0x3FA00000,
    0x07000000, 0x3FA00000, 0x08000000, 0x3FA00000,
    0x09000000, 0x3FA00000, 0x0A000000, 0x3FA00000,
    0x0B000000, 0x3FA00000, 0x0C000000, 0x3FA00000,
    0x0D000000, 0x3FA00000, 0x0D000000, 0x40200000,
    0x0D000000, 0x40A00000, 0x0D000000, 0x41200000,
    0xFF000000, 0x3F800000, 0xFF000000, 0x3F800000,
    0x03000000, 0x3FC00000, 0x04000000, 0x3FC00000,
    0x05000000, 0x3FC00000, 0x06000000, 0x3FC00000,
    0x07000000, 0x3FC00000, 0x08000000, 0x3FC00000,
    0x09000000, 0x3FC00000, 0x0A000000, 0x3FC00000,
    0x0B000000, 0x3FC00000, 0x0C000000, 0x3FC00000,
    0x0D000000, 0x3FC00000, 0x0D000000, 0x40400000,
    0x0D000000, 0x40C00000, 0x0D000000, 0x41400000,
    0xFF000000, 0x3F800000, 0xFF000000, 0x3F800000,
    0x03000000, 0x3FE00000, 0x04000000, 0x3FE00000,
    0x05000000, 0x3FE00000, 0x06000000, 0x3FE00000,
    0x07000000, 0x3FE00000, 0x08000000, 0x3FE00000,
    0x09000000, 0x3FE00000, 0x0A000000, 0x3FE00000,
    0x0B000000, 0x3FE00000, 0x0C000000, 0x3FE00000,
    0x0D000000, 0x3FE00000, 0x0D000000, 0x40600000,
    0x0D000000, 0x40E00000, 0x0D000000, 0x41600000,
    0xFF000000, 0x3F800000, 0xFF000000, 0x3F800000,
};
s32 D_80078E60 = 0;
s32 D_80078E64 = 0;
s32 D_80078E68 = 0;
s32 D_80078E6C = 0; // unreferenced
s32 D_80078E70 = 0;
s32 D_80078E74 = 112;
u8 D_80078E78 = 0x00;
u8 D_80078E7C = 0x00;

// D_80078E80 and D_80078E83/8B/93/9B/A3/AB/B3 are interior aliases
// (undefined_syms.ld); variables.h already declares D_80078E80 as a u8.
u8 sLoopPointTable[0x3C] = {
    0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x04, 0x05,
    0x23, 0x23, 0x23, 0x25, 0x25, 0x25, 0x25, 0x0E, 0x23, 0x23, 0x23, 0x25,
    0x25, 0x25, 0x0E, 0x0D, 0x06, 0x06, 0x06, 0x37, 0x37, 0x37, 0x3B, 0x39,
    0x34, 0x34, 0x34, 0x2F, 0x2F, 0x2F, 0x2E, 0x35, 0x0B, 0x0B, 0x0B, 0x0C,
    0x0C, 0x0C, 0x0C, 0x12, 0x0B, 0x0B, 0x0B, 0x0C, 0x0C, 0x0C, 0x12, 0x36,
};
// D_80078EBF is an interior alias.
u8 D_80078EBC[0xC] = {
    0x22, 0x22, 0x22, 0x24, 0x24, 0x24, 0x24, 0x24, 0x26, 0x00, 0x00, 0x00,
};
s32 D_80078EC8 = -1;
s32 D_80078ECC = 0;
u8 D_80078ED0 = 0x00;
s32 D_80078ED4 = 0;
s32 D_80078ED8 = 0;
s32 D_80078EDC = 0;

void GbAudio_GenerateSamples(s16* arg0, s32 arg1, u32 arg2, f32 arg3) {
    func_80049A60(arg2);
}

void GbAudio_QueueRegisterWrite(u16 arg0, u8 arg1, u16 arg2) {
    D_800FD068[D_800FD6AC].unk_00 = (u8*)&D_800FD008.unk_00[(arg0 & 0xFF) - 0x10];
    D_800FD068[D_800FD6AC].unk_04 = arg1;
    D_800FD068[D_800FD6AC].unk_06 = arg2 + 1;
    D_800FD6A0[arg0 & 0xFF] = arg1;
    D_800FD6AC++;
    D_800FD6AC %= 200;
    D_800FD068[D_800FD6AC].unk_06 = 0;
}

u8 GbAudio_GetRegisterValue(u16 arg0) {
    return D_800FD6A0[arg0 & 0xFF];
}

void func_800498A8(u32 arg0, u8 arg1, u32 arg2) {
    u32 temp_t3;
    u8* p;
    s32 i;
    D_800FD004 = arg0 >> 1;
    D_800FD6E4 = 1048576.0f / (f32) D_800FD004;

    p = (u8*) &D_800FD008;
    for (i = 0; i < 48; i++) {
       p[i * 2 + 1] = 1;
    }
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
    for (i = 0; i < 16; i++) {
        p[i * 2] = 0;
    }
    D_800FD6AC = 0;
    D_800FD068[0].unk_06 = 0;
    D_800FD6A8 = 0;
    D_800FCF60.unk_00 = 0;
    D_800FCF60.unk_2C = 0;

    D_800FCF90.unk_00 = 0;
    D_800FCF90.unk_24 = 0;

    D_800FCFB8.unk_00 = 0;
    D_800FCFB8.unk_1C = 0;

    D_800FCFD8.unk_00 = 0;
    D_800FCFD8.unk_28 = 0;
    D_800FCFD8.unk_04 = 0xFF;

    GbAudio_ClearOutputBuffer();
    GbAudio_ClearInterpolationHistory();

    D_800FF97C = arg1;
    D_800FF980 = arg2;
    D_800FF980 *= 2;
    if (D_800FF980 >= 0x1141U) {
        D_800FF980 = 0x1140;
    }
    D_800FD6E8 = 2;
}

void GbAudio_ApplyQueuedWrites(u16);
s16 func_80049DF0(void);
s16 func_8004A474(void);
s16 func_8004A89C(void);

void func_80049A60(u32 arg0) {
    s32 pad[3];
    s16 sp4C[4];
    u32 i;
    f32 var_fs0;
    s16 var_a0;
    s32 var_s4;
    s16 tmp;
    u8 var_t;

    var_fs0 = 0.0f;
    var_s4 = 1;
    arg0 >>= 1;

    var_t = D_800FD6E1;
    var_a0 = ((var_t & 1) ? -1 : 0) + ((var_t & 2) ? -1 : 0) + ((var_t & 8) ? -1 : 0);

    if (D_800FD6F4 < D_800FD6F0) {
        if ((0xB80 - (arg0 * 4)) < (D_800FD6F0 - D_800FD6F4)) {
            arg0++;
        }
    } else if ((D_800FD6F4 - D_800FD6F0) < (arg0 * 4)) {
        arg0++;
    }

    for (i = 0; i < arg0; i++) {
        if (var_fs0 <= i) {
            GbAudio_ApplyQueuedWrites(var_s4);
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

            var_t = D_800FD008.unk_2A;
            var_a0 =
                ((u32)((sp4C[0] & ((var_t & 1) ? -1 : 0)) + (sp4C[1] & ((var_t & 2) ? -1 : 0)) +
                       (sp4C[3] & ((var_t & 8) ? -1 : 0))) >>
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

void GbAudio_ApplyQueuedWrites(u16 arg0) {
    while (D_800FD068[D_800FD6A8].unk_06 >= arg0) {
        D_800FD068[D_800FD6A8].unk_00[0] = D_800FD068[D_800FD6A8].unk_04;
        D_800FD068[D_800FD6A8].unk_00[1] = 1;
        D_800FD6A8++;
        if (D_800FD6A8 >= 0xC8) {
            D_800FD6A8 -= 0xC8;
        }
    }
}

s16 func_80049DF0(void) {
    s32 i;
    s32 changed;
    s32 nr14;
    u8 phase;
    u16 freq;
    s16 out;

    changed = 0;
    for (i = 0; i < 5; i++) {
        if (GB_REG_DIRTY(i) != 0) {
            changed = 1;
            GB_REG_DIRTY(i) = 0;
        }
    }

    if (changed) {
        nr14 = GB_REG(4);
        D_800FCF60.unk_04 = GB_REG(3) | (((u8)nr14 & 7) << 8);
        D_800FCF60.unk_24 = ((0x800 - D_800FCF60.unk_04) * D_800FD004) >> 11;
        switch ((GB_REG(1) & 0xC0) >> 6) {
            case 0:
                D_800FCF60.unk_18[1] = D_800FCF60.unk_24 >> 3;
                if (D_800FCF60.unk_18[1] < 0x40) {
                    D_800FCF60.unk_18[1] = 0x40;
                }
                phase = 1;
                D_800FCF60.unk_18[0] = D_800FCF60.unk_24 - D_800FCF60.unk_18[1];
                goto duty_done;
            case 1:
                D_800FCF60.unk_18[1] = D_800FCF60.unk_24 >> 2;
                if (D_800FCF60.unk_18[1] < 0x40) {
                    D_800FCF60.unk_18[1] = 0x40;
                }
                phase = 0;
                D_800FCF60.unk_18[0] = D_800FCF60.unk_24 - D_800FCF60.unk_18[1];
                goto duty_done;
            case 2:
                D_800FCF60.unk_18[1] = D_800FCF60.unk_24 >> 1;
                if (D_800FCF60.unk_18[1] < 0x40) {
                    D_800FCF60.unk_18[1] = 0x40;
                }
                phase = 0;
                D_800FCF60.unk_18[0] = D_800FCF60.unk_24 - D_800FCF60.unk_18[1];
                goto duty_done;
            case 3:
                D_800FCF60.unk_18[0] = D_800FCF60.unk_24 >> 2;
                if (D_800FCF60.unk_18[0] < 0x40) {
                    D_800FCF60.unk_18[0] = 0x40;
                }
                phase = 1;
                D_800FCF60.unk_18[1] = D_800FCF60.unk_24 - D_800FCF60.unk_18[0];
                goto duty_done;
        }
        D_800FCF60.unk_18[1] = 0;
        phase = 1;
        D_800FCF60.unk_18[0] = D_800FCF60.unk_24;
    duty_done:

        if (!(GB_REG(2) & 8) && !(GB_REG(2) & 0xF0)) {
            D_800FCF60.unk_2C = 0;
            D_800FD008.unk_2C &= 0xFFFE;
            return 0;
        }
        if ((GB_REG(2) & 8) && !(GB_REG(2) & 0xF0) && !(GB_REG(2) & 7)) {
            D_800FCF60.unk_2C = 0;
            D_800FD008.unk_2C &= 0xFFFE;
            return 0;
        }

        if (nr14 & 0x80) {
            D_800FCF60.unk_00 = 0;
            D_800FCF60.unk_2C = 1;
            D_800FCF60.unk_1E = phase;
            D_800FCF60.unk_1C = 0;
            D_800FCF60.unk_20 = 0;
            D_800FCF60.unk_0C = (u8)(GB_REG(2) & 0xF0) << 7;
            if (GB_REG(2) & 7) {
                if (GB_REG(2) & 8) {
                    D_800FCF60.unk_0E = 0x800;
                } else {
                    D_800FCF60.unk_0E = -0x800;
                }
                D_800FCF60.unk_14 = D_800FCF60.unk_10 = (GB_REG(2) & 7) * D_800FD004;
            } else {
                D_800FCF60.unk_0E = 0;
                D_800FCF60.unk_10 = -1;
                D_800FCF60.unk_14 = -1;
            }
            D_800FCF60.unk_08 = (((GB_REG(0) & 0x70) >> 4) * D_800FD004) >> 1;
            if (D_800FCF60.unk_08 == 0) {
                D_800FCF60.unk_08 = -1;
            }
            if (nr14 & 0x40) {
                D_800FCF60.unk_28 = ((0x40 - (GB_REG(1) & 0x3F)) * D_800FD004) >> 2;
            } else {
                D_800FCF60.unk_28 = -1;
            }
            GB_REG(4) = nr14 & ~0x80;
        }
        if (D_800FCF60.unk_2C == 0) {
            return 0;
        }
    } else if (D_800FCF60.unk_2C == 0) {
        return 0;
    }

    if (D_800FCF60.unk_28 < D_800FCF60.unk_00) {
        D_800FCF60.unk_2C = 0;
        D_800FD008.unk_2C &= 0xFFFE;
        return 0;
    }

    if ((D_800FCF60.unk_08 - (D_800FCF60.unk_00 % D_800FCF60.unk_08)) <= 0x40) {
        if (!(GB_REG(0) & 8)) {
            freq = (D_800FCF60.unk_04 + (D_800FCF60.unk_04 >> (GB_REG(0) & 7)));
            if (freq >= 0x800) {
                D_800FCF60.unk_2C = 0;
                D_800FD008.unk_2C &= 0xFFFE;
                return 0;
            }
            D_800FCF60.unk_04 = freq;
        } else {
            freq = (D_800FCF60.unk_04 - (D_800FCF60.unk_04 >> (GB_REG(0) & 7)));
            if ((freq >= 0x800) || (freq < 0)) {
                goto skip;
            }
            D_800FCF60.unk_04 = freq;
        }
        D_800FCF60.unk_24 = ((0x800 - D_800FCF60.unk_04) * D_800FD004) >> 11;
        switch ((GB_REG(1) & 0xC0) >> 6) {
            case 0:
                D_800FCF60.unk_18[1] = D_800FCF60.unk_24 >> 3;
                if (D_800FCF60.unk_18[1] < 0x40) {
                    D_800FCF60.unk_18[1] = 0x40;
                }
                D_800FCF60.unk_18[0] = D_800FCF60.unk_24 - D_800FCF60.unk_18[1];
                break;
            case 1:
                D_800FCF60.unk_18[1] = D_800FCF60.unk_24 >> 2;
                if (D_800FCF60.unk_18[1] < 0x40) {
                    D_800FCF60.unk_18[1] = 0x40;
                }
                D_800FCF60.unk_18[0] = D_800FCF60.unk_24 - D_800FCF60.unk_18[1];
                break;
            case 2:
                D_800FCF60.unk_18[1] = D_800FCF60.unk_24 >> 1;
                if (D_800FCF60.unk_18[1] < 0x40) {
                    D_800FCF60.unk_18[1] = 0x40;
                }
                D_800FCF60.unk_18[0] = D_800FCF60.unk_24 - D_800FCF60.unk_18[1];
                break;
            case 3:
                D_800FCF60.unk_18[0] = D_800FCF60.unk_24 >> 2;
                if (D_800FCF60.unk_18[0] < 0x40) {
                    D_800FCF60.unk_18[0] = 0x40;
                }
                D_800FCF60.unk_18[1] = D_800FCF60.unk_24 - D_800FCF60.unk_18[0];
                break;
            default:
                D_800FCF60.unk_18[1] = 0;
                D_800FCF60.unk_18[0] = D_800FCF60.unk_24;
        }
    }
skip:

    if (D_800FCF60.unk_14 < D_800FCF60.unk_00) {
        D_800FCF60.unk_0C += D_800FCF60.unk_0E;
        D_800FCF60.unk_14 += D_800FCF60.unk_10;
    }
    while (D_800FCF60.unk_20 < D_800FCF60.unk_00) {
        D_800FCF60.unk_1E ^= 1;
        D_800FCF60.unk_20 += D_800FCF60.unk_18[D_800FCF60.unk_1E];
    }

    if (!(GB_REG(2) & 8) && (D_800FCF60.unk_0C < 0)) {
        D_800FCF60.unk_2C = 0;
        return 0;
    }
    if ((u16)D_800FCF60.unk_0C > 0x7800) {
        D_800FCF60.unk_0C = 0x7800;
        D_800FCF60.unk_0E = 0;
        D_800FCF60.unk_14 = -1;
    }
    out = D_800FCF60.unk_0C;
    if (D_800FCF60.unk_1E == 0) {
        out = -out;
    }
    D_800FCF60.unk_00 += 0x40;
    return out;
}

s16 func_8004A474(void) {
    s32 i;
    s32 changed;
    s32 nr24;
    u8 phase;
    s16 out;

    changed = 0;
    for (i = 6; i < 10; i++) {
        if (GB_REG_DIRTY(i) != 0) {
            changed = 1;
            GB_REG_DIRTY(i) = 0;
        }
    }

    if (changed) {
        nr24 = GB_REG(9);
        D_800FCF90.unk_1C = ((0x800 - (GB_REG(8) | (((u8)nr24 & 7) << 8))) * D_800FD004) >> 11;
        switch ((GB_REG(6) & 0xC0) >> 6) {
            case 0:
                D_800FCF90.unk_10[1] = D_800FCF90.unk_1C >> 3;
                if (D_800FCF90.unk_10[1] < 0x40) {
                    D_800FCF90.unk_10[1] = 0x40;
                }
                phase = 1;
                D_800FCF90.unk_10[0] = D_800FCF90.unk_1C - D_800FCF90.unk_10[1];
                goto duty_done;
            case 1:
                D_800FCF90.unk_10[1] = D_800FCF90.unk_1C >> 2;
                if (D_800FCF90.unk_10[1] < 0x40) {
                    D_800FCF90.unk_10[1] = 0x40;
                }
                phase = 0;
                D_800FCF90.unk_10[0] = D_800FCF90.unk_1C - D_800FCF90.unk_10[1];
                goto duty_done;
            case 2:
                D_800FCF90.unk_10[1] = D_800FCF90.unk_1C >> 1;
                if (D_800FCF90.unk_10[1] < 0x40) {
                    D_800FCF90.unk_10[1] = 0x40;
                }
                phase = 0;
                D_800FCF90.unk_10[0] = D_800FCF90.unk_1C - D_800FCF90.unk_10[1];
                goto duty_done;
            case 3:
                D_800FCF90.unk_10[0] = D_800FCF90.unk_1C >> 2;
                if (D_800FCF90.unk_10[0] < 0x40) {
                    D_800FCF90.unk_10[0] = 0x40;
                }
                phase = 1;
                D_800FCF90.unk_10[1] = D_800FCF90.unk_1C - D_800FCF90.unk_10[0];
                goto duty_done;
        }
        D_800FCF90.unk_10[1] = 0;
        phase = 1;
        D_800FCF90.unk_10[0] = D_800FCF90.unk_1C;
    duty_done:

        if (!(GB_REG(7) & 8) && !(GB_REG(7) & 0xF0)) {
            D_800FCF90.unk_24 = 0;
            D_800FD008.unk_2C &= 0xFFFD;
            return 0;
        }
        if ((GB_REG(7) & 8) && !(GB_REG(7) & 0xF0) && !(GB_REG(7) & 7)) {
            D_800FCF90.unk_24 = 0;
            D_800FD008.unk_2C &= 0xFFFD;
            return 0;
        }

        if (nr24 & 0x80) {
            D_800FCF90.unk_00 = 0;
            D_800FCF90.unk_24 = 1;
            D_800FCF90.unk_16 = phase;
            D_800FCF90.unk_14 = 0;
            D_800FCF90.unk_18 = 0;
            D_800FCF90.unk_04 = ((GB_REG(7) & 0xF0) << 3) << 4;
            if (GB_REG(7) & 7) {
                if (GB_REG(7) & 8) {
                    D_800FCF90.unk_06 = 0x800;
                } else {
                    D_800FCF90.unk_06 = -0x800;
                }
                D_800FCF90.unk_0C = D_800FCF90.unk_08 = (GB_REG(7) & 7) * D_800FD004;
            } else {
                D_800FCF90.unk_06 = 0;
                D_800FCF90.unk_08 = -1;
                D_800FCF90.unk_0C = -1;
            }
            if (nr24 & 0x40) {
                D_800FCF90.unk_20 = ((0x40 - (GB_REG(6) & 0x3F)) * D_800FD004) >> 2;
            } else {
                D_800FCF90.unk_20 = -1;
            }
            GB_REG(9) = nr24 & ~0x80;
        }
        if (D_800FCF90.unk_24 == 0) {
            return 0;
        }
    } else if (D_800FCF90.unk_24 == 0) {
        return 0;
    }

    if (D_800FCF90.unk_20 < D_800FCF90.unk_00) {
        D_800FCF90.unk_24 = 0;
        D_800FD008.unk_2C &= 0xFFFD;
        return 0;
    }

    if (D_800FCF90.unk_0C < D_800FCF90.unk_00) {
        D_800FCF90.unk_04 += D_800FCF90.unk_06;
        D_800FCF90.unk_0C += D_800FCF90.unk_08;
    }
    while (D_800FCF90.unk_18 <= D_800FCF90.unk_00) {
        D_800FCF90.unk_16 ^= 1;
        D_800FCF90.unk_18 += D_800FCF90.unk_10[D_800FCF90.unk_16];
    }

    if (!(GB_REG(7) & 8) && (D_800FCF90.unk_04 < 0)) {
        D_800FCF90.unk_24 = 0;
        return 0;
    }
    if ((u16)D_800FCF90.unk_04 > 0x7800) {
        D_800FCF90.unk_04 = 0x7800;
        D_800FCF90.unk_06 = 0;
        D_800FCF90.unk_0C = -1;
    }
    out = D_800FCF90.unk_04;
    if (D_800FCF90.unk_16 == 0) {
        out = -out;
    }
    D_800FCF90.unk_00 += 0x40;
    return out;
}

s16 func_8004A89C(void) {
    s32 i;
    s32 nr43;
    s32 row;
    s32 changed;
    u32 nr44;
    u16 col;
    GbNoiseEntry* entry;
    u8 sampleId;
    f32 vol;
    s16 sample;
    unk_D_800FC6CC* ent;

    changed = 0;
    for (i = 0x10; i < 0x14; i++) {
        if (GB_REG_DIRTY(i) != 0) {
            changed = 1;
            GB_REG_DIRTY(i) = 0;
        }
    }

    if (changed) {
        nr43 = GB_REG(0x12);
        row = nr43 & 7;
        col = (GB_REG(0x12) & 0xF0) >> 4;
        entry = &GB_NOISE_TABLE[row][col];
        sampleId = entry->sampleId;
        if (sampleId == 0xFF) {
            D_800FCFD8.unk_28 = 0;
            return 0;
        }
        if (GB_REG(0x12) & 8) {
            sampleId += 0x10;
        }
        D_800FCFD8.unk_0C = GB_NOISE_TABLE[nr43 & 7][col].pitchStep;
        if (sampleId != D_800FCFD8.unk_04) {
            D_800FCFD8.unk_04 = sampleId;
            ent = (unk_D_800FC6CC*)((u32*)D_800FC6CC + (D_800FCFD8.unk_04 << 1));
            Rom_DmaRead(ent->unk_00, (u32)D_800FC6D0, ent->unk_04);
        }

        D_800FCFD8.unk_08 = 0;
        D_800FCFD8.unk_10 = 0;
        if (!(GB_REG(0x11) & 8) && !(GB_REG(0x11) & 0xF0)) {
            D_800FCFD8.unk_28 = 0;
            D_800FD008.unk_2C &= 0xFFF7;
            return 0;
        }
        if ((GB_REG(0x11) & 8) && !(GB_REG(0x11) & 0xF0) && !(GB_REG(0x11) & 7)) {
            D_800FCFD8.unk_28 = 0;
            D_800FD008.unk_2C &= 0xFFF7;
            return 0;
        }

        nr44 = GB_REG(0x13);
        if (nr44 & 0x80) {
            vol = D_8007D4D0;
            D_800FCFD8.unk_00 = 0;
            D_800FCFD8.unk_28 = 1;
            D_800FCFD8.unk_14 = (u8)(GB_REG(0x11) & 0xF0) * vol;
            if (GB_REG(0x11) & 7) {
                if (GB_REG(0x11) & 8) {
                    D_800FCFD8.unk_18 = vol;
                } else {
                    D_800FCFD8.unk_18 = D_8007D4D4;
                }
                D_800FCFD8.unk_20 = D_800FCFD8.unk_1C = (GB_REG(0x11) & 7) * D_800FD004 * 4;
            } else {
                D_800FCFD8.unk_1C = -1;
                D_800FCFD8.unk_20 = -1;
                D_800FCFD8.unk_18 = 0.0f;
            }
            if (nr44 & 0x40) {
                D_800FCFD8.unk_24 = (0x40 - (GB_REG(0x10) & 0x3F)) * D_800FD004;
            } else {
                D_800FCFD8.unk_24 = -1;
            }
            GB_REG(0x13) = nr44 & 0xFF7F;
        }
        if (D_800FCFD8.unk_28 == 0) {
            return 0;
        }
    } else if (D_800FCFD8.unk_28 == 0) {
        return 0;
    }

    if (D_800FCFD8.unk_24 < D_800FCFD8.unk_00) {
        D_800FCFD8.unk_28 = 0;
        D_800FD008.unk_2C &= 0xFFF7;
        return 0;
    }

    if (D_800FCFD8.unk_20 < D_800FCFD8.unk_00) {
        D_800FCFD8.unk_20 += D_800FCFD8.unk_1C;
        D_800FCFD8.unk_14 += D_800FCFD8.unk_18;
    }

    ent = (unk_D_800FC6CC*)((u32*)D_800FC6CC + (D_800FCFD8.unk_04 << 1));
    if (1) {}
    sample = ((s16*)D_800FC6D0)[D_800FCFD8.unk_08];
    D_800FCFD8.unk_10 += 1.0f;
    if (D_800FCFD8.unk_0C <= D_800FCFD8.unk_10) {
        D_800FCFD8.unk_08++;
        D_800FCFD8.unk_10 -= D_800FCFD8.unk_0C;
        if (D_800FCFD8.unk_08 >= (ent->unk_04 >> 1)) {
            D_800FCFD8.unk_08 = 0;
        }
    }

    if (!(GB_REG(0x11) & 8) && (D_800FCFD8.unk_14 < 0.0f)) {
        D_800FCFD8.unk_28 = 0;
        return 0;
    }
    if (D_800FCFD8.unk_14 > 0.75f) {
        D_800FCFD8.unk_14 = 0.75f;
        D_800FCFD8.unk_18 = 0.0f;
        D_800FCFD8.unk_20 = -1;
    }
    sample = sample * D_800FCFD8.unk_14;
    D_800FCFD8.unk_00 += 0x100;
    return sample;
}

void GbAudio_ClearInterpolationHistory(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800FD6F8); i++) {
        D_800FD6F8[i] = 0;
    }
    D_800FF978 = 0;
}

void GbAudio_ClearOutputBuffer(void) {
    s32 i;

    for (i = 0; i < 0xB80; i++) {
        D_800FC6D8[i] = 0;
    }
    D_800FD6F0 = 0;
    D_800FD6F4 = 0;
}

void func_8004AD2C(void) {

}
