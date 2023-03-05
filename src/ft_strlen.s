;------------------------------------------------------------------------------
;	ft_strlen
;
;	DESCRIPTION:
;	Counts and returns the length of a string
;
;	C PROTOTYPE:
;	size_t strlen(const char *s);
;
;	INPUT REGISTERS:
;	rdi:	s
;
;	NOTES:
;	not protected against NULL input, because the original (man 3 strlen) isn't
;------------------------------------------------------------------------------

	global	_ft_strlen

	section	.text
_ft_strlen:
	xor		rax,	rax				;	initialize return value

strlen_cmp:
	cmp		byte[rdi + rax], 0		;	check for null byte
	jne 	strlen_inc				;	continue the loop if null byte not reached
	jmp		return


strlen_inc:
	inc		rax						;	increment return value
	jmp		strlen_cmp

return:
	ret