#include<string.h>
#include"kat1.hpp"
#include"excheng.hpp"
#include"config.hpp"

Kat1::~Kat1()
 {dest();};

void Kat1::setfl(char a)
{a++;return;};

void Kat1::build(char a)
{if(a){_klassconfig->getname(vlad.namexar);
	 flag='*';};
 at.data[0]=flag;
 memcpy(at.data+1,vlad.namequllity+1,11);
 memcpy(at.data+12,vlad.namexar,9);
 at.data[20]=0;
 at.data[21]=vlad.typeinfo;
 };
void Kat1::debuild(void)
{flag=at.data[0];
 if(flag!='*')flag=32;
 memcpy(vlad.namequllity,at.data,12);
 memcpy(vlad.namexar,at.data+12,9);
 vlad.typeinfo=at.data[21];
};

int Kat1::ifcan(void)
{Dbf *var;
 var=new (0) Dbf(2);
 char name[80];
 strncpy(name,!(*var),80);
 if(var->end==0){delete var;
		 unlink(name);
		 _klassconfig->retname(vlad.namexar);
		 return 1;}
 delete var;
 return 0;
}


