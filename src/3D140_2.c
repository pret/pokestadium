#include "3D140.h"
#include "lib/ultralib/include/PR/leo.h"
#include "src/audio_commands.h"
#include "src/libnumus/player.h"
#include "src/3D140.h"
#include "src/gb_audio.h"
#include "src/libnaudio/n_libaudio_sc.h"
#include "src/libnaudio/n_libaudio_sn_sc.h"
#include "src/audio_stream.h"
#include "src/gb_audio_render.h"
#include "src/audio_loop_point.h"

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
    /* 0x7C */ u32 unk_7C;
    /* 0x80 */ s32 unk_80;
} unk_D_800FCB48; // size = 0x84

typedef struct unk_D_80078548 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
} unk_D_80078548;

// .data
// global

extern u8 D_800780B3[]; // needs addressing
extern u16 D_80078410[1][9];
extern u16 D_80078446[1][9];
extern u16 D_800784EA[1][9];

// .rodata

// const f32 D_8007CB80 = 1.100000024f;
// const f32 D_8007CB84 = 1.100000024f;
// const f32 D_8007CB88 = 1.200000048f;
// const f32 D_8007CB8C = 1.100000024f;
// const f32 D_8007CB90 = 0.009999999776f;


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
extern BattleMonRuntime* D_800FCB18[4];
extern u32 D_800FCB28[2];
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
extern u8 D_800FCCC4[2];
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
void Audio_QueueSoundWithFallbackList(u16, u16*, u8*);
u32 Battle_EstimateMoveDamage(u32, BattleMonRuntime*, BattleMonRuntime*);
s32 Battle_MapCategoryIdToCompactIndex(u8);
ALDMAproc __amDmaNew(AMDMAState** state);

