#ifndef VIRTUALH
#define VIRTUALH

typedef unsigned long int v_size; // 4 ��������

 enum {
      vNo=0,       // �����
      vYes=1,      // �ᯮ������ � ����� Virtual

      vRam,        // �� ��室���� � �᭮���� �����
      vOnlyXms,    // �ᯮ������ ⮫쪮 XMS
      vOnlyDisk,   // �ᯮ������ ⮫쪮 䠩� �����窨
      vXmsDisk,    // ��������� ��

      };



typedef struct {

    v_size memstart;   //����� � ���ᨢ�
    v_size memend;

    v_size xmsstart;
    v_size xmsend;

    v_size diskstart;
    v_size diskend;

    char flag;        //��� ��室���� ���ᨢ

    void far * MEMoffset;   //��砫� ���ᨢ� � ���
    v_size XMSoffset;       //��砫� ���ᨢ� � XMS
    v_size FILEoffset;      //��砫� ���ᨢ� � FILE

    char flaginc;           //���������� �� ����� � ����

    v_size light; //����� ���ᨢ� � XMS � ������

    int sizeblock;
	       } Mem;



#endif