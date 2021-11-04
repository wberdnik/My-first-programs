#ifndef MODALS
#define MODALS

#ifndef  PROTO
#include "proto.hpp"
#endif

#ifndef   TEXTBAR
#include "textbar.hpp"
#endif

class Modals:public Proto{
protected:
//virtual:
	virtual int key(void);
	virtual int sys(void){Ev.setevent(cmQuit);return 0;};
//user:
	void cleargroup(void);

public:
			Modals();
		       ~Modals();
};
#endif