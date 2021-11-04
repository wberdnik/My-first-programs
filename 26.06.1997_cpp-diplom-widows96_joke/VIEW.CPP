#include"view.hpp"
#include"slave.h"
#include"proto.hpp"
#pragma hdrstop

extern "C" int bioskey(int);

 View::View(int a,int b,int c,int d,word icomand,\
			word inhelp,char* ih,word ikb):
	Leaf(),Control2(){
	operator()(a,b,c,d);
	comand= icomand;		// Вызываемая команда
	nhelp = inhelp;                 // Контекст подсказка
	kbhot = ikb;                    // горячая клавиша
	hline = ih;                     // подсказка внизу
			 }


int View::filter(void){
if( status!=stNo && (Ev.flag!=eSys || Ev.press==cmWait))
newtext=hline;
switch(Ev.flag){
	case eKeyboard : if(Ev.press==kbHelp)
			 {/*Help(nhelp)*/;Ev.clear();return No;}
			 break;
	case eMouse    : return Body();
	      }
return Yes;               }

int View::handlevent(void){
int k;
if(filter()){
  if((k=preprocess())!=0)return k;
  if((Ev.flag==eMouse && Ev.press==1)||\
  (kbhot>255  &&  Ev.flag==eKeyboard && Ev.press==kbhot)||\
(kbhot<256 &&(Ev.press&0xff)==kbhot &&Ev.flag==eKeyboard &&bioskey(2)==0x04)||\
  (Ev.press==kbEnter && Ev.flag==eKeyboard && status==stSelect))
     return setcomand();
  return ((Ev.flag!=eSys && Body())||\
	     (Ev.flag==eKeyboard && Ev.press==kbhot))?stSelect:0;
	     }
return 0;
}

int View::setcomand(void){
Ev.setevent(comand);return stSelect;}

int View::preprocess(void){return 0;}
int View::Body(void){return(Ev.x>x && Ev.x<x+w && Ev.y>y && Ev.y<y+h);};
void View::draft(void){
if(status)select(stDraft);else unselect(stDraft);};