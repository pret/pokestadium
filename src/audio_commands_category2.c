#include "audio_commands_category2.h"
#include "src/libnumus/player.h"
#include "src/audio_sfx.h"
#include "src/rom_device.h"
#include "src/audio_loop_point.h"
#include "src/audio_cache.h"
#include "src/audio_commands.h"
#include "src/audio_category_fade.h"

static s32 D_80078EE0[4] = {
    0xFFFFFF9C,
    0xFFFFFFD8,
    0x00000028,
    0x00000064,
};
static s32 D_80078EF0[4] = {
    0xFFFFFFFD,
    0xFFFFFFFE,
    0xFFFFFFFE,
    0xFFFFFFFE,
};
static s32 D_80078F00[8] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

s32 Audio_PlayCategory2SoundCommand(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp34;
    UNUSED s32 pad[3];
    f32 var_fv0;
    s32 var_v0;

    var_fv0 = 0.0f;
    var_v0 = 0x80;

    if (arg0 == 0x2000A) {
        arg0 = 0x20001;
    }

    switch (arg0) {
        case 0x20003:
        case 0x20004:
        case 0x20005:
        case 0x20006:
        case 0x20007:
        case 0x20008:
            if ((arg1 <= 0) || (arg1 >= 5)) {
                arg1 = 1;
            }

            switch (arg2) {
                case 1:
                    break;

                case 2:
                    var_v0 = (arg1 * 0xAF) - 0x87;
                    break;

                case 3:
                    var_v0 = (arg1 * 0x66) - 0x4D;
                    break;

                case 4:
                    if (1) {}
                    var_v0 = (arg1 * 0x4E) - 0x44;
                    break;
            }

            if ((arg0 == 0x20004) || (arg0 == 0x20005) || (arg0 == 0x20006) || (arg0 == 0x20007)) {
                var_fv0 = (4 - arg1) * 0.5f;
            }
            break;
    }

    sp34 = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, arg0 & 0xFFFF, 0x80, var_v0, -1);
    Audio_QueueVoiceDetune(sp34, var_fv0);

    return sp34;
}

void Audio_StopCategory2SoundCommand(UNUSED s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2) {
}

s32 Audio_PlayCategory3SoundCommand(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp44;
    UNUSED s32 pad[2];
    u32 sp38;
    f32 var_fv0;
    s32 var_v0;

    var_v0 = 0x7F;
    sp38 = 0x80;
    var_fv0 = 0.0f;

    switch (arg0) {
        case 0x30003:
            sp38 = 0x50;
            if (arg2 >= 0) {
                if (Audio_IsSoundPlaying(D_80078F00[arg1]) == 0) {
                    var_fv0 += D_80078EF0[arg1];
                    var_v0 += D_80078EE0[arg1];
                    break;
                }

                if ((arg2 >= 0) && (arg2 < 0x14)) {
                    var_fv0 += D_80078EF0[arg1];
                    var_fv0 += 0.5f * arg2;

                    Audio_QueueVoiceDetune(D_80078F00[arg1], var_fv0);
                    return 0;
                }

                if (arg2 >= 0x14) {
                    var_fv0 += D_80078EF0[arg1];
                    var_fv0 += (0, 0.5f) * 22.5;

                    Audio_QueueVoiceDetune(D_80078F00[arg1], var_fv0);
                    return 0;
                }
            } else if (Audio_IsSoundPlaying(D_80078F00[arg1]) == 0) {
                return 0;
            } else {
                Audio_QueueFadeSoundCommand(D_80078F00[arg1], 0xA);
                return 0;
            }

        case 0x30004:
            Audio_QueueFadeSoundCommand(D_80078F00[0], 0x14);
            Audio_QueueFadeSoundCommand(D_80078F00[1], 0x14);
            Audio_QueueFadeSoundCommand(D_80078F00[2], 0x14);
            Audio_QueueFadeSoundCommand(D_80078F00[3], 0x14);
            var_v0 += D_80078EE0[arg1];
            break;

        case 0x30001:
        case 0x30002:
            break;

        default:
            return 0;
    }

    sp44 = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, arg0 & 0xFFFF, sp38, var_v0, -1);
    Audio_QueueVoiceDetune(sp44, var_fv0);
    if (arg0 == 0x30003) {
        D_80078F00[arg1] = sp44;
    }
    return sp44;
}

void Audio_StopCategory3SoundCommand(UNUSED s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2) {
}

s32 Audio_ComputeIndexedVolume(u32 arg0, u32 arg1) {
    s32 ret;

    if ((arg0 == 0) || (arg0 >= 5)) {
        arg0 = 1;
    }

    switch (arg1) {
        case 1:
            ret = 0x80;
            break;

        case 2:
            ret = (arg0 * 0xAF) - 0x87;
            break;

        case 3:
            ret = (arg0 * 0x66) - 0x4D;
            break;

        case 4:
            ret = (arg0 * 0x4E) - 0x44;
            break;

        default:
            ret = 0x80;
            break;
    }

    return ret;
}

