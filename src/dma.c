#include "global.h"
#include "dma.h"
#include "rsp.h"

extern s16 D_80083C1C;

s32 func_80000E80(s32 arg0, void* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    struct UnkStruct80000E80* temp_v0;

    temp_v0 = Util_Malloc(0x2C);
    if (temp_v0 != NULL) {
        if (arg0 == 0) {
            temp_v0->unk0 = 0xF0;
        } else {
            temp_v0->unk0 = 0xF1;
        }
        temp_v0->unk1C = arg2;
        temp_v0->unk24 = arg3;
        temp_v0->unk20 = arg1;
        temp_v0->unk28 = arg4;
        func_80000E2C(temp_v0, arg5);
    }
    return temp_v0 == NULL;
}

s32 func_80000F0C(s32 arg0, void* arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct UnkStruct80000E80* temp_v0;

    temp_v0 = Util_Malloc(0x2C);
    if (temp_v0 != NULL) {
        temp_v0->unk0 = 0xF4;
        temp_v0->unk1C = (uintptr_t)arg1;
        temp_v0->unk24 = arg2;
        temp_v0->unk20 = (void*)(uintptr_t)arg0;
        temp_v0->unk28 = arg3;
        func_80000E2C(temp_v0, arg4);
    }
    return temp_v0 == NULL;
}

s32 func_80000F80(s32 arg0, void* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    struct UnkStruct80000E80* temp_v0;

    temp_v0 = Util_Malloc(0x2C);
    if (temp_v0 != NULL) {
        if (arg0 == 0) {
            temp_v0->unk0 = 0xF2;
        } else {
            temp_v0->unk0 = 0xF3;
        }
        temp_v0->unk1C = arg2;
        temp_v0->unk24 = arg3;
        temp_v0->unk20 = arg1;
        temp_v0->unk28 = arg4;
        func_80000E2C(temp_v0, arg5);
    }
    return temp_v0 == NULL;
}

s32 func_8000100C(s32 arg0, void* arg1, s16 arg2, s32 arg3, s32 arg4) {
    struct UnkStruct80000E80* temp_v0;

    temp_v0 = Util_Malloc(0x2C);
    if (temp_v0 != NULL) {
        if (arg0 == 0) {
            temp_v0->unk0 = 0xF5;
        } else {
            temp_v0->unk0 = 0xF6;
        }
        temp_v0->unk1C = arg2;
        temp_v0->unk24 = 1;
        temp_v0->unk20 = arg1;
        temp_v0->unk28 = arg3;
        func_80000E2C(temp_v0, arg4);
    }
    return temp_v0 == NULL;
}

s32 func_80001098(s32 arg0, void* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    struct UnkStruct80000E80* temp_v0;

    temp_v0 = Util_Malloc(0x2C);
    if (temp_v0 != NULL) {
        if (arg0 == 0) {
            temp_v0->unk0 = 5;
        } else {
            temp_v0->unk0 = 6;
        }
        temp_v0->unk1C = arg2;
        temp_v0->unk24 = arg3;
        temp_v0->unk20 = arg1;
        temp_v0->unk28 = arg4;
        func_80000E2C(temp_v0, arg5);
    }
    return temp_v0 == NULL;
}

s32 func_80001124(s32 arg0, s32 arg1) {
    struct UnkStruct80000E80* temp_v0;

    temp_v0 = Util_Malloc(0x2C);
    if (temp_v0 != NULL) {
        temp_v0->unk0 = 0xC;
        temp_v0->unk20 = &D_800818E0;
        temp_v0->unk28 = arg0;
        func_80000E2C(temp_v0, arg1);
    }
    return temp_v0 == NULL;
}

s32 func_80001184(s32 arg0, s32 arg1, s32 arg2) {
    struct UnkStruct80000E80* temp_v0;

    temp_v0 = Util_Malloc(0x2C);
    if (temp_v0 != NULL) {
        temp_v0->unk0 = 7;
        temp_v0->unk1C = arg0;
        temp_v0->unk28 = arg1;
        func_80000E2C(temp_v0, arg2);
    }
    return temp_v0 == NULL;
}

s32 func_800011E4(s32 arg0, s32 arg1) {
    struct UnkStruct80000E80* temp_v0;

    temp_v0 = Util_Malloc(0x2C);
    if (temp_v0 != NULL) {
        temp_v0->unk0 = 8;
        temp_v0->unk1C = 0;
        temp_v0->unk28 = arg0;
        func_80000E2C(temp_v0, arg1);
    }
    return temp_v0 == NULL;
}

s32 func_8000123C(s32 arg0, s32 arg1) {
    struct UnkStruct80000E80* temp_v0;

    temp_v0 = Util_Malloc(0x2C);
    if (temp_v0 != NULL) {
        temp_v0->unk0 = 8;
        temp_v0->unk1C = 4;
        temp_v0->unk28 = arg0;
        func_80000E2C(temp_v0, arg1);
    }
    return temp_v0 == NULL;
}

s32 func_80001298(void* arg0, s32 arg1, s32 arg2) {
    struct UnkStruct80000E80* temp_v0;

    temp_v0 = Util_Malloc(0x2C);
    if (temp_v0 != NULL) {
        temp_v0->unk0 = 0xE;
        temp_v0->unk20 = arg0;
        temp_v0->unk28 = arg1;
        func_80000E2C(temp_v0, arg2);
    }
    return temp_v0 == NULL;
}

s16 func_800012F8(void) {
    return D_80083C1C;
}

s32 func_80001304(void* arg0, s32 arg1, s32 arg2) {
    struct UnkStruct80000E80* temp_v0;

    temp_v0 = Util_Malloc(0x2C);
    if (temp_v0 != NULL) {
        temp_v0->unk0 = 0xD;
        temp_v0->unk20 = arg0;
        temp_v0->unk28 = arg1;
        func_80000E2C(temp_v0, arg2);
    }
    return temp_v0 == NULL;
}
