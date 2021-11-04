#ifndef BASE
#define BASE


#ifndef  ERROR
#include "error.hpp"
#endif

typedef unsigned long ulong;

class Var
{char flag;
 public:
   void* data;
   Var(unsigned i)     {data=(void*)new char[i];flag=1;};
   Var(void * a)  {data=a;flag=0;};
   Var& operator = (void*);
   ~Var()         {operator=((void*)0);};
 };


class Base{
protected:
 virtual	void set (ulong)=0;    //интерфейс с наследуемыми
 virtual	void add (ulong)=0;
 virtual	void del (ulong)=0;
 virtual	void write(void*)=0;
 virtual	void read(void*)=0;

 unsigned  len;

public:
		ulong end;
		long that;

		Base();
		Base& operator[](ulong);
 virtual	Base& operator() (ulong);              // обмен that с 'a'
		Base& operator=(void* a);
		Base& operator<<(void* a);
		Base& operator>>(int& a);
		Base& operator<<(int a);
		Base& operator<<(int* a);
		Base& operator>>(int* a);
		Base& operator<<(Var& a);
		Base& operator+(long a);
		Base& operator-(long);
		Base& operator>>(void * a);
		Base& operator>>(Var& a);
 };

#endif