s32 Audio_PlayCategory4SoundCommand(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp3C;
    UNUSED s32 pad;
    s32 var_v1 = 0x80;
    u32 var_a3 = 0x80;
    f32 var_fv0 = 0.0f;

    switch (arg0) {
        case 0x00040004:
            if ((arg1 <= 0) || (arg1 >= 5)) {
                var_a3 = 0x80;
                arg1 = 1;
            }
            Audio_QueueFadeSoundCommand(D_80078F00[arg1 + 3], 0x14);
            var_v1 = Audio_ComputeIndexedVolume(arg1, arg2);
            var_fv0 = (4 - arg1) * 0.5f;
            break;

        case 0x00040005:
        case 0x00040006:
        case 0x00040007:
            if ((arg1 <= 0) || (arg1 >= 5)) {
                arg1 = 1;
            }
            var_v1 = Audio_ComputeIndexedVolume(arg1, arg2);
            var_a3 = 0x80;
            var_fv0 = (4 - arg1) * 0.5f;
            break;

        case 0x00040001:
            var_a3 = 0xC0;
            break;

        case 0x00040003:
            if ((arg1 <= 0) || (arg1 >= 5)) {
                arg1 = 1;
            }
            var_v1 = Audio_ComputeIndexedVolume(arg1, arg2);
            var_a3 = 0xC0;
            var_fv0 = 0.0f;
            break;

        case 0x00040002:
            break;

        default:
            return 0;
    }

    sp3C = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, arg0 & 0xFFFF, var_a3, var_v1, -1);
    Audio_QueueVoiceDetune(sp3C, var_fv0);

    if (arg0 == 0x40004) {
        D_80078F00[arg1 + 3] = sp3C;
    }

    return sp3C;
}

void Audio_StopCategory4SoundCommand(UNUSED s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2) {
}

s32 Audio_PlayCategory5SoundCommand(s32 arg0, s32 arg1, s32 arg2) {
    static s32 D_80078F20 = 0x00000000;

    s32 sp34;
    UNUSED s32 pad;
    u32 var_v0 = 0x80;
    s32 var_a3 = 0x80;
    f32 var_fv0 = 0.0f;

    switch (arg0) {
        case 0x50001:
        case 0x50002:
        case 0x50003:
        case 0x50004:
        case 0x50005:
        case 0x50006:
        case 0x50007:
            break;

        case 0x50008:
        case 0x50009:
        case 0x5000A:
            if ((arg1 <= 0) || (arg1 >= 5)) {
                arg1 = 1;
            }
            var_fv0 = (4 - arg1) * 0.5f;
            if (arg2 >= 0x141) {
                arg2 = 0x140;
            }
            var_v0 = arg2 * 0.796875f;
            break;

        case 0x5000B:
            Audio_QueueFadeSoundCommand(D_80078F20, 1);
            var_v0 = 0x80;
            var_a3 = 0x80;
            var_fv0 = 0.0f;
            break;

        case 0x5000C:
            var_a3 = 0xA0;
            break;

        default:
            return 0;
    }

    sp34 = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, arg0 & 0xFFFF, var_a3, var_v0, -1);
    Audio_QueueVoiceDetune(sp34, var_fv0);
    D_80078F20 = sp34;
    return sp34;
}

void Audio_StopCategory5SoundCommand(UNUSED s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2) {
}

s32 Audio_PlayCategory6SoundCommand(s32 arg0, s32 arg1, UNUSED s32 arg2) {
    static s32 D_80078F24[4] = {
        0xFFFFFF88,
        0xFFFFFFC4,
        0x0000003C,
        0x00000078,
    };
    static f32 D_80078F34[4] = {
        -1,
        -0.5,
        0,
        0.5,
    };
    static s32 D_80078F44 = 0x00000000;
    static s32 D_80078F48 = 0x00000000;

    s32 sp34;
    UNUSED s32 pad;
    u32 var_v1;
    s32 sp28;
    UNUSED s32 pad2;
    f32 sp20;

    sp20 = 0.0f;
    var_v1 = 0x7F;
    sp28 = 0x80;

    if ((arg1 >= 4) | (arg1 < 0)) {
        return 0;
    }

    switch (arg0) {
        case 0x60003:
            sp20 += D_80078F34[arg1];
            var_v1 = D_80078F24[arg1] + 0x7F;
        case 0x60001:
        case 0x60002:
        case 0x60006:
        case 0x60008:
        case 0x60009:
        case 0x6000A:
        case 0x6000B:
            break;

        case 0x60004:
            var_v1 = D_80078F24[arg1] + 0x7F;
            sp28 = 0x70;
            break;

        case 0x60005:
            if (Audio_IsSoundPlaying(D_80078F48) != 0) {
                return 0;
            }
            var_v1 = 0x7F;
            if (Audio_IsSoundPlaying(D_80078F44) != 0) {
                return 0;
            }
            break;

        case 0x60007:
            var_v1 = 0x7F;
            if (Audio_IsSoundPlaying(D_80078F48) != 0) {
                arg0 = 0x60008;
            }
            break;

        default:
            return 0;
    }

    sp34 = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, arg0 & 0xFFFF, sp28, var_v1, -1);
    if (arg0 == 0x60005) {
        if (Audio_IsSoundPlaying(D_80078F44) == 0) {
            D_80078F44 = sp34;
        }
    }
    D_80078F48 = sp34;
    Audio_QueueVoiceDetune(sp34, sp20);
    return sp34;
}

