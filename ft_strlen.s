;	TODO
;	comments
;	'norm'

	global _ft_strlen

	section .text
_ft_strlen:
	xor rax, rax				; set rax to 0, storing the length

loop:
	cmp	byte[rdi + rax], 0		; check for null byte
	jne increment				; continue the loop if null byte not reached

	ret							; return (why is it rax?)

increment:
	inc rax
	jmp loop