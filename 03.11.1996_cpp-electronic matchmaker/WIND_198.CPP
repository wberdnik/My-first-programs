#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<bios.h>
#include<stdlib.h>
#include<alloc.h>

#define COLMEN LIGHTGREEN
#define REDIT 4864

#include"iosys.hpp"
#include"driver.hpp"
#include"wind_2.h"

Iosys *vviv;
Driver *swaha;
marks *resultat;
Scr * screen;
main()
{strcpy(vlad.nameconfig,"swaha.cfg");
	vviv=new(0)Iosys(1);
  wind=0;
  per=0;
  menu_00();
  menu_1();
 /*------------*/
  menu(BLUE,WHITE,YELLOW);
  menu4_0();
  gotoxy(15,2);
 /*-------------*/
int a;
   while(1)
    {  a=bioskey(0);
     switch(a)
       {
	 case UP:
	   if(per==0)
	     {
	      if(wherey()>2)
		gotoxy(wherex(),wherey()-1);
	     }
	   if(per==1)
	     {
	      menu1_1();
	     }
	   break;
	 case DOWN:
	    if(per==0)
	      {
	       if(wherey()<23)
		 gotoxy(wherex(),wherey()+1);
	      }
	    if(per==1)
	     {
	      gotoxy(wherex(),wherey()+1);
	      menu1_0();
	     }
	    break;
	 case LEFT:
	    if((wherex()>15)&&(wherex()<64))
	      gotoxy(wherex()-1,wherey());
	    break;
	 case RIGHT:
	    if(wherex()<63)
	      gotoxy(wherex()+1,wherey());
	    break;
   case REDIT: if(getch()=='e'){vlad.edit();textcolor(BLACK);}
              break;
	 case TAB:
	    switch(per)
	     {
	      case 1:
		{
		 if(wind==2)
		   vviv->up();
		 wind=0;
		 menu4_0();
		 menu_down_1();
		 per=0;
		 gotoxy(15,2);
		 break;
		}
	      case 0:
		{
		 gotoxy(wherex(),3);
		 menu1_0();
		 per=1;
		 break;
		}
	     }
	    break;
	 case CR:
	    strncpy(name1,*(name_func+wherey()-3),11);
	     if(strcmp(name1,"menu_down()")==0)
	      {
	       menu4_0();
	       wind++;
	       if(wind==1)
		{
		 per_k=1;
		 init_katal();
		 if(vlad.stop!=0)
		   {
		    read_katalog();
		    mov_init();
		   }
		};
		menu_down();
		break;
	      }
	     if(strcmp(name1,"menu_up()")==0)
	      {
	       if(vlad.stop!=0)
		 move_katalog_dn();
	       break;
	      }
	     if(strcmp(name1,"quit")==0)
	       quit();
	     if(strcmp(name1,"red_kat()")==0)
	      {
	       if(vlad.stop!=0)
		 redoctir_name_kat();
	       break;
	      }
	     if(strcmp(name1,"red_men()")==0)
	      {
	       redoctir_name_men();
	       break;
	      }
	     if(strcmp(name1,"inc_kat()")==0)
	      {
	       inc_name_kat();
	       break;
	      }
	     if(strcmp(name1,"del_kat()")==0)
	      {
	       if(vlad.stop!=0)
		 delete_kat();
	       break;
	      }
	     if(strcmp(name1,"del_men()")==0)
	      {
	       delete_men();
	       break;
	      }
	     if(strcmp(name1,"inc_men()")==0)
	      {
	       move_men_men();
	       break;
	      }
	     if(strcmp(name1,"dec_men()")==0)
	      {
	       move_men_dn();
	       break;
	      }
	     if(strcmp(name1,"inc_men1()")==0)
	      {
	       inc_name_men();
	       break;
	      }
	     if(strcmp(name1,"quit_up()")==0)
	      {
	       menu4_0();
	       if(wind==6||wind==8)
		  wind=0;
	       else
		  wind--;
	       menu_down();
	       break;
	      };
	     if(strcmp(name1,"kat_down()")==0)
	      {
		if(vlad.stop!=0)
		  {
		    menu4_0();
		    dn_name_kat();
		    textbackground(COLMEN);
		    gotoxy(15,1);
		    cprintf("%s",line5);
		    wind++;
		    menu_down();
		  }
		break;
	      }
	     if(strcmp(name1,"kat_up()")==0)
	      {
	       vviv->set(tKat0);
	       strcpy(line5,"");
	       menu4_0();
	       wind--;
	       if(wind==1||wind==6)
		{
		  read_katalog();
		  textcolor(WHITE);
		  textbackground(COLMEN);
		  gotoxy(2,m_k);
		  cprintf("%s",name_katalog[m_k-2]);
		  textcolor(0);
		}
	       menu_down();
	       break;
	      }
	     if(strcmp(name1,"men_up()")==0)
	      {
	       if(f_tr_xar==1)
		{
		 vviv->kat();
		 f_tr_xar=0;/*если было требование или характеристика*/
		}
	       vviv->up();
	       menu4_0();
	       dlina();
	       wind--;
	       read_men();
	       textcolor(WHITE);
	       textbackground(COLMEN);
	       gotoxy(2,m_m);
	       cprintf("%s",name_men[m_m-2]);
	       textcolor(0);
	       flag_tr_xar=0;
	       flag_ramka=0;
	       menu_down();
	       break;
	      }
	     if(strcmp(name1,"move_kat")==0)
	      {
	       if(vlad.stop!=0)
		 move_katalog();
	       break;
	      }
	     if(strcmp(name1,"del_kach")==0)
	      {
	       if(vlad.stop!=0)
		  delete_kach();
	       break;
	      }

    /******Работа с базой качеств******/

	     if(strcmp(name1,"menu_down_1")==0)
	      {
	       per_k=0;
	       menu4_0();
	       vviv->set(tKat1);
	       init_name_kach();
	       if(vlad.stop!=0)
		 {
		  wind=4;
		 }
	       else
		 {
		  wind=0;
		  vviv->kat();
		 }
	       menu_down();
	       break;
	      }
	     if(strcmp(name1,"quit_up_1")==0)
	      {
	       menu4_0();
	       gotoxy(15,1);
	       cprintf("%s",line5);
	       
	       if(per_k==0)
		 wind=0;
	       if(per_k==1)
		{
		 wind=3;
		 flag_tr_xar=1;
		 f_save=0;
		}
	       menu_down();

	       if(per_k==1)
		{
		 vviv->set(tWork);
		 textbackground(LIGHTCYAN);
		 gotoxy(40,1);
		 cprintf("ХАРАКТЕРИСТИКИ");
		 gotoxy(42,13);
		 cprintf("ТРЕБОВАНИЯ");
		 textcolor(0);
		 textbackground(COLMEN);
		 help3();
		 gotoxy(64,3);
		 kach_treb_xar();
		 textbackground(COLMEN);
		 if(vlad.stop!=0)
		   {
		    if(m_k_t==0)
		      m_k_t=2;
		    textcolor(WHITE);
		    gotoxy(2,m_k_t);
		    cprintf("%s",name_kach_d[m_k_t-2]);
		    gotoxy(2,m_k_t+12);
		    cprintf("%s",name_kach_d[m_k_t-2]);
		    textbackground(BLUE);
		    textcolor(0);
		    gotoxy(64,3);
		   }
		}
	       else
		{
                 vviv->set(tKat0);
		}
	       break;
	      };
	     if(strcmp(name1,"kach_up")==0)
	      {
	       if(vlad.stop!=0)
		 move_kach_dn();
	       break;
	      }
	     if(strcmp(name1,"mov_kach")==0)
	      {
	       move_kach();
	       break;
	      }
	     if(strcmp(name1,"inc_kach")==0)
	      {
	       inc_name_kach();
	       break;
	      }
	     if(strcmp(name1,"red_kach")==0)
	      {
	       if(vlad.stop!=0)
		 redoctir_name_kach();
	       break;
	      }

/******     Качества     ******/

	     if(strcmp(name1,"kach_dn")==0)
	      {
		if(vlad.stop!=0)
		  {
		    dn_name_kach();
		    menu_down();
		  }
		break;
	      }
	     if(strcmp(name1,"quit_kach")==0)
	      {
	       vviv->up();
	       wind=4;
	       menu_2();
	       menu_down();
	       break;
	      };
	     if(strcmp(name1,"inc_qull")==0)
	      {
	       inc_name_qullity();
	       break;
	      }
	     if(strcmp(name1,"inc_q()")==0)
	      {
	       move_men_qullity();
	       break;
	      }
	     if(strcmp(name1,"dec_qull")==0)
	      {
	       move_qullity_dn();
	       break;
	      }
	     if(strcmp(name1,"red_qull")==0)
	      {
	       redoctir_name_qullity();
	       break;
	      }
	     if(strcmp(name1,"del_qull")==0)
	      {
	       delete_qullity();
	       if(vlad.stop==0)
		 gotoxy(64,3);
	       break;
	      }

/******Обьединение двух баз******/
	     if(strcmp(name1,"menu_too()")==0)
	      {
	       menu4_0();
	       kact_treb();
	       wind++;
	       menu_down();
	       textbackground(LIGHTCYAN);
	       gotoxy(40,1);
	       cprintf("ХАРАКТЕРИСТИКИ");
	       gotoxy(42,13);
	       cprintf("ТРЕБОВАНИЯ");
	       textcolor(0);
	       textbackground(COLMEN);
	       help3();
	       gotoxy(64,3);
	       break;
	      }
	     if(strcmp(name1,"in_men_t")==0)
	      {
	       per_k=1;
	       menu4_0();
	       gotoxy(15,1);
	       cprintf("%s",line5);
	       if(f_tr_xar==0)
 /***********/   vviv->set(tKat1);
	       else
		  f_tr_xar=0; /*если есть качества и требования*/
	       init_name_kach();
	       wind=4;
	       flag_tr_xar=1;
	       menu_down();
	       break;
	      }

  /******Работа с базой качеств из каталога******/
	     if(strcmp(name1,"mark_1")==0)
	      {
	       if(vlad.stop!=0)
		 mark_xar();
	       break;
	      }

  /******Работа внутри базы качеств из каталога******/
	     if(strcmp(name1,"mark_2")==0)
	      {
	       mark_treb();
	       break;
	      }
	     if(strcmp(name1,"mark_3")==0)
	      {
	       mark_xar_xar();
	       break;
	      }


	   /*****Запись изменений*****/
	     if(strcmp(name1,"save()")==0)
	      {
	       save_kact();
	       break;
	      }

/***** Передвижение по характеристикам и требованиям *****/
	     if(strcmp(name1,"inc_t_x")==0)
	      {
	       if(vlad.stop!=0)
		 move_treb_xar();
	       break;
	      }

	     if(strcmp(name1,"dec_t_x")==0)
	      {
		if(vlad.stop!=0)
		  move_treb_kach_dn();
		break;
	      }
	     if(strcmp(name1,"del_t_x")==0)
	      {
		if(vlad.stop!=0)
		  del_k_tr();
		break;
	      }
      /* Ввод весов  */
	     if(strcmp(name1,"netto()")==0)
	      {
		if(vlad.stop!=0)
		  netto();
		break;
	      }



       /***** Вхождение в сваху *****/


	     if(strcmp(name1,"menu_down_s")==0)
	      {
	       menu4_0();
	       wind=6;
	       init_katal();
	       if(vlad.stop!=0)
		 {
		  read_katalog();
		  mov_init();
		 }
	       menu_down();
		break;
	      }

	/***** Запомнить католог клиента *****/
	     if(strcmp(name1,"k_client")==0)
	      {
	       if(vlad.stop!=0)
		 {
		  kat_client();
		 };
		break;
	      }

	/***** Запомнить клиента *****/
	     if(strcmp(name1,"client")==0)
	      {
	       if(vlad.stop!=0)
		 {
		  client();
		 };
		break;
	      }

	/***** Запомнить группу *****/
	     if(strcmp(name1,"group")==0)
	      {
	       if(vlad.stop!=0)
		 {
		  group();
		 };
		break;
	      }

	/***** Запуск свахи *****/
	     if(strcmp(name1,"r_swaha")==0)
	      {
		run_swaha();
		break;
	      }

       /***** Вхождение в вывод результатов свахи *****/
	     if(strcmp(name1,"menu_down_r")==0)
	      {
	       menu4_0();
	       wind=8;
	       if(swaha->end!=0 && swaha!=NULL)
		 init_res();
	       else
		 no_res();
	       menu_down();
		break;
	      }


       /***** Передвижение по результатам свахи вниз*****/
	     if(strcmp(name1,"inc_swaha")==0)
	      {
                inc_swaha();
		break;
	      }

       /***** Передвижение по результатам свахи вверх*****/
	     if(strcmp(name1,"dec_swaha")==0)
	      {
		dec_swaha();
		break;
	      }


	     break;
	 case ESC:
	    if(wind==2)
	      vviv->up();
	    quit();
       };
    };
/*-------------*/
}


