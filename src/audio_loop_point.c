#include "audio_loop_point.h"
#include "src/libnumus/player.h"
#include "src/audio_channel.h"
#include "src/audio_commands_category2.h"
#include "src/rom_device.h"
#include "src/audio_stream.h"
#include "src/audio_cache.h"
#include "src/3D140.h"
#include "src/audio_commands.h"

static s32 D_800FF9B0;
static s32 D_800FF9B4;

extern u8 D_80078E83;
extern u8 D_80078E8B;
extern u8 D_80078E93;
extern u8 D_80078E9B;
extern u8 D_80078EA3;
extern u8 D_80078EAB;
extern u8 D_80078EB3;
extern u8 D_80078EBC;
extern u8 D_80078EBF;

void Audio_SetMusicLoopPoint(s32 arg0) {
    D_80078EC8 = arg0;
}

s32 Audio_StartMusicTrack(s32 arg0) {
    u32 sp2C;
    s32 var_a2;
    UNUSED s32 pad;
    s32 sp20;
    s32 sp1C;

    sp20 = arg0;
    sp1C = 0x80;
    AudioStream_SetEnabled(1);
    Audio_SetVoiceStartTimingMode(1);
    D_800FF9B4 = arg0;
    if (arg0 == 0x50) {
        D_80078E78 = 0;
        D_80078E7C = 0;
        if (D_80078ED0 == 1) {
            Audio_StartVolumeTransition(D_80078ECC, 0, 0x80, 0x50);
            D_80078ED0 = 2;
            return 0;
        }
        Audio_StopAllSoundEffects();
        D_80078E70 = 0;
        Audio_QueueFadeSoundCommand(D_80078ECC, 1);
        D_80078ED0 = 0;
        D_80078ECC = Audio_PlayDirectSoundCommand(0x01000003, 0, 0);
        arg0 = 0x28;
        D_80078ED0 = 2;
    } else if (arg0 == 0x28) {
        D_80078E78 = 0;
        if (D_80078ED0 == 2) {
            Audio_StartVolumeTransition(D_80078ECC, 0x80, 0, 0x50);
            D_80078ED0 = 1;
            return 0;
        }
        Audio_StopAllSoundEffects();
        D_80078E70 = 0;
        Audio_QueueFadeSoundCommand(D_80078ECC, 1);
        D_80078ED0 = 0;
        D_80078ECC = Audio_PlayDirectSoundCommand(0x01000003, 0, 0);
        Audio_QueueVoiceVolumeScale(D_80078ECC, 0);
        D_80078ED0 = 1;
    } else {
        Audio_StopAllSoundEffects();
        D_80078E70 = 0;
        Audio_QueueFadeSoundCommand(D_80078ECC, 1);
        D_80078ED0 = 0;
    }

    if (arg0 == 0x32) {
        if ((D_80078404 < 0xC) && (D_80078390[0] > 0) && (D_80078390[1] == 0) && (D_80078408 == 8)) {
            arg0 = 0x3C;
        } else if ((D_80078404 == 0xD) && (D_80078390[0] > 0) && (D_80078390[1] == 0) && (D_80078408 == 5)) {
            arg0 = 0x3E;
            D_800FF9B4 = 0x3E;
        } else if ((D_80078404 == 0xF) && (D_80078390[0] > 0) && (D_80078390[1] == 0)) {
            arg0 = 0x40;
        }
    }

    if ((arg0 == 0x3F) && (D_80078404 == 0xD) && (D_80078408 == 5)) {
        arg0 = 0x41;
    }

    if ((arg0 == 0x31) && (D_80078E78 != 0)) {
        arg0 = 0x46;
    }

    if ((arg0 == 0x3A) && (D_80078E7C != 0)) {
        arg0 = 0x48;
    }

    sp2C = arg0;
    switch (arg0) {
        case 0x0:
            D_80078E78 = 0;
            D_80078E7C = 0;
            D_80078E80 = 1;
            sp20 = 0x98;
            break;

        case 0x1:
            sp20 = 0x68;
            D_80078E80 = 1;
            Audio_SelectModeMusic(0, 0xF);
            break;

        case 0x9:
            sp20 = 0x50;
            break;

        case 0x7:
            sp20 = 0x78;
            break;

        case 0x8:
            sp20 = 0xA0;
            break;

        case 0xF:
            sp20 = 0x60;
            break;

        case 0xA:
            sp20 = 0x60;
            break;

        case 0x11:
            sp20 = 0x60;
            break;

        case 0x17:
            sp20 = 0x60;
            break;

        case 0x18:
            sp20 = 0x60;
            break;

        case 0x19:
            sp20 = 0x58;
            break;

        case 0x1C:
            sp20 = 0x60;
            break;

        case 0x1D:
            sp20 = D_80078E74;
            break;

        case 0x1E:
            sp20 = 0x65;
            break;

        case 0x1F:
            sp20 = 0x70;
            break;

        case 0x20:
            sp20 = 0x70;
            break;

        case 0x21:
            sp20 = 0x50;
            break;

        case 0x1A:
            sp20 = 0x60;
            Audio_ResetVolumeTransition();
            break;

        case 0x1B:
            sp20 = 0x58;
            Audio_ResetVolumeTransition();
            break;

        case 0x2C:
            sp20 = 0x70;
            break;

        case 0x13:
            sp20 = 0x68;
            break;

        case 0x38:
            sp20 = 0x60;
            break;

        case 0x15:
            sp20 = 0x60;
            break;

        case 0x2D:
            sp20 = 0x60;
            break;

        case 0x16:
            sp20 = 0x60;
            break;

        case 0x10:
            sp20 = 0x68;
            break;

        case 0x2A:
            sp20 = 0x60;
            break;

        case 0x27:
            sp20 = 0x58;
            break;

        case 0x2B:
            sp20 = 0x60;
            break;

        case 0x30:
            D_80078E78 = 1;
            sp20 = 0x64;
            break;

        case 0x28:
            D_80078E78 = 0;
            D_80078E7C = 0;
            sp20 = 0x48;
            break;

        case 0x29:
            D_80078E78 = 0;
            D_80078E7C = 0;
            sp20 = 0x78;
            sp1C = 0x87;
            break;

        case 0x31:
            sp20 = 0x60;
            break;

        case 0x33:
            sp20 = 0x60;
            break;

        case 0x46:
            sp20 = 0x60;
            break;

        case 0x32:
            sp20 = 0x60;
            break;

        case 0x3C:
            sp20 = 0x60;
            break;

        case 0x3D:
            sp20 = 0x88;
            break;

        case 0x3E:
            sp20 = 0x60;
            break;

        case 0x3F:
            sp20 = 0x60;
            break;

        case 0x40:
            sp20 = 0x50;
            break;

        case 0x41:
            sp20 = 0x60;
            break;

        case 0x45:
            sp20 = 0x60;
            break;

        case 0x44:
            sp20 = 0x90;
            break;

        case 0x47:
            sp20 = 0x88;
            D_80078E7C = 1;
            break;

        case 0x5B:
            sp20 = 0x78;
            sp2C = 1;
            break;

        case 0x3A:
            sp20 = 0x68;
            Audio_SelectModeMusic(0, 0xF);
            Audio_PlayCategory11SoundCommand(0x01100016, 0, 0);
            break;

        case 0x48:
            Audio_SelectModeMusic(0, 0xF);
            Audio_PlayCategory11SoundCommand(0x01100016, 0, 0);
            sp20 = 0x70;
            break;

        case 0x49:
            sp20 = 0x68;
            break;

        case 0x4A:
            sp20 = 0xA8;
            break;

        case 0x4B:
            sp20 = 0x60;
            break;

        case 0x42:
            D_80078E78 = 0;
            D_80078E7C = 0;
            sp20 = 0x80;
            break;

        case 0x43:
            D_80078E78 = 0;
            D_80078E7C = 0;
            sp20 = 0x80;
            break;

        case 0x22:
            sp20 = 0x48;
            break;

        case 0x24:
            sp20 = 0x48;
            break;

        case 0x26:
            sp20 = 0x40;
            break;

        case 0x23:
            sp20 = 0x50;
            break;

        case 0x25:
            sp20 = 0x50;
            break;

        case 0xE:
            sp20 = 0x64;
            break;

        case 0xD:
            sp20 = 0x48;
            break;

        case 0xB:
            sp20 = 0x38;
            break;

        case 0xC:
            sp20 = 0x38;
            break;

        case 0x12:
            sp20 = 0x2E;
            break;

        case 0x36:
            sp20 = 0x38;
            break;

        case 0x6:
            sp20 = 0x38;
            break;

        case 0x37:
            sp20 = 0x38;
            break;

        case 0x3B:
            sp20 = 0x3C;
            break;

        case 0x39:
            sp20 = 0x38;
            break;

        case 0x34:
            sp20 = 0x60;
            break;

        case 0x2F:
            sp20 = 0x58;
            break;

        case 0x2E:
            sp20 = 0x54;
            break;

        case 0x35:
            sp20 = 0x54;
            break;

        case 0x14:
            sp20 = 0x58;
            break;

        case 0x2:
            sp20 = 0x34;
            break;

        case 0x3:
            sp20 = 0x44;
            break;

        case 0x4:
            sp20 = 0x38;
            break;

        case 0x5:
            sp20 = 0x34;
            break;

        case 0x5A:
            sp20 = 0x50;
            D_80078E80 = 0;
            sp2C = 2;
            break;

        default:
            return 0;
    }

    if (sp2C < D_800FC6E4->num_files - 1) {
        var_a2 = D_800FC6E4->files[sp2C + 1] - D_800FC6E4->files[sp2C];
    } else if (sp2C == D_800FC6E4->num_files - 1) {
        var_a2 = gAudioRegions[2] - D_800FC6E4->files[sp2C];
    } else {
        return 0;
    }

    Rom_DmaRead(D_800FC6E4->files[sp2C], D_800FC6DC, var_a2);
    Audio_CopyDataWithCacheSync(D_800FC6DC, D_800FC680, 0x98D8);

    if (D_80078EC8 <= 0) {
        D_80078E70 = Audio_PlayMusicSequence(D_800FC684, D_800FC680);
    } else {
        D_80078E70 = Audio_PlayMusicSequenceLooped(D_800FC684, D_800FC680, D_80078EC8 ^ 0);
    }

    D_80078EC8 = -1;
    Audio_QueueVoiceVolumeScale(D_80078E70, sp20);

    if (sp1C != 0x80) {
        Audio_QueueVoiceVolume(D_80078E70, sp1C);
    }

    if (arg0 == 0x1D) {
        D_800FF9B0 = D_80078E70;
    }

    return D_80078E70;
}

