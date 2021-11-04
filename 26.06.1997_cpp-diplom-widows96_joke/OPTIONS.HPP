#ifndef OPTIONS
#define OPTIONS

#ifndef MODALS
#include "modals.hpp"
#endif

class Stepweb:public Modals{
public:
   Stepweb();
   int sys(void);
   int build(void);
   ~Stepweb(){};
};

class Real:public Modals{
public:
   Real();
   int sys(void);
   int build(void);
   ~Real(){};
};

#endif
