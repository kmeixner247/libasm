NAME		=	libasm.a
TEST_NAME	=	test
SRCS		=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s ft_atoi_base.s
OBJS		=	$(SRCS:.s=.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

NASM		=	nasm
NASM_FLAGS	=	-f macho64

LD			=	ld
LD_FLAGS	=	-macosx_version_min 10.7.0 -lSystem

%.o:			%.s
				$(NASM) $(NASM_FLAGS) $<

all:			$(NAME) $(TEST_NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

$(TEST_NAME):	
				$(CC) $(CFLAGS) -o $(TEST_NAME) $(NAME) main.c

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME)
				rm -rf $(TEST_NAME)

re:				fclean $(NAME) $(TEST_NAME)

.PHONY:			clean fclean re