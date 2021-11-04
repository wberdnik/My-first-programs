#ifndef IOSYS
#define IOSYS
#include"kat0.hpp"
#include"kat1.hpp"
#include"work.hpp"
#include"xar.hpp"
#include"main.hpp"
#include"config.hpp"
#include"excheng.hpp"

class Iosys
{ Live* one;
  Live* spirit;
    char type;
  char type1;
  long stop1;
  long myk;

  public:

  Iosys& down(void);
  Iosys& up(void);
  Iosys& kat(void);

   Iosys(char);
   ~Iosys();
  Iosys& operator[](long a){(*one)[a];return *this;};
  Iosys& operator++(void){++(*one);return *this;};
  Iosys& operator--(void){--(*one);return *this;};
  Iosys& next(void){one->next();return *this;};
  Iosys& save(void){one->save();return *this;};
  void greatspisok(void){one->greatspisok();};
  Iosys& set(char a){
	      error(a>4 || a<0,OPERATOR,"cбойный тип в Iosys:set");
		if(a==type)return *this;
	      int x= (a==tKat1 || a==tXar) - (type==tKat1 || type==tXar);
	     if(x) kat();
	     if(a<type) up();
	     if(a<type) up();
	     if(a>type) down();
	      error(a>type,OPERATOR,"Нельзя использовать двойной down");
	       error(a!=type,SYSTEM,"ошибка в Iosys:: set");
	      return *this;
	   };


  Iosys& ini(void);  // считывание по указателям
     // освобождение указателей с целью перeустановки
  Iosys& free(void){error(type!=tWork,OPERATOR,"Не корректное раб"
  "очее состояние");one->ifcan();return *this;};

  void mark1(void){error(type!=tKat1,OPERATOR,"Не корректное рабочее "
  "состояние mark1");vlad.markfile=one->yk;};
  void mark2(void){error(type!=tXar,OPERATOR,"Не корректное рабочее "
  "состояние mark2");vlad.marktreb=one->yk;};
  void mark3(void){error(type!=tXar,OPERATOR,"Не корректное рабочее "
  "состояние mark3");vlad.markxar=one->yk;};

};

#endif