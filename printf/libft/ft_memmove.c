/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:49:43 by yiken             #+#    #+#             */
/*   Updated: 2023/12/01 15:14:51 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*new_src;
	unsigned char	*new_dst;
	int				diff;
	int				i;

	new_src = src;
	new_dst = dst;
	diff = new_dst - new_src;
	if (diff > 0)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			new_src[i + diff] = new_src[i];
			i--;
		}
	}
	else
	{
		ft_memcpy(new_dst, new_src, len);
	}
	return (dst);
}
