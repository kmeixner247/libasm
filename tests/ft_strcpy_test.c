#include "../libasm.h"
#include "tests.h"

static void strcpy_test(char *testname, char *dst, char *src) {
	char *path = ft_strjoin("tests/ft_strcpy/", testname);
	FILE *fptr;
	char *newptr;
	char *path_ft = ft_strjoin(path, "_ft");
	fptr = fopen(path_ft, "w");
	if (!fptr)
		return ;
	char *ft_dst = strdup(dst);
	fprintf(fptr, "dst before: %s\tsrc before: %s\n", ft_dst, src);
	newptr = ft_strcpy(ft_dst, src);
	fprintf(fptr, "dst after: %s\tsrc after: %s\treturn %s\n", ft_dst, src, newptr);
	fprintf(fptr, "dst and return same address: ");
	if (dst == newptr) {
		fprintf(fptr, "YES\n");
	}
	else {
		fprintf(fptr, "NO\n");
	}
	fclose(fptr);
	free(path_ft);
	free(ft_dst);
	char *path_std = ft_strjoin(path, "_st");
	fptr = fopen(path_std, "w");
	if (!fptr)
		return ;
	char *st_dst = strdup(dst);
	fprintf(fptr, "dst before: %s\tsrc before: %s\n", st_dst, src);
	newptr = strcpy(st_dst, src);
	fprintf(fptr, "dst after: %s\tsrc after: %s\treturn %s\n", st_dst, src, newptr);
	fprintf(fptr, "dst and return same address: ");
	if (dst == newptr) {
		fprintf(fptr, "YES\n");
	}
	else {
		fprintf(fptr, "NO\n");
	}
	
	fclose(fptr);
	free(path_std);
	free(st_dst);
	free(path);
}

void	test_strcpy() {
	char longstring[487] = "The path of the righteous man is beset on all sides by the inequities of the selfish and the tyranny of evil men. Blessed is he who, in the name of charity and good will, shepherds the weak through the valley of the darkness. For he is truly his brother's keeper and the finder of lost children. And I will strike down upon thee with great vengeance and furious anger those who attempt to poison and destroy my brothers. And you will know I am the Lord when I lay my vengeance upon you.";
	char lotsanulls[5000];
	bzero(lotsanulls, 5000);
	strcpy_test("1_both_empty", "", "");
	strcpy_test("2_src_empty", longstring, "");
	strcpy_test("3_same_length", "I am Groot!!", "I am Ironman");
	strcpy_test("4_bzerod_dest", lotsanulls, "Just something else man idk");
}