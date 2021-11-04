#include"simple.hpp"
#include"slave.h"
#include<stdio.h>
#pragma hdrstop

extern "C"{
	  unsigned strlen(const char *s);
	  unsigned long farcoreleft(void);
	  char *ltoa(long, char *,int );
	  int bioskey(int);
	  };


void  Ramka::draft (void){
High::draft();
setfillstyle(SOLID_FILL,LIGHTGRAY);bar(x+1,y+1,x+w-2,y+h-2);
			 }

void  High::draft (void){
setcolor(mode?WHITE:DARKGRAY);
line(x,y,x+w,y);line(x,y,x,y+h);
setcolor(mode?DARKGRAY:WHITE);
line(x+w,y+h,x+w,y);line(x+w,y+h,x,y+h);
			 }

void Bar::draft(void){
if(mode==modeOnlyDialog || mode==modeGroup){
 dlx=drx=ddy=duy=0;dialogbox();return;}

setfillstyle(SOLID_FILL,color);
bar(x,y,x+w,y+h);
if(mode==modeSimple)return;
			   setcolor(colorramka);
			   line(x+2,y+3,x+w-2,y+3);
			   line(x+2,y+3,x+2,y+h-2);
			   line(x+w-2,y+h-2,x+w-2,y+3);
			   line(x+w-2,y+h-2,x+2,y+h-2);

			   line(x+4,y+5,x+w-4,y+5);
			   line(x+4,y+5,x+4,y+h-4);
			   line(x+w-4,y+h-4,x+w-4,y+5);
			   line(x+w-4,y+h-4,x+4,y+h-4);
if(mode==modeBox)return;

			    char len=strlen(name);
			    bar(x+w/2-(len*4)-16,y+1,x+w/2+(len*4)+16,y+5);
			    outtextxy(x+w/2-(len*4),y+1,name);
if(mode==modeNameBox)return;
			    dialogbox();
if(mode==modeDialog)return;

	    }

void Bar::dialogbox(void){
	    setfillstyle(SOLID_FILL,colordialog);
	    bar(x+dlx,y+duy,x+w-drx,y+h-ddy);
	    setcolor(DARKGRAY);
	    line(x+dlx,y+duy,x+dlx,y+h-ddy);
	    line(x+dlx,y+duy,x+w-drx,y+duy);
	    setcolor(WHITE);
	    line(x+w-drx,y+h-ddy,x+dlx,y+h-ddy);
	    line(x+w-drx,y+h-ddy,x+w-drx,y+duy);
			     }
Bar::Bar(int a,int b,int c,int d,char *name,char ibox):Draft(),Control2(){
operator()(a,b,c,d);
set(modeNameBox,name);  dlx=drx=duy=ddy=6; //║ - 6 lines
colordialog=color=ibox;
colorramka=WHITE;
};

Bar::Bar(int a,int b,int c,int d,char icolor):Draft(),Control2(){
	operator()(a,b,c,d);
	mode=modeSimple;
	duy=ddy=drx=dlx=0;
	colordialog=color=icolor;};

void Bar::set(char imode,char *iname,char icolorramka,char icolordialog){
mode=imode;name=iname;colorramka=icolorramka;
colordialog=icolordialog;
			};

void Desktop::draft(void){
int sx=25,sy=25;
for(int i=(sizeX%sx)/2;i<sizeX;i+=sx)
  for(int j=sy;j<sizeY-sizeDy;j+=sy)
       putpixel(i,j,CYAN);
			}


Wait::Wait(char a):Window(sizeX-25,sizeY-60,15,40,LIGHTBLUE),
			n1(x+w/2,y+h/2+6,color),
			n2(x+w/2,y+h/2+2,color),
			n3(x+w/2,y+h-7,  color)
{                       box=LIGHTGRAY;
			  ++(*this);
a++;
   gettime(&start);
			  }


void Wait::plot(void){
	      setfillstyle(SOLID_FILL,BLACK);
	      bar(x,y,x+w,y+h);

	      setcolor(box);
	      line(x+1,y+4,x+w/2-4,y+h/2-4);
	      line(x+w/2-4,y+h/2-4,w/2+x+4,h/2+y+4);
	      line(w/2+x+4,h/2+y+4,x+w,y+h);

	      line(x+w-1,y+4,x+w/2+4,y+h/2-4);
	      line(x+w/2+4,y+h/2-4,x+w/2-4,h/2+y+4);
	      line(x+w/2-4,h/2+y+4,x,y+h);

	      setfillstyle(SOLID_FILL,box);
	      bar(x,y,w+x,y+3);
	      bar(x,y+h-3,x+w,y+h);

	      setfillstyle(SOLID_FILL,color);
	      bar(x+1,y+h-5,x+w-1,y+h-4);
	      putpixel(x+w/2,y+h/2-2,color);
	      putpixel(x+w/2,y+h/2-1,color);
	      ++n1;
	      bar(x+w/2-2,y+h/2-4,x+w/2+2,y+h/2-3);
	      bar(x+w/2-3,y+h/2-6,x+w/2+3,y+h/2-5);
	       flag=1;
		     };

void ESCbreak(void);

void Wait::tik(char kk){
// if(bioskey(1)==kbESC){bioskey(0);ESCbreak();}
switch(flag){
   case 1:   --n1;  ++n3;
	     flag=2;return;
   case 2:   --n3;  ++n2;
	    flag=3;return;
   case 3:   --n2;  ++n1; flag=1;

  setcolor(RED);
     gettime(&watch);


    watch.ti_hour-=start.ti_hour;
    watch.ti_min-=start.ti_min;
    watch.ti_sec-=start.ti_sec;

    if(watch.ti_sec>60){watch.ti_sec+=60;watch.ti_min-=1;}
    if(watch.ti_min>60){watch.ti_min+=60;watch.ti_hour-=1;}
    if(watch.ti_hour>24) watch.ti_min+=24;

     sprintf(a,"Время %2d:%02d:%02d Готово:%2u%%",\
     watch.ti_hour,watch.ti_min,watch.ti_sec,kk);

     setfillstyle(SOLID_FILL,LIGHTGRAY);
     bar(350,sizeY-sizeDy,sizeX,sizeY);
     outtextxy(350,468,a);
     return;
	    }
		     }
