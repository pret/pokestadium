#include "50A00.h"
#include "src/38BB0.h"
#include "src/4B940.h"
#include "src/51740.h"
#include "src/50860.h"
#include "src/373A0.h"

s32 func_8004FE00(u8* arg0) {
    UNUSED s32 pad[2];
    u8* sp1C;

    func_8004FCD8(1);
    D_800FF9C0 = arg0;
    sp1C = D_800FF9C0 + 0x4120;

    if (1) {}

    func_8004ADB0(D_800FC6E4->offset1, D_800FC6DC, D_800FC6E4->wave_tables_offset - D_800FC6E4->offset1);
    func_80050B40(D_800FC6DC, D_800FF9C0, 0x4120);
    func_8004ADB0(D_800FC6E4->wave_tables_offset, sp1C, D_800FC6E4->files[0] - D_800FC6E4->wave_tables_offset);
    func_8003979C(D_800FF9C0, sp1C);
    D_800FC820 |= 0x80000000;
    func_8004ADB0(D_800FC6E4->files[0], D_800FC6DC, D_800FC6E4->files[1] - D_800FC6E4->files[0]);
    func_80050B40(D_800FC6DC, D_800FC680, 0x98D8);
    D_80078E70 = func_80038F30(D_800FF9C0, D_800FC680);
    func_800393DC(D_80078E70, 0x70);

    return D_80078E70;
}

void func_8004FF20(void) {
    D_800FC820 &= ~0x80000000;
}
