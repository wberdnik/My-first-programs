#include<math.h>
#include<string.h>
#define MATHH
#define STRINGH
#include"bitmap.hpp"

#include"concent.hpp"
#include"button.hpp"
#include"tkeys.h"
#include"desktop.hpp"
#include"group.hpp"
#include"linebar.hpp"
#include"function.hpp"
#include"basedata.hpp"

#include"sourse.hpp"
#include"diagnost.hpp"
#pragma hdrstop

extern int maxstation;
extern char* linebar;
extern char* con;
const double wx=1.0000001*sizeX/20;
const double wy=1.0000001*(sizeY-sizeDy)/15;
long abs (long a);

cAdd::cAdd():cSub(){};
cAdd::~cAdd(){};


FILE* cSub::algoritm(void){
LinePrint("Алгоритм \"Удаление\"");
Masint& mas=*massiv;
long i,s=0;
int min,nmin,j,k,x,l;
double dQ;
double begin;
int nQ;

char flag=No;

Masint&  copy=*new Masint(mai,ncon+1);
Masint&  first=*new Masint(mai,ncon+1);

Wait * myxa=new Wait(0);

first<<0;

for(l=0;l<ncon;l++){

nQ=ncon; dQ=0.0;


for(k=-1;k<ncon;k++){

if(!(s%10))myxa->tik((float)s*100/(ncon*ncon));
s++;
copy<<first;                       // инициализация матрицы подключений
if(k>0)copy[k]=concent.input+2;    // помечаем как перегруженый


		// сборка матрицы ╗
for(i=0;i<n;i++)mas[i*(ncon+2)+ncon+1]=ncon+1;
for(j=0;j<ncon;j++) con[j].flag=No;
for(i=0;i<n;i++)
  if(mas[i*(ncon+2)+ncon+1]>ncon) { // если станция не подключена
nmin=ncon;min=mas[i*(ncon+2)+ncon]; //первоначальная точка - ЦК
 for(j=0;j<ncon;j++)                //по всем концентраторам
   if(copy[j]<concent.input){
       x=mas[i*(ncon+2)+j];
     if(x<min){nmin=j;min=x;}}
  copy[nmin]+=1;
  mas[i*(ncon+2)+ncon+1]=nmin;
  if(nmin<ncon)con[nmin].flag=Yes;
			      }
double cena2=findcoast();
	//конец сборки матрицы   ╝

if(flag){cena=cena2; k=l=ncon; continue;}

if(k==-1){
cena=cena2;
if(l==0){--(*myxa);draft();++(*myxa);begin=cena;}
	 }
else if(dQ>(cena2-cena)){ nQ=k;dQ=cena2-cena; }

		       }  // для k
if(dQ>=0) {flag=Yes;continue;}   // Условие выхода из алгоритма
first[nQ]=concent.input+2;       // принимаем в качестве нач сеть мин сто
		       }
delete myxa;

    char string[100];
sprintf(string,"Cтоимость сети в начале : %.3f\n"
	       "            в результате : %.3f",begin,cena);
    Message(string);
    draft();


char * a="netsub.rpt";
   unlink(a);
   FILE* file =fopen(a,"wt");
   fprintf(file,"Отчет программы о установке концентраторов \"Удаление\"");
delete &copy;
delete &first;
   return file;

	   }
