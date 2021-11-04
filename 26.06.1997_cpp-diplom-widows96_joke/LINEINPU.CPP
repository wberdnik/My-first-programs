#include<string.h>
#define STRINGH
#include"lineinpu.hpp"
#include"function.hpp"
#include"tkeys.h"
#pragma hdrstop

Lineinput& Lineinput::operator=(char* a){
strcpy(string,a);
lenght=strlen(a);
position=left=0;
if(lenght<lenscreen)position=lenght;
print();
return *this;
				    }

Lineinput::Lineinput(int a,int b,int c,int d,int com,char* s,\
char co,char colch,char* hlin):
View(a,b,c,d,com,0,hlin)                    {
if(b>sizeY-sizeDy){y=b;h=d;}
colorscreen=co;
colorchar=colch;
strcpy(string,s);
lenght=strlen(s);
position=left=0;
if(lenght<lenscreen)position=lenght;
lenscreen=c/8-1;
						}

void Lineinput::print(void){
char b[2];b[1]=0;int j;
setfillstyle(SOLID_FILL,colorscreen);bar(x+1,y+1,x+w-1,y+h-1);
for(int i=0;i<lenscreen;i++){
 j=i+left;if(j>=lenght)break;
 b[0]=string[j];
 setcolor(colorchar);outtextxy(xx(i),y+(h-8)/2,b);
			    }
 printchar(LIGHTRED);

			    }

void Lineinput::printchar(char a){
char b[2];b[1]=0;b[0]=string[position+left];
 setfillstyle(SOLID_FILL,a);
 bar(xx(position)+1,y+2,xx(position+1)-1,y+h-2);
 if(position+left<lenght){
 setcolor(colorchar);outtextxy(x+2+8*position,y+(h-8)/2,b);
		    }
				   }
int Lineinput::preprocess(void){
if(status!=stSelect || Ev.flag!=eKeyboard)return 0;
int i;
switch(Ev.press){
   case kbEnter     : string[lenght]=0;
   case kbF6:
   case kbTab	    :
   case kbShiftTab  : Ev.flag=eKeyboard;return 0;
		}


switch(Ev.teg.ch){
      case '\b':       // kbTab
		  if(position+left==0)return stSelect;
		    if(position)position--;
		    else if(left>lenscreen/2){
			 position=lenscreen/2;
			 left-=lenscreen/2;}
			 else {left=0;position=lenscreen/2;}
		     Ev.teg.sk=scDel;

      case 0   :  switch(Ev.teg.sk){
		    case scDel   :
				if(lenght==0 || position+left>=lenght)
				     return 1;
				  for(i=position+left+1;i<lenght;i++)
				   string[i-1]=string[i];
				  lenght--;
				   break;
		    case scLeft  :
				  if(position)position--;
				  else {if(!left)return 1;
					if(left>lenscreen/2){
					position=lenscreen/2;
					left-=lenscreen/2;}
					else left=position=0;
				       }
				  break;
		    case scRight :
				  if(position+left>=lenght)return 1;
				  if(position<lenscreen)position++;
				   else if(position+left<lenght-lenscreen/2){
					position=lenscreen/2;
					left+=lenscreen/2;                  }
					else {position=lenght%2;
					     left=lenght-position;
					     }
				  break;
		    case scHome  : position=left=0;
				   break;
		    case scEnd   : position=lenght%lenscreen;
				   left=lenght-position;
				   }
				 break;

      default:
		 // проверяем переполнение
		if(lenght>=254){lenght=254;position=254-left;
				return stSelect;
			       }
		//  если не в конце строки
		   if(position+left<lenght)
		      // то сдвигаем вправо
			  for(i=position+left;i<lenght;i++)
			   string[i+1]=string[i];
		 // фиксируем символ
		   string[position+left]=Ev.teg.ch;  position++;
			 //  наращиваем размер строки
		  if(position+left>lenght) lenght=position+left;
			 //  проверяем сдвиг экрана вправо
		  if(position>=lenscreen){
		    position-=lenscreen/2;
		    left+=lenscreen/2;
			 }
		}
print();
return stSelect;
		     }

void Lineinput::select(int a){
status=stSelect;
if(a==stDraft){
 setfillstyle(SOLID_FILL,colorscreen);bar(x,y,x+w,y+h);
print();
	       }
 setcolor(DARKGRAY); line(x,y,x,y+h); line(x,y,x+w,y);
 setcolor(WHITE); line(x+w,y+h,x,y+h);line(x+w,y+h,x+w,y);
			       }

void Lineinput::unselect(int a){
string[lenght]=0;
status=stNo;
if(a==stDraft){
 setfillstyle(SOLID_FILL,colorscreen);bar(x,y,x+w,y+h);
print();
	       }
 setcolor(LIGHTGRAY);
 line(x,y,x,y+h); line(x,y,x+w,y);
 line(x+w,y+h,x,y+h);line(x+w,y+h,x+w,y);
			       }
