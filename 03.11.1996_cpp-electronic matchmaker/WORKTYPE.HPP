#ifndef WORKTYPE
#define WORKTYPE

#define tKat0 0
#define tKat1 1
#define tXar  2
#define tMain 3
#define tWork 4

class Type
{   	char type;
	char sbros[80];
	char* great(char*);
   public:
       char* toname(void);
       Type(char a);
       char* operator!(void){return great(toname());};
       char number;
       char dlins;
       struct{
	      char* name;
	      char dlins;
	      char type;}field[6];

  };

#endif