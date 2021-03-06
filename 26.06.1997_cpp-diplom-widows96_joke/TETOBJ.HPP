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


// � �⮬ 䠩�� ���ᠭ� �� 䨣��� ����
class One :public Fig{    //  �
public:
  void set(void);
  void reset(void);
  int test(void);
  int others(int);      };


class Two :public Fig{     // ��
public:
  int test(void);
  void set(void);
  void reset(void);
  int others(int);     };

class Three :public Fig{   // ���
public:
  int test(void);
  void set(void);
  void reset(void);
  int others(int);      };

class Four :public Fig{    // ����
public:
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);      };

class UpTwo :public Fig{     // �
public:                      // �
  int test(void);
  void set(void);
  void reset(void);
  int others(int);      };

class UpThree :public Fig{   // �
public:                      // �
  int test(void);            // �
  void set(void);
  void reset(void);
  int others(int);      };

class UpFour :public Fig{    // �
public:                      // �
  int  test(void);           // �
  void set(void);            // �
  void reset(void);
  int others(int);      };

class Upper :public Fig{           //  �
public:                            //  u
  int test(void);                  //  �
  void set(void);                  //  �
  void reset(void);
  int others(int);      };

class Block :public Fig{           //    ��
public:                            //    ��
  int test(void);
  void set(void);
  void reset(void);
  int others(int);     };

class Z :public Fig{                //   ��
public:                             //    ��
  int test(void);
  void set(void);
  void reset(void);
  int others(int);  };
class MZ :public Fig{               //
public:                             //     ��
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);   };

class UpZ :public Fig{              //      �
public:                             //     ��
  int test(void);                   //    �
  void set(void);
  void reset(void);
  int others(int);     };

class UpMZ :public Fig{             //    �
public:                             //    ��
  int   test(void);                 //      �
  void set(void);
  void reset(void);
  int others(int);     };


class LtML :public Fig{              //  ����
public:                              //     �
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);     };

class LtL :public Fig{              //     �
public:                             //  ����
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);    };

class RtML :public Fig{              //  �
public:                              //  ����
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);     };

class RtL :public Fig{              //  ����
public:                             //  �
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);    };

class UpML :public Fig{              //   �
public:                              //   �
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);    };

class UpL :public Fig{              //  �
public:                             //  �
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);     };

class DnML :public Fig{              //  ��
public:                              //  �
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);     };

class DnL :public Fig{              //  ��
public:                             //   �
  int   test(void);
  void set(void);
  void reset(void);
  int others(int);    };


#endif