#include "3D140.h"
#include "lib/ultralib/include/PR/leo.h"
#include "src/373A0.h"
#include "src/libnumus/player.h"
#include "src/3D140.h"
#include "src/435D0.h"
#include "src/libnaudio/n_libaudio_sc.h"
#include "src/libnaudio/n_libaudio_sn_sc.h"
#include "src/45720.h"
#include "src/4A3E0.h"
#include "src/4BDC0.h"

typedef union {
    struct {
        s16 type;
    } gen;
    struct {
        s16 type;
        struct AudioInfo* info;
    } done;
} AudioMsg; // size = 0x8

typedef struct AudioInfo {
    /* 0x00 */ s16* data;
    /* 0x04 */ s16 frameSamples;
    /* 0x08 */ AudioMsg msg;
} AudioInfo; // size = 0x10

#define NUM_ACMD_LISTS 2
#define NUM_OUTPUT_BUFFERS 2
#define MAX_MESGS 3
#define NUM_DMA_BUFFERS 48
#define SAMPLES 184

typedef struct AMAudioMgr {
    /* 0x000 */ Acmd* ACMDList[NUM_ACMD_LISTS];
    /* 0x008 */ AudioInfo* audioInfo[NUM_OUTPUT_BUFFERS];
    /* 0x010 */ char unk10[0x228];
    ///* 0x010 */ OSThread thread;
    ///* 0x1C0 */ OSMesgQueue audioFrameMsgQ;
    ///* 0x1D8 */ OSMesg audioFrameMsgBuf[MAX_MESGS];
    ///* 0x1E0 */ OSMesgQueue audioReplyMsgQ;
    ///* 0x1F8 */ OSMesg audioReplyMsgBuf[MAX_MESGS];
    /* 0x238 */ ALGlobals g;
} AMAudioMgr; // size = 0x288

typedef struct AMDMABuffer {
    /* 0x00 */ ALLink node;
    /* 0x08 */ u32 startAddr;
    /* 0x0C */ u32 lastFrame;
    /* 0x10 */ char* ptr;
} AMDMABuffer; // size = 0x14

typedef struct AMDMAState {
    /* 0x00 */ u8 initialized;
    /* 0x04 */ AMDMABuffer* firstUsed;
    /* 0x08 */ AMDMABuffer* firstFree;
} AMDMAState; // size = 0xC

typedef struct unk_D_800FCB48 {
    /* 0x00 */ u16 unk_00[16];
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ u16 unk_28[16];
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ u16 unk_50[16];
    /* 0x70 */ s32 unk_70;
    /* 0x74 */ s32 unk_74;
    /* 0x78 */ u32 unk_78;
    /* 0x7C */ s32 unk_7C;
    /* 0x80 */ s32 unk_80;
} unk_D_800FCB48; // size = 0x84

typedef struct unk_D_80078548 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
} unk_D_80078548;

// .data
extern u8 D_80077D90[];// = { 0, 0, 0, 0 };
extern f32 D_80077D94;// = 0.8000000119f;
extern u8 D_80077D98[];// = { 0, 0, 0, 0 };
extern u8 D_80077D9C[];// = { 0, 0, 0, 0 };
extern u16 D_80077DA0;
extern u32 D_80077DA4;
extern u8 D_80077DA8;
extern s32 D_80077DAC;
extern u32 audFrameCt;
extern u32 nextDMA;
extern u32 curAcmdList;
extern AudioInfo* lastInfo;
extern s32 min_only_one;
// global
extern s32 mus_active_fade_handle;
extern f32 mus_fade_start_volume;
extern u8 mus_fade_target_volume;
extern f32 mus_fade_step_rate;
extern f32 D_80077DD4;
extern f32 D_80077DD8;
extern f32 D_80077DDC;
extern f32 D_80077DE0;
extern u8 mus_sound_effect_blocked;

