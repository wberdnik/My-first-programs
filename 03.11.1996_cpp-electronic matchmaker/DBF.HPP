#ifndef DBF
#define DBF

#include"sourse.hpp"

#include"worktype.hpp"

 /* заголовок  dbf файла      */



class Dbf : public Base , public Type
 {
	     private:

	     File one;

	     void read(char* );
	     void set(long);
	     void add(long);
	     void del(long);


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


	     char name[16];

	     public:

	     Dbf(char n_file);
	     ~Dbf(void);
	     Base& operator=(Var& a){one=a;return *this;};
	     };

#endif