#ifndef BOARDH
#define BOARDH

#ifndef  DOSH
#define  DOSH
#include <dos.h>
#endif

			     // strBoard.type принимает значения:::

enum{ tNo,
      tRound,
      tRectangle,
      tMore,
      tFree,
      };


typedef struct {

	char type;		// тип топологических границ
	float mashtx;           // масштаб по оси Х
	float mashty;           // масштаб по оси У

	unsigned number;	// число станций
	unsigned doplam;        // допустим проп способность
	char     ncentre;       // количество АТС
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
	char modemath;                  // режим трассировки
			  } strDlins;

typedef struct {
		strStation  station;
		float c[5];
		float d[5];
		int  ci[5];             // координаты ЦК
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