extern u16 D_80077DF0[];
extern u16 D_80077E00[];
extern u16 D_80077E10[];
extern u16 D_80077E18[];
extern u16 D_80077E20[];
extern u16 D_80077E28[];
extern u16 D_80077E30[];
extern u16 D_80077E38[];
extern u16 D_80077E40[];
extern u16 D_80077E48[];
extern u16 D_80077E50[];
extern u16 D_80077E58[];
extern u16 D_80077E60[];
extern u16 D_80077E68[];
extern u16 D_80077E70[];
extern u16 D_80077E78[];
extern u16 D_80077E88[];
extern u16 D_80077E90[];
extern u16 D_80077E98;
extern u16 D_80077EA4;
extern u16 D_80077EB4;
extern u16 D_80077EC0;
extern u16 D_80077ECC;
extern u16 D_80077ED8;
extern u16 D_80077EE4;
extern u16 D_80077EF0;
extern u16 D_80077EF8;
extern u16 D_80077F04;
extern u16 D_80077F0C;
extern u16 D_80077F14;
extern u16 D_80077F1C;
extern u16 D_80077F24;
extern u16 D_80077F2C;
extern u16 D_80077F34;
extern u16 D_80077F3C;
extern u16 D_80077F44;
extern u16 D_80077F50;
extern u16 D_80077F58;
extern u16 D_80077F60;
extern u16 D_80077F6C[];
extern u16 D_80077F74[];
extern u16 D_80077F7C[];
extern u16 D_80077F88[];
extern u16 D_80077F90[];
extern u16 D_80077F98[];
extern u16 D_80077FA4[];
extern u16 D_80077FAC[];
extern u16 D_80077FB4[];
extern u16 D_80077FC0[];
extern u16 D_80077FC8[];
extern u16 D_80077FD0[];
extern u16 D_80077FD8[];
extern u16 D_80077FE4[];
extern u16 D_80077FEC[];
extern u16 D_80077FF4[];
extern u16 D_80077FFC[];
extern u16 D_80078004[];
extern u16 D_8007800C[];
extern u16 D_80078014[];
extern u8 D_8007801C;
extern u8 D_80078024;
extern u8 D_80078030;
extern u8 D_80078038;
extern u16 D_80078040[];
extern u16 D_80078048[];
extern u16 D_80078050;
extern u16 D_80078058;
extern u16 D_80078060;
extern u16 D_80078068[];
extern u8 D_80078070;
extern u16 D_80078078;
extern u16 D_80078080;
extern u16 D_80078088;
extern u16 D_80078090;
extern u16 D_80078098;
extern u16 D_800780A0;
extern u16 D_800780A8[];
extern u8 D_800780B3[]; // needs addressing
extern u8 D_800780B4[];
extern u8 D_80078180[];
extern u8 D_800781E0[];
extern u8 D_800782A4[];
extern s32 D_80078388;
extern u8 D_8007838C[4];
extern u8 D_80078390[2];
extern u8 D_80078394[4];
extern u8 D_80078398[4];
extern u8 D_8007839C[];
extern u8 D_800783A0;
extern u32 D_800783A4[4];
extern u32 D_800783B4;
extern s32 D_800783B8;
extern u8 D_800783BC;
extern u8 D_800783C0;
extern u8 D_800783C4;
extern u32 D_800783C8;
extern u32 D_800783CC;
extern u8 D_800783D0;
extern u8 D_800783D4;
extern u8 D_800783D8;
extern u8 D_800783DC;
extern u8 D_800783E0;
extern u8 D_800783E4;
extern u8 D_800783E8;
extern u8 D_800783EC;
extern s16 D_800783F0;
extern s16 D_800783F4;
extern s16 D_800783F8;
extern u8 D_800783FC;
extern u8 D_80078400;
extern u32 D_80078404;
extern s32 D_80078408;
extern u8 D_8007840C;
extern u16 D_80078410[1][9];
extern u16 D_80078446[1][9];
extern u16 D_800784EA[1][9];
extern u32 D_80078544;
extern unk_D_80078548 D_80078548[];
extern u8 D_80078554[];
extern u8 D_80078568[];

// .rodata

// const f64 D_8007C7E0 = 0.699999999999999956f;
// const f64 D_8007C7E8 = 0.599999999999999978f;
// const f64 D_8007C7F0 = 0.400000000000000022f;
// const f64 D_8007C7F8 = 0.299999999999999989f;

