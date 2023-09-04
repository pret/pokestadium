#ifndef _RESET_H_
#define _RESET_H_

void SoftReset_ClearLines320(u16 *buf);
void SoftReset_ClearLines640(u16 *buf);
void func_8000559C(void);
void SoftReset_Thread(void* unused);
void SoftReset_CreateThread(void);

#endif // _RESET_H_
