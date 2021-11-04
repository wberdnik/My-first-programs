#ifndef HANDLEPOINT
#define HANDLEPOINT

#ifndef GROUP
#include "group.hpp"
#endif

#ifndef MODALS
#include "modals.hpp"
#endif

#ifndef  BASEMATH
#include "basemath.hpp"
#endif

class hStation:public Modals,BaseMath{
friend Rectangle;
friend Circle;
Group *menu;
void shistka(void);
void hSave(void);
public:
	hStation();
	int sys(void);
	~hStation();
	      };

#endif