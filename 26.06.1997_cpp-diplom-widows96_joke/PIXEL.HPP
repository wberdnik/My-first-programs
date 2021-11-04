#ifndef PIXEL
#define PIXEL

#ifndef OBJECT
#include "object.hpp"
#endif

#ifndef  GRAPHICSH
#define  GRAPHICSH
#include <graphics.h>
#endif

class Pixel:public Object{
    char hiden;
 protected:
      void store(void){hiden=getpixel(x,y);};
      void restore(void){putpixel(x,y,hiden);};
      void plot (void){putpixel(x,y,color);};
      void work(int,int){};
 public:
     Pixel(int a,int b,int c):Object(a,b,c){};
     ~Pixel(){if(status)restore();};
			 };
#endif