void Audio_StopCategory6SoundCommand(UNUSED s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2) {
}

static u8 D_80078F4C = 0;

s32 Audio_PlayCategory7SoundCommand(s32 arg0, s32 arg1, UNUSED s32 arg2) {
    s32 sp44;
    s32 var_a2;
    s32 var_a3;
    s32 var_v0;
    f32 var_fv0;
    u8 var_t0;
    u8 sp2C[] = {
        0x19,
        0x4E,
        0xB2,
        0xE6,
    };

    var_fv0 = 0.0f;
    var_t0 = 0x80;
    var_a3 = 0x80;
    var_v0 = -1;
    var_a2 = arg0 & 0xFFFF;

    switch (arg0) {
        case 0x70004:
        case 0x70005:
        case 0x70006:
            if ((arg1 <= 0) || (arg1 >= 5)) {
                arg1 = 1;
            }
            var_t0 = sp2C[arg1 - 1];
            var_fv0 = ((4 - arg1) * 0.5f) + -2.0f;
            break;

        case 0x70009:
            break;

        case 0x70003:
            if (arg1 != 0) {
                var_t0 = 0x1E;
            } else {
                var_t0 = 0xE1;
            }
            break;

        case 0x70001:
            switch (D_80078F4C) {
                case 0:
                    var_a2 = 1;
                    break;

                case 1:
                    var_a2 = 7;
                    break;

                case 2:
                    var_a2 = 8;
                    break;
            }
            var_a3 = 0x70;

            D_80078F4C++;
            if (D_80078F4C >= 3) {
                D_80078F4C = 0;
            }
            var_v0 = 0x80;
            break;

        case 0x70002:
            D_80078F4C = 0;
            var_a3 = 0x70;
            var_v0 = 0x80;
            break;

        default:
            return 0;
    }

    sp44 = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, var_a2, var_a3, var_t0, var_v0);
    Audio_QueueVoiceDetune(sp44, var_fv0);
    return sp44;
}

void Audio_StopCategory7SoundCommand(UNUSED s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2) {
}

static s32 D_80078F54[4] = {
    0xFFFFFF88,
    0xFFFFFFC4,
    0x0000003C,
    0x00000078,
};

static f32 D_80078F64[4] = {
    0.0f,
    0.1000000015f,
    -0.1000000015f,
    0.200000003f,
};

static s32 D_80078F74[4] = {
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
};

static s32 D_80078F84 = 0x00000000;

static s32 D_80078F88 = 0x00000000;

static s32 D_80078F8C[4] = {
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
};

static s32 D_80078F9C = 0x00003039;
static u32 D_80078FA0 = 0x00001A85;

void Audio_SeedRandom(s32 arg0, u32 arg1) {
    D_80078F9C = arg0;
    D_80078FA0 = arg1;
}

u32 Audio_NextRandom(void) {
    D_80078F9C = (D_80078F9C * 0x41C64E6D) + 0x3039;

    if (D_80078FA0 & 1) {
        D_80078FA0 ^= 0x11020;
    }

    D_80078FA0 >>= 1;

    return D_80078F9C ^ D_80078FA0;
}

f32 Audio_RandomFloat(void) {
    return (f32)Audio_NextRandom() / -1u;
}

