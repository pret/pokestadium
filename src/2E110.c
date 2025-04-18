#include "2E110.h"
#include "src/3FB0.h"
#include "src/memory.h"

#define D_800AF740_NUM_FILES 42

static BinArchive* D_800AF740;
static char** D_800AF744;

void func_8002D510(void) {
    s32 i;

    D_800AF740 = func_800044F4(textdata_ROM_START, NULL, 1, 0);
    D_800AF744 = main_pool_alloc(D_800AF740_NUM_FILES * sizeof(char*), 0);

    for (i = 0; i < D_800AF740_NUM_FILES; i++) {
        D_800AF744[i] = NULL;
    }
}

char** func_8002D5AC(s32 file_number) {
    return (char**)func_8000484C(D_800AF740, file_number);
}

void func_8002D5D4(u32 arg0, u32 arg1) {
    if ((arg0 >= 0x14) && (arg0 < 0x2A)) {
        D_800AF744[arg0] = (char*)arg1;
    }
}

void func_8002D600(u32 arg0, u32 arg1) {
    if ((arg0 != 0) && (arg0 < 0xA)) {
        D_800AF744[arg0] = (char*)arg1;
    }
}

void func_8002D628(char* arg0, u32 arg1, s8* arg2) {
    u32 i;
    s32 var_s2;
    s32 temp_v0;
    char sp58[12];
    s8* var_s4;
    char* sp54;
    u32 var_s3;

    var_s2 = 0;
    var_s3 = 0;
    sp54 = var_s4;
    var_s4 = sp54;
    i = 0;

    while (i < arg1 - 1u) {
        switch (var_s2) {
            case 0:
                temp_v0 = *arg2++;
                if (temp_v0 == '\x00') {
                    goto end;
                }

                if (temp_v0 == '#') {
                    temp_v0 = *arg2++;

                    temp_v0 -= '0';
                    temp_v0 = (*arg2++ + (temp_v0 * 10)) - '0';
                    if ((temp_v0 > 0) && (temp_v0 < 10)) {
                        sprintf(sp58, "%d", D_800AF744[temp_v0]);
                        var_s4 = sp58;
                        var_s2 = 1;
                        continue;
                    }

                    if ((temp_v0 >= 0x14) && (temp_v0 < 0x2A)) {
                        if (D_800AF744[temp_v0] != NULL) {
                            var_s4 = D_800AF744[temp_v0];
                            var_s2 = 1;
                        }
                        continue;
                    }
                } else {
                    *arg0++ = temp_v0;
                    var_s3++;
                    i++;
                }
                break;

            case 1:
                temp_v0 = *var_s4++;
                if (temp_v0 == '\x00') {
                    var_s2 = 0;
                } else {
                    *arg0++ = temp_v0;
                    var_s3++;
                    i++;
                }
                break;
        }
    }

end:
    *arg0++ = '\x00';
}

char* func_8002D7C0(char* arg0, s32 arg1, char** arg2, u32 file_number) {
    char* sp1C;
    char* sp18 = (u32)arg2 + (u32)arg2[file_number + 1];

    if (arg0 == NULL) {
        sp1C = sp18;
    } else {
        sp1C = arg0;
        func_8002D628(arg0, arg1, sp18);
    }

    return sp1C;
}

s32 func_8002D80C(s8* arg0) {
    s32 last_chr = 0;
    s32 line_count = 0;
    s32 chr = *arg0++;

    while (chr != 0) {
        last_chr = chr;
        if (chr == '\n') {
            line_count++;
        }
        chr = *arg0++;
    }

    if (last_chr != '\n') {
        line_count++;
    }

    return line_count;
}
