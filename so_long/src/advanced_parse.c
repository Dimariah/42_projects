/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:27:47 by yiken             #+#    #+#             */
/*   Updated: 2024/04/18 13:38:49 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_seek(t_map *map, int y, int x, int *c)
{
	if (map->map2d[y][x] == '1' || map->map2d[y][x] == '!')
		return ;
	if (map->map2d[y][x] == 'E')
		map->is_exitable = true;
	if (map->map2d[y][x] == 'C')
		(*c)--;
	map->map2d[y][x] = '!';
	flood_seek(map, y - 1, x, c);
	flood_seek(map, y + 1, x, c);
	flood_seek(map, y, x + 1, c);
	flood_seek(map, y, x - 1, c);
}

void	advanced_parse_err(t_map *map)
{
	free_map(map->map2d, map->y);
	write(2, "Error\n", 6);
	write(2, "the given map is misconfigured\n", 31);
	exit(1);
}

void	lmnts_count(t_map *map, int *p, int *e)
{
	int	i;
	int	j;

	i = 0;
	map->c_count = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->map2d[i][j] == 'P')
			{
				(*p)++;
				map->pp[1] = j;
				map->pp[0] = i;
			}
			if (map->map2d[i][j] == 'C')
				map->c_count++;
			if (map->map2d[i][j] == 'E')
				(*e)++;
			j++;
		}
		i++;
	}
}

void	advanced_parse(t_map *map)
{
	int	p;
	int	c;
	int	e;

	p = 0;
	e = 0;
	lmnts_count(map, &p, &e);
	c = map->c_count;
	if (p != 1 || c == 0 || e != 1)
		advanced_parse_err(map);
	map->is_exitable = false;
	flood_seek(map, map->pp[0], map->pp[1], &c);
	if (!map->is_exitable || c > 0)
		advanced_parse_err(map);
	free_map(map->map2d, map->y);
}
