;ПРОГРАММА УСТАНАВЛИВАЕТ ЗАЩИЩЕННЫЙ  РЕЖИМ  ,  ВЫДАЕТ СООБЩЕНИЕ 
;           И ВОЗВРАЩАЕТСЯ В РЕАЛЬНЫЙ РЕЖИМ
;создается gdt , в которой описаны сегменты кода, данных, стека
;создается idt , в которой описаны шлюзы прерываний и исключений
;    Смотрите книгу :
;А.В. Фролов,Г.В.Фролов Защищенный режим процессоров Intel 80286/80386/80486

IDEAL
P386
MODEL LARGE
include "protmode.h"
;=============== Сегмент стека ===============================
STACK_SIZE=0400h
STACK STACK_SIZE
;=============== Сегмент данных ==============================

DATASEG
DSEG_BEG        = THIS WORD
;--------------- Регистры реального режима -------------------
real_ss dw ?
real_sp dw ?
;--------------- Текстовые сообщения -------------------------
kx      dw 10
ky      dw 10
mess    db  42,'Сообщение из защищенного режима процессора'
rmes    db  0dh,0ah,'Успешное завершение программы$'

;--------------- Таблица GDT ---------------------------------
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

;--------------- Область для загрузки IDTR -------------------
idtr idtr_struc <IDT_SIZE,,,0>
null_idt idtr_struc <0,0,0,0>          ; пустой дескриптор
realidt		dw	3ffh
realbase	dd	0
;--------------- Таблица IDT ---------------------------------
IDT_BEG = $
        ;Шлюзы исключений (exc_trap - процедура-заглушка)
idt idt_struc 32 dup (<OFFSET exc_trap,CS_DESCR,0,TRAP_ACC,0>)
        ;Шлюзы аппаратных прерываний
        ;(dummy_iret0 , dummy_iret1 - процедуры-заглушки)
        ; INT 20h,21h,22h,23h,24h,25h,26h,27h -  IRQ0/IRQ7
idt_struc 8 dup (<OFFSET dummy_iret0,CS_DESCR,0,INT_ACC,0>)
        ; INT 28h,29h,2Ah,2Bh,2Ch,2Dh,2Eh,2Fh -  IRQ8/IRQ15
idt_struc 8 dup (<OFFSET dummy_iret1,CS_DESCR,0,INT_ACC,0>)
IDT_SIZE = ($-IDT_BEG)

;=============== Cегмент кода ===============================

CODESEG

; Программа начинает выполнение с данного места
PROC Start
    mov ax,DGROUP
    mov ds, ax


   call init_protected_mode
   call setpm

;--------- Программа  работает в защищенном режиме

    call pwrite

      call setrm286
;     call setrm386

;--------- Программа работает в реальном режиме

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
;разрешаем все прерывания и размаскируем контроллеры
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

;--------------- Процедура подготовки защищенного режима -----

PROC init_protected_mode NEAR
; определяем базовый адрес DS
     mov ax,DGROUP
     mov dl,ah
     shr dl,4
     shl ax,4
     mov si,ax
     mov di,dx

;заполняем дескриптор gdt в GDT
     add ax,OFFSET gdtr
     adc dl,0
     mov bx,OFFSET gdt_gdt
     setgdtentry

; заполняем дескриптор IDT в GDT
     mov ax,si
     mov dx,di
     add ax,OFFSET idt
     adc dl,0
     mov bx,OFFSET gdt_idt
     setgdtentry

; заполняем структуру для загрузки IDTR
     mov bx,OFFSET idtr
     mov [(idtr_struc bx).idt_l],ax
     mov [(idtr_struc bx).idt_h],dl

;заполняем дескриптор DS в GDT
     mov bx,OFFSET gdt_ds
     mov ax,si
     mov dx,di
     setgdtentry

;заполняем дескриптор CS в GDT
     mov bx,OFFSET gdt_cs
     mov ax,cs
     mov dl,ah
     shr dl,4
     shl ax,4
     setgdtentry

;заполняем дескриптор SS в GDT
     mov bx,OFFSET gdt_ss
     mov ax,ss
     mov dl,ah
     shr dl,4
     shl ax,4
     setgdtentry

;записываем адрес возврата по адресу 0040:0067h
     push ds
     mov ax, 40h
     mov ds, ax
     mov [WORD 67h],OFFSET shutdown_return
     mov [WORD 69h],cs
     pop ds

     ret

ENDP    init_protected_mode

; ------    Переход в защищенный режим   ---------------

PROC setpm NEAR

;запрещаем все прерывания, записываем в CMOS 5 по адресу 0Fh
;для того чтобы после сброса процессора инициализировался контролер
;прерываний и управление передано по адресу из ячеек 00467h

     cli
     
     mov al, 8Fh
     out CMOS_PORT, al
     jmp short $+2
     
     mov al,5
     out CMOS_PORT+1, al

;разрешаем линию А20
     call    enable_a20
;запоминаем сегменты реального режима
     mov [real_ss], ss
     
