;	char *strdup(const char *s1);
;	s1 in rdi
;	TODO:
;	input protection
;	comments
;	'norm'

	global _ft_strdup
	extern _malloc

	section .text
_ft_strdup:
	xor rax, rax

strlen_loop:
	cmp	byte[rdi + rax], 0
	jne strlen_increment

malloc_and_stuff:
	push rdi
	mov rdi, rax
	call _malloc
	pop rsi
	mov rdi, rax
	push rdi
	jmp cpy_loop

strlen_increment:
	inc rax
	jmp strlen_loop

cpy_loop:
	cmp byte[rsi], 0
	jne cpy_increment
	mov byte[rdi], 0
	pop rax
	ret

cpy_increment:
	mov dl, byte[rsi]
	mov byte[rdi], dl
	inc rdi
	inc rsi
	jmp cpy_loop