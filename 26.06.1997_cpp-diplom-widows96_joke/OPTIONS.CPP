#include"options.hpp"
#include"button.hpp"
#include"clast.hpp"
#include"linebar.hpp"
#include"diagnost.hpp"
#include"error.hpp"
#pragma hdrstop
extern char * linebar;

Stepweb::Stepweb():Modals(){
Clast * yk;
Leaf *c[6];
setbase(new Bar(92,95,448,180,"��ଠ ����⠡�஢����"));
insert(yk=new Clast());

yk->insert(c[0]=new Radio(330,130,190,cmB1,1005,"����⠡��� ��� ���������",\
		0,"�� ����ࠨ������"));
yk->insert(c[1]=new Radio(330,150,190,cmB2,1005,"����⠡��� ��� � ���� �祪",\
		0,"��窠��"));
yk->insert(c[2]=new Radio(330,170,190,cmB3,1005,"����⠡��� ��� � ���� �����",\
		0,"����ﬨ"));
 switch(KNOW.stepweb){
  case cmNo :	yk->setfirst(c[0]);break;
  case cmPoint: yk->movefirst(c[1]);
		 }

yk->setbase(new High(329,129,192,62,Yes));
yk->status=stFocus;
//*******************************************
insert(yk=new Clast());
char *f="���� ����⠡��� ��";
yk->insert(c[0]=new Radio(110,130,190,cmB4,1005,f,0,"���筥��"));
yk->insert(c[1]=new Radio(110,150,190,cmB5,1005,f,0,"�����"));
yk->insert(c[2]=new Radio(110,170,190,cmB6,1005,f,0,"����"));
yk->insert(c[3]=new Radio(110,190,190,cmB7,1005,f,0,"����"));
yk->insert(c[4]=new Radio(110,210,190,cmB8,1005,f,0,"������"));
yk->insert(c[5]=new Radio(110,230,190,cmB9,1005,f,0,"����"));

char nom=0;
 switch(KNOW.colorweb){
  case BROWN:    nom=0;break;
  case CYAN:      nom=1;break;
  case DARKGRAY:  nom=2;break;
  case RED:       nom=3;break;
  case GREEN :    nom=4;break;
  case LIGHTGRAY: nom=5;break;
		 }
yk->movefirst(c[nom]);

yk->setbase(new High(109,129,192,122,Yes));
yk->status=stFocus;


insert(new Button(390,215,90,30,cmOpros,1005,"����� �����襭�",0,"��"));
};


int Stepweb::sys(void){
if(Ev.press==cmOpros){
     Ev.setevent(cmStop);
     return 0;}
if(Ev.press==cmStop){
		    Ev.setevent(cmStop);
		    Ev.get();
		    while(Ev.flag==eSys &&Ev.press!=cmStop){
		     switch(Ev.press){
		     case cmB1	: KNOW.stepweb=cmNo;break;
		     case cmB2	: KNOW.stepweb=cmPoint;break;
		     case cmB3	: KNOW.stepweb=cmLine;break;
		     case cmB4	: KNOW.colorweb=BROWN;break;
		     case cmB5	: KNOW.colorweb=CYAN;break;
		     case cmB6	: KNOW.colorweb=DARKGRAY;break;
		     case cmB7	: KNOW.colorweb=RED;break;
		     case cmB8	: KNOW.colorweb=GREEN;break;
		     case cmB9	: KNOW.colorweb=LIGHTGRAY;break;
				    }
			  Ev.get();	// cmStop
							 }
			  Ev.setevent(cmQuit);
			  return 1;
				    }

return 0;

 }

///********************************************************************
Real::Real():Modals(){
Proto * yk;
Leaf *c,*d;
setbase(new Bar(92,95,448,180,"���� ���⮢"));
//*******************************************
insert(yk=new Clast());
yk->insert(c=new Radio(110,205,190,cmB6,1006,"���न���� ��������� �१ "
	"1 ᥪ㭤� ��᫥ ��⠭���� �����",0,"�ਢ離� � ⠩����"));
yk->insert(new Radio(110,225,190,cmB7,1006,"���न���� ��������� �� �����"
	"���� ��������� �����",0,"�ਢ離� � ������"));
yk->setbase(new High(109,204,192,42,Yes));
if(KNOW.curtime)yk->setfirst(c);
//***
insert(new Button(390,215,90,30,cmOpros,1005,"����� �����襭�",0,"��"));
//*****
insert(yk=new Clast());

yk->insert(c=new Radio(330,130,190,cmB1,1005,"����� �஢������ �� ���न�"
		"�⠬ �祪 ��࠭�",0,"������ �� ���ᥫ��"));
yk->insert(new Radio(330,150,190,cmB2,1005,"����� �஢������ �� ॠ���"
		" ���न��⠬",0,"������ �����"));
 if(KNOW.modemath==rasMathPixel) yk->setfirst(c);

yk->setbase(new High(329,129,192,42,Yes));


//*****
insert(yk=new Clast());
yk->insert(c=new Radio(110,130,190,cmB3,1005,"�⮡ࠦ����� ���न�"
		"��� �祪 ��࠭�",0,"���न���� ���ᥫ�"));
yk->insert(d=new Radio(110,150,190,cmB4,1005,"�⮡ࠦ����� ॠ��� "
		"���न����",0,"������ ���न����"));
yk->insert(new Radio(110,170,190,cmB5,1005,"K��न���� �� �⮡ࠦ�����",\
		0," ��� ���न���"));

 switch(KNOW.modecoo){
  case rasCooPixel : yk->setfirst(c);break;
  case rasCooReal  : yk->movefirst(d);
		 }
yk->setbase(new High(109,129,192,62,Yes));


};


int Real::sys(void){
switch(Ev.press){
	case cmOpros :Ev.setevent(cmStop);break;
	case cmStop  :
		    Ev.setevent(cmStop);Ev.get();
		    while(Ev.flag==eSys &&Ev.press!=cmStop){
		     switch(Ev.press){
		     case cmB2  :
		     case cmB1	: KNOW.modemath=rasMathPixel;break;
		     case cmB3	: KNOW.modecoo=rasCooPixel;break;
		     case cmB4	: KNOW.modecoo=rasCooReal;break;
		     case cmB5  : KNOW.modecoo=rasCooNo;break;
		     case cmB6  : KNOW.curtime=Yes;break;
		     case cmB7  : KNOW.curtime=No; break;
				    }
			  Ev.get();	// cmStop
							 }
			  Ev.setevent(cmQuit);
			  return 1;
		}
return 0;

 }


