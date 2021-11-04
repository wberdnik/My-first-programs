#ifndef BORDER
#define BORDER

#ifndef  BOARD
#include "board.h"
#endif

#ifndef MODALS
#include "modals.hpp"
#endif

#ifndef  SOURSE
#include "sourse.hpp"
#endif

class Border:public Modals{
friend void theprogram(GroupBar&,char);
strStation one;
public:
   Border();
   int sys();
   ~Border();
};

#endif