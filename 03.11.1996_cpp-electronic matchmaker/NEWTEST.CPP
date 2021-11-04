#include<conio.h>
#include<mem.h>
#include<alloc.h>
#include"base.hpp"
#include"error.hpp"

Base& Base::operator+(long a)
{ add(a);
  end+=a;
  return *this;
 };
Base& Base::operator-(long a)
 {if(end!=0)
    {if(a>end) a=end;
     del(a);
     end-=a;
     if(end==0) that=0;
     else
       if(that>=end) (*this)[0];
    };
   return *this;
 };

Base& Base::operator[](long a)
{error(a>=end,OPERATOR,"Установка за предел :: Base []");
   set(a); that=a;
 return *this;
 };
// ----------------------------------------------------------------------

Var& Var::operator = (char* a)
 {if(flag==1)
    {delete data;flag=0;};
   data=a;
  return *this;};


Base& Base::operator()(long a)
{ if(end!=0 && a!=that )
  {long b=that;

    Var x=(int)len;
    Var x1=(int)len;
    x=(*this)[b];
    x1=(*this)[a];
    (*this)[a]=x;
    (*this)[b]=x1;
    set(b);
   }
  return *this;
}
Wait::Wait(char a)
{const unsigned j=256*(RED+GREEN*16);
 char *y="Wait.";
	y[4]=a;
	for(char i=0;i<5;i++)
	 {x[i]=_mvideo[i];
	  _mvideo[i]=j+(unsigned)y[i];
	 };
 char w[8];
 sprintf(w,"%lu",farcoreleft());
     for(i=70;i<77;i++)
      _mvideo[i]=j+(unsigned)w[i-70];

 };
Wait::~Wait()
{for(char i=0;i<5;_mvideo[i++]=x[i]);};
