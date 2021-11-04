#ifndef EZIK
#define EZIK

#ifndef MODALS
#include "modals.hpp"
#endif

#ifndef  BASEMATH
#include "basemath.hpp"
#endif

#ifndef  VIRTUAL
#include "virtual.hpp"
#endif


class Ezik:public Modals, BaseMath{
strDlins moi;
Virtual mai;
strCentre centr;
Mem** m;
int* Qv;
int* Qg1;
float w,w1;
int imin,jmin;
int flag5;
char string[300];
int* mass_set;

void movematrix(void);
void preparation_matrix(void);
void training_matrix(void);
void search_min_2(void);
void exchange_Q(int index);
void res_nete(int ji, int &res, int &jres);
void dop_Qg1(int imin, int jmin, int ji);
void for_search_min(int ji, int &you1, int &imin, int &jmin);
float fromto(int fr,int to);
void unite_with_commutator_2(void);
float fromto_2(int fr,int to);

public:
	Ezik(void);
	 ~Ezik();

				  };

#endif