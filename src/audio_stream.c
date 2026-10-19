#include "audio_stream.h"

u8 D_800785F0 = 0;

s32 D_800FCED0;
unk_D_800FCED8* D_800FCED8[2];
s16* D_800FCEE0[2];
u32 D_800FCEE8;
u32 D_800FCEEC;
u8 D_800FCEF0[2];
s32 D_800FCEF8[2];
u32 D_800FCF00[2];
s32 D_800FCF08[2];
s32 D_800FCF10[2];
s32 pad_D_800FCF18;
s16 D_800FCF1C[2];
u8 D_800FCF20[2];
OSPiHandle* D_800FCF24;
unk_D_800FCF28* D_800FCF28[2];
u32 D_800FCF30[2];
s32 D_800FCF38[2];
OSMesgQueue D_800FCF40;
OSMesg D_800FCF58;

void AudioStream_Init(ALHeap* arg0, u32 arg1, u32 arg2) {
    s32 i;

    D_800FCEE8 = arg1 >> 1;
    D_800FCEEC = arg2 >> 1;

    for (i = 0; i < 2; i++) {
        D_800FCED8[i] = alHeapDBAlloc(NULL, 0, arg0, 1, sizeof(unk_D_800FCED8));
        D_800FCF28[i] = alHeapDBAlloc(NULL, 0, arg0, sizeof(*D_800FCF28[0]) / 2, 2);

        D_800FCEE0[i] = (u32)D_800FCED8[i] + 0x198;
        D_800FCF30[i] = 0;
        D_800FCF38[i] = 0x400;
        D_800FCEF0[i] = 2;

        bzero(D_800FCF28[i], 0x1140);
        bzero(D_800FCEE0[i], 0x1400);

        AudioStream_OpenChannel(D_800FCED8[i], 0, 0);
        D_800FCF20[i] = 0;
    }

    D_800FCF24 = osCartRomInit();
    osCreateMesgQueue(&D_800FCF40, &D_800FCF58, 1);
    D_800FCED0 = 0;
    D_800785F0 = 0;
}

void AudioStream_Start(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 temp_a0;

    if ((arg0 < 2) && (D_800785F0 == 0)) {
        if (arg2 >= 0x81) {
            arg2 = 0x80;
        }

        temp_a0 = osSetIntMask(1);

        if (arg3 == 0) {
            D_800FCEF0[arg0] = 0;
        } else {
            D_800FCEF0[arg0] = 3;
        }

        D_800FCEF8[arg0] = arg1;
        D_800FCF10[arg0] = arg3;
        D_800FCF08[arg0] = arg2;

        osSetIntMask(temp_a0);
    }
}

void AudioStream_Stop(u32 arg0, u32 arg1) {
    u32 temp_a0;

    if (arg0 < 2) {
        if (arg1 != 0) {
            D_800FCF1C[arg0] = (f32)D_800FCF00[arg0] / arg1;
        }
        temp_a0 = osSetIntMask(1);
        if (arg1 != 0) {
            D_800FCEF0[arg0] = 5;
        } else {
            D_800FCEF0[arg0] = 1;
        }
        osSetIntMask(temp_a0);
    }
}

s32 AudioStream_IsPlaying(u32 arg0) {
    if (D_800FCEF0[arg0] == 2) {
        return 0;
    }
    return 1;
}

void AudioStream_SetEnabled(s32 arg0) {
    if (arg0 != 0) {
        D_800785F0 = 0;
    } else {
        D_800785F0 = 1;
    }
}

