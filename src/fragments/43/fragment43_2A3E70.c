#include "fragment43.h"
#include "src/2E110.h"

static char** D_83407BF0;
static char** D_83407BF4;

void func_83402340(void) {
    D_83407BF0 = func_8002D5AC(0x2C);
    D_83407BF4 = func_8002D5AC(0x1A);
}

char* func_83402374(s32 arg0) {
    return func_8002D7C0(NULL, 0, D_83407BF0, arg0);
}

char* func_834023A4(char* arg0, s32 arg1, s32 arg2) {
    return func_8002D7C0(arg0, arg1, D_83407BF0, arg2);
}

char* func_834023CC(s32 arg0) {
    func_8002D7C0(NULL, 0, D_83407BF4, arg0);
}

char* func_834023FC(char* arg0, s32 arg1, u32 arg2) {
    func_8002D7C0(arg0, arg1, D_83407BF4, arg2);
}
