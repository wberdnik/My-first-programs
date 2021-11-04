#include"object.hpp"
#include"control.hpp"
#include"slave.h"
#pragma hdrstop

Object::Object(int xi,int yi,int ci):Control(){
color=ci; status=0;
operator()(xi,yi);}

Object& Object::move(int xi,int yi){
  if(status) restore();
  (*this)(xi,yi);
  if(status) show();
  return *this;        }

Object& Object::operator=(int c){
  --(*this);
  color=c;
  ++(*this);
  status=1; return *this;         }

Object& Object::operator++(void){
 if(status)return *this;
  status=1;
  show();
  return *this;         }

Object& Object::operator--(void){
 if(!status)return *this;
  status=0;
  restore();
  return *this; }

Object& Object::hmove(int a,int b){
 if(status)restore();
  work(a,b);
  if(status)show();
  return *this;   }


void Control::operator()(int a,int b){
if(a<0)a=0;	 		if(b<0)b=0;
if(a>sizeX)a=sizeX;		if(b>sizeY)b=sizeY;
x=a;y=b;}


extern "C" {
	     void exit(int);
	     int getch(void);
	     int printf(const char * , ...);
	    };


void Control2::operator()(int a,int b,int c,int d){
operator()(a,b);
if( (c<0 || c+x>sizeX) || (d<0 || d+y>sizeY)){
    printf("\n Некорректная установка размеров обьекта");
    getch();
    exit(33); 				     }
 w=c;h=d;
						 }