/******Передвижение вверх в окне******/
 void menu1_1(void)
  {
    if(wherey()!=3)
     {
      textbackground(WHITE);
      gotoxy(64,wherey()-1);
      cprintf("%s\n",*(name_window+wherey()-3));
      textbackground(COLMEN);
      gotoxy(64,wherey());
      cprintf("%s\n",*(name_window+wherey()-3));
      gotoxy(64,wherey()-2);
     }
    else
     {
      textbackground(COLMEN);
      gotoxy(64,wherey());
      cprintf("%s\n",*(name_window+wherey()-3));
      textbackground(WHITE);
      gotoxy(64,2+*(namber+wind));
      cprintf("%s\n",*(name_window+wherey()-3));
      gotoxy(64,wherey()-1);
     }

  }

/******Вволится в окно уровня ниже******/
 void menu_down(void)
  {
   menu_1();
   menu_0();
   menu0();
   menu1_0();
  }

/******Ввойти в окно уровня выше******/
 void menu_down_1(void)
  {
   menu_1();
   menu_0();
   menu0();
  }



/******Инициализация имен каталога******/
 void init_katal(void)
  {
   int z;

   if(f_one_exit_2==1)
     for(z=0;z<11;delete name_katalog[z++]);
   f_one_exit_2=1;
   for(z=0;z<11;z++)
    {
     name_katalog[z]=(char*)mallos(11);
    }
  if(vlad.stop!=0)
    {
      z_k=10;
      for(z=0;z<11;z++)
	{
	  if(z>=vlad.stop)
	    {
	      f_end_katalog=z-1;
	      z_k=z-1;
	      break;
	    }
	  (*vviv)[z];
	  strncpy(name_katalog[z],vlad.nametom+1,11);
	};
    }
  }

/******Чтение имен каталога******/
 void read_katalog(void)
  {
   int k=11,z;


   textbackground(9);
   textcolor(WHITE);
   if(f_end_katalog!=0||z_k==0)
     k=f_end_katalog+1;
   gotoxy(2,1);
   for(z=0;z<k;z++)
    {
      gotoxy(2,wherey()+1);
      cprintf("%s",name_katalog[z]);
    }
   textcolor(0);
  }

/******Передвижение по именам каталогов вверх******/
 void move_katalog(void)
  {
   int z;
     if(f_end_katalog!=0)
       z=f_end_katalog;
     else
       z=10;
     if(m_k>=12)
      {
       inc_kat();
      }
     if(m_k!=z+2&&z_k!=0)
      {
       mov_kat();
       gotoxy(64,4);
      }
  }

void mov_init(void)
  {
     if(per_kat!=10)
      {
       textcolor(WHITE);
       textbackground(COLMEN);
       gotoxy(2,2);
       cprintf("%s",name_katalog[0]);
       per_kat=10;
       gotoxy(64,4);
       textcolor(0);
       m_k=2;
      }
     else
      {
       textcolor(WHITE);
       textbackground(COLMEN);
       gotoxy(2,m_k);
       cprintf("%s",name_katalog[m_k-2]);
       gotoxy(64,4);
       textcolor(0);
      }
  }

void mov_kat(void)
  {
    textcolor(WHITE);
    textbackground(COLMEN);
    gotoxy(2,m_k+1);
    cprintf("%s",name_katalog[m_k-1]);
    gotoxy(2,m_k);
    textbackground(BLUE);
    cprintf("%s",name_katalog[m_k-2]);
    m_k++;
    textcolor(0);
  }

/******Передвижение по именам каталогов вниз******/
void move_katalog_dn(void)
  {
   if(m_k==2&&z_k>10)
    {
     dec_kat();
    }
   if(m_k!=2)
    {
     textcolor(WHITE);
     textbackground(COLMEN);
     gotoxy(2,m_k-1);
     cprintf("%s",name_katalog[m_k-3]);
     gotoxy(2,m_k);
     textbackground(BLUE);
     cprintf("%s",name_katalog[m_k-2]);
     m_k--;
     gotoxy(64,5);
     textcolor(0);
    }
  }

/******Изменение каталога******/
void inc_kat(void)
  {
   int z;
   z_k++;
   if(z_k<vlad.stop)
    {
      for(z=0;z<10;z++)
       {
	 strncpy(name_katalog[z],name_katalog[z+1],11);
       }
      (*vviv)[z_k];
      strncpy(name_katalog[10],vlad.nametom+1,11);

      init_two();
      textbackground(COLMEN);
      gotoxy(2,12);
      cprintf("%s",name_katalog[10]);
      gotoxy(64,4);
      textcolor(0);
    }
   else
    z_k--;
  }

void dec_kat(void)
  {
   int z;
   if(z_k>10)
    {
      z_k--;
      for(z=9;z>=0;z--)
       {
	 strncpy(name_katalog[z+1],name_katalog[z],11);
       }
      (*vviv)[z_k-10];
      strncpy(name_katalog[0],vlad.nametom+1,11);
    }
   init_two();
   textbackground(COLMEN);
   gotoxy(2,2);
   cprintf("%s",name_katalog[0]);
   gotoxy(64,5);
   textcolor(0);
  }

void init_two(void)
  {
   int z;
   textbackground(9);
   textcolor(WHITE);
   gotoxy(2,1);
   for(z=0;z<11;z++)
    {
      gotoxy(2,wherey()+1);
      cprintf("%s",line3);
    }
   gotoxy(2,1);
   for(z=0;z<11;z++)
    {
      gotoxy(2,wherey()+1);
      cprintf("%s",name_katalog[z]);
    }
  }

/******Добавление каталога******/
void inc_name_kat(void)
  {
   vv();
   if(strcmp(dop,"")!=0)
    {
     if(vlad.stop==0)
      {
       z_k=-1;
       f_end_katalog=-1;
       m_k=2;
      }
     ++(*vviv);
     (*vviv)[vlad.stop-1];
     strncpy(vlad.nametom+1,dop,11);
     vviv->save();
     if(z_k<10)
      {
       f_end_katalog++;
       z_k++;
       strncpy(name_katalog[f_end_katalog],dop,11);
       textcolor(WHITE);
       textbackground(BLUE);
       if(vlad.stop==1)
	 textbackground(COLMEN);
       gotoxy(2,f_end_katalog+2);
       cprintf("%s",name_katalog[f_end_katalog]);
      }

    }
   textcolor(0);
   gotoxy(64,8);
 }



