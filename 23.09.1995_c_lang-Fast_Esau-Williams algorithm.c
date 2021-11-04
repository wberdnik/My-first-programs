/*
       ╔══════════════════════════════════════════════════════╗
       ║   Лабораторная работа по курсу Надежность ЭВМ        ║
       ║         выполнилии студенты группы ВТ 328б           ║
       ║         Бердник Владислав Леонидович , и             ║
       ║         Борисенко Сергей Генадьевич .                ║
       ╚══════════════════════════════════════════════════════╝

      О П И С А Н И Е    М Е Т О Д А    И С П О Л Ь З У Е М О Г О

                   В   Д А Н Н О Й   Р А Б О Т Е


       В работе использовается эвристический алгоритм  основанный
       на алгоритме Еже-Вильемса. Алгоритм метода основан на особом спо-
       собе формирования матрицы длин растояния между  различными
       точками на плоскости. В данной работе  используется  обыч-
       ный алгоритм ЕжеВильемса, более глубоко проработана  реа-
       лизация этого метода . В частности в учебных целях коорди-
       наты точек приводятся

*/

#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <alloc.h>

/*          блок описания переменных       */

float *lamda,*a,lamda1,max,min,lin,t,*d,*c,s,r,kof,you;
float y,x;
int i,j,n,*ci,*di,k,*em,*sem,jm;
int *Qg,*Qv,*Qg1,*Qv1,*Qg2,*Qv2,*Dg,*Dv,imin,jmin,Dmin;
int driver,mode;
int xm,ym,skx,sky,x1,y1;
int doplam;
char string[10];
int far **m;
float w,w1;
/*           блок описания функций         */
void graphika(void);
void sets(void);
void vvod(void);
float func(void);
void dlina(void);
void capacity_of_information(void);
void center(void);
float fromto(int,int);

/*     main() - подготавливает начальные данные, а также
                следит за распределением памяти.             */

main()
 {              /* Вычисление размеров экрана */
     driver=DETECT;
     initgraph(&driver,&mode,"..");
     xm=getmaxx();
     ym=getmaxy();
     skx=abs(xm/4);
     sky=abs(ym/4);
     closegraph();
     restorecrtmode();

   printf("\n|\tСколько станций необходимо обслуживать : ");
   scanf("%d",&n);
   printf("|\tВведите данные для гиперэкспоненциального закона\n"
          "|\t************************************************\n"
          "|\tВведите колличество интервалов K : ");
   scanf("%d",&k);
   printf("|\t------------------------------------------------");


   c=(float*)calloc(n,sizeof(float));
   ci=(int*)calloc(n+1,sizeof(int));
   em=(int *)calloc(n,sizeof(int));
   sem=(int *)calloc(300,sizeof(int));
   d=(float*)calloc(n,sizeof(float));
   di=(int*)calloc(n+1,sizeof(int));
   lamda=(float *)calloc(k,sizeof(float));
   a=(float *)calloc(k,sizeof(float));

     vvod();   /*  здесь формируются координаты точек */

     free(c);
     free(d);
     free(lamda);
     free(a);

   Qv=(int *)calloc(20,sizeof(int));
   Qg=(int *)calloc(15,sizeof(int));
   Qv1=(int *)calloc(20,sizeof(int));
   Qg1=(int *)calloc(15,sizeof(int));
   Qv2=(int *)calloc(20,sizeof(int));
   Qg2=(int *)calloc(15,sizeof(int));
   Dv=(int *)calloc(20,sizeof(int));
   Dg=(int *)calloc(15,sizeof(int));

     center();    /* здесь определяется центр комутации */

     free(Qv);
     free(Qg);
     free(Qv1);
     free(Qv2);
     free(Qg2);
     free(Qg1);
     free(em);
     free(Dv);
     free(Dg);

     dlina();      /* здесь формируется матрица растояний */
  Qv=(int*)calloc(n,sizeof(int));
  Qg1=(int *)calloc(n,sizeof(int));
       if(Qg1==NULL)
         {
           clrscr();
           printf(" \n\n\n       F E W  M E M O R Y ! ! ! ");
           getch();
           exit(1);
         }

     capacity_of_information();   /*  а здесь все отображается на дисплее */
     graphika();

     printf("|\tДлина основного пути  : %.2f\n|\tДлина резервного пути"
            " : %.2f\n|\n|\tCуммарная длина пути  : %.2f",w,w1,w1+w);
     getch();

     free(ci);  /*   x   */
     free(di);  /*   y   */
     for(i=0;i<n;i++)
     farfree(m[i]);
     free(m);
     free(Qv);
     free(Qg1);
     free(sem);
  }


void vvod(void)
 {printf("\n|\tВведите парaметры отказов lamda (1e-6) интервалов  \n"
          "|\t-------------------------------------------------\n");
   for(i=0;i<k;i++)
     {
       printf("|\tlamda %d-ого интервала : ",i+1);
       scanf("%f",&t);
       lamda[i]=t*(1e-6);
     }
   clrscr();
   printf("\n|\tВведите парметры A интервалов (сумма A равна 1)\n");
   for(i=0;i<k;i++)
     {printf("|\tA %d-ого интервала : ",i+1);
       scanf("%f",&t);
       a[i]=t;
     }

  /* Вычисление координаты по X   гиперэкспонициальный закон */

  max=0;
   for(i=0;i<n;i++){ 
     j=0;
       s=a[j];
       r=(float)rand()/32767;
       while(r>=s)
         { j++;
           s+=a[j];}

       c[i]=func();
       if(c[i]>max)
         max=c[i];
      };
          /* маштабирование по оси X */

     for(i=0;i<n;i++)
     ci[i]=abs(c[i]*4*skx/max);

 /********** Формирование maтрицы высоты *********************/

  for(i=0;i<n;i++)
   {
     d[i] = (float)rand()/32767;
     max=4*sky;
     min=0;
     if(ci[i]<skx)
       min=-sky*ci[i]/skx+sky;
     if(ci[i]<(2*skx))
       max=sky*ci[i]/(2*skx)+3*sky;
     if(ci[i]>(3*skx))
       max=(-2*ci[i]/skx+9)*sky;
     di[i]=abs(min+(max-min)*d[i]);
   }
}

 float func(void)
 { return -(float)(1/lamda[j])*log((1e-5+(double)rand()/32767));}

/*   вспомогательная функция при построении сети   */

 float fromto(int fr,int to)
 {  line(ci[fr],4*sky-di[fr],ci[to],4*sky-di[to]);
    x=(float)(ci[fr]-ci[to]);
    y=(float)(di[fr]-di[to]);
    return hypot(x,y);
 }

void center(void)       /* все говорит самo за себя */
  {int k,st;

   for(i=0;i<n;i++)
    em[i]=abs(5+20*((float)rand()/32767));

    clrscr();

   if(n<80)
   {
    printf("|\tЕмкости или пропускная способность каждого узла : \n"
           "|\t-------------------------------------------------\n");
    for(i=0;i<n;i++)
        printf("C[%d]   =   %d  ",i+1,em[i]);
     getch();
    }
    else
    {
    printf("\n|\tВнутренние расчеты  ! ! !\n"
           "------------------------------------------------------\n"
           "\t200        300      400       500      600\n"
           "------------------------------------------------------\n");
    }

 /*   определение отображения точек на каждый участок */

    w1=1.0001*skx/5;
    w=4.00001*sky/15;
 for(k=0;k<n;k++)
   if(ci[k]!=0)
    *(sem+(int)(ceil(ci[k]/w1))-1+20*(int)(ceil(di[k]/w-1)))+=em[k];
    else
    *(sem+20*(int)(ceil(di[k]/w-1)))+=em[k];

/*  центр комутации по координате Y  */

    for(i=0;i<15;i++)
        for(j=0;j<20;j++)
          { Qg[i]+=*(sem+i*20+j);
            Qv[j]+=*(sem+i*20+j); }

     Qg1[0]=Qg[0];
     Qg2[14]=Qg[14];

     for(i=1;i<15;i++)
       { Qg1[i]=Qg[i]+Qg1[i-1];
         Qg2[14-i]=Qg[14-i]+Qg2[15-i];
       }
     imin=0;
     for(i=0;i<15;i++)
       {Dg[i]=abs(Qg1[i]-Qg2[i]);
         if(i==0)
             Dmin=Dg[0];

         if(Dg[i]<Dmin)
           {Dmin=Dg[i];
            imin=i;}
       }

/*  центр комутации по координате X  */

     Qv1[0]=Qv[0];
     Qv2[19]=Qv[19];

     for(j=1;j<20;j++)
       { Qv1[j]=Qv[j]+Qv1[j-1];
         Qv2[19-j]=Qv[19-j]+Qv2[20-j];
       }
     for(j=0;j<20;j++)
       { Dv[j]=abs(Qv1[j]-Qv2[j]);

         if(j==0)
             Dmin=Dv[0];

         if(Dv[j]<Dmin)
           {Dmin=Dv[j];
            jmin=j;}
       }

     x=w1*jmin;
     y=w*imin;
     x1=0;
     y1=0;

/*  определение наличия в данном квадрате станции    */

      for(j=0;j<n;j++)
        {if((ci[j]>=x) && (ci[j]<(x+w1)) && (di[j]>y) && (di[j]<=(y+w)))
           {
             x1=ci[j];
             y1=di[j];
             jm=j;
             j=n;
           }
        }
}

