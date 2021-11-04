#include<string.h>
#include"xar.hpp"
#include"excheng.hpp"
#include"config.hpp"

Xar::~Xar()
{ char a;
 a=stop==0?'*':' ';
  Dbf* x=new (0) Dbf(1);
  Var ll(x->dlins);
  ll=(*x)[root];
  ll.data[0]=a;
  (*x)[root]=ll;
 delete x;
 dest();
};

void Xar::build(char b){
XAR * my=(XAR*)at.data;
  memcpy(my->pole,vlad.qullity+1,49);
 if(!b){
  my->mark=' ';
  my->weightqullity=vlad.weigtqullity;
  my->chethik=vlad.chethik;
       }
  else{
  my->mark='*';
  my->weightqullity=my->chethik=0;
       }
 };
void Xar::debuild(void){
XAR * my=(XAR*)at.data;
 memcpy(vlad.qullity+1,my->pole,49);
 vlad.weigtqullity=my->weightqullity;
 vlad.chethik=my->chethik;
 vlad.qullity[0]=my->chethik==0?'*':' ';
};
int Xar::ifcan(void)
{if(yk==stop-1 && vlad.chethik==0)return 1;
 return 0;
}



