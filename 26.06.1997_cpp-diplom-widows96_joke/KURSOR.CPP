#include <conio.h>
#include <bios.h>
#define  CONIOH
#define  BIOSH
#include"event.hpp"
#include"tkeys.h"
#pragma hdrstop


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
