#include<string.h>
#include"iosys.hpp"

Iosys::~Iosys(){
 delete one;
 delete spirit;
 delete _klassconfig;};

 Iosys::Iosys(char a)	{
     _klassconfig=new (0) Config();
	 a++;
     one=new (0) Kat0(0);
     type=tKat0;
     stop1=vlad.stop;

     spirit=new (0) Kat1(0);
     type1=tKat1;

     long b=vlad.stop;
     vlad.stop=stop1;
     stop1=b;
     };


Iosys& Iosys::ini(void)
{if(vlad.file==-1){strcpy(vlad.inifile,"᢮�����");
		   strcpy(vlad.initreb,"<�� ����� ���祭��>");
		   strcpy(vlad.inixar,"<�� �����⭮>");
			    return *this;}
 char flag=type;
   set(tKat1);

 //�⫠��筠� ����
 if(vlad.file>=vlad.stop){strcpy(vlad.inifile,"᢮�����");
			  strcpy(vlad.initreb,"<�� ����� ���祭��>");
			  strcpy(vlad.inixar,"<�� �����⭮>");
			  return set(flag);
			    }
 (*one)[vlad.file];
 strncpy(vlad.inifile,vlad.namequllity+1,11);

 down();

if(vlad.treb>=vlad.stop)
     {error(1,OPERATOR,"bad vlad.treb");
       vlad.treb=-1;}

if(vlad.xar>=vlad.stop)
     {error(1,OPERATOR,"bad vlad.xar");
       vlad.xar=-1;}


if(vlad.treb!=-1)
  { (*one)[vlad.treb];
   strncpy(vlad.initreb,vlad.qullity+1,49);
   vlad.weighttr=vlad.weigtqullity;}
  else {
      strcpy(vlad.initreb,"<�� ����� ���祭��>");
      vlad.weighttr=0;}

if(vlad.xar!=-1)
  {(*one)[vlad.xar];strncpy(vlad.inixar,vlad.qullity+1,49);}
  else strcpy(vlad.inixar,"<�� �����⭮>");

  return set(flag);};

Iosys& Iosys::down(void)
{ switch(type)
 {
	case tKat0: {delete one;myk=one->yk; //myk => 3-��� ����������
		     one=new (0) Main(one->yk);
		     type=tMain; return *this;};
	case tKat1: {delete one;
		     one=new (0) Xar(one->yk);
		     type=tXar; return *this;};
	case tMain: {delete one;
		     one=new (0) Work(one->yk);
		     type=tWork; return *this;};
  };
  error(1,OPERATOR,"����� ��� ����");    return *this;};

Iosys& Iosys::up(void)
{ switch(type)
 {
	case tXar: {delete one;
		    one=new (0) Kat1(0);
		    type=tKat1; return *this;};
	case tMain: {delete one;
		     one=new (0) Kat0(0);
		     type=tKat0; return *this;};
	case tWork: {delete one;
		     one=new (0) Main(myk);
		     type=tMain; return *this;};
  };
  error(1,OPERATOR,"��� �����");    return *this;};

Iosys& Iosys::kat(void)
{Live* a; char b;
 a=one; one=spirit; spirit=a;
 b=type;type=type1; type1=b;
 long c=vlad.stop;
 vlad.stop=stop1;
 stop1=c;
  return *this;}
