#define  GRAPHICSH
#include <graphics.h>
#include"proto.hpp"
#include"error.hpp"
#include"event.hpp"
#include"tkeys.h"
#include"slave.h"
#include"function.hpp"
#pragma hdrstop


Leaf* Proto::go(){
if(first==NULL)return this;
status=stFocus;
static int hran=0;
Ev.setfirst(cmDraft);
while(1){
 if(hran>60){
  hran=0;Ev.setevent(cmGreen);}// == 1 minute
 Ev.get();
 preprocess();
 if(Ev.flag==eSys){
       switch(Ev.press){
     case cmDraft: --Ev;draft(); Ev.clear();LinePrint("");break;
     case cmQuit : return this;
     case cmWait : hran++;
     default     : if(sys())Ev.clear();
		   }
		  }
    else hran=0;
    if(Ev.flag==No)continue;

   switch(handlevent()){
     case stFocus : status=stFocus;draft();break;
     case stDraft : status=stSelect;draft();break;
			}
	}
	  }


int Proto::handlevent(){		//Ok
Leaf *b=first;
  while(b!=NULL && Ev)
    switch(b->handlevent()){
    case stFocus :  if(first->status!=stFocus || b==first){
				 b->draft();newtext=NULL;}  // for Group
    case stSelect :  Ev.clear();
		     if(b!=first){
		       if(first->status==stFocus) {
			 first->status=stNo;
			 Ev.setfirst(cmDraft);      }
			if(!status){status=stSelect;}
			movefirst(b);  }
		     return stSelect;

     case stDraft :  Ev.setfirst(cmDraft);return stSelect;
      default : b=b->next;
			     }

return (Ev.flag==eKeyboard) ? key():0;
}



void Proto::draft(void) {	// Строим в обратном порядке чем
if(cls!=NULL){setcolor(BLACK);cleardevice();cls->draft();newtext=NULL;}
if(status!=stFocus)  return; // Чем обработка ошибок  /Ok
if(base!=NULL)base->draft();
Leaf *b=ends;
if(first==NULL)return;
  while(b!=NULL){
   b->draft();
   b=b->last;	 }
   first->select(stSelect);
			}

void Proto::setfirst(Leaf* a){			//Ok
if(a==first || first==NULL)return; //заклепка

Leaf* b=first;
while(b!=NULL){
 if(b==a){

  if(b->next==NULL)ends=b->last;
  else(b->next->last)=b->last;// Зашили дыру
  (b->last->next)=b->next;

  if(status)first->unselect(0);
  insert(b);
  if(status)first->select(stSelect);
  return;
	  }

  b=b->next;     }
error("Proto : setfirst не найден");
				}

void Proto::movefirst(Leaf* a){                      //Ok
if(a==first || first==0)return;

Leaf* b=first;
int c=status;

if(status){first->unselect(0);status=0;}

while(b!=NULL){
 if(b==a){       // поиск наличия

  while(b!=first) setfirst(ends);  // гоним

  status=c;  if(status) first->select(stSelect);
  return ;
	}

  b=b->next;     }

error("Proto : movefirst не найден");
return ;
				}

Proto::Proto():Leaf(){                                        //Ok
base=first=ends=NULL;cls=No;
}


Proto::~Proto(){					//Ok
Leaf * b=first;
if(base!=NULL)delete base;
if(cls!=NULL)delete cls;
while(b!=NULL)  {
first=b->next;
delete b;
b=first;       	}
		 }

void Proto::insert(Leaf* a){				//Ok
if(a==NULL)error("Ошибка Proto::insert");
if(first==NULL){
	first=ends=a;
	a->next=a->last=NULL;
	return;
		}
   a->next=first;
   (first->last)=a;
   a->last=NULL;
   first=a;
			}


