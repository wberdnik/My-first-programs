#include"signal.hpp"
#include"function.hpp"
#include<process.h>
#include<stdio.h>
#include"diagnost.hpp"
#include"simple.hpp"
#include"button.hpp"
#pragma hdrstop
Signal::Signal():Modals(){
if(!yesno("  �� ��ࠫ� ���� ����஢�� ����஫������� \n"
	  "        � �ࠢ����� ᨣ����� � ��!\n"
	  "        �� ������ �த������ ����� ?"))return;
setcls(new Desktop);
setbase(new MasterButton(cmNo,"",0,""));
char* name;
name="iiscad.txt";
FILE * file=fopen(name,"r");
if(file==NULL){
   Message("    ��� ����室����� ⥪�⮢��� 䠩�� iiscad.txt"
	     "\n              �롥�� ���� ���");
   return;    }
   fclose(file);

File& a =*new File("netcad.iis");
if(a.end <2)
  {
   Message("    ��� ����室����� 䠩�� netcad.iis"
	     "\n     �롥�� ���� ���");
   delete &a;
   return;
  }

a%1+=sizeof(strCentre);

a%sizeof(strIIS);
a[0]>>(void*)&stol;
a+=1;
delete &a;

if(stol.kol==0)
 {
   Message("  ������⢮ ����⥫쭮-�����⥫��� �⮫��\n"
	   "               ࠢ��    ���\n"
	   "      ���쭥��� ࠡ�� ����������!!!");
   return;
 }

name="iis.exe";
file=fopen(name,"r");
if(file==NULL){
   Message(" ��� ����室����� ���૥����� 䠩��");
   return;    }
   fclose(file);
int k;
KNOW.close();
printf("  �����!!! ���� ��।������ ����஫��� � \n     �ࠢ����� ᨣ����� � ��");
k=system(name);
KNOW.open();
status=stFocus;
draft();

if(k){
  Message("�� ���� �������� ���૥��� 䠩�");
  return;}
Message("       �ਫ������ �����稫� ᢮� ࠡ���\n"
	"    �������� ��室���� � 䠩�� result.txt");
}
Signal::~Signal(){
}