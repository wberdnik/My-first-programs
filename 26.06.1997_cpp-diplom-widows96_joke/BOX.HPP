#ifndef BOX
#define BOX

#ifndef MODALS
#include "modals.hpp"
#endif


#ifndef   TEXTBAR
#include "textbar.hpp"
#endif


#ifndef SLAVE
#include "slave.h"
#endif

#ifndef  VIEW
#include "view.hpp"
#endif


#ifndef DIRH
#define DIRH
#include <dir.h>
#endif

class ListFile:public View,public TextBar{
char** name;
char * mem;
int razmer;

int nselect;
int nstart;
int all;

void scan(void);
void modeselect(void);
int setcomand(void);
int preprocess();
void show(void);

void add(int);
void sub(int);
void setnsel();
void findalpha();
void hiden(void);
public:
	void draft(void);
	ListFile();
	void unselect(int){status=stNo;modeselect();};
	void select(int){status=stSelect;modeselect();}
	~ListFile();
	};




class Box:public Modals{
ListFile* wind;
public:
   Box(int vid,char*);
   int sys(void);
   ~Box(){};
};


#endif