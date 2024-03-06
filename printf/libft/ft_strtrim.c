/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:26:59 by yiken             #+#    #+#             */
/*   Updated: 2023/12/01 15:15:44 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static int	get_end(const char *s1, const char *set)
{
	int	i;

	i = 0;
	if (ft_strlen(s1))
		i = ft_strlen(s1) - 1;
	while (i >= 0 && ft_strchr(set, s1[i]))
		i--;
	return (i);
}

static char	*call911(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = get_end(s1, set) + 1;
	str = (char *)malloc((j - get_start(s1, set) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (get_start(s1, set) + i < j)
	{
		str[i] = s1[i + get_start(s1, set)];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	j;

	if (!s1 || !set)
		return (0);
	j = get_end(s1, set) + 1;
	if (get_end(s1, set) < get_start(s1, set) || *s1 == '\0')
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (0);
		*str = '\0';
	}
	else
	{
		str = call911(s1, set);
	}
	return (str);
}
