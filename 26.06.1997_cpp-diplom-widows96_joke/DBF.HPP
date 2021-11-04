#ifndef DBF
#define DBF

#ifndef  SOURSE
#include "sourse.hpp"
#endif
#pragma hdrstop

enum{
    baseNo,
    baseConcen,
    baseCabel,
    };
enum{
     dbfNorm,
     dbfGreat,
     dbfSboi,
     };


class Type{
 void ras(char,char);
protected:
       struct{
	      char* name;
	      char dlins;
	      char type;}field[7];
       char number;
       unsigned dlins;
       Type(char a);
  };


class Dbf :public Type,public File {
  private:
	     struct {
		 char dbf_id;
		 char last_update[1];
		 char kkk[2];
		 long last_rec;
		 unsigned data_offset;
		 unsigned rec_size;
		 char filler [20]; }head;

 /*  32 byte to long  поле dbf файла */

	     struct {
		 char field_name[11];
		 char field_type;
		 char dummy [4];
		union
		  { unsigned char_len;
		    struct { char len;
			     char dee;
				      } num_size;
		  } len_info;
		 char filler[14];

			    }poly;

//--------------------------------------------------------------------------

public:
     Dbf(char n_file,char* name);
     ~Dbf(void);
     char dbfinfo;
	     };
#endif