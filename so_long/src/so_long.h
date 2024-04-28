/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:32:08 by yiken             #+#    #+#             */
/*   Updated: 2024/04/21 15:05:56 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../utils/get_next_line.h"
# include "../mlx/include/MLX42.h"
# define MAX_H 1440
# define MAX_W 2000
# define UMAX 100
# define UMIN 60

typedef struct s_map
{
	char	*path;
	int		fd;
	int		x;
	int		y;
	char	**map2d;
	int		pp[2];
	int		np[2];
	int		c_count;
	bool	is_exitable;
}	t_map;

typedef struct s_mlx
{
	mlx_t			*mlx_ptr;
	int				window_h;
	int				window_w;
	int				advance_by;
	mlx_texture_t	*back_txtr;
	mlx_texture_t	*wall_txtr;
	mlx_texture_t	*player_txtr;
	mlx_texture_t	*collectible_txtr;
	mlx_texture_t	*exit_txtr;
	mlx_image_t		*back_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*player_img;
	mlx_image_t		*collectible_img;
	mlx_image_t		*exit_img;
	mlx_image_t		*counter_img;
	int				coordins[2];
}	t_mlx;

typedef struct s_pack
{
	t_map	*map;
	t_mlx	*mlx;
}	t_pack;

int		ft_strlen(char *str);
void	init_map(t_map *map, char **av, int ac);
void	simple_parse(t_map *map);
void	advanced_parse(t_map *map);
void	free_map(char **map, int y);
void	init_mlx(t_mlx *mlx, t_map *map);
void	read_map(t_map *map);
void	init_imgs(t_mlx *mlx);
void	proper_exit(t_mlx *mlx);
void	release(t_mlx *mlx, t_map *map);
void	render_map(t_mlx *mlx, t_map *map);
void	re_render(t_mlx *mlx, t_map *map);
void	putnbr(int num);
char	*ft_itoa(int num);

#endif