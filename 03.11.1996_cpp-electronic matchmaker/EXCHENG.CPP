#define iiiii
#include"excheng.hpp"
#include"vlad.hpp"

Excheng vlad(-1);

void Excheng::edit(void)
{ Win k;
  namemain[8]=0;k.kprintf(" ��� 䠩�� : main ->",namemain);
  namework[8]=0;k.kprintf(" ��� 䠩�� : work ->",namework);
  namexar[8]=0;k.kprintf(" ��� 䠩�� : xar -> ",namexar);
  namekat0[8]=0;k.kprintf(" ��� 䠩�� : kat0 -> ",namekat0);
  namekat1[8]=0;k.kprintf(" ��� 䠩�� : main -> ",namekat1);
  nameconfig[71]=0;k.kprintf(" ��� 䠩�� : config -> ",nameconfig);
  path[69]=0;k.kprintf(" ���� � ��⠫��� -> ",path);
  extend[4]=0;k.kprintf(" ����७�� -> ",extend);

  nametom[11]=0;k.kprintf(" ��� tom -> ",nametom);
  namemen[11]=0;k.kprintf(" ��� men -> ",namemen);
  namequllity[11]=0;k.kprintf(" �������� ����⢠ -> ",namequllity);
  qullity[49]=0;k.kprintf(" ����⢠ -> ",qullity);

  inifile[10]=0;k.kprintf(" ���� inifile -> ",inifile);
  initreb[48]=0;k.kprintf(" ���� initreb -> ",initreb);
  inixar[48]=0;k.kprintf(" ���� inixar -> ",inixar);

  k.kprintf(" ���稪 -> ",&chethik);
  k.kprintf("file -> ",&file);
  k.kprintf("treb -> ",&treb);
  k.kprintf("xar -> ",&xar);

  k.kprintf("mark  file -> ",&markfile);
  k.kprintf("mark  treb -> ",&marktreb);
	k.kprintf("mark  xar -> ",&markxar);
	k.kprintf("vlad.stop  ",&vlad.stop);
 k.edit();
};
