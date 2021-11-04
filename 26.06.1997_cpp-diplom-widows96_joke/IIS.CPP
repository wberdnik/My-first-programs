#include <math.h>
#define  MATHH

#include"iis.hpp"

#include"diagnost.hpp"
#include"button.hpp"
#include"tkeys.h"
#include"iistol.h"
#include"desktop.hpp"
#include"group.hpp"
#include"linebar.hpp"
#include"function.hpp"
#pragma hdrstop


//  ************    endsym  **********************
const double wx=1.0000001*sizeX/20;
const double wy=1.0000001*(sizeY-sizeDy)/15;


extern int maxstation;
extern char* linebar;

extern "C" {
	    unsigned long farcoreleft(void);
	    int memcmp(const void *s1, const void *s2, size_t n);
	   };



Iistol::Iistol():Modals(){
 flagworking=cmBreak;
 maxstation=(int)((farcoreleft()-10000L)/14 )-1;
 if(maxstation>65535L/4)maxstation=int (65535L/4);

 File* file =new File("netcad.sum");

 if(file->end>sizeof(strCentre)+sizeof(strDlins)) LoadAdd(*file);
 else
  {
   Message("Нет информации о суммарной сети");
   delete file;
   return;
  }
 delete file;

 if( flagworking==cmBreak) return;


  too=centr.station;   // копируем структуры
  too.number=moi.number;
  n=moi.number;

Wait *myxa=new Wait('T');
int k;
int x,y;
for(k=0;k<300;k++)sem[k]=0;
myxa->tik(1);
 for(k=0;k<n;k++){
 if(k && (k%1000)==0)myxa->tik(((float(k)*99)/n));
  x=(int)ceil(ci[k]/wx-1);  x=x>0?x:0;
  y=(int)ceil(di[k]/wy-1);  y=y>0?y:0;
  sem[20*(14-y)+x]+=em[k];
		}
myxa->tik(100);
delete myxa;

 file =new File("netcad.iis");
 if(file->end==sizeof(strCentre)+sizeof(strIIS))
   LoadIis(*file);
 else
  niis=0;
 delete file;


 SetBorder();
 setbase(border);
 setcls(new Worknet());
 insert(menu=new Group);
 int down=sizeY-sizeDy;

 menu->master(new MasterButton(cmNo,"Meню",kbAltM,"Меню"));// кнопка
 menu->insert(new LineBar(1,down-91,140,cmInfo, 1101,"Информ.",kbCtrlI));
 menu->insert(new LineBar(1,down-81,140,cmSaveas, 1101,"Сохранить",kbCtrlV));
 menu->insert(new LineBar(1,down-71,140,cmAuto, 1101,"Авто.",kbCtrlA));
 menu->insert(new LineBar(1,down-61,140,cmB3, 1101,"Связи выкл",kbCtrlC));
 menu->insert(new LineBar(1,down-51,140,cmView, 1101,"Поток выкл",kbCtrlP));
 menu->insert(perek[0]=new LineBar(1,down-41,140,cmB1, 1101,"Удалить",\
								   kbCtrlS));
 menu->insert(perek[1]=new LineBar(1,down-31,140,cmB2, 1101,"Установить *",\
								   kbCtrlU));
 menu->insert(new LineBar(1,down-21,140,cmFreeDraft, 11,"Обновить",kbCtrlR));
 menu->insert(new LineBar(1,down-11,140,cmQuit, 1101,"Выход",kbCtrlQ));
 menu->setbase(new Ramka(0,down-92,142,82));
 insert(new DeskTop(cmPoint,*this));
 mode=Yes;         //set
 modedraft=No;
 modeline1=No;

				    }

Iistol::~Iistol(){
if(flagworking==cmBreak) return;
if(flagworking==cmSaveas) hSave();
if(sum_set){ sum_set=mai.destroy(sum_set);}
if(cent) { delete cent;  cent=NULL;}
		 }


