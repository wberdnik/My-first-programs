#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"error.hpp"
#include"new.hpp"
#include"iosys.hpp"
#include"pcxlib.h"
#define pcxtype pcxEGA_10

#define COLMEN	GREEN
extern void menu0(void);
extern char line[];
extern char line2[];
extern char line1[];
extern char line4[];
extern char type[];
extern char s[];
extern FILE* file;
extern FILE* file1;
extern int *namber;
extern char *name_file[10];
extern char name1[11];
extern Iosys *vviv;
extern int wind;
extern char *name_window[10];
extern int f_one_exit_1;
extern char *name_func[10];

void mas(void);
void all_quit(void);
void menu_11(void);

char name[]="katalog.txt";
void menu (unsigned,unsigned,unsigned);

void menu(unsigned back,unsigned table,unsigned rem)
 {unsigned a,b,c;
 FILE* file=fopen("duk.pcx","r");
 if(file!=NULL){
 	fclose(file);
  char pal1[768], pal2[768];
 pcxSetDisplay (pcxtype);
 pcxSetMode (pcxGRAPHICS);
 pcxGetDisplayPalette(pal2);
 pcxGetFilePalette(pcxtype,"duk.pcx", pal1);
 pcxSetDisplayPalette(pal1);
     pcxFileDisplay("duk.pcx",0,0,0);
 getch();
 pcxSetDisplayPalette(pal2);
 pcxSetMode (pcxTEXT);
 return ;
                   }


  window(1,1,80,25);
  textbackground(back);
  clrscr();
  window(16,7,65,14);
  textbackground(0);
  clrscr();
  textbackground(table);
  textcolor(0);
  window(15,6,65,13);
  gotoxy(1,1);
  cprintf("浜様様様様様様様様様様様様様様様様様様様様様様様融\n\r");
  cprintf("�                                                �\n\r");
  cprintf("�      � � � � � � � � � � �     � � � � �       �\n\r");
  cprintf("�                                                �\n\r");
  cprintf("�          Copyright (c) 1995 , 1999  by         �\n\r");
  cprintf("�        Berdnik W. L.  and  Borisenko S. G.     �\n\r");
  cprintf("�                                                �\n\r");
  cprintf("藩様様様様様様様様様様様様様様様様様様様様様様様夕");
  window(26,18,56,18);
  textbackground(0);
  clrscr();
  window(25,17,55,19);
  textbackground(rem);
  textcolor(WHITE);
  gotoxy(1,1);
  cprintf(" �甎ュ�� � ��｀皀 � �牀������� ");
  gotoxy(31,1);
  if(getch()=='p'){scanf("%d %d %d",&a,&b,&c);
                   menu(a,b,c);}
  window(1,1,80,25);
 };


/******��ぃ�皰→� ���� �キ�******/
void menu_0(void)
 {                                        
   int i;
   textbackground(COLMEN);
   for(i=0;i<22;i++)
    {
     gotoxy(64,2+i);
     cprintf("%s",line2);
    }
 }


/******��ぅ爨━�� 皀�竕ィ� ����******/
 void menu0(void)
 {
  int i;
  textbackground(COLMEN);
  for(i=0;i<*(namber+wind);i++)
   {
    gotoxy(64,3+i);
    cprintf("%s\n",*(name_window+i));
   };
 }


/************ �甅�↓�� ���� ************/
 void menu4_0(void)
   {
     int i;

     window(1,1,80,25);
     textbackground(BLACK);
     clrscr();
     textcolor(WHITE);
     gotoxy(1,1);
     textbackground(9);
     cprintf("�%s�",line);
     for(i=0;i<22;i++)
      {
       if(i!=11)
	 cprintf("%s",line1);
       else
	 cprintf("�%s�",line);
      }
     cprintf("�%s",line);
     gotoxy(14,1);
     cprintf("�");
     gotoxy(14,13);
     cprintf("�");
     gotoxy(14,24);
     cprintf("�");
     textbackground(BLACK);
     for(i=0;i<21;i++)
      {
       gotoxy(80,3+i);
       cprintf("�");
      }
     gotoxy(80,24);
     cprintf("�");
     for(i=0;i<15;i++)
      {
       gotoxy(i+65,24);
       cprintf("�");
      }
     gotoxy(20,24);
     cprintf("ESC-���爬��覃 �諷��");
     menu_0();
     textcolor(BLACK);
     menu0();
   }


