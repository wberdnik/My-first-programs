#include<math.h>
#include<dos.h>
#include<stdlib.h>
#define STDLIBH
#define MATHH
#define DOSH

#include"fstation.hpp"
#include"desktop.hpp"
#include"button.hpp"
#include"tkeys.h"
#include"function.hpp"
#include"border.hpp"
#include"diagnost.hpp"
#pragma hdrstop

extern"C" {
	  int rand(void);
	  unsigned long farcoreleft(void);
	  void sound(unsigned frequency);
	  void nosound(void);
	  void delay(unsigned);
	  }

extern int maxstation;
fStation * alocals;

fStation::fStation():Modals(){

void (*prog)(GroupBar&,char);
Leaf* c;

maxstation=(int)((farcoreleft()-10000L)/14);
if(maxstation>5000)maxstation=5000;
maxstation-=5;

File * file=new File("netcad.brd");
 if(file->end<sizeof(strStation)){delete file;
		  delete((new Border())->go());
		  file=new File("netcad.brd");
		  if(file->end==0L){delete file;error(USERS,"","��� �࠭��");}
		  }
 LoadHeadStn(*file);
delete file;

alocals=this;

 switch(too.type){
  case  tRound :    prog=theprogram1; break;
  case  tRectangle: prog=theprogram2;break;
  case  tMore :     prog=theprogram3;break;
  case  tFree :     prog=theprogram4;
			   }

insert(c=new GroupBar(110,110,300,190,cmOk,100,"���������� ����",prog));
insert(new Button(420,160,90,40,cmQuit,1009,"�⬥��",0,"�⬥��"));
insert(new Button(420,220,90,40,cmOpros,1010,"�������� ������� ��"
				 "�",0,"��"));

setbase(new Bar(92,95,448,220,"������� ���न��� �⠭権"));

setfirst(c); status=stFocus;
flagworking=No; // �� ���� �� ��祣� �� ᣥ���஢���
too.ncentre=0;
      }

int fStation::sys(void){
  switch(Ev.press){
  case cmPoint    : DeskTopPrint("� ������ ���㫥 ��� ����� ������");
		    return 1;

  case cmOpros    : Ev.setevent(cmStop);
		    return 0;
  case cmStop     :
		   Ev.get();
		   if(Ev.press==cmOk && Ev.flag==eSys)runnig();
		    return 1;
		   }
   return 1;
			   }


void fStation::runnig(void) {
int j;

n=too.number;
   ci=new int[n];    di=new int[n];   em=new int[n];
   c = new float[n];                  d = new float[n];

  cleargroup();
  delete base;

  SetBorder();
  setbase(border);
  setcls(new Worknet());
  insert(new DeskTop(cmNo,*this));
  insert(new MasterButton(cmQuit,"��室",kbEsc,"��"));

  n=0;  draft();  n=too.number;
  LinePrint("������� �⠭権");

for(int i=0;i<n;i++){
  border->running(*this,i);
   if(c[i]<0)error("���ࠢ��쭠�\n ������� �祪");
   ci[i]=(int)((c[i]/too.mashtx)*sizeX);
   di[i]=(int)((d[i]/too.mashty)*(sizeY-sizeDy));    // aim - 楫�
 for(j=0;j<i;j++) if(ci[j]==ci[i] && di[j]==di[i]){i--;continue;}
   if(!border->test(ci[i],di[i])){i--;continue;}

   em[i]=(int)(tr2-tr1)*((float)rand()/RAND_MAX)+tr1;

   if((i%100)==0 && i!=0){
    sprintf(text,"������஢��� �⠭権 %d",i);LinePrint(text);
		      }
   putpixel(ci[i],di[i],YELLOW);
		    };
   sprintf(text,"������஢��� �⠭権 %d",n);LinePrint(text);
   if(KNOW.sound){sound(3000);delay(50);nosound();}
flagworking=Yes;
		     }


