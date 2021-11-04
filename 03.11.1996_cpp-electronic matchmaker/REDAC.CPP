#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<bios.h>

extern char line3[];
extern char dop[11];
extern char dop_10[49];
extern void massege7(void);

#define LEFT        0x4b00
#define RIGHT       0x4d00
#define ESC         0x011b
#define CR          0x1c0d
#define BACKSPASE   0x0e08

/******ฅค ชโฎเ แโเฎชจ******/

void vv(void)
 {
   char g;
   int i,j,h,x=1;

   g=' ';
   strcpy(dop,"          ");
   dop[0]=0;
   massege7();

   gotoxy(x,1);
   for(i=0;i<11;i++)
    {
     h=bioskey(0);
     g=h;
     switch(h)
       {
	 case ESC:
	      {
	       strcpy(dop,"");
	       i=11;
	       break;
	      }
	 case CR:
	      {
	       for(j=0;j<11;j++)
		 {
		  if(dop[j]==' '&&dop[j+1]==' ')
		    {
		      dop[j]=0;
		      j=11;
		      i=11;
		      break;
		    }
		 }
	       dop[10]=0;
	       j=11;
	       i=11;
	       break;
	      }
	 case LEFT:
	      {
	       if(x>1)
		 {
		  i=i-2;
		  x--;
		  gotoxy(x,1);
		 }
	       else
		  i=-1;
	       break;
	      }
	 case RIGHT:
	      {
		if(x==10)
		  i--;
	       if(x<10)
		 {
		  x++;
		  gotoxy(x,1);
		 }
	       break;
	      }
	 case BACKSPASE:
	      {
	       if(x>1)
		 {
		  i--;
		  for(j=i;j<10;j++)
		     dop[j]=dop[j+1];
		  dop[10]=0;
		  clrscr();
		  gotoxy(1,1);
		  cprintf("%s",&dop);
		  x--;
		  if(x==0)
		   {
		     i=0;
		     x=1;
		   }
		  gotoxy(x,1);
		  i--;
		 }
	       break;
	      }
	 default:
	     {
	      if(i==10)
	       i--;
	      if(i!=10&&x<11)
	       {
		textcolor(0);
		dop[i]=g;
		gotoxy(x,1);
		cprintf("%s",&dop[i]);
		x++;
		gotoxy(x,1);
		if(i==9)
		  {
		   x=10;
		   gotoxy(x,1);
		   i=8;
		  }
	       }
	     }
       }
     }
     window(22,4,54,12);
     textbackground(BLUE);
     clrscr();
     window(1,1,80,25);

  }

/******ฅค ชโฎเ แโเฎชจ******/
void vv_1(void)
 {
   char g;
   int i=0,j,h,x=1;

   g=' ';
   strcpy(dop_10,"                                        ");
   dop[0]=0;


   window(16,15,63,21);
   textbackground(0);
   clrscr();
   window(15,14,63,21);
   textbackground(LIGHTCYAN);
   textcolor(WHITE);
   gotoxy(1,1);
   cprintf("ษออออออออออออออออออออออออออออออออออออออออออออออป\n\r");
   cprintf("บ                                              บ\n\r");
   cprintf("บ             ขฅคจโฅ ญฎขฎฅ จฌ๏:               บ\n\r");
   cprintf("บ                                              บ\n\r");
   cprintf("บ                                              บ\n\r");
   cprintf("บ             ESC-ฎโฌฅญจโ์ ขขฎค                บ\n\r");
   cprintf("ศออออออออออออออออออออออออออออออออออออออออออออออผ\n\r");

   window(17,17,60,17);
   textbackground(WHITE);
   textcolor(0);
   clrscr();
   window(17,17,60,17);


   gotoxy(x,1);
   for(i=0;i<49;i++)
    {
     h=bioskey(0);
     g=h;
     switch(h)
       {
	 case ESC:
	      {
	       strcpy(dop_10,"");
	       i=49;
	       break;
	      }
	 case CR:
	      {
	       for(j=0;j<49;j++)
		 {
		  if(dop_10[j]==' '&&dop_10[j+1]==' ')
		    {
		      dop_10[j]=0;
		      j=49;
		      i=49;
		      break;
		    }
		 }
	       dop_10[48]=0;
	       j=49;
	       i=49;
	       break;
	      }
	 case LEFT:
	      {
	       if(x>1)
		 {
		  i=i-2;
		  x--;
		  gotoxy(x,1);
		 }
	       else
		  i=-1;
	       break;
	      }
	 case RIGHT:
	      {
		if(x==43)
		 {
		  i--;
		 }
	       if(x<43)
		 {
		  x++;
		  gotoxy(x,1);
		 }
	       break;
	      }
	 case BACKSPASE:
	      {
	       if(x>1)
		 {
		  i--;
		  for(j=i;j<48;j++)
		   {
		     dop_10[j]=dop_10[j+1];
		   }
		  dop_10[48]=0;
		  clrscr();
		  gotoxy(1,1);
		  cprintf("%s",&dop_10);
		  x--;
		  if(x==0)
		   {
		     i=0;
		     x=1;
		   }
		  gotoxy(x,1);
		  i--;
		 }
	       break;
	      }
	 default:
	     {
	      if(i==43)
	       i--;
	      if(i!=43&&x<44)
	       {
		dop_10[i+1]=0;
		dop_10[i]=g;
		gotoxy(x,1);
		cprintf("%s",&dop_10[i]);
		x++;
		gotoxy(x,1);
		if(i==42)
		  {
		   x=43;
		   gotoxy(x,1);
		   i=41;
		  }
	       }
	     }
       }
    }
   window(15,14,63,21);
   textbackground(BLUE);
   clrscr();
   window(1,1,80,25);
   textcolor(0);

  }