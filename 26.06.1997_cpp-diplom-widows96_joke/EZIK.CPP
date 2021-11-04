#include"ezik.hpp"
#include"tkeys.h"
#include"math.h"
#include"slave.h"
#include"button.hpp"
#include"function.hpp"
#include"diagnost.hpp"
#include"desktop.hpp"
#define MS 7


extern "C"{
	 int memcmp(const void *s1, const void *s2, size_t n);
	 void *calloc(size_t nitems, size_t size);
	 unsigned long farcoreleft(void);
	   };


Ezik::Ezik():Modals(){
maxstation=(int)((farcoreleft()-10000L)/14);
if(maxstation>65535L/4)maxstation=int (65535L/4);

flagworking=cmNo;
char * text;



File* file =new File("netcad.lht");
if(file->end>=sizeof(strDlins)){
(*file)%sizeof(strDlins);
(*file)[0]>>(void*)&moi;
delete file;                   }
else
    {
      Message(" Матрицы длин не существует");
      flagworking=cmBreak;
      delete file;
      return;
    }


if(moi.modemath!=rasMathPixel){
	 text="Матрица длин должнать быть рассчитана по пикселям"
	      "\n    Дальнейшая работа не возможна ! ";
	 flagworking=cmBreak;
			      }


if(flagworking!=cmBreak)
   if(LoadAllStn(0))return;

if(flagworking==cmNo && (moi.number!=too.number ||\
  memcmp(&too.gdate,&moi.gdate,\
  sizeof(struct date))  || memcmp(&too.gtime,&moi.gtime,\
  sizeof(struct time)))){
	 text="Матрица длин не соответсвует для\n данных станций";
	 flagworking=cmBreak;
		       }


if(flagworking==cmNo && too.number<5){
		     text="    Количество станций меньше чем пять.\n";
		  flagworking=cmBreak;
		};

if(flagworking==cmNo && too.ncentre<=0){
		     text="    Не указано ни одного центра \n";
		  flagworking=cmBreak;
		}

if(flagworking==cmNo && too.ncentre>5){
		     text="    Колличество центров указано неправильно \n"
			  "    Дальнейшая работа не возможна ! ";
					  flagworking=cmBreak;
		}
if(flagworking==cmBreak){Message(text);return;};


 if(yesno("     Резервные линии строить ?")) flag5=0;
 else
    flag5=1;

 n=too.number;

 setcls(new Worknet());
 SetBorder();
 setbase(border);
 insert(new DeskTop(cmPoint,*this));
 flagworking=cmLoad;
 status=stFocus;
 insert(new MasterButton(cmNowork," ",0," "));
 draft();

 setcolor(LIGHTRED);  setfillstyle(CLOSE_DOT_FILL,LIGHTRED);
 for(int i=0;i<too.ncentre;i++)
    fillellipse(ci[too.centre[i]],di[too.centre[i]],3,3);

 m=(Mem**)calloc(too.ncentre,sizeof(Mem));

 LinePrint("Идет чтение матрицы длин");
 movematrix();

 LinePrint("Идет подготовка матрицы длин");
 preparation_matrix();

 LinePrint("Подготовка для быстрого поиска");
 training_matrix();

 /*Массив для хранениния информации об составной сети*/
 mass_set=new int[too.number*MS];
 for(i=0;i<too.number*MS;i++)
   mass_set[i]=-1;
/***********************************/

 LineYesNo("Процесс построения сети");
 search_min_2();

 unite_with_commutator_2();
 LineYesNo("Построение сети закончено");


 sprintf(string,"Длина основных  линий : %.3f \n"
	       " Длина резервных линий : %.3f \n"
	       " Сумма                 : %.3f",w,w1,w+w1);
 Message(string);

			      }


