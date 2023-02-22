#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/errno.h>
size_t ft_strlen(char *);
char *ft_strcpy(char *dst, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
           
extern int errno;

int main(void)
{
	char lol[69];
	char lol2[69];
	printf("\nSTRLEN\n");
	printf("%lu\t:\t", ft_strlen("asdf"));
	printf("%lu\n", strlen("asdf"));

	printf("\nSTRCPY\n");
	printf("%s\t:\t", ft_strcpy(lol, "Hello!"));
	printf("%s\n", strcpy(lol2, "Hello!"));

	printf("\nSTRCMP\n");
	printf("%d\t:\t", ft_strcmp("3", "2"));
	printf("%d\n", strcmp("3", "2"));
	printf("%d\t:\t", ft_strcmp("2", "3"));
	printf("%d\n", strcmp("2", "3"));
	printf("%d\t:\t", ft_strcmp("2", "2"));
	printf("%d\n", strcmp("2", "2"));
	printf("%d\t:\t", ft_strcmp("", "2"));
	printf("%d\n", strcmp("", "2"));

	printf("\nWRITE\n");
	printf("%lu\n", ft_write(1, "HELLO YOYOYO\t", 13));
	printf("%lu\n", write(1, "HELLO YOYOYO\t", 13));
	printf("%lu\n", ft_write(3, "HELLO YOYOYO\t", 13));
	printf("%lu\n", write(3, "HELLO YOYOYO\t", 13));

	printf("\nREAD\n");
	int fd = open("truth.txt", O_RDONLY);
	printf("%lu", ft_read(fd, lol, 13));
	printf("\t%s\n", lol);
	close(fd);
	fd = open("truth.txt", O_RDONLY);
	printf("%lu", read(fd, lol2, 13));
	printf("\t%s\n", lol2);
	close(fd);
	printf("%lu\n", ft_read(15, lol2, 13));
	printf("%lu\n", read(15, lol2, 13));
	return 0;
}