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
	Leaf* next;		        // �।�����祭� ��� ��।��
	Leaf* last;                      // �ࠢ�����
virtual void draft  (void)  =0;      // ����ந�� ��쥪� �� ��࠭�
virtual	int  handlevent(void)=0;	// ��ࠡ��⪠ ᮡ���
virtual void unselect(int)=0;    // ᤥ���� ���뤥����� ��쥪⮬
virtual void select(int)=0;
   virtual ~Leaf(){};
	};

#endif
