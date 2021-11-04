#ifndef ERROR
#define ERROR

#ifndef SCR
#include"scr.hpp"
#endif

#define OPEN       1
#define CLOSE      2
#define READ       3
#define WRITE      4
#define MEM        5
#define DBFI       6
#define BADFILE    7
#define SYSTEM     8
#define OPERATOR   9
#define CHANGE     10
#define CONFIGI    11
#define WARNING    12

void error(int res,int kode,char* c);
#endif