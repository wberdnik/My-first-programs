;================ Определения структур данных ================
;---------------- Структура дескриптора ----------------------
STRUC desc_struc
      limit      dw   0 ; предел 15-0
      base_l     dw   0 ; два мл. байта физического адреса
      base_h     db   0 ; третий байт физического адреса
      access     db   0 ; байт прав доступа
      rsrv       dw   0 ; предел 19-16 , биты G,D,0,U и
                        ; четвертый  байт физического адреса
                        ; (при размере сегмента в 64 К и 16-
                        ; разрядной адресации это поле содер-
                        ; жит 0)
ENDS  desc_struc

;--------------- Структура шлюза прерывания ------------------
STRUC   idt_struc
        destoff   dw  0 ; смещение в сегменте назначения 15-0
        destsel   dw  0 ; селектор сегмента назначения
        nparams   db  0 ; число копируемых параметров
        access    db  0 ; байт прав доступа
        rsrv      dw  0 ; смещение в сегменте назначения 31-16
                        ; (при 16-разрядной адресации это поле
                        ; содержит 0)
ENDS    idt_struc

;--------------- Структура регистра IDTR ---------------------
STRUC   idtr_struc
        idt_lim   dw    0
        idt_l     dw    0
        idt_h     db    0
        rsrv      db    0
ENDS    idtr_struc

;--------------- Биты байта доступа --------------------------
ACC_PRESENT     EQU  10000000b;сегмент есть в памяти
ACC_CSEG        EQU  00011000b;сегмент кода
ACC_DSEG        EQU  00010000b;сегмент данных
ACC_EXPDOWN     EQU  00000100b;сегмент расширяется вниз
ACC_CONFORM     EQU  00000100b;согласованный сегмент
ACC_DATAWR      EQU  00000010b;разрешена запись
ACC_INT_GATE    EQU  00000110b;шлюз прерывания
ACC_TRAP_GATE   EQU  00000111b;шлюз исключения

;--------------- Типы сегментов ------------------------------
                 ; Сегмент данных
DATA_ACC = ACC_PRESENT OR ACC_DSEG OR ACC_DATAWR
                 ; Сегмент кода
CODE_ACC = ACC_PRESENT OR ACC_CSEG OR ACC_CONFORM
                 ; Сегмент стека
STACK_ACC = ACC_PRESENT OR ACC_DSEG OR ACC_DATAWR OR ACC_EXPDOWN
                 ; Байт доступа сегмента таблицы IDT
IDT_ACC = DATA_ACC
                 ; Байт доступа шлюза прерывания
INT_ACC = ACC_PRESENT OR ACC_INT_GATE
                 ; Байт доступа шлюза исключения
TRAP_ACC = ACC_PRESENT OR ACC_TRAP_GATE

;--------------- Селекторы, определенные в таблице GDT -------

DS_DESCR = (gdt_ds - gdt_0)
CS_DESCR = (gdt_cs - gdt_0)
SS_DESCR = (gdt_ss - gdt_0)
CRT_DESCR= (gdt_crt - gdt_0)

A20_PORT        EQU     0d1h    ; команда управлением линией А20
A20_ON          EQU     0dfh
A20_OFF         EQU     0ddh
STATUS_PORT     EQU     64h     ; порт состояния клавиатуры
KBD_PORT_A      EQU     60h     ; адреса клавиатурных портов
KBD_PORT_B      EQU     61h
VIRTUAL_MODE    EQU     1       ; бит перехода в защищенный режим
CRT_SIZE        EQU     4000    ; размер сегмента видеопамяти
CRT_LOW         EQU     8000h   ; младший байт физического адреса сегмента
                                ; сегмета видеопамяти
CRT_SEG         EQU     0bH     ; старший байт
SHUT_DOWN       EQU     0feh
INT_MASK_PORT_M	EQU	21h	; порт для масирвания прерываний
INT_MASK_PORT_S	EQU	0A1h	; порт для масирвания прерываний
EOI		EQU	20h	; команда конца прерывания
MASTER8259A	EQU	20h	; первый контролер прерываний
SLAVE8259A	EQU	0A0H	; второй контролер прерываний
CMOS_PORT	EQU	70h	; адрес CMOS порта