s32 Audio_PlayCategory8SoundCommand(s32 arg0, s32 arg1, s32 arg2) {
    static u32 D_80078FA4 = 0;

    s32 sp44;
    UNUSED s32 pad;
    u32 sp3C;
    s32 sp38;
    UNUSED s32 pad2;
    f32 var_fv1;

    sp3C = 0x7F;
    sp38 = 0x80;
    var_fv1 = 0.0f;

    if ((arg1 >= 4) || (arg1 < 0)) {
        return 0;
    }

    if ((arg2 < 0) || (arg2 >= 6)) {
        return 0;
    }

    switch (arg0) {
        case 0x80001:
            sp3C += D_80078F54[arg1];
            sp38 = 0x40;
            var_fv1 += D_80078F64[arg1];
            switch (arg2) {
                case 0:
                    break;

                case 1:
                    return 0;

                case 2:
                    var_fv1 += 0.5;
                    Audio_QueueVoiceDetune(D_80078F74[arg1], var_fv1);
                    return 0;

                case 3:
                    var_fv1 += 1.0;
                    Audio_QueueVoiceDetune(D_80078F74[arg1], var_fv1);
                    return 0;

                case 4:
                    var_fv1 += 2.0;
                    Audio_QueueVoiceDetune(D_80078F74[arg1], var_fv1);
                    Audio_QueueVoiceVolumeScale(D_80078F74[arg1], 0x58);
                    return 0;

                case 5:
                    Audio_QueueFadeSoundCommand(D_80078F74[arg1], 3);

                default:
                    return 0;
            }
            break;

        case 0x80002:
            if (Audio_IsSoundPlaying(D_80078F8C[arg1]) != 0) {
                return 0;
            }

            sp3C += D_80078F54[arg1];
            var_fv1 += D_80078F64[arg1];

            switch (arg2) {
                case 1:
                    return 0;

                case 2:
                    if (Audio_RandomFloat() > 0.05) {
                        return 0;
                    }
                    break;

                case 3:
                    if (Audio_RandomFloat() > 0.1) {
                        return 0;
                    }
                    break;

                case 4:
                    if (Audio_RandomFloat() > 0.17) {
                        return 0;
                    }
                    break;

                default:
                    return 0;
            }
            break;

        case 0x80003:
            if (Audio_IsSoundPlaying(D_80078F84) != 0) {
                return 0;
            }
            Audio_FadeCategories(1, 1);
            break;

        case 0x80004:
            Audio_FadeCategories(1, 1);
            break;

        case 0x80005:
            var_fv1 += (f32)D_80078FA4 * 2.0;
            if (D_80078FA4 < 2) {
                D_80078FA4 += 1;
            } else if (D_80078FA4 >= 2) {
                D_80078FA4 = 0;
            }
            break;

        case 0x80006:
            Audio_FadeCategories(1, 2);
            break;

        case 0x80007:
        case 0x80008:
            break;

        default:
            return 0;
    }

    sp44 = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, arg0 & 0xFFFF, sp38, sp3C, -1);

    switch (arg0) {
        case 0x80001:
            D_80078F74[arg1] = sp44;
            break;

        case 0x80002:
            D_80078F8C[arg1] = sp44;
            break;

        case 0x80003:
            D_80078F84 = sp44;

        case 0x80004:
            D_80078F88 = sp44;
            break;
    }

    Audio_QueueVoiceDetune(sp44, var_fv1);
    return sp44;
}

void Audio_StopCategory8SoundCommand(s32 arg0, s32 arg1, UNUSED s32 arg2) {
    if (arg0 == 0x80001) {
        Audio_QueueFadeSoundCommand(D_80078F74[arg1], 0xA);
    }
}

s32 D_80078FA8 = 0;

s32 Audio_PlayCategory9SoundCommand(s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2) {
    static s32 D_80078FAC = 0;

    s32 sp3C;
    s32 sp38;
    UNUSED s32 pad;
    s32 sp30;
    f32 var_fv1;
    UNUSED s32 pad2;

    sp30 = 0x80;
    var_fv1 = 0.0f;
    sp38 = arg0 & 0xFFFF;

    switch (arg0) {
        case 0x90001:
            if (D_80078FAC == 0) {
                D_80078ED4 = 0;
                D_80078ED8 = 0;
                D_80078EDC = 0;
                sp38 = 2;
                D_80078FAC++;
                Audio_UpdateSpecialSequence(0x1E, 0);
            } else if (D_80078FAC == 1) {
                D_80078FAC++;
                var_fv1 -= 4.0f;
            } else if (D_80078FAC == 2) {
                D_80078FAC++;
                var_fv1 -= 2.0f;
            } else if (D_80078FAC == 3) {
                D_80078FAC = 0;
                var_fv1 -= 9.0f;
            }
            break;

        case 0x90002:
        case 0x90003:
        case 0x90004:
        case 0x90005:
        case 0x90006:
        case 0x90007:
        case 0x90008:
        case 0x90009:
            break;

        case 0x9000A:
            Audio_StartMusicTrack(0x1A);
            break;

        case 0x9000B:
            Audio_StartMusicTrack(0x1B);
            break;

        case 0x9000C:
            return 0;

        case 0x9000D:
        case 0x9000E:
        case 0x9000F:
        case 0x90010:
        case 0x90011:
            sp38 = sp38 - 1;
            sp30 = 0x60;
            break;

        default:
            return 0;
    }

    sp3C = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, sp38, sp30, 0x7F, -1);
    Audio_QueueVoiceDetune(sp3C, var_fv1);

    switch (arg0) {
        case 0x9000D:
        case 0x9000E:
        case 0x9000F:
        case 0x90010:
        case 0x90011:
            D_80078FA8 = sp3C;
            break;
    }

    return sp3C;
}

void Audio_StopCategory9SoundCommand(UNUSED s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2) {
}