/******Редоктирование каталога******/
void redoctir_name_kat(void)
  {
   vv();
   if(strcmp(dop,"")!=0)
    {
     if(z_k>=10)
       (*vviv)[z_k-12+m_k];
     else
       (*vviv)[m_k-2];
     strncpy(vlad.nametom+1,dop,11);
     vviv->save();
     strncpy(name_katalog[m_k-2],dop,11);
     textbackground(BLUE);
     gotoxy(2,m_k);
     cprintf("           ");
     textcolor(WHITE);
     textbackground(COLMEN);
     gotoxy(2,m_k);
     cprintf("%s",name_katalog[m_k-2]);
    }
   textcolor(0);
   gotoxy(64,9);
 }

/******Удаление каталога******/
void delete_kat(void)
 {
   char dop_1;
   char dop_2[2]="";
   int i;

   massege8();
   dop_1=getch();
   textbackground(BLUE);
   clrscr();
   window(1,1,80,25);
   if(dop_1=='y'||dop_1=='Y'||dop_1=='н'||dop_1=='Н')
    {
     if(z_k>=10)
       (*vviv)[z_k-12+m_k];
     else
       (*vviv)[m_k-2];
     strncpy(dop_2,vlad.nametom,1);
     if(dop_2[0]!='*')
      {
	massege9();

	textcolor(0);
	gotoxy(64,7);
      }
     else
      {
       if(z_k>=10)
	 (*vviv)[z_k-12+m_k];
       else
	 (*vviv)[m_k-2];
	   --(*vviv);
       if(z_k==vlad.stop)
	{
	 for(i=0;i<11;i++)
	  {
	   gotoxy(2,i+2);
	   cprintf("%s",line3);
	  }
	 per_kat=0;
	 init_katal();
	 if(vlad.stop!=0)
	   {
	     read_katalog();
	     mov_init();
	   }
	}
       else
	{
	  textbackground(BLUE);
	  gotoxy(2,m_k);
	  cprintf("          ");
	  if(z_k>=10)
	   (*vviv)[z_k-12+m_k];
	  else
	   (*vviv)[m_k-2];
	  strncpy(name_katalog[m_k-2],vlad.nametom+1,11);
	  textbackground(COLMEN);
	  gotoxy(2,m_k);
	  cprintf("%s",name_katalog[m_k-2]);
	}
       textcolor(0);
       gotoxy(64,7);
      }
    }
     else
      {
       textcolor(0);
       gotoxy(64,7);
      }
 }



/******Войти во внутрь каталога******/

/******Инициализация имен внутри каталога******/
void dn_name_kat(void)
  {
   char dop_2[2]="";
   int z;

   strncpy(dop_2,"",1);
   if(z_k>=10)
     (*vviv)[z_k-12+m_k];
   else
     (*vviv)[m_k-2];
   z_men=10;
   strncpy(dop_2,vlad.nametom,1);
   if(dop_2[0]=='*')
      null_men();
   else
    {
     strcpy(line5,vlad.nametom+1);
     vviv->down();
     if(f_one_exit_3==1)
       for(z=0;z<11;delete name_men[z++]);
     for(z=0;z<11;z++)
       name_men[z]=(char*)mallos(11);
     f_one_exit_3=1;
     for(z=0;z<11;z++)
     {
      if(z>=vlad.stop)
       {
	 f_end_men=z-1;
	 z_men=z-1;
	 break;
       }
      (*vviv)[z];
      strncpy(name_men[z],vlad.namemen+1,11);
     };
    read_men();
    textcolor(WHITE);
    textbackground(COLMEN);
    gotoxy(2,2);
    cprintf("%s",name_men[0]);
    textcolor(0);
    m_m=2;

   }
  }

/******Чтение имен внутри каталога******/
 void read_men(void)
  {
   int k=11,z;
   textbackground(9);
   textcolor(WHITE);
   if(z_men==0)
     k=1;
   if(f_end_men!=0)
     k=f_end_men+1;
   gotoxy(2,1);
   for(z=0;z<k;z++)
    {
      gotoxy(2,wherey()+1);
      cprintf("%s",name_men[z]);
    }
   textcolor(0);
  }

/******Передвижение по именам клиентов вверх******/
 void move_men_men(void)
  {
   int z;
   if(z_men==0)
       z=f_end_men;
   else
    {
     if(f_end_men!=0)
       z=f_end_men;
     else
       z=10;
    }
     if(m_m>=12)
      {
       inc_men();
      }
     if(m_m==0||z_men==0)
      {
       m_m=2;
       textcolor(WHITE);
       textbackground(COLMEN);
       gotoxy(2,m_m);
       cprintf("%s",name_men[m_m-2]);
       textcolor(0);
       gotoxy(64,4);
      }
     else
      {
       if(m_m!=z+2)
	{
	 mov_men();
	 gotoxy(64,4);
	}
      }
  }

void mov_men(void)
  {
    textcolor(WHITE);
    textbackground(COLMEN);
    gotoxy(2,m_m+1);
    cprintf("%s",name_men[m_m-1]);
    gotoxy(2,m_m);
    textbackground(BLUE);
    cprintf("%s",name_men[m_m-2]);
    m_m++;
    textcolor(0);
  }

/******Изменение клиентов******/
void inc_men(void)
  {
   int z;
   z_men++;
   if(z_men<vlad.stop)
    {
      for(z=0;z<10;z++)
       {
	 strncpy(name_men[z],name_men[z+1],11);
       }
      (*vviv)[z_men];
      strncpy(name_men[10],vlad.namemen+1,11);

      init_two_men();
      textbackground(COLMEN);
      gotoxy(2,12);
      cprintf("%s",name_men[10]);
      gotoxy(64,4);
      textcolor(0);
    }
   else
    z_men--;
  }

void init_two_men(void)
  {
   int z;
   textbackground(9);
   textcolor(WHITE);
   gotoxy(2,1);
   for(z=0;z<11;z++)
    {
      gotoxy(2,wherey()+1);
      cprintf("%s",line3);
    }
   gotoxy(2,1);
   for(z=0;z<11;z++)
    {
      gotoxy(2,wherey()+1);
      cprintf("%s",name_men[z]);
    }
  }

/******Передвижение по клиентам каталогов вниз******/
void move_men_dn(void)
  {
   if(m_m==2&&z_men>10)
    {
     dec_men();
    }
   if(m_m!=2)
    {
     textcolor(WHITE);
     textbackground(COLMEN);
     gotoxy(2,m_m-1);
     cprintf("%s",name_men[m_m-3]);
     gotoxy(2,m_m);
     textbackground(BLUE);
     cprintf("%s",name_men[m_m-2]);
     m_m--;
     gotoxy(64,5);
     textcolor(0);
    }
  }

void dec_men(void)
  {
   int z;
   if(z_men>10)
    {
      z_men--;
      for(z=9;z>=0;z--)
       {
	 strncpy(name_men[z+1],name_men[z],11);
       }
      (*vviv)[z_men-10];
      strncpy(name_men[0],vlad.namemen+1,11);
    }
   init_two_men();
   textbackground(COLMEN);
   gotoxy(2,2);
   cprintf("%s",name_men[0]);
   gotoxy(64,5);
   textcolor(0);
  }

/******Добавление клиента******/
void inc_name_men(void)
  {
   int z;

   vv();
   if(strcmp(dop,"")!=0)
     {
      if(f_exit==1)
       {
	if(z_k>=10)
	 (*vviv)[z_k-12+m_k];
	else
	 (*vviv)[m_k-2];
	vviv->down();
	for(z=0;z<11;z++)
	 name_men[z]=(char*)mallos(11);
	f_exit=0;
       }
       ++(*vviv);
       (*vviv)[vlad.stop-1];
       strncpy(vlad.namemen+1,dop,11);
       strncpy(line5,vlad.nametom+1,11);
       vviv->save();
       if(f_end_men<10)
	 {
	   f_end_men++;
	   z_men++;
	   strncpy(name_men[f_end_men],dop,11);
	   textcolor(WHITE);
	   textbackground(BLUE);
	   gotoxy(2,f_end_men+2);
	   cprintf("%s",name_men[f_end_men]);
	   textcolor(0);
	 }
     }
   textcolor(0);
   gotoxy(64,8);
 }

/******Если внутри каталога пусто******/
void null_men(void)
  {
    char dop_1;

    massege10();
    dop_1=getch();
    textbackground(BLUE);
    clrscr();
    window(1,1,80,25);
    if(dop_1=='y'||dop_1=='Y'||dop_1=='н'||dop_1=='Н')
      {
       f_end_men=-1;
       z_men=-1;
       f_end_men_1=1;
       f_exit=1;
       inc_name_men();
       if(strcmp(dop,"")!=0)
	 {
	   textcolor(WHITE);
	   textbackground(COLMEN);
	   gotoxy(2,2);
	   cprintf("%s",name_men[0]);
	   m_m=2;
	 }
       else
	 {
	   strcpy(line5,"");
	   f_exit=0;
	   menu4_0();
	   if(wind==1)
	     {
	      read_katalog();
	      textcolor(WHITE);
	      textbackground(COLMEN);
	      gotoxy(2,m_k);
	      cprintf("%s",name_katalog[m_k-2]);
	      textcolor(0);
	     }
	   wind--;
	   textcolor(0);
	 }
      }
    else
      {
       strcpy(line5,"");
       menu4_0();
       if(wind==1||wind==6)
	{
	  read_katalog();
	  textcolor(WHITE);
	  textbackground(COLMEN);
	  gotoxy(2,m_k);
	  cprintf("%s",name_katalog[m_k-2]);
	  textcolor(0);
	}
       wind--;
       textcolor(0);
      }
    textcolor(0);
  }