u16 D_80077DF0[8] = {
    0x0007, 0x024F, 0x0250, 0x0255, 0x0271, 0x0273, 0x0289, 0x028F,
};
u16 D_80077E00[8] = {
    0x0006, 0x0269, 0x026C, 0x026D, 0x026E, 0x0287, 0x0288, 0x0000,
};
u16 D_80077E10[4] = {
    0x0003, 0x0281, 0x0282, 0x0283,
};
u16 D_80077E18[4] = {
    0x0003, 0x027E, 0x027F, 0x0280,
};
u16 D_80077E20[4] = {
    0x0003, 0x024D, 0x0278, 0x0279,
};
u16 D_80077E28[4] = {
    0x0003, 0x024C, 0x0274, 0x0275,
};
u16 D_80077E30[4] = {
    0x0003, 0x024B, 0x0276, 0x0277,
};
u16 D_80077E38[4] = {
    0x0002, 0x027C, 0x027D, 0x0000,
};
u16 D_80077E40[4] = {
    0x0002, 0x027A, 0x027B, 0x0000,
};
u16 D_80077E48[4] = {
    0x0003, 0x0252, 0x0270, 0x0272,
};
u16 D_80077E50[4] = {
    0x0003, 0x0284, 0x0285, 0x0286,
};
u16 D_80077E58[4] = {
    0x0003, 0x0259, 0x028B, 0x028C,
};
u16 D_80077E60[4] = {
    0x0003, 0x025A, 0x028A, 0x028C,
};
u16 D_80077E68[4] = {
    0x0003, 0x024E, 0x0258, 0x028E,
};
u16 D_80077E70[4] = {
    0x0002, 0x0251, 0x028D, 0x0000,
};
u16 D_80077E78[8] = {
    0x0006, 0x024F, 0x0250, 0x0255, 0x0271, 0x0289, 0x028F, 0x0000,
};
u16 D_80077E88[4] = {
    0x0003, 0x0253, 0x026F, 0x0291,
};
u16 D_80077E90[4] = {
    0x0002, 0x0252, 0x0270, 0x0000,
};
u16 D_80077E98[6] = {
    0x0005, 0x0062, 0x0067, 0x006E, 0x008D, 0x008E,
};
u16 D_80077EA4[8] = {
    0x0006, 0x006D, 0x0072, 0x0089, 0x008A, 0x008B, 0x008C, 0x0000,
};
u16 D_80077EB4[6] = {
    0x0005, 0x006F, 0x0070, 0x009F, 0x00A0, 0x00A1,
};
u16 D_80077EC0[6] = {
    0x0005, 0x0060, 0x0065, 0x0092, 0x0093, 0x0094,
};
u16 D_80077ECC[6] = {
    0x0005, 0x0061, 0x0066, 0x0095, 0x0096, 0x0097,
};
u16 D_80077ED8[6] = {
    0x0004, 0x0069, 0x0098, 0x0099, 0x009A, 0x0000,
};
u16 D_80077EE4[6] = {
    0x0005, 0x0063, 0x0064, 0x008F, 0x0090, 0x0091,
};
u16 D_80077EF0[4] = {
    0x0003, 0x006A, 0x009B, 0x009C,
};
u16 D_80077EF8[6] = {
    0x0004, 0x006B, 0x006C, 0x009D, 0x009E, 0x0000,
};
u16 D_80077F04[4] = {
    0x0002, 0x008A, 0x008B, 0x0000,
};
u16 D_80077F0C[4] = {
    0x0003, 0x007C, 0x0086, 0x00AC,
};
u16 D_80077F14[4] = {
    0x0002, 0x007E, 0x007F, 0x0000,
};
u16 D_80077F1C[4] = {
    0x0002, 0x00AE, 0x00AF, 0x0000,
};
u16 D_80077F24[4] = {
    0x0002, 0x0082, 0x0083, 0x0000,
};
u16 D_80077F2C[4] = {
    0x0002, 0x0072, 0x008A, 0x0000,
};
u16 D_80077F34[4] = {
    0x0002, 0x0085, 0x0084, 0x0000,
};
u16 D_80077F3C[4] = {
    0x0002, 0x0088, 0x0071, 0x0000,
};
u16 D_80077F44[6] = {
    0x0005, 0x0062, 0x0067, 0x006E, 0x008D, 0x008E,
};
u16 D_80077F50[4] = {
    0x0002, 0x0080, 0x0081, 0x0000,
};
u16 D_80077F58[4] = {
    0x0002, 0x00B3, 0x00B4, 0x0000,
};
u16 D_80077F60[6] = {
    0x0005, 0x0072, 0x0089, 0x008A, 0x008B, 0x008C,
};
u16 D_80077F6C[4] = {
    0x0003, 0x001D, 0x001E, 0x001F,
};
u16 D_80077F74[4] = {
    0x0003, 0x0020, 0x0021, 0x0022,
};
u16 D_80077F7C[6] = {
    0x0004, 0x0019, 0x001A, 0x001B, 0x001C, 0x0000,
};
u16 D_80077F88[4] = {
    0x0002, 0x001A, 0x001B, 0x0000,
};
u16 D_80077F90[4] = {
    0x0003, 0x0018, 0x001B, 0x001C,
};
u16 D_80077F98[6] = {
    0x0004, 0x0014, 0x0015, 0x0016, 0x0017, 0x0000,
};
u16 D_80077FA4[4] = {
    0x0002, 0x0010, 0x0011, 0x0000,
};
u16 D_80077FAC[4] = {
    0x0002, 0x0012, 0x0013, 0x0000,
};
u16 D_80077FB4[6] = {
    0x0004, 0x00B7, 0x00B8, 0x00B9, 0x00BA, 0x0000,
};
u16 D_80077FC0[4] = {
    0x0003, 0x00BD, 0x00BE, 0x00BF,
};
u16 D_80077FC8[4] = {
    0x0002, 0x00C0, 0x00C1, 0x0000,
};
u16 D_80077FD0[4] = {
    0x0003, 0x00BB, 0x00C6, 0x00C7,
};
u16 D_80077FD8[6] = {
    0x0004, 0x0050, 0x0051, 0x0052, 0x0053, 0x0000,
};
u16 D_80077FE4[4] = {
    0x0002, 0x0056, 0x0057, 0x0000,
};
u16 D_80077FEC[4] = {
    0x0002, 0x0059, 0x005A, 0x0000,
};
u16 D_80077FF4[4] = {
    0x0002, 0x000B, 0x000C, 0x0000,
};
u16 D_80077FFC[4] = {
    0x0002, 0x0004, 0x0003, 0x0000,
};
u16 D_80078004[4] = {
    0x0002, 0x0005, 0x0003, 0x0000,
};
u16 D_8007800C[4] = {
    0x0002, 0x0008, 0x000D, 0x0000,
};
u16 D_80078014[4] = {
    0x0002, 0x000E, 0x000F, 0x0000,
};
u8 D_8007801C[8] = {
    0x00, 0x03, 0x01, 0x81, 0x01, 0x9D, 0x01, 0x9E,
};
u8 D_80078024[12] = {
    0x00, 0x04, 0x01, 0x7C, 0x01, 0x82, 0x01, 0x9D, 0x01, 0x9E, 0x00, 0x00,
};
u8 D_80078030[8] = {
    0x00, 0x02, 0x01, 0x7C, 0x01, 0x9E, 0x00, 0x00,
};
u8 D_80078038[8] = {
    0x00, 0x02, 0x01, 0x80, 0x01, 0x98, 0x00, 0x00,
};
u16 D_80078040[4] = {
    0x0002, 0x0180, 0x017C, 0x0000,
};
u16 D_80078048[4] = {
    0x0003, 0x0179, 0x019D, 0x019E,
};
u16 D_80078050[4] = {
    0x0002, 0x0177, 0x0178, 0x0000,
};
u16 D_80078058[4] = {
    0x0002, 0x0183, 0x0184, 0x0000,
};
u16 D_80078060[4] = {
    0x0002, 0x0184, 0x0185, 0x0000,
};
u16 D_80078068[4] = {
    0x0003, 0x0172, 0x0173, 0x0174,
};
u8 D_80078070[8] = {
    0x00, 0x03, 0x00, 0x71, 0x00, 0xA8, 0x00, 0xA9,
};
u16 D_80078078[4] = {
    0x0002, 0x0073, 0x0074, 0x0000,
};
u16 D_80078080[4] = {
    0x0002, 0x0175, 0x0176, 0x0000,
};
u16 D_80078088[4] = {
    0x0002, 0x007D, 0x00AA, 0x0000,
};
u16 D_80078090[4] = {
    0x0003, 0x007D, 0x00AA, 0x00AB,
};
u16 D_80078098[4] = {
    0x0002, 0x0199, 0x019A, 0x0000,
};
u16 D_800780A0[4] = {
    0x0002, 0x019B, 0x019C, 0x0000,
};
u16 D_800780A8[6] = {
    0x0005, 0x005B, 0x005C, 0x005D, 0x005E, 0x005F,
};
u8 D_800780B4[204] = {
    0x00, 0x28, 0x00, 0x00, 0x32, 0x00, 0x1D, 0x0F, 0x00, 0x1D, 0x12, 0x00, 0x00, 0x50, 0x00, 0x10,
    0x28, 0x00, 0x04, 0x4B, 0x14, 0x05, 0x4B, 0x19, 0x06, 0x4B, 0x17, 0x00, 0x28, 0x00, 0x00, 0x37,
    0x00, 0x26, 0x01, 0x00, 0x27, 0x50, 0x00, 0x32, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x28, 0x00,
    0x00, 0x23, 0x02, 0x1C, 0x00, 0x00, 0x2B, 0x46, 0x02, 0x2A, 0x0F, 0x00, 0x00, 0x50, 0x00, 0x00,
    0x23, 0x16, 0x25, 0x41, 0x00, 0x2C, 0x1E, 0x01, 0x00, 0x78, 0x00, 0x2D, 0x46, 0x01, 0x25, 0x3C,
    0x01, 0x16, 0x00, 0x00, 0x25, 0x46, 0x00, 0x00, 0x41, 0x00, 0x1D, 0x0F, 0x00, 0x26, 0x01, 0x00,
    0x00, 0x23, 0x00, 0x24, 0x55, 0x00, 0x2A, 0x0F, 0x00, 0x30, 0x5A, 0x00, 0x1B, 0x5A, 0x00, 0x30,
    0x64, 0x00, 0x13, 0x00, 0x00, 0x02, 0x0F, 0x03, 0x4D, 0x19, 0x07, 0x1D, 0x0E, 0x07, 0x13, 0x00,
    0x00, 0x1F, 0x3C, 0x00, 0x12, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x20, 0x00, 0x00, 0x31, 0x00, 0x00,
    0x29, 0x01, 0x00, 0x56, 0x00, 0x00, 0x45, 0x28, 0x03, 0x04, 0x28, 0x14, 0x04, 0x5F, 0x14, 0x2E,
    0x00, 0x19, 0x00, 0x28, 0x15, 0x00, 0x78, 0x15, 0x00, 0x5F, 0x15, 0x05, 0x5F, 0x19, 0x23, 0x78,
    0x19, 0x4C, 0x41, 0x18, 0x46, 0x41, 0x15, 0x44, 0x41, 0x19, 0x50, 0x96, 0x00, 0x00, 0x23, 0x02,
    0x00, 0x50, 0x02, 0x30, 0x50, 0x01, 0x25, 0x32, 0x01, 0x00, 0x01, 0x01,
};
u8 D_80078180[96] = {
    0x29, 0x01, 0x01, 0x00, 0x50, 0x00, 0x03, 0x14, 0x16, 0x03, 0x28, 0x16, 0x54, 0x00, 0x16, 0x0D,
    0x00, 0x00, 0x00, 0x37, 0x16, 0x27, 0x78, 0x16, 0x42, 0x00, 0x03, 0x43, 0x00, 0x16, 0x20, 0x00,
    0x16, 0x1B, 0x46, 0x16, 0x14, 0x00, 0x07, 0x29, 0x01, 0x1A, 0x2A, 0x0F, 0x14, 0x06, 0x28, 0x17,
    0x06, 0x5F, 0x17, 0x43, 0x00, 0x17, 0x06, 0x78, 0x17, 0x00, 0x32, 0x05, 0x00, 0x64, 0x04, 0x26,
    0x01, 0x04, 0x27, 0x64, 0x04, 0x42, 0x00, 0x03, 0x4C, 0x32, 0x18, 0x47, 0x5A, 0x18, 0x20, 0x00,
    0x18, 0x0A, 0x00, 0x18, 0x34, 0x00, 0x18, 0x00, 0x28, 0x00, 0x51, 0x14, 0x00, 0x1C, 0x00, 0x18,
};
u8 D_800781E0[196] = {
    0x29, 0x00, 0x08, 0x52, 0x00, 0x00, 0x3B, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x38, 0x00, 0x00, 0x0B,
    0x00, 0x00, 0x0F, 0x00, 0x00, 0x16, 0x00, 0x00, 0x31, 0x00, 0x08, 0x0B, 0x00, 0x15, 0x0B, 0x00,
    0x00, 0x33, 0x00, 0x18, 0x40, 0x00, 0x18, 0x19, 0x00, 0x19, 0x41, 0x00, 0x18, 0x2F, 0x00, 0x00,
    0x1A, 0x00, 0x00, 0x53, 0x00, 0x00, 0x09, 0x00, 0x02, 0x07, 0x82, 0x00, 0x00, 0x64, 0x00, 0x24,
    0x14, 0x08, 0x21, 0x14, 0x03, 0x21, 0x41, 0x03, 0x1F, 0x41, 0x04, 0x22, 0x78, 0x14, 0x00, 0x50,
    0x15, 0x2A, 0x23, 0x15, 0x11, 0x3C, 0x00, 0x27, 0x64, 0x00, 0x1D, 0x14, 0x00, 0x46, 0x0A, 0x00,
    0x35, 0x00, 0x18, 0x16, 0x00, 0x18, 0x38, 0x00, 0x00, 0x2D, 0x55, 0x01, 0x43, 0x00, 0x00, 0x08,
    0x64, 0x18, 0x42, 0x00, 0x03, 0x1D, 0x0F, 0x00, 0x03, 0x14, 0x07, 0x20, 0x00, 0x00, 0x27, 0x8C,
    0x02, 0x39, 0x00, 0x00, 0x46, 0x14, 0x15, 0x00, 0x46, 0x00, 0x20, 0x00, 0x16, 0x16, 0x00, 0x00,
    0x29, 0x01, 0x18, 0x55, 0x00, 0x00, 0x33, 0x00, 0x03, 0x00, 0x5A, 0x15, 0x07, 0xAA, 0x00, 0x1D,
    0x12, 0x00, 0x2C, 0x32, 0x04, 0x38, 0x00, 0x18, 0x00, 0x4B, 0x05, 0x1F, 0x50, 0x00, 0x0A, 0x00,
    0x00, 0x18, 0x00, 0x00, 0x00, 0x50, 0x00, 0x28, 0x01, 0x00, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x00,
    0x30, 0x32, 0x00, 0x00,
};
u8 D_800782A4[228] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x00,
    0x02, 0x02, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x00, 0x02, 0x00, 0x03,
    0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00, 0x03,
    0x02, 0x02, 0x00, 0x00, 0x00, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x03, 0x00,
    0x02, 0x00, 0x00, 0x02, 0x03, 0x02, 0x00, 0x02, 0x03, 0x00, 0x02, 0x00, 0x02, 0x02, 0x00, 0x03,
    0x02, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x03, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x00, 0x02, 0x00, 0x02, 0x02, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
    0x02, 0x02, 0x00, 0x00, 0x03, 0x02, 0x02, 0x00, 0x00, 0x03, 0x00, 0x03, 0x02, 0x00, 0x00, 0x03,
    0x00, 0x01, 0x00, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x00, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00, 0x02, 0x03,
    0x00, 0x00, 0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x02, 0x00, 0x02, 0x03, 0x00, 0x03,
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00,
};
s32 D_80078388 = 0x00000001;
u8 D_8007838C[4] = {
    0x03, 0x03, 0x03, 0x03,
};
u8 D_80078390[4] = {
    0x03, 0x03, 0x00, 0x00,
};
u8 D_80078394[4] = {
    0x00, 0x01, 0x00, 0x00,
};
u8 D_80078398[4] = {
    0x01, 0x02, 0x01, 0x02,
};
u8 D_8007839C[4] = {
    0x00, 0x00, 0x00, 0x00,
};
u8 D_800783A0 = 0x00;
u32 D_800783A4[4] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
u32 D_800783B4 = 0x00000000;
s32 D_800783B8 = 0x00000000;
u8 D_800783BC = 0x00;
u8 D_800783C0 = 0x00;
u8 D_800783C4 = 0x00;
u32 D_800783C8 = 0x00000000;
u32 D_800783CC = 0x00000000;
u8 D_800783D0 = 0x00;
u8 D_800783D4 = 0x00;
u8 D_800783D8 = 0x00;
u8 D_800783DC = 0x00;
u8 D_800783E0 = 0x00;
u8 D_800783E4 = 0x00;
u8 D_800783E8 = 0x00;
u8 D_800783EC = 0x00;
s16 D_800783F0 = 0x0000;
s16 D_800783F4 = 0x0000;
s16 D_800783F8 = 0x0000;
u8 D_800783FC = 0x01;
u8 D_80078400 = 0x01;
u32 D_80078404 = 0x00000000;
s32 D_80078408 = 0x00000000;
u8 D_8007840C = 0x00;
// 0x80078410 / 0x80078446 / 0x800784EA are interior aliases (undefined_syms.ld).
u8 sMusicSeqTables[0x134] = {
    0x00, 0x35, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29,
    0x00, 0x2A, 0x00, 0x35, 0x00, 0x2B, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28,
    0x00, 0x29, 0x00, 0x2A, 0x00, 0x35, 0x00, 0x2C, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27,
    0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x35, 0x00, 0x2D, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26,
    0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x37, 0x00, 0x2F, 0x00, 0x24, 0x00, 0x25,
    0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x36, 0x00, 0x2E, 0x00, 0x24,
    0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x38, 0x00, 0x30,
    0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x38,
    0x00, 0x31, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A,
    0x00, 0x38, 0x00, 0x32, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29,
    0x00, 0x2A, 0x00, 0x38, 0x00, 0x33, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28,
    0x00, 0x29, 0x00, 0x2A, 0x00, 0x38, 0x00, 0x30, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x27,
    0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x38, 0x00, 0x30, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26,
    0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x39, 0x00, 0x4C, 0x00, 0x4E,
    0x00, 0x3A, 0x00, 0x4A, 0x00, 0x4D, 0x00, 0x4F, 0x00, 0x3B, 0x00, 0x00, 0x00, 0x4B, 0x00, 0x4C,
    0x00, 0x4E, 0x00, 0x3C, 0x00, 0x4A, 0x00, 0x4D, 0x00, 0x4F, 0x00, 0x3D, 0x00, 0x00, 0x00, 0x4B,
    0x00, 0x4C, 0x00, 0x4E, 0x00, 0x3E, 0x00, 0x4A, 0x00, 0x4D, 0x00, 0x4F, 0x00, 0x3F, 0x00, 0x00,
    0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4E, 0x00, 0x40, 0x00, 0x4A, 0x00, 0x4D, 0x00, 0x4F, 0x00, 0x41,
    0x00, 0x00, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44, 0x00, 0x45, 0x00, 0x46, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};
