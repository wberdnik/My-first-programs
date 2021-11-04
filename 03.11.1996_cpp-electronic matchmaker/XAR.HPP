#ifndef XARi
#define XARi
#include"live.hpp"
typedef struct {
		char mark;
                char pole[49];
                long weightqullity;
                long chethik;
                      }XAR;


class Xar:public Live
{ void build(char);
  void debuild(void);
  int ifcan(void);
  void setfl(char);
  public:
  Xar(long b):Live(2,b){;};
  ~Xar();
 };
#endif