s32 Audio_PlayCategoryASoundCommand(s32 arg0, s32 arg1, s32 arg2) {
    static s32 D_80078FB0[4] = {
        0xFFFFFF88,
        0xFFFFFFD8,
        0x00000028,
        0x00000078,
    };
    static s32 D_80078FC0[3] = {
        0xFFFFFF8D,
        0x00000000,
        0x00000073,
    };
    static f32 D_80078FCC[3] = {
        1.0f,
        0.8000000119f,
        0.6000000238f,
    };
    static f32 D_80078FD8[4] = {
        -0.6000000238f,
        1.0f,
        -1.0f,
        0.6000000238f,
    };
    static f32 D_80078FE8[4] = {
        0.0f,
        0.0f,
        2.0f,
        2.0f,
    };
    static f32 D_80078FF8[4] = {
        0.0f,
        4.0f,
        8.0f,
        12.0f,
    };

    s32 sp34;
    s32 sp30;
    u32 var_t0;
    u32 var_a3;
    f32 var_fv0;
    UNUSED s32 pad;

    var_t0 = 0x7F;
    var_a3 = 0x80;
    sp30 = arg0 & 0xFFFF;
    var_fv0 = 0.0f;

    switch (arg0) {
        case 0xA0003:
            if (arg1 < 0) {
                return 0;
            }

            if (arg1 >= 4) {
                return 0;
            }

            switch (arg2) {
                case 0:
                    break;

                case 1:
                    sp30 = 4;
                    break;

                case 2:
                    sp30 = 5;
                    break;

                case 3:
                    sp30 = 6;
                    break;
            }

            var_fv0 += D_80078FD8[arg1];
            var_fv0 += D_80078FE8[arg2];
            var_t0 = D_80078FB0[arg1] + 0x7F;
            var_a3 = 240.0f;
            var_a3 += D_80078FF8[arg2];

            if (var_t0 >= 0x100) {
                var_t0 = 0xFF;
            }

            if (var_t0 == 0) {
                var_t0 = 1;
            }
            break;

        case 0xA0001:
        case 0xA0002:
        case 0xA0009:
        case 0xA000C:
        case 0xA000D:
        case 0xA0010:
        case 0xA0012:
        case 0xA0013:
            break;

        case 0xA0007:
            if (arg1 < 0) {
                return 0;
            }

            if (arg1 >= 4) {
                return 0;
            }

            if (arg2 < -0x7D) {
                arg2 = -0x7D;
            } else if (arg2 >= 0x7E) {
                arg2 = 0x7D;
            }

            var_t0 = arg2 + 0x7F;
            var_fv0 += D_80078FD8[arg1];
            break;

        case 0xA0008:
            if (arg1 == 1) {
                sp30 = 9;
            } else if (arg1 != 0) {
                return 0;
            }

            if ((arg2 < 0) || (arg2 >= 0xB) || (arg2 == 3) || (arg2 == 7)) {
                return 0;
            }

            var_t0 = (s32)(D_80078FCC[(arg2 & 0xC) >> 2] * (f32)D_80078FC0[arg2 & 3]) + 0x7F;
            break;

        case 0xA000A:
            var_t0 = (s32)((0.8 * (f32)D_80078FC0[arg2 & 3]) * D_80078FCC[(arg2 & 0xC) >> 2]) + (0, 0x7F);
            break;

        case 0xA000B:
            if (arg1 == 1) {
                sp30 = 0xC;
            } else if (arg1 != 0) {
                return 0;
            }
            var_t0 = (s32)(0.8 * (f32)D_80078FC0[arg2 & 3] * D_80078FCC[(arg2 & 0xC) >> 2]) + (0, 0x7F);
            break;

        case 0xA000E:
            Audio_FadeCategories(1, 5);
            var_a3 = 0x80;
            var_t0 = 0x7F;
            var_fv0 = 0.0f;
            break;

        case 0xA000F:
            return 0;

        case 0xA0011:
            if (arg1 == 1) {
                sp30 = 0x10;
            } else if (arg1 != 0) {
                return 0;
            }
            var_t0 = (s32)(0.8 * (f32)D_80078FC0[arg2 & 3] * D_80078FCC[(arg2 & 0xC) >> 2]) + (0, 0x7F);
            break;

        default:
            return 0;
    }

    if (var_t0 == 0) {
        var_t0 = 1;
    } else if (var_t0 >= 0x100) {
        var_t0 = 0xFF;
    }

    sp34 = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, sp30, var_a3, var_t0, -1);
    Audio_QueueVoiceDetune(sp34, var_fv0);
    return sp34;
}

void Audio_StopCategoryASoundCommand(UNUSED s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2) {
}

s32 Audio_PlayPersistentSoundCommand(s32 arg0, u32 arg1) {
    static s32 D_80079008 = 0x00000000;
    static s32 D_8007900C = 0x00000000;
    static s32 D_80079010 = 0x00000000;

    s32 temp_v0;

    switch (arg0) {
        case 19:
            Audio_QueueFadeSoundCommand(D_80079008, 1);
            break;

        case 18:
        case 20:
            break;

        case 21:
            switch (arg1) {
                case 0:
                    if (Audio_IsSoundPlaying(D_80079010) != 0) {
                        return 0;
                    }
                    break;

                case 1:
                    Audio_QueueFadeSoundCommand(D_8007900C, 0x19);
                    break;
            }
            break;

        default:
            return 0;
    }

    if (arg0 == 0x15) {
        Audio_QueueFadeSoundCommand(D_80079010, 0xA);
    }

    temp_v0 = Audio_PlaySoundEffect(D_800FC68C, D_800FC688, arg0, 0x80, 0x80, -1);
    switch (arg0) {
        case 18:
            D_80079008 = temp_v0;
            break;

        case 20:
            D_8007900C = temp_v0;
            break;

        case 21:
            D_80079010 = temp_v0;
            break;
    }

    return temp_v0;
}

