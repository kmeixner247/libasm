#include "../libasm.h"
#include "bonus_tests.h"
#include "../tests/tests.h"

static void list_size_test_ft() {
	FILE *fptr = fopen("bonus_tests/ft_list_size/0_bigtest_ft", "w");

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

	l0.next = &l1;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	l7.next = &l8;
	l8.next = &l9;
	l9.next = NULL;

	fprintf(fptr, "%d\n", ft_list_size(NULL));
	fprintf(fptr, "%d\n", ft_list_size(&l9));
	fprintf(fptr, "%d\n", ft_list_size(&l8));
	fprintf(fptr, "%d\n", ft_list_size(&l7));
	fprintf(fptr, "%d\n", ft_list_size(&l6));
	fprintf(fptr, "%d\n", ft_list_size(&l5));
	fprintf(fptr, "%d\n", ft_list_size(&l4));
	fprintf(fptr, "%d\n", ft_list_size(&l3));
	fprintf(fptr, "%d\n", ft_list_size(&l2));
	fprintf(fptr, "%d\n", ft_list_size(&l1));
	fprintf(fptr, "%d\n", ft_list_size(&l0));
	fclose(fptr);
}


static void list_size_test_st() {

	FILE *fptr = fopen("bonus_tests/ft_list_size/0_bigtest_st", "w");
	fprintf(fptr, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n");
	fclose(fptr);
}

void test_list_size() {
	list_size_test_ft();
	list_size_test_st();
}