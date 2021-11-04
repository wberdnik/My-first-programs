#include<conio.h>
#define CONIOH
#include"sourse.hpp"
#include"simple.hpp"
#pragma hdrstop

extern "C"{
void * calloc(unsigned,unsigned);
void free(void*);
int strlen(char far*);
char *strcpy(char *, const char *);
	  };

File& File::operator-=(ulong a){
 start-=a*len;end+=a;that+=a;realend+=a*len;
 set(that);
 return *this;}

File& File::operator+=(ulong a){
  start+=a*len;end-=a;realend-=a*len;
  that-=a;
  if(that<0)    {that=0;set(0);}
  return *this;}

File& File::operator%(unsigned a){
  end=realend;that*=len;
  len=a;
  end/=len;that/=len;
  set(that);          //that drobnoe
  return *this;};

void File::read(void* a){
 while(fread(a,len,1,one)!=1)
    if(!error(ERRORFILE,"Не могу считать из файла",name))break;
  that+=1;};

void File::sbrosstart(void){
operator%(1);
if(start)operator-=(start);}


void File::add(ulong n){
  set(end);
  char *c=(char*)calloc(len,1);
  while(fwrite(c,len,size_t(n),one)!=n)
    if(!error(ERRORFILE,"Не могу добавить в файл",name))break;
  realend+=len*n;
  if(c!=NULL) free(c);
 };


void File::del(ulong n){
   while(chsize(fileno(one),(end-n)*len+start)!=0)
    if(!error(ERROR,"Сбой ОС","Не могу уменьшить длину файла"))break;
	 realend-=len*n;};

int File::toend(unsigned long b,void* a){
end++;that=b;
fseek(one,start+b*len,SEEK_SET);
return fwrite(a,len,1,one);}

void File::write(void * c)
 { while(fwrite(c,len,1,one)!=1)
    if(!error(ERRORFILE,"Не могу писать в файл",name))break;
  that++;
  };
void File::set(ulong a)
{fseek(one,start+(unsigned long)a*len,SEEK_SET);};

File :: File(char * ima):Wait('F'){
	len=1;
	start=0;
	that=0;
	int a=strlen(ima)+1;
	name=new char[a];
	strcpy(name,ima);
	if(name==NULL)error("Ошибка File::File имя");

	if((one=fopen(name,"rb+"))!=NULL)
	   { rewind(one);
	     end=filelength(fileno(one));
	     result=end!=0?1:0;
	    }
	else
	    {while((one=fopen(name,"wb+"))==NULL)
	       if(!error(ERRORFILE,"Не могу создать файл",name)){result=-1;
								 break;}
	     result=0; end=0;
	     }
	realend=end;
 }
 File::~File(void){
 if(name==NULL)error(" Повторный вызов \n деструктора");
  while(fclose(one)!=0)
    if(!error(MESSAGE,"Не могу закрыть файл",name))break;
    delete name;
    name=NULL;
 };


