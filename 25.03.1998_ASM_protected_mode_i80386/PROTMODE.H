;================ ��।������ ������� ������ ================
;---------------- ������� ���ਯ�� ----------------------
STRUC desc_struc
      limit      dw   0 ; �।�� 15-0
      base_l     dw   0 ; ��� ��. ���� 䨧��᪮�� ����
      base_h     db   0 ; ��⨩ ���� 䨧��᪮�� ����
      access     db   0 ; ���� �ࠢ ����㯠
      rsrv       dw   0 ; �।�� 19-16 , ���� G,D,0,U �
                        ; �⢥���  ���� 䨧��᪮�� ����
                        ; (�� ࠧ��� ᥣ���� � 64 � � 16-
                        ; ࠧ�來�� ����樨 �� ���� ᮤ��-
                        ; ��� 0)
ENDS  desc_struc

;--------------- ������� � ���뢠��� ------------------
STRUC   idt_struc
        destoff   dw  0 ; ᬥ饭�� � ᥣ���� �����祭�� 15-0
        destsel   dw  0 ; ᥫ���� ᥣ���� �����祭��
        nparams   db  0 ; �᫮ �����㥬�� ��ࠬ��஢
        access    db  0 ; ���� �ࠢ ����㯠
        rsrv      dw  0 ; ᬥ饭�� � ᥣ���� �����祭�� 31-16
                        ; (�� 16-ࠧ�來�� ����樨 �� ����
                        ; ᮤ�ন� 0)
ENDS    idt_struc

;--------------- ������� ॣ���� IDTR ---------------------
STRUC   idtr_struc
        idt_lim   dw    0
        idt_l     dw    0
        idt_h     db    0
        rsrv      db    0
ENDS    idtr_struc

;--------------- ���� ���� ����㯠 --------------------------
ACC_PRESENT     EQU  10000000b;ᥣ���� ���� � �����
ACC_CSEG        EQU  00011000b;ᥣ���� ����
ACC_DSEG        EQU  00010000b;ᥣ���� ������
ACC_EXPDOWN     EQU  00000100b;ᥣ���� �������� ����
ACC_CONFORM     EQU  00000100b;ᮣ��ᮢ���� ᥣ����
ACC_DATAWR      EQU  00000010b;ࠧ�襭� ������
ACC_INT_GATE    EQU  00000110b;�� ���뢠���
ACC_TRAP_GATE   EQU  00000111b;�� �᪫�祭��

;--------------- ���� ᥣ���⮢ ------------------------------
                 ; ������� ������
DATA_ACC = ACC_PRESENT OR ACC_DSEG OR ACC_DATAWR
                 ; ������� ����
CODE_ACC = ACC_PRESENT OR ACC_CSEG OR ACC_CONFORM
                 ; ������� �⥪�
STACK_ACC = ACC_PRESENT OR ACC_DSEG OR ACC_DATAWR OR ACC_EXPDOWN
                 ; ���� ����㯠 ᥣ���� ⠡���� IDT
IDT_ACC = DATA_ACC
                 ; ���� ����㯠 � ���뢠���
INT_ACC = ACC_PRESENT OR ACC_INT_GATE
                 ; ���� ����㯠 � �᪫�祭��
TRAP_ACC = ACC_PRESENT OR ACC_TRAP_GATE

;--------------- ��������, ��।������ � ⠡��� GDT -------

DS_DESCR = (gdt_ds - gdt_0)
CS_DESCR = (gdt_cs - gdt_0)
SS_DESCR = (gdt_ss - gdt_0)
CRT_DESCR= (gdt_crt - gdt_0)

A20_PORT        EQU     0d1h    ; ������� �ࠢ������ ������ �20
A20_ON          EQU     0dfh
A20_OFF         EQU     0ddh
STATUS_PORT     EQU     64h     ; ���� ���ﭨ� ����������
KBD_PORT_A      EQU     60h     ; ���� ����������� ���⮢
KBD_PORT_B      EQU     61h
VIRTUAL_MODE    EQU     1       ; ��� ���室� � ���饭�� ०��
CRT_SIZE        EQU     4000    ; ࠧ��� ᥣ���� ����������
CRT_LOW         EQU     8000h   ; ����訩 ���� 䨧��᪮�� ���� ᥣ����
                                ; ᥣ��� ����������
CRT_SEG         EQU     0bH     ; ���訩 ����
SHUT_DOWN       EQU     0feh
INT_MASK_PORT_M	EQU	21h	; ���� ��� ���ࢠ��� ���뢠���
INT_MASK_PORT_S	EQU	0A1h	; ���� ��� ���ࢠ��� ���뢠���
EOI		EQU	20h	; ������� ���� ���뢠���
MASTER8259A	EQU	20h	; ���� ����஫�� ���뢠���
SLAVE8259A	EQU	0A0H	; ��ன ����஫�� ���뢠���
CMOS_PORT	EQU	70h	; ���� CMOS ����



