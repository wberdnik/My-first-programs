#include"cler.hpp"
#include<process.h>
Cler::Cler(Iosys* a,long n_kat,long n_cler):Spisok(sizeof(SLOT)),at((char*)&t)
 {
    from=a;
    if(from==NULL){
		  error(1,OPERATOR,"�� ���樠�����஢��� C���");
		  exit(1);
		  }
      // ������ �㦭� �����⠫��
     (((from->set(tKat0)[n_kat]).set(tMain))[n_cler]).set(tWork);
     //����ᨬ ᯨ᮪
     (*this)+vlad.stop;

     for(long i=0;i<end;i++){
      ((*from)[i]).ini(); // ��⠫�
      t.file=vlad.file;   // ����� �ࠪ���⨪�
      t.treb=vlad.treb;   // �ࠪ���⨪� ������
      t.xar=vlad.xar;     // �ࠪ���⨪� ᥡ�
      t.weightfb=vlad.weighttr;
      t.weigt=vlad.weigt; // �業�� �ॡ������
      t.weigx=vlad.weigtqullity; // ᢮� �業��
      t.others=vlad.others; // ����� �ࠢ��� � ���� ������
      (*this)[i]=at;      // ����ᠫ�
      }
}
 SLOT& Cler::find(long a){
	SLOT *c=(SLOT*)at.data;
	for(long i=0;i<end;i++){
   at=(*this)[i];
	 if(c->file==a)return *c;
	 }
	c->file=-1;
	return *c;
 }
