#ifndef _D470_H_
#define _D470_H_

#include "global.h"

OSPiHandle* func_8000C870(u8 latency, u8 pulse, u8 page_size, u8 rel_duration, u32 start);
OSPiHandle* func_8000C8F8(void);
void func_8000CA4C(u8* flash_status);
void func_8000CB18(u32* flash_type, u32* flash_maker);
void func_8000CC30(void);
s32 func_8000CC9C(void);
s32 func_8000CDB8(s32 arg0);
s32 func_8000CEE4(OSIoMesg* mb, s32 priority, void* dramAddr, OSMesgQueue* mq);
s32 func_8000CFB0(s32 arg0);
s32 func_8000D0B4(OSIoMesg* mb, s32 priority, s32 devAddr, void* dramAddr, s32 n_pages, OSMesgQueue* mq);

#endif // _D470_H_
