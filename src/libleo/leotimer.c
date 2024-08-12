#include "global.h"
#include "libleo/internal.h"

static const u8 ymdupper[6] = { 99, 12, 31, 23, 59, 59 };
static const u8 dayupper[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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
    if ((u8)LEOcur_command->data.time.yearlo >= 0x96U) {
        LEOcur_command->data.time.yearhi = 0x19;
    } else {
        LEOcur_command->data.time.yearhi = 0x20;
    }
    LEOcur_command->header.status = 0;
}

void leoSetTimer(void) {
    UNUSED LEOCmdReadTimer rd_timer;
    u8* p_tmp = &LEOcur_command->data.time.yearlo;
    u32 year;
    u32 month;
    u32 temp;
    u32 ymd;
    u8 result;
    __LOCTime time;

    // Verify values (if they're correct BCD or within limits)

    for (ymd = 0; ymd < 6; ymd++) {
        temp = *p_tmp;

        // Verify right nybble (only right nybble for some reason)
        if ((temp & 0xF) > 9) {
            // nybble is above 0x9 therefore the BCD value is invalid
            LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
            LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
            return;
        }

        // Convert BCD value to binary value
        temp = temp - ((temp >> 4) * 6);

        switch (ymd) {
            case 2:
                // Day value check
                if ((dayupper[month] < temp) && ((temp != 0x1D) || (year & 3))) {
                    LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
                    LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                    return;
                }
            case 1:
                // Month value cannot be 0
                if (temp == 0) {
                    LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
                    LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                    return;
                }
            default:
                // Verify max value of each time info
                if (ymdupper[ymd] < temp) {
                    LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
                    LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                    return;
                }
        }

        year = month;
        month = temp;
        p_tmp++;
    }

    // Every value has been ymd good, now set the values in hardware

    // Prepare the time info to use
    time.year = LEOcur_command->data.time.yearlo;
    time.month = LEOcur_command->data.time.month;
    time.day = LEOcur_command->data.time.day;
    time.hour = LEOcur_command->data.time.hour;
    time.minute = LEOcur_command->data.time.minute;
    time.second = LEOcur_command->data.time.second;

    // Set the new time
    result = __locSetTimer(&time);
    if (result != 0) {
        LEOcur_command->header.sense = result;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    // Get the time
    result = __locReadTimer(&time);
    if (result != 0) {
        LEOcur_command->header.sense = result;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    // Check if the time is set correctly
    if ((time.year != LEOcur_command->data.time.yearlo) || (time.month != LEOcur_command->data.time.month) ||
        (time.day != LEOcur_command->data.time.day) || (time.hour != LEOcur_command->data.time.hour) ||
        (time.minute != LEOcur_command->data.time.minute) || (time.second != LEOcur_command->data.time.second)) {
        LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    LEOcur_command->header.status = LEO_STATUS_GOOD;
}

u8 __locReadTimer(__LOCTime* time) {
    u32 data;
    u8 sense_code;

    sense_code = leoSend_asic_cmd_w_nochkDiskChange(ASIC_READ_TIMER_MINUTE, 0U);
    if (sense_code != 0) {
        return sense_code;
    }
    osEPiReadIo(LEOPiInfo, LEO_DATA, &data);
    time->minute = (u8)((u32)(data & 0xFF000000) >> 0x18);
    time->second = (s8)((u32)(data & 0xFF0000) >> 0x10);
    sense_code = leoSend_asic_cmd_w_nochkDiskChange(ASIC_READ_TIMER_DATE, 0U);
    if (sense_code != 0) {
        time->minute = (u8)(time->minute & 0xFF7F);
        return sense_code;
    }
    osEPiReadIo(LEOPiInfo, LEO_DATA, &data);
    time->day = (s8)((u32)(data & 0xFF000000) >> 0x18);
    time->hour = (s8)((u32)(data & 0xFF0000) >> 0x10);
    sense_code = leoSend_asic_cmd_w_nochkDiskChange(ASIC_READ_TIMER_YEAR, 0U);
    if (sense_code != 0) {
        time->minute = (u8)(time->minute & 0xFF7F);
        return sense_code;
    }
    osEPiReadIo(LEOPiInfo, LEO_DATA, &data);
    sense_code = time->minute;
    time->year = (s8)((u32)(data & 0xFF000000) >> 0x18);
    time->month = (s8)((u32)(data & 0xFF0000) >> 0x10);
    if (sense_code & 0x80) {
        time->minute = (u8)(sense_code & 0xFF7F);
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
    if ((temp_v0 != 0) ||
        (temp_v0_2 = leoSend_asic_cmd_w_nochkDiskChange(ASIC_SET_TIMER_DATE, dayHour), result = temp_v0_2,
         (temp_v0_2 != 0)) ||
        (temp_v0_3 = leoSend_asic_cmd_w_nochkDiskChange(ASIC_SET_TIMER_MINUTE, minuteSecond), result = temp_v0_3,
         (temp_v0_3 != 0))) {
        return result;
    }
    return 0;
}
