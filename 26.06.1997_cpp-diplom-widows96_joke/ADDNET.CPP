#include"addnet.hpp"
#include"tkeys.h"
#include"math.h"
#include"iistol.h"
#include"button.hpp"
#include"function.hpp"
#include"desktop.hpp"

#define MS 7
int* mass_set;

extern "C"{
	 unsigned long farcoreleft(void);
	 int memcmp(const void *s1, const void *s2, size_t n);
	   };



Addnet::Addnet():Modals(){
maxstation=(int)((farcoreleft()-10000L)/14);
if(maxstation>65535L/4)maxstation=int (65535L/4);

flagworking=cmNo;
char * text;

File* file =new File("netcad.n0");
if(file->end>=(2+sizeof(strCentre))){LoadAdd(*file);}
else
    {
      Message(" Файла подсети не существует");
      flagworking=cmBreak;
      delete file;
      return;
    }
delete file;

if(LoadAllStn(5*(kol+1)))return;


if(memcmp(&too.gdate2,&centr.station.gdate2,\
  sizeof(struct date))  || memcmp(&too.gtime2,&centr.station.gtime2,\
  sizeof(struct time))){
	 text="Файл подсети не соответствует файлу станций"
	       "\n    Дальнейшая работа не возможна ! ";;
	 flagworking=cmBreak;
		       }


if(flagworking==cmNo && too.number<5){
		     text="    Количество станций меньше чем пять.\n"
			  "    Дальнейшая работа не возможна ! ";
		  flagworking=cmBreak;
		};

if(flagworking==cmBreak){Message(text);return;};

net=centr.station.number-centr.station.add+5*(kol+1);
myd=new float[(kol+1)*5];
myc=new float[(kol+1)*5];
myi=new int[(kol+1)*5];
cent=new int[(kol+1)*5];
sum_set=mai.myalloc((v_size)net*net,sizeof(int));
if(!mai(sum_set))printf("\n Ошибка выделения памяти");

add=0;
ncent=0;


 int i;
 for(i=0;i<net;i++)
  for(int j=0;j<net;j++)
    mai(sum_set,sizeof(int))[(ulong)i*net+j]<<0;

 if(kol!=0) movekoord();

 int kol1=kol;
 kol2=kol;


 draftnet();

 sprintf(string,"Подсеть N %d",1);
 LinePrint(string);

 centredraft();
 move();
 sumnet();
 LineYesNo("Нажмите любую клавишу");

 for(i=1;i<kol1+1;i++)
   {
    sprintf(string,"netcad.n%d",i);
    file =new File(string);
    if(file->end<2)
      {
	 text="  Неправильная информация в файле netcad.n0"
	       "\n    Дальнейшая работа не возможна ! ";
	 flagworking=cmBreak;
      }
    else
      LoadAdd(*file);
    delete file;
    if(memcmp(&too.gdate2,&centr.station.gdate2,\
       sizeof(struct date))  || memcmp(&too.gtime2,&centr.station.gtime2,\
       sizeof(struct time))){
	 text="           Сбой модуля"
	       "\n    Дальнейшая работа не возможна ! ";
	 flagworking=cmBreak;
		       }
    if(flagworking==cmBreak){Message(text);return;};
    movekoord();
//    draftnet();
    centredraft();
    sprintf(string,"Подсеть N %d",i+1);
    LinePrint(string);
    move();
    sumnet();
   LineYesNo("Нажмите любую клавишу");
   }

   ncent=add;
  for(int ji=0;ji<ncent;ji++)
   {
    c[myi[ji]]=myc[ji];
    d[myi[ji]]=myd[ji];
    ci[myi[ji]]=myc[ji]*sizeX/too.mashtx;
    di[myi[ji]]=myd[ji]*sizeY/too.mashty;
    cent[ji]=myi[ji];
   }

 for(i=0;i<kol1+1;i++)
   {
    sprintf(string,"netcad.n%d",i);
    file =new File(string);
    if(file->end<2)
      {
	 text="  Неправильная информация в файле netcad.n0"
	       "\n    Дальнейшая работа не возможна ! ";
	 flagworking=cmBreak;
      }
    else
      LoadAdd(*file);
    delete file;
    if(memcmp(&too.gdate2,&centr.station.gdate2,\
       sizeof(struct date))  || memcmp(&too.gtime2,&centr.station.gtime2,\
       sizeof(struct time))){
	 text="           Сбой модуля"
	       "\n    Дальнейшая работа не возможна ! ";
	 flagworking=cmBreak;
		       }
    if(flagworking==cmBreak){Message(text);return;};

    AddKoor();
   }
 moi.number=centr.station.number-centr.station.add+add;
 SumNet();

 unlink("netcad.sum");
 file =new File("netcad.sum");
 LinePrint("Запись суммарной сети");
 SaveAdd(*file);
 delete file;

 LinePrint("Запись текстового файла");
 SaveTxt();
			      }


