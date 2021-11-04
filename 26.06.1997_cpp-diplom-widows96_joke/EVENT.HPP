#ifndef EVENT
#define EVENT


#ifndef STDIOH
#define STDIOH
#include <stdio.h>
#endif


#ifndef SLAVE
#include "slave.h"
#endif

#ifndef TIME
#include "time.hpp"
#endif


#ifndef  LINE
#include "line.hpp"
#endif


#ifndef  CONTROL
#include "control.hpp"
#endif


class Kursor:public Control{
	Line lx1,ly1,lx2,ly2;
	int x1,y1;
	 public:
	  Kursor(int,int);
	  void hmove(int,int);
	  void operator++(void);
	  void operator--(void);
	 };

class Mouse{
      union REGS inr,outr;
      void status(void);
      void screen_size(int ,int y_min, int x_max, int);// размер экрана
public:
      int  READY;

    Mouse& set(int x,int y){
    if(READY){inr.x.ax=4;inr.x.cx=x;inr.x.dx=y;
    int86(0x33,&inr,&outr);
		       }
    return *this;
   }


     int event(int &x,int &y){
       inr.x.ax=3;  int86(0x33,&inr,&outr);
       x=outr.x.cx; y=outr.x.dx;
       return outr.x.bx;
			}

      Mouse(int,int);
	};

class Keyboard{
public:
union{
      unsigned buf;
      struct{
	     char ch;
	     char sk;
	     }teg;
      };
      int event(int&,int&);
			     };


extern char* newtext;

#define Deep	10

class Event:public Keyboard,public Kursor{
friend Group;
friend void LinePrint(char*);
struct {
	   char ident[5];
	   long nsoob;
	   int x;
	   int y;
	  } zag;
struct {
	  char ident;
	  int x;
	  int y;
	  char flag;
	  unsigned press;
	  Time where;
	} zap;

char mas[3];  // отладочный резерв


Time wrema;

long nsoob;

Mouse  * mouse;
	     // структура сообщения
	word*	sysev;
	byte nsys;
  char* textforprint;
  void showline();
  void buildline();
  void getuser(void);
  char mode;
  FILE * swap;
  Time tik;


public:
	Time rolik;
	 word press;        // сообщение
	 byte flag;	    // Тип события
	 Event();

	void Run(void);
	void clear(void){flag=No;}
	void setevent(word a);
	void setfirst(word a);
	void get(void);
	operator void *(){return flag?this:NULL;};
	void set(int,int);
	int event(int&,int&,int&);
	void operator++(void){Kursor::operator++();};
	void operator--(void){Kursor::operator--();};
	 ~Event();
	 void setsave(void);
	 void setuser(void);
	 void setload(void);
	 void rolikerror(char*);

	      };
extern Event Ev;
#endif





