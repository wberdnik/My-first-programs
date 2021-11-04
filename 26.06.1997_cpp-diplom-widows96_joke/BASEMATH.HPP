#ifndef BASEMATH
#define BASEMATH
#include"board.h"

#ifndef  GSIMPLE
#include "gsimple.hpp"
#endif

#ifndef  SOURSE
#include "sourse.hpp"
#endif

#ifndef   EVENT
#include "event.hpp"
#endif


extern maxstation;
class Gobject;

class BaseMath{
public:
// mathimatic:
float * c;float * d;// топологические координата станций
int *ci;int *di;    // экранные координаты
int *em;            // информационная емкость станций
unsigned n;         // число станций

// common:

int **m;           //hlam

int tr1,tr2,tr3;    // транзитные переменные
float there;

strStation too;     // заголовок stn файла

Gobject * border;   // указатель на контроль топологических границ

char flagworking;

 BaseMath();

 void pixcel(void);
 void sort(void);
 void move(int,int);
 void LoadHeadStn(File&);
 int LoadStn(File&);
 void SaveStn(File&);
 void SetBorder(void);
 int LoadAllStn(int);
 ~BaseMath();
};
#endif
