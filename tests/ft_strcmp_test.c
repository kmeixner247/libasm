#include "../libasm.h"
#include "tests.h"

static void	strcmp_test(char *testname, char *str1, char *str2) {
	char *path = ft_strjoin("tests/ft_strcmp/", testname);
	FILE *fptr;
	int	a, b;
	char *path_ft = ft_strjoin(path, "_ft");
	fptr = fopen(path_ft, "w");
	if (!fptr)
		return ;
	a = ft_strcmp(str1, str2);
	a = a ? (a > 0 ? 1 : -1) : 0;
	b = ft_strcmp(str2, str1);
	b = b ? (b > 0 ? 1 : -1) : 0;
	fprintf(fptr, "%d\n", a);
	fprintf(fptr, "%d\n", b);
	fclose(fptr);
	free(path_ft);
	char *path_std = ft_strjoin(path, "_st");
	fptr = fopen(path_std, "w");
	if (!fptr)
		return ;
	a = strcmp(str1, str2);
	a = a ? (a > 0 ? 1 : -1) : 0;
	b = strcmp(str2, str1);
	b = b ? (b > 0 ? 1 : -1) : 0;
	fprintf(fptr, "%d\n", a);
	fprintf(fptr, "%d\n", b);
	fclose(fptr);
	free(path_std);
	free(path);
}
 
void test_strcmp() {
	strcmp_test("1_both_empty", "", "");
	strcmp_test("2_one_empty", "", "hullo");
	strcmp_test("3_sam_len_diff.", "asdfg", "hullo");
	strcmp_test("4_sam_len_eq", "no wayy", "no wayy");
	strcmp_test("5_diff_len_diff", "I am not prepared", "for this kind of anarchy");
	strcmp_test("6_diff_len_sam", "I am not prepared", "I am not prepared for this kind of anarchy");
}