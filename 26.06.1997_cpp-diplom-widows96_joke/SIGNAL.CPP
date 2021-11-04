#include"signal.hpp"
#include"function.hpp"
#include<process.h>
#include<stdio.h>
#include"diagnost.hpp"
#include"simple.hpp"
#include"button.hpp"
#pragma hdrstop
Signal::Signal():Modals(){
if(!yesno("  Вы выбрали опцию трассировки контроллирующих \n"
	  "        и управляющих сигналов в сети!\n"
	  "        Вы желаете продолжить дальше ?"))return;
setcls(new Desktop);
setbase(new MasterButton(cmNo,"",0,""));
char* name;
name="iiscad.txt";
FILE * file=fopen(name,"r");
if(file==NULL){
   Message("    Нет необходимого текстового файла iiscad.txt"
	     "\n              Выберите опцию ИИС");
   return;    }
   fclose(file);

File& a =*new File("netcad.iis");
if(a.end <2)
  {
   Message("    Нет необходимого файла netcad.iis"
	     "\n     Выберите опцию ИИС");
   delete &a;
   return;
  }

a%1+=sizeof(strCentre);

a%sizeof(strIIS);
a[0]>>(void*)&stol;
a+=1;
delete &a;

if(stol.kol==0)
 {
   Message("  Количество испытательно-измерительных столов\n"
	   "               равно    нулю\n"
	   "      Дальнейшая работа невозможна!!!");
   return;
 }

name="iis.exe";
file=fopen(name,"r");
if(file==NULL){
   Message(" Нет необходимого оверлейного файла");
   return;    }
   fclose(file);
int k;
KNOW.close();
printf("  ЖДИТЕ!!! идет распределение контрольных и \n     управляющих сигналов в сети");
k=system(name);
KNOW.open();
status=stFocus;
draft();

if(k){
  Message("Не могу запустить оверлейный файл");
  return;}
Message("       Приложение закончило свою работу\n"
	"    Результаты ныходятся в файле result.txt");
}
Signal::~Signal(){
}