void Iistol::LoadAdd(File& a) {

LinePrint("Загрузка исходных данных");

   a%(sizeof(strCentre));
   a[0]>>(void*)&centr;
   a%1+=sizeof(strCentre);     // информация о центрах


   a%(sizeof(strDlins));       // идентификатор матриц длин
   a[0]>>(void*)&moi;
   a%1+=(sizeof(strDlins));

 if(centr.station.number!=moi.number)
  {
   Message("Информация о суммарной сети ошибочная");
   flagworking=cmBreak;
   return;
  }

   flagworking=cmLoad;

   c=new float[moi.number];
   d=new float[moi.number];
   ci=new int[moi.number];
   di=new int[moi.number];
   em=new int[moi.number];

   a%(moi.number*4);
   a[0]>>(void*)c;  a.tik(1);    a[1]>>(void*)d;  a.tik(1);
   (a%1)+=(moi.number*4);         a+=(moi.number*4);

   a%(moi.number*2);
   a[0]>>(void*)ci; a.tik(1);   a[1]>>(void*)di;  a.tik(1);
   a[2]>>(void*)em;  a.tik(1);
   (a%1)+=(moi.number*2);        a+=(moi.number*2);
   a+=(moi.number*2);

   cent=new int[centr.station.ncentre];
   a%(centr.station.ncentre*2);
   a[0]>>(void*)cent; a.tik(1);
   (a%1)+=(centr.station.ncentre*2);



    // открытие виртуального окна

   sum_set=mai.myalloc((v_size)moi.number*moi.number,sizeof(int));

   int hlam;
   a%2;  mai(sum_set,sizeof(int));
   unsigned long i;

   for(i=0;i<(unsigned long)moi.number*moi.number;i++){
    a[i]>>(void*)&hlam; mai[i]<<hlam;
    if(!(i%100))a.tik(99*i/((v_size)moi.number*moi.number));}

   for(i=0;i<moi.number;i++) a+=moi.number;   // корректировка заголовка
   a.tik(100);

  }



int Iistol::sys(){
static int last=n;
switch(Ev.press){

 case cmB1: case cmB2 : setperek(Ev.press); return 1;

 case cmInfo :   LineYesNo("Укажите где находятся испытательно-измерительные столы");


 case cmFreeDraft:  draft();return 1;

 case cmSaveas : hSave();draft();return 1;

 case cmAuto  :  setiis();draft();return 1;

 case cmView  :    if(modedraft){modedraft=No;linebar="Поток выкл";}
		    else{modedraft=Yes;linebar="Поток вкл";}
		  Ev.setevent(cmLineBar);
				return 1;

 case cmB3  :    if(modeline1){modeline1=No;linebar="Связи выкл";}
		    else{modeline1=Yes;linebar="Связи вкл";}
		  Ev.setevent(cmLineBar);
				return 1;

 case cmPoint :    imin=Ev.x;jmin=Ev.y;
		   switch(mode){
		   case Yes       : if(setcentre())break; return 1;
		   case No        : if(unsetcentre())break;return 1;
		   default        : mode=Yes;
			       }
		   break;


	       }
 return 0;
 }



void Iistol::draft(void){
menu->status=stSelect;
Modals::draft();
int hlam;
int i,j;
LinePrint("Ж Д И Т Е ");

if(modeline1==Yes){
setcolor(YELLOW);
for(i=0;i<moi.number-1;i++)
  for(j=i+1;j<moi.number;j++)
   {
    mai(sum_set,sizeof(int))[(v_size)i*moi.number+j]>>hlam;
    if(hlam>0) line(ci[i],di[i],ci[j],di[j]);
   }
		  }

  setcolor(LIGHTRED);  setfillstyle(CLOSE_DOT_FILL,LIGHTRED);
for(i=0;i<centr.station.ncentre;i++)
  fillellipse(ci[cent[i]],di[cent[i]],3,3);


setcolor(LIGHTBLUE);  setfillstyle(CLOSE_DOT_FILL,LIGHTBLUE);
for(i=0;i<niis;i++)
  fillellipse(ci[stol.number[i]],di[stol.number[i]],3,3);

if(modedraft==Yes){
 setcolor(KNOW.colorweb);
 for(i=0;i<16;i++)for(j=0;j<20;j++)
 if(sem[i*20+j]!=0) {sprintf(string,"%Ld",sem[i*20+j]);
  outtextxy(j*sizeX/20+sizeX/80,(14-i)*(sizeY-sizeDy)/15+sizeY/40, string);
		    }
		  }


			 }



