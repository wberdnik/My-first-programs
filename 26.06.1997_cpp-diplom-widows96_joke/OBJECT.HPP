#ifndef OBJECT
#define OBJECT

#ifndef  CONTROL
#include "control.hpp"
#endif

class Object:public virtual Control{
 protected:
    int status;
    void show(void){store();plot();};
    int color;
     virtual void store(void)=0;
     virtual void restore(void)=0;
     virtual void plot (void)=0;
     virtual void work(int,int)=0;
  public:
   Object(int,int,int);
   Object& operator++(void);
   Object& operator--(void);
   Object& move(int,int);
   Object& operator=(int);
   Object& hmove(int,int);
	    };

#endif
