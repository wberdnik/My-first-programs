#ifdef PROECT
#include<conio.h>
#include<string.h>
#include"c:\swaha\iosys.hpp"
main()
{Scr fi(1);

 strcpy(vlad.nameconfig,"c:\\swaha\\swaha.cfg");
	vlad.edit();

 Iosys b;
	 int x;

while(1)
{textbackground(BLACK);
 textcolor(WHITE);
 clrscr();
	printf("\n\n"
     "\t0 - ࠡ�� � 䠩���   \n"
    " \t1 - ����             \n"
    " \t2 - ��������          \n"
    " \t3 - ���             \n"
    " \t4 - ���樠��������    \n"
    " \t5 - ������� kat      \n"
    " \t6 - �᢮������        \n"
    " \t7 - ᬥ���� ��⠫��   \n"
    " \t8 - ᮧ���� ᯨ᮪    \n"
    " \t9 - 㤠����           \n"
    " \t10 - ��⪠ treb        \n"
    " \t11 - ��⪠ xar         \n"
    " \t12 - �����襭�� ࠡ��� \n"
    " \t13 - 㪠��⥫�         \n"
    " \t14 - �����            \n"
    " \t������ what  ");
scanf("%d",&x);
switch(x)
{case 0 :{while(1)      {clrscr();
			 printf("\n ������ n ����� (9-��室) \t");
			 scanf("%d",&x);
			 if(x<0)break;
			 if(vlad.stop<=x){x=vlad.stop-1;printf("error");getch();}
			 b[x];
			 vlad.edit();
			 printf("������� ?");
			 if(getch()=='y')
			 b.save();
			 };
			break;
			};
 case 1 :{b.down();break;};
 case 2 :{b++;break;};
 case 3 :{b.up();break;};
 case 4 :{b.ini();break;};
 case 5 : {b.mark1();break;};
 case 6 :{b.free();break;};
 case 7 :{b.kat();break;};
 case 8 :{b.greatspisok();break;};
 case 9 : {b--;break;};
 case 10 :{b.mark2();break;};
 case 11 :{b.mark3();break;};
 case 13 :{clrscr();
			 printf("\n ������ n ����� (9-��室) \t");
			 scanf("%d",&x);
			 if(x<0)break;
			 if(vlad.stop<=x){x=vlad.stop-1;printf("error");getch();}
			 b[x];
	   };
 case 14 :{;};



};
if(x==12)break;
};
 textattr(BLACK*16+WHITE);clrscr();
 return 0;
 }
#endif