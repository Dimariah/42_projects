/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:10:25 by yiken             #+#    #+#             */
/*   Updated: 2024/03/04 13:17:49 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*generate_line(t_list *list)
{
	int		len_of_line;
	char	*line;

	len_of_line = get_len_of_line(list);
	line = malloc(len_of_line + 1);
	if (!line)
		return (0);
	fill_line(list, line);
	return (line);
}

void	join_list(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buffer);
		return ;
	}
	new_node->str = buffer;
	new_node->next = 0;
	last_node = get_last_node_gnl(*list);
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
}

int	new_line_found(t_list *list)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	create_list(t_list **list, int fd)
{
	char	*buffer;
	int		bytes_read;

	while (!new_line_found(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (cleanup(list, 0, 0));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return ;
		}
		if (bytes_read == -1)
		{
			free(buffer);
			cleanup(list, 0, 0);
			return ;
		}
		buffer[bytes_read] = '\0';
		join_list(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	create_list(&list, fd);
	if (!list)
		return (0);
	next_line = generate_line(list);
	adjust_list(&list);
	return (next_line);
}
