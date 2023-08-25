#include <ultra64.h>
#include "profiler.h"

extern OSTime D_800A6CE8;
extern Gfx *gDisplayListHead;

struct Profiler gProfiler;

/*
 * The profiler uses a value that is seemingly derived from an unknown approximation
 * of 60 FPS. You can get varying close values by doing (62500000*3/4)/60, but they
 * dont quite match up. This may be some developer approximation of 60 FPS based on
 * a VI formula.
 *
 * TODO: Is there any way to derive this value correctly?
 */
#define UNK_FPS_60_APPROX_VALUE  770296

// log the current osTime to the appropriate idx for current thread5 processes.
void profiler_log_thread5_time(enum ProfilerGameEvent eventID) {
    if (eventID == THREAD5_START) {
        gProfiler.profiler_data[gProfiler.frameIdx1].gameTimes[eventID] = D_800A6CE8;
    } else {
        gProfiler.profiler_data[gProfiler.frameIdx1].gameTimes[eventID] = osGetTime();
    }

    // event ID 3 is the last profiler event for after incrementing
    // buffers: increment the Info after updating.
    if (eventID == THREAD5_END) {
        if (gProfiler.frameIdx1 == 2) {
            gProfiler.frameIdx1 = 0;
        } else {
            gProfiler.frameIdx1++;
        }
        gProfiler.profiler_data[gProfiler.frameIdx1].numSoundTimes = 0;
    }
}

// log the audio system before and after osTimes in pairs to the soundTimes array.
void profiler_log_thread4_time(void) {
    struct ProfilerFrameData *profiler = &gProfiler.profiler_data[gProfiler.frameIdx1];

    if(profiler->numSoundTimes < ARRAY_COUNT(profiler->soundTimes)) {
       profiler->soundTimes[profiler->numSoundTimes++] = osGetTime();
    }
}

// log the times for gfxTimes: RSP completes, and RDP completes.
void profiler_log_gfx_time(enum ProfilerGfxEvent eventID) {
    if (eventID == TASKS_QUEUED) {
        if (gProfiler.frameIdx2 == 2) {
            gProfiler.frameIdx2 = 0;
        } else {
            gProfiler.frameIdx2++;
        }
        gProfiler.profiler_data[gProfiler.frameIdx2].numVblankTimes = 0;
    }
    gProfiler.profiler_data[gProfiler.frameIdx2].gfxTimes[eventID] = osGetTime();
}

// log the times between vblank started and ended.
void profiler_log_vblank_time(void) {
    struct ProfilerFrameData *profiler = &gProfiler.profiler_data[gProfiler.frameIdx2];

    if (profiler->numVblankTimes < ARRAY_COUNT(profiler->vblankTimes)) {
        profiler->vblankTimes[profiler->numVblankTimes++] = osGetTime();
    }
}

/*
 * Render the actual rectangle for the profiler display.
 */
void draw_profiler_rect(s32 ulx, s32 lrx, s32 uly_in, u16 color) {
    s32 uly = uly_in;
    s32 lry = uly + 2;

    if (func_80007A58() != 0) {
        ulx <<= 1;
        lrx <<= 1;
        uly <<= 1;
        lry <<= 1;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, (color << 0x10) | color);
    gDPFillRectangle(gDisplayListHead++, ulx, uly, lrx, lry);
}

// Draw the CPU bar.
void draw_profiler_bar_cpu(OSTime clockBase, OSTime clockStart, OSTime clockEnd, s16 posY, u16 color) {
    s64 durationStart, durationEnd;
    s32 rectX1, rectX2;

    // set the duration to start, and floor to 0 if the result is below 0.
    if ((durationStart = clockStart - clockBase) < 0) {
        durationStart = 0;
    }
    // like the above, but with end.
    if ((durationEnd = clockEnd - clockBase) < 0) {
        durationEnd = 0;
    }

    // calculate the x coordinates of where start and end begins, respectively.
    // convert the cycles to microseconds, but multiply by 3 before converting them
    // to nanoseconds. So why not just use OS_CYCLES_TO_NSEC?
    rectX1 = ((OS_CYCLES_TO_USEC(durationStart)) * 3ULL / 1000ULL) + 30;
    rectX2 = ((OS_CYCLES_TO_USEC(durationEnd))   * 3ULL / 1000ULL) + 30;

    if (rectX1 > 225) {
        rectX1 = 225;
    }
    if (rectX2 > 225) {
        rectX2 = 225;
    }

    // perform the render if start is less than end. in most cases, it should be.
    if (rectX1 < rectX2) {
        draw_profiler_rect(rectX1, rectX2, posY, color);
    }
}

