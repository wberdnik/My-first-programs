#include<string.h>
#include"main.hpp"
#include"excheng.hpp"
#include"config.hpp"

void Main::build(char a)
{ if(a){_klassconfig->getname(vlad.namework);
	     flag='*';};
 at.data[0]=flag;
 memcpy(at.data+1,vlad.namemen+1,11);
 memcpy(at.data+12,vlad.namework,9);
 at.data[20]=0;
 *(int*)(at.data+21)=vlad.acssesmen;
 };
void Main::debuild(void)
{flag=at.data[0];
 if(flag!='*')flag=32;
 memcpy(vlad.namemen,at.data,12);
 memcpy(vlad.namework,at.data+12,9);
 vlad.typeinfo=*(int*)(at.data+21);
};
Main::~Main()
{char a;
 if(stop==0)a='*';
    else a=32;
 Dbf* x=new (0) Dbf(0);
 Var ll(x->dlins);
 ll=(*x)[root];
 ll.data[0]=a;
 (*x)[root]=ll;
 delete x;
   dest();
};
int Main::ifcan(void)
{Dbf *var;
 var=new Dbf(4);
 char name[80];
 strncpy(name,!(*var),80);
 delete var;
  unlink(name);
 _klassconfig->retname(vlad.namework);
 return 1;
}


