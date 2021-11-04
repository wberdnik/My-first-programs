#ifndef MAIN
#define MAIN
#include"live.hpp"
class Main:public Live
{ void build(char);
  void debuild(void);
  int ifcan(void);
   public:
  Main(long a):Live(3,a){;};
   ~Main();
 };
#endif