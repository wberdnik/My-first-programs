#ifndef WORK
#define WORK
#include"live.hpp"
class Work:public Live
{ void build(char);
  void debuild(void);
  int ifcan(void);
  public:
  void save(void);
  Work(long a):Live(4,a){;};
 ~Work();
 };
#endif
