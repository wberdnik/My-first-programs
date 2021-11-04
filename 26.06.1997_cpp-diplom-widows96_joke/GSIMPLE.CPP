#include<math.h>
#include<stdlib.h>
#include<graphics.h>
#define GRAPHICSH
#define MATHH
#define STDLIBH

#include"gsimple.hpp"
#include"diagnost.hpp"
#include"error.hpp"
#pragma hdrstop

int Circle::test(int a,int b){
float alfa=acos((double)2.0*(a-x)/w-1);
int c=y+(h/2)*(1+sin(alfa));
int d=y+(h/2)*(1+sin(-alfa));
return ((b>c && b<d) || (b<c && b>d));
			}

void Circle::running(BaseMath& z,int b){
static   double s,alfa;
static   double R,r;
		    // первую
      alfa=(double)6.2832*rand()/RAND_MAX;
      s=double(z.too.mashtx/2)*cos(alfa);
      r=double(z.too.mashty/2)*sin(alfa);
      R=sqrt(s*s+r*r);
		    // вторую
      do{ s=0;
	  for(int j=0;j<15;j++)   s+=(float)rand()/RAND_MAX;
	  s-=7.5;
	  r=s*R*z.there;
	}while(r>R || r<0);

      // Найдем точки
    z.c[b]=float(z.too.mashtx/2*(1+(r/R)*cos(alfa)));
    z.d[b]=float(z.too.mashty/2*(1+(r/R)*sin(alfa)));

		     }


void Circle::draft(void){
float cosi,sini,con=y+h/2,con2=x+w/2;
float thecon=8*3.1415926/(w+h);
float wl=w/2,hl=h/2;
float oldcosi=wl,oldsini=0;
 setcolor(color);
   for(float i=0;i<thecon*((w+h)/16+2);i+=thecon){
    cosi=cos(i)*wl;sini=sin(i)*hl;
    line(con2+oldcosi,con+oldsini,con2+cosi,con+sini);
    line(con2+oldcosi,con-oldsini,con2+cosi,con-sini);
    line(con2-oldcosi,con+oldsini,con2-cosi,con+sini);
    line(con2-oldcosi,con-oldsini,con2-cosi,con-sini);
     oldcosi=cosi;oldsini=sini;
			   }
			 }

void Rectangle::draft(void){
 setcolor(color);
  rectangle(x,y,x+w,y+h);   }


void Rectangle::running(BaseMath& a ,int b){
    a.c[b]=a.too.mashtx*rand()/RAND_MAX;
    a.d[b]=a.too.mashty*rand()/RAND_MAX;
				   }

int Rectangle::test(int a,int b){
return (a<x+w && b<y+h && a>x && b>y);}

void Worknet::draft(void){
int i,j;
 switch(KNOW.stepweb){
  case cmNo : return;
  case cmPoint: for(i=0;i<21;i++)
		  for(j=0;j<16;j++)
		    putpixel(i*sizeX/20,(14-j)*(sizeY-sizeDy)/15,\
		     KNOW.colorweb);
		 break;
  case cmLine:setcolor(KNOW.colorweb);
      for(i=0;i<21;i++) line(i*sizeX/20,0,i*sizeX/20,sizeY-sizeDy);
       for(i=0;i<16;i++)
	  line(0,(14-i)*(sizeY-sizeDy)/15,sizeX,(14-i)*(sizeY-sizeDy)/15);
		 break;
  default	: error("Gsimple::неизвестное webset");
			  }

			 }


