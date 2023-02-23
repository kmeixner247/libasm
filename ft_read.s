;------------------------------------------------------------------------------
;	ft_read
;
;	DESCRIPTION:
;	C PROTOTYPE:
;	ssize_t read(int fildes, void *buf, size_t nbyte);
;
;	INPUT REGISTERS:
;	rdi	:	fildes
;	rsi	:	buf 
;	rdx	:	nbyte
;------------------------------------------------------------------------------

	global	_ft_read
	extern	___error

	section	.text
_ft_read:
	mov		rax,	0x02000003	;	prepare syscall read
	syscall
	jc		error				;	check for error flag
	jmp		return				;	return read return otherwise

error:
	push	rax					;	store read return (error code) on stack
	call	___error			;	call to find errno memory location
	mov		rdi, rax			;	save errno memory location in rdi
	pop		rax					;	restore error code
	mov		[rdi], rax			;	write error code into errno
	mov		rax, -1				;	prepare return value -1
	jmp		return

return:
	ret