NAME		=	libasm.a
TEST_NAME	=	libasm_test

SRCS_DIR	=	src/
SRCS		=	$(SRCS_DIR)ft_strlen.s \
				$(SRCS_DIR)ft_strcpy.s \
				$(SRCS_DIR)ft_strcmp.s \
				$(SRCS_DIR)ft_write.s \
				$(SRCS_DIR)ft_read.s \
				$(SRCS_DIR)ft_strdup.s
OBJS		=	$(SRCS:.s=.o)

BSRCS_DIR	=	bonus_src/
BSRCS		= 	$(BSRCS_DIR)ft_atoi_base.s \
				$(BSRCS_DIR)ft_list_push_front.s \
				$(BSRCS_DIR)ft_list_size.s \
				$(BSRCS_DIR)ft_list_sort.s \
				$(BSRCS_DIR)ft_list_remove_if.s
BOBJS		=	$(BSRCS:.s=.o)

TEST_DIR	=	tests/
TEST_SUBS	=	ft_strlen ft_strcmp ft_strcpy ft_read ft_write ft_strdup
TEST_SRCS	=	$(TEST_DIR)test_utils.c \
				$(TEST_DIR)ft_strlen_test.c \
				$(TEST_DIR)ft_strcmp_test.c \
				$(TEST_DIR)ft_strcpy_test.c \
				$(TEST_DIR)ft_read_test.c \
				$(TEST_DIR)ft_write_test.c \
				$(TEST_DIR)ft_strdup_test.c

BTEST_DIR	=	bonus_tests/
BTEST_SUBS	=	ft_atoi_base ft_list_push_front ft_list_size ft_list_sort ft_list_remove_if
BTEST_SRCS	=	$(BTEST_DIR)bonus_test_utils.c \
				$(BTEST_DIR)ft_atoi_base_test.c \
				$(BTEST_DIR)ft_list_push_front_test.c \
				$(BTEST_DIR)ft_list_size_test.c \
				$(BTEST_DIR)ft_list_sort_test.c \
				$(BTEST_DIR)ft_list_remove_if_test.c


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

bonus:			$(OBJS) $(BOBJS)
				ar rcs $(NAME) $(OBJS) $(BOBJS)

$(TEST_NAME):	$(NAME)
				$(CC) $(CFLAGS) -o $(TEST_NAME) $(NAME) main.c $(TEST_SRCS) $(BTEST_SRCS)

test:			$(TEST_NAME)
				./$(TEST_NAME)
				python3 script.py

clean:
				rm -rf $(OBJS) $(BOBJS)

fclean:			clean
				rm -rf $(TEST_DIR)/ft_strlen/*
				rm -rf $(TEST_DIR)/ft_strcmp/*
				rm -rf $(TEST_DIR)/ft_strcpy/*
				rm -rf $(TEST_DIR)/ft_read/*
				rm -rf $(TEST_DIR)/ft_write/*
				rm -rf $(TEST_DIR)/ft_strdup/*
				rm -rf $(BTEST_DIR)/ft_atoi_base/*
				rm -rf $(BTEST_DIR)/ft_list_push_front/*
				rm -rf $(BTEST_DIR)/ft_list_size/*
				rm -rf $(BTEST_DIR)/ft_list_sort/*
				rm -rf $(BTEST_DIR)/ft_list_remove_if/*
				rm -rf $(NAME)
				rm -rf $(TEST_NAME)

re:				fclean $(NAME)

.PHONY:			all bonus test clean fclean

