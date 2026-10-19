#include "audio_stream.h"

// GSM stream channel state for AudioStream_*: opening, DMA refill and decode, and sample
// consumption. A separate file because the Japanese ROM pads AudioStream_DmaReadChunk's end
// to 16 bytes before AudioStream_OpenChannel (0x800426E4 to 0x800426F0), a file boundary; the
// US AudioStream_OpenChannel (0x800456D0) is already 16-byte aligned.

void AudioStream_OpenChannel(unk_D_800FCED8* arg0, s32 arg1, s32 arg2) {
    bzero(&arg0->unk_0000, sizeof(unk_D_800FCED8_0000));

    arg0->unk_0000.gsm.nrp = 0x28;
    arg0->unk_0190 = arg2;
    arg0->unk_0194 = arg1;

    osCreateMesgQueue(&arg0->unk_25A0, &arg0->unk_25B8, 1);

    if ((arg1 == 0) || (arg2 == 0)) {
        arg0->unk_25D1 = 0;
    } else {
        arg0->unk_25D1 = 1;
    }

    arg0->unk_25D0 = 0;
    arg0->unk_2598 = arg0->unk_259C = arg0->unk_259A = 0;
    arg0->unk_25BC = 0;
    arg0->unk_25C4 = 0;
    arg0->unk_25C0 = 0;
    arg0->unk_25CC = 0;
    arg0->unk_25C8 = 0;
    arg0->unk_25D2 = 2;
}

void AudioStream_RefillAndDecode(unk_D_800FCED8* arg0) {
    s32 var_a2;
    s32 var_s2;
    u32 var_v1;

    var_s2 = arg0->unk_25D2;

    if ((arg0->unk_25D0 != 0) && (osRecvMesg(&arg0->unk_25A0, NULL, 0) >= 0)) {
        if (arg0->unk_25C4 == 0) {
            arg0->unk_2598 = (arg0->unk_1598[0].unk_04 >> 0x10) & 0xFFFF;
            arg0->unk_259A = arg0->unk_1598[0].unk_04 & 0xFFFF;
            arg0->unk_259C = arg0->unk_15A0 & 0xFFFFFF;
            arg0->unk_25BC = 0x60;
        }

        arg0->unk_25C4 += 0x400;
        if (arg0->unk_259C >= 0x100) {
            arg0->unk_259C -= 0x100;
        } else {
            arg0->unk_259C = 0;
        }
        arg0->unk_25D0 = 0;
    }

    if ((arg0->unk_25D0 == 0) && ((arg0->unk_25D1 == 1) || (arg0->unk_25D1 == 2) || (arg0->unk_25D1 == 3))) {
        if ((arg0->unk_25C4 - arg0->unk_25C0) < 0xC01) {
            if (arg0->unk_25C4 == 0) {
                var_a2 = 0x400;
            } else if (arg0->unk_259C >= 0x101) {
                var_a2 = 0x400;
            } else {
                var_a2 = arg0->unk_259C * 4;
            }

            if (var_a2 > 0) {
                arg0->unk_25D0 = 1;
                arg0->unk_0190(arg0->unk_0194 + arg0->unk_25C4, &arg0->unk_1598[(arg0->unk_25C4 & 0xFFF) >> 3], var_a2,
                               &arg0->unk_25A0);
            }
        }
    }

    var_v1 = arg0->unk_25CC - arg0->unk_25C8;
    while ((var_v1 < 0x960) && ((arg0->unk_25D1 == 1) || (arg0->unk_2598 > 0)) &&
           ((arg0->unk_25C4 - arg0->unk_25C0) >= 0x25) && (var_s2 > 0)) {
        Gsm_Decode_Stream(arg0, arg0->unk_0198.unk_0000 + (((arg0->unk_25CC % 2560) >> 2) * 8));
        arg0->unk_25C0 = (arg0->unk_25BC >> 3) & ~3;
        arg0->unk_25CC += 0xA0;
        arg0->unk_2598--;
        var_v1 = arg0->unk_25CC - arg0->unk_25C8;
        var_s2--;
    }

    if ((arg0->unk_25D1 == 1) && (var_v1 >= 0x8C0)) {
        arg0->unk_25D1 = 2;
    }
}

u32 AudioStream_ConsumeSamples(unk_D_800FCED8* arg0, u32 arg1) {
    u32 temp_v0;
    u32 var_a2;

    if (arg0->unk_25D1 == 3) {
        temp_v0 = arg0->unk_25CC - arg0->unk_25C8;
        if (arg1 < temp_v0) {
            var_a2 = arg1;
        } else {
            var_a2 = temp_v0;
            if (arg0->unk_2598 <= 0) {
                arg0->unk_25D1 = 4;
            }
        }
        arg0->unk_25C8 += var_a2;
        return var_a2;
    }

    return 0;
}

void AudioStream_MarkLoaded(unk_D_800FCED8* arg0) {
    if (arg0->unk_25D1 == 2) {
        arg0->unk_25D1 = 3;
    }
}

void AudioStream_Abort(unk_D_800FCED8* arg0) {
    arg0->unk_25D1 = 4;
}
