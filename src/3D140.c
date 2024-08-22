#include "3D140.h"
#include "373A0.h"
#include "45720.h"

extern u8 D_800783FC;
extern u8 D_80078400;
extern u16 D_80078410[1][9];
extern u16 D_80078446[1][9];
extern u16 D_800784EA[1][9];
extern u16 D_80077DF0[];
extern u16 D_80077E00[];
extern u16 D_80077E10[];
extern u16 D_80077E18[];
extern u16 D_80077E20[];
extern u16 D_80077E28[];
extern u16 D_80077E30[];
extern u16 D_80077E38[];
extern u16 D_80077E40[];
extern u16 D_80077E48[];
extern u16 D_80077E50[];
extern u16 D_80077E58[];
extern u16 D_80077E60[];
extern u16 D_80077E68[];
extern u16 D_80077E70[];
extern u16 D_80077E78[];
extern u16 D_80077E88[];
extern u16 D_80077E90[];
extern u16 D_800780A8[];
extern u8 D_800783BC;
extern u8 D_800783C0;
extern u8 D_800783C4;
extern s32 D_800783C8;
extern u32 D_800783CC;
extern u8 D_800783D4;
extern u8 D_800783D8;
extern u8 D_800783DC;
extern u8 D_800783E4;
extern u8 D_800783E8;
extern u8 D_800783EC;
extern f64 D_8007C7E0;
extern f64 D_8007C7E8;
extern f64 D_8007C7F0;
extern f64 D_8007C7F8;
extern u8 D_800FCD18[];

typedef struct unk_D_800FCB18 {
	/* 0x00 */ char pad00[0xC];
	/* 0x0C */ u16 unk_0C;
	/* 0x0E */ char pad0E[0xE];
	/* 0x1C */ u8 unk_1C;
	/* 0x1D */ u8 unk_1D;
	/* 0x1E */ char pad1E[0x8];
	/* 0x26 */ u8 unk_26;
	/* 0x28 */ u16 unk_28;
} unk_D_800FCB18; // size >= 0x2C

extern unk_D_800FCB18* D_800FCB18[2];
extern s32 D_800FCB28;
extern s32 D_800FCB2C;

typedef struct unk_D_800FCB48 {
	/* 0x00 */ u16 unk_00[16];
	/* 0x20 */ char pad20[0x4];
	/* 0x24 */ s32 unk_24;
	/* 0x28 */ char pad28[0x50];
	/* 0x78 */ s32 unk_78;
	/* 0x7C */ s32 unk_7C;
	/* 0x80 */ char pad80[0x4];
} unk_D_800FCB48; // size = 0x84
extern unk_D_800FCB48 D_800FCB48[2];
extern s32 D_800FCCA4;
extern u8 D_800FCCAE;
extern u8 D_800FCCAF;
extern u8 D_800FCCB0;
extern u8 D_800FCCB1;
extern u8 D_800FCCB2;
extern u8 D_800FCCB3;
extern u8 D_800FCCB4;
extern u8 D_800FCCB5;
extern u8 D_800FCCB6;
extern s8 D_8007839C[];
extern s8 D_800783E0;
extern s16 D_800783F0;
extern s16 D_800783F4;
extern s16 D_800783F8;
extern u8 D_800FCB38[2][8];
extern s32 D_800FCC50[];
extern s8 D_800FCCA0;
extern s8 D_800FCCA1;
extern s8 D_800FCCA2;
extern s8 D_800FCCAC;
extern s8 D_800FCCB7;
extern s8 D_800FCCB8[];
extern s8 D_800FCCBA[];
extern s8 D_800FCCBC[];
extern s8 D_800FCCBE[];
extern s8 D_800FCCC0[];
extern s8 D_800FCCC2[];
extern s8 D_800FCCD4[];
extern s8 D_800FCCD6[];
extern s8 D_800FCCD8[];
extern s32 D_80078388;
extern u32 D_800783A4[4];
extern s32 D_800783B8;

void func_80041A98(void);
void func_80041C70(u32);
void func_800420C0(u16*);

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003C540.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003C8DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003CADC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D128.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D160.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D264.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D2B8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D32C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D494.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D4A0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D514.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D54C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D570.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D624.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D68C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D6B0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D6DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D828.s")

