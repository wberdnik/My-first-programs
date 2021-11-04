#ifndef LIVE
#define LIVE

#include"sourse.hpp"
#include"dbf.hpp"

class Live
{private:
 friend Iosys;
  Dbf one;
  char flagspiska;
  Spisok* ba;

	protected:
	char flag;
  long root;
  long yk;
  Var at;
  virtual void build(char)=0;
  virtual void debuild(void)=0;
  virtual int ifcan(void)=0;
  void dest(void);
  public:
  Live(char,long);
  virtual ~Live(){;};
  void operator[](long);
  virtual void save(void);
  void next(void);
  void operator++(void);
  void operator--(void);
  void greatspisok(void);
  long stop;
  long mera;
};
#endif