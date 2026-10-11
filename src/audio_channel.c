#include "audio_channel.h"
#include "src/audio_sfx.h"
#include "src/libnumus/player.h"
#include "src/3D140.h"

void Audio_SetChannelVolume(s32 arg0, u32 arg1) {
    s32 var_a1;

    switch (arg1) {
        case 0:
            var_a1 = 0;
            break;

        case 1:
            var_a1 = 0x3FFF;
            break;

        case 2:
            var_a1 = 0x4FFF;
            break;

        case 3:
            var_a1 = 0x5FFF;
            break;

        case 4:
            var_a1 = 0x6FFF;
            break;

        case 5:
            var_a1 = 0x7FFF;
            break;

        default:
            var_a1 = 0x6FFF;
            break;
    }

    if (arg0 & 1) {
        D_80078E64 = var_a1;
    }

    if (arg0 & 2) {
        D_80078E60 = var_a1;
    }

    Audio_QueueSetVolumeCommand(arg0, var_a1);
}

void Audio_SetMonoOutput(s32 arg0) {
    Audio_QueueSetMonoOutputCommand(arg0);
}

void Audio_SetPauseMixMode(u32 arg0) {
    switch (arg0) {
        case 1:
            Audio_QueueFadeSoundCommand(D_80078E68, 3);
            Audio_QueueSetVolumeCommand(2, D_80078E60 >> 1);
            Audio_QueueSetVolumeCommand(1, D_80078E64 / 3);
            D_80078E68 = Audio_PlaySoundEffectById(SFX_PAUSE);
            Audio_QueueVoiceVolumeScale(D_80078E68, 0xFF);
            break;

        case 0:
            Audio_QueueFadeSoundCommand(D_80078E68, 3);
            Audio_QueueSetVolumeCommand(2, D_80078E60);
            Audio_QueueSetVolumeCommand(1, D_80078E64);
            D_80078E68 = Audio_PlaySoundEffectById(SFX_RESUME);
            break;

        case 2:
            Audio_QueueVoiceVolumeScale(Audio_PlaySoundEffectById(SFX_MENU_SCROLL), 0xFF);
            break;

        case 3:
            Audio_QueueVoiceVolumeScale(Audio_PlaySoundEffectById(0x21), 0xFF);
            break;

        case 4:
            Audio_QueueFadeSoundCommand(D_80078E68, 3);
            Audio_QueueSetVolumeCommand(2, D_80078E60);
            Audio_QueueSetVolumeCommand(1, D_80078E64);
            break;
    }
}

void Audio_BeginVolumeTransition(u32 arg0) {
    u32 temp_v0;

    if (arg0 == 0) {
        arg0 = 1;
    }

    temp_v0 = osSetIntMask(1);

    D_80077DD4 = D_80078E60;
    D_80077DDC = D_80078E64;
    D_80077DD8 = D_80077DD4 / arg0;
    D_80077DE0 = D_80077DDC / arg0;
    mus_sound_effect_blocked = 1;

    osSetIntMask(temp_v0);
}

void Audio_ResetVolumeTransition(void) {
    u32 temp_v0 = osSetIntMask(1);

    mus_sound_effect_blocked = 0;
    D_80077DD4 = 0.0f;
    D_80077DDC = 0.0f;

    osSetIntMask(temp_v0);

    Audio_QueueSetVolumeCommand(2, D_80078E60);
    Audio_QueueSetVolumeCommand(1, D_80078E64);
}
