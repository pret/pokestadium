#include "3D140.h"
#include "lib/ultralib/include/PR/leo.h"
#include "src/373A0.h"
#include "src/38BB0.h"
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
} AMAudioMgr; // size = 0x284 ??

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

extern f32 D_80077D94;
extern s32 D_80077DC4;
extern f32 D_80077DC8;
extern u8 D_80077DCC;
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
extern u16 D_800780A8[];
typedef struct unk_D_8007838C {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
} unk_D_8007838C; // size = 0x04

extern unk_D_8007838C D_8007838C;
extern u8 D_800783BC;
extern u8 D_800783C0;
extern u8 D_800783C4;
extern u32 D_800783C8;
extern u32 D_800783CC;
extern u8 D_800783D4;
extern u8 D_800783D8;
extern u8 D_800783DC;
extern u8 D_800783E4;
extern u8 D_800783E8;
extern u8 D_800783EC;
extern u8 D_800783FC;
extern u8 D_80078400;
extern u16 D_80078410[1][9];
extern u16 D_80078446[1][9];
extern u16 D_800784EA[1][9];
extern u32 D_80078544;
extern f32 D_8007C7C0;
extern f64 D_8007C7E0;
extern f64 D_8007C7E8;
extern f64 D_8007C7F0;
extern f64 D_8007C7F8;
extern u8 D_800FCD18[];
extern u8 D_80077D90;
extern u8 D_80077D98;
extern u8 D_80077D9C;
extern u8 D_80077DA8;
extern s32 D_80077DAC;
extern u32 audFrameCt;
extern AudioInfo* lastInfo;
extern s32 min_only_one;
extern u8 D_800FC825;
extern s32 D_800FC828;
extern s32 D_800FCB28;
extern s32 D_800FCB2C;
extern u32 D_800FCCF0[10];

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
    /* 0x78 */ s32 unk_78;
    /* 0x7C */ s32 unk_7C;
    /* 0x80 */ s32 unk_80;
} unk_D_800FCB48; // size = 0x84

extern unk_D_800FCB48 D_800FCB48[2];
extern u32 D_800FCCA4;
extern u8 D_800FCCAE;
extern u8 D_800FCCAF;
extern u8 D_800FCCB0;
extern u8 D_800FCCB1;
extern u8 D_800FCCB2;
extern u8 D_800FCCB3;
extern u8 D_800FCCB4;
extern u8 D_800FCCB5;
extern u8 D_800FCCB6;
extern s8 D_8007839C[];
extern s8 D_800783E0;
extern s16 D_800783F0;
extern s16 D_800783F4;
extern s16 D_800783F8;
typedef struct unk_D_80078548 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
} unk_D_80078548;

extern unk_D_80078548 D_80078548[];
extern u8 D_80078554[];
extern u8 D_80078568[];
extern u8 D_800FCB38[2][8];
extern s32 D_800FCC50[];
extern s8 D_800FCCA0;
extern s8 D_800FCCA1;
extern u8 D_800FCCA2;
extern u8 D_800FCCAC;
extern u8 D_800FCCB7;
extern s8 D_800FCCB8[];
extern s8 D_800FCCBA[];
extern s8 D_800FCCBC[];
extern s8 D_800FCCBE[];
extern s8 D_800FCCC0[];
extern s8 D_800FCCC2[];
extern s8 D_800FCCC4[];
extern u8 D_800FCCC6[];
extern u8 D_800FCCC8[];
extern u8 D_800FCCCA[];
extern u8 D_800FCCCC[];
extern u8 D_800FCCCE[];
extern u8 D_800FCCD0[];
extern u8 D_800FCCD2[];
extern s8 D_800FCCD4[];
extern s8 D_800FCCD6[];
extern s8 D_800FCCD8[];
extern s32 D_80078388;
extern u32 D_800783A4[4];
extern s32 D_800783B8;
extern u32 nextDMA;
extern u16 D_80077DA0;
extern u32 D_80077DA4;
extern s8 D_800FC824;
extern AMAudioMgr __am;
extern AMDMAState dmaState;
extern s32 minFrameSize;
extern u32 frameSize;
extern s32 maxFrameSize;
extern s32 maxRSPCmds;
extern s32 D_800FCAD4;
extern s32 D_800FCAD8;
extern OSMesgQueue audDMAMessageQ;
extern AMDMABuffer (*dmaBuffs)[NUM_DMA_BUFFERS];
extern OSIoMesg (*audDMAIOMesgBuf)[NUM_DMA_BUFFERS];
extern OSMesg (*audDMAMessageBuf)[NUM_DMA_BUFFERS];
extern u32 dmaBufferLen;
extern OSPiHandle* D_800FCB08;
extern u32 curAcmdList;
extern u16 D_80077E98;
extern u16 D_80077EA4;
extern u16 D_80077EB4;
extern u16 D_80077F04;
extern u16 D_80077F44;
extern u16 D_80077F60;
extern u16 D_80077F6C[];
extern u16 D_80077F74[];
extern u16 D_80077F7C[];
extern u16 D_80077F88[];
extern u16 D_80077F90[];
extern u16 D_80077F98[];
extern u16 D_80077FA4[];
extern u16 D_80077FAC[];
extern u32 D_800783B4;
extern s32 D_800FCCA8;
extern u8 D_800FCCAD;

ALDMAproc __amDmaNew(AMDMAState** state);

