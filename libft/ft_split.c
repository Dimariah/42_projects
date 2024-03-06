/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:37:08 by yiken             #+#    #+#             */
/*   Updated: 2023/12/01 16:09:37 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	fill_str(char **tab, char const *s, char c, int index)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		tab[index][i] = s[i];
		i++;
	}
	tab[index][i] = '\0';
}

static char	**free_tab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (0);
}

static char	**fill_tab(char **tab, char const *s, char c)
{
	int	i;
	int	index;
	int	len;

	i = 0;
	index = 0;
	while (s[i])
	{
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len > 0)
		{
			tab[index] = (char *)malloc((len + 1) * sizeof(char));
			if (!tab[index])
				return (free_tab(tab, index));
			fill_str(tab, s + i, c, index);
			index++;
			i = i + len;
		}
		else
			i++;
	}
	tab[index] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	if (!s)
		return (0);
	words = get_words(s, c) + 1;
	tab = (char **)malloc(words * sizeof(char *));
	if (!tab)
		return (0);
	tab = fill_tab(tab, s, c);
	return (tab);
}