/******Редоктирование имен в каталоге******/
void redoctir_name_men(void)
  {
   vv();
   if(strcmp(dop,"")!=0)
    {
     if(z_men>=10)
       (*vviv)[z_men-12+m_m];
     else
       (*vviv)[m_m-2];
     strncpy(vlad.namemen+1,dop,11);
     vviv->save();
     strncpy(name_men[m_m-2],dop,11);
     textbackground(BLUE);
     gotoxy(2,m_m);
     cprintf("           ");
     textcolor(WHITE);
     textbackground(COLMEN);
     gotoxy(2,m_m);
     cprintf("%s",name_men[m_m-2]);
    }
   textcolor(0);
   gotoxy(64,9);
 }

/******Удаление клиентов******/
void delete_men(void)
 {
   char dop_1;
   char dop_2[2]="";
   int i;

   massege8();
   dop_1=getch();
   textbackground(BLUE);
   clrscr();
   window(1,1,80,25);
   if(dop_1=='y'||dop_1=='Y'||dop_1=='н'||dop_1=='Н')
    {
     if(z_men>=10)
       (*vviv)[z_men-12+m_m];
     else
       (*vviv)[m_m-2];
     strncpy(dop_2,vlad.namemen,1);
     if(dop_2[0]!='*')
      {
	massege9();

	textcolor(0);
	gotoxy(64,7);
      }
     else
      {
       if(z_men>=10)
	 (*vviv)[z_men-12+m_m];
       else
	 (*vviv)[m_m-2];
       --(*vviv);
       if(z_men==vlad.stop)
	{
	 for(i=0;i<11;i++)
	  {
	   gotoxy(2,i+2);
	   cprintf("%s",line3);
	  }
	 vviv->up();
	 dn_name_kat();
	 if(wind==1)
	  {
	   read_katalog();
	   textcolor(WHITE);
	   textbackground(COLMEN);
	   gotoxy(2,m_k);
	   cprintf("%s",name_katalog[m_k-2]);
	   textcolor(0);
	   menu_down();
	  }
         else
         gotoxy(64,7);
	}
       else
	{
	  textbackground(BLUE);
	  gotoxy(2,m_m);
	  cprintf("          ");
	  if(z_men>=10)
	   (*vviv)[z_men-12+m_m];
	  else
	   (*vviv)[m_m-2];
	  strncpy(name_men[m_m-2],vlad.namemen+1,11);
	  textbackground(COLMEN);
	  gotoxy(2,m_m);
	  cprintf("%s",name_men[m_m-2]);
	  gotoxy(64,7);
	}
       textcolor(0);

      }
    }
  else
    {
     textcolor(0);
     gotoxy(64,7);
    }
 }




/******Войти в базу качеств******/

/******Инициализация имен качеств******/
void init_name_kach(void)
 {
   char dop_1;
   int z;


   if(f_one_exit_4==1)
     for(z=0;z<11;delete name_kach[z++]);
   f_one_exit_4=1;
   for(z=0;z<11;z++)
     name_kach[z]=(char*)mallos(11);
   if(vlad.stop!=0)
     {
      z_kach=10;
      for(z=0;z<11;z++)
	{
	 if(z>=vlad.stop)
	  {
	   f_end_kach=z-1;
	   z_kach=z-1;
	   break;
	  }
	 vviv->set(tKat1);
	 (*vviv)[z];
	 strncpy(name_kach[z],vlad.namequllity+1,11);
	}
      read_kach();
      textcolor(WHITE);
      textbackground(COLMEN);
      gotoxy(2,2);
      cprintf("%s",name_kach[0]);
      textcolor(0);
      m_kach=2;
     }
   else
     {
       massege11();
       dop_1=getch();
       textbackground(BLUE);
       clrscr();
       window(1,1,80,25);
       if(dop_1=='y'||dop_1=='Y'||dop_1=='н'||dop_1=='Н')
	 {
	  inc_name_kach();
	  textcolor(0);
	 }
       else
	 {
	  textcolor(0);
	 }
     }
 }

/******Чтение имен какачеств******/
void read_kach(void)
  {
   int k=11,z;

   textbackground(9);
   textcolor(WHITE);
   if(z_kach==0)
     k=1;
   if(f_end_kach!=0)
     k=f_end_kach+1;
   gotoxy(2,1);
   for(z=0;z<k;z++)
    {
      gotoxy(2,wherey()+1);
      cprintf("%s",name_kach[z]);
    }
   textcolor(0);
  }



/******Передвижение по именам качеств вверх******/
 void move_kach(void)
  {
     int z;

     if(f_end_kach!=0)
       z=f_end_kach;
     else
       z=10;
     if(m_kach>=12)
      {
       inc_kach();
      }
     if(m_kach!=z+2&&z_kach!=0)
      {
       mov_kach();
       gotoxy(64,4);
      }
  }

void mov_init_kach(void)
  {
     if(per_kach!=10)
      {
       textcolor(WHITE);
       textbackground(COLMEN);
       gotoxy(2,2);
       cprintf("%s",name_kach[0]);
       per_kach=10;
       gotoxy(64,4);
       textcolor(0);
       m_kach=2;
      }
     else
      {
       textcolor(WHITE);
       textbackground(COLMEN);
       gotoxy(2,m_kach);
       cprintf("%s",name_kach[m_kach-2]);
       gotoxy(64,4);
       textcolor(0);
      }
  }

void mov_kach(void)
  {
    textcolor(WHITE);
    textbackground(COLMEN);
    gotoxy(2,m_kach+1);
    cprintf("%s",name_kach[m_kach-1]);
    gotoxy(2,m_kach);
    textbackground(BLUE);
    cprintf("%s",name_kach[m_kach-2]);
    m_kach++;
    textcolor(0);
  }

/******Передвижение по именам качеств вниз******/
void move_kach_dn(void)
  {
   if(m_kach==2&&z_kach>10)
    {
     dec_kach();
    }
   if(m_kach!=2)
    {
     textcolor(WHITE);
     textbackground(COLMEN);
     gotoxy(2,m_kach-1);
     cprintf("%s",name_kach[m_kach-3]);
     gotoxy(2,m_kach);
     textbackground(BLUE);
     cprintf("%s",name_kach[m_kach-2]);
     m_kach--;
     gotoxy(64,5);
     textcolor(0);
    }
  }

/******Изменение качества******/
void inc_kach(void)
  {
   int z;
   z_kach++;
   if(z_kach<vlad.stop)
    {
      for(z=0;z<10;z++)
       {
	 strncpy(name_kach[z],name_kach[z+1],11);
       }
      (*vviv)[z_kach];
      strncpy(name_kach[10],vlad.namequllity+1,11);

      init_two_kach();
      textbackground(COLMEN);
      gotoxy(2,12);
      cprintf("%s",name_kach[10]);
      gotoxy(64,4);
      textcolor(0);
    }
   else
    z_kach--;
  }

void dec_kach(void)
  {
   int z;
   if(z_kach>10)
    {
      z_kach--;
      for(z=9;z>=0;z--)
       {
	 strncpy(name_kach[z+1],name_kach[z],11);
       }
      (*vviv)[z_kach-10];
      strncpy(name_kach[0],vlad.namequllity+1,11);
    }
   init_two_kach();
   textbackground(COLMEN);
   gotoxy(2,2);
   cprintf("%s",name_kach[0]);
   gotoxy(64,5);
   textcolor(0);
  }

void init_two_kach(void)
  {
   int z;

   textbackground(9);
   textcolor(WHITE);
   gotoxy(2,1);
   for(z=0;z<11;z++)
    {
      gotoxy(2,wherey()+1);
      cprintf("%s",line3);
    }
   gotoxy(2,1);
   for(z=0;z<11;z++)
    {
      gotoxy(2,wherey()+1);
      cprintf("%s",name_kach[z]);
    }
  }

/******Добавление качества******/
void inc_name_kach(void)
  {
   vv();
   if(strcmp(dop,"")!=0)
    {
     if(vlad.stop==0)
       {
	  f_end_kach=-1;
	  z_kach=-1;
	  m_kach=2;
       }
     ++(*vviv);
     (*vviv)[vlad.stop-1];
     strncpy(vlad.namequllity+1,dop,11);
     vviv->save();
     if(z_kach<10)
      {
       f_end_kach++;
       z_kach++;
       strncpy(name_kach[f_end_kach],dop,11);
       textcolor(WHITE);
       textbackground(BLUE);
       if(vlad.stop==1)
	 textbackground(COLMEN);
       gotoxy(2,f_end_kach+2);
       cprintf("%s",name_kach[f_end_kach]);
      }
    }
   textcolor(0);
   gotoxy(64,8);
 }

