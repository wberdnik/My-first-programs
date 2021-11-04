#include"desktop.hpp"
#include"tkeys.h"
#include"diagnost.hpp"
#include"proto.hpp"
#include<stdio.h>
#include"error.hpp"
#include"function.hpp"
#pragma hdrstop

extern"C" {
	  void sound(unsigned);
	  void nosound(void);
	  void delay(unsigned);
	  char *strcat(char *dest, const char *src);
	  }
char* desktopline;

DeskTop::DeskTop(char imode,BaseMath& b)\
	:View(0,0,sizeX,sizeY-sizeDy),math(b){
mode=imode;
c[0]=c[1]=c[2]=0;
isSorted=Yes;
int i;
if(math.n>100){
  for(i=1;i<math.n;i++)
   if(b.ci[i]<b.ci[i-1]){
      isSorted=No;break;};
	      }
else isSorted=No;
if(isSorted){
  dta=math.n/50;
  for(i=0;i<50;i++)
   masfind[i]=b.ci[i*dta];
	    }
}

int DeskTop::preprocess(void){
int acomand=cmNo;
int i;
 switch(Ev.flag){
  case eKeyboard : switch(Ev.teg.ch){
		   case 0x0d : case ' ' : acomand=cmOk;break;
	   default :
	     switch(Ev.press){
		   case kbEsc   :  Ev.clear();return stSelect;
		   case kbLeft  : case kbRight :  case kbUp    :
		   case kbHome  : case kbPgUp  :  case kbPgDn  :
		   case kbEnd   : case kbDown  : acomand=cmGo;
				  }
			      }
			   break;
   case eMouse :  acomand=Ev.press?cmOk:cmGo;break;

   case eSys   : switch(Ev.press){
		  case cmOpros :  Ev.setevent(comand);  return stDelete;
		  case cmWait  :
		  if(hline==c && KNOW.curtime)        {
		  moveuser();LinePrint(c);hline+=1;}
				thewait();           return stDelete;
	  case cmEndWork : hline="Операция завершена";return stSelect;
	  case cmLineDeskTop: hline=desktopline;
			      LinePrint(hline);Ev.clear();
				 return stDelete;
		  case cmLoad    : isSorted=No;
				   if(math.n<=100) return stSelect;
				   isSorted=Yes;
				    for(i=1;i<math.n;i++)
				     if(math.ci[i]<math.ci[i-1]){
				      isSorted=No;break;};

				     if(isSorted){
				       dta=math.n/50;
				      for(i=0;i<50;i++)
					masfind[i]=math.ci[i*dta];
				       math.too.number=math.n;
				   }
						      return stSelect;

				     }
		 }
if(acomand==cmOk) {
		    if(math.border->test(Ev.x,Ev.y)) Ev.setevent(cmPoint);
		    else {hline="А где границы ???";
		    LinePrint(hline);}
		    return stSelect;}
if(acomand==cmGo){hline=c;if(!KNOW.curtime)moveuser();}
    return stDelete;
				   };

void DeskTop::moveuser(void){
char b[80];
int i=0;
Ev.setevent(cmShowLine);
c[0]=0;
switch(KNOW.modecoo){
	case rasCooPixel : sprintf(c," Пиксел X: %d Y: %d  ",Ev.x,Ev.y); break;
	case rasCooReal  :
			  sprintf(c," Карта X :%.2f Y: %.2f  ",\
			  math.too.mashtx*Ev.x/sizeX,\
			  math.too.mashty*Ev.y/(sizeY-sizeDy));

		     }
b[0]=0;

math.tr3=-1;
    i=isSorted?fast(Ev.x,Ev.y):simple(Ev.x,Ev.y);
    if(i!=math.n){
	if(KNOW.sound)sound(3000);
	sprintf(b,"Найдена точка n: %d ",i);
	 math.tr3=i;
       if(KNOW.sound){delay(10);nosound();}
	 }
//   if(isSorted)
//    if(simple(Ev.x,Ev.y)!=fast(Ev.x,Ev.y)){
//     simple(Ev.x,Ev.y);
//     fast(Ev.x,Ev.y);
//    error(FATALERROR,"","Point ambigious find");     }

  strcat(c,b);
  math.tr1=Ev.x;math.tr2=Ev.y;
  newtext=c;
  hline=c;
}
void DeskTop::thewait(void){

}
DeskTop::~DeskTop(){};


int DeskTop::simple(int x,int y){
 for(int i=0;i<math.n;i++)
  if(x==math.ci[i])
   if(y==math.di[i])
    return i;
return math.n;                 }


int DeskTop::fast(int x,int y){
int i,j;
 for(i=math.too.number;i<math.n;i++) //Поиск по добавленным
       if(x==math.ci[i])
	if(y==math.di[i]) return i;

 if(x>=masfind[49]){                 //  Поиск по шапке
     for(i=math.too.number-1;(math.ci[i]>=x || math.ci[i]==-1) && i>0;i--)
      if(x==math.ci[i])
	if(y==math.di[i]) return i;
		  }
else{
  i=x>masfind[23]?22:1;
  for(;i<50;i++)
   if(x<=masfind[i]){
    if(x>masfind[i])return math.tr3;
	for(j=(i-1)*dta;j<(i*dta+1) &&j<math.too.number;j++)
	  if(x==math.ci[j])
	     if(y==math.di[j])
	       return j;
		    }
      }
 return math.n;
			  }



void DeskTop::unselect(int a)
{status=stNo;if(a==stDraft)show();};
void DeskTop::select(int a)
{status=stSelect;if(a==stDraft)show();};