Ezik::~Ezik(){
  if(Qv )delete Qv;
  if(Qg1) delete Qg1;

  if(flagworking==cmBreak)return;

 if(yesno(" Включить получившуюся подсеть в суммарную сеть \n"))
  {
  LinePrint("Происходит запись в файл");
  for(int i=0;i<too.ncentre;i++)
   {
     centr.c[i]=c[too.centre[i]];
     centr.d[i]=d[too.centre[i]];
     centr.ci[i]=ci[too.centre[i]];
     centr.di[i]=di[too.centre[i]];
   }

  centr.station=too;

  strCentre poo;
  int kol;
  unsigned long ctr;
  File* file =new File("netcad.n0");
  if(file->end>(sizeof(strCentre)+2))
   {
    (*file)%2;
    (*file)[0]>>(void*)&kol;
    (*file)%1+=2;


    (*file)%(sizeof(strCentre));
    (*file)[0]>>(void*)&poo;
    (*file)%1+=(sizeof(strCentre));

    if(!memcmp(&poo.station.gdate2,&too.gdate2,\
       sizeof(struct date))&&!memcmp(&poo.station.gtime2,&too.gtime2,\
       sizeof(struct time))){
	kol++;
	if(kol>14)
	 {
	  if(!yesno(" Количество подсетей максимально!!!\n "
		   "Уничтожить последнюю подсеть?")) return;
	 kol=14;

	 }
	sprintf(string,"netcad.n%d",kol);
       }
    else
       {
	sprintf(string,"netcad.n0");
	kol=0;
       }
   }
  else
   {
    sprintf(string,"netcad.n0");
    kol=0;
   }
  delete file;



  unlink(string);
  file=new File(string);

  (*file)%2;
  (*file)+1;
  (*file)[0]=(void*)&kol;
  (*file)%1+=2;

  (*file)%(sizeof(strCentre));
  (*file)+1;
  (*file)[0]=(void*)&centr;
  (*file)%1+=(sizeof(strCentre));


  (*file)%(sizeof(strDlins));
  (*file)+1;
  (*file)[0]=(void*)&moi;
  (*file)%1+=(sizeof(strDlins));

   ctr=((v_size)too.number*MS*2);
   if(ctr>0xffff)error("Преобразование в addnet привело к сбою");

  (*file)%(unsigned)ctr;
  (*file)+1;
  (*file)[0]=(void*)mass_set;
  (*file)%1+=(unsigned)ctr;

  delete file;

  if(memcmp(string,"netcad.n0",10))
    {
     file =new File("netcad.n0");
     (*file)%2;
     (*file)[0]<<(void*)&kol;
     delete file;
    }
  }

  for(int i=0;i<too.ncentre;i++)
    m[i]=mai.destroy(m[i]);
  if(m) delete m;
  if(mass_set) delete mass_set;
		}


void Ezik::movematrix(void){
 const unsigned long oll=(ulong)too.number*too.number;
 int j,hlam;
 for(j=0;j<too.ncentre;j++)
  if(!( m[j]=mai.myalloc((v_size)oll,sizeof(int))))
   error("Сбой в виртуальной памяти \n"
    "Возможно мало памяти \n или места на диске");

 File& file1 =*new File("netcad.lht");
 ((file1%sizeof(strDlins))+=1)%2;
 for(ulong i=0;i<oll;i++) {
 file1[i]>>(void *)&hlam;
 for(j=0;j<too.ncentre;j++) mai(m[j])[i]<<hlam; // по всем матрицам
 if(!(i%1000))file1.tik((float)i*100/oll);
			  }
 delete &file1;
			   }



