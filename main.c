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
int ft_list_size(t_list *begin_list);
void ft_list_sort(t_list **begin_list, int (*cmp)());

extern int errno;

void print_list(t_list **head)
{
	t_list *temp = *head;
	int i = 1;
	while (temp)
	{
		printf("%d: %s %p\n", i, temp->data, temp);
		i++;
		temp = temp->next;
	}
}

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
	printf("%d\t:\t", ft_strcmp("A", "Z"));
	printf("%d\n", strcmp("A", "Z"));
	printf("%d\t:\t", ft_strcmp("Z", "A"));
	printf("%d\n", strcmp("Z", "A"));
	printf("%d\t:\t", ft_strcmp("A", "A"));
	printf("%d\n", strcmp("A", "A"));
	printf("%d\t:\t", ft_strcmp("", "2"));
	printf("%d\n", strcmp("", "2"));

	printf("\nWRITE\n");
	printf("%ld\n", ft_write(1, "HELLO YOYOYO\t", 13));
	printf("%ld\n", write(1, "HELLO YOYOYO\t", 13));
	printf("%ld\n", ft_write(3, "HELLO YOYOYO\t", 13));
	printf("%ld\n", write(3, "HELLO YOYOYO\t", 13));

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
	
	printf("\nSTRDUP\n");
	printf("%s\n", ft_strdup("YOYOYOYOYOY I CAN DO THISS"));
	printf("\nATOI_BASE\n");
	printf("%d\n", ft_atoi_base("    FFasdf", "AF"));
	// printf("sergjhslkdjrgjsjkldhg\n");

	char *s0 = "9";
	char *s1 = "2";
	char *s2 = "5";
	char *s3 = "3";
	char *s4 = "7";
	t_list *l1 = malloc(sizeof(t_list));
	t_list *l2 = malloc(sizeof(t_list));
	t_list *l3 = malloc(sizeof(t_list));
	t_list *l4 = malloc(sizeof(t_list));
	l1->data = s1;
	l2->data = s2;
	l3->data = s3;
	l4->data = s4;
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = NULL;
	t_list **head = &l1;

	printf("\nLIST_PUSH_FRONT\n");
	print_list(head);
	printf("_____________\n");
	ft_list_push_front(head, s0);
	print_list(head);

	printf("\nLIST_SIZE\n");
	printf("%d\n", ft_list_size(*head));

	printf("\nLIST_SORT\n");
	
	print_list(head);
	printf("_____________\n");

	ft_list_sort(head, &strcmp);
	print_list(head);
	printf("END\n");
	return 0;
}