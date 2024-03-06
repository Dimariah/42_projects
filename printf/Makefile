# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiken <yiken@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 13:22:52 by yiken             #+#    #+#              #
#    Updated: 2023/12/19 18:27:21 by yiken            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
LIBFT			= libft
CC				= cc
AR				= ar
RM				= rm -f
C_FLAGS			= -Werror -Wall -Wextra
SRCS			= ft_printf.c ft_printf_hf.c ft_putptr.c ft_putnbr.c ft_put_uint.c \
					ft_put_hexa.c
OBJS			= $(SRCS:.c=.o)
FT_PF_HEADER	= ft_printf.h

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(AR) r $(NAME) $(OBJS)

%.o		:	%.c $(FT_PF_HEADER)
	$(CC) $(CFLAGS) -c $<

clean	:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean	:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re		:	fclean all

.PHONY	:	clean