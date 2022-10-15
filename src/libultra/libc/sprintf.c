#include <ultratypes.h>
#include "stdarg.h"

typedef unsigned long uintptr_t;

int _Printf(char *(*prout)(char *, const char *, size_t), char *dst, const char *fmt, va_list args);

void* proutSprintf(void* dst, const char* fmt, size_t size) {
    return (void*)((uintptr_t)memcpy(dst, fmt, size) + size);
}

int sprintf(char* dst, char* fmt, ...) {
    int ans;
    va_list args;
    va_start(args, fmt);

    ans = _Printf((void*)&proutSprintf, dst, fmt, args);
    if (ans > -1) {
        dst[ans] = 0;
    }

    va_end(args);

    return ans;
}
