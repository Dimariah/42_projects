/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:35:38 by yiken             #+#    #+#             */
/*   Updated: 2023/12/01 16:10:53 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;
	size_t			i;

	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (new_s1[i] == new_s2[i] && i < n - 1)
		i++;
	return (new_s1[i] - new_s2[i]);
}
