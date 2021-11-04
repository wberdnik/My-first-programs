#ifndef HELP
#define  HELP

#ifndef MODALS
#include "modals.hpp"
#endif

class Help:public Modals{
char * string;
char * locals;
char number;
char that;
TextBar* pvv;
public:
	Help(char*);
	int sys(void);
	void draft(void);
	~Help();
};




#endif
