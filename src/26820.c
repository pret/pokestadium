#include "26820.h"
#include "src/26820.h"
#include "src/22630.h"
#include "src/3FB0.h"
#include "src/memory.h"

static s16 D_800AE4E0;
static unk_D_800AE4E8 D_800AE4E8[4];

void func_80025C20(UNUSED MainPoolBlock* arg0, u32 arg1) {
    u32 bank_num = arg1 - 'BNK0';
    unk_D_800AE4E8* temp_v0 = &D_800AE4E8[bank_num];

    if ((arg1 >= 'BNK0') && (arg1 < 'BNK4')) {
        temp_v0->unk_00 &= ~3;
        temp_v0->unk_04.unk1 = NULL;
        temp_v0->unk_08.unk1 = NULL;
    }
}

u16 func_80025C80(u8* arg0, s32 arg1) {
    u16 var_v1 = 0;

    while (arg1-- > 2) {
        var_v1 += *arg0++;
    }
    return var_v1;
}

s32 func_80025CBC(u8* arg0, s32 arg1) {
    u16* temp_v1 = arg1 + arg0;

    temp_v1 -= 3;

    if (temp_v1[0] != 'PO') {
        return 0;
    }

    if (temp_v1[1] != 'KE') {
        return 0;
    }

    if (temp_v1[2] != func_80025C80(arg0, arg1)) {
        return 0;
    }

    return 1;
}

void func_80025D30(u8* arg0, s32 arg1, s32 arg2) {
    u16* temp_v1;

    if (arg2 != 0) {
        temp_v1 = arg1 + arg0;

        temp_v1 -= 3;
        *temp_v1++ = 'PO';
        *temp_v1++ = 'KE';
        *temp_v1++ = func_80025C80(arg0, arg1);
    } else {
        temp_v1 = arg1 + arg0;
        temp_v1 -= 3;

        *temp_v1++ = 'XX';
        *temp_v1++ = 'XX';
        *temp_v1++ = func_80025C80(arg0, arg1) ^ 0xFF;
    }
}

void func_80025DA0(u8* arg0, u8* arg1, s32 arg2, s32 arg3) {
    _bcopy(arg0, arg1, arg2);
    D_800AE4E8[arg3].unk_00 |= 2;
}

void func_80025DE4(u8* arg0, s32 arg1, s32 arg2) {
    if (*arg0 & 2) {
        *arg0 &= ~2;
        func_80025D30(arg0, arg1, 1);
        D_800AE4E8[arg2].unk_00 |= 2;
    }
}

void func_80025E44(u8* arg0, s32 arg1, s32 arg2) {
    if (*arg0 & 2) {
        func_80025D30(arg0, arg1, 0);
        D_800AE4E8[arg2].unk_00 |= 2;
    }
}

void func_80025EA0(u8* arg0, s32 arg1, s32 arg2) {
    u32 tmp = arg0 - (u8*)D_800AE4E8[arg2].unk_04.unk1;

    _bcopy(tmp + (u8*)D_800AE4E8[arg2].unk_08.unk1, arg0, arg1);
}

void func_80025EF8(u8* arg0, s32 arg1, s32 arg2) {
    bzero(arg0, arg1);
    *arg0 |= 2;
    D_800AE4E8[arg2].unk_00 |= 2;
}

