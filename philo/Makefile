NAME	=	philo
SRCS	=	philo.c philo_utils.c init.c monitoring.c life_cycle.c threads.c
OBJS	=	$(SRCS:.c=.o)
INCLUDE	=	philo.h
FLAGS	=	-Werror -Wall -Wextra
CC		=	cc

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) -pthread $(FLAGS) $^ -o $@

%.o		:	%.c  $(INCLUDE)
	$(CC) -pthread $(FLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJS)

fclean	:	clean
	@rm -f $(NAME)

re		:	fclean all

.PHONY	:	clean