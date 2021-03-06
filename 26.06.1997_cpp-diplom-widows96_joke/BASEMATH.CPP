#include <math.h>
#include <graphics.h>
#define  GRAPHICSH
#define  MATHH

#include "basemath.hpp"
#include"simple.hpp"
#include"diagnost.hpp"
#include"function.hpp"
#pragma hdrstop

extern"C" {
	  void sound(unsigned);
	  void nosound(void);
	  void delay(unsigned);
	  unsigned long farcoreleft(void);
	  }


///___________________________________________________________________
		//  �뢮� �� ��ᯫ�� ������ �����⮢
void BaseMath::pixcel(void)  {
for(int i=0;i<n;i++)if(ci[i]!=-1)putpixel(ci[i],di[i],YELLOW);
}

void BaseMath::sort(void){
int i,j,k,l=0;
int ze;
Wait wait('T');
if(n<100){
 for(i=0;i<n-1;i++)
  for(j=i;j<n;j++)
   if(c[i]>c[j])move(i,j);
   return;
	 }

int dta=n%50?n/50+1:n/50;        // ࠧ��� ������
int* nmas=new int[50];  // �ᥣ�� 50 �����஢  + ����� �� �訡��
			// � �  � 50 ࠧ ����॥
//float * view=c;

for(i=0;i<50 && i*dta<n;i++){   // �����⮢�� ������ ����஢
   k=i*dta;
   for(j=k+1;j<((i+1)*dta)&&j<n;j++) if(c[k]>c[j])k=j;
   nmas[i]=k; }

int maxn=(n%dta)?n/dta+1:n/dta;

wait.tik(1);
int tim=100;

for(i=0;i<n;i++){                                                       //�
tim--;if(!tim){tim=100;wait.tik(((float(i)*100)/n));} // ����� 100 �祪 �⬥砥� �
	      //
  k=nmas[i/dta];     // ���� ��稭�� � ⥪�饣� ᥣ����                 �
  for(j=i/dta;j<maxn;j++)if(c[k]>c[ nmas[j] ])k=nmas[j];     //           �
					 // ������ ������
//  if(k<i || k>=n)
//	       error(FATALERROR,""," ������ �� ������");
		    // k - ����� �������쭮�� �������                    �
  if(c[k]!=c[i])move(k,i);                          //                          �
//    if(i!=0 && c[i]<c[i-1])
//	error(FATALERROR,"","���� ���஢��");

		    // �᫨ k ��室���� � ⮬ �� ᥣ����, �� � i
   l=((k/dta)==(i/dta))?i+1:dta*(k/dta);  // � ��稭�� � �᫠ ��᫥ i   �
					  // ���� � ��砫� ᥣ����
   k=l;                                   //                              �
   ze=(l/dta+1)*dta;         ze=ze>n?n:ze; // �᫮��� ����砭�� 横��     �
     for(j=l;j<ze;j++) if(c[k]>c[j])k=j; // �饬 ������ ᥣ����         �
   nmas[l/dta]=k;                      // ���⠭�������� �����            �

  if(nmas[i/dta]<=i){                  // ���⠭�������� ᥪ�� � ���஬ i
    ze=(i/dta+1)*dta;ze=ze>n?n:ze;  k=i+1;                              //�
    for(j=i+1;j<ze;j++)if(c[k]>c[j])k=j;                               // �
     nmas[i/dta]=k;  }                                                  //�
		  }   // 横� ���஢�� �����祭                         �
 wait.tik(99);
delete nmas;
if(KNOW.sound){sound(2000);delay(50);nosound();}
   for(i=1;i<n;i++)if(c[i]<c[i-1])   // �஢��塞 �த������� ࠡ���
   error("���� ���஢��");
flagworking=cmSort;
				}

void BaseMath::move(int i,int j){
float a;        int b;
    a= c[i];  c[i]= c[j]; c[j]=a;     a= d[i];  d[i]= d[j]; d[j]=a;
    b=ci[i]; ci[i]=ci[j];ci[j]=b;     b=di[i]; di[i]=di[j];di[j]=b;
		    b=em[i]; em[i]=em[j];em[j]=b;
if(too.ncentre && too.ncentre<6)
for(b=0;b<too.ncentre;b++){
  if(too.centre[b]==i)too.centre[b]=j;
  else
    if(too.centre[b]==j)too.centre[b]=i;
			      }
		      }