void func_80025F50(s32 arg0, s32 arg1) {
    s32 sp34;
    s32 sp30;
    UNUSED s32 pad;
    s32 idx2;
    u8* sp24;
    u8* sp20;

    switch (arg0) {
        case 16:
            sp30 = D_800AE4E0 / 4;
            idx2 = D_800AE4E0 % 4;
            sp34 = 0x160;
            sp24 = (u8*)&D_800AE4E8[sp30].unk_04.unk1->unk_0000[idx2][arg1];
            sp20 = (u8*)&D_800AE4E8[sp30].unk_08.unk1->unk_0000[idx2][arg1];
            break;

        case 17:
            sp30 = 3;
            sp34 = 0x468;
            sp24 = (u8*)&D_800AE4E8[3].unk_04.unk3->unk_0000[arg1];
            sp20 = (u8*)&D_800AE4E8[3].unk_08.unk3->unk_0000[arg1];
            break;

        case 18:
            sp30 = 3;
            sp34 = 0xE0;
            sp24 = (u8*)&D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1];
            sp20 = (u8*)&D_800AE4E8[3].unk_08.unk3->unk_34E0[arg1];
            break;

        case 19:
            sp30 = 2;
            sp34 = 0xF60;
            sp24 = (u8*)&D_800AE4E8[2].unk_04.unk2->unk_0DC0;
            sp20 = (u8*)&D_800AE4E8[2].unk_08.unk2->unk_0DC0;
            break;

        case 20:
            sp30 = 2;
            sp34 = 0x28;
            sp24 = (u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EA0;
            sp20 = (u8*)&D_800AE4E8[2].unk_08.unk2->unk_1EA0;
            break;

        case 21:
            sp30 = 2;
            sp34 = 0x180;
            sp24 = (u8*)&D_800AE4E8[2].unk_04.unk2->unk_1D20;
            sp20 = (u8*)&D_800AE4E8[2].unk_08.unk2->unk_1D20;
            break;

        case 22:
            sp30 = 2;
            sp34 = 0x13B8;
            sp24 = (u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EC8;
            sp20 = (u8*)&D_800AE4E8[2].unk_08.unk2->unk_1EC8;
            break;

        case 23:
            sp30 = 2;
            sp34 = 0xB84;
            sp24 = (u8*)&D_800AE4E8[2].unk_04.unk2->unk_3280;
            sp20 = (u8*)&D_800AE4E8[2].unk_08.unk2->unk_3280;
            break;
    }

    switch ((func_80025CBC(sp24, sp34) | func_80025CBC(sp20, sp34) << 1)) {
        case 0:
            func_8002707C(arg0, arg1);
            break;

        case 1:
            func_80025DA0(sp24, sp20, sp34, sp30);
            break;

        case 2:
            func_80025DA0(sp20, sp24, sp34, sp30);
            break;
    }
}

void func_80026268(unk_func_80026268_arg0* arg0, unk_D_800AE4E8_004_1_000_010* arg1) {
    func_80021D9C(arg0, arg1);
    func_80022338(arg0);

    arg0->unk_52 = 0;
    arg0->unk_53 = 0;
    arg0->unk_25 = 0;

    _bcopy(arg1->unk_2C, arg0->unk_46, 0xB);
    func_80021C40(arg0->unk_30, arg1->unk_21);
    func_80021C40(arg0->unk_3B, arg1->unk_2C);
}

void func_800262DC(unk_func_80026268_arg0* arg0, unk_D_800AE4E8_004_1_000_010* arg1) {
    arg0->unk_04 = arg0->unk_24;

    func_80021F04(arg0, &arg1->unk_00);
    func_80021B7C(arg1->unk_21, arg0->unk_30);

    _bcopy(arg0->unk_46, arg1->unk_2C, 0xB);
}

s32 func_80026338(s32 arg0, s32 arg1, s16 arg2) {
    s32 var_v1 = 0;
    s16 idx1 = D_800AE4E0 / 4;
    s16 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            var_v1 = (D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_000.unk_00 & arg2) != 0;
            break;

        case 17:
            var_v1 = (D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_000.unk_00 & arg2) != 0;
            break;

        case 18:
            var_v1 = (D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_00.unk_00 & arg2) != 0;
            break;

        case 19:
            var_v1 = (D_800AE4E8[2].unk_04.unk2->unk_0DC0.unk_000 & arg2) != 0;
            break;

        case 20:
            var_v1 = (D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_00 & arg2) != 0;
            break;

        case 21:
            var_v1 = (D_800AE4E8[2].unk_04.unk2->unk_1D20.unk_000 & arg2) != 0;
            break;

        case 22:
            var_v1 = (D_800AE4E8[2].unk_04.unk2->unk_1EC8.unk_0000 & arg2) != 0;
            break;

        case 23:
            var_v1 = (D_800AE4E8[2].unk_04.unk2->unk_3280.unk_0000 & arg2) != 0;
            break;
    }

    return var_v1;
}

void func_800264DC(s32 arg0, s32 arg1, s16 arg2) {
    s16 idx1 = D_800AE4E0 / 4;
    s16 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_000.unk_00 |= arg2;
            break;

        case 17:
            D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_000.unk_00 |= arg2;
            break;

        case 18:
            D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_00.unk_00 |= arg2;
            break;

        case 19:
            D_800AE4E8[2].unk_04.unk2->unk_0DC0.unk_000 |= arg2;
            break;

        case 20:
            D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_00 |= arg2;
            break;

        case 21:
            D_800AE4E8[2].unk_04.unk2->unk_1D20.unk_000 |= arg2;
            break;

        case 22:
            D_800AE4E8[2].unk_04.unk2->unk_1EC8.unk_0000 |= arg2;
            break;

        case 23:
            D_800AE4E8[2].unk_04.unk2->unk_3280.unk_0000 |= arg2;
            break;
    }
}

void func_8002667C(void) {
}

