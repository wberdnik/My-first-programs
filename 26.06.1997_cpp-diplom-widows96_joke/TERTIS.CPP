#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include"tetris.hpp"
#include"tkeys.h"
#include<bios.h>
#include<dos.h>
#pragma hdrstop

char * tetmas;
char weight;
char deep;

int Tetris::go(void){
figure->set();
while(1){
build();
figure->reset();
y++;
if(!(*figure)(x,y).test()){
    (*figure)(x,y-1).set();
    delete figure;
    figure=getfig();
    x=weight/2-2;
    y=0;
     teststat();
    if(!(*figure)(x,y).test()){
     delete figure;
	   return gYes;            }
			   }

if(movefig()){delete figure;return gNo;};
delay(200);
figure->set();

		}
		       }

int Tetris::movefig(void){
while(bioskey(1))
    switch(bioskey(0)){
     case kbEsc        : return gYes;
     case  kbLeft 	: (*figure)(x-1,y);
			  if(!figure->test()){
			    (*figure)(x,y);   }
			   else  x--;
					   break;

     case  kbRight	: (*figure)(x+1,y);
			  if(!figure->test()){
			    (*figure)(x,y);   }
			   else   x++;	   break;

     case  kbDown	:  y+=3;
			   while(!(*figure)(x,y+1).test()){y--;};
			   (*figure)(x,y+1);
			   break;


     case  kbUp		: if(figure->others(gYes)==figNo)break;
			  Fig* tmp=convert(figure->others(gYes));
			  if((*tmp)(x,y).test()){
			     delete figure;
			     figure=tmp;        }
			   else delete tmp;
			  break;
		      }
return gNo;
			  }


Tetris::Tetris(char a,char b){
   ::weight=b;
   ::deep=a;
   tetmas=A=new char[a*b]; B=new char[a*b];
   for(int i=0;i<a*b;i++){A[i]=figNo;B[i]=3;}
   y=0;
   x=weight/2-2;
   figure=getfig();
   randomize();
			      }


void Tetris::teststat(void){
char a;
int i,j,k,l;
 for(i=0;i<deep;i++){
   a=A[i*weight];
  if(a!=figNo)
   for(j=0;j<weight;j++)
     if(A[i*weight+j]==figNo)
      j=weight;
     else
      if(j==weight-1){
	for(k=i;k>=0;k--)   //колодец падает
	 for(l=0;l<weight;l++)
	   if(k+1<deep) A[(k+1)*weight+l]=A[k*weight+l];
			}
		       }

		}


Fig* Tetris::convert(char a){
 switch(a){

  case	figTwo		: return new Two();
  case	figThree	: return new Three();
  case	figFour		: return new Four();


  case	figUpTwo	: return new UpTwo();
  case	figUpThree	: return new UpThree();
  case	figUpFour	: return new UpFour();


  case	figZ		: return new Z();
  case	figMZ		: return new MZ();
  case	figUpZ		: return new UpZ();
  case	figUpMZ		: return new UpMZ();


  case	figUpL		: return new UpL();
  case	figUpML		: return new UpML();
  case	figDnL		: return new DnL();
  case	figDnML		: return new DnML();
  case	figLtL		: return new LtL();
  case	figLtML		: return new LtML();
  case	figRtL		: return new RtL();
  case	figRtML		: return new RtML();


  case	figUpper	: return new Upper();
  case	figBlok		: return new Block();
  case 	figOne		: return new One();
  default 		: cprintf("No figure");
			  getch();
			 exit(33);
		       }
return NULL;
			 }

void Tetris::build(void){
char color;
for(int i=0;i<deep;i++)
 for(char j=0;j<weight;j++)
   if(A[i*weight+j]!=B[i*weight+j]){
      switch(A[i*weight+j]){
	 case figNo : color=DARKGRAY; break;
	 case figUpper: color=RED;break;
	 case figBlok : color=WHITE;break;
	 case figOne  : color=LIGHTGREEN;break;
	 case figZ    :
	 case figUpZ  :
	 case figMZ   :
	 case figUpMZ : color=YELLOW;break;
	 default : color=GREEN;
			    }
	 setfillstyle(SOLID_FILL,color);
	 bar(j*12+50,i*12+10,(j+1)*12+50,(i+1)*12+10);
	 B[i*weight+j]=A[i*weight+j];
				    }
			 }

