#ifndef SIMPLE
#define SIMPLE

#ifndef  LEAF
#include "Leaf.hpp"
#endif

#ifndef DOSH
#define DOSH
#include <dos.h>
#endif


#ifndef  WINDOW
#include "window.hpp"
#endif


#ifndef  PIXEL
#include "pixel.hpp"
#endif

class Desktop:public Draft{
public:
	virtual void draft(void);       // построить обьект на экране
			};

class High:public Draft,public Control2{
char mode;
public:
       High(int a,int b,int c,int d,char imode=Yes):Control2(){
				   operator()(a,b,c,d);mode=imode;};
	void draft     (void) ;
		       };


class Ramka:public High{
public:
	Ramka(int a,int b,int c,int d,char imode=Yes):High(a,b,c,d,imode){};
	void draft     (void) ;
		       };

class Wait:public Window{
 struct time watch;
 struct time start;
  char a[80];
	void plot(void);
	 Pixel n1;
	 Pixel n2;
	 Pixel n3;
	 char flag;
	 char box;
 public:
	 Wait(char);
	 void tik(char);
	 ~Wait(){};
 };

class Bar:public Draft,virtual public Control2{
protected:
char mode;			// режим отображения
char color;                     // цвет фона for modeSimple
char colorramka;                // цвет обводки for modeBox
char colordialog;               // цвет встроеного окна
char *name;                     // имя рамки modeNameBox
	void dialogbox(void);
public:
	int duy,ddy,dlx,drx;

	Bar(int a,int b,int c,int d,char *name,char ibox=LIGHTGRAY);
	Bar(int a,int b,int c,int d,char icolor);
	void draft     (void);
	void set (char imode,char *iname,char icolorramka=WHITE,\
			char icolordialog=CYAN);
	void set (int a,int b,int c,int d){dlx=a;drx=b;duy=c;ddy=d;};
		       };

#endif