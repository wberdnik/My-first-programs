#include <graphics.h>
#include <conio.h>
#include <dos.h>
#define  GRAPHICSH
#define  CONIOH
#define  DOSH
#include"button.hpp"
#pragma hdrstop

void Button::select(int a){
  switch(a){
  case stPress  : status=stPress;show(Yes);return;
  case stDraft  : show(No);
  case stSelect : setcolor(color);rectangle(x,y,x+w,y+h);
  status=stSelect;}
			   }

Button::Button(int x,int y,int w,int h,int com,int nHelp,\
		char* helpline,word kbHot,char* on,word icolor):
	View(x,y,w,h,com,nHelp,helpline,kbHot)
{color=icolor; my=on;}

MasterButton::MasterButton(int com,char* helpline,word kbHot,char* on):
	Button(4,sizeY-14,38,14,com,1004,helpline,kbHot,on){};

int Button::setcomand(){
 Ev.setevent(comand);
  press();delay(150);
  return stSelect;          }

//===================  private  =============================

void Button::show(int t){
 const c=LIGHTGRAY;
  setfillstyle(SOLID_FILL,c);  bar(x+1,y+1,t?x+w:x+w-3,t?y+h:y+h-3);

  settextjustify(CENTER_TEXT,CENTER_TEXT);
  setcolor(BLACK);             outtextxy(x+w/2,y+h/2,my);
  settextjustify(LEFT_TEXT,TOP_TEXT);

  if(t){ setcolor(DARKGRAY); rectangle(x,y,x+w,y+h); return;}

  setcolor(BLACK);
  line(x+2,y+h-2,x+w-2,y+h-2);	line(x+w-2,y+h-2,x+w-2,y+2);
  setcolor(DARKGRAY);
  line(x+1,y+h-1,x+w,y+h-1);	line(x,y+h,x+w,y+h);
  line(x+w-1,y+1,x+w-1,y+h);	line(x+w,y,x+w,y+h);
  setcolor(WHITE);
  line(x,y,x+w,y);		line(x,y,x,y+h);
  line(x,y+1,x+w-1,y+1);	line(x+1,y+1,x+1,y+h-1);
  }
int Button::preprocess(void){
if(Ev.flag==eSys && Ev.press==cmUpButton && status==stPress){
 --Ev;show(No);select(stSelect);
 return stDelete;}
 return 0;                       }
void Button::unselect(int)
{status=0;show(No);}
void Button::press(void)
{status=stPress;show(Yes);};
