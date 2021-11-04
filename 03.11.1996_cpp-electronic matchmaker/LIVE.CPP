#include"live.hpp"
#include"excheng.hpp"

void Live::dest(void)
{ if(flagspiska==1)
   {if(one.end>stop)one-(one.end-stop);
    if(one.end<stop)one+(stop-one.end);
    for(long i=0;i<stop;i++)
     { at=(*ba)[i];
       one[i]=at;
     }
    delete ba;
   }
};

void Live::greatspisok(void)
{error(flagspiska==1,OPERATOR,"повторное связывание ::Spisok");
 ba=new (0) Spisok((int)mera);
 *ba+stop;
 for(long i=0;i<stop;i++)
   {at=one[i];
    (*ba)[i]=at;
    };
  flagspiska=1;
};

void Live::operator--(void)
 { if(stop==0){error(1,OPERATOR,"Удаление из пустого");
                return;}
   if(ifcan())
     {if(flagspiska){(*ba)[yk];(*ba)(stop-1);(*ba)-1;}
	else  {one[yk];one(stop-1);one-1;};
      stop--;
      vlad.stop=stop;
         yk=stop-1;}
 };
Live::Live(char a,long b):one(a),at(one.dlins+1)
  {stop=one.end;mera=one.dlins;
   at.data[one.dlins]=0;         //stop simvol
    vlad.stop=stop;
    flagspiska=0;
    root=b;
   };

void Live::operator[](long a)
  {error(a>=stop,OPERATOR,"Попытка чтения за пределами LIVE");
       if(a>=stop)a=stop-1;
   if(flagspiska==1) at=(*ba)[a];
	     else at=one[a];
   yk=a;debuild();
   };

 void Live::save(void)
 {build(0);
  if(flagspiska)(*ba)[yk]=at;
	else one[yk]=at;};

void  Live::next(void)
 {(*this)[yk+1];};

void Live::operator++(void)
 { if(flagspiska)*ba+1;
	     else one+1;
  stop++;
  vlad.stop=stop;
  build(1);
  if(flagspiska)(*ba)[stop-1]=at;
	   else  one[stop-1]=at;
 };

  
