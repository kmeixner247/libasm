;------------------------------------------------------------------------------
;	ft_strdup
;
;	DESCRIPTION:
;	creates a heap-allocated copy of a string and returns a pointer to it
;
;	C PROTOTYPE:
;	char *strdup(const char *s1);
;
;	INPUT REGISTERS:
;	s1 in rdi
;
;	NOTES:
;	Not protected against NULL input, because the original (man 3 strdup) isn't
;------------------------------------------------------------------------------
	global	_ft_strdup
	extern	_malloc

	section	.text
_ft_strdup:
	xor		rax,	rax
	jmp		strlen_cmp

malloc_and_stuff:
	push	rdi
	mov		rdi,	rax
	inc		rdi
	call	_malloc
	cmp		rax,	0
	jz		return
	pop		rsi
	mov		rdi,	rax
	push	rdi
	jmp		cpy_cmp

strlen_cmp:
	cmp		byte[rdi + rax],	0
	jne		strlen_inc
	jmp		malloc_and_stuff

strlen_inc:
	inc		rax
	jmp		strlen_cmp

cpy_cmp:
	cmp		byte[rsi],	0
	jne		cpy_inc
	mov		byte[rdi],	0
	pop		rax
	jmp		return

cpy_inc:
	mov		dl,	byte[rsi]
	mov		byte[rdi],	dl
	inc		rdi
	inc		rsi
	jmp		cpy_cmp

return:
	ret