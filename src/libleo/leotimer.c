#include <ultra64.h>
#include "libleo/internal.h"

void leoReadTimer(void) {
	UNUSED u8* rdparam;
	UNUSED u8 data[4];
    __LOCTime time;
    u8 sense_code = __locReadTimer(&time);
    LEOcur_command->data.time.yearlo = time.year;
    LEOcur_command->data.time.month = time.month;
    LEOcur_command->data.time.day = time.day;
    LEOcur_command->data.time.hour = time.hour;
    LEOcur_command->data.time.minute = time.minute;
    LEOcur_command->data.time.second = time.second;
    if (sense_code != 0) {
        LEOcur_command->header.sense = sense_code;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    if ((u8) LEOcur_command->data.time.yearlo >= 0x96U) {
        LEOcur_command->data.time.yearhi = 0x19;
    } else {
        LEOcur_command->data.time.yearhi = 0x20;
    }
    LEOcur_command->header.status = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/libleo/leotimer/leoSetTimer.s")

u8 __locReadTimer(__LOCTime* time) {
    u32 data;
    u8 sense_code;

    sense_code = leoSend_asic_cmd_w_nochkDiskChange(ASIC_READ_TIMER_MINUTE, 0U);
    if (sense_code != 0) {
        return sense_code;
    }
    osEPiReadIo(LEOPiInfo, LEO_DATA, &data);
    time->minute = (u8) ((u32) (data & 0xFF000000) >> 0x18);
    time->second = (s8) ((u32) (data & 0xFF0000) >> 0x10);
    sense_code = leoSend_asic_cmd_w_nochkDiskChange(ASIC_READ_TIMER_DATE, 0U);
    if (sense_code != 0) {
        time->minute = (u8) (time->minute & 0xFF7F);
        return sense_code;
    }
    osEPiReadIo(LEOPiInfo, LEO_DATA, &data);
    time->day = (s8) ((u32) (data & 0xFF000000) >> 0x18);
    time->hour = (s8) ((u32) (data & 0xFF0000) >> 0x10);
    sense_code = leoSend_asic_cmd_w_nochkDiskChange(ASIC_READ_TIMER_YEAR, 0U);
    if (sense_code != 0) {
        time->minute = (u8) (time->minute & 0xFF7F);
        return sense_code;
    }
    osEPiReadIo(LEOPiInfo, LEO_DATA, &data);
    sense_code = time->minute;
    time->year = (s8) ((u32) (data & 0xFF000000) >> 0x18);
    time->month = (s8) ((u32) (data & 0xFF0000) >> 0x10);
    if (sense_code & 0x80) {
        time->minute = (u8) (sense_code & 0xFF7F);
        return 5;
    }
    return 0;
}

u8 __locSetTimer(__LOCTime* time) {
    u32 yearMonth;
    u32 dayHour;
    u32 minuteSecond;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 result;

    yearMonth = (time->year << 0x18) + (time->month << 0x10);
    dayHour = (time->day << 0x18) + (time->hour << 0x10);
    minuteSecond = (time->minute << 0x18) + (time->second << 0x10);
    temp_v0 = leoSend_asic_cmd_w_nochkDiskChange(ASIC_SET_TIMER_YEAR, yearMonth);
    result = temp_v0;
    if ((temp_v0 != 0) || (temp_v0_2 = leoSend_asic_cmd_w_nochkDiskChange(ASIC_SET_TIMER_DATE, dayHour), result = temp_v0_2, (temp_v0_2 != 0)) || (temp_v0_3 = leoSend_asic_cmd_w_nochkDiskChange(ASIC_SET_TIMER_MINUTE, minuteSecond), result = temp_v0_3, (temp_v0_3 != 0))) {
        return result;
    }
    return 0;
}
