#ifndef RAMKA
#define RAMKA
#ifndef  OXY
#include "oxy.hpp"
#endif

#ifndef  CONTROL
#include "control.hpp"
#endif

class Ramka:public Draft,Control2{
public:
char mode;
	Ramka(int a,int b,int c,int d,char imode=Yes):Control2(a,b,c,d){
						mode=imode;};
	void draft     (void) ;
		       };

class Bar:public Draft,virtual public Control2{
protected:
char mode;
char color;
char colorramka;
char colordialog;
char *name;
	void dialogbox(void);
public:
	int duy,ddy,dlx,drx;
	Bar(int a,int b,int c,int d,char icolor):
	Draft(),
	Control2(a,b,c,d){
		mode=0;
		duy=ddy=drx=dlx=16;
		color=icolor;};

	 void draft     (void) ;

	 void set	(char a){
			  colorramka=a;mode=modeBox;};// Цвет рамки
	 void set	(char a,char* b){   	// имя рамки
			  colorramka=a;name=b;mode=modeNameBox;};
	 void set	(char a,char b,char* c){// цвет Box
			  set(a,c);colorramka=b;mode=modeDialog;};
	 void set	(int a,int b,int c,int d){
			  dlx=a;drx=b;duy=c;ddy=d;};
		       };


#endif