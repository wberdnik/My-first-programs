#ifndef SCR
#define SCR

class Scr{
 unsigned *line;
 char x;
 char y;
 public:
 Scr(char a);
 void operator !(void);
 ~Scr();
};
#endif
