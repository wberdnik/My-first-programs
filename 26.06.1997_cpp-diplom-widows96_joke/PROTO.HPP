#ifndef PROTO
#define PROTO

#ifndef  LEAF
#include "Leaf.hpp"
#endif




class Proto:public Leaf{
protected:
  Leaf* first;				// Элементы Z порядка
  Leaf* ends;
  Draft* base;
  Draft* cls;

public:

     virtual void unselect  (int){};     // сделать невыделенным обьектом
     virtual void select    (int){};
     virtual  int sys       (void){return 0;};
     virtual  int key       (void)=0;
     virtual void preprocess(void){};

	     void setbase   (Draft* a){base=a;};
	     void setcls    (Draft* a){cls=a;};
	     void insert    (Leaf*);       // вставим в Z группу
	     void setfirst  (Leaf*);       //
	     void movefirst (Leaf*);

     virtual  int handlevent(void);     // команда обработки событ
     virtual  void draft     (void);       // системная команда построения
	     Leaf* go        (void);

		  Proto     ();           // конструктор
		  virtual ~Proto    ();

};
#endif

