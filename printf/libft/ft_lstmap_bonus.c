/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:50:32 by yiken             #+#    #+#             */
/*   Updated: 2023/12/01 15:14:34 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*hero;

	if (!lst || !f || !del)
		return (0);
	new = 0;
	while (lst)
	{
		hero = ft_lstnew(0);
		if (!hero)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		hero->content = f(lst->content);
		ft_lstadd_back(&new, hero);
		lst = lst->next;
	}
	return (new);
}