/******Удаление качества******/
void delete_kach(void)
 {
   char dop_1;
   char dop_2[2]="";
   int i;

   massege8();
   dop_1=getch();
   textbackground(BLUE);
   clrscr();
   window(1,1,80,25);
   if(dop_1=='y'||dop_1=='Y'||dop_1=='н'||dop_1=='Н')
    {
     if(z_kach>=10)
       (*vviv)[z_kach-12+m_kach];
     else
       (*vviv)[m_kach-2];
     strncpy(dop_2,vlad.namequllity,1);
     if(dop_2[0]!='*')
      {
	massege9();
	gotoxy(64,7);
	textcolor(0);
      }
     else
      {
       if(z_kach>=10)
	 (*vviv)[z_kach-12+m_kach];
       else
	 (*vviv)[m_kach-2];
       --(*vviv);
       if(z_kach==vlad.stop)
	{
	 for(i=0;i<11;i++)
	  {
	   gotoxy(2,i+2);
	   cprintf("%s",line3);
	  }
	 per_kach=0;
	 init_name_kach();
	 if(vlad.stop!=0)
	   {
	     read_kach();
	     mov_init_kach();
	   }
	}
       else
	{
	  textbackground(BLUE);
	  gotoxy(2,m_kach);
	  cprintf("          ");
	  if(z_kach>=10)
	   (*vviv)[z_kach-12+m_kach];
	  else
	   (*vviv)[m_kach-2];
	  strncpy(name_kach[m_kach-2],vlad.namequllity+1,11);
	  textbackground(COLMEN);
	  gotoxy(2,m_kach);
	  cprintf("%s",name_kach[m_kach-2]);
	}
       textcolor(0);
       gotoxy(64,7);
      }
    }
     else
      {
       textcolor(0);
       gotoxy(64,7);
      }
 }

/******Редоктирование качества******/
void redoctir_name_kach(void)
  {
   vv();
   if(strcmp(dop,"")!=0)
    {
     if(z_kach>=10)
       (*vviv)[z_kach-12+m_kach];
     else
       (*vviv)[m_kach-2];
     strncpy(vlad.namequllity+1,dop,11);
     vviv->save();
     strncpy(name_kach[m_kach-2],dop,11);
     textbackground(BLUE);
     gotoxy(2,m_kach);
     cprintf("           ");
     textcolor(WHITE);
     textbackground(COLMEN);
     gotoxy(2,m_kach);
     cprintf("%s",name_kach[m_kach-2]);
    }
   textcolor(0);
   gotoxy(64,9);
 }


/******Войти во внутрь качества******/

/******Инициализация имен внутри качества******/
void dn_name_kach(void)
  {
   char dop_2[2]="";
   int z;

   if(z_kach>=10)
     (*vviv)[z_kach-12+m_kach];
   else
     (*vviv)[m_kach-2];
   z_qullity=10;
   strncpy(dop_2,vlad.namequllity,1);
   if(dop_2[0]=='*')
    null_qullity();
   else
    {
     wind=5;

     vviv->down();
     if(f_one_exit_5==1)
      {
       for(z=0;z<11;delete name_qullity[z++]);
       delete netto_kach;
      }
     for(z=0;z<11;z++)
       name_qullity[z]=(char*)mallos(49);
     netto_kach=(int*)mallos(20);
     f_one_exit_5=1;
     f_end_qullity=0;
     for(z=0;z<11;z++)
     {
      if(z>=vlad.stop||z==11)
       {
	 f_end_qullity=z-1;
	 z_qullity=z-1;
	 break;
       }
      (*vviv)[z];
      strncpy(name_qullity[z],vlad.qullity+1,49);
      *(netto_kach+z)=(int)vlad.weigtqullity;
     };
    read_qullity();
    textcolor(WHITE);
    textbackground(COLMEN);
    gotoxy(15,2);
    cprintf("%s",name_qullity[0]);
    textcolor(0);
    m_q=2;

   }
  }

/******Чтение имен внутри каталога качества******/
 void read_qullity(void)
  {
   int k=11,z;
   textbackground(9);
   textcolor(WHITE);
   if(z_qullity==0)
     k=1;
   if(f_end_qullity!=0)
     k=f_end_qullity+1;
   gotoxy(15,1);
   for(z=0;z<k;z++)
    {
      gotoxy(15,wherey()+1);
      cprintf("%s",name_qullity[z]);
      gotoxy(60,wherey());
      cprintf("%d",*(netto_kach+z));
    }
   textcolor(0);
  }

/******Если внутри каталога пусто******/
void null_qullity(void)
  {
    char dop_1;

    massege10();

    dop_1=getch();
    textbackground(BLUE);
    clrscr();
    window(1,1,80,25);
    if(dop_1=='y'||dop_1=='Y'||dop_1=='н'||dop_1=='Н')
      {
       f_end_qullity=-1;
       z_qullity=-1;
       f_end_qullity_1=1;
       f_exit_qullity=1;
       inc_name_qullity();

       if(strcmp(dop_10,"")!=0)
	 {
	   m_q=0;
	   if(m_q==0)
	     {
	       m_q=2;
	       textcolor(WHITE);
	       textbackground(COLMEN);
	       gotoxy(15,m_q);
	       cprintf("%s",name_qullity[m_q-2]);
	       textcolor(0);
	     };
	   wind=5;
	 }
       else
	 {
	   f_exit_qullity=0;
 /*управлять экраном */
	   wind=4;
	   textcolor(0);
	   menu_down();
	 }
      }
    else
      {
       wind=4;
       textcolor(0);
       menu_down();
      }
    textcolor(0);
  }

/******Добавление качества******/
void inc_name_qullity(void)
  {
   int z;

   vv_1();
   if(strcmp(dop_10,"")!=0)
     {
      if(f_exit_qullity==1)
       {
	if(z_kach>=10)
	 (*vviv)[z_kach-12+m_kach];
	else
	 (*vviv)[m_kach-2];
	vviv->down();
	for(z=0;z<11;z++)
	 name_qullity[z]=(char*)mallos(49);
	f_exit_qullity=0;
       }
       ++(*vviv);
       (*vviv)[vlad.stop-1];
       strncpy(vlad.qullity+1,dop_10,49);
       vviv->save();
       if((f_end_qullity<10||f_end_qullity==0)&&z_qullity<10)
	 {
	   f_end_qullity++;
	   z_qullity++;
	   strncpy(name_qullity[f_end_qullity],dop_10,49);
	   *(netto_kach+f_end_qullity)=0;
	   textcolor(WHITE);
	   textbackground(BLUE);
	   gotoxy(15,f_end_qullity+2);
	   cprintf("%s",name_qullity[f_end_qullity]);
	   gotoxy(60,f_end_qullity+2);
	   cprintf("%d",*(netto_kach+f_end_qullity));
	 }
     }
   textcolor(0);
   gotoxy(64,7);
 }




/******Передвижение по именам качеств вверх******/
 void move_men_qullity(void)
  {
   int z;

   if(z_qullity==0)
       z=f_end_qullity;
   else
    {
     if(f_end_qullity!=0)
       z=f_end_qullity;
     else
       z=10;
    }
     if(m_q>=12)
      {
       inc_qullity();
      }
     if(m_q==0||z_qullity==0)
      {
       m_q=2;
       textcolor(WHITE);
       textbackground(COLMEN);
       gotoxy(15,m_q);
       cprintf("%s",name_qullity[m_q-2]);
       textcolor(0);
       gotoxy(64,4);
      }
     else
      {
       if(m_q!=z+2)
	{
	 mov_qullity();
	 gotoxy(64,4);
	}
      }
  }

void mov_qullity(void)
  {
    textcolor(WHITE);
    textbackground(COLMEN);
    gotoxy(15,m_q+1);
    cprintf("%s",name_qullity[m_q-1]);
    gotoxy(15,m_q);
    textbackground(BLUE);
    cprintf("%s",name_qullity[m_q-2]);
    m_q++;
    textcolor(0);
  }

/******Изменение качества******/
void inc_qullity(void)
  {
   int z;
   z_qullity++;
   if(z_qullity<vlad.stop)
    {
      for(z=0;z<10;z++)
       {
	 strncpy(name_qullity[z],name_qullity[z+1],49);
	 *(netto_kach+z)=*(netto_kach+z+1);
       }
      (*vviv)[z_qullity];
      strncpy(name_qullity[10],vlad.qullity+1,49);
      *(netto_kach+10)=(int)vlad.weigtqullity;
      init_two_qullity();
      textbackground(COLMEN);
      gotoxy(15,12);
      cprintf("%s",name_qullity[10]);
      gotoxy(64,4);
      textcolor(0);
    }
   else
    z_qullity--;
  }

void init_two_qullity(void)
  {
   int z;

   textbackground(9);
   textcolor(WHITE);
   gotoxy(15,1);
   for(z=0;z<11;z++)
    {
      gotoxy(15,wherey()+1);
      cprintf("%s",line4);
    }
   gotoxy(15,1);
   for(z=0;z<11;z++)
    {
      gotoxy(15,wherey()+1);
      cprintf("%s",name_qullity[z]);
      gotoxy(60,wherey());
      cprintf("%d",*(netto_kach+z));
    }
  }

/******Передвижение по качествам вниз******/
void move_qullity_dn(void)
  {
   if(m_q==2&&z_qullity>10)
    {
     dec_qullity();
    }
   if(m_q!=2)
    {
     textcolor(WHITE);
     textbackground(COLMEN);
     gotoxy(15,m_q-1);
     cprintf("%s",name_qullity[m_q-3]);
     gotoxy(15,m_q);
     textbackground(BLUE);
     cprintf("%s",name_qullity[m_q-2]);
     m_q--;
     gotoxy(64,5);
     textcolor(0);
    }
  }

void dec_qullity(void)
  {
   int z;
   if(z_qullity>10)
    {
      z_qullity--;
      for(z=9;z>=0;z--)
       {
	 strncpy(name_qullity[z+1],name_qullity[z],49);
	 *(netto_kach+z+1)=*(netto_kach+z);
       }
      (*vviv)[z_qullity-10];
      strncpy(name_qullity[0],vlad.qullity+1,49);
      *netto_kach=(int)vlad.weigtqullity;
    }
   init_two_qullity();
   textbackground(COLMEN);
   gotoxy(15,2);
   cprintf("%s",name_qullity[0]);
   gotoxy(64,5);
   textcolor(0);
  }

