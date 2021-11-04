#ifndef CLER
#define CLER
 #include"iosys.hpp"
 #include"swaha.h"
// дубликат файла о клиенте
class Cler : public Spisok {
   Iosys * from;
   SLOT t;
   Var at;
   public:
 Cler(Iosys* a,long n_kat ,long n_cler);
 SLOT& get(void){return *((SLOT*)thethat->data);};
 SLOT& find (long);          // поиск группы
 };
#endif