/**************   Подготовка  матрицы   *************/
void Ezik::preparation_matrix(void) {
 int hlam,hlam2;
 int j,z,i;
 int k=0;

 Wait myxa('T');
 myxa.tik(0);
 for(j=0;j<too.ncentre;j++)
  {
   for(i=0;i<too.number;i++)
    {
     k++;
     mai(m[j])[i]>>hlam;
     mai(m[j])[(v_size)too.centre[j]*too.number+i]>>hlam2;
     mai(m[j])[i]<<hlam2;
     mai(m[j])[(v_size)too.centre[j]*too.number+i]<<hlam;
     if(k==10)
      {
       myxa.tik(((float)i/too.number/too.ncentre+(float)j/too.ncentre)*20);
       k=0;
      }
    }

  }

 k=0;
 for(j=0;j<too.ncentre;j++)
  {
   for(i=0;i<too.number;i++)
    {
     k++;
     mai(m[j])[(v_size)i*too.number]>>hlam;
     mai(m[j])[(v_size)i*too.number+too.centre[j]]>>hlam2;
     mai(m[j])[(v_size)i*too.number]<<hlam2;
     mai(m[j])[(v_size)i*too.number+too.centre[j]]<<hlam;
     if(k==10)
      {
       myxa.tik(((float)i/too.number+(float)j/too.ncentre)*20+20);
       k=0;
      }

    }
  }

  k=0;
  for(z=0;z<too.ncentre;z++)
   for(i=1;i<too.number;i++)
     for(j=1;j<too.number;j++)
      {
	k++;
	if(i==j)
	 mai(m[z])[(v_size)i*too.number+j]<<0;
	else
	 {
	  mai(m[z])[(v_size)i*too.number+j]>>hlam;
	  mai(m[z])[(v_size)i*too.number]>>hlam2;
	  hlam-=hlam2;
	  mai(m[z])[(v_size)i*too.number+j]<<hlam;
	 }
       if(k==200)
	{
	 myxa.tik(((float)z/too.ncentre+(float)i/too.ncentre/too.number)*60+40);
	 k=0;
	}
      }


				    }



