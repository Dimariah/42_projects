/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_extras.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiken <yiken@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:44:47 by yiken             #+#    #+#             */
/*   Updated: 2024/04/25 12:31:23 by yiken            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_binary_path(char *cmd, char **envp)
{
	char	*full_path;
	char	*dir;
	char	*path;

	path = 0;
	full_path = get_full_path(envp);
	dir = get_next_word(full_path, ':', true);
	while (dir)
	{
		free(path);
		path = str_join(dir, cmd);
		free(dir);
		if (!path)
			return (0);
		if (access(path, X_OK) == 0)
			break ;
		dir = get_next_word(full_path, ':', false);
	}
	return (path);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		while (s1[i] == s2[i] && s1[i] && s2[i])
			i++;
	}
	else
	{
		while (n-- > 1 && s1[i] == s2[i] && s1[i] && s2[i])
			i++;
	}
	return (s1[i] - s2[i]);
}

char	*get_full_path(char **envp)
{
	char	*full_path;
	int		i;

	full_path = 0;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			full_path = envp[i] + 5;
			break ;
		}
		i++;
	}
	return (full_path);
}

int	is_corrupted(char **argv, char *str, char sep)
{
	int	i;
	int	j;
	int	words_num;

	i = 0;
	j = 0;
	words_num = 0;
	while (argv[i])
		i++;
	while (str[j])
		if (str[j++] != sep && (str[j] == sep || !str[j]))
			words_num++;
	if (words_num != i)
		return (1);
	return (0);
}

void	free_resources(char **argv, char *binary_path)
{
	int		i;

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	free(binary_path);
	if (argv)
	{
		i = 0;
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
	exit(1);
}
