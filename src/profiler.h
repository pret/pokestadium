#ifndef _PROFILER_H_
#define	_PROFILER_H_

/*
 * This struct contains time values per frame which is kept up by profiler.c. The game has
 * functions which are called by their respective threads which back up the current OSTime
 * to the appropriate array and index so the profiler can calculate the duration and display
 * it to the profiler later.
 */
struct ProfilerFrameData {
    /* 0x00 */ s16 numSoundTimes;
    /* 0x02 */ s16 numVblankTimes;
    /* 0x08 */ OSTime gameTimes[5];
    /* 0x30 */ OSTime gfxTimes[3];
    /* 0x48 */ OSTime soundTimes[8];
    /* 0x88 */ OSTime vblankTimes[8];
}; // size = 0xC8

// Unlike prior EAD profiler versions, the frame index values are built into the profiler
// struct now.
struct Profiler {
    /* 0x0000 */ struct ProfilerFrameData profiler_data[3];
    /* 0x0258 */ s16 unused; // unused. extra frame index?
    /* 0x025A */ s16 frameIdx1;
    /* 0x025C */ s16 frameIdx2;
}; // size = 0x260

// thread event IDs
enum ProfilerGameEvent {
    THREAD5_START,
    UNK_EVENT_1,
    UNK_EVENT_2,
    THREAD5_END
};

enum ProfilerGfxEvent {
    TASKS_QUEUED,
    RSP_COMPLETE,
    RDP_COMPLETE
};

enum SetGetTimeDiff {
    SET_TIME = 1,
    GET_TIME_DIFF = 2
};

void profiler_log_thread5_time(enum ProfilerGameEvent eventID);
void profiler_log_thread4_time(void);
void profiler_log_gfx_time(enum ProfilerGfxEvent eventID);
void profiler_log_vblank_time(void);
void draw_profiler_rect(s32 ulx, s32 lrx, s32 uly_in, u16 color);
void draw_profiler_bar_cpu(OSTime clockBase, OSTime clockStart, OSTime clockEnd, s16 posY, u16 color);
void draw_profiler_bar_cpu_keep_max(OSTime start, OSTime end, s16 posY, s16* last_max, s16* reset_ctr);
void draw_reference_profiler_bars(void);
void draw_profiler_mode_1(void);
void draw_profiler_mode_0(void);
void draw_profiler(s32 profiler_mode);
void print_profiler_metrics(void);
void clear_profiler_data(void);
u32 set_get_time_diff(enum SetGetTimeDiff state);

#endif // _PROFILER_H_
