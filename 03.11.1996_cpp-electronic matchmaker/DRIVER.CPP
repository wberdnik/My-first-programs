#include"driver.hpp"
#include"base.hpp"

Driver::Driver(Iosys* a,long n_kat,long n_men,long n_group){
 homer=new(0)Cler(a,n_kat,n_men);
 n_gr=n_group;
 end=0;
 base=a;
		     }

void Driver::run(char mark){
  marks* t;

 (base->set(tKat0))[n_gr].set(tMain);      // ��।����� ࠧ��� ��㯯�
   size_group=vlad.stop;
   end=size_group;
  comp=new (0) Comp(size_group,mark);      // �����⮢��� ���� �業��

  for(long i=0;i<size_group;i++){          // 横� ��ॡ�� �������⮢

      (*comp)[i];                          // ������ ���� 蠡��� �業��

     kandidat=new (0) Cler(base,n_gr,i);   // ���뢠��� ��������



      t=&(comp->get());

                      //������ ���樠������ ��������  �業��               

      t->qme   = (int)homer->end;         
      t->qyou  = (int)kandidat->end;
      t->enable=0;
      t->enable1=0;
      t->forme =0;
      t->foryou=0;
      t->marks =0;
			t->hu    =i;

                      // �業�� ᮮ⢥��⢨� ���� ����������

			for(long j=0;j<homer->end;j++) {       // �� �ॡ������ �����稪�
			 (*homer)[j];
			 comp->run(homer->get(),kandidat->find(homer->get().file));
                          					}       // �ࠢ����


      delete kandidat;                      // ���㤥� �⮣� ������

      t->marks=aprior(*t);                  // � ���� ��� �����⥫���
			                                      // �業��
        	 }
      // �� �����襭� 
      // ���⮬� ���㤥� � � ������

    delete homer;

 }

float Driver::aprior(marks& a){
    return ((a.forme+a.foryou)*(a.enable+a.enable1))/(a.qme+a.qyou);
			      }

void Driver::sort(int number){
 Wait wi('?');
 float max;
 long nmax;
 float c;
 long j;

 for(long i=0;i<number && i<comp->end;i++){
					// ���� ���ᨬ㬠
  nmax=i;(*comp)[i];max=comp->get().marks;

   for(j=i+1;j<comp->end;j++){
     (*comp)[j];
     c=comp->get().marks;
     if(max<c){max=c;nmax=j;}
			     }
    if(nmax!=i)					// ���஢��
		((*comp)[i])(nmax);
			   // �����﫨 i � j
			  }
     }
