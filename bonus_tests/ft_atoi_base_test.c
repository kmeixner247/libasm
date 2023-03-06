#include "../libasm.h"
#include "bonus_tests.h"
#include "../tests/tests.h"

static void	execute_test(char *dir, int mode, char *str, char *base, int result) {
	char	*suffix = (mode == FT) ? "_ft" : "_st";
	FILE *fptr;
	char	*path = ft_strjoin(dir, suffix);

	fptr = fopen(path, "w");
	if (!fptr)
		exit(EXIT_FAILURE);
	if (mode == FT)
		result = ft_atoi_base(str, base);
	fprintf(fptr, "%s\n%s\n%d\n", str, base, result);
	fclose(fptr);
	free(path);
}

static void atoi_base_test(char *testname, char *str, char *base, int result) {
	char *path = ft_strjoin("bonus_tests/ft_atoi_base/", testname);

	execute_test(path, FT, str, base, result);
	execute_test(path, ST, str, base, result);

	free(path);
}

void test_atoi_base() {
	atoi_base_test("00_empty_base", "6969", "", 0);
	atoi_base_test("01_base_too_small", "6969", "X", 0);
	atoi_base_test("02_duplicates_in_base_0", "6969", "1223", 0);
	atoi_base_test("03_duplicates_in_base_1", "6969", "1123", 0);
	atoi_base_test("04_duplicates_in_base_2", "6969", "1278533", 0);
	atoi_base_test("05_duplicates_in_base_3", "6969", "012340", 0);
	atoi_base_test("06_plus_in_base", "6969", "1234+5", 0);
	atoi_base_test("07_minus_in_base", "6969", "-1234", 0);
	atoi_base_test("08_space_in_base", "6969", "a word", 0);
	atoi_base_test("09_newline_in_base", "6969", "nl\nyo", 0);
	atoi_base_test("10_basic_decimal", "6969", "0123456789", 6969);
	atoi_base_test("11_basic_binary", "101010", "01", 42);
	atoi_base_test("12_basic_hex", "6969", "0123456789ABCDEF", 26985);
	atoi_base_test("13_basic_base7", "5213", "0123456", 1823);
	atoi_base_test("14_whitespace_first", "    \t\n \v	\t\f  6969", "0123456789", 6969);
	atoi_base_test("15_negative", "  -6969", "0123456789", -6969);
	atoi_base_test("16_string_before", "LOL6969", "0123456789", 0);
	atoi_base_test("16_string_and_whitespace", "   LOL6969", "0123456789", 0);
}