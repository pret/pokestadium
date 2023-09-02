#ifndef _CRASH_SCREEN_H_
#define _CRASH_SCREEN_H_

typedef struct {
    /* 0x000 */ OSThread thread;
    /* 0x1B0 */ char stack[0x800];
    /* 0x9B0 */ OSMesgQueue queue;
    /* 0x9C8 */ OSMesg mesg;
    /* 0x9CC */ u16* frameBuf;
    /* 0x9D0 */ u16 width;
    /* 0x9D2 */ u16 height;
} CrashScreen; // size = 0x9D4

extern CrashScreen gCrashScreen;
extern u8 gCrashScreenCharToGlyph[128];
extern u32 gCrashScreenFont[];
extern const char* gFaultCauses[18];
extern const char* gFPCSRFaultCauses[6];
extern u16 gCrashScreenUnlockInputs[];

void crash_screen_sleep(s32 ms);
void crash_screen_wait_for_button_combo(void);
void crash_screen_draw_rect(s32 x, s32 y, s32 width, s32 height);
void crash_screen_draw_glyph(s32 x, s32 y, s32 glyph);
char *crash_screen_copy_to_buf(char *buffer, const char *data, size_t size);
void crash_screen_printf(s32 x, s32 y, const char *fmt, ...);
void crash_screen_print_fpr(s32 x, s32 y, s32 regNum, void *addr);
void crash_screen_print_fpcsr(u32 fpcsr);
void crash_screen_draw(OSThread* faultedThread);
OSThread* crash_screen_get_faulted_thread(void);
void crash_screen_thread_entry(void* unused);
void crash_screen_set_draw_info(u16* frameBufPtr, u16 width, u16 height);
void crash_screen_init(void);
void crash_screen_printf_with_bg(s16 x, s16 y, const char* fmt, ...);

#endif // _CRASH_SCREEN_H_
