#ifndef COMP
#define COMP
#include"vector.hpp"
#include"swaha.h"
//����� ��� �業�� ���� �����⮢
class Comp:public Vector{
 char deep;
 public:
 Comp(long a,char b);  //����� ����e� ���뢠���� 䠩� �� ���� ������
		// a - ࠧ��� �����
 void run(SLOT&,SLOT&);
 };
#endif
