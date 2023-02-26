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
	xor		rax,	rax				;	set rax to 0
	jmp		strlen_cmp				;	get length of input string

malloc:
	push	rdi						;	store s1 pointer
	mov		rdi,	rax				;	prepare length parameter for malloc
	inc		rdi						;	i
	call	_malloc					;	extern malloc call
	cmp		rax,	0				;	check fur malloc error return
	jz		return					;	return if null
	pop		rsi						;	restore s1 pointer
	mov		rdi,	rax				;	move allocated memory address to rdi
	push	rdi						;	store pointer to new memory for return
	jmp		cpy_cmp

strlen_cmp:
	cmp		byte[rdi + rax],	0	;	check for null terminator
	jne		strlen_inc				;	if \0 not reached, keep incrementing
	jmp		malloc					;	otherwise, go to malloc

strlen_inc:
	inc		rax						;	i++
	jmp		strlen_cmp

cpy_cmp:
	cmp		byte[rsi],	0			;	check for null terminator of source
	jne		cpy_inc					;	continue copying if null not reached
	mov		byte[rdi],	0			;	terminate dest string
	pop		rax						;	restore pointer to new alloced memory
	jmp		return

cpy_inc:
	mov		dl,	byte[rsi]			;	tmp = *src
	mov		byte[rdi],	dl			;	*dst = tmp
	inc		rdi						;	dst++
	inc		rsi						;	src++
	jmp		cpy_cmp

return:
	ret