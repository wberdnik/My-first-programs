#ifndef EDITNET
#define EDITNET

#ifndef GROUP
#include "group.hpp"
#endif

#ifndef MODALS
#include "modals.hpp"
#endif

#ifndef  BASEMATH
#include "basemath.hpp"
#endif

#ifndef  VIRTUAL
#include "virtual.hpp"
#endif

class EditNet:public Modals,BaseMath{
friend Rectangle;
friend Circle;
Virtual mai;
Mem* sum_set;
int* cent;
strCentre centr;
strDlins moi;
Group *menu;

struct time tnaw;
struct date dnaw;

void setperek(int);  char mode;
View *perek[2];

void hSave(void);
void LoadAdd(File& a);
void SaveTxt(void);
public:

	EditNet(void);
	void draft(void);
	int sys(void);
	~EditNet();
	      };

#endif