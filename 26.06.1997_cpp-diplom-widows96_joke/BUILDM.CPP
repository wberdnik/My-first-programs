#include"buildm.hpp"
#include"tkeys.h"
#include"button.hpp"
#include"function.hpp"
#include"diagnost.hpp"

extern "C"{
	 double hypot(double x, double y);
	 unsigned long farcoreleft(void);
	 int memcmp(const void *s1, const void *s2, size_t n);
	   };

Buildm::Buildm():Modals(){
maxstation=(int)((farcoreleft()-10000L)/14);
if(maxstation>65535L/4)maxstation=int (65535L/4);

if(LoadAllStn(0))return;
flagworking=cmNo;
char * text;
File* file =new File("netcad.lht");
if(file->end>=sizeof(strDlins)){
(*file)%sizeof(strDlins);
(*file)[0]>>(void*)&moi;
if(moi.number==too.number && !memcmp(&too.gdate,&moi.gdate,\
  sizeof(struct date))  && ! memcmp(&too.gtime,&moi.gtime,\
  sizeof(struct time)) && moi.modemath==KNOW.modemath){
	 text="Матрица длин для данных станций\n уже существует";
	 flagworking=cmBreak;
		       }
				}
delete file;
if(flagworking==cmNo && too.number<5){
		     text="    Количество станций меньше чем пять.\n"
			  "    Дальнейшая работа не возможна ! ";
		  flagworking=cmBreak;
		};

if(flagworking==cmNo && too.ncentre<=0){
		     text="    Не указано ни одного центра \n";
		  flagworking=cmBreak;
		}

if(flagworking==cmNo && too.ncentre>5){
		     text="    Колличество центров указано неправильно \n";
					  flagworking=cmBreak;
		}
if(flagworking==cmBreak){Message(text);return;};

if(!yesno("  Расчет матрицы длин может длится достаточно\n"
	  " долго ! Вы желаете расчитать матрицу длин ?"))return;

flagworking=cmLoad;

setcls(new Desktop);
status=stFocus;
setbase(new MasterButton(cmNowork,"",kbF10,""));
draft();

LinePrint("Расчет матрицы длин.");

unlink("netcad.lht");
file=new File("netcad.lht");
(*file)%(sizeof(strDlins));
(*file)+1;

moi.gtime=too.gtime;
moi.gdate=too.gdate;
moi.number=too.number;
KNOW.modemath=rasMathPixel;
moi.modemath=KNOW.modemath;

(*file)[0]=(void*)&moi;
(*file)%1+=(sizeof(strDlins));

//if(KNOW.modemath==rasMathPixel)
	matrixlength1(*file);
/*else{
   KNOW.modemath=rasMathReal;
	matrixlength2(*file);
    }*/

delete file;
				   }


void Buildm::matrixlength1(File& a){
int x;a%2;
for(int i=0;i<too.number;i++){
     a.tik(((float(i)*100)/too.number));
     for(int j=0;j<too.number;j++){
x=i==j?0:(int)hypot((c[i]-c[j])*sizeX/too.mashtx,\
(d[i]-d[j])*(sizeY-sizeDy)/too.mashty);
a.toend((unsigned long)i*too.number+j,(void*)&x);
				  }
			  }

			       }
/*void Buildm::matrixlength2(File& a){
a%4;
float x;
for(int i=0;i<too.number;i++){
     a.tik(((float(i)*100)/too.number));
     for(int j=0;j<too.number;j++){
      x=i==j?0.0:(float)hypot(c[i]-c[j],d[i]-d[j]);
     a.toend(i*too.number+j,(void*)&x);
				  }
			  }

			       }*/
Buildm::~Buildm(){};