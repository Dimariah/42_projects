/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:56:56 by yiken             #+#    #+#             */
/*   Updated: 2024/04/21 13:09:24 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int y)
{
	int	i;

	i = 0;
	while (i < y)
		free(map[i++]);
	free(map);
}

void	release(t_mlx *mlx, t_map *map)
{
	free_map(map->map2d, map->y);
	proper_exit(mlx);
}

void	char_to_img(char c, t_mlx *mlx, t_map *map)
{
	if (mlx_image_to_window(mlx->mlx_ptr, mlx->back_img,
			mlx->coordins[1], mlx->coordins[0]) == -1)
		release(mlx, map);
	if (c == '1' && mlx_image_to_window(mlx->mlx_ptr, mlx->wall_img,
			mlx->coordins[1], mlx->coordins[0]) == -1)
		release(mlx, map);
	if (c == 'P' && mlx_image_to_window(mlx->mlx_ptr, mlx->player_img,
			mlx->coordins[1], mlx->coordins[0]) == -1)
		release(mlx, map);
	if (c == 'C' && mlx_image_to_window(mlx->mlx_ptr, mlx->collectible_img,
			mlx->coordins[1], mlx->coordins[0]) == -1)
		release(mlx, map);
	if (c == 'E' && mlx_image_to_window(mlx->mlx_ptr, mlx->exit_img,
			mlx->coordins[1], mlx->coordins[0]) == -1)
		release(mlx, map);
}

void	re_render(t_mlx *mlx, t_map *map)
{
	mlx->coordins[0] = map->np[0] * mlx->advance_by;
	mlx->coordins[1] = map->np[1] * mlx->advance_by;
	char_to_img(map->map2d[map->np[0]][map->np[1]], mlx, map);
	mlx->coordins[0] = map->pp[0] * mlx->advance_by;
	mlx->coordins[1] = map->pp[1] * mlx->advance_by;
	char_to_img(map->map2d[map->pp[0]][map->pp[1]], mlx, map);
}

void	render_map(t_mlx *mlx, t_map *map)
{
	int	i;
	int	j;

	mlx->coordins[0] = 0;
	mlx->coordins[1] = 0;
	i = 0;
	while (i < map->y)
	{
		j = 0;
		mlx->coordins[1] = 0;
		while (j < map->x)
		{
			char_to_img(map->map2d[i][j], mlx, map);
			mlx->coordins[1] += mlx->advance_by;
			j++;
		}
		mlx->coordins[0] += mlx->advance_by;
		i++;
	}
}
