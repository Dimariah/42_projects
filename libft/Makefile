# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiken <yiken@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:31:17 by yiken             #+#    #+#              #
#    Updated: 2023/11/29 18:04:02 by yiken            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CC			=	cc
CFLAGS		=	-Werror -Wall -Wextra
RM			=	rm -f
SRCS		=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
				ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
				ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
				ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_strtrim.c \
				ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
				ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c \
				ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_striteri.c
OBJS		=	$(SRCS:.c=.o)
BNS_SRCS	=	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
				ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
BNS_OBJS	=	$(BNS_SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	ar rcs $@ $^

bonus	:	$(NAME) $(BNS_OBJS)
	ar r $(NAME) $^
%.o		:	%.c libft.h
	$(CC) -c $(CFLAGS) $<

clean	:
	$(RM) $(OBJS) $(BNS_OBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all


.PHONY	:	all bonus clean fclean re