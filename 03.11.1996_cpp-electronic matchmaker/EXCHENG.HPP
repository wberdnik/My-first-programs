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

	long	file;		//㪠��⥫� � ��⠫��� �����        .1
	long	treb;		//㪠��⥫� �ॡ�������� ����⢠     .2
	long	xar;		//㪠��⥫� "����� �"		      .3

        long   weighttr;         //��� �ॡ������ �� ���樠����樨

 public:
	Excheng(long i)
	{markfile=marktreb=markxar=xar=treb=file=i;};

      char	nametom[12];  	//�⥭�� ��⠫���
      int	keytom;   	//���� ⮬�
      
      char	namemen[12]; 	// �⥭�� ⮬�
      int	acssesmen;	//�ࠢ� ����㯠 � ������� 祫�����
      
      char	namequllity[12];// �⥭�� ��⠫��� 祫����᪨� �����
      char	typeinfo;	// �� �࠭���� ����� : �᫮ �� ��ப�
      
      char	qullity[50];	//ᠬ� ����⢮
      long	weigtqullity;   // ��� �஢��� �।� ��� ���� �����
      
      long	weigt;		//��᪮�쪮 ����� �ॡ������
      long	others;		//㪠��⥫� �� ���� ������
      int	acsess;         //�ࠢ� ����㯠 � �⮫� ��⨬���� ������
      
      char	inifile[11];	// �������� ����⢠
      char	initreb[49];    // �� �⥫��� ��
      char	inixar[49];	// � �� ���� '�'

      char	path[70];	//��⠫�� ��� �࠭���� ��
      char	extend[5];      //���७�� �ᯮ��㥬�� ��� 䠩��� ��
      char	nameconfig[72];

      long	stop;

      void	edit(void);
 };

#ifndef iiiii
extern Excheng vlad;
#endif

#endif