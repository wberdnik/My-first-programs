#include"bitmap.hpp"

Bitmap::Bitmap(Virtual& a,long b):mai(a){
size=b;
one=mai.myalloc(b/16+1,2);
number=0;
}


Bitmap::~Bitmap(){
one=mai.destroy(one);
	 }
Bitmap& Bitmap::operator[](unsigned long a){
if(a>=size)error("‘¡®© ¢ Bitmap");
number=a;return *this;};

void Bitmap::operator=(int a){
unsigned long nbyte=number/16;
int tmp; mai(one,2)[nbyte]>>tmp;
char sdwig=15-number%16;
tmp=tmp>>sdwig;
if(a)tmp|=1;else tmp&=0xfffe;
tmp=tmp<<sdwig;
mai[nbyte]<<tmp;
}

Bitmap::operator int (){
int tmp;mai(one,2)[number/16]>>tmp;
tmp=tmp>>(15-number%16);
return tmp&1?1:0;
}

void Bitmap::operator<<(Bitmap& a){
unsigned long cic;
cic=size<a.size?size:a.size;
int tmp;
for(long i=0;i<cic/16+1;i++){
mai(a.one,2)[i]>>tmp;
mai(one,2)[i]<<tmp;         }
}
void Bitmap::operator<<(int a){
a=a?0xffff:0;mai(one,2);
for(long i=0;i<size/16+1;i++)mai[i]<<a;
			      }

Masint::Masint(Virtual& a,long b):mai(a){
size=b;
one=mai.myalloc(b,2);
number=0;
}


Masint::~Masint(){
one=mai.destroy(one);
	 }
Masint& Masint::operator[](unsigned long a){
if(a>=size)error("‘¡®© ¢ Masint");
number=a;return *this;};

void Masint::operator=(int a){
mai(one,sizeof(int))[number]<<a;
}

void Masint::operator+=(int a){
int x;
mai(one,sizeof(int))[number]>>x;
mai[number]<<(x+a);
}

Masint::operator int (){
int tmp;
mai(one,2)[number]>>tmp;
return tmp;
}

void Masint::operator<<(int a){
mai(one,2);
for(long i=0;i<size;i++)mai[i]<<a;
			     }
void Masint::operator<<(Masint& a){
int tmp;mai(one,2);
for(long i=0;i<size;i++){
mai(a.one,2)[i]>>tmp;
mai(one,2)[i]<<tmp;
			 }        }
