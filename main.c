/*	TODO:
/	more tests
/	better tests
*/

#include "libasm.h"
#include "tests/tests.h"

// void print_list(t_list **head)
// {
// 	t_list *temp = *head;
// 	int i = 1;
// 	while (temp)
// 	{
// 		printf("%d: %s %p\n", i, temp->data, temp);
// 		i++;
// 		temp = temp->next;
// 	}
// }

int main(void)
{
	test_strlen();
	test_strcmp();
	test_strcpy();
	return 0;
}