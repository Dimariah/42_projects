/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:58:52 by yiken             #+#    #+#             */
/*   Updated: 2023/12/01 15:15:12 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_s1;
	size_t	s1_size;
	size_t	i;

	s1_size = ft_strlen(s1) + sizeof(char);
	new_s1 = (char *)malloc(s1_size);
	if (!new_s1)
		return (0);
	i = 0;
	ft_memcpy(new_s1, s1, s1_size);
	return (new_s1);
}
