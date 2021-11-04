#ifndef GROUP
#define GROUP

#ifndef  PROTO
#include "proto.hpp"
#endif

#ifndef SLAVE
#include "slave.h"
#endif

// --------------------------------------------------------------
// class Group - базовый класс для организации иерархии окон
//                и распределение сообщений
//---------------------------------------------------------------


class Group:public Proto{
friend Applic;
protected:
Leaf* image;				// Отображение группы
public:

	void master(Leaf* a){image=a;}; // отображение группы
	void unselect(int);		// сделать невыделенным обьектом
	void select(int);
	int key(void);
	int handlevent(void);        // системная команда обработки событ
	void draft   (void);           // системная команда построения
	Group();
	virtual ~Group();

};

#endif

