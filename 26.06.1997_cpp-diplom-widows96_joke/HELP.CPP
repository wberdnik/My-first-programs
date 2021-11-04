#include"help.hpp"
#include"button.hpp"
#include"sourse.hpp"
#include"function.hpp"
#include"tkeys.h"
#pragma hdrstop

const char maxy=14;
const char maxx=65;


Help::Help(char* b):Modals(){

File* file=new File(b);
string=NULL;
if(file->end==0||file->end>60000L){Message("Нет необходимого файла");
		 delete file;return;}
string=new char[unsigned (file->end)+1];
unsigned razm=(unsigned)file->end;
(*file)%int(file->end-1);
(*file)>>string;
delete file;

number=0;
char strok=0,stolb=0;

for(unsigned i=0;i<razm;i++)
switch(string[i]){
case 0: string[i]=' ';break;
case '\n' : strok++;stolb=0; break;
default :  stolb++;
	if(stolb>=maxx){
	   strok++;
	   stolb=0;}
	if(strok>=maxy){
	  number++;
	  strok=0;
	   string[i-1]=0; }
		 }
if(string[razm]){
string[razm]=0;  number++;}

locals=string;
that=0;

setbase(pvv=new TextBar(50,50,540,360,NULL,LIGHTGRAY));
pvv->set(modeDialog,"Справка",WHITE,BLUE);
pvv->set(10,10,10,60);

insert(new Button(110,365,90,30,cmUp,10,"Назад",kbPgUp,"<< Назад"));
insert(new Button(210,365,90,30,cmDown,10,"Еще",kbPgDn,"Еще >>"));
insert(new Button(450,365,90,30,cmQuit,1005,"Работа завершена",0,"Все"));
};


void Help::draft(void){
Modals::draft();
(*pvv)(YELLOW)(1,1)<<locals;        }


int Help::sys(){
int i=Ev.press;
switch(i){
	case cmDown :  i=1;
		       if(that<number-1){
		       that++;
		       for(i=0;locals[i]!=0 && i<1000;i++);
		       locals+=i+1;
		       draft();        }
		       Ev.setevent(cmUpButton);return 1;

	case cmUp   :  if(that>0){
			that--;
		    for(i=0;i<2;i++)while((--locals)[0]&&locals>=string);
			 locals++;
			 draft();
				  }
			Ev.setevent(cmUpButton);return 1;

	default : return 0;

	       }
 }

Help::~Help(){
if(string)delete string;};





