#ifndef VCON
#define VCON
#ifndef GROUP
#include "group.hpp"
#endif

#ifndef MODALS
#include "modals.hpp"
#endif

#ifndef BITMAP
#include "bitmap.hpp"
#endif


#ifndef  BASEMATH
#include "basemath.hpp"
#endif

#ifndef  VIRTUAL
#include "virtual.hpp"
#endif

#ifndef  BOARDH
#include "board.h"
#endif

#define CON 30

class cSub:public Modals,public BaseMath{
Group* menu;
View* perek[3];
void setperek(char);

ulong  Qv[20];  ulong  Qv1[20];
ulong  Qv2[20]; ulong  Dv[20];
ulong  Qg[15];  ulong  Qg1[15];
ulong  Qg2[15]; ulong  Dg[15];

ulong sem[300];

int imin,jmin;
char string[200];
int   unsetcon(void);
int   setcon(void);
void   calc(void);
char mode;
char modedraft;
void metod(void);
void build(void);

protected:

Virtual mai;
double cena;
struct con{
	int x;
	int y;
	long number;
	int npoint;
	char flag;
	  } con[CON];
int ncon;
int conbegin;

strConcent concent;
strCabel  cabel;

Masint * massiv;


double findcoast(void);
virtual FILE* algoritm(void);
public:
	cSub();
	int sys (void);
	void draft(void);
	~cSub();
	      };

class cAdd :public cSub{
FILE* algoritm(void);
public :
	cAdd();
	~cAdd();
			};

#endif