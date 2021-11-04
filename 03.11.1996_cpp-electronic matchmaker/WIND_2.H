#ifndef wind_2h
#define wind_2h

extern void menu(unsigned,unsigned,unsigned);
extern void menu_0(void);
extern void menu4_0(void);
extern void menu_2(void);
extern void menu_00(void);
extern void quit(void);
extern void menu0(void);
extern void menu1_0(void);
extern void menu_1(void);
extern void clr_help1(void);
extern void help1(void);
extern void clr_help2(void);
extern void help2(void);
extern void clr_swaha(void);
extern void no_res(void);
extern void help3(void);
extern void massege1(void);
extern void massege2(void);
extern void massege3(void);
extern void massege4(void);
extern void massege5(void);
extern void massege6(void);
extern void massege8(void);
extern void massege9(void);
extern void massege10(void);
extern void massege11(void);
extern void massege12(void);
extern void massege13(void);
extern void massege14(void);
extern void massege15(void);
extern void massege16(void);
extern void massege17(void);
extern void massege18(void);
extern void massege19(void);
extern void massege20(void);
extern void vv(void);
extern void vv_1(void);



#define UP          0x4800
#define DOWN        0x5000
#define LEFT        0x4b00
#define RIGHT       0x4d00
#define ESC         0x011b
#define TAB         0x0f09
#define CR          0x1c0d
#define BACKSPASE   0x0e08

FILE * file,* file1;
char type[]="rt";
char name1[11];
char dop[11];
char dop_0[11];
char dop_10[49];
char dop_20[49];
char s[30];
char *name_window[10],*name_file[10],*name_func[10];
char *name_katalog[11];
char *name_kach[11];
char *name_qullity[11];
char *name_kach_d[11];
char *name_qullity_d[11];
char *name_treb[11];
char *name_men[11];

int  *netto_kach;
int  *netto_treb;

int  *namber,wind,per,per_kat=0;
int  per_kach=0;
int  per_k=0;
int  m_k,m_m,m_kach,m_q;
int  f_end_katalog=0;
int  f_end_kach=0;
int  f_end_men=0;
int  f_end_men_1=0;
int  f_end_qullity_1=0;
int  f_end_qullity=0;
int  f_end_treb=0;
int  f_end_kach_d=0;
int  f_end_qullity_d=0;
int  f_exit=0;
int  f_exit_qullity=0;
int  f_one_exit_1=0;
int  f_one_exit_2=0;
int  f_one_exit_3=0;
int  f_one_exit_4=0;
int  f_one_exit_5=0;

int  f_one_exit_4d=0;
int  f_one_exit_5d=0;

int  f_one_exit_6=0;
int  f_save=0;
int  f_save_1=0;
int  f_tr_xar=0;
int  z_k,z_men,z_kach,z_qullity;
int  m_k_t;
int  dop_nam=-1;
int  dop_nam_1=0;

int  z_kach_d,z_qullity_d,z_treb;
int  flag_tr_xar=0;
int  flag_ramka=0;

int  n_kat_client=-1;
int  n_client=-1;
int  n_group=-1;
int cadit=0;
int m_swaha=0;

char line[]="ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ";
char line1[]="บ            บ                                                                 บ";
char line2[]="                ";
char line3[]="          ";
char line4[]="                                                ";
char line5[]="";


void menu1_1(void);
void menu_down(void);
void menu_down_1(void);


void init_katal(void);
void read_katalog(void);
void move_katalog(void);
void move_katalog_dn(void);
void mov_kat(void);
void inc_kat(void);
void dec_kat(void);
void init_two(void);
void inc_name_kat(void);
void redoctir_name_kat(void);
void dn_name_kat(void);
void mov_init(void);
void delete_kat(void);

void read_men(void);
void mov_men(void);
void move_men_men(void);
void init_two_men(void);
void inc_men(void);
void dec_men(void);
void move_men_dn(void);
void inc_name_men(void);
void null_men(void);
void redoctir_name_men(void);
void delete_men(void);


void init_name_kach(void);
void read_kach(void);
void move_kach(void);
void mov_init_kach(void);
void mov_kach(void);
void move_kach_dn(void);
void inc_kach(void);
void dec_kach(void);
void init_two_kach(void);
void inc_name_kach(void);
void delete_kach(void);
void redoctir_name_kach(void);
void dn_name_kach(void);
void read_qullity(void);
void inc_name_qullity(void);
void null_qullity(void);

void init_two_qullity(void);
void inc_qullity(void);
void mov_qullity(void);
void move_men_qullity(void);
void move_qullity_dn(void);
void dec_qullity(void);
void redoctir_name_qullity(void);
void delete_qullity(void);

void mark_xar(void);
void mark_treb(void);
void mark_xar_xar(void);

void kact_treb(void);
void dlina(void);

void save_kact(void);
void read_kach_1(void);
void read_qullity_1(void);
void read_treb(void);
void kach_treb_xar(void);
void move_treb_xar(void);
void inc_kach_d(void);
void move_treb_kach_dn(void);
void dec_kach_d(void);
void clr_tr_xar(void);
void del_k_tr(void);
void mov_kach_d(void);

void kact_treb_dop(void);

void netto(void);
void  kat_client(void);
void  client(void);
void  group(void);
void  run_swaha(void);

void clr_help1(void);
void help1(void);
void init_res(void);

void  inc_swaha(void);
void  dec_swaha(void);
void  i_d_swaha(void);
void v_swaha(void);

#endif