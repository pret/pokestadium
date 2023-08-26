#ifndef _RSP_H_
#define _RSP_H_

struct UnkStruct800006C4_2 {
    char unk0;
    char filler1[0x1B];
    s32 unk1C;
    void* vaddr;
    s32 size;
    s32 unk28;
};

struct UnkStruct80000A80 {
    LEOCmd cmd;
    union {
        u32 lba;
        struct {
            char filler0[0x3];
            LEOSpdlMode mode;
        };
    };
    void *addr;
};

struct UnkStruct80083BD0 {
    OSMesg unk0;
    u8 unk4[0x18];
    OSMesgQueue queue1;
    OSMesgQueue queue2;
};

s32 func_800005C0(void);
OSPiHandle *func_80000628(void);
s32 func_800006C4(struct UnkStruct800006C4_2* arg0);
s32 func_8000074C(struct UnkStruct800006C4_2* arg0);
s32 func_800007D4(struct UnkStruct800006C4_2* arg0, s32 arg1);
s32 func_8000087C(struct UnkStruct800006C4_2* arg0);
s32 func_80000904(struct UnkStruct800006C4_2* arg0);
s32 func_80000974(struct UnkStruct800006C4_2* arg0);
void *func_800009C8(void);
void *func_800009F8(struct UnkStruct800006C4_2* arg0);
void *func_80000A3C(struct UnkStruct800006C4_2* arg0);
void *func_80000A80(struct UnkStruct80000A80* arg0);
void *func_80000AB0(struct UnkStruct80000A80* arg0);
void *func_80000AE0(struct UnkStruct80000A80* arg0);
void *func_80000B10(struct UnkStruct80000A80* arg0);
void *func_80000B74(struct UnkStruct80000A80* arg0);
void thread20_rsp(void *arg);
void rsp_init(void);
void func_80000DF4(void);
void func_80000E2C(void* arg0, s32 arg1);

#endif // _RSP_H_