void func_80026684(s32 arg0, s32 arg1) {
    s16 idx1 = D_800AE4E0 / 4;
    s16 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            func_80025DE4((u8*)&D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1], 0x160, idx1);
            break;

        case 17:
            func_80025DE4((u8*)&D_800AE4E8[3].unk_04.unk3->unk_0000[arg1], 0x468, 3);
            break;

        case 18:
            func_80025DE4((u8*)&D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1], 0xE0, 3);
            break;

        case 19:
            func_80025DE4((u8*)&D_800AE4E8[2].unk_04.unk2->unk_0DC0, 0xF60, 2);
            break;

        case 20:
            func_80025DE4((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EA0, 0x28, 2);
            break;

        case 21:
            func_80025DE4((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1D20, 0x180, 2);
            break;

        case 22:
            func_80025DE4((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EC8, 0x13B8, 2);
            break;

        case 23:
            func_80025DE4((u8*)&D_800AE4E8[2].unk_04.unk2->unk_3280, 0xB84, 2);
            break;
    }
}

void func_8002685C(s32 arg0, s32 arg1) {
    s16 idx1 = D_800AE4E0 / 4;
    s16 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            func_80025E44((u8*)&D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1], 0x160, idx1);
            break;

        case 17:
            func_80025E44((u8*)&D_800AE4E8[3].unk_04.unk3->unk_0000[arg1], 0x468, 3);
            break;

        case 18:
            func_80025E44((u8*)&D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1], 0xE0, 3);
            break;

        case 19:
            func_80025E44((u8*)&D_800AE4E8[2].unk_04.unk2->unk_0DC0, 0xF60, 2);
            break;

        case 20:
            func_80025E44((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EA0, 0x28, 2);
            break;

        case 21:
            func_80025E44((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1D20, 0x180, 2);
            break;

        case 22:
            func_80025E44((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EC8, 0x13B8, 2);
            break;

        case 23:
            func_80025E44((u8*)&D_800AE4E8[2].unk_04.unk2->unk_3280, 0xB84, 2);
            break;
    }
}

void func_80026A34(s32 arg0, s32 arg1) {
    s16 idx1 = D_800AE4E0 / 4;
    s16 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            func_80025EA0((u8*)&D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1], 0x160, idx1);
            break;

        case 17:
            func_80025EA0((u8*)&D_800AE4E8[3].unk_04.unk3->unk_0000[arg1], 0x468, 3);
            break;

        case 18:
            func_80025EA0((u8*)&D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1], 0xE0, 3);
            break;

        case 19:
            func_80025EA0((u8*)&D_800AE4E8[2].unk_04.unk2->unk_0DC0, 0xF60, 2);
            break;

        case 20:
            func_80025EA0((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EA0, 0x28, 2);
            break;

        case 21:
            func_80025EA0((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1D20, 0x180, 2);
            break;

        case 22:
            func_80025EA0((u8*)&D_800AE4E8[2].unk_04.unk2->unk_1EC8, 0x13B8, 2);
            break;

        case 23:
            func_80025EA0((u8*)&D_800AE4E8[2].unk_04.unk2->unk_3280, 0xB84, 2);
            break;
    }
}

void func_80026C0C(s32 arg0, s32 arg1) {
    UNUSED s32 pad;
    unk_D_800AE4E8_004_1_000* sp38;
    unk_D_800AE4E8_004_3_0000* sp34;
    unk_D_800AE4E8_004_3_34E0* sp30;
    unk_D_800AE4E8_004_2_0DC0* sp2C;
    unk_D_800AE4E8_004_2_1EA0* sp28;
    unk_D_800AE4E8_004_2_1D20* sp24;
    unk_D_800AE4E8_004_2_1EC8* sp20;
    unk_D_800AE4E8_004_2_3280* sp1C;
    s16 idx1 = D_800AE4E0 / 4;
    s16 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            sp38 = &D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1];
            func_80025EF8(sp38, 0x160, idx1);
            sp38->unk_000.unk_01 = 0x50;
            break;

        case 17:
            sp34 = &D_800AE4E8[3].unk_04.unk3->unk_0000[arg1];
            func_80025EF8(sp34, 0x468, 3);
            sp34->unk_000.unk_01 = 0x50;
            break;

        case 18:
            sp30 = &D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1];
            func_80025EF8(sp30, 0xE0, 3);
            sp30->unk_00.unk_01 = 0x50;
            break;

        case 19:
            sp2C = &D_800AE4E8[2].unk_04.unk2->unk_0DC0;
            func_80025EF8(sp2C, 0xF60, 2);
            sp2C->unk_000 |= 1;
            break;

        case 20:
            sp28 = &D_800AE4E8[2].unk_04.unk2->unk_1EA0;
            func_80025EF8(sp28, 0x28, 2);
            sp28->unk_00 |= 1;
            break;

        case 21:
            sp24 = &D_800AE4E8[2].unk_04.unk2->unk_1D20;
            func_80025EF8(sp24, 0x180, 2);
            break;

        case 22:
            sp20 = &D_800AE4E8[2].unk_04.unk2->unk_1EC8;
            func_80025EF8(sp20, 0x13B8, 2);
            sp20->unk_0000 |= 1;
            break;

        case 23:
            sp1C = &D_800AE4E8[2].unk_04.unk2->unk_3280;
            func_80025EF8(sp1C, 0xB84, 2);
            sp1C->unk_0000 |= 1;
            break;
    }
}

