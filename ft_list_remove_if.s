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

	cmp		rdi,		0					;	head input protection
	jz		return
	cmp		rsi,		0					;	data_ref input protection
	jz		return
	cmp		rdx,		0					;	cmp input protection
	jz		return
	cmp		rcx,		0					;	free_fct input protection
	jz		return

	mov		rbp,		rdi					;	init head
	mov		rbx,		rsi					;	init data_ref
	xor		r12,		r12					;	init prev_ptr = 0
	mov		r13,		[rbp]				;	init current_pointer = *head
	mov		r14,		rdx					;	init cmp
	mov		r15,		rcx					;	init free_fct

call_cmp:
	cmp		r13,		0					;	null protection for curr ptr
	jz		return
	mov		rsi,		[r13]				;	load content of curr ptr
	mov		rdi,		rbx					;	load data_ref
	push	rsp								;	align stack
	call	r14								;	call cmp
	pop		rsp								;	undo stack align push
	cmp		eax,		0					;	check cmp return value
	jz		remove_node						;	if return 0, delete the node
	jmp		list_iterate					;	else continue through the list

list_iterate:
	mov		r12,		r13					;	prev = curr
	mov		r13,		[r13+8]				;	curr = curr->next
	cmp		r13,		0					;	check if curr == 0
	jz		return							;	in that case end is reached
	jmp		call_cmp						;	else keep comparing

remove_node:
	mov		rdi,		[r13]				;	load curr->data for free
	push	rsp								;	align stack
	call	r15								;	call free function
	pop		rsp								;	undo stack align push
	cmp		r12,		0					;	if prev is 0, curr is first
	jz		remove_first
	mov		rcx,		[r13+8]				;	temp = curr->next
	mov		[r12+8],	rcx					;	prev->next = temp
	mov		r13,		rcx					;	curr = temp (next)
	cmp		r13,		0					;	check if curr == 0
	jz		return							;	in that case end is reached
	jmp		call_cmp						;	else keep comparing

remove_first:
	mov		rcx,		[r13+8]				;	temp = curr->next
	mov		[rbp],		rcx					;	*head = temp
	mov		r13,		rcx					;	curr = temp (next)
	jmp		call_cmp

return:
	pop	r15
	pop	r14
	pop	r13
	pop	r12
	pop	rbx
	pop	rbp
	ret