/******Редоктирование качества******/
void redoctir_name_qullity(void)
  {
   vv_1();
   if(strcmp(dop_10,"")!=0)
    {
     if(z_qullity>=10)
       (*vviv)[z_qullity-12+m_q];
     else
       (*vviv)[m_q-2];
     strncpy(vlad.qullity+1,dop_10,49);
     vviv->save();
     strncpy(name_qullity[m_q-2],dop_10,49);
     textbackground(BLUE);
     gotoxy(15,m_q);
     cprintf("%s",line4);
     textcolor(WHITE);
     textbackground(COLMEN);
     gotoxy(15,m_q);
     cprintf("%s",name_qullity[m_q-2]);
     textbackground(BLUE);
     gotoxy(60,m_q);
     cprintf("%d",netto_kach[m_q-2]);
    }
   textcolor(0);
   gotoxy(64,8);
 }

/******Удаление имен качеств******/
void delete_qullity(void)
 {
   char dop_1;
   char dop_2[2]="";
   int i,z;

   massege15();
   dop_1=getch();
   textbackground(BLUE);
   clrscr();
   window(1,1,80,25);
   if(dop_1=='y'||dop_1=='Y'||dop_1=='н'||dop_1=='Н')
    {
     if(z_qullity>=10)
      {
       (*vviv)[z_qullity-12+m_q];
       z=z_qullity-12+m_q;
      }
     else
      {
       (*vviv)[m_q-2];
       z=m_q-2;
      }
     strncpy(dop_2,vlad.qullity,1);
     if(z!=vlad.stop-1)
      {
	massege16();

	textcolor(0);
	gotoxy(64,6);
      }
     else
      {
      if(dop_2[0]!='*')
       {
	massege9();

	textcolor(0);
	gotoxy(64,6);
       }
      else
       {
       if(z_qullity>=10)
	 (*vviv)[z_qullity-12+m_q];
       else
	 (*vviv)[m_q-2];
       --(*vviv);
       if(z_qullity==vlad.stop)
	{
	 for(i=0;i<11;i++)
	  {
	   gotoxy(15,i+2);
	   cprintf("%s",line4);
	  }
	 vviv->up();
	 dn_name_kach();
	 if(strncmp(vlad.namequllity,"*",1)==0)
	   gotoxy(64,3);
	 else
	   gotoxy(64,6);
/*	 if(vlad.stop==1)
	  gotoxy(64,6);*/
	}
       else
	{
	  textbackground(BLUE);
	  gotoxy(15,m_q);
	  cprintf("%s",line4);
	  if(z_qullity>=10)
	   (*vviv)[z_qullity-12+m_q];
	  else
	   (*vviv)[m_q-2];
	  strncpy(name_qullity[m_q-2],vlad.qullity+1,49);
	  textbackground(COLMEN);
	  gotoxy(15,m_q);
	  cprintf("%s",name_qullity[m_q-2]);
	  gotoxy(64,7);
	}
       textcolor(0);

       }
      }
    }
  else
    {
     textcolor(0);
     gotoxy(64,6);
    }
 }

/******Выделение качества для данного клиента******/

void mark_xar(void)
 {
  if(per_k==1)
   {
   if(z_kach>=10)
      (*vviv)[z_kach-12+m_kach];
    else
      (*vviv)[m_kach-2];

    strncpy(dop_0,vlad.namequllity+1,11);
/*******************************************************/
    vviv->mark1();
    textbackground(COLMEN);
    gotoxy(13,m_kach);
    cprintf("+");
    f_save=1;
    strcpy(dop_20,"");
    strcpy(dop_10,"");
   }
  else
   {
    massege12();

    textcolor(0);
   }
  gotoxy(64,10);
 }

/******Выделение внутри качества характеристики клиента******/

void mark_xar_xar(void)
 {

  strcpy(dop_10,"");

  if(per_k==1)
   {
    if(f_save==1)
     {
      if(z_qullity>=10)
	(*vviv)[z_qullity-12+m_q];
      else
	(*vviv)[m_q-2];
      vviv->mark3();
      strncpy(dop_10,vlad.qullity+1,49);
/*******************************************************/
      textbackground(COLMEN);
      gotoxy(62,m_q);
      cprintf("+");
      f_save_1=1;
     }
    else
     {
      massege20();
      textcolor(0);
     }
   }
  else
   {
    massege12();
    textcolor(0);
   }
  gotoxy(64,9);
 }

/******Выделение внутри качества требования клиента******/

void mark_treb(void)
 {
  int nam;

  strcpy(dop_20,"");

  if(per_k==1)
   {
    if(f_save==1)
     {
     if(z_qullity>=10)
	(*vviv)[z_qullity-12+m_q];
       else
	(*vviv)[m_q-2];
       vviv->mark2();
       strncpy(dop_20,vlad.qullity+1,49);
/*******************************************************/
       textbackground(COLMEN);
       gotoxy(62,m_q);
       cprintf("+");
       help2();

       massege17();

       scanf("%d",&nam);
       vlad.others=nam;
       while(nam>3||nam<-1)
	{
	  clrscr();
	  gotoxy(1,1);
	  scanf("%d",&nam);
	  vlad.others=nam;
	}
       window(22,14,54,21);
       textbackground(BLUE);
       clrscr();
       window(1,1,80,25);

       textbackground(COLMEN);
       clr_help2();

       dop_nam=nam;
/***********************************************/
       textbackground(COLMEN);
       textcolor(0);
       help1();
       if(nam!=-1)
	 {
	  if(nam==0||nam==1)
	      massege18();
	  else
	      massege19();

	  scanf("%d",&nam);
	  vlad.weigt=(long)nam;
	  while(nam>100||nam<0)
	    {
	     clrscr();
	     gotoxy(1,1);
	     scanf("%d",&nam);
	     vlad.weigt=(long)nam;
	   }
	  dop_nam_1=nam;
	  window(22,14,54,21);
	  textbackground(BLUE);
	  clrscr();
	  window(1,1,80,25);
	  textbackground(COLMEN);
	  clr_help1();

	 }
/**********************************************/

       textcolor(0);
       f_save_1=1;
     }
    else
     {
       massege20();
       textcolor(0);
     }
   }
  else
   {
    massege12();
    textcolor(0);
   }
  gotoxy(64,10);
 }



/***** Просмотр требований и характеристик *****/

/*****Вход в просмотр требований и характеристик*****/
void kact_treb(void)
 {
   int z;

  kact_treb_dop();

  if(vlad.stop!=0)
    {
      m_k_t=2;
      z_kach_d=9;
      z_qullity_d=9;
      z_treb=9;

      for(z=0;z<10;z++)
	{
	 if(z>=vlad.stop)
	  {
	   f_end_kach_d=z-1;
	   z_kach_d=z-1;
	   f_end_qullity_d=z-1;
	   z_qullity_d=z-1;
	   f_end_treb=z-1;
	   z_treb=z-1;
	   break;
	  }
	 (*vviv)[z].ini();
	 strncpy(name_kach_d[z],vlad.inifile,11);
	 strncpy(name_qullity_d[z],vlad.inixar,49);
	 strncpy(name_treb[z],vlad.initreb,49);
	 *(netto_treb+z)=(int)vlad.others;
	}
      read_kach_1();
      read_qullity_1();
      read_treb();
      textbackground(COLMEN);
      textcolor(WHITE);
      gotoxy(2,2);
      cprintf("%s",name_kach_d[0]);
      gotoxy(2,14);
      cprintf("%s",name_kach_d[0]);
      textbackground(BLUE);
      textcolor(0);

      vviv->kat();
      f_tr_xar=1;
    }
 }

void dlina(void)
 {
   line5[strcspn(line5," ")]=0;
   gotoxy(15,1);
   cprintf("%s",line5);
 }

void kact_treb_dop(void)
 {
  int z;

 vviv->set(tMain);
 if(z_men>=10)
     (*vviv)[z_men-12+m_m];
   else
     (*vviv)[m_m-2];
  vviv->set(tWork);  /*down();*/
  textbackground(COLMEN);
  if(flag_ramka==0)
    {
     strncat(line5," ",1);
     strncat(line5,vlad.namemen+1,11);
     flag_ramka=1;
    }
  gotoxy(15,1);
  cprintf("%s",line5);
  textbackground(BLUE);

  if(f_one_exit_4d==1)
   {
     for(z=0;z<11;delete name_kach_d[z++]);
     delete netto_treb;
   }
  netto_treb=(int*)mallos(20);
  f_one_exit_4d=1;
  for(z=0;z<11;z++)
    name_kach_d[z]=(char*)mallos(11);
  z_kach_d=0;

  if(f_one_exit_5d==1)
    for(z=0;z<11;delete name_qullity_d[z++]);
  for(z=0;z<11;z++)
    name_qullity_d[z]=(char*)mallos(49);
  f_one_exit_5d=1;
  z_qullity_d=0;

  if(f_one_exit_6==1)
    for(z=0;z<11;delete name_treb[z++]);
  for(z=0;z<11;z++)
    name_treb[z]=(char*)mallos(49);
  f_one_exit_6=1;
  z_treb=0;
  f_end_kach_d=0;
  f_end_qullity_d=0;
  f_end_treb=0;
  m_k_t=0;
 }

