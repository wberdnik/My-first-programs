#ifndef VIRTUALH
#define VIRTUALH

typedef unsigned long int v_size; // 4 Гигабайта

 enum {
      vNo=0,       // пустая
      vYes=1,      // используется в классе Virtual

      vRam,        // все находится в основной памяти
      vOnlyXms,    // используется только XMS
      vOnlyDisk,   // используется только файл подкачки
      vXmsDisk,    // ипользуется все

      };



typedef struct {

    v_size memstart;   //номер в массиве
    v_size memend;

    v_size xmsstart;
    v_size xmsend;

    v_size diskstart;
    v_size diskend;

    char flag;        //где находится массив

    void far * MEMoffset;   //начало массива в ОЗУ
    v_size XMSoffset;       //начало массива в XMS
    v_size FILEoffset;      //начало массива в FILE

    char flaginc;           //изменились ли данные в КЭШе

    v_size light; //длина массива в XMS в Кбайтах

    int sizeblock;
	       } Mem;



#endif