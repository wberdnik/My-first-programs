; 		Бердник В.Л.   

;------------------------------------------------------------------------------

	 .model tiny
	 .code
	 org 100h
start:	jmp	begin
coob	db 'В памяти возможен OneHalf' 
old	dd	?
	
vect 	PROC	far
	push	es
	push	si
	push	di
	xor	si,si
	mov	es,si
	mov	si,413h
	mov	di,word ptr es:[si]	
	cmp	di,027fh
	jb	poo3
	jmp	exit
	
poo3:	push	ax
	push	cx
	push	ds
	push	cs
	pop	ds
	lea	si,coob		; установка указателя на строку
	mov	ax,0b800h	; установка указателя на видеобуфер
	mov	es,ax
	mov	di,60d		;; 30stolb+0ctr*80stolb    * 2
	mov	ah,1ah		;; (фон*16)+text 1 - синий  6-коричневый
	mov	cx,18d		; длина первого слова
poo1:	lodsb			; печать слова
	stosw
	loop	poo1
	mov	ah,0ch		;; (фон*16)+text 1 - синий  6-коричневый
	mov	cx,7		; длина первого слова
poo2:	lodsb			; печать слова
	stosw
	loop	poo2
	
	pop	ds
	pop	cx
	pop	ax
	
exit:	pop	di
	pop	si
	pop	es	
	jmp	cs:[old]
vect	ENDP	

begin:
	MOV  DX,OFFSET Report   ; Report на экран
	mov	ah,09h
	int	21h
;-------------------------------------------------------------------------------
        mov     ax,3509h       		 ; Взять вектор 09h
        int     21h 
        mov     WORD PTR old,bx    ; Сохранить старый вектор
        mov     WORD PTR old+2,es  

        mov     ax,2509h        	; Установить
        lea     dx,vect			; свой
        int     21h            		; вектор

        lea     dx,begin       		; Смещение начала нерезидентной части
        int	27h
        
Report DB 10,13
 DB '                ╔═════════════════════════════════════════════╗ ',10,13
 DB '                ║          Г р у п п а   В Т - 4 6 2          ║ ',10,13
 DB '                ║         Бердник В.Л.                        ║ ',10,13
 DB '                ║        Проверка обьема свободной памяти     ║ ',10,13
 DB '                ║                                             ║ ',10,13
 DB '                ╚═════════════════════════════════════════════╝ $'
;===============================================================================
;-------------------------------------------------------------------------------

	end     start

	
		
	