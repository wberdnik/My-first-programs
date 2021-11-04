#ifndef TETOBJ
#define TETOBJ
#include"tetris.h"
extern char weight;
extern char deep;
extern char* tetmas;

class Fig{
protected:
char x,y;
public:
  virtual void set(void)=0;
  virtual void reset(void)=0;
  virtual int test(void)=0;
  virtual int others(int)=0;
  Fig& operator()(char a,char b){ x=a;y=b; return *this;};
  Fig(){x=weight/2-2;y=0;};
	  };


// ‚ нв®¬ д ©«Ґ ®ЇЁб ­л ўбҐ дЁЈгал вҐваЁб 
class One :public Fig{    //  Ы
public:
  void set(void);
  void reset(void);
  int test(void);
  int others(int);      };


class Two :public Fig{     // ЫЫ
public:
  int test(void);
  void set(void);
  void reset(void);
  int others(int);     };

class Three :public Fig{   // ЫЫЫ
public:
  int test(void);
  void set(void);
  void reset(void);
  int others(int);      };

class Four :public Fig{    // ЫЫЫЫ
public:
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);      };

class UpTwo :public Fig{     // Ы
public:                      // Ы
  int test(void);
  void set(void);
  void reset(void);
  int others(int);      };

class UpThree :public Fig{   // Ы
public:                      // Ы
  int test(void);            // Ы
  void set(void);
  void reset(void);
  int others(int);      };

class UpFour :public Fig{    // Ы
public:                      // Ы
  int  test(void);           // Ы
  void set(void);            // Ы
  void reset(void);
  int others(int);      };

class Upper :public Fig{           //  Ы
public:                            //  u
  int test(void);                  //  Ы
  void set(void);                  //  Ы
  void reset(void);
  int others(int);      };

class Block :public Fig{           //    ЫЫ
public:                            //    ЫЫ
  int test(void);
  void set(void);
  void reset(void);
  int others(int);     };

class Z :public Fig{                //   ЫЫ
public:                             //    ЫЫ
  int test(void);
  void set(void);
  void reset(void);
  int others(int);  };
class MZ :public Fig{               //
public:                             //     ЫЫ
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);   };

class UpZ :public Fig{              //      Ы
public:                             //     ЫЫ
  int test(void);                   //    Ы
  void set(void);
  void reset(void);
  int others(int);     };

class UpMZ :public Fig{             //    Ы
public:                             //    ЫЫ
  int   test(void);                 //      Ы
  void set(void);
  void reset(void);
  int others(int);     };


class LtML :public Fig{              //  ЫЫЫЫ
public:                              //     Ы
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);     };

class LtL :public Fig{              //     Ы
public:                             //  ЫЫЫЫ
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);    };

class RtML :public Fig{              //  Ы
public:                              //  ЫЫЫЫ
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);     };

class RtL :public Fig{              //  ЫЫЫЫ
public:                             //  Ы
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);    };

class UpML :public Fig{              //   Ы
public:                              //   Ы
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);    };

class UpL :public Fig{              //  Ы
public:                             //  Ы
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);     };

class DnML :public Fig{              //  ЫЫ
public:                              //  Ы
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);     };

class DnL :public Fig{              //  ЫЫ
public:                             //   Ы
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);    };


#endif