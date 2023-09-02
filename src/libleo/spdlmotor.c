#include <ultra64.h>
#include "libleo/internal.h"

s32 LeoSpdlMotor(LEOCmd* cmdBlock, u8 mode, OSMesgQueue* mq) {
    if (!__leoActive) {
        return -1;
    }
    cmdBlock->header.command = LEO_COMMAND_START_STOP;
    cmdBlock->header.reserve1 = 0;

    switch (mode) {
        case LEO_MOTOR_ACTIVE:
            cmdBlock->header.control = LEO_CONTROL_START;
            break;
        case LEO_MOTOR_STANDBY:
            cmdBlock->header.control = LEO_CONTROL_STBY;
            break;
        case LEO_MOTOR_SLEEP:
            cmdBlock->header.control = 0;
            break;
        case LEO_MOTOR_BRAKE:
            cmdBlock->header.control = LEO_CONTROL_BRAKE;
            break;
    }
    cmdBlock->header.reserve3 = 0;

    if (mq != NULL) {
        cmdBlock->header.post = mq;
        cmdBlock->header.control |= LEO_CONTROL_POST;
    }

    leoCommand(cmdBlock);
    return 0;
}
