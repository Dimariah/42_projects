/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:42:51 by yiken             #+#    #+#             */
/*   Updated: 2023/12/01 15:14:35 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;
	t_list	my_node;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (0);
	my_node.content = content;
	my_node.next = 0;
	*ptr = my_node;
	return (ptr);
}