/* Вывод качеств, требований, характеристик*/
void kach_treb_xar(void)
 {
   read_kach_1();
   read_qullity_1();
   read_treb();
   gotoxy(64,3);
 }

/*Сохранить измененные данные*/
void save_kact(void)
 {
  int z;

  if(f_save==1&&f_save_1==1)
   {
     vviv->kat();
     ++(*vviv);
     (*vviv)[vlad.stop-1];
     vlad.others=(long)dop_nam;
     vlad.weigt=(long)dop_nam_1;
     dop_nam=-1;
     dop_nam_1=0;
     vviv->save();
     f_save=0;
     f_save_1=0;
     textbackground(BLUE);
     gotoxy(13,m_kach);
     cprintf(" ");
     gotoxy(64,11);

     if(vlad.stop==1)
       {
	 if(f_one_exit_4d==1)
	  {
	   for(z=0;z<11;delete name_kach_d[z++]);
	   delete netto_treb;
	  }
	 f_one_exit_4d=1;
	 for(z=0;z<11;z++)
	   name_kach_d[z]=(char*)mallos(11);
	   netto_treb=(int*)mallos(20);
	 z_kach_d=-1;

	 if(f_one_exit_5d==1)
	   for(z=0;z<11;delete name_qullity_d[z++]);
	 for(z=0;z<11;z++)
	   name_qullity_d[z]=(char*)mallos(49);
	 f_one_exit_5d=1;
	 z_qullity_d=-1;

	 if(f_one_exit_6==1)
	   for(z=0;z<11;delete name_treb[z++]);
	 for(z=0;z<11;z++)
	   name_treb[z]=(char*)mallos(49);
	 f_one_exit_6=1;
	 z_treb=-1;
	 f_end_kach_d=-1;
	 f_end_qullity_d=-1;
	 f_end_treb=-1;
      }

     vviv->kat();
     if(z_kach_d<9||vlad.stop==1)
      {
       f_end_kach_d++;
       z_kach_d++;
       strncpy(name_kach_d[f_end_kach_d],dop_0,11);
       f_end_qullity_d++;
       z_qullity_d++;
       if(strcmp(dop_10,"")!=0)
	 strncpy(name_qullity_d[f_end_qullity_d],dop_10,49);
       else
	 strcpy(name_qullity_d[f_end_qullity_d],"<не известно>");
       f_end_treb++;
       z_treb++;
       if(strcmp(dop_20,"")!=0)
	 strncpy(name_treb[f_end_treb],dop_20,49);
       else
	 strcpy(name_treb[f_end_treb],"<не имеет значения>");
       netto_treb[f_end_treb]=(int)vlad.others;
      }
   }
  else
   {
    massege13();

    textcolor(0);
    gotoxy(64,11);
   }
 }


/* Чтение имен качеств внутри клиента */
void read_kach_1(void)
  {
   int k=10,z;

   textbackground(9);
   textcolor(WHITE);
   if(vlad.stop!=0)
    {
     if(z_kach_d==0)
       k=1;
     if(f_end_kach_d!=0)
       k=f_end_kach_d+1;
     gotoxy(2,13);
     for(z=0;z<k;z++)
      {
	gotoxy(2,wherey()+1);
	cprintf("%s",name_kach_d[z]);
	gotoxy(60,wherey());
	if(netto_treb[z]==-1) cprintf("Н");
	else
	 {
	  if(netto_treb[z]==0) cprintf(">");
	  else
	    {
	      if(netto_treb[z]==1) cprintf("<");
	      else
		{
		 if(netto_treb[z]==2) cprintf("В");
		 else cprintf("=");
		}
	    }
	  }
      }
     gotoxy(2,1);
     for(z=0;z<k;z++)
      {
	gotoxy(2,wherey()+1);
	cprintf("%s",name_kach_d[z]);
      }
    }
   textcolor(0);
  }

/******Чтение характеристик внутри клиента******/
 void read_qullity_1(void)
  {
   int k=10,z;
   textbackground(9);
   textcolor(WHITE);
   if(vlad.stop!=0)
     {
      if(z_qullity_d==0)
	k=1;
      if(f_end_qullity_d!=0)
	k=f_end_qullity_d+1;
      gotoxy(15,1);
      for(z=0;z<k;z++)
	{
	 gotoxy(15,wherey()+1);
	 cprintf("%s",name_qullity_d[z]);
	}
     }
   textcolor(0);
  }

/******Чтение требований внутри клиента******/
 void read_treb(void)
  {
   int k=10,z;
   textbackground(9);
   textcolor(WHITE);
   if(vlad.stop!=0)
     {
      if(z_treb==0)
	k=1;
      if(f_end_treb!=0)
	k=f_end_treb+1;
      gotoxy(15,13);
      for(z=0;z<k;z++)
	{
	 gotoxy(15,wherey()+1);
	 cprintf("%s",name_treb[z]);
	}
     }
   textcolor(0);
  }


/* Передвижение по характеристикам и требованиям вниз */
 void move_treb_xar(void)
  {
     int z;

     if(f_end_kach_d!=0)
       z=f_end_kach_d;
     else
       z=9;

     if(m_k_t>=11)
      {
	if(flag_tr_xar==0)
	  vviv->kat();
	vviv->set(tWork);
	if(z_kach_d+1<vlad.stop)
	  inc_kach_d();
	if(flag_tr_xar==0)
	  vviv->kat();
      }
     if(m_k_t!=z+2&&z_kach_d!=0)
      {
       mov_kach_d();
       gotoxy(64,4);
      }
  }

/******Изменение качества******/
void inc_kach_d(void)
  {
   int z;

   z_kach_d++;
   z_qullity_d++;
   z_treb++;
   if(z_kach_d<vlad.stop)
    {
      for(z=0;z<9;z++)
       {
	 strncpy(name_kach_d[z],name_kach_d[z+1],11);
	 strncpy(name_qullity_d[z],name_qullity_d[z+1],49);
	 strncpy(name_treb[z],name_treb[z+1],49);
	 netto_treb[z]=netto_treb[z+1];
       }
      (*vviv)[z_kach_d].ini();
      strncpy(name_kach_d[9],vlad.inifile,11);
      strncpy(name_qullity_d[9],vlad.inixar,49);
      strncpy(name_treb[9],vlad.initreb,49);
      netto_treb[9]=(int)vlad.others;
      clr_tr_xar();

      kach_treb_xar();
      textbackground(COLMEN);
      textcolor(WHITE);
      gotoxy(2,m_k_t);
      cprintf("%s",name_kach_d[m_k_t-2]);
      gotoxy(2,m_k_t+12);
      cprintf("%s",name_kach_d[m_k_t-2]);
      textbackground(BLUE);
      textcolor(0);
      gotoxy(64,4);
    }
   else
    {
      z_kach_d--;
      z_qullity_d--;
      z_treb--;
    }
  }


void mov_kach_d(void)
  {
    textcolor(WHITE);
    textbackground(COLMEN);
    gotoxy(2,m_k_t+1);
    cprintf("%s",name_kach_d[m_k_t-1]);
    gotoxy(2,m_k_t+13);
    cprintf("%s",name_kach_d[m_k_t-1]);
    gotoxy(2,m_k_t);
    textbackground(BLUE);
    cprintf("%s",name_kach_d[m_k_t-2]);
    gotoxy(2,m_k_t+12);
    cprintf("%s",name_kach_d[m_k_t-2]);
    m_k_t++;
    textcolor(0);
  }




/*****Передвижение по характеристикам и требованиям вверх*****/
void move_treb_kach_dn(void)
  {
   if(z_kach_d>=10&&m_k_t==2)
    {
     if(flag_tr_xar==0)
       vviv->kat();
     dec_kach_d();
     if(flag_tr_xar==0)
       vviv->kat();
    }
   if(m_k_t!=2)
    {
     textcolor(WHITE);
     textbackground(COLMEN);
     gotoxy(2,m_k_t-1);
     cprintf("%s",name_kach_d[m_k_t-3]);
     gotoxy(2,m_k_t+11);
     cprintf("%s",name_kach_d[m_k_t-3]);
     gotoxy(2,m_k_t);
     textbackground(BLUE);
     cprintf("%s",name_kach_d[m_k_t-2]);
     gotoxy(2,m_k_t+12);
     cprintf("%s",name_kach_d[m_k_t-2]);
     m_k_t--;
     gotoxy(64,5);
     textcolor(0);
    }
  }




/******Изменение качества******/
void dec_kach_d(void)
  {
   int z;

   if(z_kach_d>9)
    {
      z_kach_d--;
      for(z=8;z>=0;z--)
       {
	 strncpy(name_kach_d[z+1],name_kach_d[z],11);
	 strncpy(name_qullity_d[z+1],name_qullity_d[z],49);
	 strncpy(name_treb[z+1],name_treb[z],49);
	 netto_treb[z+1]=netto_treb[z];
       }
      (*vviv)[z_kach_d-9].ini();
      strncpy(name_kach_d[0],vlad.inifile,11);
      strncpy(name_qullity_d[0],vlad.inixar,49);
      strncpy(name_treb[0],vlad.initreb,49);
      *netto_treb=(int)vlad.others;
    }
   clr_tr_xar();
   kach_treb_xar();
   textbackground(COLMEN);
   textcolor(WHITE);
   gotoxy(2,m_k_t);
   cprintf("%s",name_kach_d[m_k_t-2]);
   gotoxy(2,m_k_t+12);
   cprintf("%s",name_kach_d[m_k_t-2]);
   textbackground(BLUE);
   textcolor(0);
   gotoxy(64,5);
  }

