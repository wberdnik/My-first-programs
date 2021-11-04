#ifndef VLAD
#define VLAD

#ifndef SCR
#include"scr.hpp"
#endif

#include<conio.h>
extern char buf;
struct OKO{
	  char* a;
	  char* b;
	  long* k;
	  char  flag;
	  };

extern struct OKO okno[25];
class Win
{ friend Str;
  Scr fr;
  int n;
  public:
  void kprintf(char*,long*);
  void kprintf(char*,char*);
	void edit(void);
   Win();
  ~Win();
  };

class Str
{int nstr;
 void color(int);
 void edit(void);
 public:
  Str(int d){nstr=d;edit();};
  ~Str(){color(YELLOW+16*BLUE);}
};

#endif