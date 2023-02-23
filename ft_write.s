;------------------------------------------------------------------------------
;	DESCRIPTION:
;	C PROTOTYPE:
;	ssize_t write(int fildes, const void *buf, size_t nbyte);
;
;	INPUT REGISTERS:
;	rdi	:	fildes
;	rsi	:	buf 
;	rdx	:	nbyte
;------------------------------------------------------------------------------
	global	_ft_write
	extern	___error
	
	section	.text
_ft_write:
	mov		rax, 0x02000004	;	prepare syscall write
	syscall
	jc		error			;	check for error flag
	jmp		return

error:
	push	rax				;	store write return value (error code) on stack
	call	___error		;	call to find errno memory location
	mov		rdi, rax		;	save errno memory location in rdi
	pop		rax				;	restore error code
	mov		[rdi], rax		;	write error code into errno
	mov		rax, -1			;	prepare return value -1
	jmp		return

return:
	ret