#include<mem.h>
#include"work.hpp"
#include"excheng.hpp"
#include"config.hpp"
#include"xar.hpp"
typedef struct {
               char del;
               long file;
               long treb;
               long xar;
               long weight;
               long others;
               int acsess;} work;

Work::~Work()
{char a;
 a=stop==0?'*':' ';
 Dbf* x=new (0) Dbf(tMain);
 Var ll(x->dlins);
 ll=(*x)[root];
 ll.data[0]=a;
 (*x)[root]=ll;
  delete x;
 dest();
};

void Work::build(char b)
{error(sizeof(work)!=23,SYSTEM,"Убери в опциях выравнивание к параграфу");
work* a=(work*)at.data;
if(!b){
	a->del=' ';
	a->file=vlad.markfile;
	a->treb=vlad.marktreb;
	a->xar=vlad.markxar;
	a->weight=vlad.weigt;
	a->others=vlad.marktreb==-1?-1:vlad.others;
	a->acsess=vlad.acsess;
       }
 else{a->del='*';
      a->file=-1;
      a->treb=-1;
      a->xar=-1;
      a->weight=0;
      a->others=-1;
      a->acsess=0;
      }

 };
void Work::debuild(void)
{work* a=(work*)at.data;
 a->del='*';
 vlad.file=a->file;
 vlad.treb=a->treb;
 vlad.xar=a->xar;
 vlad.weigt=a->weight;
 vlad.others=a->others;
 vlad.acsess=a->acsess;
};
//*********************************************************************
int Work::ifcan(void)
{Dbf* var;
 Var* wir;
 if(vlad.file<0 || (vlad.treb==-1 && vlad.xar==-1)) return 1;


  var= new (0) Dbf(tKat1);
  wir=new (0) Var(var->dlins);
  if(vlad.file>=var->end) {
	      error(1,OPERATOR," \nСбой vlad.file > end");
			    return 1;}


  *wir=(*var)[vlad.file];         //считали нужную запись
     vlad.file=-1;
  delete var;                     // закрыли файл
  char c[9];
  memcpy(c,vlad.namexar,9);        //сбросили в буфер
  wir->data[21]=0;
  memcpy(vlad.namexar,wir->data+12,9); //подготовили имя
  var=new (0) Dbf(tXar);
  delete wir;
  memcpy(vlad.namexar,c,9);           //востановили из буфера
  wir=new (0) Var(var->dlins);
XAR * my=(XAR*)wir->data;

if(vlad.treb!=-1)
  {*wir=(*var)[vlad.treb];     // считали
    my->chethik=-1;
  (*var)[vlad.treb]=*wir;    //записали
  }

if(vlad.xar!=-1)
  {*wir=(*var)[vlad.xar];
   my->chethik=-1;
  (*var)[vlad.xar]=*wir;
  }

  delete wir;
  delete var;

  vlad.file=-1;  // очистили
  vlad.treb=-1;
  vlad.xar=-1;

return 1;}

void Work::save(void)
{Dbf* var;
 Var* wir;

  ifcan(); //ocвободим

 if(vlad.markfile<0  || (vlad.marktreb==-1 && vlad.markxar==-1))
	  {    		vlad.marktreb=-1;
			vlad.markxar=-1;
			vlad.markfile=-1;
			Live::save();
			return;};

  var= new (0) Dbf(tKat1);
       if(vlad.markfile>=var->end){
	      error(1,OPERATOR,"Сбой vlad.markfile");

			vlad.markfile=-1;
			vlad.marktreb=-1;
			vlad.markxar=-1;
			delete var;
			Live::save();
			return;};

  wir=new (0) Var(var->dlins);
  *wir=(*var)[vlad.markfile];
  delete var;
				 //алгоритм смотри выше
  char c[9];
  memcpy(c,vlad.namexar,9);
  wir->data[21]=0;
  memcpy(vlad.namexar,wir->data+12,9);
  var=new (0) Dbf(tXar);
  delete wir;
  memcpy(vlad.namexar,c,9);

  wir=new (0) Var(var->dlins);
XAR* my=(XAR*)wir->data;

if(vlad.marktreb!=-1)
  {*wir=(*var)[vlad.marktreb];
    my->chethik+=1;
  (*var)[vlad.marktreb]=*wir;
  }

if(vlad.markxar!=-1)
  {*wir=(*var)[vlad.markxar];     //
  my->chethik+=1;
  (*var)[vlad.markxar]=*wir;
  }

  delete wir;
  delete var;
  Live::save();

vlad.markfile=-1;           //сегодня чистый четверг/
vlad.marktreb=-1;
vlad.markxar=-1;
return;}


