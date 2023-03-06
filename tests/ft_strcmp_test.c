#include "../libasm.h"
#include "tests.h"


static void execute_test(char *dir, int mode, char *str1, char *str2, int (*f_strcmp)()) {
	char	*suffix = (mode == FT) ? "_ft" : "_st";
	FILE	*fptr;
	int		strcmp_return;
	char	*path = ft_strjoin(dir, suffix);

	fptr = fopen(path, "w");
	if (!fptr)
		exit(EXIT_FAILURE);
	strcmp_return = f_strcmp(str1, str2);
	strcmp_return = strcmp_return ? (strcmp_return > 0 ? 1 : -1) : 0;
	fprintf(fptr, "%d\n", strcmp_return);
	strcmp_return = f_strcmp(str2, str1);
	strcmp_return = strcmp_return ? (strcmp_return > 0 ? 1 : -1) : 0;
	fprintf(fptr, "%d\n", strcmp_return);
	fclose(fptr);
	free(path);
}

static void	strcmp_test(char *testname, char *str1, char *str2) {
	char *path = ft_strjoin("tests/ft_strcmp/", testname);

	execute_test(path, FT, str1, str2, &ft_strcmp);
	execute_test(path, ST, str1, str2, &strcmp);

	free(path);
}
 
void test_strcmp() {
	strcmp_test("0_both_empty", "", "");
	strcmp_test("1_one_empty", "", "hullo");
	strcmp_test("2_sam_len_diff.", "asdfg", "hullo");
	strcmp_test("3_sam_len_eq", "no wayy", "no wayy");
	strcmp_test("4_diff_len_diff", "I am not prepared", "for this kind of anarchy");
	strcmp_test("5_diff_len_sam", "I am not prepared", "I am not prepared for this kind of anarchy");
}