#ifdef NON_MATCHING
void func_8003D918(u32 arg0, u32 arg1) {
    u32 temp_v0 = arg1 == 0x10;
    u8 sp1B = 0;
    u16 var_a0;

    func_80041A98();
    D_80078404 = arg1;
    D_80078408 = arg0;

    if (arg1 < 0x11) {
        D_800783FC = 1;
        D_8007840C = 1;

        if ((arg0 == 0) && (arg1 != 0x10) && (arg1 != 0xF)) {
            func_80041C70(0x34);
        } else if ((arg0 == 0xFF) && (arg1 != 0x10) && (arg1 != 0xF)) {
            func_80041C70(0x47);
            arg0 = 0;
            sp1B = 1;
        }

        if (arg1 < 0xC) {
            if (arg0 < 9) {
                var_a0 = D_80078410[arg1][arg0];
                D_800783FC = 1;
                D_80078400 = 1;
            } else {
            	return;
            }
        } else if (arg1 == 0xC) {
            if ((arg0 < 0x21) && (arg0 != 0)) {
                var_a0 = D_800784EA[(arg0 - 1) / 8][(arg0 - 1) % 8];
                D_800783FC = 1;
                D_80078400 = 0;
            } else {
            	return;
            }
        } else if (arg1 == 0xD) {
            if (arg0 < 6) {
                var_a0 = D_80078446[arg1][arg0];
                D_800783FC = 1;
                D_80078400 = 0;
            } else {
            	return;
            }
        } else {
            if (arg1 == 0xE) {
                var_a0 = 0x49;
                D_800783FC = 1;
                D_80078400 = 2;
            } else if (arg1 == 0xF) {
                var_a0 = 0;
                D_800783FC = 0;
                D_80078400 = 0;
                arg0 = 1;
            } else {
                D_800783FC = 1;
                if (temp_v0) {
                    var_a0 = 0x48;
                    D_80078400 = 1;
                    arg0 = 1;
                } else {
                    var_a0 = 0;
                    D_80078400 = 1;
                }
            }
        }

        if ((arg0 == 0) && (sp1B == 0)) {
            D_80078400 = 2;
        }

        if (var_a0 != 0) {
            func_80041C70(var_a0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003D918.s")
#endif

#ifdef NON_MATCHING
void func_8003DB84(s32 arg0) {
	s32 i;
    s32 var_t0;
    s32 var_t2;
    s32 var_t4;
    s32 var_t5;
    s32 var_v0;
    u32 var_a0;
    u32 temp_v0;

    if (arg0 != 0) {
        temp_v0 = osSetIntMask(1);
        D_800783BC = 1;
        D_800783C8 = 0;
        D_800783C0 = 0;
        D_800783C4 = 0;
        osSetIntMask(temp_v0);
        D_800783D4 = 0;
        D_800783D8 = 0;
        D_800783DC = 0;
        D_800FCCAE = 0;
        D_800FCCAF = 0;
        D_800FCCB2 = 0;
        D_800FCCB6 = 0;
        D_800783E8 = 0;
        D_800783EC = 0;
        D_800FCCA4 = 0;
        func_800367A0(0x5A, D_80078400, 0);

        if ((D_800FCB18[0] != NULL) && (D_800FCB18[1] != NULL)) {
            if (D_800FCB18[0] != NULL) {
            	D_800FCB28 = D_800FCB18[0]->unk_0C;
            }

            if (D_800FCB18[1] != NULL) {
                D_800FCB2C = D_800FCB18[1]->unk_0C;
            }

            D_800FCB48[0].unk_24++;
            D_800FCB48[0].unk_00[D_800FCB48[0].unk_24 & 0xF] = D_800FCB18[0]->unk_0C;
            D_800FCB48[1].unk_24++;
            D_800FCB48[1].unk_00[D_800FCB48[1].unk_24 & 0xF] = D_800FCB18[1]->unk_0C;

            if (D_800783CC != 0) {
                var_t0 = 1;
                if (D_800FCB18[0]->unk_26 < D_800FCB18[1]->unk_26) {
                    var_t2 = 0;
                    var_t4 = 1;
                } else {
                	var_t4 = 0;
                	var_t2 = 1;
                }

                if (D_800FCB18[0]->unk_0C < D_800FCB18[1]->unk_0C) {
                    var_t0 = 0;
                    var_t5 = 1;
                } else {
                	var_t5 = 0;
                }

                if (D_800783CC < 2) {
                    if ((D_800FCB18[0]->unk_0C == 0) || (D_800FCB18[1]->unk_0C == 0)) {
                        temp_v0 = osSetIntMask(1);
                        D_800783C0 = 1;
                        osSetIntMask(temp_v0);

                        if (D_800FCB18[0]->unk_0C == 0) {
                            D_800FCCB0 = 1;
                        } else {
                            D_800FCCB0 = 2;
                        }

                        if ((D_800FCB18[0]->unk_0C == 0) && (D_800FCB18[1]->unk_0C == 0)) {
                            func_800420C0(D_80077E90);
                            return;
                        }

                        func_800420C0(D_80077E48);
                        return;
                    }

                    if ((((D_800FCB18[0]->unk_0C * 0x64u) / D_800FCB18[0]->unk_28) < 0x1E) && 
                        (((D_800FCB18[1]->unk_0C * 0x64u) / D_800FCB18[1]->unk_28) < 0x1E)) {
                        func_800420C0(D_80077E88);
                        return;
                    }

                    if (((((D_800FCB18[var_t4]->unk_26 - D_800FCB18[var_t2]->unk_26) * 0x64u) / D_800FCB18[var_t2]->unk_26) >= 0x15) && 
                        (((D_800FCB18[var_t2]->unk_0C * 0x64u) / D_800FCB18[var_t2]->unk_28) < 0x28) && 
                        (((D_800FCB18[var_t4]->unk_0C * 0x64u) / D_800FCB18[var_t4]->unk_28) >= 0x51)) {
                        if (__ull_rem(osGetTime(), 3) == 0) {
                            var_a0 = 0x256;
                            goto block_53;
                        }
                    }

                    if ((((D_800FCB18[0]->unk_0C * 0x64u) / D_800FCB18[0]->unk_28) >= 0x5B) && 
                        (((D_800FCB18[1]->unk_0C * 0x64u) / D_800FCB18[1]->unk_28) >= 0x5B)) {
                        func_800420C0(D_80077E68);
                        return;
                    }

                    if (D_80078400 == 0) {
                        func_800420C0(D_80077E78);
                        return;
                    }

                    func_800420C0(D_80077DF0);
                    return;
                }

                if ((D_800FCB18[0]->unk_0C == 0) || (D_800FCB18[1]->unk_0C == 0)) {
                    temp_v0 = osSetIntMask(1);
                    D_800783C0 = 1;
                    osSetIntMask(temp_v0);

                    if (D_800FCB18[0]->unk_0C == 0) {
                        D_800FCCB0 = 1;
                    } else {
                        D_800FCCB0 = 2;
                    }

                    if (D_80078390[0] >= D_80078390[1]) {
                        var_v0 = D_80078390[0] - D_80078390[1];
                    } else {
                    	var_v0 = D_80078390[1] - D_80078390[0];
                    }

                    if (var_v0 >= 2) {
                        func_800420C0(D_80077E70);
                        return;
                    }

                    if ((D_80078390[0] == 1) && (D_80078390[1] == 1)) {
                        var_a0 = 0x290;
                        if (D_800783E4 != 0) {
                            D_800783E4 = 0;
                        } else {
                            if (__ull_rem(osGetTime(), 2) != 0) {
                                var_a0 = 0x254;
                            } else {
                            	var_a0 = 0x26B;
                            }
                        }
block_53:
                        func_80041C70(var_a0);
                        return;
                    }

                    if (D_80078390[D_800FCCB0 - 1] == 1) {
                        func_80041C70(0x26A);
                        return;
                    }

                    func_800420C0(D_80077E00);
                    return;
                }

                if (D_800FCCB0 != 0) {
                    if (((D_80078390[0] == 1) || (D_80078390[1] == 1)) && 
                        (D_80078390[0] < 4) && (D_80078390[1] < 4)) {
                        if (D_80078390[0] == 1) {
                            switch (D_80078390[1]) {
                                case 1:
                                    func_80041C70(0x260);
                                    func_80041C70(0x266);
                                    break;

                                case 2:
                                    func_80041C70(0x261);
                                    if (D_800FCCB0 == 1) {
                                        func_80041C70(0x265);
                                    } else {
                                        func_80041C70(0x267);
                                    }
                                    break;

                                case 3:
                                    func_80041C70(0x262);
                                    func_80041C70(0x264);
                                    break;

                                default:
                                    func_80041C70(0x271);
                                    break;
                            }

                            D_800FCCB0 = 0;
                            return;
                        }

                        switch (D_80078390[0]) {
                            case 2:
                                func_80041C70(0x25E);
                                if (D_800FCCB0 == 2) {
                                    func_80041C70(0x265);
                                } else {
                                    func_80041C70(0x267);
                                }
                                break;

                            case 3:
                                func_80041C70(0x25C);
                                func_80041C70(0x264);
                                break;

                            default:
                                func_80041C70(0x271);
                                break;
                        }

                        D_800FCCB0 = 0;
                        return;
                    }

                    if (D_800FCCB1 != 0) {
                        if (__ull_rem(osGetTime(), 2) != 0) {
	                        D_800FCCB0 = 0;
	                        func_800420C0(D_80077E10);
                        	return;
	                    }
                    }

                    if (D_800FCB18[0]->unk_1C != D_800FCB18[1]->unk_1C) {
                        if (D_800FCB18[0]->unk_1C != D_800FCB18[1]->unk_1D) {
                            if ((D_800FCB18[0]->unk_1D != D_800FCB18[1]->unk_1C) && 
                                (D_800FCB18[0]->unk_1D != D_800FCB18[1]->unk_1D)) {
                                D_800FCCB0 = 0;
                                func_800420C0(D_80077E18);
                                return;
                            }
                        }
                    }

                    D_800FCCB0 = 0;
                    switch (D_80078390[0]) {
                        case 2:
                            switch (D_80078390[1]) {
                                case 2:
                                    func_80041C70(0x25D);
                                    func_80041C70(0x268);
                                    return;

                                case 3:
                                    func_80041C70(0x25F);
                                    func_80041C70(0x263);
                                    return;

                                default:
                                    func_80041C70(0x271);
                                    return;
                            }
                            break;

                        case 3:
                            if (D_80078390[1] == 2) {
                                func_80041C70(0x25B);
                                func_80041C70(0x263);
                                return;
                            }

                            func_80041C70(0x271);
                            return;

                        default:
                            if (D_80078400 == 0) {
                                func_800420C0(D_80077E78);
                                return;
                            }

                            func_800420C0(D_80077DF0);
                            return;
                    }
                } else {

                    if (D_800FCCB3 != 0) {
                        func_800420C0(D_80077E38);
                        D_800FCCB3 = 0;
                        return;
                    }

                    if (D_800FCCB4 != 0) {
                        func_800420C0(D_80077E40);
                        D_800FCCB4 = 0;
                        return;
                    }

                    if (D_800FCCB5 != 0) {
                        func_800420C0(D_80077E50);
                        D_800FCCB5 = 0;
                        return;
                    }

                    if ((D_800FCB18[0]->unk_28 * 0.5f) < (D_800FCB48[0].unk_00[(D_800FCB48[0].unk_24 - 1) & 0xF] - D_800FCB48[0].unk_00[D_800FCB48[0].unk_24 & 0xF])) {
                        if ((D_800FCB18[1]->unk_28 * 0.5f) < (D_800FCB48[1].unk_00[(D_800FCB48[1].unk_24 - 1) & 0xF] - D_800FCB48[1].unk_00[(D_800FCB48[1].unk_24 & 0xF)])) {
                            if ((((D_800FCB18[0]->unk_0C * 0x64u) / D_800FCB18[0]->unk_28) < 0x14u) && 
                                (((D_800FCB18[1]->unk_0C * 0x64u) / D_800FCB18[1]->unk_28) < 0x14u)) {
                                func_800420C0(D_80077E60);
                            } else {
                            	func_800420C0(D_80077E58);
                            }
                            return;
                        }
                    }

                    if (D_800FCB18[0]->unk_0C >= D_800FCB18[1]->unk_0C) {
                        var_v0 = D_800FCB18[0]->unk_0C - D_800FCB18[1]->unk_0C;
                    } else {
                        var_v0 = D_800FCB18[1]->unk_0C - D_800FCB18[0]->unk_0C;
                    }

                    if ((D_800FCB18[var_t0]->unk_28 * D_8007C7E0) < var_v0) {
                        if ((((D_800FCB18[var_t5]->unk_0C * 0x64u) / D_800FCB18[var_t5]->unk_28) >= 0x47) && 
                            (D_800FCB18[0]->unk_0C != D_800FCB18[0]->unk_28) && (D_800FCB18[1]->unk_0C != D_800FCB18[1]->unk_28)) {
                            if ((D_800FCB18[var_t5]->unk_28 * D_8007C7E8) < D_800FCB18[var_t5]->unk_0C) {
                                if (D_800FCB18[var_t0]->unk_0C < (D_800FCB18[var_t0]->unk_28 * D_8007C7F0)) {
                                    func_800420C0(D_80077E20);
                                    return;
                                }
                            }
                        }
                    }

                    if (D_800FCB18[0]->unk_0C >= D_800FCB18[1]->unk_0C) {
                        var_v0 = D_800FCB18[0]->unk_0C - D_800FCB18[1]->unk_0C;
                    } else {
                    	var_v0 = D_800FCB18[1]->unk_0C - D_800FCB18[0]->unk_0C;
            		}

                    if (var_v0 < 0xA) {
                        if ((D_800FCB18[0]->unk_28 * 0.5) < D_800FCB18[0]->unk_0C) {
                            if (((D_800FCB18[1]->unk_28 * 0.5) < D_800FCB18[1]->unk_0C) && 
                                (D_800FCB18[0]->unk_0C < D_800FCB18[0]->unk_28) && 
                                (D_800FCB18[1]->unk_0C < D_800FCB18[1]->unk_28)) {
                                func_800420C0(D_80077E30);
                                return;
                            }
                        }
                    }

                    if (D_800FCB18[0]->unk_0C >= D_800FCB18[1]->unk_0C) {
                        var_v0 = D_800FCB18[0]->unk_0C - D_800FCB18[1]->unk_0C;
                    } else {
                    	var_v0 = D_800FCB18[1]->unk_0C - D_800FCB18[0]->unk_0C;
                    }

                    if (var_v0 < 0xA) {
                        if (D_800FCB18[0]->unk_0C < (D_800FCB18[0]->unk_28 * D_8007C7F8)) {
                            if (D_800FCB18[1]->unk_0C < (D_800FCB18[1]->unk_28 * D_8007C7F8)) {
                                func_800420C0(D_80077E28);
                                return;
                            }
                        }
                    }

                    if (D_80078400 == 0) {
                        func_800420C0(D_80077E78);
                    } else {
                    	func_800420C0(D_80077DF0);
                    }
                    return;
                }
            }
        }
    } else {
        temp_v0 = osSetIntMask(1);
        D_800783BC = 0;
        osSetIntMask(temp_v0);
        func_80037234(0x5A, 0);
        func_80037234(0x5B, 0);

        if (D_800FCB18[0] != NULL) {
            D_800FCB28 = D_800FCB18[0]->unk_0C;
        }

        if (D_800FCB18[1] != NULL) {
            D_800FCB2C = D_800FCB18[1]->unk_0C;
        }

        D_800783CC++;

        for (i = 0; i < 2; i++) {
        	D_800FCB48[i].unk_78++;
        	if (D_800FCB48[i].unk_7C != 0) {
        		D_800FCB48[i].unk_7C++;
        	}
        }

        D_800FCCB4 = 0;
        D_800FCCB3 = 0;
        D_800FCCB5 = 0;
        D_800783E4 = 0;

        if ((D_800FCB18[0] != NULL) && (D_800FCB18[1] != NULL) && 
            (D_8007840C != 0) && 
            (D_800FCB18[0]->unk_0C != 0) && (D_800FCB18[1]->unk_0C != 0) && 
            (func_80044E54(1) == 0)) {
            if (__ull_rem(osGetTime(), 2) == 0) {
                func_800420C0(D_800780A8);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003DB84.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003EB40.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003F1AC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003F4C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003F624.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8003F660.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_80040A70.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_800414B8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_8004153C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_80041688.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_800416BC.s")

#ifdef NON_MATCHING
void func_80041A98(void) {
    s32 i;
    s32 j;

    D_800783CC = 0;

    for (i = 0; i < 2; i++) {
    	for (j = 0; j < 8; j++) {
    		D_800FCB38[i][j] = 0;
    	}
    }

    D_8007839C[0] = 0;
    D_8007839C[1] = 0;
    D_800FCCA1 = 0;
    D_800FCCA0 = 0;
    D_800FCCA2 = 0;
    D_800FCCA4 = 0;
    D_800FCCAC = 0;
    D_800783E0 = 0;
    D_800FCCAF = 0;
    D_800FCCB0 = 0;
    D_800FCCB2 = 0;
    D_800FCCB3 = 0;
    D_800FCCB4 = 0;
    D_800FCCB5 = 0;
    D_800FCCB7 = 0;
    D_800FCCB6 = 0;
    D_800783E4 = 0;
    D_800783E8 = 0;
    D_800783EC = 0;
    D_800783F0 = 0;
    D_800783F4 = 0;
    D_800783F8 = 0;

    for (i = 0; i < 21; i++) {
    	D_800FCCD8[i] = 0;
    }

    for (i = 0; i < 80; i++) {
    	D_800FCC50[i] = 0;
    }

    for (i = 0; i < 2; i++) {
    	D_800FCCB8[i] = 0;
    	D_800FCCBA[i] = 0;
    	D_800FCCBC[i] = 0;
    	D_800FCCBE[i] = 0;
    	D_800FCCC0[i] = 0;
    	D_800FCCC2[i] = 0;
    	D_800FCCD4[i] = 0;
    	D_800FCCD6[i] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_80041A98.s")
#endif

void func_80041C70(u32 arg0) {
    u32 temp_v0;

    if ((D_80078388 != 0) && (D_800783FC != 0) && (arg0 != 0)) {
        temp_v0 = osSetIntMask(1);
        D_800783A4[D_800783B8 & 3] = arg0;
        D_800783B8++;
        osSetIntMask(temp_v0);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_80041CEC.s")

void func_80041D50(u8* arg0, u8* arg1) {
    u8 temp_v0 = *arg0;
    u8 temp_v1 = *arg1;

    if (temp_v1 != temp_v0) {
        *arg0 = temp_v1;
        *arg1 = temp_v0;
    }
}

u16 func_80041D70(u16 arg0) {
    s32 i;

    for (i = 0; i < 20; i++) {
        if (arg0 == D_800FCC50[i]) {
            return 0;
        }
    }

    return arg0;
}

void func_80041DF4(u16 arg0) {
    u16 i;

    for (i = 0; i < 19; i++) {
        D_800FCC50[i] = D_800FCC50[i + 1];
    }

    D_800FCC50[19] = arg0;
}

void func_80041E40(u16 arg0) {
    u32 i;

    for (i = arg0; i > 0; i--) {
        D_800FCC50[i] = D_800FCC50[i - 1];
    }

    D_800FCC50[0] = 0;
}

u32 func_80041EF4(u16* arg0) {
    u16 temp_v0 = *arg0;
    u32 i;
    u32 j;
    u16 sp5A;

    for (i = 0; i < temp_v0; i++) {
        D_800FCD18[i] = i + 1;
    }

    for (i = 0; i < temp_v0 << 1; i++) {
        func_80041D50(D_800FCD18, D_800FCD18 + __ull_rem(osGetTime(), (s32)temp_v0));
    } 

    for (i = 0; i < temp_v0; i++) {
        sp5A = func_80041D70(arg0[D_800FCD18[i]]);
        if (sp5A != 0) {
            func_80041DF4(sp5A);
            return sp5A;
        }
    }

    for (i = 0; i < 20; i++) {
        for (j = 1; j <= temp_v0; j++) {
            if (D_800FCC50[i] == arg0[j]) {
                func_80041E40(i);
                func_80041DF4(arg0[j]);
                return arg0[j];
            }
        }
    }

    return 0;
}

void func_800420C0(u16* arg0) {
    u32 temp_v0 = func_80041EF4(arg0);

    if (temp_v0 != 0) {
        func_80041C70(temp_v0);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_800420F0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_80042158.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_80042850.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/3D140/func_800428FC.s")
