#include<stdio.h>
#include<string.h>
#include<dir.h>
#include"excheng.hpp"
#define iiiii
#include"config.hpp"


Config *_klassconfig;


char* text[6]={"\t\tФайл конфигурации программы SWAHA :",
		"\r\nТекущий каталог :",
		"\r\nИмена корневых файлов :",
		"\r\nИмя последнего файла :",
		"\r\nРасширения всех файлов :",
		"\r\nСтек имен : "};

//-----------------------------------------------------------------
Config::Config():Steck(9)
{det='#';
 lastname="aa000000";
 max=500;
 FILE * fil;
 fil=fopen(vlad.nameconfig,"r");
 if(fil==NULL){error(1,WARNING," не обнаружен файл конфигурации");
		test();return;}
 ane=new (0) File(vlad.nameconfig);
 (*ane)%1;
  error(!(find(*ane,vlad.path,70)&&
	  find(*ane,vlad.namekat0,8)&&
	  find(*ane,vlad.namekat1,8)&&
	  find(*ane,lastname,8)&&
	  find(*ane,vlad.extend,4)),CONFIGI," "
	  "Не полная информация в файле конфигурации ");
	 char ss[9];
	 while(find(*ane,ss,8)) push(ss);
	 delete ane;
      if(one.end==0) return;

	 // Выделение сбойных имен
	 Wait ccc('?');
	 Var x=9;
	 Var y=9;
	   for(long i=0;i<one.end-1;i++)
	    for(long j=i+1;j<one.end;j++)
	     { x=one[i];           //Берем по 1 записи
	       y=one[j];
	       if(x.data[7]==y.data[7]) //для скорости
		if(!strncmpi(x.data,y.data,9))
		  {one[one.end-1];
		   one(j);
		   one-1;           //удаляем
		  }
	      }

};

Config::~Config()
{ane=new (0) File(vlad.nameconfig);
 *ane-ane->end;
 ane->tprint(text[0]);

 ane->tprint(text[1]);
 format(*ane,vlad.path,70);

 ane->tprint(text[2]);
 format(*ane,vlad.namekat0,8);
 format(*ane,vlad.namekat1,8);

 ane->tprint(text[3]);
 format(*ane,lastname,8);

 ane->tprint(text[4]);
 format(*ane,vlad.extend,4);
  char name[8];
 ane->tprint(text[5]);
   name[0]=0;

 while(flag()!=0) {format(*ane,pop(name),8);}
 delete ane;
}

char* Config::getname(char* a)
{if(flag()!=0) pop(a);
  else  newname(a);
  a[8]=0;
 char *patch=new(0)char[80];
 strcpy(patch,vlad.path);
 strcat(patch,a);
 strcat(patch,vlad.extend);
 FILE* file=fopen(patch,"r");
   if(file!=NULL){fclose(file);return getname(a);}
  delete patch;
  return a;
};
char* Config::retname(char* a)
{if(flag()>=max){rename();reset();return a;}
  return  push(a);
 };
//---------------------------------------------------------------
char* Config::newname(char* a)
     {lastname[8]=0;
      lastname[7]++;
      for(int i=7; i>0;i--)
       {if(lastname[i]<'0')lastname[i]='0';
	if((lastname[i])>'9')
	  {lastname[i-1]++;
	   lastname[i]='0';};
	}
      strncpy(a,lastname,8);
     return a;};

int Config::find(File& one,char* a,int b)
{Var x=1;
 for(long i=0;i<one.end;i++)
   {x=one[i];
    if(x.data[0]==det)
       {one+=i+1;
	for(long j=0;j<one.end && j<b;j++)
	 {x=one[j];
	  if(x.data[0]==det){*(a+int(j))=0;break;}
	  *(a+int(j))=x.data[0];}
	 one+=j+1;
	 return 1;
       };
    }
 return 0;
}
void Config::format(File& one,char* a,int b)
{one.tprint("\r\n",2);
 one.tprint(&det,1);
 one.tprint(a,b);
 one.tprint(&det,1);
};

void Config::test(void)
{strcpy(vlad.path,"base\\");
 strcpy(vlad.extend,".dbf");
 strcpy(vlad.nameconfig,"swaha.cfg");
 strcpy(vlad.namekat0,"listman");
 strcpy(vlad.namekat1,"listqull");
  mkdir("base");
 };

