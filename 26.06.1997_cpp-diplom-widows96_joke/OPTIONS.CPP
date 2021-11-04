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
setbase(new Bar(92,95,448,180,"Форма масштабирования"));
insert(yk=new Clast());

yk->insert(c[0]=new Radio(330,130,190,cmB1,1005,"Масштабная сеть отсутствует",\
		0,"Не отстраивается"));
yk->insert(c[1]=new Radio(330,150,190,cmB2,1005,"Масштабная сеть в виде точек",\
		0,"Точками"));
yk->insert(c[2]=new Radio(330,170,190,cmB3,1005,"Масштабная сеть в виде линий",\
		0,"Линиями"));
 switch(KNOW.stepweb){
  case cmNo :	yk->setfirst(c[0]);break;
  case cmPoint: yk->movefirst(c[1]);
		 }

yk->setbase(new High(329,129,192,62,Yes));
yk->status=stFocus;
//*******************************************
insert(yk=new Clast());
char *f="Цвет масштабной сети";
yk->insert(c[0]=new Radio(110,130,190,cmB4,1005,f,0,"Коричневый"));
yk->insert(c[1]=new Radio(110,150,190,cmB5,1005,f,0,"Синий"));
yk->insert(c[2]=new Radio(110,170,190,cmB6,1005,f,0,"Серый"));
yk->insert(c[3]=new Radio(110,190,190,cmB7,1005,f,0,"Красный"));
yk->insert(c[4]=new Radio(110,210,190,cmB8,1005,f,0,"Зеленый"));
yk->insert(c[5]=new Radio(110,230,190,cmB9,1005,f,0,"Белый"));

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


insert(new Button(390,215,90,30,cmOpros,1005,"Работа завершена",0,"Да"));
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
setbase(new Bar(92,95,448,180,"Виды расчетов"));
//*******************************************
insert(yk=new Clast());
yk->insert(c=new Radio(110,205,190,cmB6,1006,"Координаты вычисляются через "
	"1 секунду после остановки курсора",0,"Привязка к таймеру"));
yk->insert(new Radio(110,225,190,cmB7,1006,"Координаты вычисляются при измен"
	"ении положения курсора",0,"Привязка к курсору"));
yk->setbase(new High(109,204,192,42,Yes));
if(KNOW.curtime)yk->setfirst(c);
//***
insert(new Button(390,215,90,30,cmOpros,1005,"Работа завершена",0,"Да"));
//*****
insert(yk=new Clast());

yk->insert(c=new Radio(330,130,190,cmB1,1005,"Расчет проводится по координ"
		"атам точек экрана",0,"Расчеты по пикселам"));
yk->insert(new Radio(330,150,190,cmB2,1005,"Расчет проводится по реальным"
		" координатам",0,"Реальные расчеты"));
 if(KNOW.modemath==rasMathPixel) yk->setfirst(c);

yk->setbase(new High(329,129,192,42,Yes));


//*****
insert(yk=new Clast());
yk->insert(c=new Radio(110,130,190,cmB3,1005,"Отображаются координ"
		"аты точек экрана",0,"Координаты пиксела"));
yk->insert(d=new Radio(110,150,190,cmB4,1005,"Отображаются реальные "
		"координаты",0,"Реальные координаты"));
yk->insert(new Radio(110,170,190,cmB5,1005,"Kоординаты не отображаются",\
		0," Без координат"));

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


