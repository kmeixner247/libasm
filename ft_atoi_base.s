;------------------------------------------------------------------------------
;	ft_atoi_base
;
;	DESCRIPTION:
;
;	C PROTOTYPE:
;	int ft_atoi_base(char *str, char *base);
;
;	INPUT REGISTERS:
;	rdi	:	str
;	rsi	:	base
;------------------------------------------------------------------------------
;	I want to return strlen
;	r8	baselen
;	using al and rcx to compare rn
	global _ft_atoi_base

	section .text
_ft_atoi_base:
	push	rbx
	cmp		rdi,		0
	jz		error
	cmp		rsi,		0
	jz		error
	jmp		val_base

val_base:
	xor		rax,		rax
	mov		r8,			rsi
	jmp		val_outer

val_outer:
	mov		al,			byte[r8]
	cmp		al,		 	0
	jz		get_baselength
	cmp		al,			9
	je		error
	cmp		al,			10
	je		error
	cmp		al,			11
	je		error
	cmp		al,			12
	je		error
	cmp		al,			13
	je		error
	cmp		al,			32
	je		error
	cmp		al,			43
	je		error
	cmp		al,			45
	je		error
	mov		rcx,		r8
	jmp		val_inner_inc

val_inner:
	cmp		al,			byte[rcx]
	je		error
	jmp		val_inner_inc

val_inner_inc:
	inc		rcx
	cmp		byte[rcx],	0
	jz		val_outer_inc
	jmp		val_inner

val_outer_inc:
	inc		r8
	jmp		val_outer

get_baselength:
	sub		r8,		rsi
	cmp		r8,		2
	jl		error
	jmp		skip_whitespace_cmp

skip_whitespace_cmp:
	cmp byte[rdi], 9
	je skip_whitespace_inc
	cmp byte[rdi], 10
	je skip_whitespace_inc
	cmp byte[rdi], 11
	je skip_whitespace_inc
	cmp byte[rdi], 12
	je skip_whitespace_inc
	cmp byte[rdi], 13
	je skip_whitespace_inc
	cmp byte[rdi], 32
	je skip_whitespace_inc
	jmp handle_sign

skip_whitespace_inc:
	inc rdi
	jmp skip_whitespace_cmp

handle_sign:
	mov		r10,			1
	cmp		byte[rdi],		43
	je		skip_plus
	cmp		byte[rdi],		45
	je		skip_minus
	jmp		check_base_init

skip_plus:
	inc		rdi
	jmp		check_base_init

skip_minus:
	inc		rdi
	mov		r10,			-1
	jmp		check_base_init

check_base_init:
	xor		rbx,		rbx
	xor		rax,		rax
	jmp		check_base

check_base:
	xor		rcx,		rcx
	jmp		check_base_cmp

check_base_cmp:
	cmp		byte[rsi + rcx], 0
	jz		return
	mov		bl, byte[rsi + rcx]
	cmp		byte[rdi], bl
	jne		check_base_inc
	je		check_base_convert

check_base_inc:
	inc		rcx
	jmp		check_base_cmp

check_base_convert:
	imul	rax,		r8
	add		rax,		rcx
	inc		rdi
	jmp		check_base

error:
	pop		rbx
	xor		rax,		rax
	ret

return:
	imul	rax,		r10
	pop		rbx
	ret

test:
	pop		rbx
	mov		rax,		123
	ret