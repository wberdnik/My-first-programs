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
	int filter();		// ��।������ ������ ᮮ�饭��
protected:
	int Body(void);
	int comand;			// ��뢠���� �������
	int nhelp;                      // ���⥪�� ���᪠���
	word kbhot;                     // ������ ������
	char* hline;
//user:
	virtual int setcomand(void); // ��쥪�� ��諮 ᮡ�⨥
	virtual int preprocess(void);
	virtual void unselect(int)=0;    // ᤥ���� ���뤥����� ��쥪⮬
	virtual void select(int)=0;
public:
	View(int a,int b,int c,int d,word icomand=cmNowork,\
			word inhelp=0,char* ih="",word ikb=kbNoKey);

	int  handlevent(void);	   //  ��ࠡ��⪠ ᮡ���
	void draft(void);
};

#endif