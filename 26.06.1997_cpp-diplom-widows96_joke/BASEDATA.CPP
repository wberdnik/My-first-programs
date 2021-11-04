#include"basedata.hpp"
#include"button.hpp"
#include"function.hpp"
#include"tkeys.h"
#include<string.h>
#pragma hdrstop

char* con="пуста";

BaseData::BaseData(int a,char* b):Modals(),Dbf(a,b){
base=0;Wait::operator--();
};

Cabel::~Cabel(){
if(dbfinfo==dbfSboi)return;
SaveData();
}
Concent::~Concent(){
if(dbfinfo==dbfSboi)return;
SaveData();
}

int BaseData::sys(void){
switch(Ev.press){
 case cmB1   : movefirst(mas[1]);return 1;
 case cmB2   : movefirst(mas[2]);return 1;
 case cmB3   : movefirst(mas[3]);return 1;
 case cmB4   : movefirst(mas[4]);return 1;
 case cmB5   : movefirst(mas[5]);return 1;
 case cmB6   : movefirst(mas[6]);return 1;
 case cmB7   : movefirst(mas[0]);return 1;


 case cmWait : Ev.setevent(cmUpButton);return 0;
 case cmAuto : if(base>=end || end<2)return 1;
		(*this)[base];
		(Base::operator()(end-1))-1;
		base=base>0?base-1:0;
		LoadData();
		break;


 case cmDown :  if(base>(long)end-1)return 1;
		SaveData();
		base++;
		if(base==end)FreeData();
		 else LoadData();
		 break;

 case cmUp   : if(base==0)return 1;
		  SaveData();
		  base--;
		 LoadData();break;
default : return 0;
		}
 (*out)(1,1)<<"N записи : "<<(base+1);
 return 1;
 }


Cabel::Cabel():BaseData(baseCabel,"netcab.dbf"){
if(dbfinfo==dbfSboi){Message("Не возможно создать файл БД.");
		     return;}
setbase(out=new TextBar(92,125,448,160,"БД по кабелям"));
out->set(300,5,60,20);
insert(mas[4]=mas[0]=new Lineinput(230,145,260,19,cmB1,con));
insert(mas[5]=mas[1]=new Lineinput(230,175,80,19,cmB2,con));
insert(mas[6]=mas[2]=new Lineinput(230,205,80,19,cmB3,con));
insert(mas[3]=new Lineinput(410,175,80,19,cmB7,con));
if(end==0)FreeData(); else LoadData();

insert(new Button(118,240,90,30,cmUp,10,"Назад",kbPgUp,"<< Назад"));
insert(new Button(218,240,90,30,cmDown,10,"Еще",kbPgDn,"Еще >>"));
insert(new Button(318,240,90,30,cmAuto,10,"Удаление",0,"Удаление"));
insert(new Button(440,240,90,30,cmQuit,1005,"Работа завершена",0,"Все"));
};
void Cabel::draft(void){
Modals::draft();
setcolor(BLACK);
outtextxy(105,148,"Наименование");
outtextxy(105,178,"Число жил"); outtextxy(317,178,"Цена");
outtextxy(105,208,"Частота");
(*out)(BLACK)(1,1)<<"N записи : "<<(base+1);
	       }


void Cabel::LoadData(void){
(*this)[base]>>(void*)&zapis;
(*mas[0])=zapis.name;

 sprintf(str,"%ld",zapis.potok);(*mas[1])=str;
 sprintf(str,"%ld",zapis.outfq);(*mas[2])=str;
 sprintf(str,"%ld",zapis.cena);(*mas[3])=str;
		     }

void Cabel::SaveData(void){
 zapis.ident=' ';
 strncpy(zapis.name,*mas[0],19);

 strcpy(str,*mas[1]); sscanf(str,"%ld",&zapis.potok);
 strcpy(str,*mas[2]); sscanf(str,"%ld",&zapis.outfq);
 strcpy(str,*mas[3]); sscanf(str,"%ld",&zapis.cena);

  if(strncmp(zapis.name,con,strlen(con))|| end<1){
   if(base==end)(*this)+1;
   (*this)[base]<<(void*)&zapis;           }
		     }
