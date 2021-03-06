#include"applic.hpp"
#include"tkeys.h"
#include"button.hpp"
#include"linebar.hpp"
#include"box.hpp"
#include"buildm.hpp"
#include"fStation.hpp"
#include"hstation.hpp"
#include"ezik.hpp"
#include"addnet.hpp"
#include"fCentre.hpp"
#include"border.hpp"
#include"function.hpp"
#include"options.hpp"
#include"diagnost.hpp"
#include"editnet.hpp"
#include"basedata.hpp"
#include"help.hpp"
#include"iis.hpp"
#include"concent.hpp"
#include"signal.hpp"
#pragma hdrstop


extern "C" int system(const char *);
Applic::~Applic(){};

Applic::Applic():Group(){
Group* submenu;
Leaf *f1;

setcls(new Desktop);
//setcls(new Circle(0,50,sizeX,sizeY-sizeDy-100));
master(new MasterButton(cmNowork,"����",kbF10,"����"));

insert(submenu=new Group);
Leaf* frt=submenu;
 submenu->setbase(new Ramka(23,39,112,42));
 submenu->master(new Button(18,3,64,20,cmNo,1005,"�������� ��⥬�",\
							kbAltF,"����"));
 submenu->insert(f1=new LineBar(24,40,110,cmLoad,1101,"���",      kbCtrlN));
 submenu->insert(new LineBar(24,50,110,cmGetInfo,   1104,"�������", kbCtrlG));
 submenu->insert(new LineBar(24,60,110,cmDOSshell,1104,"�����",    kbCtrlD));
 submenu->insert(new LineBar(24,70,110,cmQuit,    1105,"��室",    kbCtrlE));
 submenu->setfirst(f1);


insert(submenu=new Group);
	submenu->setbase(new Ramka(113,39,142,132));
 submenu->master(new Button(108,3,64,20,cmNo,1006,"�����㬥�⠫�� �����.",\
							     kbAltT,"����"));
 submenu->insert(f1=new LineBar(114,40,140,cmBorder,1101,"�࠭���", kbCtrlB));
 submenu->insert(new LineBar(114,50,140,cmStationa, 1101,"�⠭樨", kbCtrlS));
 submenu->insert(new LineBar(114,60,140,cmStationb, 1101,"�ࠢ�� �⠭権",\
								    kbCtrlH));
 submenu->insert(new LineBar(114,70,140,cmCentre ,  1101,"������",  kbCtrlT));
 submenu->insert(new LineBar(114,80,140,cmBuildm,11,"����� ����",kbCtrlB));
 submenu->insert(new LineBar(114,90,140,cmEji, 1101,"����஢��",  kbCtrlY));
 submenu->insert(new LineBar(114,100,140,cmSum, 1101,"�������� ��", kbCtrlN));
 submenu->insert(new LineBar(114,110,140,cmEditNet,1,"�ࠢ�� ��", kbCtrlE));
 submenu->insert(new LineBar(114,120,140,cmSub,  1101,"��⮤ 㤠�����",\
								 kbCtrlD));
 submenu->insert(new LineBar(114,130,140,cmAdd,  1101,"��⮤ ����������",\
								 kbCtrlA));

 submenu->insert(new LineBar(114,140,140,cmIis,  1101,"���",\
								 kbCtrlI));
 submenu->insert(new LineBar(114,150,140,cmSignal,  1101,"C������ �� ���",\
								 kbCtrlC));
 submenu->insert(new LineBar(114,160,140,cmRezult,  1101,"�������� ��",\
								 kbCtrlC));
	submenu->setfirst(f1);


insert(submenu=new Group);
	submenu->setbase(new Ramka(203,39,142,22));
 submenu->master(new Button(198,3,64,20,cmShowsubmenu,1007,"���� ������.",\
								    kbAltB,\
							    "� �"));
 submenu->insert(f1=new LineBar(204,40,140,cmBaseCabel,1,"������", kbCtrlC));
 submenu->insert(new LineBar(204,50,140,cmBaseConc,1,"���業����",kbCtrlA));
	submenu->setfirst(f1);

insert(submenu=new Group);
	submenu->setbase(new Ramka(293,39,152,32));
 submenu->master(new Button(288,3,64,20,cmShowsubmenu,1008,"����ன�� �ணࠬ"
							     "��.", kbAltO,\
							  "����ன"));
 submenu->insert(f1=new LineBar(294,40,150,cmStepweb,1101,"����⠡��� ���",\
								  kbCtrlM));
 submenu->insert(new LineBar(294,50,150,cmModeCoor,1101,"��ࠬ���� ����",\
								kbCtrlR));
 submenu->insert(new LineBar(294,60,150,cmSound,1101,KNOW.sound?"���":"�"
							 "�設�", kbCtrlS));
	submenu->setfirst(f1);

	insert(submenu=new Group);
	submenu->setbase(new Ramka(384,39,112,22));
 submenu->master(new Button(378,3,64,20,cmShowsubmenu,1009,"��ࠢ�筠� ����"
							   "�⥬�.",kbAltH,\
							   "��ࠢ��"));
 submenu->insert(f1=new LineBar(384,40,110,cmAbout,11,"� ��⥬�", kbCtrlH));
 submenu->insert(new LineBar(384,50,110,cmHelp,1101,"� ����",     kbCtrlI));
// submenu->insert(new LineBar(384,60,110,cmHelp1,1101,"�ॡ������", kbCtrlC));
	submenu->setfirst(f1);


insert(submenu=new Group);
	submenu->setbase(new Ramka(473,39,112,62));
 submenu->master(new Button(468,3,64,20,cmShowsubmenu,1010,"��, �� ������"
						" �뢠�� �������.",kbAltE,\
							   "��祥"));
submenu->insert(f1=new LineBar(474,40,110,cmDraft,1105,"����ன",  kbCtrlR));
submenu->insert(new LineBar(474,50,110,cmCopyright,1105,"���㭮�", kbCtrlC));
submenu->insert(new LineBar(474,60,110,cmError,   1105,"Error",    kbCtrlE));
submenu->insert(new LineBar(474,70,110,cmSaveSlaid,1105,"�����",   kbCtrlT));
submenu->insert(new LineBar(474,80,110,cmLoadSlaid,1105,"��⠩",   kbCtrlT));
submenu->insert(new LineBar(474,90,110,cmStopSlaid,1105,"�⮯",   kbCtrlT));

	submenu->setfirst(f1);

insert(new Button(558,3,64,20,cmQuit,1011,"��室 � DOS.",kbAltX,"��室"));
setfirst(frt);
status=stFocus;
Ev.setevent(cmAbout);
}
extern char* linebar;

