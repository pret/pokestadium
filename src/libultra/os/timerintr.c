#include "PR/os_internal.h"
#include "osint.h"

OSTimer *__osTimerList = &__osBaseTimer;
OSTimer __osBaseTimer;
OSTime __osCurrentTime;
u32 __osBaseCounter;
u32 __osViIntrCount;
u32 __osTimerCounter;

void __osTimerServicesInit(void) {
	__osCurrentTime = 0;
	__osBaseCounter = 0;
	__osViIntrCount = 0;
	__osTimerList->prev = __osTimerList;
	__osTimerList->next = __osTimerList->prev;
	__osTimerList->value = 0;
	__osTimerList->interval = __osTimerList->value;
	__osTimerList->mq = NULL;
	__osTimerList->msg = 0;
}

void __osTimerInterrupt(void) {
	OSTimer *t;
	u32 count;
	u32 elapsed_cycles;

	if (__osTimerList->next != __osTimerList) {
		while (TRUE) {
			t = __osTimerList->next;
			if (t == __osTimerList) {
				__osSetCompare(0);
				__osTimerCounter = 0;
				break;
			}
			
			count = osGetCount();
			elapsed_cycles = count - __osTimerCounter;
			__osTimerCounter = count;

			if (elapsed_cycles < t->value)
			{
				t->value -= elapsed_cycles;
				__osSetTimerIntr(t->value);
				break;
			} else {
				t->prev->next = t->next;
				t->next->prev = t->prev;
				t->next = NULL;
				t->prev = NULL;
				
				if (t->mq != NULL) {
					osSendMesg(t->mq, t->msg, OS_MESG_NOBLOCK);
				}

				if (t->interval != 0) {
					t->value = t->interval;
					__osInsertTimer(t);
				}
			}
		}
	}
}

void __osSetTimerIntr(OSTime tim) {
	OSTime NewTime;
	u32 savedMask;

	savedMask = __osDisableInt();
	__osTimerCounter = osGetCount();
	NewTime = __osTimerCounter + tim;
	__osSetCompare(NewTime);
	__osRestoreInt(savedMask);
}

OSTime __osInsertTimer(OSTimer* timer) {
    OSTimer* nextTimer;
    u64 timerValue;
    u32 prevInt = __osDisableInt();

    for (nextTimer = __osTimerList->next, timerValue = timer->value;
         nextTimer != __osTimerList && timerValue > nextTimer->value;
         timerValue -= nextTimer->value, nextTimer = nextTimer->next) {
        ;
    }

    timer->value = timerValue;
    if (nextTimer != __osTimerList) {
        nextTimer->value -= timerValue;
    }

    timer->next = nextTimer;
    timer->prev = nextTimer->prev;
    nextTimer->prev->next = timer;
    nextTimer->prev = timer;
    __osRestoreInt(prevInt);

    return timerValue;
}
