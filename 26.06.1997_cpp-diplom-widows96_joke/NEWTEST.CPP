#include"base.hpp"
#include"tkeys.h"
#pragma hdrstop

Base::Base()
{end=0;that=0;};
Base& Base::operator=(void* a)
{write(a);return *this;};
Base& Base::operator<<(void* a)
{write(a);return *this;};
Base& Base::operator>>(int& a)
{read((void*)&a);return *this;};
Base& Base::operator<<(int a)
{write(&a);return *this;};
Base& Base::operator<<(int* a)
{write((void*)a);return *this;};
Base& Base::operator>>(int* a)
{read((void*)a);return *this;};
Base& Base::operator<<(Var& a)
{return operator=(a.data);};
Base& Base::operator+(long a)
{add(a);end+=a;return *this;};
Base& Base::operator>>(void * a)
{read(a);return *this;};
Base& Base::operator>>(Var& a)
{return operator>>(a.data);};


Base& Base::operator-(long a) {
  if(end!=0) {
    (*this)[0];
     a=a>end?end:a;
      del(a); end-=a;
	     };
   return *this;
			     }

Base& Base::operator[](ulong a)
{if(a>=end)
  error("Žè¨¡ª  Base[end+1]");
   set(a); that=a;
 return *this;
 };

 Base& Base::operator()(ulong a)
{ if(end!=0 && a!=that )
  {long b=that;

    Var x=len;
    Var x1=len;
    (*this)[b]>>x;
    (*this)[a]>>x1;
    (*this)[a]<<x;
    (*this)[b]<<x1;

    set(b);
   }
  return *this;
}

// ----------------------------------------------------------------------

Var& Var::operator = (void* a)
 {if(flag){delete data;flag=0;};
   data=a;
  return *this;};

