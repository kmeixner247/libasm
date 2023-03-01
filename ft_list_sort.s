;------------------------------------------------------------------------------
;	ft_list_sort
;
;	DESCRIPTION:
;	sorts a list by ascending order by comparing data of nodes with a function
;
;	C PROTOTYPE:
;	void ft_list_sort(t_list **begin_list, int (*cmp)());
;
;	INPUT REGISTERS:
;	rdi:	begin_list (head)
;	rsi:	(*cmp)(list_ptr->data, list_other_ptr->data);
;
;	NOTES:
;------------------------------------------------------------------------------

	;	NEED TO PRESERVE:
	;	rbp	HEAD
	;	rbx	MAX
	;	r12	curr node for cmp
	;	r13	next node for cmp
	;	r14	max-from-before
	;	r15 prev-to-max
;
	global _ft_list_sort

	section	.text
_ft_list_sort:
	push	rbp
	push	rbx
	push	r12
	push	r13
	push	r14
	push	r15

	mov		rbp,		rdi			;	init	HEAD
	mov		rax,		rsi			;	init	CMP
	xor		r14,		r14			;	init	max-from-before
	mov		r12,		[rbp]		;	init	curr
	cmp		r12,		0			;	empty list case
	jz		return
	jmp		find_max

find_max:
	xor		r15,		r15			;	init prevmax as 0
	mov		r12,		[rbp]		;	init curr for loop
	mov		r13,		[r12+8]		;	init next for loop
	mov		rbx,		r12			;	init max for loop
	cmp		r13,		0			;	if next is 0, curr is min element
	jz		finish
	jmp		call_cmp

call_cmp:
	mov		rsi,		[rbx]		;	load content of max
	mov		rdi,		[r13]		;	load content0x602000000150 of next
	push	rax						;	save cmp ptr
	call	rax						;	call cmp
	cmp		eax,		0			;	check cmp return
	jg		new_max					;	if return > 0, new max
	jmp		list_iterate

list_iterate:
	pop		rax						;	restore cmp ptr
	mov		r12,		r13			;	curr = next
	mov		r13,		[r13+8]		;	next = next->next
	cmp		r13,		0			;	if next is 0, end of list is reached
	jz		remove_max
	jmp		call_cmp

new_max:
	mov		rbx,		r13			;	replace MAX with new max
	mov		r15,		r12			;	replace prevmax
	jmp		list_iterate

remove_max:
	cmp		r15,		0			;	if max is first element, prevmax is 0
	jz		remove_first
	mov		rcx,		[rbx+8]		;	temp = max->next
	mov		[r15+8],	rcx			;	prevtomax-next = temp
	jmp		add_to_newlist

add_to_newlist:
	mov		[rbx+8],	r14			;	max->next = maxfromprev
	mov		r14,		rbx			;	maxfromprev = max
	jmp		find_max

remove_first:
	mov		rcx,		[rbx+8]		;	temp = max->next
	mov		[rbp],		rcx			;	*head = temp
	jmp		add_to_newlist

finish:
	mov		[r12+8],	r14			;	curr->next = maxfromprev
	mov		[rbp],		r12			;	*head = curr
	jmp		return

return:
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	pop		rbx
	pop		rbp
	ret