u32 D_80078544 = 0x00000000;
unk_D_80078548 D_80078548[6] = {
    { 0x03, 0x29 }, { 0x8C, 0x83 }, { 0x18, 0x1F }, { 0x9A, 0x04 }, { 0x9B, 0x2A }, { 0x00, 0x00 },
};
u8 D_80078554[20] = {
    0x0E, 0x36, 0x4A, 0x60, 0x61, 0x68, 0x6A, 0x6B, 0x6E, 0x6F, 0x70, 0x71, 0x73, 0x74, 0x85, 0x97,
    0x9F, 0x00, 0x00, 0x00,
};
u8 D_80078568[24] = {
    0x1C, 0x27, 0x2B, 0x2D, 0x51, 0x67, 0x6C, 0x86, 0x94, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};


void BitArray_SetBit(u8* array, u8 index, u8 flag) {
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
s32 BitArray_IsBitSet(u8* array, u8 index) {
    u8 offset = index / 8;
    u8 bitPosition = index % 8;
    u8 flag = (array[offset] & (u8)(1 << bitPosition));
    if (flag) {
        return 1;
    }
    return 0;
}

void Audio_SetVoiceEnabled(s32 arg0) {
    if (arg0 != 0) {
        D_80078388 = 1;
    } else {
        D_80078388 = 0;
    }
}

void Audio_SetChannelGroupCounts(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    D_8007838C[0] = arg0;
    D_8007838C[1] = arg1;
    D_8007838C[2] = arg2;
    D_8007838C[3] = arg3;
}

void Audio_ResetChannelGroupState(u8 arg0) {
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

void Audio_ConfigureChannelGroups(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
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
    Audio_ResetChannelGroupState(0);
    Audio_ResetChannelGroupState(1);
}

void Audio_SelectModeMusic(u32 arg0, u32 arg1) {
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
            Audio_QueueSequenceId(0x34);
        } else if ((arg0 == 0xFF) && (arg1 != 0x10) && (arg1 != 0xF)) {
            Audio_QueueSequenceId(0x47);
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
            Audio_QueueSequenceId(var_a0);
        }
    }
}

void AudioFrameUpdate(s32 arg0) {
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
        Audio_PlayCommand(0x5A, D_80078400, 0);

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
                    Audio_QueueSoundAvoidingRecent(D_80077E90);
                } else {
                    Audio_QueueSoundAvoidingRecent(D_80077E48);
                }
                return;
            }

            if (((((u32)D_800FCB18[0]->unk_0C * 100) / D_800FCB18[0]->unk_28) < 0x1E) &&
                ((((u32)D_800FCB18[1]->unk_0C * 100) / D_800FCB18[1]->unk_28) < 0x1E)) {
                Audio_QueueSoundAvoidingRecent(D_80077E88);
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
                Audio_QueueSoundAvoidingRecent(D_80077E68);
            } else if (D_80078400 == 0) {
                Audio_QueueSoundAvoidingRecent(D_80077E78);
            } else {
                Audio_QueueSoundAvoidingRecent(D_80077DF0);
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
                Audio_QueueSoundAvoidingRecent(D_80077E70);
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
                Audio_QueueSequenceId(var_a0);
            } else if (D_80078390[D_800FCCB0 - 1] == 1) {
                Audio_QueueSequenceId(0x26A);
            } else {
                Audio_QueueSoundAvoidingRecent(D_80077E00);
            }
            return;
        }

        if (D_800FCCB0 != 0) {
            if (((D_80078390[0] == 1) || (D_80078390[1] == 1)) && (D_80078390[0] < 4) &&
                (D_80078390[1] < 4)) {
                if (D_80078390[0] == 1) {
                    switch (D_80078390[1]) {
                        case 1:
                            Audio_QueueSequenceId(0x260);
                            Audio_QueueSequenceId(0x266);
                            break;

                        case 2:
                            Audio_QueueSequenceId(0x261);
                            if (D_800FCCB0 == 1) {
                                Audio_QueueSequenceId(0x265);
                            } else {
                                Audio_QueueSequenceId(0x267);
                            }
                            break;

                        case 3:
                            Audio_QueueSequenceId(0x262);
                            Audio_QueueSequenceId(0x264);
                            break;

                        default:
                            Audio_QueueSequenceId(0x271);
                            break;
                    }

                    D_800FCCB0 = 0;
                    return;
                }

                switch (D_80078390[0]) {
                    case 2:
                        Audio_QueueSequenceId(0x25E);
                        if (D_800FCCB0 == 2) {
                            Audio_QueueSequenceId(0x265);
                        } else {
                            Audio_QueueSequenceId(0x267);
                        }
                        break;

                    case 3:
                        Audio_QueueSequenceId(0x25C);
                        Audio_QueueSequenceId(0x264);
                        break;

                    default:
                        Audio_QueueSequenceId(0x271);
                        break;
                }

                D_800FCCB0 = 0;
                return;
            }

            if (D_800FCCB1 != 0) {
                if ((osGetTime() % 2) != 0) {
                    D_800FCCB0 = 0;
                    Audio_QueueSoundAvoidingRecent(D_80077E10);
                    return;
                }
            }

            if (D_800FCB18[0]->unk_16[6] != D_800FCB18[1]->unk_16[6]) {
                if (D_800FCB18[0]->unk_16[6] != D_800FCB18[1]->unk_16[7]) {
                    if ((D_800FCB18[0]->unk_16[7] != D_800FCB18[1]->unk_16[6]) &&
                        (D_800FCB18[0]->unk_16[7] != D_800FCB18[1]->unk_16[7])) {
                        D_800FCCB0 = 0;
                        Audio_QueueSoundAvoidingRecent(D_80077E18);
                        return;
                    }
                }
            }

            D_800FCCB0 = 0;
            switch (D_80078390[0]) {
                case 2:
                    switch (D_80078390[1]) {
                        case 2:
                            Audio_QueueSequenceId(0x25D);
                            Audio_QueueSequenceId(0x268);
                            break;

                        case 3:
                            Audio_QueueSequenceId(0x25F);
                            Audio_QueueSequenceId(0x263);
                            break;

                        default:
                            Audio_QueueSequenceId(0x271);
                            break;
                    }
                    break;

                case 3:
                    if (D_80078390[1] == 2) {
                        Audio_QueueSequenceId(0x25B);
                        Audio_QueueSequenceId(0x263);
                    } else {
                        Audio_QueueSequenceId(0x271);
                    }
                    break;

                default:
                    if (D_80078400 == 0) {
                        Audio_QueueSoundAvoidingRecent(D_80077E78);
                    } else {
                        Audio_QueueSoundAvoidingRecent(D_80077DF0);
                    }
                    break;
            }

            return;
        }

        if (D_800FCCB3 != 0) {
            Audio_QueueSoundAvoidingRecent(D_80077E38);
            D_800FCCB3 = 0;
            return;
        }

        if (D_800FCCB4 != 0) {
            Audio_QueueSoundAvoidingRecent(D_80077E40);
            D_800FCCB4 = 0;
            return;
        }

        if (D_800FCCB5 != 0) {
            Audio_QueueSoundAvoidingRecent(D_80077E50);
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
                    Audio_QueueSoundAvoidingRecent(D_80077E60);
                } else {
                    Audio_QueueSoundAvoidingRecent(D_80077E58);
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
            (D_800FCB18[0]->unk_0C != D_800FCB18[0]->unk_28) &&
            (D_800FCB18[1]->unk_0C != D_800FCB18[1]->unk_28)) {
            if ((D_800FCB18[var_t5]->unk_28 * 0.6) < D_800FCB18[var_t5]->unk_0C) {
                if (D_800FCB18[var_t0]->unk_0C < (D_800FCB18[var_t0]->unk_28 * 0.4)) {
                    Audio_QueueSoundAvoidingRecent(D_80077E20);
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
                    Audio_QueueSoundAvoidingRecent(D_80077E30);
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
                    Audio_QueueSoundAvoidingRecent(D_80077E28);
                    return;
                }
            }
        }

        if (D_80078400 == 0) {
            Audio_QueueSoundAvoidingRecent(D_80077E78);
        } else {
            Audio_QueueSoundAvoidingRecent(D_80077DF0);
        }

        return;
    }

    var_v0 = osSetIntMask(1);
    D_800783BC = 0;
    osSetIntMask(var_v0);
    Audio_FadeCommand(0x5A, 0);
    Audio_FadeCommand(0x5B, 0);

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
        (D_800FCB18[0]->unk_0C != 0) && (D_800FCB18[1]->unk_0C != 0) && (AudioStream_IsPlaying(1) == 0)) {
        if ((osGetTime() % 2) == 0) {
            Audio_QueueSoundAvoidingRecent(D_800780A8);
        }
    }
}

