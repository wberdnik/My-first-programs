#include <stdio.h>
#include <dos.h>
#include<stdlib.h>
#include "xms.h"

#include"xms.hpp"

void far* MakeFP(int,int);
union{
	struct {
		int b;
		int a;
		}ss;
	long c;
      }xx;

void far* MakeFP(int a,int b){
xx.ss.a=a;   // � ����� � ������� xx.a=b;xx.b=a;
xx.ss.b=b;
return (void far*)xx.c;       }


extern	struct XMSMove MoveBlockParameters;
	/* ���� ��ࠬ��஢ ��� ��७�� ��� � ���७��� ����� */


Xms::Xms(){
  // ���樠����஢��� �ࠩ���
_AX = 0x4300;
 geninterrupt(0x2F);
 if (_AL != 0x80)
  {
   XMSError=NOTINSTALLED;
 //  XMS_SayErrorMSG(XMSError);
   (long)XMSControl = 0L;
   return;
  }
_AX = 0x4310;
 geninterrupt(0x2F);
 XMSControl = (void far (*) (void))MakeFP(_ES,_BX);
 XMSError=NOERROR;
}

void Xms::add(ulong ){
//  size of file filelength(fileno(sdb));

		     }
void Xms::write(void far* a)
 {
  MoveBlockParameters.SourceHandle=0;
  MoveBlockParameters.SourceOffset=(ulong)a;
  MoveBlockParameters.DestHandle=Handle;
  MoveBlockParameters.DestOffset=Offset;
  XMSMoveBlock();
 }

void Xms::read(void* a)
 {
  MoveBlockParameters.SourceHandle=Handle;
  MoveBlockParameters.SourceOffset=Offset;
  MoveBlockParameters.DestHandle=0;
  MoveBlockParameters.DestOffset=(ulong)a;
  XMSMoveBlock();
 }

void Xms::set(ulong a,ulong b,ulong light)
 { end=2;
  if(a>((unsigned long int)light*1024)||(b+a)>((unsigned long int)light*1024))
   {
     clrscr();
     error("����� ��७�ᨬ��� ����� ����� �뤥������ �����");
     //??�������� ��������� ����� �� �㦭�� ����稭�
   }
  MoveBlockParameters.Lenght=a;
  Offset=b;
 }

Xms::~Xms(){
  if ((long)XMSControl == 0L)
   {
    return;
    }
/*  _AH = 0x0A;
  _DX = Handle;
  XMSControl();
  if (_AX == 0) XMS_SayErrorMSG(0x00FF&_BL);
  XMSError=NOERROR;*/

	    }


void Xms::XMSDelete(void){
  if ((long)XMSControl == 0L)
   {
    return;
    }
  _AH = 0x0A;
  _DX = Handle;
  XMSControl();
  if (_AX == 0) XMS_SayErrorMSG(0x00FF&_BL);
  XMSError=NOERROR;

	    }


void   Xms::XMS_SayErrorMSG(unsigned Ecode){
char* a;
    a="�訡�� �������⭠";
    switch(Ecode){
	case 0x04:  a="�����⥫� �� �।�� �뤥������ �����  ";break;
	case 0x80:  a="�㭪�� �� �����ন������ XMS �ࠩ��஬";break;
	case 0x81:  a="HMA �ᯮ�짮��� ����㠫�� ���       ";break;
	case 0x82:  a="�訡�� ����� �20 		      ";break;
	case 0x8E:  a="����७��� �訡�� XMS-�ࠩ���	      ";break;
	case 0x8F:  a="������⠭������ �訡�� XMS-�ࠩ���    ";break;
	case 0x90:  a="HMA �� �������  		      ";break;
	case 0x91:  a="HMA 㦥 �ᯮ������		      ";break;
	case 0x92:  a="������ ����� ��ࠬ��� XMS-�ࠩ���  /HMAMIN = error";break;
	case 0x93:  a="HMA �� �뤥����		              ";break;
	case 0x94:  a="����� �20 㦥 ࠧ�襭�		      ";break;
	case 0xA0:  a="��� ᢮������ XMS �����               ";break;
	case 0xA1:  a="�� ���ਯ��� �ᯮ�짮����	      ";break;
	case 0xA2:  a="���ࠢ���� ���ਯ��  	      ";break;
	case 0xA3:  a="���ࠢ���� ���ਯ�� ���筨��      ";break;
	case 0xA4:  a="���ࠢ��쭮� ᬥ饭�� � ���筨��      ";break;
	case 0xA5:  a="���ࠢ���� ���ਯ�� �ਥ�����      ";break;
	case 0xA6:  a="���ࠢ��쭮� ᬥ饭�� � �ਥ�����      ";break;
	case 0xA7:  a="���ࠢ��쭠� ����� of block            ";break;
	case 0xA8:  a="���ࠢ��쭮� ��४��⨥ �� ��६�饭��";break;
	case 0xA9:  a="�訡�� �����                        ";break;
	case 0xAA:  a="���� �� �����஢��                     ";break;
	case 0xAB:  a="���� �����஢��                        ";break;
	case 0xAC:  a="��९������� ���稪� �����஢��       ";break;
	case 0xAD:  a="���ࠢ��쭠� �����஢��                ";break;
	case 0xB0:  a="UMB don't make allocated               ";break;
	case 0xB1:  a="Not enought UMB                        ";break;
	case 0xB2:  a="Bad UMB segment                        ";break;
	case NOTINSTALLED: a="XMS driver not installed        ";
	}
	error(a);
}


