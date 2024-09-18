#include "38BB0.h"
#include "src/3D140.h"
#include "src/435B0.h"

typedef u8* (*func_D_80077C98)(unk_D_800FC7D0*, u8*);
typedef u8* (*func_D_80077D5C)(u8*);

static s32 D_80077C90 = -1;
static u8 D_80077C94 = 0;
static func_D_80077C98 D_80077C98[] = {
    func_80037FB0, func_80037FD0, func_80038008, func_8003802C, func_80038038, func_800381B4, func_8003827C,
    func_80038268, func_800382AC, func_80038304, func_80038360, func_80038374, func_800383B8, func_800383C8,
    func_800383D8, func_800383E8, func_8003844C, func_800384AC, func_800384BC, func_800384C8, func_800384D8,
    func_800384E4, func_800385D0, func_80038688, func_800386A8, func_800386B4, func_800386C4, func_800386D0,
    func_800386E4, func_80038704, func_80038710, func_80038738, func_80038744, func_80038750, func_800387B4,
    func_800387C4, func_80038814, func_80038864, func_800388B4, func_800388C4, func_800389C0, func_80038A10,
    NULL,          NULL,          NULL,          NULL,          NULL,          NULL,          func_80038A34,
};
static func_D_80077D5C D_80077D5C[] = {
    func_80039D58, func_8003A10C, func_8003A234, func_8003A2F0, func_8003A39C, func_8003A438, func_8003A4D8,
    func_8003A564, func_8003A614, func_8003A6D4, func_8003A744, func_80039F28, NULL,
};

static ALPlayer D_800FC7A0;
static ALHeap D_800FC7B8;
static s32 pad_D_800FC7C8;
static u32 D_800FC7CC;
static unk_D_800FC7D0* D_800FC7D0;
static u32 D_800FC7D4;
static u32 D_800FC7D8;
static u16 D_800FC7DC;
static u16 D_800FC7DE;
static u32 D_800FC7E0;
static s32 D_800FC7E4;
static u8* D_800FC7E8;
static s32 D_800FC7EC;
static u32 D_800FC7F0;
static u8 D_800FC7F4;
static u32 D_800FC7F8;
static unk_D_800FC7D0_148* D_800FC7FC;
static unk_D_800FC7D0_148* D_800FC800;
static unk_D_800FC7D0_148* D_800FC804;
static unk_D_800FC7D0_148* D_800FC808;
static unk_D_800FC7D0_148* D_800FC80C;
ALHeap* D_800FC810;
u32 D_800FC814;
s32 D_800FC818;
s32 D_800FC81C;

u8* func_80037FB0(unk_D_800FC7D0* arg0, UNUSED u8* arg1) {
    arg0->unk_060 = 0;
    arg0->unk_05C = 0;
    arg0->unk_08C = 0;
    arg0->unk_0BA = 0;
    arg0->unk_064 = 0;
    return NULL;
}

u8* func_80037FD0(unk_D_800FC7D0* arg0, u8* arg1) {
    u16 var_v1 = *arg1++;

    if (var_v1 & 0x80) {
        var_v1 = (var_v1 & 0x7F) << 8;
        var_v1 |= *arg1++;
    }

    arg0->unk_0C2 = var_v1;
    return arg1;
}

u8* func_80038008(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0CC = *arg1++;
    if (arg0->unk_0CC) {
        arg0->unk_070 = arg0->unk_054;
    }
    return arg1;
}

u8* func_8003802C(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0CC = 0;
    return arg1;
}

u8* func_80038038(unk_D_800FC7D0* arg0, u8* arg1) {
    u8 var_v0;

    var_v0 = *arg1++;
    if (var_v0 == 0) {
        var_v0 = 1;
    }
    arg0->unk_0D3 = var_v0;
    arg0->unk_07C = 0x400 / var_v0;
    arg0->unk_0D4 = 0;

    arg1++;

    var_v0 = *arg1++;
    if (var_v0 == 0) {
        var_v0 = 1;
    }
    arg0->unk_0DA = var_v0;
    arg0->unk_0D5 = *arg1++;
    arg0->unk_074 = (1.0 / (f32)var_v0) * (f32)(arg0->unk_0D5 - arg0->unk_0D4);

    var_v0 = *arg1++;
    if (var_v0 == 0) {
        var_v0 = 1;
    }
    arg0->unk_0DB = var_v0;
    arg0->unk_0D6 = *arg1++;
    arg0->unk_078 = (1.0f / var_v0) * ((f32)arg0->unk_0D6 - arg0->unk_0D5);

    var_v0 = *arg1++;
    if (var_v0 == 0) {
        var_v0 = 1;
    }
    arg0->unk_0E0 = var_v0;

    return arg1;
}

u8* func_800381B4(unk_D_800FC7D0* arg0, u8* arg1) {
    s32 i;
    s32 temp_lo;
    s32 temp2;
    unk_D_800FC7D0* var_a3;

    temp_lo = ((*arg1++ * 0x6000) / 120) / D_800FC7D4;
    temp2 = (arg0->unk_0AC * temp_lo) >> 7;

    if (arg0->unk_0BA != 0) {
        arg0->unk_0B0 = temp_lo;
    } else {
        for (i = 0, var_a3 = D_800FC7D0; i < D_800FC7CC; i++, var_a3++) {
            if (var_a3->unk_08C == arg0->unk_08C) {
                var_a3->unk_0BC = temp_lo;
                var_a3->unk_0B0 = temp2;
            }
        }
    }

    return arg1;
}

u8* func_80038268(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0C8 = *arg1++;
    arg0->unk_0C6 = 0;
    return arg1;
}

u8* func_8003827C(unk_D_800FC7D0* arg0, u8* arg1) {
    s16 tmp = *arg1++ << 8;

    tmp |= *arg1++;

    arg0->unk_0C6 = tmp;
    arg0->unk_0C8 = 0;

    return arg1;
}

u8* func_800382AC(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0CA = *arg1++;
    arg0->unk_0EC = *arg1++;
    arg0->unk_048 = (f32)*arg1++ / 50.0;
    return arg1;
}

u8* func_80038304(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0CA = *arg1++;
    arg0->unk_0EC = *arg1++;
    arg0->unk_048 = -(f32)*arg1++ / 50.0;

    return arg1;
}

u8* func_80038360(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0EC = 0;
    arg0->unk_080 = 0.0f;
    return arg1;
}

u8* func_80038374(unk_D_800FC7D0* arg0, u8* arg1) {
    u8 temp_v0 = *arg1++;

    if (temp_v0 < 0x80) {
        arg0->unk_0C0 = temp_v0;
    } else {
        arg0->unk_0C0 = (temp_v0 & 0x7F) << 8;
        arg0->unk_0C0 += *arg1++;
    }
    return arg1;
}

u8* func_800383B8(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0CB = 1;
    return arg1;
}

u8* func_800383C8(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0CD = *arg1++;
    return arg1;
}

u8* func_800383D8(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0CE = 1;
    return arg1;
}

u8* func_800383E8(unk_D_800FC7D0* arg0, u8* arg1) {
    s32 var_v1 = *arg1++;

    if (var_v1 & 0x80) {
        var_v1 |= ~0xFF;
    }
    arg0->unk_058 -= arg0->unk_0A4;
    arg0->unk_0A4 = (f32)var_v1 / 100.0;
    arg0->unk_058 += arg0->unk_0A4;
    return arg1;
}

u8* func_8003844C(unk_D_800FC7D0* arg0, u8* arg1) {
    s32 var_v0 = *arg1++;

    if (var_v0 & 0x80) {
        var_v0 = (var_v0 & 0x7F) << 8;
        var_v0 |= *arg1++;
    }

    func_80038038(arg0, (u8*)&arg0->unk_08C->unk_10[var_v0]);
    return arg1;
}

u8* func_800384AC(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0ED = 1;
    return arg1;
}

u8* func_800384BC(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0ED = 0;
    return arg1;
}

u8* func_800384C8(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0EE = 1;
    return arg1;
}

u8* func_800384D8(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0EE = 0;
    return arg1;
}

u8* func_800384E4(unk_D_800FC7D0* arg0, u8* arg1) {
    u8 temp_v1 = arg0->unk_0F2;

    arg0->unk_134[temp_v1] = *arg1++;

    arg0->unk_0F4[temp_v1] = arg1;
    arg0->unk_104[temp_v1] = arg0->unk_060;
    arg0->unk_114[temp_v1] = arg0->unk_05C;

    arg0->unk_138[temp_v1] = arg0->unk_0D0;
    arg0->unk_13C[temp_v1] = arg0->unk_088;

    arg0->unk_124[temp_v1] = arg0->unk_0B6;
    arg0->unk_12C[temp_v1] = arg0->unk_0B8;

    arg0->unk_0F2++;
    return arg1;
}

