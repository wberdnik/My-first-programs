#include"diagnost.hpp"
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<alloc.h>
#include<stdio.h>
#include<string.h>
#include"slave.h"
#include"event.hpp"
#pragma hdrstop

void set_new_handler(void(far*)(void));
void obrmemerror(void);
extern "C"{
	void far pascal Processor_detect(void);
	  };

void Diagnost::test(void){
Processor_detect(); processor=_AX;
speedcpu=(long)processor*100;
disk = getdisk();
if(disk<2){printf("\n Использование диска не эффективно.");sleep(1);}
getcwd(path, MAXPATH);

struct dfree free;

getdfree(disk+1, &free);
if (free.df_sclus == 0xFFFF)
{
   printf("Ошибка в getdfree().");
   _exit(1);
}

diskfree =  (long) free.df_avail * (long) free.df_bsec * (long) free.df_sclus;
if(diskfree<100000L){
   printf("\n Мало свободного места на диске.");
   _exit(2);
}
memfree=farcoreleft();
if(memfree<10000L){
   printf("\n Мало свободной оперативной памяти.");
   _exit(3);
}


/*int errorcode;
errorcode = registerfarbgidriver(EGAVGA_driver_far);
if (errorcode < 0){
   printf("Внутренний сбой при инициализации драйвера");
   getch();
   _exit(10);  terminate with an error code
} */
open();

set_new_handler(obrmemerror);
Ev.Run();
strcpy(filename,"netcad");
FILE *file=fopen("netcad.ini","r");
if(file!=NULL){
   fread(&stepweb,1,1,file);
   fread(&colorweb,1,1,file);
   fread(&modemath,1,1,file);
   fread(&modecoo,1,1,file);
   fread(&sound,1,1,file);
   fread(&curtime,1,1,file);
    fclose(file);
	      }
   sound=sound?Yes:No;
 switch(stepweb){
  case cmNo :  case cmPoint:  case cmLine: break;
  default : stepweb=cmLine;
		 }
 switch(colorweb){
  case BROWN:  case CYAN: case DARKGRAY: case RED:
  case GREEN :  case LIGHTGRAY:break;
  default 	: colorweb=LIGHTGRAY;
		 }
  switch(modemath){
   case rasMathReal: case rasMathPixel:break;
   default : modemath=rasMathPixel;
		  }
  switch(modecoo){
   case rasCooReal: case rasCooPixel:case rasCooNo: break;
   default : modecoo=rasCooPixel;
		  }

}
void Diagnost::open(void){
int gdriver = VGA, gmode=VGAHI, errorcode;
/*_mvideo=(unsigned*)0x0b8000000L;
for(int i=0;i<2000;i++)screen[i]=_mvideo[i];*/

initgraph(&gdriver, &gmode, "");
errorcode = graphresult();

if (errorcode != grOk|| VGAHI!=getgraphmode())
{
   printf("\nНевозможно установить необходимый графический режим монитора");
   getch();
   _exit(1);
}
}
void Diagnost::close(void){
closegraph();
restorecrtmode();
/*for(int i=0;i<2000;i++)_mvideo[i]=screen[i];
window(1,1,80,25);
textbackground(BLACK);
textcolor(LIGHTGRAY);
gotoxy(79,24);
cprintf("\r\n");*/
}

Diagnost KNOW;

void obrmemerror(void){
closegraph();
printf(" Не хватает памяти !!!!");
getch();
_exit(33);
};


Diagnost::~Diagnost(){
char screen[30];
fcloseall();
close();
unsigned long b=farcoreleft();
if(b!=memfree){printf("\n В программе была потеряна память %lu байт",\
	     memfree-b); getch();}
sprintf((char*)screen,"%s\\netcad.ini",path);
FILE *file=fopen((char*)screen,"w");
if(file!=NULL){
   fwrite(&stepweb,1,1,file);
   fwrite(&colorweb,1,1,file);
   fwrite(&modemath,1,1,file);
   fwrite(&modecoo,1,1,file);
   fwrite(&sound,1,1,file);
   fwrite(&curtime,1,1,file);
    fclose(file);
	      }

}