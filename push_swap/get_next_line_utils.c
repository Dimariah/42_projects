/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:32:59 by yiken             #+#    #+#             */
/*   Updated: 2024/03/04 11:36:55 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cleanup(t_list **list, char *buffer, t_list *new_node)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str);
		free(*list);
		*list = tmp;
	}
	*list = 0;
	if (buffer && new_node)
	{
		if (buffer[0])
		{
			new_node->str = buffer;
			new_node->next = 0;
			*list = new_node;
		}
		else
		{
			free(buffer);
			free(new_node);
		}
	}
}

void	adjust_list(t_list **list)
{
	t_list	*new_node;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		cleanup(list, 0, 0);
		return ;
	}
	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buffer);
		cleanup(list, 0, 0);
		return ;
	}
	preserve_buf(*list, buffer);
	cleanup(list, buffer, new_node);
}

void	fill_line(t_list *list, char *line)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				line[j++] = list->str[i];
				line[j] = '\0';
				return ;
			}
			line[j++] = list->str[i++];
		}
		list = list->next;
	}
	line[j] = '\0';
}

t_list	*get_last_node_gnl(t_list *list)
{
	if (!list)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}

int	get_len_of_line(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		list = list->next;
	}
	return (len);
}