/* подготовка матрицы для быстрого поиска */
void Ezik::training_matrix(void){
 int hlam,hlam2,hlam3,z;
 int k;

 Wait myxa('T');
 myxa.tik(0);

 k=0;
  for(z=0;z<too.ncentre;z++)
   for(int i=1;i<too.number;i++)
    {
      mai(m[z])[i]<<i;
      for(int j=1;j<too.number;j++)
       {
	k++;
	mai(m[z])[(v_size)i*too.number+j]>>hlam;
	mai(m[z])[i]>>hlam3;
	mai(m[z])[(v_size)i*too.number+hlam3]>>hlam2;
	if(hlam<hlam2)
	  mai(m[z])[i]<<j;
	if(k==200)
	  {
	   myxa.tik(((float)z/too.ncentre+(float)i/too.ncentre/too.number)*100);
	   k=0;
	  }
       }

    }
  myxa.tik(100);

  }




     /**** очень быстрый поиск минимума *******/
 void Ezik::search_min_2(void)
  {
    int jmin_res;
    int imin_res;
    int ji,i;
    int p_imin,p_jmin;
    int* you5;
    int* imin5;
    int* jmin5;
    int* res5;
    int* jres5;
//    int flag5=1;
    int flag3=0;
    int flag4=0;
    int buf;

   w=0;  w1=0;
   Wait myxa('T');
   myxa.tik(0);

   you5=new int[too.ncentre];
   imin5=new int[too.ncentre];
   jmin5=new int[too.ncentre];
   res5=new int[too.ncentre];
   jres5=new int[too.ncentre];
   Qv=new int[too.number];
   Qg1=new int[too.number];
   for(i=0;i<too.number;i++)
     Qv[i]=0;

  for(i=0;i<too.number;i++)
    Qg1[i]=em[i];

  for(i=0;i<too.ncentre;i++)
    Qv[too.centre[i]]=-1;

   int k=0;
   myxa.tik(1);
   while(1)
    {
      flag3=1;


      k++;
     for(ji=0;ji<too.ncentre;ji++)
       {
	 you5[ji]=0;

	 buf=too.centre[ji];
	 exchange_Q(too.centre[ji]);
	 move(too.centre[ji],0);   //устанавливаем параметры
				   //первой сети

	 for_search_min(ji,you5[ji],imin5[ji],jmin5[ji]);
				   //снимаем параметры
	 move(too.centre[ji],buf);   //первой сети
	 exchange_Q(too.centre[ji]);
       }
/***********************************************************************/
     for(ji=1;ji<too.ncentre;ji++)
       {
	if((you5[ji]>you5[0]&&you5[ji]!=0)||(you5[0]==0))
	  {
	    you5[0]=you5[ji];
	    imin5[0]=imin5[ji];
	    jmin5[0]=jmin5[ji];
	    flag3=ji+1;
	  }
       }
/***********************************************************************/
     if(you5[0]==0) break; /*   а это условие выхода из цикла  */

/*  построение основной сети  */

     setcolor(YELLOW);
/**********************************************************/
     p_imin=imin5[flag3-1];
     p_jmin=jmin5[flag3-1];

	if(p_jmin==0)
	  p_jmin=too.centre[flag3-1];
	else
	  {
	   if(p_jmin==too.centre[flag3-1])
	     p_jmin=0;
	  }
	if(p_imin==too.centre[flag3-1])
	  p_imin=0;


     mass_set[p_imin*MS+(MS-4)]=p_jmin;//записали желтую линию +3
     mass_set[p_imin*MS+(MS-3)]=Qg1[p_imin];//записали обьем информации +4
/**********************************************************/
			      //устанавливаем параметры
			     //первой сети
     buf=too.centre[flag3-1];
     exchange_Q(too.centre[flag3-1]);
     move(too.centre[flag3-1],0);
     dop_Qg1(imin5[flag3-1],jmin5[flag3-1],flag3-1);
				      //снятие параметров
				      //первой сети
     move(too.centre[flag3-1],buf);
     exchange_Q(too.centre[flag3-1]);
/**********************************************************/
/*  построение резервной сети  */

     setcolor(BLUE);
/**********************************************************/
   jmin=jmin5[0];
   imin=imin5[0];

   if(flag5==0)
    {
     flag4=1;
     jmin_res=jmin;
     imin_res=imin;

     for(ji=0;ji<too.ncentre;ji++)
      {
	if(flag3!=ji+1)
	  {
	   if(jmin==too.centre[ji])
	     jmin=0;
	   for(i=0;i<too.ncentre;i++)
	     {
	       if(i!=ji)
		 {
		   if(flag3==i+1&&jmin==too.centre[i])
		     jmin=too.centre[ji];
		   if(flag3==i+1&&imin==too.centre[i])
		     imin=too.centre[ji];
		 }
	     }
	  }

	exchange_Q(too.centre[ji]);
	res5[ji]=0;
	jres5[ji]=0;

	res_nete(ji,res5[ji],jres5[ji]);
	if(res5[ji]==0&&(ji!=flag3-1||too.ncentre!=1))
	  jres5[ji]=0;
	else
	  res5[ji]=-1;
	exchange_Q(too.centre[ji]);

	jmin=jmin_res;
	imin=imin_res;
      }
/**********************************************************/
     for(ji=1;ji<too.ncentre;ji++)
       {
	if((res5[ji]>res5[0]&&res5[ji]!=0)||(res5[0]==0))
	  {
	    flag4=ji+1;
	    jres5[0]=jres5[ji];
	    res5[0]=res5[ji];
	  }
       }
/***************************************************************/
     p_jmin=jres5[0];

     if(p_jmin==0)
       p_jmin=too.centre[flag4-1];
     else
      {
       if(p_jmin==too.centre[flag4-1])
	 p_jmin=0;
      }
     mass_set[p_imin*MS+(MS-2)]=p_jmin;//записали синию линию +5
     mass_set[p_imin*MS+(MS-1)]=Qg1[p_imin];//записали обьем линию +6
/**********************************************************/
	    if(flag3!=flag4)
	      {
		for(i=0;i<too.ncentre;i++)
		  {
		    if(i!=flag4-1)
		      {
		       if((flag3==i+1&&imin==too.centre[i]))
			 imin=too.centre[flag4-1];
		      }
		  }
	      }

			       //устанавливаем параметры
			       //первой сети
	     buf=too.centre[flag4-1];
	     exchange_Q(too.centre[flag4-1]);
	     move(too.centre[flag4-1],0);

	     if(res5[flag4-1]!=0)
	       Qg1[jres5[flag4-1]]+=Qg1[imin];

	     w1+=fromto(imin,jres5[flag4-1]);
			       //снимаем параметры
			       //первой сети
	     move(too.centre[flag4-1],buf);
	     exchange_Q(too.centre[flag4-1]);
    }
   myxa.tik((float)k/too.number*98+1);
/**********************************************************/
 /* установка маркера вычеркнутого столбца */

     }
   myxa.tik(100);
   delete you5;
   delete imin5;
   delete jmin5;
   delete res5;
   delete jres5;
 }



