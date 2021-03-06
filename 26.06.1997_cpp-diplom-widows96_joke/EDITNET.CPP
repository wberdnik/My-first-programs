#include"editnet.hpp"
#include"button.hpp"
#include"tkeys.h"
#include"desktop.hpp"
#include"group.hpp"
#include"linebar.hpp"
#include"function.hpp"
#pragma hdrstop

extern int maxstation;
extern char* linebar;

extern "C" {
		int atoi(const char*);
		 unsigned long farcoreleft(void);
	   };



EditNet::EditNet():Modals(){
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


if(flagworking==cmLoad && !yesno(" �� ������ ��ᯮ�짮������ ����묨"
" ��o諮��\n              ᥠ�� ࠡ��� ?"));

 flagworking=cmNo;

  too=centr.station;   // �����㥬 ��������
  too.number=n=moi.number;

 SetBorder();
 setbase(border);
 setcls(new Worknet());
 insert(menu=new Group);
 int down=sizeY-sizeDy;

 menu->master(new MasterButton(cmNo,"����",kbAltM,"����"));// ������
 menu->insert(new LineBar(1,down-51,140,cmInfo, 1101,"�⮣",kbCtrlI));
 menu->insert(new LineBar(1,down-41,140,cmSaveas, 1101,"���࠭���",kbCtrlV));
menu->insert(perek[0]=new LineBar(1,down-31,140,cmB1,1,"�������",kbCtrlD));
menu->insert(perek[1]=new LineBar(1,down-21,140,cmB2,1,"�������� *",kbCtrlS));
 menu->insert(new LineBar(1,down-11,140,cmQuit, 1101,"��室",kbCtrlQ));
 menu->setbase(new Ramka(0,down-52,142,52));

 mode=Yes;
 insert(new DeskTop(cmPoint,*this));
}

int EditNet::sys(void){
static int last=n;
switch(Ev.press){
 case cmB1: case cmB2 : setperek(Ev.press); return 1;

 case cmSaveas : hSave();menu->status=stSelect;draft();return 1;

 case cmInfo :   LineYesNo("???");

 case cmFreeDraft:  menu->status=stSelect;draft();return 1;

case cmPoint :  if(tr3==-1){LinePrint("��窠 �� �������");return 1;}

	   if(last==n){LinePrint("��窠 ����祭�");last=tr3;return 1;}
	   if(last==tr3){LinePrint("��窠 �⬥����");last=n;return 1;}
	   flagworking=cmLoad;

		int p;
		if(last>tr3){p=last;last=tr3;tr3=p;}

		if(mode==Yes){// ������ �����
		p=(int)LineInput("������ ������⢮ ���");
		mai(sum_set,sizeof(int))[(v_size)last*moi.number+tr3]<<p;
		setcolor(BLUE);
		line(ci[last],di[last],ci[tr3],di[tr3]);
		Ev.setevent(cmEndWork);
		last=n;
		     return 1;
			  }
		 else {
		mai(sum_set,sizeof(int))[(v_size)last*moi.number+tr3]>>p;
		if(p>0){
		setcolor(BLACK);
		line(ci[last],di[last],ci[tr3],di[tr3]);
		putpixel(ci[last],di[last],YELLOW);
		putpixel(ci[tr3],di[tr3],YELLOW);
			}
		LinePrint(p>0?"���� �⬥����":"���� ����� �⠭�ﬨ"
		" ���������");
		 mai(sum_set,sizeof(int))[(v_size)last*moi.number+tr3]<<0;
		 Ev.setevent(cmEndWork);
		 last=n;
		 return 1;
		       }

	       }
return 0; }


// *****   ����� ��������� � �������� ***********************


void EditNet::hSave(void){
const long ddl= (long)moi.number*moi.number;

  File& a =*new File("netcad.sum");
   LinePrint("������ ��");
   a.tik(1);
   (a%1)+=sizeof(strCentre)+sizeof(strDlins);
   a+=(moi.number*4);a+=(moi.number*4);a+=(moi.number*4);
   a+=(moi.number*2);  a+=(centr.station.ncentre*2);

   int hlam;
   a%2;
   mai(sum_set,sizeof(int));
   for(long i=0;i<ddl;i++){
	mai[i]>>hlam;a+1;a[i]=(void*)&hlam;
	if(!(i%25 && i))a.tik(100*i/ddl);
			  }

   delete &a;
   SaveTxt();
}





EditNet::~EditNet(){
if(flagworking==cmLoad) hSave();
if(flagworking==cmNo||flagworking==cmLoad)
 {
  if(sum_set){ sum_set=mai.destroy(sum_set);}
  if(cent){ delete cent; cent=NULL;}
 }
		 }

