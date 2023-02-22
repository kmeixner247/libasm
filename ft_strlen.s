

	global _ft_strlen

	section .text
_ft_strlen:
	xor rax, rax				; set rax to 0, storing the length
	dec rax					; reduce rax by 1 for first increment

loop:
	inc rax					;
	cmp	byte[rdi + rax], 0	; check for null byte
	jne loop				; continue the loop if null byte not reached

	ret						; return (why is it rax?)