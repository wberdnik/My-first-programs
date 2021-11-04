#ifndef APLICATIONOFPROGRAMM
#define APLICATIONOFPROGRAMM

#ifndef SLAVE
#include "slave.h"
#endif

#ifndef GROUP
#include "group.hpp"
#endif

#ifndef   EVENT
#include "event.hpp"
#endif

class Applic:public Group{
private:
	virtual void preprocess(void);
	 int sys	(void);
public:
	     ~Applic	();
	      Applic	();
		  };
#endif