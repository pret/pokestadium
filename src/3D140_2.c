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
extern s32 D_800FC820;
extern s8 D_800FC824;
extern u8 D_800FC825;
extern s32 D_800FC828;
extern AMAudioMgr __am;
extern AMDMAState dmaState;
extern s32 minFrameSize;
extern u32 frameSize;
extern s32 maxFrameSize;
extern s32 maxRSPCmds;
extern s32 D_800FCAD4;
extern s32 D_800FCAD8;
extern OSMesgQueue audDMAMessageQ;
extern AMDMABuffer* dmaBuffs;
extern OSIoMesg* audDMAIOMesgBuf;
extern OSMesg* audDMAMessageBuf;
extern u32 dmaBufferLen;
extern OSPiHandle* D_800FCB08[4];
// s32 D_800FCB0C[3];
extern unk_D_800FCB18* D_800FCB18[4];
extern s32 D_800FCB28[2];
extern u8 D_800FCB30[2];
extern u8 D_800FCB38[2][8];
extern unk_D_800FCB48 D_800FCB48[2];
extern s32 D_800FCC50[20];
extern s8 D_800FCCA0;
extern s8 D_800FCCA1;
extern u8 D_800FCCA2;
extern u32 D_800FCCA4;
extern s32 D_800FCCA8;
extern u8 D_800FCCAC;
extern u8 D_800FCCAD;
extern u8 D_800FCCAE;
extern u8 D_800FCCAF;
extern u8 D_800FCCB0;
extern u8 D_800FCCB1;
extern u8 D_800FCCB2;
extern u8 D_800FCCB3;
extern u8 D_800FCCB4;
extern u8 D_800FCCB5;
extern u8 D_800FCCB6;
extern u8 D_800FCCB7;
extern u8 D_800FCCB8[2];
extern u8 D_800FCCBA[2];
extern u8 D_800FCCBC[2];
extern u8 D_800FCCBE[2];
extern u8 D_800FCCC0[2];
extern u8 D_800FCCC2[2];
extern s8 D_800FCCC4[2];
extern u8 D_800FCCC6[2];
extern u8 D_800FCCC8[2];
extern u8 D_800FCCCA[2];
extern u8 D_800FCCCC[2];
extern u8 D_800FCCCE[2];
extern u8 D_800FCCD0[2];
extern u8 D_800FCCD2[2];
extern u8 D_800FCCD4[2];
extern u8 D_800FCCD6[2];
extern s8 D_800FCCD8[0x18];
extern u32 D_800FCCF0[10];
extern u8 D_800FCD18[0x28];

// function prototypes
void func_800420F0(u16, u16*, u8*);
u32 func_80042158(u32, unk_D_800FCB18*, unk_D_800FCB18*);
s32 func_80042850(u8);
ALDMAproc __amDmaNew(AMDMAState** state);

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
    D_8007838C[0] = arg0;
    D_8007838C[1] = arg1;
    D_8007838C[2] = arg2;
    D_8007838C[3] = arg3;
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

void func_8003D828(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    s32 i;
    s32 j;

    D_80078398[0] = arg0;
    D_80078398[1] = arg1;
    D_80078398[2] = arg2;
    D_80078398[3] = arg3;
    D_80078394[0] = 0xFF;
    D_80078394[1] = 0xFF;
    D_80078390[0] = 0;
    D_80078390[1] = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            if (i + 1 == D_80078398[j]) {
                D_80078390[i] += D_8007838C[j];
            }
        }
    }
    D_800FCB18[0] = 0;
    D_800FCB18[1] = 0;
    D_800FCB28[0] = 0;
    D_800FCB28[1] = 0;
    func_8003D6DC(0);
    func_8003D6DC(1);
}

