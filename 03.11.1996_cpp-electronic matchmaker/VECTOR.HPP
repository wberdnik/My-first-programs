#ifndef VECTOR
#define VECTOR
#include"swaha.h"
#include"sourse.hpp"
//'�����' �࠭�騩 �業��
class Vector:public Spisok
 {public:
  Vector(long);
  marks& get(void){return *((marks*)thethat->data);};
 };

#endif