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
  cprintf("ษออออออออออออออออออออออออออออออออออออออออออออออออป\n\r");
  cprintf("บ                                                บ\n\r");
  cprintf("บ        …  ’     €      ‘  € • €       บ\n\r");
  cprintf("บ                                                บ\n\r");
  cprintf("บ          Copyright (c) 1995 , 1999  by         บ\n\r");
  cprintf("บ        Berdnik W. L.  and  Borisenko S. G.     บ\n\r");
  cprintf("บ                                                บ\n\r");
  cprintf("ศออออออออออออออออออออออออออออออออออออออออออออออออผ");
  window(26,18,56,18);
  textbackground(0);
  clrscr();
  window(25,17,55,19);
  textbackground(rem);
  textcolor(WHITE);
  gotoxy(1,1);
  cprintf(" “แฏฅๅฎข ข เ กฎโฅ แ ฏเฎฃเ ฌฌฎฉ ");
  gotoxy(31,1);
  if(getch()=='p'){scanf("%d %d %d",&a,&b,&c);
                   menu(a,b,c);}
  window(1,1,80,25);
 };


/******ฎคฃฎโฎขช  ฎชญ  ฌฅญ๎******/
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


/******‘ฎคฅเฆจฌฎฅ โฅชใ้ฅฃฎ ฎชญ ******/
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


/************ แญฎขญฎฅ ฎชญฎ ************/
 void menu4_0(void)
   {
     int i;

     window(1,1,80,25);
     textbackground(BLACK);
     clrscr();
     textcolor(WHITE);
     gotoxy(1,1);
     textbackground(9);
     cprintf("ษ%sป",line);
     for(i=0;i<22;i++)
      {
       if(i!=11)
	 cprintf("%s",line1);
       else
	 cprintf("ฬ%sถ",line);
      }
     cprintf("ำ%s",line);
     gotoxy(14,1);
     cprintf("ห");
     gotoxy(14,13);
     cprintf("ฮ");
     gotoxy(14,24);
     cprintf("ส");
     textbackground(BLACK);
     for(i=0;i<21;i++)
      {
       gotoxy(80,3+i);
       cprintf("บ");
      }
     gotoxy(80,24);
     cprintf("ผ");
     for(i=0;i<15;i++)
      {
       gotoxy(i+65,24);
       cprintf("อ");
      }
     gotoxy(20,24);
     cprintf("ESC- ข เจฉญ๋ฉ ข๋ๅฎค");
     menu_0();
     textcolor(BLACK);
     menu0();
   }


/******ฅงฅเข******/
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


/******๋ๅฎค จง แจแโฅฌ๋******/
 void quit(void)
  {
   delete vviv;
   all_quit();
   textbackground(BLACK);
   textcolor(LIGHTGRAY);
   clrscr();
   exit(0);
  }


/******ญจๆจ ซจง ๆจ๏ ฌ โเจๆ******/
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

/******€ชโจขจง ๆจ๏ โฅชใ้ฅฃฎ ฎชญ ******/
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

/*****ญจๆจ ซจง ๆจ๏ โฅชใ้ฅฃฎ ฎชญ *****/
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
      cprintf("ฅฏเ ขจซ์ญฎฅ ็โฅญจฅ โฅชแโฎขฎฃฎ ไ ฉซ \n");
      cprintf(" กฎโ   ข เจฉญฎ ง ชฎญ็ฅญ \n");
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
      cprintf("ใซจขฎฉ ใช ง โฅซ์ ญ  โฅชแโฎข๋ฉ ไ ฉซ\n");
      cprintf(" กฎโ   ข เจฉญฎ ง ชฎญ็ฅญ \n");
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
   cprintf("    ฎฌฎ้์:   \n\r");
   cprintf("จญโฅเข ซ ขขฎคจ-\n\r");
   cprintf("ฌ๋ๅ ฏฎช ง โฅซฅฉ\n\r");
   cprintf("ฎโ 0 คฎ 100\n\r");
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
   cprintf("     ฎฌฎ้์:\n\r");
   cprintf("-1-ญฅโ แเ ขญฅญจ๏");
   cprintf(" 0 - กฎซ์่ฅ\n\r");
   cprintf(" 1 - ฌฅญ์่ฅ\n\r");
   cprintf(" 2 - ฎๆฅญช \n\r");
   cprintf(" 3 - เ ขฅญแโขฎ\n\r");
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
    cprintf("ษอออออออออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                                     บ\n\r");
    cprintf("บ  ซ๏ โฎฃฎ ็โฎก๋ ฏฎซใ็จโ์ เฅงใซ์โ โ  บ\n\r");
    cprintf("บ  แข ๅจ, ญฅฎกๅฎคจฌฎ ขฎฉโจ  ข  ฎฏๆจ๎  บ\n\r");
    cprintf("บ  ‘€•€ จ โ ฌ ฏฎฌฅโจโ์  ช โ ซฎฃ ฃคฅ  บ\n\r");
    cprintf("บ  ญ ๅฎคจโแ๏  ชซจฅญโ,  ฏฎฌฅโจโ์  แ -  บ\n\r");
    cprintf("บ  ฌฎฃฎ ชซจฅญโ ,   โ ชฆฅ ช โฎซฎฃ ฃคฅ  บ\n\r");
    cprintf("บ  จแช โ์ จงกเ ญญจช .                 บ\n\r");
    cprintf("บ                                     บ\n\r");
    cprintf("ศอออออออออออออออออออออออออออออออออออออผ");
    textbackground(COLMEN);
    textcolor(0);
    window(1,1,80,25);
  }

