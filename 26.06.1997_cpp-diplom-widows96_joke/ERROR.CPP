#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define  STDLIBH
#define  CONIOH
#define  STDIOH
#include "textbar.hpp"
#include "error.hpp"
#include "diagnost.hpp"
#pragma hdrstop

#define FATALERROR  5   // фатальная

extern"C" {
	  void sound(unsigned);
	  void nosound(void);
	  void delay(unsigned);
	  }


Error error;
void Error::operator()(char* a){
operator()(FATALERROR,"",a);    }


int Error::operator()(int kode,char* c,char* d){
if(kode==0)return 0;                // c - cooбщение 1
char* e="Инкогнито";                // d - cообщение 2
 switch(kode){
 case MESSAGE    : e="Сообщение";break;
 case WARNING    : e="Предупреждение";break;
 case ERROR      : e="Ошибка";break;
 case FATALERROR : c="Обратитесь к разработчикам";
		   e="Аварийное завершение";break;
 case USERS      : c="Неправильное использование."
		     "Смотрите техническое\nруководство : ";
		   e="Аварийное завершение";break;
 case ERRORFILE  : e=" Проблема работы с OS";
	   }
 TextBar t(200,133,240,190,NULL,LIGHTRED);
 t(YELLOW)(1,1);
 t.set(modeNameBox,e,WHITE,LIGHTRED);
 t.draft();
 t<<c<<"\n\n   "<<d;
 if(KNOW.sound){sound(1000);delay(500);nosound();}
 getch();
 if(kode==FATALERROR)exit(kode);

 switch(kode){
 case MESSAGE    :
 case WARNING    : return 0;
 case ERROR      : return 1;

 case ERRORFILE  : t<<"(R)etry,(A)bort,(I)gnore\n ";
		   kode=getch();
		   switch(kode){
		   case 'R':
		   case 'r':  return 1;
		   case 'A':
		   case 'a':  exit(33);
		   case 'I':
		   case 'i': return 0;
				}

 case USERS      : getch();getch(); exit(33);
 case FATALERROR : exit(33);

	   }
return 1;
						 }

Error::~Error(){};
Error::Error(){};
/*			if(a)    cout << "\nОшибка при работе с файлом\n";
			  else    cout << "\nНе могу создать файл\n";
                           cout << name;
		switch(errno){
				 case ENOFILE : cout << "Файл не найден";break;
				 case ENOPATH : cout << "Путь указан неверно";break;
				 case EINVENV : cout << "Ошибка в окружении";break;
				 case EINVFMT : cout << "Ошибочный формат данных";break;
				 case EINVACC : cout << "Доступ к файлу закрыт";break;
				 case EINVDRV : cout << "Ошибочно указано устройство";break;
				 case ENOTSAM : cout << "Нет такого устройства";break;
				 case EMFILE  : cout << "Слишком много открытых файлов";break;
				 case EXDEV   : cout << "Ошибка в FATе";break;
				 default : cout << "Неизвестная ошибка";
				};
			 getche();
			 fclose(mone);
			exit(33);
					};
*/