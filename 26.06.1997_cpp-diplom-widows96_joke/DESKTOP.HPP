#ifndef DESKTOP
#define DESKTOP

#ifndef  VIEW
#include "view.hpp"
#endif

#ifndef SLAVE
#include "slave.h"
#endif

#ifndef  BASEMATH
#include "basemath.hpp"
#endif



class DeskTop:public View{
int simple(int,int);
int fast(int,int);
char isSorted;
int masfind[50];
int dta;
char c[80];
int x,y;
	int setcomand(void){return stSelect;}; // Обьекту пришло событие
	int preprocess(void);
	char mode;
	BaseMath& math;
	void moveuser(void);
	void thewait(void);
	void show(void){math.pixcel();}

public:

	void unselect(int a);
	void select(int a);
	DeskTop(char mode,BaseMath& );
	~DeskTop();

			   };
#endif
