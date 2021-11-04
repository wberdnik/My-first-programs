#ifndef FCENTRE
#define FCENTRE

#ifndef MODALS
#include "modals.hpp"
#endif

#ifndef  BASEMATH
#include "basemath.hpp"
#endif

#ifndef  WINDOW
#include "window.hpp"
#endif

class fCentre:public Modals,BaseMath{
Group* menu;
View* perek[3];
Window* wind[5];
void setperek(char);
void loadcentre(void);

unsigned long  Qv[20]; unsigned long  Qv1[20];
unsigned long  Qv2[20]; unsigned long  Dv[20];
unsigned long  Qg[15]; unsigned long  Qg1[15];
unsigned long  Qg2[15]; unsigned long  Dg[15];

unsigned long sem[300];

int imin,jmin;
char string[200];

void   centr_commutator(void);
int   setcentre(void);
int   unsetcentre(void);
void   calc(void);
char mode;
char modedraft;
public:
	fCentre();
	int sys (void);
	void draft(void);
	~fCentre();
	      };

#endif