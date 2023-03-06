NAME		=	libasm.a
BNAME		=	libasm_bonus.a

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
TEST_SUBS	=	$(TEST_DIR)ft_strlen \
				$(TEST_DIR)ft_strcmp \
				$(TEST_DIR)ft_strcpy \
				$(TEST_DIR)ft_read \
				$(TEST_DIR)ft_write \
				$(TEST_DIR)ft_strdup

TEST_SRCS	=	$(TEST_DIR)test_utils.c \
				$(TEST_DIR)ft_strlen_test.c \
				$(TEST_DIR)ft_strcmp_test.c \
				$(TEST_DIR)ft_strcpy_test.c \
				$(TEST_DIR)ft_read_test.c \
				$(TEST_DIR)ft_write_test.c \
				$(TEST_DIR)ft_strdup_test.c

BTEST_DIR	=	bonus_tests/
BTEST_SUBS	=	$(BTEST_DIR)ft_atoi_base \
				$(BTEST_DIR)ft_list_push_front \
				$(BTEST_DIR)ft_list_size \
				$(BTEST_DIR)ft_list_sort \
				$(BTEST_DIR)ft_list_remove_if

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

PINK		= \033[0;35m
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

%.o:			%.s
				@$(NASM) $(NASM_FLAGS) $< 
				@echo -n .

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)
				@echo "$(GREEN) $(NAME) successfully compiled!$(RESET)"

bonus:			$(BNAME)

$(BNAME):		$(OBJS) $(BOBJS)
				@ar rcs $(BNAME) $(OBJS) $(BOBJS)
				@echo "$(GREEN) bonus successfully compiled!$(RESET)"

test:			$(NAME)
				@rm -rf $(TEST_SUBS)
				@$(CC) $(CFLAGS) -o $(TEST_NAME) $(NAME) main.c $(TEST_SRCS)
				@mkdir $(TEST_SUBS)
				@./$(TEST_NAME)
				@python3 test.py

testbonus:		$(BNAME) bonus
				@rm -rf $(TEST_SUBS)
				@rm -rf $(BTEST_SUBS)
				@$(CC) $(CFLAGS) -o $(TEST_NAME) $(BNAME) main_bonus.c $(TEST_SRCS) $(BTEST_SRCS)
				@mkdir $(TEST_SUBS) $(BTEST_SUBS)
				@./$(TEST_NAME)
				@python3 test.py
				@python3 test_bonus.py

cute:			
				@echo "$(PINK)You are so cute$(RESET)"

clean:
				@rm -rf $(OBJS) $(BOBJS)

fclean:			clean
				@rm -rf $(TEST_SUBS)
				@echo -n .
				@rm -rf $(BTEST_SUBS)
				@echo -n .
				@rm -rf $(NAME)
				@echo -n .
				@rm -rf $(BNAME)
				@echo -n .
				@rm -rf $(TEST_NAME)
				@echo -n .
				@echo "$(RED) clean successful!$(RESET)"

re:				fclean $(NAME)

.PHONY:			all bonus test testbonus clean fclean re cute