/******�ェム�******/
void menu_2(void)
 {
   int i;

   textbackground(BLUE);
   gotoxy(15,1);
   for(i=0;i<11;i++)
      {
	 gotoxy(15,wherey()+1);
	 cprintf("%s",line4);
      }

 }


/******�諷�� ├ 瓱痰ガ�******/
 void quit(void)
  {
   delete vviv;
   all_quit();
   textbackground(BLACK);
   textcolor(LIGHTGRAY);
   clrscr();
   exit(0);
  }


/******���罔��├�罔� ��矗��******/
void menu_00(void)
 {
   int n,z,i=0,k;

   file=fopen(name,type);
   error(file==NULL,OPEN,name);
   if(file==NULL)
     quit();
   fscanf(file,"%s",s);
   n=atoi(s);
   namber=(int *)calloc(n,sizeof(int));

   for(z=0;z<n;z++)
      name_file[z]=(char*)mallos(8);

   while(!feof(file))
    {
      fscanf(file,"%s",name1);
      strncpy(*(name_file+i),name1,8);
      i++;
    }
   fclose(file);

   for(i=0;i<n;i++)
     {
      strncpy(name1,*(name_file+i),8);
      file1=fopen(name1,type);
      error(file1==NULL,OPEN,name1);
      if(file1==NULL)
	quit();
      fscanf(file1,"%s",s);
      k=atoi(s);
      *(namber+i)=k;
      fclose(file1);
     }

 }

/******��皋※��罔� 皀�竕ィ� ����******/
 void menu1_0(void)
 {
  if(wherey()-3<*(namber+wind))
   {
    textbackground(WHITE);
    gotoxy(64,wherey());
    cprintf("%s\n",*(name_window+wherey()-3));
    if(wherey()>4)
     {
       textbackground(COLMEN);
       gotoxy(64,wherey()-2);
       cprintf("%s\n",*(name_window+wherey()-3));
       gotoxy(64,wherey());
     }
    else
     gotoxy(64,wherey()-1);
   }
  else
   {
     textbackground(COLMEN);
     gotoxy(64,wherey()-1);
     cprintf("%s\n",*(name_window+wherey()-3));
     textbackground(WHITE);
     gotoxy(64,wherey()-*(namber+wind));
     cprintf("%s\n",*(name_window+wherey()-3));
     gotoxy(64,wherey()-1);
   }
 }

/*****���罔��├�罔� 皀�竕ィ� ����*****/
void menu_1(void)
 {
   menu_11();
   if(*(name_window)=="\..")
    {
	menu_11();
    }
   if(*(name_window)=="\..")
    {
      textbackground(RED);
      cprintf("�ク��※�讚�� 艪キ┘ 皀�痰�〓�� �����\n");
      cprintf("��｀�� ���爬��� �����腑��\n");
      getch();
      quit();
    }
 }


void menu_11(void)
 {
  int i=0,z;

   if(f_one_exit_1==1)
     {
       for(z=0;z<11;z++)
	{
	  delete name_window[z];
	  delete name_func[z];
	}
     }
  f_one_exit_1=0;
  if(name_window==NULL||name_func==NULL)
    {
      textbackground(RED);
      cprintf("�祀│�� 礫���皀�� �� 皀�痰��覃 ����\n");
      cprintf("��｀�� ���爬��� �����腑��\n");
      getch();
      quit();
    }
  for(z=0;z<*(namber+wind);z++)
   {
     name_window[z]=(char*)mallos(25);
     name_func[z]=(char*)mallos(25);
   }

  strncpy(name1,*(name_file+wind),8);
  file1=fopen(name1,type);
  fscanf(file1,"%s",s);
  for(i=0;i<*(namber+wind);i++)
   {
     fscanf(file1,"%s",s);
     strncpy(*(name_window+i),s,25);
   }
  for(i=0;i<*(namber+wind);i++)
   {
     fscanf(file1,"%s",name1);
     strncpy(*(name_func+i),name1,11);
   }
  fclose(file1);
 }

void help1(void)
  {
   window(64,13,79,19);
   gotoxy(1,1);
   cprintf("****************");
   cprintf("    ����蛹:   \n\r");
   cprintf("┃皀燿�� □�え-\n\r");
   cprintf("�諷 ������皀�ォ\n\r");
   cprintf("�� 0 ぎ 100\n\r");
   cprintf("****************");
   window(1,1,80,25);
  }

