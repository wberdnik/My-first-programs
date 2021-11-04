#ifndef COMP
#define COMP
#include"vector.hpp"
#include"swaha.h"
//класс для оценки двух клиентов
class Comp:public Vector{
 char deep;
 public:
 Comp(long a,char b);  //здесь должeн открываться файл из базы знаний
		// a - размер вектора
 void run(SLOT&,SLOT&);
 };
#endif