FILE* cAdd::algoritm(void){

Masint& mas=*massiv;
long i;
int min,imin,j,x,jmin,k,y;
double cena2;


for(i=0;i<n;i++)mas[i*(ncon+2)+ncon+1]=ncon;
for(j=0;j<ncon;j++)con[j].flag=No;
double begin=cena=findcoast();
draft();
Wait* myxa=new Wait(0);

Masint& copy=*new Masint(mai,(ncon+2)*n);
copy<<mas;

 LinePrint("Преобразование матрицы");
 for(i=0;i<n;i++){
  if(!(i&&(i%10))) myxa->tik((float)i*100/n);
  for(j=0;j<ncon;j++)
    copy[i*(ncon+2)+j]+=(-(int)copy[i*(ncon+2)+ncon]);
		 }


Masint& first=*new Masint(mai,ncon+1);

LinePrint("Алгоритм \"Добавления\"");

first<<0;

for(k=0;k<ncon;k++){

  myxa->tik((float)k*100/ncon);

imin=-1;jmin=ncon;min=0; //первоначальная точка - ЦК

for(j=0;j<ncon;j++)                //по всем концентраторам
 if(con[j].flag==0)
   for(i=0;i<n;i++){
       x=copy[i*(ncon+2)+j];
     if(x<min){jmin=(int)j;min=x;imin=(int)i;}
			      }

if(min>=0)break;         // for k
			 // Установка концентратора

  con[jmin].flag=-1;
  first[jmin]+=1;
  mas[imin*(ncon+2)+ncon+1]=jmin;

for(j=0;j<n;j++){
min=0;
if(first[jmin]<concent.input)
  for(i=0;i<n;i++){
     x=copy[i*(ncon+2)+jmin];
    if(x<min){
     y=mas[i*(ncon+2)+ncon+1];
     if(y==ncon || mas[i*(ncon+2)+y]>mas[i*(ncon+2)+jmin])
			     {;min=x;imin=(int)i;}
	     }
		   }

if(min>=0)break;  //for j
  first[jmin]+=1;
  mas[imin*(ncon+2)+ncon+1]=jmin;
		   }// for j


cena2=findcoast();
 if(cena2<cena){cena=cena2;con[jmin].flag=1;continue;}

for(i=ncon+1;i<n*(ncon+2);i+=(ncon+2))if(mas[i]==jmin) mas[i]=ncon;

     } //for k

for(j=0;j<ncon;j++)if(con[j].flag==-1)con[j].flag=0;

delete myxa;
    char string[100];
   sprintf(string,"Cтоимость сети в начале : %.3f\n"
	       "            в результате : %.3f",begin,cena);
    Message(string);
    draft();

char * a="netadd.rpt";
   unlink(a);
   FILE* file =fopen(a,"wt");
   fprintf(file,"Отчет программы о установке концентраторов \"Добавление\"");

delete & first;
delete & copy;
   return file;

};


