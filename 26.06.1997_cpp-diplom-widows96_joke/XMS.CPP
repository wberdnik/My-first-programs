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
xx.ss.a=a;   // А может и наоборот xx.a=b;xx.b=a;
xx.ss.b=b;
return (void far*)xx.c;       }


extern	struct XMSMove MoveBlockParameters;
	/* Блок параметров для переноса инфо в расширенной памяти */


Xms::Xms(){
  // инициализировать драйвер
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
     error("Длина переносимого блока больше выделенной памяти");
     //??добавить изменение памяти на нужную величину
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
    a="Ошибка неизвестна";
    switch(Ecode){
	case 0x04:  a="Указатель за предел выделенной памяти  ";break;
	case 0x80:  a="Функция не поддерживается XMS драйвером";break;
	case 0x81:  a="HMA использовал Виртуальный Диск       ";break;
	case 0x82:  a="Ошибка линии А20 		      ";break;
	case 0x8E:  a="Внутренняя ошибка XMS-драйвера	      ";break;
	case 0x8F:  a="Невосстановимая ошибка XMS-драйвера    ";break;
	case 0x90:  a="HMA не существует  		      ";break;
	case 0x91:  a="HMA уже используется		      ";break;
	case 0x92:  a="Размер меньше параметра XMS-драйвера  /HMAMIN = error";break;
	case 0x93:  a="HMA не выделена		              ";break;
	case 0x94:  a="Линия А20 уже разрешена		      ";break;
	case 0xA0:  a="Нет свободной XMS памяти               ";break;
	case 0xA1:  a="Все дескрипторы использованы	      ";break;
	case 0xA2:  a="Неправильный дескриптор  	      ";break;
	case 0xA3:  a="Неправильный дескриптор источника      ";break;
	case 0xA4:  a="Неправильное смещение в источнике      ";break;
	case 0xA5:  a="Неправильный дескриптор приемника      ";break;
	case 0xA6:  a="Неправильное смещение в приемнике      ";break;
	case 0xA7:  a="Неправильная длина of block            ";break;
	case 0xA8:  a="Неправильное перекрытие при перемещении";break;
	case 0xA9:  a="Ошибка паритета                        ";break;
	case 0xAA:  a="Блок не блокирован                     ";break;
	case 0xAB:  a="Блок блокирован                        ";break;
	case 0xAC:  a="Переполнение счетчика блокировок       ";break;
	case 0xAD:  a="Неправильная блокировка                ";break;
	case 0xB0:  a="UMB don't make allocated               ";break;
	case 0xB1:  a="Not enought UMB                        ";break;
	case 0xB2:  a="Bad UMB segment                        ";break;
	case NOTINSTALLED: a="XMS driver not installed        ";
	}
	error(a);
}


/* Определяет общий объем свободной XMS памяти */
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


/* Запрос состояния линии A20 */
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


/* Глобальное деблокироварие линии A20 */
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

/* Глобальное блокирование линии A20 */
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

/* Определяет размер наибольшего свободного блока XMS памяти */
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

/* Распределение в XMS памяти блока в SizeK Kb */
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


/* Возвращает информацию о блоке с Handle указателем в XMS памяти */
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


/* Запирает в XMS памяти блок с Handle указателем */
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

/* Отпирает в XMS памяти блок с Handle указателем */
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

/* Перемещает блок информации в XMS памяти */
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