fStation::~fStation(){
if(!flagworking)return;
LinePrint("���࠭���� १����");
unlink ("netcad.stn");
File *file=new File("netcad.stn");
gettime(&(too.gtime));
getdate(&(too.gdate));
too.gtime2=too.gtime;
too.gdate2=too.gdate;
too.add=0; too.ncentre=0;
SaveStn(*file);
delete file;
}




void progforall(GroupBar& z,char a){
int n;
if(a!=cmDraft)goto almf;
switch(z.forprogram){
almf:
 case 2: (!z)(1,0)<<"\n ������ ���祭�� ���ᨬ��쭮�\n"
		      " �ய�᪭�� ᯮᮡ���� �����\n"
		      " ����� ���� 㧫���: - ";
	     if(a==cmDraft)return;

 z>>n;
 while(n<=0){z.merror();z>>n;}
 (alocals->too.doplam)=n;

 z.forprogram+=1;

 case 3 :  z<<"\n �������쭠� ������⢮ ������⮢\n : _ ";
	   if(a==cmDraft)return;

       z>>n;
       while(n<=0 || n>(alocals->too.doplam)){z.merror();z>>n;}
       (alocals->tr1)=n;

      z.forprogram+=1;

 case 4 : z<<"\n ���ᨬ��쭠� ������⢮ ������⮢\n : _ ";
	     if(a==cmDraft)return;

	z>>n;
	while(n<(alocals->tr1) || n>(alocals->too.doplam)){z.merror();z>>n;}

       (alocals->tr2)=n;

       z.forprogram+=1;

}
		  };


void theprogram1(GroupBar& z,char a){
float t; int n;
if(a!=cmDraft)goto amf;
switch(z.forprogram){
amf:
 case 0  : z(BLACK)(5,1)<<"��ଠ �࠭�� ⮯������ : \n";
	   z(LIGHTRED)(10,2)<<" ������";
	   z(BLACK)(1,3)<<"�������襥 �᫮ �⠭権 : "<<maxstation;
	   z(YELLOW)(1,4)<<"����쪮 �⠭権 ����室���\n"
			   " ��� B�襩 �� : _ ";
	    if(a==cmDraft)return;

   z>>n;
   while(n<=0 || n>=maxstation){  z.merror(); z>>n;  }

  alocals->too.number=n;
  z.forprogram+=1;

 case 1: z<<"\n ��������, 㪠��� ��⭮���\n"
	      " ��ᯥ�ᨨ ࠤ���� ����ਨ \n : _ ";
			 if(a==cmDraft)return;

  z>>t;
 while(t<=0){z.merror();z>>t;};
 alocals-> there=t;

 z.forprogram+=1;
 default : progforall(z,a);
		    }
			       };
void theprogram2(GroupBar& z,char a){
int n;
if(a!=cmDraft)goto amf2;
switch(z.forprogram){
amf2:
 case 0  : z(BLACK)(5,1)<<"��ଠ �࠭�� ⮯������ :\n";
	   z(LIGHTRED)(10,2)<<"��אַ㣮�쭨�";
	   z(BLACK)(1,3)<<"�������襥 �᫮ �⠭権 : "<<maxstation;
	   z(YELLOW)(1,4)<<"����쪮 �⠭権 ����室���\n"
			   " ��� B�襩 �� : _ ";
	    if(a==cmDraft)return;

   z>>n;
   while(n<=0 || n>maxstation){  z.merror(); z>>n;  }

  alocals->too.number=n;
  z.forprogram=2;

 default : progforall(z,a);
		    }
			       };

void theprogram3(GroupBar& z,char){
	 z(BLACK)(5,1)<<"��ଠ �࠭�� ⮯������ :\n";
	 z(LIGHTRED)(8,2)<<"�����㣮�쭨�";
	 z(1,3)<<"� ������ ���ᨨ \n �� �� ॠ�������� !!!";
	    return;

		       } ;
void theprogram4(GroupBar& z,char){
	 z(BLACK)(5,1)<<"��ଠ �࠭�� ⮯������ :\n";
	 z(LIGHTRED)(8,2)<<"�ந����쭠� �������";
	   z(1,3)<<"� ������ ���ᨨ \n �� �� ॠ�������� !!!";
	    return;
		       } ;