void Iistol::setperek(int a){
char i=0;

for(char j=0;j<2;j++){
if(!j)
switch(a){
   case cmB1 : linebar="Удалить    *"; i=0;mode=No;break;
   case cmB2 : linebar="Установить *"; i=1;mode=Yes;break;
	 }
else
switch(mode){
   case Yes : linebar="Удалить";i=0;break;
   case No  : linebar="Установить";i=1;break;
	    }
Ev.flag=eSys;Ev.press=cmLineBar;
menu->movefirst(perek[i]);menu->handlevent();
		     }
menu->movefirst(perek[mode?1:0]);
Ev.flag=0;
}


int Iistol::setcentre(void){
if(niis>=20){
DeskTopPrint("Установка новых испытытательно-измерительных столов невозможна !!!");
niis=20;return 0;}
if(tr3==-1||tr3>moi.number){LinePrint("Точка не найдена");return 1;}

int i;
for(i=0;i<niis;i++)
  if(imin==ci[stol.number[i]] && jmin==di[stol.number[i]]){
    Message("    Испытытательно-измерительный стол совпал\n"
	    "               с существующим");
    Ev.setevent(cmDraft);return 1;}

int p;
if(mode==Yes){// Вводим линию
p=(int)LineInput("Введите количество контрольных генераторов");
	     }

stol.number[niis]=tr3;
stol.signal[niis]=p;
niis+=1;

sprintf(string,"Установлен испытытательно-измерительный стол %d",niis);
DeskTopPrint(string);
setcolor(LIGHTBLUE);  setfillstyle(CLOSE_DOT_FILL,LIGHTBLUE);
fillellipse(imin,jmin,3,3);
flagworking=cmSaveas;

return 0;
			  }



int Iistol::unsetcentre(void){
if(niis<=0){DeskTopPrint("Удаление невозможно !!!");
		   niis=0; return 0;}
int i,j=niis;
float len,min=3.0;
for(i=0;i<niis;i++){
len=hypot(float(imin-ci[stol.number[i]]),float(jmin-di[stol.number[i]]));
if(len<min){j=i;min=len;}
			  }
if(j==niis){DeskTopPrint(" Станция не найдена ");return 0;}

			 // j - номер удаляемого ц.к.


flagworking=cmSaveas;
setcolor(BLACK);  setfillstyle(CLOSE_DOT_FILL,BLACK);
fillellipse(ci[stol.number[j]],di[stol.number[j]],3,3);

putpixel(ci[stol.number[j]],di[stol.number[j]],YELLOW);

stol.number[j]=stol.number[niis-1];
stol.signal[j]=stol.signal[niis-1];
niis--;

setcolor(LIGHTBLUE);  setfillstyle(CLOSE_DOT_FILL,LIGHTBLUE);
for(i=0;i<niis;i++)
  fillellipse(ci[stol.number[i]],di[stol.number[i]],3,3);

DeskTopPrint("Удалена станция");
return 0;
				      }