u32 D_80079014 = 0xFFFFFFFF;
static s32 D_80079018 = 0x00000000;

s32 Audio_DispatchSoundBankCommand(s32 arg0, s32 arg1, s32 arg2) {
    UNUSED s32 pad[5];
    s32 var_v0;
    u32 sp24;
    u32 temp_v1;

    temp_v1 = arg0 & 0xFFFF0000;

    switch (temp_v1) {
        case 0x20000:
        case 0x30000:
        case 0x40000:
        case 0x50000:
        case 0x60000:
        case 0x70000:
        case 0x80000:
        case 0x90000:
        case 0xA0000:
            break;

        default:
            return 0;
    }

    if (temp_v1 != D_80079014) {
        sp24 = D_800FC6F8->seqArray[(temp_v1 >> 0x10) - 2].offset;

        Rom_DmaRead(sp24, (u32)D_800FC798, 0xC);
        Audio_RelocateOffsets((u32)D_800FC798, sp24, 3);
        Rom_DmaRead(D_800FC798[0], D_800FC6DC, D_800FC798[1] - D_800FC798[0]);
        Audio_CopyDataWithCacheSync(D_800FC6DC, D_800FC6A8, 0xBB8);
        Audio_RelocateSoundBankTable(D_800FC6A8);
        Rom_DmaRead(D_800FC798[1], D_800FC6DC, D_800FC798[2] - D_800FC798[1]);
        Audio_CopyDataWithCacheSync(D_800FC6DC, D_800FC6A4, 0x1388);
        Audio_RelocateSoundBankWrapper(D_800FC6A4, D_800FC798[2]);
    }

    D_80079014 = temp_v1;

    switch (temp_v1) {
        case 0x20000:
            var_v0 = Audio_PlayCategory2SoundCommand(arg0, arg1, arg2);
            break;

        case 0x30000:
            var_v0 = Audio_PlayCategory3SoundCommand(arg0, arg1, arg2);
            break;

        case 0x40000:
            var_v0 = Audio_PlayCategory4SoundCommand(arg0, arg1, arg2);
            break;

        case 0x50000:
            var_v0 = Audio_PlayCategory5SoundCommand(arg0, arg1, arg2);
            break;

        case 0x60000:
            var_v0 = Audio_PlayCategory6SoundCommand(arg0, arg1, arg2);
            break;

        case 0x70000:
            var_v0 = Audio_PlayCategory7SoundCommand(arg0, arg1, arg2);
            break;

        case 0x80000:
            var_v0 = Audio_PlayCategory8SoundCommand(arg0, arg1, arg2);
            break;

        case 0x90000:
            var_v0 = Audio_PlayCategory9SoundCommand(arg0, arg1, arg2);
            break;

        case 0xA0000:
            var_v0 = Audio_PlayCategoryASoundCommand(arg0, arg1, arg2);
            break;

        default:
            return 0;
    }

    D_80079018 = var_v0;
}

void Audio_DispatchSoundBankStopCommand(s32 arg0, s32 arg1, s32 arg2) {
    switch (arg0 & 0xFFFF0000) {
        case 0x20000:
            Audio_StopCategory2SoundCommand(arg0, arg1, arg2);
            break;

        case 0x30000:
            Audio_StopCategory3SoundCommand(arg0, arg1, arg2);
            break;

        case 0x40000:
            Audio_StopCategory4SoundCommand(arg0, arg1, arg2);
            break;

        case 0x50000:
            Audio_StopCategory5SoundCommand(arg0, arg1, arg2);
            break;

        case 0x60000:
            Audio_StopCategory6SoundCommand(arg0, arg1, arg2);
            break;

        case 0x70000:
            Audio_StopCategory7SoundCommand(arg0, arg1, arg2);
            break;

        case 0x80000:
            Audio_StopCategory8SoundCommand(arg0, arg1, arg2);
            break;

        case 0x90000:
            Audio_StopCategory9SoundCommand(arg0, arg1, arg2);
            break;

        case 0xA0000:
            Audio_StopCategoryASoundCommand(arg0, arg1, arg2);
            break;
    }
}

