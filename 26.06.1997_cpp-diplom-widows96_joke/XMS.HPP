#ifndef XMS
#define XMS
#include"base.hpp"
#include<conio.h>
#include"xms.h"
#include"base.hpp"

class Xms:public Base
{ private:
	ulong realend;
	ulong start;

	ulong Offset;
	void (*XMSControl)(void);      // ��窠 �室� � XMS �ࠩ���

//function:
	void XMS_SayErrorMSG(unsigned Ecode);

//borned:
	void add(ulong);
	void del(ulong){;};
	void read(void far* a);
	void write(void far* a);
	void set(ulong){};


  public:
      Xms();
     ~Xms();

//function:
     Xms& operator%(unsigned);	    // ��⠭���� ����� ������
     Xms& operator+=(ulong);	   // ��砫� ����
     Xms& operator-=(ulong);

     void set(ulong a,ulong b,ulong light);

     ulong   XMSVersion(void);
     void    XMSDelete(void);
     unsigned XMSQueryTotalFree(void);
     unsigned XMSQueryA20(void);
     unsigned XMSGlobalEnableA20(void);
     unsigned XMSGlobalDisableA20(void);
     unsigned XMSQueryLargestFree(void);
     unsigned XMSAllocateEMB(void);
     ulong XMSGetHandleInfo(unsigned Handle);
     ulong XMSLockEMB(void);
     unsigned XMSUnLockEMB(void);
     unsigned XMSMoveBlock(void);


     unsigned Handle;
     unsigned light_memory;
     unsigned XMSError;            // ��� �訡��
     struct XMSMove MoveBlockParameters;
     /* ���� ��ࠬ��஢ ��� ��७�� ��� � ���७��� ����� */

  };
#endif

