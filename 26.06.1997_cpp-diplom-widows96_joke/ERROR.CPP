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

#define FATALERROR  5   // �⠫쭠�

extern"C" {
	  void sound(unsigned);
	  void nosound(void);
	  void delay(unsigned);
	  }


Error error;
void Error::operator()(char* a){
operator()(FATALERROR,"",a);    }


int Error::operator()(int kode,char* c,char* d){
if(kode==0)return 0;                // c - coo�饭�� 1
char* e="��������";                // d - c���饭�� 2
 switch(kode){
 case MESSAGE    : e="����饭��";break;
 case WARNING    : e="�।�०�����";break;
 case ERROR      : e="�訡��";break;
 case FATALERROR : c="������� � ࠧࠡ��稪��";
		   e="���਩��� �����襭��";break;
 case USERS      : c="���ࠢ��쭮� �ᯮ�짮�����."
		     "������ �孨�᪮�\n�㪮����⢮ : ";
		   e="���਩��� �����襭��";break;
 case ERRORFILE  : e=" �஡���� ࠡ��� � OS";
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
/*			if(a)    cout << "\n�訡�� �� ࠡ�� � 䠩���\n";
			  else    cout << "\n�� ���� ᮧ���� 䠩�\n";
                           cout << name;
		switch(errno){
				 case ENOFILE : cout << "���� �� ������";break;
				 case ENOPATH : cout << "���� 㪠��� ����୮";break;
				 case EINVENV : cout << "�訡�� � ���㦥���";break;
				 case EINVFMT : cout << "�訡��� �ଠ� ������";break;
				 case EINVACC : cout << "����� � 䠩�� ������";break;
				 case EINVDRV : cout << "�訡�筮 㪠���� ���ன�⢮";break;
				 case ENOTSAM : cout << "��� ⠪��� ���ன�⢠";break;
				 case EMFILE  : cout << "���誮� ����� ������� 䠩���";break;
				 case EXDEV   : cout << "�訡�� � FAT�";break;
				 default : cout << "�������⭠� �訡��";
				};
			 getche();
			 fclose(mone);
			exit(33);
					};
*/