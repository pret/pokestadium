#include "common.h"

typedef struct {
    /* 0x00 */ char unk_00[0x16];
    /* 0x16 */ s16 unk_16;
} struct_800429B0;

void func_800429B0(struct_800429B0* arg0, s16 arg1) {
    arg0->unk_16 = arg1;
}