/*
 * Similar to draw_profiler_bar_cpu, draw a CPU bar, but this time, draw it based on
 * the maximum value observed in the last 16 calls. This may be useful for observing
 * quick rises in lag over a duration period.
 */
void draw_profiler_bar_cpu_keep_max(OSTime start, OSTime end, s16 posY, s16* last_max, s16* reset_ctr) {
    s64 duration;
    s32 ulx;
    s32 lrx;

    // set the duration, and floor to 0 if the result is below 0.
    if ((duration = end - start) < 0) {
         duration = 0;
    }

    // like earlier, multiply by 3 and convert to nsec by dividing by 1000.
    // why not just use OS_CYCLES_TO_NSEC?
    lrx = (OS_CYCLES_TO_USEC(duration) * 3ULL / 1000ULL) + 30;
    if(lrx > 225) {
       lrx = 225;
    }

    // Keep the maximum lrx seen in the last 16 calls. If a new max is seen, reset
    // the counter to start over and set the new observed maximum.
    if(++*reset_ctr > 15 || *last_max < lrx) {
        *reset_ctr = 0;
        *last_max = lrx;
    }
    
    // now that we have a max, build the coordinates to make the rect.
    lrx = *last_max;
    ulx = lrx - 4;
    if (ulx < 30) {
        ulx = 30;
    }

    if (ulx < lrx) {
        draw_profiler_rect(ulx, lrx, posY, GPACK_RGBA5551(160, 200, 248, 1));
    }
}

void draw_reference_profiler_bars(void) {
    // Draws the reference "max" bars underneath the real thing.
    draw_profiler_rect(30,   79, 220, GPACK_RGBA5551(40,  80,  255, 1)); // Blue
    draw_profiler_rect(79,  128, 220, GPACK_RGBA5551(255, 255, 40,  1)); // Yellow
    draw_profiler_rect(128, 177, 220, GPACK_RGBA5551(255, 120, 40,  1)); // Orange
    draw_profiler_rect(177, 226, 220, GPACK_RGBA5551(255, 40,  40,  1)); // Red
}

/*
 * Draw Profiler Mode 1. This mode draws a traditional per-event bar for durations
 * of tasks recorded by the profiler calls of various threads.
 */
void draw_profiler_mode_1(void) {
    s32 i;
    struct ProfilerFrameData *profiler;
    struct ProfilerFrameData *profiler_2;
    OSTime clockBase;

    // set profiler pointers. first pointer is for game+sound profiler and 2nd is for gfx and vblank.
    profiler   = &gProfiler.profiler_data[(gProfiler.frameIdx1 == 0) ? 2 : gProfiler.frameIdx1 - 1];
    profiler_2 = &gProfiler.profiler_data[(gProfiler.frameIdx2 == 0) ? 2 : gProfiler.frameIdx2 - 1];

    // calculate the clockBase.
    clockBase = profiler->gameTimes[0] - UNK_FPS_60_APPROX_VALUE;

    // (yellow)
    draw_profiler_bar_cpu(clockBase, profiler->gameTimes[0], profiler->gameTimes[1], 212, GPACK_RGBA5551(255, 255, 40, 1));
    
    // (orange)
    draw_profiler_bar_cpu(clockBase, profiler->gameTimes[1], profiler->gameTimes[2], 212, GPACK_RGBA5551(255, 120, 40, 1));

    // we need to get the amount of finished numSoundTimes pairs, so get rid of the odd bit to get the
    // limit of finished pairs.
    profiler->numSoundTimes &= 0xFFFE;

    // draw the sound update times. (red)
    for (i = 0; i < profiler->numSoundTimes; i += 2) {
        draw_profiler_bar_cpu(clockBase, profiler->soundTimes[i], profiler->soundTimes[i + 1], 212, GPACK_RGBA5551(255, 40, 40, 1));
    }

    //! RSP and RDP run in parallel, so while they are not absolutely guaranteed to return in order,
    //  it is theoretically possible they might not. In all cases, the RDP should finish later than RSP.
    //  Thus, this is not really a bug in practice, but should still be noted that the C doesn't check
    //  this.
    draw_profiler_bar_cpu(clockBase, profiler_2->gfxTimes[0], profiler_2->gfxTimes[1], 216, GPACK_RGBA5551(255, 255, 40, 1));
    draw_profiler_bar_cpu(clockBase, profiler_2->gfxTimes[1], profiler_2->gfxTimes[2], 216, GPACK_RGBA5551(255, 120, 40, 1));

    // like earlier, toss the odd bit.
    profiler_2->numVblankTimes &= 0xFFFE;

    // render the vblank time pairs. (red)
    for (i = 0; i < profiler_2->numVblankTimes; i += 2) {
        draw_profiler_bar_cpu(clockBase, profiler_2->vblankTimes[i], profiler_2->vblankTimes[i + 1], 216, GPACK_RGBA5551(255, 40, 40, 1));
    }

    draw_reference_profiler_bars();
}

