	public PROCESSOR_DETECT
	extrn  Processor32:far

DIAGNOST_TEXT	segment byte public 'CODE'
	assume	cs:DIAGNOST_TEXT
PROCESSOR_DETECT PROC far

	push bx cx dx
	pushf
	mov dx,sp
	
	push dx ax
	
	xor cl,cl                       ; processor type 0 in case of exit

	pushf                           ; transfer FLAGS to BX
	pop bx
; // seek   !!
	mov ax,bx                       ; try to clear high 4 bits of FLAGS
	and ah,0fh

	push ax                         ; transfer AX to FLAGS
	popf
	pushf                           ; transfer FLAGS back to AX
	pop ax
;//seek
	and ah,0f0h                     ; isolate high 4 bits
	cmp ah,0f0h
	je short @@detect_processordone ; if bits are set, CPU is 8086/8

	mov cl,2                        ; processor type 2 in case of exit

	or bh,0f0h                      ; try to set high 4 bits of FLAGS

	push bx                         ; transfer BX to FLAGS
	popf
	pushf                           ; transfer FLAGS to AX
	pop ax
;//seek
	and ah,0f0h                     ; isolate high 4 bits
	jz short @@detect_processordone ; if bits are not set, CPU is 80286
	call Processor32

@@detect_processordone:

	mov sp,dx
	popf
	mov ax,cx	
	pop dx cx bx
	ret                             ; return
PROCESSOR_DETECT endp
DIAGNOST_TEXT	ends
	end



