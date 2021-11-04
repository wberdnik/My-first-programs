#include <bios.h>
#include<dos.h>
#include<graphics.h>
#include <conio.h>
#include <string.h>
#define  CONIOH
#define GRAPHICSH
#define BIOSH
#define DOSH
#include"event.hpp"
#include"error.hpp"
#include"diagnost.hpp"
#include"function.hpp"
#include"tkeys.h"
#pragma hdrstop
void Event::rolikerror(char* a){
beep();
setuser();
LinePrint(a);
getch();                }

enum{
	evNo,
	evUser,
	evSave,
	evLoad,
     };
char* nameswp="netcad.cin";


void Event::setsave(void){
if(mode!=evUser || swap)setuser();
unlink(nameswp);
swap=fopen(nameswp,"wb+");
if(!swap){
rolikerror("Rolik:не могу создать");
return;   }
rewind(swap);
zag.x=x;
zag.y=y;
strcpy(zag.ident,"AAAA");
zag.nsoob=0;
fseek(swap,0,SEEK_SET);fwrite(&zag,sizeof(zag),1,swap);
mode=evSave;
nsoob=0;
!tik;
};

void Event::setload(void){
if(mode!=evUser || swap)setuser();
swap=fopen(nameswp,"rb");
if(!swap){
rolikerror("Rolik:нет файла");
return;   }
rewind(swap);
fread(&zag,sizeof(zag),1,swap);
if(strncmp(zag.ident,"AAAA",4) || zag.nsoob>1000000L){
fclose(swap);
beep();
swap=NULL;
LineYesNo("ошибка идентификатора Rolik");
return;
			       }
set(zag.x,zag.y);
mode=evLoad;
!rolik;
nsoob=0;
};

void Event::setuser(void){
if(mode==evUser)return;
switch(mode){
case evSave:
		strcpy(zag.ident,"AAAA");
		zag.nsoob=nsoob;
		fseek(swap,0,SEEK_SET);
		fwrite(&zag,sizeof(zag),1,swap);

case evLoad:fclose(swap);swap=NULL;
}
mode=evUser;
};



void Event::get(void){
static char forwait=No;
switch(mode){
case evUser: getuser(); return;
case evSave : getuser();
	      if(flag==eSys)return;

	      zap.x=x;
	      zap.y=y;
	      zap.flag=flag;
	      zap.press=press;
	      zap.ident='A';
	      !rolik;
	      zap.where=rolik-tik;
	      if(!fwrite(&zap,sizeof(zap),1,swap)){
	      rolikerror("Rolik:: нельзя писать");
	      return;                          }

	      !tik;
	      nsoob++;
	      return;

case evLoad:  if(nsys){getuser();return;}
		operator++();

	      if(zag.nsoob<=nsoob){
	      beep();
	      setuser();
	      LinePrint("Rolik закончен");
	      return;             }
      if(forwait==No)
	      if(!fread(&zap,sizeof(zap),1,swap)){
	      rolikerror("Нельзя читать");
	      return;                           }

	      if(zap.ident!='A'){
	      rolikerror("не опознано событие Rolik");
	      return;
				}
	      if(bioskey(1)){
	      rolikerror("Управление передано пользователю.");
	      return;        }
	      showline();

	      while(1){
		if((!tik)-rolik>zap.where)break;

		if(tik.one.ti_sec>0){
			     forwait=Yes;
			     zap.where-tik;
			     !rolik;
			     flag=eSys;press=cmWait;
			     return;}

		      }
	     forwait=No;
	      flag=zap.flag;
	      press=zap.press;
	      if(flag==eKeyboard)
			     buf=press;
	      !rolik;
	      operator--();
	      set(zap.x,zap.y);
	       nsoob++;
	      return;
	    }

}


Kursor::Kursor(int a,int b):Control(a,b),
  lx1(x,y-1,x,y-10,WHITE),
  ly1(x-1,y,x-10,y,WHITE),
  lx2(x,y+1,x,y+10,WHITE),
  ly2(x+1,y,x+10,y,WHITE) {}

void Kursor::hmove(int a, int d){
  (*this)(a,d);
  lx1.hmove(x,y-1);
  ly1.hmove(x-1,y);
  lx2.hmove(x,y+1);
  ly2.hmove(x+1,y);
  }
void Kursor::operator++(void){
 ++lx1;++lx2;++ly1;++ly2;}

void Kursor::operator--(void){
 --lx1;--lx2;--ly1;--ly2;}


Mouse::Mouse(int a,int b){
		 status();
		 if(!READY)return;
		 screen_size(0,0,sizeX,sizeY);
		 set(a,b);
		 inr.x.ax=2;//погасим мышку
		 int86(0x33,&inr,&outr);
		   };


 //**********************************************************************

