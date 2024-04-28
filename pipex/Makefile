NAME		=	pipex
SRCS		= 	pipex.c pipex_utils.c pipex_extras.c exec_command.c gnl/get_next_line.c \
				gnl/get_next_line_utils.c
OBJS		=	$(SRCS:.c=.o)
INCLUDES	=	pipex.h gnl/get_next_line.h
CFLAGS		=	-Werror -Wall -Wextra

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	cc $(CFLAGS) $^ -o $@

%.o		:	%.c $(INCLUDES)
	cc $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJS)

fclean	:	clean
	@rm -f $(NAME)

re		:	fclean all

.PHONY	:	clean