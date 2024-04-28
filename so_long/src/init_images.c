/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:59:39 by yiken             #+#    #+#             */
/*   Updated: 2024/04/21 15:05:23 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	proper_exit(t_mlx *mlx)
{
	mlx_delete_image(mlx->mlx_ptr, mlx->back_img);
	mlx_delete_image(mlx->mlx_ptr, mlx->wall_img);
	mlx_delete_image(mlx->mlx_ptr, mlx->player_img);
	mlx_delete_image(mlx->mlx_ptr, mlx->collectible_img);
	mlx_delete_image(mlx->mlx_ptr, mlx->exit_img);
	if (mlx->counter_img)
		mlx_delete_image(mlx->mlx_ptr, mlx->counter_img);
	mlx_delete_texture(mlx->back_txtr);
	mlx_delete_texture(mlx->wall_txtr);
	mlx_delete_texture(mlx->player_txtr);
	mlx_delete_texture(mlx->collectible_txtr);
	mlx_delete_texture(mlx->exit_txtr);
	mlx_terminate(mlx->mlx_ptr);
	exit(1);
}

void	init_left_txtrs(t_mlx *mlx)
{
	if (!mlx->collectible_txtr)
	{
		mlx_delete_texture(mlx->back_txtr);
		mlx_delete_texture(mlx->wall_txtr);
		mlx_delete_texture(mlx->player_txtr);
		mlx_terminate(mlx->mlx_ptr);
		exit(1);
	}
	mlx->exit_txtr = mlx_load_png("assets/exit.png");
	if (!mlx->exit_txtr)
	{
		mlx_delete_texture(mlx->back_txtr);
		mlx_delete_texture(mlx->wall_txtr);
		mlx_delete_texture(mlx->player_txtr);
		mlx_delete_texture(mlx->collectible_txtr);
		mlx_terminate(mlx->mlx_ptr);
		exit(1);
	}
}

void	init_txtrs(t_mlx *mlx)
{
	mlx->back_txtr = mlx_load_png("assets/back.png");
	if (!mlx->back_txtr)
	{
		mlx_terminate(mlx->mlx_ptr);
		exit(1);
	}
	mlx->wall_txtr = mlx_load_png("assets/wall.png");
	if (!mlx->wall_txtr)
	{
		mlx_delete_texture(mlx->back_txtr);
		mlx_terminate(mlx->mlx_ptr);
		exit(1);
	}
	mlx->player_txtr = mlx_load_png("assets/player.png");
	if (!mlx->player_txtr)
	{
		mlx_delete_texture(mlx->back_txtr);
		mlx_delete_texture(mlx->wall_txtr);
		mlx_terminate(mlx->mlx_ptr);
		exit(1);
	}
	mlx->collectible_txtr = mlx_load_png("assets/collectible.png");
	init_left_txtrs(mlx);
}

void	resize_imgs(t_mlx *mlx)
{
	if (!mlx_resize_image(mlx->back_img, mlx->advance_by, mlx->advance_by))
		proper_exit(mlx);
	if (!mlx_resize_image(mlx->wall_img, mlx->advance_by, mlx->advance_by))
		proper_exit(mlx);
	if (!mlx_resize_image(mlx->player_img, mlx->advance_by, mlx->advance_by))
		proper_exit(mlx);
	if (!mlx_resize_image(mlx->collectible_img, mlx->advance_by,
			mlx->advance_by))
		proper_exit(mlx);
	if (!mlx_resize_image(mlx->exit_img, mlx->advance_by, mlx->advance_by))
		proper_exit(mlx);
}

void	init_imgs(t_mlx *mlx)
{
	init_txtrs(mlx);
	mlx->back_img = mlx_texture_to_image(mlx->mlx_ptr, mlx->back_txtr);
	mlx->wall_img = mlx_texture_to_image(mlx->mlx_ptr, mlx->wall_txtr);
	mlx->player_img = mlx_texture_to_image(mlx->mlx_ptr, mlx->player_txtr);
	mlx->collectible_img = mlx_texture_to_image(mlx->mlx_ptr,
			mlx->collectible_txtr);
	mlx->exit_img = mlx_texture_to_image(mlx->mlx_ptr, mlx->exit_txtr);
	mlx->counter_img = 0;
	resize_imgs(mlx);
}
