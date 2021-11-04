#include"excheng.hpp"
#include"worktype.hpp"
#include"error.hpp"
#include<stdio.h>
#include<string.h>


 const char* pole[10] ={ "C\xb FIELDNAME",    // 0      ima pola
			 "C\x9 FILENAME",    // 1       ima file
			 "C\x31 DATA",       // 2       opisanie dannix
			 "N\x4 DESCRIPT",    // 3      qulitty
			 "N\x2 ACSESS",      // 4      dostup
			 "N\x4 WEIGHT",      // 5      ves
			 "N\x4 HIGH",        // 6      chethik
			 "N\x4 HIMSELF",     // 7      xarakter
			 "N\x4 YOUSELF",     // 8      trebovania
			 "C\x1 TYPEINFO"};   // 9      type


		   //    n  1  2  3  4  5
 const char* pofi[5] ={"\x3\x0\x1\x4",      // katalog 0
		      "\x3\x0\x1\x9",      // katalof 1
		      "\x3\x2\x5\x6",      // xarakter
		      "\x3\x0\x1\x4",      // main
		      "\x6\x3\x7\x8\x5\x3\x4" // work
			};
 //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Type::Type(char tipe)
{error(tipe>4,SYSTEM,"Попытка открыть файл неизвестного типа worktype");
 type=tipe;
  char* c;char* d;
  char e=0;
  c=(char*)pofi[type];
   number=c[0];
  for(int i=0;i<number;i++)
   {d=(char*)pole[c[i+1]];
    field[i].type=d[0];
    field[i].dlins=d[1];
    e+=d[1];
    field[i].name=d+2;
   }
   dlins=e+1;
};

char* Type::great(char* a)
{error(a[0]==0,SYSTEM,"имя не найдено");
 strncpy(sbros,vlad.path,70);
 a[8]=0;
 strcat(sbros,a);
 strcat(sbros,vlad.extend);
   return sbros;
};

char* Type :: toname(void)
 {switch(type)
   {case tKat0: return vlad.namekat0;
    case tKat1: return vlad.namekat1;
    case tXar: return vlad.namexar;
    case tMain: return vlad.namemain;
    case tWork: return vlad.namework;
   };
   return NULL;
  };