void Ezik::exchange_Q(int index)
   {
     int k;
     k=Qg1[index];
     Qg1[index]=Qg1[0];
     Qg1[0]=k;

     k=Qv[index];
     Qv[index]=Qv[0];
     Qv[0]=k;
   }





 void Ezik::for_search_min(int ji, int &you1, int &imin, int &jmin)
  {
   int i,hlam,hlam2;
   int j;

   for(i=1;i<too.number;i++)
   {
    mai(m[ji])[i]>>hlam2;
    mai(m[ji])[(v_size)i*too.number+hlam2]>>hlam;
    if(hlam<you1&&Qv[i]==0)
     {
      if( (Qv[hlam2]!=1&&(Qg1[i]+Qg1[hlam2])<=too.doplam) || Qv[hlam2]==-1)   // Qv[hlam2]!=1
       {
	imin=i;
	jmin=hlam2;
	you1=hlam;
       }
      else
       {
	mai(m[ji])[i]<<i;
	for(j=1;j<too.number;j++)
	 {
	  mai(m[ji])[i]>>hlam2;
	  mai(m[ji])[(v_size)i*too.number+hlam2]>>hlam;
	  mai(m[ji])[(v_size)i*too.number+j]>>hlam2;
	  if(hlam2<hlam && ( (Qv[j]!=1&&(Qg1[i]+Qg1[j])<=too.doplam) || Qv[j]==-1))  //Qv[j]!=1
	    mai(m[ji])[i]<<j;
	 }

	mai(m[ji])[i]>>hlam2;
	mai(m[ji])[(v_size)i*too.number+hlam2]>>hlam;
	if(hlam<you1)
	  {
	   imin=i;
	   jmin=hlam2;
	   you1=hlam;
	  }
       }
     }
   }
  }


 void Ezik::dop_Qg1(int imin, int jmin, int ji)
  {
   if((Qg1[jmin]+Qg1[imin])<= too.doplam || Qv[jmin]==-1)
     {
      Qg1[jmin]+=Qg1[imin];
      Qv[imin]=1; /* установка маркера вычеркнутой строки и столбца */
      w+=fromto(imin,jmin);
     }
   else
     {
      mai(m[ji])[(v_size)imin*too.number+jmin]<<0;
 /* установка маркера вычеркнутого столбца */
//      Qv[jmin]=-1;
     }

  }


 void Ezik::res_nete(int ji, int &res, int &jres)
  {
   int j,hlam;
   for(j=1;j<n;j++)
    {
     mai(m[ji])[(v_size)imin*too.number+j]>>hlam;
     if(hlam<res && (((Qg1[j]+Qg1[imin])<=too.doplam && Qv[j]!=1)||(Qv[j]==-1)) && j!=jmin)   //Qv[j]!=1
       {
	res=hlam;
	jres=j;
       }
    }
  }

float Ezik::fromto(int fr,int to)
 {
//    fillellipse(ci[fr],4*sky-di[fr],5,5);
    float x,y;
    line(ci[fr],di[fr],ci[to],di[to]);
    x=(float)(ci[fr]-ci[to]);
    y=(float)(di[fr]-di[to]);
    return hypot(x,y);
 }


float Ezik::fromto_2(int fr,int to)
 {
    float x,y;
    x=(float)(ci[fr]-ci[to]);
    y=(float)(di[fr]-di[to]);
    return hypot(x,y);
 }



  /***** Дальше идет соединение узлов с центрами комутаций *****/
