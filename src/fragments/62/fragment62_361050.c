#include "fragment62.h"
#include "include/math.h"
#include "src/3FB0.h"
#include "src/22630.h"

unk_D_843C5310 D_843C5310[18];
u8 D_843C5550[0x14];
unk_D_843C60F0_00C* D_843C5564;
unk_D_843C5568 D_843C5568[2];
s32 pad_D_843C60A0;
unk_D_843C60A4* D_843C60A4;
unk_D_843C60A4* D_843C60A8;
unk_D_843C60AC* D_843C60AC;
unk_D_843C60AC* D_843C60B0;
unk_D_800FCB18* D_843C60B4;
unk_D_800FCB18* D_843C60B8;
s32 D_843C60BC;
unk_D_843C60C0 D_843C60C0[2];
u8 D_843C60E8;
unk_D_843C60F0 D_843C60F0;
u8 D_843C6138[2];
u16 D_843C613A;
u16 D_843C613C;
u16 D_843C613E;
u16 D_843C6140;
u16 D_843C6142;
u8 D_843C6144;
unk_D_843C6148 D_843C6148;
s32 D_843C6150;
u32 D_843C6154;

s32 D_8438AFB0 = 0;

static u8 D_8438AFB4[] = {
    0x05, 0x0D, 0x0E, 0x12, 0x19, 0x5C, 0x20, 0x22, 0x24, 0x26, 0x3D, 0x37, 0x3A, 0x3B, 0x3F, 0x06, 0x42, 0x44, 0x45,
    0x63, 0x48, 0x4C, 0x52, 0x55, 0x57, 0x59, 0x5A, 0x5B, 0x5E, 0x64, 0x66, 0x68, 0x73, 0x75, 0x76, 0x78, 0x79, 0x7E,
    0x81, 0x82, 0x87, 0x8A, 0x8F, 0x9C, 0x56, 0x95, 0x99, 0x9D, 0xA1, 0xA4, 0x0F, 0x13, 0x39, 0x46, 0x94, 0x00,
};

static u8 D_8438AFEC[] = {
    0x16, 0x49, 0x4F, 0x34, 0x35, 0x7E, 0x37, 0x6E, 0x38, 0x51, 0x6A, 0x4F, 0x28, 0x6A, 0x29, 0x10, 0x12, 0x13, 0x9E,
    0xA2, 0x77, 0x41, 0x23, 0x89, 0x55, 0x57, 0x1C, 0x9A, 0x2D, 0x28, 0x22, 0x1E, 0x20, 0x05, 0x76, 0x2F, 0x27, 0x6D,
    0x2F, 0x66, 0x30, 0x72, 0x47, 0x4E, 0x50, 0x4A, 0x93, 0x8D, 0x3C, 0x5B, 0x59, 0x06, 0x9A, 0x32, 0x38, 0x02, 0x45,
    0x2E, 0x7E, 0x91, 0x37, 0x42, 0x64, 0x86, 0x5E, 0x02, 0x43, 0x19, 0x4A, 0x23, 0x4B, 0x28, 0x5C, 0x6A, 0x58, 0x9D,
    0x34, 0x53, 0x9C, 0x85, 0x31, 0x56, 0x1F, 0x1F, 0xA1, 0x3E, 0x3A, 0x8B, 0x97, 0x80, 0x83, 0x6D, 0x7A, 0x65, 0x14,
    0x8A, 0x60, 0x0B, 0x98, 0x78, 0x99, 0x8C, 0x79, 0x7D, 0x9B, 0x88, 0x04, 0x6F, 0x7B, 0x7C, 0x1E, 0x20, 0x87, 0x84,
    0x92, 0x6C, 0x38, 0x27, 0x7F, 0x37, 0x69, 0x70, 0xA3, 0x8E, 0x09, 0x07, 0x0C, 0x24, 0x96, 0x52, 0x39, 0x90, 0x62,
    0x36, 0x2A, 0x53, 0xA0, 0x6E, 0x83, 0x6A, 0xA3, 0x13, 0x9C, 0x3B, 0x57, 0x8F, 0x23, 0x52, 0x3F, 0x5E, 0x76,
};
static u8 D_8438B084[] = {
    0x00, 0x00, 0x01, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x01, 0x01, 0x00, 0x01, 0x03, 0x02, 0x00, 0x00, 0x01, 0x01,
    0x00, 0x02, 0x01, 0x00, 0x03, 0x02, 0x03, 0x01, 0x03, 0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02,
    0x00, 0x01, 0x01, 0x03, 0x02, 0x02, 0x03, 0x02, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
static u8 D_8438B0BC[] = {
    0x32, 0x75, 0x66, 0x76, 0x82,
};

static u8 D_8438B0C4[] = {
    0x63, 0x68, 0x80, 0x78, 0x14, 0x26, 0x99, 0x64, 0x5C, 0x24, 0x9C, 0x22, 0x3F, 0x53, 0x23, 0xA4, 0x66,
};

static u8 D_8438B0D8[] = {
    0xA,  0xB,  0xC,  0xD,  0xE,  0xF,  0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x32,
    0x33, 0x34, 0x35, 0x36, 0x37, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41,
};
static u8 D_8438B0F4[] = { 0x27, 0x2B };

void func_84376790(s32 arg0, u32 arg1) {
    u32 temp_a1 = (u32)_7820E0_ROM_START + arg0 * 0x48;

    func_80003B30(arg1, temp_a1, temp_a1 + 0x48, 0);
}

void func_843767DC(void) {
}

s32 func_843767E4(s32 arg0) {
    s32 var_v1_1;
    u8 var_v1_2;
    s32 var_v1;

    if (arg0 <= 0) {
        return 0;
    }

    var_v1_1 = (osGetCount() & 0xFF0) >> 4;
    var_v1_2 = var_v1_1;
    while (var_v1_2 > 0) {
        D_843C6150 = (D_843C6150 * 0x49967AD5) + 0x3039;
        if (D_843C6154 & 1) {
            D_843C6154 ^= 0x8421;
        }
        D_843C6154 >>= 1;
        var_v1_2--;
    }

    var_v1 = (D_843C6150 ^ D_843C6154) % (arg0 + 1);
    if (var_v1 < 0) {
        var_v1 = 0;
    }
    if (arg0 < var_v1) {
        var_v1 = arg0;
    }
    return var_v1;
}

void func_843768D8(u8 arg0) {
    D_843C6150 ^= (osGetCount() * arg0);
    D_843C6154 = ~D_843C6150;
}

u8 func_84376920(unk_D_800FCB18* arg0, unk_D_800FCB18* arg1, u8 arg2) {
    s32 var_v1;

    if (D_8438AC60[0] == 1) {
        var_v1 = (D_80070FA0[arg0->unk_0B - 1].unk_04 + 0x4C) >> 2;
    } else {
        var_v1 = D_80070FA0[arg0->unk_0B - 1].unk_04 >> 1;
    }

    if (D_8438AC60[0] != 1) {
        if (arg0->unk_4D & 4) {
            var_v1 >>= 1;
        } else {
            var_v1 *= 2;
        }
    } else if (arg0->unk_4D & 4) {
        var_v1 += 0x28;
        var_v1 *= 4;
    } else {
        var_v1 *= 2;
    }

    if ((arg2 != 2) && (arg2 != 0x4B) && (arg2 != 0x98) && (arg2 != 0xA3)) {
        var_v1 >>= 1;
    } else {
        var_v1 *= 4;
        if (var_v1 >= 0x100) {
            var_v1 = 0xFF;
        }
    }

    if (var_v1 >= 0x100) {
        var_v1 = 0xFF;
    }

    if (var_v1 <= 0) {
        var_v1 = 1;
    }
    return var_v1;
}

u16 func_84376A34(unk_D_800FCB18* arg0, unk_D_800FCB18* arg1) {
    s32 var_v0;

    switch (D_843C6148.unk_01) {
        case 38:
            break;

        case 40:
            D_843C613A = arg0->unk_0C / 2;
            if (D_843C613A == 0) {
                D_843C613A = 1;
            }
            break;

        case 41:
            switch (D_843C6148.unk_00) {
                case 0x45:
                case 0x65:
                    var_v0 = arg0->unk_26;
                    break;

                case 0x31:
                    var_v0 = 0x14;
                    break;

                case 0x52:
                    var_v0 = 0x28;
                    break;

                default:
                    var_v0 = arg0->unk_26;
                    var_v0 = (var_v0 >> 1) + (var_v0 >> 2);
            }

            D_843C613A = var_v0;
            break;

        default:
            if (D_843C6148.unk_02 == 0) {
                return D_843C613A;
            }
            break;
    }

    return D_843C613A;
}

void func_84376B38(void) {
    if (D_843C613A >= 2) {
        D_843C613A = (D_843C613A * 0xFF) / 255;
    }
}

void func_84376B9C(unk_D_800FCB18* arg0, unk_D_800FCB18* arg1) {
    unk_D_8438ACF0* var_v0;
    u8 tmp1 = arg0->unk_16[6];
    u8 tmp2 = arg0->unk_16[7];
    u8 tmp11 = arg1->unk_16[6];
    u8 tmp21 = arg1->unk_16[7];
    u8 tmp3 = D_843C6148.unk_03;

    if (D_843C6148.unk_00 != 0xA5) {
        if ((tmp3 == tmp1) || (tmp3 == tmp2)) {
            D_843C613A += D_843C613A >> 1;
        }

        var_v0 = D_8438ACF0;
        while (var_v0->unk_00 != 0xFF) {
            if ((var_v0->unk_00 == tmp3) && ((var_v0->unk_01 == tmp11) || (var_v0->unk_01 == tmp21))) {
                D_843C613A = (D_843C613A * var_v0->unk_02) / 10;
            }
            var_v0++;
        }
    }
}

void func_84376C90(unk_D_800FCB18* arg0, unk_D_800FCB18* arg1, u8 arg2) {
    unk_D_80072B00* temp_v0 = &D_80072B00[arg2 - 1];

    D_843C6148.unk_00 = temp_v0->unk_00;
    D_843C6148.unk_01 = temp_v0->unk_01;
    D_843C6148.unk_02 = temp_v0->unk_02;
    D_843C6148.unk_03 = temp_v0->unk_03;
    D_843C6148.unk_04 = temp_v0->unk_04;
    D_843C6148.unk_05 = temp_v0->unk_05;

    D_843C613A = 0;
    D_843C613C = D_843C6148.unk_02;
    if (D_843C613C) {
        if (D_843C6148.unk_03 < 0x14) {
            D_843C6140 = arg1->unk_2C;
            if (arg1->unk_4E & 4) {
                D_843C6140 *= 2;
            }

            if (D_843C6144 != 0) {
                D_843C6140 = arg1->unk_3A;
                D_843C613E = arg0->unk_38;
            } else {
                D_843C613E = arg0->unk_2A;
            }
        } else {
            D_843C6140 = arg1->unk_30;
            if (arg1->unk_4E & 2) {
                D_843C6140 *= 2;
            }

            if (D_843C6144 != 0) {
                D_843C6140 = arg1->unk_3E;
                D_843C613E = arg0->unk_3E;
            } else {
                D_843C613E = arg0->unk_30;
            }
        }

        if (D_843C613E & 0xFF00) {
            if (D_843C6140 & 0xFF00) {
                D_843C613E >>= 2;
                D_843C6140 >>= 2;
                if (D_843C613E == 0) {
                    D_843C613E = 1;
                }
            }
        }

        D_843C6142 = arg0->unk_26;
        if (D_843C6144 != 0) {
            D_843C6142 *= 2;
        }
    }
}

void func_84376E40(unk_D_800FCB18* arg0, unk_D_800FCB18* arg1) {
    u8 tmp = D_843C6148.unk_01;

    if (tmp == 7) {
        D_843C6140 >>= 1;
        if (D_843C6140 == 0) {
            D_843C6140 = 1;
        }
    }

    if (D_843C6140 == 0) {
        D_843C6140 = 1;
    }

    D_843C613A += (((((D_843C6142 * 2) / 5) + 2) * D_843C613C * D_843C613E) / D_843C6140) / 50;

    if (D_843C613A >= 0x3E5) {
        D_843C613A = 0x3E4;
    }

    if (D_843C613C != 0) {
        D_843C613A += 2;
    }
}

u16 func_84376F68(unk_D_800FCB18* arg0, unk_D_800FCB18* arg1, u8 arg2, u8 arg3) {
    if (func_84376920(arg0, arg1, arg2) >= (0xE6 - (D_843C5564->unk_04 / 2))) {
        D_843C6144 = 1;
    } else {
        D_843C6144 = 0;
    }

    func_84376C90(arg0, arg1, arg2);
    func_84376E40(arg0, arg1);

    if (arg3 != 0) {
        func_84376B9C(arg0, arg1);
    }

    func_84376B38();
    return func_84376A34(arg0, arg1);
}

void func_84377030(unk_D_843C60AC* arg0) {
    u8 i;
    unk_D_800FCB18* temp_v0 = &arg0->unk_12;

    arg0->unk_04 = 0;
    for (i = 0; i < 6; i++) {
        temp_v0->unk_5C[i] = 7;
    }

    temp_v0->unk_4C = 0;
    temp_v0->unk_4D = 0;
    temp_v0->unk_4E = 0;
}

s32 func_84377068(s32 arg0, s32 arg1) {
    s32 var_a2;
    s32 var_v0;
    s32 var_v1;

    if (arg0 == 0) {
        var_v1 = 0;
    } else if (arg1 == 0) {
        if (arg0 >= 0) {
            var_a2 = 1;
        } else {
            var_a2 = -1;
        }
        var_v1 = var_a2 * 0xFF;
    } else {
        if (arg0 >= 0) {
            var_v0 = arg0;
        } else {
            var_v0 = -arg0;
        }

        if (arg1 >= 0) {
            var_a2 = arg1;
        } else {
            var_a2 = -arg1;
        }

        if (var_a2 < var_v0) {
            if (arg0 >= 0) {
                var_v0 = 1;
            } else {
                var_v0 = -1;
            }

            if (arg1 >= 0) {
                var_a2 = 1;
            } else {
                var_a2 = -1;
            }
            var_v1 = (var_a2 * var_v0) * 0xFF;
        } else {
            var_v1 = (arg0 * 0xFF) / arg1;
        }
    }

    if (var_v1 >= 0) {
        var_a2 = var_v1;
    } else {
        var_a2 = -var_v1;
    }

    if (var_a2 < 0x100) {
        return var_v1;
    }

    if (var_v1 >= 0) {
        var_a2 = 1;
    } else {
        var_a2 = -1;
    }
    return var_a2 * 0xFF;
}

void func_8437717C(unk_D_800AE540_0004* arg0) {
    u8 i;
    u8 j;
    s32 temp_v0;
    u8 temp_a0;

    if (arg0 == NULL) {
        return;
    }

    i = 0;
    while (i < 18 && D_843C5550[i] > 0) {
        i++;
    }

    for (j = 0; j < arg0->unk_214->unk_002; j++) {
        temp_v0 = i + j;
        if (temp_v0 >= 18) {
            break;
        }
        temp_a0 = arg0->unk_01C[j].unk_00.unk_00;
        D_843C5550[temp_v0] = temp_a0;
        func_8430255C(temp_a0, &D_843C5310[temp_v0]);
    }
}

s32 func_84377280(s32 arg0) {
    s32 temp_v0 = D_843C60A8->unk_03 + D_843C60A4->unk_03;
    u8 i;

    for (i = 0; i < temp_v0; i++) {
        if (arg0 == D_843C5550[i]) {
            return i;
        }
    }

    return 0;
}

s32 func_843772E4(u8 arg0, u8 arg1) {
    if (arg0 >= D_8438B084[arg1 - 1]) {
        return 1;
    }
    return 0;
}

u16 func_8437731C(unk_D_800FCB18* arg0) {
    u16 var_v1 = arg0->unk_3C << 2;

    if (arg0->unk_15 & 0x40) {
        var_v1 >>= 2;
    }

    if (var_v1 == 0) {
        var_v1++;
    }

    return var_v1;
}

u16 func_84377354(unk_D_800FCB18* arg0) {
    u16 var_v1 = arg0->unk_3C >> 2;

    if (arg0->unk_15 & 0x40) {
        var_v1 >>= 2;
    }

    if (var_v1 == 0) {
        var_v1++;
    }
    return var_v1;
}

f32 func_8437738C(u8 arg0, unk_D_800FCB18* arg1) {
    unk_D_8438ACF0* var_v0 = &D_8438ACF0[0];
    u8 temp_v1 = arg1->unk_16[6];
    u8 temp_a2 = arg1->unk_16[7];
    f32 var_fv1 = 1.0f;

    while (var_v0->unk_00 != 0xFF) {
        if ((var_v0->unk_00 == arg0) && ((var_v0->unk_01 == temp_v1) || (var_v0->unk_01 == temp_a2))) {
            var_fv1 *= var_v0->unk_02 / 10.0f;
        }
        var_v0++;
    }

    return var_fv1;
}

s32 func_84377430(u8 arg0, unk_D_843C60A4* arg1) {
    u8 i;
    u8 j;
    u8 var_s0;
    s32 var_a0;
    u8 end;

    for (i = 0; i < arg1->unk_00; i++) {
        if (i) {
            var_s0 = arg1->unk_01[0];
        } else {
            var_s0 = 0;
        }

        if (arg1->unk_04[i] == arg1->unk_07[i]) {
            var_a0 = arg1->unk_04[i];
        } else {
            var_a0 = arg1->unk_01[i];
        }

        end = (s32)var_a0 + var_s0;
        for (j = var_s0; j < end; j++) {
            if ((arg1->unk_14[j].unk_12.unk_0C > 0) && (func_8437738C(arg0, &arg1->unk_14[j].unk_12) == 0.0f)) {
                return 0;
            }
        }
    }
    return 1;
}

s32 func_84377550(u8 arg0, u8 arg1) {
    u8 temp_a1;
    s32 temp_a0;
    u8 var_a0;

    temp_a0 = arg0 - 1;
    temp_a1 = arg1 - 1;

    if ((arg0 == 0) || (arg1 == 0)) {
        return 0;
    }

    var_a0 = D_80070FA0[temp_a0].unk_0F[temp_a1 / 8];

    switch (arg0) {
        case 0x6:
            if (temp_a1 / 8 == 6) {
                var_a0 |= 8;
            }
            break;

        case 0xC:
        case 0x30:
        case 0x31:
            if (temp_a1 / 8 == 6) {
                var_a0 |= 0x40;
            }
            break;

        case 0x32:
        case 0x33:
        case 0x8D:
            if (temp_a1 / 8 == 6) {
                var_a0 |= 4;
            }
            break;
    }

    return var_a0 & (1 << (temp_a1 & 7)) & 0xFF;
}

s32 func_84377644(unk_D_843C60A4* arg0, u8 arg1) {
    u8 j;
    u8 i;
    u8 end;
    u8 var_a1;

    for (i = 0; i < arg0->unk_00; i++) {
        var_a1 = (i) ? arg0->unk_01[0] : 0;

        end = arg0->unk_04[i] + var_a1;

        for (j = var_a1; j < end; j++) {
            if ((arg0->unk_14[j].unk_12.unk_15 & arg1) && (arg0->unk_14[j].unk_12.unk_0C > 0)) {
                return 1;
            }
        }
    }

    return 0;
}

u8 func_843776FC(unk_D_843C60AC* arg0, unk_D_843C60AC* arg1, u8 arg2) {
    u8 i;
    u8 sp36;
    u8 temp_v0;
    unk_D_800FCB18* sp30;

    sp30 = &arg1->unk_12;
    if (arg1 == D_843C60AC) {
        sp36 = D_843C5568->unk_000;
    } else {
        sp36 = 1 - D_843C5568->unk_000;
    }

    if (arg0 == arg1) {
        for (i = 0; i < 4; i++) {
            if (arg2 == sp30->unk_1F[i]) {
                return 2;
            }
        }
        return 0;
    }

    temp_v0 = func_84377280(sp30->unk_0B);

    for (i = 0; i < 4; i++) {
        if ((arg1->unk_01 | (arg1->unk_01 >> 4)) & (1 << i) && (arg2 == sp30->unk_1F[i])) {
            return 2;
        }
    }

    if (((arg1->unk_01 | (arg1->unk_01 >> 4)) ^ 0xF) != 0) {
        for (i = 0; i < 4; i++) {
            if (arg2 == D_80070FA0[sp30->unk_0B - 1].unk_0A[i]) {
                return 1;
            }

            if ((D_84384588[sp36]->unk_00 != 0) && (arg2 == D_80070FA0[D_84384588[sp36]->unk_00 - 1].unk_0A[i])) {
                return 1;
            }

            if ((D_84384588[sp36]->unk_01 != 0) && (arg2 == D_80070FA0[D_84384588[sp36]->unk_01 - 1].unk_0A[i])) {
                return 1;
            }
        }

        for (i = 0; D_843C5310[temp_v0].unk_00[i] != 0 && sp30->unk_26 >= D_843C5310[temp_v0].unk_00[i]; i++) {
            if (arg2 == D_843C5310[temp_v0].unk_0A[i]) {
                return 1;
            }
        }

        for (i = 1; i < 0x38; i++) {
            if ((func_84377550(sp30->unk_0B, i) != 0) && (arg2 == D_8438AFB4[i - 1])) {
                return 1;
            }
        }
    }

    return 0;
}

void func_843779C0(void) {
}

u8 func_843779C8(unk_D_843C60AC* arg0, unk_D_843C60AC* arg1, u8 arg2, u8* arg3) {
    u8 temp_v0;

    switch (arg2) {
        case 1:
            *arg3 = 0xC;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x20;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x5A;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            break;

        case 0:
            *arg3 = 0x99;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x78;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            break;

        case 2:
            *arg3 = 0x69;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x87;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x9C;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            break;

        case 3:
            *arg3 = 0x5B;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x13;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            break;

        case 4:
            *arg3 = 0x4E;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x56;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x89;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            break;

        case 10:
            *arg3 = 0xE;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x60;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x9F;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            break;

        case 11:
            *arg3 = 0x70;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x97;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x6A;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x6E;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x6F;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            break;

        case 12:
            *arg3 = 0x61;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            break;

        case 13:
            *arg3 = 0x85;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x4A;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            break;

        case 14:
            *arg3 = 0x68;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x6B;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            break;

        case 20:
            *arg3 = 0x2D;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            break;

        case 21:
            *arg3 = 0x67;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x27;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x2B;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            break;

        case 22:
            *arg3 = 0x51;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            break;

        case 24:
            *arg3 = 0x1C;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x6C;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x86;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }

            *arg3 = 0x94;
            temp_v0 = func_843776FC(arg0, arg1, *arg3);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            break;
    }
    return 0;
}

u8 func_84377FA4(unk_D_843C60AC* arg0, unk_D_843C60A4* arg1, u8* arg2, u8 arg3, u8* arg4) {
    s32 i;
    s32 j;
    u8 temp_v0;
    u8 var_s4;
    s32 var_a0;
    s32 var_v0;
    UNUSED s32 pad;

    var_s4 = 0;

    for (i = 0; i < arg1->unk_00; i++) {
        var_v0 = (i != 0) ? arg1->unk_01[0] : 0;

        if (arg1->unk_04[i] == arg1->unk_07[i]) {
            var_a0 = arg1->unk_04[i];
        } else {
            var_a0 = arg1->unk_01[i];
        }

        for (j = var_v0; j < var_a0 + var_v0; j++) {
            if (arg1->unk_14[j].unk_12.unk_0C > 0) {
                temp_v0 = func_843779C8(arg0, &arg1->unk_14[j], arg3, arg4);
                if (var_s4 < temp_v0) {
                    var_s4 = temp_v0;
                    *arg2 = j;
                }
            }
        }
    }

    return var_s4;
}

s32 func_843780FC(u8 arg0, u8 arg1) {
    if (arg0 == 0) {
        return 0;
    }

    if (arg1 == D_8438AFEC[arg0 - 1]) {
        return 1;
    }
    return 0;
}

