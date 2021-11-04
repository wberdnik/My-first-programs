#ifndef BUTTON
#define BUTTON

#ifndef  VIEW
#include "view.hpp"
#endif


#ifndef SLAVE
#include "slave.h"
#endif

class Button:public View{
void show(int);
word color;
char* my;

int setcomand(void);
int preprocess(void);

public:
	Button(int,int,int,int,int com,int help,char*,word,char* on,\
	word icolor=LIGHTGREEN);
	void select(int a);
	void unselect(int);
	void press(void);
      };
class MasterButton:public Button{
public:
	MasterButton(int,char*,word,char*);
				};

#endif