int Applic::sys(void){
Proto * af;
switch(Ev.press){
	case cmSound    : if(KNOW.sound){KNOW.sound=No;linebar="��設�";}
			  else {KNOW.sound=Yes; linebar="���";}
			  Ev.setevent(cmLineBar);
				return 1;

	case cmSaveSlaid :  Ev.setsave();return 1;
	case cmLoadSlaid :  Ev.setload();return 1;
	case cmStopSlaid :  Ev.setuser();return 1;
	case cmNowork   :
	case cmError    :
	case cmAbout   :
				switch(Ev.press){

				 case cmNowork  : Zap();break;
				 case cmAbout   : About();break;
				 case cmError   : error(ERROR,"     �ਬ��",\
				 "ᮮ�饭�� �� �訡��"); break;
						    }
				LineYesNo("");
				status=stFocus;
				Ev.setevent(cmDraft);
				return 1;

	case cmGetInfo :

				status=stSelect;draft();
				GetInfo();
				status=stFocus;
				Ev.setevent(cmDraft);
				return 1;



	case cmDOSshell :
	case cmCopyright:
	case cmGreen    :
			   KNOW.close();
				switch(Ev.press){
				case cmGreen    :
				case cmCopyright: Copyright();break;
				case cmDOSshell : printf("\n Type EXIT to "
					"return to NETCAD ...");
					system("command.com"); break;
						  }
			     KNOW.open();
				draft();
				return 1;


	case cmLoad     :
	case cmCentre   :
	case cmStationa :
	case cmStationb :
	case cmStepweb	:
	case cmBuildm   :
	case cmEditNet  :
	case cmModeCoor :
	case cmEji      :
	case cmIis      :
	case cmSum      :
	case cmBaseCabel:
	case cmBaseConc :
	case cmHelp     :
	case cmRezult   :
	case cmSignal   :
	case cmAdd      :
	case cmSub      :
	case cmBorder   : status=stSelect;draft();
			  af=NULL;
			  switch(Ev.press){
			   case cmLoad     : af=new Box(Ev.press,"*.*");
						 break;
			   case cmCentre   : af=new fCentre();break;
			   case cmStationa : af=new fStation();break;
			   case cmStationb : af=new hStation();break;
			   case cmBuildm   : af=new Buildm();break;
			   case cmBorder   : af=new Border();break;
			   case cmEditNet  : af=new EditNet();break;
			   case cmStepweb  : af=new Stepweb();break;
			   case cmEji      : af=new Ezik();break;
			   case cmIis      : af=new Iistol();break;
			   case cmSum      : af=new Addnet();break;
			   case cmSignal   : af=new Signal();break;
			   case cmBaseConc : af=new Concent();break;
			   case	cmBaseCabel: af=new Cabel();break;
			   case cmModeCoor : af=new Real();break;
			   case cmAdd      : af=new cAdd();break;
			   case cmSub      : af=new cSub();break;
			   case cmHelp     : af=new Help("netcad.hlp");break;
			   case cmRezult   : af=new Help("result.txt");break;
			   default	   : error("���� � Aplic::case");
					     }
			   delete(af->go());
			   status=stFocus;
			   draft();
			   return 1;


   default     :		return 0;
				}
			   }


void Applic::preprocess(void){
if(Ev.press==kbQuit && Ev.flag==eKeyboard){
Ev.setevent(cmQuit);Ev.clear();
					}
			       }

main(){
KNOW.test();
Applic *my=new Applic;
my->go();
delete my;
return 0;
}