void ProcessAudioInfo(s32 arg0, BattleMonRuntime* arg1) {
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

    Audio_ResetChannelGroupState(side);

    D_800FCCC8[side ^ 1] = 0;

    D_800FCB28[side] = D_800FCB18[side]->unk_0C;
    D_800FCB48[side].unk_24++;
    D_800FCB48[side].unk_00[D_800FCB48[side].unk_24 & 0xF] = D_800FCB18[side]->unk_0C;

    value = D_800FCB18[side]->id;
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
        Audio_QueueSequenceId(value + 0xCB);
        if (changed) {
            Audio_QueueSoundAvoidingRecent(D_80077FEC);
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
                    Audio_QueueSoundAvoidingRecent(D_80078014);
                }
            } else if (changed == 0) {
                Audio_QueueSoundWithFallbackList(9, D_80077FF4, &D_800FCCBA[side]);
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
                        Audio_QueueSequenceId(0xA);
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
                    Audio_QueueSequenceId(2);
                } else {
                    Audio_QueueSequenceId(1);
                }
            } else {
                Audio_QueueSequenceId(0x50);
                if (changed != 0) {
                    Audio_QueueSoundAvoidingRecent(D_80077FEC);
                }
            }
            D_800783DC = 1;
        } else {
            Audio_QueueSequenceId(0x58);
            D_800783DC = 0;
            if (changed != 0) {
                Audio_QueueSoundAvoidingRecent(D_80077FEC);
            }
        }
    } else if (changed != 0) {
        Audio_QueueSoundAvoidingRecent(D_80077FEC);
    }

    D_800FCB30[side] = 0;

    if (D_800FCB18[side ^ 1] == NULL) {
        return;
    }

    if (changed != 0) {
        return;
    }

    if ((D_800FCB18[side])->unk_15 & 0x20) {
        Audio_QueueSoundAvoidingRecent(D_80077FFC);
        return;
    }

    if ((D_800FCB18[side])->unk_15 & 7) {
        Audio_QueueSoundAvoidingRecent(D_80078004);
        return;
    }

    if ((D_800FCB18[side])->unk_15 & 8) {
        Audio_QueueSequenceId(6);
        return;
    }

    if ((D_800FCB18[side])->unk_15 & 0x10) {
        Audio_QueueSequenceId(7);
        return;
    }

    if ((((f32)(D_800FCB18[side])->unk_0C / (f32)(D_800FCB18[side])->unk_28) < 0.2f) && ((D_800FCB18[side])->unk_0C < D_800FCB18[side ^ 1]->unk_0C)) {
        Audio_QueueSoundAvoidingRecent(D_8007800C);
    }
}

void RemovePlayer(u32 arg0) {
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
    Audio_PlayCommand(0x16, D_80078400, 0);
    if (D_800783D8 != 0) {
        Audio_QueueSequenceId(0xC3);
        D_800783D8 = 0;
        D_800783E4 = 1;
        return;
    }
    D_800783D8 = 1;
    if (D_800783D4 != 0) {
        Audio_QueueSequenceId(0xB9);
        D_800783D4 = 0;
        return;
    }
    if (D_800783CC < 2) {
        if (osGetTime() % 2 == 0) {
            Audio_QueueSequenceId(0xBC);
        } else {                
            Audio_QueueSequenceId(0xC5);
        }
    } else if (D_800783D0 != 0) {
        Audio_QueueSequenceId(0xC4);
        D_800783D0 = 0;
    } else if ((D_800FCCA4 >= 0x64U) && (D_800FCCB2 == 0) && (D_800783EC == 0)) {
        if (((f32)D_800FCB18[sp1F]->unk_26 * (3.0 / 10.0)) < ((f32)D_800FCB18[sp1F ^ 1]->unk_26 - D_800FCB18[sp1F]->unk_26)) {
            Audio_QueueSoundAvoidingRecent(D_80077FC0);
        } else {
            Audio_QueueSoundAvoidingRecent(D_80077FD0);
        }
        D_800FCCD6[sp1F] = 1;
    } else if ((D_800FCB48[sp1F].unk_78 >= 8U) && (D_800FCCB2 == 0)) {
        if (((u32) D_800FCCA4 < 5U) && (D_800783E8 == 0)) {
            Audio_QueueSequenceId(0xC2);
        } else {
            Audio_QueueSoundAvoidingRecent(D_80077FC8);
        }
    } else {
        Audio_QueueSoundAvoidingRecent(D_80077FB4);
    }
}

void PlayerDefeated(u32 arg0) {
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
        Audio_QueueSequenceId(0x58);
        D_800783DC = 0;
        return;
    }
    
    D_800783DC = 1;
    
    if (D_800783CC < 2) {
        if (osGetTime() % 2 == 0) {
            Audio_QueueSequenceId(0x54);
        } else {
            Audio_QueueSequenceId(0x55);
        }
    } else if (D_800FCB48[temp_v0].unk_78 < 2) {
        Audio_QueueSoundAvoidingRecent(D_80077FE4);
    } else {
        Audio_QueueSoundAvoidingRecent(D_80077FD8);
    }
}

void Audio_QueuePendingSoundId(u32 arg0) {
    D_800FCCF0[D_80078544] = arg0;
    D_80078544++;
    if (D_80078544 >= 0xA) {
        D_80078544--;
    }
}

