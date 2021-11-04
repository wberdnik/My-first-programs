#ifndef VIEW
#define VIEW

#ifndef   EVENT
#include "event.hpp"
#endif

#ifndef  CONTROL
#include "control.hpp"
#endif

#ifndef  LEAF
#include "LEAF.hpp"
#endif

#ifndef SLAVE
#include "slave.h"
#endif


class View:public Leaf,virtual public Control2{
friend Group;
	int filter();		// Определение наличия сообщения
protected:
	int Body(void);
	int comand;			// Вызываемая команда
	int nhelp;                      // Контекст подсказка
	word kbhot;                     // горячая клавиша
	char* hline;
//user:
	virtual int setcomand(void); // Обьекту пришло событие
	virtual int preprocess(void);
	virtual void unselect(int)=0;    // сделать невыделенным обьектом
	virtual void select(int)=0;
public:
	View(int a,int b,int c,int d,word icomand=cmNowork,\
			word inhelp=0,char* ih="",word ikb=kbNoKey);

	int  handlevent(void);	   //  обработатка события
	void draft(void);
};

#endif