s32 Audio_PlayDirectSoundCommand(s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2) {
    UNUSED s32 pad[4];
    s32 var_v0;
    s32 sp2C;
    u32 sp34;
    u32 sp28;

    sp28 = arg0 & 0xFFFF0000;
    sp2C = arg0 & 0xFFFF;

    if (sp28 != D_80079014) {
        sp34 = D_800FC6F4->seqArray[2].offset;

        Rom_DmaRead(sp34, &D_800FC798[0], 0xC);
        Audio_RelocateOffsets(D_800FC798, sp34, 3);
        sp34 = D_800FC798[1] - D_800FC798[0];
        Rom_DmaRead(D_800FC798[0], D_800FC6DC, sp34);
        Audio_CopyDataWithCacheSync(D_800FC6DC, D_800FC6A8, 0xBB8);
        Audio_RelocateSoundBankTable(D_800FC6A8);
        sp34 = D_800FC798[2] - D_800FC798[1];
        Rom_DmaRead(D_800FC798[1], D_800FC6DC, sp34);
        Audio_CopyDataWithCacheSync(D_800FC6DC, D_800FC6A4, 0x1388);
        Audio_RelocateSoundBankWrapper(D_800FC6A4, D_800FC798[2]);
    }

    D_80079014 = sp28;

    switch (arg0) {
        case 0x1000001:
            var_v0 = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, sp2C, 0x80, 0x80, -1);
            break;

        case 0x1000002:
            var_v0 = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, sp2C, 0xA0, 0x80, -1);
            break;

        case 0x1000003:
            var_v0 = Audio_PlaySoundEffect(D_800FC684, D_800FC6A8, sp2C, 0xA0, 0x80, -1);
            break;

        default:
            return 0;
    }

    D_80079018 = var_v0;
}

s32 Audio_PlayCategory11SoundCommand(s32 arg0, s32 arg1, s32 arg2) {
    static s32 D_8007901C = 0x00000000;
    static s32 D_80079020 = 0x00000000;
    static s32 D_80079024 = 0x00000000;
    static s32 D_80079028 = 0;
    static u8 D_8007902C[] = {
        0x60, 0xA0, 0xE0, 0x20, 0x60, 0xA0,
    };
    static u8 D_80079034[] = {
        0x60, 0xA0, 0xE0, 0x60, 0xA0, 0xE0, 0x20, 0x60, 0xA0, 0x20, 0x60, 0xA0,
    };
    static u8 D_80079040[] = {
        0x20, 0x60, 0xA0, 0xE0, 0x20, 0x60, 0xA0, 0xE0, 0x20, 0x60, 0xA0, 0xE0,
    };

    UNUSED s32 pad;
    s32 sp40;
    s32 temp_v0_2;
    u32 sp38;
    s32 sp34;
    UNUSED s32 pad2;
    u32 sp2C;
    u32 sp20;

    sp20 = arg0 & 0xFFFF0000;
    sp38 = 0x80;
    sp34 = 0x80;

    if (sp20 != D_80079014) {
        sp2C = D_800FC6F4->seqArray[3].offset;

        Rom_DmaRead(sp2C, (u32)D_800FC798, 0xC);
        Audio_RelocateOffsets((u32)D_800FC798, sp2C, 3);
        Rom_DmaRead(D_800FC798[0], D_800FC6DC, D_800FC798[1] - D_800FC798[0]);
        Audio_CopyDataWithCacheSync(D_800FC6DC, D_800FC6A8, 0xBB8);
        Audio_RelocateSoundBankTable(D_800FC6A8);
        Rom_DmaRead(D_800FC798[1], D_800FC6DC, D_800FC798[2] - D_800FC798[1]);
        Audio_CopyDataWithCacheSync(D_800FC6DC, D_800FC6A4, 0x1388);
        Audio_RelocateSoundBankWrapper(D_800FC6A4, D_800FC798[2]);
    }

    D_80079014 = sp20;

    sp40 = arg0 & 0xFFFF;
    switch (arg0) {
        case 0x1100007:
            return 0;

        case 0x1100015:
        case 0x1100016:
        case 0x1100017:
            sp40--;
            break;

        case 0x1100001:
        case 0x1100002:
        case 0x1100003:
        case 0x1100005:
        case 0x1100006:
        case 0x1100009:
        case 0x110000A:
        case 0x110000C:
        case 0x110000D:
        case 0x110000F:
        case 0x1100010:
        case 0x1100011:
            break;

        case 0x1100013:
            sp34 = 0xF0;
            break;

        case 0x1100012:
            Audio_PlaySoundEffectById(0x1B);
            break;

        case 0x1100004:
            Audio_QueueFadeSoundCommand(D_8007901C, 5);
            break;

        case 0x1100008:
            Audio_QueueFadeSoundCommand(D_80079020, 5);
            Audio_QueueFadeSoundCommand(D_80079024, 5);
            break;

        case 0x110000B:
            if (arg2 == 0) {
                if ((arg1 <= 0) || (arg1 >= 7)) {
                    return 0;
                }
                sp38 = D_8007902C[arg1 - 1];
            } else {
                if ((arg1 <= 0) || (arg1 >= 0xD)) {
                    return 0;
                }
                sp38 = D_80079034[arg1 - 1];
            }
            Audio_QueueFadeSoundCommand(D_80079028, 0xA);
            break;

        case 0x1100014:
            sp40 = 0xB;
            if (arg2 == 1) {
                sp38 = 0x7F;
            } else {
                sp38 = D_80079040[(arg1 - 1) % 4];
            }
            break;

        case 0x110000E:
            if ((arg1 < 0) || (arg1 >= 9)) {
                return 0;
            }
            sp38 = D_80079040[3 + arg1];
            break;

        default:
            return 0;
    }

    temp_v0_2 = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, sp40, sp34, sp38, -1);
    switch (arg0) {
        case 0x1100003:
            D_8007901C = temp_v0_2;
            break;

        case 0x1100006:
            D_80079020 = temp_v0_2;
            break;

        case 0x1100007:
            D_80079024 = temp_v0_2;
            break;

        case 0x110000B:
            D_80079028 = temp_v0_2;
            break;
    }
    D_80079018 = temp_v0_2;
}

