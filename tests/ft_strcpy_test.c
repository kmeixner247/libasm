#include "../libasm.h"
#include "tests.h"

static void execute_test(char *dir, int mode, char *dst, char *src, char *(*f_strcpy)()) {
	char	*suffix = (mode == FT) ? "_ft" : "_st";
	FILE	*fptr;
	char	*strcpy_return;
	char	*path = ft_strjoin(dir, suffix);

	fptr = fopen(path, "w");
	if (!fptr)
		exit(EXIT_FAILURE);
	char *temp_dst = strdup(dst);
	fprintf(fptr, "dst before: %s\nsrc before: %s\n", temp_dst, src);
	strcpy_return = f_strcpy(temp_dst, src);
	fprintf(fptr, "dst after: %s\nsrc after: %s\nreturn: %s\n", temp_dst, src, strcpy_return);
	fprintf(fptr, "dst and return same address: ");
	if (temp_dst == strcpy_return) {
		fprintf(fptr, "YES\n");
	}
	else {
		fprintf(fptr, "NO\n");
	}
	fclose(fptr);
	free(path);
	free(temp_dst);
}

static void strcpy_test(char *testname, char *dst, char *src) {
	char *path = ft_strjoin("tests/ft_strcpy/", testname);

	execute_test(path, FT, dst, src, &ft_strcpy);
	execute_test(path, ST, dst, src, &strcpy);

	free(path);
}

void	test_strcpy() {
	char longstring[487] = "The path of the righteous man is beset on all sides by the inequities of the selfish and the tyranny of evil men. Blessed is he who, in the name of charity and good will, shepherds the weak through the valley of the darkness. For he is truly his brother's keeper and the finder of lost children. And I will strike down upon thee with great vengeance and furious anger those who attempt to poison and destroy my brothers. And you will know I am the Lord when I lay my vengeance upon you.";
	strcpy_test("0_both_empty", "", "");
	strcpy_test("1_src_empty", longstring, "");
	strcpy_test("2_same_length", "I am Groot!!", "I am Ironman");
}