void cSub::metod(void){
if(ncon<1){Message("Не указаны координаты концентраторов");return;}
//Message("Необходимо выбрать кабель и концентратор \n используемые в сети");
draft();

   Cabel* base1=new Cabel();
   base1->go();
   cabel=base1->zapis;
   delete base1;
if(!strncmp(cabel.name,::con,strlen(::con)))error(USERS,"Нет кабеля","");

  Concent* base=new Concent();
   base->go();
   concent=base->zapis;
   delete base;
if(!strncmp(concent.name,::con,strlen(::con)))
			error(USERS,"Нет концентратора","");


   draft();                        // ┌───┬───────────────────┬───┬─┬─┐
long i,j,t;			   // ├───┼───────────────────┼───┤Ц├─┤
int x,k;			   // ├ 1─┼───────────────────┼ 40┤К├─┤
				   // │   │                   │   │ │F│
Wait * myxa=new Wait('T');         // ├───┼───────────────────┼───┼─┴─┤
     LinePrint("Расчет матрицы");  // └───┴───────────────────┴───┴───┘
		   //Выделили память
if(massiv && conbegin!=ncon ) delete massiv;
massiv=new Masint(mai,(v_size)(ncon+2)*(n+1));
conbegin=ncon;
Masint& mas=*massiv;

for(i=0;i<n;i++)mas[i*(ncon+2)+ncon+1]=ncon+1;

for(i=0;i<n;i++){  // Посчитали матрицу растояний
if(!(i&&(i%100)))myxa->tik((float)i*90/n);
 for(j=0;j<ncon;j++)
 mas[i*(ncon+2)+j]=(int)hypot((float)(ci[(int)i]-con[(int)j].x),\
			      (float)(di[(int)i]-con[(int)j].y));
		 }
 k=too.centre[0];
for(i=0;i<n;i++){  // Посчитали матрицу для ЦК
 if(!(i&&(i%1000)))myxa->tik((float)i*10/n+90);
mas[i*(ncon+2)+ncon]=(int)hypot((float)(ci[(int)i]-ci[k]),\
				(float)(di[(int)i]-di[k]));
		}
for(i=0;i<ncon;i++) // растояние ЦК - концентратор
 mas[(long)n*(ncon+2)+i]=(int)hypot((float)(ci[k]-con[(int)i].x),\
				(float)(di[k]-con[(int)i].y));

 mas[n*(ncon+2)+ncon]=0;
  delete myxa;


//а тeперь
FILE * file=algoritm();


   struct time tnaw;
   struct date dnaw;

   for(t=0;t<2;t++){
    if(!t){
    dnaw=too.gdate2;
    tnaw=too.gtime2;
   fprintf(file,"\nВремя создания файла станций:\n");
	   }
      else{
   getdate(&(dnaw)); gettime(&(tnaw));
   fprintf(file,"%s\n","\nВремя редактирования файла связи:");
	  }
   fprintf(file,"год - %d\tдень - %d\tмесяц - %d\n",dnaw.da_year,\
   dnaw.da_day,dnaw.da_mon);
   fprintf(file,"час - %d\tмин.- %d\tсек. - %d\n",tnaw.ti_hour,\
   tnaw.ti_min,tnaw.ti_sec);
	    }
   fprintf(file,"%s\n","\n\t\tКоординаты узлов");
   fprintf(file,"%s\n","\nШкаф\t\tX\t\tY\n");

   for(i=0;i<n;i++)
      fprintf(file,"%d\t\t%d\t\t%d\n",(int)(i+1),ci[(int)i],di[(int)i]);

   fprintf(file,"\n\tКоммутатор\tСтанция\n");
   for(i=0;i<n;i++)          {
      x=mas[i*(ncon+2)+ncon+1];
       if(x>=ncon)fprintf(file,"\n\t\tЦК\t\t%d",i);
       else       fprintf(file,"\n\t\t%d\t\t%d",x+1,i);
			      }

  fprintf(file,"\nИз %d используются только концентраторы\n",ncon);

 for(i=0;i<ncon;i++)
  if(con[(int)i].flag)
fprintf(file,"\nКонцентратор  %d\tx = %d\ty = %d",\
	       (int)(i+1),con[(int)i].x,con[(int)i].y);
fprintf(file,"\nЦК             x = %d y = %d",\
		ci[too.centre[0]],di[too.centre[0]]);

  fprintf(file,"\n\nСтоимость кабеля           %d",cabel.cena);
  fprintf(file,"\nСтоимость концентратора    %d",concent.cena);
  fprintf(file,"\nЧисло входов концентратора %d",concent.cena);
  fprintf(file,"\nСтоимость сети             %.3f\n",cena);

   fclose(file);


}

double cSub::findcoast(void){
long i;
double cena3=0;
Masint & mas=*massiv;

for(i=0;i<ncon;i++)                 // стоимость концентраторов
  if(con[(int)i].flag){
     cena3+=(double)concent.cena;   // и линий связи до АТС
     cena3+=(double)cabel.cena*(double)((int)mas[n*(ncon+2)+i]);
		       }
for(i=0;i<n;i++)                    // стоимость линий связи
cena3+=(double)cabel.cena*(double)((int)mas[i*(ncon+2)+(int)mas[i*(ncon+2)+ncon+1]]);

return cena3;
}

