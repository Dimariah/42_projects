/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:36:41 by yiken             #+#    #+#             */
/*   Updated: 2024/04/02 21:22:33 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;
t_list	*get_last_node(t_list *list);
int		get_len_of_line(t_list *list);
void	fill_line(t_list *list, char *line);
void	adjust_list(t_list **list);
void	cleanup(t_list **list, char *buffer, t_list *new_node);
char	*get_next_line(int fd);

#endif
