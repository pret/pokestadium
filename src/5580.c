#include "5580.h"
#include "src/29BA0.h"
#include "src/DDC0.h"
#include "src/profiler.h"

void func_80004980(UnkStruct80001380* arg0) {
    osWritebackDCacheAll();
    arg0->unk_1C = 0;
    arg0->unk_1E = 0;
}

void func_800049AC(UnkStruct80001380* arg0) {
    void* sp1C;

    osRecvMesg(&arg0->queue, &sp1C, 1);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_800049D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80004AB4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80004B0C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80004C68.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80004CC0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80004CF4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80004D20.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80004D64.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80004DB4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80004DBC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80004E60.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80004E94.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80004ED0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80004F08.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80004F70.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80005084.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80005148.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80005194.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_800052B4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/5580/func_80005328.s")

void func_80005370(UnkStruct800AA660* arg0) {
    UnkStruct800AA660** var_v0 = &D_800A62E0.unk_A10;
    UnkStruct800AA660* var_v1 = D_800A62E0.unk_A10;

    while (var_v1 != NULL) {
        if (var_v1 == arg0) {
            *var_v0 = var_v1->unk_01D8;
            break;
        }
        var_v0 = &var_v1->unk_01D8;
        var_v1 = var_v1->unk_01D8;
    }
}

void func_800053B4(UnkStruct80001380* arg0, s32 arg1) {
    if (arg0 != NULL) {
        func_80004980(arg0);

        switch (arg0->task.t.type) {
            case 2:
                D_800A62E0.unk_A20 = arg0;
                break;

            case 1:
                if ((arg1 != 0) && (D_800A62E0.unk_A1C == NULL)) {
                    D_800A62E0.unk_A1C = arg0;
                    D_800A62E0.unk_A24 = NULL;
                    osSendMesg(&D_800A62E0.queue, 0x67, 0);
                } else {
                    D_800A62E0.unk_A24 = arg0;
                }
                break;

            case 4:
                if (D_800A62E0.unk_A1C == NULL) {
                    D_800A62E0.unk_A1C = arg0;
                    D_800A62E0.unk_A24 = NULL;
                    osSendMesg(&D_800A62E0.queue, 0x67, 0);
                }
                break;
        }
    }
}
