;------------------------------------------------------------------------------
;	ft_list_sort
;
;	DESCRIPTION:
;	goes through a list and removes all elements that return 0 when data called
;	with a cmp function with data_ref
;
;	C PROTOTYPE:
;	void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
;
;	INPUT REGISTERS:
;	rdi:	t_list **begin_list
;	rsi:	void *data_ref
;	rdx:	int (*cmp)()
;	rcx:	void (*free_fct)(void *)
;
;	CMP FUNCTION:
;	(*cmp)(list_ptr->data, data_ref);
;
;	FREE FUNCTION:
;	(*free_fct)(list_ptr->data);
;
;	NOTES:
;------------------------------------------------------------------------------

	;	NEED TO PRESERVE:
	;	rbp	HEAD	
	;	rbx	data_ref
	;	r12	prev_ptr
	;	r13	current_ptr
	;	r14 CMP
	;	r15	FREE

	global	_ft_list_remove_if

	section	.text
_ft_list_remove_if:
	push	rbp
	push	rbx
	push	r12
	push	r13
	push	r14
	push	r15

	cmp		rdi,		0
	jz		return
	cmp		rsi,		0
	jz		return
	cmp		rdx,		0
	jz		return
	cmp		rcx,		0
	jz		return

	mov		rbp,		rdi
	mov		rbx,		rsi
	xor		r12,		r12
	mov		r13,		[rbp]
	mov		r14,		rdx
	mov		r15,		rcx

call_cmp:
	cmp		r13,		0
	jz		return
	mov		rsi,		[r13]
	mov		rdi,		rbx
	push	rsp
	call	r14
	pop		rsp
	cmp		eax,		0
	jz		remove_node
	jmp		list_iterate

list_iterate:
	mov		r12,		r13
	mov		r13,		[r13+8]
	cmp		r13,		0
	jz		return
	jmp		call_cmp

remove_node:
	mov		rsi,		[r13]
	push	rsp
	call	r15
	pop		rsp
	cmp		r12,		0
	jz		remove_first
	mov		rcx,		[r13+8]
	mov		[r12+8],	rcx
	mov		r13,		rcx
	cmp		r13,		0
	jz		return
	jmp		call_cmp

remove_first:
	mov		rcx,		[r13+8]
	mov		[rbp],		rcx
	mov		r13,		[rbp]
	jmp		call_cmp

return:
	pop	r15
	pop	r14
	pop	r13
	pop	r12
	pop	rbx
	pop	rbp
	ret