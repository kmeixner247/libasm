;------------------------------------------------------------------------------
;	ft_atoi_base
;
;	DESCRIPTION:
;	Converts the first number of a string given in a specified base to decimal
;	and returns that. The number may be preceded by whitespace and one optional
;	'+' or '-'
;
;	C PROTOTYPE:
;	int ft_atoi_base(char *str, char *base);
;
;	INPUT REGISTERS:
;	rdi	:	str
;	rsi	:	base
;
;	OTHER USED REGISTERS:
;	rax	:	temp for baselength, return value
;	rcx :	temp s2 for base validation
;	r8	:	temp s1 for base validation, baselength
;	r10	:	sign
;	bl	:	temp char
;
;------------------------------------------------------------------------------

	global _ft_atoi_base

	section .text
_ft_atoi_base:
	push	rbx								;	need to preserve rbx
	cmp		rdi,		0					;	input protection str
	jz		error
	cmp		rsi,		0					;	input protection base
	jz		error
	jmp		val_base

val_base:
	xor		rax,		rax					;	initialize rax=0 for baselen
	mov		r8,			rsi					;	initialize base ptr for val 
	jmp		val_outer

val_outer:
	mov		al,			byte[r8]			;	temp = *s1
	cmp		al,		 	0					;	temp == 0 means end of base
	jz		get_baselength
	cmp		al,			9					;	*s1 == '\t'
	je		error
	cmp		al,			10					;	*s1 == '\n'
	je		error
	cmp		al,			11					;	*s1 == '\v'
	je		error
	cmp		al,			12					;	*s1 == '\f'
	je		error
	cmp		al,			13					;	*s1 == '\r'
	je		error
	cmp		al,			32					;	*s1 == ' '
	je		error
	cmp		al,			43					;	*s1 == '+'
	je		error
	cmp		al,			45					;	*s1 == '-'
	je		error
	mov		rcx,		r8					;	if *s1 is valid, init s2
	jmp		val_inner_inc

val_inner:
	cmp		al,			byte[rcx]			;	compare *s1 == *s2
	je		error							;	equal means duplicate in base
	jmp		val_inner_inc					;	otherwise keep incrementing

val_inner_inc:
	inc		rcx								;	s2++
	cmp		byte[rcx],	0					;	null means end of string
	jz		val_outer_inc
	jmp		val_inner

val_outer_inc:
	inc		r8								;	s1++
	jmp		val_outer

get_baselength:
	sub		r8,		rsi						;	s1 - baseptr = baselength
	cmp		r8,		2						;	if baselength < 2, invalid base
	jl		error
	jmp		skip_whitespace_cmp				;	else move on to skip whitespace

skip_whitespace_cmp:
	cmp byte[rdi], 9						;	*s == '\t'
	je skip_whitespace_inc
	cmp byte[rdi], 10						;	*s == '\n'
	je skip_whitespace_inc
	cmp byte[rdi], 11						;	*s == '\v'
	je skip_whitespace_inc
	cmp byte[rdi], 12						;	*s == '\f'
	je skip_whitespace_inc
	cmp byte[rdi], 13						;	*s == '\r'
	je skip_whitespace_inc
	cmp byte[rdi], 32						;	*s == ' '
	je skip_whitespace_inc
	jmp handle_sign							;	if none of that whitespace done

skip_whitespace_inc:
	inc rdi
	jmp skip_whitespace_cmp

handle_sign:
	mov		r10,			1
	cmp		byte[rdi],		43				;	*s == '+'
	je		skip_plus
	cmp		byte[rdi],		45				;	*s == '-'
	je		skip_minus
	jmp		check_base_init					;	if neither, number is reached

skip_plus:
	inc		rdi								;	if plus, just increment
	jmp		check_base_init

skip_minus:
	inc		rdi
	mov		r10,			-1				;	if minus, sign = -1
	jmp		check_base_init

check_base_init:
	xor		rbx,		rbx					;	initalizing rbx for temp
	xor		rax,		rax					;	init rax=0 for return value
	jmp		check_base

check_base:
	xor		rcx,		rcx					;	init rcx for base index
	jmp		check_base_cmp

check_base_cmp:
	cmp		byte[rsi + rcx], 0				;	*(s + ind) == 0
	jz		return
	mov		bl, byte[rsi + rcx]				;	temp = *(s + ind)
	cmp		byte[rdi], bl					;	*s == temp
	jne		check_base_inc					;	if not equal, keep searching
	je		check_base_convert

check_base_inc:
	inc		rcx								;	ind++
	jmp		check_base_cmp

check_base_convert:
	imul	rax,		r8					;	result *= baselength
	add		rax,		rcx					;	result += index
	inc		rdi								;	s++
	jmp		check_base

error:
	pop		rbx								;	restore rbx
	xor		rax,		rax					;	result = 0
	ret

return:
	imul	rax,		r10					;	result *= sign
	pop		rbx								;	restore rbx
	ret