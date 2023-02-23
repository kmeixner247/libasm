;	strcmp(const char *s1, const char *s2);
;	s1: rdi, s2: rsi
;	TODO:
;	input protection
;	comments
;	'norm'
	global _ft_strcmp

	section .text
_ft_strcmp:
;protection?

compare:
	mov		dl, byte[rsi]
	cmp		byte[rdi], dl
	je		increment
	jl		less
	jg		more

increment:
	jz		same
	inc		rdi
	inc		rsi
	jmp		compare

less:
	mov		rax, -1
	ret

more:
	mov		rax, 1
	ret

same:
	xor		rax, rax
	ret