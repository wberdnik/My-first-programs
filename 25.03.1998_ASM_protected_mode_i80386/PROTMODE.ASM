;��������� ������������� ����������  �����  ,  ������ ��������� 
;           � ������������ � �������� �����
;ᮧ������ gdt , � ���ன ���ᠭ� ᥣ����� ����, ������, �⥪�
;ᮧ������ idt , � ���ன ���ᠭ� ��� ���뢠��� � �᪫�祭��
;    ������ ����� :
;�.�. �஫��,�.�.�஫�� ���饭�� ०�� �����஢ Intel 80286/80386/80486

IDEAL
P386
MODEL LARGE
include "protmode.h"
;=============== ������� �⥪� ===============================
STACK_SIZE=0400h
STACK STACK_SIZE
;=============== ������� ������ ==============================

DATASEG
DSEG_BEG        = THIS WORD
;--------------- �������� ॠ�쭮�� ०��� -------------------
real_ss dw ?
real_sp dw ?
;--------------- ����⮢� ᮮ�饭�� -------------------------
kx      dw 10
ky      dw 10
mess    db  42,'����饭�� �� ���饭���� ०��� ������'
rmes    db  0dh,0ah,'�ᯥ譮� �����襭�� �ணࠬ��$'

;--------------- ������ GDT ---------------------------------
GDT_BEG = $
LABEL   gdtr    word
gdt_0           desc_struc   <0,0,0,0,0>
gdt_gdt         desc_struc   <GDT_SIZE-1,,,DATA_ACC,0>
gdt_idt         desc_struc   <IDT_SIZE-1,,,IDT_ACC,0>
gdt_ds          desc_struc   <DSEG_SIZE-1,,,DATA_ACC,0>
gdt_cs          desc_struc   <CSEG_SIZE-1,,,CODE_ACC,0>
gdt_ss          desc_struc   <STACK_SIZE-1,,,DATA_ACC,0>
gdt_crt         desc_struc  <CRT_SIZE-1,CRT_LOW,CRT_SEG,DATA_ACC,0>
GDT_SIZE = ($ - GDT_BEG)

;--------------- ������� ��� ����㧪� IDTR -------------------
idtr idtr_struc <IDT_SIZE,,,0>
null_idt idtr_struc <0,0,0,0>          ; ���⮩ ���ਯ��
realidt		dw	3ffh
realbase	dd	0
;--------------- ������ IDT ---------------------------------
IDT_BEG = $
        ;���� �᪫�祭�� (exc_trap - ��楤��-�����誠)
idt idt_struc 32 dup (<OFFSET exc_trap,CS_DESCR,0,TRAP_ACC,0>)
        ;���� �������� ���뢠���
        ;(dummy_iret0 , dummy_iret1 - ��楤���-�����誨)
        ; INT 20h,21h,22h,23h,24h,25h,26h,27h -  IRQ0/IRQ7
idt_struc 8 dup (<OFFSET dummy_iret0,CS_DESCR,0,INT_ACC,0>)
        ; INT 28h,29h,2Ah,2Bh,2Ch,2Dh,2Eh,2Fh -  IRQ8/IRQ15
idt_struc 8 dup (<OFFSET dummy_iret1,CS_DESCR,0,INT_ACC,0>)
IDT_SIZE = ($-IDT_BEG)

;=============== C������ ���� ===============================

CODESEG

; �ணࠬ�� ��稭��� �믮������ � ������� ����
PROC Start
    mov ax,DGROUP
    mov ds, ax


   call init_protected_mode
   call setpm

;--------- �ணࠬ��  ࠡ�⠥� � ���饭��� ०���

    call pwrite

      call setrm286
;     call setrm386

;--------- �ணࠬ�� ࠡ�⠥� � ॠ�쭮� ०���

    call rwrite

    xor al, al
    mov ah,4Ch
    int  21h

ENDP Start

MACRO setgdtentry
    mov[(desc_struc bx).base_l],ax
    mov[(desc_struc bx).base_h],dl
ENDM

MACRO enableint
;ࠧ�蠥� �� ���뢠��� � ࠧ��᪨�㥬 ����஫����
     mov ax, 000Dh
     out CMOS_PORT, al

     in al, INT_MASK_PORT_M
     and al, 0
     out INT_MASK_PORT_M, al

     in al, INT_MASK_PORT_S
     and al, 0
     out INT_MASK_PORT_S, al

     sti
ENDM

;--------------- ��楤�� �����⮢�� ���饭���� ०��� -----

PROC init_protected_mode NEAR
; ��।��塞 ������ ���� DS
     mov ax,DGROUP
     mov dl,ah
     shr dl,4
     shl ax,4
     mov si,ax
     mov di,dx