void dlina(void)
{ int st;

/*     устанавливаем центр комутации как первую станцию    */

  if(x1!=0&&y1!=0)
       {
         k=ci[jm];
         ci[jm]=ci[0];
         ci[0]=k;

         k=di[jm];
         di[jm]=di[0];
         di[0]=k;
       }
       else
       {
         x1=abs(x+w1/2);
         y1=abs(y+w/2);

         k=ci[0];
         ci[0]=x1;
         ci[n]=k;

         k=di[0];
         di[0]=y1;
         di[n]=k;

         n=n+1;
       };

/* запрашиваем у системы память под основной массив програмы -
                     матрицу длин между точками */

   m=(int far **)calloc(n,sizeof(int far *));
   for(i=0;i<n;i++)
     m[i]=(int far *)farcalloc(n,sizeof(int));
       if(m[n-1]==NULL)
         {
           clrscr();
           printf(" \n\n|\t F E W  M E M O R Y ! ! ! ");
           getch();
           exit(1);
         }

/* самый долгий процес в программе - расчет матрицы длин         */

       st=100;
       k=20000/xm;
       for(i=1;i<n;i++)
       {if(i==st)
        {printf("%c%c",219,219); /* отображение эволюции процеса на дисплее */
          st+=20;}
         for(j=0;j<i+1;j++)
           {
             x=(float)(ci[i]-ci[j]);
             y=(float)(di[i]-di[j]);
             y=hypot(x*k,y*k);
             m[i][j]=(int)y;
             m[j][i]=(int)y;
           }
        }
/**************   Подготовка  матрицы   *************/

  for(i=1;i<n;i++)
      for(j=1;j<n;j++)
            if(j==i)
               m[i][j]=0;
            else
               m[i][j]=m[i][j]-m[i][0];

      string[0]=7;
      if(n<200)
       string[0]=32;

      clrscr();
     printf("|%c\t Центральный квадрат :\n|\tстрока - %d \n"
            "|\tстолбец - %d",string[0],imin+1,jmin+1);
  }