void func_80026E4C(s16 arg0) {
    s32 i;
    s32 sp28;

    if (D_800AE4E8[arg0].unk_00 & 1) {
        sp28 = D_800AE4E0;

        switch (arg0) {
            case 0:
                for (D_800AE4E0 = 0; D_800AE4E0 < 4; D_800AE4E0++) {
                    for (i = 0; i < 10; i++) {
                        func_80026684(0x10, i);
                    }
                }
                break;

            case 1:
                for (D_800AE4E0 = 4; D_800AE4E0 < 8; D_800AE4E0++) {
                    for (i = 0; i < 10; i++) {
                        func_80026684(0x10, i);
                    }
                }
                break;

            case 2:
                D_800AE4E0 = 8;

                for (i = 0; i < 10; i++) {
                    func_80026684(0x10, i);
                }

                func_80026684(0x13, 0);
                func_80026684(0x14, 0);
                func_80026684(0x15, 0);
                func_80026684(0x16, 0);
                func_80026684(0x17, 0);
                break;

            case 3:
                for (i = 0; i < 12; i++) {
                    func_80026684(0x11, i);
                }

                for (i = 0; i < 4; i++) {
                    func_80026684(0x12, i);
                }

                break;
        }

        D_800AE4E0 = sp28;
    }
}

void func_80027038(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80026E4C(i);
    }
}

void func_8002707C(s32 arg0, s32 arg1) {
    func_80026C0C(arg0, arg1);
    func_80026684(arg0, arg1);
}

s32 func_800270AC(s32 arg0) {
    s32 var_v1 = 0;

    switch (arg0) {
        case 16:
            var_v1 = 6;
            break;

        case 17:
            var_v1 = 0x14;
            break;

        case 18:
            var_v1 = 0x64;
            break;

        case 19:
            var_v1 = 0x97;
            break;

        case 22:
            var_v1 = 0x24;
            break;

        case 23:
            var_v1 = 0x15;
            break;
    }

    return var_v1;
}

s32 func_80027108(s32 arg0) {
    s32 var_v1 = 0;

    switch (arg0) {
        case 16:
            var_v1 = 0x54;
            break;

        case 17:
            var_v1 = 0x54;
            break;

        case 18:
            var_v1 = 2;
            break;

        case 19:
            var_v1 = 0x1A;
            break;

        case 22:
            var_v1 = 0x8C;
            break;

        case 23:
            var_v1 = 0x8C;
            break;
    }

    return var_v1;
}

s32 func_80027164(s32 arg0, s32 arg1) {
    return func_80026338(arg0, arg1, 1);
}

s32 func_80027184(s32 arg0, s32 arg1) {
    s32 sp1C = -1;

    if (func_80027164(arg0, arg1) != 0) {
        s16 idx1 = D_800AE4E0 / 4;
        s16 idx2 = D_800AE4E0 % 4;

        switch (arg0) {
            case 16:
                sp1C = D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_000.unk_0C;
                break;

            case 17:
                sp1C = D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_000.unk_0C;
                break;

            case 18:
                sp1C = D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_00.unk_0C;
                break;
        }
    }
    return sp1C;
}

char* func_800272BC(s32 arg0, s32 arg1, char* arg2) {
    char* sp1C = NULL;
    char* var_a1;

    *arg2 = '\x00';

    if (func_80027164(arg0, arg1) != 0) {
        s16 idx1 = D_800AE4E0 / 4;
        s16 idx2 = D_800AE4E0 % 4;

        var_a1 = NULL;

        switch (arg0) {
            case 16:
                var_a1 = &D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_000.unk_01;
                break;

            case 17:
                var_a1 = &D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_000.unk_01;
                break;

            case 18:
                var_a1 = &D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_00.unk_01;
                break;
        }

        if (var_a1 != NULL) {
            sp1C = func_80021A90(arg2, var_a1);
        }
    }

    return sp1C;
}