u8* func_800385D0(unk_D_800FC7D0* arg0, u8* arg1) {
    s32 var_v0 = arg0->unk_0F2 - 1;

    if (arg0->unk_134[var_v0] != 0xFF) {
        arg0->unk_134[var_v0]--;
        if (!arg0->unk_134[var_v0]) {
            arg0->unk_0F2 = var_v0;
            var_v0 = -1;
        }
    }

    if (var_v0 >= 0) {
        arg1 = arg0->unk_0F4[var_v0];

        arg0->unk_060 = arg0->unk_104[var_v0];
        arg0->unk_05C = arg0->unk_114[var_v0];
        arg0->unk_0D0 = arg0->unk_138[var_v0];

        arg0->unk_088 = arg0->unk_13C[var_v0];
        arg0->unk_0B6 = arg0->unk_124[var_v0];
        arg0->unk_0B8 = arg0->unk_12C[var_v0];
        arg0->unk_084 = 0.03125f;
        arg0->unk_04C = arg0->unk_088 * arg0->unk_084;
    }

    return arg1;
}

u8* func_80038688(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0EF = *arg1++;
    arg0->unk_0E5 = *arg1++;
    arg0->unk_0E6 = *arg1++;
    return arg1;
}

u8* func_800386A8(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0E5 = 0;
    return arg1;
}

u8* func_800386B4(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0E9 = 1;
    return arg1;
}

u8* func_800386C4(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0E9 = 0;
    return arg1;
}

u8* func_800386D0(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0EA = *arg1++;
    arg0->unk_0E9 = 0;
    return arg1;
}

u8* func_800386E4(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0D1 = *arg1++ / 2;
    return arg1;
}

u8* func_80038704(UNUSED unk_D_800FC7D0* arg0, u8* arg1) {
    arg1++;
    arg1++;
    return arg1;
}

u8* func_80038710(unk_D_800FC7D0* arg0, u8* arg1) {
    u8* ptr = (u8*)&arg0->unk_08C->unk_00 + arg0->unk_08C->unk_14[*arg1++];

    arg0->unk_098 = ptr;
    return arg1;
}

u8* func_80038738(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_098 = NULL;
    return arg1;
}

u8* func_80038744(UNUSED unk_D_800FC7D0* arg0, u8* arg1) {
    arg1++;
    return arg1;
}

u8* func_80038750(unk_D_800FC7D0* arg0, u8* arg1) {
    s32 tmp0;
    s32 tmp2;

    tmp0 = *arg1++ << 8;
    tmp0 += *arg1++;

    tmp2 = *arg1++ << 8;
    tmp2 += *arg1++;

    arg0->unk_060 = &arg0->unk_0A0[tmp2];
    arg0->unk_0B6 = 1;

    tmp2 = *arg1++ << 8;
    tmp2 += *arg1++;

    arg0->unk_05C = &arg0->unk_09C[tmp2];
    arg0->unk_0B8 = 1;

    return &arg0->unk_094[tmp0];
}

u8* func_800387B4(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0E2 = *arg1++;
    return arg1;
}

u8* func_800387C4(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0CD = func_8003BEF4(*arg1++);
    arg0->unk_0CD += *arg1++;
    return arg1;
}

u8* func_80038814(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0D0 = func_8003BEF4(*arg1++);
    arg0->unk_0D0 += *arg1++;
    return arg1;
}

u8* func_80038864(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0D1 = func_8003BEF4(*arg1++);
    arg0->unk_0D1 += *arg1++;
    return arg1;
}

u8* func_800388B4(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0D0 = *arg1++;
    return arg1;
}

u8* func_800388C4(unk_D_800FC7D0* arg0, u8* arg1) {
    s32 i;
    s32 var_s1;
    unk_D_800FC7D0* var_a0;
    u32* sp30;

    var_s1 = *arg1++;
    if (var_s1 >= 0x80) {
        var_s1 = *arg1++ + ((var_s1 & 0x7F) << 8);
    }

    sp30 = arg0->unk_140->unk_0C;
    for (i = 0, var_a0 = D_800FC7D0; i < D_800FC7CC; i++, var_a0++) {
        if (var_a0->unk_038 == NULL) {
            func_8003C2A4(var_a0, var_s1, arg0->unk_0B2, arg0->unk_0C4, arg0->unk_068);

            var_a0->unk_064 = arg0->unk_064;
            var_a0->unk_090 = arg0->unk_090;
            var_a0->unk_140 = arg0->unk_140;
            var_a0->unk_040 = arg0->unk_040;
            var_a0->unk_044 = arg0->unk_044;

            var_a0->unk_038 = var_a0->unk_094 = sp30[var_s1];
            break;
        }
    }

    return arg1;
}

u8* func_800389C0(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_084 = (f32)*arg1++ * 0.015625;
    arg0->unk_04C = SQ(arg0->unk_088);
    return arg1;
}

u8* func_80038A10(unk_D_800FC7D0* arg0, u8* arg1) {
    arg0->unk_0EB = *arg1++;
    if (!arg0->unk_0EB) {
        arg0->unk_0C4 = 0x80;
    }
    return arg1;
}

u8* func_80038A34(unk_D_800FC7D0* arg0, u8* arg1) {
    s32 i;
    s32 var_s1;
    unk_D_800FC7D0* var_a0;
    s32* sp30;

    var_s1 = *arg1++;
    if (var_s1 >= 0x80) {
        var_s1 = *arg1++ + ((var_s1 & 0x7F) << 8);
    }

    sp30 = arg0->unk_140->unk_0C;
    for (i = 0, var_a0 = D_800FC7D0; i < D_800FC7CC; i++, var_a0++) {
        if (var_a0->unk_038 == NULL) {
            func_8003C2A4(var_a0, var_s1, arg0->unk_0B2, arg0->unk_0C4, arg0->unk_068);
            var_a0->unk_064 = arg0->unk_064;
            var_a0->unk_090 = arg0->unk_090;
            var_a0->unk_140 = arg0->unk_140;
            var_a0->unk_040 = arg0->unk_040;
            var_a0->unk_044 = arg0->unk_044;
            var_a0->unk_038 = var_a0->unk_094 = sp30[var_s1];
            break;
        }
    }

    return arg1;
}

void func_80038B30(u8* arg0, u32 arg1) {
    *arg0++ = (arg1 >> 0x18) & 0xFF;
    *arg0++ = (arg1 >> 0x10) & 0xFF;
    *arg0++ = (arg1 >> 8) & 0xFF;
    *arg0++ = (arg1 >> 0) & 0xFF;
}

void func_80038B54(u8* arg0, u32 arg1) {
    *arg0++ = (arg1 >> 8u) & 0xFF;
    *arg0++ = arg1 & 0xFF;
}

