//#include<string.h>
#include<stdio.h>
#include<conio.h>
#define STRINGH
#define CONIOH
#define STDIOH
#include"tkeys.h"
#include"textbar.hpp"
#include"error.hpp"
#include"sourse.hpp"
#pragma hdrstop

extern "C"
     {
      void far * far _fmemcpy (void far *, const void far *,unsigned long);
      char *strcpy(char *dest, const char *src);
     }

char TextBar::string[256];

void TextBar::decc(void){
 if(tx!=0)tx--;
 else  if(ty>starty){ty--;tx=tdx-1;}
			};



TextBar::TextBar(int a,int b,int c,int d,char * name,char ibox,char iinput,
		 char itext,char iramka):Bar(a,b,c,d,name,ibox){
cinput=iinput;          tdx=(w-6)/8-1;	ty=0;
ctext=itext;            tdy=(h-6)/19-1;     tx=0;
colorramka=iramka;
};





TextBar& TextBar::operator<<(char *a){
	print(a,ctext);
	return *this;};

TextBar& TextBar::operator<<(char a){
	string[0]=a;
	string[1]=0;
	print(string,ctext);
	return *this;};

TextBar& TextBar::operator<<(int a){
	sprintf(string,"%d",a);
	print(string,ctext);
	return *this;};

TextBar& TextBar::operator<<(unsigned long a){
	sprintf(string,"%lu",a);
	print(string,ctext);
	return *this;};

TextBar& TextBar::operator<<(float a){
	sprintf(string,"%f",a);
	print(string,ctext);
	return *this;};

TextBar& TextBar::operator<<(double a){
	sprintf(string,"%.2f",a);
	print(string,ctext);
	return *this;};

/// >>

TextBar& TextBar::operator>>(char& a){
	input();
	a=string[0];
	return *this;}
TextBar& TextBar::operator>>(char* a){
	input();
	strcpy(a,string);
	return *this;}

TextBar& TextBar::operator>>(int& a){
	input();
	sscanf(string,"%d",&a);
	return *this;       }

TextBar& TextBar::operator>>(float& a){
	input();
	sscanf(string,"%f",&a);
	return *this;        }


void TextBar::print(char* a,char color){
char b[2];b[1]=0;
for(int i=0;i<2000;i++)
 switch(a[i]){
   case '\n': 	ty++;tx=0;
   case '\r': 	break;
   case 0   : 	return;
   default: 	if(tx+1>tdx){ty++;tx=0;}
		if(ty>tdy){tx=ty=0;operator!();}
		b[0]=a[i];

		setfillstyle(SOLID_FILL,colordialog);
		bar(xx(tx),yy(ty),xx(tx)+7,yy(ty)+19);

		setcolor(color);
		outtextxy(xx(tx),yy(ty),b);

		tx++;
	      }


error("Ошибка TextBarprint > 2000");
		 }
void TextBar::input(void){
	 char c[2]; c[1]=0;

	 startx=tx;starty=ty;
	 char endi  =0;
	 char ffx,ffy;
	 char j;
	 static char insert=No;

for(int i=0;i<255;)
   switch(c[0]=gtchar()){
      case 0   :	switch((c[0]=gtchar())){
			  case 0x52    : // kbIns
					 insert=insert?No:Yes;
					 if(endi>i){
					 c[0]=string[i];
					 print(c,insert?MAGENTA:LIGHTGREEN);
					 decc();
						   }
					  else i=endi;
					  break;

			  case 0x53    : // kbDel
				      if(i<endi){
				       endi--;
				       ffx=tx;ffy=ty;
				       for(j=i;j<endi+1;j++)
				       string[j]=string[j+1];
				       string[endi]=' ';
				       string[endi+1]=0;
				       tx=startx;ty=starty;
				       print(string,cinput);
				       tx=ffx;ty=ffy;
				       c[0]=string[i];
				       print(c,insert?MAGENTA:LIGHTGREEN);
				       decc();
						 }
				       else i=endi;

					  break;
			  case scLeft  : if(i>0){
					  decc(); i--;
					  c[0]=string[i];
					  ffx=tx;ffy=ty;
					  print(c,insert?MAGENTA:LIGHTGREEN);
					  if(i+1<endi){
					  c[0]=string[i+1];
					  print(c,cinput);
						     }
					   tx=ffx;ty=ffy;
						 }
					    else i=0;

					  break;
			  case scRight : if(endi>i) {
					  c[0]=string[i];i++;
					  print(c,cinput);
					  if(i<endi){
					   c[0]=string[i];
					   print(c,insert?MAGENTA:LIGHTGREEN);
					   decc();
						     }
						 }
					   else i=endi;
						   break;
			   case scClear : if(endi){
					   for(i=0;i<endi+1;i++)
					   string[i]=' ';
					   string[endi+1]=0;
					   tx=startx;ty=starty;
					   print(string,WHITE);
						}
					   tx=startx;ty=starty;
					   endi=i=0;

					 }

		 break;
      case '\b':         if(i>0){
			  endi--;i--;
			  for(int j=i;j<endi+1;j++) string[j]=string[j+1];
			  string[endi]=' ';  string[endi+1]=0;
			  tx=startx;ty=starty;
			  print(string,cinput);
			  decc();
			  if(i<endi){
			   c[0]=string[i];
			   print(c,insert?MAGENTA:LIGHTGREEN);
			    decc();
				    }
				   }
			   break;

      case '\r':	string[endi]=0;return;

      default:          print(c,cinput);string[i]=c[0];
			i++;
			if(i>endi)  endi=i;
			if(endi!=i)
			{
			 if(insert){
			    c[0]=string[i];
			    print(c,insert?MAGENTA:LIGHTGREEN);
			    decc();

				    }
			   else     {
			      ffx=tx;ffy=ty;
			      for(int j=i;j<endi+1;j++)
				 string[j+1]=string[j];
			      string[endi+1]=0;
			      tx=startx;ty=starty;
			      print(string,cinput);
			      tx=ffx;ty=ffy;
			      c[0]=string[i];
			      print(c,insert?MAGENTA:LIGHTGREEN);
			      decc();
			       endi++;
				    }
			 }


		     }
error(USERS,"","Ошибка TextBar::input  > 256");
	 string[255]=0;
		 }


