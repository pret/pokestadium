#include "global.h"
#include "libleo/internal.h"
#include "PR/os_message.h"

const u8 LEO_ZERO_MESG[] = { 0 };

void leoInitialize(OSPri compri, OSPri intpri, OSMesg* command_que_buf, u32 cmd_buff_size) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;
    OSPri pri;

    if (intpri < compri) {
        pri = compri;
    } else {
        pri = intpri;
    }

    oldPri = -1;

    myPri = osGetThreadPri(NULL);
    if (myPri < pri) {
        oldPri = myPri;
        osSetThreadPri(NULL, pri);
    }

    savedMask = __osDisableInt();

    __leoQueuesCreated = true;
    osCreateMesgQueue(&LEOcommand_que, command_que_buf, cmd_buff_size);
    osCreateMesgQueue(&LEOcontrol_que, LEOcontrol_que_buf, ARRAY_COUNT(LEOcontrol_que_buf));
    osCreateMesgQueue(&LEOevent_que, LEOevent_que_buf, ARRAY_COUNT(LEOevent_que_buf));
    osCreateMesgQueue(&LEOdma_que, LEOdma_que_buf, ARRAY_COUNT(LEOdma_que_buf));
    osCreateMesgQueue(&LEOblock_que, LEOblock_que_buf, ARRAY_COUNT(LEOblock_que_buf));
    osCreateMesgQueue(&LEOpost_que, LEOpost_que_buf, ARRAY_COUNT(LEOpost_que_buf));
    osCreateThread(&LEOcommandThread, 1, leomain, NULL, LEOcommandThreadStack, compri);
    osStartThread(&LEOcommandThread);
    osCreateThread(&LEOinterruptThread, 1, leointerrupt, NULL, (u32)&LEOcommand_que,
                   intpri); // this is not a stack. TODO: what is this call doing?
    osStartThread(&LEOinterruptThread);
    osSetEventMesg(OS_EVENT_CART, &LEOevent_que, (OSMesg)0x30000);
    osSendMesg(&LEOblock_que, NULL, 0);
    __osRestoreInt(savedMask);

    if (oldPri != -1) {
        osSetThreadPri(NULL, oldPri);
    }
}

void leoCommand(void* cmd_blk_addr) {
    if (__leoResetCalled != 0) {
        ((LEOCmd*)cmd_blk_addr)->header.status = LEO_STATUS_CHECK_CONDITION;
        ((LEOCmd*)cmd_blk_addr)->header.sense = LEO_SENSE_WAITING_NMI;
        if ((((LEOCmd*)cmd_blk_addr)->header.control & LEO_CONTROL_POST) != 0) {
            osSendMesg(((LEOCmd*)cmd_blk_addr)->header.post, (OSMesg)LEO_SENSE_WAITING_NMI, 1); // Presumably
        }
        return;
    }
    osRecvMesg(&LEOblock_que, NULL, 1);
    ((LEOCmd*)cmd_blk_addr)->header.status = LEO_STATUS_BUSY;
    ((LEOCmd*)cmd_blk_addr)->header.sense = LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;

    switch (((LEOCmd*)cmd_blk_addr)->header.command) {
        case 1:
            LEOclr_que_flag = 0xFF;
            leoClr_queue();
            LEOclr_que_flag = 0;
            ((LEOCmd*)cmd_blk_addr)->header.status = LEO_STATUS_GOOD;
            if (((LEOCmd*)cmd_blk_addr)->header.control & LEO_CONTROL_POST) {
                osSendMesg(((LEOCmd*)cmd_blk_addr)->header.post, (OSMesg)0, 1);
            }
            break;

        case 5:
        case 6:
            ((LEOCmd*)cmd_blk_addr)->data.readwrite.rw_bytes = 0;
            goto cmd_queing;

        default:
            if ((u32)(((LEOCmd*)cmd_blk_addr)->header.command - 1) >= 0xE) {
                ((LEOCmd*)cmd_blk_addr)->header.sense = LEO_SENSE_INVALID_COMMAND_OPERATION_CODE;
                ((LEOCmd*)cmd_blk_addr)->header.status = LEO_STATUS_CHECK_CONDITION;
                break;
            }

        cmd_queing:
            if (osSendMesg(&LEOcommand_que, (OSMesg)cmd_blk_addr, 0) != 0) {
                ((LEOCmd*)cmd_blk_addr)->header.sense = LEO_SENSE_QUEUE_FULL;
                ((LEOCmd*)cmd_blk_addr)->header.status = LEO_STATUS_CHECK_CONDITION;
            }
    }
    osSendMesg(&LEOblock_que, (OSMesg)0, 1);
}

void LeoReset(void) {
    __leoResetCalled = true;
    if (__leoQueuesCreated) {
        LEOclr_que_flag = 0xFF;
        leoClr_queue();
        LEOclr_que_flag = 0;
        osRecvMesg(&LEOevent_que, NULL, 0);
        osSendMesg(&LEOevent_que, (OSMesg)ASIC_SOFT_RESET_CODE, 1);
        osSendMesg(&LEOcommand_que, (OSMesg)LEO_ZERO_MESG, 1);
    }
}

s32 __leoSetReset(void) {
    leoDrive_reset();
    return 0;
}

s32 LeoResetClear(void) {
    LEOCmdHeader resetclear;

    resetclear.command = 0xF;
    resetclear.control = LEO_CONTROL_POST;
    resetclear.status = 0;
    resetclear.post = &LEOpost_que;
    if (osSendMesg(&LEOcommand_que, &resetclear.command, 0) != 0) {
        return LEO_SENSE_QUEUE_FULL;
    }
    osRecvMesg(&LEOpost_que, NULL, 1);
    if (resetclear.status == LEO_STATUS_GOOD) {
        return LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
    }
    return resetclear.sense;
}
