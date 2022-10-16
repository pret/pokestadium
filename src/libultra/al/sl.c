#include <libaudio.h>

extern ALGlobals* D_80079640;

void alUnlink(ALLink *ln)
{
	if (ln->next) {
		ln->next->prev = ln->prev;
	}

	if (ln->prev) {
		ln->prev->next = ln->next;
	}
}

void alLink(ALLink *ln, ALLink *to)
{
	ln->next = to->next;
	ln->prev = to;

	if (to->next) {
		to->next->prev = ln;
	}

	to->next = ln;
}

void alClose(ALGlobals* glob) {
    if (alGlobals != NULL) {
        alSynDelete(&glob->drvr);
        alGlobals = NULL;
    }
}

void alInit(ALGlobals* glob, ALSynConfig* c) {
    if (alGlobals == NULL) {
        alGlobals = glob;
        alSynNew(&glob->drvr, c);
    }
}
