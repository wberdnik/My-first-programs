#ifndef FUNCTION
#define FUNCTION

#ifndef   TEXTBAR
#include "textbar.hpp"
#endif

#ifndef   EVENT
#include "event.hpp"
#endif


void Copyright(void);
int moin(TextBar&);
void Zap(void);
int yesno(char*);
void Message(char*);
void GetInfo(void);
void About(void);

int LineYesNo(char*);
void LinePrint(char*);
long LineInput(char*);
long MessageInput(char*);
void DeskTopPrint(char*);
void beep(void);

#endif