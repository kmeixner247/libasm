#include "../libasm.h"
#include "bonus_tests.h"

void list_to_file(t_list *lst, FILE *fptr) {
	if (!lst)
		fprintf(fptr, "NULL");
	while (lst) {
		fprintf(fptr, "%s\n", lst->data);
		lst = lst->next;
	}
}

void	ft_listclear(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	if (!lst)
		return ;
	temp = *lst;
	while (temp)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	*lst = NULL;
	return ;
}
