#include"driver.hpp"
#include"base.hpp"

Driver::Driver(Iosys* a,long n_kat,long n_men,long n_group){
 homer=new(0)Cler(a,n_kat,n_men);
 n_gr=n_group;
 end=0;
 base=a;
		     }

void Driver::run(char mark){
  marks* t;

 (base->set(tKat0))[n_gr].set(tMain);      // Определили размер группы
   size_group=vlad.stop;
   end=size_group;
  comp=new (0) Comp(size_group,mark);      // Подготовили блок оценки

  for(long i=0;i<size_group;i++){          // цикл перебора кандидатов

      (*comp)[i];                          // возмем чистый шаблон оценки

     kandidat=new (0) Cler(base,n_gr,i);   // считывание кандидата



      t=&(comp->get());

                      //полная инициализация структуры  оценки               

      t->qme   = (int)homer->end;         
      t->qyou  = (int)kandidat->end;
      t->enable=0;
      t->enable1=0;
      t->forme =0;
      t->foryou=0;
      t->marks =0;
			t->hu    =i;

                      // оценка соответствия двух кандидатур

			for(long j=0;j<homer->end;j++) {       // все требования заказчика
			 (*homer)[j];
			 comp->run(homer->get(),kandidat->find(homer->get().file));
                          					}       // сравнили


      delete kandidat;                      // забудем этого клиента

      t->marks=aprior(*t);                  // и дали ему окончательную
			                                      // оценку
        	 }
      // все завершено 
      // поэтому забудем и о клиенте

    delete homer;

 }

float Driver::aprior(marks& a){
    return ((a.forme+a.foryou)*(a.enable+a.enable1))/(a.qme+a.qyou);
			      }

void Driver::sort(int number){
 Wait wi('?');
 float max;
 long nmax;
 float c;
 long j;

 for(long i=0;i<number && i<comp->end;i++){
					// поиск максимума
  nmax=i;(*comp)[i];max=comp->get().marks;

   for(j=i+1;j<comp->end;j++){
     (*comp)[j];
     c=comp->get().marks;
     if(max<c){max=c;nmax=j;}
			     }
    if(nmax!=i)					// сортировка
		((*comp)[i])(nmax);
			   // поменяли i и j
			  }
     }
