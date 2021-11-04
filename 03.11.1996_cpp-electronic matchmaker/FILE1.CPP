#include<string.h>
#include<dos.h>
#include"dbf.hpp"

	     void Dbf::read(char* a){Var b=a;b=one;};
	     void Dbf::set(long a){error(len>dlins,SYSTEM,"Error len");
	                            one[a];};
	     void Dbf::add(long a){one+a;};
	     void Dbf::del(long a){one-a;};


Dbf :: Dbf(char n_file):Type(n_file),one(!(*this))
{ that=0;
   one%32;
		Var* nik=new (0) Var((char *)&head);
	   error(sizeof(head)!=32,SYSTEM,"убери выравнивание");
	if(one.flag)
	 {  *nik=one[0];
	    error(!(head.dbf_id==3),DBFI,"DBF");        // return DONTDBF;
	    error(head.filler[0]=='f',WARNING,"Файл не был закрыт DBF");
	    if(head.rec_size!=dlins || head.data_offset<number*32+34)
		      error(1,BADFILE,!(*this));
		 head.rec_size=dlins;
		 head.data_offset=number*32+34;
	    one+=number+1;
	    one%2+=1;
	  }
	 else
	  {error(n_file==0 || n_file==1,WARNING,"нет коренных каталогов");
	   one+(number+1);
	    head.dbf_id=3;	head.last_rec=0;
	    head.data_offset=number*32+34;
	    head.rec_size=dlins;
	    strcpy(head.filler,"file dont closed ");

		one[0]=*nik;

		*nik=(char*)&poly;

		 for(int i=0;i<number;i++)
			 {for(char j=1;j<32;j++) poly.field_name[j]=0;

				strcpy(poly.field_name,field[i].name);
				poly.field_type=field[i].type;
				poly.len_info.char_len=field[i].dlins;
				one[i+1]=*nik;
				}

	      one+=(number+1);
		one%2;
		one+1;
		*nik="\xd";
		one[0]=*nik;
		one+=1;
	    }
                len=dlins;
                one%len;
		end=one.end;        
	       delete nik;
};
Dbf::~Dbf(void)
 {    		 struct date tdate;
		 head.dbf_id=3;          
		 getdate(&tdate);
			for(char i=0;i<20;i++) head.filler[i]=0;
			head.last_update[1]=tdate.da_day;
			head.last_update[2]=tdate.da_mon;
			head.last_update[0]=(char)tdate.da_year-1900;
			head.last_rec=one.end;
			head.data_offset=(number+1)*32+2;
			head.rec_size=dlins;
			Var nik=(char*)&head;

     one%2;
     one-=1;              //кушаем 0d 00
    (one%32)-=(number+1);     //открываем доступ
     one[0]=nik;             // пишем
	 };
