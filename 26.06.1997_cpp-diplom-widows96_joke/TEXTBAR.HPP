#ifndef TEXTBAR
#define TEXTBAR

#ifndef  SIMPLE
#include "simple.hpp"
#endif

#ifndef  VIEW
#include "view.hpp"
#endif

#ifndef SLAVE
#include "slave.h"
#endif

#ifndef  SETJMP
#define  SETJMP
#include <setjmp.h>
#endif

extern "C"  int getch(void);

class TextBar:public Bar{
char   ctext;     // color of text
char   cinput;     // color of input text

char   starty;
char   startx;

static char string[256];
char tx,ty;

      word  xx(byte a);
      word  yy(byte a);
      void decc(void);
      void print(char*,char);
      virtual void input();

protected:
      virtual char gtchar(void){return getch();};
      char tdx,tdy;

public:

       TextBar& operator<<(char *a);
       TextBar& operator<<(char a);
       TextBar& operator<<(int a);
       TextBar& operator<<(unsigned long a);
       TextBar& operator<<(float a);
       TextBar& operator<<(double);

       TextBar& operator>>(char&);
       TextBar& operator>>(char*);
       TextBar& operator>>(int&);
       TextBar& operator>>(float&);

       TextBar& operator!(void){dialogbox();return *this;};
       TextBar& operator()(int a,int b){tx=a;ty=b;return *this;};
       TextBar& operator()(char a){ctext=a;return *this;};

       TextBar(int a,int b,int c,int d,char * name,char ibox=LIGHTGRAY,\
		char iinput=WHITE,char itext=YELLOW,char iramka=WHITE);


	void merror(void);
			};// end of TextBar


class GroupBar:public TextBar,public View{
private:
// borned:
	virtual char gtchar(void);
	     // программирование обьекта
	void myne(void);
 char flagstart;
  char sk,ch;
 void (far* program)(GroupBar&,char);

jmp_buf jgetch;
int skan[3];      // for connect for bc4.0  library
jmp_buf jwork;
int skano[3];

//interupt:
	int setcomand(void);	// Обработка сообщения
	int preprocess(void);
public:
       GroupBar(int a,int b,int c,int d,int com,word nhelp,char * name,\
       void (far* k)(GroupBar&,char),char ibox=CYAN,\
       char iinput=WHITE,char itext=YELLOW,char iramka=WHITE);
//borned:

	 void unselect(int);    // сделать невыделенным обьектом
	 void select(int);
	 void draft(void);
	 unsigned forprogram;  // номер breakPoint

			       };
#endif