void Audio_FadeOutAll(s32 arg0) {
    s32 i;

    if (arg0 == 0) {
        arg0 = 1;
    }

    Audio_QueueFadeSoundCommand(D_80078E70, arg0);
    D_80078EC8 = -1;
    Audio_QueueFadeSoundCommand(D_80078ECC, arg0);
    D_80078ED0 = 0;
    D_8007840C = 0;
    Audio_QueueFadeSoundCommand(D_80078FA8, arg0);
    AudioStream_SetEnabled(0);
    AudioFrameUpdate(0);

    if (D_800FF9B4 != 0x50) {
        for (i = 0; i < 2; i++) {
            AudioStream_Stop(i, arg0);
        }
    }
}

s32 Audio_StartTrackForCategory(s32 arg0, s32 arg1) {
    s32 ret;
    D_80078E80 = 0;
    if ((arg0 == 0) || (arg0 == 0xFF)) {
        arg0 = 1;
        if ((arg1 == 0xE)) {    
            return Audio_StartMusicTrack(2U);
        }
    }
    switch (arg1) {
    case 10:
    case 11:
        if (arg0 >= 9U) {
            return 0;
        }
        ret = Audio_StartMusicTrack(*(&D_80078E83 + arg0));
        break;
    case 6:
    case 7:
    case 8:
        if (arg0 >= 9U) {
            return 0;
        }
        ret = Audio_StartMusicTrack(*(&D_80078E8B + arg0));
        break;
    case 9:
        if (arg0 >= 9U) {
            return 0;
        }
        ret = Audio_StartMusicTrack(*(&D_80078E93 + arg0));
        break;
    case 5:
        if (arg0 >= 9U) {
            return 0;
        }
        ret = Audio_StartMusicTrack(*(&D_80078E9B + arg0));
        break;
    case 4:
        if (arg0 >= 9U) {
            return 0;
        }
        ret = Audio_StartMusicTrack(*(&D_80078EA3 + arg0));
        break;
    case 0:
    case 1:
    case 2:
        if (arg0 >= 9U) {
            return 0;
        }
        ret = Audio_StartMusicTrack(*(&D_80078EAB + arg0));
        break;
    case 3:
        if (arg0 >= 9U) {
            return 0;
        }
        ret = Audio_StartMusicTrack(*(&D_80078EB3 + arg0));
        break;
    case 12:
        if (arg0 >= 0x21U) {
            return 0;
        }
        ret = Audio_StartMusicTrack(*(&D_80078EBC + ((arg0 - 1) & 3)));
        break;
    case 13:
        if (arg0 >= 6U) {
            return 0;
        }
        ret = Audio_StartMusicTrack(*(&D_80078EBF + arg0));
        break;
    case 15:
        ret = Audio_StartMusicTrack(0x14U);
        break;
    default:
        ret = Audio_StartMusicTrack(2U);
    }
    return ret;
}

