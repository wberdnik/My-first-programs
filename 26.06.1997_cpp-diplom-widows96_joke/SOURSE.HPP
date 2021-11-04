#ifndef SOURSE
#define SOURSE

#ifndef   BASE
#include "base.hpp"
#endif

#ifndef   SIMPLE
#include "simple.hpp"
#endif

#ifndef  STDIOH
#define  STDIOH
#include <stdio.h>
#endif

#ifndef  IOH
#define  IOH
#include <io.h>
#endif

class File:public Base,public Wait
{   private:

	     FILE* one;
	     char * name;
	     ulong realend;
	     ulong start;

protected:
	     virtual void set(ulong);
	     virtual void del(ulong);
	     virtual void add(ulong);
	     virtual void read(void*);
	     virtual void write(void*);

     public:

	     File(char *);
	     ~File(void);
	     char result;

	     void sbrosstart(void);
	     void getftime(struct ftime* a){::getftime(fileno(one),a);};
	     File& operator%(unsigned);	    // установка длины обмена
	     File& operator+=(ulong);	   // начало отчета
	     int toend(unsigned long,void*);
	     File& operator-=(ulong);
	     operator void* ()const{return one;};
	     operator !(){return one==NULL?1:0;};
  };

#endif