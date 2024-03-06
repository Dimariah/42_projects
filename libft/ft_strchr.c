/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:37:18 by yiken             #+#    #+#             */
/*   Updated: 2023/12/01 15:15:11 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*new_s;

	i = 0;
	new_s = (char *)s;
	while (new_s[i])
	{
		if (new_s[i] == (char)c)
			return (&new_s[i]);
		i++;
	}
	if (new_s[i] == (char)c)
		return (&new_s[i]);
	return (0);
}
