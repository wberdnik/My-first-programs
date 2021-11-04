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
     "\t0 - работа с файлом   \n"
    " \t1 - войти             \n"
    " \t2 - добавить          \n"
    " \t3 - выйти             \n"
    " \t4 - инициализовать    \n"
    " \t5 - пометить kat      \n"
    " \t6 - освободить        \n"
    " \t7 - сменить каталог   \n"
    " \t8 - создать список    \n"
    " \t9 - удалить           \n"
    " \t10 - метка treb        \n"
    " \t11 - метка xar         \n"
    " \t12 - завершение работы \n"
    " \t13 - указатель         \n"
    " \t14 - Доктор            \n"
    " \tВведите what  ");
scanf("%d",&x);
switch(x)
{case 0 :{while(1)      {clrscr();
			 printf("\n Введите n записи (9-выход) \t");
			 scanf("%d",&x);
			 if(x<0)break;
			 if(vlad.stop<=x){x=vlad.stop-1;printf("error");getch();}
			 b[x];
			 vlad.edit();
			 printf("Записать ?");
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
			 printf("\n Введите n записи (9-выход) \t");
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