// const f32 D_8007CB80 = 1.100000024f;
// const f32 D_8007CB84 = 1.100000024f;
// const f32 D_8007CB88 = 1.200000048f;
// const f32 D_8007CB8C = 1.100000024f;
// const f32 D_8007CB90 = 0.009999999776f;

extern f64 D_8007C7E0;
extern f64 D_8007C7E8;
extern f64 D_8007C7F0;
extern f64 D_8007C7F8;

extern f32 D_8007CB80;
extern f32 D_8007CB84;
extern f32 D_8007CB88;
extern f32 D_8007CB8C;
extern f32 D_8007CB90;

// .bss
s32 D_800FC820;
s8 D_800FC824;
u8 D_800FC825;
s32 D_800FC828;
AMAudioMgr __am;
AMDMAState dmaState;
s32 minFrameSize;
u32 frameSize;
s32 maxFrameSize;
s32 maxRSPCmds;
s32 D_800FCAD4;
s32 D_800FCAD8;
OSMesgQueue audDMAMessageQ;
AMDMABuffer* dmaBuffs;
OSIoMesg* audDMAIOMesgBuf;
OSMesg* audDMAMessageBuf;
u32 dmaBufferLen;
OSPiHandle* D_800FCB08[4];
// s32 D_800FCB0C[3];
unk_D_800FCB18* D_800FCB18[4];
s32 D_800FCB28[2];
u8 D_800FCB30[2];
u8 D_800FCB38[2][8];
unk_D_800FCB48 D_800FCB48[2];
s32 D_800FCC50[20];
s8 D_800FCCA0;
s8 D_800FCCA1;
u8 D_800FCCA2;
u32 D_800FCCA4;
s32 D_800FCCA8;
u8 D_800FCCAC;
u8 D_800FCCAD;
u8 D_800FCCAE;
u8 D_800FCCAF;
u8 D_800FCCB0;
u8 D_800FCCB1;
u8 D_800FCCB2;
u8 D_800FCCB3;
u8 D_800FCCB4;
u8 D_800FCCB5;
u8 D_800FCCB6;
u8 D_800FCCB7;
u8 D_800FCCB8[2];
u8 D_800FCCBA[2];
u8 D_800FCCBC[2];
u8 D_800FCCBE[2];
u8 D_800FCCC0[2];
u8 D_800FCCC2[2];
s8 D_800FCCC4[2];
u8 D_800FCCC6[2];
u8 D_800FCCC8[2];
u8 D_800FCCCA[2];
u8 D_800FCCCC[2];
u8 D_800FCCCE[2];
u8 D_800FCCD0[2];
u8 D_800FCCD2[2];
u8 D_800FCCD4[2];
u8 D_800FCCD6[2];
s8 D_800FCCD8[0x18];
u32 D_800FCCF0[10];
u8 D_800FCD18[0x28];

// function prototypes
void func_800420F0(u16, u16*, u8*);
u32 func_80042158(u32, unk_D_800FCB18*, unk_D_800FCB18*);
s32 func_80042850(u8);
ALDMAproc __amDmaNew(AMDMAState** state);

