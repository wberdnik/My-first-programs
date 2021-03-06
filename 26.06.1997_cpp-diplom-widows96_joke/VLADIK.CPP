#include"vladik.hpp"
#include"button.hpp"
#include"tkeys.h"
#include"desktop.hpp"
#include"group.hpp"
#include"linebar.hpp"
#include"function.hpp"
#pragma hdrstop

enum{
	stNo,
	stSimple,
	stCentre,
	stConcentr,
	stQwery,
	};

extern int maxstation;
extern char* linebar;

extern "C" {
		int atoi(const char*);
		 unsigned long farcoreleft(void);
	   };



cAdd::cAdd():BaseNet(){
 flagworking=cmBreak;
 maxstation=(int)((farcoreleft()-10000L)/14 )-1;
 if(maxstation>65535L/4)maxstation=int (65535L/4);

  File* file =new File("netcad.sum");

 if(file->end>sizeof(strCentre)+sizeof(strDlins)) LoadAdd(*file);
 else
  {
   Message("��� ���ଠ樨 � �㬬�୮� ��");
   delete file;
   return;
  }
 delete file;
 flagworking=cmLoad;
 cost=mai.myalloc((v_size)moi.number*moi.number,sizeof(long));
 station=mai.myalloc((v_size)moi.number,sizeof(int));


  too=centr.station;   // �����㥬 ��������
  too.number=n=moi.number;
  if(too.ncentre!=1){
       Message("��� ������� �㭪� ������ ���� 㪠��� \n"
	       "⮫쪮 ���� 業�� ������樨");
	       return;

		    }
  Message("����஥��� ⮯������᪮� �� � ��⨢�묨 \n"
	  "���業���ࠬ� �� ������� \"����������\".");

 SetBorder();
 setbase(border);
 setcls(new Worknet());
 insert(new MasterButton(cmNo,"",0,""));
 insert(new DeskTop(cmPoint,*this));
 Ev.setevent(cmLoad);
}

