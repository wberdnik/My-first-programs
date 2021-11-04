#include"cler.hpp"
#include<process.h>
Cler::Cler(Iosys* a,long n_kat,long n_cler):Spisok(sizeof(SLOT)),at((char*)&t)
 {
    from=a;
    if(from==NULL){
		  error(1,OPERATOR,"Не инициализиирована CУБД");
		  exit(1);
		  }
      // найдем нужный подкаталог
     (((from->set(tKat0)[n_kat]).set(tMain))[n_cler]).set(tWork);
     //запросим список
     (*this)+vlad.stop;

     for(long i=0;i<end;i++){
      ((*from)[i]).ini(); // считали
      t.file=vlad.file;   // номер характеристики
      t.treb=vlad.treb;   // характеристика идеала
      t.xar=vlad.xar;     // характеристика себя
      t.weightfb=vlad.weighttr;
      t.weigt=vlad.weigt; // оценка требования
      t.weigx=vlad.weigtqullity; // своя оценка
      t.others=vlad.others; // номер правила в базе знаний
      (*this)[i]=at;      // записали
      }
}
 SLOT& Cler::find(long a){
	SLOT *c=(SLOT*)at.data;
	for(long i=0;i<end;i++){
   at=(*this)[i];
	 if(c->file==a)return *c;
	 }
	c->file=-1;
	return *c;
 }