void func_80044EA4(void) {
    UNUSED s32 pad;
    u32 j;
    u32 var_s7;
    s32 i;
    u32 temp_a2;
    s32 temp_v0_9;
    s16 sample;

    for (i = 0; i < 2; i++) {
        if (D_800FCEF0[i] == 2U) {
            continue;
        }
        {
            if (D_800FCF30[i] < D_800FCF38[i]) {
                if ((D_800FCF38[i] - D_800FCF30[i]) < D_800FCEEC) {
                    var_s7 = D_800FCEEC;
                } else {
                    var_s7 = D_800FCEE8;
                }
            } else if ((0x8A0 - D_800FCEEC) < (D_800FCF30[i] - D_800FCF38[i])) {
                var_s7 = D_800FCEEC;
            } else {
                var_s7 = D_800FCEE8;
            }

            AudioStream_RefillAndDecode(D_800FCED8[i]);
            if ((u8)D_800FCED8[i]->unk_25D1 == 2) {
                osWritebackDCache(D_800FCF28[i], 0x1140);
                AudioStream_MarkLoaded(D_800FCED8[i]);
                D_800FCED0 = 1;
                D_800FCF20[i] = 0;
            } else if ((D_800FCEF0[i] != 0) && (D_800FCEF0[i] != 3) && ((u8)D_800FCED8[i]->unk_25D1 == 4)) {
                if (D_800FCF20[i] == 0) {
                    AudioStream_Abort(D_800FCED8[i]);
                    D_800FCF20[i] = 1;
                }
                D_800FCED0 = 0;
                D_800FCEF0[i] = 2;
                bzero(D_800FCEE0[i], 0x1400);
                bzero(D_800FCF28[i], 0x1140);
            }

            AudioStream_ConsumeSamples(D_800FCED8[i], var_s7);

            temp_a2 = D_800FCED8[i]->unk_25C8 - var_s7;
            for (j = 0; j < var_s7; j++) {
                sample = (D_800FCEE0[i][(temp_a2 + j) % 2560] * D_800FCF00[i]) >> 7;
                D_800FCF28[i]->unk_000[(D_800FCF38[i] + (j << 1) + 1) % 2208] = sample;
                D_800FCF28[i]->unk_000[(D_800FCF38[i] + (j << 1)) % 2208] = sample;
            }

            D_800FCF38[i] += var_s7 * 2;
            D_800FCF38[i] = (u32)D_800FCF38[i] % 2208;
            osWritebackDCache(D_800FCF28[i], 0x1140);

            switch (D_800FCEF0[i]) {
                case 2:
                case 4:
                    break;

                case 0:
                    AudioStream_OpenChannel(D_800FCED8[i], D_800FCEF8[i], AudioStream_DmaReadChunk);
                    D_800FCEF0[i] = 4;
                    if (D_800FCED0 != 0) {
                        D_800FCED0 = 0;
                    }
                    D_800FCF00[i] = D_800FCF08[i];
                    break;

                case 1:
                    AudioStream_Abort(D_800FCED8[i]);
                    bzero(D_800FCEE0[i], 0x1400);
                    D_800FCF20[i] = 1;
                    break;

                case 3:
                    if (--D_800FCF10[i] == 0) {
                        D_800FCEF0[i] = 0;
                    }
                    break;

                case 5:
                    temp_v0_9 = D_800FCF00[i] - D_800FCF1C[i];
                    if (temp_v0_9 <= 0) {
                        D_800FCF00[i] = 0;
                        D_800FCEF0[i] = 1;
                    } else {
                        D_800FCF00[i] = temp_v0_9;
                    }
                    break;
            }
        }
    }
}


void AudioStream_DmaReadChunk(u32 arg0, u32 arg1, u32 arg2, OSMesgQueue* arg3) {
    OSIoMesg sp48;
    u32 var_s1;
    u32 var_s2;
    u32 var_s3;

    var_s2 = arg0;
    var_s3 = arg1;

    while (arg2) {
        if (arg2 >= 0x1001) {
            var_s1 = 0x1000;
        } else {
            var_s1 = arg2;
        }

#if defined(VERSION_JP)
        sp48.hdr.pri = OS_MESG_PRI_HIGH;
#else
        sp48.hdr.pri = 0;
#endif
        sp48.hdr.retQueue = &D_800FCF40;
        sp48.dramAddr = var_s3;
        sp48.devAddr = var_s2;
#if defined(VERSION_JP)
        // Each Japanese request spans from the current position to the end of the transfer instead
        // of one 0x1000-byte chunk, so later iterations reread bytes the previous ones copied.
        sp48.size = arg2;
#else
        sp48.size = var_s1;
#endif

        osInvalDCache(arg1, arg2);
        osEPiStartDma(D_800FCF24, &sp48, 0);
        osRecvMesg(&D_800FCF40, NULL, 1);

        arg2 -= var_s1;
        var_s2 += var_s1;
        var_s3 += var_s1;
    }

    osSendMesg(arg3, NULL, 1);
}
