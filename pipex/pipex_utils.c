/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:04:01 by yiken             #+#    #+#             */
/*   Updated: 2024/04/23 15:59:30 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *filename, int is_inp)
{
	int	fd;

	if (is_inp == 1)
		fd = open(filename, O_RDONLY);
	else if (is_inp == 2)
		fd = open(filename, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else
		fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
	{
		close(STDIN_FILENO);
		perror(filename);
		exit(1);
	}
	return (fd);
}

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*get_next_word(char *str, char sep, bool reset)
{
	static int	i;
	int			len;
	char		*word;

	if (!str)
		return (0);
	if (reset)
		i = 0;
	len = 0;
	while (str[i] == sep)
		i++;
	while (str[i + len] != sep && str[i + len])
		len++;
	if (len == 0)
		return (0);
	word = malloc(len + 1);
	if (!word)
		return (0);
	len = 0;
	while (str[i] != sep && str[i])
		word[len++] = str[i++];
	word[len] = 0;
	return (word);
}

char	**ft_split(char *str, char sep)
{
	int		i;
	int		words_num;
	char	**words_tab;

	i = 0;
	words_num = 0;
	while (str[i])
		if (str[i++] != sep && (str[i] == sep || !str[i]))
			words_num++;
	words_tab = malloc(sizeof(char *) * (words_num + 1));
	if (!words_tab)
		free_resources(0, 0);
	i = 0;
	while (i < words_num)
		words_tab[i++] = get_next_word(str, sep, false);
	words_tab[i] = 0;
	return (words_tab);
}

char	*str_join(char *dir, char *cmd)
{
	int		i;
	int		j;
	char	*new_str;

	if (!cmd || !dir)
		return (0);
	new_str = malloc(ft_strlen(dir) + ft_strlen(cmd) + 2);
	if (!new_str)
		return (0);
	i = 0;
	while (dir[i])
	{
		new_str[i] = dir[i];
		i++;
	}
	new_str[i++] = '/';
	j = 0;
	while (cmd[j])
	{
		new_str[i + j] = cmd[j];
		j++;
	}
	new_str[i + j] = 0;
	return (new_str);
}