void func_80027410(s32 arg0, s32 arg1, char* arg2) {
    func_800272BC(arg0, arg1, arg2);
}

void func_80027430(s32 arg0, s32 arg1, s32 arg2, char* arg3, u16 arg4) {
    unk_D_800AE4E8_004_1_000* temp_v0;
    unk_D_800AE4E8_004_3_0000* temp_v0_2;
    unk_D_800AE4E8_004_3_34E0* temp_v0_3;
    s16 idx1 = D_800AE4E0 / 4;
    s16 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            temp_v0 = &D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1];
            if (arg4 >= 0) {
                temp_v0->unk_000.unk_0C = arg4;
            }

            if (arg3 != NULL) {
                func_80021B7C(&temp_v0->unk_000.unk_01, arg3);
            }

            func_800264DC(arg0, arg1, 3);
            break;

        case 17:
            temp_v0_2 = &D_800AE4E8[3].unk_04.unk3->unk_0000[arg1];
            if (arg4 >= 0) {
                temp_v0_2->unk_000.unk_0C = arg4;
            }

            if (arg3 != NULL) {
                func_80021B7C(&temp_v0_2->unk_000.unk_01, arg3);
            }

            func_800264DC(arg0, arg1, 3);
            break;

        case 18:
            temp_v0_3 = &D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1];
            if (arg4 >= 0) {
                temp_v0_3->unk_00.unk_0C = arg4;
            }

            if (arg3 != NULL) {
                func_80021B7C(&temp_v0_3->unk_00.unk_01, arg3);
            }

            func_800264DC(arg0, arg1, 3);
            break;
    }
}

s16 func_800275E0(s32 arg0, s32 arg1) {
    s16 var_v1 = 0;
    s32 idx1 = D_800AE4E0 / 4;
    s32 idx2 = D_800AE4E0 % 4;

    switch (arg0) {
        case 16:
            var_v1 = D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_000.unk_0E;
            break;

        case 17:
            var_v1 = D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_000.unk_0E;
            break;

        case 18:
            var_v1 = D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_00.unk_0E;
            break;

        case 19:
            var_v1 = 0x97;
            break;

        case 22:
            var_v1 = 0x24;
            break;

        case 23:
            var_v1 = 0x15;
            break;
    }

    return var_v1;
}

void func_800276F0(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp1C = D_800AE4E0 / 4;
    s32 sp18 = D_800AE4E0 % 4;

    if (arg2 < func_800275E0(arg0, arg1)) {
        switch (arg0) {
            case 16:
                D_800AE4E8[sp1C].unk_04.unk1->unk_0000[sp18][arg1].unk_000.unk_0E = arg2;
                break;

            case 17:
                D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_000.unk_0E = arg2;
                break;

            case 18:
                D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_00.unk_0E = arg2;
                break;
        }

        func_800264DC(arg0, arg1, 2);
    }
}

void func_8002782C(s32 arg0, s32 arg1) {
    s32 idx1;
    s32 idx2;
    s32 sp1C;

    idx1 = D_800AE4E0 / 4;
    idx2 = D_800AE4E0 % 4;

    sp1C = func_800275E0(arg0, arg1);
    if (sp1C < func_800270AC(arg0)) {
        switch (arg0) {
            case 16:
                D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_000.unk_0E = sp1C + 1;
                break;

            case 17:
                D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_000.unk_0E = sp1C + 1;
                break;

            case 18:
                D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_00.unk_0E = sp1C + 1;
                break;
        }
        func_800264DC(arg0, arg1, 2);
    }
}

s32 func_8002797C(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    s32 sp2C = 0;
    s32 idx1 = D_800AE4E0 / 4;
    s32 idx2 = D_800AE4E0 % 4;

    if (arg2 < func_800275E0(arg0, arg1)) {
        switch (arg0) {
            case 16:
                func_80026268(arg3, &D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_010[arg2]);
                break;

            case 17:
                func_80026268(arg3, &D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_010[arg2]);
                break;

            case 18:
                *(unk_D_800AE4E8_004_3_34E0_010*)arg3 = D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_10[arg2];
                break;

            case 19:
                *(unk_D_800AE4E8_004_2_0DC0_002*)arg3 = D_800AE4E8[2].unk_04.unk2->unk_0DC0.unk_002[arg2];
                break;

            case 22:
                _bcopy(&D_800AE4E8[2].unk_04.unk2->unk_1EC8.unk_0002[arg2], arg3,
                       sizeof(unk_D_800AE4E8_004_2_1EC8_0002));
                break;

            case 23:
                _bcopy(&D_800AE4E8[2].unk_04.unk2->unk_3280.unk_0002[arg2], arg3,
                       sizeof(unk_D_800AE4E8_004_2_1EC8_0002));
                break;
        }
        sp2C = 1;
    }

    return sp2C;
}

