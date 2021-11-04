#include"group.hpp"
#include"modals.hpp"
#include"clast.hpp"
#include"slave.h"
#include"tkeys.h"
#pragma hdrstop

int Group::handlevent(){		//Ok
int  c=Ev.nsys;
int d=0;

// preprocess
if(image!=NULL && status!=stFocus ||\
	     !(Ev.press==kbEnter && Ev.flag==eKeyboard))
		  d=image->handlevent();         //kbEnter не пропускаем


    if(c!=Ev.nsys){
     Ev.get();  newtext=NULL;
     status=(status!=stFocus)?stFocus:stSelect;
     return (status==stFocus)?stFocus:stDraft;
		  }
return (status!=stFocus || first==NULL || d!=0)?d:Proto::handlevent();
		    }


void Group::draft(void) {	// Строим в обратном порядке чем
Proto::draft();
if(image!=NULL)
  if(status==stFocus)image->select(stPress);
    else            image->draft();
		}

void Group::select(int a){
if(status!=stFocus && image!=NULL){
  image->select(a);  status=stSelect;
				  }
			}

void Group::unselect(int a){
if(status!=stFocus && image!=NULL){
 image->unselect(a);status=0;       }
}

int Group::key(void){
   switch(Ev.press){
   case kbF6:
   case kbTab	    : setfirst(ends);return stSelect;
   case kbShiftTab  : movefirst(first->next);return stSelect;
   case kbESC       : status=stSelect;return stDraft;
   default 	    : return 0;
		   }
			}


int Modals::key(void){
   switch(Ev.press){
   case kbF6:
   case kbTab	    : setfirst(ends);		return stNo;
   case kbShiftTab  : movefirst(first->next);   return stNo;
   case kbPgUp	    : Ev.setevent(cmUp);		return stNo;
   case kbPgDn      : Ev.setevent(cmDown);	return stNo;
   case kbHome      : Ev.setevent(cmHome);	return stNo;
   case kbEnd	    : Ev.setevent(cmEnd); 	return stNo;
   case kbESC	    : Ev.setevent(cmQuit);
     default        : return stNo;
	   }

			}

void Modals::cleargroup(void){
Leaf * b=first;
while(b!=NULL)  {
first=b->next;
delete b;
b=first;           	}
first=NULL;
	       }

void Clast::draft(void){
int i=status;
status=stFocus;
Proto::draft();
status=i;
if(first)first->unselect(stFocus);
			}
void Clast::unselect(int){
if(first)first->unselect(stFocus);
status=stNo;
};
void Clast::select(int){
status=stSelect;
if(first)first->select(stFocus);};

int Clast::key(void){
 if(status==stSelect)
   switch(Ev.press){
   case kbDown	    : setfirst(ends);return stSelect;
   case kbUp        : if(first->next)movefirst(first->next);return stSelect;
		   }
 return 0;
			}
Clast::Clast():Proto(){};
Clast::~Clast(){};
Group::Group():Proto(){
image=NULL;}
Group::~Group(){
if(image)delete image;  }
Modals::Modals():Proto(){};
Modals::~Modals(){};
