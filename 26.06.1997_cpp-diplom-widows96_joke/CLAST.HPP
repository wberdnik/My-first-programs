#ifndef CLASTER
#define CLASTER

#ifndef  PROTO
#include "proto.hpp"
#endif

class Clast:public Proto{
     virtual  int sys(void){return 0;};
     virtual  int key(void);
     void select(int);
     void unselect(int);
     void draft(void);
public:
	Clast();
	virtual ~Clast();
			};



#endif