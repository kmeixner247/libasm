;------------------------------------------------------------------------------
;	ft_list_push_front
;
;	DESCRIPTION:
;	Creates a new t_list node with given data
;	and inserts it at the beginning of a list
;
;	LIST STRUCT:
;	typedef struct s_list
;	{
;		void *data;
;		struct s_list *next;
;	} t_list;
;
;	C PROTOTYPE:
;	void ft_list_push_front(t_list **begin_list, void *data)
;
;	INPUT REGISTERS:
;	rdi	:	begin_list
;	rsi	:	data
;------------------------------------------------------------------------------

			global	_ft_list_push_front
			extern	_malloc

			section	.text

_ft_list_push_front:
			push	rsp						;	save stack pointer to restore later
			push	rdi						;	save begin_list on stack
			push	rsi						;	save data on stack
			mov		rdi,		list_size	;	prepare argument for malloc
			call	_malloc					;	call malloc with sizeof(t_list)
			pop		rsi						;	get back data from stack
			pop		rdi						;	get back begin_list from stack
			cmp		rax,		0			;	check for NULL return from malloc
			jz		return					;	return if NULL
			mov		rcx,		[rdi]		;	temp = *begin_list
			mov		[rax],		rsi			;	*new = data
			mov		[rax + 8],	rcx			;	*(new + 8) = temp
			mov		[rdi],		rax			;	*begin_list = new

return:
			pop		rsp						;	restore stack pointer
			ret

			section	.data
list_size:	equ		16