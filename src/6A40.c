#include "global.h"
#include "6A40.h"

struct UnkStruct800A7428 {
    u32* unk0;
    u32* unk4;
    u32 unk8;
    s32 unkC;
    s16 unk10;
};

extern struct UnkStruct800A7428 D_800A7428;

void func_80005EDC(void);

void func_80005E40(u32 arg0, s32 arg1) {
    D_800A7428.unk10 = 0;
    D_800A7428.unkC = arg0;
    D_800A7428.unk0 = main_pool_alloc_with_func(arg0, arg1, 'DYN0', NULL);
    D_800A7428.unk4 = main_pool_alloc_with_func(arg0, arg1, 'DYN1', NULL);
    func_80005EDC();
}

void func_80005EAC(void) {
    main_pool_try_free(D_800A7428.unk4);
    main_pool_try_free(D_800A7428.unk0);
}

void func_80005EDC(void) {
    s32* temp_v0 = (s32*)&D_800A7428;

    D_800A7428.unk10 ^= 1;
    temp_v0 += D_800A7428.unk10;

    D_800A7428.unk8 = *temp_v0 + D_800A7428.unkC;
    gDisplayListHead = *temp_v0;
}

void func_80005F1C(Gfx** arg0, Gfx** arg1) {
    s32* ptr = (s32*)&D_800A7428;
    *arg1 = (Gfx*)((uintptr_t)gDisplayListHead - ptr[D_800A7428.unk10]);
    *arg0 = (Gfx*)(ptr[D_800A7428.unk10]);
}

void* func_80005F5C(s32 arg0) {
    u32 temp_v0;
    u32 ret;

    arg0 = ALIGN8(arg0);
    temp_v0 = (D_800A7428.unk8 - arg0);
    ret = NULL;
    if (temp_v0 >= (uintptr_t)gDisplayListHead) {
        D_800A7428.unk8 = temp_v0;
        ret = temp_v0;
    }
    return ret;
}

s32 func_80005F9C(void) {
    return D_800A7428.unk8 - (uintptr_t)gDisplayListHead;
}
