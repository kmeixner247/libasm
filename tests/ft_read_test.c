#include "../libasm.h"
#include "tests.h"

static void execute_test(char *dir, int mode, int fd, size_t n, ssize_t (*f_read)()) {
	char	*suffix = (mode == FT) ? "_ft" : "_st";
	FILE	*fptr;
	int		read_return;
	char	buffer[500];
	bzero(buffer, 500);
	char	*path = ft_strjoin(dir, suffix);
	fptr = fopen(path, "w");
	if (!fptr)
		exit(EXIT_FAILURE);
	read_return = f_read(fd, buffer, n);
	fprintf(fptr, "%d\n", read_return);
	fprintf(fptr, "%s\n", buffer);
	if (read_return < 0)
		fprintf(fptr, "ERROR: %d\n", errno);
	fclose(fptr);
	free(path);
}

static void	read_test_fd(char *testname, int fd, size_t n) {

	char *path = ft_strjoin("tests/ft_read/", testname);

	execute_test(path, FT, fd, n, &ft_read);
	execute_test(path, ST, fd, n, &read);

	free(path);
}

static void	read_test_filename(char *testname, char *filename, size_t n) {
	int fd;
	char *path = ft_strjoin("tests/ft_read/", testname);

	fd = open(filename, O_RDONLY);
	execute_test(path, FT, fd, n, &ft_read);
	close(fd);
	fd = open(filename, O_RDONLY);
	execute_test(path, ST, fd, n, &read);
	close(fd);

	free(path);
}

void test_read() {
	read_test_fd("0_invalid_fd", -1, 5);
	read_test_fd("1_read_0_invalid_fd", -1, 5);
	read_test_filename("2_file_read_0", "tests/readfile1", 0);
	read_test_filename("3_file_read_5", "tests/readfile1", 5);
	read_test_filename("4_file_read_all", "tests/readfile1", 25);
	read_test_filename("5_file_read_more", "tests/readfile1", 50);
	read_test_filename("6_file_read_longer", "tests/readfile2", 499);
}