void GroupBar::select(int){
status=stSelect;
 if(flagstart==cmQuit)(*this)(LIGHTRED)(0,0)<<"      Окно закрыто.";
	    setcolor(DARKGRAY);
	    line(x+dlx,y+duy,x+dlx,y+h-ddy);
	    line(x+dlx,y+duy,x+w-drx,y+duy);
	    setcolor(WHITE);
	    line(x+w-drx,y+h-ddy,x+dlx,y+h-ddy);
	    line(x+w-drx,y+h-ddy,x+w-drx,y+duy);

			    }
void GroupBar::unselect(int){
 status=0;
	    Bar::draft();
	    setcolor(LIGHTGRAY);
	    line(x+dlx,y+duy,x+dlx,y+h-ddy);
	    line(x+dlx,y+duy,x+w-drx,y+duy);
	    line(x+w-drx,y+h-ddy,x+dlx,y+h-ddy);
	    line(x+w-drx,y+h-ddy,x+w-drx,y+duy);
 if(flagstart==No)(*program)(*this,cmDraft);
 if(flagstart==cmQuit)(*this)(LIGHTRED)(0,0)<<"      Окно закрыто.";
			     }

int GroupBar::setcomand(void){
   select(0);
   return stSelect;
			   }
void GroupBar::draft(void){
  View::draft();
  if(flagstart==Yes)
    if(setjmp(jwork)!=cmNew)
       {flagstart=No;
	   myne();
       }
			  }



void GroupBar::myne(void){
char steckbuf[300]; //Массив прослойка
 steckbuf[0]=2;steckbuf[0]+=2;
static GroupBar *ykaz;
 ykaz=this;
(*program)(*this,cmGo);
ykaz->flagstart=cmQuit;
longjmp(ykaz->jwork,cmNew);
}

int GroupBar::preprocess(void){
if(Ev.flag==eKeyboard && flagstart!=cmQuit && Ev.press!=kbTab &&
       setjmp(jwork)!=cmNew)
     {if(status==stSelect){ ch=Ev.teg.ch;sk=Ev.teg.sk;}
      else {ch=0;sk=scClear;}
      longjmp(jgetch,cmNew);// трассируем до следующего этапа
			   }
if(Ev.flag==eSys && Ev.press==cmOpros && flagstart==cmQuit){
	 Ev.setevent(comand);
	 return stDelete;
					    }
return 0;
}
char GroupBar::gtchar(void){
static char scan=No;
if(scan){scan=No;return sk;}
if(setjmp(jgetch)!=cmNew)
	    longjmp(jwork,cmNew);// BreakPoint при тассировке
if(ch==0)scan=Yes;
return ch;
			 }

void TextBar::merror(void){print("Данные введены неверно \n :_ ",LIGHTRED);};
word TextBar::xx(byte a)
{return 8*a+x+dlx+2;};
word TextBar::yy(byte a)
{return 19*a+y+duy+2;};
GroupBar::GroupBar(int a,int b,int c,int d,int com,word nhelp,char * name,\
 void (far* k)(GroupBar&,char),char ibox,\
 char iinput,char itext,char iramka):
 TextBar(a,b,c,d,name,ibox,iinput,itext,iramka),
 View(a,b,c,d,com,nhelp,name,kbNoKey){
	mode=modeGroup;
	program=k;forprogram=0;flagstart=Yes;colordialog=ibox;
	tdx=(w-4)/8;tdy=(h-4)/19;

	};
