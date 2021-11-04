#ifndef NEW
#define NEW

#include<stdio.h>
void* operator new(size_t sz,char a);
void* mallos(size_t);
void* callos(size_t,size_t);

#endif