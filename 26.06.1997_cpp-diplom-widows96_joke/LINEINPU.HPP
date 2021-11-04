#ifndef LINEINPUT
#define LINEINPUT

#ifndef  VIEW
#include "view.hpp"
#endif

#ifndef MODALS
#include "modals.hpp"
#endif


class Lineinput:public View{
char string[256];
char lenscreen;
char colorscreen;
char colorchar;

unsigned char position;
unsigned char lenght;
unsigned char left;

       void print(void);
       void printchar(char);

      int preprocess(void);

      word  xx(byte a){return 8*a+x+2;};

public:
	Lineinput(int a,int b,int c,int d,int,char* s,char co=LIGHTBLUE,\
	char colch=YELLOW,char* hline="");
	void select(int);
	void unselect(int);
	 operator char *(){return string;};
	 Lineinput& operator=(char*);
	~Lineinput(){string[lenght]=0;};
			   };
#endif