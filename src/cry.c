#include "cry.h"
#include "src/audio_commands.h"
#include "src/audio_stream.h"
#include "src/rom_device.h"
#include "src/3D140.h"

extern u8 D_80078400;

typedef struct unk_D_80079070 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
} unk_D_80079070; // size = 0x5

static unk_D_80079070 D_80079070[151] = {
    {
        0x01,
        0x01,
        0x00,
        0x52,
        0x04,
    },
    {
        0x01,
        0x01,
        0x00,
        0x58,
        0x36,
    },
    {
        0x02,
        0x02,
        0x00,
        0x1A,
        0x3C,
    },
    {
        0x01,
        0x01,
        0x00,
        0x00,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x54,
        0x3C,
    },
    {
        0x02,
        0x02,
        0x01,
        0x2E,
        0x0A,
    },
    {
        0x01,
        0x01,
        0x00,
        0x5C,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x44,
        0x52,
    },
    {
        0x02,
        0x02,
        0x00,
        0x22,
        0x36,
    },
    {
        0x01,
        0x01,
        0x00,
        0x98,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x32,
        0xA4,
    },
    {
        0x01,
        0x01,
        0x00,
        0x00,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x32,
        0x9E,
    },
    {
        0x01,
        0x01,
        0x00,
        0x0C,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x12,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x8C,
        0x24,
    },
    {
        0x01,
        0x01,
        0x00,
        0x8C,
        0x24,
    },
    {
        0x02,
        0x01,
        0x00,
        0x8C,
        0x24,
    },
    {
        0x01,
        0x01,
        0x00,
        0x54,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x50,
        0x34,
    },
    {
        0x00,
        0x01,
        0x00,
        0x3C,
        0x00,
    },
    {
        0x09,
        0x01,
        0x00,
        0x28,
        0x10,
    },
    {
        0x02,
        0x01,
        0x00,
        0x76,
        0x94,
    },
    {
        0x02,
        0x02,
        0x00,
        0x72,
        0x3C,
    },
    {
        0x01,
        0x00,
        0x00,
        0x4E,
        0x3C,
    },
    {
        0x01,
        0x01,
        0x00,
        0x7E,
        0x72,
    },
    {
        0x01,
        0x01,
        0x00,
        0x00,
        0x7E,
    },
    {
        0x01,
        0x01,
        0x00,
        0x3C,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x34,
        0x16,
    },
    {
        0x01,
        0x01,
        0x00,
        0x3C,
        0x5A,
    },
    {
        0x02,
        0x02,
        0x00,
        0x00,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x08,
        0x0A,
    },
    {
        0x01,
        0x01,
        0x00,
        0x6E,
        0x64,
    },
    {
        0x02,
        0x02,
        0x00,
        0x40,
        0x00,
    },
    {
        0x01,
        0x00,
        0x00,
        0x54,
        0x7E,
    },
    {
        0x01,
        0x00,
        0x00,
        0x2C,
        0x66,
    },
    {
        0x01,
        0x00,
        0x00,
        0x72,
        0x98,
    },
    {
        0x01,
        0x01,
        0x00,
        0x2A,
        0x78,
    },
    {
        0x09,
        0x00,
        0x00,
        0x92,
        0x2C,
    },
    {
        0x01,
        0x01,
        0x00,
        0x52,
        0x3C,
    },
    {
        0x01,
        0x01,
        0x00,
        0x46,
        0x00,
    },
    {
        0x02,
        0x02,
        0x00,
        0x54,
        0x4A,
    },
    {
        0x00,
        0x00,
        0x00,
        0x38,
        0x1E,
    },
    {
        0x01,
        0x01,
        0x00,
        0x00,
        0x38,
    },
    {
        0x09,
        0x01,
        0x00,
        0x50,
        0x7E,
    },
    {
        0x01,
        0x01,
        0x00,
        0x6E,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x8E,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x38,
        0xBA,
    },
    {
        0x02,
        0x01,
        0x00,
        0x3A,
        0x36,
    },
    {
        0x00,
        0x00,
        0x00,
        0x3C,
        0x5E,
    },
    {
        0x00,
        0x01,
        0x00,
        0x3C,
        0x54,
    },
    {
        0x01,
        0x01,
        0x00,
        0x24,
        0x88,
    },
    {
        0x02,
        0x01,
        0x00,
        0x5A,
        0x08,
    },
    {
        0x01,
        0x01,
        0x00,
        0x5A,
        0x00,
    },
    {
        0x02,
        0x01,
        0x00,
        0x38,
        0x64,
    },
    {
        0x01,
        0x01,
        0x00,
        0x64,
        0x54,
    },
    {
        0x01,
        0x01,
        0x00,
        0x00,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x42,
        0x18,
    },
    {
        0x02,
        0x01,
        0x00,
        0x6A,
        0x16,
    },
    {
        0x01,
        0x00,
        0x00,
        0x32,
        0x60,
    },
    {
        0x01,
        0x01,
        0x00,
        0xA4,
        0x42,
    },
    {
        0x02,
        0x01,
        0x00,
        0x38,
        0x86,
    },
    {
        0x01,
        0x01,
        0x00,
        0xCC,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x5A,
        0x6C,
    },
    {
        0x02,
        0x01,
        0x00,
        0x46,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x14,
        0xAE,
    },
    {
        0x02,
        0x01,
        0x00,
        0x64,
        0x32,
    },
    {
        0x02,
        0x02,
        0x00,
        0x6C,
        0xB0,
    },
    {
        0x00,
        0x01,
        0x00,
        0x28,
        0x92,
    },
    {
        0x01,
        0x01,
        0x00,
        0x24,
        0x34,
    },
    {
        0x02,
        0x01,
        0x00,
        0x16,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x30,
        0x9E,
    },
    {
        0x02,
        0x02,
        0x00,
        0x20,
        0x00,
    },
    {
        0x02,
        0x01,
        0x00,
        0x7A,
        0x7C,
    },
    {
        0x02,
        0x02,
        0x00,
        0x00,
        0x0C,
    },
    {
        0x02,
        0x02,
        0x00,
        0x3C,
        0x2E,
    },
    {
        0x01,
        0x00,
        0x00,
        0x00,
        0x00,
    },
    {
        0x02,
        0x01,
        0x00,
        0x28,
        0x10,
    },
    {
        0x02,
        0x01,
        0x00,
        0x00,
        0x98,
    },
    {
        0x02,
        0x01,
        0x00,
        0x00,
        0x80,
    },
    {
        0x01,
        0x01,
        0x00,
        0x6A,
        0x1A,
    },
    {
        0x01,
        0x01,
        0x00,
        0x00,
        0x1A,
    },
    {
        0x01,
        0x01,
        0x00,
        0x64,
        0x0C,
    },
    {
        0x01,
        0x01,
        0x00,
        0x00,
        0x00,
    },
    {
        0x02,
        0x01,
        0x00,
        0x28,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x54,
        0x72,
    },
    {
        0x02,
        0x01,
        0x00,
        0x6A,
        0x00,
    },
    {
        0x09,
        0x02,
        0x00,
        0x44,
        0x00,
    },
    {
        0x09,
        0x02,
        0x00,
        0x40,
        0x2A,
    },
    {
        0x01,
        0x01,
        0x00,
        0x7E,
        0x00,
    },
    {
        0x02,
        0x02,
        0x00,
        0x00,
        0x7C,
    },
    {
        0x00,
        0x01,
        0x00,
        0x3E,
        0x2E,
    },
    {
        0x00,
        0x02,
        0x00,
        0x32,
        0x33,
    },
    {
        0x00,
        0x02,
        0x00,
        0x38,
        0x32,
    },
    {
        0x02,
        0x02,
        0x00,
        0x30,
        0x3A,
    },
    {
        0x01,
        0x01,
        0x00,
        0x34,
        0x00,
    },
    {
        0x02,
        0x01,
        0x00,
        0x00,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x58,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x46,
        0x00,
    },
    {
        0x09,
        0x01,
        0x00,
        0x00,
        0x00,
    },
    {
        0x09,
        0x01,
        0x00,
        0x28,
        0x36,
    },
    {
        0x01,
        0x01,
        0x00,
        0x44,
        0x2A,
    },
    {
        0x02,
        0x01,
        0x00,
        0x60,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0xB4,
        0x36,
    },
    {
        0x01,
        0x01,
        0x00,
        0x14,
        0x00,
    },
    {
        0x02,
        0x01,
        0x00,
        0x10,
        0x72,
    },
    {
        0x02,
        0x01,
        0x00,
        0x40,
        0xB6,
    },
    {
        0x02,
        0x01,
        0x00,
        0x3E,
        0x2C,
    },
    {
        0x01,
        0x01,
        0x00,
        0x50,
        0x78,
    },
    {
        0x02,
        0x02,
        0x00,
        0x20,
        0x3C,
    },
    {
        0x02,
        0x01,
        0x00,
        0x4C,
        0x3C,
    },
    {
        0x02,
        0x02,
        0x00,
        0x36,
        0x0C,
    },
    {
        0x01,
        0x00,
        0x00,
        0x1E,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x00,
        0x51,
    },
    {
        0x02,
        0x01,
        0x00,
        0x8C,
        0x22,
    },
    {
        0x00,
        0x00,
        0x00,
        0x5C,
        0x6E,
    },
    {
        0x01,
        0x01,
        0x00,
        0x5A,
        0x6E,
    },
    {
        0x01,
        0x00,
        0x00,
        0x7C,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x00,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x28,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x1A,
        0x64,
    },
    {
        0x01,
        0x01,
        0x00,
        0x62,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x14,
        0x1A,
    },
    {
        0x09,
        0x01,
        0x00,
        0x4A,
        0x00,
    },
    {
        0x02,
        0x01,
        0x00,
        0x0A,
        0x5E,
    },
    {
        0x02,
        0x02,
        0x00,
        0x2E,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x14,
        0x00,
    },
    {
        0x02,
        0x02,
        0x00,
        0x8C,
        0x62,
    },
    {
        0x00,
        0x01,
        0x00,
        0x00,
        0x64,
    },
    {
        0x02,
        0x02,
        0x00,
        0x8C,
        0x1E,
    },
    {
        0x02,
        0x01,
        0x00,
        0x28,
        0x82,
    },
    {
        0x09,
        0x00,
        0x00,
        0x00,
        0x00,
    },
    {
        0x01,
        0x00,
        0x00,
        0x00,
        0x3C,
    },
    {
        0x01,
        0x00,
        0x00,
        0x00,
        0x06,
    },
    {
        0x01,
        0x00,
        0x00,
        0x40,
        0x0C,
    },
    {
        0x01,
        0x00,
        0x00,
        0x18,
        0x8E,
    },
    {
        0x01,
        0x01,
        0x00,
        0x3C,
        0x0E,
    },
    {
        0x01,
        0x01,
        0x00,
        0x00,
        0x00,
    },
    {
        0x01,
        0x01,
        0x00,
        0x00,
        0x34,
    },
    {
        0x01,
        0x01,
        0x00,
        0x32,
        0x12,
    },
    {
        0x01,
        0x01,
        0x00,
        0x50,
        0x42,
    },
    {
        0x09,
        0x02,
        0x00,
        0x28,
        0x00,
    },
    {
        0x02,
        0x01,
        0x00,
        0x3C,
        0x82,
    },
    {
        0x02,
        0x01,
        0x00,
        0x32,
        0x2A,
    },
    {
        0x02,
        0x01,
        0x00,
        0x38,
        0x2E,
    },
    {
        0x02,
        0x01,
        0x00,
        0x1E,
        0x2A,
    },
    {
        0x02,
        0x00,
        0x00,
        0x23,
        0x18,
    },
    {
        0x02,
        0x01,
        0x00,
        0x28,
        0x00,
    },
    {
        0x02,
        0x01,
        0x00,
        0x6C,
        0x00,
    },
    {
        0x02,
        0x01,
        0x00,
        0x64,
        0x0A,
    },
    {
        0x00,
        0x00,
        0x00,
        0x82,
        0x00,
    },
};

