#ifndef BONUS_TESTS_H
#define BONUS_TESTS_H
#define FT 0
#define ST 1
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>
#include <unistd.h>
#include <fcntl.h>

void	list_to_file(t_list *lst, FILE *fptr);
void	ft_listclear(t_list **lst);

void	test_atoi_base();
void	test_list_push_front();
void	test_list_size();
void	test_list_sort();
void	test_list_remove_if();
#endif