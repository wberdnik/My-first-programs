#ifndef BITMAP
#define BITMAP

#ifndef VIRTUAL
#include"virtual.hpp"
#endif

class Bitmap {
Virtual& mai;
long size;
Mem* one;
unsigned long number;
public:
	Bitmap(Virtual&,long size);
	~Bitmap();
	Bitmap& operator[](unsigned long a);
	void operator=(int);
	void operator<<(Bitmap&);
	void operator<<(int);
	operator int ();
	int operator !(){return (int)(*this)?0:1;};
	      };

class Masint {
Virtual& mai;
long size;
Mem* one;
unsigned long number;
public:
	Masint(Virtual&,long size);
	~Masint();
	Masint& operator[](unsigned long a);
	void operator=(int);
	void operator+=(int);
	void operator<<(int);
	void operator<<(Masint&);
	operator int ();
	      };


#endif