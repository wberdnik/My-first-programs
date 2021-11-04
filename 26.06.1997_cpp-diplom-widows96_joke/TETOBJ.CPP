#include"tetobj.hpp"
#include"tetris.h"
#pragma hdrstop
// public

 int Xtest(char x,char y,char n){
   if(x<0 || x+n>weight || y>=deep)return gNo;
   for(char i=0;i<n;i++)if(tetmas[x+i+y*weight]!=figNo)return gNo;
  return gYes;
			 };

  void Xset(char x,char y,char n,char ident){
   for(char i=0;i<n;i++) tetmas[x+i+y*weight]=ident;
			 };

  void Xreset(char x,char y,char n){
   for(char i=0;i<n;i++)  tetmas[x+i+y*weight]=figNo;
			 };

 int Ytest(char x,char y,char n){
   if(x<0 || x>=weight || y+n>deep)return gNo;
   for(char i=0;i<n;i++) if(tetmas[x+(y+i)*weight]!=figNo)return gNo;
  return gYes;		 };

  void Yset(char x,char y,char n,char ident){
   for(char i=0;i<n;i++)   tetmas[x+(i+y)*weight]=ident;
			 };

  void Yreset(char x,char y,char n){
   for(char i=0;i<n;i++) tetmas[x+(i+y)*weight]=figNo;
			 };

//class One ::      л


int One::test(void){return Xtest(x,y,1);}
int One::others(int){return figNo;}
void One::set(void){Xset(x,y,1,figOne);}
void One::reset(void){Xreset(x,y,1);}


//class Two ::               лл

int  Two::test(void){return Xtest(x,y,2);}
void Two::set(void){Xset(x,y,2,figTwo);}
void Two::reset(void){Xreset(x,y,2);}
int  Two::others(int){return figUpTwo;}


// class Three ::            ллл

int  Three::test(void){return Xtest(x,y,3);}
void Three::set(void){Xset(x,y,3,figThree);}
void Three::reset(void){Xreset(x,y,3);}
int  Three::others(int){return figUpThree;}


//class Four                 лллл

int  Four::test(void){return Xtest(x,y,3);}
void Four::set(void){Xset(x,y,3,figFour);}
void Four::reset(void){Xreset(x,y,3);}
int  Four::others(int){return figUpFour;}

//class UpTwo                   л
//                              л

int  UpTwo::test(void){return Ytest(x,y,2);}
void UpTwo::set(void){Yset(x,y,2,figUpTwo);}
void UpTwo::reset(void){Yreset(x,y,2);}
int  UpTwo::others(int){return figTwo;}


//class UpThree ::                л
//                                л
//                                л
int  UpThree::test(void){return Ytest(x,y,3);}
void UpThree::set(void){Yset(x,y,3,figUpThree);}
void UpThree::reset(void){Yreset(x,y,3);}
int  UpThree::others(int){return figThree;}

//class UpFour ::               л
//                              л
//                              л
//                              л

int  UpFour::test(void){return Ytest(x,y,4);}
void UpFour::set(void){Yset(x,y,4,figUpFour);}
void UpFour::reset(void){Yreset(x,y,4);}
int  UpFour::others(int){return figFour;}


//class Upper ::                       л
//                                     u
//                                     p
//				       л

int  Upper::test(void){return Ytest(x,y,4);}
void Upper::set(void){Yset(x,y,4,figUpper);}
void Upper::reset(void){Yreset(x,y,4);}
int  Upper::others(int){return figNo;}


//class Block ::                         лл
//                                       лл

int  Block::test(void){return Ytest(x,y,2)&&Ytest(x,y,2);}
void Block::set(void){Yset(x,y,2,figBlok);Yset(x+1,y,2,figBlok);}
void Block::reset(void){Yreset(x,y,2);Yreset(x+1,y,2);}
int  Block::others(int){return figNo;}


//class Z ::                             лл
//                                        лл

int  Z::test(void){return Xtest(x,y,2)&&Xtest(x+1,y+1,2);}
void Z::set(void){Xset(x,y,2,figZ);Xset(x+1,y+1,2,figZ);}
void Z::reset(void){Xreset(x,y,2);Xreset(x+1,y+1,2);}
int  Z::others(int){return figUpZ;}



//class MZ ::                             лл
//                                       лл
int  MZ::test(void){return Xtest(x+1,y,2)&&Xtest(x,y+1,2);}
void MZ::set(void){Xset(x+1,y,2,figMZ);Xset(x,y+1,2,figMZ);}
void MZ::reset(void){Xreset(x+1,y,2);Xreset(x,y+1,2);}
int  MZ::others(int){return figUpMZ;}