void clr_help1(void)
  {
   window(64,13,79,18);
   clrscr();
   window(1,1,80,25);
  }


void help2(void)
  {
   window(64,13,79,21);
   gotoxy(1,1);
   cprintf("****************");
   cprintf("     ����蛹:\n\r");
   cprintf("-1-�モ 痼�↓キ��");
   cprintf(" 0 - ｀�跏�\n\r");
   cprintf(" 1 - �キ跏�\n\r");
   cprintf(" 2 - �罐���\n\r");
   cprintf(" 3 - ��▲�痰〓\n\r");
   cprintf("****************");
   window(1,1,80,25);
  }

void clr_help2(void)
  {
   window(64,13,79,20);
   clrscr();
   window(1,1,80,25);
  }

void clr_swaha(void)
  {
    textbackground(BLUE);
    textcolor(WHITE);
    window(15,2,63,12);
    clrscr();
    window(15,14,63,23);
    clrscr();
    window(2,2,13,12);
    clrscr();
    window(2,14,13,23);
    clrscr();
    window(1,1,80,25);
  }

void no_res(void)
  {
    window(19,3,57,12);
    textbackground(0);
    clrscr();
    window(18,2,56,11);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    clrscr();
    window(18,2,57,11);
    gotoxy(1,1);
    cprintf("浜様様様様様様様様様様様様様様様様様様�\n\r");
    cprintf("�                                     �\n\r");
    cprintf("�  ��� 皰�� 艪�° ���竍�碎 爛с�赳��  �\n\r");
    cprintf("�  瓣�紲, �ギ≦�え�� 〓�皋  �  ��罔�  �\n\r");
    cprintf("�  ����� � ��� ���モ�碎  ������� �ぅ  �\n\r");
    cprintf("�  ��絎え矚�  ��┘��,  ���モ�碎  ��-  �\n\r");
    cprintf("�  ���� ��┘���, � ���Ε ��皰��� �ぅ  �\n\r");
    cprintf("�  �瓷�碎 ├÷���┴�.                 �\n\r");
    cprintf("�                                     �\n\r");
    cprintf("藩様様様様様様様様様様様様様様様様様様�");
    textbackground(COLMEN);
    textcolor(0);
    window(1,1,80,25);
  }

void help3(void)
  {
   window(64,13,79,21);
   gotoxy(1,1);
   cprintf("****************");
   cprintf("     ����蛹:\n\r");
   cprintf(" �-�モ 痼�↓キ��");
   cprintf(" > - ｀�跏�\n\r");
   cprintf(" < - �キ跏�\n\r");
   cprintf(" � - �罐���\n\r");
   cprintf(" = - ��▲�痰〓\n\r");
   cprintf("****************");
   window(1,1,80,25);
  }



void massege1(void)
  {
    window(18,16,62,23);
    textbackground(0);
    clrscr();
    textcolor(WHITE);
    textbackground(LIGHTCYAN);
    window(17,15,61,22);
    clrscr();
    window(17,15,62,22);
    gotoxy(1,1);    
    cprintf("浜様様様様様様様様様様様様様様様様様様様様様�\n\r");
    cprintf("�                                           �\n\r");
    cprintf("�           �� �皙ョキ �������              �\n\r");
    cprintf("�                                           �\n\r");
    cprintf("�         �ぅ ��絎え矚� ����х┴            �\n\r");
    cprintf("�                                           �\n\r");
    cprintf("�                                           �\n\r");
    cprintf("藩様様様様様様様様様様様様様様様様様様様様様�");
    getch();
    textbackground(BLUE);
    window(17,15,62,23);
    clrscr();
    window(1,1,80,25);
  }

void massege2(void)
  {
    window(18,16,62,23);
    textbackground(0);
    clrscr();
    textcolor(WHITE);
    textbackground(LIGHTCYAN);
    window(17,15,61,22);
    clrscr();
    window(17,15,62,22);
    gotoxy(1,1);    
    cprintf("浜様様様様様様様様様様様様様様様様様様様様様�\n\r");
    cprintf("�                                           �\n\r");
    cprintf("�           �� �皙ョキ �������              �\n\r");
    cprintf("�                                           �\n\r");
    cprintf("�         か� ���瓷� �爛皀�ぅ�皰�           �\n\r");
    cprintf("�                                           �\n\r");
    cprintf("�                                           �\n\r");
    cprintf("藩様様様様様様様様様様様様様様様様様様様様様�");
    getch();
    textbackground(BLUE);
    window(17,15,62,23);
    clrscr();
    window(1,1,80,25);
  }  


