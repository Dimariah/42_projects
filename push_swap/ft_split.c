/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:07:45 by yiken             #+#    #+#             */
/*   Updated: 2024/03/11 16:01:05 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str, char sep)
{
	int	i;	
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == sep || !str[i + 1]))
			words++;
		i++;
	}
	return (words);
}

char	*get_next_word(char **av, char sep)
{
	static int	i;
	static int	j;
	int			len;
	char		*str;

	len = 0;
	while (av[j][i] == sep)
		i++;
	while (av[j][i + len] != sep && av[j][i + len])
		len++;
	str = malloc(len + 1);
	if (!str)
		return (0);
	len = 0;
	while (av[j][i] != sep && av[j][i])
		str[len++] = av[j][i++];
	str[len] = 0;
	while (av[j][i] == sep)
		i++;
	if (!av[j][i])
	{
		i = 0;
		j++;
	}
	return (str);
}

char	**ft_split(char **av, int ac, char sep)
{
	int		i;
	int		words;
	char	**new_av;

	i = 1;
	words = 0;
	while (i < ac)
		words += count_words(av[i++], sep);
	if (!words)
		exit(1);
	new_av = malloc(sizeof(char *) * (words + 2));
	if (!new_av)
		return (0);
	i = 0;
	new_av[i++] = 0;
	while (i < words + 1)
		new_av[i++] = get_next_word(av + 1, sep);
	new_av[i] = 0;
	return (new_av);
}
