#ifndef IIS
#define IIS

#ifndef MODALS
#include "modals.hpp"
#endif

#ifndef  BASEMATH
#include "basemath.hpp"
#endif

#ifndef  VIRTUAL
#include "virtual.hpp"
#endif

#include"iistol.h"



class Iistol:public Modals, BaseMath{

strCentre centr;
strCentre centr1;

strDlins moi;
strIIS stol;
Virtual mai;
Mem* sum_set;
int* cent;
int niis;
Group *menu;
char mode;
char modedraft;
char modeline1;
char string[300];
int* iis;
int* emiis;
int imin,jmin;
int home, end;

int* placenum;

unsigned long sem[300];

struct time tnaw;
struct date dnaw;


void LoadAdd(File& a);
void LoadIis(File& a);
void SaveTxt(void);
void setperek(int);
int setcentre(void);
void poiskcent(void);
int unsetcentre(void);
int setiis(void);
void hSave(void);
View *perek[2];
public:
	Iistol();
	int sys(void);
	void draft(void);
	 ~Iistol();

				  };

#endif