s32 Audio_UpdateSpecialSequence(s32 arg0, u32 arg1) {
    s32 var_a3;

    switch (arg0) {
        case 30:
            switch (D_80078ED4) {
                case 0:
                    D_80078ED4 = 1;
                    return Audio_StartMusicTrack(0x1E);

                case 1:
                    return 0;

                case 2:
                    return 0;

                case 3:
                    if (Audio_IsSoundPlaying(D_80078EDC) == 0) {
                        D_80078ED4 = 1;
                        if (arg1 == 0) {
                            return Audio_StartMusicTrack(0x1E);
                        }
                        return 0;
                    }
                    return 0;
            }
            return 0;

        case 31:
            D_80078ED4 = 2;
            switch (arg1) {
                case 0:
                    var_a3 = (arg1 * 0x48) + 0xD6;
                    break;

                case 1:
                    var_a3 = (arg1 * 0x48) + 0xD6;
                    break;

                case 2:
                    var_a3 = (arg1 * 0x48) + 0xD6;
                    break;

                case 3:
                    var_a3 = (arg1 * 0x48) + 0xD6;
                    break;

                case 4:
                    var_a3 = (arg1 * 0x48) + 0xD6;
                    break;

                default:
                    var_a3 = 0xD6;
                    break;
            }

            switch (arg1) {
                case 0:
                    Audio_DispatchSoundBankCommand(0x9000D, 0, 0);
                    break;

                case 1:
                    Audio_DispatchSoundBankCommand(0x9000E, 0, 0);
                    break;

                case 2:
                    Audio_DispatchSoundBankCommand(0x9000F, 0, 0);
                    break;

                case 3:
                    Audio_DispatchSoundBankCommand(0x90010, 0, 0);
                    break;

                case 4:
                    Audio_DispatchSoundBankCommand(0x90011, 0, 0);
                    break;
            }

            Audio_SetMusicLoopPoint(var_a3);
            D_80078ED8 = Audio_StartMusicTrack(0x1F);
            return D_80078ED8;

        case 32:
            switch (D_80078ED4) {
                case 0:
                    return 0;

                case 1:
                    return 0;

                case 2:
                    if (Audio_IsSoundPlaying(D_80078ED8) == 0) {
                        if (arg1 == 0) {
                            D_80078ED4 = 3;
                            D_80078EDC = 0;
                        } else {
                            Audio_SetMusicLoopPoint(0x46);
                            D_80078ED4 = 3;
                            D_80078EDC = Audio_StartMusicTrack(0x20);
                            return D_80078EDC;
                        }
                    }
                    return 0;

                case 3:
                    return 0;
            }
            return 0;
    }
}

u32 Audio_GetSpecialSequenceState(void) {
    return D_80078ED4;
}
