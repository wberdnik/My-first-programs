#ifndef ERROR

#define MESSAGE     1   //
#define DIALOG      2
#define WARNING     3
#define ERROR       4
//#define FATALERROR  5   // �⠫쭠�
#define ERRORFILE   6   //�訡�� DOS
#define USERS       7

class Error{
unsigned *mas;
public:
Error();
int operator()(int,char*,char*);
void operator()(char*);
~Error();
	   };

extern Error error;
#endif