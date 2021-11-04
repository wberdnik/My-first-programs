#ifndef LINEBAR
#define LINEBAR

#ifndef SLAVE
#include "slave.h"
#endif

#ifndef  VIEW
#include "view.hpp"
#endif


class LineBar:public View
{void show(int);
 char * newline;
 int kbhot;
 int preprocess(void);
public:
	LineBar(int,int,int w,int comand,int help,char*,int,int hi=10);
	void select(int);
	void unselect(int){status=0;show(No);};
	~LineBar();
		};

class Radio:public View{
 void show(char);
	int setcomand(void){return stSelect;};
	int preprocess(void);
 char* text;
public:
	Radio(int,int,int w,int comand,int help,char*,int,char*);
	void select(int );
	void unselect(int);
			   };



#endif