void Ezik::unite_with_commutator_2(void)
  {
   int i;
   int imax_2;
//   float max;
//   int max_2;

   setcolor(MAGENTA);
   if(too.ncentre==1)
     for(i=0;i<too.number;i++)
      if(*(Qv+i)==0&&i!=too.centre[0])
       {
	w+=fromto(too.centre[0],i);
	mass_set[i*MS+(MS-6)]=too.centre[0];//записали красную линию +1
	mass_set[i*MS+(MS-5)]=Qg1[i];//записали обьем линию +2
       }

 int* line;
 int j;
   if(too.ncentre>1)
    {
     line=new int[too.ncentre];
     for(j=0;j<too.ncentre;j++)
       line[j]=j;

    float max_2;

    max_2=ci[too.centre[0]];
    imax_2=0;
    for(j=1;j<too.ncentre;j++)
     {
      if(max_2>ci[too.centre[j]])
	{
	 max_2=ci[too.centre[j]];
	 imax_2=j;
	}
     }

    line[0]=imax_2;
    line[imax_2]=0;

    int ji;
    for(j=0;j<too.ncentre-2;j++)
     {
       if(j!=0)
	 {
	  ji=line[j];
	  line[j]=line[imax_2];
	  line[imax_2]=ji;
	 }
       max_2=fromto_2(too.centre[line[j]],too.centre[line[j+1]]);
       imax_2=j+1;
       for(ji=j+2;ji<too.ncentre;ji++)
	 {
	   if(max_2>fromto_2(too.centre[line[j]],too.centre[line[ji]]))
	     {
	       max_2=fromto_2(too.centre[line[j]],too.centre[line[ji]]);
	       imax_2=ji;
	     }
	 }

	mass_set[too.centre[line[j]]*MS+(MS-6)]=too.centre[line[imax_2]];//записали красную линию +1
	mass_set[too.centre[line[j]]*MS+(MS-5)]=too.doplam;//записали обьем линию +2
	w+=fromto(too.centre[line[j]],too.centre[line[imax_2]]);
     }

    ji=line[j];
    line[j]=line[imax_2];
    line[imax_2]=ji;


   max_2=fromto_2(too.centre[line[too.ncentre-1]],too.centre[line[too.ncentre-2]]);
   imax_2=too.ncentre-2;
    for(j=too.ncentre-3;j>=0;j--)
     {
       if(max_2>fromto_2(too.centre[line[too.ncentre-1]],too.centre[line[j]]))
	 {
	   max_2=fromto_2(too.centre[line[too.ncentre-1]],too.centre[line[j]]);
	   imax_2=j;
	 }
     }
   mass_set[too.centre[line[too.ncentre-1]]*MS+(MS-6)]=too.centre[line[imax_2]];//записали красную линию +1
   mass_set[too.centre[line[too.ncentre-1]]*MS+(MS-5)]=too.doplam;//записали обьем линию +2
   w+=fromto(too.centre[line[too.ncentre-1]],too.centre[line[imax_2]]);


    }
 delete line;


/*   if(too.ncentre>2)
     {
       max_2=ci[too.centre[0]];                imax_2=0;
       for(ji=1;ji<too.ncentre;ji++)
	 {
	  if(max_2>ci[too.centre[ji]])
	    {
	     max_2=ci[too.centre[ji]];
	     imax_2=ji;
	    }
	 }
       max_2=too.centre[0];
       too.centre[0]=too.centre[imax_2];
       too.centre[imax_2]=max_2;
     }*/



/*   for(ji=0;ji<(too.ncentre-1);ji++)
     {
      max=fromto_2(too.centre[ji],too.centre[ji+1]);
      imax=ji+1;
      for(i=0;i<too.ncentre;i++)
	{
	  if(max>fromto_2(too.centre[ji],too.centre[i]))
	   {
	    max=fromto_2(too.centre[ji],too.centre[i]);
	    imax=i;
	   }
	}
      w+=fromto(too.centre[ji],too.centre[imax]);
      max_2=ji;     */
//      mass_set[conc5[max_2]*Main_I*MS+main_i*MS+(MS-6)]=conc5[imax];//записали красную линию +1
//     }

     /*****Соединение всех со всеми*****/

//   for(ji=0;ji<NamConc;ji++)
//     {
//      for(i=ji+1;i<NamConc;i++)
//	{
//	  w+=fromto(conc5[ji],conc5[i]);
//	}
//     }

//   if(NamConc>2)
//     {
//       max_2=ci[conc5[0]];
//       ci[conc5[0]]=ci[imax_2];
//       ci[imax_2]=max_2;

//       max_2=di[conc5[0]];
//       di[conc5[0]]=di[imax_2];
//       di[imax_2]=max_2;
//     }

  }
