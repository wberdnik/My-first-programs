#ifndef BUILDM
#define BUILDM

#ifndef MODALS
#include "modals.hpp"
#endif

#ifndef  BASEMATH
#include "basemath.hpp"
#endif

class Buildm:public Modals, BaseMath{
void matrixlength1(File&);
void matrixlength2(File&);
strDlins moi;
public:
	Buildm();
	int sys(void){return 0;};
	 ~Buildm();
	      };

#endif