cSub::cSub(){
flagworking=cmBreak;
int x,y;
massiv=NULL;
if(LoadAllStn(5))return;
if(too.number<5){
		  Message(" Количество станций меньше чем пять.\n");
		   return;}

 n=too.number;
if(too.ncentre!=1){
		  Message(" Должен быть указан один центp коммутации");
		   return;}



Wait *myxa=new Wait('T');
int k;
for(k=0;k<300;k++)sem[k]=0;
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
 menu->insert(new LineBar(1,down-81,140,cmAuto, 1101,"Алгоритм",kbCtrlB));
 menu->insert(new LineBar(1,down-71,140,cmView, 1101,"Поток нет",kbCtrlP));
 menu->insert(perek[0]=new LineBar(1,down-61,140,cmCalc, 1101,"Оценка ",\
								   kbCtrlO));
 menu->insert(perek[1]=new LineBar(1,down-51,140,cmB1, 1101,  "Установка *",\
								   kbCtrlS));
 menu->insert(perek[2]=new LineBar(1,down-41,140,cmB2, 1101,  "Удаление",\
								   kbCtrlU));
 menu->insert(new LineBar(1,down-31,140,cmLoad, 1101,  "Загрузить",\
								   kbCtrlU));
 menu->insert(new LineBar(1,down-21,140,cmSaveas, 1101,  "Сохранить",\
								   kbCtrlU));
 menu->insert(new LineBar(1,down-11,140,cmQuit, 1101,"Выход",kbCtrlQ));
 menu->setbase(new Ramka(0,down-82,142,82));
 insert(new DeskTop(cmPoint,*this));
 mode=Yes;         //set
 modedraft=No;
 flagworking=cmBreak;
 ncon=0; // число концентраторов равно 0
 conbegin=-1;
 delete myxa;
};


int cSub::sys(void){
File* file;
int j;
switch(Ev.press){
case cmB1    :    setperek(1);mode=Yes; return 1;
case cmB2    :    setperek(2);mode=No;  return 1;
case cmPoint :    imin=Ev.x;jmin=Ev.y;
		  switch(mode){
		  case cmGetInfo : calc();       break;
		  case Yes       : if(setcon())break; return 1;
		  case No        : if(unsetcon())break;return 1;
		  default        : mode=Yes;
			      }
		  break;

case cmView  :    if(modedraft){modedraft=No;linebar="Поток нет";}
		    else{modedraft=Yes;linebar="Поток да";}
		  Ev.setevent(cmLineBar);return 1;

case cmAuto  :    if(ncon>0){
			metod();flagworking=cmNo;break;
			    }
		   return 1;
case cmSaveas  :    if(ncon==0) return 1;
		   file=new File("netcad.con");
		  (*file)%2+(1+ncon*2);
		  (*file)[0]<<(void*)&ncon;
		  (*file)+=1;
		for(j=0;j<ncon;j++){
		 ((*file)[0]<<(void*)&(con[j].x))[1]<<(void*)&(con[j].y);
		 (*file)+=2;}

		  delete file;
		  return 1;

case cmLoad  :    file=new File("netcad.con");
		  (*file)%2;
		  (*file)>>(void*)&ncon;
     if(ncon>CON || file->end<(ncon*2)){
		  Message("Ошибка в файле");ncon=0;break;}
		  (*file)+=1;
		for(j=0;j<ncon;j++){
		 ((*file)[0]>>(void*)&(con[j].x))[1]>>(void*)&(con[j].y);
		 con[j].flag=Yes;
		 (*file)+=2;}
		  delete file;  break;


case cmCalc  :    if(ncon==0){
		  Message("Концентраторы не установлены ");break;
				    }
		  setperek(0); mode=cmGetInfo;return 1;
default       :  return 0;
	       }
draft(); return 1;
 }


cSub::~cSub(){
if(massiv)delete massiv;
}


//******************** function ********************************************


int cSub::setcon(void){
if(ncon>=CON){
DeskTopPrint("Установка новых концентраторов невозможна !!!");
ncon=CON;return 0;}

int i;
for(i=0;i<ncon;i++)
      if(imin==con[i].x && jmin==con[i].y){
      Message("Концентратор совпал с существующем");
      Ev.setevent(cmDraft);return 1;}

con[ncon].x=imin; con[ncon].y=jmin;

for(i=0;i<too.number;i++)
  if(ci[i]==imin && di[i]==jmin){
    con[ncon].npoint=i;
    too.ncentre+=1;
    break;                    }


sprintf(string,"Установлен концентратор %d",ncon);
con[ncon].flag=Yes;
ncon++;

DeskTopPrint(string);
setcolor(LIGHTBLUE);  setfillstyle(CLOSE_DOT_FILL,LIGHTBLUE);
fillellipse(imin,jmin,3,3);
flagworking=cmNo;
return 1;
			  }

