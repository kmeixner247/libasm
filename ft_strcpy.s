;------------------------------------------------------------------------------
;	ft_strcpy
;
;	DESCRIPTION:
;	Copies all bytes from a source string into a destination string
;
;	C PROTOTYPE:
;	char *	strcpy(char *dst, const char *src);
;
;	INPUT REGISTERS:
;	rdi:	dst
;	rsi:	src
;
;	NOTES:
;	Not protected against NULL input, because the original (man 3 strcpy) isn't
;	Not protected against dst overflow
;------------------------------------------------------------------------------

	global _ft_strcpy

	section .text
_ft_strcpy:
	push	rdi				;	save dst pointer to restore later

strcmp_cmp:
	cmp		byte[rsi], 0	;	check for null terminator of src
	je		return			;	return if null terminator reached
	jmp		strcmp_inc

strcmp_inc:
	mov		dl, byte[rsi]	;	temp = *src
	mov		byte[rdi], dl	;	*dest = temp
	inc		rdi				;	dest++
	inc		rsi				;	src++
	jmp		strcmp_cmp

return:
	mov		byte[rdi], 0	;	add null terminator to dest string
	pop		rax				;	restore dst pointer from stack
	ret