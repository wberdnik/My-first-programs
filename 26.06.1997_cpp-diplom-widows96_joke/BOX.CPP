#include"box.hpp"
#include"base.hpp"
#include"button.hpp"
#include"tkeys.h"
#include"slave.h"
#include"diagnost.hpp"
#include"lineinpu.hpp"
#include <string.h>
#pragma hdrstop
extern "C" {
   unsigned long farcoreleft(void);
	   };


Box::Box(int vid,char* r):Modals(){
strcpy(KNOW.pathfile,r);
setbase(new Bar(128,57,376,361,vid==cmSaveas?"Save file":"Load file"));
Leaf *c;
insert(c=new Lineinput(160,95,312,19,cmLoad,KNOW.filename));
insert(wind=new ListFile);
insert(new Button(471,207,20,30,cmUp,1003,"Смотреть файлы выше",kbPgUp,"Up"));
insert(new Button(471,257,20,30,cmDown,1003,"Смотреть файлы ниже",kbPgDn,"Dn"));
insert(new Button(190,360,100,30,cmOk,1003,"Согласен",kbAltO,"Установить"));
insert(new Button(350,360,100,30,cmCansel,1003,"Я попал не туда",kbAltC,"От"
					     "менить"));
insert(new MasterButton(cmQuit,"Выход в DOS",kbF10,"Все"));
setfirst(c);
   }


int Box::sys(void){
    switch(Ev.press){
     case cmOk  :
     case cmCansel:	Ev.setevent(cmQuit);return 1;
     default	  :    return 0;
		   }
		       }


//==========================================================================

ListFile::ListFile():View(168,152,296,190,cmQuit),\
  TextBar(168,152,296,190,""){

set(modeGroup,"",WHITE,BLUE);
set(1,1,15,1);

long size=farcoreleft();
size=(size-8000L)/36;    // В запасе только 4 Kb
razmer=int(size<32000L?size:32000L);
name=new char* [razmer];   // по 4 байта
for(int i=0;i<razmer;i++){name[i]=new char[13];name[i][0]=0;}
			 // Запросили все каталоги
nselect=nstart=all=0;
scan();
nstart=0;
};


ListFile::~ListFile(){
for(int i=0;i<razmer;i++) delete name[i];
delete name;
   }


void ListFile::scan(void){
Wait myxa('S');
				// nstart - номер начала блока
struct ffblk dta;
char * c;
int i,j;

char * path=new char[MAXPATH+13];
strcpy(path,KNOW.pathfile);
strcat(path,KNOW.filename);
int  done = findfirst(path,&dta,FA_HIDDEN | FA_DIREC);
delete path;

while(!done){
all++;					// проверяем ? можно дальше ?
if(all>=razmer){error(MESSAGE,"","Не достаточно памяти\n"
		      "для считывания текущ\nего каталога.");return;}

if(!strcmp(dta.ff_name,".")) { all--;goto scanm;}

 c=name[all-1];
 strncpy(c,dta.ff_name,13);                     // записываем в конец

 if(dta.ff_attrib & FA_DIREC){
   for(j=0;j<nstart;j++)                           // сортируем
    if(strncmp(name[j],dta.ff_name,12)>=0){        // найден элемент больше
     for(i=all-1;i>j;i--)name[i]=name[i-1];
     name[j]=c; break;               }
   nstart++;
			     }
else{
   for(j=nstart;j<all-1;j++)                        // сортируем
     if(strncmp(name[j],dta.ff_name,12)>=0){         // найден элемент больше
       for(i=all-1;i>j;i--)name[i]=name[i-1];
	name[j]=c;break;                    }
   strlwr(c);
  }

   c[12]=dta.ff_attrib;		   // запоминаем атрибуты
scanm:      done = findnext(&dta);                     // ищем следующий
   }
}


void ListFile::show(void){
setcolor(DARKGRAY);line(x+w/2,y+1,x+w/2,y+h-1);
(*this)(LIGHTGREEN);
char c;char *d;
for(int i=0;i<all&&i<18;i++){
d=name[i+nstart];
c=d[12];d[12]=0;
hiden();
(*this)(i<9?1:w/16+1,i<9?i:i-9)<<d;
d[12]=c;

			    }
}


void ListFile::modeselect(void){
char *d=name[nselect+nstart];
char c=d[12];d[12]=0;
(*this)(status==stSelect?LIGHTRED:LIGHTGREEN)\
(nselect<9?1:w/16+1,nselect<9?nselect:nselect-9)<<d;
d[12]=c;
}




int ListFile::setcomand(void){
   Ev.clear();
   return No;
				   }
void ListFile::draft(void){
TextBar::draft();show();modeselect();}


void ListFile::hiden(void){
setfillstyle(SOLID_FILL,BLUE);
int F=(nselect%9)*19+y;
if(nselect>9)
 bar(x+w/2+2,F,x+w-2,F+17);
else
 bar(x+2,F,x+w/2-2,F+17);

F=status;status=0;
modeselect();status=F;}



void ListFile::add(int a){
if(nselect+a<18)nselect+=a;
else {
if(nstart>=all-18)return;
nstart=nstart+a>all-18?all-18:nstart+a;
      }
setnsel();
modeselect();
		   }

void ListFile::sub(int a){
if(nselect-a>0)nselect-=a;
else{
if(nstart==0)return;
nstart=nstart-a<0?0:nstart-a;
    }
setnsel();
modeselect();

		   }

void ListFile::findalpha(void){}


void ListFile::setnsel(void){
char b;
hiden();
if(nselect<nstart || nselect>=all-nstart)
if(Body()){
nselect=Ev.x>x+w/2?9:0;
b=(Ev.y-duy)/19;
nselect+=b>8?8:b;
if(nselect+nstart>=all)nselect=all-nstart;
	    }
else nselect=nstart;
show();            }




int ListFile::preprocess(void){
  switch(Ev.flag){
    case eSys :switch(Ev.press){
	      case cmLoad :nselect=nstart=all=0;scan();nstart=0;break;
	      case cmUp	:  sub(8);break;
	      case cmDown: add(8);break;
	      case cmHome: sub(nstart+nselect);break;
	      case cmEnd : add(all-19-nstart-nselect);break;
	      default: return stDelete;
		 }
	      return stDelete;

    case eKeyboard: if(status!=stSelect)return stDelete;
      switch(Ev.press){
		 case kbUp	: sub(1);break;
		 case kbDown	: add(1);break;
		 case kbLeft	: sub(9);break;
		 case kbRight	: add(9);break;
		  default : findalpha();return stDelete;
		    }

     }
return stDelete;
}