void Mouse::status(void) {
   inr.x.ax=0;
   int86(0x33,&inr,&outr);
   READY=(signed int)outr.x.ax==-1 ? Yes:No;
  }

void Mouse::screen_size(int x_min,int y_min, int x_max, int y_max)
   {

     inr.x.ax=7;
     inr.x.cx=x_min;
     inr.x.dx=x_max;
     int86(0x33,&inr,&outr);

     inr.x.ax=8;
     inr.x.cx=y_min;
     inr.x.dx=y_max;
     int86(0x33,&inr,&outr);
    }


int Keyboard::event(int& x,int& y){
 if(bioskey(1)==0)return kbNoKey;
   static int dec=9;
   buf=bioskey(0);
      switch(buf)
       {
	case kbPgUp     : x+=dec;           //rigt
	case kbUp	: y-=dec; break;
	case kbHome	: y-=dec;           //up
	case kbLeft	: x-=dec; break;
	case kbPgDn     : y+=dec;           //down
	case kbRight    : x+=dec; break;
	case kbEnd      : x-=dec;           //left
	case kbDown     : y+=dec; break;
	case kbPlus     :if(dec<80) dec+= dec<2 ? 1 : dec   ;break;
	case kbMinus    :if(dec> 1) dec-= dec<2 ? 1 : dec/2 ;break;
       }
      if(!(dec%10))dec--;if(dec==0)dec=1;
    return buf;
}


char* newtext;

void Event::getuser(void){
static int ix,iy,key,mus; // меньше времени
static long i;
iy=y;ix=x;

if(nsys){ 			// сначала разгрузим системные сообщения

  flag=eSys; press=sysev[0];
  for(int i=0;i<nsys-1;i++)sysev[i]=sysev[i+1];
  nsys--;

  switch(press){
  case cmWait : newtext=" Нажмите любую клавишу или кнопку мыши";
		showline();
	   operator++();
	   press=No;
	   while(1){
	    if(mouse->READY) press=mouse->event(ix,iy);
		  key=Keyboard::event(ix,iy);
		  if(press!=mus)mus=0;

		  if(ix!=x||iy!=y){flag=0;operator--();
				   x=ix;y=iy;
				   set(ix,iy);operator++();}
		   else
		     if(key || (press && press!=mus)){
		     operator--();get();return;}
		      }
   case cmLine :    newtext="";
   case cmShowLine: textforprint=newtext+1;
    default:        showline();
		    return;
		    }
  };

  showline();
operator++();
i=KNOW.speedcpu;
press=No;
do{
  if(mouse->READY)press=mouse->event(ix,iy);
	   key=Keyboard::event(ix,iy);
	   if(press!=mus)mus=0;
	   if(!(i--)){
		      i=KNOW.speedcpu;
		      (!wrema)-rolik;
		      if(wrema.one.ti_sec>0){
		       !rolik;
		       flag=eSys;press=cmWait;
		       KNOW.speedcpu=i+100;
		       return;                      }
		     }
   }while(!key && ix==x && iy==y && (!press || press==mus));

 if(key){   flag=eKeyboard;
	    press=key;
	   }
  else {mus=press;flag=eMouse;}

x=ix; y=iy;
operator--();
set(ix,iy);
};


void Event::setevent(word a){
if(nsys+1>Deep)error("переполнение очереди сообщений");
sysev[nsys]=a;
nsys++;              };

void Event::setfirst(word a){
if(nsys+1>Deep)error("переполнение очереди сообщений");
for(char i=0;i<nsys;i++) sysev[i+1]=sysev[i];
sysev[0]=a;
nsys++;              };


void Event::set(int a,int b){
 if(mouse->READY&&flag!=eMouse)mouse->set(a,b);
 Kursor::hmove(a,b);
}
Event::Event():Kursor(320,240){
mode=evUser;swap=0;};

Event::~Event(){
delete mouse;delete sysev;
if(mode!=evUser)setuser();};


void Event::Run(void){
mouse= new Mouse(320,240);
clear();nsys=0;sysev=new word[Deep];
!wrema;rolik=wrema;
textforprint="";//Мы благодарим Вас за то,что Вы используете программу NetCad.";
};
void Event::showline(void){
if(newtext!=NULL){
 if(newtext==textforprint)return;
 textforprint=newtext;
		 }
 else newtext=textforprint;
 buildline();
			   }

void Event::buildline(void){
 if(y>=sizeY-sizeDy-10 && x>=56)operator--();
 setfillstyle(1,LIGHTGRAY); bar(46,sizeY-sizeDy,sizeX,sizeY);
 setcolor(RED);outtextxy(66,sizeY-11,textforprint);

			 }
Event Ev;

