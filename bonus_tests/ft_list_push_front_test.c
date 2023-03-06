#include "../libasm.h"
#include "bonus_tests.h"
#include "../tests/tests.h"

static void list_push_front_test_ft() {
	FILE *fptr = fopen("bonus_tests/ft_list_push_front/0_bigtest_ft", "w");

	char *c0 = "ZERO";
	char *c1 = "ONE";
	char *c2 = "TWO";
	char *c3 = "THREE";
	char *c4 = "FOUR";
	char *c5 = "FIVE";
	char *c6 = "SIX";
	char *c7 = "SEVEN";
	char *c8 = "EIGHT";
	char *c9 = "NINE";

	t_list *lst = malloc(sizeof(t_list));
	lst->data = c9;
	lst->next = NULL;

	t_list *head = lst;
	list_to_file(head, fptr);
	ft_list_push_front(&head, c8);
	list_to_file(head, fptr);
	ft_list_push_front(&head, c7);
	list_to_file(head, fptr);
	ft_list_push_front(&head, c6);
	list_to_file(head, fptr);
	ft_list_push_front(&head, c5);
	list_to_file(head, fptr);
	ft_list_push_front(&head, c4);
	list_to_file(head, fptr);
	ft_list_push_front(&head, c3);
	list_to_file(head, fptr);
	ft_list_push_front(&head, c2);
	list_to_file(head, fptr);
	ft_list_push_front(&head, c1);
	list_to_file(head, fptr);
	ft_list_push_front(&head, c0);
	list_to_file(head, fptr);
	fclose(fptr);
	ft_listclear(&head);
}

static void list_push_front_test_st() {
	t_list l0;
	t_list l1;
	t_list l2;
	t_list l3;
	t_list l4;
	t_list l5;
	t_list l6;
	t_list l7;
	t_list l8;
	t_list l9;

	char *c0 = "ZERO";
	char *c1 = "ONE";
	char *c2 = "TWO";
	char *c3 = "THREE";
	char *c4 = "FOUR";
	char *c5 = "FIVE";
	char *c6 = "SIX";
	char *c7 = "SEVEN";
	char *c8 = "EIGHT";
	char *c9 = "NINE";

	l0.data = c0;
	l0.next = &l1;

	l1.data = c1;
	l1.next = &l2;

	l2.data = c2;
	l2.next = &l3;

	l3.data = c3;
	l3.next = &l4;

	l4.data = c4;
	l4.next = &l5;

	l5.data = c5;
	l5.next = &l6;

	l6.data = c6;
	l6.next = &l7;

	l7.data = c7;
	l7.next = &l8;

	l8.data = c8;
	l8.next = &l9;

	l9.data = c9;
	l9.next = NULL;

	FILE *fptr = fopen("bonus_tests/ft_list_push_front/0_bigtest_st", "w");
	list_to_file(&l9, fptr);
	list_to_file(&l8, fptr);
	list_to_file(&l7, fptr);
	list_to_file(&l6, fptr);
	list_to_file(&l5, fptr);
	list_to_file(&l4, fptr);
	list_to_file(&l3, fptr);
	list_to_file(&l2, fptr);
	list_to_file(&l1, fptr);
	list_to_file(&l0, fptr);
	fclose(fptr);
}

void test_list_push_front() {
	list_push_front_test_ft();
	list_push_front_test_st();
}