void Iistol::hSave(void){
   unlink("netcad.iis");
   File& a =*new File("netcad.iis");
   LinePrint("Запись параметров испытательно-измерительных столов");
   a.tik(1);
   a%sizeof(strCentre);
   a+1;
   a[0]=(void*)&centr;
   a+=1;

   stol.kol=niis;
   a%sizeof(strIIS);
   a+1;
   a[0]=(void*)&stol;
   a+=1;

   delete &a;


   //Текстовый файл

   unlink("netiis.txt");
   FILE* file =fopen("netiis.txt","wt");
   Wait wait('T');
   wait.tik(1);
   sprintf(string,"%s\n","\nВремя создания файла станций:");
   fprintf(file,string);
   sprintf(string,"год - %d\tдень - %d\tмесяц - %d\n",centr.station.gdate2.da_year,\
   centr.station.gdate2.da_day,centr.station.gdate2.da_mon);
   fprintf(file,string);

   wait.tik(1);
   sprintf(string,"час - %d\tмин.- %d\tсек. - %d\n",centr.station.gtime2.ti_hour,\
   centr.station.gtime2.ti_min,centr.station.gtime2.ti_sec);
   fprintf(file,string);

   gettime(&(tnaw));
   getdate(&(dnaw));


   wait.tik(1);
   sprintf(string,"%s\n","\nВремя создания испытательно-измерительных столов:");
   fprintf(file,string);
   sprintf(string,"год - %d\tдень - %d\tмесяц - %d\n",dnaw.da_year,\
   dnaw.da_day,dnaw.da_mon);
   fprintf(file,string);

   wait.tik(1);
   sprintf(string,"час - %d\tмин.- %d\tсек. - %d\n",tnaw.ti_hour,\
   tnaw.ti_min,tnaw.ti_sec);
   fprintf(file,string);


   wait.tik(1);

   wait.tik(1);
   sprintf(string,"%s\n","\nИспытательно-измерительные столы");
   fprintf(file,string);
   sprintf(string,"%s\n","\nСтол\t\tНомер\t\tСигналы\n");
   fprintf(file,string);

   for(int i=0;i<niis;i++)
    {
      sprintf(string,"%d\t\t%d\t\t%d\n",i+1,stol.number[i]+1,stol.signal[i]);
      fprintf(file,string);
    }


   fclose(file);
//   delete file;

   LinePrint("Запись текстового файла");
   SaveTxt();
}


void Iistol::SaveTxt(void) {
   sprintf(string,"iiscad.txt");
   unlink(string);
   FILE* file =fopen(string,"wt");
   Wait wait('T');
   wait.tik(1);
   sprintf(string,"\nВремя создания файла станций:\n");
   fprintf(file,string);
   sprintf(string,"год - %d\tдень - %d\tмесяц - %d\n",centr.station.gdate2.da_year,\
   centr.station.gdate2.da_day,centr.station.gdate2.da_mon);
   fprintf(file,string);

   wait.tik(1);
   sprintf(string,"час - %d\tмин.- %d\tсек. - %d\n",centr.station.gtime2.ti_hour,\
   centr.station.gtime2.ti_min,centr.station.gtime2.ti_sec);
    fprintf(file,string);

   gettime(&(tnaw));
   getdate(&(dnaw));


   wait.tik(1);
   sprintf(string,"%s\n","\nВремя создания испытательно-измерительных столов:");
   fprintf(file,string);
   sprintf(string,"год - %d\tдень - %d\tмесяц - %d\n",dnaw.da_year,\
   dnaw.da_day,dnaw.da_mon);
   fprintf(file,string);


   wait.tik(1);
   sprintf(string,"час - %d\tмин.- %d\tсек. - %d\n",tnaw.ti_hour,\
   tnaw.ti_min,tnaw.ti_sec);
   fprintf(file,string);

   wait.tik(1);
   sprintf(string,"%s\n","\n\t\tКоординаты узлов");
   fprintf(file,string);
   sprintf(string,"%s\n","\nШкаф\t\tX\t\tY\n");
   fprintf(file,string);

   for(int i=0;i<moi.number;i++)
    {
      sprintf(string,"%d\t%d(%.3f)\t%d(%.3f)\n",i+1,(int)ci[i],(float)c[i],\
      (int)di[i],(float)d[i]);
      fprintf(file,string);
      if(!(i%25))wait.tik(29*i/moi.number);
    }


   wait.tik(1);
   sprintf(string,"%s\n","\nНомера центров коммутации");
   fprintf(file,string);
   sprintf(string,"%s\n","\nЦентр\t\tНомер\n");
   fprintf(file,string);

   for(i=0;i<centr.station.ncentre;i++)
    {
      sprintf(string,"%d\t\t%d\n",i+1,cent[i]+1);
      fprintf(file,string);
    }


   wait.tik(1);
   sprintf(string,"\n%s\n","[Данные о связности]");
   fprintf(file,string);
   sprintf(string,"%s\n","Шкаф1\tШкаф2\t\tДлина   Емк-ть\n");
   fprintf(file,string);
   int hlam,hlam2,k=0;
   for(i=0;i<moi.number-1;i++)
     for(int j=i+1;j<moi.number;j++)
       {
	mai(sum_set,sizeof(int))[(v_size)i*moi.number+j]>>hlam;
	mai(sum_set,sizeof(int))[(v_size)j*moi.number+i]>>hlam2;
	if(hlam!=0)
	 {
	  sprintf(string,"%d\t%d\t\t%d\t%d\n",i+1,j+1,hlam2,hlam);
	  fprintf(file,string);
	 }
	if(k==30)
	 {
	  wait.tik(40*((v_size)i*moi.number+j)/((v_size)moi.number*moi.number)+29);
	  k=0;
	 }
	else
	 k++;
       }

   sprintf(string,"\n%s\n","[Данные об УКУСах]");
   fprintf(file,string);
   sprintf(string,"%s","# Шкафа\tКол-во КГ\n");
   fprintf(file,string);
   for(i=0;i<niis;i++)
    {
     sprintf(string,"%d\t\t%d\n",stol.number[i]+1,stol.signal[i]);
     fprintf(file,string);
    }


   wait.tik(69);
   sprintf(string,"\n%s\n","[Данные о шкафах]");
   fprintf(file,string);
   sprintf(string,"%s\n","Шкаф   Коробок\n");
   fprintf(file,string);

   for(i=0;i<moi.number;i++)
    {
     sprintf(string,"%d\t%d\n",i+1,em[i]);
     fprintf(file,string);
     if(!(i%25))wait.tik(30*i/moi.number+69);
    }

   fclose(file);

  }