void amCreateAudioMgr(ALSynConfig* c, amConfig* amc, u32 num_dma_buffers, s32 arg3, s32 arg4) {
    u32 i;
    f32 fsize;

    D_800FCB08[0] = osCartRomInit();
    dmaBufferLen = arg3;

    dmaState.initialized = FALSE;

    c->dmaproc = __amDmaNew;
    c->outputRate = amc->outputRate;

    i = num_dma_buffers;
    i <<= 1;
    dmaBuffs = alHeapAlloc(c->heap, 1, num_dma_buffers * sizeof(AMDMABuffer));
    audDMAIOMesgBuf = alHeapAlloc(c->heap, 1, i * sizeof(OSIoMesg));
    audDMAMessageBuf = alHeapAlloc(c->heap, 1, i * sizeof(OSMesg));

    fsize = (f32)amc->framesPerField * c->outputRate / arg4;
    frameSize = (s32)fsize;
    if (frameSize < fsize) {
        frameSize++;
    }

    frameSize = ((frameSize / SAMPLES) + 1) * SAMPLES;
    minFrameSize = frameSize - SAMPLES;
    maxFrameSize = frameSize + 0x100;

    alInit(&__am.g, c);

    dmaBuffs[0].node.prev = NULL;
    dmaBuffs[0].node.next = NULL;

    for (i = 0; i < num_dma_buffers - 1; i++) {
        alLink(&dmaBuffs[i + 1].node, &dmaBuffs[i].node);
        dmaBuffs[i].ptr = alHeapAlloc(c->heap, 1, arg3);
    }

    dmaBuffs[i].ptr = alHeapAlloc(c->heap, 1, arg3);

    for (i = 0; i < 2; i++) {
        __am.ACMDList[i] = alHeapAlloc(c->heap, 1, amc->maxACMDSize * sizeof(Acmd));
    }

    maxRSPCmds = amc->maxACMDSize;

    for (i = 0; i < 3; i++) {
        __am.audioInfo[i] = alHeapAlloc(c->heap, 1, sizeof(AudioInfo));
        __am.audioInfo[i]->msg.done.type = 0;
        __am.audioInfo[i]->msg.done.info = __am.audioInfo[i];
        __am.audioInfo[i]->data = alHeapAlloc(c->heap, 1, maxFrameSize * 4);
    }

    osCreateMesgQueue(&audDMAMessageQ, audDMAMessageBuf, num_dma_buffers << 1);

    D_800FCAD4 = c->outputRate;
    D_800FCAD8 = c->maxVVoices;
    D_800FC824 = 0;

    func_80044B20(c->heap, minFrameSize, maxFrameSize);
}

s32 __amDMA(s32 addr, s32 len, void* state) {
    void* foundBuffer;
    s32 delta;
    AMDMABuffer* sp34;
    OSIoMesg* ioMesg;
    AMDMABuffer* dmaPtr;
    AMDMABuffer* lastDmaPtr;
    OSPiHandle* sp2C;
    s32 buffEnd;

    if (D_800FC820 & 0x80000000) {
        return osVirtualToPhysical(addr);
    }

    sp2C = D_800FCB08[0];
    dmaPtr = dmaState.firstUsed;
    lastDmaPtr = NULL;
    while (dmaPtr) {
        buffEnd = dmaPtr->startAddr + dmaBufferLen;

        if (dmaPtr->startAddr > addr) {
            break;
        }

        if (buffEnd >= (addr + len)) {
            dmaPtr->lastFrame = audFrameCt;
            return osVirtualToPhysical(dmaPtr->ptr + addr - dmaPtr->startAddr);
        }

        lastDmaPtr = dmaPtr;
        dmaPtr = dmaPtr->node.next;
    }

    dmaPtr = dmaState.firstFree;
    if (!dmaPtr) {
        return osVirtualToPhysical(dmaState.firstUsed);
    }

    dmaState.firstFree = dmaPtr->node.next;
    alUnlink(&dmaPtr->node);

    if (lastDmaPtr != NULL) {
        alLink(&dmaPtr->node, &lastDmaPtr->node);
    } else if (dmaState.firstUsed) {
        lastDmaPtr = dmaState.firstUsed;

        dmaState.firstUsed = dmaPtr;
        dmaPtr->node.next = lastDmaPtr;
        dmaPtr->node.prev = NULL;

        lastDmaPtr->node.prev = &dmaPtr->node;
    } else {
        dmaState.firstUsed = dmaPtr;
        dmaPtr->node.next = NULL;
        dmaPtr->node.prev = NULL;
    }

    foundBuffer = dmaPtr->ptr;
    delta = addr & 1;
    addr -= delta;
    dmaPtr->startAddr = addr;
    dmaPtr->lastFrame = audFrameCt;

    ioMesg = audDMAIOMesgBuf + nextDMA++;
    ioMesg->hdr.pri = OS_MESG_PRI_HIGH;
    ioMesg->hdr.retQueue = &audDMAMessageQ;
    ioMesg->devAddr = addr;
    ioMesg->dramAddr = foundBuffer;
    ioMesg->size = dmaBufferLen;

    osInvalDCache(foundBuffer, dmaBufferLen);
    osEPiStartDma(sp2C, ioMesg, OS_READ);

    return osVirtualToPhysical(foundBuffer) + delta;
}