;перепрограммируем контроллеры прерываний
;для IRQ0-IRQ7 - номера прерываний 20h-27h
     mov dx, MASTER8259A
     mov ah, 20h
     mov cl, 4

     call setint        

;для IRQ8-IRQ15 - номера прерываний 28h-2Fh
     mov dx, SLAVE8259A
     mov ah, 28h
     mov cl, 2
     call setint

;загружаем IDTR & GDTR

     lidt [FWORD idtr]
     lgdt [QWORD gdt_gdt]

;устанавливаем защищенный режим

;     mov eax, CR0     ; для 386 процессора
;     or al, 1
;     mov CR0,eax

     mov     ax,VIRTUAL_MODE    ; для 286 процессора
     lmsw    ax                 ; загрузить машинное слово

;команда  jmp far  - первая команда защ. режима
; Jmp far необходим для очищения очереди команд

     db 0EAh
     dw $+4,CS_DESCR

;загружаем селекторы в сегментные регистры
     mov ax,SS_DESCR
     mov ss,ax
     mov ax,DS_DESCR
     mov ds,ax

     enableint  ; разрешаем прерывания

     ret
ENDP setpm

;--------------- Процедура возврата в реальный режим --------
;------------------------ для i80286 ------------------------
PROC setrm286 NEAR
;запоминаем указатель стека
     mov [real_sp], sp
;сброс процессора через контролер клавиатуры

;     mov al, SHUT_DOWN
;     out STATUS_PORT, al
     
; другой вариант ( "двойная ошибка" )
	LIDT [FWORD null_idt]
	int 3
          
wait_reset:
     hlt
     jmp wait_reset

;в это место передается управление после сброса

LABEL shutdown_return FAR
;запрещаем все прерывания
     cli
     
     mov al, 8Fh
     out CMOS_PORT, al
     jmp short $+2

;инициализируем сегмент DS
     mov ax, DGROUP
     mov ds, ax
     ASSUME ds:DGROUP
;инициализируем стек 
     mov ss, [real_ss]
     mov sp, [real_sp]
     
; разрешаем прерывания
     enableint
;закрываем линию А20
     call    disable_a20
     ret

ENDP setrm286

;--------------- Процедура возврата в реальный режим --------
;------------------------ для i80386 ------------------------

PROC setrm386 NEAR
;запрещаем все прерывания
     mov [real_sp],sp
     cli
     
     lidt [fword ds:realidt] ; установка idt для реалььного  режима
     
     mov al, 8Fh
     out CMOS_PORT, al
     jmp short $+2

     mov eax, CR0     ; для 386 процессора
     and al, 0feh
     mov CR0,eax
;команда  jmp far  - первая команда реального режима
; Jmp far необходим для очищения очереди команд
      db  0eah
      dw $+4,PROTMODE_TEXT
;инициализируем сегмент DS
     mov ax, DGROUP
     mov ds, ax
     ASSUME ds:DGROUP
;инициализируем стек и ES
     mov ss, [real_ss]
     mov sp, [real_sp]
     
     enableint
;закрываем линию А20
     call    disable_a20
     ret
ENDP setrm386

;Процедура вывода сообщение в защищенном режиме

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
     mov   ah,30h    ; атрибуты символа

mt1:  lodsb
      stosw
      loop  mt1
      inc [ky]
      ret

ENDP     pwrite

PROC     rwrite near        ; cообщение об успешном завершении  в реальном
         mov    ax,DGROUP   ; режиме
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


;--------------- Заглушка для IRQ0-IRQ7 ---------------------
PROC dummy_iret0 NEAR
     push ax
     mov al,EOI
     out MASTER8259A,al
     pop ax
     iret
ENDP dummy_iret0
;--------------- Заглушка для IRQ8-IRQ15 --------------------
PROC dummy_iret1 NEAR
     push ax
     mov al,EOI
     out MASTER8259A,al
     out SLAVE8259A,al
     pop ax
     iret
ENDP dummy_iret1
;--------------- Заглушка исключений ------------------------
LABEL exc_trap WORD

     jmp shutdown

;------------- аварийное завершение по исключению -------------
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
exep    db      0dh,0ah,'Аварийное завершение по исключению'
        db      0dh,0ah,07h,'Нажмите любую клавишу$'
ENDP shutdown

;-- Процедура перепрограммирования контроллеров прерываний --
PROC setint NEAR
     mov al,11h    ;установить ICW1
     out dx,al
     jmp short $+2

     mov al,ah     ;установить ICW2 - базовый адрес
     inc dx
     out dx,al
     jmp short $+2

     mov al,cl      ;установить ICW3- MASTER/SLAVE
     out dx,al
     jmp short $+2

     mov al,1      ;установить ICW4
     out dx,al
     jmp short $+2
     mov al,0FFh   ;установка масок
     out dx,al
     dec dx

     ret
ENDP setint

CSEG_SIZE = ($-Start)
DATASEG
DSEG_SIZE = ($-DSEG_BEG)
END Start