//class UpZ ::                             л
//                                        лл
//					  л

int  UpZ::test(void){return Ytest(x,y+1,2)&&Ytest(x+1,y,2);}
void UpZ::set(void){Yset(x,y+1,2,figUpZ);Yset(x+1,y,2,figUpZ);}
void UpZ::reset(void){Yreset(x,y+1,2);Yreset(x+1,y,2);}
int  UpZ::others(int){return figZ;}


//class UpMZ ::                           л
//                                        лл
//                                         л

int  UpMZ::test(void){ return Ytest(x,y,2)&&Ytest(x+1,y+1,2);}
void UpMZ::set(void){Yset(x,y,2,figUpMZ);Yset(x+1,y+1,2,figUpMZ);}
void UpMZ::reset(void){Yreset(x,y,2);Yreset(x+1,y+1,2);}
int  UpMZ::others(int){return figMZ;}

//class LtML ::          Yes=Right       лллл
//                                          л

int  LtML::test(void){return Xtest(x,y,4)&&Xtest(x+3,y+1,1);}
void LtML::set(void){Xset(x,y,4,figLtML);Xset(x+3,y+1,1,figLtML);}
void LtML::reset(void){Xreset(x,y,4);Xreset(x+3,y+1,1);}
int  LtML::others(int a){return a?figUpML:figDnML;}

//class LtL ::                             л
//                                      лллл

int  LtL::test(void){return Xtest(x,y+1,4)&&Xtest(x+3,y,1);}
void LtL::set(void){Xset(x,y+1,4,figLtL);Xset(x+3,y,1,figLtL);}
void LtL::reset(void){Xreset(x,y+1,4);Xreset(x+3,y,1);}
int  LtL::others(int a){return a?figUpL:figDnL;}


//class RtL ::          Yes=Right       лллл
//                                      л

int  RtL::test(void){return Xtest(x,y,4)&&Xtest(x,y+1,1);}
void RtL::set(void){Xset(x,y,4,figRtL);Xset(x,y+1,1,figRtL);}
void RtL::reset(void){Xreset(x,y,4);Xreset(x,y+1,1);}
int  RtL::others(int a){return a?figDnL:figUpL;}

//class RtML ::                          л
//                                       лллл

int  RtML::test(void){return Xtest(x,y+1,4)&&Xtest(x,y,1);}
void RtML::set(void){Xset(x,y+1,4,figRtML);Xset(x,y,1,figRtML);}
void RtML::reset(void){Xreset(x,y+1,4);Xreset(x,y,1);}
int  RtML::others(int a){return a?figDnML:figUpML;}


/*******************************************************************/

//class UpL ::                            л
//                                        л
//                                        л
//                                        лл


int  UpL::test(void){return Ytest(x,y,4)&&Ytest(x+1,y+3,1);}
void UpL::set(void){Yset(x,y,4,figUpL);Yset(x+1,y+3,1,figUpL);}
void UpL::reset(void){Yreset(x,y,4);Yreset(x+1,y+3,1);}
int  UpL::others(int a){return a?figRtL:figLtL;}


//class UpML ::                           л
//                                        л
//					  л
//					 лл

int  UpML::test(void){return Ytest(x+1,y,4)&&Ytest(x,y+3,1);}
void UpML::set(void){Yset(x+1,y,4,figUpML);Yset(x,y+3,1,figUpML);}
void UpML::reset(void){Yreset(x+1,y,4);Yreset(x,y+3,1);}
int  UpML::others(int a){return a?figRtML:figLtML;}


//class DnML ::         Yes=Right        лл
//                                       л
//					 л
//					 л

int  DnML::test(void){return Ytest(x,y,4)&&Ytest(x+1,y,1);}
void DnML::set(void){Yset(x,y,4,figDnML);Yset(x+1,y,1,figDnML);}
void DnML::reset(void){Yreset(x,y,4);Yreset(x+1,y,1);}
int  DnML::others(int a){return a?figLtML:figRtML;}


//class DnL ::                          лл
//                                       л
//					 л
//					 л

int  DnL::test(void){return Ytest(x+1,y,4)&&Ytest(x,y,1);}
void DnL::set(void){Yset(x+1,y,4,figDnL);Yset(x,y,1,figDnL);}
void DnL::reset(void){Yreset(x+1,y,4);Yreset(x,y,1);}
int  DnL::others(int a){return a?figLtL:figRtL;}
