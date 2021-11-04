#ifndef TIME
#define TIME

#ifndef __DOS_H
#include"dos.h"
#endif


class Time{
public:
struct time one;
	int operator==(Time&);
	Time& operator-(Time&);
	Time& operator !(void);
	int operator>(Time&);
	int operator<(Time&);
	Time& operator=(Time&);
	};
#endif