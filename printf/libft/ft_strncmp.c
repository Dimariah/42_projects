/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:05:06 by yiken             #+#    #+#             */
/*   Updated: 2023/12/01 15:15:24 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && new_s1[i]
		&& new_s2[i] && new_s1[i] == new_s2[i])
	{
		i++;
	}
	return (new_s1[i] - new_s2[i]);
}
