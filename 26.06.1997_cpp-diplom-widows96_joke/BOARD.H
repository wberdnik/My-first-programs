#ifndef BOARDH
#define BOARDH

#ifndef  DOSH
#define  DOSH
#include <dos.h>
#endif

			     // strBoard.type �ਭ����� ���祭��:::

enum{ tNo,
      tRound,
      tRectangle,
      tMore,
      tFree,
      };


typedef struct {

	char type;		// ⨯ ⮯������᪨� �࠭��
	float mashtx;           // ����⠡ �� �� �
	float mashty;           // ����⠡ �� �� �

	unsigned number;	// �᫮ �⠭権
	unsigned doplam;        // �����⨬ �ய ᯮᮡ�����
	char     ncentre;       // ������⢮ ���
	char add;
	unsigned centre[5];
	struct time gtime;
	struct date gdate;

	struct time gtime2;
	struct date gdate2;
		} strStation;



typedef struct{
	struct time gtime;
	struct date gdate;
	unsigned number;
	char modemath;                  // ०�� ����஢��
			  } strDlins;

typedef struct {
		strStation  station;
		float c[5];
		float d[5];
		int  ci[5];             // ���न���� ��
		int  di[5];
			    } strCentre;
typedef struct{
	       char ident;
	       char name[30];
	       long cena;
	       long potok;
	       long outfq;
	       long infq;
	       int input;
	       int inpotok;
	       } strConcent;
typedef struct{
	       char ident;
	       char name[30];
	       long cena;
	       long potok;
	       long outfq;} strCabel;

#endif