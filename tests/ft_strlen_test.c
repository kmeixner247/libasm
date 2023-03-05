#include "../libasm.h"
#include "tests.h"

static void strlen_test(char *testname, char *str) {
	char *path = ft_strjoin("tests/ft_strlen/", testname);
	FILE *fptr;
	char *path_ft = ft_strjoin(path, "_ft");
	fptr = fopen(path_ft, "w");
	if (!fptr)
		return ;
	fprintf(fptr, "%lu\n", ft_strlen(str));
	fclose(fptr);
	free(path_ft);
	char *path_std = ft_strjoin(path, "_st");
	fptr = fopen(path_std, "w");
	if (!fptr)
		return ;
	fprintf(fptr, "%lu\n", strlen(str));
	fclose(fptr);
	free(path_std);
	free(path);
}

void test_strlen() {
	strlen_test("1_empty_input", "");
	strlen_test("2_one_byte", "a");
	strlen_test("3_short_string", "HI THIS IS BRAIN");
	strlen_test("4_long_string", "Did you ever hear the tragedy of Darth Plagueis The Wise? I thought not. It’s not a story the Jedi would tell you. It’s a Sith legend. Darth Plagueis was a Dark Lord of the Sith, so powerful and so wise he could use the Force to influence the midichlorians to create life… He had such a knowledge of the dark side that he could even keep the ones he cared about from dying. The dark side of the Force is a pathway to many abilities some consider to be unnatural. He became so powerful… the only thing he was afraid of was losing his power, which eventually, of course, he did. Unfortunately, he taught his apprentice everything he knew, then his apprentice killed him in his sleep. Ironic. He could save others from death, but not himself.");
	char *really_long_string = malloc(sizeof(char) * 1000001);
	memset(really_long_string, 'X', 1000000);
	really_long_string[1000000] = 0;
	strlen_test("5_really_long_string", really_long_string);
	free(really_long_string);
}