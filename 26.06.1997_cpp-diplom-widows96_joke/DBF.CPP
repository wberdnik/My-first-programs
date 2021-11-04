#include<string.h>
#include<dos.h>
#include"dbf.hpp"
	char* pole[7] ={ "C\x1f NAME",         // 0
			 "N\x4 CENA",          // 1
			 "N\x4 POTOK",         // 2
			 "N\x4 OUTFQ",
			 "N\x2 INPUT",         // 3
			 "N\x2 INPOTOK",
			 "N\x4 INFQ"
			 };      // 4

 //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Type::ras(char a,char b){
field[a].name=pole[b]+3;
field[a].dlins=pole[b][1];
field[a].type=pole[b][0];
dlins+=pole[b][1];
		       }

Type::Type(char a){
number=a==baseCabel?4:7;
dlins=0;
switch(a){
  case baseConcen :ras(6,6);
		   ras(5,5);
		   ras(4,4);
  case baseCabel:  ras(3,3);
		   ras(2,2);
		   ras(1,1);
		   ras(0,0);
	  }
		    }



Dbf :: Dbf(char n_file,char* name):File(name),Type(n_file){
File& one=*this;
dbfinfo=dbfNorm;
if(one.end){
  (one%32)[0]>>(void*)&head;
  head.rec_size=dlins;
  head.data_offset=number*32+34;
  one+=number+1;
  one%2+=1;

if(!(head.dbf_id==3 || head.rec_size!=dlins || head.data_offset<number*32+34))
     dbfinfo=dbfSboi;
		   }
 else{
 dbfinfo=dbfGreat;
 (one%32)+(number+1);

  head.dbf_id=3;
  head.last_rec=0;
  head.data_offset=number*32+34;
  head.rec_size=dlins;

  one[0]<<(void*)&head;
  for(int i=0;i<number;i++){
  for(char j=1;j<32;poly.field_name[j++]=0);
  strcpy(poly.field_name,field[i].name);
  poly.field_type=field[i].type;
  poly.len_info.char_len=field[i].dlins;
  one[i+1]<<(void*)&poly;
			   }
   one+=(number+1);
   char* a="\xd";((one%2)+1)[0]<<(void*)a;
   one+=1;
	    }

 len=dlins;  one%len;  end=one.end;  that=0;
};

Dbf::~Dbf(void){
 File& one=*this;
 struct date tdate;getdate(&tdate);

 for(char i=0;i<20;head.filler[i++]=0);
 head.dbf_id=3;
 head.last_update[1]=tdate.da_day;
 head.last_update[2]=tdate.da_mon;
 head.last_update[0]=(char)tdate.da_year-1900;
 head.last_rec=one.end;
 head.data_offset=(number+1)*32+2;
 head.rec_size=dlins;
 sbrosstart();
 (one%32)[0]<<(void*)&head;
	 };
