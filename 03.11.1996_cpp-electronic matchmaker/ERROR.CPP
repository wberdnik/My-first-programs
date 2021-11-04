#include "error.hpp"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<errno.h>

char* errtext [12]={		"\nНельзя открыть",
				"\nНельзя закрыть",
				"\nНельзя читать",
				"\nНельзя писать",
				"\nНет памяти",
				"\nФайл не .dbf",
	"\n Перекрестная ссылка в БД",
	"\n Системный сбой",
	"\n Ошибка интерфейса модулей ",
	"\n Нельзя изменить размер файла ",
	"\n Плохой файл конфигурации",
	"\n Системное предупреждение"
	};

void error(int res,int kode,char* c)
	{if(res){Scr x(1);
		 window(1,1,80,25);
		 textbackground(WHITE);
		 clrscr();
		 window(20,5,60,20);
		 textcolor(GREEN);
		 textbackground(RED);
		  clrscr();
		 cprintf("      %s ",errtext[kode-1]);
		 gotoxy(4,3);
		 cprintf(" %s",c);
		 gotoxy(3,5);
		 if(kode<4)
				switch(errno){
				 case ENOFILE : cprintf( "Файл не найден");break;
				 case ENOPATH : cprintf( "Путь указан неверно");break;
				 case EINVENV : cprintf("Ошибка в окружении");break;
				 case EINVFMT : cprintf("Ошибочный формат");break;
				 case EINVACC : cprintf("Нет доступа к файлу");break;
				 case EINVDRV : cprintf("Ошибочно указан диск");break;
				 case ENOTSAM : cprintf("Нет такого устройства");break;
				 case EMFILE  : cprintf("Слишком много открытых файлов");break;
				 case EBADF   : cprintf("Ошибочный номер файла");break;
				 case EXDEV   : cprintf("Ошибка в FATе");break;
				 default : cprintf("Неизвестная ошибка");
			}
		 gotoxy(5,14);
		 cprintf("\n Прекратить-1  Продолжать -2");
		 window(1,1,80,25);
		 if(getche()=='2')return;
		  exit(1);}
	 }

