#include"border.hpp"
#include"Button.hpp"
#include"linebar.hpp"
#include"clast.hpp"
#include"simple.hpp"
#include"diagnost.hpp"
#pragma hdrstop

extern "C"{
	 char *strncpy(char*,const char*,unsigned);
	 char *strcat(char *,const char*);
	  };



Border * locals;

void theprogram(GroupBar& z,char a){
float t;
if(a!=cmDraft)goto mf;
switch(z.forprogram){
mf:
case 0 : z(1,0)<<"\n ������ ࠧ��� �� �� X (km) _ ";
		   if(a==cmDraft)return;

z>>t;
while(t<=0){z.merror();z>>t;};

(locals->one.mashtx)=t;
z.forprogram+=1;

case 1 : z(1,4)<<"\n ������ ࠧ��� �� �� Y (km) _ ";
		 if(a==cmDraft)return;
z>>t;
while(t<=0){z.merror(); z>>t;};

(locals->one.mashty)=t;
		      }
				     };

Border::Border():Modals(){
Clast * yk;
Leaf *c;
locals=this;
setbase(new Bar(92,95,448,220,"��ଠ ࠡ�祩 ������"));
insert(yk=new Clast());

yk->insert(c=new Radio(330,120,190,cmB1,1005,"������ ������� � �ଥ ����"
		"�� ��� ���㦭���",0,"���"));
yk->insert(new Radio(330,140,190,cmB2,1005,"������ ������� � ���� ��אַ�"
		"��쭨�� ��� ������",0,"��אַ㣮�쭨�"));
/*yk->insert(new Radio(330,160,190,cmB3,1005,"������ ������� � ���� ��㪫�"
		"�� �����㣮�쭨��",0,"�����㣮�쭨�"));
yk->insert(new Radio(330,180,190,cmB4,1005,"������ ������� �ந����쭮� �"
		"��� ",0,"�ந����쭠� �������"));*/
yk->setfirst(c);
yk->setbase(new High(329,119,192,42,Yes));
yk->status=stFocus;

insert(new Button(380,230,90,60,cmOpros,1005,"����� �����襭�",0,"��"));
insert(c=new GroupBar(110,110,200,190,cmOk,100,"���������� ����",theprogram));

setfirst(c);
};

int Border::sys(void){
if(Ev.press==cmOpros){
     Ev.setevent(cmStop);
     return 0;}
if(Ev.press==cmStop){
      Ev.setevent(cmStop);
      while(1){
	Ev.get();
	if(Ev.press==cmStop) break;
	switch(Ev.press){
	 case cmB1	: one.type=tRound;break;
	 case cmB2	: one.type=tRectangle;break;
	 case cmB3	: one.type=tMore;break;
	 case cmB4	: one.type=tFree;break;
	 case cmOk      : Ev.setevent(cmQuit);
		       }
	       }
		    }
return 0;

 }
Border::~Border(){
unlink("netcad.brd");
File* file=new File("netcad.brd");
(*file)+sizeof(strStation);
(*file)%sizeof(strStation);
one.ncentre=one.add=0;one.number=0;
gettime(&(one.gtime));
getdate(&(one.gdate));
(*file)[0]=(void*)&one;
delete file;
		 }