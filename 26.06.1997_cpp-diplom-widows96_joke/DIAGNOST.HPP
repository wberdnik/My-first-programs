#ifndef DIAGNOST
#define DIAGNOST

#ifndef DIRH
#define DIRH
#include <dir.h>
#endif

class Diagnost{
/*unsigned far * _mvideo;
unsigned screen[2000];*/

public:
//   arena || bazar

	char path[MAXPATH];
	char pathfile[MAXPATH];
	char filename[13];

	int disk;
	char processor;
unsigned long speedcpu;
	long diskfree;
unsigned long memfree;

	char stepweb;
	char colorweb;
	char modemath;
	char modecoo;
	char sound;
	char curtime;


	void test(void);
	void open(void);
	void close(void);
	~Diagnost();
};

extern Diagnost KNOW;

#endif