/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:07:45 by yiken             #+#    #+#             */
/*   Updated: 2024/02/19 16:57:54 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str, char sep)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != sep && (!str[i + 1] || str[i + 1] == sep))
			counter++;
		i++;
	}
	return (counter);
}

char	*get_next_word(char *str, char sep)
{
	static int	i;
	int			len;
	char		*word_str;

	len = 0;
	while (str[i] == sep)
		i++;
	while (str[i + len] && str[i + len] != sep)
		len++;
	word_str = malloc(len + 1);
	if (!word_str)
		return (0);
	len = 0;
	while (str[i] != sep && str[i])
	{
		word_str[len++] = str[i++];
	}
	word_str[len] = 0;
	return (word_str);
}

char	**ft_split(char *str, char sep)
{
	int		words_num;
	char	**words_tab;
	int		i;

	words_num = count_words(str, sep);
	if (!words_num)
		exit(1);
	words_tab = malloc(sizeof(char *) * (words_num + 2));
	if (!words_tab)
		return (0);
	words_tab[0] = 0;
	i = 1;
	while (i < words_num + 1)
		words_tab[i++] = get_next_word(str, sep);
	words_tab[i] = 0;
	return (words_tab);
}