OSTask* func_8003CADC(OSTask* arg0) {
    s16* audioPtr;
    Acmd* cmdp;
    s32 cmdLen;
    s32 samplesLeft;
    OSTask sp38;
    s32 pad[2];
    AudioInfo* info;
    AMAudioMgr* mgr;

    info = __am.audioInfo[audFrameCt % 3];
    audioPtr = osVirtualToPhysical(info->data);
    samplesLeft = HW_REG(AI_LEN_REG, u32) >> 2;

    if ((D_80077DA8 == 0) && (lastInfo != NULL)) {
        osAiSetNextBuffer(lastInfo->data, lastInfo->frameSamples << 2);
    }

    if ((samplesLeft >= 0x1A9) && (min_only_one != 0)) {
        info->frameSamples = minFrameSize;
        min_only_one = 0;
    } else {
        info->frameSamples = frameSize;
        min_only_one = 1;
    }

    __clearAudioDMA();

    if (D_80077DAC != 0) {
        D_800FC828 = LeoTestUnitReady(&D_800FC825);
    }

    cmdp = alAudioFrame(__am.ACMDList[curAcmdList], &cmdLen, audioPtr, info->frameSamples);
    sp38.t.data_ptr = __am.ACMDList[curAcmdList];
    sp38.t.data_size = (cmdp - __am.ACMDList[curAcmdList]) * sizeof(Acmd);

    sp38.t.type = M_AUDTASK;
    sp38.t.ucode_boot = &rspbootTextStart;
    sp38.t.ucode_boot_size = (s32)_binary_assets_us_F3DEX2_bin_start - (s32)rspbootTextStart;
    sp38.t.flags = 0;
    sp38.t.ucode = &aspMainTextStart;
    sp38.t.ucode_data = &aspMainDataStart;
    sp38.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    sp38.t.dram_stack = NULL;
    sp38.t.dram_stack_size = 0;
    sp38.t.output_buff = NULL;
    sp38.t.output_buff_size = 0;
    sp38.t.yield_data_ptr = NULL;
    sp38.t.yield_data_size = 0;

    curAcmdList ^= 1;
    lastInfo = __am.audioInfo[audFrameCt % 3];
    audFrameCt++;

    if (D_80077D9C[0] != 0) {
        func_8003D32C();
    }

    if (D_80077D90[0] != 0) {
        func_800429D0();
        if (lastInfo != NULL) {
            func_800497E0(lastInfo->data, 0, ((audFrameCt % 3) == 0) ? 0x216 : 0x215, 0);
        }
    }

    if (D_80077D98[0] != 0) {
        func_80044EA4();
    }

    func_800416BC();

    if (mus_active_fade_handle != 0) {
        mus_fade_start_volume += mus_fade_step_rate;
        if (mus_fade_step_rate > 0.0f) {
            if (mus_fade_target_volume <= mus_fade_start_volume) {
                mus_fade_start_volume = mus_fade_target_volume;
            }
        } else {
            if (mus_fade_start_volume <= mus_fade_target_volume) {
                mus_fade_start_volume = mus_fade_target_volume;
            }
        }

        MusSetVolumeScale(mus_active_fade_handle, (u32)mus_fade_start_volume & 0xFF);

        if (mus_fade_start_volume == mus_fade_target_volume) {
            mus_active_fade_handle = 0;
        }
    }

    if (D_80077DD4 != 0.0f) {
        D_80077DD4 -= D_80077DD8;
        if (D_80077DD4 <= 0) {
            D_80077DD4 = 0.0f;
            MusSetAllChannelsDuration(2, 1);
        }
        MusSetMasterVolume(2, D_80077DD4);
    }

    if (D_80077DDC != 0.0f) {
        D_80077DDC -= D_80077DE0;
        if (D_80077DDC <= 0) {
            D_80077DDC = 0.0f;
            MusSetAllChannelsDuration(1, 1);
        }
        MusSetMasterVolume(1, D_80077DDC);
    }

    if (D_80077DA8 != 0) {
        sp38.t.data_size = 0;
    }

    *arg0 = sp38;

    return arg0;
}

