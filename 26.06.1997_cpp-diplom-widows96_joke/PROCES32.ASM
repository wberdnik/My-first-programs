	.386p
DIAGNOST_TEXT	segment byte public 'CODE'
	assume	cs:DIAGNOST_TEXT
Processor32 PROC far
	inc cx                          ; processor type 3 in case of exit

	push eax ebx edx                ; preserve 32bit registers
	pushfd
	mov dx,sp

	push dx
	push dx

	pushfd                          ; transfer EFLAGS to EBX
	pop ebx

	mov eax,ebx                     ; try to flip AC bit in EFLAGS
	xor eax,40000h

	push eax                        ; transfer EAX to EFLAGS
	popfd
	pushfd                          ; transfer EFLAGS back to EAX
	pop eax
;// seek +4
	xor eax,ebx                     ; AC bit fliped?
	jz short @@detect_processordone2; if no, CPU is 386

	inc cx                          ; processor type 4 in case of exit

	mov eax,ebx                     ; try to flip ID bit in EFLAGS
	xor eax,200000h

	push eax                        ; transfer EAX to EFLAGS
	popfd
	pushfd                          ; transfer EFLAGS back to EAX
	pop eax
;//seek
	xor eax,ebx                     ; ID bit fliped?
	jz short @@detect_processordone2; if no, CPU is 486

	inc cx                          ; processor type 5, CPU is 586

@@detect_processordone2:
	mov sp,dx
	popfd
	pop edx ebx eax                 ; restore 32bit registers
	ret                             ; return
Processor32 endp
DIAGNOST_TEXT	ends
	public	Processor32
	end