Addnet::~Addnet(){
if(mass_set){ delete mass_set; mass_set=NULL;}
if(myd){ delete myd; myd=NULL;}
if(myc){ delete myc; myc=NULL;}
if(myi){ delete myi; myi=NULL;}
if(cent){ delete cent; cent=NULL;}
if(sum_set){ sum_set=mai.destroy(sum_set);}
	       }

void Addnet::LoadAdd(File& a){
ulong ctr;
   a%2;
   a[0]>>(void*)&kol;
   a%1+=2;

   a%(sizeof(strCentre));
   a[0]>>(void*)&centr;
   a%1+=sizeof(strCentre);

   a%(sizeof(strDlins));
   a[0]>>(void*)&moi;
   a%1+=(sizeof(strDlins));

   if(mass_set==NULL)
     mass_set=new int[(centr.station.number-centr.station.add+5)*MS];

   ctr=((v_size)centr.station.number*MS*2);
   if(ctr>0xffff)error("Преобразование в addnet привело к сбою");
   a%(unsigned)ctr;
   a[0]>>(void*)mass_set;
  }

void Addnet::movekoord(void)
  {
   if(centr.station.add!=0)
     for(int i=0;i<centr.station.ncentre;i++)
       if(centr.station.centre[i]>=centr.station.number-centr.station.add)
	{
	  c[centr.station.centre[i]]=centr.c[i];
	  d[centr.station.centre[i]]=centr.d[i];
	  ci[centr.station.centre[i]]=centr.ci[i];
	  di[centr.station.centre[i]]=centr.di[i];
	}
  }

void Addnet::centredraft(void)
 {
  setcolor(LIGHTRED);  setfillstyle(CLOSE_DOT_FILL,LIGHTRED);
  for(int i=0;i<centr.station.ncentre;i++)
    fillellipse(ci[centr.station.centre[i]],di[centr.station.centre[i]],3,3);
 }

float Addnet::fromto(int fr,int to)
 {
//    fillellipse(ci[fr],4*sky-di[fr],5,5);
    float x,y;
    line(ci[fr],di[fr],ci[to],di[to]);
    x=(float)(ci[fr]-ci[to]);
    y=(float)(di[fr]-di[to]);
    return hypot(x,y);
 }

void Addnet::sumnet(void)
 {
  for(int i=0;i<centr.station.number;i++)
  {
    setcolor(MAGENTA);
    /*вывод красных линий*/
    if(mass_set[i*MS+(MS-6)]!=-1)
      fromto(i,mass_set[i*MS+(MS-6)]);

    setcolor(YELLOW);
    /*вывод желтых линий*/
    if(mass_set[i*MS+(MS-4)]!=-1)
      fromto(i,mass_set[i*MS+(MS-4)]);

    setcolor(BLUE);
    /*вывод синих линий*/
    if(mass_set[i*MS+(MS-2)]!=-1)
      fromto(i,mass_set[i*MS+(MS-2)]);
  }
//?

 }


