#include "../libasm.h"
#include "tests.h"

static void	strcmp_test(char *testname, char *str1, char *str2) {
	char *path = ft_strjoin("tests/ft_strcmp/", testname);
	FILE *fptr;
	char *path_ft = ft_strjoin(path, "_ft");
	fptr = fopen(path_ft, "w");
	if (!fptr)
		return ;
	fprintf(fptr, "%d\n", ft_strcmp(str1, str2));
	fprintf(fptr, "%d\n", ft_strcmp(str2, str1));
	fclose(fptr);
	free(path_ft);
	char *path_std = ft_strjoin(path, "_st");
	fptr = fopen(path_std, "w");
	if (!fptr)
		return ;
	fprintf(fptr, "%d\n", strcmp(str1, str2));
	fprintf(fptr, "%d\n", strcmp(str2, str1));
	fclose(fptr);
	free(path_std);
	free(path);
}
 
void test_strcmp() {
	strcmp_test("both_empty", "", "");
	strcmp_test("one_empty", "", "hullo");
	strcmp_test("same_length_different", "asdfg", "hullo");
	strcmp_test("same_length_equal", "no wayy", "no wayy");
	strcmp_test("different_length_different", "I am not prepared", "for this kind of anarchy");
	strcmp_test("different_length_same", "I am not prepared", "I am not prepared for this kind of anarchy");
}