#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <process.h>
#include <alloc.h>

#define ALLOCH
#define  PROCESSH
#define  CONIOH
#define  GRAPHICSH
#define  STDIOH

#include"function.hpp"
#include"modals.hpp"
#include"button.hpp"
#include"diagnost.hpp"
#include"lineinpu.hpp"
#include"pcxlib.h"
#define pcxtype pcxVGA_13
#include"textbar.hpp"
#pragma hdrstop

extern "C"{
	    unsigned strlen(const char *);
	    int atoi(const char *);
	    long atol(const char *);
	    void sound(unsigned);
	    void nosound(void);
	    void delay(unsigned);
	    int bioskey(int);
		};
extern char* desktopline;

void beep(void){
sound(1000);delay(200);nosound();
	       }

void ESCbreak(void){
 TextBar t(20,5,40,16,"Break math",BLUE);
  t(BLACK);
  t.draft();
  (t)(1,1)<<" �������: S,\n �த������ : Space";
  getch();

		    }
void DeskTopPrint(char* a){
desktopline=a;Ev.setevent(cmLineDeskTop);}

void Copyright(void){
 char *pal1,* pal2=((pal1=new char[1536])+768);
 pcxSetDisplay (pcxtype); pcxSetMode (pcxGRAPHICS);
 pcxGetDisplayPalette(pal2);
 pcxGetFilePalette(pcxtype,"mouse.pcx", pal1);
 pcxSetDisplayPalette(pal1);
     pcxFileDisplay("mouse.pcx",0,0,0);
 getch();
 pcxSetDisplayPalette(pal2); pcxSetMode (pcxTEXT);
   delete pal1;
		       }
void GetInfo(void){
int x,y;
TextBar* k= new TextBar(100,100,440,260,NULL,LIGHTGRAY);
k->set(modeDialog,"Info",WHITE,BLUE);
k->set(10,10,10,10);
k->draft();
char * text;
switch(KNOW.processor){
   case 0 : text="i8086(88)"; break;
   case 2 : text="i80286";break;
   case 3 : text="i80386 � ����";break;
   default : text="�� �����⥭";
		       }
((*k)(YELLOW)(1,1)<<"��⮬�⨧�஢���� ࠡ�祥 ���� �஥��஢騪�\n"
		    "                ⮯����� ��. \n"
		    " � �ணࠬ�� ������� �ਭ樯� �ࠢ����� ᮡ��ﬨ,\n"
		    " ᫥����⥫쭮 ��� ������ Windows � TurboVision.  \n"
		    " ��������� ����� � ����� ������ : "<<farcoreleft()<<" "
		    "����.\n � ��ࢮ��砫쭮 �뫮 : "<<KNOW.memfree<<" "
		    "(use = "<<(KNOW.memfree-farcoreleft())<<") ����."
"\n ���������� ���� �� ��᪥ "<<(unsigned long)KNOW.diskfree<<" ����.\n ��"
"� ������ : "<<text<<"(")(25,8)<<KNOW.speedcpu/100<<" K��./ᥪ)";
(*k)<<"\n ����騩 ��⠫�� : "<<KNOW.path<<"\n ����饥 �६� : ";
(*k)(20,10)<<(int)Ev.rolik.one.ti_hour<<":"<<Ev.rolik.one.ti_min<<":";
(*k)<<Ev.rolik.one.ti_sec<<". ";
 x=Ev.x;y=Ev.y;
   while(1){
      Ev.get();
      if(Ev.flag==eSys && Ev.press==cmWait){
      if(Ev.x>k->x+148 && Ev.x<k->x+k->w && Ev.y>k->y+140 && Ev.y< k->y+k->h-19)
      --Ev ;
	  (*k)(20,10)<<(int)Ev.rolik.one.ti_hour<<":"<<Ev.rolik.one.ti_min;
	  (*k)<<":"<<Ev.rolik.one.ti_sec<<". ";
	  (*k)(25,8)<<KNOW.speedcpu/100<<" K��./ᥪ)";
	   continue;                     }
      if(x!=Ev.x || y!=Ev.y){ x=Ev.x;y=Ev.y;continue;}
      else break;
      }
delete k;
    }