void Addnet::move(void)
 {
  int j;
  int ki,kj,ji;
  int hlam=0;
  char flag;
  for(int i=0;i<centr.station.number;i++)
   {
    flag=cmLoad;
    j=i;
    if(i>=net-5*(kol2+1))
     {
      for(ji=0;ji<add+hlam;ji++)
       {
	if(myc[ji]==c[i] && myd[ji]==d[i])
	  {
	   j=myi[ji];
	   flag=cmBreak;
	  }
       }
      if(flag==cmLoad)
       {
	myc[add+hlam]=c[i];
	myd[add+hlam]=d[i];
	j=net-5*(kol2+1)+add+hlam;
	myi[ji]=j;
	hlam++;
       }
     }

    flag=cmLoad;
    /*вывод красных линий*/
    if(mass_set[i*MS+(MS-6)]!=-1)
     {
      ki=mass_set[i*MS+(MS-6)];
      kj=mass_set[i*MS+(MS-5)];
      if(ki>=net-5*(kol2+1))
       {
	for(ji=0;ji<add+hlam;ji++)
	 {
	   if(myc[ji]==c[ki] && myd[ji]==d[ki])
	    {
	     ki=myi[ji];
	     flag=cmBreak;
	     ji=add+hlam;
	    }
	 }
	if(flag==cmLoad)
	 {
	  myc[add+hlam]=c[ki];
	  myd[add+hlam]=d[ki];
	  ki=net-5*(kol2+1)+add+hlam;
	  myi[add+hlam]=ki;
	  hlam++;
	 }
       }
      mai(sum_set)[(ulong)j*net+ki]<<kj;
     }


    flag=cmLoad;
    /*вывод желтых линий*/
    if(mass_set[i*MS+(MS-4)]!=-1)
     {
      ki=mass_set[i*MS+(MS-4)];
      kj=mass_set[i*MS+(MS-3)];
      if(ki>=net-5*(kol2+1))
       {
	for(ji=0;ji<add+hlam;ji++)
	 {
	  if(myc[ji]==c[ki] && myd[ji]==d[ki])
	   {
	    ki=myi[ji];
	    flag=cmBreak;
	    ji=add+hlam;
	   }
	 }
	if(flag==cmLoad)
	 {
	  myc[add+hlam]=c[ki];
	  myd[add+hlam]=d[ki];
	  ki=net-5*(kol2+1)+add+hlam;
	  myi[add+hlam]=ki;
	  hlam++;
	 }
       }
      mai(sum_set)[(ulong)j*net+ki]<<kj;
     }

    flag=cmLoad;
    setcolor(BLUE);
    /*вывод синих линий*/
    if(mass_set[i*MS+(MS-2)]!=-1)
     {
      ki=mass_set[i*MS+(MS-2)];
      kj=mass_set[i*MS+(MS-1)];
      if(ki>=net-5*(kol2+1))
       {
	for(ji=0;ji<add+hlam;ji++)
	 {
	  if(myc[ji]==c[ki] && myd[ji]==d[ki])
	   {
	    ki=myi[ji];
	    flag=cmBreak;
	    ji=add+hlam;
	   }
	 }
	if(flag==cmLoad)
	 {
	  myc[add+hlam]=c[ki];
	  myd[add+hlam]=d[ki];
	  ki=net-5*(kol2+1)+add+hlam;
	  myi[add+hlam]=ki;
	  hlam++;
	 }
       }
      mai(sum_set)[(ulong)j*net+ki]<<kj;
     }
   }
  add+=hlam;
 }

void Addnet::draftnet(void)
 {
  n=centr.station.number;

  setcls(new Worknet());
  SetBorder();
  setbase(border);
  insert(new DeskTop(cmPoint,*this));
  flagworking=cmLoad;
  status=stFocus;
  insert(new MasterButton(cmNowork,"Меню",kbF10,"Меню"));
  draft();
 }

void Addnet::AddKoor(void)
 {
   int ji;
   char flag;


   for(int i=0;i<centr.station.ncentre;i++)
    {
     flag=cmLoad;
     for(ji=0;ji<ncent;ji++)
      {
       if(myc[ji]==c[centr.station.centre[i]]&&\
	  myd[ji]==d[centr.station.centre[i]])
	  flag=cmBreak;
      }
     if(flag==cmLoad)
      {
       cent[ncent]=centr.station.centre[i];
       myc[ncent]=c[centr.station.centre[i]];
       myd[ncent]=d[centr.station.centre[i]];
       myi[ncent]=centr.station.centre[i];
       ncent++;
      }
    }
 }


