#ifndef TETRIS
#define TETRIS
#include "tetris.h"
#include "tetobj.hpp"

extern "C" int rand(void);

class Tetris{
private:
char *A, *B;

Fig * figure;
char x,y;

	Fig* convert(char);
	void teststat(void);
	int movefig(void);
	Fig* getfig(){return convert(rand()%(figMax-1)+1);};
	void build(void);

public:
	Tetris(char,char);
	int go(void);
	~Tetris(){delete A;delete B;};
	 };


#endif
