# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiken <yiken@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 12:22:03 by yiken             #+#    #+#              #
#    Updated: 2024/03/06 10:16:03 by yiken            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
PRIM_LIB	=	prim_lib.a
SRCS		=	action_push.c action_rev_rotate.c action_rotate.c action_swap.c				\
				check_error.c cr_stack.c ft_split.c get_next_line.c get_next_line.h			\
				get_next_line_extra.c get_next_line_utils.c long_sort.c long_sort_init.c	\
				short_sort.c stack_utils.c
OBJS		=	$(SRCS:.c=.o)
PUSH_SWAP_O	=	push_swap.o
CHECKER_O	=	checker.o
PUSH_SWAP_H	=	push_swap.h
C_FLAGS		=	-Werror -Wall -Wextra

all			:	$(NAME)

$(NAME)		:	$(PRIM_LIB) $(PUSH_SWAP_O)
	ar rc $^
	cc $< -o $@
$(PRIM_LIB)	:	$(OBJS)
	ar rc $@ $^
*.o			:	*.c $(PUSH_SWAP_H)
	cc -c $(C_FLAGS) $<
clean		:
	rm -f $(OBJS) $(PRIM_LIB) $(PUSH_SWAP_O)