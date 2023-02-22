; ssize_t write(int fildes, const void *buf, size_t nbyte);
; fildes rdi  - buf rsi - nbyte rdx

	global _ft_write
	extern ___error
	
	section .text

_ft_write:
	mov	rax, 0x02000004
	syscall
	jc error
	ret

error:
	push rax
	call ___error
	mov rdi, rax
	pop rax
	mov [rdi], rax
	mov rax, -1
	ret