void Cabel::FreeData(void){
(*mas[0])=con;
(*mas[1])=(*mas[2])=(*mas[3])="0";
		     }

Concent::Concent():BaseData(baseConcen,"netcon.dbf"){
if(dbfinfo==dbfSboi){Message("Не возможно создать файл БД.");
		     return;}
setbase(out=new TextBar(92,85,448,220,"БД по концентраторам"));
out->set(300,5,130,20);

insert(mas[0]=new Lineinput(227,105,260,19,cmB1,con));
insert(mas[1]=new Lineinput(227,135,80,19,cmB2,con));
insert(mas[2]=new Lineinput(227,165,80,19,cmB3,con));
insert(mas[3]=new Lineinput(227,195,80,19,cmB4,con));
insert(mas[4]=new Lineinput(437,135,80,19,cmB5,con));
insert(mas[5]=new Lineinput(437,165,80,19,cmB6,con));
insert(mas[6]=new Lineinput(437,195,80,19,cmB7,con));
if(end==0)FreeData(); else LoadData();


insert(new Button(117,260,90,30,cmUp,10,"Назад",kbPgUp,"<< Назад"));
insert(new Button(217,260,90,30,cmDown,10,"Еще",kbPgDn,"Еще >>"));
insert(new Button(317,260,90,30,cmAuto,10,"Удалить",0,"Удалить"));
insert(new Button(440,260,90,30,cmQuit,1005,"Работа завершена",0,"Все"));
};
void Concent::draft(void){
Modals::draft();
setcolor(BLACK);
outtextxy(105,108,"Наименование ");
outtextxy(105,138,"Жил на 1 вход"); outtextxy(317,138,"Вход  частота");
outtextxy(105,168,"Число выходов"); outtextxy(317,168,"Вых.  частота");
outtextxy(105,198,"Число  входов"); outtextxy(317,198,"Цена");

(*out)(BLACK)(1,1)<<"N записи : "<<(base+1);
	       }


void Concent::LoadData(void){
(*this)[base]>>(void*)&zapis;
(*mas[0])=zapis.name;

 sprintf(str,"%d",zapis.inpotok);(*mas[1])=str;
 sprintf(str,"%ld",zapis.potok);(*mas[2])=str;
 sprintf(str,"%d",zapis.input);(*mas[3])=str;
 sprintf(str,"%ld",zapis.infq);(*mas[4])=str;
 sprintf(str,"%ld",zapis.outfq);(*mas[5])=str;
 sprintf(str,"%ld",zapis.cena);(*mas[6])=str;
    }

void Concent::SaveData(void){
 zapis.ident=' ';
 strncpy(zapis.name,*mas[0],29);
 strcpy(str,*mas[1]); sscanf(str,"%d",&zapis.inpotok);
 strcpy(str,*mas[2]); sscanf(str,"%ld",&zapis.potok);
 strcpy(str,*mas[3]); sscanf(str,"%d",&zapis.input);
 strcpy(str,*mas[4]); sscanf(str,"%ld",&zapis.infq);
 strcpy(str,*mas[5]); sscanf(str,"%ld",&zapis.outfq);
 strcpy(str,*mas[6]); sscanf(str,"%ld",&zapis.cena);
 if(strncmp(zapis.name,con,strlen(con))|| end<1){
   if(base==end)(*this)+1;
   (*this)[base]<<(void*)&zapis;           }
		     }
void Concent::FreeData(void){
(*mas[0])=con;
(*mas[1])=(*mas[2])=(*mas[3])=(*mas[4])=(*mas[5])=(*mas[6])="0";
		     }
BaseData:: ~BaseData(){};