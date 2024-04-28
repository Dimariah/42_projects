/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:58:44 by yiken             #+#    #+#             */
/*   Updated: 2024/04/18 16:58:53 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	simple_parse_err(t_map *map, char *line)
{
	close(map->fd);
	free(line);
	write(2, "Error\n", 6);
	write(2, "the given map is misconfigured\n", 31);
	exit(1);
}

int	is_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_line(char *line)
{
	int		i;
	char	c;

	i = 0;
	while (line[i])
	{
		c = line[i++];
		if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
			return (0);
	}
	return (1);
}

void	simple_parse(t_map *map)
{
	int		len;
	char	*line;
	char	*next_line;

	map->y = 0;
	line = get_next_line(map->fd);
	map->x = ft_strlen(line);
	while (line)
	{
		len = ft_strlen(line);
		if (len != map->x || line[0] != '1' || line[len - 1] != '1')
			simple_parse_err(map, line);
		if ((map->y == 0 && !is_wall(line)) || !is_valid_line(line))
			simple_parse_err(map, line);
		map->y++;
		next_line = get_next_line(map->fd);
		if (!next_line && !is_wall(line))
			simple_parse_err(map, line);
		free(line);
		line = next_line;
	}
	if (map->x < 3 || map->y < 3)
		simple_parse_err(map, line);
	close(map->fd);
}
