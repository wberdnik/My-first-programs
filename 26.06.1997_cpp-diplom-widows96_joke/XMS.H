/* ------------------------------------------------------- */
/*      Заголовочный файл для собственных функций          */
/*            управления расширенной памятью               */
/* ------------------------------------------------------- */

#if !defined(DEF_XMS)
#define    NOTINSTALLED 0
#define    NOERROR      1

typedef unsigned long dword;

#include"board.h"

struct XMSMove
{
// 4 байта: размер блока в байтах (четное число)
//  Размер переносимого блока в байтах
	unsigned long  Lenght       ;

// 2 байта:дескриптор источника (0-стандартная память)
//      XMS-префикс блока источника
	unsigned       SourceHandle ;

// 4 байта: смещение блока в источнике (seg:off - стандартная память)
//      Смещение от начала блока источника или
//      far pointer, если SourseHandle = 0
	unsigned long  SourceOffset;

// 2 байта:дескриптор приемника (0-стандартная память)
//      XMS-префикс блока назначения
	unsigned       DestHandle   ;

// 4 байта:смещение блока в приемнике (seg:off - стандартная память)
//      Смещение от начала блока назначения или
//      far pointer, если DestHandle = 0
	unsigned long  DestOffset;
};

//unsigned      XMSInstalled       ( void );
unsigned        XMSRequestHMA      ( unsigned Space );
unsigned        XMSReleaseHMA      ( void );
unsigned        XMSGlobalEnableA20 ( void );
unsigned        XMSGlobalDisableA20( void );
unsigned        XMSLocalEnableA20  ( void );
unsigned        XMSLocalDisableA20 ( void );
//unsigned      XMSQueryA20        ( void );
unsigned        XMSQueryLargestFree( void );
unsigned        XMSQueryTotalFree  ( void );
unsigned        XMSAllocateEMB     ( unsigned SizeK );
unsigned        XMSFreeEMB         ( unsigned Handle );
unsigned        XMSMoveBlock       ( void );
unsigned        XMSReleaseUMB      ( unsigned Segment );
unsigned        XMSUnLockEMB       ( unsigned Handle );
long            XMSGetHandleInfo   ( unsigned Handle );
long            XMSReallocateEMB   ( unsigned Handle,unsigned NewSizeK );
long            XMSRequestUMB      ( unsigned SizeP );
//long          XMSVersion         ( void );
long            XMSLockEMB         ( unsigned Handle);
//void          XMS_SayErrorMSG    ( unsigned Ecode );





#define         DEF_XMS 1
#endif
