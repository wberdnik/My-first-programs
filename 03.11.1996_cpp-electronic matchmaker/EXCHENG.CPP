#define iiiii
#include"excheng.hpp"
#include"vlad.hpp"

Excheng vlad(-1);

void Excheng::edit(void)
{ Win k;
  namemain[8]=0;k.kprintf(" Имя файла : main ->",namemain);
  namework[8]=0;k.kprintf(" Имя файла : work ->",namework);
  namexar[8]=0;k.kprintf(" Имя файла : xar -> ",namexar);
  namekat0[8]=0;k.kprintf(" Имя файла : kat0 -> ",namekat0);
  namekat1[8]=0;k.kprintf(" Имя файла : main -> ",namekat1);
  nameconfig[71]=0;k.kprintf(" Имя файла : config -> ",nameconfig);
  path[69]=0;k.kprintf(" Путь к каталогу -> ",path);
  extend[4]=0;k.kprintf(" Расширение -> ",extend);

  nametom[11]=0;k.kprintf(" Имя tom -> ",nametom);
  namemen[11]=0;k.kprintf(" Имя men -> ",namemen);
  namequllity[11]=0;k.kprintf(" Название качества -> ",namequllity);
  qullity[49]=0;k.kprintf(" Качества -> ",qullity);

  inifile[10]=0;k.kprintf(" Поле inifile -> ",inifile);
  initreb[48]=0;k.kprintf(" Поле initreb -> ",initreb);
  inixar[48]=0;k.kprintf(" Поле inixar -> ",inixar);

  k.kprintf(" счетчик -> ",&chethik);
  k.kprintf("file -> ",&file);
  k.kprintf("treb -> ",&treb);
  k.kprintf("xar -> ",&xar);

  k.kprintf("mark  file -> ",&markfile);
  k.kprintf("mark  treb -> ",&marktreb);
	k.kprintf("mark  xar -> ",&markxar);
	k.kprintf("vlad.stop  ",&vlad.stop);
 k.edit();
};
