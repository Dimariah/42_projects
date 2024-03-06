/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:52:17 by yiken             #+#    #+#             */
/*   Updated: 2023/12/01 16:24:52 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*new_s;
	char	*occ;
	int		i;

	new_s = (char *)s;
	occ = 0;
	i = 0;
	while (new_s[i])
	{
		if (new_s[i] == (char)c)
			occ = &new_s[i];
		i++;
	}
	if (new_s[i] == (char)c)
		occ = &new_s[i];
	return (occ);
}
