/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:41:56 by yiken             #+#    #+#             */
/*   Updated: 2024/04/21 13:11:58 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_mv_num(t_mlx *mlx, action_t action)
{
	static int			counter;
	char				*str;

	if (action == MLX_PRESS)
	{
		putnbr(++counter);
		write(1, "\n", 1);
		str = ft_itoa(counter);
		if (!str)
			return ;
		if (mlx->counter_img)
			mlx_delete_image(mlx->mlx_ptr, mlx->counter_img);
		mlx->counter_img = mlx_put_string(mlx->mlx_ptr, str, 0, 0);
		mlx_resize_image(mlx->counter_img, mlx->advance_by, mlx->advance_by);
		free(str);
	}
}

void	map_move(t_map *map, t_mlx *mlx, mlx_key_data_t keydata)
{
	if (map->map2d[map->np[0]][map->np[1]] == 'E' && !map->c_count)
	{
		print_mv_num(mlx, keydata.action);
		release(mlx, map);
	}
	if (map->map2d[map->np[0]][map->np[1]] == 'C')
		map->c_count--;
	if (map->map2d[map->np[0]][map->np[1]] == '0'
		|| map->map2d[map->np[0]][map->np[1]] == 'C')
	{
		map->map2d[map->pp[0]][map->pp[1]] = '0';
		map->map2d[map->np[0]][map->np[1]] = 'P';
	}
}

void	key_resp(t_pack *pack, keys_t code, action_t action)
{
	if (code == MLX_KEY_ESCAPE && action == MLX_PRESS)
		release(pack->mlx, pack->map);
	if (code == MLX_KEY_W && action == MLX_PRESS)
	{
		pack->map->np[0] = pack->map->pp[0] - 1;
		pack->map->np[1] = pack->map->pp[1];
	}
	if (code == MLX_KEY_S && action == MLX_PRESS)
	{
		pack->map->np[0] = pack->map->pp[0] + 1;
		pack->map->np[1] = pack->map->pp[1];
	}
	if (code == MLX_KEY_D && action == MLX_PRESS)
	{
		pack->map->np[0] = pack->map->pp[0];
		pack->map->np[1] = pack->map->pp[1] + 1;
	}
	if (code == MLX_KEY_A && action == MLX_PRESS)
	{
		pack->map->np[0] = pack->map->pp[0];
		pack->map->np[1] = pack->map->pp[1] - 1;
	}
}

void	on_keypress(mlx_key_data_t keydata, void *param)
{
	t_pack		*pack;
	int			code;

	pack = param;
	code = keydata.key;
	if (code != MLX_KEY_W && code != MLX_KEY_S && code != MLX_KEY_D
		&& code != MLX_KEY_A && code != MLX_KEY_ESCAPE)
		return ;
	key_resp(pack, code, keydata.action);
	map_move(pack->map, pack->mlx, keydata);
	if (pack->map->map2d[pack->map->np[0]][pack->map->np[1]] != '1'
		&& pack->map->map2d[pack->map->np[0]][pack->map->np[1]] != 'E')
	{
		re_render(pack->mlx, pack->map);
		pack->map->pp[0] = pack->map->np[0];
		pack->map->pp[1] = pack->map->np[1];
		print_mv_num(pack->mlx, keydata.action);
	}
}

void	init_mlx(t_mlx *mlx, t_map *map)
{
	t_pack	pack;

	pack.map = map;
	pack.mlx = mlx;
	mlx->window_h = map->y * UMAX;
	mlx->window_w = map->x * UMAX;
	mlx->advance_by = UMAX;
	if (mlx->window_h > MAX_H || mlx->window_w > MAX_W)
	{
		mlx->window_h = map->y * UMIN;
		mlx->window_w = map->x * UMIN;
		mlx->advance_by = UMIN;
	}
	mlx->mlx_ptr = mlx_init(mlx->window_w, mlx->window_h, map->path, false);
	if (!mlx->mlx_ptr)
		exit(1);
	init_imgs(mlx);
	read_map(map);
	render_map(mlx, map);
	mlx_key_hook(mlx->mlx_ptr, on_keypress, &pack);
	mlx_loop(mlx->mlx_ptr);
}