#ifdef NON_MATCHING
void amCreateAudioMgr(ALSynConfig* c, amConfig* amc, u32 num_dma_buffers, s32 arg3, s32 arg4) {
    u32 i;
    f32 fsize;

    D_800FCB08 = osCartRomInit();
    dmaBufferLen = arg3;

    dmaState.initialized = FALSE;

    c->dmaproc = __amDmaNew;
    c->outputRate = amc->outputRate;

    dmaBuffs = alHeapAlloc(c->heap, 1, num_dma_buffers * sizeof(AMDMABuffer));
    audDMAIOMesgBuf = alHeapAlloc(c->heap, 1, (num_dma_buffers << 1) * sizeof(OSIoMesg));
    audDMAMessageBuf = alHeapAlloc(c->heap, 1, (num_dma_buffers << 1) * sizeof(OSMesg));

    fsize = (f32)amc->framesPerField * c->outputRate / arg4;
    frameSize = (s32)fsize;
    if (frameSize < fsize) {
        frameSize++;
    }

    frameSize = ((frameSize / SAMPLES) + 1) * SAMPLES;
    minFrameSize = frameSize - SAMPLES;
    maxFrameSize = frameSize + 0x100;

    alInit(&__am.g, c);

    (*dmaBuffs)[0].node.prev = NULL;
    (*dmaBuffs)[0].node.next = NULL;

    for (i = 0; i < num_dma_buffers - 1; i++) {
        alLink(&(*dmaBuffs)[i + 1].node, &(*dmaBuffs)[i].node);
        (*dmaBuffs)[i].ptr = alHeapAlloc(c->heap, 1, arg3);
    }

    (*dmaBuffs)[i].ptr = alHeapAlloc(c->heap, 1, arg3);

    for (i = 0; i < 2; i++) {
        __am.ACMDList[i] = alHeapAlloc(c->heap, 1, amc->maxACMDSize * 8);
    }

    maxRSPCmds = amc->maxACMDSize;

    for (i = 0; i < 2; i++) {
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
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/amCreateAudioMgr.s")
#endif

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

    sp2C = D_800FCB08;
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

    ioMesg = (*audDMAIOMesgBuf) + nextDMA++;
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

    if (D_80077D9C != 0) {
        func_8003D32C();
    }

    if (D_80077D90 != 0) {
        func_800429D0();
        if (lastInfo != NULL) {
            func_800497E0(lastInfo->data, 0, ((audFrameCt % 3) == 0) ? 0x216 : 0x215, 0);
        }
    }

    if (D_80077D98 != 0) {
        func_80044EA4();
    }

    func_800416BC();

    if (D_80077DC4 != 0) {
        D_80077DC8 += D_80077DD0;
        if (D_80077DD0 > 0.0f) {
            if (D_80077DCC <= D_80077DC8) {
                D_80077DC8 = D_80077DCC;
            }
        } else {
            if (D_80077DC8 <= D_80077DCC) {
                D_80077DC8 = D_80077DCC;
            }
        }

        func_800393DC(D_80077DC4, (u32)D_80077DC8 & 0xFF);

        if (D_80077DC8 == D_80077DCC) {
            D_80077DC4 = 0;
        }
    }

    if (D_80077DD4 != 0.0f) {
        D_80077DD4 -= D_80077DD8;
        if (D_80077DD4 <= 0) {
            D_80077DD4 = 0.0f;
            func_8003916C(2, 1);
        }
        func_80038E98(2, D_80077DD4);
    }

    if (D_80077DDC != 0.0f) {
        D_80077DDC -= D_80077DE0;
        if (D_80077DDC <= 0) {
            D_80077DDC = 0.0f;
            func_8003916C(1, 1);
        }
        func_80038E98(1, D_80077DDC);
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
    if (arg0 != 0) {
        func_800498A8(0x7D00, 0x78, 0x640);
        D_80077D90 = 1;
        D_80077D94 = D_8007C7C0;
        return;
    }
    D_80077D90 = 0;
}

void func_8003D2B8(s32 arg0) {
    if (D_80077D90 == 0) {
        func_800498A8(0x7D00, 0x78, 0x320);
        D_80077D90 = 1;
        D_80077D9C = 1;
        D_80077D94 = 0.0f;
        D_80077DA0 = arg0;
        D_80077DA4 = 0;
        D_800FC824 = 0;
    }
}

#ifdef NON_MATCHING
void func_8003D32C(void) {
    switch (D_80077D9C) {
        case 1:
            func_80039B88(D_80078E70, 0x50, 0x18, 3);
            func_80042AB0(D_80077DA0);
            D_80077D9C++;
            D_80077DA4 = 0;
            break;

        case 2:
            D_80077DA4++;
            if (D_80077DA4 >= 2) {
                D_80077DA4 = 0;
                D_80077D9C++;
                D_800FC824 = 1;
            }
            break;

        case 3:
            if (func_800449F8() == 0) {
                D_80077D9C++;
                D_80077DA4 = 0;
            }
            break;

        case 4:
            if (D_80077DA4 == 0) {
                func_80039B88(D_80078E70, 0x18, 0x50, 0x14);
            }

            if (D_80077DA4 >= 0x1F) {
                D_80077D9C++;
            }

            D_80077DA4++;
            break;

        case 5:
            D_80077D9C = 0;
            D_80077D90 = 0;
            D_800FC824 = 0;
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D32C.s")
#endif

s32 func_8003D494(void) {
    return D_80077D90;
}

s32 func_8003D4A0(s32 arg0) {
    if (arg0 == 0) {
        if (D_800FC818 != D_800FCAD8) {
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

/**
 * Sets or clears a bit in an array.
 */
void func_8003D570(u8* array, u8 index, u8 flag) {
    u8 offset = index / 8;
    u8 bitPosition = index % 8;
    u8 mask = (1 << bitPosition);
    if (flag) {
        array[offset] |= mask;   // Set the bit
    } else {
        array[offset] &= ~mask;  // Clear the bit
    }
}

/**
 * Checks if a bit is set in an array.
 */
s32 func_8003D624(u8* array, u8 index) {
    u8 offset = index / 8;
    u8 bitPosition = index % 8;
    u8 flag = (array[offset] & (u8)(1 << bitPosition));
    if (flag) {
        return 1;
    }
    return 0;
}

void func_8003D68C(s32 arg0) {
    if (arg0 != 0) {
        D_80078388 = 1;
    } else {
        D_80078388 = 0;
    }
}

void func_8003D6B0(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    D_8007838C.unk_00 = arg0;
    D_8007838C.unk_01 = arg1;
    D_8007838C.unk_02 = arg2;
    D_8007838C.unk_03 = arg3;
}

void func_8003D6DC(u8 arg0) {
    s32 i;

    if (arg0 < 3) {
        for (i = 0; i < 16; i++) {
            D_800FCB48[arg0].unk_00[i] = 0;
            D_800FCB48[arg0].unk_28[i] = 0;
            D_800FCB48[arg0].unk_50[i] = 0;
        }
        D_800FCB48[arg0].unk_20 = 0;
        D_800FCB48[arg0].unk_24 = 0;
        D_800FCB48[arg0].unk_48 = 0;
        D_800FCB48[arg0].unk_4C = 0;
        D_800FCB48[arg0].unk_70 = 0;
        D_800FCB48[arg0].unk_74 = 0;
        D_800FCB48[arg0].unk_78 = 0;
        D_800FCB48[arg0].unk_7C = 0;
        D_800FCB48[arg0].unk_80 = 0;
        D_800FCCBC[arg0] = 0;
        D_800FCCBE[arg0] = 0;
        D_800FCCC4[arg0] = 0;
        D_800FCCC6[arg0] = 0;
        D_800FCCC8[arg0] = 0;
        D_800FCCCA[arg0] = 0;
        D_800FCCCC[arg0] = 0;
        D_800FCCCE[arg0] = 0;
        D_800FCCD0[arg0] = 0;
        D_800FCCD2[arg0] = 0;
        D_800FCCD4[arg0] = 0;
        D_800FCCC2[arg0] = 0;
        D_800FCCC0[arg0] = 0;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D828.s")

#ifdef NON_MATCHING
void func_8003D918(u32 arg0, u32 arg1) {
    u32 temp_v0 = arg1 == 0x10;
    u8 sp1B = 0;
    u16 var_a0;

    func_80041A98();
    D_80078404 = arg1;
    D_80078408 = arg0;

    if (arg1 < 0x11) {
        D_800783FC = 1;
        D_8007840C = 1;

        if ((arg0 == 0) && (arg1 != 0x10) && (arg1 != 0xF)) {
            func_80041C70(0x34);
        } else if ((arg0 == 0xFF) && (arg1 != 0x10) && (arg1 != 0xF)) {
            func_80041C70(0x47);
            arg0 = 0;
            sp1B = 1;
        }

        if (arg1 < 0xC) {
            if (arg0 < 9) {
                var_a0 = D_80078410[arg1][arg0];
                D_800783FC = 1;
                D_80078400 = 1;
            } else {
                return;
            }
        } else if (arg1 == 0xC) {
            if ((arg0 < 0x21) && (arg0 != 0)) {
                var_a0 = D_800784EA[(arg0 - 1) / 8][(arg0 - 1) % 8];
                D_800783FC = 1;
                D_80078400 = 0;
            } else {
                return;
            }
        } else if (arg1 == 0xD) {
            if (arg0 < 6) {
                var_a0 = D_80078446[arg1][arg0];
                D_800783FC = 1;
                D_80078400 = 0;
            } else {
                return;
            }
        } else {
            if (arg1 == 0xE) {
                var_a0 = 0x49;
                D_800783FC = 1;
                D_80078400 = 2;
            } else if (arg1 == 0xF) {
                var_a0 = 0;
                D_800783FC = 0;
                D_80078400 = 0;
                arg0 = 1;
            } else {
                D_800783FC = 1;
                if (temp_v0) {
                    var_a0 = 0x48;
                    D_80078400 = 1;
                    arg0 = 1;
                } else {
                    var_a0 = 0;
                    D_80078400 = 1;
                }
            }
        }

        if ((arg0 == 0) && (sp1B == 0)) {
            D_80078400 = 2;
        }

        if (var_a0 != 0) {
            func_80041C70(var_a0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D918.s")
#endif

#ifdef NON_MATCHING
void func_8003DB84(s32 arg0) {
    s32 i;
    s32 var_t0;
    s32 var_t2;
    s32 var_t4;
    s32 var_t5;
    s32 var_v0;
    u32 var_a0;
    u32 temp_v0;

    if (arg0 != 0) {
        temp_v0 = osSetIntMask(1);
        D_800783BC = 1;
        D_800783C8 = 0;
        D_800783C0 = 0;
        D_800783C4 = 0;
        osSetIntMask(temp_v0);
        D_800783D4 = 0;
        D_800783D8 = 0;
        D_800783DC = 0;
        D_800FCCAE = 0;
        D_800FCCAF = 0;
        D_800FCCB2 = 0;
        D_800FCCB6 = 0;
        D_800783E8 = 0;
        D_800783EC = 0;
        D_800FCCA4 = 0;
        func_800367A0(0x5A, D_80078400, 0);

        if ((D_800FCB18[0] != NULL) && (D_800FCB18[1] != NULL)) {
            if (D_800FCB18[0] != NULL) {
                D_800FCB28 = D_800FCB18[0]->unk_0C;
            }

            if (D_800FCB18[1] != NULL) {
                D_800FCB2C = D_800FCB18[1]->unk_0C;
            }

            D_800FCB48[0].unk_24++;
            D_800FCB48[0].unk_00[D_800FCB48[0].unk_24 & 0xF] = D_800FCB18[0]->unk_0C;
            D_800FCB48[1].unk_24++;
            D_800FCB48[1].unk_00[D_800FCB48[1].unk_24 & 0xF] = D_800FCB18[1]->unk_0C;

            if (D_800783CC != 0) {
                var_t0 = 1;
                if (D_800FCB18[0]->unk_26 < D_800FCB18[1]->unk_26) {
                    var_t2 = 0;
                    var_t4 = 1;
                } else {
                    var_t4 = 0;
                    var_t2 = 1;
                }

                if (D_800FCB18[0]->unk_0C < D_800FCB18[1]->unk_0C) {
                    var_t0 = 0;
                    var_t5 = 1;
                } else {
                    var_t5 = 0;
                }

                if (D_800783CC < 2) {
                    if ((D_800FCB18[0]->unk_0C == 0) || (D_800FCB18[1]->unk_0C == 0)) {
                        temp_v0 = osSetIntMask(1);
                        D_800783C0 = 1;
                        osSetIntMask(temp_v0);

                        if (D_800FCB18[0]->unk_0C == 0) {
                            D_800FCCB0 = 1;
                        } else {
                            D_800FCCB0 = 2;
                        }

                        if ((D_800FCB18[0]->unk_0C == 0) && (D_800FCB18[1]->unk_0C == 0)) {
                            func_800420C0(D_80077E90);
                            return;
                        }

                        func_800420C0(D_80077E48);
                        return;
                    }

                    if ((((D_800FCB18[0]->unk_0C * 0x64u) / D_800FCB18[0]->unk_28) < 0x1E) &&
                        (((D_800FCB18[1]->unk_0C * 0x64u) / D_800FCB18[1]->unk_28) < 0x1E)) {
                        func_800420C0(D_80077E88);
                        return;
                    }

                    if (((((D_800FCB18[var_t4]->unk_26 - D_800FCB18[var_t2]->unk_26) * 0x64u) /
                          D_800FCB18[var_t2]->unk_26) >= 0x15) &&
                        (((D_800FCB18[var_t2]->unk_0C * 0x64u) / D_800FCB18[var_t2]->unk_28) < 0x28) &&
                        (((D_800FCB18[var_t4]->unk_0C * 0x64u) / D_800FCB18[var_t4]->unk_28) >= 0x51)) {
                        if (__ull_rem(osGetTime(), 3) == 0) {
                            var_a0 = 0x256;
                            goto block_53;
                        }
                    }

                    if ((((D_800FCB18[0]->unk_0C * 0x64u) / D_800FCB18[0]->unk_28) >= 0x5B) &&
                        (((D_800FCB18[1]->unk_0C * 0x64u) / D_800FCB18[1]->unk_28) >= 0x5B)) {
                        func_800420C0(D_80077E68);
                        return;
                    }

                    if (D_80078400 == 0) {
                        func_800420C0(D_80077E78);
                        return;
                    }

                    func_800420C0(D_80077DF0);
                    return;
                }

                if ((D_800FCB18[0]->unk_0C == 0) || (D_800FCB18[1]->unk_0C == 0)) {
                    temp_v0 = osSetIntMask(1);
                    D_800783C0 = 1;
                    osSetIntMask(temp_v0);

                    if (D_800FCB18[0]->unk_0C == 0) {
                        D_800FCCB0 = 1;
                    } else {
                        D_800FCCB0 = 2;
                    }

                    if (D_80078390[0] >= D_80078390[1]) {
                        var_v0 = D_80078390[0] - D_80078390[1];
                    } else {
                        var_v0 = D_80078390[1] - D_80078390[0];
                    }

                    if (var_v0 >= 2) {
                        func_800420C0(D_80077E70);
                        return;
                    }

                    if ((D_80078390[0] == 1) && (D_80078390[1] == 1)) {
                        var_a0 = 0x290;
                        if (D_800783E4 != 0) {
                            D_800783E4 = 0;
                        } else {
                            if (__ull_rem(osGetTime(), 2) != 0) {
                                var_a0 = 0x254;
                            } else {
                                var_a0 = 0x26B;
                            }
                        }
                    block_53:
                        func_80041C70(var_a0);
                        return;
                    }

                    if (D_80078390[D_800FCCB0 - 1] == 1) {
                        func_80041C70(0x26A);
                        return;
                    }

                    func_800420C0(D_80077E00);
                    return;
                }

                if (D_800FCCB0 != 0) {
                    if (((D_80078390[0] == 1) || (D_80078390[1] == 1)) && (D_80078390[0] < 4) && (D_80078390[1] < 4)) {
                        if (D_80078390[0] == 1) {
                            switch (D_80078390[1]) {
                                case 1:
                                    func_80041C70(0x260);
                                    func_80041C70(0x266);
                                    break;

                                case 2:
                                    func_80041C70(0x261);
                                    if (D_800FCCB0 == 1) {
                                        func_80041C70(0x265);
                                    } else {
                                        func_80041C70(0x267);
                                    }
                                    break;

                                case 3:
                                    func_80041C70(0x262);
                                    func_80041C70(0x264);
                                    break;

                                default:
                                    func_80041C70(0x271);
                                    break;
                            }

                            D_800FCCB0 = 0;
                            return;
                        }

                        switch (D_80078390[0]) {
                            case 2:
                                func_80041C70(0x25E);
                                if (D_800FCCB0 == 2) {
                                    func_80041C70(0x265);
                                } else {
                                    func_80041C70(0x267);
                                }
                                break;

                            case 3:
                                func_80041C70(0x25C);
                                func_80041C70(0x264);
                                break;

                            default:
                                func_80041C70(0x271);
                                break;
                        }

                        D_800FCCB0 = 0;
                        return;
                    }

                    if (D_800FCCB1 != 0) {
                        if (__ull_rem(osGetTime(), 2) != 0) {
                            D_800FCCB0 = 0;
                            func_800420C0(D_80077E10);
                            return;
                        }
                    }

                    if (D_800FCB18[0]->unk_16[6] != D_800FCB18[1]->unk_16[6]) {
                        if (D_800FCB18[0]->unk_16[6] != D_800FCB18[1]->unk_16[7]) {
                            if ((D_800FCB18[0]->unk_16[7] != D_800FCB18[1]->unk_16[6]) &&
                                (D_800FCB18[0]->unk_16[7] != D_800FCB18[1]->unk_16[7])) {
                                D_800FCCB0 = 0;
                                func_800420C0(D_80077E18);
                                return;
                            }
                        }
                    }

                    D_800FCCB0 = 0;
                    switch (D_80078390[0]) {
                        case 2:
                            switch (D_80078390[1]) {
                                case 2:
                                    func_80041C70(0x25D);
                                    func_80041C70(0x268);
                                    return;

                                case 3:
                                    func_80041C70(0x25F);
                                    func_80041C70(0x263);
                                    return;

                                default:
                                    func_80041C70(0x271);
                                    return;
                            }
                            break;

                        case 3:
                            if (D_80078390[1] == 2) {
                                func_80041C70(0x25B);
                                func_80041C70(0x263);
                                return;
                            }

                            func_80041C70(0x271);
                            return;

                        default:
                            if (D_80078400 == 0) {
                                func_800420C0(D_80077E78);
                                return;
                            }

                            func_800420C0(D_80077DF0);
                            return;
                    }
                } else {

                    if (D_800FCCB3 != 0) {
                        func_800420C0(D_80077E38);
                        D_800FCCB3 = 0;
                        return;
                    }

                    if (D_800FCCB4 != 0) {
                        func_800420C0(D_80077E40);
                        D_800FCCB4 = 0;
                        return;
                    }

                    if (D_800FCCB5 != 0) {
                        func_800420C0(D_80077E50);
                        D_800FCCB5 = 0;
                        return;
                    }

                    if ((D_800FCB18[0]->unk_28 * 0.5f) < (D_800FCB48[0].unk_00[(D_800FCB48[0].unk_24 - 1) & 0xF] -
                                                          D_800FCB48[0].unk_00[D_800FCB48[0].unk_24 & 0xF])) {
                        if ((D_800FCB18[1]->unk_28 * 0.5f) < (D_800FCB48[1].unk_00[(D_800FCB48[1].unk_24 - 1) & 0xF] -
                                                              D_800FCB48[1].unk_00[(D_800FCB48[1].unk_24 & 0xF)])) {
                            if ((((D_800FCB18[0]->unk_0C * 0x64u) / D_800FCB18[0]->unk_28) < 0x14u) &&
                                (((D_800FCB18[1]->unk_0C * 0x64u) / D_800FCB18[1]->unk_28) < 0x14u)) {
                                func_800420C0(D_80077E60);
                            } else {
                                func_800420C0(D_80077E58);
                            }
                            return;
                        }
                    }

                    if (D_800FCB18[0]->unk_0C >= D_800FCB18[1]->unk_0C) {
                        var_v0 = D_800FCB18[0]->unk_0C - D_800FCB18[1]->unk_0C;
                    } else {
                        var_v0 = D_800FCB18[1]->unk_0C - D_800FCB18[0]->unk_0C;
                    }

                    if ((D_800FCB18[var_t0]->unk_28 * D_8007C7E0) < var_v0) {
                        if ((((D_800FCB18[var_t5]->unk_0C * 0x64u) / D_800FCB18[var_t5]->unk_28) >= 0x47) &&
                            (D_800FCB18[0]->unk_0C != D_800FCB18[0]->unk_28) &&
                            (D_800FCB18[1]->unk_0C != D_800FCB18[1]->unk_28)) {
                            if ((D_800FCB18[var_t5]->unk_28 * D_8007C7E8) < D_800FCB18[var_t5]->unk_0C) {
                                if (D_800FCB18[var_t0]->unk_0C < (D_800FCB18[var_t0]->unk_28 * D_8007C7F0)) {
                                    func_800420C0(D_80077E20);
                                    return;
                                }
                            }
                        }
                    }

                    if (D_800FCB18[0]->unk_0C >= D_800FCB18[1]->unk_0C) {
                        var_v0 = D_800FCB18[0]->unk_0C - D_800FCB18[1]->unk_0C;
                    } else {
                        var_v0 = D_800FCB18[1]->unk_0C - D_800FCB18[0]->unk_0C;
                    }

                    if (var_v0 < 0xA) {
                        if ((D_800FCB18[0]->unk_28 * 0.5) < D_800FCB18[0]->unk_0C) {
                            if (((D_800FCB18[1]->unk_28 * 0.5) < D_800FCB18[1]->unk_0C) &&
                                (D_800FCB18[0]->unk_0C < D_800FCB18[0]->unk_28) &&
                                (D_800FCB18[1]->unk_0C < D_800FCB18[1]->unk_28)) {
                                func_800420C0(D_80077E30);
                                return;
                            }
                        }
                    }

                    if (D_800FCB18[0]->unk_0C >= D_800FCB18[1]->unk_0C) {
                        var_v0 = D_800FCB18[0]->unk_0C - D_800FCB18[1]->unk_0C;
                    } else {
                        var_v0 = D_800FCB18[1]->unk_0C - D_800FCB18[0]->unk_0C;
                    }

                    if (var_v0 < 0xA) {
                        if (D_800FCB18[0]->unk_0C < (D_800FCB18[0]->unk_28 * D_8007C7F8)) {
                            if (D_800FCB18[1]->unk_0C < (D_800FCB18[1]->unk_28 * D_8007C7F8)) {
                                func_800420C0(D_80077E28);
                                return;
                            }
                        }
                    }

                    if (D_80078400 == 0) {
                        func_800420C0(D_80077E78);
                    } else {
                        func_800420C0(D_80077DF0);
                    }
                    return;
                }
            }
        }
    } else {
        temp_v0 = osSetIntMask(1);
        D_800783BC = 0;
        osSetIntMask(temp_v0);
        func_80037234(0x5A, 0);
        func_80037234(0x5B, 0);

        if (D_800FCB18[0] != NULL) {
            D_800FCB28 = D_800FCB18[0]->unk_0C;
        }

        if (D_800FCB18[1] != NULL) {
            D_800FCB2C = D_800FCB18[1]->unk_0C;
        }

        D_800783CC++;

        for (i = 0; i < 2; i++) {
            D_800FCB48[i].unk_78++;
            if (D_800FCB48[i].unk_7C != 0) {
                D_800FCB48[i].unk_7C++;
            }
        }

        D_800FCCB4 = 0;
        D_800FCCB3 = 0;
        D_800FCCB5 = 0;
        D_800783E4 = 0;

        if ((D_800FCB18[0] != NULL) && (D_800FCB18[1] != NULL) && (D_8007840C != 0) && (D_800FCB18[0]->unk_0C != 0) &&
            (D_800FCB18[1]->unk_0C != 0) && (func_80044E54(1) == 0)) {
            if (__ull_rem(osGetTime(), 2) == 0) {
                func_800420C0(D_800780A8);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003DB84.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003EB40.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003F1AC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003F4C0.s")

void func_8003F624(u32 arg0) {
    D_800FCCF0[D_80078544] = arg0;
    D_80078544++;
    if (D_80078544 >= 0xA) {
        D_80078544--;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003F660.s")

u32 func_80042158(u32, unk_D_800FCB18*, unk_D_800FCB18*);

#ifdef NON_MATCHING
void func_80040A70(unk_D_800FCB18* arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 sp40;
    u32 temp_lo;
    u32 temp_v0;
    s32 sp34;
    u32 tmp;
    OSIntMask sp2C;

    if (arg0 == NULL) {
        return;
    }

    if (arg0 == D_800FCB18[0]) {
        sp40 = 0;
    } else if (arg0 == D_800FCB18[1]) {
        sp40 = 1;
    } else {
        return;
    }

    if ((D_800FCB18[0] == NULL) || (D_800FCB18[1] == NULL)) {
        return;
    }

    D_800FCCAC = arg1;

    switch (arg3) {
        case 1:
            D_800FCCB7 = 0;
            func_80041CEC();
            sp40 ^= 1;

            if (D_800FCB18[sp40]->unk_0C != 0) {
                for (i = 0; i < 5; i++) {
                    if (arg1 == D_80078548[i].unk_00) {
                        if (D_800FCB18[sp40]->unk_0C < D_800FCB48[sp40].unk_00[D_800FCB48[sp40].unk_24 & 0xF]) {
                            tmp = (D_800FCB48[sp40].unk_00[D_800FCB48[sp40].unk_24 & 0xF] - D_800FCB18[sp40]->unk_0C);
                            D_800FCCA4 = (tmp * 0x64) / D_800FCB18[sp40]->unk_28;
                        } else {
                            D_800FCCA4 = 0;
                        }
                        D_800FCCAD = arg2;
                        return;
                    }

                    if (arg1 == D_80078548[i].unk_01) {
                        if (D_800FCB18[sp40]->unk_0C < D_800FCB48[sp40].unk_00[D_800FCB48[sp40].unk_24 & 0xF]) {
                            tmp = D_800FCB48[sp40].unk_00[D_800FCB48[sp40].unk_24 & 0xF] - D_800FCB18[sp40]->unk_0C;
                            D_800FCCA4 = (tmp * 0x64) / D_800FCB18[sp40]->unk_28;
                        } else {
                            D_800FCCA4 = 0;
                        }
                        D_800FCCAD = arg2;
                        return;
                    }
                }
            }

            temp_v0 = osSetIntMask(sp2C);

            D_800FCCA2 = 0x1E;
            if (D_800FCB18[sp40]->unk_0C < D_800FCB48[sp40].unk_00[D_800FCB48[sp40].unk_24 & 0xF]) {
                tmp = D_800FCB48[sp40].unk_00[D_800FCB48[sp40].unk_24 & 0xF] - D_800FCB18[sp40]->unk_0C;
                D_800FCCA4 = (tmp * 0x64) / D_800FCB18[sp40]->unk_28;
            } else {
                D_800FCCA4 = 0;
            }
            D_800FCCAD = arg2;

            osSetIntMask(temp_v0);

            if (D_800FCCA4 >= 0x29) {
                func_800367A0(0x16, D_80078400, 0);
            }
            break;

        case 0:
        case 2:
            func_80041CEC();
            D_800FCCC0[sp40] = 0;
            D_800FCCC2[sp40] = 0;

            if (arg1 != 0x13) {
                D_800FCCCE[sp40] = 0;
            }

            if (arg1 != 0x5B) {
                D_800FCCD0[sp40] = 0;
            }

            if (arg3 != 2) {
                D_800FCCD2[sp40] = 0;
            }

            D_800FCCAE += 1;

            for (i = 0; i < 17; i++) {
                if (arg1 == D_80078554[i]) {
                    goto loop1_end;
                }
            }

            D_800FCCC6[sp40] = 0;
        loop1_end:

            for (i = 0; i < 9; i++) {
                if (arg1 == D_80078568[i]) {
                    goto loop2_end;
                }
            }

            D_800FCCC8[sp40] = 0;
        loop2_end:

            D_800FCCA2 = 0;
            if (D_800FCCB7 == 0) {
                tmp = func_80042158(arg1, D_800FCB18[sp40], D_800FCB18[sp40 ^ 1]);

                if (tmp == -1) {
                    if (func_8003D624(D_800FCCD8, arg1 - 1) == 0) {
                        sp34 = arg1 + 0x1A2;
                        func_8003D570(D_800FCCD8, arg1 - 1, 1);
                        func_80041C70(sp34);
                    } else {
                        func_800420C0(D_80077F6C);
                    }
                } else if (tmp == -2) {
                    if (func_8003D624(D_800FCCD8, arg1 - 1) == 0) {
                        sp34 = arg1 + 0x1A2;
                        func_8003D570(D_800FCCD8, arg1 - 1, 1);
                        func_80041C70(sp34);
                    } else {
                        func_800420C0(D_80077F74);
                    }
                } else if (tmp == -3) {
                    D_800783D4 = 1;
                    if (func_8003D624(D_800FCCD8, arg1 - 1) == 0) {
                        sp34 = arg1 + 0x1A2;
                        func_8003D570(D_800FCCD8, arg1 - 1, 1);
                        func_80041C70(sp34);
                    } else {
                        func_80041C70(0x187);
                    }
                } else if (tmp == -4) {
                    if (func_8003D624(D_800FCCD8, arg1 - 1) == 0) {
                        sp34 = arg1 + 0x1A2;
                        func_8003D570(D_800FCCD8, arg1 - 1, 1);
                        func_80041C70(sp34);
                    } else {
                        func_800420C0(D_80077F98);
                    }
                } else if (tmp != -5) {
                    if ((D_800FCB48[sp40 ^ 1].unk_00[D_800FCB48[sp40 ^ 1].unk_24 & 0xF] < tmp) && (D_800FCCB6 == 0)) {
                        if (func_8003D624(D_800FCCD8, arg1 - 1) == 0) {
                            sp34 = arg1 + 0x1A2;
                            func_8003D570(D_800FCCD8, arg1 - 1, 1);
                            func_80041C70(sp34);
                        } else {
                            func_800420C0(D_80077F90);
                            D_800FCCB6 = 0;
                        }
                    } else {
                        D_800FCCB6 = 0;
                        temp_lo = (tmp * 0x64) / D_800FCB18[sp40 ^ 1]->unk_28;
                        if (temp_lo >= 0x51) {
                            if (D_800FCCAF == 0) {
                                D_800FCCAF = 1;
                                func_800420C0(D_80077F6C);
                            } else {
                                func_800420C0(D_80077F74);
                            }
                        } else if (temp_lo >= 0x33) {
                            if (D_800783CC == 1) {
                                func_800420C0(D_80077F88);
                            } else {
                                func_800420C0(D_80077F7C);
                            }
                        } else if (func_80044E54(1) == 0) {
                            if (D_800783CC == 1) {
                                if (D_800FCCAE == 2) {
                                    func_800420C0(D_80077FAC);
                                } else {
                                    func_800420C0(D_80077FA4);
                                }
                            } else {
                                func_800420C0(D_80077F98);
                            }
                        }
                    }
                }
            }
            break;

        case 3:
            if (D_800FCCB7 == 0) {
                D_800FCCB7 = 1;
                D_800FCCA2 = 0;
                tmp = func_80042158(arg1, D_800FCB18[sp40], D_800FCB18[sp40 ^ 1]);
                if ((tmp >> 0x10) == 0) {
                    tmp = tmp << 1;

                    if (D_800FCB48[sp40 ^ 1].unk_00[D_800FCB48[sp40 ^ 1].unk_24 & 0xF] < tmp) {
                        if (func_8003D624(D_800FCCD8, arg1 - 1) == 0) {
                            sp34 = arg1 + 0x1A2;
                            func_8003D570(D_800FCCD8, arg1 - 1, 1);
                            func_80041C70(sp34);
                        } else {
                            func_800420C0(D_80077F90);
                        }
                    } else {
                        temp_lo = (tmp * 0x64u) / D_800FCB18[sp40 ^ 1]->unk_28;
                        if (temp_lo >= 0x51) {
                            if (D_800FCCAF == 0) {
                                D_800FCCAF = 1;
                                func_800420C0(D_80077F6C);
                            } else {
                                func_800420C0(D_80077F74);
                            }
                        } else if (temp_lo >= 0x33) {
                            if (D_800783CC == 1) {
                                func_800420C0(D_80077F88);
                            } else {
                                func_800420C0(D_80077F7C);
                            }
                        } else if (func_80044E54(1) == 0) {
                            if (D_800783CC == 1) {
                                if (D_800FCCAE == 2) {
                                    func_800420C0(D_80077FAC);
                                } else {
                                    func_800420C0(D_80077FA4);
                                }
                            } else {
                                func_800420C0(D_80077F98);
                            }
                        }
                    }
                }
            }
            break;

        case 4:
            D_800FCCAE += 1;
            D_800FCCB7 = 0;
            D_800FCCA2 = 0;
            break;

        case 5:
            D_800FCCB7 = 0;
            D_800FCCA2 = 0;
            break;

        default:
            D_800FCCB7 = 0;
            D_800FCCA2 = 0;
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_80040A70.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_800414B8.s")

void func_8004153C(void) {
    if (D_80078E80 == 0) {
        func_8004B1CC(0x3D);
        func_800367A0(0x16, D_80078400, 0);
        if (D_80078404 == 0xC) {
            if (!(D_80078408 & 3) && (*D_80078390 != 0)) {
                func_80041C70(0xCA);
                return;
            }
            func_80041C70(0xC8);
            return;
        }
        if (D_80078404 == 0xD) {
            if ((D_80078408 == 4) && (*D_80078390 != 0)) {
                func_80041C70(0xCA);
                return;
            }
            if ((D_80078408 == 5) && (*D_80078390 != 0)) {
                func_80041C70(0xCB);
                return;
            }
            func_80041C70(0xC8);
            return;
        }
        if ((D_80078408 == 8) && (*D_80078390 != 0)) {
            func_80041C70(0xC9);
            return;
        }
        func_80041C70(0xC8);
    }
}

void func_80041688(void) {
    func_800367A0(0x16, D_80078400, 0);
    func_80041C70(0x1A2);
}

void func_800416BC(void) {
    u8* seq;

    if ((D_800783B4 < D_800783B8) && (D_80078388 != 0) && (func_80044E54(1) == 0)) {
        if (D_800783A4[D_800783B4 & 3] != 0) {
            seq = D_800FC714->seqArray[D_800783A4[D_800783B4 & 3] - 1].offset;
            func_80044CBC(1, seq, 0x7E, 0);
        }
        D_800783B4++;
    }

    if (D_800783BC != 0) {
        if ((D_800783C8 >= 0x3E9) && (D_800783C0 == 0) && (D_800783CC != 0)) {
            func_80041C70(0x248);
            D_800783C0 = 1;
        } else if ((D_800783C8 >= 0x7D1) && (D_800783C0 == 0) && (D_800783CC == 0)) {
            func_80041C70(0x248);
            D_800783C0 = 1;
            D_800783C8 = 0x3E8;
        } else if ((D_800783C8 >= 0x641) && (D_800783C0 == 1)) {
            func_80041C70(0x249);
            if (D_800783C4 == 0) {
                func_800367A0(0x5B, D_80078400, 0);
                D_800783C4 = 1;
            }
            D_800783C0 = 2;
        } else if ((D_800783C8 >= 0x899) && (D_800783C0 == 2)) {
            func_80041C70(0x24A);
            D_800783C8 = 0x3E8;
            D_800783C0 = 1;
        }

        D_800783C8++;
    }

    if (D_800FCCA2 != 0) {
        if (D_800FCCA2 == 1) {
            if (D_800FCCA4 != 0) {
                if (D_800FCCA4 >= 0x29) {
                    if (((D_800FCCAD == 0x10) || (D_800FCCAD == 0x11) || (D_800FCCAD == 0x12) || (D_800FCCAD == 0x15) ||
                         (D_800FCCAD == 0x16) || (D_800FCCAD == 0x53) || (D_800FCCAD == 0x54) ||
                         (D_800FCCAD == 0x55)) &&
                        ((D_800FCCAC == 0x34) || (D_800FCCAC == 0x35) || (D_800FCCAC == 0x7E))) {
                        func_800420C0(&D_80077F44);
                    } else {
                        func_800420C0(&D_80077E98);
                    }
                } else if (D_800FCCA4 >= 6) {
                    if ((D_800FCB18[0]->unk_0C > 0) && (D_800FCB18[1]->unk_0C > 0)) {
                        func_800420C0(&D_80077EA4);
                    } else {
                        func_800420C0(&D_80077F60);
                    }
                } else if ((D_800FCB18[0]->unk_0C > 0) && (D_800FCB18[1]->unk_0C > 0)) {
                    func_800420C0(&D_80077EB4);
                } else {
                    func_800420C0(&D_80077F04);
                }
            }
            D_800FCCA8 = D_800FCCA4;
        }
        D_800FCCA2--;
    }
}

#ifdef NON_MATCHING
void func_80041A98(void) {
    s32 i;
    s32 j;

    D_800783CC = 0;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 8; j++) {
            D_800FCB38[i][j] = 0;
        }
    }

    D_8007839C[0] = 0;
    D_8007839C[1] = 0;
    D_800FCCA1 = 0;
    D_800FCCA0 = 0;
    D_800FCCA2 = 0;
    D_800FCCA4 = 0;
    D_800FCCAC = 0;
    D_800783E0 = 0;
    D_800FCCAF = 0;
    D_800FCCB0 = 0;
    D_800FCCB2 = 0;
    D_800FCCB3 = 0;
    D_800FCCB4 = 0;
    D_800FCCB5 = 0;
    D_800FCCB7 = 0;
    D_800FCCB6 = 0;
    D_800783E4 = 0;
    D_800783E8 = 0;
    D_800783EC = 0;
    D_800783F0 = 0;
    D_800783F4 = 0;
    D_800783F8 = 0;

    for (i = 0; i < 21; i++) {
        D_800FCCD8[i] = 0;
    }

    for (i = 0; i < 80; i++) {
        D_800FCC50[i] = 0;
    }

    for (i = 0; i < 2; i++) {
        D_800FCCB8[i] = 0;
        D_800FCCBA[i] = 0;
        D_800FCCBC[i] = 0;
        D_800FCCBE[i] = 0;
        D_800FCCC0[i] = 0;
        D_800FCCC2[i] = 0;
        D_800FCCD4[i] = 0;
        D_800FCCD6[i] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_80041A98.s")
#endif

void func_80041C70(u32 arg0) {
    OSIntMask mask;

    if ((D_80078388 != 0) && (D_800783FC != 0) && (arg0 != 0)) {
        mask = osSetIntMask(OS_IM_NONE);
        D_800783A4[D_800783B8 & 3] = arg0;
        D_800783B8++;
        osSetIntMask(mask);
    }
}

void func_80041CEC(void) {
    OSIntMask mask;

    if ((D_80078388 != 0) && (D_800783FC != 0)) {
        mask = osSetIntMask(OS_IM_NONE);
        D_800783A4[(D_800783B8 - 1) & 3] = 0;
        osSetIntMask(mask);
    }
}

void func_80041D50(u8* arg0, u8* arg1) {
    u8 temp_v0 = *arg0;
    u8 temp_v1 = *arg1;

    if (temp_v1 != temp_v0) {
        *arg0 = temp_v1;
        *arg1 = temp_v0;
    }
}

u16 func_80041D70(u16 arg0) {
    s32 i;

    for (i = 0; i < 20; i++) {
        if (arg0 == D_800FCC50[i]) {
            return 0;
        }
    }

    return arg0;
}

void func_80041DF4(u16 arg0) {
    u16 i;

    for (i = 0; i < 19; i++) {
        D_800FCC50[i] = D_800FCC50[i + 1];
    }

    D_800FCC50[19] = arg0;
}

void func_80041E40(u16 arg0) {
    u32 i;

    for (i = arg0; i > 0; i--) {
        D_800FCC50[i] = D_800FCC50[i - 1];
    }

    D_800FCC50[0] = 0;
}

u32 func_80041EF4(u16* arg0) {
    u16 temp_v0 = *arg0;
    u32 i;
    u32 j;
    u16 sp5A;

    for (i = 0; i < temp_v0; i++) {
        D_800FCD18[i] = i + 1;
    }

    for (i = 0; i < temp_v0 << 1; i++) {
        func_80041D50(D_800FCD18, D_800FCD18 + __ull_rem(osGetTime(), (s32)temp_v0));
    }

    for (i = 0; i < temp_v0; i++) {
        sp5A = func_80041D70(arg0[D_800FCD18[i]]);
        if (sp5A != 0) {
            func_80041DF4(sp5A);
            return sp5A;
        }
    }

    for (i = 0; i < 20; i++) {
        for (j = 1; j <= temp_v0; j++) {
            if (D_800FCC50[i] == arg0[j]) {
                func_80041E40(i);
                func_80041DF4(arg0[j]);
                return arg0[j];
            }
        }
    }

    return 0;
}

void func_800420C0(u16* arg0) {
    u32 temp_v0 = func_80041EF4(arg0);

    if (temp_v0 != 0) {
        func_80041C70(temp_v0);
    }
}

void func_800420F0(u16 arg0, u16* arg1, u8* arg2) {
    u8 temp_v0;

    if (*arg2 == 0) {
        func_80041C70(arg0);
    } else {
        func_800420C0(arg1);
    }
    temp_v0 = *arg2;
    if (temp_v0 < 0xFF) {
        *arg2 = temp_v0 + 1;
    }
}

void func_800420F0_empty() {
    
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_80042158.s")

s32 func_80042850(u8 arg0) {
    switch (arg0) {
    case 0:
        return 0;
    case 20:
        return 1;
    case 21:
        return 2;
    case 23:
        return 3;
    case 22:
        return 4;
    case 25:
        return 5;
    case 1:
        return 6;
    case 3:
        return 7;
    case 4:
        return 8;
    case 2:
        return 9;
    case 24:
        return 0xA;
    case 7:
        return 0xB;
    case 5:
        return 0xC;
    case 8:
        return 0xD;
    case 26:
        return 0xE;
    default:
        return 0;
    }
}

#ifdef NON_MATCHING
void func_800428FC(void) {
    func_80041C70(0); // Should not take an argument
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_800428FC.s")
#endif
