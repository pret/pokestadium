#include "18480.h"
#include "src/11BA0.h"
#include "src/E890.h"
#include "src/util.h"

typedef void (*func_D_8006F2B0)(void);

extern MemoryBlock* D_800ABD30;
extern unk_D_86002F34* D_800ABD34;
extern s32 D_800ABD38[];
extern s32 D_800ABD78;
extern s16 D_800ABDF8;
extern s16 D_800ABDFA;
extern s16 D_800ABDFE;
extern u8* D_800ABE00;

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017880.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017914.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_8001799C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_800179C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017A1C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017A54.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017A98.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017AC4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017B28.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017B60.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017BBC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017BFC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017C48.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017D94.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017DE0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017E2C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017E78.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017EC4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017F1C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017F5C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017F64.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80017FD4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_800180BC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_800180D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_8001812C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_8001819C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_800181FC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_8001824C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_8001829C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_800183C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80018490.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_800185A8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80018600.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_8001878C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_800188C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80018968.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_800189B8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80018A40.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80018A8C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18480/func_80018AD0.s")

unk_D_86002F34* func_80018B70(MemoryBlock* arg0, void* arg1) {
    extern func_D_8006F2B0 D_8006F2B0[];

    D_800ABD34 = NULL;
    D_800ABDF8 = 0;
    D_800ABDFA = 2;
    D_800ABDFE = 2;
    D_800ABE00 = Util_ConvertAddrToVirtAddr(arg1);
    D_800ABD30 = arg0;
    D_800ABD78 = 0;
    D_800ABD38[0] = 0;
    D_800ABD38[1] = 0;

    while (D_800ABE00 != 0) {
        D_8006F2B0[*D_800ABE00]();
    }

    return D_800ABD34;
}
