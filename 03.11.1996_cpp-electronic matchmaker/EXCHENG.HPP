#ifndef EXCHENG
#define EXCHENG

class Excheng  
{private:
	friend	Type;
	friend  Config;
	friend  Kat0;
	friend  Kat1;
	friend  Work;
	friend  Main;
	friend  Xar;
	friend  Iosys;
	friend  Live;
        friend  Cler;

	char	namemain[9];
	char	namework[9];
	char	namexar[9];
	char	namekat0[9];
	char	namekat1[9];


	long	chethik;

	long	markfile;
	long	marktreb;
	long	markxar;

	long	file;		//указатель в каталоге качеств        .1
	long	treb;		//указатель требоваемого качества     .2
	long	xar;		//указатель "какой Я"		      .3

        long   weighttr;         //вес требования из инициализации

 public:
	Excheng(long i)
	{markfile=marktreb=markxar=xar=treb=file=i;};

      char	nametom[12];  	//чтение каталога
      int	keytom;   	//ключ тома
      
      char	namemen[12]; 	// чтение тома
      int	acssesmen;	//права доступа к данному человеку
      
      char	namequllity[12];// чтение каталога человеческих качеств
      char	typeinfo;	// что хранится здесь : число фото строка
      
      char	qullity[50];	//само качество
      long	weigtqullity;   // его уровень среди всех прочих качеств
      
      long	weigt;		//насколько важно требование
      long	others;		//указатель на базу знаний
      int	acsess;         //права доступа к столь интимному качеству
      
      char	inifile[11];	// название качества
      char	initreb[49];    // что хотелось бы
      char	inixar[49];	// и что есть 'Я'

      char	path[70];	//каталог где хранится БД
      char	extend[5];      //расширение используемое для файлов БД
      char	nameconfig[72];

      long	stop;

      void	edit(void);
 };

#ifndef iiiii
extern Excheng vlad;
#endif

#endif