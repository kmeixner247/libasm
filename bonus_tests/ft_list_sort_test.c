#include "../libasm.h"
#include "bonus_tests.h"
#include "../tests/tests.h"

void list_sort_test_ft() {
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

	char *c0 = "1";
	char *c1 = "8";
	char *c2 = "4";
	char *c3 = "5";
	char *c4 = "3";
	char *c5 = "2";
	char *c6 = "9";
	char *c7 = "7";
	char *c8 = "0";
	char *c9 = "6";

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

	FILE *fptr = fopen("bonus_tests/ft_list_sort/0_bigtest_ft", "w");
	t_list *head = &l0;
	ft_list_sort(&head, &strcmp);
	list_to_file(head, fptr);
	fclose(fptr);
}
void list_sort_test_st() {
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

	char *c0 = "0";
	char *c1 = "1";
	char *c2 = "2";
	char *c3 = "3";
	char *c4 = "4";
	char *c5 = "5";
	char *c6 = "6";
	char *c7 = "7";
	char *c8 = "8";
	char *c9 = "9";

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

	FILE *fptr = fopen("bonus_tests/ft_list_sort/0_bigtest_st", "w");
	list_to_file(&l0, fptr);
	fclose(fptr);
}


void test_list_sort() {
	list_sort_test_ft();
	list_sort_test_st();
}