u8 func_84378140(unk_D_843C60AC* arg0, unk_D_843C60AC* arg1) {
    u8 sp27;
    u8 temp_v0;
    u8 sp25 = 0;

    temp_v0 = func_843779C8(arg0, arg1, 0xA, &sp27);
    if (temp_v0 && (arg1->unk_12.unk_5C[0] < 0xD) && (sp25 < temp_v0)) {
        sp25 = temp_v0;
    }

    temp_v0 = func_843779C8(arg0, arg1, 0xB, &sp27);
    if (temp_v0 && (arg1->unk_12.unk_5C[1] < 0xD) && (sp25 < temp_v0)) {
        sp25 = temp_v0;
    }

    temp_v0 = func_843779C8(arg0, arg1, 0xC, &sp27);
    if (temp_v0 && (arg1->unk_12.unk_5C[2] < 0xD) && (sp25 < temp_v0)) {
        sp25 = temp_v0;
    }

    temp_v0 = func_843779C8(arg0, arg1, 0xD, &sp27);
    if (temp_v0 && (arg1->unk_12.unk_5C[3] < 0xD) && (sp25 < temp_v0)) {
        sp25 = temp_v0;
    }

    temp_v0 = func_843779C8(arg0, arg1, 0xE, &sp27);
    if (temp_v0 && (arg1->unk_12.unk_5C[5] < 0xD) && (sp25 < temp_v0)) {
        sp25 = temp_v0;
    }

    return sp25;
}

u8 func_8437828C(unk_D_843C60AC* arg0, unk_D_843C60AC* arg1) {
    u8 sp2F;
    u8 temp_v0;
    u8 sp2D = 0;
    UNUSED s32 pad[1];

    if (arg0->unk_12.unk_4D & 0x12) {
        return 0;
    }

    temp_v0 = func_843779C8(arg0, arg1, 0x14, &sp2F);
    if ((temp_v0 != 0) && (arg1->unk_12.unk_5C[0] >= 2) && (sp2D < temp_v0)) {
        sp2D = temp_v0;
    }

    temp_v0 = func_843779C8(arg0, arg1, 0x15, &sp2F);
    if (temp_v0 != 0) {
        if ((arg1->unk_12.unk_5C[1] >= 2) && (sp2D < temp_v0)) {
            sp2D = temp_v0;
        }
    }

    temp_v0 = func_843779C8(arg0, arg1, 0x16, &sp2F);
    if (temp_v0 != 0) {
        if ((arg1->unk_12.unk_5C[2] >= 2) && (sp2D < temp_v0)) {
            sp2D = temp_v0;
        }
    }

    temp_v0 = func_843779C8(arg0, arg1, 0x18, &sp2F);
    if (temp_v0 != 0) {
        if ((arg1->unk_12.unk_5C[5] >= 2) && (sp2D < temp_v0)) {
            sp2D = temp_v0;
        }
    }
    return sp2D;
}

s32 func_843783CC(unk_D_843C60A4* arg0) {
    u8 i;
    u8 j;
    u8 temp_t2;
    u8 var_v0 = 0;
    u8 var_a2;

    for (i = 0; i < arg0->unk_00; i++) {
        if (i) {
            var_a2 = arg0->unk_01[0];
        } else {
            var_a2 = 0;
        }

        temp_t2 = arg0->unk_04[i] + var_a2;

        for (j = var_a2; j < temp_t2; j++) {
            if (arg0->unk_14[j].unk_12.unk_0C > 0) {
                var_v0++;
            }
        }
    }

    if (var_v0 == 1) {
        return 1;
    }
    return 0;
}

void func_84378474(unk_D_800AE540_0004* arg0, unk_D_800AE540_0004* arg1, unk_D_800AE540_0004* arg2,
                   unk_D_843C5568* arg3, s32 arg4) {
    s32 i;

    switch (arg4) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            for (i = 0; i < 2; i++) {
                arg3[i].unk_002 = 1;
                arg3[i].unk_003 = 6;
                arg3[i].unk_004 = 0;
                arg3[i].unk_005 = 6;
                arg3[i].unk_006 = 3;
                arg3[i].unk_007 = 0;
                arg3[i].unk_008 = 3;
            }
            break;

        case 0:
        case 8:
            if (arg1 == NULL) {
                arg3->unk_002 = 1;
                arg3->unk_004 = 0;
                arg3->unk_006 = arg0->unk_002;
                arg3->unk_007 = 0;
            } else {
                arg3->unk_002 = 2;
                arg3->unk_006 = arg0->unk_002;
                arg3->unk_007 = arg1->unk_002;
                arg3->unk_004 = arg1->unk_214->unk_002;
            }

            arg3[0].unk_003 = arg0->unk_214->unk_002;
            arg3[0].unk_005 = arg3[0].unk_003 + arg3[0].unk_004;
            arg3[0].unk_008 = arg3[0].unk_006 + arg3[0].unk_007;

            arg3[1].unk_002 = 1;
            arg3[1].unk_006 = arg2->unk_002;
            arg3[1].unk_004 = 0;
            arg3[1].unk_007 = 0;

            arg3[1].unk_005 = arg3[1].unk_003 = arg3[1].unk_008 = arg3[1].unk_006;
            break;
    }
}

void func_84378578(unk_D_843C60AC* arg0, u8 arg1) {
    u8 sp2F = arg0->unk_02;
    UNUSED s32 pad;

    if ((sp2F > 0) && (sp2F < 0xA6) && (sp2F != arg0->unk_05[arg1])) {
        if (!(arg0->unk_12.unk_15 & 7) && !(arg0->unk_12.unk_15 & 0x20) && !(arg0->unk_12.unk_4D & 0x20)) {
            if (D_80072B00[sp2F - 1].unk_02 != 0) {
                if (func_8437738C(D_80072B00[sp2F - 1].unk_03, &arg0->unk_12) != 0.0f) {
                    if ((D_80072B00[sp2F - 1].unk_01 != 7) && (D_80072B00[sp2F - 1].unk_01 != 0x26) &&
                        (D_80072B00[sp2F - 1].unk_01 != 0x28)) {
                        arg0->unk_05[arg1] = sp2F;
                    }
                }
            }
        }
    }
}

u16 func_8437865C(unk_D_800FCB18* arg0, unk_D_800FCB18* arg1, u8 arg2) {
    u16 var_v0;

    if (D_843C5564->unk_00 & 0x10) {
        var_v0 = func_84376F68(arg0, arg1, arg2, 1);
    } else if (D_843C5564->unk_00 & 0x20) {
        var_v0 = func_84376F68(arg0, arg1, arg2, 0);
    } else {
        var_v0 = func_84376F68(arg0, arg1, arg2, 1);
    }

    switch (D_80072B00[arg2 - 1].unk_01) {
        case 0x3:
            if (arg1->unk_4D & 0x10) {
                var_v0 = 0;
            }
            break;

        case 0x8:
            if (!(arg1->unk_15 & 7) || (arg1->unk_4D & 0x10)) {
                var_v0 = 0;
            }
            break;

        case 0x1D:
            var_v0 *= 4;
            break;

        case 0x26:
            if ((arg0->unk_2E >= arg1->unk_2E) &&
                (!(D_843C5564->unk_00 & 0x10) || (func_8437738C(D_80072B00[arg2 - 1].unk_03, arg1) != 0.0f))) {
                var_v0 = 0x3E7;
            } else {
                var_v0 = 0;
            }
            break;

        case 0x2C:
        case 0x4D:
            var_v0 *= 2;
            break;

        case 0xA:
        case 0xB:
        case 0xD:
        case 0xF:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x16:
        case 0x18:
        case 0x19:
        case 0x1C:
        case 0x20:
        case 0x2E:
        case 0x2F:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x38:
        case 0x39:
        case 0x3B:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x4F:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
            var_v0 = 0;
            break;
    }
    return var_v0;
}

void func_843787F4(unk_D_800FCB18* arg0, unk_D_800FCB18* arg1, u16* arg2, u8* arg3, u8 arg4, u8 arg5) {
    u16 temp_v0;
    u8 var_a1;
    u16 tmp = arg4;

    if ((arg4 != 0) && (D_80072B00[arg4 - 1].unk_02 != 0)) {
        if (1) {}
        if (1) {}
        if (1) {}
        if (1) {}
        temp_v0 = func_8437865C(arg0, arg1, arg4);

        var_a1 = D_80072B00[arg4 - 1].unk_01;

        if (((var_a1 != 0x26) && (D_80072B00[arg4 - 1].unk_01 != 7)) || (arg5 == 0)) {
            switch (arg5) {
                case 1:
                    if ((D_80072B00[arg4 - 1].unk_03 < 0xA) && (temp_v0 >= *arg2)) {
                        *arg3 = arg4;
                        *arg2 = temp_v0;
                    }
                    break;

                case 2:
                    if ((D_80072B00[arg4 - 1].unk_03 >= 0xB) && (temp_v0 >= *arg2)) {
                        *arg3 = arg4;
                        *arg2 = temp_v0;
                    }
                    break;

                case 3:
                    if ((D_80072B00[arg4 - 1].unk_03 < 2) && (temp_v0 >= *arg2)) {
                        *arg3 = arg4;
                        *arg2 = temp_v0;
                    }
                    break;

                case 10:
                    temp_v0 *= (f32)D_80072B00[arg4 - 1].unk_04 / 255.0;
                    if ((D_80072B00[arg4 - 1].unk_01 != 0x1A) && (D_80072B00[arg4 - 1].unk_01 != 0x27) &&
                        (D_80072B00[arg4 - 1].unk_01 != 0x2B) && (D_80072B00[arg4 - 1].unk_01 != 0x50) &&
                        (arg0->unk_2E >= arg1->unk_2E)) {
                        temp_v0 *= 2;
                    }

                    if (*arg2 < temp_v0) {
                        *arg3 = arg4;
                        *arg2 = temp_v0;
                        return;
                    }
                    break;

                case 12:
                    if ((D_80072B00[arg4 - 1].unk_01 != 0x1A) && (D_80072B00[arg4 - 1].unk_01 != 0x27) &&
                        (D_80072B00[arg4 - 1].unk_01 != 0x2B) && (D_80072B00[arg4 - 1].unk_01 != 0x50)) {
                        temp_v0 *= 2;
                    }

                    if (*arg2 < temp_v0) {
                        *arg3 = arg4;
                        *arg2 = temp_v0;
                        return;
                    }
                    break;

                case 11:
                    if ((D_80072B00[arg4 - 1].unk_01 == 0x27) || (D_80072B00[arg4 - 1].unk_01 == 0x2B)) {
                        temp_v0 = 0;
                    }

                    if (*arg2 < temp_v0) {
                        *arg3 = arg4;
                        *arg2 = temp_v0;
                        return;
                    }
                    break;

                default:
                    if (*arg2 < temp_v0) {
                        *arg3 = arg4;
                        *arg2 = temp_v0;
                    }
                    break;
            }
        }
    }
}

s32 func_84378B0C(unk_D_843C60AC* arg0, unk_D_843C60AC* arg1, u8* arg2, u8 arg3) {
    u8 i;
    u8 spDE;
    u8 var_v0_2;
    u8 var_s0;
    UNUSED s32 pad;
    u16 spD6;
    unk_D_843C60AC sp60;
    s16 tmp;
    unk_D_800FCB18* temp_s2;
    UNUSED s32 pad2;

    spD6 = 0;
    *arg2 = 0;
    temp_s2 = &arg0->unk_12;
    spDE = func_84377280(temp_s2->unk_0B);

    if (temp_s2->unk_4C & 1) {
        *arg2 = 0x75;

        switch (arg3) {
            case 1:
            case 3:
            case 11:
                if (temp_s2->unk_4F != 0) {
                    spD6 = 0;
                } else {
                    spD6 = temp_s2->unk_54 * 2;
                }
                break;

            case 12:
                if ((temp_s2->unk_4F - 1) > 0) {
                    spD6 = 0;
                } else {
                    spD6 = temp_s2->unk_54 * 2;
                }
                break;

            default:
                spD6 = func_8437865C(temp_s2, &arg1->unk_12, 0x75);
                break;
        }
    } else if (temp_s2->unk_4C & 2) {
        i = (arg0 == D_843C60AC) ? D_843C5568->unk_000 : 1 - D_843C5568->unk_000;
        *arg2 = D_84390010[i]->unk_654.unk_38.unk_5A;
        spD6 = func_8437865C(temp_s2, &arg1->unk_12, *arg2);
    } else if ((temp_s2->unk_4C & 0x10) || (temp_s2->unk_4C & 0x20) || (temp_s2->unk_4C & 0x40)) {
        i = (arg0 == D_843C60AC) ? D_843C5568->unk_000 : 1 - D_843C5568->unk_000;
        *arg2 = D_84390010[i]->unk_654.unk_38.unk_5A;
        spD6 = func_8437865C(temp_s2, &arg1->unk_12, *arg2);

        if (arg3 == 0xC) {
            _bcopy(arg0, &sp60, sizeof(unk_D_843C60AC));
            sp60.unk_12.unk_4C &= ~0x30;
            spD6 += func_84378B0C(&sp60, arg1, arg2, 0xB);
        }
    } else if (temp_s2->unk_4D & 0x20) {
        *arg2 = 0x3F;
        if (arg3 == 0xC) {
            _bcopy(arg0, &sp60, sizeof(unk_D_843C60AC));
            sp60.unk_12.unk_4D &= ~0x20;
            spD6 = func_84378B0C(&sp60, arg1, arg2, 0xB);
        } else {
            spD6 = 0;
        }
    } else if (temp_s2->unk_4D & 0x40) {
        *arg2 = 0x63;
        spD6 = func_8437865C(temp_s2, &arg1->unk_12, 0x63);
    } else if (((arg0->unk_01 | (arg0->unk_01 >> 4)) ^ 0xF) != 0) {
        for (i = 0; i < 4; i++) {
            if ((arg0->unk_01 | (arg0->unk_01 >> 4)) & (1 << i)) {
                func_843787F4(temp_s2, &arg1->unk_12, &spD6, arg2, temp_s2->unk_1F[i], arg3);
            }
        }

        if (D_843C5564->unk_00 & 0x2000) {
            if (arg0->unk_05[arg1->unk_00] != 0) {
                func_843787F4(temp_s2, &arg1->unk_12, &spD6, arg2, arg0->unk_05[arg1->unk_00], arg3);
            }
        }

        if (spD6 == 0) {
            for (i = 0; i < 4 && (tmp = D_80070FA0[temp_s2->unk_0B - 1].unk_0A[i]); i++) {
                func_843787F4(temp_s2, &arg1->unk_12, &spD6, arg2, tmp, arg3);
            }

            if (temp_s2 == D_843C60B8) {
                var_v0_2 = 0;
            } else {
                var_v0_2 = 1;
            }

            if (D_84384588[var_v0_2]->unk_00 != 0) {
                for (i = 0; i < 4 && (tmp = D_80070FA0[D_84384588[var_v0_2]->unk_00 - 1].unk_0A[i]); i++) {
                    func_843787F4(temp_s2, &arg1->unk_12, &spD6, arg2, tmp, arg3);
                }
            }

            if (D_84384588[var_v0_2]->unk_01 != 0) {
                for (i = 0; i < 4 && (tmp = D_80070FA0[D_84384588[var_v0_2]->unk_01 - 1].unk_0A[i]) != 0; i++) {
                    func_843787F4(temp_s2, &arg1->unk_12, &spD6, arg2, tmp, arg3);
                }
            }

            for (i = 0; i < 10; i++) {
                if ((D_843C5310[spDE].unk_00[i] != 0) && (temp_s2->unk_26 >= D_843C5310[spDE].unk_00[i])) {
                    tmp = D_843C5310[spDE].unk_0A[i];
                    func_843787F4(temp_s2, &arg1->unk_12, &spD6, arg2, tmp, arg3);
                }
            }

            for (i = 1; i < 0x38; i++) {
                if ((func_84377550(temp_s2->unk_0B, i) != 0) &&
                    (func_843772E4((D_843C5564->unk_00 & 0xC000u) >> 0xE, i) != 0)) {
                    tmp = D_8438AFB4[i - 1];
                    func_843787F4(temp_s2, &arg1->unk_12, &spD6, arg2, tmp, arg3);
                }
            }
        }
    } else {
        tmp = temp_s2->unk_1F[0];
        for (i = 0; i < 4 && (tmp = temp_s2->unk_1F[i]); i++) {
            if (temp_s2->unk_32[i] > 0) {
                func_843787F4(temp_s2, &arg1->unk_12, &spD6, arg2, tmp, arg3);
            }
        }
    }
    return spD6;
}

s32 func_843791AC(unk_D_843C60AC* arg0, unk_D_843C60AC* arg1, u8* arg2, u8 arg3) {
    return func_84377068(func_84378B0C(arg0, arg1, arg2, arg3), arg1->unk_12.unk_28);
}

s32 func_843791E4(unk_D_843C60AC* arg0, unk_D_843C60AC* arg1, u8* arg2, u8 arg3) {
    return func_84377068(func_84378B0C(arg0, arg1, arg2, arg3), arg1->unk_12.unk_0C);
}

void func_8437921C(void) {
}

u8 func_84379224(unk_D_800FCB18* arg0, unk_D_800FCB18* arg1, u8 arg2, u8 arg3) {
    s32 var_t0;
    s32 var_a3;
    unk_D_8438ACB8* var_a0;
    s32 tmp1;
    s32 tmp2;

    if (arg2 == 0) {
        return 0;
    }

    if (D_8438AC60[0] == 1) {
        var_a0 = D_8438ACD4;
    } else {
        var_a0 = &D_8438ACB8->unk_00;
    }

    tmp1 = arg0->unk_5C[4];
    tmp2 = 14 - arg1->unk_5C[5];

    if (arg3) {
        var_a3 = D_80072B00[arg2 - 1].unk_04;
    } else {
        var_a3 = 0xFF;
    }

    var_t0 = (var_a3 * var_a0[tmp1 - 1].unk_00) / var_a0[tmp1 - 1].unk_01;
    if (var_t0 == 0) {
        var_t0 = 1;
    }

    var_t0 = (var_t0 * var_a0[tmp2 - 1].unk_00) / var_a0[tmp2 - 1].unk_01;
    if ((D_8438AC60[0] == 1) && (arg2 == 0x81)) {
        var_t0 = 0xFF;
    }

    if (arg0->unk_15 & 0x40) {
        var_t0 *= 3;
        var_t0 /= 4;
    }

    if (arg0->unk_4C & 0x80) {
        var_t0 /= 2;
    }

    if (var_t0 == 0) {
        var_t0 = 1;
    }

    if (var_t0 >= 0x100) {
        var_t0 = 0xFF;
    }

    return var_t0;
}

void func_843793E0(u8 arg0, u8* arg1) {
    s32 temp_v0 = 0xFF - arg0;

    if (temp_v0 == 0) {
        *arg1 = 1;
        return;
    }

    *arg1 *= temp_v0 / 255.0f;
}

