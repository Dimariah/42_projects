# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiken <yiken@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 12:22:03 by yiken             #+#    #+#              #
#    Updated: 2024/03/17 14:10:09 by yiken            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
PRIM_LIB	=	prim_lib.a
BONUS		=	checker
SRCS		=	action_push.c action_rev_rotate.c action_rotate.c action_swap.c				\
				check_error.c cr_stack.c ft_split.c get_next_line.c	get_next_line_extra.c	\
				get_next_line_utils.c long_sort.c long_sort_init.c checker_utils_bonus.c	\
				short_sort.c stack_utils.c
OBJS		=	$(SRCS:.c=.o)
PUSH_SWAP_O	=	push_swap.o
CHECKER_O	=	checker_bonus.o
HEADERS	=	push_swap.h get_next_line.h checker_bonus.h
C_FLAGS		=	-Werror -Wall -Wextra
# Define color codes
RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m # No Color

all			:	$(NAME)
	@echo "$(GREEN)$^$(NC)is ready! don't forget to $(RED)clean"
$(NAME)		:	$(PRIM_LIB) $(PUSH_SWAP_O)
	@ar rc $^
	@cc $< -o $@
	@rm $<

$(PRIM_LIB)	:	$(OBJS)
	@ar rc $@ $^

%.o			:	%.c $(HEADERS)
	@cc -c $(C_FLAGS) $<

bonus		:	$(BONUS)
	@echo "$(GREEN)$^$(NC)is ready! don't forget to $(RED)clean"

$(BONUS)	:	$(PRIM_LIB) $(CHECKER_O)
	@ar rc $^
	@cc $< -o $@
	@rm $<

clean		:
	@rm -f $(OBJS) $(PRIM_LIB) $(PUSH_SWAP_O) $(CHECKER_O)
	@echo "$(GREEN)clean done!"

fclean		:	clean
	@rm -f $(NAME) $(BONUS)
	@echo "$(RED)full clean done!"

re			:	fclean all
	@echo "$(GREEN)rebuild done!"

.PHONY		:	clean