#ifndef LINE
#define LINE

#ifndef OBJECT
#include "object.hpp"
#endif

class Line:public Object{
    private:
    float a,xc;
    int dx,dy;
    int flag;
    int len;
    int n,n1;
    int bx,by;
    protected:
     char* mas;
     Control too;
     virtual void store(void);
     virtual void restore(void);
     virtual void plot (void);
     void work(int a,int b);
     int& x1;
     int& y1;

    public:
    Line(int,int,int,int,unsigned);
    virtual ~Line();
   };
#endif
