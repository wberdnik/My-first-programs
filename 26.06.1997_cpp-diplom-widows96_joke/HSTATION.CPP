#include"hstation.hpp"
#include"button.hpp"
#include"tkeys.h"
#include"desktop.hpp"
#include"group.hpp"
#include"linebar.hpp"
#include"function.hpp"
#pragma hdrstop

int maxstation;

extern "C" {
		int atoi(const char*);
		 unsigned long farcoreleft(void);
	   };
int hStation::sys(void){
char* text="������ ����稭� ���ଠ樮���� ���⭮��";
switch(Ev.press){
 case cmSaveas : hSave();menu->status=stSelect;draft();return 1;
 case cmSort :  LinePrint("����஢�� ���ᨢ�");
		shistka();
		Ev.setevent(cmLoad);
		too.number=n;                 // ����砥� �� ��
		Ev.setevent(cmEndWork);
		if(n>100)sort();


case cmFreeDraft:  menu->status=stSelect;draft();return 1;

case cmPoint :     flagworking=cmLoad;
		if(tr3!=-1) { //�᫨ �窠 ������� ��� ����� �⠭樨
		if(LineYesNo("������� ��� ?")){
		ci[tr3]=-1; putpixel(tr1,tr2,BLACK);//����砥� ��� 㤠������
						    }
		Ev.setevent(cmEndWork);
		     return 1;
			  }

		if(n>=maxstation){ LineYesNo("  ��⠭���� ����� �⠭権"
						" ���������� !");
				   Ev.setevent(cmEndWork);
				    return 1;
				  }
		  Ev.setevent(cmEndWork);

		 tr1=Ev.x;tr2=Ev.y;
		 for(int i=0;i<n;i++)if(ci[i]==tr1 && di[i]==tr2)return 1;
		 ci[n]=tr1;di[n]=tr2; putpixel(tr1,tr2,YELLOW);
		 c[n]=(float)too.mashtx*tr1/sizeX;
		 d[n]=(float)too.mashty*tr2/(sizeY-sizeDy);
		 do{
		 em[n]=(unsigned)LineInput(text);
		   }while(em[n]>too.doplam);
		 n++;
		 Ev.setevent(cmEndWork);
		 return 1;

	       }
return 0; }


// *****   ����� ��������� � �������� ***********************

hStation::hStation():Modals(){
 flagworking=cmLoad;
 maxstation=(int)((farcoreleft()-20000L)/14 )-1;
 tr3=-1;

   ci=new int[maxstation];
   di=new int[maxstation];
   em=new int[maxstation];
   c = new float[maxstation];
   d = new float[maxstation];


File* file=new File("netcad.stn");

if(file->end<sizeof(strStation)) flagworking=cmNo;

if(flagworking==cmLoad && !yesno(" �� ������ ��ᯮ�짮������ ����묨"
" ��o諮��\n              ᥠ�� ࠡ��� ?"))   flagworking=cmNo;

 if(flagworking==cmLoad){
  LoadHeadStn(*file);
  if(!LoadStn(*file))flagworking=cmNo;
			}
int i;
if(too.add)if(yesno("� ��室��� ������ ᮤ�ন��� ���ଠ�� � 業���\n"
		    "������樨. �� �⮬ �� �� ��⠭���� �뫨 �������\n"
		    "���� �⠭樨. �� ������ �� 㤠���� ?")){
	   too.number-=too.add;
	   too.add=0;
	   for(i=0;i<too.ncentre;i++)
	    if(too.centre[i]>=too.number){
	       too.centre[i]=too.centre[too.ncentre-1];
	       too.ncentre--;             }
								      }
if(flagworking==cmLoad){
for(i=1;i<n;i++) if(c[i-1]>c[i]){i=0;break;}
//if(i==0 && n>99 && yesno(" �� ������,��� �᪮७�� ࠡ��� � ��"
//	"�ࠬ���, \n    �����஢��� �⠭樨 �� ���न��⠬ ?"))sort();
		   }
else{
  long k;
  delete file;
  file=new File("netcad.brd");

  if(file->end<sizeof(strStation)){
  Message("��� ���ଠ樨 � �࠭���");
  delete file;
  flagworking=cmBreak;
  return;
				 }
  LoadHeadStn(*file);
  do{
k=MessageInput("������ ��࠭�祭�� �� ���ଠ樮���� \n"
	       "        ���⭮��� �⠭権");
     }while(k<0 || k>65535L);
too.doplam=(unsigned)k;
}

delete file; //  � 䠩���� ��
//------------------------------------------------------------------
 // ��㥬 ����䥩�

if(flagworking==cmNo) too.number=0;
 n=too.number;

 SetBorder();
 setbase(border);
 setcls(new Worknet());
 insert(menu=new Group);
 int down=sizeY-sizeDy;

 menu->master(new MasterButton(cmNo,"����",kbAltM,"����"));// ������
 menu->insert(new LineBar(1,down-31,140,cmSort, 1101,"����஢��",kbCtrlR));
 menu->insert(new LineBar(1,down-21,140,cmSaveas, 1101,"�������",kbCtrlS));
 menu->insert(new LineBar(1,down-11,140,cmQuit, 1101,"��室",kbCtrlQ));
 menu->setbase(new Ramka(0,down-32,142,32));
 insert(new DeskTop(cmPoint,*this));
if(flagworking!=cmSort)flagworking=cmBreak;
too.ncentre=0;
}

void hStation::hSave(void){
if(flagworking==cmBreak || n==0)return;
unlink ("netcad.stn");
File *file=new File("netcad.stn");
shistka();
too.number=n;
too.add=0; too.ncentre=0;
gettime(&(too.gtime));
getdate(&(too.gdate));
too.gtime2=too.gtime;
too.gdate2=too.gdate;
SaveStn(*file);
delete file;
flagworking=cmBreak;
}

void hStation::shistka(void){
for(int i=0;i<n;i++)if(ci[i]<0 || ci[i]>sizeX){n--;move(i,n);i--;}
		    }

hStation::~hStation(){hSave();};