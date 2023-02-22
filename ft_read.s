; ssize_t read(int fildes, void *buf, size_t nbyte);

	global _ft_read
	extern ___error

	section .text
_ft_read:
	mov	rax, 0x02000003
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