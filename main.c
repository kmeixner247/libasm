/*	TODO:
/	more tests
/	better tests
*/

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
char *ft_strdup(const char *s1);
int ft_atoi_base(char *str, char *base);

typedef struct s_list
{
	void	*data;
	struct	s_list *next;
} t_list;
void ft_list_push_front(t_list **begin_list, void *data);

extern int errno;

void print_list(t_list **head)
{
	t_list *temp = *head;
	int i = 1;
	while (temp)
	{
		printf("%d: %s\n", i, temp->data);
		i++;
		temp = temp->next;
	}
}

int main(void)
{
	// char lol[69];
	char lol2[69];
	// printf("\nSTRLEN\n");
	// printf("%lu\t:\t", ft_strlen("asdf"));
	// printf("%lu\n", strlen("asdf"));

	// printf("\nSTRCPY\n");
	// printf("%s\t:\t", ft_strcpy(lol, "Hello!"));
	printf("%s\n", strcpy(lol2, NULL));

	// printf("\nSTRCMP\n");
	// printf("%d\t:\t", ft_strcmp("3", "2"));
	// printf("%d\n", strcmp("3", "2"));
	// printf("%d\t:\t", ft_strcmp("2", "3"));
	// printf("%d\n", strcmp("2", "3"));
	// printf("%d\t:\t", ft_strcmp("2", "2"));
	// printf("%d\n", strcmp("2", "2"));
	// printf("%d\t:\t", ft_strcmp("", "2"));
	// printf("%d\n", strcmp("", "2"));

	// printf("\nWRITE\n");
	// printf("%lu\n", ft_write(1, "HELLO YOYOYO\t", 13));
	// printf("%lu\n", write(1, "HELLO YOYOYO\t", 13));
	// printf("%lu\n", ft_write(3, "HELLO YOYOYO\t", 13));
	// printf("%lu\n", write(3, "HELLO YOYOYO\t", 13));

	// printf("\nREAD\n");
	// int fd = open("truth.txt", O_RDONLY);
	// printf("%lu", ft_read(fd, lol, 13));
	// printf("\t%s\n", lol);
	// close(fd);
	// fd = open("truth.txt", O_RDONLY);
	// printf("%lu", read(fd, lol2, 13));
	// printf("\t%s\n", lol2);
	// close(fd);
	// printf("%lu\n", ft_read(15, lol2, 13));
	// printf("%lu\n", read(15, lol2, 13));
	
	// printf("\nSTRDUP\n");
	// printf("%s\n", ft_strdup("YOYOYOYOYOY I CAN DO THISS"));
	// printf("\nATOI_BASE\n");
	// printf("%d\n", ft_atoi_base("    FFasdf", "AF"));

	// char *s1 = "ONE";
	// char *s2 = "TWO";
	// char *s3 = "THREE";
	// char *s4 = "FOUR";
	// char *s0 = "ZERO";
	// t_list *l1;
	// l1 = malloc(sizeof(t_list));
	// t_list *l2 = malloc(sizeof(t_list));
	// t_list *l3 = malloc(sizeof(t_list));
	// t_list *l4 = malloc(sizeof(t_list));
	// l1->data = s1;
	// l2->data = s2;
	// l3->data = s3;
	// l4->data = s4;
	// l1->next = l2;
	// l2->next = l3;
	// l3->next = l4;
	// l4->next = NULL;
	// t_list **head = &l1;
	// print_list(head);
	// printf("%p\n", *head);
	// printf("%s\n", (*head)->data);
	// ft_list_push_front(head, s0);
	// printf("%p\n", *head);
	// printf("%s\n", (*head)->data);
	// print_list(head);
	return 0;
}