s32 Audio_PlayCategory12SoundCommand(s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2) {
    static s32 D_8007904C = 0x00000000;
    static s32 D_80079050 = 0x00000000;
    static s32 D_80079054 = 0x00000000;
    static s32 D_80079058 = 0x00000000;
    static s32 D_8007905C = 0x00000000;
    static u8 D_80079060 = 0;
    static u8 D_80079064 = 0;

    UNUSED s32 pad[2];
    s32 sp4C;
    UNUSED s32 pad2[2];
    f32 var_fv1;
    u32 sp3C;
    u32 sp24;

    sp24 = arg0 & 0xFFFF0000;
    if (sp24 != D_80079014) {
        sp3C = D_800FC6F4->seqArray[4].offset;

        Rom_DmaRead(sp3C, (u32)D_800FC798, 0xC);
        Audio_RelocateOffsets((u32)D_800FC798, sp3C, 3);
        Rom_DmaRead(D_800FC798[0], D_800FC6DC, D_800FC798[1] - D_800FC798[0]);
        Audio_CopyDataWithCacheSync(D_800FC6DC, D_800FC6A8, 0xBB8);
        Audio_RelocateSoundBankTable(D_800FC6A8);
        Rom_DmaRead(D_800FC798[1], D_800FC6DC, D_800FC798[2] - D_800FC798[1]);
        Audio_CopyDataWithCacheSync(D_800FC6DC, D_800FC6A4, 0x1388);
        Audio_RelocateSoundBankWrapper(D_800FC6A4, D_800FC798[2]);
    }

    D_80079014 = sp24;

    switch (arg0) {
        case SFX_TRADE_TEXT:
            Audio_QueueFadeSoundCommand(D_8007904C, 1);
            var_fv1 = __ull_to_f(__ull_rem(osGetTime(), 8)) - 4.0f;
            sp4C = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, 7, 0x80, 0x80, -1);
            Audio_QueueVoiceDetune(sp4C, var_fv1);
            D_8007904C = sp4C;
            break;

        case SFX_TRADE_BEGIN:
            sp4C = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, 1, 0x80, 0x80, -1);
            D_80079050 = sp4C;
            D_80079064 = 0;
            break;

        case SFX_TRADE_END:
            Audio_QueueFadeSoundCommand(D_80079050, 0x3C);
            Audio_QueueFadeSoundCommand(D_80079054, 0x3C);
            D_80079060 = 0;
            sp4C = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, 3, 0x80, 0x80, -1);
            break;

        case SFX_TRADE_LIGHT_ON:
            if (D_80079060 == 0) {
                sp4C = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, 2, 0x80, 0x80, -1);
                D_80079054 = sp4C;
                var_fv1 = 2.0f;
                D_80079060 = 1;
            } else {
                var_fv1 = 4.0f;
            }
            Audio_QueueVoiceDetune(D_80079054, var_fv1);
            break;

        case SFX_TRADE_BALL_APPEAR:
            sp4C = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, 4, 0x80, 0x80, -1);
            D_80079058 = sp4C;
            break;

        case SFX_TRADE_BALL_READY:
            Audio_QueueFadeSoundCommand(D_80079054, 0x5A);
            Audio_QueueFadeSoundCommand(D_80079058, 1);
            sp4C = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, 5, 0x80, 0x80, -1);
            break;

        case SFX_EVOLUTION_START:
            D_8007905C = sp4C = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, 6, 0x80, 0x80, -1);
            Audio_FadeOutAll(0x78);
            D_80079064 = 1;
            break;

        case 0x1200008:
            Audio_QueueFadeSoundCommand(D_8007905C, 6);
            Audio_StartMusicTrack(0x13);
            D_80079064 = 1;
            break;

        case 0x1200009:
            if (D_80079064 != 0) {
                Audio_StartMusicTrack(0x10);
            }
            Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
            D_80079064 = 0;
            break;

        case 0x120000C:
            sp4C = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, 8, 0x80, 0x80, -1);
            break;

        case 0x120000D:
            sp4C = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, 9, 0x80, 0x80, -1);
            break;

        case 0x120000E:
            Audio_QueueFadeSoundCommand(D_8007904C, 1);
            sp4C = Audio_PlaySoundEffect(D_800FC6A4, D_800FC6A8, 7, 0x80, 0x80, -1);
            Audio_QueueVoiceDetune(sp4C, -5.0f);
            D_8007904C = sp4C;
            break;

        default:
            return 0;
    }

    D_80079018 = sp4C;
}
