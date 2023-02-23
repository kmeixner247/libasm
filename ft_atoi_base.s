;	int ft_atoi_base(char *str, char *base);
;	rdi	:	str
;	rsi	:	base
;	rdx	:	stringlength of base
;	rcx	:	index of char in base
;	TO DO:
;	base validation
;	input protection
;	comments
;	'norm'

	global _ft_atoi_base

	section .text

_ft_atoi_base:
	jmp skip_whitespace_cmp

base_length:
	xor rax, rax
	jmp strlen_cmp

asdf:
	mov rdx, rax
	xor rax, rax

basecheck:
	xor rcx, rcx

basecheck_cmp:
	cmp byte[rsi + rcx], 0
	jz return
	mov bl, byte[rsi + rcx]
	cmp byte[rdi], bl
	jne basecheck_inc
	je convert

basecheck_inc:
	inc rcx
	jmp basecheck_cmp

convert:
	imul rax, rdx
	add	rax, rcx
	inc rdi
	jmp basecheck

skip_whitespace_cmp:
	cmp byte[rdi], 9
	jz return
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
	jmp base_length

skip_whitespace_inc:
	inc rdi
	jmp skip_whitespace_cmp

strlen_cmp:
	cmp byte[rsi + rax], 0
	jne strlen_inc
	jmp asdf

strlen_inc:
	inc rax
	jmp strlen_cmp

return:
	ret