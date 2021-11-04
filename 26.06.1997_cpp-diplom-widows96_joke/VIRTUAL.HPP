#ifndef VIRTUAL
#define VIRTUAL
#include"virtual.h"
#include"sourse.hpp"
#include"xms.hpp"
#include<stdio.h>

class Virtual{

Mem * curmem;
unsigned int cursize;
v_size curnumber;
v_size oldcurnumber;
char where;
File* file;
Xms* tt;

char flag;

	void freeblock(Mem*);
	void freekesh(void);
	void write(void*);
	void read(void*);

public:
	Virtual();
	~Virtual();
	Mem* myalloc(v_size,int);
	void freexms(Mem*);
	Virtual& operator()(Mem*,unsigned int);
	Virtual& operator()(Mem*);
	Virtual& operator[](v_size);

	int operator ! (void);


	Virtual& operator<<(int a){write((void*)&a);return *this;};
	Virtual& operator>>(int& a){read((void*)&a);return *this;};
	Virtual& operator<<(float a){write((void*)&a);return *this;};
	Virtual& operator>>(float& a){read((void*)&a);return *this;};
	Virtual& operator<<(File&);
	Virtual& operator>>(File&);


	   // . . .             для других типов (float char )

	Mem* destroy(Mem*);

private:
  unsigned long int ramfree;

	     };

#endif