int cAdd::sys(void){
long i,j,k;
int x;
char* a="caddini.rpt";
switch(Ev.press){
 case cmLoad :
     LinePrint("��।������ ᮮ⢥⢥��⢨� �痢� � ��");

    moi(station,sizeof(int));  //���樠������ ������ �⠭権
   for(i=0;i<moi.number;i++) moi[i]<<stNo;

   unlink(a);
   FILE* file =fopen(a,"wt");
   struct time tnam;
   struct date dnam;
   fprintf(file,"���� �ணࠬ�� � �롮� ����� �痢� ��"
   " ��⠭���� ���業���஢");
   for(int t=0;t<2;t++){
    if(!t){
    dnam=centr.station.gdate2;
    tnam=centr.station.gtime2;
   fprintf(file,"\n�६� ᮧ����� 䠩�� �⠭権:\n");
	   }
      else{
   getdate(&(dnaw)); gettime(&(tnaw));
   fprintf(file,"%s\n","\n�६� ।���஢���� 䠩�� �裡:");
	  }
   fprintf(file,"��� - %d\t���� - %d\t����� - %d\n",dnaw.da_year,\
   dnaw.da_day,dnaw.da_mon);
   fprintf(file,"�� - %d\t���.- %d\tᥪ. - %d\n",tnaw.ti_hour,\
   tnaw.ti_min,tnaw.ti_sec);
	    }
   fprintf(file,"\n��1\t\t��2\t\t��������\n");


 Dbf& base=*new Dbf(baseCabel,"netcab.dbf");
   if(base.end==0){
	   Message("���� ������ �� ����� �裡 �� �������");
	    delete &base;
	     fprintf(file,"�����襭� ��-�� ������⢨� ���� ������");
	    fclose(file);
	    Ev.setevent(cmQuit);
	    return 1;    }

 setcolor(WHITE);

Wait* myxa=new Wait('T');

double coast=0;

 for(i=0;i<moi.number-1;i++)
  for(j=i+1;j<moi.number;j++){
    myxa->tik(100*(float)i/moi.number);
    mai(sum_set,sizeof(int))[i*moi.number+j]>>hlam;// ��諨 ����� �裡
    if(hlam>0) line(ci[i],di[i],ci[j],di[j]); //�������� �� ࠡ�⠥� � ���

long min=0xffffffff;
long number=base.end;

    for(k=0;k<base.end;k++){             // ᪠���㥬 ���� ������
      base[k]>>(void*)&cabel;
      if(cabel.potok>=hlam && cabel.cena<min){ //���� ������ ��� 業�
       min=cabel.cena;
       number=k;                            }
			   }
 char *str=new char[50];
  sprintf(str,"������ � ���� ������ � ����⢥ ��᫥����\n"
	      "����� ����� �裡 ������� �ய�᪭�� ᯮ�"
	      "������ ����� %d ",hlam);

  if(number==base.end)                  // �᫨ ���e�� �� ������
   while(1){
   base[base.end-1]>>(void*)&cabel
   if(cabel.potok>=hlam){number=base.end-1;break;}
   if(!yesno(str)){
	     fprintf(file,"�����襭� �� ������� ���짮��⥫�");
		fclose(file);delete str; delete &base;delete myxa;
		    Ev.setevent(cmQuit);return 1;}
		      //��������
   Modals * BD=Cabel();
    delete(BD->go());
    draft();
		      }
   delete str;
					  // �᫨ ������ ������
     base[number]>>(void*)&cabel;            // ��⠭�������� ������
    mai(cost,sizeof(long))[i*moi.number+j]<<number; // 㪠�뢠�� ����� ������
    mai(sum_set,sizeof(int))[j*moi.number+i]>>hlam;// ���뢠�� ������ �裡
    min=hlam*cabel.cena;      			   //���� �⮨���� �裡
    coast+=(double)min;
    mai(cost,sizeof(long))[j*moi.number+i]<<min;   // �����뢠�� 業�
    fprintf(file,"\n%d\t\t%d\t\t%s\n",i,j,cabel.name);


			    }  //���� 横�
     fprintf(file,"�㬬�ୠ� �⮨����� %lf",coast);
     fclose(file);
  delete myxa;

 draft();


  LinePrint(" ���� ���� ��⠭���� ���業���஢");
  myxa=new Wait('F');
  mai(station,sizeof(char))[too.centre[0]]<<stCentre;

  for(i=0;i<moi.number;i++){ // ��� ��� �⠭権
  k=0;                       // ������� 0 �⠭権
  myxa->tik(100*(float)i/moi.number);
  moi(station,sizeof(char))[i]>>x;
  if(x!=stNo)continue;          // �᫨ ������ �⠭�� �� �஢��﫠��

    for(j=0;j<moi.number;j++){ // �஢��塞 �� �裡
    mai(sum.set,sizeof(int));
    if(j>i)mai[i*moi.number+j]>>hlam;
    else  mai[j*moi.number+i]>>hlam;
    if(hlam==0)continue;      // ec�� �裡 ��� � � ᫥���饩 �窥
     k++;		     }

   if(k<3){                  // ��� ࠧ����� - ��� ���業����
     mai(station,sizeof(char))[i]<<stSimple;
     continue;}
     //����⠥��� ��⠭����� ���業����
     x=k;
     mai(station,sizeof(int))[i]<<x+stQwery;
     outtextxy(ci[i],di[i],"?");
			   }
  delete myxa;

  LinePrint("A����� ��⠭���� ���業���஢ ");
  myxa=new Wait('F');
  for(i=0;i<moi.number;i++){
    j=too.centre[0];            // ��⠭�������� �� 業��
    mai(sum.set,sizeof(int));
    if(j>i)mai[i*moi.number+j]>>hlam;
    else  mai[j*moi.number+i]>>hlam;
    if(hlam){                   // ec�� ���� ���
     mai(station,sizeof(int))[i]>>x;
      if(x>stQwery){          //�஡㥬 ��⠭�����
    mai(coast,sizeof(long));
    if(j<i)mai[i*moi.number+j];  //業�
    else  mai[j*moi.number+i];
    long mycoast;
    mai>>mycoast;
    Dbf& dbs=*new Dbf(baseConcent,"netcon.dbf");
    number=dbs.end;
    min=0xffffffff;
    for(k=0;k<dbs.end;k++){
      dbs[0]>>(void*)&concen;
      if(concen.input>=x && concen.cena<=min)






 delete myxa;
 delete &base;


}
return 0; }


// *****   ����� ��������� � �������� ***********************


void BaseNet::hSave(void){
LinePrint("������ १���⮢");
char * name="netcad.sub"
unlink(name);
  File& a =*new File(name);

   a.tik(0);
   a%(sizeof(strCentre));
   a.toend(0,(void*)&centr);
   a%1+=sizeof(strCentre);     // ���ଠ�� � 業���


   a%(sizeof(strDlins));       // �����䨪��� ����� ����
   a.toend(0,(void*)&moi);
   a%1+=(sizeof(strDlins));

   a%(moi.number*4);
   a.toend(0,(void*)c);     a.toend(1,(void*)d);
   (a%1)+=(moi.number*4);         a+=(moi.number*4);

   a%(moi.number*2);
   a.toend(0,(void*)ci); a.tik(1);   a.toend(1,(void*)di);  a.tik(1);
   a.toend(2,(void*)em);  a.tik(1);
   (a%1)+=(moi.number*2);  a+=(moi.number*2);  a+=(moi.number*2);

   cent=new int[centr.station.ncentre];
   a%(centr.station.ncentre*2);
   a.toend(0,(void*)cent); a.tik(2);
   (a%1)+=(centr.station.ncentre*2);

   const unsigned long max=moi.number*moi.number;
   int hlam;long k=0;
   a%2;mai(sum_set,sizeof(int));
   for(int i=0;i<moi.number;i++)
     for(int j=0;j<moi.number;j++){
	moi[(v_size)i*moi.number+j]>>hlam;
	a.toend(0,(void*)&hlam);a+=1;
	if(!(k%25))a.tik(100*(k/max);
	 k++;
       }

   delete &a;

}





cAdd::~cAdd(){
if(flagworking==cmLoad) hSave();
if(flagworking==cmNo||flagworking==cmLoad)
 {
  if(sum_set){ sum_set=mai.destroy(sum_set);}
  if(cost){cost=mai.destroy(cost);}
  if(cent){ delete cent; cent=NULL;}
 }
		 }

void Vladik::draft(void){
Modals::draft();
int hlam,i,j;
LinePrint("� � � � � ");
setcolor(YELLOW);
mai(sum_set,sizeof(int));
for(i=0;i<moi.number-1;i++)
  for(j=i+1;j<moi.number;j++){
    mai[(v_size)i*moi.number+j]>>hlam;
    if(hlam>0) line(ci[i],di[i],ci[j],di[j]);
   }
			 }


void Vladik::LoadAdd(File& a) {

LinePrint("����㧪� ��室��� ������");

   a%(sizeof(strCentre));
   a[0]>>(void*)&centr;
   a%1+=sizeof(strCentre);     // ���ଠ�� � 業���


   a%(sizeof(strDlins));       // �����䨪��� ����� ����
   a[0]>>(void*)&moi;
   a%1+=(sizeof(strDlins));

   c=new float[moi.number];
   d=new float[moi.number];
   ci=new int[moi.number];
   di=new int[moi.number];
   em=new int[moi.number];

   a%(moi.number*4);
   a[0]>>(void*)c;  a.tik(1);    a[1]>>(void*)d;  a.tik(1);
   (a%1)+=(moi.number*4);         a+=(moi.number*4);

   a%(moi.number*2);
   a[0]>>(void*)ci; a.tik(1);   a[1]>>(void*)di;  a.tik(1);
   a[2]>>(void*)em;  a.tik(1);
   (a%1)+=(moi.number*2);        a+=(moi.number*2);
   a+=(moi.number*2);

   cent=new int[centr.station.ncentre];
   a%(centr.station.ncentre*2);
   a[0]>>(void*)cent; a.tik(1);
   (a%1)+=(centr.station.ncentre*2);



    // ����⨥ ����㠫쭮�� ����

   sum_set=mai.myalloc((v_size)moi.number*moi.number,sizeof(int));

   int hlam;
   a%2;  mai(sum_set,sizeof(int));
   unsigned long i;

   for(i=0;i<(unsigned long)moi.number*moi.number;i++){
    a[i]>>(void*)&hlam; mai[i]<<hlam;
    if(!(i%100))a.tik(99*i/((v_size)moi.number*moi.number));}

   for(i=0;i<moi.number;i++) a+=moi.number;   // ���४�஢�� ���������
   a.tik(100);

  }





