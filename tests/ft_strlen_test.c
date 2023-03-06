#include "../libasm.h"
#include "tests.h"

static void execute_test(char *dir, int mode, char *str, size_t (*f_strlen)()) {
	char	*suffix = (mode == FT) ? "_ft" : "_st";
	FILE	*fptr;
	int		strlen_return;
	char	*path = ft_strjoin(dir, suffix);

	fptr = fopen(path, "w");
	if (!fptr)
		exit(EXIT_FAILURE);
	strlen_return = f_strlen(str);
	fprintf(fptr, "%s\n", str);
	fprintf(fptr, "%d\n", strlen_return);
	fclose(fptr);
	free(path);
}

static void strlen_test(char *testname, char *str) {
	char *path = ft_strjoin("tests/ft_strlen/", testname);

	execute_test(path, FT, str, &ft_strlen);
	execute_test(path, ST, str, &strlen);

	free(path);
}

void test_strlen() {
	strlen_test("0_empty_input", "");
	strlen_test("1_one_byte", "a");
	strlen_test("2_short_string", "HI THIS IS BRAIN");
	strlen_test("3_long_string", "Did you ever hear the tragedy of Darth Plagueis The Wise? I thought not. It’s not a story the Jedi would tell you. It’s a Sith legend. Darth Plagueis was a Dark Lord of the Sith, so powerful and so wise he could use the Force to influence the midichlorians to create life… He had such a knowledge of the dark side that he could even keep the ones he cared about from dying. The dark side of the Force is a pathway to many abilities some consider to be unnatural. He became so powerful… the only thing he was afraid of was losing his power, which eventually, of course, he did. Unfortunately, he taught his apprentice everything he knew, then his apprentice killed him in his sleep. Ironic. He could save others from death, but not himself.");
	char *really_long_string = malloc(sizeof(char) * 1000001);
	memset(really_long_string, 'X', 1000000);
	really_long_string[1000000] = 0;
	strlen_test("4_really_long_string", really_long_string);
	strlen_test("5_null_in_middle", "Ha forced\0me to do this");
	free(really_long_string);
}