NAME		=	hello

SRCS		=	hello.s
OBJS		=	$(SRCS:.s=.o)

NASM		=	nasm
NASM_FLAGS	=	-f macho64

LD			=	ld
LD_FLAGS	=	-macosx_version_min 10.7.0 -lSystem

%.o:			%.s
				$(NASM) $(NASM_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				$(LD) $(LD_FLAGS) -o $(NAME) $(OBJS)

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY:			clean fclean re