s32 func_80027C24(s32 arg0, s32 arg1, s32 arg2, void* arg3) {
    s32 sp34 = 0;
    s32 idx1 = D_800AE4E0 / 4;
    s32 idx2 = D_800AE4E0 % 4;
    s32 sp28 = func_800270AC(arg0);
    s32 sp24 = func_800275E0(arg0, arg1);

    if ((arg2 < sp24) || ((arg2 == sp24) && (arg2 < sp28))) {
        switch (arg0) {
            case 16:
                func_800262DC(arg3, &D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1].unk_010[arg2]);
                break;
            case 17:
                func_800262DC(arg3, &D_800AE4E8[3].unk_04.unk3->unk_0000[arg1].unk_010[arg2]);
                break;
            case 18:
                D_800AE4E8[3].unk_04.unk3->unk_34E0[arg1].unk_10[arg2] = *(unk_D_800AE4E8_004_3_34E0_010*)arg3;
                break;
            case 19:
                D_800AE4E8[2].unk_04.unk2->unk_0DC0.unk_002[arg2] = *(unk_D_800AE4E8_004_2_0DC0_002*)arg3;
                break;
            case 22:
                _bcopy(arg3, &D_800AE4E8[2].unk_04.unk2->unk_1EC8.unk_0002[arg2], 0x8C);
                break;
            case 23:
                _bcopy(arg3, &D_800AE4E8[2].unk_04.unk2->unk_3280.unk_0002[arg2], 0x8C);
                break;
        }

        if (arg2 == sp24) {
            func_8002782C(arg0, arg1);
        } else {
            func_800264DC(arg0, arg1, 2);
        }

        sp34 = 1;
    }
    return sp34;
}

void func_80027F24(unk_func_8002A728* arg0) {
    *arg0 = D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_04;
}

void func_80027F40(unk_func_8002A728* arg0) {
    if (bcmp(arg0, &D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_04, 8) != 0) {
        D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_04 = *arg0;
        func_800264DC(0x14, 0, 2);
    }
}

void func_80027FA0(unk_func_80027FA0* arg0, s16 arg1) {
    *arg0 = D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_0C[arg1];
}

void func_80027FE0(unk_func_80027FA0* arg0, s16 arg1) {
    if (bcmp(arg0, &D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_0C[arg1], sizeof(unk_func_80027FA0)) != 0) {
        D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_0C[arg1] = *arg0;
        func_800264DC(0x14, 0, 2);
    }
}

void func_80028070(u16* arg0) {
    *arg0 = D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_02;
}

void func_80028084(u16* arg0) {
    u16 tmp = *arg0;
    unk_D_800AE4E8_004_2* temp_v1 = D_800AE4E8[2].unk_04.unk2;

    if (temp_v1->unk_1EA0.unk_02 != tmp) {
        temp_v1->unk_1EA0.unk_02 = tmp;
        func_800264DC(0x14, 0, 2);
    }
}

s32 func_800280C4(void) {
    return D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_1E;
}

void func_800280D4(u8 arg0) {
    unk_D_800AE4E8_004_2* temp_v0 = D_800AE4E8[2].unk_04.unk2;

    if (temp_v0->unk_1EA0.unk_1E != arg0) {
        temp_v0->unk_1EA0.unk_1E = arg0;
        func_800264DC(0x14, 0, 2);
    }
}

s32 func_80028118(void) {
    return D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_1F;
}

void func_80028128(u8 arg0) {
    unk_D_800AE4E8_004_2* temp_v0 = D_800AE4E8[2].unk_04.unk2;

    if (temp_v0->unk_1EA0.unk_1F != arg0) {
        temp_v0->unk_1EA0.unk_1F = arg0;
        func_800264DC(0x14, 0, 2);
    }
}

s32 func_8002816C(void) {
    return D_800AE4E8[2].unk_04.unk2->unk_1EA0.unk_1C;
}

void func_8002817C(u8 arg0, u8 arg1) {
    s32 temp_v0 = (((arg1 & 1) << 8) | arg0) & 0xFFFF;
    unk_D_800AE4E8_004_2* temp_v1 = D_800AE4E8[2].unk_04.unk2;

    if (temp_v1->unk_1EA0.unk_1C != temp_v0) {
        temp_v1->unk_1EA0.unk_1C = temp_v0;
        func_800264DC(0x14, 0, 2);
    }
}

