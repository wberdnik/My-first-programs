#include "error.hpp"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<errno.h>

char* errtext [12]={		"\n����� ������",
				"\n����� �������",
				"\n����� ����",
				"\n����� �����",
				"\n��� �����",
				"\n���� �� .dbf",
	"\n ��४��⭠� ��뫪� � ��",
	"\n ���⥬�� ᡮ�",
	"\n �訡�� ����䥩� ���㫥� ",
	"\n ����� �������� ࠧ��� 䠩�� ",
	"\n ���宩 䠩� ���䨣��樨",
	"\n ���⥬��� �।�०�����"
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
				 case ENOFILE : cprintf( "���� �� ������");break;
				 case ENOPATH : cprintf( "���� 㪠��� ����୮");break;
				 case EINVENV : cprintf("�訡�� � ���㦥���");break;
				 case EINVFMT : cprintf("�訡��� �ଠ�");break;
				 case EINVACC : cprintf("��� ����㯠 � 䠩��");break;
				 case EINVDRV : cprintf("�訡�筮 㪠��� ���");break;
				 case ENOTSAM : cprintf("��� ⠪��� ���ன�⢠");break;
				 case EMFILE  : cprintf("���誮� ����� ������� 䠩���");break;
				 case EBADF   : cprintf("�訡��� ����� 䠩��");break;
				 case EXDEV   : cprintf("�訡�� � FAT�");break;
				 default : cprintf("�������⭠� �訡��");
			}
		 gotoxy(5,14);
		 cprintf("\n �४����-1  �த������ -2");
		 window(1,1,80,25);
		 if(getche()=='2')return;
		  exit(1);}
	 }

