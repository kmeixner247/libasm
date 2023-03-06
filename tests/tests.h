#ifndef TESTS_H
#define TESTS_H
#define FT 0
#define ST 1
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>
#include <unistd.h>
#include <fcntl.h>
char	*ft_strjoin(char const *s1, char const *s2);

void	test_strlen();
void	test_strcmp();
void	test_strcpy();
void	test_read();
void	test_write();
void	test_strdup();
#endif