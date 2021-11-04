#include<string.h>
#include"kat0.hpp"
#include"excheng.hpp"
#include"config.hpp"

Kat0::~Kat0()
{dest();};

void Kat0::setfl(char a)
 {a++;return;};

void Kat0::build(char a)
{if(a){_klassconfig->getname(vlad.namemain);
			 flag='*';}
 at.data[0]=flag;
 memcpy(at.data+1,vlad.nametom+1,11);
 memcpy(at.data+12,vlad.namemain,9);
 at.data[20]=0;
 ((int*)at.data+1)[20]=vlad.keytom;
 };
void Kat0::debuild(void)
{flag=at.data[0];
 if(flag!='*')flag=32;
 memcpy(vlad.nametom,at.data,12);
 memcpy(vlad.namemain,at.data+12,9);
 vlad.keytom=(int)(at.data+1)[20];
};
int Kat0::ifcan(void)
{Dbf *var;
 var=new (0) Dbf(3);
 char name[80];
 strncpy(name,!(*var),80);
 if(var->end==0){delete var;unlink(name);
		_klassconfig->retname(vlad.namemain);
		 return 1;}
 delete var;
 return 0;
}