/* ��।���� ��騩 ��ꥬ ᢮������ XMS ����� */
unsigned Xms::XMSQueryTotalFree(void)
{
  if ((long)XMSControl == 0L)
   {
//  XMS_SayErrorMSG(NOTINSTALLED);
    return(XMSError=NOTINSTALLED);
   }
  _AH = 0x08;
  XMSControl();
  if(_BL != 0)
   {
    XMSError=0x00FF&_BL;
//    XMS_SayErrorMSG(XMSError);
    return (XMSError);
   }
  XMSError = NOERROR;
  return (_DX);
}


/* ����� ���ﭨ� ����� A20 */
unsigned Xms::XMSQueryA20(void)
{
   if ((long)XMSControl == 0L)
    {
     XMS_SayErrorMSG(NOTINSTALLED);
     return(XMSError=NOTINSTALLED);
    }
   _AH = 0x07;
   XMSControl();
   if(_BL != 0)
    {
     XMSError=0x00FF&_BL;
     XMS_SayErrorMSG(XMSError);
     return (XMSError);
    }
   XMSError = NOERROR;
   return(_AX);
}


/* ������쭮� �������஢�ਥ ����� A20 */
unsigned Xms::XMSGlobalEnableA20(void)
{
 if ((long)XMSControl == 0L)
   {
    XMS_SayErrorMSG(NOTINSTALLED);
    return(XMSError=NOTINSTALLED);
   }
 _AH = 0x03;
 XMSControl();
 if(_AX == 0)
  {
   XMSError=0x00FF&_BL;
   XMS_SayErrorMSG(XMSError);
   return (XMSError);
  }
 return(XMSError=NOERROR);
}

/* ������쭮� �����஢���� ����� A20 */
unsigned Xms::XMSGlobalDisableA20(void)
{

   if ((long)XMSControl == 0L)
    {
     XMS_SayErrorMSG(NOTINSTALLED);
     return(XMSError=NOTINSTALLED);
    }
   _AH = 0x04;
   XMSControl();
   if(_AX == 0)
    {
     XMSError=0x00FF&_BL;
     XMS_SayErrorMSG(XMSError);
     return (XMSError);
    }
   return(XMSError=NOERROR);
}

/* ��।���� ࠧ��� �������襣� ᢮������� ����� XMS ����� */
unsigned Xms::XMSQueryLargestFree(void)
{
  if ((long)XMSControl == 0L)
   {
    XMS_SayErrorMSG(NOTINSTALLED);
    return(XMSError=NOTINSTALLED);
   }
  _AH = 0x08;
  XMSControl();
  if(_BL != 0)
   {
    XMSError=0x00FF&_BL;
    XMS_SayErrorMSG(XMSError);
    return (XMSError);
   }
  XMSError = NOERROR;
  return(_AX);
}

/* ���।������ � XMS ����� ����� � SizeK Kb */
unsigned Xms::XMSAllocateEMB(void)
{
  if ((long)XMSControl == 0L)
   {
    XMS_SayErrorMSG(NOTINSTALLED);
    return(XMSError=NOTINSTALLED);
   }
  _AH = 0x09;
  _DX = light_memory;//unsigned SizeK;
  XMSControl();
  if (_AX == 0) 
   {
    XMSError=0x00FF&_BL;
    XMS_SayErrorMSG(XMSError);
    return (XMSError);
   }
  XMSError = NOERROR;
  return(_DX);
}


