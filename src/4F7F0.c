#include "common.h"

struct UnkArray4 {
    u32 unk0;
    u32 unk4;
    u16 unk8;
    u16 unkA;
    f32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
};
struct UnkStructUnk8 {
    char filler[0x88];
    u32 unk88;
};
struct UnkStruct8004EBF0 {
    char filler[0x8];
    struct UnkStructUnk8* unk8;
};
void func_80047500(void*, u8, void*, void*);
struct UnkArray4* func_800495F8();
extern struct UnkArray4* D_80078584; // who did this? fix later

void func_8004EBF0(struct UnkStruct8004EBF0* arg0, f32 arg1) {
    struct UnkArray4* temp_v0;

    if (arg0->unk8 != NULL) {
        temp_v0 = func_800495F8();
        if (temp_v0 != NULL) {
            temp_v0->unk4 = (s32)(D_80078584->unk1C + arg0->unk8->unk88);
            temp_v0->unk8 = 7;
            temp_v0->unkC = arg1;
            temp_v0->unk0 = 0;
            func_80047500(arg0->unk8, 3, temp_v0, arg0);
        }
    }
}
