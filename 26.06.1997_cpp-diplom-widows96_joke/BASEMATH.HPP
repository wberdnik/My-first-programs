#ifndef BASEMATH
#define BASEMATH
#include"board.h"

#ifndef  GSIMPLE
#include "gsimple.hpp"
#endif

#ifndef  SOURSE
#include "sourse.hpp"
#endif

#ifndef   EVENT
#include "event.hpp"
#endif


extern maxstation;
class Gobject;

class BaseMath{
public:
// mathimatic:
float * c;float * d;// ⮯������᪨� ���न��� �⠭権
int *ci;int *di;    // ��࠭�� ���न����
int *em;            // ���ଠ樮���� ������� �⠭権
unsigned n;         // �᫮ �⠭権

// common:

int **m;           //hlam

int tr1,tr2,tr3;    // �࠭���� ��६����
float there;

strStation too;     // ��������� stn 䠩��

Gobject * border;   // 㪠��⥫� �� ����஫� ⮯������᪨� �࠭��

char flagworking;

 BaseMath();

 void pixcel(void);
 void sort(void);
 void move(int,int);
 void LoadHeadStn(File&);
 int LoadStn(File&);
 void SaveStn(File&);
 void SetBorder(void);
 int LoadAllStn(int);
 ~BaseMath();
};
#endif
