;------------------------------------------------------------------------------
;	ft_list_size
;
;	DESCRIPTION:
;	Counts nodes in a list and returns that number
;
;	LIST STRUCT:
;	typedef struct	s_list
;	{
;		void	*data;
;		struct	s_list *next;
;	}	t_list;
;
;	C PROTOTYPE:	
;	int ft_list_size(t_list *begin_list);
;
;	INPUT REGISTERS:
;	rdi	:	begin_list
;
;	NOTES:
;	Returns 0 if passed a NULL
;------------------------------------------------------------------------------

	global _ft_list_size

	section .text
_ft_list_size:
	xor		rax,		rax			;	initialize return value
	cmp		rdi,		0			;	check for NULL input
	jz		return					;	return 0 if NULL input

size_cmp:
	inc		rax						;	increment return value
	cmp		DWORD[rdi + 8],	0		;	node->next == 0
	jz		return					;	return if last node
	jmp		size_iterate

size_iterate:
	mov		rdi,		[rdi + 8]	;	move to next node of the list
	jmp		size_cmp

return:
	ret
