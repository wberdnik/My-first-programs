#ifndef SOURSE
#define SOURSE

#include"error.hpp"
#include<mem.h>

#include"base.hpp"

class File:public Base
 {           private:

	     FILE* one;
	     long realend;
	     long start;

	     void set(long);
	     void read(char*);
	     void del(long);
	     void add(long);

	     public:

	     char flag;
	     File(char *);
	     ~File(void);

	     File& operator%(int);	    // установка длины обмена
	     File& operator+=(long);	   // начало отчета
	     File& operator-=(long);

	     Base& operator=(Var&);
	     void tprint(char*,int b=70);
  };
class Spisok:public Base
{ private:
	struct spisok
	 {char* data;
	  struct spisok* next;}otkat;

	void read(char* a){memcpy(a,thethat->data,len);};

	void add(long);
	void del(long);
	void set(long);
   protected:
	struct spisok* thethat;


	public:
	Spisok(int);
	~Spisok(){del(end);};

	Base& operator()(long a);
	Base& operator=(Var&);
	void print(void);
  };
class Steck
{ friend Config;
  Spisok one;
  public:
  Steck(int a):one(a){;};
  char* pop(char *);
  char* push(char*);
  long  flag(void){return one.end;};
  void reset(void){one-one.end;};
};

#endif