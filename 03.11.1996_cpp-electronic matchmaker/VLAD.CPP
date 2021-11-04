#include<dos.h>
#include<stdlib.h>
#include<stdio.h>

#include"new.hpp"
#include"vlad.hpp"

 struct OKO okno[25];

 char buf;

unsigned far * _mvideo=(unsigned far *)0xb8000000L;

void gotoh(char x,char y)
{
   union REGS inregs, outregs;
   struct SREGS segregs;

   inregs.h.ah = 0x2;
   inregs.h.dh = y;
   inregs.h.dl = x;
   inregs.h.bh = 0;
   int86x(0x10, &inregs, &outregs, &segregs);
};

Scr::Scr(char a){
a++;
x=wherex();
y=wherey();
line=new unsigned[2000];
if(line!=0)
for(int i=0;i<2000;line[i]=_mvideo[i])i++;
}

void Scr::operator!(void){
if(line!=0)
  for(int i=0;i<2000;_mvideo[i]=line[i])i++;
}

Scr::~Scr(){
 !(*this);
if(line!=0) delete line;
gotoh(x,y);
}

Win::Win():fr(1)
{ n=0;
 textattr(BLUE*16+YELLOW); clrscr();
};

Win::~Win()
 {for(int i=0;i<n;i++)
	 if(okno[n].flag)delete okno[n].b;
 };

void Win::kprintf(char* ai,char* bi)
{if(n>25)return;
 okno[n].flag=0;
 okno[n].a=ai;
 okno[n].b=bi;

 gotoh(0,n);
 cprintf(ai);
 gotoh(40,n);
 cprintf(bi);
 n++;

};
void Win::kprintf(char* ai,long* bi)
{if(n>25)return;
 okno[n].flag=1;
 okno[n].a=ai;
 okno[n].k=bi;
 char* string=new (0) char[40];
 ltoa(*bi,string,10);
 okno[n].b=string;

 gotoh(0,n);
 cprintf(ai);
 gotoh(40,n);
 cprintf(string);
 n++;
}

void Str::color (int a)
{char far * b=(char far *)_mvideo+nstr*160+81;
 for(int i=0;i<80;i+=2)  b[i]=a;
};

void Str::edit(void)
{color(YELLOW+16*GREEN);
 gotoh(40,nstr);
 if((buf=getch())=='\r')
       {gotoh(40,nstr);
	textattr(YELLOW+16*CYAN);
	cprintf("                                        ");
	gotoh(40,nstr);
	if(okno[nstr].flag)
	    {*okno[nstr].k=0;
	     cscanf("%d",okno[nstr].k);ltoa(*okno[nstr].k,okno[nstr].b,10);}
	else
	    cscanf("%s",okno[nstr].b);
       textattr(BLUE*16+YELLOW);
       gotoh(40,nstr);
       color(YELLOW+16*GREEN);
       buf=0;
       }
};

void Win::edit(void)
{int tr=0;
do{
 Str* vd=new (0) Str(tr);
 if(buf==0)buf=getch();
 if(buf=='P' && tr<n-1)tr++;
  else if(buf=='H'&& tr>0)tr--;
	  else if(buf!=27) while(buf!=27 && (buf=getch())!=0);
 delete vd;
}
while(buf!=27);
}


