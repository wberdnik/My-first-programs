#ifndef CONFIG
#define CONFIG

#include"sourse.hpp"

class  Config:private Steck
{ char  det;
  int max;
  char* lastname;
  File* ane;
  char* newname(char* a);
  void rename(void){lastname[0]++;};
  int find(File&,char*,int);
  void format(File&,char* ,int);
  void test(void);


  public:
   Config();
   ~Config();
   char* getname(char*);
   char* retname(char*);
};
#ifndef iiiii
extern Config * _klassconfig;
#endif

#endif