void clr_tr_xar(void)
  {
   int z;

   gotoxy(2,1);
   textbackground(BLUE);
   for(z=0;z<10;z++)
     {
      gotoxy(2,wherey()+1);
      cprintf("%s",line3);
     }
   gotoxy(2,13);
   for(z=0;z<10;z++)
     {
      gotoxy(2,wherey()+1);
      cprintf("%s",line3);
     }
   gotoxy(15,1);
   for(z=0;z<10;z++)
     {
      gotoxy(15,wherey()+1);
      cprintf("%s",line4);
     }
   gotoxy(15,13);
   for(z=0;z<10;z++)
     {
      gotoxy(15,wherey()+1);
      cprintf("%s",line4);
     }
  }


/*****Удаление качеств и требований*****/
void del_k_tr(void)
 {
   char dop_1;

   screen=new (0) Scr(1);

   massege8();
   dop_1=getch();
   textbackground(BLUE);
   clrscr();
   window(1,1,80,25);
   delete screen;
   if(dop_1=='y'||dop_1=='Y'||dop_1=='н'||dop_1=='Н')
    {
      vviv->set(tWork);
      if(z_kach_d>=9)
	(*vviv)[z_kach_d-11+m_k_t];
      else
	(*vviv)[m_k_t-2];
      --(*vviv);
      if(z_kach_d==vlad.stop)
	{
	 vviv->kat();
	 clr_tr_xar();
	 kact_treb();
	}
      else
	{
	  if(z_kach_d>=9)
	    (*vviv)[z_kach_d-11+m_k_t];
	  else
	    (*vviv)[m_k_t-2];

	  (*vviv).ini();
	  strncpy(name_kach_d[m_k_t-2],vlad.inifile,11);
	  strncpy(name_qullity_d[m_k_t-2],vlad.inixar,49);
	  strncpy(name_treb[m_k_t-2],vlad.initreb,49);
	  netto_treb[m_k_t-2]=(int)vlad.others;
	  vviv->kat();
	  textbackground(BLUE);
	  gotoxy(2,m_k_t);
	  cprintf("%s",line3);
	  gotoxy(2,m_k_t+12);
	  cprintf("%s",line3);
	  gotoxy(15,m_k_t);
	  cprintf("%s",line4);
	  gotoxy(15,m_k_t+12);
	  cprintf("%s",line4);

	  textbackground(COLMEN);
	  gotoxy(2,m_k_t);
	  cprintf("%s",name_kach_d[m_k_t-2]);
	  gotoxy(2,m_k_t+12);
	  cprintf("%s",name_kach_d[m_k_t-2]);
	  textbackground(BLUE);
	  gotoxy(15,m_k_t);
	  cprintf("%s",name_qullity_d[m_k_t-2]);
	  gotoxy(15,m_k_t+12);
	  cprintf("%s",name_treb[m_k_t-2]);
	  gotoxy(60,m_k_t+12);
	  if(netto_treb[m_k_t-2]==-1) cprintf("Н");
	  else
	    {
	     if(netto_treb[m_k_t-2]==0) cprintf(">");
	     else
	       {
		if(netto_treb[m_k_t-2]==1) cprintf("<");
		else
		  {
		   if(netto_treb[m_k_t-2]==2) cprintf("В");
		   else cprintf("=");
		  }
	       }
	    }
	}
     textcolor(0);
     gotoxy(64,7);
    }
   else
    {
     textcolor(0);
     gotoxy(64,7);
    }
 }

/*****Ввод весов качеств*****/
void netto(void)
  {
   int nam=0;

   if(per_k==0)
    {
     if(z_qullity>=10)
       (*vviv)[z_qullity-12+m_q];
     else
       (*vviv)[m_q-2];
     textbackground(COLMEN);
     textcolor(0);
     help1();

     massege14();

     scanf("%d",&nam);
     vlad.weigtqullity=nam;
     while(vlad.weigtqullity>100)
       {
	clrscr();
	gotoxy(1,1);
	scanf("%d",&nam);
	vlad.weigtqullity=nam;
       }
     window(22,14,54,21);
     textbackground(BLUE);
     clrscr();
     window(1,1,80,25);

     vviv->save();
     *(netto_kach+m_q-2)=nam;
     textcolor(WHITE);
     gotoxy(60,m_q);
     cprintf("   ");
     gotoxy(60,m_q);
     cprintf("%d",*(netto_kach+m_q-2));
     textcolor(0);
     textbackground(COLMEN);
     clr_help1();
     textbackground(BLUE);
     gotoxy(64,11);
    }
  }




/***** Подготовка данных к работе свахи *****/

/***** Запоминание номера каталога клиента *****/
void  kat_client(void)
 {
   if(z_k>=10)
     n_kat_client=z_k-12+m_k;
   else
     n_kat_client=m_k-2;
   gotoxy(15,m_k);
   textcolor(WHITE);
   textbackground(COLMEN);
   cprintf("* В этом каталоге находится клиент *");
   textcolor(0);
   textbackground(BLUE);
   gotoxy(64,7);
 }

/***** Запоминание номера клиента *****/
void  client(void)
 {
   if(z_men>=10)
     n_client=z_men-12+m_m;
   else
     n_client=m_m-2;
   gotoxy(15,m_m);
   textcolor(WHITE);
   textbackground(COLMEN);
   cprintf("* Клиент *");
   textcolor(0);
   textbackground(BLUE);
   gotoxy(64,6);
 }

/***** Запоминание номера группы *****/
void  group(void)
 {
   if(z_k>=10)
     n_group=z_k-12+m_k;
   else
     n_group=m_k-2;
   gotoxy(15,m_k);
   textcolor(WHITE);
   textbackground(COLMEN);
   cprintf("* Каталог для поиска альтернатив *");
   textcolor(0);
   textbackground(BLUE);
   gotoxy(64,8);
 }

/***** Запуск свахи *****/
void  run_swaha(void)
 {
   char s;
   char otc=1;



   cadit=0;
   gotoxy(20,15);
   if(n_kat_client==-1)
     {
       massege1();
       gotoxy(64,9);
     }
   else
     {
       if(n_group==-1)
	 {
	   massege2();
	   gotoxy(64,9);
	 }
       else
	 {
	   if(n_client==-1)
	     {
	       massege3();
	       gotoxy(64,9);
	     }
	   else
	     {
	       massege5();

	       s=getch();
	       if(s=='y'||s=='Y'||s=='н'||s=='Н')
		 otc=2;
	       window(1,1,80,25);

	       massege6();

	       scanf("%d",&cadit);
	       textbackground(BLUE);
	       window(22,15,54,22);
	       clrscr();
	       window(1,1,80,25);

	       gotoxy(20,15);

	       massege4();

	       gotoxy(64,9);
	       swaha=new(0)Driver(vviv,(long)n_kat_client,(long)n_client,(long)n_group);
	       swaha->run(otc);
	       swaha->sort(cadit);
	       vviv->set(tKat0);
	       window(19,14,63,23);
	       textbackground(BLUE);
	       clrscr();
	       window(1,1,80,25);
	       gotoxy(64,9);
	     }
	 }
     }
   textcolor(0);
 }

/***** Вывод альтернатив *****/
void init_res(void)
  {

    m_swaha=1;
    textbackground(BLUE);
    textcolor(WHITE);
    resultat=(*swaha)[0];
    window(15,2,63,12);
    v_swaha();

    gotoxy(2,5);
    cprintf("%s",vlad.namemen+1);
    vviv->set(tKat0);

    if(cadit>=2&&swaha->end>=2)
      {
	resultat=(*swaha)[1];
	window(15,14,63,23);
	v_swaha();
	gotoxy(2,17);
	cprintf("%s",vlad.namemen+1);
	vviv->set(tKat0);
	m_swaha++;
      }
    textcolor(0);
  }

void v_swaha(void)
  {
    cprintf("количество требований заказчика              %d\r\n",resultat->qme);
    cprintf("количество требований претендента            %d\r\n",resultat->qyou);
    cprintf("число сработавших требований заказчика       %d\r\n",resultat->enable);
    cprintf("число сработавших требований претендента     %d\r\n",resultat->enable1);
    cprintf("оценка соответствия требованиям заказчика   %5.2f",resultat->forme);
    cprintf("оценка соответствия требованиям претендента %5.2f",resultat->foryou);
    cprintf("окончательная оценка                        %5.2f",resultat->marks);
    window(1,1,80,25);
    ((vviv->set(tKat0))[n_group]).set(tMain);
    (*vviv)[resultat->hu];
  }

/***** Передвижение по результатам вниз *****/
void  inc_swaha(void)
 {
    if(m_swaha+1<=cadit&&m_swaha<swaha->end)
      {
       m_swaha++;
       clr_swaha();

       i_d_swaha();
       gotoxy(64,4);
       textcolor(0);
      }

 }

void i_d_swaha(void)
  {
    textbackground(BLUE);
    textcolor(WHITE);
    resultat=(*swaha)[m_swaha-2];
    window(15,2,63,12);
    v_swaha();
    gotoxy(2,5);
    cprintf("%s",vlad.namemen+1);
    vviv->set(tKat0);

    textbackground(BLUE);
    textcolor(WHITE);
    resultat=(*swaha)[m_swaha-1];
    window(15,14,63,23);
    v_swaha();
    gotoxy(2,17);
    cprintf("%s",vlad.namemen+1);
    vviv->set(tKat0);
  }

/***** Передвижение по результатам вверх *****/
void  dec_swaha(void)
 {
    if(m_swaha-1>=2)
      {
       m_swaha--;
       clr_swaha();

       i_d_swaha();
       gotoxy(64,5);
       textcolor(0);
      }

 }