void func_800281D4(unk_func_800281D4* arg0, unk_func_80026268_arg0* arg1, s32 arg2) {
    unk_D_800AE4E8_004_2_1D20* temp_v0;
    s32 i;

    if (D_800AE4E8[2].unk_00 & 1) {
        temp_v0 = &D_800AE4E8[2].unk_04.unk2->unk_1D20;

        temp_v0->unk_000 |= 3;
        temp_v0->unk_002 = *arg0;
        temp_v0->unk_022 = arg2;

        for (i = 0; i < arg2; i++) {
            func_800262DC(&arg1[i], &temp_v0->unk_024[i]);
            temp_v0->unk_16E[i] = arg1[i].unk_52;
            temp_v0->unk_174[i] = arg1[i].unk_53;
        }
    }
}

s32 func_80028320(unk_func_800281D4* arg0, unk_func_80026268_arg0* arg1) {
    s16 var_s5 = -1;
    unk_D_800AE4E8_004_2_1D20* temp_v0;
    s32 i;

    if (D_800AE4E8[2].unk_00 & 1) {
        temp_v0 = &D_800AE4E8[2].unk_04.unk2->unk_1D20;

        if (temp_v0->unk_000 & 1) {
            *arg0 = temp_v0->unk_002;
            var_s5 = temp_v0->unk_022;
            if (arg1 != NULL) {
                for (i = 0; i < var_s5; i++) {
                    func_80026268(&arg1[i], &temp_v0->unk_024[i]);
                    arg1[i].unk_52 = temp_v0->unk_16E[i];
                    arg1[i].unk_53 = temp_v0->unk_174[i];
                }
            }
        }
    }
    return var_s5;
}

s32 func_8002847C(void) {
    s32 var_v1 = 0;

    if (D_800AE4E8[2].unk_00 & 1) {
        unk_D_800AE4E8_004_2_1D20* temp_v0 = &D_800AE4E8[2].unk_04.unk2->unk_1D20;

        var_v1 = (temp_v0->unk_000 & 1) != 0;
    }
    return var_v1;
}

s32 func_800284B4(s16 arg0) {
    static u32 D_80073650[] = {
        0x3700,
        0x3700,
        0x3F80,
        0x3880,
    };

    s32 sp38;
    s32 var_s0;
    s16 temp_s5;

    temp_s5 = D_80073650[arg0] >> 7;

    if ((D_800AE4E8[arg0].unk_00 & 1) && (D_800AE4E8[arg0].unk_00 & 2)) {
        _bcopy(D_800AE4E8[arg0].unk_04.unk1, D_800AE4E8[arg0].unk_08.unk1, D_80073650[arg0]);
        var_s0 = 0;
        while (func_80003B04(arg0) == -1) {
            var_s0++;
            if (var_s0 == 4) {
                return -1;
            }
        }

        var_s0 = 0;
        sp38 = arg0 << 7;
        while (func_80003A14((u8*)D_800AE4E8[arg0].unk_04.unk1, sp38, temp_s5, 1) == -1) {
            var_s0++;
            if (var_s0 == 4) {
                return -1;
            }
        }

        var_s0 = 0;
        while (func_80003B04(arg0 + 4) == -1) {
            var_s0 += 1;
            if (var_s0 == 4) {
                return -1;
            }
        }

        sp38 = arg0 << 7;
        sp38 += 0x200;
        var_s0 = 0;
        while (func_80003A14((u8*)D_800AE4E8[arg0].unk_08.unk1, sp38, temp_s5, 1) == -1) {
            var_s0++;
            if (var_s0 == 4) {
                return 0;
            }
        }

        D_800AE4E8[arg0].unk_00 &= ~2;
    }

    return 0;
}

s32 func_800286D8(void) {
    s32 i;
    s32 var_s1 = 0;

    for (i = 0; i < 4; i++) {
        if (func_800284B4(i) != 0) {
            var_s1 |= 1 << i;
        }
    }

    return var_s1;
}

s32 func_8002873C(s16 arg0, u32 arg1) {
    s32 sp2C = 0;
    u8* sp28;

    if (D_800AE4E8[arg0].unk_04.unk1 == NULL) {
        sp28 = main_pool_alloc_with_func(arg1 * 2, 0, 'BNK0' + arg0, func_80025C20);
        if (sp28 != NULL) {
            bzero(sp28, arg1 * 2);
            D_800AE4E8[arg0].unk_04.unk1 = sp28;
            D_800AE4E8[arg0].unk_08.unk1 = sp28 + arg1;
            func_80003A14(sp28, arg0 << 7, arg1 >> 7, 0);
            func_80003A14(D_800AE4E8[arg0].unk_08.unk1, (arg0 << 7) + 0x200, arg1 >> 7, 0);
            sp2C = 1;
        }
    }

    return sp2C;
}