/* �����頥� ���ଠ�� � ����� � Handle 㪠��⥫�� � XMS ����� */
ulong Xms::XMSGetHandleInfo(unsigned Handle)
{
  int	bx,dx;
  if ((long)XMSControl == 0L)
   {
    XMS_SayErrorMSG(NOTINSTALLED);
    return(XMSError=NOTINSTALLED);
   }
  _AH = 0x0E;
  _DX = Handle;
  XMSControl();
  bx = _BX;	dx = _DX;
  if (_AX == 0) 
   {
    XMSError=0x00FF&_BL;
    XMS_SayErrorMSG(XMSError);
    return (XMSError);
   }
  XMSError = NOERROR;
  return(((long)(dx)<<16)|(unsigned)(bx));
}


/* ����ࠥ� � XMS ����� ���� � Handle 㪠��⥫�� */
ulong Xms::XMSLockEMB(void)   //unsigned Handle
{
  unsigned dx,bx;

  if ((long)XMSControl == 0L)
   {
    XMS_SayErrorMSG(NOTINSTALLED);
    return(XMSError=NOTINSTALLED);
   }
  _AH = 0x0C;
  _DX = Handle;
  XMSControl();
  dx = _DX;	bx = _BX;
  if (_AX == 0)
   {
    XMSError=0x00FF&_BL;
//    XMS_SayErrorMSG(XMSError);
    return (XMSError);
   }
  XMSError = NOERROR;
  return((long)((dx&0x7F)<<16)|(unsigned)(bx));
}

/* �⯨ࠥ� � XMS ����� ���� � Handle 㪠��⥫�� */
unsigned Xms::XMSUnLockEMB(void)   //unsigned Handle
{
  if ((long)XMSControl == 0L)
   {
    XMS_SayErrorMSG(NOTINSTALLED);
    return(XMSError=NOTINSTALLED);
   }
  _AH = 0x0D;
  _DX = Handle;
  XMSControl();
  if (_AX == 0)
   {
    XMSError=0x00FF&_BL;
//    XMS_SayErrorMSG(XMSError);
    return (XMSError);
   }
  return(XMSError=NOERROR);
}

/* ��६�頥� ���� ���ଠ樨 � XMS ����� */
unsigned Xms::XMSMoveBlock(void)
{
 unsigned g;

  if ((long)XMSControl == 0L)
   {
    XMS_SayErrorMSG(NOTINSTALLED);
    return(XMSError=NOTINSTALLED);
   }

  _SI= FP_OFF((struct XMSMove far *)&MoveBlockParameters);
  g=_DS;
  _DS= FP_SEG((struct XMSMove far *)&MoveBlockParameters);
  _AH = 0x0B;
  XMSControl();
  _DS=g;
  if (_AX == 0)
   {
    XMSError=0x00FF&_BL;
    XMS_SayErrorMSG(XMSError);
    return (XMSError);
   }
  return(XMSError=NOERROR);
}

/*Mem* Xms::myalloc(int n)
 {Mem a;

  a.memstart=-1;
  a.memend=-1;
  a.xmsstart=-1;
  a.xmsend=-1;
  a.diskstart=-1;
  a.diskend=-1;

  if(n<=50)
   {
    a.flag=vRam;
    a.memstart=0;
    a.memstart=n*n-1;
    int *proba;
    proba=new int[n*n];
    a.MEMoffset=proba;
   }

  return &a;
 } */

/*Xms& Xms::operator-=(ulong a){
 if(a<=0){error("Xms::-=");exit(33);}
 start-=a*len;end+=a;that+=a;realend+=a*len;
 set(that);
 return *this;}

Xms& Xms::operator+=(ulong a){
  if(a<=0){error("Xms::+=");exit(33);}
  start+=a*len;end-=a;realend-=a*len;
  that-=a;
  if(that<0)    {that=0;set(0);}
  return *this;}

Xms& Xms::operator%(unsigned a){
  if(a<=0){error("Xms:: operator%");exit(33);}
  end=realend;that*=len;
  len=a;
  end/=len;that/=len;
  set(that);          //that drobnoe
  return *this;}; */