void Iistol::LoadIis(File& a) {

LinePrint("Загрузка исходных данных");

   a%(sizeof(strCentre));
   a[0]>>(void*)&centr1;
   a%1+=sizeof(strCentre);     // информация о центрах

   a%(sizeof(strIIS));       // идентификатор матриц длин
   a[0]>>(void*)&stol;
   a%1+=(sizeof(strIIS));

   if(!memcmp(&centr.station.gtime,&centr1.station.gtime,\
   sizeof(struct time))&&!memcmp(&centr.station.gdate,&centr1.station.gdate,\
   sizeof(struct date)))
      niis=stol.kol;
   else
      niis=0;

  }


int Iistol::setiis(void){
 int p;
 if(!yesno("Вы выбрали опцию меню автоматической расстановки\n"
	   "испытательно - измерительных  столов.    Все\n"
	   "установленные  ранее   столы  аннулируются.\n"
	   "        Вы желаете продолжить дальше ?")) return 1;

 draft();
 p=(int)LineInput("Введите количество ИИС");
 if(p<=0||p>20||p>moi.number)
   {
    Message("Количество испытательно-измерительных столов\n"
	    "            введено неправельно!!!");
    return 1;
   }
 niis=0;
 draft();

 placenum=new int[moi.number];
 for(int i=0;i<moi.number;i++)
   placenum[i]=i;

 int min, max, imin, imax;
 int b;


 if(p>1)
  {
   for(i=0;i<moi.number/2;i++)
    {
     imin=i;
     imax=i;
     min=ci[placenum[i]];
     max=ci[placenum[i]];
     for(int j=i+1;j<moi.number-i;j++)
      {
       if(min>ci[placenum[j]])
	{
	 imin=j;
	 min=ci[placenum[j]];
	}

       if(max<ci[placenum[j]])
	{
	 imax=j;
	 max=ci[placenum[j]];
	}
      }


     if(placenum[imax]==placenum[i])
       imax=imin;

     b=placenum[i];
     placenum[i]=placenum[imin];
     placenum[imin]=b;

     b=placenum[moi.number-i-1];
     placenum[moi.number-i-1]=placenum[imax];
     placenum[imax]=b;
    }

   int k;
   k=moi.number/p;
   if(moi.number>p*k)
     k++;
   home=0;
   end=k-1;
   for(i=0;i<p-1;i++)
    {
     poiskcent();
     home=end+1;
     end=end+k;
    }
   end=moi.number-1;
   poiskcent();
  }
 else
  {
   home=0;
   end=moi.number-1;
   poiskcent();
  }

 flagworking=cmSaveas;


 delete placenum;
return 1;
			}