;������塞 ���ਯ�� gdt � GDT
     add ax,OFFSET gdtr
     adc dl,0
     mov bx,OFFSET gdt_gdt
     setgdtentry

; ������塞 ���ਯ�� IDT � GDT
     mov ax,si
     mov dx,di
     add ax,OFFSET idt
     adc dl,0
     mov bx,OFFSET gdt_idt
     setgdtentry

; ������塞 �������� ��� ����㧪� IDTR
     mov bx,OFFSET idtr
     mov [(idtr_struc bx).idt_l],ax
     mov [(idtr_struc bx).idt_h],dl

;������塞 ���ਯ�� DS � GDT
     mov bx,OFFSET gdt_ds
     mov ax,si
     mov dx,di
     setgdtentry

;������塞 ���ਯ�� CS � GDT
     mov bx,OFFSET gdt_cs
     mov ax,cs
     mov dl,ah
     shr dl,4
     shl ax,4
     setgdtentry

;������塞 ���ਯ�� SS � GDT
     mov bx,OFFSET gdt_ss
     mov ax,ss
     mov dl,ah
     shr dl,4
     shl ax,4
     setgdtentry

;�����뢠�� ���� ������ �� ����� 0040:0067h
     push ds
     mov ax, 40h
     mov ds, ax
     mov [WORD 67h],OFFSET shutdown_return
     mov [WORD 69h],cs
     pop ds

     ret

ENDP    init_protected_mode

; ------    ���室 � ���饭�� ०��   ---------------

PROC setpm NEAR

;����頥� �� ���뢠���, �����뢠�� � CMOS 5 �� ����� 0Fh
;��� ⮣� �⮡� ��᫥ ��� ������ ���樠����஢���� ����஫��
;���뢠��� � �ࠢ����� ��।��� �� ����� �� �祥� 00467h

     cli
     
     mov al, 8Fh
     out CMOS_PORT, al
     jmp short $+2
     
     mov al,5
     out CMOS_PORT+1, al

;ࠧ�蠥� ����� �20
     call    enable_a20
;���������� ᥣ����� ॠ�쭮�� ०���
     mov [real_ss], ss
     
;��९ணࠬ���㥬 ����஫���� ���뢠���
;��� IRQ0-IRQ7 - ����� ���뢠��� 20h-27h
     mov dx, MASTER8259A
     mov ah, 20h
     mov cl, 4

     call setint        

;��� IRQ8-IRQ15 - ����� ���뢠��� 28h-2Fh
     mov dx, SLAVE8259A
     mov ah, 28h
     mov cl, 2
     call setint

;����㦠�� IDTR & GDTR

     lidt [FWORD idtr]
     lgdt [QWORD gdt_gdt]

;��⠭�������� ���饭�� ०��

;     mov eax, CR0     ; ��� 386 ������
;     or al, 1
;     mov CR0,eax

     mov     ax,VIRTUAL_MODE    ; ��� 286 ������
     lmsw    ax                 ; ����㧨�� ��設��� ᫮��

;�������  jmp far  - ��ࢠ� ������� ���. ०���
; Jmp far ����室�� ��� ��饭�� ��।� ������

     db 0EAh
     dw $+4,CS_DESCR

;����㦠�� ᥫ����� � ᥣ����� ॣ�����
     mov ax,SS_DESCR
     mov ss,ax
     mov ax,DS_DESCR
     mov ds,ax

     enableint  ; ࠧ�蠥� ���뢠���

     ret
ENDP setpm

;--------------- ��楤�� ������ � ॠ��� ०�� --------
;------------------------ ��� i80286 ------------------------
PROC setrm286 NEAR
;���������� 㪠��⥫� �⥪�
     mov [real_sp], sp
;��� ������ �१ ����஫�� ����������

;     mov al, SHUT_DOWN
;     out STATUS_PORT, al
     
; ��㣮� ��ਠ�� ( "������� �訡��" )
	LIDT [FWORD null_idt]
	int 3
          
wait_reset:
     hlt
     jmp wait_reset

;� �� ���� ��।����� �ࠢ����� ��᫥ ���

LABEL shutdown_return FAR
;����頥� �� ���뢠���
     cli
     
     mov al, 8Fh
     out CMOS_PORT, al
     jmp short $+2

;���樠�����㥬 ᥣ���� DS
     mov ax, DGROUP
     mov ds, ax
     ASSUME ds:DGROUP
;���樠�����㥬 �⥪ 
     mov ss, [real_ss]
     mov sp, [real_sp]
     