/*
 * Draw Profiler Mode 0. This mode renders bars over each other to make it
 * easier to see which processes take the longest.
 */
void draw_profiler_mode_0(void) {
    s32 i;                 // set profiler pointers. first pointer is for game+sound profiler and 2nd is for gfx and vblank.
    struct ProfilerFrameData *profiler   = &gProfiler.profiler_data[(gProfiler.frameIdx1 == 0) ? 2 : gProfiler.frameIdx1 - 1];
    OSTime clockStart = profiler->gameTimes[0] <= profiler->soundTimes[0] ? profiler->gameTimes[0]
                                                                       : profiler->soundTimes[0];
    OSTime gameDuration = profiler->gameTimes[1] - clockStart;
    OSTime renderDuration = profiler->gameTimes[2] - profiler->gameTimes[1];
    OSTime taskStart = 0;
    struct ProfilerFrameData *profiler_2 = &gProfiler.profiler_data[(gProfiler.frameIdx2 == 0) ? 2 : gProfiler.frameIdx2 - 1];
    OSTime rspDuration = profiler_2->gfxTimes[1] - profiler_2->gfxTimes[0];
    OSTime rdpDuration = profiler_2->gfxTimes[2] - profiler_2->gfxTimes[0];
    OSTime vblank = 0;
    static s16 sRenderLastMax  = 0;
    static s16 sRenderResetCtr = 0;
    static s16 sRDPLastMax     = 0;
    static s16 sRDPResetCtr    = 0;

    // like above functions, toss the odd bit.
    profiler->numSoundTimes &= 0xFFFE;

    // sound duration seems to be rendered with empty space and not actually drawn.
    for (i = 0; i < profiler->numSoundTimes; i += 2) {
        // calculate sound duration of max - min
        u64 soundDuration = profiler->soundTimes[i + 1] - profiler->soundTimes[i];
        taskStart += soundDuration;
        // was the sound time minimum less than game execution?
        if (profiler->soundTimes[i] < profiler->gameTimes[1]) {
            // overlay the gameDuration onto the profiler by subtracting the soundDuration.
            gameDuration -= soundDuration;
        } else if (profiler->soundTimes[i] < profiler->gameTimes[2]) {
            // overlay the renderDuration onto the profiler by subtracting the soundDuration.
            renderDuration -= soundDuration;
        }
    }

    // same as above. toss the odd bit.
    profiler_2->numVblankTimes &= 0xFFFE;

    for (i = 0; i < profiler_2->numVblankTimes; i += 2) {
        vblank += (profiler_2->vblankTimes[i + 1] - profiler_2->vblankTimes[i]);
    }

    // draw sound duration as the first bar. (red)
    clockStart = 0;
    draw_profiler_bar_cpu(0, clockStart, clockStart + taskStart, 212, GPACK_RGBA5551(255, 40, 40, 1));

    // draw game execution duration. (yellow)
    clockStart += taskStart;
    draw_profiler_bar_cpu(0, clockStart, clockStart + gameDuration, 212,
                      GPACK_RGBA5551(255, 255, 40, 1));

    // draw render duration. (orange)
    clockStart += gameDuration;
    draw_profiler_bar_cpu(0, clockStart, clockStart + renderDuration, 212,
                      GPACK_RGBA5551(255, 120, 40, 1));

    draw_profiler_bar_cpu_keep_max(0, clockStart + renderDuration, 212, &sRenderLastMax, &sRenderResetCtr);

    // Draw bottom profilers.

    // rdp duration (orange)
    draw_profiler_bar_cpu(0, 0, rdpDuration, 216, GPACK_RGBA5551(255, 120, 40, 1));
    // rsp duration (yellow)
    draw_profiler_bar_cpu(0, 0, rspDuration, 216, GPACK_RGBA5551(255, 255, 40, 1));
    // vblank duration (red)
    draw_profiler_bar_cpu(0, 0, vblank, 216, GPACK_RGBA5551(255, 40, 40, 1));

    draw_profiler_bar_cpu_keep_max(0, rdpDuration, 216, &sRDPLastMax, &sRDPResetCtr);

    draw_reference_profiler_bars();
}

// Draw the Profiler per frame.
void draw_profiler(s32 profiler_mode) {
    s32 ulx;
    s32 uly;
    s32 ulx_off;
    s32 uly_off;

    gDPPipeSync(gDisplayListHead++);
    gDPSetCycleType(gDisplayListHead++, G_CYC_FILL);
    gDPSetRenderMode(gDisplayListHead++, G_RM_NOOP, G_RM_NOOP2);

    ulx     = 30;
    uly     = 211;
    ulx_off = 196;
    uly_off = 9;

    if (func_80007A58() != 0) {
        ulx     <<= 1;
        uly     <<= 1;
        ulx_off <<= 1;
        uly_off <<= 1;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetFillColor(gDisplayListHead++, 0x00010001);
    gDPFillRectangle(gDisplayListHead++, ulx, uly, ulx + ulx_off, uly + uly_off);

    if (profiler_mode == 0) {
        draw_profiler_mode_0();
    } else {
        draw_profiler_mode_1();
    }
}

/*
 * Print the CPU and RCP metrics to the screen, using a scale to approximate it to a scale near 0.0-1.0.
 * Based on the 770296 value documented earlier (it is close to a 60 FPS approximation), it may have been
 * used to measure for undesired lag (values above 1.0) when printed to the screen.
 */
void print_profiler_metrics(void) {
    struct ProfilerFrameData *profiler   = &gProfiler.profiler_data[(gProfiler.frameIdx1 == 0) ? 2 : gProfiler.frameIdx1 - 1];
    struct ProfilerFrameData *profiler_2 = &gProfiler.profiler_data[(gProfiler.frameIdx2 == 0) ? 2 : gProfiler.frameIdx2 - 1];
    s32 pad[3]; // i dont understand. but ok.

    HAL_Printf(240, 210, "CPU:%5.3f", ((profiler->gameTimes[2]  - profiler->gameTimes[0]))  * (1/(float)UNK_FPS_60_APPROX_VALUE));
    HAL_Printf(240, 220, "RCP:%5.3f", ((profiler_2->gfxTimes[2] - profiler_2->gfxTimes[0])) * (1/(float)UNK_FPS_60_APPROX_VALUE));
}

// reset the profiler data to uninitialized 0s.
void clear_profiler_data(void) {
    bzero(&gProfiler.profiler_data[0], sizeof(struct ProfilerFrameData));
    gProfiler.frameIdx1 = 1;
    gProfiler.frameIdx2 = 1;
}

// unused. seems to be intended to set a static OSTime and then get the last difference (in usec)
// since the last set.
u32 set_get_time_diff(enum SetGetTimeDiff state) {
    u32 ret = 0;
    static OSTime sBackupTime = 0ULL;

    switch(state) {
        case SET_TIME:
            sBackupTime = osGetTime();
            ret = 0;
            break;
        case GET_TIME_DIFF:
            ret = OS_CYCLES_TO_USEC(osGetTime() - sBackupTime);
            break;
    }
    return ret;
}
