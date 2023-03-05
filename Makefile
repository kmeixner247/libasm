NAME		=	libasm.a
TEST_NAME	=	test
SRCS_DIR	=	src/
SRCS		=	$(SRCS_DIR)ft_strlen.s \
				$(SRCS_DIR)ft_strcpy.s \
				$(SRCS_DIR)ft_strcmp.s \
				$(SRCS_DIR)ft_write.s \
				$(SRCS_DIR)ft_read.s \
				$(SRCS_DIR)ft_strdup.s \
				$(SRCS_DIR)ft_atoi_base.s \
				$(SRCS_DIR)ft_list_push_front.s \
				$(SRCS_DIR)ft_list_size.s \
				$(SRCS_DIR)ft_list_sort.s \
				$(SRCS_DIR)ft_list_remove_if.s
OBJS		=	$(SRCS:.s=.o)
TEST_DIR	=	tests/
TEST_SRCS	=	$(TEST_DIR)test_utils.c \
				$(TEST_DIR)ft_strlen_test.c \
				$(TEST_DIR)ft_strcmp_test.c

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g -fsanitize=address

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
				$(CC) $(CFLAGS) -o $(TEST_NAME) $(NAME) main.c $(TEST_SRCS)

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(TEST_DIR)/ft_strlen/*
				rm -rf $(TEST_DIR)/ft_strcmp/*
				rm -rf $(NAME)
				rm -rf $(TEST_NAME)

re:				fclean $(NAME) $(TEST_NAME)

.PHONY:			clean fclean re