; ࠧ�蠥� ���뢠���
     enableint
;����뢠�� ����� �20
     call    disable_a20
     ret

ENDP setrm286

;--------------- ��楤�� ������ � ॠ��� ०�� --------
;------------------------ ��� i80386 ------------------------

PROC setrm386 NEAR
;����頥� �� ���뢠���
     mov [real_sp],sp
     cli
     
     lidt [fword ds:realidt] ; ��⠭���� idt ��� ॠ��쭮��  ०���
     
     mov al, 8Fh
     out CMOS_PORT, al
     jmp short $+2

     mov eax, CR0     ; ��� 386 ������
     and al, 0feh
     mov CR0,eax
;�������  jmp far  - ��ࢠ� ������� ॠ�쭮�� ०���
; Jmp far ����室�� ��� ��饭�� ��।� ������
      db  0eah
      dw $+4,PROTMODE_TEXT
;���樠�����㥬 ᥣ���� DS
     mov ax, DGROUP
     mov ds, ax
     ASSUME ds:DGROUP
;���樠�����㥬 �⥪ � ES
     mov ss, [real_ss]
     mov sp, [real_sp]
     
     enableint
;����뢠�� ����� �20
     call    disable_a20
     ret
ENDP setrm386

;��楤�� �뢮�� ᮮ�饭�� � ���饭��� ०���

PROC pwrite NEAR
     mov    ax,CRT_DESCR
     mov    es,ax
     mov    ax,[ky]
     mov    bl,160
     mul    bl
     add    ax,[kx]
     add    ax,[kx]

     mov    di,ax

     mov    si,offset mess
     lodsb
     xor   cx,cx
     mov   cl,al
     mov   ah,30h    ; ��ਡ��� ᨬ����

mt1:  lodsb
      stosw
      loop  mt1
      inc [ky]
      ret

ENDP     pwrite

PROC     rwrite near        ; c���饭�� �� �ᯥ譮� �����襭��  � ॠ�쭮�
         mov    ax,DGROUP   ; ०���
         mov    ds,ax
         mov    ah,09h
         mov    dx,offset rmes
         int    21h
         mov    ah,1
         int    21h
         ret
ENDP     rwrite


PROC enable_a20 near
	push	ax
        mov     al,A20_PORT
        out     STATUS_PORT,al
        mov     al,A20_ON
        out     KBD_PORT_A,al
        pop	ax
        ret
ENDP    enable_a20


PROC disable_a20 near
	push	ax
        mov     al,A20_PORT
        out     STATUS_PORT,al
        mov     al,A20_OFF
        out     KBD_PORT_A,al
        pop	ax
        ret
ENDP    disable_a20


;--------------- �����誠 ��� IRQ0-IRQ7 ---------------------
PROC dummy_iret0 NEAR
     push ax
     mov al,EOI
     out MASTER8259A,al
     pop ax
     iret
ENDP dummy_iret0
;--------------- �����誠 ��� IRQ8-IRQ15 --------------------
PROC dummy_iret1 NEAR
     push ax
     mov al,EOI
     out MASTER8259A,al
     out SLAVE8259A,al
     pop ax
     iret
ENDP dummy_iret1
;--------------- �����誠 �᪫�祭�� ------------------------
LABEL exc_trap WORD

     jmp shutdown

;------------- ���਩��� �����襭�� �� �᪫�祭�� -------------
PROC shutdown NEAR
     call setrm286
     mov        ax,cs
     mov        ds,ax
     mov        ah,09h
     mov        dx,offset exep
     int        21h
     mov	ax,0
     int	16h
     mov	ah, 4Ch
     int	21h
exep    db      0dh,0ah,'���਩��� �����襭�� �� �᪫�祭��'
        db      0dh,0ah,07h,'������ ���� �������$'
ENDP shutdown

;-- ��楤�� ��९ணࠬ��஢���� ����஫��஢ ���뢠��� --
PROC setint NEAR
     mov al,11h    ;��⠭����� ICW1
     out dx,al
     jmp short $+2

     mov al,ah     ;��⠭����� ICW2 - ������ ����
     inc dx
     out dx,al
     jmp short $+2

     mov al,cl      ;��⠭����� ICW3- MASTER/SLAVE
     out dx,al
     jmp short $+2

     mov al,1      ;��⠭����� ICW4
     out dx,al
     jmp short $+2
     mov al,0FFh   ;��⠭���� ��᮪
     out dx,al
     dec dx

     ret
ENDP setint

CSEG_SIZE = ($-Start)
DATASEG
DSEG_SIZE = ($-DSEG_BEG)
END Start
