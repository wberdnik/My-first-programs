#ifndef swahah
#define swahah
// ������� ���ଠ樨 � ������
typedef struct{
		long file;     // ����� �ࠪ���⨪�
		long treb;     // �ࠪ���⨪� ������
                long weightfb; // �ॡ㥬� ��� ����⢠
		long xar;      // �ࠪ���⨪� ᥡ�
		long weigt;    // �業�� ������� �ॡ������
		long weigx;    // ᢮� �業��
		long others;   // ����� �ࠢ��� � ���� ������
			   }SLOT;

// �業�筠� ������� ᮮ⢥�ᢨ� ���� ��

typedef struct{
    int qme;      //�᫮ ����⢮����� ����ᮢ
		int qyou;     //�᫮ �⢥��� ����ᮢ
		int enable;   //�᫮ ᮮ⢥��⢨� �����ᢨ� ������
                int enable1;
		float forme;  // ᮮ⢥��⢨� ������
			     //��᪮�쪮 ��(�) ᮮ⢥���� ���
		float foryou; // ��� � ᮮ⢥����
			     // ��᪮�쪮 � ��(���) ���宦�
		float marks;  // �����⥫쭠� �業��
		long  hu;     // ����� 祫����� � ��㯯�
			     }marks;


#endif