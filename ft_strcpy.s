;	char *	strcpy(char *dst, const char *src);
;	dst: rdi, src: rsi

	global _ft_strcpy

	section .text
_ft_strcpy:
;protection?
	push rdi

loop:
	cmp byte[rsi], 0
	jne copy
	mov byte[rdi], 0
	pop rax
	ret

copy:
	mov dl, byte[rsi]
	mov byte[rdi], dl
	inc rdi
	inc rsi
	jmp loop

