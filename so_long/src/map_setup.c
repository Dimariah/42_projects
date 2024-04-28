/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:03:58 by yiken             #+#    #+#             */
/*   Updated: 2024/04/21 12:17:21 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	read_map(t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	map->fd = open(map->path, O_RDONLY);
	if (map->fd == -1)
	{
		perror(map->path);
		exit(1);
	}
	map->map2d = malloc(map->y * sizeof(char *));
	if (!map->map2d)
	{
		close(map->fd);
		perror("malloc");
		exit(1);
	}
	line = get_next_line(map->fd);
	while (line)
	{
		map->map2d[i++] = line;
		line = get_next_line(map->fd);
	}
	close(map->fd);
}

void	init_map(t_map *map, char **av, int ac)
{
	char	*extension;

	if (ac != 2)
	{
		write(2, "usage: ./so_long *.ber\n", 23);
		exit(1);
	}
	map->path = av[1];
	extension = map->path + (ft_strlen(map->path) - 4);
	if (ft_strcmp(extension, ".ber"))
	{
		write(2, "usage: ./so_long *.ber\n", 23);
		exit(1);
	}
	map->fd = open(map->path, O_RDONLY);
	if (map->fd == -1)
	{
		perror(map->path);
		exit(1);
	}
	simple_parse(map);
	read_map(map);
	advanced_parse(map);
}
