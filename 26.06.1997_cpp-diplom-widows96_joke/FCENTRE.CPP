#include <math.h>
#define  MATHH
#include"fcentre.hpp"
#include"sourse.hpp"
#include"diagnost.hpp"
#include"function.hpp"
#include"group.hpp"
#include"button.hpp"
#include"linebar.hpp"
#include"tkeys.h"
#include"desktop.hpp"
#pragma hdrstop

extern char* linebar;

long abs (long a){return a>0?a:-a;};

//  ************    endsym  **********************
const double wx=1.0000001*sizeX/20;
const double wy=1.0000001*(sizeY-sizeDy)/15;


fCentre::fCentre():Modals(){
flagworking=cmBreak;
int x,y;
if(LoadAllStn(5))return;
if(too.number<5){
		  Message(" Количество станций меньше чем пять.\n"
			  " Дальнейшая работа не возможна ! ");
		   return;}

 n=too.number;
Wait *myxa=new Wait('T');
int k;
for(k=0;k<300;k++)sem[k]=0;
for(k=0;k<5;k++)wind[k]=NULL;
myxa->tik(1);
 for(k=0;k<n;k++){
 if(k && (k%1000)==0)myxa->tik(((float(k)*99)/n));
  x=(int)ceil(ci[k]/wx-1);  x=x>0?x:0;
  y=(int)ceil(di[k]/wy-1);  y=y>0?y:0;
  sem[20*(14-y)+x]+=em[k];
		}
myxa->tik(99);
 for(k=0;k<15;k++)Qg[k]=Qg1[k]=Qg2[k]=Dg[k]=0;
 for(k=0;k<20;k++)Qv[k]=Qv1[k]=Qv2[k]=Dv[k]=0;

myxa->tik(100);

 setcls(new Worknet());
 SetBorder();
 setbase(border);
 insert(menu=new Group);
 int down=sizeY-sizeDy;

 menu->master(new MasterButton(cmNo,"Меню",kbAltM,"Меню"));// кнопка
 menu->insert(new LineBar(1,down-61,140,cmAuto, 1101,"Авто",kbCtrlA));
 menu->insert(new LineBar(1,down-51,140,cmView, 1101,"Поток нет",kbCtrlP));
 menu->insert(perek[0]=new LineBar(1,down-41,140,cmCalc, 1101,"Оценка ",\
								   kbCtrlO));
 menu->insert(perek[1]=new LineBar(1,down-31,140,cmB1, 1101,  "Установка *",\
								   kbCtrlS));
 menu->insert(perek[2]=new LineBar(1,down-21,140,cmB2, 1101,  "Удаление",\
								   kbCtrlU));
 menu->insert(new LineBar(1,down-11,140,cmQuit, 1101,"Выход",kbCtrlQ));
 menu->setbase(new Ramka(0,down-62,142,62));
 insert(new DeskTop(cmPoint,*this));
 mode=Yes;         //set
 modedraft=No;
 flagworking=cmBreak;
if(too.ncentre) Ev.setfirst(cmLoad);
 delete myxa;
};


int fCentre::sys(void){
switch(Ev.press){
case cmLoad :   loadcentre();
		flagworking=cmBreak;
		 return 1;
case cmFreeDraft:           break;
case cmB1    :    setperek(1);mode=Yes; return 1;
case cmB2    :    setperek(2);mode=No;  return 1;
case cmPoint :    imin=Ev.x;jmin=Ev.y;
		  switch(mode){
		  case cmGetInfo : calc();       break;
		  case Yes       : if(setcentre())break; return 1;
		  case No        : if(unsetcentre())break;return 1;
		  default        : mode=Yes;
			      }
		  break;
case cmView  :    if(modedraft){modedraft=No;linebar="Поток нет";}
		    else{modedraft=Yes;linebar="Поток да";}
		  Ev.setevent(cmLineBar);
				return 1;

case cmAuto  :    centr_commutator();{flagworking=cmNo;break;}
case cmCalc  :    if(too.ncentre==0){
		  Message("Центральные станции не определены ");break;
				    }
		  setperek(0); mode=cmGetInfo;return 1;
default       :  return 0;
	       }
draft(); return 1;
 }


fCentre::~fCentre(){
for(char i=0;i<5;i++)
 if(wind[i]!=NULL)
   delete wind[i];
if(flagworking==cmBreak)return;
if(too.add)unlink("netcad.stn");
File * file=new File("netcad.stn");
too.number=n;
(*file)%sizeof(strStation);
if(too.add)(*file)+1;
(*file)[0]=(void*)&too;
if(too.add){
gettime(&(too.gtime));
getdate(&(too.gdate));
SaveStn(*file);
	    }
delete file;
}