void func_843794CC(unk_D_843C60AC* arg0, unk_D_843C60AC* arg1, s32 arg2, u8 arg3, u8 arg4, unk_func_843794CC* arg5) {
    u8 i;
    u8 sp10E;
    unk_D_800FCB18* var_s0;
    unk_D_800FCB18* var_s3;
    s16 sp102;
    s16 sp100;
    s16 var_v1;
    s16 spFC;
    u8 spFB;
    u8 spFA;
    u8 spF9;
    u8 spF8;
    u8 spF7;
    u8 spF6;
    u8 spF5;
    unk_func_843794CC* var_s2;
    s16 var_s4;
    s16 var_s7;
    s16 var_v0;
    unk_D_843C60AC sp74;
    UNUSED s32 pad;
    s16 var_s1;

    var_s3 = &arg1->unk_12;
    var_s0 = &arg0->unk_12;

    if ((arg2 != 0) && (D_843C60BC == 0)) {
        sp102 = func_8437865C(var_s3, var_s0, arg3);
    } else {
        sp102 = 0;
        var_s3 = &arg1->unk_12;
        var_s0 = &arg0->unk_12;
    }

    if ((arg2 != 0) && (D_843C60BC == 0)) {
        spF9 = func_84379224(var_s3, var_s0, arg3, 0);
    } else {
        spF9 = 0;
    }

    _bcopy(arg1, &sp74, sizeof(unk_D_843C60AC));

    if (arg2 != 0) {
        var_s3->unk_4C &= 0xFF8F;
        var_s3->unk_4D &= 0xFFDF;
    }

    if (D_843C60BC != 0) {
        if ((var_s0->unk_15 & 7) && (func_843767E4(2) != 0)) {
            var_s0->unk_15 = 0;
        }
        var_s0->unk_4C &= 0xFF8F;
        var_s0->unk_4D &= 0xFFDF;
    }

    sp100 = func_84378B0C(arg1, arg0, &spF7, 0xB);
    spF8 = func_84379224(var_s3, var_s0, spF7, 0);
    spF6 = spF7;

    if (arg0 == D_843C60B0) {
        func_84378B0C(arg0, arg1, &spF5, 0xB);
    }

    for (i = 0; i < arg4; i++) {
        var_s4 = sp100;
        var_s7 = 0;
        spFA = spF8;
        spF7 = spF6;

        if (arg0 == D_843C60B0) {
            var_s2 = &arg5[i];
            var_s2->unk_00 = spF5;
        } else {
            var_s2 = &arg5[i];
            var_s2->unk_00 = var_s0->unk_1F[i];
        }

        var_s2->unk_05 = spF7;
        if ((var_s2->unk_00 == 0x77) && (var_s0->unk_2E >= var_s3->unk_2E)) {
            if (var_s3->unk_58 != 0) {
                var_s2->unk_00 = var_s3->unk_58;
            }
        }

        var_s1 = func_8437865C(var_s0, var_s3, var_s2->unk_00);
        spFB = func_84379224(var_s0, var_s3, var_s2->unk_00, 1);
        var_s2->unk_02 = func_84376920(var_s0, var_s3, var_s2->unk_00);

        var_s2->unk_03 = D_80072B00[var_s2->unk_00 - 1].unk_01;
        var_s2->unk_16 = 0;
        var_s2->unk_04 = 0xFF;
        var_s2->unk_0E = var_s2->unk_16;

        if ((var_s2->unk_03 != 0x26) && (var_s2->unk_03 != 0x28) && (var_s2->unk_03 != 0x29) && (var_s1 > 0)) {
            var_s1 = var_s1 * ((((D_843C5564->unk_04 / 255.0f) * 38.0f) + 217.0f) / 255.0f);
            if (var_s1 == 0) {
                var_s1 += 1;
            }
        }

        if ((var_s3->unk_4C & 0x40) && (var_s0->unk_2E >= var_s3->unk_2E) && (var_s2->unk_03 != 0x27) &&
            (var_s2->unk_03 != 0x2B) && (var_s2->unk_03 != 0x11)) {
            var_s1 = 0;
        }

        if (((D_843C60BC != 0) && (arg2 == 0)) || ((var_s3->unk_15 & 7) != 0) ||
            ((var_s0->unk_4C & 0x20) && (var_s0->unk_4F != 0)) ||
            ((var_s3->unk_15 & 0x20) && (D_80072B00[var_s2->unk_00 - 1].unk_01 != 4) &&
             (D_80072B00[var_s2->unk_00 - 1].unk_01 != 0x22))) {
            var_s4 = 0;
            sp102 = 0;
        }

        spFC = var_s0->unk_0C;
        if (arg2 != 0) {
            if (sp102 >= var_s0->unk_0C) {
                func_843793E0(spF9, &spFB);
            }

            if (sp102 >= var_s0->unk_0C) {
                var_s0->unk_0C = 0;
            } else {
                var_s0->unk_0C -= sp102;
            }
        }

        switch (D_80072B00[var_s2->unk_00 - 1].unk_01) {
            case 0x0:
                switch (var_s2->unk_00) {
                    case 0x44:
                        if (var_s4 < var_s0->unk_0C) {
                            if (D_80072B00[spF7 - 1].unk_03 < 2) {
                                var_s1 = var_s4 * 2;
                                spFB *= ((f32)spFA * 0.7) / 255.0;
                            } else {
                                var_s1 = func_84378B0C(arg0, arg1, &spF7, 3) * 2;
                                spFB *= ((f32)spFA * 0.5) / 255.0;
                            }
                        } else {
                            var_s1 = 0;
                            func_843793E0(spFA, &spFB);
                        }
                        break;

                    case 0x62:
                        if (var_s3->unk_4C & 0x40) {
                            var_s1 = 0;
                        }
                        if (var_s1 >= var_s3->unk_0C) {
                            func_843793E0(spFB, &spFA);
                        }
                        goto switch_end;
                }

            case 0x10:
            case 0x11:
            case 0x1B:
            case 0x1D:
            case 0x26:
            case 0x28:
            case 0x29:
            case 0x2C:
            case 0x2D:
            case 0x51:
                if (var_s0->unk_2E >= var_s3->unk_2E) {
                    if (var_s1 >= var_s3->unk_0C) {
                        func_843793E0(spFB, &spFA);
                    }
                } else if (var_s4 >= var_s0->unk_0C) {
                    func_843793E0(spFA, &spFB);
                }
                break;

            case 0x3:
                if (var_s0->unk_2E >= var_s3->unk_2E) {
                    if (var_s1 >= var_s3->unk_0C) {
                        func_843793E0(spFB, &spFA);
                    } else {
                        var_s7 = var_s1 >> 1;
                        if (var_s0->unk_28 < (var_s0->unk_0C + var_s7)) {
                            var_s7 = var_s0->unk_28 - var_s0->unk_0C;
                        }
                    }
                } else if (var_s4 >= var_s0->unk_0C) {
                    func_843793E0(spFA, &spFB);
                } else {
                    if (var_s1 < var_s3->unk_0C) {
                        var_s7 = var_s1 >> 1;
                    }

                    if (var_s0->unk_28 < (var_s0->unk_0C + var_s7)) {
                        var_s7 = var_s0->unk_28 - var_s0->unk_0C;
                    }
                }
                break;

            case 0x27:
            case 0x2B:
                if ((D_843C60BC != 0) && (var_s1 != 0)) {
                    if (func_84377430(D_80072B00[var_s2->unk_00 - 1].unk_03, D_843C60A8) == 0) {
                        var_s1 = 0;
                    } else {
                        var_s1 *= 0.75;
                    }
                }

                if (var_s0->unk_15 & 0x40) {
                    spFB *= 0.75;
                }

                if (var_s0->unk_4C & 0x80) {
                    spFB /= 2;
                }

                if (spFB == 0) {
                    spFB++;
                }

                if ((var_s2->unk_00 != 0x5B) && (var_s2->unk_00 != 0x13)) {
                    if (var_s0->unk_2E >= var_s3->unk_2E) {
                        if ((func_843779C8(arg0, arg1, 3, &sp10E) == 2) && !(var_s3->unk_4C & 0x50)) {
                            var_s1 = 0;
                        }

                        if (var_s4 >= var_s0->unk_0C) {
                            var_s1 = var_s1 / 2;
                            func_843793E0(spFA, &spFB);
                        }

                        if (var_s1 < var_s3->unk_0C) {
                            var_s4 = func_84378B0C(arg1, arg0, &spF7, 0xC);
                        }
                    } else {
                        if (func_843779C8(arg0, arg1, 3, &sp10E) == 2) {
                            var_s1 = 0;
                        }

                        var_s4 = func_84378B0C(arg1, arg0, &spF7, 0xC);
                        if (var_s4 >= var_s0->unk_0C) {
                            var_s1 = var_s1 / 2;
                            func_843793E0(spFA, &spFB);
                        }
                    }
                } else if (var_s0->unk_2E >= var_s3->unk_2E) {
                    if (var_s1 >= var_s3->unk_0C) {
                        func_843793E0(spFB, &spFA);
                    }
                } else {
                    if (func_843779C8(arg0, arg1, 3, &sp10E) == 2) {
                        var_s1 = 0;
                    }

                    if (var_s4 >= var_s0->unk_0C) {
                        func_843793E0(spFA, &spFB);
                    }
                }
                break;

            case 0x2:
            case 0x4:
            case 0x5:
            case 0x6:
            case 0x1F:
            case 0x23:
            case 0x4C:
                var_s2->unk_04 = 0x1A;
                if (var_s0->unk_2E >= var_s3->unk_2E) {
                    if (var_s1 >= var_s3->unk_0C) {
                        func_843793E0(spFB, &spFA);
                    }
                } else if (var_s4 >= var_s0->unk_0C) {
                    func_843793E0(spFA, &spFB);
                }
                break;

            case 0x44:
            case 0x45:
            case 0x46:
            case 0x47:
                var_s2->unk_04 = 0x55;
                if (var_s0->unk_2E >= var_s3->unk_2E) {
                    if (var_s1 >= var_s3->unk_0C) {
                        func_843793E0(spFB, &spFA);
                    }
                } else if (var_s4 >= var_s0->unk_0C) {
                    func_843793E0(spFA, &spFB);
                }
                break;

            case 0x7:
                if (var_s0->unk_2E >= var_s3->unk_2E) {
                    if (var_s1 >= var_s3->unk_0C) {
                        func_843793E0(spFB, &spFA);
                    }
                } else if (var_s4 >= var_s0->unk_0C) {
                    func_843793E0(spFA, &spFB);
                }

                if (var_s0->unk_0C >= 2) {
                    var_s2->unk_16 = var_s0->unk_0C;
                } else {
                    var_s2->unk_16 = 1;
                }
                break;

            case 0x8:
                if (var_s1 < var_s3->unk_0C) {
                    var_s7 = var_s1 >> 1;
                }

                if (var_s0->unk_28 < (var_s0->unk_0C + var_s7)) {
                    var_s7 = var_s0->unk_28 - var_s0->unk_0C;
                }

                if (var_s0->unk_2E >= var_s3->unk_2E) {
                    if (var_s1 >= var_s3->unk_0C) {
                        func_843793E0(spFB, &spFA);
                    }
                } else if (var_s4 >= var_s0->unk_0C) {
                    func_843793E0(spFA, &spFB);
                }
                break;

            case 0x9:
                if (var_s0->unk_2E >= var_s3->unk_2E) {
                    if ((var_s3->unk_58 == 0) || (var_s3->unk_58 == 0x77)) {
                        var_s1 = 0;
                        spFB = 0;
                    }
                } else {
                    var_s1 = func_8437865C(var_s0, var_s3, spF7);
                    spFB = func_84379224(var_s0, var_s3, spF7, 1);
                    if ((arg2 != 0) && (sp102 >= spFC)) {
                        func_843793E0(spF9, &spFB);
                    }
                }

                if (var_s0->unk_2E >= var_s3->unk_2E) {
                    if (var_s1 >= var_s3->unk_0C) {
                        func_843793E0(spFB, &spFA);
                    }
                } else if (var_s4 >= var_s0->unk_0C) {
                    func_843793E0(spFA, &spFB);
                }
                break;

            case 0x1A:
                var_s4 *= 2;
                var_s1 = var_s4;
                if (var_s4 >= var_s0->unk_0C) {
                    var_s1 = 0;
                    func_843793E0(spFA, &spFB);
                }
                break;

            case 0x21:
            case 0x22:
            case 0x24:
            case 0x25:
                var_s2->unk_04 = 0x4D;
                if (var_s0->unk_2E >= var_s3->unk_2E) {
                    if (var_s1 >= var_s3->unk_0C) {
                        func_843793E0(spFB, &spFA);
                    }
                } else if (var_s4 >= var_s0->unk_0C) {
                    func_843793E0(spFA, &spFB);
                }
                break;

            case 0x2A:
                if (var_s0->unk_2E >= var_s3->unk_2E) {
                    if (var_s1 != 0) {
                        func_843793E0(spFB, &spFA);
                    }
                } else if (var_s4 >= var_s0->unk_0C) {
                    func_843793E0(spFA, &spFB);
                }
                break;

            case 0x30:
                if (var_s0->unk_2E >= var_s3->unk_2E) {
                    if (var_s1 >= var_s3->unk_0C) {
                        func_843793E0(spFB, &spFA);
                    }
                } else if (var_s4 >= var_s0->unk_0C) {
                    func_843793E0(spFA, &spFB);
                }

                if (var_s1 < var_s3->unk_0C) {
                    var_s4 = var_s4 + (var_s1 / 4);
                }
                break;

            case 0x4D:
                var_s2->unk_04 = 0x34;
                if (var_s0->unk_2E >= var_s3->unk_2E) {
                    if (var_s1 >= var_s3->unk_0C) {
                        func_843793E0(spFB, &spFA);
                    }
                } else if (var_s4 >= var_s0->unk_0C) {
                    func_843793E0(spFA, &spFB);
                }
                break;

            case 0x50:
                if (var_s0->unk_2E >= var_s3->unk_2E) {
                    if (var_s1 >= var_s3->unk_0C) {
                        if (D_8438AC60[0] != 1) {
                            func_843793E0(spFB, &spFA);
                        }
                    } else {
                        if (D_843C60BC != 0) {
                            var_s4 = func_84378B0C(arg1, arg0, &spF7, 0xB);
                        } else {
                            var_s4 = func_84378B0C(arg1, arg0, &spF7, 0xC);
                        }
                    }
                } else {
                    if (var_s4 >= var_s0->unk_0C) {
                        func_843793E0(spFA, &spFB);
                    }

                    if ((var_s1 >= var_s3->unk_0C) && (D_8438AC60[0] != 1)) {
                        func_843793E0(spFB, &spFA);
                    } else {
                        arg1->unk_12.unk_4D &= 0xFFDF;
                        var_s4 += func_84378B0C(arg1, arg0, &spF7, 0xB);
                    }
                }
                break;

            case 0x38:
                spFB = 0xFF;
                if (var_s0->unk_15 & 0x40) {
                    spFB = 0xBF;
                }

                if (var_s0->unk_4C & 0x80) {
                    spFB /= 2;
                }

                if (spFB == 0) {
                    spFB++;
                }

                if ((arg2 != 0) && (sp102 >= spFC)) {
                    func_843793E0(spF9, &spFB);
                }
                break;

            case 0xA:
            case 0xB:
            case 0xD:
            case 0xF:
            case 0x18:
            case 0x19:
            case 0x1C:
            case 0x2E:
            case 0x2F:
            case 0x32:
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x39:
            case 0x40:
            case 0x41:
            case 0x52:
            case 0x53:
            case 0x55:
            case 0x56:
                spFB = 0xFF;
                if (var_s0->unk_15 & 0x40) {
                    spFB = 0xBF;
                }

                if (var_s0->unk_4C & 0x80) {
                    spFB /= 2;
                }

                if (spFB == 0) {
                    spFB++;
                }

                if ((arg2 != 0) && (sp102 >= spFC)) {
                    func_843793E0(spF9, &spFB);
                }

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
                var_s1 = 0;
                if ((var_s3->unk_2E >= var_s0->unk_2E) && (var_s4 >= var_s0->unk_0C)) {
                    func_843793E0(spFA, &spFB);
                }
                break;

            case 0x4F:
                var_s1 = 0;
                if (var_s0->unk_4D & 0x10) {
                    spFB = 0;
                } else {
                    if (var_s0->unk_0C < (var_s0->unk_28 >> 2)) {
                        spFB = 0;
                    } else {
                        spFB = 0xFF;
                    }

                    if (var_s0->unk_15 & 0x40) {
                        spFB = (spFB * 3) / 4;
                    }

                    if (var_s0->unk_4C & 0x80) {
                        spFB /= 2;
                    }

                    if (spFB == 0) {
                        spFB++;
                    }

                    if ((arg2 != 0) && (sp102 >= spFC)) {
                        func_843793E0(spF9, &spFB);
                    }

                    if ((var_s3->unk_2E >= var_s0->unk_2E) && (var_s4 >= var_s0->unk_0C)) {
                        func_843793E0(spFA, &spFB);
                    }

                    if ((var_s4 >= (var_s0->unk_28 >> 2)) && (var_s0->unk_0C >= (var_s0->unk_28 >> 2)) &&
                        (var_s3->unk_2E < var_s0->unk_2E)) {
                        var_s4 = var_s0->unk_28 / 4;
                    }
                }
                break;
        }

    switch_end:
        if (var_s0->unk_15 & 0x18) {
            if ((var_s0->unk_28 >> 4) != 0) {
                var_v1 = var_s0->unk_28 >> 4;
            } else {
                var_v1 = 1;
            }

            if (var_s0->unk_4E & 1) {
                var_v1 *= var_s0->unk_51;
            }
            var_s2->unk_16 += var_v1;
        }

        if (var_s3->unk_15 & 0x18) {
            if ((var_s0->unk_28 >> 4) != 0) {
                var_v0 = var_s3->unk_28 >> 4;
            } else {
                var_v0 = 1;
            }

            if (var_s3->unk_4E & 1) {
                var_v0 *= var_s3->unk_51;
            }
            var_s2->unk_0E += var_v0;
        }

        if (var_s0->unk_4D & 0x80) {
            if ((var_s0->unk_28 >> 4) <= 0) {
                var_v1 = 1;
            } else {
                var_v1 = var_s0->unk_28 >> 4;
            }

            if (var_s0->unk_4E & 1) {
                var_v1 *= var_s0->unk_51 + 1;
            }

            var_s2->unk_16 += var_v1;
            var_s2->unk_0E -= (var_s2->unk_00 != 0x9C)       ? var_v1
                              : ((var_s0->unk_28 >> 4) <= 0) ? 1
                                                             : var_s0->unk_28 >> 4;
        }

        if (var_s3->unk_4D & 0x80) {
            if ((var_s3->unk_28 >> 4) <= 0) {
                var_v0 = 1;
            } else {
                var_v0 = var_s3->unk_28 >> 4;
            }

            if (var_s3->unk_4E & 1) {
                var_v0 *= var_s3->unk_51 + 1;
            }

            var_s2->unk_0E += var_v0;
            var_s2->unk_16 -= var_v0;
        }

        if (var_s0->unk_4D & 0x10) {
            var_s4 = 0;
        }

        if (var_s3->unk_4D & 0x10) {
            if (var_s3->unk_59 < var_s1) {
                var_s1 = var_s3->unk_59;
            }
        }

        var_s2->unk_0A = var_s1;
        var_s2->unk_01 = spFB;
        var_s2->unk_0C = func_84377068(var_s1, var_s3->unk_0C);
        var_s2->unk_10 = func_84377068(var_s2->unk_0E, var_s3->unk_0C);
        var_s2->unk_05 = spF7;
        var_s2->unk_12 = var_s4;
        var_s2->unk_06 = spFA;
        var_s2->unk_14 = func_84377068(var_s4, var_s0->unk_0C);
        var_s2->unk_18 = func_84377068(var_s2->unk_16, var_s0->unk_0C);
        var_s2->unk_1A = var_s7;
        var_s2->unk_1C = func_84377068(var_s7, var_s0->unk_0C);
        var_s2->unk_07 = arg3;
        var_s2->unk_1E = sp102;
        var_s2->unk_08 = spF9;
        var_s2->unk_20 = func_84377068(sp102, spFC);

        if ((var_s2->unk_0C + var_s2->unk_10) >= 0x100) {
            var_s2->unk_0C = 0xFF - var_s2->unk_10;
        }

        if (0xFF < var_s2->unk_14 + (var_s2->unk_18 - var_s2->unk_1C)) {
            var_s2->unk_14 = 0xFF - (var_s2->unk_18 - var_s2->unk_1C);
        }
        var_s0->unk_0C = spFC;
    }
    _bcopy(&sp74, arg1, sizeof(unk_D_843C60AC));
}

s32 func_8437AC20(unk_func_843794CC* arg0, u8 arg1, u8 arg2) {
    u8 i;

    for (i = 0; i < arg1; i++) {
        if ((arg2 == arg0[i].unk_0C) && (D_80072B00[arg0[i].unk_00 - 1].unk_01 != 0x26)) {
            return 1;
        }
    }

    return 0;
}

s32 func_8437ACB0(unk_func_843794CC* arg0, u8 arg1, u8 arg2, u8 arg3) {
    s32 i;
    s32 var_v1 = 0;

    for (i = 0; i < arg2; i++) {
        if ((arg3 < arg0[i].unk_0C) && (D_80072B00[arg0[i].unk_00 - 1].unk_01 != 0x26)) {
            var_v1 = 1;
        }
    }

    if (arg3 < arg0[arg1].unk_0C) {
        var_v1 = 0;
    }
    return var_v1;
}

u8 func_8437AEA4(unk_func_843794CC* arg0, u8 arg1, u8 arg2, u8 arg3) {
    s32 i;
    u8 var_v1 = 0;

    if (arg3 >= 0x100) {
        arg3 = 0xFF;
    }

    if (arg3 < 0) {
        arg3 = 0;
    }

    for (i = 0; i < arg2; i++) {
        if (i != arg1) {
            if ((arg0[i].unk_0C >= arg3) && (D_80072B00[arg0[i].unk_00 - 1].unk_01 != 0x26)) {
                var_v1 = 1;
            }
        }
    }

    return var_v1;
}