void ProcessAudioCommandQueue(s32 arg0) {
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
            Audio_QueueSequenceId(0x165);
            D_80078544 = 0;
            D_800FCCBE[temp_s0] = 0;
            Audio_PlayCommand(0x16, D_80078400, 0);
            return;
        case 0x6:
            if (D_800FCB48[temp_s0].unk_7C == 1) {
                Audio_QueueSequenceId(0x19F);
            } else if (D_800FCB48[temp_s0].unk_7C >= 4U) {
                Audio_QueueSequenceId(0x164);
            } else {
                Audio_QueueSequenceId(0x163);
            }
            D_80078544 = 0;
            D_800FCB48[temp_s0].unk_7C = 0;
            D_800FCCBC[temp_s0] = 0;
            D_800FCCB4 = 0;
            Audio_PlayCommand(0x16, D_80078400, 0);
            return;
        case 0xB:
            Audio_QueueSequenceId(0x17B);
            D_80078544 = 0;
            return;
        case 0xC:
            Audio_QueueSequenceId(0x186);
            D_800FCCC4[temp_s0] = 0;
            D_80078544 = 0;
            return;
        case 0x11:
            Audio_QueueSequenceId(0x192);
            D_800FCCD4[temp_s0] = 0;
            D_80078544 = 0;
            return;
        case 0x5:
            if ((D_80078390[0] == 1) && (D_80078390[1] == 1)) {
                Audio_QueueSoundWithFallbackList(0x17D, &D_80078040, &D_800FCCBC[temp_s0]);
            } else {
                Audio_QueueSoundWithFallbackList(0x17D, &D_8007801C, &D_800FCCBC[temp_s0]);
            }
            D_80078544 = 0;
            return;
        case 0x7:
            if ((D_80078390[0] == 1) && (D_80078390[1] == 1)) {
                Audio_QueueSoundWithFallbackList(0x17E, &D_80078038, &D_800FCCBE[temp_s0]);
            } else {
                Audio_QueueSoundWithFallbackList(0x17E, &D_80078024, &D_800FCCBE[temp_s0]);
            }
            D_80078544 = 0;
            return;
        case 0x10:
            if ((D_80078390[0] == 1) && (D_80078390[1] == 1)) {
                Audio_QueueSoundWithFallbackList(0x17F, &D_80078040, &D_800FCCC0[temp_s0]);
            } else {
                Audio_QueueSoundWithFallbackList(0x17F, &D_80078030, &D_800FCCC0[temp_s0]);
            }
            D_80078544 = 0;
            return;
        case 0x8:
            if ((D_80078390[0] == 1) && (D_80078390[1] == 1)) {
                Audio_QueueSoundWithFallbackList(0x17C, &D_80078040, &D_800FCCC2[temp_s0]);
            } else {
                Audio_QueueSoundWithFallbackList(0x17C, &D_80078048, &D_800FCCC2[temp_s0]);
            }
            D_80078544 = 0;
            return;
        case 0x9:
        case 0xA:
            if ((D_80078390[0] == 1) && (D_80078390[1] == 1)) {
                Audio_QueueSequenceId(0x180);
            } else {
                Audio_QueueSequenceId(0x17C);
            }
            D_80078544 = 0;
            return;
        case 0x13:
            Audio_QueueSoundAvoidingRecent(&D_80078050);
            D_800FCCB6 = 1;
            D_80078544 = 0;
            return;
        case 0xF:
            Audio_QueueSequenceId(0x17A);
            D_80078544 = 0;
            return;
        case 0xE:
            D_800783D0 = 1;
            if (D_800FCCC4[temp_s0] != 0) {
                Audio_QueueSoundAvoidingRecent(&D_80078060);
            } else {
                Audio_QueueSoundAvoidingRecent(&D_80078058);
                D_800FCCC4[temp_s0] = 1;
            }
            D_80078544 = 0;
            Audio_PlayCommand(0x16, D_80078400, 0);
            return;
        case 0x12:
            if (D_800FCCCA[temp_s0] == 0) {
                Audio_QueueSequenceId(0x18C);
            } else {
                Audio_QueueSequenceId(0x18E);
            }
            D_800FCCCA[temp_s0] ^= 1;
            D_80078544 = 0;
            Audio_PlayCommand(0x16, D_80078400, 0);
            return;
        case 0x71:
        case 0x77:
            Audio_QueueSoundWithFallbackList(0x16A, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0x72:
        case 0x78:
            Audio_QueueSoundWithFallbackList(0x16B, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0x73:
        case 0x79:
            Audio_QueueSoundWithFallbackList(0x16C, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0x74:
        case 0x7A:
            Audio_QueueSoundWithFallbackList(0x16D, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0x75:
        case 0x7B:
            Audio_QueueSoundWithFallbackList(0x16E, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0x76:
        case 0x7C:
            Audio_QueueSoundWithFallbackList(0x16F, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0xB5:
            Audio_QueueSoundWithFallbackList(0x170, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0xB7:
            Audio_QueueSoundWithFallbackList(0x171, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0x9A:
            Audio_QueueSoundWithFallbackList(0x169, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0x9C:
            Audio_QueueSoundWithFallbackList(0x194, &D_80078068, &D_800FCCC6[temp_s0]);
            D_80078544 = 0;
            return;
        case 0xAE:
            Audio_QueueSequenceId(0x1A0);
            D_80078544 = 0;
            return;
        case 0x7E:
        case 0x84:
            if (D_800FCCC8[temp_s0] < 3) {
                Audio_QueueSoundWithFallbackList(0xA2, &D_80078070, &D_800FCCC8[temp_s0]);
            } else {
                Audio_QueueSoundAvoidingRecent(&D_80078078);
            }
            D_80078544 = 0;
            return;
        case 0x7F:
        case 0x85:
            if (D_800FCCC8[temp_s0] < 3) {
                Audio_QueueSoundWithFallbackList(0xA3, &D_80078070, &D_800FCCC8[temp_s0]);
            } else {
                Audio_QueueSoundAvoidingRecent(&D_80078078);
            }
            D_80078544 = 0;
            return;
        case 0x80:
        case 0x86:
            if (D_800FCCC8[temp_s0] < 3) {
                Audio_QueueSoundWithFallbackList(0xA7, &D_80078070, &D_800FCCC8[temp_s0]);
            } else {
                Audio_QueueSoundAvoidingRecent(&D_80078078);
            }
            D_80078544 = 0;
            return;
        case 0x81:
        case 0x87:
            if (D_800FCCC8[temp_s0] < 3) {
                Audio_QueueSoundWithFallbackList(0xA4, &D_80078070, &D_800FCCC8[temp_s0]);
            } else {
                Audio_QueueSoundAvoidingRecent(&D_80078078);
            }
            D_80078544 = 0;
            return;
        case 0x82:
        case 0x88:
            if (D_800FCCC8[temp_s0] < 3) {
                Audio_QueueSoundWithFallbackList(0xA5, &D_80078070, &D_800FCCC8[temp_s0]);
            } else {
                Audio_QueueSoundAvoidingRecent(&D_80078078);
            }
            D_80078544 = 0;
            return;
        case 0x83:
        case 0x89:
            if (D_800FCCC8[temp_s0] < 3) {
                Audio_QueueSoundWithFallbackList(0xA6, &D_80078070, &D_800FCCC8[temp_s0]);
            } else {
                Audio_QueueSoundAvoidingRecent(&D_80078078);
            }
            D_80078544 = 0;
            return;
        case 0x19:
        case 0x1B:
            if ((D_800780B3[D_800FCCAC * 3] == 0) && ((D_800FCB18[temp_s0]->unk_16[6] == 8) || (D_800FCB18[temp_s0]->unk_16[7] == 8))) {
                Audio_QueueSoundAvoidingRecent(&D_80077F24);
            } else {
                Audio_QueueSoundAvoidingRecent(&D_80077F14);
            }
            D_80078544 = 0;
            return;
        case 0x1A:
        case 0x1C:
            if (D_800FCCD2[temp_s0 ^ 1] != 0) {
                Audio_QueueSoundAvoidingRecent(&D_80077F50);
            } else {
                if ((D_800783D4 != 0) || ((D_80078390[temp_s0 ^ 1] == 1) && ((s32)D_800FCB18[temp_s0 ^ 1]->unk_0C < 0x13))) {
                    Audio_QueueSoundAvoidingRecent(&D_80077F1C);
                    Audio_PlayCommand(0x16, D_80078400, 0);
                } else {
                    Audio_QueueSoundAvoidingRecent(&D_80077F0C);
                }
                D_800FCCD2[temp_s0 ^ 1] = 1;
            }
            D_80078544 = 0;
            return;
        case 0xA7:
            Audio_QueueSoundAvoidingRecent(&D_80077F0C);
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
            Audio_QueueSoundAvoidingRecent(&D_80078088);
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
            Audio_QueueSoundAvoidingRecent(&D_80078090);
            D_80078544 = 0;
            return;
        case 0x1F:
            Audio_QueueSequenceId(0x18D);
            D_80078544 = 0;
            return;
        case 0x93:
        case 0x94:
        case 0x95:
        case 0x96:
            Audio_QueueSequenceId(0x18F);
            D_80078544 = 0;
            return;
        case 0x97:
            Audio_QueueSoundWithFallbackList(0x18A, &D_80078098, &D_800FCCCE[temp_s0]);
            D_80078544 = 0;
            Audio_PlayCommand(0x16, D_80078400, 0);
            return;
        case 0x98:
            Audio_QueueSoundWithFallbackList(0x18B, &D_800780A0, &D_800FCCD0[temp_s0]);
            D_80078544 = 0;
            Audio_PlayCommand(0x16, D_80078400, 0);
            return;
        case 0x2B:
            Audio_QueueSequenceId(0x76);
            D_80078544 = 0;
            return;
        case 0x2C:
            Audio_QueueSoundAvoidingRecent(&D_80078080);
            D_80078544 = 0;
            return;
        case 0xBB:
            Audio_QueueSequenceId(0x189);
            D_80078544 = 0;
            Audio_PlayCommand(0x16, D_80078400, 0);
            D_800783D0 = 1;
            return;
        case 0x68:
            Audio_QueueSoundAvoidingRecent(&D_80077F34);
            D_80078544 = 0;
            return;
        case 0x69:
            Audio_QueueSoundAvoidingRecent(&D_80077F3C);
            D_80078544 = 0;
            return;
        case 0xA1:
            Audio_QueueSequenceId(0x7A);
            D_80078544 = 0;
            return;
        case 0xA6:
            Audio_QueueSoundAvoidingRecent(&D_80077F2C);
            D_80078544 = 0;
            return;
        case 0xAF:
        case 0xB0:
            Audio_QueueSequenceId(0x167);
            D_800FCB48[temp_s0].unk_24++;
            ((u16*)D_800FCB48[temp_s0].unk_00)[D_800FCB48[temp_s0].unk_24 & 0xF] = ((BattleMonRuntime*)D_800FCB18[temp_s0])->unk_0C;
            D_80078544 = 0;
            return;
        case 0xB1:
            Audio_QueueSequenceId(0x166);
            D_800FCB48[temp_s0].unk_24++;
            ((u16*)D_800FCB48[temp_s0].unk_00)[D_800FCB48[temp_s0].unk_24 & 0xF] = ((BattleMonRuntime*)D_800FCB18[temp_s0])->unk_0C;
            D_80078544 = 0;
            return;
        case 0xB3:
            Audio_QueueSequenceId(0x188);
            D_80078544 = 0;
            Audio_PlayCommand(0x16, D_80078400, 0);
            return;
        case 0xA8:
            Audio_QueueSequenceId(0x197);
            D_80078544 = 0;
            return;
        case 0xA9:
            Audio_QueueSequenceId(0x193);
            D_80078544 = 0;
            return;
        case 0xA4:
            Audio_QueueSequenceId(0x195);
            D_80078544 = 0;
            return;
        case 0xAC:
            Audio_QueueSequenceId(0x196);
            D_80078544 = 0;
            return;
        case 0x9F:
            Audio_QueueSequenceId(0x87);
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
        Audio_QueueSequenceId(0x79);
        D_800FCCB3 = 1;
        Audio_PlayCommand(0x16, D_80078400, 0);
    } else if (sp36 != 0) {
        mask = osSetIntMask(1);
        D_800FCCA2 = 0;
        osSetIntMask(mask);
        if (D_800FCCCC[temp_s0] != 0) {
            Audio_QueueSequenceId(0xAD);
        } else {
            Audio_QueueSequenceId(0x78);
        }
        D_800FCB48[temp_s0].unk_7C = 1;
        D_800FCCCC[temp_s0] = 1;
        D_800FCCB4 = 1;
        Audio_PlayCommand(0x16, D_80078400, 0);
    } else if (sp37 != 0) {
        mask = osSetIntMask(1);
        D_800FCCA2 = 0;
        osSetIntMask(mask);
        D_800783E8 = 1;
        Audio_QueueSequenceId(0x77);
        Audio_PlayCommand(0x16, D_80078400, 0);
    } else if (sp3A != 0) {
        mask = osSetIntMask(1);
        D_800FCCA2 = 0;
        osSetIntMask(mask);
        D_800783E8 = 1;
        if (sp39 != 0) {
            if ((u32) D_800FCCA4 < 0xAU) {
                if ((D_800FCB18[temp_s0]->unk_0C > 0) && ((s32)D_800FCB18[temp_s0 ^ 1]->unk_0C >= 0xB)) {
                    Audio_QueueSoundAvoidingRecent(&D_80077EF0);
                } else {
                    Audio_QueueSoundAvoidingRecent(&D_80077F04);
                }
            } else if ((u32) D_800783CC < 2U) {
                Audio_QueueSequenceId(0x68);
                Audio_PlayCommand(0x16, D_80078400, 0);
            } else {
                if ((D_800FCB48[temp_s0 ^ 1].unk_78 < 2U) && (D_80078390[temp_s0 ^ 1] >= 2)) {
                    Audio_QueueSoundAvoidingRecent(&D_80077F58);
                } else {
                    Audio_QueueSoundAvoidingRecent(&D_80077EE4);
                }
                Audio_PlayCommand(0x16, D_80078400, 0);
            }
        } else if ((u32) D_800FCCA4 < 0xAU) {
            if (((s32)D_800FCB18[temp_s0]->unk_0C > 0) && ((s32)D_800FCB18[temp_s0 ^ 1]->unk_0C >= 0xB)) {
                Audio_QueueSoundAvoidingRecent(&D_80077EF0);
            } else {
                Audio_QueueSoundAvoidingRecent(&D_80077F04);
            }
        } else {
            Audio_QueueSoundAvoidingRecent(&D_80077EC0);
            Audio_PlayCommand(0x16, D_80078400, 0);
        }
    } else if (sp39 != 0) {
        mask = osSetIntMask(1);
        D_800FCCA2 = 0;
        osSetIntMask(mask);
        D_800783E8 = 1;
        if ((D_800FCB48[temp_s0 ^ 1].unk_78 < 2U) && (D_80078390[temp_s0 ^ 1] >= 2)) {
            Audio_QueueSoundAvoidingRecent(&D_80077F58);
        } else {
            Audio_QueueSoundAvoidingRecent(&D_80077ECC);
        }
        Audio_PlayCommand(0x16, D_80078400, 0);
    } else if (sp38 != 0) {
        mask = osSetIntMask(1);
        D_800FCCA2 = 0;
        osSetIntMask(mask);
        if ((u32) D_800FCCA4 >= 0x29U) {
            Audio_QueueSoundAvoidingRecent(&D_80077EF8);
            Audio_PlayCommand(0x16, D_80078400, 0);
        } else if ((D_800FCB18[0]->unk_0C > 0) && (D_800FCB18[1]->unk_0C > 0)) {
            Audio_QueueSoundAvoidingRecent(&D_80077ED8);
        } else {
            Audio_QueueSoundAvoidingRecent(&D_80077F04);
            Audio_PlayCommand(0x16, D_80078400, 0);
        }
    } else if ((sp32 != 0) && (D_800FCCA4 != 0)) {
        if (D_800FCCA4 >= 0x29) {
            Audio_QueueSoundAvoidingRecent(&D_80077E98);
            Audio_PlayCommand(0x16, D_80078400, 0);
        }else if (D_800FCCA4 >= 6) {
            if (( D_800FCB18[0]->unk_0C > 0) && ((s32) D_800FCB18[1]->unk_0C > 0)) {
                Audio_QueueSoundAvoidingRecent(&D_80077EA4);
            } else {
                Audio_QueueSoundAvoidingRecent(&D_80077F60);
            }
        }else if (((s32) D_800FCB18[0]->unk_0C > 0) && ((s32) D_800FCB18[1]->unk_0C > 0)) {
            Audio_QueueSoundAvoidingRecent(&D_80077EB4);
        } else {
            Audio_QueueSoundAvoidingRecent(&D_80077F04);
        }
    }
}

void HandleMoveEvent(BattleMonRuntime* arg0, s32 arg1, s32 arg2, s32 arg3) {
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
            Audio_RemoveLastQueuedSequenceId();
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
                Audio_PlayCommand(0x16, D_80078400, 0);
            }
            break;

        case 0:
        case 2:
            Audio_RemoveLastQueuedSequenceId();
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
                tmp = Battle_EstimateMoveDamage(arg1, D_800FCB18[sp40], D_800FCB18[sp40 ^ 1]);

                if (tmp == -1) {
                    if (BitArray_IsBitSet(D_800FCCD8, arg1 - 1) == 0) {
                        sp34 = arg1 + 0x1A2;
                        BitArray_SetBit(D_800FCCD8, arg1 - 1, 1);
                        Audio_QueueSequenceId(sp34);
                    } else {
                        Audio_QueueSoundAvoidingRecent(D_80077F6C);
                    }
                } else if (tmp == -2) {
                    if (BitArray_IsBitSet(D_800FCCD8, arg1 - 1) == 0) {
                        sp34 = arg1 + 0x1A2;
                        BitArray_SetBit(D_800FCCD8, arg1 - 1, 1);
                        Audio_QueueSequenceId(sp34);
                    } else {
                        Audio_QueueSoundAvoidingRecent(D_80077F74);
                    }
                } else if (tmp == -3) {
                    D_800783D4 = 1;
                    if (BitArray_IsBitSet(D_800FCCD8, arg1 - 1) == 0) {
                        sp34 = arg1 + 0x1A2;
                        BitArray_SetBit(D_800FCCD8, arg1 - 1, 1);
                        Audio_QueueSequenceId(sp34);
                    } else {
                        Audio_QueueSequenceId(0x187);
                    }
                } else if (tmp == -4) {
                    if (BitArray_IsBitSet(D_800FCCD8, arg1 - 1) == 0) {
                        sp34 = arg1 + 0x1A2;
                        BitArray_SetBit(D_800FCCD8, arg1 - 1, 1);
                        Audio_QueueSequenceId(sp34);
                    } else {
                        Audio_QueueSoundAvoidingRecent(D_80077F98);
                    }
                } else if (tmp != -5) {
                    if ((D_800FCB48[sp40 ^ 1].unk_00[D_800FCB48[sp40 ^ 1].unk_24 & 0xF] < tmp) && (D_800FCCB6 == 0)) {
                        if (BitArray_IsBitSet(D_800FCCD8, arg1 - 1) == 0) {
                            sp34 = arg1 + 0x1A2;
                            BitArray_SetBit(D_800FCCD8, arg1 - 1, 1);
                            Audio_QueueSequenceId(sp34);
                        } else {
                            Audio_QueueSoundAvoidingRecent(D_80077F90);
                            D_800FCCB6 = 0;
                        }
                    } else {
                        D_800FCCB6 = 0;
                        temp_lo = (tmp * 0x64) / D_800FCB18[sp40 ^ 1]->unk_28;
                        if (temp_lo >= 0x51) {
                            if (D_800FCCAF == 0) {
                                D_800FCCAF = 1;
                                Audio_QueueSoundAvoidingRecent(D_80077F6C);
                            } else {
                                Audio_QueueSoundAvoidingRecent(D_80077F74);
                            }
                        } else if (temp_lo >= 0x33) {
                            if (D_800783CC == 1) {
                                Audio_QueueSoundAvoidingRecent(D_80077F88);
                            } else {
                                Audio_QueueSoundAvoidingRecent(D_80077F7C);
                            }
                        } else if (AudioStream_IsPlaying(1) == 0) {
                            if (D_800783CC == 1) {
                                if (D_800FCCAE == 2) {
                                    Audio_QueueSoundAvoidingRecent(D_80077FAC);
                                } else {
                                    Audio_QueueSoundAvoidingRecent(D_80077FA4);
                                }
                            } else {
                                Audio_QueueSoundAvoidingRecent(D_80077F98);
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
                tmp = Battle_EstimateMoveDamage(arg1, D_800FCB18[sp40], D_800FCB18[sp40 ^ 1]);
                if ((tmp >> 0x10) == 0) {
                    tmp = tmp << 1;

                    if (D_800FCB48[sp40 ^ 1].unk_00[D_800FCB48[sp40 ^ 1].unk_24 & 0xF] < tmp) {
                        if (BitArray_IsBitSet(D_800FCCD8, arg1 - 1) == 0) {
                            sp34 = arg1 + 0x1A2;
                            BitArray_SetBit(D_800FCCD8, arg1 - 1, 1);
                            Audio_QueueSequenceId(sp34);
                        } else {
                            Audio_QueueSoundAvoidingRecent(D_80077F90);
                        }
                    } else {
                        temp_lo = (tmp * 0x64u) / D_800FCB18[sp40 ^ 1]->unk_28;
                        if (temp_lo >= 0x51) {
                            if (D_800FCCAF == 0) {
                                D_800FCCAF = 1;
                                Audio_QueueSoundAvoidingRecent(D_80077F6C);
                            } else {
                                Audio_QueueSoundAvoidingRecent(D_80077F74);
                            }
                        } else if (temp_lo >= 0x33) {
                            if (D_800783CC == 1) {
                                Audio_QueueSoundAvoidingRecent(D_80077F88);
                            } else {
                                Audio_QueueSoundAvoidingRecent(D_80077F7C);
                            }
                        } else if (AudioStream_IsPlaying(1) == 0) {
                            if (D_800783CC == 1) {
                                if (D_800FCCAE == 2) {
                                    Audio_QueueSoundAvoidingRecent(D_80077FAC);
                                } else {
                                    Audio_QueueSoundAvoidingRecent(D_80077FA4);
                                }
                            } else {
                                Audio_QueueSoundAvoidingRecent(D_80077F98);
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

void QueuePlayerDefeatMessage(s32 arg0) {
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
        Audio_QueueSequenceId(0x190);
        D_800FCCD4[temp_v0] = 1;
    } else {
        Audio_QueueSequenceId(0x191);
    }
}

void Audio_StartBattleMusicSequence(void) {
    if (D_80078E80 == 0) {
        Audio_StartMusicTrack(0x3D);
        Audio_PlayCommand(0x16, D_80078400, 0);
        if (D_80078404 == 0xC) {
            if (!(D_80078408 & 3) && (*D_80078390 != 0)) {
                Audio_QueueSequenceId(0xCA);
                return;
            }
            Audio_QueueSequenceId(0xC8);
            return;
        }
        if (D_80078404 == 0xD) {
            if ((D_80078408 == 4) && (*D_80078390 != 0)) {
                Audio_QueueSequenceId(0xCA);
                return;
            }
            if ((D_80078408 == 5) && (*D_80078390 != 0)) {
                Audio_QueueSequenceId(0xCB);
                return;
            }
            Audio_QueueSequenceId(0xC8);
            return;
        }
        if ((D_80078408 == 8) && (*D_80078390 != 0)) {
            Audio_QueueSequenceId(0xC9);
            return;
        }
        Audio_QueueSequenceId(0xC8);
    }
}

void Audio_StartResultMusicSequence(void) {
    Audio_PlayCommand(0x16, D_80078400, 0);
    Audio_QueueSequenceId(0x1A2);
}

void Audio_UpdateBattleAudioFrame(void) {
    u8* seq;

    if ((D_800783B4 < D_800783B8) && (D_80078388 != 0) && (AudioStream_IsPlaying(1) == 0)) {
        if (D_800783A4[D_800783B4 & 3] != 0) {
            seq = D_800FC714->seqArray[D_800783A4[D_800783B4 & 3] - 1].offset;
            AudioStream_Start(1, seq, 0x7E, 0);
        }
        D_800783B4++;
    }

    if (D_800783BC != 0) {
        if ((D_800783C8 >= 0x3E9) && (D_800783C0 == 0) && (D_800783CC != 0)) {
            Audio_QueueSequenceId(0x248);
            D_800783C0 = 1;
        } else if ((D_800783C8 >= 0x7D1) && (D_800783C0 == 0) && (D_800783CC == 0)) {
            Audio_QueueSequenceId(0x248);
            D_800783C0 = 1;
            D_800783C8 = 0x3E8;
        } else if ((D_800783C8 >= 0x641) && (D_800783C0 == 1)) {
            Audio_QueueSequenceId(0x249);
            if (D_800783C4 == 0) {
                Audio_PlayCommand(0x5B, D_80078400, 0);
                D_800783C4 = 1;
            }
            D_800783C0 = 2;
        } else if ((D_800783C8 >= 0x899) && (D_800783C0 == 2)) {
            Audio_QueueSequenceId(0x24A);
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
                        Audio_QueueSoundAvoidingRecent(&D_80077F44);
                    } else {
                        Audio_QueueSoundAvoidingRecent(&D_80077E98);
                    }
                } else if (D_800FCCA4 >= 6) {
                    if ((D_800FCB18[0]->unk_0C > 0) && (D_800FCB18[1]->unk_0C > 0)) {
                        Audio_QueueSoundAvoidingRecent(&D_80077EA4);
                    } else {
                        Audio_QueueSoundAvoidingRecent(&D_80077F60);
                    }
                } else if ((D_800FCB18[0]->unk_0C > 0) && (D_800FCB18[1]->unk_0C > 0)) {
                    Audio_QueueSoundAvoidingRecent(&D_80077EB4);
                } else {
                    Audio_QueueSoundAvoidingRecent(&D_80077F04);
                }
            }
            D_800FCCA8 = D_800FCCA4;
        }
        D_800FCCA2--;
    }
}

/**
 * Everything below is byte-exact against the target except ONE instruction.
 *
 * The target materialises &D_800FCCA1 into a general register
 * (`lui $a0, %hi; addiu $a0, $a0, %lo; sb $zero, 0($a0)`) instead of the
 * `lui $at, %hi; sb $zero, %lo($at)` form IDO uses for every other scalar
 * store in this function. IDO only picks the register form when the address
 * survives CSE, i.e. when the C references that lvalue at least twice --
 * exactly why the neighbouring `D_8007839C[0]`/`D_8007839C[1]` pair keeps its
 * base in $v1 (drop either store and it reverts to the $at form).
 *
 * A read-modify-write whose read IDO folds away late (`D_800FCCA1 *= 0;`,
 * `D_800FCCA1 %= 1;`, `D_800FCCA1 = D_800FCCA1 * 0;`) reproduces the target
 * word-for-word, register-for-register -- but none of those is plausible
 * source, so the real shape of this one statement is still unknown. Things
 * that do NOT produce it: array/struct/union wrappers with a constant index,
 * casts through `s8*`, a local pointer, `static`, `register`, bitfields,
 * `&= 0` / `-= x` / `^= x` (folded too early), and one- or two-trip loops.
 * `volatile` does force a register, but IDO then allocates $t6 and schedules
 * the `addiu` after the two D_8007839C stores, which is not the target.
 * Also ruled out: assignment chains (`D_800FCCA0 = D_800FCCA1 = 0;` etc.
 * materialise $a0 correctly but keep the semantic reload `lb` of the stored
 * byte), duplicate/dead stores (IDO never eliminates the redundant global
 * store), `x - x`, `x ^ x`, `*(&x) = 0`, `(x, 0)`, `x && 0`, constant
 * ternaries, and `x >> 8`. The `*=` form below is therefore landed
 * deliberately: it is the only source family that reaches the target's
 * register-materialised store.
 */
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
    D_800FCCA1 *= 0;
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

void Audio_QueueSequenceId(u32 arg0) {
    OSIntMask mask;

    if ((D_80078388 != 0) && (D_800783FC != 0) && (arg0 != 0)) {
        mask = osSetIntMask(OS_IM_NONE);
        D_800783A4[D_800783B8 & 3] = arg0;
        D_800783B8++;
        osSetIntMask(mask);
    }
}

void Audio_RemoveLastQueuedSequenceId(void) {
    OSIntMask mask;

    if ((D_80078388 != 0) && (D_800783FC != 0)) {
        mask = osSetIntMask(OS_IM_NONE);
        D_800783A4[(D_800783B8 - 1) & 3] = 0;
        osSetIntMask(mask);
    }
}

void Audio_SwapSoundCandidates(u8* arg0, u8* arg1) {
    u8 temp_v0 = *arg0;
    u8 temp_v1 = *arg1;

    if (temp_v1 != temp_v0) {
        *arg0 = temp_v1;
        *arg1 = temp_v0;
    }
}

u16 Audio_FilterRecentSoundId(u16 arg0) {
    s32 i;

    for (i = 0; i < 20; i++) {
        if (arg0 == D_800FCC50[i]) {
            return 0;
        }
    }

    return arg0;
}

void Audio_RecordRecentSoundId(u16 arg0) {
    u16 i;

    for (i = 0; i < 19; i++) {
        D_800FCC50[i] = D_800FCC50[i + 1];
    }

    D_800FCC50[19] = arg0;
}

void Audio_RemoveRecentSoundAt(u16 arg0) {
    u32 i;

    for (i = arg0; i > 0; i--) {
        D_800FCC50[i] = D_800FCC50[i - 1];
    }

    D_800FCC50[0] = 0;
}

u32 Audio_SelectSoundAvoidingRecent(u16* arg0) {
    u16 temp_v0 = *arg0;
    u32 i;
    u32 j;
    u16 sp5A;

    for (i = 0; i < temp_v0; i++) {
        D_800FCD18[i] = i + 1;
    }

    for (i = 0; i < temp_v0 << 1; i++) {
        Audio_SwapSoundCandidates(D_800FCD18, D_800FCD18 + (osGetTime() % (s32)temp_v0));
    }

    for (i = 0; i < temp_v0; i++) {
        sp5A = Audio_FilterRecentSoundId(arg0[D_800FCD18[i]]);
        if (sp5A != 0) {
            Audio_RecordRecentSoundId(sp5A);
            return sp5A;
        }
    }

    for (i = 0; i < 20; i++) {
        for (j = 1; j <= temp_v0; j++) {
            if (D_800FCC50[i] == arg0[j]) {
                Audio_RemoveRecentSoundAt(i);
                Audio_RecordRecentSoundId(arg0[j]);
                return arg0[j];
            }
        }
    }

    return 0;
}

void Audio_QueueSoundAvoidingRecent(u16* arg0) {
    u32 temp_v0 = Audio_SelectSoundAvoidingRecent(arg0);

    if (temp_v0 != 0) {
        Audio_QueueSequenceId(temp_v0);
    }
}

void Audio_QueueSoundWithFallbackList(u16 arg0, u16* arg1, u8* arg2) {
    u8 temp_v0;

    if (*arg2 == 0) {
        Audio_QueueSequenceId(arg0);
    } else {
        Audio_QueueSoundAvoidingRecent(arg1);
    }
    temp_v0 = *arg2;
    if (temp_v0 < 0xFF) {
        *arg2 = temp_v0 + 1;
    }
}

void func_800420F0_empty() {
    
}

// Estimates the damage `moveId` would do from `attacker` to `defender`, for picking
// commentary lines. Returns a small negative code for moves that are classified rather
// than scored (see the effect switch below), otherwise a damage estimate capped at 0x7FFF.
u32 Battle_EstimateMoveDamage(u32 moveId, BattleMonRuntime* attacker, BattleMonRuntime* defender) {
    f32 var_f0;  // defense stat, then the STAB multiplier, then the defender's status multiplier
    f32 var_f2;  // attack stat, then the attacker's hp reference
    f32 var_f12; // multiplier for the defender's first type, then the attacker's boost
    f32 baseDamage;
    f32 scaledDamage;
    f32 pad58;
    f32 defenderHp;
    u8* moveEntry;
    u8* pad4C;
    f32 attackerHp;
    f32 defType1Mult;
    s32 pad44[2];
    u8 defType0Idx;
    u8 defType1Idx;
    u8 moveTypeIdx;
    u8 power;
    u8 effect;
    u8 effectiveness;
    f32 defenderHpBase;
    f32 defenderBoost;
    u32 result;
    s32 side;

    if ((moveId == 0) || (moveId >= 0xA6)) {
        moveId = 1;
    }

    if (attacker == D_800FCB18[0]) {
        side = 0;
    } else if (attacker == D_800FCB18[1]) {
        side = 1;
    } else {
        return 0;
    }
    moveEntry = &D_800780B4[(moveId * 3) - 3];

    moveTypeIdx = Battle_MapCategoryIdToCompactIndex(moveEntry[2]);
    effect = moveEntry[0];
    power = moveEntry[1];

    switch (effect) {
        case 0x26:
            return -1;

        case 0x28:
            return defender->unk_28 / 2;

        case 0x29:
            switch (moveId) {
                case 0x31:
                    return 0x14;
                case 0x45:
                    return attacker->unk_26;
                case 0x52:
                    return 0x28;
                case 0x65:
                    return attacker->unk_26;
                case 0x95:
                    return ((f32)attacker->unk_26 * 1.5f);
                default:
                    return 0;
            }
        case 0x7:
            return -3;
        case 0x9:
        case 0xA:
        case 0xB:
        case 0xD:
        case 0xF:
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x2E:
        case 0x2F:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x38:
        case 0x39:
        case 0x40:
        case 0x41:
        case 0x4F:
        case 0x52:
        case 0x53:
        case 0x55:
            return -5;
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x16:
        case 0x20:
        case 0x31:
        case 0x3B:
        case 0x42:
        case 0x43:
        case 0x54:
        case 0x56:
            return -4;
        case 0x1C:
            if (moveId == 100) {
                return -5;
            }
            return -4;
        default:
            break;
    }

    if (moveId == 68) {
        return -2;
    }

    if (attacker->unk_2A != 0) {
        var_f2 = attacker->unk_2A;
    } else {
        var_f2 = 1.0f;
    }

    if (defender->unk_2C != 0) {
        var_f0 = defender->unk_2C;
    } else {
        var_f0 = 1.0f;
    }

    baseDamage = ((((f32)(((attacker->unk_26 * 2) / 5) + 2) * (f32)power) * var_f2) / var_f0) / 50.0f;

    defType0Idx = Battle_MapCategoryIdToCompactIndex(defender->unk_16[6]);
    defType1Idx = Battle_MapCategoryIdToCompactIndex(defender->unk_16[7]);

    effectiveness = D_800782A4[(moveTypeIdx * 0xF) + defType0Idx];
    switch (effectiveness) {
        case 1:
            var_f12 = 0.0f;
            break;
        case 2:
            var_f12 = 0.5f;
            break;
        case 3:
            var_f12 = 2.0f;
            break;
        default:
            var_f12 = 1.0f;
    }

    effectiveness = D_800782A4[(moveTypeIdx * 0xF) + defType1Idx];
    switch (effectiveness) {
        case 1:
            defType1Mult = 0.0f;
            break;
        case 2:
            defType1Mult = 0.5f;
            break;
        case 3:
            defType1Mult = 2.0f;
            break;
        default:
            defType1Mult = 1.0f;
    }

    if ((attacker->unk_16[6] == moveEntry[2]) || (attacker->unk_16[7] == moveEntry[2])) {
        var_f0 = 1.5f;
    } else {
        var_f0 = 1.0f;
    }

    scaledDamage = baseDamage * var_f12 * defType1Mult * var_f0;

    defenderHpBase = D_800FCB48[side ^ 1].unk_00[D_800FCB48[side ^ 1].unk_24 & 0xF];
    if (defenderHpBase == 0.f) {
        defenderHpBase = 1.f;
    }
    defenderHp = defender->unk_28;

    if (D_80078390[side ^ 1] == 1) {
        defenderBoost = 1.1f;
    } else {
        defenderBoost = 1.0f;
    }

    var_f2 = D_800FCB48[side].unk_00[D_800FCB48[side].unk_24 & 0xF];
    if (var_f2 == 0.0f) {
        var_f2 = 1.f;
    }

    attackerHp = attacker->unk_28;
    if (D_80078390[side] == 1) {
        var_f12 = 1.1f;
    } else {
        var_f12 = 1.0f;
    }

    if (defender->unk_15 & 0x20) {
        var_f0 = 1.2f;
    } else if (defender->unk_15 & 7) {
        var_f0 = 1.10f;
    } else {
        var_f0 = 1.0f;
    }

    result = ((((defenderHp / defenderHpBase) * 0.01f) + 1.f) * scaledDamage * (1.f + ((attackerHp / var_f2) * 0.01f)) * defenderBoost * var_f12 * var_f0);

    result = (result >= 0x8000) ? 0x7FFF : result;

    return result;
}

s32 Battle_MapCategoryIdToCompactIndex(u8 arg0) {
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

void Audio_QueueSequenceIdWrapper(u32 arg0) {
    Audio_QueueSequenceId(arg0);
}
