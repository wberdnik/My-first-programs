#ifndef BASEDATA
#define BASEDATA

#ifndef MODALS
#include "modals.hpp"
#endif

#ifndef  SOURSE
#include "sourse.hpp"
#endif

#ifndef  BOARDH
#include "board.h"
#endif

#ifndef  TEXTBAR
#include "textbar.hpp"
#endif

#ifndef DBF
#include"dbf.hpp"
#endif

#ifndef LINEINPUT
#include "lineinpu.hpp"
#endif
class BaseData:public Modals,public Dbf{
virtual void LoadData(void)=0;
virtual void SaveData(void)=0;
virtual void FreeData(void)=0;
protected:
TextBar* out;
Lineinput* mas[7];
char str[256];
public:
 unsigned long base;
 int sys(void);
 BaseData(int,char*);
 virtual ~BaseData();

		  };



class Concent:public BaseData{
void LoadData(void);
void SaveData(void);
void FreeData(void);
public:
strConcent zapis;
   Concent();
   void draft(void);
   ~Concent();
};


class Cabel:public BaseData{
void LoadData(void);
void SaveData(void);
void FreeData(void);
public:
strCabel zapis;
   Cabel();
   void draft(void);
   ~Cabel();
};


#endif