void Addnet::SaveAdd(File& a)
  {
   centr.station.ncentre=ncent;
   centr.station.number=moi.number;
   gettime(&(centr.station.gtime));
   getdate(&(centr.station.gdate));

   a%(sizeof(strCentre));
   a+1;
   a[0]=(void*)&centr;
   a%1+=sizeof(strCentre);


   a%(sizeof(strDlins));
   a+1;
   a[0]=(void*)&moi;
   a%1+=(sizeof(strDlins));

   a%(moi.number*4);
   a+2;
   a[0]=(void*)c;  a.tik(1);
   a[1]=(void*)d;  a.tik(1);
   (a%1)+=(moi.number*4);
   a+=(moi.number*4);

   int i;
   for(i=centr.station.number-centr.station.add;i<moi.number;i++)
     em[i]=0;

   a%(moi.number*2);
   a+3;
   a[0]=(void*)ci; a.tik(1);
   a[1]=(void*)di; a.tik(1);
   a[2]=(void*)em; a.tik(1);
   (a%1)+=(moi.number*2);
   a+=(moi.number*2);
   a+=(moi.number*2);

   a%(ncent*2);
   a+1;
   a[0]=(void*)cent; a.tik(1);
   (a%1)+=(ncent*2);

   int hlam;
   for(i=0;i<moi.number;i++)
     for(int j=0;j<moi.number;j++)
       {
	mai(sum_set,sizeof(int))[(v_size)i*net+j]>>hlam;
	a%2;
	a+1;
	a[0]=(void*)&hlam;
	(a%1)+=2;
	if(!(i%100))a.tik(99*((v_size)i*moi.number+j)/((v_size)moi.number*moi.number));
       }
   a.tik(100);

  }



void Addnet::SumNet(void)
  {
    int hlam, hlam2;
    for(int i=0;i<moi.number-1;i++)
      for(int j=i+1;j<moi.number;j++)
      {
       mai(sum_set,sizeof(int))[(v_size)i*net+j]>>hlam;
       mai(sum_set,sizeof(int))[(v_size)j*net+i]>>hlam2;
       hlam+=hlam2;
       hlam2=(int)hypot((c[i]-c[j])*sizeX/too.mashtx,(d[i]-d[j])*(sizeY-sizeDy)/too.mashty);
       mai(sum_set,sizeof(int))[(v_size)j*net+i]<<hlam2;
       mai(sum_set,sizeof(int))[(v_size)i*net+j]<<hlam;
      }

  }



void Addnet::SaveTxt(void){
   unlink("netcad.txt");
   FILE* file =fopen("netcad.txt","wt");
   Wait wait('T');
   wait.tik(1);
   fprintf(file,"%s\n","\nВремя создания файла станций:");
   fprintf(file,"год - %d\tдень - %d\tмесяц - %d\n",centr.station.gdate2.da_year,\
   centr.station.gdate2.da_day,centr.station.gdate2.da_mon);

   wait.tik(1);
   fprintf(file,"час - %d\tмин.- %d\tсек. - %d\n",centr.station.gtime2.ti_hour,\
   centr.station.gtime2.ti_min,centr.station.gtime2.ti_sec);

   wait.tik(1);
   fprintf(file,"%s\n","\n\t\tКоординаты узлов");
   fprintf(file,"%s\n","\nШкаф\t\tX\t\tY\n");

   for(int i=0;i<moi.number;i++)
    {
      fprintf(file,"%d\t%d(%f)\t%d(%f)\n",i+1,ci[i],c[i],di[i],d[i]);
      if(!(i%25))wait.tik(29*i/moi.number);
    }


   wait.tik(1);
   fprintf(file,"%s\n","\nНомера центров коммутации");
   fprintf(file,"%s\n","\nЦентр\t\tНомер\n");

   for(i=0;i<ncent;i++)
      fprintf(file,"%d\t\t%d\n",i+1,cent[i]+1);


   wait.tik(1);
   fprintf(file,"\n%s\n","[Данные о связности]");
   fprintf(file,"%s\n","\nШкаф1\tШкаф2\t\tДлина   Емк-ть\n");
   int hlam,hlam2,k=0;
   for(i=0;i<moi.number-1;i++)
     for(int j=i+1;j<moi.number;j++)
       {
	mai(sum_set,sizeof(int))[(v_size)i*net+j]>>hlam;
	mai(sum_set,sizeof(int))[(v_size)j*net+i]>>hlam2;
	if(hlam!=0)
	  fprintf(file,"%d\t%d\t\t%d\t%d\n",i+1,j+1,hlam2,hlam);
	if(k==30)
	 {
	  wait.tik(40*((v_size)i*moi.number+j)/((v_size)moi.number*moi.number)+29);
	  k=0;
	 }
	else
	 k++;
       }

   wait.tik(69);
   fprintf(file,"\n%s\n","[Данные о шкафах]");
   fprintf(file,"%s\n","\nШкаф   Коробок\n");

   for(i=0;i<moi.number;i++)
    {
     fprintf(file,"%d\t%d\n",i+1,em[i]);
     if(!(i%25))wait.tik(30*i/moi.number+69);
    }

   fclose(file);

  }