int cSub::unsetcon(void){
if(ncon<=0){DeskTopPrint("Удаление невозможно !!!");
	     n=too.number;ncon=0; return 0;}

int i,j=ncon;
float len,min=3.0;
for(i=0;i<ncon;i++){
len=hypot(float(imin-con[i].x),float(jmin-con[i].y));
if(len<min){j=i;min=len;}
			  }
if(j==ncon){DeskTopPrint("Концентратор  не найден ");return 0;}

			 // j - номер удаляемого ц.к.

flagworking=cmNo;
ncon--;
con[j]=con[ncon];

DeskTopPrint("Концентратор удален");
return 1;
				      }

void cSub::calc(void){
int i,j=ncon;

long double dlins=0.0;
long double podl=3.0;
double ax,ay;
int fo=0;
long sdl=0;

Wait myxa('T');

for(i=0;i<ncon;i++){
dlins=hypot(float(imin-con[i].x),float(jmin-con[i].y));
if(dlins<podl){j=i;podl=dlins;}
		    }
if(j==ncon){DeskTopPrint("Концентратор не найден");return;}
dlins=podl=0.0;
myxa.tik(0);


dlins=hypot(c[too.centre[0]]-too.mashtx*con[j].x/sizeX,\
	    d[too.centre[0]]-too.mashty*con[j].y/(sizeY-sizeDy));

for(i=0;i<too.number;i++)
if(i!=con[j].npoint){
ax=hypot(c[i]-too.mashtx*con[j].x/sizeX,\
	 d[i]-too.mashty*con[j].y/(sizeY-sizeDy));

ay=hypot(c[i]-c[too.centre[0]],d[i]-d[too.centre[0]]);
if(ax<ay){
fo++;podl+=ax;sdl+=em[i];
	 }
if(!(i && (i%500)))myxa.tik(((float(i)*100)/too.number));
		 }

sprintf(string," Растояние концентратора до ЦК :%.3Lf km\n"
	       "  Предполагаемое число станций  : %d \n"
	       "  Суммарное растояние до станций: %.3Lf km\n"
	       "  Суммарный поток от станций    : %Ld",dlins,fo,podl,sdl);
Message(string);
			   }

void cSub::draft(void){
int i,j;
menu->status=stSelect;

Modals::draft();

if(massiv && conbegin!=ncon ){delete massiv;massiv=NULL;
for(i=0;i<CON;i++)con[i].flag=Yes;
}

if(modedraft==Yes){
 setcolor(KNOW.colorweb);
 for(i=0;i<16;i++)for(j=0;j<20;j++)
 if(sem[i*20+j]!=0) {sprintf(string,"%Ld",sem[i*20+j]);
  outtextxy(j*sizeX/20+sizeX/80,(14-i)*(sizeY-sizeDy)/15+sizeY/40, string);
		    }

		  }
setcolor(LIGHTRED);  setfillstyle(CLOSE_DOT_FILL,LIGHTRED);
fillellipse(ci[too.centre[0]],di[too.centre[0]],3,3);
setcolor(LIGHTBLUE);  setfillstyle(CLOSE_DOT_FILL,LIGHTBLUE);
for(i=0;i<ncon;i++)
  if(con[(int)i].flag==Yes)fillellipse(con[i].x,con[i].y,3,3);

if(massiv==NULL)return;
    setcolor(WHITE);         //Отображаем на экране
Masint& mas=*massiv;
int x;
 for(i=0;i<n;i++){
   x=mas[(long)i*(ncon+2)+ncon+1];
   if(x<ncon)line(ci[(int)i],di[(int)i],con[x].x,con[x].y);
   if(x==ncon) line(ci[(int)i],di[(int)i],ci[too.centre[0]],di[too.centre[0]]);
		  }
     setcolor(RED);
 for(j=0;j<ncon;j++)
  if(con[j].flag==Yes)
    line(con[j].x,con[j].y,ci[too.centre[0]],di[too.centre[0]]);
char string[80];
 sprintf(string,"Цена сети :%.3f",cena);
 LinePrint(string);
		    }

void cSub::setperek(char a){
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
