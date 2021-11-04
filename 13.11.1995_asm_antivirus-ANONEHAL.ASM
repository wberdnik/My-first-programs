;------------------------------------------------------------------------------

	 .model tiny
	 .code
	 org 100h
start:	jmp	begin
coob	db '‚ OneHalf presents in memory' 
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
	lea	si,coob		
	mov	ax,0b800h	; video
	mov	es,ax
	mov	di,60d		;; 30stolb+0ctr*80stolb    * 2
	mov	ah,1ah		;; (ä®­*16)+text
	mov	cx,18d		 
poo1:	lodsb			 
	stosw
	loop	poo1
	mov	ah,0ch		
	mov	cx,7		 
poo2:	lodsb			
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
	MOV  DX,OFFSET Report   ; Report ­  íªà ­
	mov	ah,09h
	int	21h
;-------------------------------------------------------------------------------
        mov     ax,3509h       		 ; stay native
        int     21h 
        mov     WORD PTR old,bx    
        mov     WORD PTR old+2,es  

        mov     ax,2509h        	
        lea     dx,vect			
        int     21h            		

        lea     dx,begin       		
        int	27h
        
Report DB 10,13
 DB '                ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ» ',10,13
 DB '                º          VT - 4 6 2                         º ',10,13
 DB '                º          Antivirus                          º ',10,13
 DB '                º        Vladislav Berdnik                    º ',10,13
 DB '                º                                             º ',10,13
 DB '                ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼ $'
;===============================================================================
;-------------------------------------------------------------------------------

	end     start
