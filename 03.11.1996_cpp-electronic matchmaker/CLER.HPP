#ifndef CLER
#define CLER
 #include"iosys.hpp"
 #include"swaha.h"
// �㡫���� 䠩�� � ������
class Cler : public Spisok {
   Iosys * from;
   SLOT t;
   Var at;
   public:
 Cler(Iosys* a,long n_kat ,long n_cler);
 SLOT& get(void){return *((SLOT*)thethat->data);};
 SLOT& find (long);          // ���� ��㯯�
 };
#endif