ALDMAproc __amDmaNew(AMDMAState** state) {
    if (!dmaState.initialized) {
        dmaState.firstUsed = NULL;
        dmaState.firstFree = &dmaBuffs[0];
        dmaState.initialized = TRUE;
    }

    *state = &dmaState;

    return __amDMA;
}

#define FRAME_LAG 1

void __clearAudioDMA(void) {
    s32 i;
    void* sp40;
    AMDMABuffer* var_s0_2;
    ALLink* node;

    for (i = 0; i < nextDMA; i++) {
        osRecvMesg(&audDMAMessageQ, &sp40, 0);
    }

    var_s0_2 = dmaState.firstUsed;
    while (var_s0_2 != NULL) {
        node = var_s0_2->node.next;

        if ((var_s0_2->lastFrame + FRAME_LAG) < audFrameCt) {
            if (var_s0_2 == dmaState.firstUsed) {
                dmaState.firstUsed = var_s0_2->node.next;
            }

            alUnlink(var_s0_2);

            if (dmaState.firstFree != NULL) {
                alLink(var_s0_2, dmaState.firstFree);
            } else {
                dmaState.firstFree = var_s0_2;
                var_s0_2->node.next = NULL;
                var_s0_2->node.prev = NULL;
            }
        }

        var_s0_2 = node;
    }

    nextDMA = 0;
}


void func_8003D264(s32 arg0) {
    const f32 D_8007C7C0 = 0.8000000119f;
    if (arg0 != 0) {
        func_800498A8(0x7D00, 0x78, 0x640);
        D_80077D90[0] = 1;
        D_80077D94 = D_8007C7C0;
        return;
    }
    D_80077D90[0] = 0;
}

void func_8003D2B8(s32 arg0) {
    if (D_80077D90[0] == 0) {
        func_800498A8(0x7D00, 0x78, 0x320);
        D_80077D90[0] = 1;
        D_80077D9C[0] = 1;
        D_80077D94 = 0.0f;
        D_80077DA0 = arg0;
        D_80077DA4 = 0;
        D_800FC824 = 0;
    }
}

void func_8003D32C(void) {
    switch (D_80077D9C[0]) {
        case 1:
            MusSetupVolumeFade(D_80078E70, 0x50, 0x18, 3);
            func_80042AB0(D_80077DA0);
            D_80077D9C[0]++;
            D_80077DA4 = 0;
            break;

        case 2:
            D_80077DA4++;
            if (D_80077DA4 >= 2) {
                D_80077DA4 = 0;
                D_80077D9C[0]++;
                D_800FC824 = 1;
            }
            break;

        case 3:
            if (func_800449F8() == 0) {
                D_80077D9C[0]++;
                D_80077DA4 = 0;
            }
            break;

        case 4:
            if (D_80077DA4 == 0) {
                MusSetupVolumeFade(D_80078E70, 0x18, 0x50, 0x14);
            }

            if (D_80077DA4 >= 0x1F) {
                D_80077D9C[0]++;
            }

            D_80077DA4++;
            break;

        case 5:
            D_80077D9C[0] = 0;
            D_80077D90[0] = 0;
            D_800FC824 = 0;
            break;
    }
}

s32 func_8003D494(void) {
    return D_80077D90[0];
}

s32 func_8003D4A0(s32 arg0) {
    if (arg0 == 0) {
        if (mus_free_voices_count != D_800FCAD8) {
            return 0;
        }
        D_80077DA8 = 1;
    } else {
        osAiSetFrequency(D_800FCAD4);
        lastInfo = NULL;
        dmaState.initialized = 0;
        D_80077DA8 = 0;
    }
    return 1;
}

s32 func_8003D514(u8* arg0) {
    if (D_80077DAC == 0) {
        *arg0 = 7;
        return 8;
    }
    *arg0 = D_800FC825;
    return D_800FC828;
}

void func_8003D54C(s32 arg0) {
    if (arg0 == 1) {
        D_80077DAC = 1;
        return;
    }
    D_80077DAC = 0;
}
