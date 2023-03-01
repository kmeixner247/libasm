;------------------------------------------------------------------------------
;	ft_strcmp
;
;	DESCRIPTION:
;	Compares two strings. Returns 0 if equal, 1 if s1>s2 and -1 if s1<s2
;
;	C PROTOTYPE:
;	strcmp(const char *s1, const char *s2);
;
;	INPUT REGISTERS:
;	rdi	:	s1
;	rsi	:	s2
;
;	NOTES:
;	Not protected against NULL input, because the original (man 3 strcmp) isn't
;------------------------------------------------------------------------------

	global	_ft_strcmp

	section	.text
_ft_strcmp:

strcmp_cmp:
	mov		dl, byte[rsi]	;	temp = *s2
	cmp		byte[rdi], dl	;	compare *s1 with temp
	je		strcmp_inc		;	if equal, increment and continue
	jl		less			;	if *s1<temp, jump to less
	jg		more			;	if *s1>temp, jump to more

strcmp_inc:
	jz		same			;	if *s1 == 0, both strings are the same
	inc		rdi				;	s1++
	inc		rsi				;	s2++
	jmp		strcmp_cmp		;	

less:
	mov		eax, -1			;	returning -1 if s1<s2
	jmp		return

more:
	mov		eax, 1			;	returning 1 if s1>s2
	jmp		return

same:
	xor		eax, eax		;	returning 0 if s1 == s2
	jmp		return

return:
	ret