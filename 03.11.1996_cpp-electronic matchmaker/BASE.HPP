#ifndef BASE

#define BASE

#include"new.hpp"

extern unsigned far * _mvideo;

class Base
{friend Var;
 protected:

 virtual void read(char *)=0;
 virtual void set (long)=0;
 virtual void add (long)=0;       // добавить
 virtual void del (long)=0;
 int len;

 public:
 Base& operator[](long);          // установка  that
 virtual Base& operator() (long); // обмен that с 'a'
 virtual Base& operator=(Var&)=0; // инициализация [that]
 Base& operator+(long);           // добавить
 Base& operator-(long);           // удалить
 long end;
 long that;

 };

class Var
{friend Base;
 char flag;
 public:
 char* data;
 int len;
  Var(int i)
		{data=new (0) char[i];flag=1;};

  Var(char * a)
     {data=a;flag=0;};

  ~Var()
		{(*this)=(char*)NULL;};

  Base& operator = (Base& a)
	      {a.read(data);return a;};

  Var& operator = (char*);
 };
class Wait
{unsigned x[5];
 public:
 Wait(char);
 ~Wait();
 };
#endif