void Iistol::poiskcent(void){
unsigned long x;
unsigned long y;
x=0;
y=0;
unsigned long func,func2,old;

for(int i=home;i<=end;i++)
  {
   x+=ci[placenum[i]];
   y+=di[placenum[i]];
  }
x/=(end-home+1);
y/=(end-home+1);

setcolor(YELLOW);  setfillstyle(CLOSE_DOT_FILL,LIGHTBLUE);
fillellipse((int)x,(int)y,3,3);

func=0;
func2=0;
int ix,iy;
for(i=home;i<=end;i++)
 {
  func+=abs((int)x-ci[placenum[i]]);
  func+=abs((int)y-di[placenum[i]]);
 }

do{
ix=1;
	 //x
for(i=home;i<=end;i++)
 {
  func2+=abs((int)x+ix-ci[placenum[i]]);
  func2+=abs((int)y-di[placenum[i]]);
 }


if(func2>func)
 {
  func2=0;
  ix=-1;
  for(i=home;i<=end;i++)
   {
    func2+=abs((int)x+ix-ci[placenum[i]]);
    func2+=abs((int)y-di[placenum[i]]);
   }
 }

if(func2<func)
  x+=ix;

old=func;

while(func>func2)
 {
  x+=ix;
  old=func;
  func=func2;
  func2=0;
  for(i=home;i<=end;i++)
   {
    func2+=abs((int)x-ci[placenum[i]]);
    func2+=abs((int)y-di[placenum[i]]);
   }

 }


     //y
  func2=0;
  iy=1;
for(i=home;i<=end;i++)
 {
  func2+=abs((int)x-ci[placenum[i]]);
  func2+=abs((int)y+iy-di[placenum[i]]);
 }

if(func2>func)
 {
  func2=0;
  iy=-1;
  for(i=home;i<=end;i++)
   {
    func2+=abs((int)x-ci[placenum[i]]);
    func2+=abs((int)y+iy-di[placenum[i]]);
   }
 }

if(func2<func)
  y+=iy;

old=func;

while(func>func2)
 {
  y+=iy;
  old=func;
  func=func2;
  func2=0;
  for(i=home;i<=end;i++)
   {
    func2+=abs((int)x-ci[placenum[i]]);
    func2+=abs((int)y-di[placenum[i]]);
   }

 }
}while(abs((int)old-(int)func)>1);

setcolor(GREEN);  setfillstyle(CLOSE_DOT_FILL,LIGHTBLUE);
fillellipse((int)x,(int)y,3,3);

int dlinmin;
int hlam, ihlam;
dlinmin=(int)hypot((int)x-ci[placenum[home]],(int)y-di[placenum[home]]);
ihlam=home;

for(i=home+1;i<=end;i++)
  {
   hlam=hypot((int)x-ci[placenum[i]],(int)y-di[placenum[i]]);
   if(dlinmin>hlam)
    {
     dlinmin=hlam;
     ihlam=i;
    }
  }
setcolor(BLUE);  setfillstyle(CLOSE_DOT_FILL,LIGHTBLUE);
fillellipse(ci[placenum[ihlam]],di[placenum[ihlam]],3,3);
stol.number[niis]=placenum[ihlam];
int kl;
kl=(int)LineInput("Введите количество контрольных генераторов");
stol.signal[niis]=kl;
niis++;

			    }