void capacity_of_information (void)
 {int xa,ya;
   printf("\n|\n|\tВведите допустимое значение пропускной способности  : ");
  scanf("%d",&doplam);
  do
  {
  printf("\n|\tМинимальная и mаксимальная lamda : ");
  scanf("%d %d",&xa,&ya);
   }while(xa>doplam || ya<xa || xa<0 );

  for(i=0;i<n;i++)
   { Qg1[i]=(int)(xa+(ya-xa)*(double)rand()/32767);
     if(Qg1[i]>doplam )
     i--;
   };
}

 void graphika(void)
 {
     /*          ГРАФИКА       */

     initgraph(&driver,&mode,"..");

/* построение координатной сетки */

     for(i=0;i<5;i++)
       { if(i==0 ||i==4)
           setcolor(LIGHTGRAY);
          else
            setcolor(DARKGRAY);
         line(0,i*sky,4*skx,i*sky);
         line(i*skx,0,i*skx,4*sky);
       }

/* построение границ расположения станций */

     setcolor(BROWN);
     moveto(0,sky);
     lineto(0,3*sky);
     lineto(skx,sky*4);
     lineto(4*skx,4*sky);
     lineto(4*skx,2*sky);
     lineto(3*skx,0);
     lineto(2*skx,0);
     lineto(0,sky);

/* вывод на дисплей точек   */

     for(i=0;i<n;i++)
       putpixel(ci[i],4*sky-di[i],WHITE);
     getch();

/* построение более мелкой координатной сетки */

     setcolor(BLACK);
     for(i=1;i<4;i++)
       { line(0,i*sky,xm,i*sky);
         line(i*skx,0,i*skx,ym);}
     setcolor(DARKGRAY);
     for(i=1;i<15;i++)
        line(0,abs(i*4*sky/15),4*skx,abs(4*i*sky/15));
     for(i=1;i<20;i++)
       line(abs(i*skx/5),0,abs(i*skx/5),4*sky);

/* вывод на дисплей емкости квадратов   */

     setcolor(CYAN);
     for(i=0;i<15;i++)
         for(j=0;j<20;j++)
          {
            if(*(sem+i*20+j)!=0)
              {itoa(*(sem+i*20+j),string,10);
               outtextxy(abs(skx/20+j*skx/5),abs(2*sky/15+(14-i)*4*sky/15),string);}
          }

/*  выделение центра комутации */

     setcolor(WHITE);
     moveto(abs(jmin*skx/5),abs((14-imin)*4*sky/15));
     lineto(abs((jmin+1)*skx/5),abs((14-imin)*4*sky/15));
     lineto(abs((jmin+1)*skx/5),abs((15-imin)*4*sky/15));
     lineto(abs((jmin)*skx/5),abs((15-imin)*4*sky/15));
     lineto(abs((jmin)*skx/5),abs((14-imin)*4*sky/15));
     setcolor(LIGHTRED);
     circle(ci[0],4*sky-di[0],4);
     getch();

     sets();     /* здесь строится сеть */

     closegraph();
     restorecrtmode();
}

void sets(void)  /* функция построения сети */
{int you1;
 int res;
 int jres;

/* подготовка матрицы для быстрого поиска */

 for(i=1;i<n;i++)
  { m[0][i]=i;
    for(j=1;j<n;j++)
     if(m[i][j]<m[i][m[0][i]])
       m[0][i]=j;}

 w=0;  w1=0;
    while(1)
      {
        you1=0;     /**** очень быстрый поиск минимума *******/
        for(i=1;i<n;i++)
         if( Qv[i]==0 && m[i][m[0][i]]<you1)
            {if(Qv[m[0][i]]==0)
              {imin=i;
              jmin=m[0][i];
              you1=m[i][m[0][i]];}
            else
             {m[0][i]=i;
              for(j=1;j<n;j++)
               if(m[i][j]<m[i][m[0][i]] && Qv[j]!=1)
                m[0][i]=j;
               if(m[i][m[0][i]]<you1)
                {imin=i;
                 jmin=m[0][i];
                 you1=m[i][m[0][i]];}
              }
            }
/***********************************************************************/
      if(you1==0) break; /*   а это условие выхода из цикла  */

/*  построение основной сети  */

     setcolor(YELLOW);
     if( (Qg1[jmin]+Qg1[imin])<= doplam)
        {Qg1[jmin]+=Qg1[imin];
         Qv[imin]=1; /* установка маркера вычеркнутой строки и столбца */
         w+=fromto(imin,jmin);}
      else
          m[imin][jmin]=0;

/*  построение резервной сети  */

    setcolor(BLUE);
    res=0;   jres=0;
    for(j=1;j<n;j++)
    {
     if(m[imin][j]<res && (Qg1[j]+Qg1[imin])<= doplam && j!=jmin && Qv[j]!=1)
        {res=m[imin][j];
        jres=j;}
     }
    if(res!=0)
       Qg1[j]+=Qg1[imin];
    else
      jres=0;

    w1+=fromto(imin,jres);

 /* установка маркера вычеркнутого столбца */

    if(Qg1[jmin]>=doplam)
      Qv[jmin]=-1;
   }

/****** Дальше идет соединение узлов с центром комутации ********/

 setcolor(MAGENTA);
 for(i=1;i<n;i++)
       if(*(Qv+i)!=1)
          w+=fromto(0,i);
 getch();
}