void EditNet::draft(void){
Modals::draft();
int hlam,i,j;
LinePrint("� � � � � ");
setcolor(YELLOW);
for(i=0;i<moi.number-1;i++)
  for(j=i+1;j<moi.number;j++)
   {
    mai(sum_set,sizeof(int))[(v_size)i*moi.number+j]>>hlam;
    if(hlam>0) line(ci[i],di[i],ci[j],di[j]);
   }

  setcolor(LIGHTRED);  setfillstyle(CLOSE_DOT_FILL,LIGHTRED);
for(i=0;i<centr.station.ncentre;i++)
  fillellipse(ci[cent[i]],di[cent[i]],3,3);

			 }


void EditNet::LoadAdd(File& a) {

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

void EditNet::setperek(int a){
char i=0;

for(char j=0;j<2;j++){
if(!j)
switch(a){
   case cmB1 : linebar="�������  *"; i=0;mode=No;break;
   case cmB2 : linebar="�������� *"; i=1;mode=Yes;break;
	 }
else
switch(mode){
   case Yes : linebar="�������";i=0;break;
   case No  : linebar="��������";i=1;break;
	    }
Ev.flag=eSys;Ev.press=cmLineBar;
menu->movefirst(perek[i]);menu->handlevent();
		     }
menu->movefirst(perek[mode?1:0]);
Ev.flag=0;
}

void EditNet::SaveTxt(){
   LinePrint("������ ⥪�⮢��� 䠩��");
   unlink("netcad.txt");
   FILE* file =fopen("netcad.txt","wt");
   Wait wait('T');
   wait.tik(1);
   fprintf(file,"\n�६� ᮧ����� 䠩�� �⠭権:");
   fprintf(file,"��� - %d\t���� - %d\t����� - %d\n",\
   centr.station.gdate2.da_year,\
   centr.station.gdate2.da_day,centr.station.gdate2.da_mon);

   wait.tik(1);
   fprintf(file,"�� - %d\t���.- %d\tᥪ. - %d\n",\
   centr.station.gtime2.ti_hour,\
   centr.station.gtime2.ti_min,centr.station.gtime2.ti_sec);

   gettime(&(tnaw));
   getdate(&(dnaw));


   wait.tik(1);
   fprintf(file,"%s\n","\n�६� ।���஢���� 䠩�� �裡:");
   fprintf(file,"��� - %d\t���� - %d\t����� - %d\n",dnaw.da_year,\
   dnaw.da_day,dnaw.da_mon);

   wait.tik(1);
   fprintf(file,"�� - %d\t���.- %d\tᥪ. - %d\n",tnaw.ti_hour,\
   tnaw.ti_min,tnaw.ti_sec);


   wait.tik(1);
   fprintf(file,"%s\n","\n\t\t���न���� 㧫��");
   fprintf(file,"%s\n","\n����\t\tX\t\tY\n");

   for(int i=0;i<moi.number;i++)
    {
      fprintf(file,"%d\t%d(%f)\t%d(%f)\n",i+1,ci[i],c[i],di[i],d[i]);
      if(!(i%25))wait.tik(29*i/moi.number);
    }


   wait.tik(30);
   fprintf(file,"%s\n","\n����� 業�஢ ������樨");
   fprintf(file,"%s\n","\n�����\t\t�����\n");

   for(i=0;i<centr.station.ncentre;i++)
      fprintf(file,"%d\t\t%d\n",i+1,cent[i]+1);


   wait.tik(30);
   fprintf(file,"\n%s\n","[����� � �吝���]");
   fprintf(file,"%s\n","\n����1\t����2\t\t�����   ���-��\n");
   int hlam,hlam2,k=0;
   for(i=0;i<moi.number-1;i++)
     for(int j=i+1;j<moi.number;j++)
       {
	mai(sum_set,sizeof(int))[(v_size)i*moi.number+j]>>hlam;
	mai(sum_set,sizeof(int))[(v_size)j*moi.number+i]>>hlam2;
	if(hlam!=0)
	  fprintf(file,"%d\t%d\t\t%d\t%d\n",i+1,j+1,hlam2,hlam);
	if(k==30)
	 {
	  wait.tik(40*((v_size)i*moi.number+j)/((v_size)moi.number*moi.number)+29);
	  k=0;
	 }
	else
	 k++;
       }

   wait.tik(69);
   fprintf(file,"\n%s\n","[����� � 誠��]");
   fprintf(file,"%s\n","\n����   ��஡��\n");

   for(i=0;i<moi.number;i++)
    {
     fprintf(file,"%d\t%d\n",i+1,em[i]);
     if(!(i%25))wait.tik(30*i/moi.number+69);
    }

   fclose(file);
  }
