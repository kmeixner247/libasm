#include "../libasm.h"
#include "tests.h"

static void	read_test(char *testname, int fd, void *buf, size_t n) {
	char *path = ft_strjoin("tests/ft_read/", testname);
	FILE *fptr;
	char *path_ft = ft_strjoin(path, "_ft");
	fptr = fopen(path_ft, "w");
	if (!fptr)
		return ;
}

void test_read() {

}