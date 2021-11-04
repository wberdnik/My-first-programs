#include<stdio.h>
#include<io.h>
#include<conio.h>
#include<alloc.h>
#include"sourse.hpp"

File& File::operator-=(long a)
{start-=a*len;end+=a;that+=a;realend+=a*len;
 set(that);
 error(start<0,SYSTEM,"маска пуста File::-=");
 return *this;}

File& File::operator+=(long a)
 {start+=a*len;end-=a;realend-=a*len;
  that-=a;
  if(that<0)
    {that=0;set(0);}
  return *this;}

File& File::operator%(int a)
 {end=realend;that*=len;
  len=a;
  end/=len;that/=len;
  set(that);          //that drobnoe
  return *this;};

void File::read(char* a)
 {Wait x('R');
  error(fread(a,len,1,one)!=1,READ,"File::read");
  that+=1;};

void File::add(long n)
 {char *c=(char*)calloc(len,1);
  set(end);
  Wait x('+');
  error(fwrite(c,len,size_t(n),one)!=n,WRITE,"File::add");
  realend+=len*n;
  if(c!=NULL)
    free(c);
  that=end+n;
 };


void File::del(long n)
 {Wait x('-');
   error(chsize(fileno(one),(end-n)*len+start)!=0,CHANGE,"F"
	 "ile::del");realend-=len*n;};

Base& File::operator=(Var& a)
 {Wait x('W');
  error(fwrite(a.data,len,1,one)!=1,WRITE,"File write");
  that++;
  return *this;
  };
void File::set(long a)
{Wait x('S');
 fseek(one,start+(unsigned long)a*len,SEEK_SET);};

File :: File(char * ima)
{ 	len=1;
	start=0;
	that=0;
	Wait x('O');
	one=fopen(ima,"rb+");
	if(one!=NULL)
	   { rewind(one);
	     end=filelength(fileno(one));
	     if(end!=0)
	      flag=1;
	     else flag=0;
	    }
	else
	    {error((one=fopen(ima,"wb+"))==NULL,OPEN,ima);
	     flag=0;
	     end=0;
	     }
	realend=end;
 }
 File::~File(void)
 {Wait x('C');
  error(fclose(one)!=0,CLOSE,"Файл почему-то не закрывается");
 };
void File::tprint(char* a,int b)
{for(int c=0;c<b && a[c]!=0;c++);
 Wait x('P');
 fseek(one,start,SEEK_SET);
 error(fwrite(a,c,1,one)!=1,WRITE,"Write in tprint");
 start+=c;
 that=0;
};


// *********************************************************************
//       s   s    ppppp    i      s   s      oooo    k     k
//      s         p    p         s          o    o   k    k
//       s        p    p   i      s         o    o   k   k
//        s       ppppp    i       s        o    o   kk k
//          s     p        i        s       o    o   k k
//           s    p        i          s     o    o   k  k
//      s    s    p        i     s    s     o    o   k   k
//       s  s     p        i      s  s       oooo    k    k
// **********************************************************************
/*   отладка
void Spisok::print(void)
{thethat=&otkat;
 int k=0;
 getch();
 for(int i=0;i<end+1;i++)
  {printf("\nномер%d\tуказат%p\tданные%c"
	  "%c",i,thethat,thethat->data[0],thethat->data[1]);
   if(thethat!=NULL)thethat=thethat->next;
   if(i==k+25){k+=25;getch();}
  }
 thethat=&otkat;
 that=-1;
 };*/
void Spisok::add(long a)
{ set(end-1);
  for(long i=0;i<a;i++)
	{thethat->next=new (0) struct spisok;
	 thethat=thethat->next;
	 thethat->data=new (0) char[len];
	};
	thethat->next=NULL;
  that=end;
};

void Spisok::del(long a)
{ struct spisok* b,*c;
  if(end==0)return;
  set(end-1-a);
  c=thethat->next;
  thethat->next=NULL;  //___________^___________
  long i=a;
while(c!=NULL)
  {b=c;
	 delete b->data;
	 c=b->next;
	 delete b;
	 i--;
	if(i<-1)error(1,SYSTEM,"программа зависла");
  }
};


void Spisok::set(long a)
{ //ускорители
 if(a<0){thethat=&otkat;that=a; return;}
 if(a==0){thethat=otkat.next;that=0;return;}

 if(a==that && thethat!=NULL) return;

   if(a==that+1 && thethat!=NULL){
    thethat=thethat->next;
    that=a;
    return;
    }


 if(a==that+2 && thethat!=NULL){
    thethat=thethat->next;
    thethat=thethat->next;
    that=a;
    return;
    }

  thethat=&otkat;
  for(long i=0;i<a+1;i++)
   {error((thethat=thethat->next)==NULL,SYSTEM,"Spisok: нет конца");
   }
  that=a;
};
Base& Spisok::operator=(Var& a)
{memcpy(thethat->data,a.data,len);
 return *this;
}

Spisok::Spisok(int a)
{end=0;  len=a;   that=-1;
  thethat=&otkat;
};

Base& Spisok::operator()(long a)
{error(a>end,SYSTEM,"Spisok: выход за пределы");
  if(end==0 && a==that) return *this;
  long ttt=that;

  struct spisok *b;
  struct spisok *last[2];

  set(ttt-1);    last[0]=thethat;
  set(a-1);      last[1]=thethat;

  b=last[0]->next;
  (last[0]->next)=last[1]->next;
  (last[1]->next)=b;

  last[0]=last[0]->next;
  last[1]=last[1]->next;

  b=last[0]->next;
  (last[0]->next)=last[1]->next;
  (last[1]->next)=b;

   set(ttt);
  return *this;
}

//----------------------------------------------------------------------

//***********************************************************************
char* Steck::pop(char* a)
{Var x=a;
 (x=one[one.end-1])-1;
 return a;
};
char* Steck::push(char* a)
{Var x=a;
 (one+1)[one.end]=x;
 return  a;
};
