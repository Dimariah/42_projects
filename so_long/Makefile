NAME		=	so_long
MLX_FLAGS	=	mlx/lib_glfw/libglfw3.a mlx/libmlx42.a -framework Cocoa -framework	\
				OpenGL -framework IOKit
INCLUDES	=	src/so_long.h utils/get_next_line.h mlx/include/MLX42.h
SRCS		=	src/so_long.c utils/get_next_line_utils.c utils/get_next_line.c	\
				src/simple_parse.c utils/so_long_utils.c src/advanced_parse.c	\
				src/map_setup.c src/mlx_setup.c src/init_images.c src/render_map.c
OBJS		=	$(SRCS:.c=.o)
CFLAGS		=	-Werror -Wall -Wextra

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	cc $(CFLAGS) $^ $(MLX_FLAGS) -o $@

%.o		:	%.c $(INCLUDES)
	cc $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJS)

fclean	:	clean
	@rm -f $(NAME)

re		:	fclean all

.PHONY	:	clean