void help3(void)
  {
   window(64,13,79,21);
   gotoxy(1,1);
   cprintf("****************");
   cprintf("     ฎฌฎ้์:\n\r");
   cprintf(" -ญฅโ แเ ขญฅญจ๏");
   cprintf(" > - กฎซ์่ฅ\n\r");
   cprintf(" < - ฌฅญ์่ฅ\n\r");
   cprintf("  - ฎๆฅญช \n\r");
   cprintf(" = - เ ขฅญแโขฎ\n\r");
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
    cprintf("ษอออออออออออออออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                                           บ\n\r");
    cprintf("บ           ฅ ฎโฌฅ็ฅญ ช โ ซฎฃ              บ\n\r");
    cprintf("บ                                           บ\n\r");
    cprintf("บ         ฃคฅ ญ ๅฎคจโแ๏ ง ช ง็จช            บ\n\r");
    cprintf("บ                                           บ\n\r");
    cprintf("บ                                           บ\n\r");
    cprintf("ศอออออออออออออออออออออออออออออออออออออออออออผ");
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
    cprintf("ษอออออออออออออออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                                           บ\n\r");
    cprintf("บ           ฅ ฎโฌฅ็ฅญ ช โ ซฎฃ              บ\n\r");
    cprintf("บ                                           บ\n\r");
    cprintf("บ         คซ๏ ฏฎจแช  ฏเฅโฅญคฅญโฎข           บ\n\r");
    cprintf("บ                                           บ\n\r");
    cprintf("บ                                           บ\n\r");
    cprintf("ศอออออออออออออออออออออออออออออออออออออออออออผ");
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
    cprintf("ษอออออออออออออออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                                           บ\n\r");
    cprintf("บ                ฅ ฎโฌฅ็ฅญ                 บ\n\r");
    cprintf("บ                                           บ\n\r");
    cprintf("บ                 ง ช ง็จช                  บ\n\r");
    cprintf("บ                                           บ\n\r");
    cprintf("บ                                           บ\n\r");
    cprintf("ศอออออออออออออออออออออออออออออออออออออออออออผ");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ            ’…             บ\n\r");
    cprintf("บ         จคใโ เ แ็ฅโ๋         บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ       ‘ซฎฆญ ๏ ฎๆฅญช ?        บ\n\r");
    cprintf("บ            (Y/N)             บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ    ขฅคจโฅ ฌ ชแจฌ ซ์ญฎฅ      บ\n\r");
    cprintf("บ      ็จแซฎ ช ญคจค โฎข        บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ     ขฅคจโฅ ญฎขฎฅ จฌ๏:       บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ     ESC-ฎโฌฅญจโ์ ขขฎค        บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ           “ค ซจโ์?           บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ            (Y/N)             บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ     ฅ ฌฎฃใ ใญจ็โฎฆจโ์!!!    บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ    ญใโเจ ฅแโ์ จญไฎเฌ ๆจ๏.   บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ        €…!!!           บ\n\r");
    cprintf("บ        โ ซฎฃ ฏใแโ.          บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ          ฏฎซญ๏โ์            บ\n\r");
    cprintf("บ           (Y/N)              บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ        €…!!!           บ\n\r");
    cprintf("บ       ง  ช ็ฅแโข ฏใแโ .     บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ          ฏฎซญ๏โ์            บ\n\r");
    cprintf("บ           (Y/N)              บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ   โ  ฎฏๆจ๏ เ กฎโ ฅโ โฎซ์ชฎ  บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ       จง ก ง๋ ค ญญ๋ๅ!!!      บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ             ญญ๋ๅ            บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ        คซ๏ ง ฏจแจ ญฅโ        บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ     ขฅคจโฅ ขฅแ ช ็ฅแโข :    บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ     ฅ ฌฎฃใ ใค ซจโ์!!!       บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ    ฎฆญฎ ใค ซ๏โ์ โฎซ์ชฎ      บ\n\r");
    cprintf("บ      ฏฎแซฅคญ๎๎ ง ฏจแ์.       บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ   ขฅคจโฅ ฏเ ขจซฎ ฎๆฅญชจ:    บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ  ขฅคจโฅ ฎๆฅญชใ โเฅกฎข ญจ๏:  บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ    ขฅคจโฅ ขฅแ โเฅกฎข ญจ๏:   บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
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
    cprintf("ษออออออออออออออออออออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                                                บ\n\r");
    cprintf("บ        …€… ‘—€‘’  —            บ\n\r");
    cprintf("บ                                                บ\n\r");
    cprintf("บ        …  ’     €      ‘  € • €       บ\n\r");
    cprintf("บ          Copyright (c) 1995 , 1999  by         บ\n\r");
    cprintf("บ        Berdnik W. L.  and  Borisenko S. G.     บ\n\r");
    cprintf("บ                                                บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออออออออออออออออออออผ");
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
    cprintf("ษออออออออออออออออออออออออออออออป\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ         ญจฌ ญจฅ!!!          บ\n\r");
    cprintf("บ                              บ\n\r");
    cprintf("บ    ฌ๏ ช โ ซฎฃ  ช ็ฅแโข      บ\n\r");
    cprintf("บ         ญฅ ฏฎฌฅ็ฅญฎ.         บ\n\r");
    cprintf("ศออออออออออออออออออออออออออออออผ\n\r");
    gotoxy(25,6);
    getch();
    textbackground(BLUE);
    clrscr();
    window(1,1,80,25);
  }


