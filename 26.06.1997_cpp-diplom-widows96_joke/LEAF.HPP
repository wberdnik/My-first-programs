#ifndef LEAF
#define LEAF

#ifndef   EVENT
#include "event.hpp"
#endif

class Draft{
public:
   virtual void draft(void)=0;
   virtual ~Draft(){};
		       };


class Leaf:public Draft{
public:
	Leaf(){status=No;next=last=NULL;};
	int status;
	Leaf* next;		        // предназначено для передачи
	Leaf* last;                      // управления
virtual void draft  (void)  =0;      // построить обьект на экране
virtual	int  handlevent(void)=0;	// обработатка события
virtual void unselect(int)=0;    // сделать невыделенным обьектом
virtual void select(int)=0;
   virtual ~Leaf(){};
	};

#endif