#ifdef NON_MATCHING
s32 func_80038B68(sp38_func_800373D8* arg0) {
    UNUSED s32 pad[2];
    s32 i;
    ALSynConfig sp4C;
    amConfig sp40;

    sp4C.outputRate = osAiSetFrequency(arg0->unk_18);
    D_800FC7CC = arg0->unk_00;
    if (osTvType == OS_TV_PAL) {
        D_800FC7D4 = 50;
    } else {
        D_800FC7D4 = 60;
    }
    D_800FC7D8 = 1000000 / D_800FC7D4;

    func_8003C1D0(arg0->unk_0C, 0, arg0->unk_10);
    alHeapInit(&D_800FC7B8, arg0->unk_0C, arg0->unk_10);
    D_800FC810 = &D_800FC7B8;
    D_800FC7D0 = alHeapAlloc(&D_800FC7B8, 1, D_800FC7CC * sizeof(unk_D_800FC7D0));
    func_8003C1D0(D_800FC7D0, 0, D_800FC7CC * sizeof(unk_D_800FC7D0));

    D_800FC7E8 = alHeapAlloc(&D_800FC7B8, 1, arg0->unk_2C);
    D_800FC7EC = 0;
    D_800FC7F0 = arg0->unk_2C;

    D_800FC7FC = alHeapAlloc(&D_800FC7B8, arg0->unk_04, sizeof(unk_D_800FC7D0_148));
    D_800FC804 = NULL;
    D_800FC800 = NULL;
    D_800FC808 = NULL;
    D_800FC80C = NULL;
    D_800FC818 = 0;
    D_800FC81C = 0;

    for (i = 0; i < arg0->unk_04; i++) {
        func_8003C2F8(D_800FC7FC++);
    }

    sp4C.maxVVoices = arg0->unk_04;
    sp4C.maxPVoices = arg0->unk_08;
    sp4C.maxUpdates = arg0->unk_14;
    sp4C.dmaproc = NULL;
    sp4C.fxType = AL_FX_BIGROOM;
    sp4C.heap = &D_800FC7B8;

    sp40.outputRate = arg0->unk_18;
    sp40.framesPerField = arg0->unk_20;
    sp40.maxACMDSize = arg0->unk_1C;

    amCreateAudioMgr(&sp4C, &sp40, arg0->unk_24, arg0->unk_28, D_800FC7D4);

    D_800FC814 = arg0->unk_04;
    D_800FC7E0 = 1;
    D_800FC7F8 = 0;
    D_800FC7DE = 0x7FFF;
    D_800FC7DC = 0x7FFF;

    D_80077C90 = -1;
    D_80077DE4 = 0;
    D_80077C94 = 1;

    D_800FC7A0.next = NULL;
    D_800FC7A0.handler = func_8003A78C;
    D_800FC7A0.clientData = &D_800FC7A0;

    n_alSynAddPlayer(&D_800FC7A0);

    for (i = 0; i < D_800FC7CC; i++) {
        D_800FC7D0[i].unk_0E1 = 0;
        D_800FC7D0[i].unk_038 = 0;
        func_8003BFF4(&D_800FC7D0[i]);
    }

    return D_800FC7B8.cur - D_800FC7B8.base;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/38BB0/func_80038B68.s")
#endif

void func_80038E98(s32 arg0, u32 arg1) {
    u8* temp_a0;
    u32 sp18 = osSetIntMask(1);

    temp_a0 = D_800FC7E8;
    temp_a0 += D_800FC7EC;

    *temp_a0++ = 9;
    *temp_a0++ = arg0;
    func_80038B54(temp_a0, arg1);
    temp_a0 += 2;

    D_800FC7EC += 4;
    if (D_800FC7EC >= D_800FC7F0) {
        D_800FC7EC -= 4;
    }

    osSetIntMask(sp18);
}

s32 func_80038F30(SoundBank* arg0, s32 arg1) {
    u8* temp_a0;
    u32 sp20;
    UNUSED s32 pad;
    u32 sp18;

    if (arg0 == 0) {
        return 0;
    }

    if (!(arg0->flags & 1)) {
        return 0;
    }

    sp18 = osSetIntMask(1);

    temp_a0 = D_800FC7E8;
    temp_a0 += D_800FC7EC;

    sp20 = D_800FC7E0;
    D_800FC7E0++;

    *temp_a0++ = 0;
    func_80038B30(temp_a0, arg0);
    temp_a0 += 4;
    func_80038B30(temp_a0, arg1);
    temp_a0 += 4;
    func_80038B30(temp_a0, sp20);
    temp_a0 += 4;

    D_800FC7EC += 0xD;
    if (D_800FC7EC >= D_800FC7F0) {
        D_800FC7EC -= 0xD;
    }

    osSetIntMask(sp18);
    return sp20;
}

s32 func_80039024(SoundBank* arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5) {
    u32 sp2C;
    UNUSED s32 pad[2];
    u32 sp20;
    u8* temp_s0;

    if (D_80077DE4 != 0) {
        return 0;
    }

    if (arg0 == NULL) {
        return 0;
    }

    if (!(arg0->flags & 1)) {
        return 0;
    }

    sp20 = osSetIntMask(1);

    temp_s0 = D_800FC7E8;
    temp_s0 += D_800FC7EC;

    sp2C = D_800FC7E0;
    D_800FC7E0++;

    *temp_s0++ = 1;
    func_80038B30(temp_s0, arg0);
    temp_s0 += 4;
    func_80038B30(temp_s0, arg1);
    temp_s0 += 4;
    func_80038B30(temp_s0, sp2C);
    temp_s0 += 4;
    func_80038B30(temp_s0, arg2);
    temp_s0 += 4;

    *temp_s0++ = arg3;
    *temp_s0++ = arg4;
    *temp_s0++ = arg5;

    D_800FC7EC += 0x14;
    if (D_800FC7EC >= D_800FC7F0) {
        D_800FC7EC -= 0x14;
    }

    osSetIntMask(sp20);
    return sp2C;
}

void func_8003916C(s32 arg0, u32 arg1) {
    u8* temp_a0;
    u32 sp18 = osSetIntMask(1);

    temp_a0 = D_800FC7E8;
    temp_a0 += D_800FC7EC;

    *temp_a0++ = 8;
    *temp_a0++ = arg0;
    func_80038B54(temp_a0, arg1);
    temp_a0 += 2;

    D_800FC7EC += 4;
    if (D_800FC7EC >= D_800FC7F0) {
        D_800FC7EC -= 4;
    }

    osSetIntMask(sp18);
}

s32 func_80039204(s32 arg0) {
    s32 i;
    s32 sp20;
    unk_D_800FC7D0* var_v1;
    u32 sp18;

    sp18 = osSetIntMask(1);

    for (i = 0, sp20 = 0, var_v1 = D_800FC7D0; i < D_800FC7CC; i++, var_v1++) {
        if (var_v1->unk_038 != NULL) {
            if (((var_v1->unk_0BA != 0) && (arg0 & 1)) || ((var_v1->unk_0BA == 0) && (arg0 & 2))) {
                sp20++;
            }
        }
    }

    osSetIntMask(sp18);
    return sp20;
}

void func_800392A8(s32 arg0, u32 arg1) {
    UNUSED s32 pad;
    u8* temp_a0;
    u32 sp1C;

    if (arg0 != 0) {
        sp1C = osSetIntMask(1);

        temp_a0 = D_800FC7E8;
        temp_a0 += D_800FC7EC;

        *temp_a0++ = 7;
        func_80038B30(temp_a0, arg0);
        temp_a0 += 4;
        func_80038B54(temp_a0, (u16)arg1);

        D_800FC7EC += 7;
        if (D_800FC7EC >= D_800FC7F0) {
            D_800FC7EC -= 7;
        }

        osSetIntMask(sp1C);
    }
}

s32 func_80039354(s32 arg0) {
    unk_D_800FC7D0* var_a0;
    s32 i;
    s32 sp1C;
    u32 sp18;

    if (arg0 == 0) {
        return 0;
    }

    sp18 = osSetIntMask(1);

    for (i = 0, sp1C = 0, var_a0 = D_800FC7D0; i < D_800FC7CC; i++, var_a0++) {
        if (arg0 == var_a0->unk_064) {
            sp1C++;
        }
    }

    osSetIntMask(sp18);

    return sp1C;
}

void func_800393DC(s32 arg0, u32 arg1) {
    u8* temp_a0;
    UNUSED s32 pad[2];
    u32 sp18;

    if (arg0 != 0) {
        sp18 = osSetIntMask(1);

        temp_a0 = D_800FC7E8;
        temp_a0 += D_800FC7EC;

        *temp_a0++ = 4;
        func_80038B30(temp_a0, arg0);
        temp_a0 += 4;
        func_80038B54(temp_a0, (u16)arg1);

        D_800FC7EC += 7;
        if (D_800FC7EC >= D_800FC7F0) {
            D_800FC7EC -= 7;
        }

        osSetIntMask(sp18);
    }
}

void func_80039488(s32 arg0, u16 arg1) {
    u8* temp_a0;
    UNUSED s32 pad[2];
    u32 sp18;

    if (arg0 != 0) {
        sp18 = osSetIntMask(1);

        temp_a0 = D_800FC7E8;
        temp_a0 += D_800FC7EC;

        *temp_a0++ = 5;
        func_80038B30(temp_a0, arg0);
        temp_a0 += 4;
        func_80038B54(temp_a0, arg1);
        temp_a0 += 2;

        D_800FC7EC += 7;
        if (D_800FC7EC >= D_800FC7F0) {
            D_800FC7EC -= 7;
        }
        osSetIntMask(sp18);
    }
}

void func_80039534(s32 arg0, f32 arg1) {
    u8* temp_a0;
    UNUSED s32 pad[3];
    u32 sp1C;
    UNUSED s32 pad2;

    if (arg0 != 0) {
        sp1C = osSetIntMask(1);

        temp_a0 = D_800FC7E8;
        temp_a0 += D_800FC7EC;

        *temp_a0++ = 2;
        func_80038B30(temp_a0, arg0);
        temp_a0 += 4;
        func_80038B54(temp_a0, (s32)(255.0f * arg1) & 0xFFFF);

        D_800FC7EC += 7;
        if (D_800FC7EC >= D_800FC7F0) {
            D_800FC7EC -= 7;
        }

        osSetIntMask(sp1C);
    }
}

void func_800395FC(s32 arg0, s32 arg1) {
    u8* temp_a0;
    UNUSED s32 pad;
    u32 sp1C;

    if (arg0 != 0) {
        if (arg1 <= 0) {
            arg1 = 1;
        } else if (arg1 > 0x100) {
            arg1 = 0x100;
        }
        arg1--;

        sp1C = osSetIntMask(1);
        temp_a0 = D_800FC7E8;
        temp_a0 += D_800FC7EC;

        *temp_a0++ = 3;
        func_80038B30(temp_a0, arg0);
        temp_a0 += 4;
        func_80038B54(temp_a0, arg1 & 0xFFFF);

        D_800FC7EC += 7;
        if (D_800FC7EC >= D_800FC7F0) {
            D_800FC7EC -= 7;
        }

        osSetIntMask(sp1C);
    }
}

void func_800396D0(u32 arg0, s32 arg1) {
    u8* temp_a0;
    UNUSED s32 pad;
    u32 sp1C;

    if (arg0 != 0) {
        if (arg1 < 0) {
            arg1 = 0;
        } else if (arg1 >= 0x80) {
            arg1 = 0x7F;
        }

        sp1C = osSetIntMask(1);

        temp_a0 = D_800FC7E8;
        temp_a0 += D_800FC7EC;

        *temp_a0++ = 3;
        func_80038B30(temp_a0, arg0);
        temp_a0 += 4;

        *temp_a0++ = arg1;

        D_800FC7EC += 6;
        if (D_800FC7EC >= D_800FC7F0) {
            D_800FC7EC -= 6;
        }

        osSetIntMask(sp1C);
    }
}

void func_8003979C(s32 arg0, s32 arg1) {
    func_8003BD2C(arg0, arg1);
}

void func_800397BC(unk_func_800397BC* arg0) {
    u32 i;
    u32* ptr;
    u32 num_entries;
    u32 val;
    u32 a0 = (u32)arg0;

    if (arg0->flags & 2) {
        return;
    }

    num_entries = arg0->num_entries;

    val = arg0->unk_offset;
    arg0->unk_offset = a0 + val;

    val = arg0->entries_offset;
    arg0->entries_offset = a0 + val;

    ptr = arg0->entries_offset;
    if (0) {}

    for (i = 0; i < num_entries; i++, ptr++) {
        *ptr += a0;
    }

    arg0->flags |= 2;
}

void func_8003986C(s32 arg0) {
    u32 temp_v0 = osSetIntMask(1);
    u8* temp_v1 = D_800FC7E8;

    temp_v1 += D_800FC7EC;

    *temp_v1++ = 0xA;
    *temp_v1++ = arg0;

    D_800FC7EC += 2;
    if (D_800FC7EC >= D_800FC7F0) {
        D_800FC7EC -= 2;
    }

    osSetIntMask(temp_v0);
}

void func_800398F0(s32 arg0) {
    u32 temp_a0 = osSetIntMask(1);

    if (arg0 != 0) {
        D_80077C94 = 1;
    } else {
        D_80077C94 = 0;
    }

    osSetIntMask(temp_a0);
}

void func_80039940(void) {
    UNUSED s32 pad[4];
    u32 sp34 = osSetIntMask(1);
    u32 i;
    unk_D_800FC7D0* ptr = D_800FC7D0;

    for (i = 0; i < D_800FC7CC; i++, ptr++) {
        if ((ptr->unk_0BA != 0) || (ptr->unk_038 == 0)) {
            continue;
        }

        ptr->unk_038 = func_80037FB0(ptr, 0);

        if (ptr->unk_0E1 == 0) {
            ptr->unk_03C = 0;
            continue;
        }

        ptr->unk_148->unk_2A = 4;
        ptr->unk_148->unk_24 = D_800FC7F8 + 2;

        n_alSynSetVol(&ptr->unk_148->voice, 0, D_800FC7D8 * 2);

        func_800429B0(&ptr->unk_148->voice, 0);
        func_8003C3A0(ptr->unk_148);

        ptr->unk_148 = NULL;
        ptr->unk_0DC = 1;
        ptr->unk_0E1 = 0;
        ptr->unk_03C = 0;
    }

    osSetIntMask(sp34);
}

s32 func_80039A7C(SoundBank* arg0, s32 arg1, s32 arg2) {
    u8* temp_s0;
    s32 sp28;
    UNUSED s32 pad;
    u32 sp20;

    if (arg0 == NULL) {
        return 0;
    }

    if (!(arg0->flags & 1)) {
        return 0;
    }

    sp20 = osSetIntMask(1);

    temp_s0 = D_800FC7E8;
    temp_s0 += D_800FC7EC;

    sp28 = D_800FC7E0++;

    *temp_s0++ = 11;
    func_80038B30(temp_s0, arg0->header_name);
    temp_s0 += sizeof(u32);
    func_80038B30(temp_s0, arg1);
    temp_s0 += sizeof(u32);
    func_80038B30(temp_s0, sp28);
    temp_s0 += sizeof(u32);
    func_80038B30(temp_s0, arg2);

    D_800FC7EC += 17;
    if (D_800FC7EC >= D_800FC7F0) {
        D_800FC7EC -= 17;
    }

    osSetIntMask(sp20);

    return sp28;
}

s32 func_80039B88(s32 arg0, u8 arg1, u8 arg2, u32 arg3) {
    u32 temp_v0;

    if (arg1 == arg2) {
        return 0;
    }

    if (D_80077DC4 != 0) {
        return 0;
    }

    temp_v0 = osSetIntMask(1);

    D_80077DC4 = arg0;
    D_80077DD0 = ((f32)arg2 - arg1) / arg3;
    D_80077DC8 = arg1;
    D_80077DCC = arg2;

    osSetIntMask(temp_v0);

    return 1;
}

u32 func_80039C84(u8* arg0) {
    u32 val = *arg0++ << 0x18;
    val += *arg0++ << 0x10;
    val += *arg0++ << 8;
    val += *arg0++;
    return val;
}

u16 func_80039CB4(u8* arg0) {
    u32 val = *arg0++ << 8;
    val += *arg0++;
    return val;
}

void func_80039CD0(void) {
    u8* var_s0 = D_800FC7E8;
    s32 idx;

    while (D_800FC7EC) {
        idx = *var_s0++;
        D_800FC7EC--;
        var_s0 = D_80077D5C[idx](var_s0);
    }
}

u8* func_80039D58(u8* arg0) {
    unk_D_800FC7D0_08C* sp4C;
    unk_D_800FC7D0_08C* temp_s2;
    unk_D_800FC7D0_08C* sp44;
    unk_D_800FC7D0* temp_s0;
    u32 i;
    u32 count;
    u32 temp_v0;

    sp44 = func_80039C84(arg0);
    arg0 += 4;
    temp_s2 = func_80039C84(arg0);
    arg0 += 4;
    sp4C = func_80039C84(arg0);
    arg0 += 4;

    D_800FC7EC -= 0xC;

    count = temp_s2->unk_00;
    if ((u32)temp_s2->unk_04 < 0x400) {
        func_8003C204(&temp_s2->unk_04, temp_s2, 5);
        func_8003C204(temp_s2->unk_04, temp_s2, count);
        func_8003C204(temp_s2->unk_08, temp_s2, count);
        func_8003C204(temp_s2->unk_0C, temp_s2, count);
    }

    for (i = 0; i < count; i++) {
        if (temp_s2->unk_04[i] == 0) {
            continue;
        }

        temp_v0 = func_8003C180(temp_s2, i);
        if (temp_v0 == -1) {
            continue;
        }

        temp_s0 = &D_800FC7D0[temp_v0];
        func_8003BFF4(temp_s0);
        temp_s0->unk_08C = temp_s2;
        temp_s0->unk_090 = sp44;
        temp_s0->unk_060 = temp_s0->unk_0A0 = temp_s0->unk_08C->unk_08[i];
        temp_s0->unk_05C = temp_s0->unk_09C = temp_s0->unk_08C->unk_0C[i];
        temp_s0->unk_038 = temp_s0->unk_094 = temp_s0->unk_08C->unk_04[i];
        temp_s0->unk_064 = sp4C;
        temp_s0->unk_068 = 0x3C;
    }

    D_80077C90 = -1;
    return arg0;
}

u8* func_80039F28(u8* arg0) {
    u32 sp5C;
    u32 i;
    u32 sp54;
    s32 temp_v0;
    u32 temp_fp;
    unk_D_800FC7D0_08C* temp_s2;
    unk_D_800FC7D0* temp_s0;
    u32 sp40;

    sp54 = func_80039C84(arg0);
    arg0 += 4;
    temp_s2 = func_80039C84(arg0);
    arg0 += 4;
    sp5C = func_80039C84(arg0);
    arg0 += 4;
    sp40 = func_80039C84(arg0);
    arg0 += 4;

    D_800FC7EC -= 0x10;

    temp_fp = temp_s2->unk_00;
    if ((u32)temp_s2->unk_04 < 0x400) {
        func_8003C204(&temp_s2->unk_04, temp_s2, 5);
        func_8003C204(temp_s2->unk_04, temp_s2, temp_fp);
        func_8003C204(temp_s2->unk_08, temp_s2, temp_fp);
        func_8003C204(temp_s2->unk_0C, temp_s2, temp_fp);
    }

    for (i = 0; i < temp_fp; i++) {
        if (temp_s2->unk_04[i] == 0) {
            continue;
        }

        temp_v0 = func_8003C180(temp_s2, i);
        if (temp_v0 == -1) {
            continue;
        }

        temp_s0 = &D_800FC7D0[temp_v0];
        func_8003BFF4(temp_s0);
        temp_s0->unk_08C = temp_s2;
        temp_s0->unk_090 = sp54;
        temp_s0->unk_060 = temp_s0->unk_0A0 = temp_s2->unk_08[i];
        temp_s0->unk_05C = temp_s0->unk_09C = temp_s2->unk_0C[i];
        temp_s0->unk_038 = temp_s0->unk_094 = temp_s2->unk_04[i];
        temp_s0->unk_064 = sp5C;
        temp_s0->unk_068 = 0x3C;
    }

    D_80077C90 = sp40;
    return arg0;
}

u8* func_8003A10C(u8* arg0) {
    u32 sp44;
    unk_D_800FC7D0_140* sp40;
    u32* sp3C;
    u32 sp38;
    u32 sp34;
    u32 i;
    u8 var_t0;
    u8 var_t1;
    u8 var_t2;
    unk_D_800FC7D0* var_a0;
    unk_D_800FC7D0_08C_008* a;

    sp44 = func_80039C84(arg0);
    arg0 += 4;
    sp40 = func_80039C84(arg0);
    arg0 += 4;
    sp38 = func_80039C84(arg0);
    arg0 += 4;
    sp34 = func_80039C84(arg0);
    arg0 += 4;

    var_t2 = *arg0++;
    var_t1 = *arg0++;
    var_t0 = *arg0++;

    D_800FC7EC -= 0x13;
    sp3C = sp40->unk_0C;
    a = sp40->unk_08;

    if (var_t0 == 0xFF) {
        var_t0 = a[sp34].unk_00[3];
    }

    for (i = 0, var_a0 = D_800FC7D0; i < D_800FC7CC; i++, var_a0++) {
        if (var_a0->unk_038 == NULL) {
            func_8003C2A4(var_a0, sp34, var_t2, var_t1, var_t0);
            var_a0->unk_064 = sp38;
            var_a0->unk_090 = sp44;
            var_a0->unk_140 = sp40;
            var_a0->unk_038 = var_a0->unk_094 = sp3C[sp34];
            break;
        }
    }

    return arg0;
}

u8* func_8003A234(u8* arg0) {
    u32 sp1C;
    s32 i;
    s16 temp_v0;
    unk_D_800FC7D0* var_a0;

    sp1C = func_80039C84(arg0);
    arg0 += 4;
    temp_v0 = func_80039CB4(arg0);
    arg0 += 2;

    D_800FC7EC -= 6;

    for (i = 0, var_a0 = D_800FC7D0; i < D_800FC7CC; i++, var_a0++) {
        if (sp1C == var_a0->unk_064) {
            var_a0->unk_058 = var_a0->unk_0A4 + (temp_v0 / 255.0f);
        }
    }

    return arg0;
}

u8* func_8003A2F0(u8* arg0) {
    u32 sp24;
    u16 temp_v0;
    unk_D_800FC7D0* var_v1;
    u32 i;
    u8 val;

    sp24 = func_80039C84(arg0);
    arg0 += 4;
    temp_v0 = func_80039CB4(arg0);
    arg0 += 2;

    D_800FC7EC -= 6;

    for (i = 0, var_v1 = D_800FC7D0; i < D_800FC7CC; i++, var_v1++) {
        if (sp24 == var_v1->unk_064) {
            val = temp_v0;
            var_v1->unk_0AC = val;
            var_v1->unk_0B0 = (var_v1->unk_0BC * val) >> 7;
        }
    }

    return arg0;
}

u8* func_8003A39C(u8* arg0) {
    u32 sp1C;
    u32 i;
    unk_D_800FC7D0* var_v1;
    u16 temp_v0;
    u8 val;

    sp1C = func_80039C84(arg0);
    arg0 += 4;
    temp_v0 = func_80039CB4(arg0);
    arg0 += 2;

    D_800FC7EC -= 6;

    for (i = 0, var_v1 = D_800FC7D0; i < D_800FC7CC; i++, var_v1++) {
        if (sp1C == var_v1->unk_064) {
            val = temp_v0;
            var_v1->unk_0B2 = val;
        }
    }

    return arg0;
}

u8* func_8003A438(u8* arg0) {
    u32 sp24;
    u32 i;
    u16 temp_v0;
    unk_D_800FC7D0* var_v1;
    u8 val;

    sp24 = func_80039C84(arg0);
    arg0 += 4;
    temp_v0 = func_80039CB4(arg0);
    arg0 += 2;

    D_800FC7EC -= 6;

    for (i = 0, var_v1 = D_800FC7D0; i < D_800FC7CC; i++, var_v1++) {
        if (sp24 == var_v1->unk_064) {
            val = temp_v0;
            var_v1->unk_0C4 = val;
            var_v1->unk_0D2 = 0xFF;
        }
    }

    return arg0;
}

u8* func_8003A4D8(u8* arg0) {
    u32 i;
    u32 temp_v0;
    unk_D_800FC7D0* var_v1;
    u8 val;

    temp_v0 = func_80039C84(arg0);
    arg0 += 4;
    val = *arg0++;

    D_800FC7EC -= 5;

    for (i = 0, var_v1 = D_800FC7D0; i < D_800FC7CC; i++, var_v1++) {
        if (temp_v0 == var_v1->unk_064) {
            var_v1->unk_0E3 = val;
            var_v1->unk_0E4 = 0xFF;
        }
    }

    return arg0;
}

u8* func_8003A564(u8* arg0) {
    u32 sp24;
    u32 i;
    u32 var_a2;
    u16 temp_v0;
    unk_D_800FC7D0* var_v1;

    sp24 = func_80039C84(arg0);
    arg0 += 4;
    temp_v0 = func_80039CB4(arg0);
    arg0 += 2;

    D_800FC7EC -= 6;

    if (sp24 != 0) {
        if (temp_v0 != 0) {
            var_a2 = temp_v0 & 0xFFFF;
        } else {
            var_a2 = 1;
        }

        for (i = 0, var_v1 = D_800FC7D0; i < D_800FC7CC; i++, var_v1++) {
            if (sp24 == var_v1->unk_064) {
                var_v1->unk_040 = temp_v0;
                var_v1->unk_044 = var_a2;
            }
        }
    }

    return arg0;
}

u8* func_8003A614(u8* arg0) {
    u8 sp27;
    u32 i;
    u32 var_t0;
    u32 temp_v0;
    unk_D_800FC7D0* var_a0;

    sp27 = *arg0++;
    temp_v0 = func_80039CB4(arg0);
    arg0 += 2;

    D_800FC7EC -= 3;

    if (temp_v0 != 0) {
        var_t0 = temp_v0 & 0xFFFF;
    } else {
        var_t0 = 1;
    }

    for (i = 0, var_a0 = D_800FC7D0; i < D_800FC7CC; i++, var_a0++) {
        if (((var_a0->unk_0BA != 0) && (sp27 & 1)) || ((var_a0->unk_0BA == 0) && (sp27 & 2))) {
            var_a0->unk_040 = temp_v0;
            var_a0->unk_044 = var_t0;
        }
    }

    return arg0;
}

u8* func_8003A6D4(u8* arg0) {
    u8 sp1F;
    u16 temp_v0;

    sp1F = *arg0++;
    temp_v0 = func_80039CB4(arg0);
    arg0 += 2;

    D_800FC7EC -= 3;

    if (sp1F & 1) {
        D_800FC7DC = temp_v0;
    }

    if (sp1F & 2) {
        D_800FC7DE = temp_v0;
    }

    return arg0;
}

u8* func_8003A744(u8* arg0) {
    u8 val = *arg0++;

    D_800FC7EC--;

    if (val == 1) {
        D_800FC7F4 = 1;
    } else {
        D_800FC7F4 = 0;
    }
    return arg0;
}

#ifdef NON_MATCHING
s32 func_8003A78C(void* arg0) {
    s32 i;
    UNUSED s32 pad4[1];
    f32 spA4;
    UNUSED s32 pad[4];
    ALVoiceConfig sp8C;
    UNUSED s32 pad2[3];
    UNUSED s32 pad3[1];
    f32 var_fs0;
    s32 temp_s3;
    u32 var_s4;
    u32 temp_s1;
    s32 var_s2;
    unk_D_800FC7D0* ptr;

    if (D_80077C90 > 0) {
        D_80077C90--;
    }

    if (D_80077C90 == 0) {
        func_80039940();
        D_80077C90 = -1;
    }

    func_80039CD0();

    ptr = D_800FC7D0;

    for (i = 0; i < D_800FC7CC; i++, ptr++) {
        if (ptr->unk_038 == 0) {
            continue;
        }

        ptr->unk_008 += ptr->unk_0B0;

        if (ptr->unk_0AE != 0x7FFF) {
            while ((ptr->unk_008 > ptr->unk_020) && (ptr->unk_038 != 0)) {
                func_8003AD58(ptr);
            }
        }

        if (ptr->unk_060 != 0) {
            if (ptr->unk_010 < ptr->unk_008) {
                func_8003B94C(ptr);
            }
        }

        if (ptr->unk_05C != 0) {
            if (ptr->unk_018 < ptr->unk_008) {
                func_8003BA44(ptr);
            }
        }

        if (ptr->unk_040 != -1) {
            ptr->unk_040--;
            if (ptr->unk_040 == -1) {
                ptr->unk_038 = func_80037FB0(ptr, 0);
                if (ptr->unk_0E1 != 0) {
                    ptr->unk_0E1 = 0;
                    n_alSynStopVoice(&ptr->unk_148->voice);
                    n_alSynFreeVoice(&ptr->unk_148->voice);
                    ptr->unk_148->unk_2A = 5;
                    func_8003C2F8(ptr->unk_148);
                    ptr->unk_148 = NULL;
                    ptr->unk_0BA = 0;
                }
                ptr->unk_03C = 0;
            }
        }

        if (ptr->unk_03C == 0) {
            continue;
        }

        func_8003B2B4(ptr);

        if (ptr->unk_03C == 0) {
            continue;
        }

        spA4 = ptr->unk_058;
        if (ptr->unk_0EC != 0) {
            spA4 += func_8003B8A4(ptr);
        }

        if (ptr->unk_0E5 != 0) {
            spA4 += func_8003B854(ptr);
        }

        var_fs0 = func_8003B0DC(ptr, spA4);
        temp_s3 = func_8003B00C(ptr);

        if (ptr->unk_0EB != 0) {
            if (ptr->unk_0A8 < ptr->unk_008) {
                func_8003B788(ptr);
            }
        }

        if (D_800FC7F4 == 1) {
            var_s2 = 0x40;
        } else {
            var_s2 = ((ptr->unk_0D1 * ptr->unk_0C4) >> 7) & 0x7F;
        }

        var_s4 = ptr->unk_008 - ptr->unk_028;
        ptr->unk_0BE = var_s4 >> 8;

        temp_s1 = ptr->unk_0E3;
        temp_s1 += (((0x80 - temp_s1) * ptr->unk_0E2) >> 7);

        if (ptr->unk_0E1 != 0) {
            if (var_fs0 != 0.0f) {
                n_alSynSetPitch(&ptr->unk_148->voice, var_fs0);
            }

            if (temp_s3 != ptr->unk_0B4) {
                ptr->unk_0B4 = temp_s3;
                n_alSynSetVol(&ptr->unk_148->voice, temp_s3, D_800FC7D8);
            }

            if (var_s2 != ptr->unk_0D2) {
                ptr->unk_0D2 = var_s2;
                n_alSynSetPan(&ptr->unk_148->voice, var_s2);
            }

            if (ptr->unk_0E2 != ptr->unk_0E4) {
                ptr->unk_0E4 = temp_s1;
                n_alSynSetFXMix(&ptr->unk_148->voice, temp_s1);
            }
        } else {
            ptr->unk_148 = func_8003C35C();
            if (ptr->unk_148 == NULL) {
                ptr->unk_03C = 0;
                continue;
            }

            ptr->unk_148->unk_2A = ptr->unk_0D7;
            ptr->unk_148->unk_28 = ptr->unk_0E0;

            if (ptr->unk_068 >= 0x80) {
                sp8C.priority = 0x7F;
            } else {
                sp8C.priority = ptr->unk_068;
            }

            sp8C.unityPitch = 0;
            sp8C.fxBus = 0;
            n_alSynAllocVoice(&ptr->unk_148->voice, &sp8C);

            ptr->unk_0B4 = temp_s3;
            ptr->unk_0D2 = var_s2;
            ptr->unk_0E4 = temp_s1;

            if (var_fs0 == 0.0f) {
                var_fs0 = func_8003BBA4(ptr->unk_050 * 0.0833333333333333287);
                if (var_fs0 > 2.0) {
                    var_fs0 = 2.0f;
                }
            }

            if (D_80077C94 == 0) {
                n_alSynStartVoiceParams(&ptr->unk_148->voice, ptr->unk_03C, var_fs0, temp_s3, var_s2, temp_s1,
                                        D_800FC7D8);
            } else {
                n_alSynStartVoiceParams(&ptr->unk_148->voice, ptr->unk_03C, var_fs0, temp_s3, var_s2, temp_s1, 1);
            }

            ptr->unk_0DC = 0;
            ptr->unk_0E1 = 1;
            ptr->unk_148->unk_2A = 1;
        }
    }

    func_8003C408();
    D_800FC7F8++;

    return D_800FC7D8;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/38BB0/func_8003A78C.s")
#endif

void func_8003AD58(unk_D_800FC7D0* arg0) {
    s32 pad[2];
    unk_D_800FC7D0_08C* temp_s0;
    u8* var_s0;
    u8 temp_a0;
    u8 tmp;
    u8 tmp1;
    u16 tmp2;
    u32 tmp3;

    var_s0 = arg0->unk_038;
    while (var_s0 != NULL && (tmp1 = *var_s0) >= 0x80) {
        var_s0 = D_80077C98[tmp1 & 0x7F](arg0, var_s0 + 1);
    }
    arg0->unk_038 = var_s0;

    if (arg0->unk_038 != NULL) {
        arg0->unk_06C = arg0->unk_070;
        tmp = *arg0->unk_038++;

        if (arg0->unk_0E9 != 0) {
            arg0->unk_0CF = *arg0->unk_038++;
        } else {
            arg0->unk_0CF = arg0->unk_0EA;
        }

        if (arg0->unk_0C0 != 0) {
            if (arg0->unk_0CB == 0) {
                arg0->unk_0AE = arg0->unk_0C0;
            } else {
                arg0->unk_0CB = 0;
                temp_a0 = *arg0->unk_038++;
                if (temp_a0 < 0x80) {
                    arg0->unk_0AE = temp_a0;
                } else {
                    arg0->unk_0AE = *arg0->unk_038++ + ((temp_a0 & 0x7F) << 8);
                }
            }
        } else {
            temp_a0 = *arg0->unk_038++;
            if (temp_a0 < 0x80) {
                arg0->unk_0AE = temp_a0 ^ 0;
            } else {
                arg0->unk_0AE = *arg0->unk_038++ + ((temp_a0 & 0x7F) << 8);
            }
        }

        arg0->unk_028 = arg0->unk_020;
        arg0->unk_020 += arg0->unk_0AE << 8;

        arg0->unk_0BE = 0;
        arg0->unk_0E8 = 0;
        arg0->unk_0E7 = arg0->unk_0E6;

        if (tmp != 0x60) {
            temp_s0 = arg0->unk_090;
            func_8003B214(arg0);

            if (arg0->unk_0EB != 0) {
                func_8003B76C(arg0);
            }

            if (arg0->unk_0E1 != 0) {
                arg0->unk_03C = NULL;
                func_8003B2B4(arg0);
            }

            tmp2 = arg0->unk_0C2;
            tmp3 = temp_s0->unk_2C[tmp2];
            arg0->unk_03C = tmp3;
            arg0->unk_054 = temp_s0->unk_28[tmp2] + tmp;
        } else {
            arg0->unk_03C = NULL;
            if (arg0->unk_0E1 != 0) {
                arg0->unk_030 = arg0->unk_008;
                func_8003B2B4(arg0);
            }
        }
    } else {
        arg0->unk_03C = NULL;
        if (arg0->unk_0E1 != 0) {
            arg0->unk_030 = arg0->unk_008;
            func_8003B2B4(arg0);
        }
    }
}

s32 func_8003B00C(unk_D_800FC7D0* arg0) {
    u32 var_v1 = arg0->unk_0D0 * arg0->unk_0D8 * arg0->unk_0CF * arg0->unk_0B2;

    var_v1 >>= 0xD;
    if (arg0->unk_0BA == 0) {
        var_v1 *= D_800FC7DE;
    } else {
        var_v1 *= D_800FC7DC;
    }

    var_v1 >>= 0xF;
    if (var_v1 >= 0x8000) {
        var_v1 = 0x7FFF;
    }

    if (arg0->unk_040 != -1) {
        var_v1 = (arg0->unk_040 * var_v1) / arg0->unk_044;
    }

    return var_v1;
}

f32 func_8003B0DC(unk_D_800FC7D0* arg0, f32 arg1) {
    f32 temp_fv1;
    f32 var_fv1;
    f32 var_fv1_2;
    s32 temp_lo;

    temp_fv1 = arg0->unk_054;
    if (arg0->unk_0CC != 0) {
        if (arg0->unk_0CC >= arg0->unk_0BE) {
            var_fv1_2 = ((temp_fv1 - arg0->unk_06C) / arg0->unk_0CC);
            var_fv1_2 *= arg0->unk_0BE;
            temp_fv1 = arg0->unk_06C + var_fv1_2;
        }
        arg0->unk_070 = temp_fv1;
    }

    temp_lo = arg0->unk_0CD * (1 - arg0->unk_0CE);

    arg0->unk_0CE = 0;

    temp_fv1 += (arg1 + arg0->unk_04C + temp_lo);
    if (temp_fv1 == arg0->unk_050) {
        return 0.0f;
    }
    arg0->unk_050 = temp_fv1;

    temp_fv1 = func_8003BBA4(temp_fv1 * 0.0833333333333333287);
    if (temp_fv1 > 2.0) {
        temp_fv1 = 2.0f;
        arg0->unk_0CF = 0;
    }

    return temp_fv1;
}

void func_8003B214(unk_D_800FC7D0* arg0) {
    s32 temp_t7;
    s32 temp_t7_2;
    u16 temp_v0;
    u32 temp_t3;
    u32 temp_t5;

    if (arg0->unk_0AE != 0x7FFF) {
        if (arg0->unk_0C6 != 0) {
            arg0->unk_030 = arg0->unk_028 + (arg0->unk_0C6 << 8);
        } else {
            arg0->unk_030 = arg0->unk_020 - (arg0->unk_0C8 << 8);
        }
    } else {
        arg0->unk_030 = 0x7FFFFFFF;
    }

    arg0->unk_0D8 = arg0->unk_0D4;
    arg0->unk_0D9 = arg0->unk_0D3;
    arg0->unk_0D7 = 1;
}

void func_8003B2B4(unk_D_800FC7D0* arg0) {
    u32 temp_ft4;
    s32 var_v1;
    u32 temp_a0;

    if (arg0->unk_148 != NULL) {
        if (((arg0->unk_008 >= arg0->unk_030) && (arg0->unk_148->unk_2A < 4)) || (arg0->unk_03C == 0)) {
            arg0->unk_148->unk_2A = 4;
            temp_ft4 = (f32)arg0->unk_148->unk_28 / ((f32)arg0->unk_0B0 * 0.00390625);
            if (temp_ft4 == 0) {
                temp_ft4++;
            }
            arg0->unk_148->unk_24 = D_800FC7F8 + temp_ft4 + 1;

            n_alSynSetVol(&arg0->unk_148->voice, 0, D_800FC7D8 * temp_ft4);

            if (arg0->unk_068 < 0x80) {
                if (arg0->unk_0BA != 0) {
                    func_800429B0(&arg0->unk_148->voice, 1);
                } else {
                    func_800429B0(&arg0->unk_148->voice, 0);
                }
            }

            func_8003C3A0(arg0->unk_148);

            arg0->unk_148 = NULL;
            arg0->unk_0DC = 1;
            arg0->unk_0E1 = 0;
            arg0->unk_03C = 0;
        } else {
            switch (arg0->unk_148->unk_2A) {
                case 1:
                    temp_a0 = (u32)(arg0->unk_008 - arg0->unk_028) >> 8;
                    if (temp_a0 < arg0->unk_0DA) {
                        arg0->unk_0D8 = arg0->unk_074 * temp_a0;
                    } else {
                        arg0->unk_148->unk_2A++;
                        arg0->unk_0D8 = arg0->unk_0D5;
                    }
                    break;

                case 2:
                    temp_a0 = ((arg0->unk_008 - arg0->unk_028) >> 8) - arg0->unk_0DA;
                    if (temp_a0 < arg0->unk_0DB) {
                        arg0->unk_0D8 = arg0->unk_0D5 + (s32)(arg0->unk_078 * temp_a0);
                    } else {
                        arg0->unk_148->unk_2A++;
                        arg0->unk_0D8 = arg0->unk_0D6;
                    }
                    break;

                case 3:
                case 4:
                    break;
            }
        }
    } else {
        temp_a0 = (u32)(arg0->unk_008 - arg0->unk_028) >> 8;
        if ((temp_a0 < arg0->unk_0DA) && (arg0->unk_0DA >= 2)) {
            arg0->unk_0D7 = 1;
            arg0->unk_0D8 = arg0->unk_074 * temp_a0;
        } else {
            arg0->unk_0D7 = 2;
            arg0->unk_0D8 = arg0->unk_0D5;
        }
    }
}

void func_8003B76C(unk_D_800FC7D0* arg0) {
    arg0->unk_0A8 = arg0->unk_028;
    arg0->unk_0F0 = 0;
    arg0->unk_0F1 = arg0->unk_0C4 & 0x80;
}

void func_8003B788(unk_D_800FC7D0* arg0) {
    u32 temp_v1;
    u32 var_v0;

    do {
        arg0->unk_0A8 += 0x100;

        temp_v1 = arg0->unk_0F0 + (arg0->unk_0EB * 2);
        if (temp_v1 < 0x80) {
            arg0->unk_0F0 = temp_v1;
            continue;
        }

        arg0->unk_0F0 = temp_v1 & 0x7F;
        temp_v1 >>= 7;
        if (arg0->unk_0F1 == 0) {
            var_v0 = arg0->unk_0C4;
            var_v0 += temp_v1;
            if (var_v0 >= 0xFF) {
                var_v0 = 0xFE;
                arg0->unk_0F1 = 1;
            }
            arg0->unk_0C4 = var_v0;
        } else {
            var_v0 = arg0->unk_0C4;
            var_v0 -= temp_v1;
            if ((var_v0 >= 0xFF) || (var_v0 == 0)) {
                var_v0 = 1;
                arg0->unk_0F1 = 0;
            }
            arg0->unk_0C4 = var_v0;
        }
    } while (arg0->unk_0A8 < arg0->unk_008);

    arg0->unk_0D2 = 0xFF;
}

f32 func_8003B854(unk_D_800FC7D0* arg0) {
    arg0->unk_0E7--;
    if (!arg0->unk_0E7) {
        if (arg0->unk_0E8 == 0) {
            arg0->unk_0E8 = arg0->unk_0EF;
            arg0->unk_0E7 = arg0->unk_0E5;
        } else {
            arg0->unk_0E8 = 0;
            arg0->unk_0E7 = arg0->unk_0E6;
        }
    }

    return arg0->unk_0E8;
}

f32 func_8003B8A4(unk_D_800FC7D0* arg0) {
    u32 temp_v0 = arg0->unk_0BE - arg0->unk_0CA;
    f32 tmp;

    if (temp_v0 != 0) {
        tmp = __sinf(((temp_v0 / (f32)arg0->unk_0EC) * 2) * 3.14159260000000007) * arg0->unk_048;
        arg0->unk_080 = tmp;
    }
    return arg0->unk_080;
}

void func_8003B94C(unk_D_800FC7D0* arg0) {
    s32 tmp;

    do {
        arg0->unk_010 += 0x100;

        arg0->unk_0B6--;
        if (arg0->unk_0B6) {
            continue;
        }

        tmp = *arg0->unk_060++;
        if (tmp >= 0x80u) {
            arg0->unk_0D0 = tmp & 0x7F;

            tmp = *arg0->unk_060++;
            if (tmp >= 0x80u) {
                arg0->unk_0B6 = (tmp & 0x7F) << 8;
                arg0->unk_0B6 += *arg0->unk_060++ + 2;
            } else {
                arg0->unk_0B6 = tmp + 2;
            }
        } else {
            arg0->unk_0D0 = tmp;
            arg0->unk_0B6 = 1;
        }
    } while (arg0->unk_010 < arg0->unk_008);
}

void func_8003BA44(unk_D_800FC7D0* arg0) {
    u8 tmp;

    do {
        arg0->unk_018 += 0x100;

        arg0->unk_0B8--;
        if (arg0->unk_0B8) {
            continue;
        }

        tmp = *arg0->unk_05C++;
        if (tmp >= 0x80) {
            arg0->unk_088 = (f32)(tmp & 0x7F) - 64.0;
            arg0->unk_04C = arg0->unk_088 * arg0->unk_084;
            tmp = *arg0->unk_05C++;
            if (tmp >= 0x80) {
                arg0->unk_0B8 = (tmp & 0x7F) << 8;
                arg0->unk_0B8 += *arg0->unk_05C++ + 2;
            } else {
                arg0->unk_0B8 = tmp + 2;
            }
        } else {
            arg0->unk_088 = (f32)(tmp)-64.0;
            arg0->unk_04C = arg0->unk_088 * arg0->unk_084;
            arg0->unk_0B8 = 1;
        }
    } while (arg0->unk_018 < arg0->unk_008);
}

f32 func_8003BBA4(f32 arg0) {
    f32 temp_fa1;
    f32 temp_fv1;

    if (arg0 == 0.0f) {
        return 1.0f;
    }

    if (arg0 > 0.0f) {
        temp_fv1 = SQ(arg0);
        temp_fa1 = SQ(temp_fv1);
        return (arg0 * 0.693147180559944953) + 1.0 + (temp_fv1 * 0.240226506959100999) +
               ((temp_fv1 * arg0) * 0.055504108664821597) + (temp_fa1 * 0.00961812910762848035) +
               ((temp_fa1 * arg0) * 0.00133335581464283999) + ((temp_fa1 * temp_fv1) * 0.000154035303933816006);
    } else {
        arg0 = -arg0;
        temp_fv1 = SQ(arg0);
        temp_fa1 = SQ(temp_fv1);
        return 1.0 / ((arg0 * 0.693147180559944953) + 1.0 + (temp_fv1 * 0.240226506959100999) +
                      ((temp_fv1 * arg0) * 0.055504108664821597) + (temp_fa1 * 0.00961812910762848035) +
                      ((temp_fa1 * arg0) * 0.00133335581464283999) + ((temp_fa1 * temp_fv1) * 0.000154035303933816006));
    }
}

void func_8003BD2C(u8* arg0, s32 arg1) {
    UNUSED s32 pad;
    u32 i;
    f32 var_fv0;
    SoundBank* soundbank = arg0;
    u8 temp_v1;

    if (soundbank->flags & 1) {
        return;
    }

    soundbank->flags |= 1;

    func_8003C204(&soundbank->basenote, arg0, 3);
    func_8003C204(soundbank->wave_list, arg0, soundbank->count);

    for (i = 0; i < soundbank->count; i++) {
        f32* ptr = &soundbank->detune[i];

        temp_v1 = *(u8*)ptr;
        if (temp_v1 & 0x80) {
            var_fv0 = -(0x100 - temp_v1);
        } else {
            var_fv0 = (s32)temp_v1;
        }
        *ptr = var_fv0 / 100.0;

        temp_v1 = soundbank->basenote[i] - 0x30;
        if (temp_v1 & 0x80) {
            var_fv0 = -(0x100 - temp_v1);
        } else {
            var_fv0 = (s32)temp_v1;
        }
        *ptr += var_fv0;

        if (soundbank->wave_list[i]->flags == 0) {
            u32 tmp = soundbank->wave_list[i]->base;

            if ((tmp & 0xFF000000) != 0xFF000000) {
                tmp += arg1;
                soundbank->wave_list[i]->base = tmp;
            }

            soundbank->wave_list[i]->flags = 1;

            if (soundbank->wave_list[i]->waveInfo.rawWave.loop != NULL) {
                soundbank->wave_list[i]->waveInfo.rawWave.loop =
                    (u32)soundbank + (u32)soundbank->wave_list[i]->waveInfo.rawWave.loop;
            }

            if (soundbank->wave_list[i]->type == AL_ADPCM_WAVE) {
                soundbank->wave_list[i]->waveInfo.adpcmWave.book =
                    (u32)soundbank + (u32)soundbank->wave_list[i]->waveInfo.adpcmWave.book;
            }
        }
    }

    osWritebackDCacheAll();
}

s32 func_8003BEF4(s32 arg0) {
    s32 i;
    s32 tmp;
    f32 tmpf;

    for (i = 0; i < 8; i++) {
        tmp = D_800FC7E4 & 0x48000000;
        D_800FC7E4 <<= 1;
        if ((tmp == 0x48000000) || (tmp == 0x08000000)) {
            D_800FC7E4 |= 1;
        }
    }

    tmpf = D_800FC7E4 / 65536.0f;
    tmpf /= 65536.0f;
    return arg0 * tmpf;
}

void func_8003BFF4(unk_D_800FC7D0* arg0) {
    u8* ptr;
    s32 i;

    arg0->unk_038 = 0;
    arg0->unk_090 = 0;
    arg0->unk_03C = 0;
    arg0->unk_148 = NULL;

    arg0->unk_008 = 0;
    arg0->unk_010 = 0;
    arg0->unk_018 = 0;
    arg0->unk_020 = 0;
    arg0->unk_028 = 0;
    arg0->unk_030 = 0;

    ptr = (u8*)&arg0->unk_030 + 4;
    for (i = 0x34; i < 0x150; i++) {
        *ptr++ = 0;
    }

    arg0->unk_0B4 = 0xFFFF;
    arg0->unk_0E4 = -1;
    arg0->unk_0D2 = -1;
    arg0->unk_050 = 99.90000153f;

    arg0->unk_0B0 = arg0->unk_0BC = 0x6000 / D_800FC7D4;
    arg0->unk_0AE = 1;

    arg0->unk_0E9 = 0;
    arg0->unk_0EA = 0x7F;

    if (1) {}

    arg0->unk_0C0 = 0;
    arg0->unk_0CB = 0;
    arg0->unk_0D0 = 0x7F;
    arg0->unk_0D1 = 0x40;
    arg0->unk_0B6 = 1;
    arg0->unk_0B8 = 1;
    arg0->unk_040 = -1;
    arg0->unk_0EB = 0;
    arg0->unk_0B2 = 0x80;
    arg0->unk_0C4 = 0x80;
    arg0->unk_0AC = 0x80;
    arg0->unk_0D3 = 1;
    arg0->unk_0DA = 1;
    arg0->unk_0D5 = 0x7F;
    arg0->unk_0DB = -1;
    arg0->unk_084 = 0.03125f;

    arg0->unk_074 = 1.0f;
    arg0->unk_078 = 0.003921568859f;
    arg0->unk_04C = 0.0f;
    arg0->unk_058 = 0.0f;
    arg0->unk_070 = 0.0f;
    arg0->unk_0A4 = 0.0f;

    arg0->unk_0D6 = 0x7F;
    arg0->unk_0E0 = 1;
    arg0->unk_0DC = 1;
    arg0->unk_0EC = 0;
    arg0->unk_0E5 = 0;
    arg0->unk_0BA = 0;
    arg0->unk_0E1 = 0;
}

s32 func_8003C180(unk_D_800FC7D0_08C* arg0, s32 arg1) {
    s32 i;
    unk_D_800FC7D0* var_v0 = D_800FC7D0;

    for (i = 0; i < D_800FC7CC; i++, var_v0++) {
        if (var_v0->unk_038 == NULL) {
            return i;
        }
    }

    return -1;
}

void func_8003C1D0(u8* arg0, u8 arg1, u32 arg2) {
    u8* a0 = arg0;

    while (arg2--) {
        *a0++ = arg1;
    }
}

void func_8003C204(u8* arg0, u32 arg1, u32 arg2) {
    u32* ptr = arg0;
    u32 i;

    for (i = 0; i < arg2; i++) {
        if (ptr[i] != 0) {
            ptr[i] += arg1;
        }
    }
}

s32 func_8003C2A4(unk_D_800FC7D0* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_8003BFF4(arg0);
    arg0->unk_0BA = arg1;
    arg0->unk_0B2 = arg2;
    arg0->unk_0C4 = arg3;
    arg0->unk_068 = arg4;
    return arg0->unk_064;
}

void func_8003C2F8(unk_D_800FC7D0_148* arg0) {
    if (D_800FC800 == NULL) {
        D_800FC800 = D_800FC804 = arg0;
        arg0->node.next = NULL;
    } else {
        D_800FC804->node.next = arg0;
        arg0->node.next = NULL;
        D_800FC804 = arg0;
    }

    arg0->unk_2A = 5;
    D_800FC818++;
}

unk_D_800FC7D0_148* func_8003C35C(void) {
    unk_D_800FC7D0_148* temp_v0;

    if (D_800FC800 == NULL) {
        return NULL;
    }

    temp_v0 = D_800FC800;
    D_800FC800 = D_800FC800->node.next;

    D_800FC818--;
    return temp_v0;
}

void func_8003C3A0(unk_D_800FC7D0_148* arg0) {
    if (D_800FC808 == NULL) {
        D_800FC808 = D_800FC80C = arg0;
        arg0->node.next = NULL;
        arg0->node.prev = NULL;
    } else {
        D_800FC80C->node.next = arg0;
        arg0->node.next = NULL;
        arg0->node.prev = D_800FC80C;
        D_800FC80C = arg0;
    }

    D_800FC81C++;
}

void func_8003C408(void) {
    unk_D_800FC7D0_148* temp_s1;
    unk_D_800FC7D0_148* var_s0;

    if (D_800FC808 != NULL) {
        var_s0 = D_800FC808;

        do {
            if (var_s0->unk_24 < D_800FC7F8) {
                n_alSynStopVoice(&var_s0->voice);
                n_alSynFreeVoice(&var_s0->voice);

                var_s0->unk_2A = 5;
                if (var_s0->node.prev != NULL) {
                    if (var_s0->node.next != NULL) {
                        var_s0->node.prev->next = var_s0->node.next;
                        var_s0->node.next->prev = var_s0->node.prev;
                    } else {
                        var_s0->node.prev->next = NULL;
                        D_800FC80C = var_s0->node.prev;
                    }
                } else if (var_s0->node.next != NULL) {
                    D_800FC808 = var_s0->node.next;
                    if (!var_s0) {}
                    D_800FC808->node.prev = NULL;
                } else {
                    D_800FC808 = D_800FC80C = NULL;
                }
                temp_s1 = var_s0->node.next;
                D_800FC81C -= 1;
                func_8003C2F8(var_s0);
                var_s0 = temp_s1;
            } else {
                var_s0 = var_s0->node.next;
            }
        } while (var_s0 != NULL);
    }
}