void func_80028840(void) {
    s32 j;
    s32 sp28;

    if (func_8002873C(0, 0x3700) != 0) {
        sp28 = D_800AE4E0;

        for (D_800AE4E0 = 0; D_800AE4E0 < 4; D_800AE4E0++) {
            for (j = 0; j < 10; j++) {
                func_80025F50(0x10, j);
            }
        }

        D_800AE4E8->unk_00 |= 1;
        D_800AE4E0 = sp28;
    }
}

void func_800288F4(void) {
    s32 i;
    s32 sp28;

    if (func_8002873C(1, 0x3700) != 0) {
        sp28 = D_800AE4E0;
        D_800AE4E0 = 4;
        while (D_800AE4E0 < 8) {
            for (i = 0; i < 10; i++) {
                func_80025F50(16, i);
            }
            D_800AE4E0++;
        }
        D_800AE4E8[1].unk_00 |= 1;
        D_800AE4E0 = sp28;
    }
}

void func_800289AC(void) {
    s32 i;
    s32 sp20;

    if (func_8002873C(2, 0x3F80) != 0) {
        sp20 = D_800AE4E0;
        D_800AE4E0 = 8;

        for (i = 0; i < 10; i++) {
            func_80025F50(16, i);
        }

        func_80025F50(19, 0);
        func_80025F50(20, 0);
        func_80025F50(21, 0);
        func_80025F50(22, 0);
        func_80025F50(23, 0);

        D_800AE4E8[2].unk_00 |= 1;
        D_800AE4E0 = sp20;
    }
}

void func_80028A74(void) {
    s32 i;

    if (func_8002873C(3, 0x3880) != 0) {
        for (i = 0; i < 12; i++) {
            func_80025F50(17, i);
        }

        for (i = 0; i < 4; i++) {
            func_80025F50(18, i);
        }

        D_800AE4E8[3].unk_00 |= 1;
    }
}

s32 func_80028AFC(s16 arg0) {
    if (!((D_800AE4E8[arg0].unk_00 & 1) != 0)) {
        switch (arg0) {
            case 0:
                func_80028840();
                break;

            case 1:
                func_800288F4();
                break;

            case 2:
                func_800289AC();
                break;

            case 3:
                func_80028A74();
                break;
        }
    }

    return (D_800AE4E8[arg0].unk_00 & 1) != 0;
}

void func_80028BE4(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80028AFC(i);
    }
}

void func_80028C28(void) {
    func_80028AFC(3);
}

s32 func_80028C48(s16 arg0) {
    s32 tmp = D_800AE4E0;

    if ((arg0 >= 0) && (arg0 < 9)) {
        D_800AE4E0 = arg0;
    }
    return tmp;
}

s32 func_80028C7C(unk_D_800AE4E8_004_1_000* arg0, s32 arg1) {
    s32 var_v1 = 0;
    s32 idx1 = D_800AE4E0 / 4;
    s32 idx2 = D_800AE4E0 % 4;

    if ((arg1 >= 0) && (arg1 < 0xA)) {
        *arg0 = D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1];
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_80028D60(unk_D_800AE4E8_004_1_000* arg0, s32 arg1) {
    s32 var_v1 = 0;
    s32 idx1 = D_800AE4E0 / 4;
    s32 idx2 = D_800AE4E0 % 4;

    if ((arg1 >= 0) && (arg1 < 0xA)) {
        D_800AE4E8[idx1].unk_04.unk1->unk_0000[idx2][arg1] = *arg0;
        func_800264DC(0x10, arg1, 2);
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_80028E68(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (func_80027164(0x10, i) == 0) {
            break;
        }
    }

    return i;
}

void func_80028EB8(void) {
    unk_D_800AE4E8_004_1_000 sp40;
    s32 i;
    s32 j;

    for (i = 9; i >= 0; i--) {
        if (func_80027164(0x10, i) != 0) {
            break;
        }
    }

    for (j = i - 1; j >= 0; j--) {
        if (func_80027164(0x10, j) != 0) {
            continue;
        }

        for (i = j; i < 9; i++) {
            if (i && i) {}

            func_80028C7C(&sp40, i + 1);
            func_80028D60(&sp40, i);
            func_80026684(0x10, i);
        }

        func_8002707C(0x10, 9);
    }
}
