#ifndef GROUP
#define GROUP

#ifndef  PROTO
#include "proto.hpp"
#endif

#ifndef SLAVE
#include "slave.h"
#endif

// --------------------------------------------------------------
// class Group - ������ ����� ��� �࣠����樨 ����娨 ����
//                � ��।������ ᮮ�饭��
//---------------------------------------------------------------


class Group:public Proto{
friend Applic;
protected:
Leaf* image;				// �⮡ࠦ���� ��㯯�
public:

	void master(Leaf* a){image=a;}; // �⮡ࠦ���� ��㯯�
	void unselect(int);		// ᤥ���� ���뤥����� ��쥪⮬
	void select(int);
	int key(void);
	int handlevent(void);        // ��⥬��� ������� ��ࠡ�⪨ ᮡ��
	void draft   (void);           // ��⥬��� ������� ����஥���
	Group();
	virtual ~Group();

};

#endif

