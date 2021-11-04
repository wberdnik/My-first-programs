#ifndef KAT0
#define KAT0

#include"live.hpp"
class Kat0:public Live
{ void build(char);
  void debuild(void);
  int ifcan(void);
	void setfl(char);
	public:
	Kat0(long a):Live(0,a){;};
	~Kat0();
 };
#endif