void BaseMath::SetBorder(void){
  switch(too.type){
      case  tRound :    border=new Circle(0,0,sizeX,sizeY-sizeDy); break;
      case  tRectangle: border=new Rectangle(0,0,sizeX,sizeY-sizeDy);break;
      case  tMore :
      case  tFree : error("��⠭���� �� ������-\n �饣� ⨯� �࠭��.");
		   }
				 }

void BaseMath::LoadHeadStn(File& a){
 ( a%sizeof(strStation) )[0]>>(void*)&too;
( a%1)+=sizeof(strStation);
				   }


int BaseMath::LoadStn(File& a){
if(flagworking!=cmLoad)return No;
LinePrint("����㧪� ��室��� ������");
				 // �஢��塞 ���������
if(too.number<=0 || too.number>(a.end-sizeof(strStation)/14)){
   Message("����� � 䠩�� �⠭権 �訡��� ! ");return No;          }

if(too.number>maxstation){
Message("���������� ��ᯮ�짮������ ����묨 \n �� �� ������⪠ �����");
       return No;                     }

if(flagworking==cmLoad){
unsigned block=too.number*2;
 a%block;
 a[0]>>(void*)ci;	  	a.tik(14);	a.tik(14);
 a[1]>>(void*)di;	  	a.tik(29);	a.tik(29);
 a[2]>>(void*)em;	  	a.tik(43);	a.tik(43);
 a[3]>>(void*)c;                a.tik(57);	a.tik(57);
 a[4]>>(void*)((char*)c+block); a.tik(71);	a.tik(71);
 a[5]>>(void*)d;                a.tik(85);	a.tik(86);
 a[6]>>(void*)((char*)d+block); a.tik(99);	a.tik(99);
 (a%1)+=block;	a+=block;	a+=block;	a+=block;
 a+=block;	a+=block;	a+=block;

unsigned i;
if(too.mashtx<=0 || too.mashty<=0){Message("�訡�祭 ����⠡");return No;}

for(i=0;i<too.number;i++)
 if(abs(ci[i]-int(c[i]*sizeX/too.mashtx))>2 ||\
    ci[i]<0 || ci[i]>sizeX || di[i]<0 || di[i]>(sizeY -sizeDy)||\
    em[i]<0 || em[i]>too.doplam||\
    abs(di[i]-int(d[i]*(sizeY-sizeDy)/too.mashty))>2){
     Message("���祭�� k��न��� �訡���");
     return No;                         }
		   }
return Yes;
}



void BaseMath::SaveStn(File& a){
too.number=n;
unsigned block=sizeof(strStation);;

 a%block+1;
 a[0]=(void*)&too;
 a%1+=block;

 block=n*2;
 a%block+7;
 a[0]=(void*)ci;		a.tik(14);	a.tik(14);
 a[1]=(void*)di;		a.tik(29);	a.tik(29);
 a[2]=(void*)em;		a.tik(43);	a.tik(43);
 a[3]=(void*)c;			a.tik(57);	a.tik(57);
 a[4]=(void*)((char*)c+block);	a.tik(71);	a.tik(71);
 a[5]=(void*)d;			a.tik(85);	a.tik(86);
 a[6]=(void*)((char*)d+block);	a.tik(99);	a.tik(99);

 (a%1)+=block;	a+=block;	a+=block;	a+=block;
 a+=block;	a+=block;	a+=block;
			}

BaseMath::~BaseMath(){
if(c)delete c;   	if(d)delete d;
if(ci) delete ci;       if(di) delete di;
	if(em) delete em;};

extern int maxstation;

int BaseMath::LoadAllStn(int b){
char * textmessage=" ��� ����室���� ������ ��� ����㧪�";
maxstation=(int)((farcoreleft()-5000L)/14 );
File* file=new File("netcad.stn");
if(file->end<sizeof(strStation))goto metkaerror;
LoadHeadStn(*file);
if(too.number>=17000L )goto metkaerror;
if((too.number+b)>=maxstation){
textmessage="�� �����筮 ᢮������ �����\n ��� ����㧪� ��室��� ������";
goto metkaerror;              }

ci=new int[too.number+b];   di=new int[too.number+b];
em=new int[too.number+b];
d= new float[too.number+b]; c= new float[too.number+b];
flagworking=cmLoad;
if(!LoadStn(*file)) goto metkaerror;
delete file;
return No;

metkaerror:
 // ��ࠡ��稪 �訡��
flagworking=cmBreak;
Message(textmessage);
delete file;
return Yes;
		       }
BaseMath::BaseMath(){c=d=NULL;ci=di=em=NULL;};