//******************** function ********************************************

void fCentre::centr_commutator(void) {
if(too.ncentre>=5){
Message("Установка новых центров комутации невозможна !!!");return;}

Wait* myxa=new Wait('T');
 int i,j;
 unsigned long Dmin;

 imin=0;jmin=0;

for(i=0;i<15;i++)for(j=0;j<20;j++){Qg[i]+=sem[i*20+j]; Qv[j]+=sem[i*20+j];}

/*  центр комутации по координате Y  */

Qg1[0]=Qg[0];  Qg2[14]=Qg[14];
for(i=1;i<15;i++){Qg1[i]=Qg[i]+Qg1[i-1];Qg2[14-i]=Qg[14-i]+Qg2[15-i];}
for(i=0;i<15;i++){Dg[i]=abs((long)Qg1[i]-(long)Qg2[i]);if(i==0)  Dmin=Dg[0];
 if(Dg[i]<Dmin){Dmin=Dg[i];jmin=i;}
		 }

/*  центр комутации по координате X  */

Qv1[0]=Qv[0];  Qv2[19]=Qv[19];
for(j=1;j<20;j++){ Qv1[j]=Qv[j]+Qv1[j-1]; Qv2[19-j]=Qv[19-j]+Qv2[20-j];}
for(j=0;j<20;j++){Dv[j]=abs((long)Qv1[j]-(long)Qv2[j]); if(j==0)  Dmin=Dv[0];
  if(Dv[j]<Dmin){Dmin=Dv[j];imin=j;}
		 }
jmin=14-jmin;
imin=imin*wx+wx/2;
jmin=jmin*wy+wy/2;
int len=int(wx+wy);
int curlen;
myxa->tik(30);
j=n;
for(i=0;i<n;i++){
curlen=hypot(ci[i]-imin,di[i]-jmin);
if(curlen<len){len=curlen;j=i;}
		}
if(j!=n && abs(ci[j]-imin)<=wx/2 && abs(di[j]-jmin)<=wy/2){
   imin=ci[j];
   jmin=di[j];                                  }


/////////////////////////////////////////////////////////////////////////////
delete myxa;
if(border->test(imin,jmin))setcentre();
else{ Message("Центр не найден");Ev.setevent(cmDraft);}

		       }

int fCentre::setcentre(void){
if(too.ncentre>=5){
DeskTopPrint("Установка новых центров комутации невозможна !!!");
too.ncentre=5;return 0;}

int i;
for(i=0;i<too.ncentre;i++)
      if(imin==ci[too.centre[i]] && jmin==di[too.centre[i]]){
      Message("Центр комутации совпал с существующем");
      Ev.setevent(cmDraft);return 1;}

for(i=0;i<too.number;i++)
  if(ci[i]==imin && di[i]==jmin){
    too.centre[too.ncentre]=i;
    too.ncentre+=1;
    break;                    }
if(i==too.number){
ci[n]=imin;		di[n]=jmin;     em[n]=0;
c[n]=(float)too.mashtx*imin/sizeX; d[n]=(float)too.mashty*jmin/(sizeY-sizeDy);
too.centre[too.ncentre]=n;
n++;
too.ncentre+=1;
too.add+=1;
		}
sprintf(string,"Установлена станция номер %d",too.ncentre);
DeskTopPrint(string);
wind[too.ncentre-1]=new Window(imin-4,jmin-4,8,8,WHITE);
++(*wind[too.ncentre-1]);
setcolor(LIGHTRED);  setfillstyle(CLOSE_DOT_FILL,LIGHTRED);
fillellipse(imin,jmin,3,3);
flagworking=cmNo;
return 0;
			  }

