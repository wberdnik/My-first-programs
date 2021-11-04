#include "line.hpp"
#include<math.h>
#include<graphics.h>
#pragma hdrstop

#define GX 1
#define GY 2

void Line::work(int a,int b){
  (*this)(a,b);too(a+bx,b+by);return; }

Line::Line(int xa, int ya,int xb,int yb,unsigned col)
   :Object(xa,ya,col),too(),x1(too.x),y1(too.y){
   len=0; mas=0L;too(xb,yb);
   bx=xb-xa;by=yb-ya;				}

void Line::store(void){
  dx=x1-x;dy=y1-y;
  int k=abs(dx); int f=abs(dy);
  flag=0;
  if(k>f && dx!=0){
	   flag=GX;
	   if(k!=len){
	   if(mas!=0L)delete mas;
	   mas=new char[k];len=k;
		     }
	      a=dy;a/=dx; xc=y;xc-=a*x;
	      if(x>x1){n=x1;n1=x;}else{n=x;n1=x1;};
	      for(int i=n;i<n1;i++)
		  mas[i-n]=(char)getpixel(i,(int)(a*i+xc));
		   }
     else
	if(dy!=0)
	 {  flag=GY;
	   if(f!=len){
	   if(mas!=0L)delete mas;
	    mas=new char[f]; len=f;
		     }
	 a=dx;a/=dy;xc=x;xc-=a*y;
	    if(y>y1){n=y1;n1=y;}else{n=y;n1=y1;};
	    for(int i=n;i<n1;i++)
	       mas[i-n]=(char)getpixel((int)(a*i+xc),i);};
};
void Line::restore(void){
   int i;
 if(flag==GX) for(i=n;i<n1;i++) putpixel(i,(int)(a*i+xc),(unsigned)mas[i-n]);
 if(flag==GY) for(i=n;i<n1;i++) putpixel((int)(a*i+xc),i,(unsigned)mas[i-n]);
 }
void Line::plot(void){
   int i;
  if(flag==GX) for(i=n;i<n1;i++)putpixel(i,(int)(a*i+xc),color);
  if(flag==GY) for(i=n;i<n1;i++)putpixel((int)(a*i+xc),i,color);
 }
Line::~Line(){
if(status)restore();if(mas!=0L)delete mas;};