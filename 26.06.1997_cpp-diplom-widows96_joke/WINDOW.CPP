#include"window.hpp"
#include<graphics.h>
#define GRAPHICSH
#include"error.hpp"
#include"slave.h"
#pragma hdrstop

Window::Window(int a, int b,int c,int d,word col)
   :Object(a,b,col),Control2(){ operator()(a,b,c,d); }

void Window::store(void){
 size=imagesize(x,y,x+w,y+h);
 if(signed (size)==-1)error("Window::размеры");
 mas=new byte[size];
 getimage(x,y,x+w,y+h,mas);
			}
void Window::restore(void){
   putimage(x,y,mas,COPY_PUT);
   delete mas;
			  }

void Window::plot(void){
//setfillstyle(SOLID_FILL,color);
//bar(x,y,x+w,y+h);
			  }

