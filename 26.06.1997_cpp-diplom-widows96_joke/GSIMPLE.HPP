#ifndef GSIMPLE
#define GSIMPLE

#ifndef  BASEMATH
#include "basemath.hpp"
#endif

#ifndef  LEAF
#include "Leaf.hpp"
#endif

#ifndef  CONTROL
#include "control.hpp"
#endif
class BaseMath;
class Gobject:public Draft,public Control2{
public:
  Gobject():Control2(){};
  virtual void running(BaseMath&,int)=0;
  virtual void draft(void)=0;
  virtual int  test(int,int)=0;
			  };

class Circle:public Gobject{
char color;
public:
	Circle(int a,int b,int c,int d,char icolor=BROWN):Gobject(){
				   operator()(a,b,c,d);color=icolor;};
	void draft     (void) ;
	void running   (BaseMath&,int);
	int test(int,int);
		       };

class Rectangle:public Gobject{
char color;
public:
	Rectangle(int a,int b,int c,int d,char icolor=BROWN):Gobject(){
				   operator()(a,b,c,d);color=icolor;};
	void draft     (void);
	void running   (BaseMath&,int);
	int test(int,int);
		       };


class Worknet:public Draft{
public:
     void draft(void);
			};

#endif