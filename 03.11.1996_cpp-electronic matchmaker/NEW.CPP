#include"new.hpp"
#include"error.hpp"
#include<stdio.h>

void* operator new(size_t sz,char a){a++;
 void* b;
 error((b=(void*)new char [sz])==NULL,MEM,"Дальнейшая работа не возможна");
 return b;
};
void* mallos(size_t sz)
{return new (0) char[sz];};

void* callos(size_t sz,size_t t)
{return new (0) char[sz*t];};