void About(void){
TextBar* k= new TextBar(100,100,440,260,NULL,LIGHTGRAY);
--Ev;
Ramka v(99,99,442,262,Yes);v.draft();
(*k)(BLACK)<<"\n    ������������������ ������� ����� ��������������\n"
		"                  ��������� ����\n\n\n"
		"    ���ࠡ��稪� :";
(*k)(BLACK)(15,3)<<"( �������� �஥��.)";
(*k)(30,5)<<"��भ�� �.�.";
(*k)(30,6)<<"���ᥭ�� �.�.";
(*k)(4,9)<<"�㪮����⥫� :";
(*k)(30,9)<<"���ﭮ� �.�.";
(*k)(19,12)<<"������ࠤ 1997�.";

High d(339,195,120,50,No),s(339,273,120,25,No);
s.draft(); d.draft();
delete k;}




void Zap(void){
setfillstyle(SOLID_FILL,WHITE);
bar(100,100,300,300);
setcolor(RED);
outtextxy(120,190,"����� �� ॠ������� ");
		}

void LinePrint(char* b){
 Ev.textforprint=b;  Ev.buildline(); newtext=b;
				  }
int LineYesNo(char* b){
  LinePrint(b);
 do Ev.get(); while(Ev.flag==eSys || !Ev.press);       // ������� ������
int rez=No;
   if(Ev.flag==eMouse){ if(Ev.press==1) rez=Yes; }
    else
	switch(Ev.teg.ch){
	 case 'Y' :
	 case 'y' :
	 case '�' :
	 case '�' :
	 case 0xd :
	 case ' ' : rez=Yes;break;
			 }
 Ev.setevent(cmLine);Ev.get();Ev.clear();// ���⨬ ���᪠���
 return rez;
		     };// function  a LineYesNo

long LineInput(char* text){
LinePrint(text);
Lineinput xtx(strlen(text)*8+74,sizeY-sizeDy,200,sizeDy,cmQuit,"",CYAN,\
BLACK,text);
xtx.status=stSelect;
xtx.draft();
do{xtx.handlevent();Ev.get();}while(Ev.flag!=eSys || Ev.press!=cmQuit);
LinePrint("");
return atol((char*)xtx);        };


class _M_yesno:public Modals,public TextBar{
friend int yesno(char*);
friend void Message(char*);
friend long MessageInput(char*);
     char * stroka;

     int rez;

    _M_yesno(char * b):Modals(),TextBar(100,133,440,190,NULL){
    stroka=b;--Ev;LinePrint("");};
    ~_M_yesno(){LinePrint("");};
    void draft(void){
    TextBar::draft();
    Modals::draft();
    (*this)(YELLOW)(1,1)<<stroka;};
       int sys(void);
			   };

int _M_yesno::sys(void){
	 switch(Ev.press){
	  case cmOk : rez=Yes; break;
	  case cmNo : rez=No; break;
	  default : return 1;
		}
	   Ev.setevent(cmQuit);
	   return 0;   }


int yesno(char* a){
_M_yesno obj(a);
obj.insert(new Button(400,280,52,20,cmNo,0,"���",'N',"���"));
obj.insert(new Button(200,280,52,20,cmOk,0,"��",'Y',"��"));
obj.set((int)16,16,16,60); obj.set(modeDialog,"��� �롮�");
obj.go();
return obj.rez;
}

void Message(char* a){
_M_yesno obj(a);
obj.insert(new Button(300,280,52,20,cmNo,0,"��������",'Y',"��"));
obj.set((int)16,16,16,60);
obj.set(modeDialog," ���ଠ�� ");
if(KNOW.sound){sound(200);delay(100);sound(150);delay(100);nosound();}
obj.go();
}



long MessageInput(char* b){
Lineinput *c;
LinePrint("���� �����");
_M_yesno obj(b);
obj.set((int)16,16,16,85);obj.set(modeDialog," ���� ���ଠ樨. ");
obj.insert(new Button(300,280,52,20,cmNo,0,"��������",'Y',"��"));
obj.insert(c=new Lineinput(116,242,408,15,cmNo,"10",CYAN,\
    WHITE,"��ப� �����"));
obj.go();

return atol((char*)(*c));
}
