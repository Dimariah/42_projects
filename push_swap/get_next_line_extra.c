/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_extra.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:32:10 by yiken             #+#    #+#             */
/*   Updated: 2024/03/04 11:38:12 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	preserve_buf(t_list *list, char *buffer)
{
	t_list	*last_node;
	int		i;
	int		j;

	i = 0;
	j = 0;
	last_node = get_last_node_gnl(list);
	while (last_node->str[i] && last_node->str[i] != '\n')
		i++;
	while (last_node->str[i] && last_node->str[++i])
		buffer[j++] = last_node->str[i];
	buffer[j] = '\0';
}
