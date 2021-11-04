#include"vladik.hpp"
#include"button.hpp"
#include"tkeys.h"
#include"desktop.hpp"
#include"group.hpp"
#include"linebar.hpp"
#include"function.hpp"
#pragma hdrstop

enum{
	stNo,
	stSimple,
	stCentre,
	stConcentr,
	stQwery,
	};

extern int maxstation;
extern char* linebar;

extern "C" {
		int atoi(const char*);
		 unsigned long farcoreleft(void);
	   };



cAdd::cAdd():BaseNet(){
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
 flagworking=cmLoad;
 cost=mai.myalloc((v_size)moi.number*moi.number,sizeof(long));
 station=mai.myalloc((v_size)moi.number,sizeof(int));


  too=centr.station;   // копируем структуры
  too.number=n=moi.number;
  if(too.ncentre!=1){
       Message("Для данного пункта должен быть указан \n"
	       "только один центр коммутации");
	       return;

		    }
  Message("Построение топологической сети с активными \n"
	  "концентраторами по алгоритму \"добавления\".");

 SetBorder();
 setbase(border);
 setcls(new Worknet());
 insert(new MasterButton(cmNo,"",0,""));
 insert(new DeskTop(cmPoint,*this));
 Ev.setevent(cmLoad);
}

int cAdd::sys(void){
long i,j,k;
int x;
char* a="caddini.rpt";
switch(Ev.press){
 case cmLoad :
     LinePrint("Определение соответветствия связей и БД");

    moi(station,sizeof(int));  //инициализация матрицы станций
   for(i=0;i<moi.number;i++) moi[i]<<stNo;

   unlink(a);
   FILE* file =fopen(a,"wt");
   struct time tnam;
   struct date dnam;
   fprintf(file,"Отчет программы о выборе линий связей до"
   " установки концентраторов");
   for(int t=0;t<2;t++){
    if(!t){
    dnam=centr.station.gdate2;
    tnam=centr.station.gtime2;
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
   fprintf(file,"\nСт1\t\tСт2\t\tНазвание\n");


 Dbf& base=*new Dbf(baseCabel,"netcab.dbf");
   if(base.end==0){
	   Message("База данных по линиям связи не найдена");
	    delete &base;
	     fprintf(file,"Завершено из-за отсутствия базы данных");
	    fclose(file);
	    Ev.setevent(cmQuit);
	    return 1;    }

 setcolor(WHITE);

Wait* myxa=new Wait('T');

double coast=0;

 for(i=0;i<moi.number-1;i++)
  for(j=i+1;j<moi.number;j++){
    myxa->tik(100*(float)i/moi.number);
    mai(sum_set,sizeof(int))[i*moi.number+j]>>hlam;// нашли линию связи
    if(hlam>0) line(ci[i],di[i],ci[j],di[j]); //показали что работаем с ней

long min=0xffffffff;
long number=base.end;

    for(k=0;k<base.end;k++){             // сканируем базу данных
      base[k]>>(void*)&cabel;
      if(cabel.potok>=hlam && cabel.cena<min){ //подх кабель мин цена
       min=cabel.cena;
       number=k;                            }
			   }
 char *str=new char[50];
  sprintf(str,"Введите в базу данных в качестве последней\n"
	      "записи линию связи имеющую пропускную спосо"
	      "бность более %d ",hlam);

  if(number==base.end)                  // если кабeль не найден
   while(1){
   base[base.end-1]>>(void*)&cabel
   if(cabel.potok>=hlam){number=base.end-1;break;}
   if(!yesno(str)){
	     fprintf(file,"Завершено по желанию пользователя");
		fclose(file);delete str; delete &base;delete myxa;
		    Ev.setevent(cmQuit);return 1;}
		      //ВНИМАНИЕ
   Modals * BD=Cabel();
    delete(BD->go());
    draft();
		      }
   delete str;
					  // если кабель найден
     base[number]>>(void*)&cabel;            // устанавливаем позицию
    mai(cost,sizeof(long))[i*moi.number+j]<<number; // указываем номер кабеля
    mai(sum_set,sizeof(int))[j*moi.number+i]>>hlam;// считываем длинну связи
    min=hlam*cabel.cena;      			   //расчет стоимости связи
    coast+=(double)min;
    mai(cost,sizeof(long))[j*moi.number+i]<<min;   // записываем цену
    fprintf(file,"\n%d\t\t%d\t\t%s\n",i,j,cabel.name);


			    }  //весь цикл
     fprintf(file,"Суммарная стоимость %lf",coast);
     fclose(file);
  delete myxa;

 draft();


  LinePrint(" Поиск мест установки концентраторов");
  myxa=new Wait('F');
  mai(station,sizeof(char))[too.centre[0]]<<stCentre;

  for(i=0;i<moi.number;i++){ // для всех станций
  k=0;                       // найдено 0 станций
  myxa->tik(100*(float)i/moi.number);
  moi(station,sizeof(char))[i]>>x;
  if(x!=stNo)continue;          // если данная станция не проверялась

    for(j=0;j<moi.number;j++){ // проверяем все связи
    mai(sum.set,sizeof(int));
    if(j>i)mai[i*moi.number+j]>>hlam;
    else  mai[j*moi.number+i]>>hlam;
    if(hlam==0)continue;      // ecли связи нет то к следующей точке
     k++;		     }

   if(k<3){                  // нет развилки - нет концентратора
     mai(station,sizeof(char))[i]<<stSimple;
     continue;}
     //попытаемся установить концентратор
     x=k;
     mai(station,sizeof(int))[i]<<x+stQwery;
     outtextxy(ci[i],di[i],"?");
			   }
  delete myxa;

  LinePrint("Aлгоритм установки концентраторов ");
  myxa=new Wait('F');
  for(i=0;i<moi.number;i++){
    j=too.centre[0];            // устанавливаем от центра
    mai(sum.set,sizeof(int));
    if(j>i)mai[i*moi.number+j]>>hlam;
    else  mai[j*moi.number+i]>>hlam;
    if(hlam){                   // ecли есть связь
     mai(station,sizeof(int))[i]>>x;
      if(x>stQwery){          //пробуем установить
    mai(coast,sizeof(long));
    if(j<i)mai[i*moi.number+j];  //цену
    else  mai[j*moi.number+i];
    long mycoast;
    mai>>mycoast;
    Dbf& dbs=*new Dbf(baseConcent,"netcon.dbf");
    number=dbs.end;
    min=0xffffffff;
    for(k=0;k<dbs.end;k++){
      dbs[0]>>(void*)&concen;
      if(concen.input>=x && concen.cena<=min)






 delete myxa;
 delete &base;


}
return 0; }


// *****   далее конструктор и деструктор ***********************


void BaseNet::hSave(void){
LinePrint("Запись результатов");
char * name="netcad.sub"
unlink(name);
  File& a =*new File(name);

   a.tik(0);
   a%(sizeof(strCentre));
   a.toend(0,(void*)&centr);
   a%1+=sizeof(strCentre);     // информация о центрах


   a%(sizeof(strDlins));       // идентификатор матриц длин
   a.toend(0,(void*)&moi);
   a%1+=(sizeof(strDlins));

   a%(moi.number*4);
   a.toend(0,(void*)c);     a.toend(1,(void*)d);
   (a%1)+=(moi.number*4);         a+=(moi.number*4);

   a%(moi.number*2);
   a.toend(0,(void*)ci); a.tik(1);   a.toend(1,(void*)di);  a.tik(1);
   a.toend(2,(void*)em);  a.tik(1);
   (a%1)+=(moi.number*2);  a+=(moi.number*2);  a+=(moi.number*2);

   cent=new int[centr.station.ncentre];
   a%(centr.station.ncentre*2);
   a.toend(0,(void*)cent); a.tik(2);
   (a%1)+=(centr.station.ncentre*2);

   const unsigned long max=moi.number*moi.number;
   int hlam;long k=0;
   a%2;mai(sum_set,sizeof(int));
   for(int i=0;i<moi.number;i++)
     for(int j=0;j<moi.number;j++){
	moi[(v_size)i*moi.number+j]>>hlam;
	a.toend(0,(void*)&hlam);a+=1;
	if(!(k%25))a.tik(100*(k/max);
	 k++;
       }

   delete &a;

}





cAdd::~cAdd(){
if(flagworking==cmLoad) hSave();
if(flagworking==cmNo||flagworking==cmLoad)
 {
  if(sum_set){ sum_set=mai.destroy(sum_set);}
  if(cost){cost=mai.destroy(cost);}
  if(cent){ delete cent; cent=NULL;}
 }
		 }

void Vladik::draft(void){
Modals::draft();
int hlam,i,j;
LinePrint("Ж Д И Т Е ");
setcolor(YELLOW);
mai(sum_set,sizeof(int));
for(i=0;i<moi.number-1;i++)
  for(j=i+1;j<moi.number;j++){
    mai[(v_size)i*moi.number+j]>>hlam;
    if(hlam>0) line(ci[i],di[i],ci[j],di[j]);
   }
			 }


void Vladik::LoadAdd(File& a) {

LinePrint("Загрузка исходных данных");

   a%(sizeof(strCentre));
   a[0]>>(void*)&centr;
   a%1+=sizeof(strCentre);     // информация о центрах


   a%(sizeof(strDlins));       // идентификатор матриц длин
   a[0]>>(void*)&moi;
   a%1+=(sizeof(strDlins));

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





