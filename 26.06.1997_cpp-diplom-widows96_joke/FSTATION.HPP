#ifndef FSTATION
#define FSTATION

#ifndef MODALS
#include "modals.hpp"
#endif

#ifndef  BASEMATH
#include "basemath.hpp"
#endif

class fStation:public Modals, BaseMath{
friend Rectangle; friend Circle;
friend void theprogram1(GroupBar&,char);
friend void theprogram2(GroupBar&,char);
friend void theprogram3(GroupBar&,char);
friend void theprogram4(GroupBar&,char);
friend void progforall(GroupBar&,char);
char text[80];
void runnig(void);
public:
	fStation();
	int sys(void);
	virtual ~fStation();
	      };

#endif