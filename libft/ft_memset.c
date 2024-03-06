/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:12:10 by yiken             #+#    #+#             */
/*   Updated: 2023/12/01 15:14:56 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*arr;

	i = 0;
	arr = (unsigned char *)b;
	while (i < len)
	{
		arr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
