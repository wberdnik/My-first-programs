/* ------------------------------------------------------- */
/*      ���������� 䠩� ��� ᮡ�⢥���� �㭪権          */
/*            �ࠢ����� ���७��� �������               */
/* ------------------------------------------------------- */

#if !defined(DEF_XMS)
#define    NOTINSTALLED 0
#define    NOERROR      1

typedef unsigned long dword;

#include"board.h"

struct XMSMove
{
// 4 ����: ࠧ��� ����� � ����� (�⭮� �᫮)
//  ������ ��७�ᨬ��� ����� � �����
	unsigned long  Lenght       ;

// 2 ����:���ਯ�� ���筨�� (0-�⠭���⭠� ������)
//      XMS-��䨪� ����� ���筨��
	unsigned       SourceHandle ;

// 4 ����: ᬥ饭�� ����� � ���筨�� (seg:off - �⠭���⭠� ������)
//      ���饭�� �� ��砫� ����� ���筨�� ���
//      far pointer, �᫨ SourseHandle = 0
	unsigned long  SourceOffset;

// 2 ����:���ਯ�� �ਥ����� (0-�⠭���⭠� ������)
//      XMS-��䨪� ����� �����祭��
	unsigned       DestHandle   ;

// 4 ����:ᬥ饭�� ����� � �ਥ����� (seg:off - �⠭���⭠� ������)
//      ���饭�� �� ��砫� ����� �����祭�� ���
//      far pointer, �᫨ DestHandle = 0
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
