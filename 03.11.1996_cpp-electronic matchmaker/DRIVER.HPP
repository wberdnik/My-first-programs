#ifndef DRIVER
#define DRIVER
#include"cler.hpp"
#include"comp.hpp"
#include"iosys.hpp"
//����� �ࠢ����� ��⥫���㠫쭮� �����⥬��
class Driver {
  Cler* homer;
  Cler* kandidat;
  Comp* comp;
  long n_gr;
  long size_group;
  Iosys* base;
  public:
  Driver(Iosys* a,long n_kat,long n_men,long n_group);
  void run(char mark); // ��㡨�� �業��
  void sort(int number); //᪮�쪮 �����⮢ ��⠢���
  virtual float aprior(marks&);
  marks* operator[](int a){if(a<end)(*comp)[a];return &comp->get();};
   long end;
  ~Driver(){delete comp;}
};
#endif