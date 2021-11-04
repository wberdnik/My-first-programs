#ifndef WINDOW
#define WINDOW

#ifndef OBJECT
#include "object.hpp"
#endif

#ifndef SLAVE
#include "slave.h"
#endif

class Window:public Object,public Control2{
     byte* mas;
     word size;
//virtual:
     void store  (void);
     void restore(void);
     void plot   (void);
     void work   (int a,int b){(*this)(a,b);};
public:
	Window(int,int,int,int,unsigned);
	virtual ~Window(){if(status)restore();};
        };
#endif

