#ifndef ADDNET
#define ADDNET

#ifndef MODALS
#include "modals.hpp"
#endif

#ifndef  BASEMATH
#include "basemath.hpp"
#endif

#ifndef  VIRTUAL
#include "virtual.hpp"
#endif



class Addnet:public Modals, BaseMath{
strCentre centr;
Virtual mai;
//int* mass_set;
Mem* sum_set;
int* cent;
int* myi;
float* myd,* myc;
strDlins moi;
char string[200];
int net,add,ncent;
int kol,kol2;

float fromto(int fr,int to);
void sumnet(void);
void move(void);
void draftnet(void);
void centredraft(void);
void movekoord(void);
void LoadAdd(File& a);
void SaveAdd(File& a);
void SaveTxt(void);
void AddKoor(void);
void SumNet(void);

public:
	Addnet();
	 ~Addnet();

				  };

#endif