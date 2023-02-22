#include <stdio.h>
#include <string.h>

int ft_strlen(char *);
char *ft_strcpy(char *dst, const char *src);

int main(void)
{
	char lol[69];
	printf("%d\n", ft_strlen("asdf"));
	printf("%s\n", ft_strcpy(lol, "Hello!"));
	return 0;
}