void massege3(void)
  {
    window(18,16,62,23);
    textbackground(0);
    clrscr();
    textcolor(WHITE);
    textbackground(LIGHTCYAN);
    window(17,15,61,22);
    clrscr();
    window(17,15,62,22);
    gotoxy(1,1);    
    cprintf("浜様様様様様様様様様様様様様様様様様様様様様�\n\r");
    cprintf("�                                           �\n\r");
    cprintf("�                �� �皙ョキ                 �\n\r");
    cprintf("�                                           �\n\r");
    cprintf("�                 ����х┴                  �\n\r");
    cprintf("�                                           �\n\r");
    cprintf("�                                           �\n\r");
    cprintf("藩様様様様様様様様様様様様様様様様様様様様様�");
    getch();
    textbackground(BLUE);
    window(17,15,62,23);
    clrscr();
    window(1,1,80,25);
  }  

void massege4(void)
  {
    window(23,16,54,21);
    textbackground(0);
    clrscr();
    window(22,15,54,22);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�                              �\n\r");
    cprintf("�            �����             �\n\r");
    cprintf("�         ┐竄 ��瘍モ�         �\n\r");
    cprintf("�                              �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    window(1,1,80,25);
  }

void massege5(void)
  {
    window(23,16,54,21);
    textbackground(0);
    clrscr();
    window(22,15,54,22);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�                              �\n\r");
    cprintf("�       ���Ν�� �罐���?        �\n\r");
    cprintf("�            (Y/N)             �\n\r");
    cprintf("�                              �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    gotoxy(19,4);
  }

void massege6(void)
  {
    window(23,16,54,22);
    textbackground(0);
    clrscr();
    window(22,15,54,22);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�                              �\n\r");
    cprintf("�    �▲え皀 ���瓱���讚��      �\n\r");
    cprintf("�      腮甄� ���え��皰�        �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�                              �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    textbackground(WHITE);
    window(33,20,39,20);
    clrscr();
  }

void massege7(void)
  {
    window(23,5,54,11);
    textbackground(0);
    clrscr();
    window(22,4,54,12);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�                              �\n\r");
    cprintf("�     �▲え皀 ��〓� ━�:       �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�     ESC-�皙キ�碎 □��        �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    textbackground(WHITE);
    window(30,7,39,7);
    clrscr();
    window(30,7,40,7);
  }

void massege8(void)
  {
    window(23,5,54,11);
    textbackground(0);
    clrscr();
    window(22,4,54,12);
    mas();
    gotoxy(19,5);
  }

void mas(void)
  {
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�                              �\n\r");
    cprintf("�           �����碎?           �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�            (Y/N)             �\n\r");
    cprintf("�                              �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
  }

void massege15(void)
  {
    window(23,15,54,21);
    textbackground(0);
    clrscr();
    window(22,14,54,21);
    mas();
    gotoxy(19,5);
  }

void massege9(void)
  {
    window(23,5,54,11);
    textbackground(0);
    clrscr();
    window(22,4,54,12);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�                              �\n\r");
    cprintf("�     �� ��ｃ 祗�艪�Θ碎!!!    �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�    ��竄爬 メ碎 ┃筮爼�罔�.   �\n\r");
    cprintf("�                              �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    gotoxy(28,5);
    getch();
    textbackground(BLUE);
    clrscr();
    window(1,1,80,25);
  }

void massege10(void)
  {
    window(23,5,54,11);
    textbackground(0);
    clrscr();
    window(22,4,54,12);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�        ��������!!!           �\n\r");
    cprintf("�       ������� �竅�.          �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�         ������閧�            �\n\r");
    cprintf("�           (Y/N)              �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    gotoxy(18,6);
  }

void massege11(void)
  {
    window(23,5,54,11);
    textbackground(0);
    clrscr();
    window(22,4,54,12);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�        ��������!!!           �\n\r");
    cprintf("�      ���� ��腑痰� �竅��.     �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�         ������閧�            �\n\r");
    cprintf("�           (Y/N)              �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    gotoxy(18,6);
  }

void massege12(void)
  {
    window(23,15,54,21);
    textbackground(0);
    clrscr();
    window(22,14,54,21);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�                              �\n\r");
    cprintf("�   ��� ��罔� ��｀��モ 皰�讓�  �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�       ├ ��щ ����諷!!!      �\n\r");
    cprintf("�                              �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    gotoxy(26,5);
    getch();
    textbackground(BLUE);
    clrscr();
    window(1,1,80,25);
  }


void massege13(void)
  {
    window(23,15,54,21);
    textbackground(0);
    clrscr();
    window(22,14,54,21);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�                              �\n\r");
    cprintf("�            ����諷            �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�        か� ����瓱 �モ        �\n\r");
    cprintf("�                              �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    gotoxy(26,5);
    getch();
    textbackground(BLUE);
    clrscr();
    window(1,1,80,25);
  }


void massege14(void)
  {
    window(23,15,54,21);
    textbackground(0);
    clrscr();
    window(22,14,54,21);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�                              �\n\r");
    cprintf("�     �▲え皀 ▲� ��腑痰��:    �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�                              �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    textbackground(WHITE);
    window(33,18,42,18);
    clrscr();
    gotoxy(1,1);
  }


void massege16(void)
  {
    window(23,15,54,21);
    textbackground(0);
    clrscr();
    window(22,14,54,21);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�                              �\n\r");
    cprintf("�     �� ��ｃ 磴���碎!!!       �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�    ��Ν� 磴��閧� 皰�讓�      �\n\r");
    cprintf("�      ��甄イ�銕 ����瘡.       �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    gotoxy(25,6);
    getch();
    textbackground(BLUE);
    clrscr();
    window(1,1,80,25);
  }

void massege17(void)
  {
    window(23,15,54,21);
    textbackground(0);
    clrscr();
    window(22,14,54,21);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�                              �\n\r");
    cprintf("�   �▲え皀 ���※�� �罐���:    �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�                              �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    textbackground(WHITE);
    window(33,18,42,18);
    clrscr();
    gotoxy(1,1);
  }

void massege18(void)
  {
    window(23,15,54,21);
    textbackground(0);
    clrscr();
    window(22,14,54,21);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�                              �\n\r");
    cprintf("�  �▲え皀 �罐��� 矗ァ������:  �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�                              �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    textbackground(WHITE);
    window(33,18,42,18);
    clrscr();
    gotoxy(1,1);
  }


void massege19(void)
  {
    window(23,15,54,21);
    textbackground(0);
    clrscr();
    window(22,14,54,21);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�                              �\n\r");
    cprintf("�    �▲え皀 ▲� 矗ァ������:   �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�                              �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    textbackground(WHITE);
    window(33,18,42,18);
    clrscr();
    gotoxy(1,1);
  }

void all_quit(void)
  {
    textbackground(BLUE);
    clrscr();
    window(16,9,65,17);
    textbackground(0);
    clrscr();
    textbackground(WHITE);
    textcolor(BLUE);
    window(15,8,65,16);
    gotoxy(1,1);
    cprintf("浜様様様様様様様様様様様様様様様様様様様様様様様融\n\r");
    cprintf("�                                                �\n\r");
    cprintf("�        ������ ������� � ������ �����           �\n\r");
    cprintf("�                                                �\n\r");
    cprintf("�      � � � � � � � � � � �     � � � � �       �\n\r");
    cprintf("�          Copyright (c) 1995 , 1999  by         �\n\r");
    cprintf("�        Berdnik W. L.  and  Borisenko S. G.     �\n\r");
    cprintf("�                                                �\n\r");
    cprintf("藩様様様様様様様様様様様様様様様様様様様様様様様夕");
    gotoxy(44,7);
    getch();
    window(1,1,80,25);

  }

void massege20(void)
  {
    window(23,15,54,21);
    textbackground(0);
    clrscr();
    window(22,14,54,21);
    textbackground(LIGHTCYAN);
    textcolor(WHITE);
    cprintf("浜様様様様様様様様様様様様様様融\n\r");
    cprintf("�                              �\n\r");
    cprintf("�         ��━��┘!!!          �\n\r");
    cprintf("�                              �\n\r");
    cprintf("�    ��� �������� ��腑痰��     �\n\r");
    cprintf("�         �� ���ョキ�.         �\n\r");
    cprintf("藩様様様様様様様様様様様様様様夕\n\r");
    gotoxy(25,6);
    getch();
    textbackground(BLUE);
    clrscr();
    window(1,1,80,25);
  }


