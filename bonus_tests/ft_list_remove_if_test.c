#include "../libasm.h"
#include "bonus_tests.h"
#include "../tests/tests.h"

void list_remove_if_test_ft() {
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

	char *c0 = strdup("ZERO");
	char *c1 = strdup("ONE");
	char *c2 = strdup("ONE");
	char *c3 = strdup("TWO");
	char *c4 = strdup("THREE");
	char *c5 = strdup("FOUR");
	char *c6 = strdup("FOUR");
	char *c7 = strdup("FOUR");
	char *c8 = strdup("FOUR");
	char *c9 = strdup("FIVE");

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

	FILE *fptr = fopen("bonus_tests/ft_list_remove_if/0_bigtest_ft", "w");
	t_list *head = &l0;
	list_to_file(head, fptr);
	ft_list_remove_if(&head, "TEN", &strcmp, &free);
	list_to_file(head, fptr);
	ft_list_remove_if(&head, "TWO", &strcmp, &free);
	list_to_file(head, fptr);
	ft_list_remove_if(&head, "FIVE", &strcmp, &free);
	list_to_file(head, fptr);
	ft_list_remove_if(&head, "ZERO", &strcmp, &free);
	list_to_file(head, fptr);
	ft_list_remove_if(&head, "ONE", &strcmp, &free);
	list_to_file(head, fptr);
	ft_list_remove_if(&head, "FOUR", &strcmp, &free);
	list_to_file(head, fptr);
	ft_list_remove_if(&head, "THREE", &strcmp, &free);
	list_to_file(head, fptr);
	fclose(fptr);
}
void list_remove_if_test_st() {
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

	char *c0 = strdup("ZERO");
	char *c1 = strdup("ONE");
	char *c2 = strdup("ONE");
	char *c3 = strdup("TWO");
	char *c4 = strdup("THREE");
	char *c5 = strdup("FOUR");
	char *c6 = strdup("FOUR");
	char *c7 = strdup("FOUR");
	char *c8 = strdup("FOUR");
	char *c9 = strdup("FIVE");

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

	FILE *fptr = fopen("bonus_tests/ft_list_remove_if/0_bigtest_st", "w");
	t_list *head = &l0;
	list_to_file(head, fptr);
	list_to_file(head, fptr);
	l2.next = &l4;
	list_to_file(head, fptr);
	l8.next = NULL;
	list_to_file(head, fptr);
	head = &l1;
	list_to_file(head, fptr);
	head = &l4;
	list_to_file(head, fptr);
	l4.next = NULL;
	list_to_file(head, fptr);
	head = NULL;
	list_to_file(head, fptr);
	fclose(fptr);
	free(c0);
	free(c1);
	free(c2);
	free(c3);
	free(c4);
	free(c5);
	free(c6);
	free(c7);
	free(c8);
	free(c9);
}


void test_list_remove_if() {
	list_remove_if_test_ft();
	list_remove_if_test_st();
}