int fCentre::unsetcentre(void){
if(too.ncentre<=0){DeskTopPrint("Удаление невозможно !!!");
		   n=too.number;too.ncentre=0; return 0;}
int i,j=too.ncentre;
float len,min=3.0;
for(i=0;i<too.ncentre;i++){
len=hypot(float(imin-ci[too.centre[i]]),float(jmin-di[too.centre[i]]));
if(len<min){j=i;min=len;}
			  }
if(j==too.ncentre){DeskTopPrint(" Станция не найдена ");return 0;}

			 // j - номер удаляемого ц.к.

flagworking=cmNo;
for(i=too.ncentre-1;i>=0;i--)--(*wind[i]);  //hiden all station

if(too.centre[j]>=too.number){    // если точка была создана
n--; too.add-=1; i=too.centre[j]; // i - удаляемая точка
 if(i!=n)                    {    // ЕСЛИ точка была создана не одна
c[i]=c[n];d[i]=d[n];ci[i]=ci[n];di[i]=di[n]; // то переносим ее в конец
for(i=0;i<too.ncentre;i++)        // ищем ту
   if(too.centre[i]==n)      {    // которая указывала на последнюю
     too.centre[i]=too.centre[j]; //теперь указывает на j
       break;                }}}

too.ncentre-=1;
delete wind[j];
wind[j]=wind[too.ncentre];
wind[too.ncentre]=NULL;
too.centre[j]=too.centre[too.ncentre];

			    // show all station
setcolor(LIGHTRED);  setfillstyle(CLOSE_DOT_FILL,LIGHTRED);
for(i=0;i<too.ncentre;i++)
if(wind[i]==NULL)error("переменная fcentre:wind");
 else{ ++(*wind[i]); fillellipse(ci[too.centre[i]],di[too.centre[i]],3,3);}

DeskTopPrint("Удалена станция");
return 0;
				      }

void fCentre::calc(void){
int i,j=too.ncentre;

long double dlins=0.0;
long double podl=3.0;
double ax;

Wait myxa('T');

for(i=0;i<too.ncentre;i++){
dlins=hypot(float(imin-ci[too.centre[i]]),float(jmin-di[too.centre[i]]));
if(dlins<podl){j=i;podl=dlins;}
			  }
if(j==too.ncentre){DeskTopPrint(" Станция не найдена");return;}
dlins=podl=0.0;
myxa.tik(0);

for(i=0;i<too.number;i++)
if(i!=too.centre[j]){
ax=hypot(c[i]-c[too.centre[j]],d[i]-d[too.centre[j]]);
dlins+=ax;podl+=ax*em[i];
if(i && (i%500)==0)myxa.tik(((float(i)*100)/too.number));
		 }
sprintf(string,"Суммарное растояние от всех станций до \n"
	       " центральной : %.3Lf km\n"
	       " растояние * поток : %.3Lf",dlins,podl);
Message(string);
			   }

void fCentre::draft(void){
int i,j;
for(i=0;i<5;i++)if(wind[i])--(*wind[i]);
menu->status=stSelect;
Modals::draft();
if(modedraft==Yes){
 setcolor(KNOW.colorweb);
 for(i=0;i<16;i++)for(j=0;j<20;j++)
 if(sem[i*20+j]!=0) {sprintf(string,"%Ld",sem[i*20+j]);
  outtextxy(j*sizeX/20+sizeX/80,(14-i)*(sizeY-sizeDy)/15+sizeY/40, string);
		    }
		  }
for(i=0;i<5;i++)if(wind[i])++(*wind[i]);
setcolor(LIGHTRED);  setfillstyle(CLOSE_DOT_FILL,LIGHTRED);
for(i=0;i<too.ncentre;i++)
   fillellipse(ci[too.centre[i]],di[too.centre[i]],3,3);

			 }

void fCentre::setperek(char a){
char i=2;
for(char j=0;j<2;j++){
if(j)
switch(a){
   case 0 : linebar="Оценка    *"; i=a;break;
   case 1 : linebar="Установка *"; i=a;break;
   case 2 : linebar="Удаление  *"; i=a;
	 }
else
switch(mode){
   case cmGetInfo : linebar="Оценка";i=0;break;
   case Yes       : linebar="Установка";i=1;break;
   case No        : linebar="Удаление";i=2;
	 }
Ev.flag=eSys;Ev.press=cmLineBar;
menu->movefirst(perek[i]);menu->handlevent();
		 }
Ev.flag=0;
}

void fCentre::loadcentre(void){
char i;	char  pk=too.ncentre;
unsigned* point=new unsigned[pk*2];
for(i=0;i<pk;i++){      // запомнили координаты
point[i]=ci[too.centre[i]];point[i+pk]=di[too.centre[i]]; }

 too.number-=too.add;  //установили системные переменные
 too.add=0;
 too.ncentre=0;
 n=too.number;

 for(i=0;i<pk;i++){
 imin=point[i];jmin=point[i+pk];setcentre(); }
delete point;
		       }