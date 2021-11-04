#ifndef CONTROL
#define CONTROL

class Control{
public:
   int x,y;
   void operator()(int,int);
   Control(){};
   Control(int a,int b){(*this)(a,b);};
	    };

class Control2:virtual public Control{
public:
	int w,h;
	void operator()(int,int,int,int);
	void operator()(int a,int b){Control::operator()(a,b);};
	void operator=(Control2* a){operator=(a);};
	void operator=(Control2& a){operator()(a.x,a.y,a.w,a.h);};
	Control2(Control2* a):Control(){operator=(a);};
	Control2(){x=y=0;w=h=10;};
			     };

#endif