void func_8003D918(u32 arg0, u32 arg1) {
    s32 pad[1];
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
                if (arg1 == 0x10) {
                    var_a0 = 0x48;
                    D_80078400 = 1;
                    arg0 = 1;
                } else {
                    var_a0 = 0;
                    D_80078400 = 1;
                }
                D_800783FC = 1;
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

#ifdef NON_MATCHING
// Only a spill slot differs: target uses 0x1C(sp), this compiles to 0x18(sp)
void func_8003DB84(s32 arg0) {
    s8 var_t0;
    s8 var_t2;
    s8 var_t4;
    s8 var_t5;
    s32 var_v0;
    s32 var_a0;
    s32 i;

    if (arg0 != 0) {
        var_v0 = osSetIntMask(1);
        D_800783BC = 1;
        D_800783C8 = 0;
        D_800783C0 = 0;
        D_800783C4 = 0;
        osSetIntMask(var_v0);
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

        if ((D_800FCB18[0] == NULL) || (D_800FCB18[1] == NULL)) {
            return;
        }

        if (D_800FCB18[0] != NULL) {
            D_800FCB28[0] = D_800FCB18[0]->unk_0C;
        }

        if (D_800FCB18[1] != NULL) {
            D_800FCB28[1] = D_800FCB18[1]->unk_0C;
        }

        D_800FCB48[0].unk_24++;
        D_800FCB48[0].unk_00[D_800FCB48[0].unk_24 & 0xF] = D_800FCB18[0]->unk_0C;
        D_800FCB48[1].unk_24++;
        D_800FCB48[1].unk_00[D_800FCB48[1].unk_24 & 0xF] = D_800FCB18[1]->unk_0C;

        if (D_800783CC == 0) {
            return;
        }

        if (D_800FCB18[0]->unk_26 < D_800FCB18[1]->unk_26) {
            var_t2 = 0;
            var_t4 = 1;
        } else {
            var_t2 = 1;
            var_t4 = 0;
        }

        if (D_800FCB18[0]->unk_0C < D_800FCB18[1]->unk_0C) {
            var_t0 = 0;
            var_t5 = 1;
        } else {
            var_t0 = 1;
            var_t5 = 0;
        }

        if (D_800783CC < 2) {
            if ((D_800FCB18[0]->unk_0C == 0) || (D_800FCB18[1]->unk_0C == 0)) {
                var_v0 = osSetIntMask(1);
                D_800783C0 = 1;
                osSetIntMask(var_v0);

                if (D_800FCB18[0]->unk_0C == 0) {
                    D_800FCCB0 = 1;
                } else {
                    D_800FCCB0 = 2;
                }

                if ((D_800FCB18[0]->unk_0C == 0) && (D_800FCB18[1]->unk_0C == 0)) {
                    func_800420C0(D_80077E90);
                } else {
                    func_800420C0(D_80077E48);
                }
                return;
            }

            if (((((u32)D_800FCB18[0]->unk_0C * 100) / D_800FCB18[0]->unk_28) < 0x1E) &&
                ((((u32)D_800FCB18[1]->unk_0C * 100) / D_800FCB18[1]->unk_28) < 0x1E)) {
                func_800420C0(D_80077E88);
                return;
            }

            if (((((D_800FCB18[var_t4]->unk_26 - D_800FCB18[var_t2]->unk_26) * 0x64U) /
                  D_800FCB18[var_t2]->unk_26) >= 0x15) &&
                ((((u32)D_800FCB18[var_t2]->unk_0C * 100) / D_800FCB18[var_t2]->unk_28) < 0x28) &&
                ((((u32)D_800FCB18[var_t4]->unk_0C * 100) / D_800FCB18[var_t4]->unk_28) >= 0x51)) {
                if ((osGetTime() % 3) == 0) {
                    var_a0 = 0x256;
                    goto block_53;
                }
            }

            if (((((u32)D_800FCB18[0]->unk_0C * 100) / D_800FCB18[0]->unk_28) >= 0x5B) &&
                ((((u32)D_800FCB18[1]->unk_0C * 100) / D_800FCB18[1]->unk_28) >= 0x5B)) {
                func_800420C0(D_80077E68);
            } else if (D_80078400 == 0) {
                func_800420C0(D_80077E78);
            } else {
                func_800420C0(D_80077DF0);
            }
            return;
        }

        if ((D_800FCB18[0]->unk_0C == 0) || (D_800FCB18[1]->unk_0C == 0)) {
            var_v0 = osSetIntMask(1);
            D_800783C0 = 1;
            osSetIntMask(var_v0);

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
                if (D_800783E4 != 0) {
                    D_800783E4 = 0;
                    var_a0 = 0x290;
                } else if ((osGetTime() % 2) != 0) {
                    var_a0 = 0x254;
                } else {
                    var_a0 = 0x26B;
                }
            block_53:
                func_80041C70(var_a0);
            } else if (D_80078390[D_800FCCB0 - 1] == 1) {
                func_80041C70(0x26A);
            } else {
                func_800420C0(D_80077E00);
            }
            return;
        }

        if (D_800FCCB0 != 0) {
            if (((D_80078390[0] == 1) || (D_80078390[1] == 1)) && (D_80078390[0] < 4) &&
                (D_80078390[1] < 4)) {
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
                if ((osGetTime() % 2) != 0) {
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
                            break;

                        case 3:
                            func_80041C70(0x25F);
                            func_80041C70(0x263);
                            break;

                        default:
                            func_80041C70(0x271);
                            break;
                    }
                    break;

                case 3:
                    if (D_80078390[1] == 2) {
                        func_80041C70(0x25B);
                        func_80041C70(0x263);
                    } else {
                        func_80041C70(0x271);
                    }
                    break;

                default:
                    if (D_80078400 == 0) {
                        func_800420C0(D_80077E78);
                    } else {
                        func_800420C0(D_80077DF0);
                    }
                    break;
            }

            return;
        }

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

        if ((D_800FCB18[0]->unk_28 * 0.5f) <
            (D_800FCB48[0].unk_00[(D_800FCB48[0].unk_24 - 1) & 0xF] -
             D_800FCB48[0].unk_00[D_800FCB48[0].unk_24 & 0xF])) {
            if ((D_800FCB18[1]->unk_28 * 0.5f) <
                (D_800FCB48[1].unk_00[(D_800FCB48[1].unk_24 - 1) & 0xF] -
                 D_800FCB48[1].unk_00[D_800FCB48[1].unk_24 & 0xF])) {
                if (((((u32)D_800FCB18[0]->unk_0C * 100) / D_800FCB18[0]->unk_28) < 0x14U) &&
                    ((((u32)D_800FCB18[1]->unk_0C * 100) / D_800FCB18[1]->unk_28) < 0x14U)) {
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

        if (((D_800FCB18[var_t0]->unk_28 * 0.7) < var_v0) &&
            ((((u32)D_800FCB18[var_t5]->unk_0C * 100) / D_800FCB18[var_t5]->unk_28) >= 0x47) &&
            (D_800FCB18[0]->unk_0C != D_800FCB18[0]->unk_28) && (D_800FCB18[1]->unk_0C != D_800FCB18[1]->unk_28)) {
            if ((D_800FCB18[var_t5]->unk_28 * 0.6) < D_800FCB18[var_t5]->unk_0C) {
                if (D_800FCB18[var_t0]->unk_0C < (D_800FCB18[var_t0]->unk_28 * 0.4)) {
                    func_800420C0(D_80077E20);
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
            if (D_800FCB18[0]->unk_0C < (D_800FCB18[0]->unk_28 * 0.3)) {
                if (D_800FCB18[1]->unk_0C < (D_800FCB18[1]->unk_28 * 0.3)) {
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

    var_v0 = osSetIntMask(1);
    D_800783BC = 0;
    osSetIntMask(var_v0);
    func_80037234(0x5A, 0);
    func_80037234(0x5B, 0);

    if (D_800FCB18[0] != NULL) {
        D_800FCB28[0] = D_800FCB18[0]->unk_0C;
    }

    if (D_800FCB18[1] != NULL) {
        D_800FCB28[1] = D_800FCB18[1]->unk_0C;
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

    if ((D_800FCB18[0] != NULL) && (D_800FCB18[1] != NULL) && (D_8007840C != 0) &&
        (D_800FCB18[0]->unk_0C != 0) && (D_800FCB18[1]->unk_0C != 0) && (func_80044E54(1) == 0)) {
        if ((osGetTime() % 2) == 0) {
            func_800420C0(D_800780A8);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140_2/func_8003DB84.s")
#endif

void func_8003EB40(s32 arg0, unk_D_800FCB18* arg1) {
    u8 pad;
    u8 value;
    u8 side;
    u8 changed = 0;
    u32 i;
    u8 pad2;

    D_800FCCB1 = 0;
    D_800783F0 = 0;
    D_800783F4 = 0;
    D_800783F8 = 0;

    if (arg1 == NULL) {
        return;
    }
    if ((arg0 == 0) || ((u32)arg0 >= 5)) {
        return;
    }

    arg0--;
    side = D_80078398[arg0];
    if ((side <= 0) || (side >= 3)) {
        return;
    }
    side--;
    side &= 0xFF;

    if (D_80078394[side] != arg0) {
        changed = 1;
        D_80078394[side] = arg0;
    }

    D_800FCB18[side] = arg1;

    func_8003D6DC(side);

    D_800FCCC8[side ^ 1] = 0;

    D_800FCB28[side] = D_800FCB18[side]->unk_0C;
    D_800FCB48[side].unk_24++;
    D_800FCB48[side].unk_00[D_800FCB48[side].unk_24 & 0xF] = D_800FCB18[side]->unk_0C;

    value = D_800FCB18[side]->unk_0B;
    if ((value <= 0) || (value >= 0x98)) {
        return;
    }

    for (i = 0; i < D_8007839C[side]; i++) {
        if (D_800FCB38[side][i] == value) {
            goto found_value;
        }
    }

    D_800FCB38[side][D_8007839C[side]] = value;
    D_8007839C[side]++;
    if (D_8007839C[side] >= 8) {
        D_8007839C[side] = 7;
    }

    D_800FCB30[side] = 0;
    if (D_800783CC != 0) {
        func_80041C70(value + 0xCB);
        if (changed) {
            func_800420C0(D_80077FEC);
        }

        if (D_800FCB18[side ^ 1] == NULL) {
            return;
        }

        if (((f32)D_800FCB18[side ^ 1]->unk_26 - (f32)(D_800FCB18[side])->unk_26) > ((f32)(D_800FCB18[side])->unk_26 * 2.0f)) {
            D_800FCCB1 = 1;
            D_800FCCBA[side] = 0;
            return;
        }

        if (((f32)(D_800FCB18[side])->unk_26 * 0.3f) < ((f32)D_800FCB18[side ^ 1]->unk_26 - (f32)(D_800FCB18[side])->unk_26)) {
            D_800FCCB1 = 1;
            D_800FCCBA[side] = 0;
            return;
        }

        if (((f32)D_800FCB18[side ^ 1]->unk_26 * 0.3f) < ((f32)(D_800FCB18[side])->unk_26 - (f32)D_800FCB18[side ^ 1]->unk_26)) {
            D_800FCCB1 = 1;
            if ((D_800FCCD6[side] != 0) && (D_800FCCBA[side] != 0)) {
                if (changed == 0) {
                    func_800420C0(D_80078014);
                }
            } else if (changed == 0) {
                func_800420F0(9, D_80077FF4, &D_800FCCBA[side]);
            } else {
                D_800FCCBA[side]++;
            }

            D_800FCCB8[side] = 0;
            D_800FCCD6[side] = 0;
            return;
        }

        if ((D_80078390[side] == 2) && (D_80078390[side ^ 1] == 3)) {
            if ((((u32)D_800FCB18[side ^ 1]->unk_0C * 100) / D_800FCB18[side ^ 1]->unk_28) < 0x32) {
                if (D_800783E0 == 0) {
                    if (changed == 0) {
                        func_80041C70(0xA);
                    }
                    D_800783E0 = 1;
                }
            }
        }
    }
    D_800FCCB8[side] = 0;
    D_800FCCBA[side] = 0;
    return;

found_value:
    if (D_800FCB30[side] == 0) {
        if (D_800783DC == 0) {
            if (D_80078390[side] < 2) {
                if ((osGetTime() % 2) == 0) {
                    func_80041C70(2);
                } else {
                    func_80041C70(1);
                }
            } else {
                func_80041C70(0x50);
                if (changed != 0) {
                    func_800420C0(D_80077FEC);
                }
            }
            D_800783DC = 1;
        } else {
            func_80041C70(0x58);
            D_800783DC = 0;
            if (changed != 0) {
                func_800420C0(D_80077FEC);
            }
        }
    } else if (changed != 0) {
        func_800420C0(D_80077FEC);
    }

    D_800FCB30[side] = 0;

    if (D_800FCB18[side ^ 1] == NULL) {
        return;
    }

    if (changed != 0) {
        return;
    }

    if ((D_800FCB18[side])->unk_15 & 0x20) {
        func_800420C0(D_80077FFC);
        return;
    }

    if ((D_800FCB18[side])->unk_15 & 7) {
        func_800420C0(D_80078004);
        return;
    }

    if ((D_800FCB18[side])->unk_15 & 8) {
        func_80041C70(6);
        return;
    }

    if ((D_800FCB18[side])->unk_15 & 0x10) {
        func_80041C70(7);
        return;
    }

    if ((((f32)(D_800FCB18[side])->unk_0C / (f32)(D_800FCB18[side])->unk_28) < 0.2f) && ((D_800FCB18[side])->unk_0C < D_800FCB18[side ^ 1]->unk_0C)) {
        func_800420C0(D_8007800C);
    }
}

void func_8003F1AC(u32 arg0) {
    u8 sp1F;

    if (arg0 == 0 || arg0 >= 5) {
        return;
    }
    arg0--;
    sp1F = D_80078398[arg0];
    if (sp1F <= 0 || sp1F >= 3) {
        return;
    }
    sp1F--;
    D_8007838C[arg0]--;
    D_80078390[sp1F]--;
    D_800FCB30[sp1F] = 0;
    if (D_800FCB18[0] == 0 || D_800FCB18[1] == 0) {
        return;
    }
    func_800367A0(0x16, D_80078400, 0);
    if (D_800783D8 != 0) {
        func_80041C70(0xC3);
        D_800783D8 = 0;
        D_800783E4 = 1;
        return;
    }
    D_800783D8 = 1;
    if (D_800783D4 != 0) {
        func_80041C70(0xB9);
        D_800783D4 = 0;
        return;
    }
    if (D_800783CC < 2) {
        if (osGetTime() % 2 == 0) {
            func_80041C70(0xBC);
        } else {                
            func_80041C70(0xC5);
        }
    } else if (D_800783D0 != 0) {
        func_80041C70(0xC4);
        D_800783D0 = 0;
    } else if ((D_800FCCA4 >= 0x64U) && (D_800FCCB2 == 0) && (D_800783EC == 0)) {
        if (((f32)D_800FCB18[sp1F]->unk_26 * (3.0 / 10.0)) < ((f32)D_800FCB18[sp1F ^ 1]->unk_26 - D_800FCB18[sp1F]->unk_26)) {
            func_800420C0(D_80077FC0);
        } else {
            func_800420C0(D_80077FD0);
        }
        D_800FCCD6[sp1F] = 1;
    } else if ((D_800FCB48[sp1F].unk_78 >= 8U) && (D_800FCCB2 == 0)) {
        if (((u32) D_800FCCA4 < 5U) && (D_800783E8 == 0)) {
            func_80041C70(0xC2);
        } else {
            func_800420C0(D_80077FC8);
        }
    } else {
        func_800420C0(D_80077FB4);
    }
}

void func_8003F4C0(u32 arg0) {
    u8 temp_v0;
    
    if (arg0 == 0 || arg0 >= 5) {
        return;
    }
    
    arg0--;
    temp_v0 = D_80078398[arg0];

    if (temp_v0 <= 0 || temp_v0 >= 3) {
        return;
    }
    
    temp_v0--;

    if (D_800FCB18[0] == 0 || D_800FCB18[1] == 0) {
        return;
    }

    if (D_800FCB18[temp_v0]->unk_0C <= 0) {
       return; 
    }
    
    D_800FCB30[temp_v0] = 1;
    D_800FCCB5 = 1;
    
    if (D_800783DC != 0) {
        func_80041C70(0x58);
        D_800783DC = 0;
        return;
    }
    
    D_800783DC = 1;
    
    if (D_800783CC < 2) {
        if (osGetTime() % 2 == 0) {
            func_80041C70(0x54);
        } else {
            func_80041C70(0x55);
        }
    } else if (D_800FCB48[temp_v0].unk_78 < 2) {
        func_800420C0(D_80077FE4);
    } else {
        func_800420C0(D_80077FD8);
    }
}

void func_8003F624(u32 arg0) {
    D_800FCCF0[D_80078544] = arg0;
    D_80078544++;
    if (D_80078544 >= 0xA) {
        D_80078544--;
    }
}

#ifdef NON_MATCHING
void func_8003F660(s32 arg0) {
    u32 mask;
    u32 sp40;
    s32 sp3C;
    u8 temp_s0;
    u8 sp3A;
    u8 sp39;
    u8 sp38;
    u8 sp37;
    u8 sp36;
    u8 pad1;
    u8 sp34;
    u8 pad2;
    u8 sp32;


    sp3A = 0;
    sp39 = 0;
    sp38 = 0;
    sp37 = 0;
    sp36 = 0;
    sp34 = 0;
    sp32 = 0;
    mask = osSetIntMask(1);
    sp3C = D_800FCCA2;
    D_800FCCA2 = 0;
    osSetIntMask(mask);
    D_800783D0 = 0;
    D_800FCCB2 = 0;
    if (arg0 == 0 || arg0 >= 5U) {
        return;
    }
    arg0--;
    temp_s0 = D_80078398[arg0];
    if (temp_s0 <= 0 || temp_s0 >= 3) {
        return;
    }
    temp_s0--;
    if (D_800FCB18[0] == 0 || D_800FCB18[1] == 0) {
        return;
    }
    for (sp40 = 0; sp40 < D_80078544; sp40++) {
        switch (D_800FCCF0[sp40]) {
        case 0x1D:
            sp3A = 1;
            D_800783A0 = 1;
            break;
        case 0x1E:
            sp37 = 1;
            D_800783A0 = 1;
            break;
        case 0x29:
            sp39 = 1;
            D_800783A0 = 1;
            break;
        case 0x2A:
            sp38 = 1;
            D_800783A0 = 1;
            break;
        case 0x66:
            sp36 = 1;
            break;
        case 0x6F:
            sp34 = 1;
            break;
        case 0x6B:
        case 0x6C:
            D_800FCB48[temp_s0].unk_24++;
            ((u16*)D_800FCB48[temp_s0].unk_00)[D_800FCB48[temp_s0].unk_24 & 0xF] = D_800FCB18[temp_s0]->unk_0C;
            mask = osSetIntMask(1);
            D_800FCCA2 = (u8) sp3C;
            osSetIntMask(mask);
            break;
        case 0x6E:
        case 0x70:
        case 0x9E:
        case 0xAB:
            mask = osSetIntMask(1);
            D_800FCCA2 = (u8) sp3C;
            osSetIntMask(mask);
            break;
        case 0x0:
        case 0x1:
        case 0x2:
            D_800FCCB2 = 1;
            D_800783EC = 1;
            break;
        case 0x9D:
            D_800783D0 = 1;
            D_800FCCB2 = 1;
            break;
        case 0x6D:
            func_80041C70(0x165);
            D_80078544 = 0;
            D_800FCCBE[temp_s0] = 0;
            func_800367A0(0x16, D_80078400, 0);
            return;
        case 0x6:
            if (D_800FCB48[temp_s0].unk_7C == 1) {
                func_80041C70(0x19F);
            } else if (D_800FCB48[temp_s0].unk_7C >= 4U) {
                func_80041C70(0x164);
            } else {
                func_80041C70(0x163);
            }
            D_80078544 = 0;
            D_800FCB48[temp_s0].unk_7C = 0;
            D_800FCCBC[temp_s0] = 0;
            D_800FCCB4 = 0;
            func_800367A0(0x16, D_80078400, 0);
            return;
        case 0xB:
            func_80041C70(0x17B);
            D_80078544 = 0;
            return;
        case 0xC:
            func_80041C70(0x186);
            D_800FCCC4[temp_s0] = 0;
            D_80078544 = 0;
            return;
        case 0x11:
            func_80041C70(0x192);
            D_800FCCD4[temp_s0] = 0;
            D_80078544 = 0;
            return;
        case 0x5:
            if ((D_80078390[0] == 1) && (D_80078390[1] == 1)) {
                func_800420F0(0x17D, &D_80078040, &D_800FCCBC[temp_s0]);
            } else {
                func_800420F0(0x17D, &D_8007801C, &D_800FCCBC[temp_s0]);
            }
            D_80078544 = 0;
            return;
        case 0x7:
            if ((D_80078390[0] == 1) && (D_80078390[1] == 1)) {
                func_800420F0(0x17E, &D_80078038, &D_800FCCBE[temp_s0]);
            } else {
                func_800420F0(0x17E, &D_80078024, &D_800FCCBE[temp_s0]);
            }
            D_80078544 = 0;
            return;
        case 0x10:
            if ((D_80078390[0] == 1) && (D_80078390[1] == 1)) {
                func_800420F0(0x17F, &D_80078040, &D_800FCCC0[temp_s0]);
            } else {
                func_800420F0(0x17F, &D_80078030, &D_800FCCC0[temp_s0]);
            }
            D_80078544 = 0;
            return;
        case 0x8:
            if ((D_80078390[0] == 1) && (D_80078390[1] == 1)) {
                func_800420F0(0x17C, &D_80078040, &D_800FCCC2[temp_s0]);
            } else {
                func_800420F0(0x17C, &D_80078048, &D_800FCCC2[temp_s0]);
            }
            D_80078544 = 0;
            return;
        case 0x9:
        case 0xA:
            if ((D_80078390[0] == 1) && (D_80078390[1] == 1)) {
                func_80041C70(0x180);
            } else {
                func_80041C70(0x17C);
            }
            D_80078544 = 0;
            return;
        case 0x13:
            func_800420C0(&D_80078050);
            D_800FCCB6 = 1;
            D_80078544 = 0;
            return;
        case 0xF:
            func_80041C70(0x17A);
            D_80078544 = 0;
            return;
        case 0xE:
            D_800783D0 = 1;
            if (D_800FCCC4[temp_s0] != 0) {
                func_800420C0(&D_80078060);
            } else {
                func_800420C0(&D_80078058);
                D_800FCCC4[temp_s0] = 1;
            }
            D_80078544 = 0;
            func_800367A0(0x16, D_80078400, 0);
            return;
        case 0x12:
            if (((unk_D_800FCB48*)&D_800FCCCA[temp_s0])->unk_00[0] == 0) {
                func_80041C70(0x18C);
            } else {
                func_80041C70(0x18E);
            }
            ((unk_D_800FCB48*)&D_800FCCCA[temp_s0])->unk_00[0] ^= 1;
            D_80078544 = 0;
            func_800367A0(0x16, D_80078400, 0);
            return;
        case 0x71:
        case 0x77:
            func_800420F0(0x16A, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0x72:
        case 0x78:
            func_800420F0(0x16B, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0x73:
        case 0x79:
            func_800420F0(0x16C, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0x74:
        case 0x7A:
            func_800420F0(0x16D, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0x75:
        case 0x7B:
            func_800420F0(0x16E, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0x76:
        case 0x7C:
            func_800420F0(0x16F, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0xB5:
            func_800420F0(0x170, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0xB7:
            func_800420F0(0x171, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0x9A:
            func_800420F0(0x169, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0x9C:
            func_800420F0(0x194, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0xAE:
            func_80041C70(0x1A0);
            D_80078544 = 0;
            return;
        case 0x7E:
        case 0x84:
            if (D_800FCCC8[temp_s0] < 3) {
                func_800420F0(0xA2, &D_80078070, &D_800FCCC8[temp_s0]);
            } else {
                func_800420C0(&D_80078078);
            }
            D_80078544 = 0;
            return;
        case 0x7F:
        case 0x85:
            if (D_800FCCC8[temp_s0] < 3) {
                func_800420F0(0xA3, &D_80078070, &D_800FCCC8[temp_s0]);
            } else {
                func_800420C0(&D_80078078);
            }
            D_80078544 = 0;
            return;
        case 0x80:
        case 0x86:
            if (D_800FCCC8[temp_s0] < 3) {
                func_800420F0(0xA7, &D_80078070, &D_800FCCC8[temp_s0]);
            } else {
                func_800420C0(&D_80078078);
            }
            D_80078544 = 0;
            return;
        case 0x81:
        case 0x87:
            if (D_800FCCC8[temp_s0] < 3) {
                func_800420F0(0xA4, &D_80078070, &D_800FCCC8[temp_s0]);
            } else {
                func_800420C0(&D_80078078);
            }
            D_80078544 = 0;
            return;
        case 0x82:
        case 0x88:
            if (D_800FCCC8[temp_s0] < 3) {
                func_800420F0(0xA5, &D_80078070, &D_800FCCC8[temp_s0]);
            } else {
                func_800420C0(&D_80078078);
            }
            D_80078544 = 0;
            return;
        case 0x83:
        case 0x89:
            if (D_800FCCC8[temp_s0] < 3) {
                func_800420F0(0xA6, &D_80078070, &D_800FCCC8[temp_s0]);
            } else {
                func_800420C0(&D_80078078);
            }
            D_80078544 = 0;
            return;
        case 0x19:
        case 0x1B:
            if ((D_800780B3[D_800FCCAC * 3] == 0) && ((D_800FCB18[temp_s0]->unk_16[6] == 8) || (D_800FCB18[temp_s0]->unk_16[7] == 8))) {
                func_800420C0(&D_80077F24);
            } else {
                func_800420C0(&D_80077F14);
            }
            D_80078544 = 0;
            return;
        case 0x1A:
        case 0x1C:
            if (D_800FCCD2[temp_s0 ^ 1] != 0) {
                func_800420C0(&D_80077F50);
            } else {
                if ((D_800783D4 != 0) || ((D_80078390[temp_s0 ^ 1] == 1) && ((s32)D_800FCB18[temp_s0 ^ 1]->unk_0C < 0x13))) {
                    func_800420C0(&D_80077F1C);
                    func_800367A0(0x16, D_80078400, 0);
                } else {
                    func_800420C0(&D_80077F0C);
                }
                D_800FCCD2[temp_s0 ^ 1] = 1;
            }
            D_80078544 = 0;
            return;
        case 0xA7:
            func_800420C0(&D_80077F0C);
            D_80078544 = 0;
            return;
        case 0x20:
        case 0x7D:
        case 0x8C:
        case 0x99:
        case 0x9B:
        case 0xA5:
        case 0xAD:
        case 0xB2:
        case 0xB4:
        case 0xB6:
        case 0xB8:
        case 0xB9:
        case 0xBA:
        case 0xBC:
            func_800420C0(&D_80078088);
            D_80078544 = 0;
            return;
        case 0x64:
        case 0x65:
        case 0x67:
        case 0x6A:
        case 0x8A:
        case 0x8B:
        case 0x8D:
        case 0x91:
        case 0x92:
        case 0xA0:
        case 0xA2:
        case 0xA3:
        case 0xAA:
            func_800420C0(&D_80078090);
            D_80078544 = 0;
            return;
        case 0x1F:
            func_80041C70(0x18D);
            D_80078544 = 0;
            return;
        case 0x93:
        case 0x94:
        case 0x95:
        case 0x96:
            func_80041C70(0x18F);
            D_80078544 = 0;
            return;
        case 0x97:
            func_800420F0(0x18A, &D_80078098, &D_800FCCCE[temp_s0]);
            D_80078544 = 0;
            func_800367A0(0x16, D_80078400, 0);
            return;
        case 0x98:
            func_800420F0(0x18B, &D_800780A0, &D_800FCCD0[temp_s0]);
            D_80078544 = 0;
            func_800367A0(0x16, D_80078400, 0);
            return;
        case 0x2B:
            func_80041C70(0x76);
            D_80078544 = 0;
            return;
        case 0x2C:
            func_800420C0(&D_80078080);
            D_80078544 = 0;
            return;
        case 0xBB:
            func_80041C70(0x189);
            D_80078544 = 0;
            func_800367A0(0x16, D_80078400, 0);
            D_800783D0 = 1;
            return;
        case 0x68:
            func_800420C0(&D_80077F34);
            D_80078544 = 0;
            return;
        case 0x69:
            func_800420C0(&D_80077F3C);
            D_80078544 = 0;
            return;
        case 0xA1:
            func_80041C70(0x7A);
            D_80078544 = 0;
            return;
        case 0xA6:
            func_800420C0(&D_80077F2C);
            D_80078544 = 0;
            return;
        case 0xAF:
        case 0xB0:
            func_80041C70(0x167);
            D_800FCB48[temp_s0].unk_24++;
            ((u16*)D_800FCB48[temp_s0].unk_00)[D_800FCB48[temp_s0].unk_24 & 0xF] = ((unk_D_800FCB18*)D_800FCB18[temp_s0])->unk_0C;
            D_80078544 = 0;
            return;
        case 0xB1:
            func_80041C70(0x166);
            D_800FCB48[temp_s0].unk_24++;
            ((u16*)D_800FCB48[temp_s0].unk_00)[D_800FCB48[temp_s0].unk_24 & 0xF] = ((unk_D_800FCB18*)D_800FCB18[temp_s0])->unk_0C;
            D_80078544 = 0;
            return;
        case 0xB3:
            func_80041C70(0x188);
            D_80078544 = 0;
            func_800367A0(0x16, D_80078400, 0);
            return;
        case 0xA8:
            func_80041C70(0x197);
            D_80078544 = 0;
            return;
        case 0xA9:
            func_80041C70(0x193);
            D_80078544 = 0;
            return;
        case 0xA4:
            func_80041C70(0x195);
            D_80078544 = 0;
            return;
        case 0xAC:
            func_80041C70(0x196);
            D_80078544 = 0;
            return;
        case 0x9F:
            func_80041C70(0x87);
            D_80078544 = 0;
            return;
        case 0x4:
            sp32 = 1;
            break;
        default: 
            break;
        }
    }
    D_80078544 = 0;
    
    if (sp34 != 0) {
        mask = osSetIntMask(1);
        D_800FCCA2 = 0;
        osSetIntMask(mask);
        func_80041C70(0x79);
        D_800FCCB3 = 1;
        func_800367A0(0x16, D_80078400, 0);
    } else if (sp36 != 0) {
        mask = osSetIntMask(1);
        D_800FCCA2 = 0;
        osSetIntMask(mask);
        if (D_800FCCCC[temp_s0] != 0) {
            func_80041C70(0xAD);
        } else {
            func_80041C70(0x78);
        }
        D_800FCB48[temp_s0].unk_7C = 1;
        D_800FCCCC[temp_s0] = 1;
        D_800FCCB4 = 1;
        func_800367A0(0x16, D_80078400, 0);
    } else if (sp37 != 0) {
        mask = osSetIntMask(1);
        D_800FCCA2 = 0;
        osSetIntMask(mask);
        D_800783E8 = 1;
        func_80041C70(0x77);
        func_800367A0(0x16, D_80078400, 0);
    } else if (sp3A != 0) {
        mask = osSetIntMask(1);
        D_800FCCA2 = 0;
        osSetIntMask(mask);
        D_800783E8 = 1;
        if (sp39 != 0) {
            if ((u32) D_800FCCA4 < 0xAU) {
                if ((D_800FCB18[temp_s0]->unk_0C > 0) && ((s32)D_800FCB18[temp_s0 ^ 1]->unk_0C >= 0xB)) {
                    func_800420C0(&D_80077EF0);
                } else {
                    func_800420C0(&D_80077F04);
                }
            } else if ((u32) D_800783CC < 2U) {
                func_80041C70(0x68);
                func_800367A0(0x16, D_80078400, 0);
            } else {
                if ((D_800FCB48[temp_s0 ^ 1].unk_78 < 2U) && (D_80078390[temp_s0 ^ 1] >= 2)) {
                    func_800420C0(&D_80077F58);
                } else {
                    func_800420C0(&D_80077EE4);
                }
                func_800367A0(0x16, D_80078400, 0);
            }
        } else if ((u32) D_800FCCA4 < 0xAU) {
            if (((s32)D_800FCB18[temp_s0]->unk_0C > 0) && ((s32)D_800FCB18[temp_s0 ^ 1]->unk_0C >= 0xB)) {
                func_800420C0(&D_80077EF0);
            } else {
                func_800420C0(&D_80077F04);
            }
        } else {
            func_800420C0(&D_80077EC0);
            func_800367A0(0x16, D_80078400, 0);
        }
    } else if (sp39 != 0) {
        mask = osSetIntMask(1);
        D_800FCCA2 = 0;
        osSetIntMask(mask);
        D_800783E8 = 1;
        if ((D_800FCB48[temp_s0 ^ 1].unk_78 < 2U) && (D_80078390[temp_s0 ^ 1] >= 2)) {
            func_800420C0(&D_80077F58);
        } else {
            func_800420C0(&D_80077ECC);
        }
        func_800367A0(0x16, D_80078400, 0);
    } else if (sp38 != 0) {
        mask = osSetIntMask(1);
        D_800FCCA2 = 0;
        osSetIntMask(mask);
        if ((u32) D_800FCCA4 >= 0x29U) {
            func_800420C0(&D_80077EF8);
            func_800367A0(0x16, D_80078400, 0);
        } else if ((D_800FCB18[0]->unk_0C > 0) && (D_800FCB18[1]->unk_0C > 0)) {
            func_800420C0(&D_80077ED8);
        } else {
            func_800420C0(&D_80077F04);
            func_800367A0(0x16, D_80078400, 0);
        }
    } else if ((sp32 != 0) && (D_800FCCA4 != 0)) {
        if (D_800FCCA4 >= 0x29) {
            func_800420C0(&D_80077E98);
            func_800367A0(0x16, D_80078400, 0);
        }else if (D_800FCCA4 >= 6) {
            if (( D_800FCB18[0]->unk_0C > 0) && ((s32) D_800FCB18[1]->unk_0C > 0)) {
                func_800420C0(&D_80077EA4);
            } else {
                func_800420C0(&D_80077F60);
            }
        }else if (((s32) D_800FCB18[0]->unk_0C > 0) && ((s32) D_800FCB18[1]->unk_0C > 0)) {
            func_800420C0(&D_80077EB4);
        } else {
            func_800420C0(&D_80077F04);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140_2/func_8003F660.s")
#endif

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
                    // FAKE
                    if (arg2) {}
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

void func_800414B8(s32 arg0) {
    u8 temp_v0;

    if (arg0 == 0 || arg0 >= 5U) {
        return;
    }
    arg0--;
    temp_v0 = D_80078398[arg0];
    if (temp_v0 <= 0 || temp_v0 >= 3) {
        return;
    }
    temp_v0--;
    if (D_800FCCD4[temp_v0] == 0) {
        func_80041C70(0x190);
        D_800FCCD4[temp_v0] = 1;
    } else {
        func_80041C70(0x191);   
    }
}

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
    *(volatile u8*)&D_800FCCA1 = 0;
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
    for (i = 0; i < 0x15; i++) {
        D_800FCCD8[i] = 0;
    }
    for (i = 0; i < 20; i++) {
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
#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140_2/func_80041A98.s")
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
        func_80041D50(D_800FCD18, D_800FCD18 + (osGetTime() % (s32)temp_v0));
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

#ifdef NON_MATCHING
u32 func_80042158(u32 arg0, unk_D_800FCB18* arg1, unk_D_800FCB18* arg2) {
    s32 side;
    u8* entry;
    u8 type;
    u8 power;
    u8 conv0;
    u8 conv1;
    f32 f0;
    f32 f2;
    f32 f12;
    f32 f14;
    f32 sp50;

    if ((arg0 == 0) || (arg0 >= 0xA6)) {
        arg0 = 1;
    }

    if (arg1 == D_800FCB18[0]) {
        side = 0;
    } else if (arg1 == D_800FCB18[1]) {
        side = 1;
    } else {
        return 0;
    }

    entry = &D_800780B4[(arg0 * 3) - 3];
    conv0 = func_80042850(entry[2]);

    type = entry[0];
    power = entry[1];

    switch (type) {
        case 7:
            return (u32)-1;

        case 8:
            return arg2->unk_28 / 2;

        case 0xD:
            switch (arg0) {
                case 0x31:
                    return 0x14;
                case 0x45:
                    return arg1->unk_26;
                case 0x52:
                    return 0x28;
                case 0x65:
                    return arg1->unk_26;
                case 0x95:
                    return (u32)((f32)arg1->unk_26 * 1.5f);
                default:
                    return 0;
            }

        case 0x22:
            if (entry == D_800781E0) {
                return (u32)-5;
            }
            return (u32)-4;
    }

    if (entry == D_80078180) {
        return (u32)-2;
    }

    if (arg1->unk_2A != 0) {
        f2 = arg1->unk_2A;
    } else {
        f2 = 1.0f;
    }

    if (arg2->unk_2C != 0) {
        f0 = arg2->unk_2C;
    } else {
        f0 = 1.0f;
    }

    sp50 = ((((f32)(((arg1->unk_26 * 2) / 5) + 2) * (f32)power) * f2) / f0);

    conv1 = func_80042850(arg2->unk_16[6]);
    {
        u8 conv2;
        u8 mode;

        conv2 = func_80042850(arg2->unk_16[7]);

        mode = D_800782A4[(conv1 * 0xF) + conv2];
        if (mode == 1) {
            f12 = 0.0f;
        } else if (mode == 2) {
            f12 = 0.5f;
        } else if (mode == 3) {
            f12 = 2.0f;
        } else {
            f12 = 1.0f;
        }

        mode = D_800782A4[(conv1 * 0xF) + conv0];
        if (mode == 1) {
            f2 = 0.0f;
        } else if (mode == 2) {
            f2 = 0.5f;
        } else if (mode == 3) {
            f2 = 2.0f;
        } else {
            f2 = 1.0f;
        }
    }

    if ((arg1->unk_16[6] == entry[2]) || (arg1->unk_16[7] == entry[2])) {
        f0 = 1.5f;
    } else {
        f0 = 1.0f;
    }

    {
        unk_D_800FCB48* hist;
        f32 prev;
        f32 cur;
        f32 mulA;
        f32 mulB;
        u8 flags;
        u32 ret;

        hist = &D_800FCB48[side ^ 1];
        prev = hist->unk_00[hist->unk_24 & 0xF];
        if (prev == 0.0f) {
            prev = 1.0f;
        }
        cur = arg2->unk_28;

        if (D_80078390[side] == 1) {
            mulA = D_8007CB80;
        } else {
            mulA = 1.0f;
        }

        hist = &D_800FCB48[side];
        f14 = hist->unk_00[hist->unk_24 & 0xF];
        if (f14 == 0.0f) {
            f14 = 1.0f;
        }
        f12 = arg1->unk_28;

        if (D_80078390[side ^ 1] == 1) {
            mulB = D_8007CB84;
        } else {
            mulB = 1.0f;
        }

        flags = arg2->unk_15;
        if (flags & 0x20) {
            f14 = D_8007CB88;
        } else if (flags & 7) {
            f14 = D_8007CB8C;
        } else {
            f14 = 1.0f;
        }

        ret = (u32)(((((cur / prev) * D_8007CB90) + 1.0f) * sp50 * f2 * f0) *
                    ((((f12 / hist->unk_00[D_800FCB48[side].unk_24 & 0xF]) * D_8007CB90) + 1.0f)) *
                    mulA * mulB * f14);

        if (ret >= 0x8000) {
            return 0x7FFF;
        }
        return ret;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140_2/func_80042158.s")
#endif

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

void func_800428FC(u32 arg0) {
    func_80041C70(arg0);
}
