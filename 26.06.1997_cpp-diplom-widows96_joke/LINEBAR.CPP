#include"linebar.hpp"
#include<string.h>
#include<graphics.h>
#pragma hdrstop
char * linebar;

LineBar::LineBar(int x,int y,int w,int com,int nHelp,char* tx,int ikbhot,
								int hi):
	View(x,y,w,hi,com,nHelp,tx,ikbhot) {newline=NULL;}


void LineBar::show(int t){
  setfillstyle(SOLID_FILL,t?WHITE:LIGHTGRAY);  bar(x,y,x+w,y+h);
  setcolor(BLACK);                             outtextxy(x+10,y+2,hline);
  }
int LineBar::preprocess(void){
if(Ev.flag==eSys && Ev.press==cmLineBar && status==stSelect){
int i=strlen(linebar);
if(i>30)return stSelect;
if(newline!=NULL)delete newline;
newline=new char[i+1];
strcpy(newline,linebar);
hline=newline;show(Yes);
return stSelect;            }
return 0;
}
LineBar::~LineBar(){
if(newline)delete newline;
		   }


void LineBar::select(int a){
if(a==stDraft){setcolor(BLACK);outtextxy(x+10,y+2,hline);return;}
status=stSelect;show(Yes);};

//----------------------------------------------------------------
Radio::Radio(int x,int y,int w,int com,int nHelp,char* help,int ikbhot,\
char *tx):View(x,y,w,20,com,nHelp,help,ikbhot) {text=tx;}


void Radio::show(char k){
setcolor(BLACK);  setfillstyle(SOLID_FILL,k);
fillellipse(x+w-h/2,y+h/2,h/2-2,h/2-2);
outtextxy(x+10,y+7,text);
  }

void Radio::select(int a){
status=stSelect;
show(a==stFocus?LIGHTRED:LIGHTGREEN);return;
			 }

void Radio::unselect(int a){
if(a==stFocus){show(LIGHTGREEN);return;}
status=0;show(LIGHTGRAY);
			};

int Radio::preprocess(void){
if(Ev.flag==eSys && Ev.press==cmOpros && status==stSelect)
{ Ev.setevent(comand);
 return stDelete;
}
return 0;
			       }
