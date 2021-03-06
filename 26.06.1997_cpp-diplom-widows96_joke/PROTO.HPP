#ifndef PROTO
#define PROTO

#ifndef  LEAF
#include "Leaf.hpp"
#endif




class Proto:public Leaf{
protected:
  Leaf* first;				// �������� Z ���浪�
  Leaf* ends;
  Draft* base;
  Draft* cls;

public:

     virtual void unselect  (int){};     // ᤥ���� ���뤥����� ��쥪⮬
     virtual void select    (int){};
     virtual  int sys       (void){return 0;};
     virtual  int key       (void)=0;
     virtual void preprocess(void){};

	     void setbase   (Draft* a){base=a;};
	     void setcls    (Draft* a){cls=a;};
	     void insert    (Leaf*);       // ��⠢�� � Z ��㯯�
	     void setfirst  (Leaf*);       //
	     void movefirst (Leaf*);

     virtual  int handlevent(void);     // ������� ��ࠡ�⪨ ᮡ��
     virtual  void draft     (void);       // ��⥬��� ������� ����஥���
	     Leaf* go        (void);

		  Proto     ();           // ���������
		  virtual ~Proto    ();

};
#endif