#ifdef NON_MATCHING
void func_8437B0CC(unk_D_843C60A4* arg0, unk_D_843C60A4* arg1, u8 arg2, unk_func_843794CC* arg3, u8 arg4) {
    u8 i;
    u8 j;
    u8 sp107;
    u8 sp106;
    u8 sp104;
    u8 sp103;
    s32 spFC;
    s32 spF8;
    s32 spC0;
    u8 spBA;
    u8 spB7;
    u8 spB6;
    u8 spB5;
    u8 spB4;
    unk_D_80072B00* sp9C;
    f32 sp8C;
    s32 sp80;
    s32 sp78;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s16 temp_v1_11;
    s16 temp_v1_12;
    s16 temp_v1_2;
    s16 temp_v1_3;
    s16 temp_v1_4;
    s32 temp_a0;
    s32 temp_lo;
    s32 temp_lo_2;
    u8 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s0_6;
    s32 temp_s0_7;
    s32 temp_s0_8;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s1_3;
    s32 temp_s1_4;
    s32 temp_s1_5;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_s2_3;
    s32 temp_s2_4;
    s32 temp_v0_22;
    s32 temp_v0_23;
    s32 temp_v0_24;
    s32 temp_v0_25;
    s32 temp_v0_26;
    s32 temp_v0_27;
    s32 temp_v0_3;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;
    s32 var_s1_5;
    s32 var_s1_6;
    s32 var_s1_7;
    s32 var_s1_8;
    s32 var_s1_9;
    s32 var_s2;
    s32 var_s5;
    s32 var_t1;
    s32 var_v1;
    s32 var_v1_3;
    s32 var_v1_6;
    s8 temp_v0;
    u16 temp_v0_20;
    u16 temp_v0_21;
    u16 temp_v0_9;
    u16 temp_v1_5;
    u16 temp_v1_6;
    u16 temp_v1_8;
    u16 temp_v1_9;
    s32 var_v1_4;
    s32 var_v1_5;
    u8 temp_a1;
    u8 temp_a1_2;
    u8 temp_a1_3;
    u8 temp_t0;
    u8 temp_t5;
    u8 temp_v0_10;
    u8 temp_v0_11;
    u8 temp_v0_12;
    u8 temp_v0_13;
    u8 temp_v0_14;
    u8 temp_v0_15;
    u8 temp_v0_16;
    u8 temp_v0_17;
    u8 temp_v0_18;
    u8 temp_v0_19;
    u8 temp_v0_28;
    u8 temp_v0_29;
    u8 temp_v0_2;
    u8 temp_v0_8;
    u8 temp_v1;
    u8 temp_v1_10;
    u8 temp_v1_7;
    u8 var_v1_2;
    unk_D_80072B00* temp_v1_13;
    unk_D_800FCB18* temp_s3;
    unk_D_800FCB18* temp_s3_10;
    unk_D_800FCB18* temp_s3_11;
    unk_D_800FCB18* temp_s3_12;
    unk_D_800FCB18* temp_s3_13;
    unk_D_800FCB18* temp_s3_14;
    unk_D_800FCB18* temp_s3_15;
    unk_D_800FCB18* temp_s3_16;
    unk_D_800FCB18* temp_s3_17;
    unk_D_800FCB18* temp_s3_18;
    unk_D_800FCB18* temp_s3_19;
    unk_D_800FCB18* temp_s3_20;
    unk_D_800FCB18* temp_s3_21;
    unk_D_800FCB18* temp_s3_22;
    unk_D_800FCB18* temp_s3_2;
    unk_D_800FCB18* temp_s3_3;
    unk_D_800FCB18* temp_s3_4;
    unk_D_800FCB18* temp_s3_5;
    unk_D_800FCB18* temp_s3_6;
    unk_D_800FCB18* temp_s3_7;
    unk_D_800FCB18* temp_s3_8;
    unk_D_800FCB18* temp_s3_9;
    unk_D_800FCB18* temp_s6;
    unk_D_843C60AC* temp_fp;
    unk_D_843C60AC* temp_s4;
    unk_func_843794CC* temp_s7;
    unk_func_843794CC* temp_v0_4;
    unk_func_843794CC* temp_v0_5;
    s32 tmp1;
    s32 tmp2;
    s32 tmp3;
    s32 tmp4;
    s32 tmp5;
    s32 tmp6;
    s32 tmp7;
    s32 tmp8;
    s32 tmp9;

    spBA = D_843C5564->unk_0E;
    sp58 = D_843C5564->unk_09;
    spB7 = D_843C5564->unk_0C;
    temp_t0 = D_843C5564->unk_0A;
    spB5 = D_843C5564->unk_0B;
    spB6 = D_843C5564->unk_0D;
    spB4 = D_843C5564->unk_10;
    sp78 = D_843C5564->unk_0F;

    temp_fp = &arg0->unk_14[arg0->unk_10];
    temp_s4 = &arg1->unk_14[arg1->unk_10];

    for (i = 0; i < arg2; i++) {
        temp_s6 = &temp_fp->unk_12;
        if (temp_s6) {}

        sp50 = spB5 * 0x14;
        sp54 = temp_t0 * 0x11;
        sp6C = temp_t0;
        spFC = 0;
        spF8 = 0;

        temp_s7 = &arg3[i];
        sp9C = &D_80072B00[temp_s7->unk_00 - 1];
        var_s5 = 1;
        temp_s0 = func_843780FC(temp_s6->unk_0B, temp_s7->unk_00);
        var_s1 = (func_843767E4(4) * temp_s0 * sp78 * 3) / 2;

        switch (temp_s7->unk_03) {
            case 0x0:
                temp_s3 = &temp_s4->unk_12;

                if (arg4) {
                    switch (temp_s7->unk_00) {
                        case 0x44:
                            if (temp_s3->unk_4C & 0x80) {
                                var_s1 += spBA * 2;
                            }

                            if (func_8437AEA4(arg3, i, arg2, (temp_s7->unk_0C * 2)) != 0) {
                                var_s1 = 1;
                            }
                            break;

                        case 0x62:
                            if (temp_s3->unk_4C & 0x40) {
                                spF8 = 1;
                            }
                            break;
                    }
                }
                break;

            case 0x1:
            case 0x20:
                if (arg4) {
                    temp_s3 = &temp_s4->unk_12;

                    if ((func_84377644(arg1, 7) == 0) && !(temp_s3->unk_4D & 0x10) && (temp_s3->unk_15 == 0)) {
                        var_s1 += spB7 * 5;
                        if (func_843776FC(temp_fp, temp_fp, 0x8A) != 0) {
                            var_s1 += spBA * 3;
                        }

                        if (func_8437ACB0(arg3, i, arg2, 0xB2) != 0) {
                            var_s1 -= sp6C * 5;
                        }

                        if (func_8437AC20(arg3, arg2, 0xFF) != 0) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    if (func_843776FC(temp_fp, temp_fp, 0x8A) != 0) {
                        var_s1 += spBA * 3;
                    }
                    var_s1 += spB7 * 5;
                }
                break;

            case 0x2:
            case 0x21:
            case 0x42:
            case 0x4D:
                temp_s3 = &temp_s4->unk_12;
                if (temp_s3) {}

                if ((temp_s3->unk_15 == 0) && (temp_s3->unk_16[6] != 3) && (temp_s3->unk_16[7] != 3) &&
                    !(temp_s3->unk_4D & 0x10)) {
                    if (arg4) {
                        sp5C = sp6C * 2;
                        if (temp_s7->unk_00 == 0x5C) {
                            sp68 = sp6C;
                            sp64 = spBA;
                            var_s1 += spB7;
                            var_s1 += (spB7 * func_843783CC(arg1));
                            var_s1 += (spB7 * func_843779C8(temp_fp, temp_s4, 2, &sp104));
                            var_s1 += (spB7 * func_843779C8(temp_fp, temp_s4, 0xE, &sp104));
                            var_s1 -= ((sp68 * func_843779C8(temp_fp, temp_s4, 0, &sp104)) / 2);
                            var_s1 += (sp64 * func_843776FC(temp_fp, temp_fp, 0x49));
                            if (func_8437ACB0(arg3, i, arg2, 0xB2) != 0) {
                                var_s1 -= sp68;
                            }
                        }

                        var_s1 += spB7 * 2;
                        var_s1 += ((spB7 * 2) * func_843779C8(temp_fp, temp_s4, 0xE, &sp104));
                        var_s1 -= ((sp5C * func_843779C8(temp_fp, temp_s4, 0, &sp104)) / 2);

                        if (func_8437ACB0(arg3, i, arg2, 0xB2) != 0) {
                            var_s1 -= sp5C;
                        }

                        if (((temp_s6->unk_2E >= temp_s3->unk_2E) && (func_8437AC20(arg3, arg2, 0xFF) != 0)) ||
                            ((temp_s4->unk_02 != 0xA5) && ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) ||
                                                           (func_843776FC(temp_fp, temp_s4, 0x9C) == 2))) ||
                            ((temp_s7->unk_14 >= 0x9A) && (func_843783CC(arg0) != 0) && (temp_s6->unk_5C[5] == 7) &&
                             (temp_s3->unk_5C[4] == 7))) {
                            var_s1 = 1;
                        }
                    } else {
                        if (temp_s7->unk_00 == 0x5C) {
                            var_s1 += (spB7 * 4);
                        }
                        var_s1 += spB7 * 2;
                    }
                } else {
                    spF8 = 1;
                }
                break;

            case 0x4:
            case 0x22:
                temp_s3 = &temp_s4->unk_12;
                if (temp_s3) {}

                if ((temp_s3->unk_15 == 0) && (temp_s3->unk_16[6] != 0x14) && (temp_s3->unk_16[7] != 0x14) &&
                    !(temp_s3->unk_4D & 0x10)) {
                    if (arg4) {
                        var_s1 += spB7 * 2;
                        if ((temp_s7->unk_14 >= 0x9A) && (func_843783CC(arg0) != 0)) {
                            var_s1 -= sp6C * 2;
                        }

                        if (func_8437ACB0(arg3, i, arg2, 0xB2) != 0) {
                            var_s1 -= sp6C * 2;
                        }

                        if (((temp_s4->unk_02 != 0xA5) && ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) ||
                                                           (func_843776FC(temp_fp, temp_s4, 0x9C) == 2))) ||
                            (func_8437AC20(arg3, arg2, 0xFF) != 0)) {
                            var_s1 = 1;
                        }
                    } else {
                        var_s1 += spB7 * 2;
                    }
                } else {
                    spF8 = 1;
                }
                break;

            case 0x5:
            case 0x23:
                temp_s3 = &temp_s4->unk_12;

                if ((func_84377644(arg1, 0x20) == 0) && (temp_s3->unk_15 == 0) && (temp_s3->unk_16[6] != 0x19) &&
                    (temp_s3->unk_16[7] != 0x19) && !(temp_s3->unk_4D & 0x10)) {
                    if (arg4) {
                        var_s1 += (spB7 * 3);
                        if ((func_843783CC(arg0) != 0) && (func_8437ACB0(arg3, i, arg2, 0x4D) == 0) &&
                            (temp_s7->unk_14 >= 0x4E)) {
                            var_s1 += (spB7 * 3);
                        }

                        if (func_8437ACB0(arg3, i, arg2, 0xB2) != 0) {
                            var_s1 -= sp6C * 3;
                        }

                        if (func_8437AC20(arg3, arg2, 0xFF) != 0) {
                            var_s1 = 1;
                        }
                    } else {
                        var_s1 += spB7 * 6;
                    }
                } else {
                    spF8 = 1;
                }
                break;

            case 0x6:
            case 0x24:
                temp_s3 = &temp_s4->unk_12;
                if (temp_s3) {}

                if ((temp_s3->unk_16[6] == sp9C->unk_03) || (temp_s3->unk_16[7] == sp9C->unk_03)) {
                    spF8 = 1;
                    break;
                }

            case 0x43:
                temp_s3 = &temp_s4->unk_12;
                if (temp_s3) {}

                if (arg4) {
                    if ((temp_s3->unk_15 == 0) && !(temp_s3->unk_4D & 0x10) &&
                        ((sp9C->unk_03 != 0x17) || ((temp_s3->unk_16[6] != 4) && (temp_s3->unk_16[7] != 4)))) {
                        if (temp_s3->unk_2E >= temp_s6->unk_2E) {
                            var_s1 += spB7 * 5;
                            if (func_843779C8(temp_fp, temp_fp, 1, &sp104) == 2) {
                                var_s1 += spBA * 3;
                            }

                            if (func_843779C8(temp_fp, temp_s4, 1, &sp104) == 2) {
                                var_s1 += spB6 * 3;
                            }
                        }

                        if ((func_84377FA4(temp_fp, arg0, &sp103, 1, &sp104) != (spB6 * 0)) &&
                            (temp_s3->unk_2E >= arg0->unk_14[sp103].unk_12.unk_2E)) {
                            var_s1 += spBA * 3;
                        }

                        var_s1 += spB7 * 5;
                        if (func_8437ACB0(arg3, i, arg2, 0xB2) != 0) {
                            var_s1 -= sp6C * 5;
                        }

                        if (((temp_s4->unk_02 != 0xA5) && ((func_843776FC(temp_fp, temp_s4, 0x9C) == 2) ||
                                                           (func_843776FC(temp_fp, temp_s4, 0x72) == 2))) ||
                            (func_8437AC20(arg3, arg2, 0xFF) != 0)) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    if (temp_s3->unk_2E >= temp_s6->unk_2E) {
                        var_s1 += spB7 * 6;
                    }
                    var_s1 += spB7 * 6;
                }
                break;

            case 0x7:
                if (arg4) {
                    if (func_843783CC(arg0) != 0) {
                        spFC = 1;
                        spF8 = 1;
                    }
                } else {
                    var_s1 += sp6C * 5;
                }
                break;

            case 0x8:
                temp_s3 = &temp_s4->unk_12;
                if (!(temp_s3->unk_15 & 7)) {
                    spF8 = 1;
                }
                break;

            case 0x9:
                temp_s3 = &temp_s4->unk_12;
                if (temp_s3) {}

                if ((temp_s6->unk_2E >= temp_s3->unk_2E) && (temp_s3->unk_58 == 0)) {
                    spF8 = 1;
                }
                break;

            case 0x32:
                if (temp_s6->unk_5C[0] < 0xC) {
                    var_s5 = 2;
                }

            case 0xA:
                if (arg4) {
                    if ((temp_s6->unk_5C[0] < 0xD) && (temp_s6->unk_2A < 0x3E7)) {
                        var_s0 = 1;
                        var_s1 += spB7 * 6;
                        if (temp_s7->unk_14 >= 0x9A) {
                            var_s1 -= sp6C * 6;
                        } else if (func_843776FC(temp_fp, temp_fp, 0x3F) != 0) {
                            var_s1 += spBA * 5;
                        }

                        if (temp_s7->unk_14 == 0xFF) {
                            var_s1 -= sp6C * 6;
                        }

                        var_s1 *= (0xD - temp_s6->unk_5C[0]) / 12.0f;
                        for (j = 0; j < arg2; j++) {
                            temp_v0_4 = &arg3[j];
                            if ((D_80072B00[temp_v0_4->unk_00 - 1].unk_03 < 0xA) && (temp_v0_4->unk_0A != 0)) {
                                var_s0 = 0;
                            }
                        }

                        if (var_s0 != 0) {
                            var_s1 = 1;
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) && (temp_s4->unk_02 != 0xA5)) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    if (func_843776FC(temp_fp, temp_fp, 0x3F) != 0) {
                        var_s1 += spBA * 5;
                    }
                    var_s0 = 1;
                    var_s1 += spB7 * 4;

                    for (j = 0; j < arg2; j++) {
                        temp_v0_5 = &arg3[j];
                        if ((D_80072B00[temp_v0_5->unk_00 - 1].unk_03 < 0xA) && (temp_v0_5->unk_0A != 0)) {
                            var_s0 = 0;
                        }
                    }

                    if (var_s0 != 0) {
                        var_s1 = 1;
                    }
                }
                var_s1 *= var_s5;
                break;

            case 0x33:
                if (temp_s6->unk_5C[1] < 0xC) {
                    var_s5 = 2;
                }

            case 0xB:
                if (arg4) {
                    if ((temp_s6->unk_5C[1] < 0xD) && (temp_s6->unk_2C < 0x3E7)) {
                        var_s1 += spB6 * 6;
                        if (temp_s7->unk_14 >= 0x9A) {
                            var_s1 -= sp6C * 6;
                        } else if (D_80072B00[temp_s7->unk_05 - 1].unk_03 < 0xA) {
                            var_s1 += spB6 * 6;
                        }

                        if (temp_s7->unk_14 == 0xFF) {
                            var_s1 -= sp6C * 6;
                        }

                        var_s1 *= (0xD - temp_s6->unk_5C[1]) / 12.0f;
                        if ((func_843783CC(arg1) != 0) && (temp_s4->unk_12.unk_15 & 0x20)) {
                            var_s1 = 1;
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) && (temp_s4->unk_02 != 0xA5)) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    if (D_80072B00[temp_s7->unk_05 - 1].unk_03 < 0xA) {
                        var_s1 += spB6 * 4;
                    }
                    var_s1 += spB6 * 4;
                }
                var_s1 *= var_s5;
                break;

            case 0x34:
                if (temp_s6->unk_5C[2] < 0xC) {
                    var_s5 = 2;
                }

                if (arg4) {
                    temp_s3 = &temp_s4->unk_12;

                    if ((temp_s6->unk_5C[2] < 0xD) && ((temp_s6->unk_2E < 0x3E7) != 0)) {
                        if (temp_s3->unk_2E >= temp_s6->unk_2E) {
                            var_s1 += spB7 * 3;
                            if (temp_s3->unk_2E < func_8437731C(temp_s6)) {
                                if (func_843779C8(temp_fp, temp_fp, 1, &sp104) == 2) {
                                    var_s1 += spBA * 3;
                                }

                                if (func_843779C8(temp_fp, temp_s4, 1, &sp104) == 2) {
                                    var_s1 += spB6 * 3;
                                }
                            }
                        }

                        if (temp_s7->unk_14 >= 0x9A) {
                            var_s1 -= sp6C * 3 * var_s5;
                        }

                        if (temp_s7->unk_14 == 0xFF) {
                            var_s1 -= sp6C * 3 * var_s5;
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) && (temp_s4->unk_02 != 0xA5)) {
                            var_s1 = 1;
                        }

                        if ((func_843783CC(arg1) != 0) && (func_8437731C(temp_s6) < temp_s3->unk_2E)) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    if (func_843779C8(temp_fp, temp_fp, 1, &sp104) != 0) {
                        var_s1 += spBA * 5;
                    }
                    var_s1 += spB7 * 3;
                }
                var_s1 *= var_s5;
                break;

            case 0x35:
                if (temp_s6->unk_5C[3] < 0xC) {
                    var_s5 = 2;
                }

            case 0xD:
                if (arg4) {
                    if ((temp_s6->unk_5C[3] < 0xD) && (temp_s6->unk_30 < 0x3E7)) {
                        var_s1 += spB7 * 7;
                        if (temp_s7->unk_14 >= 0x9A) {
                            var_s1 -= sp6C * 7;
                        } else if (D_80072B00[temp_s7->unk_05 - 1].unk_03 >= 0xB) {
                            var_s1 += spB6 * 7;
                        }

                        if (temp_s7->unk_14 == 0xFF) {
                            var_s1 -= sp6C * 7;
                        }

                        var_s1 *= (0xD - temp_s6->unk_5C[3]) / 12.0f;
                        if ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) && (temp_s4->unk_02 != 0xA5)) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    if (D_80072B00[temp_s7->unk_05 - 1].unk_03 >= 0xB) {
                        var_s1 += spB6 * 2;
                    }
                    var_s1 += (spB7 * 2) + (spB6 * 3);
                }
                var_s1 *= var_s5;
                break;

            case 0xF:
                temp_s3 = &temp_s4->unk_12;

                if (arg4) {
                    if (temp_s6->unk_5C[5] < 0xD) {
                        var_s1 += spB6 * 7;
                        if (func_843779C8(temp_fp, temp_s4, 0, &sp104) != 0) {
                            var_s1 += (spB6 * 7) / 2;
                        }

                        if ((temp_s6->unk_15 & 8) || (temp_s6->unk_4D & 0x80)) {
                            var_s1 /= 2;
                        }

                        if (temp_s6->unk_4E & 1) {
                            var_s1 /= 2;
                        }

                        if ((func_843783CC(arg1) != 0) && (temp_s3->unk_15 & 0x20)) {
                            var_s1 = 1;
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) && (temp_s4->unk_02 != 0xA5)) {
                            var_s1 = 1;
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x81) == 2) && (temp_s7->unk_05 == 0x81)) {
                            var_s1 = 1;
                        }
                        var_s1 *= (0xD - temp_s6->unk_5C[5]) / 12.0f;
                    } else {
                        spF8 = 1;
                    }
                } else {
                    var_s1 += spB6 * 7;
                }
                break;

            case 0x12:
            case 0x44:
                temp_s3 = &temp_s4->unk_12;

                if (arg4) {
                    if ((temp_s3->unk_5C[0] >= 2) && (temp_s3->unk_2A >= 2)) {
                        var_s1 += spB6 * 5;
                        if (func_8437ACB0(arg3, i, arg2, 0x99) != 0) {
                            var_s1 -= sp6C * 5;
                        }

                        if ((temp_s7->unk_14 >= 0x9A) && (func_843783CC(arg0) != 0)) {
                            var_s1 -= sp6C * 5;
                        }

                        var_s1 *= (temp_s3->unk_5C[0] - 1) / 12.0f;
                        if (func_8437AC20(arg3, arg2, 0xFF) != 0) {
                            var_s1 = 1;
                        }

                        if ((func_843783CC(arg1) != 0) && (temp_s3->unk_15 & 0x20)) {
                            var_s1 = 1;
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) && (temp_s4->unk_02 != 0xA5)) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    var_s1 += spB6 * 4;
                }
                break;

            case 0x3B:
                if (temp_s4->unk_12.unk_5C[1] >= 3) {
                    var_s5 = 2;
                }

            case 0x13:
            case 0x45:
                temp_s3 = &temp_s4->unk_12;

                if (arg4) {
                    if ((temp_s3->unk_5C[1] >= 2) && (temp_s3->unk_2C >= 2)) {
                        var_s1 += spB7 * 5;
                        if (temp_s3->unk_4C & 0x80) {
                            var_s1 += spBA * 5;
                        }

                        if ((temp_s7->unk_14 >= 0x9A) && (func_843783CC(arg0) != 0)) {
                            var_s1 -= sp6C * 5;
                        }

                        if (func_8437ACB0(arg3, i, arg2, 0x99) != 0) {
                            var_s1 -= sp6C * 5;
                        }

                        var_s1 *= (temp_s3->unk_5C[1] - 1) / 12.0f;
                        if (func_8437AC20(arg3, arg2, 0xFF) != 0) {
                            var_s1 = 1;
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) && (temp_s4->unk_02 != 0xA5)) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    var_s1 += spB7 * 4;
                }
                var_s1 *= var_s5;
                break;

            case 0x14:
            case 0x46:
                temp_s3 = &temp_s4->unk_12;

                if (arg4) {
                    if ((temp_s3->unk_5C[2] >= 2) && ((temp_s3->unk_2E < 2) == 0)) {
                        if (temp_s3->unk_2E >= temp_s6->unk_2E) {
                            var_s1 += spB7 * 3;
                            if (func_84377354(temp_s3) < temp_s6->unk_2E) {
                                if (func_843779C8(temp_fp, temp_fp, 1, &sp104) == 2) {
                                    var_s1 += spBA * 3;
                                }

                                if (func_843779C8(temp_fp, temp_s4, 1, &sp104) == 2) {
                                    var_s1 += spB6 * 3;
                                }
                            }
                        }

                        if (func_84377FA4(temp_fp, arg0, &sp103, 1, &sp104) != 0) {
                            if ((func_84377354(temp_s3) < arg0->unk_14[sp103].unk_12.unk_2E) &&
                                (temp_s3->unk_2E >= arg0->unk_14[sp103].unk_12.unk_2E)) {
                                var_s1 += spBA * 3;
                            }
                        }

                        if (func_8437ACB0(arg3, i, arg2, 0x99) != 0) {
                            var_s1 -= sp6C * 3;
                        }

                        if (func_8437AC20(arg3, arg2, 0xFF) != 0) {
                            var_s1 = 1;
                        }

                        if ((func_843783CC(arg0) != 0) && (temp_s6->unk_2E < func_84377354(temp_s3))) {
                            var_s1 = 1;
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) && (temp_s4->unk_02 != 0xA5)) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    if (func_843779C8(temp_fp, temp_fp, 1, &sp104) != 0) {
                        var_s1 += spBA * 5;
                    }
                    var_s1 += spB7 * 3;
                }
                break;

            case 0x47:
                temp_s3 = &temp_s4->unk_12;

                if (arg4) {
                    if ((temp_s3->unk_5C[3] >= 2) && (temp_s3->unk_30 >= 2)) {
                        var_s1 += (spB7 * 7);
                        var_s1 += (spB6 * 7);
                        if (func_8437ACB0(arg3, i, arg2, 0x99) != 0) {
                            var_s1 -= sp6C * 7;
                        } else if (D_80072B00[temp_s7->unk_05 - 1].unk_03 >= 0xB) {
                            var_s1 += spB6 * 7;
                        }

                        if (func_8437AC20(arg3, arg2, 0xFF) != 0) {
                            var_s1 -= sp6C * 7;
                        }

                        var_s1 *= (temp_s3->unk_5C[3] - 1) / 12.0f;
                        if ((func_843783CC(arg0) != 0) && (temp_s7->unk_14 >= 0xE7)) {
                            var_s1 = 1;
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) && (temp_s4->unk_02 != 0xA5)) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    var_s1 += (spB7 * 2) + (spB6 * 3);
                }
                break;

            case 0x16:
            case 0x48:
                temp_s3 = &temp_s4->unk_12;

                if (arg4) {
                    if (temp_s3->unk_5C[4] >= 2) {
                        var_s1 += spB6 * 6;
                        if (func_8437ACB0(arg3, i, arg2, 0x99) != 0) {
                            var_s1 -= sp6C * 7;
                        }

                        if ((temp_s3->unk_15 & 8) || (temp_s3->unk_4D & 0x80)) {
                            var_s1 *= 2;
                        }

                        var_s1 *= (temp_s3->unk_5C[4] - 1) / 12.0f;
                        if ((func_843783CC(arg1) != 0) && (temp_s3->unk_15 & 0x20)) {
                            var_s1 = 1;
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) && (temp_s4->unk_02 != 0xA5)) {
                            var_s1 = 1;
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x81) == 2) && (temp_s7->unk_05 == 0x81)) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    var_s1 += spB6 * 6;
                }
                break;

            case 0x18:
                temp_s3 = &temp_s4->unk_12;

                if (arg4) {
                    if ((temp_s3->unk_16[6] != temp_s6->unk_16[6]) || (temp_s3->unk_16[7] != temp_s6->unk_16[7])) {
                        var_s1 += spB4 * 3;
                        sp8C = func_8437738C(D_80072B00[temp_s7->unk_05 - 1].unk_03, temp_s6);
                        if ((sp8C - func_8437738C(D_80072B00[temp_s7->unk_05 - 1].unk_03, temp_s3)) > 0.0) {
                            var_s1 += spB6 * 3;
                        }

                        if (temp_s7->unk_14 >= 0x9A) {
                            var_s1 -= sp6C * 3;
                        }
                    }
                } else if ((temp_s3->unk_16[6] != temp_s6->unk_16[6]) || (temp_s3->unk_16[7] != temp_s6->unk_16[7])) {
                    var_s1 += spB4 * 3;
                }
                break;

            case 0x19:
                temp_s3 = &temp_s4->unk_12;

                if (arg4) {
                    var_s0 = 0;
                    switch (temp_s6->unk_15) {
                        case 0x0:
                            break;

                        case 0x8:
                            var_s1 += spB6 * 2;
                            if (temp_s6->unk_4E & 1) {
                                var_s1 += spB6;
                            }
                            goto case_20;

                        case 0x10:
                            var_s1 += spB6 * 2;
                            var_s0 = 1;
                            goto case_20;

                        case 0x40:
                            var_s1 += spB6 * 5;

                        default:
                        case 0x20:
                        case_20:
                            var_s0 = 1;
                            break;
                    }

                    if (temp_s3->unk_15 != 0) {
                        var_s0 = 1;
                        switch (temp_s6->unk_15) {
                            case 8:
                                var_s1 -= spB7 * 2;
                                if (temp_s6->unk_4E & 1) {
                                    var_s1 -= spB7 / 2;
                                }
                                break;

                            case 16:
                                var_s1 -= (spB7 * 2) / 2;
                                break;

                            case 32:
                                var_s1 = 1;
                                break;

                            case 64:
                                var_s1 -= (spB7 * 5);
                                break;

                            default:
                                var_s1 -= (spB7 * 5) / 2;
                        }
                    }

                    if (temp_s6->unk_5C[0] != 7) {
                        var_s1 = (var_s1 + (temp_s6->unk_5C[0] * 6)) - 0x2A;
                        var_s0 = 1;
                    }

                    if (temp_s6->unk_5C[1] != 7) {
                        var_s1 = (var_s1 + (temp_s6->unk_5C[1] * 6)) - 0x2A;
                        var_s0 = 1;
                    }

                    if (temp_s6->unk_5C[2] != 7) {
                        var_s1 = (var_s1 + (temp_s6->unk_5C[2] * 3)) - 0x15;
                        var_s0 = 1;
                    }

                    if (temp_s6->unk_5C[3] != 7) {
                        var_s1 = (var_s1 + (temp_s6->unk_5C[3] * 7)) - 0x31;
                        var_s0 = 1;
                    }

                    if (temp_s6->unk_5C[5] != 7) {
                        var_s1 = (var_s1 + (temp_s6->unk_5C[4] * 7)) - 0x31;
                        var_s0 = 1;
                    }

                    if (temp_s3->unk_5C[0] != 7) {
                        var_s1 = (var_s1 - (temp_s3->unk_5C[0] * 5)) + 0x23;
                        var_s0 = 1;
                    }

                    if (temp_s3->unk_5C[1] != 7) {
                        var_s1 = (var_s1 - (temp_s3->unk_5C[1] * 5)) + 0x23;
                        var_s0 = 1;
                    }

                    if (temp_s3->unk_5C[2] != 7) {
                        var_s1 = (var_s1 - (temp_s3->unk_5C[2] * 3)) + 0x15;
                        var_s0 = 1;
                    }

                    if (temp_s3->unk_5C[3] != 7) {
                        var_s1 = (var_s1 - (temp_s3->unk_5C[3] * 7)) + 0x31;
                        var_s0 = 1;
                    }

                    if (temp_s3->unk_5C[4] != 7) {
                        var_s1 = (var_s1 - (temp_s3->unk_5C[4] * 6)) + 0x2A;
                        var_s0 = 1;
                    }

                    if (var_s0 == 0) {
                        spF8 = 1;
                    }
                } else {
                    var_s1 += spB6 * 5;
                }
                break;

            case 0x1A:
                temp_s3 = &temp_s4->unk_12;

                if (arg4) {
                    if (temp_s3->unk_4C & 0x80) {
                        var_s1 += spBA * 3;
                        if (func_8437ACB0(arg3, i, arg2, 0x99) != 0) {
                            var_s1 -= sp6C * 3;
                        }

                        if (temp_s7->unk_14 >= 0x81) {
                            var_s1 = 1;
                        }
                    }

                    if ((func_843783CC(arg1) != 0) && (temp_s3->unk_15 & 0x20)) {
                        var_s1 = 1;
                    }
                }
                break;

            case 0x2E:
                if (arg4) {
                    if (!(temp_s6->unk_4D & 2)) {
                        for (j = 0; j < 6; j++) {
                            if (temp_s6->unk_5C[j] < 6) {
                                break;
                            }
                        }

                        if (!(((f32)temp_s6->unk_0C / temp_s6->unk_28) < ((D_843C5564->unk_08 + 0x33) / 255.0f))) {
                            var_s1 += spB6 * 2;
                            if ((func_843783CC(arg1) != 0) && (temp_s4->unk_12.unk_15 & 0x20)) {
                                var_s1 = 1;
                            }
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    var_s1 += spB6 * 3;
                }
                break;

            case 0x2F:
                if (arg4) {
                    if (!(temp_s6->unk_4D & 4)) {
                        if (D_8438AC60[0] == 1) {
                            var_s1 += spB7 * 3;
                            if (temp_s7->unk_14 >= 0x9A) {
                                var_s1 -= sp6C * 3;
                            }
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) && (temp_s4->unk_02 != 0xA5)) {
                            var_s1 /= 2;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else if (D_8438AC60[0] == 1) {
                    var_s1 += spB7 * 3;
                }
                break;

            case 0x31:
                temp_s3 = &temp_s4->unk_12;

                if (arg4) {
                    if (!(temp_s3->unk_4C & 0x80) && !(temp_s3->unk_4D & 0x10)) {
                        var_s1 += spB7 * 4;
                        if ((func_843776FC(temp_fp, temp_fp, 0x75) != 0) ||
                            (func_843776FC(temp_fp, temp_fp, 0x44) != 0) ||
                            (func_843779C8(temp_fp, temp_fp, 0x15, &sp104) != 0)) {
                            var_s1 += spBA * 4;
                        }

                        if (func_8437ACB0(arg3, i, arg2, 0x99) != 0) {
                            var_s1 -= sp6C * 4;
                        }

                        if (func_8437AC20(arg3, arg2, 0xFF) != 0) {
                            var_s1 = 1;
                        }

                        if ((func_843783CC(arg1) != 0) && (temp_s3->unk_15 & 0x20)) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    var_s1 += spB6 * 4;
                }
                break;

            case 0x38:
                if (arg4) {
                    if (temp_s6->unk_0C != temp_s6->unk_28) {
                        var_s1 = 1;
                        switch (temp_s7->unk_00) {
                            case 0x69:
                            case 0x87:
                                temp_s3 = &temp_s4->unk_12;
                                if (temp_s3) {}
                                if ((temp_s3->unk_2E < temp_s6->unk_2E) ||
                                    ((temp_s6->unk_2E == temp_s3->unk_2E) && (func_843767E4(1) != 0))) {
                                    if (func_84377068(temp_s6->unk_0C - temp_s7->unk_16, temp_s6->unk_28) >=
                                        (D_843C5564->unk_08 + 0x33)) {
                                        if ((func_843776FC(temp_fp, temp_s4, 0x62) != 0) && (func_843767E4(1) != 0)) {
                                            var_v1_4 = func_8437865C(temp_s3, temp_s6, 0x62);
                                        } else {
                                            var_v1_4 = 0;
                                        }

                                        if (((((temp_s6->unk_0C - temp_s7->unk_16) - temp_s7->unk_12) - var_v1_4) >=
                                             0) ||
                                            (func_8437AC20(arg3, arg2, 0xFF) != 0)) {
                                            break;
                                        }
                                    }
                                    var_s1 = (spB6 * 7) + 1;
                                } else if (func_84377068((temp_s6->unk_0C - temp_s7->unk_12) - temp_s7->unk_16,
                                                         temp_s6->unk_28) < (D_843C5564->unk_08 + 0x33)) {
                                    var_s1 = (spB6 * 7) + 1;
                                }
                                break;

                            case 0x9C:
                                temp_s3 = &temp_s4->unk_12;
                                if (temp_s3) {}

                                if ((temp_s3->unk_2E < temp_s6->unk_2E) ||
                                    ((temp_s3->unk_2E == temp_s6->unk_2E) && (func_843767E4(1) != 0))) {
                                    if (func_84377068(temp_s6->unk_0C - temp_s7->unk_16, temp_s6->unk_28) >=
                                        (D_843C5564->unk_08 - 0x33)) {
                                        if ((func_843776FC(temp_fp, temp_s4, 0x62) != 0) && (func_843767E4(1) != 0)) {
                                            var_v1_5 = func_8437865C(temp_s3, temp_s6, 0x62);
                                        } else {
                                            var_v1_5 = 0;
                                        }

                                        if ((((temp_s6->unk_0C - temp_s7->unk_16) - temp_s7->unk_12) - var_v1_5) >= 0) {
                                            goto end;
                                        }

                                        if (func_8437AC20(arg3, arg2, 0xFF) != 0) {
                                            goto end;
                                        }
                                    }
                                    var_s1 = (spB6 * 7) + 1;

                                } else {
                                    if (func_84377068((temp_s6->unk_0C - temp_s7->unk_12) - temp_s7->unk_16,
                                                      temp_s6->unk_28) < (D_843C5564->unk_08 - 0x33)) {
                                        var_s1 = (spB6 * 7) + 1;
                                    }

                                    if ((func_843779C8(temp_fp, temp_s4, 1, &sp104) == 2) && (temp_s6->unk_15 & 0x40)) {
                                        var_s1 += spB6 * 7;
                                    }
                                }
                            end:
                                if ((temp_s6->unk_15 != 8) && (temp_s6->unk_15 != 0x10) && (temp_s6->unk_15 == 0x40)) {
                                    var_s1 += spB6 * 6;
                                    sp70 = spB6;
                                    if ((func_843779C8(temp_fp, temp_s4, 1, &sp104) == 2) &&
                                        (temp_s6->unk_2E < temp_s3->unk_2E)) {
                                        var_s1 += sp70 * 7;
                                    }
                                }

                                if (temp_s7->unk_14 >= 0x81) {
                                    var_s1 >>= 1;
                                }
                                break;
                        }

                        if (func_843783CC(arg0) != 0) {
                            var_s1 *= 2;
                        }

                        if (temp_s7->unk_14 >= 0x81) {
                            var_s1 >>= 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    var_s1 += spB6 * 8;
                }
                break;

            case 0x39:
                temp_s3 = &temp_s4->unk_12;
                if (temp_s3) {}

                if (((temp_s3->unk_4E & 8) != 0) || (temp_s3->unk_0B == 0x84)) {
                    if ((temp_s3->unk_4E & 8) != 0) {
                        if (temp_s3 == D_843C60B8) {
                            var_v1_6 = (D_84390010[0]->unk_654.unk_BE ^ 0x84) != 0;
                        } else {
                            var_v1_6 = (D_84390010[1]->unk_654.unk_BE ^ 0x84) != 0;
                        }

                        if (var_v1_6 == 0) {
                            break;
                        }
                    }
                }
                var_s1 += spB4 * 3;
                break;

            case 0x40:
                if (arg4) {
                    if (!(temp_s6->unk_4E & 2)) {
                        var_s1 += spB6 * 7;
                        if (D_80072B00[temp_s7->unk_05 - 1].unk_03 >= 0xB) {
                            var_s1 += spB6 * 7;
                        }

                        if (temp_s7->unk_14 >= 0x9A) {
                            var_s1 -= sp6C * 7;
                        }

                        if (temp_s7->unk_14 == 0xFF) {
                            var_s1 -= sp6C * 7;
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) && (temp_s4->unk_02 != 0xA5)) {
                            var_s1 = 1;
                        }

                        if ((func_843783CC(arg1) != 0) && (temp_s4->unk_12.unk_15 & 0x20)) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    if (D_80072B00[temp_s7->unk_05 - 1].unk_03 >= 0xB) {
                        var_s1 += spB6 * 3;
                    }
                    var_s1 += spB6 * 3;
                }
                break;

            case 0x41:
                if (arg4) {
                    if (!(temp_s6->unk_4E & 4)) {
                        var_s1 += spB6 * 6;
                        if (D_80072B00[temp_s7->unk_05 - 1].unk_03 < 0xA) {
                            var_s1 += spB6 * 6;
                        }

                        if (temp_s7->unk_14 >= 0x9A) {
                            var_s1 -= sp6C * 6;
                        }

                        if (temp_s7->unk_14 == 0xFF) {
                            var_s1 -= sp6C * 6;
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) && (temp_s4->unk_02 != 0xA5)) {
                            var_s1 = 1;
                        }

                        if ((func_843783CC(arg1) != 0) && (temp_s4->unk_12.unk_15 & 0x20)) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    if (D_80072B00[temp_s7->unk_05 - 1].unk_03 < 0xA) {
                        var_s1 += spB6 * 3;
                    }
                    var_s1 += spB6 * 3;
                }
                break;

            case 0x4F:
                if (((temp_s6->unk_28 >> 2) < temp_s6->unk_0C) && !(temp_s6->unk_4D & 0x10)) {
                    if ((func_843783CC(arg0) != 0) && (func_843776FC(temp_fp, temp_s4, 0x90) == 0)) {
                        if (((D_843C60BC == 0) || ((D_843C60BC != 0) && (temp_s4->unk_12.unk_2E >= temp_s6->unk_2E))) &&
                            (temp_s6->unk_15 == 0) &&
                            ((func_843779C8(temp_fp, temp_s4, 4, &sp104) == 2) ||
                             ((func_843779C8(temp_fp, temp_s4, 4, &sp104) == 1) && (func_843767E4(2) != 0)))) {
                            var_s1 += spB6 * 7;
                            if (func_8437828C(temp_fp, temp_s4) != 0) {
                                var_s1 += spB6 * 7;
                            }
                        }

                        if (func_84377068(temp_s7->unk_12, temp_s6->unk_28) < 0x3F) {
                            var_s1 += spB6 * 7;
                            if (func_843779C8(temp_fp, temp_fp, 2, &sp104) == 2) {
                                var_s1 += spB6 * 7;
                            }
                        }

                        if (func_843779C8(temp_fp, temp_s4, 1, &sp104) == 2) {
                            var_s1 += spB6 * 7;
                        }
                    } else {
                        var_s1 = 1;
                    }
                } else {
                    spF8 = 1;
                }
                break;

            case 0x52:
                if (arg4) {
                    var_s1 += spB4 * 3;
                    if (func_8437ACB0(arg3, i, arg2, 0xB2) != 0) {
                        var_s1 -= sp6C * 3;
                    }

                    if ((temp_s7->unk_14 >= 0xFB) && (temp_s6->unk_2E < temp_s4->unk_12.unk_2E)) {
                        var_s1 -= sp6C * 3;
                    }
                } else {
                    var_s1 += spB4 * 3;
                }
                break;

            case 0x53:
                if (arg4) {
                    if (func_8437ACB0(arg3, i, arg2, 0) == 0) {
                        var_s1 += sp6C * 3;
                    }

                    var_s1 += spB4 * 3;
                    if (func_8437ACB0(arg3, i, arg2, 0xB2) != 0) {
                        var_s1 -= sp6C * 3;
                    }
                } else {
                    var_s1 += spB4 * 3;
                }
                break;

            case 0x54:
                temp_s3 = &temp_s4->unk_12;

                if (arg4) {
                    if ((temp_s3->unk_16[6] != 0x16) && (temp_s3->unk_16[7] != 0x16) && !(temp_s3->unk_4D & 0x90)) {
                        var_s1 += (spB7 * 3) + (spB6 * 3);
                        if (temp_s3->unk_4E & 1) {
                            var_s1 += spBA * 3;
                        }

                        if ((temp_s7->unk_14 >= 0x9A) && (func_843783CC(arg0) != 0)) {
                            var_s1 -= sp6C * 3;
                        }

                        if (func_843779C8(temp_fp, temp_s4, 0, &sp104) != 0) {
                            var_s1 -= sp6C * 3;
                        }

                        if (func_8437ACB0(arg3, i, arg2, 0x99) != 0) {
                            var_s1 -= sp6C * 3;
                        }

                        if (func_8437AC20(arg3, arg2, 0xFF) != 0) {
                            var_s1 = 1;
                        }

                        if ((func_843776FC(temp_fp, temp_s4, 0x72) == 2) && (temp_s4->unk_02 != 0xA5)) {
                            var_s1 = 1;
                        }
                    } else {
                        spF8 = 1;
                    }
                } else {
                    var_s1 += (spB7 * 3) + (spB6 * 3);
                }
                break;

            case 0x56:
                if ((arg4 != 0) && (temp_s4->unk_12.unk_57 != 0)) {
                    spF8 = 1;
                }
                break;
        }

        var_s0_4 = CLAMP_MAX(temp_s7->unk_01 + sp58, 0xFF);
        spC0 = CLAMP_MIN(temp_s7->unk_06 - sp58, 0);
        var_s2 = CLAMP_MIN(temp_s7->unk_08 - sp58, 0);

        if ((temp_s4->unk_03 != 0) && (sp9C->unk_03 < 2) && (temp_s7->unk_0C < 0xFF)) {
            var_s0_4 *= ((func_843767E4(3) * 0x55) / 255.0f);
        }

        if ((temp_s7->unk_00 == 0x44) && (temp_fp->unk_03 != 0) && !(temp_s4->unk_12.unk_4C & 0x80)) {
            var_s0_4 = (func_843767E4(2) * var_s0_4) / 2;
        }

        temp_s7->unk_01 = var_s0_4;
        temp_s7->unk_06 = spC0;
        temp_s7->unk_08 = var_s2;

        if (((temp_s7->unk_03 >= 0x12) && (temp_s7->unk_03 < 0x1A)) ||
            ((temp_s7->unk_03 >= 0x3A) && (temp_s7->unk_03 < 0x42))) {
            temp_s3 = &temp_s4->unk_12;
            if (temp_s3) {}

            if (temp_s3->unk_4D & 0x12) {
                var_s1 = 0;
            }

            if ((temp_s3->unk_2E < temp_s6->unk_2E) && (temp_s3->unk_0B == 0x84)) {
                var_s1 = 1;
            }
        }

        if (sp9C->unk_02 != 0) {
            if (func_8437738C(sp9C->unk_03, &temp_s4->unk_12) == 0.0f) {
                var_s1 = 0;
            }
        }

        if ((var_s1 < 0) || (spF8 != 0)) {
            var_s1 = 0;
        }

        temp_s7->unk_24 = var_s1;

        tmp1 = temp_s7->unk_0C * sp54;
        tmp2 = temp_s7->unk_10 * sp54;
        tmp3 = temp_s7->unk_04 * var_s1;
        tmp4 = temp_s7->unk_14 * sp50;
        tmp5 = temp_s7->unk_18 * sp50;
        tmp6 = temp_s7->unk_1C * sp50;
        tmp7 = temp_s7->unk_20 * sp50;

        temp_s7->unk_28 = (((((tmp1 + tmp6 + tmp3) * (var_s0_4 / 255.0f)) + tmp2) - (tmp4 * (spC0 / 255.0f))) - tmp5) -
                          (tmp7 * (var_s2 / 255.0f));

        if (arg4) {
            if (!(D_843C5564->unk_00 & 0x30)) {
                temp_s7->unk_28 = func_843767E4(0xFE) + 1;
                if (D_80072B00[temp_s7->unk_00 - 1].unk_02 == 0) {
                    if (spF8 != 0) {
                        temp_s7->unk_28 = 0;
                    }
                } else {
                    if ((D_80072B00[temp_s7->unk_00 - 1].unk_01 != 0x28) &&
                        (D_80072B00[temp_s7->unk_00 - 1].unk_01 != 0x29) &&
                        (func_8437738C(D_80072B00[temp_s7->unk_00 - 1].unk_03, &temp_s4->unk_12) == 0.0f)) {
                        temp_s7->unk_28 = 0;
                    }

                    if (spFC != 0) {
                        temp_s7->unk_28 = -1;
                    }
                }
            } else if ((spFC != 0) || (temp_s6->unk_32[i] <= 0) ||
                       ((spF8 != 0) && ((sp9C->unk_02 == 0) || (temp_s7->unk_0A == 0))) ||
                       ((sp9C->unk_02 != 0) && (func_8437738C(sp9C->unk_03, &temp_s4->unk_12) == 0.0f))) {
                temp_s7->unk_28 = -0x06666666;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/62/fragment62_361050/func_8437B0CC.s")
#endif

s32 func_8437E3B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg1 < arg0) {
        return 1;
    }

    if (arg0 == arg1) {
        if (D_843C5564->unk_00 & 0x1000) {
            if (arg3 < arg2) {
                return 1;
            }

            if ((arg2 == arg3) && (func_843767E4(1) != 0)) {
                return 1;
            }
        } else if (func_843767E4(1) != 0) {
            return 1;
        }
    }
    return 0;
}

s32 func_8437E448(unk_D_843C60AC* arg0, UNUSED unk_D_843C60AC* arg1, u8 arg2, unk_func_843794CC* arg3) {
    u8 i;
    s32 sp70;
    s32 sp6C;
    unk_D_800FCB18* ptr;
    s32 var_s3;
    s32 var_s4;
    s32 var_s2;
    u8 sp5B;
    u8 var_v1;
    s32 var_s5;
    s32 tmp;

    sp5B = D_843C5564->unk_06;
    if ((D_843C5564->unk_00 & 0x200000) && (arg0->unk_04 != 1) && (arg0->unk_12.unk_32[0] > 0)) {
        return 0;
    }

    var_s2 = 0x80000002;
    var_s3 = 0x80000002;
    var_s4 = 0x80000002;
    var_s5 = 0x80000002;
    sp6C = 0;
    sp70 = ptr->unk_57 * 0;

    D_843C60C0[D_843C60E8].unk_02 = arg2;

    ptr = &arg0->unk_12;
    for (i = 0; i < arg2; i++) {
        D_843C60C0[D_843C60E8].unk_04[i] = arg3[i].unk_28;

        if ((ptr->unk_32[i] > 0) && (arg3[i].unk_00 != ptr->unk_57)) {
            if (func_8437E3B4(arg3[i].unk_28, var_s5, arg3[i].unk_0A, var_s3) != 0) {
                var_s4 = var_s5;
                var_s2 = var_s3;
                var_s5 = arg3[i].unk_28;
                var_s3 = arg3[i].unk_0A;
                sp6C = sp70;
                sp70 = i;
            } else if (func_8437E3B4(arg3[i].unk_28, var_s4, arg3[i].unk_0A, var_s2) != 0) {
                var_s4 = arg3[i].unk_28;
                var_s2 = arg3[i].unk_0A;
                sp6C = i;
            }
        }
    }

    if (arg2 >= 2) {
        ptr = &arg0->unk_12;
        var_v1 = 0;
        for (i = 0; i < arg2; i++) {
            if ((ptr->unk_32[i] > 0) && (arg3[i].unk_03 != 0x38)) {
                var_v1 = 1;
            }
        }

        for (i = 0; i < arg2 - 1; i++) {
            if (arg3[i].unk_28 != arg3[i + 1].unk_28) {
                var_v1 = 0;
            }
        }

        if (var_v1) {
            ptr = &arg0->unk_12;
            do {
                if (D_843C5564->unk_06) {}
                i = func_843767E4(arg2 - 1);
            } while (arg3[i].unk_03 == 0x38 || ptr->unk_32[0, i] <= 0);

            if (sp6C == i) {
                sp6C = sp70;
                sp70 = i;
            }
        }
    }

    if (func_843767E4(0xFE) < sp5B) {
        tmp = arg0->unk_12.unk_32[sp6C];

        if ((tmp != 0) && (tmp > 0) && ((arg3[sp6C].unk_24 >= 2) || (arg3[sp6C].unk_0A != 0))) {
            return sp6C;
        }
    }
    return sp70;
}

s32 func_8437E7A4(void) {
    u8 i;
    unk_func_843794CC sp2C[4];

    for (i = 0; i < 4 && D_843C60B4->unk_1F[i] != 0; i++) {}

    func_843794CC(D_843C60AC, D_843C60B0, 0, 0, i, sp2C);
    func_8437B0CC(D_843C60A4, D_843C60A8, i, sp2C, 1);
    return func_8437E448(D_843C60AC, D_843C60B0, i, sp2C);
}

u16 func_8437E860(u8 arg0, u8 arg1) {
    u8 sp1C = (0xFF - D_843C5564->unk_04) / 17;
    u32 temp_t0 = (sp1C << 0xC) + 0xFFF;

    return (((((s32)sqrtf(temp_t0) / 4) + ((arg0 + sp1C) * 2)) * arg1) / 100) + 5;
}

u8 func_8437E920(u8 arg0) {
    u8 var_a1 = D_80072B00[arg0 - 1].unk_05;

    var_a1 += ((var_a1 / 5 >= 8) ? 7 : var_a1 / 5) * 3;
    return var_a1;
}

void func_8437E974(unk_D_800AE540_0004* arg0, unk_D_800AE540_0004* arg1, unk_D_843C60A4* arg2, u8 arg3) {
    u8 j;
    u8 k;
    u8 i;
    u8 var_v1;
    u8 sp73;
    unk_D_80070F84* sp6C;
    unk_func_80026268_arg0* sp64[2];
    unk_func_80026268_arg0* temp_s7;

    sp64[0] = arg0->unk_01C;
    if (arg1 != NULL) {
        sp64[1] = arg1->unk_01C;
    } else {
        sp64[1] = NULL;
    }

    for (i = 0; i < arg2->unk_00; i++) {
        temp_s7 = sp64[i];
        if (i) {
            var_v1 = arg2->unk_01[0];
        } else {
            var_v1 = 0;
        }

        for (j = 0; j < arg2->unk_01[i]; j++) {
            sp73 = temp_s7[j].unk_24;
            sp6C = &D_80070FA0[temp_s7[j].unk_00.unk_00 - 1];

            arg2->unk_14[j + var_v1].unk_00 = j;
            arg2->unk_14[j + var_v1].unk_04 = 0;
            arg2->unk_14[j + var_v1].unk_12.unk_0B = temp_s7[j].unk_00.unk_00;
            arg2->unk_14[j + var_v1].unk_12.unk_16[6] = temp_s7[j].unk_06;
            arg2->unk_14[j + var_v1].unk_12.unk_16[7] = temp_s7[j].unk_07;
            arg2->unk_14[j + var_v1].unk_12.unk_26 = temp_s7[j].unk_24;

            _bcopy(temp_s7[j].unk_09, &arg2->unk_14[j + var_v1].unk_12.unk_1F[0], 4);

            for (k = 0; k < 4; k++) {
                if (arg3) {
                    arg2->unk_14[j + var_v1].unk_12.unk_32[k] =
                        func_8437E920(arg2->unk_14[j + var_v1].unk_12.unk_1F[k]);
                } else {
                    arg2->unk_14[j + var_v1].unk_12.unk_32[k] = temp_s7[j].unk_20[k] & 0x3F;
                }
            }

            for (k = 0; k < 6; k++) {
                arg2->unk_14[j + var_v1].unk_12.unk_5C[k] = 7;
            }

            if (!arg3 && (D_843C5564->unk_00 & 0x02000000)) {
                arg2->unk_14[j + var_v1].unk_01 = 0xF0;
            } else {
                arg2->unk_14[j + var_v1].unk_01 = 0;
            }

            if (arg3) {
                arg2->unk_14[j + var_v1].unk_12.unk_28 = func_8437E860(sp6C->unk_01, sp73) + sp73 + 5;
            } else {
                arg2->unk_14[j + var_v1].unk_12.unk_28 = temp_s7[j].unk_26;
            }

            if (arg3) {
                arg2->unk_14[j + var_v1].unk_12.unk_2A = func_8437E860(sp6C->unk_02, sp73);
            } else {
                arg2->unk_14[j + var_v1].unk_12.unk_2A = temp_s7[j].unk_28;
            }

            if (arg3) {
                arg2->unk_14[j + var_v1].unk_12.unk_2C = func_8437E860(sp6C->unk_03, sp73);
            } else {
                arg2->unk_14[j + var_v1].unk_12.unk_2C = temp_s7[j].unk_2A;
            }

            if (arg3) {
                arg2->unk_14[j + var_v1].unk_12.unk_2E = func_8437E860(sp6C->unk_04, sp73);
            } else {
                arg2->unk_14[j + var_v1].unk_12.unk_2E = temp_s7[j].unk_2C;
            }

            if (arg3) {
                arg2->unk_14[j + var_v1].unk_12.unk_30 = func_8437E860(sp6C->unk_05, sp73);
            } else {
                arg2->unk_14[j + var_v1].unk_12.unk_30 = temp_s7[j].unk_2E;
            }

            arg2->unk_14[j + var_v1].unk_12.unk_0C = arg2->unk_14[j + var_v1].unk_12.unk_28;
            arg2->unk_14[j + var_v1].unk_12.unk_38 = arg2->unk_14[j + var_v1].unk_12.unk_2A;
            arg2->unk_14[j + var_v1].unk_12.unk_3A = arg2->unk_14[j + var_v1].unk_12.unk_2C;
            arg2->unk_14[j + var_v1].unk_12.unk_3C = arg2->unk_14[j + var_v1].unk_12.unk_2E;
            arg2->unk_14[j + var_v1].unk_12.unk_3E = arg2->unk_14[j + var_v1].unk_12.unk_30;
        }
    }
}

s32 func_8437ECFC(unk_D_843C60A4* arg0, u8* arg1, u8 arg2) {
    u8 i;
    s32 var_v1 = 1;

    for (i = 0; i < arg2; i++) {
        if (arg0->unk_11 == arg1[i]) {
            var_v1 = 0;
        }
    }

    return var_v1;
}

s32 func_8437ED54(unk_D_843C60A4* arg0, u8* arg1, u8 arg2, u8 arg3) {
    u8 i;
    s32 var_v1 = 0;

    for (i = 0; i < arg2; i++) {
        if (arg3 == arg1[i]) {
            var_v1 = 1;
        }
    }

    return var_v1;
}

s32 func_8437EDB8(unk_D_843C60A4* arg0, u8* arg1, u8 arg2, s32 arg3) {
    u8 i;
    u8 j;
    u8 k;
    u16 var_a2;
    u16 var_a3;
    u16 var_t0;
    u16 var_t1;
    s32 var_v1;
    s32 temp_t0;

    switch (arg3) {
        case 1:
        case 2:
        case 3:
            var_t0 = 0x32;
            var_a3 = 0x37;
            var_a2 = 0x9B;
            break;

        case 4:
            var_t0 = 0x19;
            var_a3 = 0x1E;
            var_a2 = 0x50;
            break;

        case 5:
            var_t0 = 0xF;
            var_a3 = 0x14;
            var_a2 = 0x32;
            break;

        default:
            return 1;
    }

    var_v1 = 0;

    for (i = 0; i < arg0->unk_03 - 2; i++) {
        for (j = i + 1; j < arg0->unk_03 - 1; j++) {
            for (k = j + 1; k < arg0->unk_03; k++) {
                if (var_a2 >=
                    (arg0->unk_14[i].unk_12.unk_26 + arg0->unk_14[j].unk_12.unk_26 + arg0->unk_14[k].unk_12.unk_26)) {
                    var_v1 = 1;
                }
            }
        }
    }

    if (var_v1 != 0) {
        var_t1 = 0;

        for (i = 0; i < arg2; i++) {
            temp_t0 = arg0->unk_14[arg1[i]].unk_12.unk_26;
            if (temp_t0 < var_t0) {
                return 0;
            }

            if (var_a3 < temp_t0) {
                return 0;
            }

            var_t1 += temp_t0;
        }

        if (var_a2 < var_t1) {
            return 0;
        }
    }

    return var_v1;
}

s32 func_8437EFBC(unk_D_843C60A4* arg0, u8* arg1, u8 arg2, u8 arg3) {
    s32 sp1C = 0;

    if (func_8437EDB8(arg0, arg1, arg2, arg3) != 0) {
        if (D_843C5564->unk_00 & 0x800000) {
            if (func_8437ED54(arg0, arg1, arg2, 0) != 0) {
                sp1C = 1;
            }
        } else if (D_843C5564->unk_00 & 0x100000) {
            if (func_8437ECFC(arg0, arg1, arg2) != 0) {
                sp1C = 1;
            }
        } else {
            sp1C = 1;
        }
    }
    return sp1C;
}

typedef struct unk_func_8437F068_sp28 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
} unk_func_8437F068_sp28; // size = 0x2

s32 func_8437F068(unk_D_843C60A4* arg0, u8* arg1, u8 arg2) {
    u8 i;
    u8 j;
    unk_func_8437F068_sp28 sp28[3];
    f32 var_fv0;
    s32 var_a2;
    unk_D_8438ACF0* var_a3;

    for (j = 0; j < arg2; j++) {
        sp28[j].unk_00 = arg0->unk_14[arg1[j]].unk_12.unk_16[6];
        sp28[j].unk_01 = arg0->unk_14[arg1[j]].unk_12.unk_16[7];
    }

    for (i = 0; i < 9; i++) {
        var_a2 = 0;

        for (j = 0; j < arg2; j++) {
            var_fv0 = 1.0f;

            var_a3 = &D_8438ACF0[0];
            while (var_a3->unk_00 != 0xFF) {
                if ((var_a3->unk_00 == i) &&
                    ((var_a3->unk_01 == sp28[j].unk_00) || (var_a3->unk_01 == sp28[j].unk_01))) {
                    var_fv0 = (var_a3->unk_02 * var_fv0) / 10.0f;
                }
                var_a3++;
            }

            if (var_fv0 < 1.0) {
                var_a2--;
            }

            if (var_fv0 > 1.0) {
                var_a2++;
            }
        }

        if (var_a2 >= 2) {
            return 1;
        }
    }

    for (i = 0x14; i < 0x1B; i++) {
        var_a2 = 0;

        for (j = 0; j < arg2; j++) {
            var_fv0 = 1.0f;

            var_a3 = &D_8438ACF0[0];
            while (var_a3->unk_00 != 0xFF) {
                if ((var_a3->unk_00 == i) &&
                    ((var_a3->unk_01 == sp28[j].unk_00) || (var_a3->unk_01 == sp28[j].unk_01))) {
                    var_fv0 = (var_a3->unk_02 * var_fv0) / 10.0f;
                }
                var_a3++;
            }

            if (var_fv0 < 1.0) {
                var_a2--;
            }

            if (var_fv0 > 1.0) {
                var_a2++;
            }
        }

        if (var_a2 >= 2) {
            return 1;
        }
    }

    return 0;
}

s32 func_8437F2EC(unk_D_843C60A4* arg0, unk_D_843C60A4* arg1, u8* arg2, s32* arg3) {
    u8 i;
    u8 j;
    u8 k;
    u8 l;
    unk_D_800FCB18* temp_s3;
    u8 sp13E;
    u8 m;
    u8 sp135;
    u8 sp134;
    u8 var_v1_2;
    u8 tmp;
    s32 sp12C;
    s32 sp128;
    s32 var_s2;
    unk_func_843794CC sp74[4];
    u8 sp5C;
    u8 temp_fp;
    u8 var_s0;
    unk_D_843C60AC* temp_s7;
    s32 var_v0;
    UNUSED s32 pad;

    sp134 = 0;
    sp135 = 0;
    sp12C = 0x80000002;

    for (i = 0; i < arg0->unk_00; i++) {
        sp13E = (i) ? arg0->unk_01[0] : 0;
        sp5C = arg0->unk_01[i] + sp13E;

        for (j = sp13E; j < sp5C; j++) {
            temp_s7 = &arg0->unk_14[j];
            arg0->unk_10 = j;
            temp_s3 = &temp_s7->unk_12;
            arg3[j] = 0;

            if (arg2 != NULL) {
                for (k = 0; k < arg1->unk_06; k++) {
                    tmp = arg2[k];
                    arg1->unk_10 = tmp;
                    if (temp_s7 == D_843C60B0) {
                        var_s2 = var_s0 = 1;
                    } else {
                        for (var_s0 = 0; var_s0 < 4 && temp_s3->unk_1F[var_s0] != 0; var_s0++) {}

                        var_s2 = var_s0;
                        if (var_s0 == 0) {
                            temp_s3->unk_1F[0] = 0xA5;
                            var_s2 = var_s0 = 1;
                        }
                    }

                    func_843794CC(temp_s7, &arg1->unk_14[tmp], 0, 0, var_s0, sp74);
                    func_8437B0CC(arg0, arg1, var_s0, sp74, 0);

                    var_v0 = 0;
                    for (m = 0; m < var_s2; m++) {
                        var_v0 += sp74[m].unk_28;
                    }
                    var_v0 /= var_s2;
                    arg3[j] += var_v0;
                }
            } else {
                for (k = 0; k < arg1->unk_00; k++) {
                    var_v1_2 = (k) ? arg1->unk_01[0] : 0;
                    temp_fp = arg1->unk_01[k] + var_v1_2;

                    for (tmp = var_v1_2; tmp < temp_fp; tmp++) {
                        arg1->unk_10 = tmp;
                        if (temp_s7 == D_843C60B0) {
                            var_s2 = var_s0 = 1;
                        } else {
                            for (var_s0 = 0; var_s0 < 4 && temp_s3->unk_1F[var_s0] != 0; var_s0++) {}

                            var_s2 = var_s0;
                            if (var_s0 == 0) {
                                temp_s3->unk_1F[0] = 0xA5;
                                var_s2 = var_s0 = 1;
                            }
                        }

                        func_843794CC(temp_s7, &arg1->unk_14[tmp], 0, 0, var_s0, sp74);
                        func_8437B0CC(arg0, arg1, var_s0, sp74, 0);

                        var_v0 = 0;
                        for (m = 0; m < var_s2; m++) {
                            var_v0 += sp74[m].unk_28;
                        }

                        var_v0 /= var_s2;
                        arg3[j] += var_v0;
                    }
                }
            }

            if ((sp12C < arg3[j]) || ((sp12C == arg3[j]) && (func_843767E4(1) != 0))) {
                sp128 = sp12C;
                sp12C = arg3[j];
                sp134 = sp135;
                sp135 = j;
            } else if ((sp128 < arg3[j]) || ((sp128 == arg3[j]) && (func_843767E4(1) != 0))) {
                sp128 = arg3[j];
                sp134 = j;
            }
        }
    }

    if ((D_843C5564->unk_00 & 0x100000) && (func_843767E4(1) != 0)) {
        arg0->unk_11 = sp134;
    } else {
        arg0->unk_11 = sp135;
    }
    return 1;
}

typedef struct unk_func_8437F85C_sp74 {
    /* 0x00 */ s32 unk_00[6];
} unk_func_8437F85C_sp74; // size >= 0x20

s32 func_8437F85C(unk_D_843C60A4* arg0, s32* arg1, s32 arg2, unk_func_8437F85C_arg3* arg3, u8* arg4, u8 arg5, u8 arg6) {
    u8 i;
    u8 j;
    u8 k;
    u8 var_fp;
    u8 sp93;
    s32 pad[1];
    unk_func_8437F85C_sp74 sp74;
    s32 pad2[3];
    unk_func_8437F85C_arg3 sp5C;

    sp93 = 0;
    i = 0;
    var_fp = 0;

    do {
        if ((arg1[i] < arg2) || ((arg2 == arg1[i]) && (func_843767E4(1) != 0))) {
            if (func_8437EFBC(arg0, arg4, arg5, arg6) != 0) {

                if (i < 7) {
                    for (j = 0; j < 7 - i; j++) {
                        sp74.unk_00[j] = arg1[i + j];
                    }
                }

                if (i < 7) {
                    // clang-format off
                    for (j = 0; j < 7 - i; j++) { arg1[i + j + 1] = sp74.unk_00[j]; }
                    // clang-format on
                }

                if (i < 7) {
                    for (j = 0; j < 7 - i; j++) {
                        for (k = 0; k < 3; k++) {
                            sp5C.unk_00[j][k] = arg3->unk_00[(i + j)][k];
                        }
                    }
                }

                if (i < 7) {
                    for (j = 0; j < 7 - i; j++) {
                        for (k = 0; k < 3; k++) {
                            arg3->unk_00[(i + j + 1)][k] = sp5C.unk_00[j][k];
                        }
                    }
                }

                arg1[i] = arg2;

                for (k = 0; k < 3; k++) {
                    arg3->unk_00[i][k] = arg4[k];
                }

                sp93 = 1;
                var_fp = 1;
            }
        }
        i++;
    } while (i < 8 && var_fp != 1);

    return sp93;
}

void func_8437FB14(unk_D_843C60A4* arg0, u8* arg1, s32 arg2) {
    u8 i;
    u8 j;
    s32 var_s2;

    do {
        for (i = 0; i < arg0->unk_06; i++) {
            do {
                var_s2 = 1;
                arg1[i] = func_843767E4(arg0->unk_03 - 1);

                for (j = 0; j < i; j++) {
                    if ((i != j) && (arg1[i] == arg1[j])) {
                        var_s2 = 0;
                    }
                }
            } while (var_s2 == 0);
        }
    } while (func_8437EDB8(arg0, arg1, arg0->unk_06, arg2) == 0);
}

s32 func_8437FC10(unk_D_843C60A4* arg0) {
    s32 var_v1;

    if ((arg0->unk_14[arg0->unk_10].unk_12.unk_0C > 0) && (func_843783CC(arg0) != 0)) {
        return 0;
    }

    do {
        var_v1 = func_843767E4(arg0->unk_06 - 1);
        if (arg0->unk_04[0] < var_v1) {
            var_v1 += arg0->unk_01[0];
        }
    } while (arg0->unk_14[var_v1].unk_12.unk_0C <= 0 || var_v1 == arg0->unk_10);

    return var_v1;
}

s32 func_8437FCCC(unk_D_800FCB18* arg0) {
    u8 i;
    u8 var_a1;
    s32 var_a2;
    s32 var_a3;

    var_a2 = 0;
    var_a3 = 0;
    var_a1 = 0;

    for (i = 0; i < 4; i++) {
        if (arg0->unk_1F[i] != 0) {
            var_a1++;
            if (arg0->unk_32[i] > 0) {
                var_a3 = 1;
            }
        }
    }

    if (var_a3 != 0) {
        do {
            var_a2 = func_843767E4(var_a1 - 1);
        } while (arg0->unk_1F[var_a2] == 0 || arg0->unk_32[var_a2] <= 0);
    }
    return var_a2;
}

#ifdef NON_MATCHING
s32 func_8437FD74(unk_D_843C60A4* arg0, s32* arg1, s32* arg2, u8 arg3) {
    u8 i;
    u8 j;
    u8 k;
    u8 l;
    u8 m;
    u8 spBF;
    u8 spBE;
    u8 spBA;
    s32 sp94[8];
    u8 sp90[3];
    u8 sp78[0x18];
    u8 sp76;
    s32 sp60;
    s32 sp5C;
    s32 temp_t2;
    s32 temp_t8;
    u8 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1_2;
    s32 var_a0_2;
    u8 var_a0_3;
    u8 var_a1;
    s32 var_s0;
    u8 var_s2;
    s32 var_s3_2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1_3;
    s32 temp_t0;
    u8 var_s1;
    u8 var_s3;
    u8 var_v1_2;
    u8 temp_v0;
    u8 temp_v1;
    u8 var_a0;
    u8 var_a3;
    u8 var_t1;
    u8 var_v1;
    u8 tmp1;
    u8 tmp2;

    sp76 = 0;

    for (i = 0; i < arg0->unk_00; i++) {
        if (i) {
            spBA = arg0->unk_04[0];
        } else {
            spBA = 0;
        }

        if (i) {
            if ((arg2 && arg2) && arg2) {}
            var_a3 = arg0->unk_01[0];
        } else {
            var_a3 = 0;
        }

        for (j = 0; j < 8; j++) {
            sp94[j] = 0x80000002;
        }

        sp5C = arg0->unk_04[i];

        if (sp5C < arg0->unk_01[i]) {
            if (arg0->unk_04[i] == 3) {
                var_s2 = 0;
                temp_v0_2 = arg0->unk_01[i] + var_a3;

                for (j = var_a3; j < temp_v0_2 - 2; j++) {
                    for (k = j + 1; k < temp_v0_2 - 1; k++) {
                        for (l = k + 1; l < temp_v0_2; l++) {
                            var_s0 = arg2[j] + arg2[k] + arg2[l];

                            sp90[0] = j;
                            sp90[1] = k;
                            sp90[2] = l;

                            if ((D_843C5564->unk_00 & 0x800) && (func_8437F068(arg0, sp90, 3) != 0)) {
                                var_s0 -= abs_asm(var_s0) * 0.2;
                            }

                            if (func_8437F85C(arg0, sp94, var_s0, sp78, sp90, 3, arg3) != 0) {
                                sp76 = 1;
                                var_s2++;
                                if (var_s2 >= 9) {
                                    var_s2 = 8;
                                }
                            }
                        }
                    }
                }

                for (j = 0; j < var_s2; j++) {
                    for (k = 0; k < 3; k++) {}
                }

                if (var_s2 > 0) {
                    var_a0_3 = 1;
                    if (D_843C5564->unk_00 & 0x10000) {
                        var_a0_3 = 2;
                    }

                    if (D_843C5564->unk_00 & 0x20000) {
                        var_a0_3 *= 4;
                    }

                    if (var_a0_3 < var_s2) {
                        var_a1 = var_a0_3;
                    } else {
                        var_a1 = var_s2;
                    }

                    // var_a1 = (var_a0_3 < var_s2) ? var_a0_3 : var_s2;

                    spBF = func_843767E4(var_a1 - 1);
                    _bcopy(&sp78[spBF * 3], &arg1[spBA], 3);
                } else {
                    func_8437FB14(arg0, arg1, arg3);
                    sp76 = 1;
                }
                continue;
            }
        } else {
            for (m = 0; m < arg0->unk_01[i]; m++) {
                arg1[m + spBA] = m + var_a3;
            }
            sp76 = 1;
        }
    }

    return sp76;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/62/fragment62_361050/func_8437FD74.s")
#endif

s32 func_84380164(unk_D_843C60A4* arg0, unk_D_843C60A4* arg1, u8* arg2, u8* arg3, s32* arg4) {
    u8 i;
    u8 j;
    u8 var_s1;
    u8 sp13C;
    u8 sp13B;
    u8 sp13A;
    unk_D_800FCB18* temp_v0;
    unk_D_843C60AC* temp_s6;
    u8 sp12F;
    UNUSED u8 sp12E;
    u8 sp12D;
    UNUSED u8 sp12C;
    u16 sp12A;
    s32 sp124;
    s32 sp120;
    unk_D_843C60AC* temp_s7;
    unk_func_843794CC sp6C[4];
    s32 var_s0_2;
    s32 var_s2;
    s32 var_v0;
    UNUSED s32 pad;

    sp12A = 0;
    sp120 = 0x80000002;
    sp124 = 0x80000002;

    for (i = 0; i < arg0->unk_06; i++) {
        if (sp124 < arg4[arg2[i]]) {
            sp13C = i;
            sp124 = arg4[arg2[i]];
        }

        if (sp12A < arg0->unk_14[arg2[i]].unk_12.unk_2E) {
            sp13B = i;
            sp12A = arg0->unk_14[arg2[i]].unk_12.unk_2E;
        }

        if (arg3 != NULL) {
            arg0->unk_10 = arg2[i];
            temp_s6 = &arg0->unk_14[arg2[i]];
            arg1->unk_10 = *arg3;

            temp_s7 = &arg1->unk_14[*arg3];
            temp_v0 = &temp_s6->unk_12;

            for (var_s1 = 0; var_s1 < 4 && temp_v0->unk_1F[var_s1] != 0; var_s1++) {}

            if (var_s1) {
                func_843794CC(temp_s6, temp_s7, 0, 0, var_s1, sp6C);
                func_8437B0CC(arg0, arg1, var_s1, sp6C, 0);

                var_v0 = 0;
                for (j = 0; j < var_s1; j++) {
                    var_v0 += sp6C[j].unk_28;
                }

                var_v0 /= var_s1;
                if (sp120 < var_v0) {
                    sp13A = i;
                    sp120 = var_v0;
                }
            }
        }
    }

    var_s2 = 0x80000002;
    sp12F = 0;

    for (i = 0; i < arg0->unk_06; i++) {
        var_s0_2 = 0;
        if (sp13C == i) {
            if (D_843C5564->unk_00 & 0x40000) {
                var_s0_2 = -0x3E7;
            } else {
                var_s0_2 = 0xC;
            }
        }

        if (sp13B == i) {
            var_s0_2 += 7;
        }

        var_s0_2 += func_843779C8(&arg0->unk_14[arg2[i]], &arg0->unk_14[arg2[i]], 0, &sp12D) * 0xA;
        if ((arg3 != NULL) && (sp13A == i)) {
            var_s0_2 += 0x23;
        }

        if (var_s2 < var_s0_2) {
            sp12F = i;
            var_s2 = var_s0_2;
        }
    }

    if (!(D_843C5564->unk_00 & 0x80000)) {
        sp12F = func_843767E4(arg0->unk_06 - 1);
    }

    if ((sp12F < 0) || (sp12F >= arg0->unk_06)) {
        sp12F = 0;
    }

    i = *arg2;
    *arg2 = arg2[sp12F];
    arg2[sp12F] = i;
    return 1;
}

s32 func_843804F4(unk_D_843C60A4* arg0, unk_D_843C60A4* arg1, u8* arg2, u8* arg3, s32 arg4) {
    s32 sp20[12];

    bzero(&sp20, 0x30);

    if (func_8437F2EC(arg0, arg1, arg3, &sp20) == 0) {
        return 0;
    }

    if (func_8437FD74(arg0, arg2, &sp20, arg4) == 0) {
        return 0;
    }

    if (func_84380164(arg0, arg1, arg2, arg3, &sp20) == 0) {
        return 0;
    }
    return 1;
}

void func_84380598(void) {
    s32 i;
    s32 j;
    s32 temp_t1;
    u8 var_v0;
    u8 var_v1;
    s32 var_t0;

    var_v0 = 0;
    var_v1 = 0;

    for (i = 0; i < D_843C60A4->unk_00; i++) {
        if (i != 0) {
            var_t0 = D_843C60A4->unk_01[0];
        } else {
            var_t0 = 0;
        }
        temp_t1 = D_843C60A4->unk_04[i] + var_t0;

        for (j = var_t0; j < temp_t1; j++) {
            if (D_843C60A4->unk_14[j].unk_12.unk_0C > 0) {
                var_v1++;
            }
        }
    }

    for (i = 0; i < D_843C60A8->unk_00; i++) {
        if (i != 0) {
            var_t0 = D_843C60A8->unk_01[0];
        } else {
            var_t0 = 0;
        }
        temp_t1 = D_843C60A8->unk_04[i] + var_t0;

        for (j = var_t0; j < temp_t1; j++) {
            if (D_843C60A8->unk_14[j].unk_12.unk_0C > 0) {
                var_v0++;
            }
        }
    }

    if (var_v1 >= (var_v0 * 2)) {
        D_843C60A4->unk_13 = 0;
        D_843C60A8->unk_13 = 2;
    } else if (var_v0 >= (var_v1 * 2)) {
        D_843C60A4->unk_13 = 2;
        D_843C60A8->unk_13 = 0;
    } else {
        D_843C60A8->unk_13 = 1;
        D_843C60A4->unk_13 = D_843C60A8->unk_13;
    }
}

u8 func_84380870(unk_D_843C60A4* arg0, unk_D_843C60A4* arg1) {
    u8 i;
    u8 j;
    u8 k;
    u8 l;
    UNUSED u8 sp8D;
    UNUSED u8 sp8D1;
    UNUSED u8 sp8D2;
    u8 sp90;
    u8 sp8F;
    u8 sp8E;
    unk_D_843C60AC* temp_s0;
    unk_D_843C60AC* temp_s1;
    f32 temp_fs0;
    f32 var_fs1;
    s32 var_s4;
    s32 var_s5;
    u8 var_a0;
    u8 var_a1;
    u8 var_a2;
    UNUSED s32 pad;

    sp8F = 0;
    var_fs1 = -3.4028235e38f;

    for (i = 0; i < arg0->unk_00; i++) {
        var_a1 = i ? arg0->unk_01[0] : 0;

        if (arg0->unk_04[i] == arg0->unk_07[i]) {
            var_a0 = arg0->unk_04[i];
        } else {
            var_a0 = arg0->unk_01[i];
        }

        for (j = var_a1; j < var_a0 + var_a1; j++) {
            var_s4 = 0;
            var_s5 = 0;
            if ((arg0->unk_14[j].unk_12.unk_0C > 0) &&
                (!(arg0->unk_14[j].unk_12.unk_15 & 0x20) || (func_843783CC(arg0) != 0))) {
                for (k = 0; k < arg1->unk_00; k++) {
                    if (k) {
                        var_a2 = arg1->unk_01[0];
                    } else {
                        var_a2 = 0;
                    }

                    if (arg1->unk_04[k] == arg1->unk_07[k]) {
                        sp90 = arg1->unk_04[k];
                    } else {
                        sp90 = arg1->unk_01[k];
                    }

                    for (l = var_a2; l < sp90 + var_a2; l++) {
                        temp_s0 = &arg0->unk_14[j];
                        temp_s1 = &arg1->unk_14[l];
                        if (arg1->unk_14[l].unk_12.unk_0C > 0) {
                            var_s5 += func_843791E4(temp_s0, temp_s1, &sp8E, 0xA);
                            var_s4 += func_843791E4(temp_s1, temp_s0, &sp8E, 0xA);
                        }
                    }

                    temp_fs0 = (f32)(var_s5 - var_s4) / sp90;
                    if ((var_fs1 < temp_fs0) || ((temp_fs0 == var_fs1) && (func_843767E4(1) != 0))) {
                        var_fs1 = temp_fs0;
                        sp8F = i;
                    }
                }
            }
        }
    }

    return sp8F;
}

u8 func_84380B40(unk_D_843C60AC* arg0, s32* arg1, s32* arg2, unk_D_843C60A4* arg3, u8 arg4, s32 arg5) {
    u8 i;
    u8 j;
    unk_D_800FCB18* temp_s5;
    unk_D_800FCB18* ptr;
    s32 temp_v0_2;
    s32 var_a0;
    s32 sp70 = 0x80000002;
    u8 sp6F = 0;
    u8 sp6E = 0;
    u8 sp6D = 0xFF;
    u8 temp_v1_2;
    u16 var_s1;
    s32 var_s1_2;
    u16 var_s3;
    u8 var_a1;
    UNUSED s32 pad;

    *arg2 = 0;
    *arg1 = 0;

    for (i = 0; i < arg3->unk_00; i++) {
        var_a1 = (i) ? arg3->unk_01[0] : 0;

        if (arg3->unk_04[i] == arg3->unk_07[i]) {
            var_a0 = arg3->unk_04[i];
        } else {
            var_a0 = arg3->unk_01[i];
        }
        temp_v1_2 = var_a1 + (0, var_a0);

        for (j = var_a1; j < temp_v1_2; j++) {
            if ((j != arg3->unk_10) && (arg3->unk_14[j].unk_12.unk_0C > 0)) {
                temp_s5 = &arg0->unk_12;
                ptr = &arg3->unk_14[j].unk_12;

                if ((arg5 != 0) && (D_843C60BC == 0)) {
                    var_s3 = func_8437865C(temp_s5, &arg3->unk_14[j].unk_12, arg4);
                } else {
                    var_s3 = 0;
                }
                sp6E = arg4;

                if (temp_s5->unk_2E < ptr->unk_2E) {
                    // clang-format off
                    if (var_s3 < ptr->unk_0C) { var_s1 = func_84378B0C(&arg3->unk_14[j], arg0, &sp6F, 4); } else { var_s1 = 0; }
                    // clang-format on

                    if (var_s1 < temp_s5->unk_0C) {
                        var_s3 += func_84378B0C(arg0, &arg3->unk_14[j], &sp6E, 4);
                    }
                } else {
                    var_s3 += func_84378B0C(arg0, &arg3->unk_14[j], &sp6E, 4);
                    if (var_s3 < ptr->unk_0C) {
                        var_s1 = func_84378B0C(&arg3->unk_14[j], arg0, &sp6F, 4);
                    } else {
                        var_s1 = 0;
                    }
                }

                if (ptr->unk_15 & 7) {
                    var_s1 = 0;
                }

                if (ptr->unk_15 & 0x20) {
                    var_s1 = 0;
                    if ((D_80072B00[arg4 - 1].unk_01 != 4) && (D_80072B00[arg4 - 1].unk_01 != 0x22)) {
                        var_s3 = ptr->unk_0C;
                    }
                }

                var_s1_2 = func_84377068(var_s1, temp_s5->unk_0C);
                temp_v0_2 = func_84377068(var_s3, ptr->unk_0C);

                if (temp_v0_2 == 0xFF) {
                    var_s1_2 = 0;
                }

                if ((!(ptr->unk_15 & 0x20) || (D_80072B00[arg4 - 1].unk_01 == 4) ||
                     (D_80072B00[arg4 - 1].unk_01 == 0x22)) &&
                    ((sp70 < (var_s1_2 - temp_v0_2)) ||
                     ((sp70 == (var_s1_2 - temp_v0_2)) && (func_843767E4(1) != 0)))) {
                    sp70 = var_s1_2 - temp_v0_2;
                    *arg1 = var_s1_2;
                    *arg2 = temp_v0_2;
                    sp6D = j;
                }
            }
        }
    }

    return sp6D;
}

s32 func_84380EB4(unk_D_843C60AC* arg0, unk_D_843C60AC* arg1, u8 arg2) {
    u8 sp2F;
    u16 temp_v0;
    unk_D_800FCB18* sp20 = &arg0->unk_12;
    unk_D_800FCB18* sp1C = &arg1->unk_12;

    if (func_843779C8(arg0, arg0, 0, &sp2F) != 0) {
        if ((func_8437865C(sp20, sp1C, sp2F) != 0) && (sp1C->unk_2E < sp20->unk_2E)) {
            temp_v0 = func_8437865C(sp1C, sp20, arg2);

            if (sp20->unk_0C < temp_v0) {
                return 0x99;
            }

            if (sp20->unk_0C < (temp_v0 * 2)) {
                return 0x99;
            }
        }
    }
    return 0;
}

s32 func_84380F7C(unk_func_8438220C* arg0) {
    s32 idx = arg0->unk_B4;
    unk_func_843794CC* temp_s0 = &arg0->unk_04[idx];
    s32 temp_v0 = D_843C5564->unk_0A * 0x11;
    s32 temp_s1 = D_843C5564->unk_0B * 0x14;
    s32 var_a0;
    s32 sp40 = temp_s0->unk_0C * temp_v0;
    s32 sp3C = temp_s0->unk_10 * temp_v0;
    s32 sp38 = temp_s0->unk_04 * temp_s0->unk_24;
    s32 sp34 = func_84377068(temp_s0->unk_12, D_843C60B4->unk_28) * temp_s1;
    s32 sp30 = func_84377068(temp_s0->unk_16, D_843C60B4->unk_28) * temp_s1;
    s32 sp2C = func_84377068(temp_s0->unk_1A, D_843C60B4->unk_28) * temp_s1;
    s32 temp_v0_2 = func_84377068(temp_s0->unk_1E, D_843C60B4->unk_28);
    s32 temp_ft4;

    temp_ft4 =
        (((((sp40 + sp2C + sp38) * (temp_s0->unk_01 / 255.0f)) + sp3C) - (sp34 * (temp_s0->unk_06 / 255.0f))) - sp30) -
        ((temp_v0_2 * temp_s1) * (temp_s0->unk_08 / 255.0f));
    if (temp_ft4 >= 0) {
        var_a0 = temp_ft4;
    } else {
        var_a0 = -temp_ft4;
    }

    return ((var_a0 * (D_843C5564->unk_07 - 0x80)) / 500) + (0, temp_ft4);
}

s32 func_843811D0(unk_D_843C60AC* arg0, unk_D_843C60AC* arg1, unk_D_843C60A4* arg2, u8* arg3, s32* arg4, s32* arg5,
                  s32* arg6, s32* arg7, s32* arg8) {
    s32 sp44 = 0;
    u8 sp43;
    UNUSED s32 pad[2];

    if (arg1->unk_12.unk_0C > 0) {
        *arg5 = func_843791E4(arg0, arg1, &sp43, 4);
        if (D_843C60BC != 0) {
            *arg6 = 0;
        } else {
            *arg6 = func_843791AC(arg1, arg0, &sp43, 0xB);
        }

        if (arg0->unk_12.unk_2E >= arg1->unk_12.unk_2E) {
            if (*arg5 >= 0xFF) {
                *arg6 = 0;
            }
        } else if (*arg6 >= 0xFF) {
            *arg5 = 0;
        }
    }

    *arg3 = func_84380B40(arg1, arg7, arg8, arg2, sp43, arg0->unk_12.unk_0C != 0);
    if (*arg3 == 0xFF) {
        *arg3 = 0;
        *arg4 = 1;
        return 0;
    }

    if ((*arg6 != 0) && (*arg8 == 0) && (*arg7 != 0)) {
        sp44 = 0x34;
    }

    if ((*arg5 == 0) && (*arg7 != 0) && !(arg1->unk_12.unk_15 & 0x27)) {
        sp44 += 0x80;
    }

    if ((*arg5 - *arg6) < ((*arg7 - *arg8) - D_843C5564->unk_07)) {
        sp44 += 0x99;
    }

    if (func_8436FD54(*arg3, arg2->unk_0A, arg2->unk_09) == 0) {
        sp44 /= 2;
    }
    return sp44;
}

s32 func_843813D4(unk_D_843C60AC* arg0, unk_D_843C60AC* arg1, unk_D_843C60A4* arg2, u8* arg3, unk_func_8438220C* arg4) {
    u8 i;
    u8 j;
    s32 sp40;
    u8 temp_s4;
    s32 var_s2;
    s32 var_v1_2;
    u8 var_v1;

    sp40 = 0;
    var_s2 = 0x80000002;

    for (i = 0; i < arg2->unk_00; i++) {
        var_v1 = (i) ? arg2->unk_01[0] : 0;
        temp_s4 = arg2->unk_04[i] + var_v1;

        for (j = var_v1; j < temp_s4; j++) {
            if ((arg2->unk_14[j].unk_12.unk_0C > 0) && (j != arg2->unk_10)) {
                if ((var_s2 < arg4[j].unk_B8) || ((var_s2 == arg4[j].unk_B8) && (func_843767E4(1) != 0))) {
                    var_s2 = arg4[j].unk_B8;
                    *arg3 = j;
                }
            }
        }
    }

    if (arg0->unk_12.unk_0C > 0) {
        var_v1_2 = func_84380F7C(&arg4[arg0->unk_00]);
    } else {
        var_v1_2 = 0x80000002;
    }

    if (var_v1_2 < var_s2) {
        sp40 = 0x99;
    }
    return sp40;
}

u8 func_84381584(unk_D_843C60AC* arg0, unk_D_843C60AC* arg1, unk_D_843C60A4* arg2, unk_D_843C60A4* arg3, u8* arg4,
                 unk_func_8438220C* arg5) {
    s32 sp6C;
    UNUSED u8 sp6B;
    UNUSED u8 sp6A;
    u8 sp69;
    UNUSED u8 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    unk_D_800FCB18* sp40 = &arg0->unk_12;
    unk_D_800FCB18* sp3C = &arg1->unk_12;
    s32 sp4C;

    sp4C = 0;
    sp58 = 0;
    sp5C = 0;
    sp60 = 0;
    sp64 = 0;
    sp6C = 0;

    if ((func_843783CC(arg2) != 0) && (sp40->unk_0C > 0)) {
        *arg4 = 0;
        return 0;
    }

    if ((sp40->unk_4C & 0x52) || (sp40->unk_4D & 0x28)) {
        *arg4 = 0;
        return 0;
    }

    if (D_843C5564->unk_00 & 0x80) {
        if (sp3C->unk_0C == 0) {
            if (sp40->unk_0C == 0) {
                *arg4 = func_84380870(arg2, arg3);
            } else {
                sp4C = 1;
            }
        } else {
            if ((D_843C5564->unk_00 & 0x400000) && (arg5 != NULL)) {
                sp6C = func_843813D4(arg0, arg1, arg2, arg4, arg5);
            } else {
                sp6C = func_843811D0(arg0, arg1, arg2, arg4, &sp4C, &sp64, &sp60, &sp5C, &sp58);
            }

            if ((sp40->unk_15 & 0x20) && (sp58 != 0)) {
                sp6C += func_84378140(arg0, arg1) * 0x64;
                sp6C += 0x1A;
            } else {
                if ((func_84377068(sp40->unk_0C, sp40->unk_28) < D_843C5564->unk_08) &&
                    (!(D_843C5564->unk_00 & 0x400000) ||
                     ((arg5 != NULL) && (arg5[*arg4].unk_04[arg5[*arg4].unk_B4].unk_1E == 0)))) {
                    if (D_843C5564->unk_00 & 0x200) {
                        sp4C = 1;
                    } else if (D_843C5564->unk_08 <
                               func_84377068(arg2->unk_14[*arg4].unk_12.unk_0C, arg2->unk_14[*arg4].unk_12.unk_28)) {
                        sp6C += 0x64;
                    }
                }

                if ((sp3C->unk_4C & 0x20) && (sp40->unk_2E < sp3C->unk_2E)) {
                    sp6C += 0x80;
                } else {
                    if ((D_843C5564->unk_00 & 0x400000) && (arg5 != NULL)) {
                        if (arg5[arg0->unk_00].unk_04[arg5[arg0->unk_00].unk_B4].unk_0C >= 0xFB) {
                            sp6C -= 0xFF;
                        }
                    } else if (sp64 >= 0xFA) {
                        sp6C -= 0xFF;
                    }

                    if (sp40->unk_4C & 1) {
                        sp6C = (sp6C - (((4 - sp40->unk_4F) / 2) * 0x4D)) - 0x4D;
                    }
                }

                if (sp40->unk_15 & 7) {
                    sp6C += func_843776FC(arg0, arg1, 0x8A) * 0x34;
                }

                if (sp40->unk_4E & 1) {
                    sp6C += sp40->unk_51 * 0x4D;
                    if (sp40->unk_4D & 0x80) {
                        sp6C *= 2;
                    }
                }

                sp6C -= sp40->unk_5C[0] * 4;
                sp6C += 0x1C;
                sp6C -= sp40->unk_5C[1] * 4;
                sp6C += 0x1C;
                sp6C -= sp40->unk_5C[2] * 4;
                sp6C += 0x1C;
                sp6C -= sp40->unk_5C[3] * 4;
                sp6C += 0x1C;
                sp6C -= sp40->unk_5C[4] * 0x1A;
                sp6C += 0xB6;
                sp6C -= sp40->unk_5C[5] * 0x1A;
                sp6C += 0xB6;

                if (sp40->unk_4E & 4) {
                    sp6C -= 0x34;
                }

                if (sp40->unk_4E & 2) {
                    sp6C -= 0x34;
                }

                if (sp40->unk_4D & 0x40) {
                    sp6C -= 0x4D;
                }

                if (!(D_843C5564->unk_00 & 0x400000) && (sp60 < sp58)) {
                    sp6C -= func_84380EB4(arg0, arg1, sp69);
                }
            }
        }

        sp6C += D_843C5564->unk_05;
        sp6C -= 0x7F;
    } else {
        *arg4 = func_8437FC10(arg2);
        sp6C = 0x3F;
    }

    if ((arg2->unk_14[*arg4].unk_12.unk_0C == 0) || (*arg4 < 0) || (*arg4 >= arg2->unk_06)) {
        *arg4 = func_8437FC10(arg2);
    }

    if (!(D_843C5564->unk_00 & 0x40)) {
        sp6C = 0;
    }

    if (sp4C != 0) {
        sp6C = 0;
    }

    if ((sp6C >= 0x100) || (sp40->unk_0C == 0)) {
        sp6C = 0xFF;
    }

    if (sp6C < 0) {
        sp6C = 0;
    }
    return sp6C;
}

u16 func_84381BD4(u16* arg0, u16 arg1, u8 arg2) {
    *arg0 = (arg1 * D_8438ACB8[arg2 - 1].unk_00) / D_8438ACB8[arg2 - 1].unk_01;

    if (*arg0 == 0) {
        *arg0 = 1;
    }

    if (*arg0 >= 0x3E8) {
        *arg0 = 0x3E7;
    }
    return *arg0;
}

void func_84381C78(unk_D_800FCB18* arg0, unk_D_800FCB18* arg1, u8 arg2, u8 arg3) {
    u16 tmp;

    if (D_80072B00[arg2 - 1].unk_02 != 0) {
        if (D_80072B00[arg2 - 1].unk_03 < 0xA) {
            if (arg3) {
                tmp = arg1->unk_38 - func_843767E4(6);
                tmp += 3;
                arg0->unk_38 = tmp;
                if (tmp <= 0) {
                    arg0->unk_38 = 1;
                }

                if (arg0->unk_15 & 0x10) {
                    arg0->unk_2A = arg0->unk_38 >> 1;
                } else {
                    arg0->unk_2A = arg0->unk_38;
                }
                func_84381BD4(&arg0->unk_2A, arg0->unk_2A, arg0->unk_5C[0]);
            } else {
                tmp = arg1->unk_3A - func_843767E4(6);
                tmp += 3;
                arg0->unk_3A = tmp;
                if (tmp <= 0) {
                    arg0->unk_3A = 1;
                }
                func_84381BD4(&arg0->unk_2C, arg0->unk_3A, arg0->unk_5C[1]);
            }
        } else {
            tmp = arg1->unk_3E - func_843767E4(6);
            tmp += 3;
            arg0->unk_3E = tmp;
            if (tmp <= 0) {
                arg0->unk_3E = 1;
            }
            func_84381BD4(&arg0->unk_30, arg0->unk_3E, arg0->unk_5C[3]);
        }
    }
}

void func_84381DD4(unk_func_8438220C* arg0) {
    u8 i;
    u8 sp5E;
    u8 j;
    unk_D_800FCB18* temp_a0;
    unk_D_843C60AC* temp_s1;

    if (D_843C60B4->unk_0C > 0) {
        func_84378B0C(D_843C60B0, D_843C60AC, &sp5E, 0xB);
    }

    for (i = 0; i < D_843C60A4->unk_06; i++) {
        temp_s1 = &D_843C60A4->unk_14[i];
        temp_a0 = &temp_s1->unk_12;

        if (temp_a0->unk_0C > 0) {
            for (j = 0; j < 4 && temp_a0->unk_1F[j] != 0; j++) {}

            arg0[i].unk_00 = j;
            func_843794CC(temp_s1, D_843C60B0, i != D_843C60AC->unk_00 && D_843C60B4->unk_0C > 0, sp5E, j,
                          arg0[i].unk_04);
        }
    }
}

void func_84381F50(unk_func_8438220C* arg0) {
    u8 i;
    u8 j;
    u8 sp4D;
    unk_func_8438220C* temp_s1;

    sp4D = D_843C60A4->unk_10;

    for (i = 0; i < D_843C60A4->unk_06; i++) {
        D_843C60A4->unk_10 = i;

        temp_s1 = &arg0[i];
        temp_s1->unk_B8 = 0x80000002;

        if (D_843C60A4->unk_14[i].unk_12.unk_0C > 0) {
            func_8437B0CC(D_843C60A4, D_843C60A8, temp_s1->unk_00, temp_s1->unk_04, 1);

            for (j = 0; j < temp_s1->unk_00; j++) {
                if (temp_s1->unk_B8 < temp_s1->unk_04[j].unk_28) {
                    temp_s1->unk_B8 = temp_s1->unk_04[j].unk_28;
                    temp_s1->unk_B4 = j;
                }
            }
        }
    }

    D_843C60A4->unk_10 = sp4D;
}

u8 func_843820B8(unk_func_8438220C* arg0) {
    UNUSED u8 pad;
    u8 sp3E = 0;
    s32 sp38;
    UNUSED s32 pad2[2];
    u8 sp2F = 0;

    if (D_843C60B4->unk_0C > 0) {
        sp2F = func_8437E448(D_843C60AC, D_843C60B0, arg0[D_843C60AC->unk_00].unk_00, arg0[D_843C60AC->unk_00].unk_04);
    }

    if ((func_843783CC(D_843C60A4) != 0) && (D_843C60B4->unk_0C > 0)) {
        return sp2F;
    }

    sp38 = func_84381584(D_843C60AC, D_843C60B0, D_843C60A4, D_843C60A8, &sp3E, arg0);
    D_843C60C0[D_843C60E8].unk_00 = sp38;
    D_843C60C0[D_843C60E8].unk_01 = sp3E;

    if ((func_843767E4(0xFE) < sp38) && (sp3E != D_843C60A4->unk_10)) {
        return sp3E + 4;
    }
    return sp2F;
}

s32 func_8438220C(void) {
    unk_func_8438220C sp18[6];

    func_84381DD4(sp18);
    func_84381F50(sp18);
    return func_843820B8(sp18);
}

s32 func_8438223C(s32 arg0) {
    u8 i;
    u8 sp5E;
    s32 max = 0xFF;
    s32 temp_a0;
    s32 temp_v1;
    s32 sp4C;
    s32 var_a0;
    s32 var_fp;
    s32 var_s0;
    s32 var_s2;
    s32 var_s6;
    s32 var_v0;
    s32 var_v0_2;

    var_v0 = 0xF999999B;
    var_s2 = 0x80000002;
    var_fp = func_8437FCCC(D_843C60B4);
    func_8437FC10(D_843C60A4);

    if (D_843C60C0[0].unk_01 == D_843C60C0[1].unk_01) {
        var_v0_2 = D_843C60C0[1].unk_00 * arg0;
        var_s6 = max - arg0;
        var_a0 = D_843C60C0[0].unk_00 * var_s6;
        sp5E = D_843C60C0[0].unk_01;
    } else {
        var_v0_2 = D_843C60C0[1].unk_00 * arg0;
        var_s6 = max - arg0;
        var_a0 = D_843C60C0[0].unk_00 * var_s6;
        if (var_v0_2 < var_a0) {
            sp5E = D_843C60C0[0].unk_01;
        } else {
            sp5E = D_843C60C0[1].unk_01;
        }
    }

    if (var_v0_2 < var_a0) {
        sp4C = var_a0;
    } else {
        sp4C = var_v0_2;
    }

    for (i = 0; i < D_843C60C0[0].unk_02; i++) {
        temp_v1 = D_843C60C0[1].unk_04[i];
        temp_a0 = D_843C60C0[0].unk_04[i];
        if ((temp_v1 + temp_a0) < var_v0) {
            var_s0 = -0x06666666;
        } else {
            var_s0 = (temp_v1 * ((f32)arg0 / 255.0)) + (temp_a0 * ((f32)var_s6 / 255.0));
        }

        if ((D_843C60B4->unk_32[i] > 0) && ((var_s2 < var_s0) || ((var_s0 == var_s2) && (func_843767E4(1) != 0)))) {
            var_s2 = var_s0;
            var_fp = i;
        }
    }

    if ((func_843767E4(0xFE) < ((sp4C / 255) & 0xFFFF)) || (D_843C60B4->unk_0C == 0)) {
        return sp5E + 4;
    }
    return var_fp;
}

s32 func_8438249C(u8 arg0, u8 arg1) {
    UNUSED s32 pad;
    unk_D_80072B00* sp18;

    if (D_843C6138[arg0] == 0) {
        return 0;
    }

    sp18 = &D_80072B00[D_843C6138[arg0] - 1];

    if (arg1 == D_843C6138[arg0]) {
        return 1;
    }

    if ((func_8436FD54(D_80072B00[arg1 - 1].unk_01, D_8438B0D8, 0x1A) != 0) &&
        (func_8436FD54(sp18->unk_01, D_8438B0D8, 0x1A) != 0)) {
        return 1;
    }
    return 0;
}

s32 func_8438255C(u8 arg0, u8 arg1) {
    if (D_843C6138[arg0] == 0) {
        return 0;
    }

    if (func_8436FD54(D_80072B00[arg1 - 1].unk_01, D_8438B0F4, 2) != 0) {
        return 1;
    }
    return 0;
}

s32 func_843825D8(u8 arg0) {
    if (func_8436FD54(arg0, D_8438B0BC, 5) != 0) {
        return 1;
    }
    return 0;
}

s32 func_84382614(u8 arg0) {
    if ((func_8436FD54(arg0, D_8438B0C4, 0x11) != 0) && (func_843767E4(0xF) != 0)) {
        return 1;
    }
    return 0;
}

s32 func_84382668(unk_D_800FCB18* arg0, s32 arg1, u8 arg2, u8 arg3) {
    u8 i;

    for (i = 0; i < 4; i++) {
        if (arg3 == D_80070FA0[arg1 - 1].unk_0A[i]) {
            return 0;
        }

        if ((D_84384588[arg2]->unk_00 != 0) && (arg3 == D_80070FA0[D_84384588[arg2]->unk_00 - 1].unk_0A[i])) {
            return 0;
        }

        if ((D_84384588[arg2]->unk_01 != 0) && (arg3 == D_80070FA0[D_84384588[arg2]->unk_01 - 1].unk_0A[i])) {
            return 0;
        }
    }

    for (i = 1; i < 0x38; i++) {
        if ((func_84377550(arg1, i) != 0) && (arg3 == D_8438AFB4[i - 1])) {
            return 0;
        }
    }

    for (i = 0; D_843C5310[arg2].unk_00[i] != 0 && arg0->unk_26 >= D_843C5310[arg2].unk_00[i]; i++) {
        if (arg3 == D_843C5310[arg2].unk_0A[i]) {
            return 0;
        }
    }

    return 1;
}

s32 func_84382840(unk_D_800FCB18* arg0, unk_D_800FCB18* arg1, u8 arg2) {
    s32 sp24 = 0;
    unk_D_80072B00* sp1C = &D_80072B00[arg2 - 1];

    if (D_80072B00[arg2 - 1].unk_02 != 0) {
        if (func_8437738C(D_80072B00[arg2 - 1].unk_03, arg1) < 1.0) {
            return 1;
        }
    }

    switch (sp1C->unk_01) {
        case 0x0:
            if ((arg2 == 0x62) && (arg1->unk_4C & 0x40)) {
                sp24 = 1;
            }
            break;

        case 0x1:
        case 0x20:
            if ((arg1->unk_4D & 0x10) || (arg1->unk_15 != 0)) {
                sp24 = 1;
            }
            break;

        case 0x2:
        case 0x21:
        case 0x42:
        case 0x4D:
            if ((arg1->unk_15 != 0) || (arg1->unk_16[6] == 3) || (arg1->unk_16[7] == 3) || (arg1->unk_4D & 0x10)) {
                sp24 = 1;
            }
            break;

        case 0x4:
        case 0x22:
            if (arg1->unk_15 & 0x20) {
                return 1;
            }
            break;

        case 0x43:
            if ((arg1->unk_15 != 0) || (arg1->unk_4D & 0x10) ||
                ((sp1C->unk_03 == 0x17) && ((arg1->unk_16[6] == 4) || (arg1->unk_16[7] == 4)))) {
                sp24 = 1;
            }
            break;

        case 0x7:
            if (arg1->unk_4C & 0x40) {
                sp24 = 1;
            }
            break;

        case 0x8:
            if (!(arg1->unk_15 & 7)) {
                return 1;
            }
            break;

        case 0x9:
            if (arg1->unk_58 == 0) {
                sp24 = 1;
            }
            break;

        case 0x31:
            if ((arg1->unk_4C & 0x80) || (arg1->unk_4D & 0x10)) {
                sp24 = 1;
            }
            break;

        case 0x38:
            if (arg0->unk_0C == arg0->unk_28) {
                sp24 = 1;
            }
            break;

        case 0x39:
            if (arg1->unk_0B == 0x84) {
                sp24 = 1;
            }
            break;

        case 0x4F:
            if (arg0->unk_0C < (arg0->unk_28 >> 2)) {
                sp24 = 1;
            }
            break;
    }

    if ((sp1C->unk_02 == 0) && (sp24 != 0)) {
        return 1;
    }
    return 0;
}

void func_84382ACC(void) {
    u8 i;
    u8 j;
    u8 k;
    s32 var_a2;
    s32 temp_v1_5;
    u8 var_v0;
    u8 var_v1;
    unk_D_800FCB18* temp_s2;
    unk_D_800FCB18* temp_s0;
    unk_D_843C5568* var_s3;

    for (i = 0; i < 2; i++) {
        temp_s2 = &D_84390010[i]->unk_654.unk_38;
        if (D_84390010[i]->unk_654.unk_2C != 0) {
            var_s3 = &D_843C5568[i];
            var_v1 = var_s3->unk_003;
        } else {
            var_s3 = &D_843C5568[i];
            var_v1 = 0;
        }

        var_s3->unk_012 = D_84390010[i]->unk_654.unk_08 + var_v1;
        temp_s0 = &var_s3->unk_016[var_s3->unk_012].unk_12;

        temp_s0->unk_0C = temp_s2->unk_0C;
        temp_s0->unk_28 = temp_s2->unk_28;
        temp_s0->unk_15 = temp_s2->unk_15;
        temp_s0->unk_16[6] = temp_s2->unk_16[6];
        temp_s0->unk_16[7] = temp_s2->unk_16[7];
        temp_s0->unk_4C = temp_s2->unk_4C;
        temp_s0->unk_4D = temp_s2->unk_4D;
        temp_s0->unk_4E = temp_s2->unk_4E;
        temp_s0->unk_4F = temp_s2->unk_4F;
        temp_s0->unk_50 = temp_s2->unk_50;
        temp_s0->unk_51 = temp_s2->unk_51;
        temp_s0->unk_52 = temp_s2->unk_52;
        temp_s0->unk_54 = temp_s2->unk_54;
        temp_s0->unk_57 = temp_s2->unk_57;
        temp_s0->unk_58 = temp_s2->unk_58;
        temp_s0->unk_59 = temp_s2->unk_59;

        _bcopy(temp_s2->unk_1F, temp_s0->unk_1F, 4);
        _bcopy(temp_s2->unk_5C, temp_s0->unk_5C, 6);

        if ((temp_s2->unk_4E & 8) && (temp_s2->unk_5A == 0x90)) {
            D_843C5568[1 - i].unk_016[D_843C5568[1 - i].unk_012].unk_01 = 15;

            temp_s0->unk_2A = temp_s2->unk_2A;
            temp_s0->unk_2C = temp_s2->unk_2C;
            temp_s0->unk_2E = temp_s2->unk_2E;
            temp_s0->unk_30 = temp_s2->unk_30;
            temp_s0->unk_38 = temp_s2->unk_38;
            temp_s0->unk_3A = temp_s2->unk_3A;
            temp_s0->unk_3C = temp_s2->unk_3C;
            temp_s0->unk_3E = temp_s2->unk_3E;
        } else if (D_843C5564->unk_00 & 8) {
            temp_s0->unk_2A = (temp_s0->unk_15 & 0x10) ? temp_s0->unk_38 >> 1 : temp_s0->unk_38;

            if (temp_s0->unk_2A == 0) {
                temp_s0->unk_2A++;
            }

            temp_s0->unk_2E = (temp_s0->unk_15 & 0x40) ? temp_s0->unk_3C >> 2 : temp_s0->unk_3C;

            if (temp_s0->unk_2E == 0) {
                temp_s0->unk_2E++;
            }

            func_84381BD4(&temp_s0->unk_2A, temp_s0->unk_2A, temp_s0->unk_5C[0]);
            func_84381BD4(&temp_s0->unk_2C, temp_s0->unk_3A, temp_s0->unk_5C[1]);
            func_84381BD4(&temp_s0->unk_2E, temp_s0->unk_2E, temp_s0->unk_5C[2]);
            func_84381BD4(&temp_s0->unk_30, temp_s0->unk_3E, temp_s0->unk_5C[3]);
        }

        if (i == D_843C5568[0].unk_000) {
            for (j = 0; j < 4; j++) {
                temp_s0->unk_32[j] = temp_s2->unk_32[j] & 0x3F;
            }
        }

        for (j = 0; j < D_843C5568[i].unk_008; j++) {
            temp_s0 = &D_843C5568[i].unk_016[j].unk_12;
            temp_s0->unk_0C = D_84390010[i]->unk_724->unk_01C[j].unk_02;

            if ((temp_s0->unk_0C > 0) && (D_843C5568[i].unk_012 != j)) {
                func_84377030(&D_843C5568[i].unk_016[j]);
                temp_s0->unk_2A = temp_s0->unk_38;
                temp_s0->unk_2C = temp_s0->unk_3A;
                temp_s0->unk_2E = temp_s0->unk_3C;
                temp_s0->unk_30 = temp_s0->unk_3E;

                if (D_843C5564->unk_00 & 8) {
                    temp_s0->unk_2A = (temp_s0->unk_15 & 0x10) ? temp_s0->unk_38 >> 2 : temp_s0->unk_38;

                    if (temp_s0->unk_2A == 0) {
                        temp_s0->unk_2A++;
                    }

                    temp_s0->unk_2E = (temp_s0->unk_15 & 0x40) ? temp_s0->unk_3C >> 2 : temp_s0->unk_3C;

                    if (temp_s0->unk_2E == 0) {
                        temp_s0->unk_2E++;
                    }
                }
            }
        }
    }

    if (D_843C60A8->unk_09 < D_843C60A8->unk_06) {
        var_a2 = 0;
        for (i = 0; i < D_843C60A8->unk_09; i++) {
            if (D_843C60A8->unk_10 == D_843C60A8->unk_0A[i]) {
                var_a2 = 1;
            }
        }

        if (var_a2 == 0) {
            D_843C60A8->unk_0A[D_843C60A8->unk_09] = D_843C60A8->unk_10;
            if (D_843C60A8->unk_10 < D_843C60A8->unk_01[0]) {
                D_843C60A8->unk_07[0]++;
            } else {
                D_843C60A8->unk_08++;
            }
            D_843C60A8->unk_09++;
        }
    }

    for (i = 0; i < D_843C60A8->unk_00; i++) {
        if (i) {
            var_v0 = D_843C60A8->unk_01[0];
        } else {
            var_v0 = 0;
        }

        for (j = 0; j < D_843C60A8->unk_04[i]; j++) {
            temp_v1_5 = j + var_v0;
            var_a2 = 1;
            D_843C60A8->unk_14[temp_v1_5].unk_12.unk_0C =
                D_84390010[1 - D_843C5568[0].unk_000]->unk_720->unk_08[i]->unk_01C[j].unk_02;
            if (D_843C60A8->unk_14[temp_v1_5].unk_12.unk_0C == 0) {
                var_a2 = 0;
                for (k = 0; k < D_843C60A8->unk_09; k++) {
                    if (temp_v1_5 == D_843C60A8->unk_0A[k]) {
                        var_a2 = 1;
                    }
                }
            }

            if (var_a2 == 0) {
                D_843C60A8->unk_0A[D_843C60A8->unk_09] = temp_v1_5;
                if (temp_v1_5 < D_843C60A8->unk_01[0]) {
                    D_843C60A8->unk_07[0]++;
                } else {
                    D_843C60A8->unk_08++;
                }
                D_843C60A8->unk_09++;
            }
        }
    }
}

s32 func_843831A0(unk_D_800AE540_0004* arg0, unk_D_800AE540_0004* arg1, unk_D_800AE540_0004* arg2, s32 arg3, u8* arg4,
                  s32 arg5, s32 arg6) {
    u8 i;
    u8 j;
    u8 sp40[4];
    u8 sp38[8];

    if (arg3 < 0xFF) {
        func_84376790(arg3, &D_843C60F0);
    }
    bzero(D_843C5568, sizeof(D_843C5568) + 2);
    D_843C5568->unk_000 = 1;
    func_843768D8(0x35);

    for (i = 0; i < 6; i++) {
        arg4[i] = i;
    }

    func_84378474(arg0, arg1, arg2, D_843C5568, arg5);

    D_843C60A4 = &D_843C5568[D_843C5568->unk_000].unk_002;
    D_843C60A8 = &D_843C5568[1 - D_843C5568->unk_000].unk_002;
    D_843C60A4->unk_12 = arg3;
    D_843C60A4->unk_13 = 1;
    D_843C60A4->unk_07[0] = D_843C60A4->unk_09 = D_843C60A4->unk_06;

    for (i = 0; i < D_843C60A4->unk_09; i++) {
        if (!D_843C60A8) {}

        D_843C60A4->unk_0A[i] = i;
    }

    if (D_843C60A8->unk_06 == D_843C60A8->unk_03) {
        for (i = 0; i < D_843C60A8->unk_06; i++) {
            D_843C60A8->unk_0A[i] = i;
        }
        D_843C60A8->unk_09 = D_843C60A8->unk_06;
        D_843C60A8->unk_07[0] = D_843C60A8->unk_04[0];
        D_843C60A8->unk_08 = D_843C60A8->unk_04[1];
    } else {
        D_843C60A8->unk_09 = 0;
    }

    D_843C5564 = &D_843C60F0.unk_0C[1];

    func_8437E974(arg0, arg1, &D_843C5568->unk_002, D_843C5568->unk_000);
    func_8437E974(arg2, NULL, &D_843C5568[1].unk_002, 1 - D_843C5568->unk_000);
    func_8437717C(arg0);
    func_8437717C(arg1);
    func_8437717C(arg2);

    if (D_843C5564->unk_00 & 0x100) {
        if (D_843C5564->unk_00 & 1) {
            if (func_843804F4(D_843C60A8, D_843C60A4, sp38, NULL, arg5) == 0) {
                return 0;
            }

            if (func_843804F4(D_843C60A4, D_843C60A8, sp40, sp38, arg5) == 0) {
                return 0;
            }

            if ((func_843767E4(1) != 0) && (D_843C5564->unk_00 & 2)) {
                if (0) {}

                if (func_843804F4(D_843C60A8, D_843C60A4, sp38, sp40, arg5) == 0) {
                    return 0;
                }

                if (func_843804F4(D_843C60A4, D_843C60A8, sp40, sp38, arg5) == 0) {
                    return 0;
                }
            }
        } else {
            for (i = 0; i < D_843C60A8->unk_06; i++) {
                sp38[i] = i;
            }

            if (func_843804F4(D_843C60A4, D_843C60A8, sp40, NULL, arg5) == 0) {
                return 0;
            }
        }
    } else {
        func_8437FB14(D_843C60A4, &sp40, arg5);
    }

    for (i = 0; i < D_843C60A4->unk_06; i++) {
        if ((sp40[i] < 0) || ((D_843C60A4->unk_03 - 1) < sp40[i])) {
            for (j = 0; j < 6; j++) {
                arg4[j] = j;
            }
            return 0;
        } else {
            arg4[i] = sp40[i];
            D_843C5568[D_843C5568->unk_000].unk_00C[i] = i;
        }
    }

    return 1;
}

void func_8438363C(UNUSED s32 arg0, UNUSED s32 arg1, s32 arg2) {
    u8 i;

    D_843C60AC->unk_02 = D_84390010[D_843C5568->unk_000]->unk_654.unk_38.unk_5A;
    D_843C60B0->unk_02 = D_84390010[1 - D_843C5568->unk_000]->unk_654.unk_38.unk_5A;

    for (i = 0; i < 4; i++) {
        if (D_843C60B0->unk_02 == D_843C60B8->unk_1F[i]) {
            D_843C60B0->unk_01 |= 1 << i;
            D_843C60B8->unk_32[i]--;
            if (D_843C60B8->unk_32[i] < 0) {
                D_843C60B8->unk_32[i] = 0;
            }
        }
    }

    if (D_843C60B0->unk_02 == 0xA5) {
        for (i = 0; i < 4; i++) {
            D_843C60B8->unk_32[i] = 0;
        }
    }

    if (((arg2 == 0) || (arg2 == 1)) && !(D_843C60B8->unk_4D & 0x20)) {
        func_84378578(D_843C60B0, D_843C60A4->unk_10);
    } else {
        D_843C60AC->unk_02 = 0;
        D_843C60B0->unk_02 = D_843C60AC->unk_02;
    }

    for (i = 0; i < 4; i++) {
        if (D_843C60AC->unk_02 == D_843C60B4->unk_1F[i]) {
            D_843C60AC->unk_01 |= 1 << i;
        }
    }

    if (D_843C5564->unk_00 & 0x400) {
        func_84381C78(D_843C60B8, &D_84390010[1 - D_843C5568->unk_000]->unk_654.unk_38, D_843C60B0->unk_02, 1);
        func_84381C78(D_843C60B8, &D_84390010[1 - D_843C5568->unk_000]->unk_654.unk_38, D_843C60AC->unk_02, 0);
    }

    if ((arg2 == 0) && (D_843C5564->unk_00 & 8)) {
        if ((D_843C60B4->unk_2E < D_843C60B8->unk_2E) && (D_843C60AC->unk_02 != 0x62) && (D_843C60B0->unk_02 != 0x44)) {
            D_843C60B8->unk_2E = D_843C60B4->unk_2E - 1;
            if (D_843C60B8->unk_15 & 0x40) {
                D_843C60B8->unk_3C = D_843C60B8->unk_2E * 4;
            } else {
                D_843C60B8->unk_3C = D_843C60B8->unk_2E;
            }
            D_843C60B8->unk_3C = (D_843C60B8->unk_3C * D_8438ACB8[D_843C60B8->unk_5C[2] - 1].unk_01) /
                                 D_8438ACB8[D_843C60B8->unk_5C[2] - 1].unk_00;
        }
    }

    if ((arg2 == 1) && (D_843C5564->unk_00 & 8)) {
        if ((D_843C60B8->unk_2E < D_843C60B4->unk_2E) && (D_843C60B0->unk_02 != 0x62) && (D_843C60AC->unk_02 != 0x44)) {
            D_843C60B8->unk_2E = D_843C60B4->unk_2E + 1;
            if (D_843C60B8->unk_15 & 0x40) {
                D_843C60B8->unk_3C = D_843C60B8->unk_2E * 4;
            } else {
                D_843C60B8->unk_3C = D_843C60B8->unk_2E;
            }
            D_843C60B8->unk_3C = (D_843C60B8->unk_3C * D_8438ACB8[D_843C60B8->unk_5C[2] - 1].unk_01) /
                                 D_8438ACB8[D_843C60B8->unk_5C[2] - 1].unk_00;
        }
    }

    for (i = 0; i < 2; i++) {
        if (D_84390010[i]->unk_654.unk_38.unk_5A == 0x44) {
            D_843C5568[i].unk_016[D_843C5568[i].unk_012].unk_03 = 2;
        }
    }
}

s32 func_84383B5C(UNUSED s32 arg0) {
    s32 sp44;
    u8 var_v1;
    u8 sp42;
    u8 sp41;
    u8 sp40;
    u8 sp3F;
    unk_D_800AE540_0004* temp_v0;
    unk_D_800AE540_0004* temp_v00;
    unk_D_800AE540_0004* sp30;

    if (D_843C5568[0].unk_001 == 0) {
        temp_v0 = D_84390010[0]->unk_720->unk_08[0];
        sp30 = D_84390010[1]->unk_720->unk_08[0];
        if (D_84390010[0]->unk_720->unk_01 == 2) {
            temp_v00 = D_84390010[0]->unk_720->unk_08[1];
            func_8437E974(temp_v0, temp_v00, D_843C60A8, 1);
        } else {
            func_8437E974(temp_v0, NULL, D_843C60A8, 1);
        }
        func_8437E974(sp30, NULL, D_843C60A4, 0);
        D_843C5568[0].unk_001 = 2;
    }

    if (D_843C60BC != 0) {
        if (D_84390010[0]->unk_654.unk_2C != 0) {
            var_v1 = D_843C5568[0].unk_003;
        } else {
            var_v1 = 0;
        }

        if (D_843C60A8->unk_10 != (D_84390010[0]->unk_654.unk_08 + var_v1)) {
            D_8438AFB0 += 1;
            goto label1;
        }
    }
    D_8438AFB0 = 0;

label1:
    func_84382ACC();
    D_843C60AC = &D_843C60A4->unk_14[D_843C60A4->unk_10];
    D_843C60B0 = &D_843C60A8->unk_14[D_843C60A8->unk_10];
    D_843C60B4 = &D_843C60AC->unk_12;
    D_843C60B8 = &D_843C60B0->unk_12;
    func_84380598();
    D_843C5564 = &D_843C60F0.unk_0C[D_843C60A4->unk_13];
    bzero(D_843C60C0, sizeof(unk_D_843C60C0) * 2);
    D_843C60E8 = 0;

    if (D_843C5564->unk_00 & 0x400000) {
        sp44 = func_8438220C();
    } else {
        D_843C60C0[D_843C60E8].unk_00 = func_84381584(D_843C60AC, D_843C60B0, D_843C60A4, D_843C60A8, &sp3F, 0);
        D_843C60C0[D_843C60E8].unk_01 = sp3F;
        if (func_843767E4(0xFE) < D_843C60C0[D_843C60E8].unk_00) {
            sp44 = D_843C60C0[D_843C60E8].unk_01 + 4;
        } else {
            sp44 = func_8437E7A4();
        }
    }

    D_843C60BC = 0;
    if ((D_843C60B8->unk_0C != 0) && (D_843C5564->unk_00 & 4)) {
        if ((D_843C5564->unk_08 + 0x33) < func_84377068(D_843C60B4->unk_0C, D_843C60B4->unk_28)) {
            sp42 = func_84381584(D_843C60B0, D_843C60AC, D_843C60A8, D_843C60A4, &sp40, 0) >> D_8438AFB0;
            if (func_843767E4(0xFE) < sp42) {
                D_843C60A8->unk_10 = sp40;
                D_843C60B0 = &D_843C60A8->unk_14[sp40];
                D_843C60B8 = &D_843C60B0->unk_12;
                D_843C60BC = 1;
                D_843C60E8++;
                if (D_843C5564->unk_00 & 0x400000) {
                    sp44 = func_8438220C();
                } else {
                    // clang-format off
                    sp41 = func_84381584(D_843C60AC, D_843C60B0, D_843C60A4, D_843C60A8, &sp3F, 0); D_843C60C0[D_843C60E8].unk_00 = sp41;
                    // clang-format on
                    D_843C60C0[D_843C60E8].unk_01 = sp3F;

                    if (func_843767E4(0xFE) < sp41) {
                        sp44 = D_843C60C0[D_843C60E8].unk_01 + 4;
                    } else {
                        sp44 = func_8437E7A4();
                    }
                }
            }
        }
    }

    if ((D_843C5564->unk_00 & 0x01000000) && (D_843C60E8 != 0) &&
        (!(D_843C5564->unk_00 & 0x200000) || (D_843C60AC->unk_04 == 1))) {
        sp44 = func_8438223C(sp42);
    }

    D_843C60AC->unk_04 = 1;
    if (((D_843C60B4->unk_0C == 0) && (sp44 < 4)) || ((D_843C60A4->unk_06 + 3) < sp44)) {
        sp44 = func_8437FC10(D_843C60A4) + 4;
    }

    if ((sp44 >= 0) && ((sp44 >= 4) || ((D_843C60B4->unk_1F[sp44] != 0) && (D_843C60B4->unk_32[sp44] != 0)))) {
        if ((D_843C60B4->unk_0C != 0) && (sp44 >= 4)) {
            if (func_843783CC(D_843C60A4) != 0) {
                goto block_44;
            }
        }
    } else {
    block_44:
        sp44 = func_8437FCCC(D_843C60B4);
    }
    return sp44;
}

void func_84384124(void) {
    u8 i;
    u8 temp_a0;

    for (i = 0; i < 2; i++) {
        D_843C6138[i] = 0;
        temp_a0 = D_84390010[i]->unk_654.unk_38.unk_0B;
        D_843C5550[i] = temp_a0;
        func_8430255C(temp_a0, &D_843C5310[i]);
    }
}

s32 func_843841C4(s32 arg0, s32 arg1) {
    unk_D_800FCB18* temp_s4 = &D_84390010[arg0]->unk_654.unk_38;
    unk_D_800FCB18* temp_s6 = &D_84390010[1 - arg0]->unk_654.unk_38;
    s32 var_s2 = 0;
    u8 var_s0;
    u8 var_s3;

    if ((arg1 > 0) && (arg1 < 0xA6)) {
        return arg1;
    }

    if (temp_s4->unk_4E & 8) {
        var_s3 = D_84390010[arg0]->unk_654.unk_BE;
    } else {
        var_s3 = temp_s4->unk_0B;
    }

    while (true) {
        if (func_843767E4(7) != 0) {
            var_s0 = func_843767E4(0xA3) + 1;
        } else {
            var_s0 = D_8438AFEC[var_s3 - 1];
        }

        var_s2++;
        if (var_s2 >= 0x12D) {
            var_s0 = 0xA5;
            break;
        }

        if (var_s0) {}

        if (!func_8438249C(arg0, var_s0) && !func_8438255C(arg0, var_s0) && !func_843825D8(var_s0) &&
            !func_84382614(var_s0) && !func_84382668(temp_s4, var_s3, arg0, var_s0) &&
            !func_84382840(temp_s4, temp_s6, var_s0)) {
            break;
        }
    }

    D_843C6138[arg0] = var_s0;
    return var_s0;
}
