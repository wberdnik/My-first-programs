#ifndef KAT1
#define KAT1
#include"live.hpp"

class Kat1:public Live
{ void build(char);
  void debuild(void);
  int ifcan(void);
	void setfl(char);
	public:
	Kat1(long a):Live(1,a){;};
	~Kat1();
 };
#endif