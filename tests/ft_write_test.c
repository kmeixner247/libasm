#include "../libasm.h"
#include "tests.h"

static void execute_test(char *dir, int mode, int fd, char *buffer, size_t n, ssize_t (*f_write)())
{
	char *suffix = (mode == FT) ? "_ft" : "_st";
	FILE *fptr;
	int write_return;
	char *path = ft_strjoin(dir, suffix);
	if (!fd)
		fd = open(path, O_WRONLY | O_CREAT, 0666);
	write_return = f_write(fd, buffer, n);
	if (fd > 2)
		close(fd);
	fptr = fopen(path, "w");
	if (!fptr)
		return ;
	fprintf(fptr, "%d\n", write_return);
	fprintf(fptr, "%s\n", buffer);
	if (write_return < 0)
		fprintf(fptr, "ERROR: %d\n", errno);
	fclose(fptr);
	free(path);
}

static void write_test(char *testname, int fd, char *buffer, size_t n)
{

	char *path = ft_strjoin("tests/ft_write/", testname);

	execute_test(path, FT, fd, buffer, n, &ft_write);
	execute_test(path, ST, fd, buffer, n, &write);

	free(path);
}

void test_write()
{
	write_test("0_invalid_fd", -1, "pls gief error", 14);
	write_test("1_write_empty", 0, "", 0);
	write_test("2_write_14", 0, "I like turtles", 14);
	write_test("3_write_more", 0, "The capybara or greater capybara (Hydrochoerus hydrochaeris) is a giant cavy rodent native to South America. It is the largest living rodent and a member of the genus Hydrochoerus. The only other extant member is the lesser capybara (Hydrochoerus isthmius). Its close relatives include guinea pigs and rock cavies, and it is more distantly related to the agouti, the chinchilla, and the nutria. The capybara inhabits savannas and dense forests, and lives near bodies of water. It is a highly social species and can be found in groups as large as 100 individuals, but usually live in groups of 10–20 individuals. The capybara is hunted for its meat and hide and also for grease from its thick fatty skin. It is not considered a threatened species.", 746);
	char *very_long_string = malloc(sizeof(char) * 1000001);
	memset(very_long_string, 'X', 1000000);
	very_long_string[1000000] = 0;
	write_test("4_write_longer", 0, very_long_string , 1000000);
	free(very_long_string);
}