u8 D_80079364 = 0;

void Cry_Play(u32 species, u32 cry_mode) {
    UNUSED s32 pad[2];
    u32 sp24;
    u32 var_a3;
    u8 is_partner_pikachu;

    var_a3 = 0;
    is_partner_pikachu = 0;
    if (species == 0xC8) {
        is_partner_pikachu = 1;
    } else if (((species == 0) || (species >= 0x98)) && (cry_mode != 0xA)) {
        return;
    }

    if (D_80079364 == 1) {
        Rom_DmaRead(D_800FC704->seqArray[0].offset, D_800FC708, 0x4BC);
        alSeqFileNew(D_800FC708, D_800FC704->seqArray[0].offset);
        D_80079364 = 0;
    }

    switch (cry_mode) {
        case 0:
            if (is_partner_pikachu != 0) {
                species = 0x9D;
            }
            sp24 = 0x70;
            break;

        case 7:
            if (is_partner_pikachu != 0) {
                species = 0x9D;
            }
            sp24 = 0x10;
            var_a3 = 0xA;
            break;

        case 8:
            if (is_partner_pikachu != 0) {
                species = 0x9D;
            }
            sp24 = 0x50;
            var_a3 = 0x14;
            break;

        case 2:
            if (is_partner_pikachu != 0) {
                species = 0x9D;
                var_a3 = 0x3C;
            } else {
                var_a3 = D_80079070[species - 1].unk_03;
            }
            sp24 = 0x30;
            break;

        case 3:
            if (is_partner_pikachu != 0) {
                species = 0x9D;
                var_a3 = 0x3C;
            } else {
                var_a3 = D_80079070[species - 1].unk_03;
            }
            sp24 = 0x60;
            Audio_PlayCommand(0x15, D_80078400, 0);
            break;

        case 4:
            if (is_partner_pikachu != 0) {
                species = 0x9C;
                var_a3 = 0x32;
            } else {
                var_a3 = D_80079070[species - 1].unk_03;
            }
            sp24 = 0x70;
            Audio_PlayCommand(0x15, D_80078400, 0);
            break;

        case 5:
            if ((is_partner_pikachu != 0) && ((D_800FCB18[0] == NULL) || (D_800FCB18[1] == NULL) ||
                                  (((D_800FCB18[0]->unk_15 & 7) == 0) && ((D_800FCB18[1]->unk_15 & 7) == 0) &&
                                   !(D_800FCB18[0]->unk_15 & 0x20) && !(D_800FCB18[1]->unk_15 & 0x20)))) {
                species = 0x9A;
                sp24 = 0x70;
            } else {
                return;
            }
            break;

        case 6:
            if ((is_partner_pikachu != 0) && (((D_800FCB18[0] == NULL) || (D_800FCB18[1] == NULL)) ||
                                  (!(D_800FCB18[0]->unk_15 & 7) && !(D_800FCB18[1]->unk_15 & 7) &&
                                   !(D_800FCB18[0]->unk_15 & 0x20) && !(D_800FCB18[1]->unk_15 & 0x20)))) {
                species = 0x9B;
                sp24 = 0x70;
            } else {
                return;
            }
            break;

        case 1:
            if (is_partner_pikachu != 0) {
                species = 0x98;
                sp24 = 0x70;
            } else {
                sp24 = 0x60;
                var_a3 = D_80079070[species - 1].unk_04;
            }
            break;

        case 10:
            sp24 = 0x70;
            switch (species) {
                case 0x9C:
                    var_a3 = 0x32;
                    break;

                case 0x9D:
                    var_a3 = 0x3C;
                    break;

                case 0x9F:
                    var_a3 = 0x14;
                    break;

                case 0xA0:
                    var_a3 = 6;
                    break;

                case 0xA3:
                    var_a3 = 0x2D;
                    break;

                case 0xA5:
                    var_a3 = 0x2A;
                    break;

                case 0x98:
                case 0x99:
                case 0x9A:
                case 0x9B:
                default:
                    var_a3 = 0x1E;
                    break;

                case 0x9E:
                case 0xA1:
                case 0xA2:
                case 0xA4:
                    break;
            }
            break;

        default:
            if (is_partner_pikachu != 0) {
                species = 0x9D;
            }
            sp24 = 0x60;
            break;
    }

    AudioStream_Start(0, D_800FC708->seqArray[species - 1].offset, sp24, var_a3);
}

void Cry_PlayVariant4(u32 arg0) {
    Cry_Play(arg0, 4);
}
